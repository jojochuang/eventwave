#include "ThreadStructure.h"

pthread_key_t ThreadStructure::ThreadSpecific::pkey;
pthread_once_t ThreadStructure::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
uint64_t ThreadStructure::nextTicketNumber = 1;
uint64_t ThreadStructure::current_valid_ticket = 1;
pthread_mutex_t ThreadStructure::ticketMutex = PTHREAD_MUTEX_INITIALIZER;

ThreadStructure::ThreadSpecific::ThreadSpecific() {
  	ticket = 0;
  	ticketIsServed = true;

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

const mace::set<mace::string>& ThreadStructure::ThreadSpecific::getEventContexts()const {
    return  eventContexts;
}
mace::ContextBaseClass* ThreadStructure::ThreadSpecific::myContext(){
    return this->thisContext;
}
void ThreadStructure::ThreadSpecific::setMyContext(mace::ContextBaseClass* thisContext){
    this->thisContext = thisContext;
}
