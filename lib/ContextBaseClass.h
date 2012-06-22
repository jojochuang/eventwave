// Parent class for all context classes
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "mace-macros.h"
#include "mstring.h"
#include "mset.h"
#include "pthread.h"
#include <queue>
#include "m_map.h"

#include "SynchronousCallWait.h"
#include "ThreadStructure.h"
namespace mace {
typedef std::map< std::pair< uint64_t, mace::string >, std::map< mace::string, mace::string > > snapshotStorageType;
class ContextThreadSpecific;
class ContextBaseClass;


class RunOnceCallBack {
public:
    virtual void operator() (void) = 0;
    static pthread_mutex_t onceLock;
};

class ContextThreadSpecific{
public:
    ContextThreadSpecific():
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
public:
    pthread_cond_t threadCond;
    int currentMode; 
    uint64_t myTicketNum;
    uint64_t snapshotVersion;
};
class ContextBaseClass: public Serializable, public RunOnceCallBack {
friend class ContextThreadSpecific;
friend class ContextLock;
public:
    static ContextBaseClass headContext;
    static ContextBaseClass globalContext;
    static ContextBaseClass __internal_Context;
    static ContextBaseClass __null_Context;
    
    static pthread_once_t global_keyOnce;
    static pthread_mutex_t newContextMutex;
    static pthread_mutex_t __internal_ContextMutex;
    static pthread_mutex_t eventCommitMutex;
    static pthread_mutex_t eventSnapshotMutex;
    static std::map< uint64_t, pthread_cond_t* > eventCommitConds;
    static std::map< uint64_t, pthread_cond_t* > eventSnapshotConds;
    static snapshotStorageType eventSnapshotStorage;
    static uint64_t migrationTicket;
    static mace::string migrationContext;

    static pthread_cond_t migrateContextCond;
public:
    ContextBaseClass(const mace::string& contextID="(unnamed)", const uint64_t ticket = 1);
    virtual ~ContextBaseClass();
    virtual void serialize(std::string& str) const{
        
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
    /* public interface of snapshot() */
    void snapshot(const uint64_t& ver) const{
        ContextBaseClass* _ctx = new ContextBaseClass(*this);
        snapshot( ver, _ctx );
    }
    /**
     * Each context is responsible for releasing its own snapshot
     * 
     * \param ver Ticket number of the snapshot 
     * */
    virtual void snapshotRelease(const uint64_t& ver) const{
      ADD_SELECTORS("ContextBaseClass::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    /**
     * Each context takes its own snapshot
     * 
     * \param ver Ticket number of the snapshot 
     * */
    /*virtual void snapshot(const uint64_t& ver) const{
      ADD_SELECTORS("ContextBaseClass::snapshot");
      ContextBaseClass* _ctx = new ContextBaseClass(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }*/
    void snapshot(const uint64_t& ver, ContextBaseClass* _ctx) const{
      ADD_SELECTORS("ContextBaseClass::snapshot");
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    virtual const ContextBaseClass& getSnapshot() const{
      VersionContextMap::const_iterator i = versionMap.begin();
      uint64_t sver = ThreadStructure::myEvent(); //mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << sver << " ticket " << ThreadStructure::myTicket() << Log::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
protected:
public:
    virtual void setSnapshot(const uint64_t ver, const mace::string& snapshot){
        std::istringstream in(snapshot);
        mace::ContextBaseClass *obj = new mace::ContextBaseClass(this->contextID, 1 );
        mace::deserialize(in, obj );
        versionMap.push_back( std::make_pair( ver, obj  ) );
    }

public:
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
    // chuangw: Assuming locks is added before addNewChild() call
    bool addNewChild( const mace::string& ctxID){
        ADD_SELECTORS("ContextBaseClass::addNewChild");
        const size_t thisContextIDLen = contextID.size();
        if( ctxID.size() <= thisContextIDLen ){ 
             macedbg(1)<<"my context id="<< contextID <<". child ctx to add is "<< ctxID<<". child ctx len <= this context len."<<Log::endl;
            return false;
        }
        if( ctxID.compare(0, thisContextIDLen , contextID ) != 0 ){
             macedbg(1)<<"my context id="<< contextID <<". child ctx to add is "<< ctxID<<". the substring does not match"<<Log::endl;
            return false;
        }
        size_t pos = ctxID.find_first_of(".", thisContextIDLen+1 );
        //macedbg(1)<<"find first of . is "<<pos<<Log::endl;
        mace::string ctxIDsubstr;
        if( pos == mace::string::npos ){
            ctxIDsubstr = ctxID;
        }else{
            ctxIDsubstr = ctxID.substr(0, pos );
        }
        std::pair<mace::set<mace::string>::iterator, bool> result = childContextID.insert( ctxIDsubstr );
        if( result.second ){
            macedbg(1)<<"child context id "<< ctxIDsubstr<<" added to this context name="<< contextID <<Log::endl;
        }else{
            macedbg(1)<<"child context id "<< ctxIDsubstr<<" not added to this context name="<< contextID <<Log::endl;
        }
        return result.second;
    }
    bool isImmediateParentOf( const mace::string& childContextID ){
        size_t thisContextIDLen = contextID.size();
        if( childContextID.size() <= thisContextIDLen ) return false;
        if( childContextID.compare(0, thisContextIDLen , contextID ) != 0 ) return false;

        size_t pos = childContextID.find_first_of(".", thisContextIDLen+1 );
        if( pos == mace::string::npos )
            return true;

        return false;

    }
    bool isLocalCommittable(){
        return true;
    }
    mace::set<mace::string> const& getChildContextID() const{
        return childContextID;
    }

private:
    pthread_key_t pkey;
    pthread_once_t keyOnce;
    uint64_t now_serving;
    uint64_t now_committing;
    uint64_t lastWrite;
    int numReaders;
    int numWriters;
    std::map<uint64_t, pthread_cond_t*> conditionVariables;
    std::map<uint64_t, pthread_cond_t*> commitConditionVariables;
    static pthread_key_t global_pkey;
    //typedef std::deque<std::pair<uint64_t, const mace::ContextBaseClass*> > VersionContextMap;
    //mutable VersionContextMap versionMap;


    typedef std::deque<std::pair<uint64_t, mace::set<mace::string>* > > ChildContextVersionMap;
    mutable ChildContextVersionMap childCtxVersions;
    std::map<uint64_t, int8_t> uncommittedEvents;

protected:
    typedef std::deque<std::pair<uint64_t, const ContextBaseClass* > > VersionContextMap;
    mutable VersionContextMap versionMap;
public:
    mace::string contextID;
    uint32_t fan_in;
    uint32_t fan_out;
    mace::set<mace::string> childContextID; // chuangw: a map of context id to the ticket number which is the first time the edge to the child context node is created.
};

}
#endif
