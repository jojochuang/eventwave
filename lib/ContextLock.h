#ifndef _CONTEXTLOCK_H
#define _CONTEXTLOCK_H

// including headers
#include "mace.h"
#include "GlobalCommit.h"
#include "ContextBaseClass.h"
#include "pthread.h"
#include "Ticket.h"
// uses snapshot by default

namespace mace{

class ContextBaseClass;
class ContextLock;

class ContextLock {
private:
    ContextBaseClass& context;
    ContextThreadSpecific *contextThreadSpecific;
  public:
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;
  private:
    static pthread_mutex_t _context_ticketbooth; // chuangw: single ticketbooth for now. we will see if it'd become a bottleneck.
    static uint64_t smallestAbsentEvent; // FIXME: need initialization
    static std::map<uint64_t, pthread_cond_t*> notready_events;
  public:
    static const int WRITE_MODE = 1;
    static const int READ_MODE = 0;
    static const int NONE_MODE = -1;
  public:
    //static uint64_t now_committing;
    //static std::map<uint64_t, pthread_cond_t*> context.commitConditionVariables; // Support for per-thread CVs, which gives per ticket CV support. Note: can just use the front of the queue to avoid lookups 
public:
    ContextLock( ContextBaseClass& ctx, int requestedMode = WRITE_MODE ): context(ctx), contextThreadSpecific(ctx.init() ), requestedMode( requestedMode), priorMode(contextThreadSpecific->currentMode), myTicketNum(Ticket::myTicket())/*, _context_ticketbooth(ctx._context_ticketbooth  )*/{
        ADD_SELECTORS("ContextLock::(constructor)");
        macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;
        if (priorMode == NONE_MODE) {
          // do what's needed
          if (requestedMode == NONE_MODE) {
            //Do nothing.
          } else {
              upgradeFromNone();
          }
        } else if (priorMode == READ_MODE) {
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
        } else if (priorMode == WRITE_MODE) {
          ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
        } else {
          ABORT("Unknown priorMode!");
        }
        macedbg(1) << "CONTINUING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;
    }
    void upgradeFromNone(){
      ADD_SELECTORS("ContextLock::upgradeFromNone");
      ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

      ScopedLock sl(_context_ticketbooth);

      // chuangw: XXX this piece of code is most likely deprecated code.
      // myTicketNum is Ticket::myTicket(), which initially is zero.
      if (myTicketNum == std::numeric_limits<uint64_t>::max()) {
        myTicketNum = Ticket::newTicket();
        macewarn << "Ticket not acquired - acquiring new ticket.  Ticket: "  << myTicketNum << Log::endl;
      }

      //
      // change ticket if ticket is invalid
      //
      if (myTicketNum < context.now_serving) {
        //Ticket already used!  Need to acquire new ticket.
        uint64_t oldTicket = myTicketNum;
        myTicketNum = Ticket::newTicket();
        macewarn << "Ticket already used - acquiring new ticket.  Sometimes possible event interleaving!  This time tickets are: "  << oldTicket << " and " << myTicketNum << Log::endl;
      }

      //
      // wait until my ticket is served
      //
      ticketBoothWait(requestedMode);


      if (requestedMode == READ_MODE) {
          ASSERT(context.numWriters == 0);
          // store the snapshot version number
          // there's no change since the last write, so current context state
          // is versioned 'lastWrite'
          contextThreadSpecific->snapshotVersion = context.lastWrite;
          // take snapshot
          // chuangw: FIXME: in fact, only the snapshot of this context is needed.
          // Need to somehow tell it to do snapshot for the context only
          BaseMaceService::globalSnapshot(context.lastWrite);
          // change mode
          contextThreadSpecific->setCurrentMode(READ_MODE);
          // wake up the next waiting thread (which has the next smallest ticket number)
          if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
            macedbg(1) << "Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
            pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
          }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
      } else if (requestedMode == WRITE_MODE) {
        //Acquire write lock
        ASSERT(context.numReaders == 0);
        ASSERT(context.numWriters == 0);
        contextThreadSpecific->setCurrentMode(WRITE_MODE);
        context.numWriters = 1;
        context.lastWrite = myTicketNum;
      }
    }
    void nullTicket() {
      ADD_SELECTORS("ContextLock::nullTicket");
      ScopedLock sl(_context_ticketbooth);
      ticketBoothWait(NONE_MODE);

      if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
        macedbg(1) << "Now signalling ticket number " << context.now_serving << " (my ticket is " << Ticket::myTicket() << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
      }

