#include "ContextDispatch.h"

bool mace::ContextEventTP::runDeliverCondition(ThreadPoolType* tp, uint threadId) {
  ScopedLock sl( context->_context_ticketbooth);
  if( !context->eventQueue.empty() && context->eventQueue.top().first == context->now_serving )
    return true;
  return false;
}
void mace::ContextEventTP::runDeliverSetup(ThreadPoolType* tp, uint threadId) {
  ScopedLock sl( context->_context_ticketbooth);
  tp->data(threadId) = context->eventQueue.top().second;
  ADD_SELECTORS("ContextEventTP::runDeliverSetup");
  macedbg(1)<<"dequeue an object = "<< context->eventQueue.top().first << Log::endl;

  context->eventQueue.pop();
}
void mace::ContextEventTP::runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId) {
  tp->data(threadId).fire();
}
void mace::ContextEventTP::runDeliverProcessFinish(ThreadPoolType* tp, uint threadId){
}
mace::ContextEventTP::ContextEventTP(ContextBaseClass* context, uint32_t minThreadSize, uint32_t maxThreadSize ) :
  context(context),
  tpptr(new ThreadPoolType(*this,&mace::ContextEventTP::runDeliverCondition,&mace::ContextEventTP::runDeliverProcessUnlocked,&mace::ContextEventTP::runDeliverSetup,NULL,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize)){
  Log::log("ContextEventTP::constructor") << "Created threadpool for context '" << context->getName() <<"' with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;
}
mace::ContextEventTP::~ContextEventTP() {
  ThreadPoolType *tp = tpptr;
  tpptr = NULL;
  delete tp;
}

void mace::ContextEventTP::signal() {
  if (tpptr != NULL) {
    tpptr->signalSingle();
  }
}

void mace::ContextEventTP::haltAndWait() {
  ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
  tpptr->halt();
  tpptr->waitForEmpty();
}
