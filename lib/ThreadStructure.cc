#include "ThreadStructure.h"

void printThreadStructure(){
  //ADD_SELECTORS ("printThreadStructure");

  //maceout<< ThreadStructure::myEvent() << Log::endl;
  std::cout<< ThreadStructure::myEvent() << std::endl;
}

pthread_key_t ThreadStructure::ThreadSpecific::pkey;
pthread_once_t ThreadStructure::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
uint64_t ThreadStructure::nextTicketNumber = 1;
uint64_t ThreadStructure::current_valid_ticket = 1;
pthread_mutex_t ThreadStructure::ticketMutex = PTHREAD_MUTEX_INITIALIZER;

ThreadStructure::ThreadSpecific::ThreadSpecific() :
  event( ),
  ticket( 0 ),
  ticketIsServed( true ),
  thisContext( NULL ),
  contextStack( ),
  subcontexts( ),
  serviceStack( )
{

} // ThreadSpecific

ThreadStructure::ThreadSpecific::~ThreadSpecific() {

} // ~ThreadSpecific

ThreadStructure::ThreadSpecific* ThreadStructure::ThreadSpecific::init() {
		pthread_once(&keyOnce, ThreadStructure::ThreadSpecific::initKey);
  	ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  	if (t == 0) {
    		t = new ThreadSpecific();
    		assert(pthread_setspecific(pkey, t) == 0);
  	}
  	return t;
} // init

void ThreadStructure::ThreadSpecific::releaseThreadSpecificMemory(){
  pthread_once(&keyOnce, initKey);
  ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  if (t != 0) {
    delete t;
  }
}

