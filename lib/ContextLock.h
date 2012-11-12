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
  public:
    const int8_t requestedMode;
    int8_t priorMode;
    uint64_t myTicketNum;
  private:
    static bool blockNewEventFlag;
    pthread_mutex_t& _context_ticketbooth;
    pthread_cond_t threadCond;
    const uint64_t skipID;
  public:
    static const int8_t WRITE_MODE = 1;
    static const int8_t READ_MODE = 0;
    static const int8_t NONE_MODE = -1;

public:
    static void signalBlockedEvents();

    ContextLock( ContextBaseClass& ctx, int8_t requestedMode = WRITE_MODE ): context(ctx), /*contextThreadSpecific(ctx.init() ),*/ requestedMode( requestedMode), /*priorMode(contextThreadSpecific->currentMode),*/ myTicketNum(ThreadStructure::myEvent().eventID), _context_ticketbooth(context._context_ticketbooth ),
    skipID( (context.contextType == mace::ContextBaseClass::HEAD)?myTicketNum: 
        (ThreadStructure::getEventSkipID(context.serviceID, context.contextID, context.parentID) ) )
    {
        ADD_SELECTORS("ContextLock::(constructor)");
        ScopedLock sl(_context_ticketbooth);

        ASSERT( myTicketNum > 0 );

        if( myTicketNum < context.now_serving ){ 
            pthread_cond_init( &threadCond, NULL );
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
                macedbg(1) << "[" << context.contextName<<"] STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
            }else{
                printError();
                ABORT("ticket number is less than now_serving, but the ticket did not appear in uncommittedEvents list");
            }
        }
        priorMode = NONE_MODE;
        macedbg(1) << "[" << context.contextName<<"] STARTING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;
        //if (priorMode == NONE_MODE) { // chuangw: OK mode transition
          // do what's needed
          if (requestedMode == NONE_MODE) {
            nullTicketNoLock(ctx, skipID);
          } else { // event initially at none mode. It can request to enter some mode.
              pthread_cond_init( &threadCond, NULL );
              upgradeFromNone(); 
          }
        //}
        macedbg(1) << "[" <<context.contextName <<"] CONTINUING.  priorMode " << (int16_t)priorMode << " requestedMode " << (int16_t)requestedMode << " myTicketNum " << myTicketNum << Log::endl;

        if( !( priorMode == NONE_MODE && requestedMode == NONE_MODE ) ){
            context.uncommittedEvents[ myTicketNum ] = requestedMode;
        }
    }

    ~ContextLock(){ 
    }

    static void nullTicket(ContextBaseClass& ctx) {// chuangw: OK, I think.
      const uint64_t skipID = ( /*(ctx.contextType == mace::ContextBaseClass::HEAD)?myTicketNum: */
        (ThreadStructure::getEventSkipID(ctx.serviceID, ctx.contextID, ctx.parentID) ) );

      ScopedLock sl(ctx._context_ticketbooth);
      nullTicketNoLock(ctx, skipID);
    }

    void downgrade(int8_t newMode) {
      ScopedLock sl(_context_ticketbooth);
      downgradeNoLock( newMode );
    }
    
