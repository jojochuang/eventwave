#include "ContextBaseClass.h"
#include "ScopedLock.h"
//#include "m_map.h"
#include <map>
using namespace mace;

ContextBaseClass::ContextBaseClass(const mace::string& contextID): 
    pkey(),
    keyOnce( PTHREAD_ONCE_INIT ),
    now_serving(1),
    now_committing(1),
    lastWrite (1),
    numReaders(0),
    numWriters(0),
    no_nextcommitting(true),
    no_nextserving(true),
    next_committing( ),
    next_serving( ),
    conditionVariables( ),
    commitConditionVariables( ),
    contextID(contextID)
    //contextThreadSpecific( *this )
{
    //contextThreadSpecific = new ContextThreadSpecific(*this);
}
ContextBaseClass::~ContextBaseClass(){
    // delete thread specific memories
  //ContextThreadSpecific* t = (ContextThreadSpecific*)pthread_getspecific(pkey);
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
    // delete keys
    //
    //if( mace::ContextBaseClass::keyOnce != PTHREAD_ONCE_INIT )
    //    pthread_key_delete(pkey);
}
ContextThreadSpecific* ContextBaseClass::init(){
  //runOnce( keyOnce, *this );
  pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
  //ContextThreadSpecific* t = (ContextThreadSpecific*)pthread_getspecific(pkey);
  std::map<ContextBaseClass*, ContextThreadSpecific*> *t = (std::map<ContextBaseClass*, ContextThreadSpecific*>*)pthread_getspecific(mace::ContextBaseClass::global_pkey);
  if (t == 0) {
    //t = new ContextThreadSpecific(*this);
    t = new std::map<ContextBaseClass*, ContextThreadSpecific*>();
    assert( t != NULL );
    //assert(pthread_setspecific(pkey, t) == 0);
    assert(pthread_setspecific(global_pkey, t) == 0);
  }
  if( t->find(this) == t->end() ){
      ContextThreadSpecific* ctxts = new ContextThreadSpecific(*this);
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
void mace::runOnce(pthread_once_t& keyOnce, mace::RunOnceCallBack& funcObj){
    // this function is useless. but until the new code is mature, I will still keep this old code.
    ABORT("defunct");
    if( keyOnce == PTHREAD_ONCE_INIT ){
        ScopedLock sl( mace::RunOnceCallBack::onceLock );
        if( keyOnce == PTHREAD_ONCE_INIT ){
            funcObj();
            keyOnce = !PTHREAD_ONCE_INIT;
        }
    }
}
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