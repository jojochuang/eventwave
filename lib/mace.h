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

#ifdef USE_SNAPSHOT
static const bool USING_RWLOCK = false;
#else
static const bool USING_RWLOCK = true;
#endif

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
}
class BaseMaceService : public AsyncEventReceiver
{

public:
  //Agent Stuff
  static pthread_mutex_t synclock;  ///< Formerly, the "agent lock", held when executing nearly any code in a service.  Recursive to allow recursive calls.  Now used to protect synchronization of sync methods.
  static bool _printLower;

  virtual void processDeferred() {} ///< Implemented by each service to process deferral queues, when directionality won't allow a call to be made immediately.
  virtual void snapshot(const uint64_t& ver) const = 0; ///< Implemented by each service to make versioned snapshots.
  virtual void snapshotRelease(const uint64_t& ver) const = 0; ///< Implemented by each service to make versioned snapshots.

  static BaseMaceService* getInstance( const uint8_t sid );
  void setInstanceID( );

  static std::deque<BaseMaceService*> instances;
  static std::vector<BaseMaceService*> instanceID;
  static uint64_t lastSnapshot;
  static uint64_t lastSnapshotReleased;

  static void globalSnapshot(const uint64_t& ver); ///< Called to cause all services to snapshot their current state as version ver.
  static void globalSnapshotRelease(const uint64_t& ver); ///< Called to cause all services to delete their snapshot prior to version ver.

  BaseMaceService(bool enqueueService = true);
  virtual ~BaseMaceService() {}

  static void globalNotifyNewContext( const uint8_t serviceID );
  virtual void notifyNewContext( const uint8_t serviceID ) = 0;

  static void globalNotifyNewEvent( const uint8_t serviceID );
  virtual void notifyNewEvent( const uint8_t serviceID ) = 0;

  static void globalCommitEvent( const uint64_t eventID );
  virtual void commitEvent( const uint64_t eventID ) = 0;
  
  static void globalDowngradeEventContext( );
  virtual void downgradeEventContext( ) = 0;

  virtual void dispatchDeferredMessages(MaceKey const& dest, mace::string const& message,  registration_uid_t const rid ) = 0;

  virtual void requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly) = 0;
protected:
  void downgradeCurrentContext() const;
  virtual void acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const {};


  virtual void asyncHead( mace::__asyncExtraField const& extra, int8_t const eventType) = 0;
  uint8_t instanceUniqueID;
};

namespace HeadEventDispatch {
  class HeadEventTP;
}

namespace mace {

void Init(); ///< Initializes Mace internals.  Assumes called without need for lock (e.g. early in main()), and that params are already configured
void Init(int argc, char** argv); ///< Initializes the params, then calls Init().  Setup params::addRequired if desired before calling.
void Shutdown(); ///< Halts threads, things in the background of Mace::Init.  When complete, should be safe to exit.
class AgentLock
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
    static pthread_mutex_t _agent_commitbooth;
    static uint64_t now_serving;
    static uint64_t lastWrite;
    static int numReaders;
    static int numWriters;

    /* chuangw: tried to use triplet, but which is a lot slower than std::pair */
    //typedef triplet<uint64_t, pthread_cond_t*, bool> QueueItemType;
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
    static BypassTicketType bypassTickets;
    static BypassTicketType bypassCommits;

    ThreadSpecific* const threadSpecific;
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;

    static uint64_t now_committing;
    static CondQueue commitConditionVariables;
    
    static bool signalHeadEvent( uint64_t ticket);
  public:

