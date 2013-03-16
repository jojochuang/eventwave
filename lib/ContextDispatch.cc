#include "ContextDispatch.h"

bool ContextEventTP::runDeliverCondition(ThreadPoolType* tp, uint threadId) {
  ScopedLock sl( context._context_ticketbooth);
  if( !eventQueue.empty() && eventQueue.top().eventID == context.now_serving )
    return true;
  return false;
}
void ContextEventTP::runDeliverSetup(ThreadPoolType* tp, uint threadId) {
  ScopedLock sl( context._context_ticketbooth);
  tp->data(threadId) = asyncEventQueue.top();
  ADD_SELECTORS("ContextEventTP::runDeliverSetup");
  macedbg(1)<<"dequeue an object = "<< tp->data(threadId).eventID << Log::endl;

  asyncEventQueue.pop();
}
void ContextEventTP::runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId) {
  tp->data(threadId).fire();
}
void ContextEventTP::runDeliverProcessFinish(ThreadPoolType* tp, uint threadId){
}
ContextEventTP::ContextEventTP(ContextBaseClass* context ) :
  context(context),
  tpptr(new ThreadPoolType(*this,&ContextEventTP::runDeliverCondition,&ContextEventTP::runDeliverProcessUnlocked,&ContextEventTP::runDeliverSetup,NULL,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize)){
  Log::log("ContextEventTP::constructor") << "Created threadpool for context '" << context->getName() <<"' with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;
}
ContextEventTP::~ContextEventTP() {
  ThreadPoolType *tp = tpptr;
  tpptr = NULL;
  delete tp;
}

void ContextEventTP::signal() {
  if (tpptr != NULL) {
    tpptr->signalSingle();
  }
}

void ContextEventTP::haltAndWait() {
  ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
  tpptr->halt();
  tpptr->waitForEmpty();
}
