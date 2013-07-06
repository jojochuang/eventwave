/* 
 * mace.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of the contributors, nor their associated universities 
 *      or organizations may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */

#ifndef _MACE_H
#define _MACE_H

/**
 * \file mace.h
 * \brief declares BaseMaceService
 */

/*
#include "CommitWrapper.h"
extern std::set<mace::commit_executor*> registered;
extern std::set<mace::CommitWrapper*> registered_class;
*/
#include "Scheduler.h"
#include "ThreadStructure.h"
#include "GlobalCommit.h"
#include "mlist.h"
#include <utility>
#include "Accumulator.h"
#include "EventExtraField.h"
#include "SpecialMessage.h"
#include <queue>

//#ifdef USE_SNAPSHOT
static const bool USING_RWLOCK = false;
/*#else
static const bool USING_RWLOCK = true;
#endif
*/

extern int32_t __eventContextType; // used in simmain.cc to determine the context type of the event.

class AsyncEventReceiver {};

/**
 * \brief Base class for all generated Mace services.
 *
 * Provides the agentlock shared by all services, and a virtual method to allow
 * deferred actions to occur.
 */
namespace mace{
  class Message;
  class ContextMapping;
  class AsyncEvent_Message;
}
class BaseMaceService : public AsyncEventReceiver
{

public:
  /**
   * Constructor
   *
   * @param enqueueService store this service in the instance stack
   * */
  BaseMaceService(bool enqueueService = true): instanceUniqueID( 0 )
  {
    if (enqueueService) {
      instances.push_back(this);
    }
  }
  /**
   * Destructor
   *
   * */
  virtual ~BaseMaceService() {}

  static BaseMaceService* getInstance( const uint8_t sid );
  void registerInstanceID( );
  /**
   * Migrate context
   * If the context does not exist yet, ignore the request, but store the mapping so that when the context is created, it is created at the destination node.
   *
   * @param serviceID the numerical ID of the target service
   * @param contextID the numerical ID of the target context
   * @param destNode the destination node where the context will be migrated
   * @param rootOnly whether or not to migrate the subcontexts as well.
   * */
  virtual void requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly) = 0;

  virtual int deserializeMethod( std::istream & is, mace::Message *& request   ) = 0;

  /**
   * An interface that services must implement to send external messages
   *
   * @param dest destination MaceKey
   * @param message the message in serialized form
   * @param rid registration id of the transport service
   * */
  virtual void dispatchDeferredMessages(MaceKey const& dest, mace::string const& message,  registration_uid_t const rid ) = 0;

  /// functions that are generated in perl compiler
  virtual void executeEvent( mace::AsyncEvent_Message* const eventObject ) = 0;
  /**
   * An interface that services must implement to execute upcalls that leaves fullcontext world.
   * These upcalls are called only after the event commits
   *
   * @param payload serialized upcall
   * @param returnValue return value of the upcall transition, serialized.
   * */
  virtual void executeDeferredUpcall(  mace::ApplicationUpcall_Message* const upcall, mace::string& returnValue ) = 0;

  virtual void executeRoutine( mace::Routine_Message* const routineobject, mace::MaceAddr const& source ) = 0;

  /**
   * initialize an event and send it to the start context 
   *
   * @param msgObject the pointer to the event object 
   * */
  virtual void createEvent(mace::AsyncEvent_Message* msgObject) = 0;

  /// WC: deprecated
  static uint64_t lastSnapshot;
  /// WC: deprecated
  static uint64_t lastSnapshotReleased;
  //Agent Stuff
  static pthread_mutex_t synclock;  ///< Formerly, the "agent lock", held when executing nearly any code in a service.  Recursive to allow recursive calls.  Now used to protect synchronization of sync methods.
  static bool _printLower;

  /// WC: deprecated
  static void globalSnapshot(const uint64_t& ver); ///< Called to cause all services to snapshot their current state as version ver.
  /// WC: deprecated
  static void globalSnapshotRelease(const uint64_t& ver); ///< Called to cause all services to delete their snapshot prior to version ver.

  // WC: deprecated
  virtual void snapshot(const uint64_t& ver) const = 0; ///< Implemented by each service to make versioned snapshots.
  // WC: deprecated
  virtual void snapshotRelease(const uint64_t& ver) const = 0; ///< Implemented by each service to make versioned snapshots.
  // WC: processDeferred is deprecated 
  virtual void processDeferred() {} ///< Implemented by each service to process deferral queues, when directionality won't allow a call to be made immediately.
