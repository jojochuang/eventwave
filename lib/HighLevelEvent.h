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
namespace mace{

/**
 * This class should only be created by head node.
 *
 * It creates a globally unique event id (because it's only created by head node)
 * 
 * This event class object is supposed to be carried around by messages generated by async/sync/timer calls
 * */
class HighLevelEvent: public Serializable{
public:
    //HighLevelEvent(): HighLevelEvent(HighLevelEvent::UNDEFEVENT){ }
    HighLevelEvent(){
        eventType= mace::HighLevelEvent::UNDEFEVENT ;
    }
    HighLevelEvent(uint8_t type): eventType(type){
        ADD_SELECTORS("HighLevelEvent::(constructor)");
        // check if this node is the head node?

        ScopedLock sl(eventMutex);
        eventID = nextTicketNumber++;
        macedbg(1) << "Ticket " << eventID << " sold!" << Log::endl;
    }
    const int64_t getEventID(){
        return eventID;
    }
    const int8_t getEventType(){
        return eventType;
    }
    const mace::list< mace::string >& getReachedContextIDs(){
        return reachedContextIDs;
    }
    virtual void serialize(std::string& str) const{
        mace::serialize( str, &eventType );
        mace::serialize( str, &eventID   );
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;
        serializedByteSize += mace::deserialize( is, &eventType );
        serializedByteSize += mace::deserialize( is, &eventID   );
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
    // XXX: Is it necessary to commit a context at head??
    // One possible use: for clean up. the event may leave snapshotted context state variables on the physical nodes.
    //  After the event commits, these memory must be cleaned up.
    //  
    //  But there are other, better, efficient ways to do clean up...
    void commit(){
        ADD_SELECTORS("HighLevelEvent::commit");
        ScopedLock sl(eventMutex);
        // chuangw: commit events in order
        
        if( eventType == MIGRATIONEVENT ){
                migrationRequests.pop();
                if( !migrationRequests.empty() ){
                    macedbg(1)<<"Signal next migration event"<<Log::endl;
                    pthread_cond_signal( migrationRequests.front() );
                }
        }
    }
private:

    static pthread_mutex_t eventMutex;
    static uint64_t nextTicketNumber;
    static uint64_t now_committing;
    static std::queue<pthread_cond_t* > migrationRequests;

    

public:
    int64_t eventID;
    int8_t  eventType;
    mace::list< mace::string > reachedContextIDs;
    // chuangw: perhaps better to use derived classes .
    static const uint8_t STARTEVENT = 0;
    static const uint8_t ENDEVENT   = 1;
    static const uint8_t TIMEREVENT = 2;
    static const uint8_t ASYNCEVENT = 3;
    static const uint8_t UPCALLEVENT= 4;
    static const uint8_t MIGRATIONEVENT = 5;
    static const uint8_t UNDEFEVENT = 6;
};

}
#endif
