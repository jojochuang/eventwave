#include "HeadEventDispatch.h"
namespace HeadEventDispatch {
  EventRequestQueueType headEventQueue;///< used by head context
  bool halting = false;

  uint32_t minThreadSize;
  uint32_t maxThreadSize;
  pthread_t HeadEventTP::headThread;
  //pthread_mutex_t queuelock = PTHREAD_MUTEX_INITIALIZER;

  HeadEventTP::HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize) :
    busy( false ),
    minThreadSize( minThreadSize ), 
    maxThreadSize( maxThreadSize ) {
    Log::log("HeadEventTP::constructor") << "Created HeadEventTP threadpool with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;

    ASSERT(pthread_cond_init(&signalv, 0) == 0);
    int rc = pthread_create( & headThread, NULL, HeadEventTP::startThread, (void*)this );
    if( rc != 0 ){
      perror("pthread_create");
    }
  }

  HeadEventTP::~HeadEventTP() {
    //ThreadPoolType *tp = tpptr;
    //tpptr = NULL;
    //delete tp;
  }
  // cond func
  bool HeadEventTP::hasPendingEvents(/*ThreadPoolType* tp, uint threadId*/){
    //ScopedLock sl(mace::AgentLock::_agent_ticketbooth);
    EventRequestQueueType::iterator reqBegin = headEventQueue.begin();
    if( reqBegin == headEventQueue.end() ) return false;

    if( reqBegin->first == mace::AgentLock::now_serving ){
      return true;
    }
    return false;
  }
  // setup
  void HeadEventTP::executeEventSetup(/*ThreadPoolType* tp, uint threadId*/ ){
      data = headEventQueue.begin()->second;
      headEventQueue.erase(headEventQueue.begin());
  }
  // process
  void HeadEventTP::executeEventProcess(/*ThreadPoolType* tp, uint threadId*/) {
      data.fire();
  }
  void HeadEventTP::wait() {
    ASSERT(pthread_cond_wait(&signalv, &mace::AgentLock::_agent_ticketbooth) == 0);
  }
  /*void HeadEventTP::signalSingleNoLock() {
  } // signal*/
  void HeadEventTP::signalSingle() {
    ADD_SELECTORS("HeadEventTP::signalSingle");
    macedbg(2) << "signal() called - just one thread." << Log::endl;
    pthread_cond_signal(&signalv);
  } // signal

  void HeadEventTP::lock() const {
    ASSERT(pthread_mutex_lock(&mace::AgentLock::_agent_ticketbooth) == 0);
  } // lock

  void HeadEventTP::unlock() const {
    ASSERT(pthread_mutex_unlock(&mace::AgentLock::_agent_ticketbooth) == 0);
  } // unlock

  void* HeadEventTP::startThread(void* arg) {
    HeadEventTP* t = (HeadEventTP*)(arg);
    t->run();
    return 0;
  }
  void HeadEventTP::run(){
    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);
    while( !halting ){
      // wait for the data to be ready
      if( !hasPendingEvents() ){
        busy = false;
        wait();
        continue;
      }
      busy = true;

      // pickup the data
      executeEventSetup();
      // execute the data
      sl.unlock();
      executeEventProcess();

      sl.lock();
    }

  }


  void HeadEventTP::haltAndWait() {
    //ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
    //tpptr->halt();
    //tpptr->waitForEmpty();
    void* status;
    int rc = pthread_join( headThread, &status );
    if( rc != 0 ){
      perror("pthread_join");
    }
    ASSERT(pthread_cond_destroy(&signalv) == 0);
  }
  void HeadEventTP::executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p){
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventTP::executeEvents");

    uint64_t myTicketNum = ThreadStructure::myTicket();
    HeadEvent thisev(sv,func,p, myTicketNum);

    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);

    macedbg(1)<<"enqueue ticket= "<< myTicketNum<<Log::endl;
    headEventQueue[ myTicketNum ] = thisev;

    //size_t busyThread = HeadEventTPInstance()->tpptr->size() - HeadEventTPInstance()->tpptr->sleepingSize();
    if( !HeadEventTPInstance()->busy ){
      //sl.unlock();

      HeadEventTPInstance()->signalSingle();
    }
  }

  HeadEventTP* _inst;
  HeadEventTP* HeadEventTPInstance() {
    return _inst;
  }
  void haltAndWait() {
    halting = true;
    // TODO: chuangw: need to execute all remaining event requests before halting.
    HeadEventTPInstance()->haltAndWait();
    delete HeadEventTPInstance();
  }

  void init() {
    //Assumed to be called from main() before stuff happens.
    minThreadSize = params::get<uint32_t>("NUM_HEAD_THREADS", 2);
    maxThreadSize = params::get<uint32_t>("MAX_HEAD_THREADS", 4);
    _inst = new HeadEventTP(minThreadSize, maxThreadSize);
  }
}
