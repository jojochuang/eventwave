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

#include "ThreadStructure.h"
#include "Printable.h"
//#include "AsyncDispatch.h"
#include "Event.h"
#include "pthread.h"
#include "mace.h"
//#include "Message.h"
#include "SpecialMessage.h"
#include "SockUtil.h"


#define  MARK_RESERVED NULL
/**
 * \file ContextBaseClass.h
 * \brief declares the base class for context classes
 */
/*namespace HeadEventDispatch {
  class HeadEventTP;
}*/
namespace mace {
class ContextEventTP;
//typedef void (AsyncEventReceiver::*ctxeventfunc)( InternalMessageHelperPtr param );

typedef std::map< std::pair< uint64_t, mace::string >, std::map< mace::string, mace::string > > snapshotStorageType;
class ContextThreadSpecific;
class ContextBaseClass;

class ContextEvent {
  public:
    static const uint8_t TYPE_NULL = 0;
    static const uint8_t TYPE_EVENT = 1;
    static const uint8_t TYPE_ROUTINE = 2;
    BaseMaceService* sv;
    uint8_t type;
    InternalMessageHelperPtr param;
    mace::MaceAddr source;
  public:
    ContextEvent() : sv(NULL), type( TYPE_NULL ) , param(), source( SockUtil::NULL_MACEADDR )  {}
    ContextEvent(BaseMaceService* sv, uint8_t const type, InternalMessageHelperPtr param, mace::MaceAddr source = SockUtil::NULL_MACEADDR) : sv(sv), type( type ), param(param), source(source) {}
    void fire() {
      switch( type ){
        case TYPE_NULL:
          break;
        case TYPE_EVENT:
          sv->executeEvent( static_cast< AsyncEvent_Message* >(param) );
          break;
        case TYPE_ROUTINE:
          sv->executeRoutine( static_cast< Routine_Message* >(param), source );
          break;
      }
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
/**
 * ContextBaseClass defines the base for context classes
 *
 * */
class ContextBaseClass: public Serializable, public PrintPrintable{
  //friend class HeadEventDispatch::HeadEventTP;
    typedef mace::hash_map<ContextBaseClass*, ContextThreadSpecific*, SoftState> ThreadSpecificMapType;
friend class ContextThreadSpecific;
friend class ContextLock;
friend class ContextEventTP;
public:
    typedef std::pair<uint64_t, pthread_cond_t*> QueueItemType;
    static const uint8_t HEAD = 0;
    static const uint8_t CONTEXT = 1;

    //static ContextBaseClass headContext;
    //static ContextBaseClass headCommitContext;
    
    static pthread_once_t global_keyOnce;
    static pthread_mutex_t eventCommitMutex;
    static pthread_mutex_t eventSnapshotMutex;
    static std::map< uint64_t, pthread_cond_t* > eventCommitConds;
    static std::map< uint64_t, pthread_cond_t* > eventSnapshotConds;
    static snapshotStorageType eventSnapshotStorage;
    mace::string contextName; ///< The canonical name of the context
    const int contextType;
    uint8_t serviceID; ///< The service in which the context belongs to
    uint32_t contextID; ///< The numerical ID of the context
    mace::vector<uint32_t> parentID; ///< The numerical ID of the context

    ContextEventTP *eventDispatcher;
public:
    /**
     * constructor
     *
     * */
    ContextBaseClass(const mace::string& contextName="(unnamed)", const uint64_t ticket = 1, const uint8_t serviceID = 0, const uint32_t contextID = 0, const mace::vector< uint32_t >& parentID = mace::vector< uint32_t >(), const uint8_t contextType = CONTEXT );
    /**
     * destructor
     * */
    virtual ~ContextBaseClass();
    virtual void print(std::ostream& out) const;
    virtual void printNode(PrintNode& pr, const std::string& name) const;
    virtual void serialize(std::string& str) const{ }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        return 0;
    }
    /**
     * returns the canonical name of the context
     * */
    mace::string const& getName() const{
      return contextName;
    }
    /**
     * returns the numerical ID of the context
     * */
    uint32_t getID() const{
      return contextID;
    }
    /** 
     * create a read only snapshot of the context
     *
     * public interface of snapshot() 
     *
     * @param ver snapshot version
     * */
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
    /**
     * return a snapshot of the current event version
     * */
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
    /**
     * insert a read-only snapshot into the context
     *
     * @param ver version number
     * @param snapshot snapshot object
     * */
    virtual void setSnapshot(const uint64_t ver, const mace::string& snapshot){
        std::istringstream in(snapshot);
        mace::ContextBaseClass *obj = new mace::ContextBaseClass(this->contextName, 1 );
        mace::deserialize(in, obj );
        versionMap.push_back( std::make_pair( ver, obj  ) );
    }
    /**
     * returns the now_serving number
     * now_serving number is the ticket of the next to run event
     * */
    uint64_t getNowServing() const{
      return now_serving;
    }

    // chuangw: XXX: need to move init() to ContextBaseClass,
    // since every variables used are references to ContextBaseClass
    ContextThreadSpecific* init();
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
    /**
     * push an event into the context execution queue
     *
     * */
    void enqueueEvent(BaseMaceService* sv, AsyncEvent_Message* const p);

    void enqueueRoutine(BaseMaceService* sv, Routine_Message* const p, mace::MaceAddr const& source);
    /**
     * signal the context thread
     *
     * */
    void signalContextThreadPool();

    /// not used?
    /*void markTicket( uint64_t const myTicketNum ){
      ScopedLock sl(_context_ticketbooth);
      conditionVariables.push( QueueItemType( myTicketNum, MARK_RESERVED  ) );
    }
    // not used?
    void removeMark(){
      ScopedLock sl(_context_ticketbooth);
      uint64_t myTicketNum = ThreadStructure::myTicket();
      if( !conditionVariables.empty() && conditionVariables.top().first == myTicketNum ){
        ASSERT( conditionVariables.top().second == MARK_RESERVED );
        conditionVariables.pop();
      }
    }*/

    void initialize(const mace::string& contextName, const uint64_t ticket, const uint8_t serviceID, const uint32_t contextID, const mace::vector< uint32_t >& parentID){
      this->contextName = contextName;
      this->now_serving = ticket;
      this->now_committing = ticket;
      this->serviceID = serviceID;
      this->contextID = contextID;
      this->parentID = parentID;

    }

    void lock(  );
    void downgrade( int8_t requestedMode );
    void unlock(  );
    void nullTicket();
    /**
     * when context is removed, eliminate thread specfici memory associated with this context
     * */
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
    static void createKeyOncePerThread();
    static mace::string getTypeName( mace::string const& fullName ){
      mace::string s;

      size_t pos = fullName.find_last_of("." );

      if( pos == mace::string::npos ){
        s = fullName;
      }else{
        s = fullName.substr( pos+1 );
      }

      size_t bracket_pos = s.find_first_of("[" );

      if( bracket_pos == mace::string::npos ){
        return s;
      }

      s = s.substr( 0, bracket_pos );

      return s;
    }
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

    typedef std::pair<uint64_t,uint64_t> RQIndexType;
    template<typename T>
    struct QueueComp{
      bool operator()( const std::pair< RQIndexType, T>& p1, const std::pair< RQIndexType, T>& p2 ){
        // first is eventID, second is skipID
        return p1.first.first > p2.first.first;
      }
    };
  typedef std::pair< RQIndexType, ContextEvent> RQType;
  typedef std::priority_queue< RQType, std::vector< RQType >, QueueComp< ContextEvent > > EventRequestQueueType;
    
    EventRequestQueueType eventQueue;
protected:
    typedef std::deque<std::pair<uint64_t, const ContextBaseClass* > > VersionContextMap;
    mutable VersionContextMap versionMap;
};

}
#endif
