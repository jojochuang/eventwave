#ifndef _CONTEXTLOCK_H
#define _CONTEXTLOCK_H

// including headers
#include "mace.h"
#include "GlobalCommit.h"
#include "ContextBaseClass.h"
#include "pthread.h"
#include "ThreadStructure.h"
// uses snapshot by default

namespace mace{

class ContextBaseClass;
class ContextLock;

class ContextLock {
private:
    ContextBaseClass& context;
    ContextThreadSpecific *contextThreadSpecific;
  public:
    const int8_t requestedMode;
    const int8_t priorMode;
    uint64_t myTicketNum;
  private:
    static pthread_mutex_t _context_ticketbooth; // chuangw: single ticketbooth for now. we will see if it'd become a bottleneck.
    //static uint64_t smallestAbsentEvent; // FIXME: need initialization
    //static std::map<uint64_t, pthread_cond_t*> notready_events;
  public:
    static const int8_t WRITE_MODE = 1;
    static const int8_t READ_MODE = 0;
    static const int8_t NONE_MODE = -1;
  public:
    //static uint64_t lastCommittedTicket;

public:
    ContextLock( ContextBaseClass& ctx, int8_t requestedMode = WRITE_MODE ): context(ctx), contextThreadSpecific(ctx.init() ), requestedMode( requestedMode), priorMode(contextThreadSpecific->currentMode), myTicketNum(ThreadStructure::myTicket()){
        ADD_SELECTORS("ContextLock::(constructor)");
        if( myTicketNum < context.now_serving ){
            std::map<uint64_t, int8_t>::iterator uceventIt = context.uncommittedEvents.find( myTicketNum );
            if( uceventIt != context.uncommittedEvents.end() ){
                int8_t origMode = uceventIt->second;
                if(  origMode >= READ_MODE  && requestedMode == origMode ){
                    return; // ready to go!
                }else if( (origMode >= READ_MODE ) && requestedMode < origMode ){
                    downgrade( requestedMode );
                    return;
                }else{
                    maceerr<< context.contextID<<"myTicketNum = "<< myTicketNum << Log::endl;
                    maceerr<< context.contextID<<"size of uncommittedEvents: "<< context.uncommittedEvents.size()<<Log::endl;
                    for(uceventIt = context.uncommittedEvents.begin(); uceventIt != context.uncommittedEvents.end(); uceventIt++){
                        maceerr<< context.contextID<<"uncommit event: ticket="<< uceventIt->first <<", mode=" << (int16_t)uceventIt->second << Log::endl;
                    }
                    maceerr<< context.contextID<<"context.now_serving="<< context.now_serving <<", context.now_committing="<< context.now_committing<<Log::endl;
                    macedbg(1) << context.contextID<<"STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
                    ABORT("unexpected event mode change");
                }
            }else{
                maceerr<<context.contextID<<"myTicketNum = "<< myTicketNum << Log::endl;
                maceerr<<context.contextID<<"size of uncommittedEvents: "<< context.uncommittedEvents.size()<<Log::endl;
                for(uceventIt = context.uncommittedEvents.begin(); uceventIt != context.uncommittedEvents.end(); uceventIt++){
                    maceerr<<context.contextID<<"uncommit event: ticket="<< uceventIt->first <<", mode=" << uceventIt->second << Log::endl;
                }
                maceerr<<context.contextID<<"context.now_serving="<< context.now_serving <<", context.now_committing="<< context.now_committing<<Log::endl;
                ABORT("ticket number is less than now_serving, but the ticket did not appear in uncommittedEvents list");
            }
        }
        macedbg(1) << context.contextID<<"STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
        if (priorMode == NONE_MODE) { // chuangw: OK mode transition
          // do what's needed
          if (requestedMode == NONE_MODE) {// chuangw: FIXME
            //Do nothing.
            nullTicket();
          } else { // event initially at none mode. It can request to enter some mode.
              upgradeFromNone(); // chuangw: FIXME
          }
        } else if (priorMode == READ_MODE) { // chuangw: OK mode transition
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
        } else if (priorMode == WRITE_MODE) {// chuangw: OK mode transition
          ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
        } else {// chuangw: OK mode transition
          ABORT("Unknown priorMode!");
        }
        macedbg(1) << context.contextID<<"CONTINUING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;

        context.uncommittedEvents[ myTicketNum ] = requestedMode;
    }
    void upgradeFromNone(){ // chuangw: OK... I think.  Need to double check
      ADD_SELECTORS("ContextLock::upgradeFromNone");
      ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

      ScopedLock sl(_context_ticketbooth);

      // chuangw: XXX: I don't think this would happen...
      /*if (myTicketNum == std::numeric_limits<uint64_t>::max()) {
        myTicketNum = ThreadStructure::newTicket();
        macewarn << context.contextID<<"Ticket not acquired - acquiring new ticket.  Ticket: "  << myTicketNum << Log::endl;
      }*/

      //
      // change ticket if ticket is invalid
      //
      // chuangw: TODO: remove this section of code.
      /*if (myTicketNum < context.now_serving) {
        //Ticket already used!  Need to acquire new ticket.
        uint64_t oldTicket = myTicketNum;
        myTicketNum = ThreadStructure::newTicket();
        macewarn << context.contextID<<"Ticket already used - acquiring new ticket.  Sometimes possible event interleaving!  This time tickets are: "  << oldTicket << " and " << myTicketNum << Log::endl;
      }*/

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


          // chuangw: FIXME TODO XXX: this is buggy! the original snapshot code would release snapshot
          // that were not taken by the previous events in the same context.
          // and then enter infinite loop in erasing std::map (for reason I don't understand yet)
          // comment it out for now.....hope it wouldn't break.

          // FIXME: BaseMaceService::globalSnapshot(context.lastWrite);
          // FIXME: experimental code
          context.snapshot( context.lastWrite );



          // change mode
          contextThreadSpecific->setCurrentMode(READ_MODE);
          // wake up the next waiting thread (which has the next smallest ticket number)
          if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
            macedbg(1) << context.contextID<<"Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
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
    void nullTicket() {// chuangw: OK, I think.
      ADD_SELECTORS("ContextLock::nullTicket");
      ScopedLock sl(_context_ticketbooth);
      ticketBoothWait(NONE_MODE);

      if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
        macedbg(1) << context.contextID<<"Now signalling ticket number " << context.now_serving << " (my ticket is " << ThreadStructure::myTicket() << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
      }

      commitOrderWait();
    }

