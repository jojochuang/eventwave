#ifndef __CONTEXT_DISPATCH_h
#define __CONTEXT_DISPATCH_h

#include "ContextBaseClass.h"
#include "Message.h"
#include "ThreadPool.h"

namespace mace{

class ContextEventTP {
  private:
    ContextBaseClass* context;
    ThreadPoolType *tpptr;
    /*const uint32_t minThreadSize;
    const uint32_t maxThreadSize;*/
    bool runDeliverCondition(ThreadPoolType* tp, uint threadId);
    void runDeliverSetup(ThreadPoolType* tp, uint threadId);
    void runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId);
    void runDeliverProcessFinish(ThreadPoolType* tp, uint threadId);
  public:
    ContextEventTP(ContextBaseClass* context );
    ~ContextEventTP();

    void signal();

    void haltAndWait();
};

}
