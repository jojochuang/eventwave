#include "AsyncDispatch.h"
#include "ThreadPool.h"
#include "ThreadStructure.h"
#include "params.h"
#include "Log.h"

namespace AsyncDispatch {

  bool halting = false;

  uint32_t minThreadSize;
  uint32_t maxThreadSize;
  uint32_t maxUncommittedEvents;
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
    public:
      typedef mace::ThreadPool<AsyncEventTP, AsyncEvent> ThreadPoolType;
    private: 
      const uint32_t minThreadSize;
      const uint32_t maxThreadSize;
      ThreadPoolType *tpptr;

      uint32_t deferEvents;

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
      
      void runDeliverProcessFinish(ThreadPoolType* tp, uint threadId){
        //signalSingle();
        //chuangw: TODO
        // if it finds that the thread pool is in "PAUSE" mode, it signals
        // a thread to process the next async event object.
        ScopedLock sl(queuelock);
        if( !asyncEventQueue.empty() ){
          sl.unlock();
          uint32_t idleThreads = tpptr->sleepingSize();
          uint32_t deferEvents = asyncEventQueue.size();
          uint32_t signalEvents = (deferEvents <= idleThreads)?(deferEvents):(idleThreads);
          tpptr->unlock();
          for(uint32_t signaledThreads = 0 ; signaledThreads < signalEvents; signaledThreads++ ){
            tpptr->signalSingle();
          }
          tpptr->lock();
        }
        /*ScopedLock sl(queuelock);
        if( deferEvents > 0 ){
          uint32_t idleThreads = tpptr->sleepingSize();
          uint32_t signalEvents = (deferEvents <= idleThreads)?(deferEvents):(idleThreads);

          for(uint32_t signaledThreads = 0 ; signaledThreads < signalEvents; signaledThreads++ ){
            tpptr->signalSingle();
          }

          deferEvents -= signalEvents;
        }*/
      }
    public:
      AsyncEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize) :
        minThreadSize( params::get<uint32_t>("NUM_ASYNC_THREADS", 8) ), 
        maxThreadSize( params::get<uint32_t>("MAX_ASYNC_THREADS", 1000) ), 
        //tpptr(new ThreadPoolType(*this,&AsyncEventTP::runDeliverCondition,&AsyncEventTP::runDeliverProcessUnlocked,&AsyncEventTP::runDeliverSetup,&AsyncEventTP::runDeliverProcessFinish,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize)),
        tpptr(new ThreadPoolType(*this,&AsyncEventTP::runDeliverCondition,&AsyncEventTP::runDeliverProcessUnlocked,&AsyncEventTP::runDeliverSetup,NULL,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize)),
        deferEvents(false) {
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

      ThreadPoolType* getThreadPoolObject(){
        return tpptr;
      }

      /*uint32_t (){
        return deferEvents;
      }*/
      void incrementDeferEvents(){
        deferEvents++;
      }
      uint32_t getDeferEvents(){
        return deferEvents;
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

      
      //AsyncEventTP::ThreadPoolType* tp = AsyncEventTPInstance()->getThreadPoolObject();
      // Idea: make sure number of busy(non-idle) threads is <= maxThreadSize -1
      //      otherwise it will not make progress
      //
      // if the runtime has already reached the maximum thread limit
      // and that (highest ticket number) - (agentlock.now_serving) >= maxThreadSize - x
      //

      //if( tp->size() == maxThreadSize   ){

      //}else{
        sl.unlock();
        AsyncEventTPInstance()->signalSingle();
      //}


      /*
      // chuangw: TODO: 
      // the runtime should signal a thread only when there is sufficient number of threads
      AsyncEventTP::ThreadPoolType* tp = AsyncEventTPInstance()->getThreadPoolObject();
        // if not it raises a flag
      if( tp->size() == maxThreadSize && 
        (AsyncEventTPInstance()->getDeferEvents() || tp->isAllBusy()) 
      ){
        AsyncEventTPInstance()->incrementDeferEvents();
      }else{
        //
        // if it's OK, signal a thread to process it.
        sl.unlock();
        AsyncEventTPInstance()->signalSingle();
      }
      */
    }
  }

  void init() {
    //Assumed to be called from main() before stuff happens.
    minThreadSize = params::get<uint32_t>("NUM_ASYNC_THREADS", 8);
    maxThreadSize = params::get<uint32_t>("MAX_ASYNC_THREADS", 1000);
    maxUncommittedEvents = params::get<uint32_t>("MAX_UNCOMMITTED_EVENTS", maxThreadSize/10 );
    _inst = new AsyncEventTP(minThreadSize, maxThreadSize);
  }

  void haltAndWait() {
    halting = true;
    AsyncEventTPInstance()->haltAndWait();
    delete AsyncEventTPInstance();
  }
  
}