protected:
  /**
   * called when an event is found to start from a new context. When an event is initialized in a service, notify other services in the hierarchy 
   * @param event the current event
   * @param serviceID the originating service ID
   * */
  static void globalNotifyNewContext( mace::Event & event, const uint8_t serviceID );
  /**
   * The interface that services need to implement. Called by globalNotifyNewContext()
   * @param event the current event
   * @param serviceID the originating service ID
   * */
  virtual void notifyNewContext( mace::Event & event, const uint8_t serviceID ) = 0;

  /**
   * called when initialize an event. When an event is initialized in a service, notify other services in the hierarchy 
   * @param event the current event
   * @param serviceID the originating service ID
   * */
  static void globalNotifyNewEvent( mace::Event & event, const uint8_t serviceID );
  /**
   * The interface that services need to implement. Called by globalNotifyNewEvent()
   * @param event the current event
   * @param serviceID the originating service ID
   * */
  virtual void notifyNewEvent( mace::Event & event, const uint8_t serviceID ) = 0;

  /**
   * Called when an event is finished to downgrade any contexts that the event holds the lock.
   * */
  static void globalDowngradeEventContext( );
  /**
   * An interface to be implemented. Called by globalDowngradeEventContext() to downgrade contexts
   * */
  virtual void downgradeEventContext( ) = 0;
  /**
   * downgrade the current context, and take a snapshot of its state, so that the next event can enter the context
   * */
  void downgradeCurrentContext() const;
  /**
   * acquires context locks 
   * @param targetContextID target context id
   * @param snapshotContextIDs the vector of id of snapshot contexts
   * @param ancestorContextNodes (TODO. not used?)
   * */
  virtual void acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const {};

  /**
   * initializes an event
   *
   * @param event the event structure to be initialized.
   * @param extra information of target context 
   * @param eventType type of the event
   * 
   * @return corresponding version of context mapping object
   * */
  //virtual mace::ContextMapping const&  asyncHead( mace::Event & event, mace::__asyncExtraField const& extra, int8_t const eventType) = 0;
  virtual const MaceAddr&  asyncHead( mace::Event & event, mace::__asyncExtraField const& extra, int8_t const eventType, uint32_t &contextID) = 0;
  /// service ID: A unique number generated at runtime in the order of maceInit invocation
  /// The maceInit in each service should call registerInstanceID() to set up its service ID.
  uint8_t instanceUniqueID;

  static std::vector<BaseMaceService*> instanceID;
private:
  static std::deque<BaseMaceService*> instances;
};

namespace HeadEventDispatch {
  class HeadEventTP;
}

namespace mace {

void Init(); ///< Initializes Mace internals.  Assumes called without need for lock (e.g. early in main()), and that params are already configured
void Init(int argc, char** argv); ///< Initializes the params, then calls Init().  Setup params::addRequired if desired before calling.
void Shutdown(); ///< Halts threads, things in the background of Mace::Init.  When complete, should be safe to exit.
//#define MARK_RESERVED NULL
/**
 * \brief AgentLock is a global lock that ensures the ordering of events
 * */
class AgentLock
{
  friend class HeadEventDispatch::HeadEventTP;
  private:
    typedef mace::map< uint64_t, pthread_cond_t*, mace::SoftState > RPCWaitType;
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();

        static ThreadSpecific* init();

        static inline int getCurrentMode() { return init()->currentMode; }
        static inline void setCurrentMode(int newMode) { init()->currentMode = newMode; }

        static inline const uint64_t& getSnapshotVersion() { return init()->snapshotVersion; }
        static inline void setSnapshotVersion(const uint64_t& ver) { init()->snapshotVersion = ver; }

        static void releaseThreadSpecificMemory();

        int currentMode;
        uint64_t myTicketNum;
        uint64_t snapshotVersion;
        pthread_cond_t threadCond;

      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        
    }; // ThreadSpecific

  public:
    static const int WRITE_MODE = 1;
    static const int READ_MODE = 0;
    static const int NONE_MODE = -1;

  private:
    static pthread_mutex_t _agent_ticketbooth;
    static pthread_mutex_t _agent_commitbooth;
    //static pthread_mutex_t _agent_mapticket;
    static uint64_t now_serving;
    static uint64_t lastWrite;
    //static int numReaders;
    static int numWriters;

