#ifndef __HEAD_EVENT_DISPATCH_h
#define __HEAD_EVENT_DISPATCH_h

#include "mace.h"
#include "mace-macros.h"
#include "ThreadPool.h"
#include "Message.h"
class AsyncEventReceiver;
namespace mace{
  class AgentLock;
}
namespace HeadEventDispatch {
  typedef mace::map< uint64_t, uint64_t, mace::SoftState> EventRequestTSType;
  // the timestamp where the event request is created
  extern EventRequestTSType eventRequestTime;
  // the timestamp where the event request is processed
  extern EventRequestTSType eventStartTime;
  extern pthread_mutex_t startTimeMutex;
  extern pthread_mutex_t requestTimeMutex;

  void insertEventStartTime(uint64_t eventID);
  void insertEventRequestTime(uint64_t eventID);
  class HeadMigration {
public:
    static void setState( const uint16_t newState ){
      ScopedLock sl( lock );
      state = newState;
    }
    static const uint16_t getState( ){
      ScopedLock sl( lock );
      return state;
    }
    static void setMigrationEventID( const uint64_t eventID ){
      ScopedLock sl( lock );
      migrationEventID = eventID;
    }
    static const uint64_t getMigrationEventID( ){
      ScopedLock sl( lock );
      return migrationEventID;
    }
    static void setNewHead( const MaceAddr& head ){
      ScopedLock sl( lock );
      newHeadAddr = head;
    }
    static const MaceAddr getNewHead( ){
      ScopedLock sl( lock );
      return newHeadAddr;
    }
public:
    static const uint16_t HEAD_STATE_NORMAL = 0;
    static const uint16_t HEAD_STATE_MIGRATING = 1;
    static const uint16_t HEAD_STATE_MIGRATED = 2;
private:
    static pthread_mutex_t lock;
    static uint16_t state;
    static uint64_t migrationEventID;
    static mace::MaceAddr newHeadAddr;

  };

  typedef void (AsyncEventReceiver::*eventfunc)(mace::Message*);
  class HeadEvent {
    private: 
      AsyncEventReceiver* cl;
      eventfunc func;
      mace::Message* param;
      uint64_t ticket;

    public:
      HeadEvent() : cl(NULL), func(NULL), param(NULL) {}
      HeadEvent(AsyncEventReceiver* cl, eventfunc func, mace::Message* param, uint64_t ticket) : cl(cl), func(func), param(param), ticket(ticket) {}
      void fire() {
        // ASSERT(cl != NULL && func != NULL);
        ADD_SELECTORS("HeadEvent::fire");
        //ThreadStructure::setTicket( ticket );
        macedbg(1)<<"Firing ticket= "<< ticket <<Log::endl;
        (cl->*func)(param);
      }
  };
  //typedef std::map<uint64_t, HeadEventDispatch::HeadEvent> EventRequestQueueType;
  template<typename T>
  struct QueueComp{
    bool operator()( const std::pair<uint64_t, T>& p1, const std::pair<uint64_t, T>& p2 ){
      return p1.first > p2.first;
    }
  };
  typedef std::pair<uint64_t, HeadEventDispatch::HeadEvent> RQType;
  typedef std::priority_queue< RQType, std::vector< RQType >, QueueComp<HeadEventDispatch::HeadEvent> > EventRequestQueueType;
  //typedef std::queue< RQType > EventRequestQueueType;

  extern EventRequestQueueType headEventQueue;///< used by head context


  //void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p);

  void init();
  void haltAndWait();

  class HeadEventTP;
  struct ThreadArg {
    HeadEventTP* p;
    uint32_t i;
  };

  class HeadEventTP{
  friend class mace::AgentLock;
  public:
  //typedef mace::ThreadPool<HeadEventTP, HeadEvent> ThreadPoolType;
  private: 
    uint32_t idle;
    bool* sleeping;
    ThreadArg* args;
    bool busyCommit;
    const uint32_t minThreadSize;
    const uint32_t maxThreadSize;
    static pthread_t* headThread;
    static pthread_t headCommitThread;
    HeadEvent data;
    mace::Event* committingEvent;
    pthread_cond_t signalv;
    pthread_cond_t signalc;
  public:
    HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize);

    ~HeadEventTP() ;

    void wait();
    void commitWait() ;

    void signalSingle() ;
    void signalAll() ;
    void signalCommitThread() ;
    // cond func
    bool hasPendingEvents();
    bool hasUncommittedEvents();
    // setup
    void executeEventSetup();
    void commitEventSetup( );
    // process
    void executeEventProcess();
    void commitEventProcess() ;
    // finish
    void executeEventFinish();
    void commitEventFinish() ;

    static void* startThread(void* arg) ;
    static void* startCommitThread(void* arg) ;
    void run(uint32_t n);
    void runCommit();

    void haltAndWait();
    static void executeEvent(AsyncEventReceiver* sv, eventfunc func, mace::Message* p, bool useTicket);
    static void commitEvent(const mace::Event& event);
    static void accumulateEventLifeTIme(mace::Event const& event);
    static void accumulateEventRequestCommitTIme(mace::Event const& event);
  };
  HeadEventTP* HeadEventTPInstance() ;


  #include "MaceKey.h"
  #include "CircularQueueList.h"
  #include <deque>

  typedef void (AsyncEventReceiver::*routefunc)(const mace::MaceKey& dest, const mace::Message& msg, registration_uid_t rid);
  class HeadTransportQueueElement {
    private: 
      AsyncEventReceiver* cl;
      routefunc func;
      mace::MaceAddr dest;
      mace::Message* msg;
      registration_uid_t rid;

    public:
      HeadTransportQueueElement() : cl(NULL), func(NULL), msg(NULL), rid(0) {}
      HeadTransportQueueElement(AsyncEventReceiver* cl, routefunc func, mace::MaceAddr const& dest, mace::Message* msg, registration_uid_t rid) : cl(cl), func(func), dest(dest), msg(msg), rid(rid) {}
      void fire() {
        ADD_SELECTORS("HeadTransportQueueElement::fire");
        const mace::MaceKey destNode( mace::ctxnode, dest );
        (cl->*func)(destNode, *msg, rid);
        delete msg;
      }
  };
  //typedef CircularQueueList< HeadTransportQueueElement > MessageQueue;
  //typedef std::deque< HeadTransportQueueElement > MessageQueue;
  typedef std::queue< HeadTransportQueueElement > MessageQueue;
  class HeadTransportTP {
    typedef mace::ThreadPool<HeadTransportTP, HeadTransportQueueElement> ThreadPoolType;
    private:
      static MessageQueue mqueue;
      ThreadPoolType *tpptr;
      bool runDeliverCondition(ThreadPoolType* tp, uint threadId);
      void runDeliverSetup(ThreadPoolType* tp, uint threadId);
      void runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId);
      void runDeliverProcessFinish(ThreadPoolType* tp, uint threadId);
    public:
      HeadTransportTP(uint32_t minThreadSize, uint32_t maxThreadSize  );
      ~HeadTransportTP();

      void signal();

      void haltAndWait();
      void lock(); // lock

      void unlock(); // unlock
      static void sendEvent(AsyncEventReceiver* sv, routefunc func, mace::MaceAddr const& dest, mace::Message* p, registration_uid_t uid);
  };
}

#endif
