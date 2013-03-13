#include "Event.h"
#include "mace.h"

uint64_t mace::Event::nextTicketNumber = 1;
uint64_t mace::Event::lastWriteContextMapping = 0;
pthread_mutex_t mace::Event::waitExitMutex = PTHREAD_MUTEX_INITIALIZER;;
pthread_cond_t mace::Event::waitExitCond = PTHREAD_COND_INITIALIZER;;
bool mace::Event::isExit = false;
uint64_t mace::Event::exitEventID = std::numeric_limits<uint64_t>::max();
//uint64_t mace::Event::now_committing = 1;
//std::queue<pthread_cond_t*> mace::Event::migrationRequests;

/*const uint8_t mace::Event::STARTEVENT = 0;
const uint8_t mace::Event::ENDEVENT   = 1;
const uint8_t mace::Event::TIMEREVENT = 2;
const uint8_t mace::Event::ASYNCEVENT = 3;
const uint8_t mace::Event::UPCALLEVENT= 4;
const uint8_t mace::Event::DOWNCALLEVENT= 5;
const uint8_t mace::Event::MIGRATIONEVENT = 6;
const uint8_t mace::Event::NEWCONTEXTEVENT = 7;
const uint8_t mace::Event::UNDEFEVENT = 8;*/

void mace::Event::print(std::ostream& out) const {
  out<< "Event(";
  out<< "eventID="; mace::printItem(out, &(eventID) ); out<<", ";
  out<< "eventType="; 
  
  switch( eventType ){
    case STARTEVENT: out<<"STARTEVENT"; break;
    case ENDEVENT: out<<"ENDEVENT"; break;
    case TIMEREVENT: out<<"TIMEREVENT"; break;
    case ASYNCEVENT: out<<"ASYNCEVENT"; break;
    case UPCALLEVENT: out<<"UPCALLEVENT"; break;
    case DOWNCALLEVENT: out<<"DOWNCALLEVENT"; break;
    case MIGRATIONEVENT: out<<"MIGRATIONEVENT"; break;
    case NEWCONTEXTEVENT: out<<"NEWCONTEXTEVENT"; break;
    case UNDEFEVENT: out<<"UNDEFEVENT"; break;
    default: mace::printItem(out, &(eventType) ); break;
  }
  
  out<<", ";

  out<< "eventContexts="; mace::printItem(out, &(eventContexts) ); out<<", ";
  out<< "eventSnapshotContexts="; mace::printItem(out, &(eventSnapshotContexts) ); out<<", ";
  //out<< "eventMessageCount="; mace::printItem(out, &(eventMessageCount) ); out<<", ";
  out<< "eventContextMappingVersion="; mace::printItem(out, &(eventContextMappingVersion) ); out<<", ";
  out<< "eventSkipID="; mace::printItem(out, &(eventSkipID) );
  out<< ")";

} // print

void mace::Event::printNode(PrintNode& pr, const std::string& name) const {
  mace::PrintNode printer(name, "Event" );
  
  mace::printItem( printer, "eventID", &eventID );
  mace::printItem( printer, "eventType", &eventType );
  mace::printItem( printer, "eventContexts", &eventContexts );
  mace::printItem( printer, "eventSnapshotContexts", &eventSnapshotContexts );
  //mace::printItem( printer, "eventMessageCount", &eventMessageCount );
  mace::printItem( printer, "eventContextMappingVersion", &eventContextMappingVersion );
  mace::printItem( printer, "eventSkipID", &eventSkipID );
  pr.addChild( printer );
}
#include "ThreadStructure.h"
#include "ContextMapping.h"
void mace::Event::sendDeferredMessages(){
  ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContextID() );
  for( DeferredMessageType::iterator msgIt = eventMessages.begin(); msgIt != eventMessages.end(); msgIt++ ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( msgIt->sid );
    serviceInstance->dispatchDeferredMessages( msgIt->dest, msgIt->message, msgIt->rid );
  }
}
