#include "HeadEventDispatch.h"
#include "ThreadPool.h"
namespace HeadEventDispatch {
  bool halting = false;

  uint32_t minThreadSize;
  uint32_t maxThreadSize;
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
        ThreadStructure::setTicket( ticket );
        (cl->*func)(param);
      }
  };
  pthread_mutex_t queuelock = PTHREAD_MUTEX_INITIALIZER;
  typedef std::map<uint64_t, HeadEventDispatch::HeadEvent> EventRequestQueueType;
  EventRequestQueueType headEventQueue;///< used by head context
  class HeadEventTP{
  public:
  typedef mace::ThreadPool<HeadEventTP, HeadEvent> ThreadPoolType;
  private: 
    const uint32_t minThreadSize;
    const uint32_t maxThreadSize;
    ThreadPoolType *tpptr;
  public:
    HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize) :
      minThreadSize( minThreadSize ), 
      maxThreadSize( maxThreadSize ), 
      tpptr(new ThreadPoolType(*this,&HeadEventTP::hasPendingEvents,&HeadEventTP::executeEventProcess,&HeadEventTP::executeEventSetup,NULL,ThreadStructure::HEAD_THREAD_TYPE,minThreadSize, maxThreadSize)) {
      Log::log("HeadEventTP::constructor") << "Created HeadEventTP threadpool with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;
    }

    ~HeadEventTP() {
      ThreadPoolType *tp = tpptr;
      tpptr = NULL;
      delete tp;
    }

    void signalSingle() {
      if (tpptr != NULL) {
        tpptr->signalSingle();
      }
    }
    // cond func
    bool hasPendingEvents(ThreadPoolType* tp, uint threadId){
      ScopedLock sl(queuelock);
      EventRequestQueueType::iterator reqBegin = headEventQueue.begin();
      if( reqBegin == headEventQueue.end() ) return false;

      /*if( reqBegin->first == now_serving ){
        return true;
      }*/

      return true;
    }
    /*static bool executePendingEvents(){
      ADD_SELECTORS("HeadEventTP::executePendingEvents");
      ScopedLock sl(queuelock);
      EventRequestQueueType::iterator reqBegin = headEventQueue.begin();
      if( reqBegin == headEventQueue.end() ) return false;
      uint64_t frontRequestTicket=0;

      while( (frontRequestTicket = reqBegin->first) == now_serving ){
        HeadEvent ev = reqBegin->second;

        headEventQueue.erase( reqBegin );
        sl.unlock();

        ThreadStructure::setTicket( frontRequestTicket );
        macedbg(1)<<"processing an event request...ticket="<< frontRequestTicket<<Log::endl;
        ev.fire();

        sl.lock();
        reqBegin = headEventQueue.begin();
      }
      ASSERT( headEventQueue.empty() || frontRequestTicket > now_serving );
      // after processing all eligible pending head event requests, look 
      // at other waiting threads
      std::map<uint64_t, pthread_cond_t*>::iterator condBegin = conditionVariables.begin();
      if (! conditionVariables.empty() && condBegin->first == now_serving
      &&  (numReaders != 0 || numWriters != 0)
      // chuangw: Assuming all AgentLock request are WRITE. No read lock
      ) {
        macedbg(1) << "Now signalling ticket number " << now_serving << Log::endl;
        pthread_cond_signal(condBegin->second); // only signal if this is a reader -- writers should signal on commit only.
      }

      return true;
    }*/
    // setup
    void executeEventSetup(ThreadPoolType* tp, uint threadId) {
        ScopedLock sl(queuelock);
        //uint64_t ticket = headEventQueue.begin()->first;
        tp->data(threadId) = headEventQueue.begin()->second;
        headEventQueue.erase(headEventQueue.begin());
    }
    // process
    void executeEventProcess(ThreadPoolType* tp, uint threadId) {
        tp->data(threadId).fire();
    }

    void haltAndWait() {
      ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
      tpptr->halt();
      tpptr->waitForEmpty();
    }
    
    // finish
    /*void executeEventFinish(ThreadPoolType* tp, uint threadId){
    }*/
  };
  HeadEventTP* _inst;
  HeadEventTP* HeadEventTPInstance() {
    return _inst;
  }
  void haltAndWait() {
    halting = true;
    HeadEventTPInstance()->haltAndWait();
    delete HeadEventTPInstance();
  }
  void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p){
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventDispatch::executeEvents");
    ScopedLock sl(queuelock);

    //bool execThisEvent = false;
    uint64_t myTicketNum = ThreadStructure::myTicket();
    HeadEvent thisev(sv,func,p, myTicketNum);
    /*if( myTicketNum == now_serving ){
      sl.unlock();
      macedbg(1)<<"fire! ticket= "<< myTicketNum<<Log::endl;

      thisev.fire();
      execThisEvent = true;
      sl.lock();
    }else{*/
      macedbg(1)<<"enqueue ticket= "<< myTicketNum<<Log::endl;
      headEventQueue[ myTicketNum ] = thisev;
      //ASSERT( myTicketNum > now_serving );
    //}

    sl.unlock();

    HeadEventTPInstance()->signalSingle();
    /*bool pendingEvents = executePendingEvents();

    return (execThisEvent || pendingEvents );*/

    //return true;
    
  }

  void init() {
    //Assumed to be called from main() before stuff happens.
    minThreadSize = params::get<uint32_t>("NUM_HEAD_THREADS", 2);
    maxThreadSize = params::get<uint32_t>("MAX_HEAD_THREADS", 4);
    _inst = new HeadEventTP(minThreadSize, maxThreadSize);
  }
}
