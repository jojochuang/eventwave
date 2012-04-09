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
      mace::ThreadPool<AsyncEventTP,AsyncEvent> *tp;

    private:
      bool runDeliverCondition(uint threadId) {
        ScopedLock sl(queuelock);
        return !asyncEventQueue.empty();
      }
      void runDeliverSetup(uint threadId) {
        ScopedLock sl(queuelock);
        ASSERT(tp != NULL);
        tp->data(threadId) = asyncEventQueue.front();
        asyncEventQueue.pop_front();
        // chuangw: obsolete.
        //ThreadStructure::newTicket();
      }
      void runDeliverProcessUnlocked(uint threadId) {
        tp->data(threadId).fire();
        //         mace::AgentLock()::possiblyNullTicket();
      }
      //       void runDeliverFinish(uint threadId) = 0;
      
    public:
      AsyncEventTP() : tp(new mace::ThreadPool<AsyncEventTP,AsyncEvent>(*this,&AsyncEventTP::runDeliverCondition,&AsyncEventTP::runDeliverProcessUnlocked,&AsyncEventTP::runDeliverSetup,NULL,params::get<uint32_t>("NUM_ASYNC_THREADS", 1))) {
        Log::log("AsyncEventTP::constructor") << "Created threadpool with " << params::get<uint32_t>("NUM_ASYNC_THREADS") << " threads." << Log::endl;
      }
      ~AsyncEventTP() {
        delete tp;
      }

      void signal() {
        tp->signal();
      }

      void haltAndWait() {
        tp->halt();
        tp->waitForEmpty();
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
      AsyncEventTPInstance()->signal();
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
