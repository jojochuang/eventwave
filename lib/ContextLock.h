#ifndef _CONTEXTLOCK_H
#define _CONTEXTLOCK_H

// including headers
#include "mace.h"
#include "GlobalCommit.h"
#include "ContextBaseClass.h"
#include "pthread.h"
#include "ThreadStructure.h"
#include "m_map.h"
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
    //const int8_t priorMode;
    int8_t priorMode;
    uint64_t myTicketNum;
  private:
    static bool blockNewEventFlag;
    static pthread_mutex_t _context_ticketbooth; // chuangw: single ticketbooth for now. we will see if it'd become a bottleneck.
    //static pthread_mutex_t blockHeadMutex; 
    //static pthread_cond_t blockHeadCond;

  public:
    static const int8_t WRITE_MODE = 1;
    static const int8_t READ_MODE = 0;
    static const int8_t NONE_MODE = -1;

public:
    static void signalBlockedEvents();

    ContextLock( ContextBaseClass& ctx, int8_t requestedMode = WRITE_MODE ): context(ctx), contextThreadSpecific(ctx.init() ), requestedMode( requestedMode), /*priorMode(contextThreadSpecific->currentMode),*/ myTicketNum(ThreadStructure::myEvent().eventID){
        ADD_SELECTORS("ContextLock::(constructor)");
        ScopedLock sl(_context_ticketbooth);

        ASSERT( myTicketNum > 0 );

        if( myTicketNum < context.now_serving ){ // chuangw: this might potentially fail because no mutext protection
            mace::map<uint64_t, int8_t>::iterator uceventIt = context.uncommittedEvents.find( myTicketNum );
            if( uceventIt != context.uncommittedEvents.end() ){
                priorMode = uceventIt->second;
                if(  priorMode >= READ_MODE  && requestedMode == priorMode ){
                    return; // ready to go!
                }else if( (priorMode >= READ_MODE ) && requestedMode < priorMode ){
                    downgradeNoLock( requestedMode );
                    return;
                }else{
                    printError();
                    ABORT("unexpected event mode change");
                }
                macedbg(1) << "[" << context.contextID<<"] STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
            }else{
                printError();
                ABORT("ticket number is less than now_serving, but the ticket did not appear in uncommittedEvents list");
            }
        }
        priorMode = NONE_MODE; //contextThreadSpecific->currentMode;
        macedbg(1) << "[" << context.contextID<<"] STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
        if (priorMode == NONE_MODE) { // chuangw: OK mode transition
          // do what's needed
          if (requestedMode == NONE_MODE) {
            nullTicketNoLock(ctx);
          } else { // event initially at none mode. It can request to enter some mode.
              upgradeFromNone(); 
          }
        } /*else if (priorMode == READ_MODE) { // chuangw: OK mode transition
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
          downgrade( requestedMode );
        } else if (priorMode == WRITE_MODE) {// chuangw: OK mode transition
          ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
          downgrade( requestedMode );
        } else {// chuangw: OK mode transition
          ABORT("Unknown priorMode!");
        }*/
        macedbg(1) << "[" <<context.contextID <<"] CONTINUING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;

        if( !( priorMode == NONE_MODE && requestedMode == NONE_MODE ) ){
            context.uncommittedEvents[ myTicketNum ] = requestedMode;
        }
    }

    ~ContextLock(){ 
    }

    static void nullTicket(ContextBaseClass& ctx) {// chuangw: OK, I think.
      ScopedLock sl(_context_ticketbooth);
      nullTicketNoLock(ctx);
    }

    void downgrade(int8_t newMode) {
      ScopedLock sl(_context_ticketbooth);
      downgradeNoLock( newMode );
    }
    
