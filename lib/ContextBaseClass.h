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
#include "Printable.h"
#include "AsyncDispatch.h"
namespace HeadEventDispatch {
  class HeadEventTP;
}
namespace mace {
class ContextEventTP;
typedef void (AsyncEventReceiver::*ctxeventfunc)(mace::Message*);

typedef std::map< std::pair< uint64_t, mace::string >, std::map< mace::string, mace::string > > snapshotStorageType;
class ContextThreadSpecific;
class ContextBaseClass;

class ContextEvent {
  //private: 
  public:
    AsyncEventReceiver* cl;
    ctxeventfunc func;
    mace::Message* param;

  public:
    ContextEvent() : cl(NULL), func(NULL), param(NULL) {}
    ContextEvent(AsyncEventReceiver* cl, ctxeventfunc func, mace::Message* param) : cl(cl), func(func), param(param) {}
    void fire() {
      (cl->*func)(param);
    }
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

    int getCurrentMode() { return currentMode; }
    void setCurrentMode(int newMode) { currentMode = newMode; }
    const uint64_t& getSnapshotVersion() { return snapshotVersion; }
    void setSnapshotVersion(const uint64_t& ver) { snapshotVersion = ver; }
public:
    pthread_cond_t threadCond;
    int currentMode; 
    uint64_t myTicketNum;
    uint64_t snapshotVersion;
};
class ContextBaseClass: public Serializable, public PrintPrintable{
  friend class HeadEventDispatch::HeadEventTP;
    typedef mace::hash_map<ContextBaseClass*, ContextThreadSpecific*, SoftState> ThreadSpecificMapType;
friend class ContextThreadSpecific;
friend class ContextLock;
friend class ContextEventTP;
public:
    static const uint8_t HEAD = 0;
    static const uint8_t CONTEXT = 1;

    static ContextBaseClass headContext;
    static ContextBaseClass headCommitContext;
    
    static pthread_once_t global_keyOnce;
    static pthread_mutex_t eventCommitMutex;
    static pthread_mutex_t eventSnapshotMutex;
    static std::map< uint64_t, pthread_cond_t* > eventCommitConds;
    static std::map< uint64_t, pthread_cond_t* > eventSnapshotConds;
    static snapshotStorageType eventSnapshotStorage;
    mace::string contextName;
    const int contextType;
    const uint8_t serviceID; ///< The service in which the context belongs to
    const uint32_t contextID; ///< The numerical ID of the context
    const mace::vector<uint32_t> parentID; ///< The numerical ID of the context

