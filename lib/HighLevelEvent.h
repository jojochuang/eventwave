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
#include "Serializable.h"
#include "Printable.h"
namespace mace{

/**
 * This class should only be created by head node.
 *
 * It creates a globally unique event id (because it's only created by head node)
 * 
 * This event class object is supposed to be carried around by messages generated by async/sync/timer calls
 * */
class HighLevelEvent: public PrintPrintable, public Serializable{
public:
    HighLevelEvent(){
      eventID = 0;
      eventType= mace::HighLevelEvent::UNDEFEVENT ;
    }
    /* creates a new event */
    HighLevelEvent(const int8_t type/*, const bool newContextMapping=false*/): eventType(type), eventContexts( ),eventSnapshotContexts( ),  eventMessageCount( 0 ){
        ADD_SELECTORS("HighLevelEvent::(constructor)");


        // check if this node is the head node?

        // if this event is created after end event, terminate the thread
        if( isExit ){
          //maceout<<"After ENDEVENT. Terminate the thread"<<Log::endl;
          //pthread_exit( NULL );
        }
        // Don't use mutex. Because When head node gets a new event, it always happen inside the AgentLock to ensure ordering.
        //ScopedLock sl(eventMutex);

        // if end event is generated, raise a flag
        if( eventType == ENDEVENT ){
          isExit = true;exitEventID = nextTicketNumber;
        }
        
        if( eventType == STARTEVENT ){
            eventID = 1;
            nextTicketNumber = 2;
        }else{
            eventID = nextTicketNumber++;
        }

        if(  eventType == STARTEVENT ){ 
          // start event creates global context
          lastWriteContextMapping = eventID;
        }
        // XXX: it is also possible ENDEVENT also modified context mapping?
        if(  eventType == MIGRATIONEVENT ){
          // these three events modifies context mapping. others don't
          lastWriteContextMapping = eventID;
        }
        /*if( eventType == NEWCONTEXTEVENT && newContextMapping ){
          lastWriteContextMapping = eventID;
        }*/
        this->eventContextMappingVersion = lastWriteContextMapping;

        //this->eventSkipID = this->eventID;

        macedbg(1) << "Event ticket " << eventID << " sold! "<< *this << Log::endl;
    }
    /* this constructor creates a copy of the event object */
    HighLevelEvent( const uint64_t id, const int8_t type, const mace::map<uint8_t, mace::set<mace::string> >& contexts, const mace::map<uint8_t, mace::map<mace::string,mace::string> >& snapshotcontexts, const uint32_t messagecount, const uint64_t mappingversion, const mace::map<uint8_t, uint64_t> skipID ):
      eventID( id ),eventType( type ),  eventContexts( contexts ), eventSnapshotContexts( snapshotcontexts ), eventMessageCount( messagecount ), eventContextMappingVersion( mappingversion ), eventSkipID( skipID ){
    }
    /* this constructor creates a lighter copy of the event object.
     * this constructor may be used when only the event ID is used. */
    HighLevelEvent( const uint64_t id ):
      eventID( id ),
      eventType( UNDEFEVENT ),
      eventContexts(),
      eventSnapshotContexts(),
      eventMessageCount( 0 ),
      eventContextMappingVersion( 0 )/*,
      eventSkipID( 0 )*/
      { }
    HighLevelEvent& operator=(const HighLevelEvent& orig){
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
      //initialMapping = orig.initialMapping;  //initialMapping is used only at initialization
      // do not copy defaultMapping
      // do not modify versionMap
    }

    void print(std::ostream& out) const;
    void printNode(PrintNode& pr, const std::string& name) const;

    const uint64_t& getEventID() const{
        return eventID;
    }
    const int8_t& getEventType() const{
        return eventType;
    }
    /*const uint64_t& getPrevContextMappingVersion() const{
        return prevContextMappingVersion;
    }*/
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

    void setSkipID(const uint8_t serviceID, const uint64_t skipID){
      ASSERT( skipID <= eventID );
      eventSkipID[ serviceID ] = skipID;
    }
    const uint64_t getSkipID(const uint8_t serviceID) const{
      mace::map< uint8_t, uint64_t>::const_iterator it = eventSkipID.find( serviceID );
      ASSERTMSG( it != eventSkipID.end(), "skipID not found for this service ID!" );
      return it->second;
    }
private:

    static uint64_t nextTicketNumber;
    static uint64_t lastWriteContextMapping;
public:
    uint64_t eventID;
    int8_t  eventType;
    mace::map<uint8_t, mace::set<mace::string> > eventContexts;
    mace::map<uint8_t, mace::map< mace::string, mace::string> > eventSnapshotContexts;
    uint32_t eventMessageCount;
    uint64_t eventContextMappingVersion;
    mace::map< uint8_t, uint64_t> eventSkipID; ///< When this event enters a context, don't wait for event ID less than skipEventID. Each service has its own skipEventID

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
    static const int8_t UNDEFEVENT = 8;
};

}
#endif
