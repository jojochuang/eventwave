#include "ContextBaseClass.h"
#include "ScopedLock.h"
//#include "m_map.h"
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
    no_nextcommitting(true),
    no_nextserving(true),
    next_committing( ),
    next_serving( ),
    conditionVariables( ),
    commitConditionVariables( ),
    contextID(contextID),
    fan_in( 1 ),
    fan_out( 0 )
    //contextThreadSpecific( *this )
{
#ifdef __APPLE__
	pthread_once_t x = PTHREAD_ONCE_INIT;
	keyOnce = x;
#endif
    //contextThreadSpecific = new ContextThreadSpecific(*this);
}
ContextBaseClass::~ContextBaseClass(){
    // delete thread specific memories
  std::map<ContextBaseClass*, ContextThreadSpecific*>* t = (std::map<ContextBaseClass*, ContextThreadSpecific*>*)pthread_getspecific(global_pkey);
  // FIXME: need to free all memories associated with pkey
  // this only releases the memory specific to this thread
  if( t == 0 ){
    //ABORT("unexpected error: pthread_getspecific() returns NULL pointer");
    //chuangw: this can happen.
  }else{
    ContextThreadSpecific* ctxts = (*t)[this];
    t->erase(this);
    delete ctxts;
  }
}
ContextThreadSpecific* ContextBaseClass::init(){
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  std::map<ContextBaseClass*, ContextThreadSpecific*> *t = (std::map<ContextBaseClass*, ContextThreadSpecific*>*)pthread_getspecific(mace::ContextBaseClass::global_pkey);
  if (t == 0) {
    t = new std::map<ContextBaseClass*, ContextThreadSpecific*>();
    assert( t != NULL );
    assert(pthread_setspecific(global_pkey, t) == 0);
  }
  if( t->find(this) == t->end() ){
      //ContextThreadSpecific* ctxts = new ContextThreadSpecific(*this);
      ContextThreadSpecific* ctxts = new ContextThreadSpecific();
      assert( ctxts != NULL );
      (*t)[this] = ctxts;
  }
  // XXX need to double check to prevent race condition.
  //
  // chuangw: XXX bug?! In AgentLock code, it seems ThreadSpecific instances are never released from the memory
  //return t;
  return (*t)[this];
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

mace::ContextBaseClass mace::ContextBaseClass::globalContext = mace::ContextBaseClass("(global)" );
mace::ContextBaseClass mace::ContextBaseClass::__internal_Context = mace::ContextBaseClass("(internal)" );
mace::ContextBaseClass mace::ContextBaseClass::__null_Context = mace::ContextBaseClass("(null)" );
pthread_once_t mace::ContextBaseClass::global_keyOnce= PTHREAD_ONCE_INIT ;
pthread_key_t mace::ContextBaseClass::global_pkey;
pthread_mutex_t mace::ContextBaseClass::newContextMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::__internal_ContextMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventCommitMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventSnapshotMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::awaitingReturnMutex = PTHREAD_MUTEX_INITIALIZER;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventCommitConds;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventSnapshotConds;
mace::snapshotStorageType mace::ContextBaseClass::eventSnapshotStorage;