    typedef std::pair<uint64_t, pthread_cond_t*> QueueItemType;

    struct CondQueueComp{
      bool operator()( const QueueItemType& p1, const QueueItemType& p2 ){
        return p1.first > p2.first;
      }
    };

    /* chuangw:
     * I tried different data structures: priority_queue<vector>, priority_queue<deque>, map, set
     * priority_queue<vector> is the fastest one.
     * */

    typedef std::priority_queue< QueueItemType, std::vector< QueueItemType >, CondQueueComp > CondQueue;
    static CondQueue conditionVariables; // Support for per-thread CVs, which gives per ticket CV support. Note: can just use the front of the queue to avoid lookups 
    typedef std::priority_queue< uint64_t, std::vector<uint64_t>, std::greater<uint64_t> > BypassTicketType;

    ThreadSpecific* const threadSpecific;
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;

    static BypassTicketType bypassTickets;
    static BypassTicketType bypassCommits;
    static uint64_t now_committing;
    static CondQueue commitConditionVariables;
    static RPCWaitType rpcWaitingEvents;
  public:
    static void cleanup(){

      now_serving = 1;
      lastWrite = 1;
      //numReaders = 0;
      numWriters = 0;
      while( !conditionVariables.empty() ){
        conditionVariables.pop();
      }
      while( !bypassTickets.empty() ){
        bypassTickets.pop();
      }
      while( !bypassCommits.empty() ){
        bypassCommits.pop();
      }

      now_committing = 1;
      while( !commitConditionVariables.empty() ){
        commitConditionVariables.pop();
      }
    }

    AgentLock(int requestedMode = WRITE_MODE) : threadSpecific(ThreadSpecific::init()), requestedMode(requestedMode), priorMode(threadSpecific->currentMode), myTicketNum(ThreadStructure::myTicket()) {
      ADD_SELECTORS("AgentLock::(constructor)");
      macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

      if (priorMode == NONE_MODE) {
        // do what's needed
        if (requestedMode == NONE_MODE) {
          //Do nothing.
        } else {
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

          ScopedLock sl(_agent_ticketbooth);

          if (myTicketNum == std::numeric_limits<uint64_t>::max()) {
            myTicketNum = ThreadStructure::newTicket();
            macewarn << "Ticket not acquired - acquiring new ticket.  Ticket: "  << myTicketNum << Log::endl;
          }

          if (myTicketNum < now_serving) {
            //Ticket already used!  Need to acquire new ticket.
            uint64_t oldTicket = myTicketNum;
            myTicketNum = ThreadStructure::newTicket();
            macewarn << "Ticket already used - acquiring new ticket.  Sometimes possible event interleaving!  This time tickets are: "  << oldTicket << " and " << myTicketNum << Log::endl;
          }

          ticketBoothWait(myTicketNum, requestedMode);

          if (requestedMode == READ_MODE) {
            //Acquire read lock
            ASSERT(numWriters == 0);
            /*if (USING_RWLOCK) {
              numReaders++;
            } else {
            }*/
            threadSpecific->currentMode = READ_MODE;
            
            notifyNext();
          }
          else if (requestedMode == WRITE_MODE) {
            //Acquire write lock
            //ASSERT(numReaders == 0);
            ASSERT(numWriters == 0);
            threadSpecific->currentMode = WRITE_MODE;
            numWriters = 1;
            lastWrite = myTicketNum;
          }
        }
      }
      else if (priorMode == READ_MODE) {
        ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
      }
      else if (priorMode == WRITE_MODE) {
        ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
      }
      else {
        ABORT("Unknown priorMode!");
      }
      macedbg(1) << "CONTINUING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

    }
    ~AgentLock() {
      ADD_SELECTORS("AgentLock::(destructor)");
      // chuangw: runningMode in ThreadSpecific is no longer meanful, because a thread can only process a part of an event's live time.
      // reset it to NONE_MODE to avoid some problems. Will overhaul this eventually.
      threadSpecific->currentMode = NONE_MODE;
    }


