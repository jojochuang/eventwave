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

  public:
    static const int8_t WRITE_MODE = 1;
    static const int8_t READ_MODE = 0;
    static const int8_t NONE_MODE = -1;
  public:

public:
    ContextLock( ContextBaseClass& ctx, int8_t requestedMode = WRITE_MODE ): context(ctx), contextThreadSpecific(ctx.init() ), requestedMode( requestedMode), priorMode(contextThreadSpecific->currentMode), myTicketNum(ThreadStructure::myEvent()){
        ADD_SELECTORS("ContextLock::(constructor)");

        ASSERT( myTicketNum > 0 );
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
                    maceerr<<context.contextID<<"uncommit event: ticket="<< uceventIt->first <<", mode=" << (int16_t)uceventIt->second << Log::endl;
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

        if( !( priorMode == NONE_MODE && requestedMode == NONE_MODE ) ){
            context.uncommittedEvents[ myTicketNum ] = requestedMode;
        }
    }
    void upgradeFromNone(){ // chuangw: OK... I think.  Need to double check
      ADD_SELECTORS("ContextLock::upgradeFromNone");
      ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

      ScopedLock sl(_context_ticketbooth);

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

      // make a local copy of the child context set while this lock still have exclusive access to the context.
      mace::set<mace::string>& subcontexts= ThreadStructure::getEventChildContexts( context.contextID );
      subcontexts = context.getChildContextID(); 

      if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
        macedbg(1) << context.contextID<<"Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
      }

      commitOrderWait();
    }

    void ticketBoothWait(int8_t requestedMode){
      ADD_SELECTORS("ContextLock::ticketBoothWait");

      //uint64_t myTicketNum = ThreadStructure::myTicket();
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
        macedbg(1)<< context.contextID << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << context.now_serving << " requestedMode " << (int16_t)requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;
        pthread_cond_wait(threadCond, &_context_ticketbooth);
      }

      macedbg(1) << context.contextID<<"Ticket " << myTicketNum << " being served!" << Log::endl;

      // XXX: chuangw: I don't see what this is used for.
      //ThreadStructure::markTicketServed();

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

    }

    ~ContextLock(){ 
    }
    
    void downgrade(int8_t newMode) {
      ADD_SELECTORS("ContextLock::downgrade");
      //int8_t runningMode = contextThreadSpecific->getCurrentMode();
      //uint64_t myTicketNum = ThreadStructure::myTicket();
      uint8_t runningMode = context.uncommittedEvents[ myTicketNum ];
      macedbg(1) << context.contextID<<"Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << (int16_t)runningMode << " newMode " << (int16_t)newMode << Log::endl;

      if( newMode == NONE_MODE ){ // remove from uncommited event list.
        context.uncommittedEvents.erase( myTicketNum );
      }

      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << context.contextID<<"Why was downgrade called?  Current mode is: " << (int16_t)runningMode << " and mode requested is: " << (int16_t)newMode << Log::endl;
      macedbg(1) << context.contextID<<"Downgrade exiting" << Log::endl;
    }
    void downgradeToNone(int8_t runningMode) {
        ADD_SELECTORS("ContextLock::downgradeToNone");
        ScopedLock sl(_context_ticketbooth);

        // make a local copy of the child context set while this lock still have  access to the context.
        mace::set<mace::string>& subcontexts= ThreadStructure::getEventChildContexts( context.contextID );
        subcontexts = context.getChildContextID(); 

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
      //uint64_t myTicketNum = ThreadStructure::myTicket();

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
    }
};

}

#endif