    void ticketBoothWait(int8_t requestedMode){
      ADD_SELECTORS("ContextLock::ticketBoothWait");

      uint64_t myTicketNum = ThreadStructure::myTicket();
      pthread_cond_t* threadCond = &(context.init()->threadCond);

      if (myTicketNum > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
         ) {
        macedbg(1)<< context.contextID << "Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        context.conditionVariables[myTicketNum] = threadCond;
      }
      while (myTicketNum > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
          ) {
        macedbg(1)<< context.contextID << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << context.now_serving << " requestedMode " << requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;
        pthread_cond_wait(threadCond, &_context_ticketbooth);
      }

      macedbg(1) << context.contextID<<"Ticket " << myTicketNum << " being served!" << Log::endl;

      // XXX: chuangw: I don't see what this is used for.
      ThreadStructure::markTicketServed();

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      // chuangw: TODO use !context.empty() instead
      if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == myTicketNum) {
        macedbg(1) << context.contextID<<"Erasing our cv from the map." << Log::endl;
        context.conditionVariables.erase(context.conditionVariables.begin());
      }
      else if (context.conditionVariables.begin() != context.conditionVariables.end()) {
        macedbg(1) << context.contextID<<"FYI, first cv in map is for ticket " << context.conditionVariables.begin()->first << Log::endl;
      }

      ASSERT(myTicketNum == context.now_serving); //Remove once working.