    static void waitAfterCommit( uint64_t eventTicket ){
      ADD_FUNC_SELECTORS

      pthread_cond_t cond;
      pthread_cond_init( & cond, NULL );

      ScopedLock sl(_agent_commitbooth);
      
      // if the event has already committed, then go ahead without stop
      if( eventTicket+1 == now_committing ){
        macedbg(1)<<"the previous event "<< eventTicket << " has committed, so go ahead without stop"<<Log::endl;
        return;
      }
      rpcWaitingEvents[ eventTicket ] = &cond;

      macedbg(1)<<"this event registers to be notified by event "<< eventTicket <<Log::endl;
      pthread_cond_wait( & cond, &_agent_commitbooth );
    }
    static void signalRPCUpcalls( mace::Event const& event ){
      ADD_FUNC_SELECTORS
      // if a later event is registered to be informed, wake it up

      RPCWaitType::iterator reIt = rpcWaitingEvents.find( event.eventID );
      if( reIt != rpcWaitingEvents.end() ){
        macedbg(1)<<"an event is registered to be notified by this event="<< event.eventID << ". wake it up"<<Log::endl;
        pthread_cond_signal( reIt->second );

        rpcWaitingEvents.erase( reIt );
      }
    }


    static void checkTicketUsed() {
      ASSERT( now_serving > ThreadStructure::myTicket() );
    }

    static int getCurrentMode() {
      return ThreadSpecific::getCurrentMode();
    }
    static int snapshotVersion() {
      return ThreadSpecific::getSnapshotVersion();
    }
    static const uint64_t& getLastWrite() { 
      ScopedLock sl(_agent_ticketbooth);
      return lastWrite;
    }

    static void commitEvent( mace::Event & event ){
      ADD_SELECTORS("AgentLock::commitEvent");
      ScopedLock sl2(_agent_commitbooth);
      ASSERT(event.eventID == now_committing); //Remove once working.

      macedbg(1)<<"commit event "<< event.eventID <<Log::endl;

      now_committing++;
      GlobalCommit::commit(event);

      signalRPCUpcalls( event );
    }

