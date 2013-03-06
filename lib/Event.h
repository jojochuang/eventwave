/**
 * chuangw: 02/04/2012
 *
 * A high-level event is a conceptual execution of event. The old event model in Mace says the event starts when (1) transport layer processes a received message, (2) Timer goes off, or (3) Asynchronous event handler processes an asynchronous message. An event ends when the event handler finishes the processing. 
 *
 * In Full Context model, events are created by the head of virtual node. The head assigns a globally unique event id to the event, and routes the event to the physical node based on the context of the event. 
 * The reason for having a high-level event in addition to the existing low-level event is that a high-level event is composed of several low-level events. Low level events starts and ends on the same physical machine, whereas the conceptual, high-level event, because it can transition to different contexts during the execution, it is likely the execution of the event spans across many physical nodes.
 *
 * */
#ifndef _MACE_HIGHLEVELEVENT_H
#define _MACE_HIGHLEVELEVENT_H
// include system library header
#include <queue>
#include <pthread.h>
// include mace library header
#include "mace-macros.h"
#include "Serializable.h"
#include "ScopedLock.h"
#include "mlist.h"
#include "mvector.h"
#include "Serializable.h"
#include "Printable.h"
#include "Message.h"
namespace mace{

/**
 * This class should only be created by head node.
 *
 * It creates a globally unique event id (because it's only created by head node)
 * 
 * This event class object is supposed to be carried around by messages generated by async/sync/timer calls
 * */
class EventMessageRecord: public PrintPrintable, public Serializable {
public:
  uint8_t sid;
  MaceKey dest;
  mace::string message;
  registration_uid_t rid;
  EventMessageRecord(  ){ }
  EventMessageRecord( uint8_t sid, MaceKey dest, mace::string message, registration_uid_t rid ):
    sid( sid ), dest( dest ), message( message ), rid (rid){}
  void print(std::ostream& out) const {
    out<< "EventMessageRecord(";
    out<< "sid="; mace::printItem(out, &(sid) ); out<<", ";
    out<< "dest="; mace::printItem(out, &(dest) ); out<<", ";
    out<< "message="; mace::printItem(out, &(message) ); out<<", ";
    out<< "rid="; mace::printItem(out, &(rid) );
    out<< ")";
  }
  void printNode(PrintNode& pr, const std::string& name) const {
    mace::PrintNode printer(name, "EventMessageRecord" );
    mace::printItem( printer, "sid", &sid );
    mace::printItem( printer, "dest", &dest );
    mace::printItem( printer, "message", &message );
    mace::printItem( printer, "rid", &rid );
    pr.addChild( printer );
  }
  virtual void serialize(std::string& str) const{
      mace::serialize( str, &sid );
      mace::serialize( str, &dest );
      mace::serialize( str, &message   );
      mace::serialize( str, &rid   );
  }
  virtual int deserialize(std::istream & is) throw (mace::SerializationException){
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize( is, &sid );
      serializedByteSize += mace::deserialize( is, &dest );
      serializedByteSize += mace::deserialize( is, &message   );
      serializedByteSize += mace::deserialize( is, &rid   );
      return serializedByteSize;
  }
};
class Event: public PrintPrintable, public Serializable{
public:
    typedef mace::map<uint8_t, mace::set< uint32_t > > EventContextType;
    typedef mace::map<uint8_t, mace::map< uint32_t, mace::string> > EventSnapshotContextType;
    typedef mace::map<uint8_t, mace::map< uint32_t, uint64_t > > SkipRecordType;
    typedef mace::vector< /*mace::Message*/ uint64_t > EventRequestType;
    typedef mace::vector< EventMessageRecord > DeferredMessageType;
    Event(){
      eventID = 0;
      eventType= mace::Event::UNDEFEVENT ;
    }
    /* creates a new event */
    Event(const int8_t type): eventType(type), eventContexts( ),eventSnapshotContexts( ),  eventMessageCount( 0 ){
      newEventID( type);
      initialize( );
    }
    void newEventID( const int8_t type){
        ADD_SELECTORS("Event::newEventID");
        // if end event is generated, raise a flag
        if( type == ENDEVENT ){
          isExit = true;exitEventID = nextTicketNumber;
        }
        if( type == STARTEVENT ){
            eventID = 1;
            nextTicketNumber = 2;
        }else{
            eventID = nextTicketNumber++;
        }
        eventType = type;
        macedbg(1) << "Event ticket " << eventID << " sold! "<< *this << Log::endl;
    }
    void initialize( ){

        if( !eventContexts.empty() ){
          eventContexts.clear();
        }
        if( !eventSnapshotContexts.empty() ){
          eventSnapshotContexts.clear();
        }
        eventMessageCount = 0;

        for( uint32_t n = 0; n< eventSkipID.size(); n++ ){
          eventSkipID[n].clear();
        }
        // check if this node is the head node?
        this->eventContextMappingVersion = lastWriteContextMapping;

    }

