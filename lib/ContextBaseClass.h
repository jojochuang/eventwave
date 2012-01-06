// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "pthread.h"
namespace mace {
class ContextThreadSpecific;
class ContextBaseClass: public Serializable {
friend class ContextLock;
public:
    ContextBaseClass();
    ~ContextBaseClass();
private:
    ContextThreadSpecific* contextThreadSpecific;
    pthread_mutex_t _context_ticketbooth;
    uint64_t now_serving;
    uint64_t now_committing;
    uint64_t lastWrite;
    int numReaders;
    int numWriters;
    std::map<uint64_t, pthread_cond_t*> conditionVariables;
    std::map<uint64_t, pthread_cond_t*> commitConditionVariables;
};

}
#include "ContextLock.h"
#endif
