// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "mstring.h"
#include "mset.h"
#include "pthread.h"
#include <queue>

#include "SynchronousCallWait.h"
namespace mace {
class ContextThreadSpecific;
class ContextBaseClass;


class RunOnceCallBack {
public:
    virtual void operator() (void) = 0;
    static pthread_mutex_t onceLock;
};
//void runOnce(pthread_once_t& keyOnce, RunOnceCallBack& funcObj);

class ContextThreadSpecific{
public:
    //ContextThreadSpecific(ContextBaseClass& ctx):
    ContextThreadSpecific():
        //context(ctx),
        threadCond(),
        currentMode(-1),
        myTicketNum(std::numeric_limits<uint64_t>::max()),
        snapshotVersion(0)
    {
        pthread_cond_init(  &threadCond, NULL );
    }

    ~ContextThreadSpecific(){
        pthread_cond_destroy( &threadCond );
    }

    // initialize the key. The key on each context is only initialized once.
    /*int getCurrentMode() { return context.init()->currentMode; }
    void setCurrentMode(int newMode) { context.init()->currentMode = newMode; }
    const uint64_t& getSnapshotVersion() { return context.init()->snapshotVersion; }
    void setSnapshotVersion(const uint64_t& ver) { context.init()->snapshotVersion = ver; }*/
    int getCurrentMode() { return currentMode; }
    void setCurrentMode(int newMode) { currentMode = newMode; }
    const uint64_t& getSnapshotVersion() { return snapshotVersion; }
    void setSnapshotVersion(const uint64_t& ver) { snapshotVersion = ver; }
private:
    //ContextBaseClass& context;
public:
    pthread_cond_t threadCond;
    int currentMode; // XXX: is this per thread and per context? or per thread only??
    // chuangw: 01/06/2012: Now I think it's per thread & per context. Because a thread can hold multiple context locks and have acces
    // to multiple contexts simultaneously. Need to record the access mode for each of these held contexts.
    uint64_t myTicketNum;
    uint64_t snapshotVersion;
};
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
    static pthread_mutex_t eventCommitMutex;
    static pthread_mutex_t awaitingReturnMutex;
    static std::map< uint64_t, pthread_cond_t* > eventCommitConds;
public:
    //ContextBaseClass();
    ContextBaseClass(const mace::string& contextID="(unnamed)", const uint64_t ticket = 1);
    ~ContextBaseClass();
    virtual void serialize(std::string& str) const{
        
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
    /**
     * Each context takes its own snapshot
     * 
     * \param ver Ticket number of the snapshot 
     * */
    virtual void snapshot(const uint64_t& ver) const{
        
    }
    /**
     * Each context is responsible for releasing its own snapshot
     * 
     * \param ver Ticket number of the snapshot 
     * */
    virtual void snapshotRelease(const uint64_t& ver) const{
        
    }

    /**
     * check if the context is a valid transition from this context
     *
     * This member method should be called by sync (direct) calls before the actual call takes place
     * to make sure call is valid according to the ContextJob model.
     *
     * */
    virtual bool checkValidTransition(const mace::string& nextContextName ){ return false;}

    // chuangw: XXX: need to move init() to ContextBaseClass,
    // since every variables used are references to ContextBaseClass
    ContextThreadSpecific* init();
    void operator() (void){
        // XXX: notice that PTHREAD_KEYS_MAX is 1024 in typical systems.
        // which means a thread can have at most 1024 keys
        assert(pthread_key_create(&pkey, NULL) == 0);
    }
    static void createKeyOncePerThread();
    int getCurrentMode() { return init()->getCurrentMode(); }
    const uint64_t& getSnapshotVersion() { return init()->getSnapshotVersion(); }
    void setCurrentMode(int newMode) { init()->currentMode = newMode; }
    void setSnapshotVersion(const uint64_t& ver) { init()->snapshotVersion = ver; }
    bool addNewChild( const mace::string& ctxID ){
        size_t thisContextIDLen = contextID.size();
        if( ctxID.size() <= thisContextIDLen ) return false;
        if( ctxID.compare(0, thisContextIDLen , contextID ) != 0 ) return false;

        static pthread_mutex_t childctxLock = PTHREAD_MUTEX_INITIALIZER;
        ScopedLock sl(childctxLock);
        mace::string ctxIDsubstr = ctxID.substr(0, ctxID.find_first_of(']', thisContextIDLen ) );
        // check if ctxID is already in the set childContextID, if not add it
        std::pair<mace::set<mace::string>::iterator, bool> result = childContextID.insert( ctxIDsubstr );
        return result.second;
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
    //std::queue<uint64_t> next_serving;
    std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t> > next_serving;
    std::map<uint64_t, pthread_cond_t*> conditionVariables;
    std::map<uint64_t, pthread_cond_t*> commitConditionVariables;
    static pthread_key_t global_pkey;
public:
    mace::string contextID;
    uint32_t fan_in;
    uint32_t fan_out;
    mace::set<mace::string> childContextID;
};

}
#endif