void ThreadStructure::ThreadSpecific::initKey() {
		assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey

uint64_t ThreadStructure::ThreadSpecific::myTicket() const {
  	return this->ticket;
} 

mace::HighLevelEvent& ThreadStructure::ThreadSpecific::myEvent() {
  	return this->event;
}  

/* make a copy of event object. store it in the thread-specific heap.*/
void ThreadStructure::ThreadSpecific::setEvent(const mace::HighLevelEvent& _event) {
  event = _event; 
}
const uint64_t ThreadStructure::ThreadSpecific::getEventContextMappingVersion() const {
  	return this->event.eventContextMappingVersion;
} 

void ThreadStructure::ThreadSpecific::setEventContextMappingVersion( )  {
  	this->event.eventContextMappingVersion = this->event.eventID;
} 
void ThreadStructure::ThreadSpecific::setEventContextMappingVersion( const uint64_t ver )  {
  	this->event.eventContextMappingVersion = ver;
} 

void ThreadStructure::ThreadSpecific::popContext(){
    ASSERT( !contextStack.empty() );
    contextStack.pop_back();
}

//void ThreadStructure::ThreadSpecific::pushContext(const std::string& contextID){
void ThreadStructure::ThreadSpecific::pushContext(const std::string& contextID){
    contextStack.push_back( contextID );
}

//const mace::string& ThreadStructure::ThreadSpecific::getCurrentContext() const{
const uint32_t ThreadStructure::ThreadSpecific::getCurrentContext() const{
    ASSERT( !contextStack.empty() );
    return contextStack.back();
}

const mace::vector<uint8_t, mace::set<uint32_t> >& ThreadStructure::ThreadSpecific::getEventContexts()const {
    return  event.eventContexts;
}
const mace::set<uint32_t> & ThreadStructure::ThreadSpecific::getCurrentServiceEventContexts() {
    return  event.eventContexts[ getServiceInstance() ];
}
const mace::map<uint32_t, mace::string> & ThreadStructure::ThreadSpecific::getCurrentServiceEventSnapshotContexts() {
    return  event.eventSnapshotContexts[ getServiceInstance() ];
}
const uint64_t ThreadStructure::ThreadSpecific::getCurrentServiceEventSkipID(const mace::string& contextID) const {
    return  event.getSkipID( getServiceInstance(), contextID );
}
const bool ThreadStructure::ThreadSpecific::isEventEnteredService() const {
    uint8_t currentService = getServiceInstance();
    if( event.eventContexts.size() <= currentService ){
      return false;
    }
    if( event.eventContexts[ currentService ].size() > 0 ){ // holding lock of some contexts in this service
      return true;
    }
    if( event.eventSnapshotContexts.size() <= currentService ){ // does not hold lock of some contexts, and does not have snapshot of any contexts in this service
      return false;
    }
    if( event.eventSnapshotContexts[ currentService ].size() > 0 ){ // has snapshot of some contexts in this service
      return true;
    }
    return false;
    //return  (event.eventContexts.find( getServiceInstance() ) != event.eventContexts.end() );
}
//const bool ThreadStructure::ThreadSpecific::insertEventContext(const mace::string& contextID){
const bool ThreadStructure::ThreadSpecific::insertEventContext(const uint32_t contextID){
    uint8_t serviceUID = getServiceInstance();
    if( event.eventContexts.size() <= serviceUID ){
      event.eventContexts.resize( serviceUID );
    }
    std::pair<mace::set<uint32_t>::iterator, bool> result = event.eventContexts[serviceUID].insert(contextID);
    // Event is allowed to enter a context multiple times.
    //ASSERTMSG( result.second , "Context already owned by the event!");
    return result.second;
}
//const bool ThreadStructure::ThreadSpecific::removeEventContext(const mace::string& contextID){
const bool ThreadStructure::ThreadSpecific::removeEventContext(const uint32_t ){
    uint8_t serviceUID = getServiceInstance();
    if( event.eventContexts.size() <= serviceUID ){
      event.eventContexts.resize( serviceUID );
    }
    const mace::set<uint32_t>::size_type removedContexts = event.eventContexts[serviceUID].erase(contextID);
    ASSERTMSG( removedContexts == 1 , "Context not found! Can't remove the context id.");
    return static_cast<const bool>(removedContexts);
}
//const void ThreadStructure::ThreadSpecific::insertSnapshotContext(const mace::string& contextID, const mace::string& snapshot){
const void ThreadStructure::ThreadSpecific::insertSnapshotContext(const uint32_t contextID, const mace::string& snapshot){
  uint8_t serviceUID = getServiceInstance();
  if( event.eventContexts.size() <= serviceUID ){
    event.eventContexts.resize( serviceUID );
  }
  event.eventSnapshotContexts[serviceUID][ contextID ] = snapshot;
}
// obsolete
void ThreadStructure::ThreadSpecific::initializeEventStack(){
//    event.eventContexts.clear();
//    event.eventMessageCount = 0;
}
//void ThreadStructure::ThreadSpecific::setEventContexts(const mace::map< uint8_t, mace::set<mace::string> >& contextIDs){
void ThreadStructure::ThreadSpecific::setEventContexts(const mace::vector< mace::set<mace::string> >& contextIDs){
    event.eventContexts = contextIDs;
}
mace::ContextBaseClass* ThreadStructure::ThreadSpecific::myContext()const{
    return this->thisContext;
}
void ThreadStructure::ThreadSpecific::setMyContext(mace::ContextBaseClass* thisContext){
    this->thisContext = thisContext;
}
void ThreadStructure::ThreadSpecific::pushServiceInstance(const uint8_t uid){
    serviceStack.push_back( uid );
}
void ThreadStructure::ThreadSpecific::popServiceInstance(){
    ASSERT( !serviceStack.empty() );
    serviceStack.pop_back();
}
bool ThreadStructure::ThreadSpecific::isOuterMostTransition() const{
    return serviceStack.size()==1;
    //return ( eventID == 0 )? true : false;
}
bool ThreadStructure::ThreadSpecific::isFirstMaceInit() const{
    return ( event.eventID == 0 && event.eventType == mace::HighLevelEvent::UNDEFEVENT )? true : false;
}
bool ThreadStructure::ThreadSpecific::isFirstMaceExit() const{
    return ( event.eventID != 0 && event.eventType != mace::HighLevelEvent::ENDEVENT )? true : false;
}
const uint8_t ThreadStructure::ThreadSpecific::getServiceInstance() const{
    ASSERT( !serviceStack.empty() );
    return serviceStack.back();
}
bool ThreadStructure::ThreadSpecific::checkValidContextRequest(const mace::string& contextID){
    // XXX: unfinished
    bool validity = true;
    // Entering a context c is allowed if the event already holds the lock of context c, or if c is the child context of one of the contexts this event currently holds.
    // In other words, the write line is above c.
    if( validity == false ){
        std::ostringstream errorOSS;
        errorOSS<<"invalid context transition. Set of contexts currently possessed by the context event "<< myTicket() << " : "<< getEventContexts() <<". Requested context is "<< contextID <<".";

        ABORT( errorOSS.str().c_str() );
    }
    return validity;
}
void ThreadStructure::ThreadSpecific::setThreadType( const uint8_t type ){
    threadType = type;
}
uint8_t ThreadStructure::ThreadSpecific::getThreadType(){
    return threadType;
}


uint32_t ThreadStructure::ThreadSpecific::incrementEventMessageCount(){
    ASSERT( event.eventType != mace::HighLevelEvent::UNDEFEVENT );
    return event.eventMessageCount++;
}
void ThreadStructure::ThreadSpecific::setEventMessageCount(const uint32_t count){
    ASSERT( event.eventType != mace::HighLevelEvent::UNDEFEVENT );
    event.eventMessageCount = count;
}
const uint32_t& ThreadStructure::ThreadSpecific::getEventMessageCount() const{
    ASSERT( event.eventType != mace::HighLevelEvent::UNDEFEVENT );
    return event.eventMessageCount;
}
