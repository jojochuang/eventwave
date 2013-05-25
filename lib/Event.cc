#include "Event.h"
#include "mace.h"

uint64_t mace::Event::nextTicketNumber = 1;
uint64_t mace::Event::lastWriteContextMapping = 0;
bool mace::Event::isExit = false;
uint64_t mace::Event::exitEventID = std::numeric_limits<uint64_t>::max();

bool mace::operator==( mace::EventMessageRecord const& r1, mace::EventMessageRecord const& r2){
  if( r1.sid == r2.sid && r1.dest == r2.dest && r1.message == r2.message && r1.rid == r2.rid ){
    return true;
  }
  return false;
}

////////////////// EventRequestWrapper ///////////////

#include "SpecialMessage.h"
mace::EventRequestWrapper & mace::EventRequestWrapper::operator=( mace::EventRequestWrapper const& right ){
#ifndef EVENTREQUEST_USE_SHARED_PTR
  /*if( this != &right ){
    delete request;
    if( right.request == NULL ){
      request = NULL;
      sid = 0;
    }else{
      request = right.request->clone();
      sid = right.sid;
    }
  } 
  */
  sid = right.sid;
  request = right.request;
#else
  sid = right.sid;
  request = right.request;

#endif
  return *this;
}
mace::EventRequestWrapper::EventRequestWrapper( mace::EventRequestWrapper const& right ): sid( right.sid ), request(){

    //ADD_SELECTORS("ContextService::(copyconstructor)");
#ifndef EVENTREQUEST_USE_SHARED_PTR
  /*if( right.request != NULL ){
    request = right.request->clone();
  }*/
  request = right.request;
#else
  request = right.request;
#endif
}
mace::EventRequestWrapper::~EventRequestWrapper(){
  //ADD_SELECTORS("ContextService::(destructor)");
#ifndef EVENTREQUEST_USE_SHARED_PTR
  //delete request;
#endif
  //maceout<< "0x"<< (uint64_t)request.get() << " unique? " << request.unique() << Log::endl;
}
void mace::EventRequestWrapper::print(std::ostream& out) const {
  out<< "EventRequestWrapper(";
  out<< "sid="; mace::printItem(out, &(sid) ); out<<", ";
  out<< "request="<< (*request) ;
  out<< ")";
}
void mace::EventRequestWrapper::printNode(PrintNode& pr, const std::string& name) const {
  mace::PrintNode printer(name, "EventRequestWrapper" );
  mace::printItem( printer, "sid", &sid );
  mace::printItem( printer, "request", &request );
  pr.addChild( printer );
}
void mace::EventRequestWrapper::serialize(std::string& str) const{
    mace::serialize( str, &sid );
    request->serialize( str );
}
int mace::EventRequestWrapper::deserialize(std::istream & is) throw (mace::SerializationException){
    int serializedByteSize = 0;
    serializedByteSize += mace::deserialize( is, &sid );

    BaseMaceService* serviceInstance = BaseMaceService::getInstance( sid );
    mace::Message* ptr;
    serializedByteSize += serviceInstance->deserializeEventRequest( is, ptr );
    request = RequestType(ptr);

    return serializedByteSize;
}







////////////////// Event ///////////////
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
  out<< "eventContextMappingVersion="; mace::printItem(out, &(eventContextMappingVersion) ); out<<", ";
  out<< "eventSkipID="; mace::printItem(out, &(eventSkipID) );
  // TODO: subevents, eventMessages, eventUpcalls
  out<< ")";

} // print

void mace::Event::printNode(PrintNode& pr, const std::string& name) const {
  mace::PrintNode printer(name, "Event" );
  
  mace::printItem( printer, "eventID", &eventID );
  mace::printItem( printer, "eventType", &eventType );
  mace::printItem( printer, "eventContexts", &eventContexts );
  mace::printItem( printer, "eventSnapshotContexts", &eventSnapshotContexts );
  mace::printItem( printer, "eventContextMappingVersion", &eventContextMappingVersion );
  mace::printItem( printer, "eventSkipID", &eventSkipID );
  // TODO: subevents, eventMessages, eventUpcalls
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
bool mace::Event::deferExternalMessage( uint8_t instanceUniqueID, MaceKey const& dest,  std::string const&  message, registration_uid_t const rid ){
  ADD_SELECTORS("Event::deferExternalMessage");
  macedbg(1)<<"defer an external message sid="<<(uint16_t)instanceUniqueID<<", dest="<<dest<<", rid="<<rid<<Log::endl;
  EventMessageRecord emr(instanceUniqueID, dest, message, rid );
  eventMessages.push_back( emr );
  return true;

}
void mace::Event::executeApplicationUpcalls(){
  for( DeferredUpcallType::iterator msgIt = eventUpcalls.begin(); msgIt != eventUpcalls.end(); msgIt++ ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( msgIt->sid );
    serviceInstance->executeDeferredUpcalls( msgIt->payload );
  }
  eventUpcalls.clear();
}
#include "HeadEventDispatch.h"
#include "ContextService.h"
void mace::Event::enqueueDeferredEvents(){
  createToken();

  for( EventRequestType::iterator subeventIt = subevents.begin(); subeventIt != subevents.end(); subeventIt++ ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( subeventIt->sid );
    //HeadEventDispatch::HeadEventTP::executeEvent(serviceInstance,(HeadEventDispatch::eventfunc)&ContextService::createEvent, subeventIt->request.get() , false );
    HeadEventDispatch::HeadEventTP::executeEvent(serviceInstance,(HeadEventDispatch::eventfunc)&ContextService::createEvent, subeventIt->request , false );
    // TODO: deserialize the event request, and call ContextService::createEvent()
  }
}
void mace::Event::newEventID( const int8_t type){
    ADD_SELECTORS("Event::newEventID");
    Accumulator::Instance(Accumulator::EVENT_CREATE_COUNT)->accumulate(1); // increment committed event number
    // if end event is generated, raise a flag
    if( type == ENDEVENT ){
      isExit = true;//exitEventID = nextTicketNumber;
    }
    eventID = ThreadStructure::myTicket();
    eventType = type;
    macedbg(1) << "Event ticket " << eventID << " sold! "<< *this << Log::endl;
}
