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
        ADD_SELECTORS("HeadEventEvent::fire");
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

  class HeadEventTP{
  friend class mace::AgentLock;
  public:
  //typedef mace::ThreadPool<HeadEventTP, HeadEvent> ThreadPoolType;
  private: 
    bool busy;
    const uint32_t minThreadSize;
    const uint32_t maxThreadSize;
    //ThreadPoolType *tpptr;
    static pthread_t headThread;
    HeadEvent data;
    pthread_cond_t signalv;
  public:
    HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize);

    ~HeadEventTP() ;

    void wait();
    void lock() const;
    void unlock() const;

    void signalSingleNoLock() ;
    void signalSingle() ;
    // cond func
    bool hasPendingEvents(/*ThreadPoolType* tp, uint threadId*/);
    // setup
    void executeEventSetup(/*ThreadPoolType* tp, uint threadId*/);
    // process
    void executeEventProcess(/*ThreadPoolType* tp, uint threadId*/);

    static void* startThread(void* arg) ;
    void run();

    void haltAndWait();
    static void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p);
  };
  HeadEventTP* HeadEventTPInstance() ;
}

#endif