    AgentLock(int requestedMode = WRITE_MODE) : threadSpecific(ThreadSpecific::init()), requestedMode(requestedMode), priorMode(threadSpecific->currentMode), myTicketNum(ThreadStructure::myTicket()) {
      ADD_SELECTORS("AgentLock::(constructor)");
      macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

      if (priorMode == NONE_MODE) {
        // do what's needed
        if (requestedMode == NONE_MODE) {
          //Do nothing.
        }
        else {
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

          ticketBoothWait(requestedMode);

          if (requestedMode == READ_MODE) {
            //Acquire read lock
            ASSERT(numWriters == 0);
            if (USING_RWLOCK) {
              numReaders++;
            } else {
            }
            //ThreadSpecific::setCurrentMode(READ_MODE);
            threadSpecific->currentMode = READ_MODE;
            
            notifyNext();
          }
          else if (requestedMode == WRITE_MODE) {
            //Acquire write lock
            ASSERT(numReaders == 0);
            ASSERT(numWriters == 0);
            //ThreadSpecific::setCurrentMode(WRITE_MODE);
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
      /*int runningMode = threadSpecific->currentMode; //ThreadSpecific::getCurrentMode();
      macedbg(1) << "ENDING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
      if (priorMode == NONE_MODE && runningMode != NONE_MODE) {
        macedbg(1) << "Downgrading to NONE_MODE" << Log::endl;
        downgrade(NONE_MODE);
      }
      macedbg(1) << "ENDED.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
      */

      // chuangw: runningMode in ThreadSpecific is no longer meanful, because a thread can only process a part of an event's live time.
      // reset it to NONE_MODE to avoid some problems. Will overhaul this eventually.
      threadSpecific->currentMode = NONE_MODE;
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
    static const uint64_t& getLastWrite() { return lastWrite; }


    static std::map< uint64_t, uint64_t > eventToTicket;
    /* maps event id to ticket number so that when downgrade from read to null it can still keep track of it
     * */
    static void setEventTicket( uint64_t const eventID ){
      ScopedLock sl(_agent_ticketbooth);
      
      eventToTicket[ eventID ] = ThreadStructure::myTicket();
    }
    static uint64_t getClearEventTicket( uint64_t const eventID ) {
      ScopedLock sl(_agent_ticketbooth);
      
      std::map< uint64_t, uint64_t >::iterator it = eventToTicket.find( eventID );
      ASSERT( it != eventToTicket.end() );
      const uint64_t ticketNum = it->second;
      eventToTicket.erase( it );
      return ticketNum;
    }
    /*static void clearEventTicket( uint64_t const eventID ){
      eventToTicket.erase( eventID );
    }*/

    static void downgrade(int newMode) {
      ADD_SELECTORS("AgentLock::downgrade");
      int runningMode = ThreadSpecific::getCurrentMode();
      uint64_t myTicketNum = ThreadStructure::myTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == NONE_MODE && runningMode != NONE_MODE) {
        ScopedLock sl(_agent_ticketbooth);
        //bool doGlobalRelease = false;
        if (runningMode == READ_MODE) {
          if (USING_RWLOCK) {
            ASSERT(numReaders > 0 && numWriters == 0);
            numReaders--;
          }
          else {
            ASSERT(numReaders == 0);
          }
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(numReaders == 0 && numWriters == 1);
          numWriters=0;
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "After lock release - numReaders " << numReaders << " numWriters " << numWriters << Log::endl;
        ThreadSpecific::setCurrentMode(NONE_MODE);
        
        notifyNext();
        sl.unlock();
        ScopedLock sl2(_agent_commitbooth);

        macedbg(1) << "Waiting to commit ticket " << myTicketNum << Log::endl;
        commitOrderWait();
        
        GlobalCommit::commit();

        macedbg(1) << "Ticket "<< myTicketNum << " Downgrade to NONE_MODE complete" << Log::endl;
      }
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) {
        macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_agent_ticketbooth);
        ASSERT(numWriters == 1 && numReaders == 0);
        //ASSERT(now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        numWriters = 0;
        if (USING_RWLOCK) {
          numReaders = 1;
        }
        else {
        } // TODO: this wakes up the thread even if there is a write mode thread
        ThreadSpecific::setCurrentMode(READ_MODE);
        notifyNext();
      }
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
    static void nullTicket() {
      ADD_SELECTORS("AgentLock::nullTicket");
      ScopedLock sl(_agent_ticketbooth);

      ticketBoothWait(NONE_MODE);

      notifyNext();

      sl.unlock();

      ScopedLock sl2(_agent_commitbooth);
      commitOrderWait();
    }

    /**
     * mark a ticket is actually going to be used 
     *
     * when HeadEvetDispatch::executeEvent() calls this function, it is already protected by the mutex
     * */
    static void markTicket( uint64_t const myTicketNum ){
      conditionVariables.push( QueueItemType( myTicketNum, reinterpret_cast<pthread_cond_t*>(1)  ) );
    }
    static void removeTicket( uint64_t const myTicketNum ){
      ASSERT( conditionVariables.top().first == myTicketNum );
      conditionVariables.pop();
    }

    /** mark the ticket will not be used 
     *
     * */
    static void skipTicket(){
      uint64_t myTicketNum = ThreadStructure::myTicket();
      ScopedLock sl(_agent_ticketbooth);
      if( myTicketNum == now_serving ){
        now_serving++;
        notifyNext();
      }else{
        bypassTickets.push( myTicketNum );
      }
      sl.unlock();
      ScopedLock sl2(_agent_commitbooth);
      if( myTicketNum == now_committing ){
        now_committing++;
        if( (now_committing % 10) == 0 ){ // accumulator takes up too much time in optimized executables. so don't accumulate every time
          Accumulator::Instance(Accumulator::AGENTLOCK_COMMIT_COUNT)->accumulate( 10 );
        }
        notifyNextCommit();
      }else{
        bypassCommits.push( myTicketNum );
      }
      
    }

  private:

    static void notifyNext(){
      ADD_SELECTORS("AgentLock::notifyNext");
      bypassTicket();
      if( !conditionVariables.empty() ){
        const QueueItemType& condBegin = conditionVariables.top();
        macedbg(1)<< "ticket="<<condBegin.first << " cond = "<< condBegin.second << Log::endl;
        if( condBegin.second == reinterpret_cast< pthread_cond_t *>( 1 ) ){
          signalHeadEvent( condBegin.first );
          conditionVariables.pop();
        }else{
          macedbg(1) << "Signalling ticket " << now_serving << Log::endl;
          pthread_cond_signal( condBegin.second); 
        }
      }
    }
    static void notifyNextCommit(){
      ADD_SELECTORS("AgentLock::notifyNextCommit");
      bypassCommit();
      if( !commitConditionVariables.empty() ){
          macedbg(1) << "Now signalling ticket number " << now_committing <<Log::endl;
          pthread_cond_signal(commitConditionVariables.top().second); 
      }
    }
    static void bypassTicket(){
      while( !bypassTickets.empty() && bypassTickets.top() == now_serving ){
        bypassTickets.pop();
        now_serving++;
      }
    }
    static void bypassCommit(){
      while( !bypassCommits.empty() && bypassCommits.top() == now_committing ){
        bypassCommits.pop();
        now_committing++;
        if( (now_committing % 10) == 0 ){ // accumulator takes up too much time in optimized executables. so don't accumulate every time
          Accumulator::Instance(Accumulator::AGENTLOCK_COMMIT_COUNT)->accumulate( 10 );
        }
      }
    }

    static void ticketBoothWait(int requestedMode) {
      ADD_SELECTORS("AgentLock::ticketBoothWait");

      uint64_t myTicketNum = ThreadStructure::myTicket();
      pthread_cond_t* threadCond = &(ThreadSpecific::init()->threadCond);

      bypassTicket();
      if (myTicketNum > now_serving ||
          ( requestedMode == READ_MODE && (numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
         ) {
        macedbg(1) << "Storing condition variable " << threadCond << " for ticket " << myTicketNum << Log::endl;
        maceout<< "(before) cv top " << conditionVariables.top().first << " = " <<conditionVariables.top().second << "cv size="<< conditionVariables.size() << Log::endl;
        if( !conditionVariables.empty() && conditionVariables.top().first == myTicketNum ){
         conditionVariables.pop(); 
        }
        conditionVariables.push( QueueItemType( myTicketNum, threadCond ) );
        maceout<< "(after) cv top " << conditionVariables.top().first << " = " <<conditionVariables.top().second << "cv size="<< conditionVariables.size() << Log::endl;
      }

      while (myTicketNum > now_serving ||
          ( requestedMode == READ_MODE && (numWriters != 0) ) ||
          ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
          ) {
        macedbg(1) << "Waiting for my turn on cv " << threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving << " requestedMode " << requestedMode << " numWriters " << numWriters << " numReaders " << numReaders << Log::endl;
        pthread_cond_wait(threadCond, &_agent_ticketbooth);
      }

      macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

      //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
      if ( ! conditionVariables.empty() ){
        const QueueItemType& condBegin = conditionVariables.top();
        if ( condBegin.first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          conditionVariables.pop();
        }else{
          macedbg(1) << "FYI, first cv in map is for ticket " << condBegin.first << Log::endl;
        }
      }

      ASSERT(myTicketNum == now_serving); //Remove once working.

      now_serving++;
    }

    static void commitOrderWait() {
      ADD_SELECTORS("AgentLock::commitOrderWait");
      uint64_t myTicketNum = ThreadStructure::myTicket();

      pthread_cond_t& threadCond = ThreadSpecific::init()->threadCond;
      if (myTicketNum > now_committing ) {
        macedbg(1) << "Storing condition variable " << &threadCond << " for ticket " << myTicketNum << Log::endl;
        commitConditionVariables.push( QueueItemType( myTicketNum, &threadCond ) );
      }

      bypassCommit();

      while (myTicketNum > now_committing) {
        macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_committing " << now_committing << Log::endl;
        pthread_cond_wait(&threadCond, &_agent_commitbooth);
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

      now_committing++;
      if( (now_committing % 10) == 0 ){ // accumulator takes up too much time in optimized executables. so don't accumulate every time
        Accumulator::Instance(Accumulator::AGENTLOCK_COMMIT_COUNT)->accumulate( 10 );
      }

      notifyNextCommit();


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
