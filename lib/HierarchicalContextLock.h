#ifndef _HIERARCHICALCONTEXTLOCK_H
#define _HIERARCHICALCONTEXTLOCK_H

// including headers
//#include "mace.h"
// uses snapshot by default
#include "HighLevelEvent.h"
#include "ScopedLock.h"
#include <pthread.h>
#include "MaceKey.h"
#include "ContextMapping.h"
#include "GlobalCommit.h"
//#include "Serializable.h"

namespace mace{

class HierarchicalContextLock{
  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();

        static ThreadSpecific* init();
        pthread_cond_t threadCond;

      private:
        static void initKey();
      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        
    }; // ThreadSpecific
public:
    HierarchicalContextLock(HighLevelEvent& event, mace::string msg) {
        ADD_SELECTORS("HierarchicalContextLock::(constructor)");
        // code adapted from mace::AgentLock::ticketBoothWait()... basically treating the event as if in READ mode.
        ScopedLock sl(ticketbooth);
        uint64_t myTicketNum = event.getEventID();

        pthread_cond_t threadCond;
        pthread_cond_init(&threadCond, NULL);
        
        if( myTicketNum > now_serving ){
            enteringEvents[ myTicketNum ] = &threadCond;
        }
        while (myTicketNum > now_serving ) {
          macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving  << Log::endl;
          pthread_cond_wait(&threadCond, &ticketbooth);
        }
        macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

        //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          enteringEvents.erase(enteringEvents.begin());
        }
        else if (enteringEvents.begin() != enteringEvents.end()) {
          macedbg(1) << "FYI, first cv in map is for event " << enteringEvents.begin()->first << Log::endl;
        }
 
        ASSERT(myTicketNum == now_serving); //Remove once working.
 				eventsQueue[myTicketNum] = msg;

        now_serving++;

        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == now_serving) {
          macedbg(1) << "Now signalling event number " << now_serving << " (my event is " << myTicketNum << " )" << Log::endl;
          pthread_cond_broadcast(enteringEvents.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(enteringEvents.begin() == enteringEvents.end() || enteringEvents.begin()->first > now_serving, "enteringEvents map contains CV for event already served!!!");
        }
    }
    static void commit(const uint64_t myTicketNum){
        ADD_SELECTORS("HierarchicalContextLock::commit");

        ScopedLock sl(ticketbooth);
        commitOrderWait(myTicketNum);
      
        GlobalCommit::commit(myTicketNum);// GlobalCommit commits all services in the service hierarchy

        //BaseMaceService::globalSnapshotRelease(myTicketNum);
    }
    static void commitOrderWait(const uint64_t myTicketNum) {
      ADD_SELECTORS("HierarchicalContextLock::commitOrderWait");

      pthread_cond_t& threadCond = ThreadSpecific::init()->threadCond;
      if (myTicketNum > now_committing ) {
        macedbg(1) << "Storing condition variable " << &threadCond << " for event " << myTicketNum << Log::endl;
        commitConditionVariables.insert( std::pair< uint64_t, pthread_cond_t* >( myTicketNum, &threadCond ) );
      }

      while (myTicketNum > now_committing) {
        macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_committing " << now_committing << Log::endl;
        pthread_cond_wait(&threadCond, &ticketbooth);
      }

      macedbg(1) << "Event " << myTicketNum << " being committed!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      std::map<uint64_t, pthread_cond_t*>::iterator condBegin = commitConditionVariables.begin();
      if ( !commitConditionVariables.empty() && condBegin->first == myTicketNum) {
        macedbg(1) << "Erasing our cv from the map." << Log::endl;
        commitConditionVariables.erase(condBegin);
        condBegin = commitConditionVariables.begin();
      }
      else if ( ! commitConditionVariables.empty()) {
        macedbg(1) << "FYI, first cv in map is for event " << condBegin->first << Log::endl;
      }

      ASSERT(myTicketNum == now_committing); //Remove once working.

      now_committing++;
      if (! commitConditionVariables.empty() && condBegin->first == now_committing) {
        macedbg(1) << "Now signalling event number " << now_committing << " (my event is " << myTicketNum << " )" << Log::endl;
        //pthread_cond_broadcast(commitConditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        pthread_cond_signal(condBegin->second); // only signal if this is a reader -- writers should signal on commit only.
      }
      else {
        ASSERTMSG(commitConditionVariables.empty() || condBegin->first > now_committing, "conditionVariables map contains CV for event already served!!!");
      }

    }
    static uint64_t nextCommitting(){
      return now_committing;
    }
private:

    static std::map<uint64_t, pthread_cond_t* >  enteringEvents;
    static uint64_t now_serving;
    static uint64_t now_committing;
    static uint32_t noLeafContexts;
    static mace::map<uint64_t, mace::set<mace::string> > eventSnapshotContextIDs;
    static std::map<uint64_t, pthread_cond_t*> commitConditionVariables; // Support for per-thread CVs, which gives per ticket CV support. Note: can just use the front of the queue to avoid lookups 
    static pthread_mutex_t ticketbooth;

		static mace::map<uint64_t, mace::string> eventsQueue;
		static mace::map<uint64_t, uint16_t> committingQueue;
		static uint64_t expectedCommiteEvent;
};

}
#endif
