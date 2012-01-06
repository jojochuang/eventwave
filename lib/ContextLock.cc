#include "ContextLock.h"
pthread_mutex_t mace::RunOnceCallBack::onceLock = PTHREAD_MUTEX_INITIALIZER;;
//pthread_once_t mace::ContextLock::keyOnce = PTHREAD_ONCE_INIT;
void mace::runOnce(pthread_once_t& keyOnce, mace::RunOnceCallBack& funcObj){
    if( keyOnce == PTHREAD_ONCE_INIT ){
        ScopedLock sl( mace::RunOnceCallBack::onceLock );
        if( keyOnce == PTHREAD_ONCE_INIT ){
            funcObj();
            keyOnce = !PTHREAD_ONCE_INIT;
        }
    }
}
pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
