#ifndef _HIERARCHICALCONTEXTLOCK_H
#define _HIERARCHICALCONTEXTLOCK_H

// including headers
//#include "mace.h"
// uses snapshot by default
#include "Event.h"
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

/*class EventMessageEntry{
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
      //serviceobj->dispatchDeferredMessages( dest, message, rid );
      delete message;
  }
};*/

/*class DeferredMessages{
private:
  static pthread_mutex_t msgmutex;
  static pthread_cond_t eventCond;
  class DeferredEventMessages{
  friend class DeferredMessages;
  private:
    uint32_t messageCount;
    //std::queue< EventMessageEntry > entries;
    std::map<uint32_t, EventMessageEntry > entries;
  public:
    DeferredEventMessages(): messageCount(0){ }

    void enqueue(BaseMaceService* serviceobj, const MaceKey& dest, Message* param,  const registration_uid_t rid, const uint32_t msgcount){
      ADD_SELECTORS("DeferredEventMessages::enqueue");
      //entries.push( EventMessageEntry(serviceobj, dest, param, rid) );
      entries.insert( std::pair< uint32_t, EventMessageEntry>( msgcount ,  EventMessageEntry(serviceobj, dest, param, rid) ) );

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
        //pthread_cond_init( &eventCond, NULL );
        messageCount = msgcount;
        
        maceout<<"Event expect "<< msgcount <<" deferred msg. Only "<< entries.size() << "is available. Wait! eventCond "<< &eventCond <<Log::endl;
        pthread_cond_wait( &eventCond, &msgmutex);

      }
      ASSERT( entries.size() == msgcount );
      while( !entries.empty() ){
        EventMessageEntry& msgentry =  entries.begin()->second ;
        msgentry.send();
        //entries.pop();
        entries.erase(entries.begin());
      }
    }
  };
  typedef mace::map< uint64_t, DeferredEventMessages, SoftState > DeferredEventMessageType;
  static DeferredEventMessageType deferredMessages;

public:
  static void sendDeferred(){
    ADD_SELECTORS("DeferredMessages::sendDeferred");
    uint64_t eventID = ThreadStructure::myEvent().getEventID();
    ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContextID() ); // add so that downcall_route() knows this is sent by head.
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
  static void enqueue( BaseMaceService* serviceobj, const MaceKey& dest, Message* param,  const registration_uid_t rid, const uint64_t eventID, const uint32_t msgcount){
    ScopedLock sl( msgmutex );
    ADD_SELECTORS("DeferredMessages::enqueue");
    deferredMessages[eventID].enqueue( serviceobj, dest, param, rid, msgcount );
  }
};
*/

//class CommitToken;

class HierarchicalContextLock{
  private:
public:
    HierarchicalContextLock(Event& event, mace::string msg) {
        ADD_SELECTORS("HierarchicalContextLock::(constructor)");
        uint64_t myTicketNum = event.getEventID();
        macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;
        
    }
    static uint64_t getUncommittedEvents(){
      return ( now_serving - now_committing );
    }
    static void commit(){
        ADD_SELECTORS("HierarchicalContextLock::commit");
        const uint64_t myTicketNum = ThreadStructure::myEvent().getEventID();
        mace::ContextLock c_lock( mace::ContextBaseClass::headCommitContext, mace::ContextLock::WRITE_MODE );

        // chuangw: waiting for the commit token
        /*waitForToken();

        CommitToken newToken = createToken();*/
        //DeferredMessages::sendDeferred();

        //ThreadStructure::myEvent().sendSubevents();
        


        BaseMaceService::globalCommitEvent( myTicketNum );
        Accumulator::Instance(Accumulator::EVENT_COMMIT_COUNT)->accumulate(1); // increment committed event number

        if( myTicketNum == mace::Event::exitEventID ){
          endEventCommitted = true;
        }

        if( ThreadStructure::myEvent().eventType == mace::Event::HEADMIGRATIONEVENT ){
          // TODO: After HEADMIGRATION event is committed, this head node is not needed anymore. Terminate.
        }

        c_lock.downgrade( mace::ContextLock::NONE_MODE );
    }
    static uint64_t nextCommitting(){
      return now_committing;
    }
private:
    /*void sendSubevents(){

    }
    CommitToken createToken(){
      // chuangw: create a token which is used by the subevents.
    }
    void waitToken(){
      // chuangw:
      // check if the token has arrived,
      // if so, remove that token from record,
      // otherwise, wait to be unlocked.
    }
    void unlockToken(){
      // chuangw:
      // if an event is waiting at this token, signal it,
      // otherwise, store this token
    }*/

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
