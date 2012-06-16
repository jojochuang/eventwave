
#include <pthread.h>
#include <stdio.h>

#include "ContextLock.h"
#include "mace.h"
#include "ThreadStructure.h"
#include "SysUtil.h"
#include "HighLevelEvent.h"

#define NUM_CTXLOCK 10
void* CtxlockThread(void *p);
int acquiredLocks[ NUM_CTXLOCK ];
int main(){
  // TODO set up one monitor thread periodically checking the state
  // other threads acquire ContextLock and release it continously to see if deadlock occurs.
  pthread_t ctxlock_threads[ NUM_CTXLOCK ];
  for(int thcounter = 0; thcounter < NUM_CTXLOCK; thcounter++ ){
    acquiredLocks[ thcounter ] = 0;
    int id = thcounter;
    if( pthread_create( &ctxlock_threads[thcounter], NULL, CtxlockThread , &id ) != 0 ){
      perror("pthread_create");
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
  return 1; 
}
#define LOCK_PER_THREAD 1000
void* CtxlockThread(void *p){
  int myid = *(int*)p;//pthread_self();
  mace::ContextBaseClass ctx;
  for( int locks=0; locks <  LOCK_PER_THREAD; locks++ ){
    ThreadStructure::newTicket();
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    //mace::HighLevelEvent he( mace::HighLevelEvent::UNDEFEVENT );
    //ThreadStructure::setEvent(he.eventID );
    //mace::ContextLock clock( ctx, mace::ContextLock::WRITE_MODE );
    mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE );

    //clock.downgrade( mace::ContextLock::NONE_MODE );
    acquiredLocks[ myid ] ++;
  }
  std::cout<<"thread "<< myid <<" is leaving."<<std::endl;
  pthread_exit(NULL);
  return NULL;
}