      context.now_serving++;

/*
      // chuangw: next_serving is a priority queue. Events with earlier(smaller) ticket always get into ticket booth than later ones.
      // chuangw: add myself to next_serving queue, before attemptting to wake up all eligible events.
      // because if the later, eligible events are woken up, it
      context.next_serving.push( myTicketNum );
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
            macedbg(1) << context.contextID<<"Signalling CV " << notready_events[ticket] << " for ticket " << ticket << Log::endl;
            pthread_cond_broadcast( notready_events[ticket] );
            notready_events.erase( notready_events.begin() );
        }
        //context.no_nextserving = false;
      }else{
        notready_events[ myTicketNum ] = threadCond;
      }

      if( context.no_nextserving && !context.next_serving.empty() && context.next_serving.top() < smallestAbsentEvent ){
        // if value of now_serving is invalid, but next_serving queue has some tickets waiting, and the first ticket is ready.
        // ("ready" means: all earlier tickets have already entered ticket booth.)
        //
        // update now_serving
        context.now_serving = context.next_serving.top();
        context.next_serving.pop();
        context.no_nextserving = false;
      }

      macedbg(1) << context.contextID<<"context.no_nextserving="<<context.no_nextserving<<",myTicketNum="<<myTicketNum<<",context.now_serving="<<context.now_serving<<",context.numWriters="<<context.numWriters<<Log::endl;
      if ( context.no_nextserving ||
        // if now_serving is invalid, that means there are some earlier tickets not yet in the ticketbooth, so this event has to wait.
        (context.no_nextserving==false && myTicketNum > context.now_serving) ||
        // now_serving is valid, but this ticket is behind what is being served.
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
         ) {
        macedbg(1) << context.contextID<<"Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        context.conditionVariables[myTicketNum] = threadCond;
      }*/
      /*while ( context.no_nextserving ||
      
        (context.no_nextserving==false && myTicketNum > context.now_serving) ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
          ) {
        macedbg(1) << context.contextID<<"Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << context.now_serving << " requestedMode " << requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;

        macedbg(1)<<"no_nextserving="<<context.no_nextserving<<Log::endl;
        if( context.next_serving.empty() ){
            macedbg(1)<<"next_serving queue is empty"<<Log::endl;
        }else{
            macedbg(1)<<"next_serving.top: "<<context.next_serving.top();
            macedbg(1)<<Log::endl;
        }

        if( context.no_nextserving && !context.next_serving.empty() && context.next_serving.top() < smallestAbsentEvent ){
          // update now_serving
          context.now_serving = context.next_serving.top();
          context.next_serving.pop();
          context.no_nextserving = false;

          if( context.now_serving != myTicketNum ){
            pthread_cond_wait(threadCond, &_context_ticketbooth);
          }else{
            macedbg(1)<<context.contextID<<"after update, I don't need to wait!"<<Log::endl;
          }
        }else
            pthread_cond_wait(threadCond, &_context_ticketbooth);
      }*/
      //chuangw: FIXME: this must be changed, since the next event to serve within the context waiting queue is not necessarily 
      // question: in the original AgentLock code, if event A gets a ticket immediately after event B therefore event A gets ticket number X and B gets X+1, after B finishes ticketBoothWait() and ready to signal event A, would A be available on the conditon variable queue??
      // the next smallest ticket number.
      //context.now_serving++;
      //
      // update now_serving. set now_serving to the next eligible event ticket.
      /*if( context.next_serving.empty() ||  context.next_serving.top() >= smallestAbsentEvent){
        context.no_nextserving = true;
        macedbg(1)<<"no more waiting events"<<Log::endl;
        macedbg(1)<<"context.next_serving.empty()="<<context.next_serving.empty();
        if( !context.next_serving.empty() ) 
            macedbg(1)<<",context.next_serving.top()="<<context.next_serving.top()<<",smallestAbsentEvent="<<smallestAbsentEvent<<Log::endl;
      }else{
        context.now_serving = context.next_serving.top();
        context.next_serving.pop();
        context.no_nextserving = false;

        macedbg(1) << context.contextID<<" now_serving changed to "<<context.now_serving<<Log::endl;
      }

    // the commit should be prepared to commit in the order ticket was requested.
      context.next_committing.push( myTicketNum );*/
    }

