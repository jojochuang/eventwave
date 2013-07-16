#include "ContextDispatch.h"

bool mace::ContextEventTP::runDeliverCondition(ThreadPoolType* tp, uint threadId) {
  ScopedLock sl( context->_context_ticketbooth);

  if( !context->eventQueue.empty() ){
    ADD_SELECTORS("ContextEventTP::runDeliverCondition");
    mace::ContextBaseClass::RQType top =  context->eventQueue.top();
    const uint64_t waitID = 
      ( top->skipID+1 < context->now_serving )? context->now_serving : 
      ( (top->skipID != top->eventID)?top->skipID+1: top->eventID ) ;
    macedbg(1)<<"top of queue: eventID= "<< top->eventID << " skipID = "<< top->skipID << " waitID = "<< waitID << ". " << context->getName() << "'" << Log::endl;
    if( waitID == context->now_serving ){
      tp->data(threadId) = top; 
      macedbg(1)<<"dequeue an object = "<< top->eventID << " in context '"<< context->getName() << "'" << Log::endl;

      context->eventQueue.pop();

      return true;
    }
  }
  return false;
}
void mace::ContextEventTP::runDeliverSetup(ThreadPoolType* tp, uint threadId) {
}
void mace::ContextEventTP::runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId) {
  tp->data(threadId)->fire();

  delete tp->data(threadId);
}
void mace::ContextEventTP::runDeliverProcessFinish(ThreadPoolType* tp, uint threadId){
}
mace::ContextEventTP::ContextEventTP(ContextBaseClass* context, uint32_t minThreadSize, uint32_t maxThreadSize ) :
  context(context),
  tpptr (new ThreadPoolType(*this,&mace::ContextEventTP::runDeliverCondition,&mace::ContextEventTP::runDeliverProcessUnlocked,NULL,NULL,ThreadStructure::ASYNC_THREAD_TYPE,minThreadSize, maxThreadSize) )
  {
  Log::log("ContextEventTP::constructor") << "Created threadpool for context '" << context->getName() <<"' with " << minThreadSize << " threads. Max: "<< maxThreadSize <<"." << Log::endl;
}
mace::ContextEventTP::~ContextEventTP() {
  haltAndWait();
  ThreadPoolType *tp = tpptr;
  tpptr = NULL;
  delete tp;
}

/*void mace::ContextEventTP::signal() {
  //ADD_SELECTORS("ContextEventTP::signal");
  if (tpptr != NULL) {
    tpptr->signalSingle();
  }
}*/

void mace::ContextEventTP::haltAndWait() {
  ASSERTMSG(tpptr != NULL, "Please submit a bug report describing how this happened.  If you can submit a stack trace that would be preferable.");
  tpptr->halt();
  tpptr->waitForEmptySignal();
}
