#include "ContextLock.h"
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
pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::ContextLock::smallestAbsentEvent = 0;
std::map<uint64_t, pthread_cond_t*> mace::ContextLock::notready_events;
