#include "HeadEventDispatch.h"
#include "ContextBaseClass.h"
#include "HierarchicalContextLock.h"
#include "Event.h"
namespace HeadEventDispatch {
  typedef std::pair<uint64_t, mace::Event*> CQType;
  typedef std::priority_queue< CQType, std::vector< CQType >, QueueComp<mace::Event*> > EventCommitQueueType;
  EventRequestQueueType headEventQueue;///< used by head context
  EventCommitQueueType headCommitEventQueue;
  bool halting = false;
  //pthread_mutex_t mace::AgentLock::_agent_commitbooth = PTHREAD_MUTEX_INITIALIZER;

  uint32_t minThreadSize;
  uint32_t maxThreadSize;
  pthread_t* HeadEventTP::headThread;
  pthread_t HeadEventTP::headCommitThread;
  //pthread_mutex_t queuelock = PTHREAD_MUTEX_INITIALIZER;
  //

  pthread_mutex_t HeadMigration::lock = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t eventQueueMutex = PTHREAD_MUTEX_INITIALIZER;
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
    if( headEventQueue.empty() ) return false;
    ADD_SELECTORS("HeadEventTP::hasPendingEvents");

    //return true;
    //mace::AgentLock::bypassTicket();

    //macedbg(1)<<"top = "<<headEventQueue.top().first<< ", now_serving="<< mace::AgentLock::now_serving << Log::endl;
    if( headEventQueue.top().first == mace::AgentLock::now_serving ){
      return true;
    }
    return false;
  }
  bool HeadEventTP::hasUncommittedEvents(){
    if( headCommitEventQueue.empty()  ) return false;
    ADD_SELECTORS("HeadEventTP::hasUncommittedEvents");

    const CQType& top = headCommitEventQueue.top();
    //mace::AgentLock::bypassCommit();

    macedbg(1)<<"top.first = "<< top.first << ", now_committing = "<< mace::AgentLock::now_committing<<Log::endl;
    if( top.first == mace::AgentLock::now_committing ){
      return true;
    }
    return false;
  }
  // setup
  void HeadEventTP::executeEventSetup( ){
      const RQType& top = headEventQueue.top();
      //const RQType& top = headEventQueue.front();
      ADD_SELECTORS("HeadEventTP::executeEventSetup");
      maceout<<"erase headEventQueue = " << top.first << Log::endl;
      ThreadStructure::setTicket( top.first );
      data = top.second;
      headEventQueue.pop();
      mace::AgentLock::ThreadSpecific::setCurrentMode( mace::AgentLock::NONE_MODE );
      //mace::AgentLock::removeMark();
  }
  void HeadEventTP::commitEventSetup( ){
      const CQType& top = headCommitEventQueue.top();
      ThreadStructure::setEvent(  *(top.second)  );
      delete top.second;
      mace::Event& myEvent = ThreadStructure::myEvent();
      ThreadStructure::setTicket( top.first );
      mace::AgentLock::ThreadSpecific::setCurrentMode( mace::AgentLock::READ_MODE );

      headCommitEventQueue.pop();

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
      //delete data;
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
    ASSERT(pthread_cond_wait(&signalv, &eventQueueMutex) == 0);
  }
  void HeadEventTP::commitWait() {
    ASSERT(pthread_cond_wait(&signalc, &mace::AgentLock::_agent_commitbooth) == 0);
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
    ADD_SELECTORS("HeadEventTP::run");
    ScopedLock sl(eventQueueMutex);
    while( !halting ){
      // wait for the data to be ready
      if( !hasPendingEvents() ){
        if( sleeping[ n ] == false ){
          sleeping[ n ] = true;
          idle ++;
        }
        macedbg(1)<<"sleep"<<Log::endl;
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

      //macedbg(1)<<"finished"<<Log::endl;

      sl.lock();
    }

  }
  void HeadEventTP::runCommit(){
    ScopedLock sl(mace::AgentLock::_agent_commitbooth);
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
    ScopedLock sl(eventQueueMutex);
    halting = true;
    HeadEventTPInstance()->signalAll();
    sl.unlock();

    ScopedLock sl2(mace::AgentLock::_agent_commitbooth);
    halting = true;
    HeadEventTPInstance()->signalCommitThread();
    sl2.unlock();

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
    ASSERT(pthread_mutex_destroy(&mace::AgentLock::_agent_commitbooth) == 0 );
  }
  void HeadEventTP::executeEvent(AsyncEventReceiver* sv, eventfunc func, mace::Message* p, bool useTicket){
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventTP::executeEvent");

    uint64_t myTicketNum;
    if( !useTicket ){
      ThreadStructure::newTicket();
    }
    myTicketNum = ThreadStructure::myTicket();
    HeadEvent thisev (sv,func,p, myTicketNum);

    ScopedLock sl(eventQueueMutex);

    macedbg(1)<<"enqueue ticket= "<< myTicketNum<<Log::endl;
    //headEventQueue[ myTicketNum ] = thisev;
    headEventQueue.push( RQType( myTicketNum, thisev ) );

    //macedbg(1)<<"event creation queue size = "<< headEventQueue.size() << Log::endl;

    //mace::AgentLock::markTicket( myTicketNum );
    if( HeadEventTPInstance()->idle > 0  && HeadEventTPInstance()->hasPendingEvents()){
      macedbg(1)<<"head thread idle, signal it"<< Log::endl;
      HeadEventTPInstance()->signalSingle();
    }
  }
  void HeadEventTP::commitEvent( const mace::Event& event){
  //void HeadEventTP::commitEvent( const uint64_t eventID, const int8_t eventType, const uint32_t eventMessageCount){
    ASSERT( event.eventType != mace::Event::UNDEFEVENT );
    if (halting) 
      return;

    ADD_SELECTORS("HeadEventTP::commitEvents");
   // const uint64_t ticketNum = mace::AgentLock::getClearEventTicket( event.eventID );
    const uint64_t ticketNum = event.eventID;

    ScopedLock sl(mace::AgentLock::_agent_commitbooth);

    macedbg(1)<<"enqueue commit event= "<< event.eventID<< ", ticket="<< ticketNum<<Log::endl;
    headCommitEventQueue.push( CQType( ticketNum, new mace::Event(event) ) );
    //headCommitEventQueue.push( CQType( ticketNum, event ) );

    if( !HeadEventTPInstance()->busyCommit /*&& HeadEventTPInstance()->hasUncommittedEvents()*/ ){
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
    minThreadSize = params::get<uint32_t>("NUM_HEAD_THREADS", 1);
    maxThreadSize = params::get<uint32_t>("MAX_HEAD_THREADS", 1);
    _inst = new HeadEventTP(minThreadSize, maxThreadSize);
  }
}