    ContextEventTP *eventDispatcher;
public:
    ContextBaseClass(const mace::string& contextName="(unnamed)", const uint64_t ticket = 1, const uint8_t serviceID = 0, const uint32_t contextID = 0, const mace::vector< uint32_t >& parentID = mace::vector< uint32_t >(), const uint8_t contextType = CONTEXT );
    virtual ~ContextBaseClass();
    virtual void print(std::ostream& out) const;
    virtual void printNode(PrintNode& pr, const std::string& name) const;
    virtual void serialize(std::string& str) const{
        
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
    mace::string const& getName() const{
      return contextName;
    }
    uint32_t getID() const{
      return contextID;
    }
    static void releaseThreadSpecificMemory(){
      // delete thread specific memories
      pthread_once( & mace::ContextBaseClass::global_keyOnce, mace::ContextBaseClass::createKeyOncePerThread );
      ThreadSpecificMapType* t = (ThreadSpecificMapType *)pthread_getspecific(global_pkey);
      if( t == 0 ){
        //chuangw: this can happen if init() is never called by this thread;
      }else{
        ThreadSpecificMapType::iterator ctIterator;
        for( ctIterator = t->begin(); ctIterator != t->end(); ctIterator++){
          delete ctIterator->second;
        }
      }
      delete t;
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
    void snapshot(const uint64_t& ver, ContextBaseClass* _ctx) const{
      ADD_SELECTORS("ContextBaseClass::snapshot");
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    virtual const ContextBaseClass& getSnapshot() const{
      VersionContextMap::const_iterator i = versionMap.begin();
      uint64_t sver = ThreadStructure::myEvent().eventID;
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
    virtual void setSnapshot(const uint64_t ver, const mace::string& snapshot){
        std::istringstream in(snapshot);
        mace::ContextBaseClass *obj = new mace::ContextBaseClass(this->contextName, 1 );
        mace::deserialize(in, obj );
        versionMap.push_back( std::make_pair( ver, obj  ) );
    }
    uint64_t getNowServing() const{
      return now_serving;
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
    static void createKeyOncePerThread();
    int getCurrentMode() { 
      const uint64_t myEventNum = ThreadStructure::myEvent().getEventID();
      mace::map<uint64_t, int8_t>::iterator uceventIt = uncommittedEvents.find( myEventNum );
      if( uceventIt == uncommittedEvents.end() ){
        return -1;
      }
      return uceventIt->second;
    }
    const uint64_t& getSnapshotVersion() { return init()->getSnapshotVersion(); }
    void setCurrentMode(int newMode) { init()->currentMode = newMode; }
    void setSnapshotVersion(const uint64_t& ver) { init()->snapshotVersion = ver; }
    bool isImmediateParentOf( const mace::string& childContextID ){
      ABORT("defunct");
        size_t thisContextIDLen = contextName.size();
        if( childContextID.size() <= thisContextIDLen ) return false;
        if( childContextID.compare(0, thisContextIDLen , contextName ) != 0 ) return false;

        size_t pos = childContextID.find_first_of(".", thisContextIDLen+1 );
        if( pos == mace::string::npos )
            return true;

        return false;

    }
    bool isLocalCommittable(){
      ABORT("defunct");
        return true;
    }
    void enqueueEvent(AsyncEventReceiver* sv, ctxeventfunc func, mace::Message* p, uint64_t eventID);

private:
    pthread_key_t pkey;
    pthread_once_t keyOnce;
    uint64_t now_serving;
    uint64_t now_committing;
    uint64_t lastWrite;
    int numReaders;
    int numWriters;

    //typedef std::map<uint64_t, pthread_cond_t*> CondQueue;
    struct CondQueueComp{
      bool operator()( const std::pair<uint64_t, pthread_cond_t*>& p1, const std::pair<uint64_t, pthread_cond_t*>& p2 ){
        return p1.first > p2.first;
      }
    };

    typedef std::priority_queue< std::pair<uint64_t, pthread_cond_t*>, std::vector<std::pair<uint64_t, pthread_cond_t*> >, CondQueueComp > CondQueue;
    CondQueue conditionVariables;
    CondQueue commitConditionVariables;

    pthread_mutex_t _context_ticketbooth; // chuangw: single ticketbooth for now. we will see if it'd become a bottleneck.

    struct BypassSorter{
      // The bypass range shouldn't intersect
      bool operator()(const std::pair<uint64_t,uint64_t>& p1, const std::pair<uint64_t,uint64_t>& p2){
        return (p1.first<p2.first);
      }
    };
    typedef std::set< std::pair< uint64_t, uint64_t >, BypassSorter > BypassQueueType ;
    /*std::set< std::pair< uint64_t, uint64_t >, BypassSorter > bypassQueue;
    std::set< std::pair< uint64_t, uint64_t >, BypassSorter > commitBypassQueue;*/
    /*typedef std::priority_queue< std::pair< uint64_t, uint64_t >, vector< std::pair< uint64_t, uint64_t > >, BypassSorter > BypassQueueType ;*/
    BypassQueueType bypassQueue;
    BypassQueueType commitBypassQueue;

    static pthread_key_t global_pkey;

    mace::map<uint64_t, int8_t> uncommittedEvents;

    //static uint64_t notifiedHeadEventID;

    template<typename T>
    struct QueueComp{
      bool operator()( const std::pair<uint64_t, T>& p1, const std::pair<uint64_t, T>& p2 ){
        return p1.first > p2.first;
      }
    };
  typedef std::pair<uint64_t, ContextEvent> RQType;
  typedef std::priority_queue< RQType, std::vector< RQType >, QueueComp< ContextEvent > > EventRequestQueueType;
    
    EventRequestQueueType eventQueue;
protected:
    typedef std::deque<std::pair<uint64_t, const ContextBaseClass* > > VersionContextMap;
    mutable VersionContextMap versionMap;
};

}
#endif
