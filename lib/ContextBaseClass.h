// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "pthread.h"
#include <queue>
namespace mace {
class ContextThreadSpecific;
class ContextBaseClass: public Serializable {
friend class ContextThreadSpecific;
friend class ContextLock;
public:
    ContextBaseClass();
    ~ContextBaseClass();
    virtual void serialize(std::string& str) const{
        
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
private:
    pthread_key_t pkey;
    pthread_once_t keyOnce;
    uint64_t now_serving;
    uint64_t now_committing;
    uint64_t lastWrite;
    int numReaders;
    int numWriters;
    bool no_nextcommitting;
    bool no_nextserving;
    std::queue<uint64_t> next_committing;
    std::queue<uint64_t> next_serving;
    ContextThreadSpecific* contextThreadSpecific;
    std::map<uint64_t, pthread_cond_t*> conditionVariables;
    std::map<uint64_t, pthread_cond_t*> commitConditionVariables;
    //pthread_mutex_t _context_ticketbooth;
};

}
#include "ContextLock.h"
#endif
