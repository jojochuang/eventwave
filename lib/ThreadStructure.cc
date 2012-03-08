#include "ThreadStructure.h"

pthread_key_t ThreadStructure::ThreadSpecific::pkey;
pthread_once_t ThreadStructure::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
uint64_t ThreadStructure::nextTicketNumber = 1;
uint64_t ThreadStructure::current_valid_ticket = 1;
pthread_mutex_t ThreadStructure::ticketMutex = PTHREAD_MUTEX_INITIALIZER;

ThreadStructure::ThreadSpecific::ThreadSpecific() {
  	ticket = 0;
  	ticketIsServed = true;

		stackPointer = -1;
} // ThreadSpecific

ThreadStructure::ThreadSpecific::~ThreadSpecific() {

} // ~ThreadSpecific

ThreadStructure::ThreadSpecific* ThreadStructure::ThreadSpecific::init() {
		pthread_once(&keyOnce, Ticket::ThreadSpecific::initKey);
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

mace::string ThreadStructure::ThreadSpecific::popContext(){
		mace::string contextID="";
		if(stackPointer>=0){
				contextID=contextStack[stackPointer];
				stackPointer--;
		}
		return contextID;
}

bool ThreadStructure::ThreadSpecific::pushContext(const char* contextID){
		if(stackPointer >= MAX_CONTEXT_NUM){
				return false;
		}else{
				strcpy(contextStack[++stackPointer], contextID);
				return true;
		}

}

mace::string ThreadStructure::ThreadSpecific::getCurrentContext(){
		mace::string contextID="";
		if(stackPointer>=0){
				contextID=contextStack[stackPointer];
		}
		return contextID;
}

