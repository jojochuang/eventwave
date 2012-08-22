#include "ContextBaseClass.h"
#include "ScopedLock.h"
#include <map>
using namespace mace;
ContextBaseClass::ContextBaseClass(const mace::string& contextID, const uint64_t ticket): 
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
    //no_nextcommitting(true),
    //no_nextserving(true),
    //next_committing( ),
    //next_serving( ),
    conditionVariables( ),
    commitConditionVariables( ),
    contextID(contextID),
    fan_in( 1 ),
    fan_out( 0 )
{
    if( ticket > 1 ){
        ADD_SELECTORS("ContextBaseClass::(constructor)");
        macedbg(1)<<"context '"<< contextID << "' is created at ticket "<< ticket << Log::endl;
    }
#ifdef __APPLE__
	pthread_once_t x = PTHREAD_ONCE_INIT;
	keyOnce = x;
#endif
}
typedef std::map<ContextBaseClass*, ContextThreadSpecific*> ThreadSpecificMapType;
// FIXME: it will not delete context thread structure in other threads.
ContextBaseClass::~ContextBaseClass(){
    // delete thread specific memories
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  ThreadSpecificMapType* t = (ThreadSpecificMapType *)pthread_getspecific(global_pkey);
  // FIXME: need to free all memories associated with pkey
  // this only releases the memory specific to this thread
  if( t == 0 ){
    //chuangw: this can happen if init() is never called on this context.
  }else{
    /*ThreadSpecificMapType::iterator ctIterator;
    std::cout<< t->size() << std::endl;
    for( ctIterator = t->begin(); ctIterator != t->end(); ctIterator++){
        std::cout<< ctIterator->second << std::endl;
    }*/
    ContextThreadSpecific* ctxts = (*t)[this];
    t->erase(this);
    delete ctxts;
  }
  //ASSERTMSG( versionMap.empty(), "the context class is being delete, but some snapshots have not been cleared" );
}
ContextThreadSpecific* ContextBaseClass::init(){
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  ThreadSpecificMapType *t = (ThreadSpecificMapType *)pthread_getspecific(mace::ContextBaseClass::global_pkey);
  if (t == 0) {
    t = new std::map<ContextBaseClass*, ContextThreadSpecific*>();
    assert( t != NULL );
    assert(pthread_setspecific(global_pkey, t) == 0);
  }
  ThreadSpecificMapType::iterator ctIterator = t->find(this);
  if( ctIterator == t->end() ){
      //ContextThreadSpecific* ctxts = new ContextThreadSpecific(*this);
      ContextThreadSpecific* ctxts = new ContextThreadSpecific();
      assert( ctxts != NULL );
      //(*t)[this] = ctxts;
      //ctIterator->second = ctxts;
      t->insert( std::pair< ContextBaseClass*, ContextThreadSpecific* >( this, ctxts ) );
      return ctxts;
  }
  // XXX need to double check to prevent race condition.
  //
  // chuangw: XXX bug?! In AgentLock code, it seems ThreadSpecific instances are never released from the memory
  //return (*t)[this];
  return ctIterator->second;
}
pthread_mutex_t mace::RunOnceCallBack::onceLock = PTHREAD_MUTEX_INITIALIZER;
// runOnce is used to guarnatee the context-specific key is initialized only once for each thread.
    // runOnce(): this imitates phtread_once() but supports object methods
/*void mace::runOnce(pthread_once_t& keyOnce, mace::RunOnceCallBack& funcObj){
    // this function is useless. but until the new code is mature, I will still keep this old code.
    ABORT("defunct");
    if( keyOnce == PTHREAD_ONCE_INIT ){
        ScopedLock sl( mace::RunOnceCallBack::onceLock );
        if( keyOnce == PTHREAD_ONCE_INIT ){
            funcObj();
            keyOnce = !PTHREAD_ONCE_INIT;
        }
    }
}*/
void mace::ContextBaseClass::createKeyOncePerThread(){
    assert(pthread_key_create(&global_pkey, NULL) == 0);
}

//mace::ContextBaseClass mace::ContextBaseClass::headContext = mace::ContextBaseClass("(head)" );
mace::ContextBaseClass mace::ContextBaseClass::globalContext = mace::ContextBaseClass("" );
mace::ContextBaseClass mace::ContextBaseClass::__internal_Context = mace::ContextBaseClass("(internal)" );
mace::ContextBaseClass mace::ContextBaseClass::__null_Context = mace::ContextBaseClass("(null)" );
pthread_once_t mace::ContextBaseClass::global_keyOnce= PTHREAD_ONCE_INIT ;
pthread_key_t mace::ContextBaseClass::global_pkey;
pthread_mutex_t mace::ContextBaseClass::headMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::newContextMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::__internal_ContextMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventCommitMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventSnapshotMutex = PTHREAD_MUTEX_INITIALIZER;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventCommitConds;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventSnapshotConds;
mace::snapshotStorageType mace::ContextBaseClass::eventSnapshotStorage;
uint64_t mace::ContextBaseClass::migrationTicket = 0;
mace::string mace::ContextBaseClass::migrationContext;
pthread_cond_t mace::ContextBaseClass::migrateContextCond = PTHREAD_COND_INITIALIZER;
