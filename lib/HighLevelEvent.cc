#include "HighLevelEvent.h"

//pthread_mutex_t mace::HighLevelEvent::eventMutex = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::HighLevelEvent::nextTicketNumber = 1;
uint64_t mace::HighLevelEvent::lastWriteContextMapping = 0;
//uint64_t mace::HighLevelEvent::now_committing = 1;
//std::queue<pthread_cond_t*> mace::HighLevelEvent::migrationRequests;

/*const uint8_t mace::HighLevelEvent::STARTEVENT = 0;
const uint8_t mace::HighLevelEvent::ENDEVENT   = 1;
const uint8_t mace::HighLevelEvent::TIMEREVENT = 2;
const uint8_t mace::HighLevelEvent::ASYNCEVENT = 3;
const uint8_t mace::HighLevelEvent::UPCALLEVENT= 4;
const uint8_t mace::HighLevelEvent::DOWNCALLEVENT= 5;
const uint8_t mace::HighLevelEvent::MIGRATIONEVENT = 6;
const uint8_t mace::HighLevelEvent::NEWCONTEXTEVENT = 7;
const uint8_t mace::HighLevelEvent::UNDEFEVENT = 8;*/

void mace::HighLevelEvent::print(std::ostream& out) const {
  out<< "HighLevelEvent(";
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
  out<< "eventMessageCount="; mace::printItem(out, &(eventMessageCount) ); out<<", ";
  out<< "eventContextMappingVersion="; mace::printItem(out, &(eventContextMappingVersion) );
  out<< ")";

} // print

void mace::HighLevelEvent::printNode(PrintNode& pr, const std::string& name) const {
  mace::PrintNode printer(name, "HighLevelEvent" );
  
  mace::printItem( printer, "eventID", &eventID );
  mace::printItem( printer, "eventType", &eventType );
  mace::printItem( printer, "eventContexts", &eventContexts );
  mace::printItem( printer, "eventMessageCount", &eventMessageCount );
  mace::printItem( printer, "eventContextMappingVersion", &eventContextMappingVersion );
  pr.addChild( printer );
}
