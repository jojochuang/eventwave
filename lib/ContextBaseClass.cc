#include "ContextBaseClass.h"
#include "ContextDispatch.h"
#include "ScopedLock.h"
#include <map>
using namespace mace;
ContextBaseClass::ContextBaseClass(const mace::string& contextName, const uint64_t ticket, const uint8_t serviceID, const uint32_t contextID, const mace::vector< uint32_t >& parentID, const uint8_t contextType): 
    contextName(contextName),
    contextType( contextType ),
    serviceID( serviceID ),
    contextID( contextID ),
    parentID( parentID ),
    pkey(),
#ifdef __APPLE__
#else
    keyOnce( PTHREAD_ONCE_INIT ),
#endif
    now_serving(ticket),
    now_committing(ticket),
    lastWrite (1), // chuangw: not used? I can't remember
    numReaders(0),
    numWriters(0),
    conditionVariables( ),
    commitConditionVariables( )
{
    if( ticket > 1 ){
        ADD_SELECTORS("ContextBaseClass::(constructor)");
        macedbg(1)<<"context '"<< contextName << "' id: "<< contextID << " is created at ticket "<< ticket << Log::endl;
    }
#ifdef __APPLE__
	pthread_once_t x = PTHREAD_ONCE_INIT;
	keyOnce = x;
#endif

  pthread_mutex_init( &_context_ticketbooth, NULL );

  /* TODO: initializes context specific thread pool
   * */

  uint32_t minThreadSize = params::get<uint32_t>("NUM_CONTEXT_THREADS", 1);
  uint32_t maxThreadSize = params::get<uint32_t>("MAX_CONTEXT_THREADS", 1);
  eventDispatcher = new ContextEventTP(  this, minThreadSize, maxThreadSize );
}
// FIXME: it will not delete context thread structure in other threads.
ContextBaseClass::~ContextBaseClass(){

    // delete thread specific memories
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  ThreadSpecificMapType* t = (ThreadSpecificMapType *)pthread_getspecific(global_pkey);
  // FIXME: need to free all memories associated with pkey
  // this only releases the memory specific to this thread
  if( t == 0 ){
    //chuangw: this can happen if init() is never called on this context.
    // that is, this thread has never accessed this context.
  }else{
    ContextThreadSpecific* ctxts = (*t)[this];
    t->erase(this);
    delete ctxts;
  }
  pthread_mutex_destroy( &_context_ticketbooth );

  /* TODO: delete context specific thread pool
   * */
}
ContextThreadSpecific* ContextBaseClass::init(){
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  ThreadSpecificMapType *t = (ThreadSpecificMapType *)pthread_getspecific(mace::ContextBaseClass::global_pkey);
  if (t == 0) {
    t = new mace::hash_map<ContextBaseClass*, ContextThreadSpecific*, SoftState>();
    assert( t != NULL );
    assert(pthread_setspecific(global_pkey, t) == 0);
  }
  ThreadSpecificMapType::iterator ctIterator = t->find(this);
  if( ctIterator == t->end() ){
      ContextThreadSpecific* ctxts = new ContextThreadSpecific();
      assert( ctxts != NULL );
      t->insert( std::pair< ContextBaseClass*, ContextThreadSpecific* >( this, ctxts ) );
      return ctxts;
  }
  return ctIterator->second;
}
void mace::ContextBaseClass::createKeyOncePerThread(){
    assert(pthread_key_create(&global_pkey, NULL) == 0);
}
void mace::ContextBaseClass::print(std::ostream& out) const {
  out<< "ContextBaseClass(";
  out<< "contextName="; mace::printItem(out, &(contextName) ); out<<", ";
  out<< "contextID="; mace::printItem(out, &(contextID) ); out<<", ";
  out<< "now_serving="; mace::printItem(out, &(now_serving) ); out<<", ";
  out<< "now_committing="; mace::printItem(out, &(now_committing) ); out<<", ";
  out<< "lastWrite="; mace::printItem(out, &(lastWrite) ); out<<", ";
  out<< "numReaders="; mace::printItem(out, &(numReaders) ); out<<", ";
  out<< "numWriters="; mace::printItem(out, &(numWriters) ); out<<", ";
  out<< "uncommittedEvents="; mace::printItem(out, &(uncommittedEvents) );
  out<< ")";

} // print

void mace::ContextBaseClass::printNode(PrintNode& pr, const std::string& name) const {
  mace::PrintNode printer(name, "ContextBaseClass" );
  
  mace::printItem( printer, "contextName", &contextName );
  mace::printItem( printer, "contextID", &contextID );
  mace::printItem( printer, "now_serving", &now_serving );
  mace::printItem( printer, "now_committing", &now_committing );
  mace::printItem( printer, "lastWrite", &lastWrite );
  mace::printItem( printer, "numReaders", &numReaders );
  mace::printItem( printer, "numWriters", &numWriters );
  mace::printItem( printer, "uncommittedEvents", &uncommittedEvents );
  pr.addChild( printer );
}

mace::ContextBaseClass mace::ContextBaseClass::headContext = mace::ContextBaseClass("(head)",1, 0, 0, mace::vector< uint32_t >(), mace::ContextBaseClass::HEAD );
mace::ContextBaseClass mace::ContextBaseClass::headCommitContext = mace::ContextBaseClass("(headcommit)", 1, 0, 1, mace::vector< uint32_t >(), mace::ContextBaseClass::HEAD );
pthread_once_t mace::ContextBaseClass::global_keyOnce= PTHREAD_ONCE_INIT ;
pthread_key_t mace::ContextBaseClass::global_pkey;
pthread_mutex_t mace::ContextBaseClass::eventCommitMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventSnapshotMutex = PTHREAD_MUTEX_INITIALIZER;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventCommitConds;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventSnapshotConds;
mace::snapshotStorageType mace::ContextBaseClass::eventSnapshotStorage;
//uint64_t mace::ContextBaseClass::notifiedHeadEventID=0;

void mace::ContextBaseClass::enqueueEvent(AsyncEventReceiver* sv, ctxeventfunc func, mace::Message* p, mace::Event const& event) {
  //if (!halting) {
    ScopedLock sl(_context_ticketbooth);


    uint64_t skipID = event.getSkipID( serviceID, contextID, parentID);
    uint64_t eventID = event.getEventID();

    //Event* eventptr = new Event( event );
    eventQueue.push( RQType( RQIndexType( eventID, skipID ), ContextEvent(sv,func,p)) );

    
    ADD_SELECTORS("ContextBaseClass::enqueueEvent");
    macedbg(1)<<"enque an object = "<< p << ", eventID = " << eventID << Log::endl;

      sl.unlock();
      eventDispatcher->signal();
  //}
}