private:
    static void nullTicketNoLock(ContextBaseClass& context) {// chuangw: OK, I think.
      ADD_SELECTORS("ContextLock::nullTicket");

      // chuangw: Instead of waiting, just simply mark this event as committed.

      const uint64_t skipID = ThreadStructure::getCurrentServiceEventSkipID();
      const uint64_t myTicketNum = ThreadStructure::myEvent().eventID;
      if( skipID == myTicketNum ){
        macedbg(1)<< "[" << context.contextID<< "] Insert event "<< myTicketNum <<" into bypassQueue."<<Log::endl;
        context.bypassQueue.insert( myTicketNum );
      }else{
        uint64_t markTicket;
        if( skipID+1 < context.now_serving ){ // this is possible if this context was created after skipID+1 event
          macedbg(1)<< "[" << context.contextID<< "] skipID+1 = "<< skipID+1 << " is less than now_serving "<< context.now_serving <<". Context is new?"<<Log::endl;
          markTicket = context.now_serving;
        }else{
          markTicket = skipID+1;
        }
        macedbg(1)<< "[" << context.contextID<< "] Insert event from "<< markTicket << " to "<< myTicketNum <<" into bypassQueue."<<Log::endl;
        for( ; markTicket <= myTicketNum; markTicket++){
          context.bypassQueue.insert( markTicket );
        }
      }

      bypassEvent(context);

      if(  context.conditionVariables.begin()->first == context.now_serving) {
        macedbg(1) << "[" << context.contextID <<"] Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }

      if( skipID == myTicketNum ){
        macedbg(1)<< "[" << context.contextID<< "] Insert event "<< myTicketNum <<" into commitBypassQueue."<<Log::endl;
        context.commitBypassQueue.insert( myTicketNum );
      }else{
        uint64_t markTicket;
        if( skipID+1 < context.now_committing ){
          markTicket = context.now_committing;
        }else{
          markTicket = skipID+1;
        }
        macedbg(1)<< "[" << context.contextID<< "] Insert event from "<< markTicket <<" to "<< myTicketNum << " into commitBypassQueue."<<Log::endl;
        for( ; markTicket <= myTicketNum; markTicket++){
          context.commitBypassQueue.insert( markTicket );
        }
      }

      bypassEventCommit(context);

      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == context.now_committing) {
        macedbg(1)<<  "[" << context.contextID << "] Now signalling ticket number " << context.now_committing << ", CV "<< context.commitConditionVariables.begin()->second << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.commitConditionVariables.empty() || context.commitConditionVariables.begin()->first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
      }

      //ASSERT( contextThreadSpecific->getCurrentMode() == NONE_MODE );
      //ticketBoothWait(NONE_MODE);

      /*if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
        macedbg(1) << "[" << context.contextID<<"] Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
      }*/

      //commitOrderWait();
    }
    void printError(){
      ADD_SELECTORS("ContextLock::printError");
      maceerr<< "[" << context.contextID<<"] myTicketNum = "<< myTicketNum <<"\n";
      maceerr<< "size of uncommittedEvents: "<< context.uncommittedEvents.size() <<"\n";
      for(mace::map<uint64_t, int8_t>::iterator uceventIt = context.uncommittedEvents.begin(); uceventIt != context.uncommittedEvents.end(); uceventIt++){
          maceerr<< "uncommit event: ticket="<< uceventIt->first <<", mode=" << (int16_t)uceventIt->second  << "\n";
      }
      maceerr<< "context.now_serving="<< context.now_serving <<", context.now_committing="<< context.now_committing<<Log::endl;
    }

    bool tooManyEvents();
    static void bypassEvent(ContextBaseClass& context){
      ADD_SELECTORS("ContextLock::bypassEvent");
      // increment now_serving counter if bypassQueue already contains that number
      while( !context.bypassQueue.empty() ){
        std::set<uint64_t>::iterator bypassIt = context.bypassQueue.begin();
        if( *bypassIt == context.now_serving ){
          macedbg(1)<< "[" << context.contextID<< "] increment now_serving to "<< context.now_serving <<Log::endl;
          context.now_serving++;
          context.bypassQueue.erase( context.bypassQueue.begin() );
        }else{
          break;
        }
      }
    }
    static void bypassEventCommit(ContextBaseClass& context){
      ADD_SELECTORS("ContextLock::bypassEventCommit");
      // increment now_committing counter if commitBypassQueue already contains that number
      while( !context.commitBypassQueue.empty() ){
        std::set<uint64_t>::iterator bypassIt = context.commitBypassQueue.begin();
        if( *bypassIt == context.now_committing ){
          context.now_committing++;
          macedbg(1)<< "[" << context.contextID<< "] increment now_committing to "<< context.now_committing <<Log::endl;
          context.commitBypassQueue.erase( context.commitBypassQueue.begin() );
        }else{
          break;
        }
      }
    }

    void upgradeFromNone(){ 
      ADD_SELECTORS("ContextLock::upgradeFromNone");
      ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

      // wait until my ticket is served
      ticketBoothWait(requestedMode);

      if (requestedMode == READ_MODE) {
        ASSERT(context.numWriters == 0);
        // store the snapshot version number
        // there's no change since the last write, so current context state
        // is versioned 'lastWrite'
        contextThreadSpecific->snapshotVersion = context.lastWrite;
        context.snapshot( context.lastWrite );

        // change mode
        //contextThreadSpecific->setCurrentMode(READ_MODE);
        context.uncommittedEvents[ myTicketNum ] = READ_MODE;
        // wake up the next waiting thread (which has the next smallest ticket number)
        if (context.conditionVariables.begin() != context.conditionVariables.end() ){
          bypassEvent(context);
          if(  context.conditionVariables.begin()->first == context.now_serving) {
            macedbg(1) << "[" << context.contextID <<"] Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
            pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
          }
        } else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
      } else if (requestedMode == WRITE_MODE) {
        //Acquire write lock
        ASSERT(context.numReaders == 0);
        ASSERT(context.numWriters == 0);
        //contextThreadSpecific->setCurrentMode(WRITE_MODE);
        context.uncommittedEvents[ myTicketNum ] = WRITE_MODE;
        context.numWriters = 1;
        context.lastWrite = myTicketNum;
      }
    }

    void ticketBoothWait(int8_t requestedMode){
      ADD_SELECTORS("ContextLock::ticketBoothWait");

      pthread_cond_t* threadCond = &(context.init()->threadCond);

      const uint64_t skipID = ThreadStructure::getCurrentServiceEventSkipID();
      const uint64_t waitID = (&context==&mace::ContextBaseClass::headContext)?myTicketNum:
        ( (skipID+1 < context.now_serving )? context.now_serving : 
        ( (skipID != myTicketNum)?skipID+1: myTicketNum ) 
      );
      
      if( !context.bypassQueue.empty() ){
        const uint64_t firstBypassTicket = *(context.bypassQueue.begin());
        if( skipID < myTicketNum ){
          ASSERTMSG( !(skipID < firstBypassTicket && firstBypassTicket <= myTicketNum), "There shouldn't be any bypass ticket between skipID and my event ID" );
        }
      }

      bypassEvent(context);

      // chuangw: logically, when now_serving == skipID+1, it should automatically ignore
      // event ticket from skipID+1 ~ myTicketNum-1, and then set now_serving = myTicketNum+1

      if (/*myTicketNum*/ waitID > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
         ) {
        macedbg(1)<< "[" << context.contextID << "] Storing condition variable " << threadCond << " at ticket " << /*myTicketNum*/ waitID << Log::endl;
        context.conditionVariables[/*myTicketNum*/ waitID] = threadCond;
      }else if( &context == &mace::ContextBaseClass::headContext ){
        if( tooManyEvents() ){
          macedbg(1)<< "[" << context.contextID << "] ratelimit: too many events. Storing condition variable " << threadCond << " at ticket " << /*myTicketNum*/ waitID << Log::endl;
          context.conditionVariables[/*myTicketNum*/ waitID] = threadCond;
        }
      }


      while ( (/*myTicketNum*/ waitID > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )


          ) || ( &context == &mace::ContextBaseClass::headContext && tooManyEvents() ) )  {


        macedbg(1)<< "[" << context.contextID << "] Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " wait until ticket " << waitID << ", now_serving " << context.now_serving << " requestedMode " << (int16_t)requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;
        pthread_cond_wait(threadCond, &_context_ticketbooth);

        if( (&context == &mace::ContextBaseClass::headContext) && (context.notifiedHeadEventID == context.now_serving) ) { break; } // if signaled by committed event
      }


      macedbg(1) << "[" << context.contextID<< "] Ticket " << myTicketNum << " being served! waitID = "<< waitID << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (!context.conditionVariables.empty() && context.conditionVariables.begin()->first == /*myTicketNum*/ waitID) {
        macedbg(1) << "[" << context.contextID<<"] Erasing our cv from the map." << Log::endl;
        context.conditionVariables.erase(context.conditionVariables.begin());
      }
      else if (!context.conditionVariables.empty()) {
        macedbg(1) << "[" << context.contextID<<"] FYI, first cv in map is for ticket " << context.conditionVariables.begin()->first << Log::endl;
      }

      //ASSERT(myTicketNum == context.now_serving); //Remove once working.
      ASSERT(waitID == context.now_serving); //Remove once working.

      //context.now_serving++;
      context.now_serving = myTicketNum+1;

    }
    void downgradeNoLock(int8_t newMode) {
      ADD_SELECTORS("ContextLock::downgrade");
      ASSERTMSG( context.uncommittedEvents.find( myTicketNum ) != context.uncommittedEvents.end(), "ticket number not found in uncommittedEvent");
      uint8_t runningMode = context.uncommittedEvents[ myTicketNum ];
      macedbg(1) << "[" << context.contextID<<"] Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << (int16_t)runningMode << " newMode " << (int16_t)newMode << Log::endl;

      if( newMode == NONE_MODE ){ // remove from uncommited event list.
        context.uncommittedEvents.erase( myTicketNum );
      }

      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << "[" << context.contextID<<"] Why was downgrade called?  Current mode is: " << (int16_t)runningMode << " and mode requested is: " << (int16_t)newMode << Log::endl;
      macedbg(1) << "[" << context.contextID<<"] Downgrade exiting" << Log::endl;
    }
    void downgradeToNone(int8_t runningMode) {
        ADD_SELECTORS("ContextLock::downgradeToNone");

        bool doGlobalRelease = false;
        if (runningMode == READ_MODE) {
            ASSERT(context.numReaders == 0);
            if (contextThreadSpecific->getSnapshotVersion() == myTicketNum) { //I did a write, and have now committed!
              doGlobalRelease = true;
            }
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(context.numReaders == 0 && context.numWriters == 1);
          context.numWriters=0;
          doGlobalRelease = true;
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "[" << context.contextID<<"] After lock release - numReaders " << context.numReaders << " numWriters " << context.numWriters << Log::endl;
        //contextThreadSpecific->setCurrentMode(NONE_MODE);
        //context.uncommittedEvents[ myTicketNum ] = NONE_MODE;

        bypassEvent(context);

        if (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) {
          if( (&context == &mace::ContextBaseClass::headContext) && tooManyEvents() ){
            macedbg(1) << "[" << context.contextID<<"] Next event " <<  context.now_serving << " is ready, but too many events. block"  << Log::endl;
          }else{
            macedbg(1) << "[" << context.contextID<<"] Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
            pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
          }
        }
        else {
          ASSERTMSG(context.conditionVariables.begin() == context.conditionVariables.end() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
        macedbg(1) << "[" << context.contextID <<"] now_serving="<< context.now_serving << " Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait();
        macedbg(1) << "[" << context.contextID<<"] Commiting ticket " << myTicketNum << Log::endl;

        if (doGlobalRelease) {
          context.snapshotRelease( myTicketNum );
        }
        macedbg(1) << "[" << context.contextID<<"] Downgrade to NONE_MODE complete" << Log::endl;
    }
    void downgradeToRead() {
      ADD_SELECTORS("ContextLock::downgradeToRead");
        macedbg(1) << "[" << context.contextID<<"] Downgrade to READ_MODE reqested" << Log::endl;
        //ScopedLock sl(_context_ticketbooth);
        ASSERT(context.numWriters == 1 && context.numReaders == 0);
        ASSERT(context.now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        context.numWriters = 0;
        contextThreadSpecific->setSnapshotVersion(context.lastWrite);
        context.snapshot( context.lastWrite );

        //contextThreadSpecific->setCurrentMode(READ_MODE);
        context.uncommittedEvents[ myTicketNum ] = READ_MODE;

        bypassEvent(context);
        if (!context.conditionVariables.empty() && context.conditionVariables.begin()->first == context.now_serving) {
          macedbg(1) << "[" << context.contextID<<"] Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.empty() || context.conditionVariables.begin()->first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
    }
    void commitOrderWait() {
      ADD_SELECTORS("ContextLock::commitOrderWait");

      const uint64_t skipID = ThreadStructure::getCurrentServiceEventSkipID();
      const uint64_t waitID = (&context==&mace::ContextBaseClass::headContext)?myTicketNum:
        ( (skipID+1 < context.now_committing )? context.now_committing : 
        ( (skipID != myTicketNum)?skipID+1: myTicketNum ) 
      );

      if( !context.commitBypassQueue.empty() ){
        const uint64_t firstBypassTicket = *(context.commitBypassQueue.begin());
        if( skipID < myTicketNum ){
          ASSERTMSG( !(skipID < firstBypassTicket && firstBypassTicket <= myTicketNum), "There shouldn't be any bypass ticket between skipID and my event ID" );
        }
      }

      bypassEventCommit(context);

      if (/*myTicketNum*/ waitID > context.now_committing ) {
        macedbg(1)<< "[" << context.contextID << "] Storing condition variable " << &(context.init()->threadCond) << " at ticket " << /*myTicketNum*/ waitID << Log::endl;
        context.commitConditionVariables[/*myTicketNum*/ waitID] = &(context.init()->threadCond);
      }
      while (/*myTicketNum*/ waitID > context.now_committing) {
        macedbg(1)<< "[" <<  context.contextID << "] Waiting for my turn on cv " << &(context.init()->threadCond) << ".  myTicketNum " << myTicketNum << " wait until ticket " << waitID << ", now_committing " << context.now_committing << Log::endl;

        ASSERT(  &(context.init()->threadCond) == context.commitConditionVariables[/*myTicketNum*/ waitID] );

        pthread_cond_wait(&(context.init()->threadCond), &_context_ticketbooth);
      }

      macedbg(1) << "[" <<  context.contextID<<"] Ticket " << myTicketNum << " being committed at context '" <<context.contextID << "'! waitID = "<< waitID << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == /*myTicketNum*/ waitID) {
        macedbg(1)<<  "[" << context.contextID << "] Erasing our cv from the map." << Log::endl;
        context.commitConditionVariables.erase(context.commitConditionVariables.begin());
      }
      else if (context.commitConditionVariables.begin() != context.commitConditionVariables.end()) {
        macedbg(1)<<  "[" << context.contextID << "] FYI, first cv in map is for ticket " << context.commitConditionVariables.begin()->first << Log::endl;
      }
      //ASSERT(myTicketNum == context.now_committing); //Remove once working.
      ASSERT(waitID == context.now_committing); //Remove once working.

      //context.now_committing++;
      context.now_committing = myTicketNum+1;

      bypassEventCommit(context);



      if (context.commitConditionVariables.begin() != context.commitConditionVariables.end() && context.commitConditionVariables.begin()->first == context.now_committing) {
        macedbg(1)<<  "[" << context.contextID << "] Now signalling ticket number " << context.now_committing << ", CV "<< context.commitConditionVariables.begin()->second << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.commitConditionVariables.empty() || context.commitConditionVariables.begin()->first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
      }
    }
};

}

#endif
