#include "ContextLock.h"
pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mace::ContextLock::blockHeadMutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t mace::ContextLock::blockHeadCond = PTHREAD_COND_INITIALIZER;
bool mace::ContextLock::blockNewEventFlag = false;


#include "HierarchicalContextLock.h"
#include "AsyncDispatch.h"
using namespace AsyncDispatch;
extern uint32_t AsyncDispatch::maxUncommittedEvents;
bool mace::ContextLock::tooManyEvents(){
  // rate-limiting:
  //  if number of inflight (uncommitted events) is more than a threshold,
  //  wait to be signaled

  //ADD_SELECTORS("ContextLock::rateLimit");
  uint64_t uncommittedEvents = HierarchicalContextLock::getUncommittedEvents();
  if( uncommittedEvents >= maxUncommittedEvents ){
    return true;
  }
  return false;
  /*ScopedLock sl(blockHeadMutex);
  //uint64_t threshold = ( maxThreadSize )/ 10; // 4 is a magic number
  uint64_t uncommittedEvents = HierarchicalContextLock::getUncommittedEvents();
  // block just the first thread/event that exceeds threshold.
  // the rest of all will be blocked in context ticket booth waiting queue.
  if( !blockNewEventFlag && uncommittedEvents >= maxUncommittedEvents ){
    macedbg(1)<<" Uncommitted events = " << uncommittedEvents 
      << ", threadshold= "<< maxUncommittedEvents <<". Block" << Log::endl;
    blockNewEventFlag = true;
    pthread_cond_wait( &blockHeadCond, &blockHeadMutex );
  }*/
}
void mace::ContextLock::signalBlockedEvents(){
  ADD_SELECTORS("ContextLock::signalBlockedEvents");

  ScopedLock sl( _context_ticketbooth );

  mace::ContextBaseClass& context = mace::ContextBaseClass::headContext;

  // if no event is occupying the head context, and that the next event is ready, wake it up.
        if ( (context.numWriters == 0 && context.numReaders == 0 )&&
        (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) &&
        context.now_serving != context.notifiedHeadEventID /* make sure it is signaled just once */
        ) {
          context.notifiedHeadEventID = context.now_serving;
          macedbg(1) << "[" << context.contextID<<"] Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
  
  //ScopedLock sl(blockHeadMutex);
  //uint64_t threshold = ( maxThreadSize )/ 10; // 4 is a magic number
  /*uint64_t uncommittedEvents = HierarchicalContextLock::getUncommittedEvents();
  if( blockNewEventFlag  ){
    macedbg(1)<<" Signal blocking threads... "<< Log::endl;
    blockNewEventFlag = false;
    //for(uint64_t n=0; n< ( threshold- uncommittedEvents); n++){
      pthread_cond_signal(&blockHeadCond);
    //}
    //pthread_cond_broadcast(&blockHeadCond);
  }*/
}