    /* this constructor creates a copy of the event object */
    Event( const uint64_t id, const int8_t type, const EventContextType& contexts, const EventSnapshotContextType& snapshotcontexts, const uint32_t messagecount, const uint64_t mappingversion, const SkipRecordType& skipID ):
      eventID( id ),eventType( type ),  eventContexts( contexts ), eventSnapshotContexts( snapshotcontexts ), eventMessageCount( messagecount ), eventContextMappingVersion( mappingversion ), eventSkipID( skipID ){
    }
    /* this constructor creates a lighter copy of the event object.
     * this constructor may be used when only the event ID is used. */
    Event( const uint64_t id ):
      eventID( id ),
      eventType( UNDEFEVENT ),
      eventContexts(),
      eventSnapshotContexts(),
      eventMessageCount( 0 ),
      eventContextMappingVersion( 0 )
      { }
    Event& operator=(const Event& orig){
      // XXX: not tested.
      ASSERTMSG( this != &orig, "Self assignment is forbidden!" );
      eventID = orig.eventID;
      eventType = orig.eventType;
      eventContexts = orig.eventContexts;
      eventSnapshotContexts = orig.eventSnapshotContexts;
      eventMessageCount = orig.eventMessageCount;
      eventContextMappingVersion = orig.eventContextMappingVersion;
      eventSkipID = orig.eventSkipID;
      return *this;
    }

    void print(std::ostream& out) const;
    void printNode(PrintNode& pr, const std::string& name) const;

    const uint64_t getEventID() const{
        return eventID;
    }
    const int8_t& getEventType() const{
        return eventType;
    }
    void commit() {
      waitToken();

      // chuangw: send deferred messages
      sendDeferredMessages();
      // create subevents
      sendDeferredEvents();
    }
    void sendDeferredMessages();
    void sendDeferredEvents(){
      createToken();

      for( EventRequestType::iterator subeventIt = subevents.begin(); subeventIt != subevents.end(); subeventIt++ ){
        // for each sub event
        // send them out to the destination physical node to start the event
      }
    }
    void createToken(){
      // chuangw: create a token which is used by the subevents.
    }
    void waitToken(){
      // chuangw:
      // check if the token has arrived,
      // if so, remove that token from record,
      // otherwise, wait to be unlocked.
    }
    void unlockToken(){
      // chuangw:
      // if an event is waiting at this token, signal it,
      // otherwise, store this token
    }
    virtual void serialize(std::string& str) const{
        mace::serialize( str, &eventType );
        mace::serialize( str, &eventID   );
        mace::serialize( str, &eventContexts   );
        mace::serialize( str, &eventSnapshotContexts   );
        mace::serialize( str, &eventMessageCount   );
        mace::serialize( str, &eventContextMappingVersion   );
        mace::serialize( str, &eventSkipID   );
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;
        serializedByteSize += mace::deserialize( is, &eventType );
        serializedByteSize += mace::deserialize( is, &eventID   );
        serializedByteSize += mace::deserialize( is, &eventContexts   );
        serializedByteSize += mace::deserialize( is, &eventSnapshotContexts   );
        serializedByteSize += mace::deserialize( is, &eventMessageCount   );
        serializedByteSize += mace::deserialize( is, &eventContextMappingVersion   );
        serializedByteSize += mace::deserialize( is, &eventSkipID   );
        return serializedByteSize;
    }