    ~ContextLock(){ // chuangw: checked once
        /*ADD_SELECTORS("ContextLock::(destructor)");
        int8_t runningMode = contextThreadSpecific->getCurrentMode();
        macedbg(1) << context.contextID<<"ENDING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
        if (priorMode == NONE_MODE && runningMode != NONE_MODE) {
          macedbg(1) << context.contextID<<"Downgrading to NONE_MODE" << Log::endl;
          // chuangw: sync call does not downgrade automatically.
          //downgrade(NONE_MODE);
        }
        macedbg(1) << context.contextID<<"ENDED.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;*/
    }
    
    void downgrade(int8_t newMode) {
/* TODO: chuangw:
 *  In fullcontext model, downgrade() has to specify which child context to downgrade.
 *  */

      ADD_SELECTORS("ContextLock::downgrade");
      //int8_t runningMode = contextThreadSpecific->getCurrentMode();
      uint64_t myTicketNum = ThreadStructure::myTicket();
      uint8_t runningMode = context.uncommittedEvents[ myTicketNum ];
      macedbg(1) << context.contextID<<"Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << (uint16_t)runningMode << " newMode " << (uint16_t)newMode << Log::endl;

      if( newMode == NONE_MODE ){ // remove from uncommited event list.
        context.uncommittedEvents.erase( ThreadStructure::myTicket() );
      }

      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << context.contextID<<"Why was downgrade called?  Current mode is: " << (uint16_t)runningMode << " and mode requested is: " << (uint16_t)newMode << Log::endl;
      macedbg(1) << context.contextID<<"Downgrade exiting" << Log::endl;
    }
    void downgradeToNone(int8_t runningMode) {
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
        macedbg(1) << context.contextID<<"After lock release - numReaders " << context.numReaders << " numWriters " << context.numWriters << Log::endl;
        contextThreadSpecific->setCurrentMode(NONE_MODE);
        if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
          macedbg(1) << context.contextID<<"Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
        macedbg(1) << context.contextID << "no_nextserving="<<context.no_nextserving<<",now_serving="<< context.now_serving<<Log::endl;
        macedbg(1) << context.contextID<<"Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait();
        macedbg(1) << context.contextID<<"Commiting ticket " << myTicketNum << Log::endl;

        // NOTE: commit executes here
        GlobalCommit::commit(myTicketNum);

        if (doGlobalRelease) {


          // chuangw: FIXME TODO XXX: this is buggy! the original snapshot code would release snapshot
          // that were not taken by the previous events in the same context.
          // and then enter infinite loop in erasing std::map (for reason I don't understand yet)
          // comment it out for now.....hope it wouldn't break.

          // FIXME: BaseMaceService::globalSnapshotRelease(myTicketNum);

          // FIXME: experimental code
          context.snapshotRelease( myTicketNum );
          // XXX: I think it suffices to take the snapshot of this particular context.
          //      It should not be worry about the snapshot of other contexts, as well as state
          //      of other services.



        }
        macedbg(1) << context.contextID<<"Downgrade to NONE_MODE complete" << Log::endl;
    }
    void downgradeToRead() {
      ADD_SELECTORS("ContextLock::downgradeToRead");
        macedbg(1) << context.contextID<<"Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_context_ticketbooth);
        ASSERT(context.numWriters == 1 && context.numReaders == 0);
        ASSERT(context.now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        context.numWriters = 0;
          contextThreadSpecific->setSnapshotVersion(context.lastWrite);


          // chuangw: FIXME TODO XXX: this is buggy! the original snapshot code would release snapshot
          // that were not taken by the previous events in the same context.
          // and then enter infinite loop in erasing std::map (for reason I don't understand yet)
          // comment it out for now.....hope it wouldn't break.

          // FIXME: BaseMaceService::globalSnapshot(context.lastWrite);





        contextThreadSpecific->setCurrentMode(READ_MODE);
        if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
          macedbg(1) << context.contextID<<"Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
    }
    void commitOrderWait() {
      ADD_SELECTORS("ContextLock::commitOrderWait");
      uint64_t myTicketNum = ThreadStructure::myTicket();

      if (myTicketNum > context.now_committing ) {
        macedbg(1)<< context.contextID << "Storing condition variable " << &(context.init()->threadCond) << " for ticket " << myTicketNum << Log::endl;
        context.commitConditionVariables[myTicketNum] = &(context.init()->threadCond);
      }
      while (myTicketNum > context.now_committing) {
        macedbg(1)<< context.contextID << "Waiting for my turn on cv " << &(context.init()->threadCond) << ".  myTicketNum " << myTicketNum << " now_committing " << context.now_committing << Log::endl;
        pthread_cond_wait(&(context.init()->threadCond), &_context_ticketbooth);
      }

      macedbg(1) << context.contextID<<"Ticket " << myTicketNum << " being committed!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == myTicketNum) {
        macedbg(1)<< context.contextID << "Erasing our cv from the map." << Log::endl;
        context.commitConditionVariables.erase(context.commitConditionVariables.begin());
      }
      else if (context.commitConditionVariables.begin() != context.commitConditionVariables.end()) {
        macedbg(1)<< context.contextID << "FYI, first cv in map is for ticket " << context.commitConditionVariables.begin()->first << Log::endl;
      }
      ASSERT(myTicketNum == context.now_committing); //Remove once working.

      context.now_committing++;
      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == context.now_committing) {
        macedbg(1)<< context.contextID << "Now signalling ticket number " << context.now_committing << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.commitConditionVariables.begin() == context.commitConditionVariables.end() || context.commitConditionVariables.begin()->first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
      }

