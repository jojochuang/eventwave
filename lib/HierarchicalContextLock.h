#ifndef _HIERARCHICALCONTEXTLOCK_H
#define _HIERARCHICALCONTEXTLOCK_H

// including headers
//#include "mace.h"
// uses snapshot by default
#include "HighLevelEvent.h"
#include "ScopedLock.h"
#include <pthread.h>
#include "MaceKey.h"
#include "ContextMapping.h"

namespace mace{

class HierarchicalContextLock {
public:
    HierarchicalContextLock(HighLevelEvent& event) {
        ADD_SELECTORS("HierarchicalContextLock::(constructor)");
        // code adapted from mace::AgentLock::ticketBoothWait()... basically treating the event as if in READ mode.
        ScopedLock sl(ticketbooth);
        uint64_t myTicketNum = event.getEventID();

        pthread_cond_t threadCond;
        pthread_cond_init(&threadCond, NULL);
        
        if( myTicketNum > now_serving ){
            enteringEvents[ myTicketNum ] = &threadCond;
        }
        while (myTicketNum > now_serving ) {
          macedbg(1) << "Waiting for my turn on cv " << &threadCond << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving  << Log::endl;
          pthread_cond_wait(&threadCond, &ticketbooth);
        }
        macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

        //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == myTicketNum) {
          macedbg(1) << "Erasing our cv from the map." << Log::endl;
          enteringEvents.erase(enteringEvents.begin());
        }
        else if (enteringEvents.begin() != enteringEvents.end()) {
          macedbg(1) << "FYI, first cv in map is for ticket " << enteringEvents.begin()->first << Log::endl;
        }
 
        ASSERT(myTicketNum == now_serving); //Remove once working.
 
        now_serving++;

        if (enteringEvents.begin() != enteringEvents.end() && enteringEvents.begin()->first == now_serving) {
          macedbg(1) << "Now signalling ticket number " << now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
          pthread_cond_broadcast(enteringEvents.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(enteringEvents.begin() == enteringEvents.end() || enteringEvents.begin()->first > now_serving, "enteringEvents map contains CV for ticket already served!!!");
        }
    }
    static void commit(HighLevelEvent& event){
        ADD_SELECTORS("HierarchicalContextLock::commit");
        uint64_t myTicketNum = event.getEventID();
        ScopedLock sl(ticketbooth);
        committingEvents[ myTicketNum ]++;
        std::set<std::string>& eventContexts = eventSnapshotContextIDs[ myTicketNum ];
        // add the list of context this event reached
        const mace::list< mace::string >& reachedCtx = event.getReachedContextIDs();
        for( mace::list< mace::string >::const_iterator ctxIter = reachedCtx.begin(); ctxIter != reachedCtx.end(); ctxIter++ ){
            eventContexts.insert( *ctxIter );
        }
        if( committingEvents.begin()->first == now_committing && committingEvents.begin()->second == noLeafContexts ){
            cleanupSnapshots(myTicketNum);
        }
    }
    static void setLeafContexts(uint32_t leafctx){
        noLeafContexts = leafctx;
    }
    static void globalCommitDone(uint64_t eventID, const std::list<std::string>& contextID ){
        for( std::list<std::string>::const_iterator ctxIter = contextID.begin(); ctxIter != contextID.end(); ctxIter++ ){
            eventSnapshotContextIDs[ eventID ].erase( *ctxIter );
        }
        if( eventSnapshotContextIDs.empty() ){
            ASSERT( committingEvents.begin()->first == eventID );
            committingEvents.erase(committingEvents.begin() );
            ASSERT( now_committing == eventID );
            now_committing++;

            // attempt to commit the next event
            if(committingEvents.begin() != committingEvents.end() && committingEvents.begin()->first == now_committing && committingEvents.begin()->second == noLeafContexts ){
                cleanupSnapshots(eventID);
            }
        }
    }
private:
    static void cleanupSnapshots(uint64_t eventID){
         // can commit
         // multicast to all contexts this event ever reaches (READ/WRITE)
         std::set<std::string>& eventContexts = eventSnapshotContextIDs[ eventID ];
         std::set< mace::MaceKey > physicalNodes;
         for( std::set<std::string>::iterator ctxIter = eventContexts.begin(); ctxIter != eventContexts.end(); ctxIter++ ){
            physicalNodes.insert( mace::ContextMapping::getNodeByContext(*ctxIter) );
         }
         // send to nodes the message.
    }

    static std::map<uint64_t, uint32_t>  committingEvents;
    static std::map<uint64_t, pthread_cond_t* >  enteringEvents;
    static uint64_t now_serving;
    static uint64_t now_committing;
    static uint32_t noLeafContexts;
    static std::map<uint64_t, std::set<std::string> > eventSnapshotContextIDs;
    static pthread_mutex_t ticketbooth;
};

}
#endif