    static void serializeToLog(mace::string& str){
            mace::serialize( str, &nextTicketNumber );
    }
    static int deserializeFromLog( std::istream& is){
            int byteSize = 0;
            byteSize += mace::deserialize( is, &nextTicketNumber );

            return byteSize;
    }
    static uint64_t getLastContextMappingVersion( )  {
        return lastWriteContextMapping;
    }
    static void setLastContextMappingVersion( const uint64_t newVersion )  {
         lastWriteContextMapping = newVersion;
    }

    /* set skip id as the event ID. This is conveniently used when the context is created at this event */
    void setSkipID(const uint8_t serviceID, const uint32_t contextID, const uint64_t skipID){
      ASSERTMSG( skipID <= eventID , "skipID should be less or equal to eventID");
      /*if( eventSkipID.size() <= serviceID ){
        eventSkipID.resize( serviceID + 1 );
      }*/
      eventSkipID[ serviceID ][ contextID ] = skipID;
    }
    void setSkipID(const uint8_t serviceID, const mace::map<uint32_t, uint64_t>& skipIDs){
      /*if( eventSkipID.size() <= serviceID ){
        eventSkipID.resize( serviceID + 1 );
      }*/
      eventSkipID[ serviceID ] = skipIDs;
    }
    void clearSkipID(){
      eventSkipID.clear();
    }
    mace::map< uint32_t, uint64_t >& getSkipIDStorage(const uint8_t serviceID){
      /*if( eventSkipID.size() <= serviceID ){
        eventSkipID.resize( serviceID + 1 );
      }*/
      return eventSkipID[ serviceID ];
    }
    const uint64_t getSkipID(const uint8_t serviceID, const uint32_t contextID, const mace::vector<uint32_t >& parentContextIDs ) const{
      SkipRecordType::const_iterator serv_it = eventSkipID.find( serviceID );
      ASSERTMSG( serv_it != eventSkipID.end(), "skipID not found for this service ID!" );
      //ASSERTMSG( serviceID < eventSkipID.size() , "skipID not found for this service ID!" );

      //mace::string lookupContextID = contextID;

      //const mace::map< uint32_t, uint64_t >& skipIDs = eventSkipID[ serviceID ];
      mace::map< uint32_t, uint64_t >::const_iterator cit = serv_it->second.find( contextID );
      if( cit != serv_it->second.end() ){
        return cit->second;
      }
      for( mace::vector<uint32_t>::const_iterator pIt = parentContextIDs.begin(); pIt != parentContextIDs.end(); pIt ++ ){
        mace::map< uint32_t, uint64_t >::const_iterator cit = serv_it->second.find( *pIt );
        if( cit != serv_it->second.end() ){
          return cit->second;
        }
      }
      ABORT("Why would this happen??");
      return 0;
    }

    static void waitExit(){
      ScopedLock sl( waitExitMutex );
      pthread_cond_wait( &waitExitCond, &waitExitMutex );
    }

    static void proceedExit(){
      ScopedLock sl( waitExitMutex );
      pthread_cond_signal( &waitExitCond );
    }
private:
    static uint64_t nextTicketNumber;
    static uint64_t lastWriteContextMapping;

    static pthread_mutex_t waitExitMutex;
    static pthread_cond_t waitExitCond;
public:
    uint64_t eventID;
    int8_t  eventType;
    EventContextType eventContexts;
    EventSnapshotContextType eventSnapshotContexts;
    uint32_t eventMessageCount;
    uint64_t eventContextMappingVersion;
    SkipRecordType eventSkipID; ///< When this event enters a context, don't wait for event ID less than skipEventID. Each service has its own skipEventID
    EventRequestType subevents;
    DeferredMessageType eventMessages;

    static bool isExit;
    static uint64_t exitEventID;

    // chuangw: perhaps better to use derived classes .
    static const int8_t STARTEVENT = 0;
    static const int8_t ENDEVENT   = 1;
    static const int8_t TIMEREVENT = 2;
    static const int8_t ASYNCEVENT = 3;
    static const int8_t UPCALLEVENT= 4;
    static const int8_t DOWNCALLEVENT= 5;
    static const int8_t MIGRATIONEVENT = 6;
    static const int8_t NEWCONTEXTEVENT = 7;
    static const int8_t HEADMIGRATIONEVENT = 8;
    static const int8_t UNDEFEVENT = 9;
};

}
#endif
