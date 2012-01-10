#include "ContextBaseClass.h"
#include "ScopedLock.h"
using namespace mace;
ContextBaseClass::ContextBaseClass(): 
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
    commitConditionVariables( )//,
    //contextThreadSpecific( *this )
{
    //contextThreadSpecific = new ContextThreadSpecific(*this);
}
ContextBaseClass::~ContextBaseClass(){
    //delete contextThreadSpecific;
}
ContextThreadSpecific* ContextBaseClass::init(){
  runOnce( keyOnce, *this );
  ContextThreadSpecific* t = (ContextThreadSpecific*)pthread_getspecific(pkey);
  if (t == 0) {
    t = new ContextThreadSpecific(*this);
    assert(pthread_setspecific(pkey, t) == 0);
  }
  // chuangw: XXX bug?! In AgentLock code, it seems ThreadSpecific instances are never released from the memory
  return t;
}
pthread_mutex_t mace::RunOnceCallBack::onceLock = PTHREAD_MUTEX_INITIALIZER;
// runOnce is used to guarnatee the context-specific key is initialized only once for each thread.
    // runOnce(): this imitates phtread_once() but supports object methods
void mace::runOnce(pthread_once_t& keyOnce, mace::RunOnceCallBack& funcObj){
    if( keyOnce == PTHREAD_ONCE_INIT ){
        ScopedLock sl( mace::RunOnceCallBack::onceLock );
        if( keyOnce == PTHREAD_ONCE_INIT ){
            funcObj();
            keyOnce = !PTHREAD_ONCE_INIT;
        }
    }
}

mace::ContextBaseClass mace::ContextBaseClass::globalContext;
