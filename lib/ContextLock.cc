#include "ContextLock.h"
//pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mace::ContextLock::blockHeadMutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t mace::ContextLock::blockHeadCond = PTHREAD_COND_INITIALIZER;
bool mace::ContextLock::blockNewEventFlag = false;


#include "HierarchicalContextLock.h"
#include "AsyncDispatch.h"
using namespace AsyncDispatch;
extern uint32_t AsyncDispatch::maxUncommittedEvents;
/*bool mace::ContextLock::tooManyEvents(){
  // rate-limiting:
  //  if number of inflight (uncommitted events) is more than a threshold,
  //  wait to be signaled

  //ADD_SELECTORS("ContextLock::rateLimit");
  uint64_t uncommittedEvents = HierarchicalContextLock::getUncommittedEvents();
  if( uncommittedEvents >= maxUncommittedEvents ){
    return true;
  }
  return false;
}*/
void mace::ContextLock::signalBlockedEvents(){
  /*ADD_SELECTORS("ContextLock::signalBlockedEvents");

  ScopedLock sl( _context_ticketbooth );

  mace::ContextBaseClass& context = mace::ContextBaseClass::headContext;

  // if no event is occupying the head context, and that the next event is ready, wake it up.
        if ( (context.numWriters == 0 && context.numReaders == 0 )&&
        (context.conditionVariables.begin() != context.conditionVariables.end() && context.conditionVariables.begin()->first == context.now_serving) &&
        context.now_serving != context.notifiedHeadEventID // make sure it is signaled just once 
        ) {
          context.notifiedHeadEventID = context.now_serving;
          macedbg(1) << "[" << context.contextID<<"] Signalling CV " << context.conditionVariables.begin()->second << " for ticket " << context.now_serving << Log::endl;
          pthread_cond_broadcast(context.conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
  */
}

/*#include "HeadEventDispatch.h"
bool mace::ContextLock::signalCommitEvent(ContextBaseClass& ctx ){
  ADD_SELECTORS("ContextLock::signalCommitEvent");
  std::set< uint64_t >::iterator reqBegin = HeadEventDispatch::headCommitEventQueue.begin();
  if( reqBegin == HeadEventDispatch::headCommitEventQueue.end() ){
    macedbg(1) << "Head event queue is empty " << Log::endl;
    return false;
  }
  if( reqBegin->first == ctx.now_serving && !HeadEventDispatch::HeadEventTPInstance()->busyCommit   ){
    macedbg(1) << "Now signalling ticket number " << ctx.now_serving << " (my ticket is " << ThreadStructure::myTicket() << " )" << Log::endl;
    HeadEventDispatch::HeadEventTPInstance()->signalCommitThread();
    return true;
  }else{
    macedbg(1) << "Next head event ticket is "<< *reqBegin <<", now_serving = "<< ctx.now_serving <<" busyCommit = "<< HeadEventDispatch::HeadEventTPInstance()->busyCommit <<" Don't signal."<< Log::endl;
  }
  return false;
}
*/