      commitOrderWait();
    }

    void ticketBoothWait(int requestedMode){
      ADD_SELECTORS("ContextLock::ticketBoothWait");

      //chuangw: unlike original AgentLock::ticketBoothWait(), the ticket number of this ContextLock is already stored
      // as a member variable when acquiring ticket. 
      // This thread can concurrently hold many ContextLocks, each with different ticket number.
      // If re-asking the current ticket number again, it would end up getting the newest ticket number, but does not
      // necessarily be the one corresponding to the context bounded to this ContextLock.
      //uint64_t myTicketNum = Ticket::myTicket();
      pthread_cond_t* threadCond = &(context.init()->threadCond);

      if( myTicketNum == smallestAbsentEvent ){
        smallestAbsentEvent++; // don't signal myself
        uint64_t old_smallestAbsentEvent = smallestAbsentEvent;
        while( notready_events.find( smallestAbsentEvent ) != notready_events.end() ){
            smallestAbsentEvent++;
        }
        uint64_t new_smallestAbsentEvent = smallestAbsentEvent;
        //for(uint64_t i=old_smallestAbsentEvent;i< new_smallestAbsentEvent;i++){
        
        for(uint64_t ticket=old_smallestAbsentEvent; ticket < new_smallestAbsentEvent; ticket ++ ){
            // FIXME: race condition?
            // tell the thread that it "may be" eligible to be served now.
            // It would be more efficient to check if it's the front event in the context...
            // Don't do it now. Just make sure don't mess things up.
            //pthread_cond_broadcast( notready_events[i] );
            macedbg(1) << "Signalling CV " << notready_events[ticket] << " for ticket " << ticket << Log::endl;
            pthread_cond_broadcast( notready_events[ticket] );
            notready_events.erase( notready_events.begin() );
        }
        //context.no_nextserving = false;
      }else{
        notready_events[ myTicketNum ] = threadCond;
      }
      context.next_serving.push( myTicketNum );

      if( context.no_nextserving && !context.next_serving.empty() && context.next_serving.front() < smallestAbsentEvent ){
        // update now_serving
        context.now_serving = context.next_serving.front();
        context.next_serving.pop();
        context.no_nextserving = false;
      }

      macedbg(1) << "context.no_nextserving="<<context.no_nextserving<<",myTicketNum="<<myTicketNum<<",context.now_serving="<<context.now_serving<<"context.numWriters="<<context.numWriters<<Log::endl;
      if ( context.no_nextserving ||
      
        myTicketNum > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
         ) {
        macedbg(1) << "Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        context.conditionVariables[myTicketNum] = threadCond;
      }

      while ( context.no_nextserving ||
      
      myTicketNum > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
          ) {
        macedbg(1) << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << context.now_serving << " requestedMode " << requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;

        if( context.no_nextserving && !context.next_serving.empty() && context.next_serving.front() < smallestAbsentEvent ){
          // update now_serving
          context.now_serving = context.next_serving.front();
          context.next_serving.pop();
          context.no_nextserving = false;

          if( context.now_serving != myTicketNum )
            pthread_cond_wait(threadCond, &_context_ticketbooth);
        }else
            pthread_cond_wait(threadCond, &_context_ticketbooth);
      }

      macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

      //chuangw: I don't see what this is used for. If marking ticket as served has effects in other parts of the code,
      // something big need to be fixed.
      Ticket::markTicketServed();

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == myTicketNum) {
        macedbg(1) << "Erasing our cv from the map." << Log::endl;
        context.conditionVariables.erase(context.conditionVariables.begin());
      }
      else if (context.conditionVariables.begin() != context.conditionVariables.end()) {
        macedbg(1) << "FYI, first cv in map is for ticket " << context.conditionVariables.begin()->first << Log::endl;
      }

      ASSERT(myTicketNum == context.now_serving); //Remove once working.

      //chuangw: FIXME: this must be changed, since the next event to serve within the context waiting queue is not necessarily 
      // question: in the original AgentLock code, if event A gets a ticket immediately after event B therefore event A gets ticket number X and B gets X+1, after B finishes ticketBoothWait() and ready to signal event A, would A be available on the conditon variable queue??
      // the next smallest ticket number.
      //context.now_serving++;
      //
      // update now_serving. set now_serving to the next eligible event ticket.
      if( context.next_serving.empty() ||  context.next_serving.front() <= smallestAbsentEvent){
        context.no_nextserving = true;
      }else{
        context.now_serving = context.next_serving.front();
        context.next_serving.pop();
        context.no_nextserving = false;
      }

    // the commit should be prepared to commit in the order ticket was requested.
      context.next_committing.push( myTicketNum );
    }

    ~ContextLock(){
        ADD_SELECTORS("ContextLock::(destructor)");
        int runningMode = contextThreadSpecific->getCurrentMode();
        macedbg(1) << "ENDING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
        if (priorMode == NONE_MODE && runningMode != NONE_MODE) {
          macedbg(1) << "Downgrading to NONE_MODE" << Log::endl;
          downgrade(NONE_MODE);
        }
        macedbg(1) << "ENDED.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
    }
    
    void downgrade(int newMode) {
      ADD_SELECTORS("ContextLock::downgrade");
      int runningMode = contextThreadSpecific->getCurrentMode();
      uint64_t myTicketNum = Ticket::myTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << "Why was downgrade called?  Current mode is: " << runningMode << " and mode requested is: " << newMode << Log::endl;
      macedbg(1) << "Downgrade exiting" << Log::endl;
    }
    void downgradeToNone(int runningMode) {
      ADD_SELECTORS("ContextLock::downgradeToNone");
        ScopedLock sl(_context_ticketbooth);
        bool doGlobalRelease = false;
        if (runningMode == READ_MODE) {
            ASSERT(context.numReaders == 0);
            if (contextThreadSpecific->getSnapshotVersion() == myTicketNum) { //I did a write, and have now committed!
              doGlobalRelease = true;
              //               BaseMaceService::globalSnapshotRelease(myTicketNum); // I was a writer, and I have committed, so earlier events have committed, so earlier snapshots can be released.
            }
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(context.numReaders == 0 && context.numWriters == 1);
          context.numWriters=0;
          doGlobalRelease = true;
          //             BaseMaceService::globalSnapshotRelease(myTicketNum); // I am a writer, and I have committed, so earlier events have committed, so earlier snapshots can be released.
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "After lock release - numReaders " << context.numReaders << " numWriters " << context.numWriters << Log::endl;
        contextThreadSpecific->setCurrentMode(NONE_MODE);
        if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
          macedbg(1) << "Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
        macedbg(1) << "Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait();
        macedbg(1) << "Commiting ticket " << myTicketNum << Log::endl;

        // NOTE: commit executes here
        GlobalCommit::commit(myTicketNum);

        if (doGlobalRelease) {
          BaseMaceService::globalSnapshotRelease(myTicketNum);
        }
        macedbg(1) << "Downgrade to NONE_MODE complete" << Log::endl;
    }
    void downgradeToRead() {
      ADD_SELECTORS("ContextLock::downgradeToRead");
        macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_context_ticketbooth);
        ASSERT(context.numWriters == 1 && context.numReaders == 0);
        ASSERT(context.now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        context.numWriters = 0;
          contextThreadSpecific->setSnapshotVersion(context.lastWrite);
          BaseMaceService::globalSnapshot(context.lastWrite);
        contextThreadSpecific->setCurrentMode(READ_MODE);
        if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
          macedbg(1) << "Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
    }
    void commitOrderWait() {
      ADD_SELECTORS("ContextLock::commitOrderWait");
      uint64_t myTicketNum = Ticket::myTicket();

      if( context.no_nextcommitting  && !context.next_committing.empty() ){
            context.now_committing = context.next_committing.front();
            context.next_committing.pop();
            context.no_nextcommitting = false;
      }

      if( context.no_nextcommitting  ){
        // no uncommitted event is earlier than me
          ASSERT( context.commitConditionVariables.empty() );
          context.now_committing = myTicketNum;
      }else{
          if (myTicketNum > context.now_committing ) {
            macedbg(1) << "Storing condition variable " << &(context.init()->threadCond) << " for ticket " << myTicketNum << Log::endl;
            context.commitConditionVariables[myTicketNum] = &(context.init()->threadCond);
          }

          while (myTicketNum > context.now_committing) {
            macedbg(1) << "Waiting for my turn on cv " << &(context.init()->threadCond) << ".  myTicketNum " << myTicketNum << " now_committing " << context.now_committing << Log::endl;
            pthread_cond_wait(&(context.init()->threadCond), &_context_ticketbooth);
          }
      }

      macedbg(1) << "Ticket " << myTicketNum << " being committed!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == myTicketNum) {
        macedbg(1) << "Erasing our cv from the map." << Log::endl;
        context.commitConditionVariables.erase(context.commitConditionVariables.begin());
      }
      else if (context.commitConditionVariables.begin() != context.commitConditionVariables.end()) {
        macedbg(1) << "FYI, first cv in map is for ticket " << context.commitConditionVariables.begin()->first << Log::endl;
      }

      ASSERT(myTicketNum == context.now_committing); //Remove once working.

    //chuangw: FIXME: same as now_serving. In fullcontext model, it does not guarantee the next event to be comitted has the next smallest ticket number.
      //context.now_committing++;
      if( context.next_committing.empty() ){
          context.no_nextcommitting = true;
      }else{
          context.now_committing = context.next_committing.front();
          context.next_committing.pop();
          context.no_nextcommitting = false;
          if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == context.now_committing) {
            macedbg(1) << "Now signalling ticket number " << context.now_committing << " (my ticket is " << myTicketNum << " )" << Log::endl;
            pthread_cond_broadcast(context.commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
          }
          else {
            ASSERTMSG(context.commitConditionVariables.begin() == context.commitConditionVariables.end() || context.commitConditionVariables.begin()->first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
          }
      }

    }
};

}

#endif
