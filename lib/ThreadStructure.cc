#include "ThreadStructure.h"

pthread_key_t ThreadStructure::ThreadSpecific::pkey;
pthread_once_t ThreadStructure::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
uint64_t ThreadStructure::nextTicketNumber = 1;
uint64_t ThreadStructure::current_valid_ticket = 1;
pthread_mutex_t ThreadStructure::ticketMutex = PTHREAD_MUTEX_INITIALIZER;

ThreadStructure::ThreadSpecific::ThreadSpecific() {
  	ticket = 0;
  	ticketIsServed = true;
    eventID = 0;

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

void ThreadStructure::ThreadSpecific::initKey() {
		assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey

uint64_t ThreadStructure::ThreadSpecific::myTicket() {
  	return this->ticket;
} // getStackValue

uint64_t ThreadStructure::ThreadSpecific::myEvent() {
  	return this->eventID;
} // getStackValue

void ThreadStructure::ThreadSpecific::popContext(){
    ASSERT( !contextStack.empty() );
    contextStack.pop_back();
}

void ThreadStructure::ThreadSpecific::pushContext(const std::string& contextID){
    contextStack.push_back( contextID );
}

const mace::string& ThreadStructure::ThreadSpecific::getCurrentContext() const{
    ASSERT( !contextStack.empty() );
    return contextStack.back();
}

const mace::map<uint8_t, mace::set<mace::string> >& ThreadStructure::ThreadSpecific::getEventContexts()const {
    return  eventContexts;
}
const bool ThreadStructure::ThreadSpecific::insertEventContext(const mace::string& contextID){
    uint8_t serviceUID = getServiceInstance();
    std::pair<mace::set<mace::string>::iterator, bool> result = eventContexts[serviceUID].insert(contextID);
    // Event is allowed to enter a context multiple times.
    //ASSERTMSG( result.second , "Context already owned by the event!");
    return result.second;
}
const bool ThreadStructure::ThreadSpecific::removeEventContext(const mace::string& contextID){
    uint8_t serviceUID = getServiceInstance();
    const mace::set<mace::string>::size_type removedContexts = eventContexts[serviceUID].erase(contextID);
    ASSERTMSG( removedContexts == 1 , "Context not found! Can't remove the context id.");
    return static_cast<const bool>(removedContexts);
}
void ThreadStructure::ThreadSpecific::initializeEventStack(){
    eventContexts.clear();
    eventMessageCount = 0;
}
void ThreadStructure::ThreadSpecific::setEventContexts(const mace::map< uint8_t, mace::set<mace::string> >& contextIDs){
    eventContexts = contextIDs;
}
mace::ContextBaseClass* ThreadStructure::ThreadSpecific::myContext(){
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
    return serviceStack.empty();
    //return ( eventID == 0 )? true : false;
}
bool ThreadStructure::ThreadSpecific::isInnerMostTransition() const{
    //return serviceStack.empty();
    return ( eventID == 0 )? true : false;
}
uint8_t ThreadStructure::ThreadSpecific::getServiceInstance(){
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
    return eventMessageCount++;
}
void ThreadStructure::ThreadSpecific::setEventMessageCount(const uint32_t count){
    eventMessageCount = count;
}
const uint32_t& ThreadStructure::ThreadSpecific::getEventMessageCount() const{
    return eventMessageCount;
}