    static void downgrade(int newMode) {
      ADD_SELECTORS("AgentLock::downgrade");
      int runningMode = ThreadSpecific::getCurrentMode();
      uint64_t myTicketNum = ThreadStructure::myTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == READ_MODE && runningMode == WRITE_MODE) {
        //macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_agent_ticketbooth);
        ASSERT(numWriters == 1 /*&& numReaders == 0*/ );
        //ASSERT(now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        numWriters = 0;
        /*if (USING_RWLOCK) {
          numReaders = 1;
        }
        else {
        } // TODO: this wakes up the thread even if there is a write mode thread
        */
        ThreadSpecific::setCurrentMode(READ_MODE);
        notifyNext();
      } else if (newMode == NONE_MODE && runningMode != NONE_MODE) {
        ScopedLock sl(_agent_ticketbooth);
        //bool doGlobalRelease = false;
        if (runningMode == READ_MODE) {
          /*if (USING_RWLOCK) {
            ASSERT(numReaders > 0 && numWriters == 0);
            numReaders--;
          }
          else {
            ASSERT(numReaders == 0);
          }*/
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(/*numReaders == 0 &&*/ numWriters == 1);
          numWriters=0;
        }
        else {
          ABORT("Invalid running mode!");
        }
        //macedbg(1) << "After lock release - numReaders " << numReaders << " numWriters " << numWriters << Log::endl;
        ThreadSpecific::setCurrentMode(NONE_MODE);
        
        notifyNext();
        sl.unlock();
        ScopedLock sl2(_agent_commitbooth);

        macedbg(1) << "Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait(myTicketNum);
        
        GlobalCommit::commit();

        macedbg(1) << "Ticket "<< myTicketNum << " Downgrade to NONE_MODE complete" << Log::endl;
      }
      else {
        macewarn << "Why was downgrade called?  Current mode is: " << runningMode << " and mode requested is: " << newMode << Log::endl;
      }
      macedbg(1) << "Downgrade exiting" << Log::endl;
    }
    static void releaseThreadSpecificMemory(){
      ThreadSpecific::releaseThreadSpecificMemory();
    }

    static void nullTicket() {
      ADD_SELECTORS("AgentLock::nullTicket");
      uint64_t myTicketNum = ThreadStructure::myTicket();
      ScopedLock sl(_agent_ticketbooth);

      ticketBoothWait(myTicketNum,NONE_MODE);

      notifyNext();

      sl.unlock();

      ScopedLock sl2(_agent_commitbooth);
      //commitOrderWait(myTicketNum);
      macedbg(1)<<"increment now_comitting from "<< now_committing <<Log::endl;
      now_committing++;
      GlobalCommit::commitNoop();
    }


  private:

    static inline void notifyNext(){
      ADD_SELECTORS("AgentLock::notifyNext");
      if( !conditionVariables.empty() ){
        const QueueItemType& condBegin = conditionVariables.top();
        macedbg(1)<< "ticket="<<condBegin.first << " cond = "<< condBegin.second << Log::endl;
        if( condBegin.first == now_serving ){
          macedbg(1) << "Signalling ticket " << now_serving << Log::endl;
          pthread_cond_signal( condBegin.second); 
        }else{
          macedbg(1) << "first on cv queue"<< condBegin.first<<" != now_serving " << now_serving << Log::endl;
        }
      }
    }

    static void ticketBoothWait( uint64_t myTicketNum, int requestedMode) {
      ADD_SELECTORS("AgentLock::ticketBoothWait");

      if (myTicketNum > now_serving ||
          ( requestedMode == READ_MODE && (numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (/*numReaders != 0 || */numWriters != 0) )
         ) {
        pthread_cond_t* threadCond = &(ThreadSpecific::init()->threadCond);
        macedbg(1) << "Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        conditionVariables.push( QueueItemType( myTicketNum, threadCond ) );
        while (myTicketNum > now_serving ||
            ( requestedMode == READ_MODE && (numWriters != 0) ) ||
            ( requestedMode == WRITE_MODE && (/*numReaders != 0 ||*/ numWriters != 0) )
            ) {
          macedbg(1) << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving << " requestedMode " << requestedMode << " numWriters " << numWriters <</* " numReaders " << numReaders << */Log::endl;
          pthread_cond_wait(threadCond, &_agent_ticketbooth);
        }

        //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
        ASSERT ( ! conditionVariables.empty() );

        const QueueItemType& condBegin = conditionVariables.top();
        if ( condBegin.first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          conditionVariables.pop();
        }else{
          macedbg(1) << "FYI, first cv in map is for ticket " << condBegin.first << Log::endl;
        }
      }

      macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

      ASSERT(myTicketNum == now_serving); //Remove once working.

      now_serving++;
    }

    // WC: defunct
    static void commitOrderWait(uint64_t myTicketNum) {
      ABORT("defunct");
      ADD_SELECTORS("AgentLock::commitOrderWait");
      //uint64_t myTicketNum = ThreadStructure::myTicket();

      //bypassCommit();
      if (myTicketNum > now_committing ) {
        pthread_cond_t& threadCond = ThreadSpecific::init()->threadCond;
        macedbg(1) << "Storing condition variable " << &threadCond << " for ticket " << myTicketNum << Log::endl;
        commitConditionVariables.push( QueueItemType( myTicketNum, &threadCond ) );
        while (myTicketNum > now_committing) {
          macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_committing " << now_committing << Log::endl;
          pthread_cond_wait(&threadCond, &_agent_commitbooth);
        }
      }

      macedbg(1) << "Ticket " << myTicketNum << " being committed!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if ( !commitConditionVariables.empty() ){
        const QueueItemType& condBegin = commitConditionVariables.top();
        if ( condBegin.first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          commitConditionVariables.pop();
        }
        else {
          macedbg(1) << "FYI, first cv in map is for ticket " << condBegin.first << Log::endl;
        }
      }

      ASSERT(myTicketNum == now_committing); //Remove once working.

      macedbg(1)<<"increment now_comitting from "<< now_committing <<Log::endl;
      now_committing++;

    }
}; //AgentLock
class AgentLockNB
{
  friend class HeadEventDispatch::HeadEventTP;
  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();

        static ThreadSpecific* init();

        static inline int getCurrentMode() { return init()->currentMode; }
        static inline void setCurrentMode(int newMode) { init()->currentMode = newMode; }

        static inline const uint64_t& getSnapshotVersion() { return init()->snapshotVersion; }
        static inline void setSnapshotVersion(const uint64_t& ver) { init()->snapshotVersion = ver; }

        static void releaseThreadSpecificMemory();

