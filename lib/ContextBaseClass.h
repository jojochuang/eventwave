// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "mstring.h"
#include "pthread.h"
#include <queue>
namespace mace {
class ContextThreadSpecific;
class ContextBaseClass;


class RunOnceCallBack {
public:
    virtual void operator() (void) = 0;
    static pthread_mutex_t onceLock;
};
void runOnce(pthread_once_t& keyOnce, RunOnceCallBack& funcObj);

class ContextBaseClass: public Serializable, public RunOnceCallBack {
friend class ContextThreadSpecific;
friend class ContextLock;
public:
    static ContextBaseClass globalContext;
    static ContextBaseClass __internal_Context;
    static ContextBaseClass __null_Context;
    
    static pthread_once_t global_keyOnce;
    static pthread_mutex_t newContextMutex;
    static pthread_mutex_t __internal_ContextMutex;
public:
    //ContextBaseClass();
    ContextBaseClass(const mace::string& contextID="(unnamed)");
    ~ContextBaseClass();
    virtual void serialize(std::string& str) const{
        
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
    // chuangw: XXX: need to move init() to ContextBaseClass,
    // since every variables used are references to ContextBaseClass
    ContextThreadSpecific* init();
    void operator() (void){
        // XXX: notice that PTHREAD_KEYS_MAX is 1024 in typical systems.
        // which means a thread can have at most 1024 keys
        assert(pthread_key_create(&pkey, NULL) == 0);
    }
    static void createKeyOncePerThread();
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
    //std::queue<uint64_t> next_serving;
    std::priority_queue<uint64_t, std::vector<unsigned int>, std::greater<unsigned int> > next_serving;
    std::map<uint64_t, pthread_cond_t*> conditionVariables;
    std::map<uint64_t, pthread_cond_t*> commitConditionVariables;
    //pthread_key_t& pkey;
    //pthread_once_t& keyOnce;
    //ContextThreadSpecific contextThreadSpecific;
    //pthread_mutex_t _context_ticketbooth;
    static pthread_key_t global_pkey;
public:
    mace::string contextID;
};
class ContextThreadSpecific{
public:
    ContextThreadSpecific(ContextBaseClass& ctx):
        context(ctx),
        //pkey(ctx->pkey),
        //keyOnce(ctx->keyOnce), 
        threadCond(),
        currentMode(-1),
        myTicketNum(std::numeric_limits<uint64_t>::max()),
        snapshotVersion(0)
    {
    }

    // initialize the key. The key on each context is only initialized once.
    int getCurrentMode() { return context.init()->currentMode; }
    void setCurrentMode(int newMode) { context.init()->currentMode = newMode; }
    const uint64_t& getSnapshotVersion() { return context.init()->snapshotVersion; }
    void setSnapshotVersion(const uint64_t& ver) { context.init()->snapshotVersion = ver; }
private:
    ContextBaseClass& context;
public:
    pthread_cond_t threadCond;
    int currentMode; // XXX: is this per thread and per context? or per thread only??
    // chuangw: 01/06/2012: Now I think it's per thread & per context. Because a thread can hold multiple context locks and have acces
    // to multiple contexts simultaneously. Need to record the access mode for each of these held contexts.
    uint64_t myTicketNum;
    uint64_t snapshotVersion;
    //pthread_mutex_t _context_ticketbooth;
    //uint64_t now_serving;
};

}
//#include "ContextLock.h"
#endif
