#include "HeadEventDispatch.h"
#include "ContextBaseClass.h"
#include "HierarchicalContextLock.h"
#include "Event.h"
namespace HeadEventDispatch {
  EventRequestQueueType headEventQueue;///< used by head context
  std::map< uint64_t, mace::Event > headCommitEventQueue;
  //std::map< uint64_t, std::pair<int8_t, uint32_t> > headCommitEventQueue;
  bool halting = false;

  uint32_t minThreadSize;
  uint32_t maxThreadSize;
  pthread_t* HeadEventTP::headThread;
  pthread_t HeadEventTP::headCommitThread;
  //pthread_mutex_t queuelock = PTHREAD_MUTEX_INITIALIZER;
  //

  pthread_mutex_t HeadMigration::lock = PTHREAD_MUTEX_INITIALIZER;
  uint16_t HeadMigration::state = HeadMigration::HEAD_STATE_NORMAL;
  uint64_t HeadMigration::migrationEventID;
  mace::MaceAddr HeadMigration::newHeadAddr;


  HeadEventTP::HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize) :
    idle( 0 ),
    sleeping( NULL ),
    args( NULL ),
    busyCommit( false ),
    minThreadSize( minThreadSize ), 
    maxThreadSize( maxThreadSize ) {
    Log::log("HeadEventTP::constructor") << "Created HeadEventTP threadpool with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;

    ASSERT(pthread_cond_init(&signalv, 0) == 0);
    ASSERT(pthread_cond_init(&signalc, 0) == 0);

    headThread = new pthread_t[ minThreadSize ];
    sleeping = new bool[ minThreadSize ];
    args = new ThreadArg[ minThreadSize ];
    for( uint32_t nThread = 0; nThread < minThreadSize; nThread++ ){
      sleeping[ nThread ] = 0;
      args[ nThread ].p = this;
      args[ nThread ].i = nThread;
      ASSERT(  pthread_create( & headThread[nThread] , NULL, HeadEventTP::startThread, (void*)&args[nThread] ) == 0 );
    }
    ASSERT(  pthread_create( & headCommitThread, NULL, HeadEventTP::startCommitThread, (void*)this ) == 0 );
  }

  HeadEventTP::~HeadEventTP() {
    delete headThread;
    delete args;
    delete sleeping;

  }
  // cond func
  bool HeadEventTP::hasPendingEvents(){
    if( headEventQueue.size() == 0 ) return false;

    EventRequestQueueType::iterator reqBegin = headEventQueue.begin();

    if( reqBegin->first == mace::AgentLock::now_serving ){
      return true;
    }
    return false;
  }
  bool HeadEventTP::hasUncommittedEvents(){
    if( headCommitEventQueue.size() == 0 ) return false;

    std::map< uint64_t, mace::Event >::iterator reqBegin = headCommitEventQueue.begin();
    //std::map< uint64_t, std::pair<int8_t, uint32_t> >::iterator reqBegin = headCommitEventQueue.begin();

    //if( reqBegin->first == mace::ContextBaseClass::headCommitContext.now_serving ){
    if( reqBegin->first == mace::AgentLock::now_committing ){
      return true;
    }
    return false;
  }
  // setup
  void HeadEventTP::executeEventSetup( ){
      ADD_SELECTORS("HeadEventTP::executeEventSetup");
      maceout<<"erase headEventQueue = " << headEventQueue.begin()->first << Log::endl;
      //mace::AgentLock::removeTicket( headEventQueue.begin()->first );
      data = headEventQueue.begin()->second;
      headEventQueue.erase(headEventQueue.begin());
      mace::AgentLock::ThreadSpecific::setCurrentMode( mace::AgentLock::NONE_MODE );
  }
  void HeadEventTP::commitEventSetup( ){

      ThreadStructure::setEvent(  headCommitEventQueue.begin()->second  );
      mace::Event& myEvent = ThreadStructure::myEvent();
      ThreadStructure::setTicket( headCommitEventQueue.begin()->first );
      mace::AgentLock::ThreadSpecific::setCurrentMode( mace::AgentLock::READ_MODE );

      headCommitEventQueue.erase(headCommitEventQueue.begin());

      // invariants for head migration
      const uint16_t hmState = HeadMigration::getState();
      ASSERT( hmState != HeadMigration::HEAD_STATE_MIGRATED );
      ASSERT( (hmState == HeadMigration::HEAD_STATE_NORMAL) ||
        (hmState == HeadMigration::HEAD_STATE_MIGRATING && HeadMigration::getMigrationEventID() >= myEvent.eventID )
      );
  }
  // process
  void HeadEventTP::executeEventProcess() {
      data.fire();
  }
  void HeadEventTP::commitEventProcess() {
    /*mace::ContextLock c_lock( mace::ContextBaseClass::headCommitContext, mace::ContextLock::WRITE_MODE );
    Accumulator::Instance(Accumulator::EVENT_COMMIT_COUNT)->accumulate(1); // increment committed event number
    ThreadStructure::myEvent().commit();
    BaseMaceService::globalCommitEvent( ThreadStructure::myEvent().eventID );
    c_lock.downgrade( mace::ContextLock::NONE_MODE );*/


    mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE ); // downgrade from read to none

  }

  void HeadEventTP::wait() {
    ASSERT(pthread_cond_wait(&signalv, &mace::AgentLock::_agent_ticketbooth) == 0);
  }
  void HeadEventTP::commitWait() {
    ASSERT(pthread_cond_wait(&signalc, &mace::AgentLock::_agent_ticketbooth) == 0);
    //ASSERT(pthread_cond_wait(&signalc, &mace::ContextBaseClass::headCommitContext._context_ticketbooth) == 0);
  }
  void HeadEventTP::signalSingle() {
    ADD_SELECTORS("HeadEventTP::signalSingle");
    macedbg(2) << "signal() called - just one thread." << Log::endl;
    pthread_cond_signal(&signalv);
  } // signal
  void HeadEventTP::signalAll() {
    ADD_SELECTORS("HeadEventTP::signalAll");
    macedbg(2) << "signal() called - all threads." << Log::endl;
    pthread_cond_broadcast(&signalv);
  } // signal

  void HeadEventTP::signalCommitThread() {
    ADD_SELECTORS("HeadEventTP::signalCommitThread");
    macedbg(2) << "signal() called - just one thread." << Log::endl;
    pthread_cond_signal(&signalc);
  } // signal

  /*void HeadEventTP::lock() const {
    ASSERT(pthread_mutex_lock(&mace::AgentLock::_agent_ticketbooth) == 0);
  } // lock

  void HeadEventTP::unlock() const {
    ASSERT(pthread_mutex_unlock(&mace::AgentLock::_agent_ticketbooth) == 0);
  } // unlock
  */

  void* HeadEventTP::startThread(void* arg) {
    struct ThreadArg* targ = ((struct ThreadArg*)arg);
    HeadEventTP* t = targ->p;
    t->run( targ->i  );
    return 0;
  }
  void* HeadEventTP::startCommitThread(void* arg) {
    HeadEventTP* t = (HeadEventTP*)(arg);
    t->runCommit();
    return 0;
  }
  void HeadEventTP::run(uint32_t n){
    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);
    while( !halting ){
      // wait for the data to be ready
      if( !hasPendingEvents() ){
        if( sleeping[ n ] == false ){
          sleeping[ n ] = true;
          idle ++;
        }
        wait();
        continue;
      }
      if( sleeping[n] == true){
        sleeping[n] = false;
        idle --;
      }

      // pickup the data
      executeEventSetup();
      // execute the data
      sl.unlock();
      executeEventProcess();

      sl.lock();
    }

  }
  void HeadEventTP::runCommit(){
    //ScopedLock sl(mace::ContextBaseClass::headCommitContext._context_ticketbooth);
    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);
    while( !halting ){
      // wait for the data to be ready
      if( !hasUncommittedEvents() ){
        busyCommit = false;
        commitWait();
        continue;
      }
      busyCommit = true;

      // pickup the data
      commitEventSetup();
      // execute the data
      sl.unlock();
      commitEventProcess();

      sl.lock();
    }

  }


  void HeadEventTP::haltAndWait() {
    //ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
    //tpptr->halt();
    //tpptr->waitForEmpty();
    
    
    // notify commit thread if it's idle
    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);
    halting = true;
    HeadEventTPInstance()->signalAll();
    //sl.unlock();

    //ScopedLock sl2(mace::ContextBaseClass::headCommitContext._context_ticketbooth);
    halting = true;
    HeadEventTPInstance()->signalCommitThread();
    //sl2.unlock();

    void* status;
    for( uint32_t nThread = 0; nThread < minThreadSize; nThread ++ ){
      int rc = pthread_join( headThread[ nThread ], &status );
      if( rc != 0 ){
        perror("pthread_join");
      }
    }
    int rc = pthread_join( headCommitThread, &status );
    if( rc != 0 ){
      perror("pthread_join");
    }

    ASSERT(pthread_cond_destroy(&signalv) == 0);
    ASSERT(pthread_cond_destroy(&signalc) == 0);
  }
  void HeadEventTP::executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p){
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventTP::executeEvent");

    uint64_t myTicketNum = ThreadStructure::myTicket();
    HeadEvent thisev(sv,func,p, myTicketNum);

    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);

    macedbg(1)<<"enqueue ticket= "<< myTicketNum<<Log::endl;
    headEventQueue[ myTicketNum ] = thisev;
    for( HeadEventDispatch::EventRequestQueueType::iterator it = HeadEventDispatch::headEventQueue.begin();
      it != HeadEventDispatch::headEventQueue.end(); it++ ){
      
      macedbg(1)<<it->first << " ";
    }
    macedbg(1)<<Log::endl;

    if( HeadEventTPInstance()->idle > 0 ){
      mace::AgentLock::markTicket( myTicketNum );
      HeadEventTPInstance()->signalSingle();
    }
  }
  void HeadEventTP::commitEvent( const mace::Event& event){
  //void HeadEventTP::commitEvent( const uint64_t eventID, const int8_t eventType, const uint32_t eventMessageCount){
    ASSERT( event.eventType != mace::Event::UNDEFEVENT );
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventTP::commitEvents");

    //ScopedLock sl(mace::ContextBaseClass::headCommitContext._context_ticketbooth);
    ScopedLock sl(mace::AgentLock::_agent_ticketbooth);

    const uint64_t ticketNum = mace::AgentLock::getEventTicket( event.eventID );
    mace::AgentLock::clearEventTicket( event.eventID );
    macedbg(1)<<"enqueue commit ticket= "<< event.eventID<<Log::endl;
    headCommitEventQueue[ ticketNum ] = event; //std::pair<int8_t, uint32_t>(eventType, eventMessageCount);

    if( !HeadEventTPInstance()->busyCommit ){
      HeadEventTPInstance()->signalCommitThread();
    }
  }

  HeadEventTP* _inst;
  HeadEventTP* HeadEventTPInstance() {
    return _inst;
  }
  void haltAndWait() {
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
