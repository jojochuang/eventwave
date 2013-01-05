#ifndef __HEAD_EVENT_DISPATCH_h
#define __HEAD_EVENT_DISPATCH_h

#include "mace.h"
#include "mace-macros.h"
#include "ThreadPool.h"
class AsyncEventReceiver;
namespace mace{
  class AgentLock;
}
namespace HeadEventDispatch {
  typedef void (AsyncEventReceiver::*eventfunc)(void*);
  class HeadEvent {
    private: 
      AsyncEventReceiver* cl;
      eventfunc func;
      void* param;
      uint64_t ticket;

    public:
      HeadEvent() : cl(NULL), func(NULL), param(NULL) {}
      HeadEvent(AsyncEventReceiver* cl, eventfunc func, void* param, uint64_t ticket) : cl(cl), func(func), param(param), ticket(ticket) {}
      void fire() {
        // ASSERT(cl != NULL && func != NULL);
        ADD_SELECTORS("HeadEvent::fire");
        ThreadStructure::setTicket( ticket );
        macedbg(1)<<"Firing ticket= "<< ticket <<Log::endl;
        (cl->*func)(param);
      }
  };
  typedef std::map<uint64_t, HeadEventDispatch::HeadEvent> EventRequestQueueType;
  extern EventRequestQueueType headEventQueue;///< used by head context


  void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p);

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
    //uint64_t commitEventID;
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
    static void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p);
    //static void commitEvent(const mace::HighLevelEvent& event);
    static void commitEvent(const uint64_t eventID, const int8_t eventType, const uint32_t eventMessageCount);
  };
  HeadEventTP* HeadEventTPInstance() ;
}

#endif