private:
    static void nullTicketNoLock(ContextBaseClass& context, const uint64_t skipID) {// chuangw: OK, I think.
      ADD_SELECTORS("ContextLock::nullTicket");

      // chuangw: Instead of waiting, just simply mark this event as committed.

      const uint64_t myTicketNum = ThreadStructure::myEvent().eventID;
      const uint64_t markTicket = (skipID == myTicketNum)? myTicketNum: (skipID+1 );
      if( skipID == myTicketNum ){
        macedbg(1)<< "[" << context.contextName<< "] Insert event "<< myTicketNum <<" into bypassQueue."<<Log::endl;
      }else{
        ASSERTMSG( skipID+1 >= context.now_serving, "skipID+1 shouldn't be less than now_serving");
        macedbg(1)<< "[" << context.contextName<< "] Insert event from "<< markTicket << " to "<< myTicketNum <<" into bypassQueue."<<Log::endl;
      }
      context.bypassQueue.insert( std::pair<uint64_t, uint64_t>( markTicket, myTicketNum ) );

      if( markTicket == context.now_serving ){
        bypassEvent(context);
      }

      if( !context.conditionVariables.empty() && context.conditionVariables.top().first == context.now_serving) {
        macedbg(1) << "[" << context.contextName <<"] Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.conditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
      }

      if( skipID == myTicketNum ){
        macedbg(1)<< "[" << context.contextName<< "] Insert event "<< myTicketNum <<" into commitBypassQueue."<<Log::endl;
      }else{
        macedbg(1)<< "[" << context.contextName<< "] Insert event from "<< markTicket <<" to "<< myTicketNum << " into commitBypassQueue."<<Log::endl;
      }
      context.commitBypassQueue.insert( std::pair<uint64_t, uint64_t>( markTicket, myTicketNum ) );

      if( markTicket == context.now_committing ){
        bypassEventCommit(context);
      }

      if ( !context.commitConditionVariables.empty() && context.commitConditionVariables.top().first == context.now_committing) {
        macedbg(1)<<  "[" << context.contextName << "] Now signalling ticket number " << context.now_committing << ", CV "<< context.commitConditionVariables.top().second << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.commitConditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.commitConditionVariables.empty() || context.commitConditionVariables.top().first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
      }

    }
    void printError(){
      ADD_SELECTORS("ContextLock::printError");
      maceerr<< "[" << context.contextName<<"] myTicketNum = "<< myTicketNum <<"\n";
      maceerr<< "size of uncommittedEvents: "<< context.uncommittedEvents.size() <<"\n";
      for(mace::map<uint64_t, int8_t>::iterator uceventIt = context.uncommittedEvents.begin(); uceventIt != context.uncommittedEvents.end(); uceventIt++){
          maceerr<< "uncommit event: ticket="<< uceventIt->first <<", mode=" << (int16_t)uceventIt->second  << "\n";
      }
      maceerr<< "context.now_serving="<< context.now_serving <<", context.now_committing="<< context.now_committing<<Log::endl;
    }

    static void bypassEvent(ContextBaseClass& context){
      ADD_SELECTORS("ContextLock::bypassEvent");
      // increment now_serving counter if bypassQueue already contains that number
      mace::ContextBaseClass::BypassQueueType::iterator bypassIt =  context.bypassQueue.begin();
      while( bypassIt != context.bypassQueue.end() ){
        if( (*bypassIt).first == context.now_serving ){
          context.now_serving = (*bypassIt).second+1;
          bypassIt++;
          macedbg(1)<< "[" << context.contextName<< "] increment now_serving to "<< context.now_serving <<Log::endl;
        }else{
          break;
        }
      }
      context.bypassQueue.erase( context.bypassQueue.begin(), bypassIt );
    }
    static void bypassEventCommit(ContextBaseClass& context){
      ADD_SELECTORS("ContextLock::bypassEventCommit");
      mace::ContextBaseClass::BypassQueueType::iterator bypassIt =  context.commitBypassQueue.begin();
      while( bypassIt != context.commitBypassQueue.end() ){
        if( (*bypassIt).first == context.now_committing ){
          context.now_committing = (*bypassIt).second+1;
          bypassIt++;
          macedbg(1)<< "[" << context.contextName<< "] increment now_committing to "<< context.now_committing <<Log::endl;
        }else{
          break;
        }
      }
      context.commitBypassQueue.erase( context.commitBypassQueue.begin(), bypassIt );
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
        //contextThreadSpecific->snapshotVersion = context.lastWrite;
        context.snapshot( context.lastWrite );

        // change mode
        context.uncommittedEvents[ myTicketNum ] = READ_MODE;
        // wake up the next waiting thread (which has the next smallest ticket number)
        if ( !context.conditionVariables.empty() ){
          bypassEvent(context);
          if(  context.conditionVariables.top().first == context.now_serving) {
            macedbg(1) << "[" << context.contextName <<"] Now signalling ticket number " << context.now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
            pthread_cond_broadcast(context.conditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
          }
        } else {
          ASSERTMSG(context.conditionVariables.empty() || context.conditionVariables.top().first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
      } else if (requestedMode == WRITE_MODE) {
        //Acquire write lock
        ASSERT(context.numReaders == 0);
        ASSERT(context.numWriters == 0);
        context.uncommittedEvents[ myTicketNum ] = WRITE_MODE;
        context.numWriters = 1;
        context.lastWrite = myTicketNum;
      }
    }

    void ticketBoothWait(int8_t requestedMode){
      ADD_SELECTORS("ContextLock::ticketBoothWait");

      //pthread_cond_t* threadCond = &(contextThreadSpecific->threadCond);

      ASSERTMSG( skipID+1 >= context.now_serving, "skipID+1 shouldn't be less than now_serving");

      const uint64_t waitID = (context.contextType == mace::ContextBaseClass::HEAD)?myTicketNum:
        ( (skipID+1 < context.now_serving )? context.now_serving : 
        ( (skipID != myTicketNum)?skipID+1: myTicketNum ) 
      );
      
      if( !context.bypassQueue.empty() ){
        const uint64_t firstBypassTicket = (*context.bypassQueue.begin()).first;
        if( skipID < myTicketNum ){
          ASSERTMSG( !(skipID < firstBypassTicket && firstBypassTicket <= myTicketNum), "There shouldn't be any bypass ticket between skipID and my event ID" );
        }
      }

      bypassEvent(context);

      // chuangw: logically, when now_serving == skipID+1, it should automatically ignore
      // event ticket from skipID+1 ~ myTicketNum-1, and then set now_serving = myTicketNum+1

      if ( waitID > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )
         ) {
        macedbg(1)<< "[" << context.contextName << "] Storing condition variable " << &threadCond << " at ticket " <<  waitID << Log::endl;
        //ASSERT(context.conditionVariables.count(waitID) == 0 );
        context.conditionVariables.push( std::pair<uint64_t, pthread_cond_t*>( waitID, &threadCond ) );
      }/*else if( &context == &mace::ContextBaseClass::headContext ){
        if( tooManyEvents() ){
          macedbg(1)<< "[" << context.contextID << "] ratelimit: too many events. Storing condition variable " << threadCond << " at ticket " <<  waitID << Log::endl;
          ASSERT(context.conditionVariables.find(waitID) == context.conditionVariables.end() );
          context.conditionVariables[ waitID] = threadCond;
        }
      }*/


      while ( ( waitID > context.now_serving ||
          ( requestedMode == READ_MODE && (context.numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (context.numReaders != 0 || context.numWriters != 0) )


          ) /*|| ( &context == &mace::ContextBaseClass::headContext && tooManyEvents() )*/ )  {


        macedbg(1)<< "[" << context.contextName << "] Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " wait until ticket " << waitID << ", now_serving " << context.now_serving << " requestedMode " << (int16_t)requestedMode << " numWriters " << context.numWriters << " numReaders " << context.numReaders << Log::endl;
        pthread_cond_wait(&threadCond, &_context_ticketbooth);

        //if( (context.contextType == mace::ContextBaseClass::HEAD) && (context.notifiedHeadEventID == context.now_serving) ) { break; } // if signaled by committed event
      }


      macedbg(1) << "[" << context.contextName<< "] Ticket " << myTicketNum << " being served! waitID = "<< waitID << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if (!context.conditionVariables.empty() && context.conditionVariables.top().first ==  waitID) {
        macedbg(1) << "[" << context.contextName<<"] Erasing our cv from the map." << Log::endl;
        context.conditionVariables.pop();
      }
      else if (!context.conditionVariables.empty()) {
        macedbg(1) << "[" << context.contextName<<"] FYI, first cv in map is for ticket " << context.conditionVariables.top().first << Log::endl;
      }

      ASSERT(waitID == context.now_serving); //Remove once working.

      context.now_serving = myTicketNum+1;

    }
    void downgradeNoLock(int8_t newMode) {
      ADD_SELECTORS("ContextLock::downgrade");
      mace::map<uint64_t, int8_t>::iterator ticketIt = context.uncommittedEvents.find( myTicketNum );
      ASSERTMSG( ticketIt != context.uncommittedEvents.end(), "ticket number not found in uncommittedEvent");
      uint8_t runningMode = ticketIt->second;
      macedbg(1) << "[" << context.contextName<<"] Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << (int16_t)runningMode << " newMode " << (int16_t)newMode << Log::endl;

      if( newMode == NONE_MODE ){ // remove from uncommited event list.
        context.uncommittedEvents.erase( ticketIt );
      }

      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << "[" << context.contextName<<"] Why was downgrade called?  Current mode is: " << (int16_t)runningMode << " and mode requested is: " << (int16_t)newMode << Log::endl;
      macedbg(1) << "[" << context.contextName<<"] Downgrade exiting" << Log::endl;
    }
    void downgradeToNone(int8_t runningMode) {
        ADD_SELECTORS("ContextLock::downgradeToNone");

        //bool doGlobalRelease = false;
        if (runningMode == READ_MODE) {
            ASSERT(context.numReaders == 0);
            /*if (contextThreadSpecific->getSnapshotVersion() == myTicketNum) { //I did a write, and have now committed!
              doGlobalRelease = true;
            }*/
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(context.numReaders == 0 && context.numWriters == 1);
          context.numWriters=0;
          /*doGlobalRelease = true;*/
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "[" << context.contextName<<"] After lock release - numReaders " << context.numReaders << " numWriters " << context.numWriters << Log::endl;
        //contextThreadSpecific->setCurrentMode(NONE_MODE);

        bypassEvent(context);

        if ( !context.conditionVariables.empty() && context.conditionVariables.top().first == context.now_serving) {
          /*if( (&context == &mace::ContextBaseClass::headContext) && tooManyEvents() ){
            macedbg(1) << "[" << context.contextID<<"] Next event " <<  context.now_serving << " is ready, but too many events. block"  << Log::endl;
          }else{*/
            macedbg(1) << "[" << context.contextName<<"] Signalling CV " << context.conditionVariables.top().second << " for ticket " << context.now_serving << Log::endl;
            pthread_cond_broadcast(context.conditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
          /*} */
        }
        else {
          ASSERTMSG(context.conditionVariables.empty() || context.conditionVariables.top().first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
        macedbg(1) << "[" << context.contextName <<"] now_serving="<< context.now_serving << " Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait();
        macedbg(1) << "[" << context.contextName<<"] Commiting ticket " << myTicketNum << Log::endl;

        /*if (doGlobalRelease) {
          context.snapshotRelease( myTicketNum );
        }*/
        macedbg(1) << "[" << context.contextName<<"] Downgrade to NONE_MODE complete" << Log::endl;
    }
    void downgradeToRead() {
      ADD_SELECTORS("ContextLock::downgradeToRead");
        macedbg(1) << "[" << context.contextName<<"] Downgrade to READ_MODE reqested" << Log::endl;
        ASSERT(context.numWriters == 1 && context.numReaders == 0);
        ASSERT(context.now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        context.numWriters = 0;
        //contextThreadSpecific->setSnapshotVersion(context.lastWrite);
        context.snapshot( context.lastWrite );

        context.uncommittedEvents[ myTicketNum ] = READ_MODE;

        bypassEvent(context);
        if (!context.conditionVariables.empty() && context.conditionVariables.top().first == context.now_serving) {
          macedbg(1) << "[" << context.contextName<<"] Signalling CV " << context.conditionVariables.top().second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(context.conditionVariables.empty() || context.conditionVariables.top().first > context.now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
    }
    void commitOrderWait() {
      ADD_SELECTORS("ContextLock::commitOrderWait");

      ASSERTMSG( skipID+1 >= context.now_committing, "skipID+1 shouldn't be less than now_committing");

      const uint64_t waitID = (context.contextType == mace::ContextBaseClass::HEAD)?myTicketNum:
        ( (skipID+1 < context.now_committing )? context.now_committing : 
        ( (skipID != myTicketNum)?skipID+1: myTicketNum ) 
      );

      if( !context.commitBypassQueue.empty() ){
        const uint64_t firstBypassTicket = (*context.commitBypassQueue.begin()).first;
        if( skipID < myTicketNum ){
          ASSERTMSG( !(skipID < firstBypassTicket && firstBypassTicket <= myTicketNum), "There shouldn't be any bypass ticket between skipID and my event ID" );
        }
      }

      bypassEventCommit(context);

      if ( waitID > context.now_committing ) {
        macedbg(1)<< "[" << context.contextName << "] Storing condition variable " << &threadCond << " at ticket " <<  waitID << Log::endl;
        //ASSERT(context.commitConditionVariables.count(waitID) == 0 );
        context.commitConditionVariables.push( std::pair< uint64_t, pthread_cond_t*>( waitID, &threadCond ) );
      }
      while ( waitID > context.now_committing) {
        macedbg(1)<< "[" <<  context.contextName << "] Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " wait until ticket " << waitID << ", now_committing " << context.now_committing << Log::endl;

        //ASSERT(  &(threadCond) == context.commitConditionVariables[ waitID] );

        pthread_cond_wait(&(threadCond), &_context_ticketbooth);
      }

      macedbg(1) << "[" <<  context.contextName<<"] Ticket " << myTicketNum << " being committed at context '" <<context.contextName << "'! waitID = "<< waitID << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if ( !context.commitConditionVariables.empty() && context.commitConditionVariables.top().first ==  waitID) {
        macedbg(1)<<  "[" << context.contextName << "] Erasing our cv from the map." << Log::endl;
        context.commitConditionVariables.pop();
      }
      else if ( !context.commitConditionVariables.empty()) {
        macedbg(1)<<  "[" << context.contextName << "] FYI, first cv in map is for ticket " << context.commitConditionVariables.top().first << Log::endl;
      }
      ASSERT(waitID == context.now_committing); //Remove once working.

      context.now_committing = myTicketNum+1;

      bypassEventCommit(context);



      if ( !context.commitConditionVariables.empty() && context.commitConditionVariables.top().first == context.now_committing) {
        macedbg(1)<<  "[" << context.contextName << "] Now signalling ticket number " << context.now_committing << ", CV "<< context.commitConditionVariables.top().second << " (my ticket is " << myTicketNum << " )" << Log::endl;
        pthread_cond_broadcast(context.commitConditionVariables.top().second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(context.commitConditionVariables.empty() || context.commitConditionVariables.top().first > context.now_committing, "conditionVariables map contains CV for ticket already served!!!");
      }
    }
};

}

#endif