        int currentMode;
        uint64_t myTicketNum;
        uint64_t snapshotVersion;
        pthread_cond_t threadCond;

      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        
    }; // ThreadSpecific

  public:
    static const int WRITE_MODE = 1;
    static const int READ_MODE = 0;
    static const int NONE_MODE = -1;

  private:
    static pthread_mutex_t _agent_ticketbooth;
    static uint64_t now_serving;
    static uint64_t lastWrite;
    static int numReaders;
    static int numWriters;

    template<typename T>
    struct CondQueueComp{
      bool operator()( const std::pair<uint64_t, T>& p1, const std::pair<uint64_t, T>& p2 ){
        return p1.first > p2.first;
      }
    };

    typedef void (*FuncType)(void);

    typedef std::priority_queue< std::pair<uint64_t, FuncType>, std::vector<std::pair<uint64_t, FuncType> >, CondQueueComp<FuncType> > CondQueue;
    static CondQueue conditionVariables; // Support for per-thread CVs, which gives per ticket CV support. Note: can just use the front of the queue to avoid lookups 

    ThreadSpecific* const threadSpecific;
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;
    FuncType func;
    static uint64_t now_committing;
    static CondQueue commitConditionVariables;
    
  public:

    AgentLockNB(int requestedMode, FuncType func ) : threadSpecific(ThreadSpecific::init()), requestedMode(requestedMode), priorMode(threadSpecific->currentMode), myTicketNum(ThreadStructure::myTicket()), func(func) {
      ADD_SELECTORS("AgentLockNB::(constructor)");
      macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;


      ScopedLock sl(_agent_ticketbooth);

      if (priorMode == NONE_MODE) {
        // do what's needed
        if (requestedMode == NONE_MODE) {
          //Do nothing.
        }
        else {
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");


          /*if (myTicketNum == std::numeric_limits<uint64_t>::max()) {
            myTicketNum = ThreadStructure::newTicket();
            macewarn << "Ticket not acquired - acquiring new ticket.  Ticket: "  << myTicketNum << Log::endl;
          }*/

          /*if (myTicketNum < now_serving) {
            //Ticket already used!  Need to acquire new ticket.
            uint64_t oldTicket = myTicketNum;
            myTicketNum = ThreadStructure::newTicket();
            macewarn << "Ticket already used - acquiring new ticket.  Sometimes possible event interleaving!  This time tickets are: "  << oldTicket << " and " << myTicketNum << Log::endl;
          }*/

          ticketBoothWait(/*requestedMode*/);

          /*if (requestedMode == READ_MODE) {
            //Acquire read lock
            ASSERT(numWriters == 0);
            if (USING_RWLOCK) {
              numReaders++;
            } else {
            }
            threadSpecific->currentMode = READ_MODE;
            
            if (! conditionVariables.empty() ){
              std::pair<uint64_t, pthread_cond_t*> condBegin = conditionVariables.top();
              if ( condBegin.first == now_serving) {
                macedbg(1) << "Now signalling ticket number " << now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
                pthread_cond_signal(condBegin.second); // only signal if this is a reader -- writers should signal on commit only.
              }
              else {
                ASSERTMSG(conditionVariables.empty() || condBegin.first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
              }
            }else{
            }
          }
          else*/ 
        }
      }
      /*else if (priorMode == READ_MODE) {
        ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
      }
      else if (priorMode == WRITE_MODE) {
        ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
      }
      else {
        ABORT("Unknown priorMode!");
      }
      */
      macedbg(1) << "CONTINUING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

      // execute ready requests
      executeReadyRequests();
    }
    /*~AgentLockNB() {
      ADD_SELECTORS("AgentLockNB::(destructor)");
      int runningMode = threadSpecific->currentMode; 
      macedbg(1) << "ENDING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
      if (priorMode == NONE_MODE && runningMode != NONE_MODE) {
        macedbg(1) << "Downgrading to NONE_MODE" << Log::endl;
        downgrade(NONE_MODE);
      }
      macedbg(1) << "ENDED.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
    }
    */


    static void checkTicketUsed() {
      ASSERT( now_serving > ThreadStructure::myTicket() );
    }

    static int getCurrentMode() {
      return ThreadSpecific::getCurrentMode();
    }
    static int snapshotVersion() {
      return ThreadSpecific::getSnapshotVersion();
    }
    static const uint64_t& getLastWrite() { return lastWrite; }

    static void downgrade(int newMode) {
      ADD_SELECTORS("AgentLockNB::downgrade");
      int runningMode = ThreadSpecific::getCurrentMode();
      uint64_t myTicketNum = ThreadStructure::myTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == NONE_MODE && runningMode != NONE_MODE) {
        ScopedLock sl(_agent_ticketbooth);
        /*if (runningMode == READ_MODE) {
          if (USING_RWLOCK) {
            ASSERT(numReaders > 0 && numWriters == 0);
            numReaders--;
          }
          else {
            ASSERT(numReaders == 0);
          }
        }
        else*/ if (runningMode == WRITE_MODE) {
          ASSERT(numReaders == 0 && numWriters == 1);
          numWriters=0;
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "After lock release - numReaders " << numReaders << " numWriters " << numWriters << Log::endl;
        ThreadSpecific::setCurrentMode(NONE_MODE);
        
        /*if (! conditionVariables.empty() ){
          std::pair<uint64_t, pthread_cond_t*> condBegin = conditionVariables.top();

          if ( condBegin.first == now_serving) {
            // chuangw: don't do signaling
            macedbg(1) << "Signalling CV " << condBegin.second << " for ticket " << now_serving << Log::endl;
            pthread_cond_signal(condBegin.second); // only signal if this is a reader -- writers should signal on commit only.
          }
          else {
            ASSERTMSG(conditionVariables.empty() || condBegin.first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
          }

        }else{
        }*/
        macedbg(1) << "Waiting to commit ticket " << myTicketNum << Log::endl;
        //commitOrderWait();
        if( (now_committing & 0xff) == 0 ){ // accumulator takes up too much time in optimized executables. so don't accumulate every time
          Accumulator::Instance(Accumulator::AGENTLOCK_COMMIT_COUNT)->accumulate( 0xff );
        }
        macedbg(1) << "Ticket "<< myTicketNum << " Downgrade to NONE_MODE complete" << Log::endl;
      }
      /*else if (newMode == READ_MODE && runningMode == WRITE_MODE) {
        macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_agent_ticketbooth);
        ASSERT(numWriters == 1 && numReaders == 0);
        ASSERT(now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        numWriters = 0;
        if (USING_RWLOCK) {
          numReaders = 1;
        }
        else {
        } // TODO: this wakes up the thread even if there is a write mode thread
        ThreadSpecific::setCurrentMode(READ_MODE);
        if (! conditionVariables.empty() ){
          std::pair<uint64_t, pthread_cond_t*> condBegin = conditionVariables.top();
          if ( condBegin.first == now_serving) {
            macedbg(1) << "Signalling CV " << condBegin.second << " for ticket " << now_serving << Log::endl;
            pthread_cond_signal(condBegin.second); // only signal if this is a reader -- writers should signal on commit only.
          } else {
            ASSERTMSG(conditionVariables.empty() || condBegin.first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
          }
        }else{
        }
      }*/
      else {
        macewarn << "Why was downgrade called?  Current mode is: " << runningMode << " and mode requested is: " << newMode << Log::endl;
      }
      macedbg(1) << "Downgrade exiting" << Log::endl;
    }
    static void releaseThreadSpecificMemory(){
      ThreadSpecific::releaseThreadSpecificMemory();
    }

  //Temporary stubs (unless Hyo wants to use these instead)
  private:
    static pthread_mutex_t ticketMutex;
    static uint64_t nextTicketNumber;

  public:

    /*static void nullTicket() {
      ADD_SELECTORS("AgentLockNB::nullTicket");
      ScopedLock sl(_agent_ticketbooth);

      ticketBoothWait(NONE_MODE);

      if (! conditionVariables.empty() ){
        std::pair<uint64_t, pthread_cond_t*> condBegin = conditionVariables.top();
        if ( condBegin.first == now_serving) {
          macedbg(1) << "Now signalling ticket number " << now_serving << " (my ticket is " << ThreadStructure::myTicket() << " )" << Log::endl;
          pthread_cond_signal(condBegin.second); // only signal if this is a reader -- writers should signal on commit only.
        } else {
          ASSERTMSG(conditionVariables.empty() || condBegin.first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
      }else{
      }

      commitOrderWait();
      Accumulator::Instance(Accumulator::AGENTLOCK_COMMIT_COUNT)->accumulate(1);
    }*/

    /*static */void ticketBoothWait(/*int requestedMode*/) {
      ADD_SELECTORS("AgentLockNB::ticketBoothWait");

      uint64_t myTicketNum = ThreadStructure::myTicket();
      pthread_cond_t* threadCond = &(ThreadSpecific::init()->threadCond);

      /*if (myTicketNum > now_serving ||
          ( requestedMode == READ_MODE && (numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
         ) {*/
        macedbg(1) << "Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        conditionVariables.push( std::pair< uint64_t, FuncType >( myTicketNum, func ) );
      /*}*/
      // chuangw: don't wait. just put the request in the queue.
      /*while (myTicketNum > now_serving ||
          ( requestedMode == READ_MODE && (numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
          ) {
        macedbg(1) << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving << " requestedMode " << requestedMode << " numWriters " << numWriters << " numReaders " << numReaders << Log::endl;
        pthread_cond_wait(threadCond, &_agent_ticketbooth);
      }*/

      // chuangw: added to measure the time holding global lock
      //maceout << "Ticket " << myTicketNum << " being served!" << Log::endl;
    }

    void executeReadyRequests(){
      ADD_SELECTORS("AgentLockNB::afterTicketBoothWait");

      while(! conditionVariables.empty() ){

        //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
        std::pair<uint64_t, FuncType> condBegin = conditionVariables.top();
        if ( condBegin.first == now_serving/*myTicketNum*/ ) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          conditionVariables.pop();
        }else{
          macedbg(1) << "FYI, first cv in map is for ticket " << condBegin.first << Log::endl;
          break;
        }
        macedbg(1) << "Ticket " << /*myTicketNum*/ now_serving << " being served!" << Log::endl;

        //ASSERT(myTicketNum == now_serving); //Remove once working.
        ThreadStructure::setTicket( now_serving );
        myTicketNum = now_serving;

        now_serving++;

        if (requestedMode == WRITE_MODE) {
          //Acquire write lock
          ASSERT(numReaders == 0);
          ASSERT(numWriters == 0);
          threadSpecific->currentMode = WRITE_MODE;
          numWriters = 1;
          lastWrite = myTicketNum;
        }

        (*(condBegin.second) )();
        // downgrade( newMode == NONE_MODE && runningMode == WRITE_MODE )
        ASSERT(numReaders == 0 && numWriters == 1);
        numWriters=0;
        commitOrderWait();

        commitFinishedRequests();
      } // while(! conditionVariables.empty() )
 
    }

    /*static */void commitOrderWait() {
      ADD_SELECTORS("AgentLockNB::commitOrderWait");
      uint64_t myTicketNum = ThreadStructure::myTicket();

      pthread_cond_t& threadCond = ThreadSpecific::init()->threadCond;
      //if (myTicketNum > now_committing ) {
        macedbg(1) << "Storing condition variable " << &threadCond << " for ticket " << myTicketNum << Log::endl;
        commitConditionVariables.push( std::pair< uint64_t, FuncType >( myTicketNum, func ) );
      //}

      // chuangw: added to measure the time holding global lock
      //maceout << "Ticket " << myTicketNum << " ready to commit!" << Log::endl;



      // chuangw: don't wait
      /*while (myTicketNum > now_committing) {
        macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_committing " << now_committing << Log::endl;
        pthread_cond_wait(&threadCond, &_agent_ticketbooth);
      }
      */

    }
    void commitFinishedRequests(){
      ADD_SELECTORS("AgentLockNB::commitFinishedRequests");
      macedbg(1) << "Ticket " << myTicketNum << " being committed!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if ( !commitConditionVariables.empty() ){
        std::pair<uint64_t, FuncType> condBegin = commitConditionVariables.top();
        if ( condBegin.first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          commitConditionVariables.pop();
          condBegin = commitConditionVariables.top();
        }
        else {
          macedbg(1) << "FYI, first cv in map is for ticket " << condBegin.first << Log::endl;
        }
      }

        ASSERT(myTicketNum == now_committing); //Remove once working.

        now_committing++;

      if ( !commitConditionVariables.empty() ){
        std::pair<uint64_t, FuncType> condBegin = commitConditionVariables.top();
        if (condBegin.first == now_committing) {
          macedbg(1) << "Now signalling ticket number " << now_committing << " (my ticket is " << myTicketNum << " )" << Log::endl;
          //pthread_cond_signal(condBegin.second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(condBegin.first > now_committing, "conditionVariables map contains CV for ticket already served!!!");
        }
      }

    }
}; //AgentLockNB

}

#endif // _MACE_H