      /*if( context.no_nextcommitting  && !context.next_committing.empty() ){
            context.now_committing = context.next_committing.front();
            context.next_committing.pop();
            context.no_nextcommitting = false;
      }*/

      /*if( context.no_nextcommitting  ){
        // no uncommitted event is earlier than me
          ASSERT( context.commitConditionVariables.empty() );
          context.now_committing = myTicketNum;
      }else{
          if (myTicketNum > context.now_committing ) {
            macedbg(1) << context.contextID<<"Storing condition variable " << &(context.init()->threadCond) << " for ticket " << myTicketNum << Log::endl;
            context.commitConditionVariables[myTicketNum] = &(context.init()->threadCond);
          }

          while (myTicketNum > context.now_committing) {
            macedbg(1) << context.contextID<<"Waiting for my turn on cv " << &(context.init()->threadCond) << ".  myTicketNum " << myTicketNum << " now_committing " << context.now_committing << Log::endl;
            pthread_cond_wait(&(context.init()->threadCond), &_context_ticketbooth);
          }
      }*/
      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      /*if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == myTicketNum) {
        macedbg(1) << context.contextID<<"Erasing our cv from the map." << Log::endl;
        context.commitConditionVariables.erase(context.commitConditionVariables.begin());
      }
      else if (context.commitConditionVariables.begin() != context.commitConditionVariables.end()) {
        macedbg(1) << context.contextID<<"FYI, first cv in map is for ticket " << context.commitConditionVariables.begin()->first << Log::endl;
      }*/

      /*
    //chuangw: FIXME: same as now_serving. In fullcontext model, it does not guarantee the next event to be comitted has the next smallest ticket number.
      //context.now_committing++;
      if( context.next_committing.empty() ){
          context.no_nextcommitting = true;
      }else{
          context.now_committing = context.next_committing.front();
          context.next_committing.pop();
          context.no_nextcommitting = false;
          if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == context.now_committing) {
            macedbg(1) << context.contextID<<"Now signalling ticket number " << context.now_committing << " (my ticket is " << myTicketNum << " )" << Log::endl;
            pthread_cond_broadcast(context.commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
          }
          else {
            ASSERTMSG(context.commitConditionVariables.begin() == context.commitConditionVariables.end() || context.commitConditionVariables.begin()->first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
          }
      }

      if( lastCommittedTicket < myTicketNum ){
        lastCommittedTicket = myTicketNum;
      }
      */
    }
};

}

#endif
