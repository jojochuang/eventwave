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
  //typedef std::priority_queue< RQType, std::vector< RQType >, QueueComp<HeadEventDispatch::HeadEvent> > EventRequestQueueType;
  typedef std::queue< RQType > EventRequestQueueType;

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

    static void* startThread(void* arg) ;
    static void* startCommitThread(void* arg) ;
    void run(uint32_t n);
    void runCommit();

    void haltAndWait();
    static void executeEvent(AsyncEventReceiver* sv, eventfunc func, mace::Message* p);
    static void commitEvent(const mace::Event& event);
    //static void commitEvent(const uint64_t eventID, const int8_t eventType, const uint32_t eventMessageCount);
  };
  HeadEventTP* HeadEventTPInstance() ;
}

#endif
