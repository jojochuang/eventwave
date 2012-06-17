#include <pthread.h>
#include <stdio.h>

#include "ContextLock.h"
#include "mace.h"
#include "ThreadStructure.h"
#include "SysUtil.h"
#include "HighLevelEvent.h"

#define NUM_CTXLOCK 10
void* CtxlockThread(void *p);
void * HierarchicalContextLockThread( void *p );
int acquiredLocks[ NUM_CTXLOCK ];
mace::ContextBaseClass ctx;
int test_option = 0;
#define TESTOPTION_NOCTXLOCK  1
#define TESTOPTION_USECTXLOCK  2
#define TESTOPTION_HIERCTXLOCK  3

std::list<std::string> ctxids;
std::list<std::string> ctx_created;
int main(int argc, char *argv[]){
  params::set("NUM_ASYNC_THREADS", "1");
  params::set("NUM_TRANSPORT_THREADS", "1");
  mace::Init(argc, argv);
  if( params::containsKey("TRACE_ALL") ){
    Log::autoAdd(".*");
  }
  test_option = params::get<int>("test_option",0);
  // TODO set up one monitor thread periodically checking the state
  // other threads acquire ContextLock and release it continously to see if deadlock occurs.
  pthread_t ctxlock_threads[ NUM_CTXLOCK ];
  for(int thcounter = 0; thcounter < NUM_CTXLOCK; thcounter++ ){
    acquiredLocks[ thcounter ] = 0;
    if( test_option == TESTOPTION_HIERCTXLOCK ){
      const char* ctxidstr[] = {"","A[0]", "A[0].B[0]", "A[1]", "A[2]", "A[0].B[1]"};
      ctxids.assign( ctxidstr, &ctxidstr[6]);
      if( pthread_create( &ctxlock_threads[thcounter], NULL, HierarchicalContextLockThread , (void*)thcounter ) != 0 ){
        perror("pthread_create");
      }
    }else{
      if( pthread_create( &ctxlock_threads[thcounter], NULL, CtxlockThread , (void*)thcounter ) != 0 ){
        perror("pthread_create");
      }
    }
  }
  for(int t=0;t< 10;t++ ){
    SysUtil::sleep(1);
    for(int c=0;c< NUM_CTXLOCK;c++){
      std::cout<< acquiredLocks[ c ] << " ";
    }
    std::cout<<std::endl;
  }
  for(int thcounter = 0; thcounter < NUM_CTXLOCK; thcounter++ ){
    void *ret;
    pthread_join( ctxlock_threads[thcounter], &ret  );
  }
  return 0; 
}
#define LOCK_PER_THREAD 100000
/* contextlock_test tests the simple functionality of ContextLock, 
 * that several threads can request write lock on the same context 
 * without deadlock */
void* CtxlockThread(void *p){
  int myid;
  memcpy(  &myid, (void*)&p, sizeof(int) );
  for( int locks=0; locks <  LOCK_PER_THREAD; locks++ ){
    ThreadStructure::newTicket();
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    if( test_option == TESTOPTION_NOCTXLOCK ){

    }else if ( test_option == TESTOPTION_USECTXLOCK ){
      mace::HighLevelEvent he( mace::HighLevelEvent::UNDEFEVENT );
      mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE );
      ThreadStructure::setEvent(he.eventID );
      mace::ContextLock clock( ctx, mace::ContextLock::WRITE_MODE );
      clock.downgrade( mace::ContextLock::NONE_MODE );
    }

    acquiredLocks[ myid ] ++;
  }
  std::cout<<"thread "<< myid <<" is leaving."<<std::endl;
  pthread_exit(NULL);
  return NULL;
}

/* this test emulates the full set of hierarchical context, message exchange/forward */
void * HierarchicalContextLockThread( void *p ){
  int myid;
  memcpy(  &myid, (void*)&p, sizeof(int) );

  for( int locks=0; locks <  LOCK_PER_THREAD; locks++ ){
    ThreadStructure::newTicket();
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    mace::HighLevelEvent he( mace::HighLevelEvent::UNDEFEVENT );
    mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE );
    ThreadStructure::setEvent(he.eventID );
    mace::ContextLock clock( ctx, mace::ContextLock::WRITE_MODE );
    clock.downgrade( mace::ContextLock::NONE_MODE );

    acquiredLocks[ myid ] ++;
  }

  pthread_exit(NULL);
  return NULL;
}
