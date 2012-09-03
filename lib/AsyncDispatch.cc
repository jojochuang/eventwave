#include "AsyncDispatch.h"
#include "ThreadPool.h"
#include "ThreadStructure.h"
#include "params.h"
#include "Log.h"

namespace AsyncDispatch {

  bool halting = false;

  class AsyncEvent {
    private: 
      AsyncEventReceiver* cl;
      asyncfunc func;
      void* param;

    public:
      AsyncEvent() : cl(NULL), func(NULL), param(NULL) {}
      AsyncEvent(AsyncEventReceiver* cl, asyncfunc func, void* param) : cl(cl), func(func), param(param) {}
      void fire() {
        // ASSERT(cl != NULL && func != NULL);
        (cl->*func)(param);
      }
  };

  mace::deque<AsyncEvent, mace::SoftState> asyncEventQueue;
  pthread_mutex_t queuelock = PTHREAD_MUTEX_INITIALIZER;

  class AsyncEventTP {
    private: 
      typedef mace::ThreadPool<AsyncEventTP, AsyncEvent> ThreadPoolType;
      const uint32_t minThreadSize;
      const uint32_t maxThreadSize;
      ThreadPoolType *tpptr;

    private:
      bool runDeliverCondition(ThreadPoolType* tp, uint threadId) {
        ScopedLock sl(queuelock);
        return !asyncEventQueue.empty();
      }
      void runDeliverSetup(ThreadPoolType* tp, uint threadId) {
        ScopedLock sl(queuelock);
        tp->data(threadId) = asyncEventQueue.front();
        asyncEventQueue.pop_front();
        // chuangw: obsolete.
        ThreadStructure::newTicket();
      }
      void runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId) {
        tp->data(threadId).fire();
        //         mace::AgentLock()::possiblyNullTicket();
      }
      //       void runDeliverFinish(uint threadId) = 0;
      
    public:
      AsyncEventTP() :
        minThreadSize( params::get<uint32_t>("NUM_ASYNC_THREADS", 8) ), 
        maxThreadSize( params::get<uint32_t>("MAX_ASYNC_THREADS", 100) ), 
        tpptr(new ThreadPoolType(*this,&AsyncEventTP::runDeliverCondition,&AsyncEventTP::runDeliverProcessUnlocked,&AsyncEventTP::runDeliverSetup,NULL,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize)) {
      mace::ScopedContextRPC::setAsyncThreads( minThreadSize);
        Log::log("AsyncEventTP::constructor") << "Created threadpool with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;
      }
      ~AsyncEventTP() {
        ThreadPoolType *tp = tpptr;
        tpptr = NULL;
        delete tp;
      }

      void signal() {
        if (tpptr != NULL) {
          tpptr->signal();
        }
      }
      void signalSingle() {
        if (tpptr != NULL) {
          tpptr->signalSingle();
        }
      }

      void haltAndWait() {
        ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
        tpptr->halt();
        tpptr->waitForEmpty();
      }
  };

  AsyncEventTP* _inst;

  AsyncEventTP* AsyncEventTPInstance() {
    return _inst;
  }

  void enqueueEvent(AsyncEventReceiver* sv, asyncfunc func, void* p) {
    if (!halting) {
      ScopedLock sl(queuelock);
      asyncEventQueue.push_back(AsyncEvent(sv,func,p));
      sl.unlock();
      //AsyncEventTPInstance()->signal();
      AsyncEventTPInstance()->signalSingle();
    }
  }

  void init() {
    //Assumed to be called from main() before stuff happens.
    _inst = new AsyncEventTP();
  }

  void haltAndWait() {
    halting = true;
    AsyncEventTPInstance()->haltAndWait();
    delete AsyncEventTPInstance();
  }
  
}
