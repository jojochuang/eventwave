#include "ContextBaseClass.h"
#include "ScopedLock.h"
#include <map>
using namespace mace;
ContextBaseClass::ContextBaseClass(const mace::string& contextID, const uint64_t ticket): 
    contextID(contextID),
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
        macedbg(1)<<"context '"<< contextID << "' is created at ticket "<< ticket << Log::endl;
    }
#ifdef __APPLE__
	pthread_once_t x = PTHREAD_ONCE_INIT;
	keyOnce = x;
#endif
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
  }else{
    ContextThreadSpecific* ctxts = (*t)[this];
    t->erase(this);
    delete ctxts;
  }
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

mace::ContextBaseClass mace::ContextBaseClass::headContext = mace::ContextBaseClass("(head)" );
pthread_once_t mace::ContextBaseClass::global_keyOnce= PTHREAD_ONCE_INIT ;
pthread_key_t mace::ContextBaseClass::global_pkey;
pthread_mutex_t mace::ContextBaseClass::eventCommitMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mace::ContextBaseClass::eventSnapshotMutex = PTHREAD_MUTEX_INITIALIZER;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventCommitConds;
std::map< uint64_t, pthread_cond_t* > mace::ContextBaseClass::eventSnapshotConds;
mace::snapshotStorageType mace::ContextBaseClass::eventSnapshotStorage;
