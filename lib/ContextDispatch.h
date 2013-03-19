#ifndef __CONTEXT_DISPATCH_h
#define __CONTEXT_DISPATCH_h

#include "ContextBaseClass.h"
#include "Message.h"
#include "ThreadPool.h"

namespace mace{

class ContextEventTP {
  typedef mace::ThreadPool<ContextEventTP, mace::ContextEvent> ThreadPoolType;
  private:
    ContextBaseClass* context;
    ThreadPoolType *tpptr;
    pthread_mutex_t queuelock;
    /*const uint32_t minThreadSize;
    const uint32_t maxThreadSize;*/
    bool runDeliverCondition(ThreadPoolType* tp, uint threadId);
    void runDeliverSetup(ThreadPoolType* tp, uint threadId);
    void runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId);
    void runDeliverProcessFinish(ThreadPoolType* tp, uint threadId);
  public:
    ContextEventTP(ContextBaseClass* context, uint32_t minThreadSize, uint32_t maxThreadSize  );
    ~ContextEventTP();

    void signal();

    void haltAndWait();
    void lock(); // lock

    void unlock(); // unlock
};

}
#endif
