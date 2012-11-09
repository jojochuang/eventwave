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
//#include "GlobalCommit.h"
#include "Accumulator.h"
#include "mace.h"
#include "ContextLock.h"
#include "Message.h"

namespace mace{

class EventMessageEntry{
private:
  BaseMaceService* serviceobj;
  const MaceKey dest;
  Message* message;
  const registration_uid_t rid;
public:
  EventMessageEntry( BaseMaceService* serviceobj, const MaceKey& dest, Message* message,  const registration_uid_t rid ):
   serviceobj( serviceobj ), dest( dest ), message( message ), rid (rid ) { }
  void send(){
      ADD_SELECTORS("EventMessageEntry::send");
      maceout<<"Send message to external world!"<<Log::endl;
      serviceobj->dispatchDeferredMessages( dest, message, rid );
      delete message;
  }
};

class DeferredMessages{
private:
  static pthread_mutex_t msgmutex;
  class DeferredEventMessages{
  friend class DeferredMessages;
  private:
    pthread_cond_t eventCond;
    uint32_t messageCount;
    std::queue< EventMessageEntry > entries;
  public:
    DeferredEventMessages(){

    }

    void enqueue(BaseMaceService* serviceobj, const MaceKey& dest, Message* param,  const registration_uid_t rid){
      ADD_SELECTORS("DeferredEventMessages::enqueue");
      entries.push( EventMessageEntry(serviceobj, dest, param, rid) );

      if( messageCount > 0 ){
        ASSERT( entries.size() <= messageCount );
        if( entries.size() == messageCount ){
          maceout<<"The event commit thread is waiting. Wake it up "<< &eventCond<<Log::endl;
          pthread_cond_signal( &eventCond );
        }
      }
    }

    void sendMessages(){
      ADD_SELECTORS("DeferredEventMessages::sendMessages");
      uint32_t msgcount = ThreadStructure::getEventMessageCount();
      ASSERT( entries.size() <= msgcount );
      if( entries.size() < msgcount ){ // some message are not delivered yet
        pthread_cond_init( &eventCond, NULL );
        messageCount = msgcount;
        
        maceout<<"Event expect "<< msgcount <<" deferred msg. Only "<< entries.size() << "is available. Wait! eventCond "<< &eventCond <<Log::endl;
        pthread_cond_wait( &eventCond, &msgmutex);

      }
      while( !entries.empty() ){
        EventMessageEntry& msgentry = entries.front();
        msgentry.send();
        entries.pop();
      }
    }
  };
  typedef mace::map< uint64_t, DeferredEventMessages, SoftState > DeferredEventMessageType;
  static DeferredEventMessageType deferredMessages;

public:
  static void sendDeferred(){
    ADD_SELECTORS("DeferredMessages::sendDeferred");
    uint64_t eventID = ThreadStructure::myEvent().getEventID();
    ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContext() );
    ScopedLock sl( msgmutex );
    if( ThreadStructure::getEventMessageCount() > 0 ){
      deferredMessages[eventID].sendMessages();
      deferredMessages.erase( eventID );
    }else{
      maceout<<"No message is deferred by this event "<< eventID << Log::endl;
      DeferredEventMessageType::iterator eventmsgIt = deferredMessages.find( eventID );
      ASSERT( eventmsgIt == deferredMessages.end() || eventmsgIt->second.entries.size() == 0 );
    }
  }
  static void enqueue( BaseMaceService* serviceobj, const MaceKey& dest, Message* param,  const registration_uid_t rid, const uint64_t eventID){
    ScopedLock sl( msgmutex );
    ADD_SELECTORS("DeferredMessages::enqueue");
    deferredMessages[eventID].enqueue( serviceobj, dest, param, rid );
  }
};


class HierarchicalContextLock{
  private:
public:
    HierarchicalContextLock(HighLevelEvent& event, mace::string msg) {
        ADD_SELECTORS("HierarchicalContextLock::(constructor)");
        uint64_t myTicketNum = event.getEventID();
        // code adapted from mace::AgentLock::ticketBoothWait()... basically treating the event as if in READ mode.
        /*ScopedLock sl(ticketbooth);
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
        */
        macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;
        
        /*

        //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          enteringEvents.erase(enteringEvents.begin());
        }
        else if (enteringEvents.begin() != enteringEvents.end()) {
          macedbg(1) << "FYI, first cv in map is for event " << enteringEvents.begin()->first << Log::endl;
        }
 
        ASSERT(myTicketNum == now_serving); //Remove once working.
 				//eventsQueue[myTicketNum] = msg;

        now_serving++;

        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == now_serving) {
          macedbg(1) << "Now signalling event number " << now_serving << " (my event is " << myTicketNum << " )" << Log::endl;
          pthread_cond_broadcast(enteringEvents.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(enteringEvents.begin() == enteringEvents.end() || enteringEvents.begin()->first > now_serving, "enteringEvents map contains CV for event already served!!!");
        }

        */
    }
    static uint64_t getUncommittedEvents(){
      return ( now_serving - now_committing );
    }
    static void commit(){
        ADD_SELECTORS("HierarchicalContextLock::commit");
        const uint64_t myTicketNum = ThreadStructure::myEvent().getEventID();
        mace::ContextLock c_lock( mace::ContextBaseClass::headCommitContext, mace::ContextLock::WRITE_MODE );

        DeferredMessages::sendDeferred();
        BaseMaceService::globalCommitEvent( myTicketNum );
        Accumulator::Instance(Accumulator::EVENT_COMMIT_COUNT)->accumulate(1);

        if( myTicketNum == mace::HighLevelEvent::exitEventID ){
          endEventCommitted = true;
        }

        c_lock.downgrade( mace::ContextLock::NONE_MODE );
    }
    /*static void commitOrderWait(const uint64_t myTicketNum) {
      ADD_SELECTORS("HierarchicalContextLock::commitOrderWait");

      pthread_cond_t threadCond;// = ThreadSpecific::init()->threadCond;
      pthread_cond_init(&threadCond, 0);

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

      pthread_cond_destroy(&threadCond);
    }*/
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


public:
    static bool endEventCommitted; // is true if the ENDEVENT commits
};

}
#endif
