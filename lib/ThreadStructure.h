#ifndef _MACE_TICKET_H
#define _MACE_TICKET_H

#include <list>
#include <pthread.h>

#include "mvector.h"
#include "mhash_set.h"
#include "mace-macros.h"
#include "mset.h"

//#include "ContextBaseClass.h"
namespace mace{
class ContextBaseClass;
}

class ThreadStructure {
  private:
		//Ticket relevant member variables
    static uint64_t nextTicketNumber;
    static uint64_t current_valid_ticket;
    static pthread_mutex_t ticketMutex;

    static uint64_t migrationTicket;

	public:
		static uint64_t newTicket(bool migrate=false) {
				ADD_SELECTORS("ThreadStructure::newTicket");
      	//Needs error checking that prior ticket is committed?
      	if( migrate == true ){
        		// if migration, don't let any other events get tickets
          	pthread_mutex_lock( & ticketMutex );
          	ThreadSpecific::init()->setTicket(nextTicketNumber);
          	macedbg(1) << "Ticket " << nextTicketNumber << " sold! (migrate event. there shouldn't be no more new tickets after this.)" << Log::endl;
          	return nextTicketNumber++;
      	}else{
          	ScopedLock sl(ticketMutex);
          	ThreadSpecific::init()->setTicket(nextTicketNumber);
          	macedbg(1) << "Ticket " << nextTicketNumber << " sold!" << Log::endl;
          	return nextTicketNumber++;
      	}
    }
    static void setTicket(uint64_t ticket){
      	ThreadSpecific::init()->setTicket(ticket);
    }
    static void setEvent(uint64_t eventID){
        ADD_SELECTORS("ThreadStructure::newTicket");
        macedbg(1)<<"Set event id = "<< eventID << Log::endl;
      	ThreadSpecific::init()->setEvent(eventID);
    }

    static uint64_t myTicket() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myTicket();
    }
    static uint64_t myEvent() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myEvent();
    }

    static mace::ContextBaseClass* myContext(){
      	ThreadSpecific *t = ThreadSpecific::init();
        ASSERTMSG(t->myContext() != NULL, "ThreadStructure::myContext() object returned NULL!");
      	return t->myContext();
    }
    static void setMyContext(mace::ContextBaseClass* thisContext){
        ASSERTMSG(thisContext != NULL, "ThreadStructure::setMyContext() received a NULL pointer!");
      	ThreadSpecific *t = ThreadSpecific::init();
        t->setMyContext( thisContext );
    }

    static void markTicketServed() {// chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      t->markTicketServed();
      return;
    }

    static void releaseTicket() {// chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      current_valid_ticket = t->myTicket() + 1;
      return;
    }

    bool checkTicket() { // chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      if (current_valid_ticket == t->myTicket()) return true;
      else return false;
    }

    static uint64_t current_ticket() {
      return current_valid_ticket;
    }

    static mace::string getCurrentContext(){
            ThreadSpecific *t = ThreadSpecific::init();
            return t->getCurrentContext();
    }

    static void popContext(){
            ThreadSpecific *t = ThreadSpecific::init();
            t->popContext();
    }

    static void pushContext(const mace::string& contextID){
            ThreadSpecific *t = ThreadSpecific::init();
            t->pushContext(contextID);
    }

    /**
     * This function returns a set of contexts owned by the event
     * */
    static const mace::set<mace::string>& getEventContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventContexts();
    }
    /**
     * This function returns a set of child-contexts of a context owned by the event
     * */
    static mace::set<mace::string>& getEventChildContexts(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventChildContexts( contextID );
    }

    /**
     * This function checks if the current event is allowed to enter the context
     * 
     * \param contextID Context ID requested to enter
     * */
    static bool isValidContextRequest(const mace::string& contextID){
        // XXX: unfinished
        return true;
    }

  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();
        static ThreadSpecific* init();
        uint64_t myTicket();
        uint64_t myEvent();
        mace::ContextBaseClass* myContext();
        void setMyContext(mace::ContextBaseClass* thisContext);
        void setTicket(uint64_t ticketNum) { ticket = ticketNum; ticketIsServed = false; }
        void setEvent(uint64_t _event) { eventID = _event; }
        void markTicketServed() { ticketIsServed = true; }

        const mace::string& getCurrentContext() const;
        void pushContext(const mace::string& contextID);
        void popContext();

        mace::set<mace::string>& getEventChildContexts(const mace::string& contextID) {
            return subcontexts[contextID];
        }
        const mace::set<mace::string>& getEventContexts() const;

      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        static unsigned int count;
        uint64_t ticket;
        uint64_t eventID;
        bool ticketIsServed;

        mace::ContextBaseClass* thisContext;
        mace::vector< mace::string> contextStack;

        mace::set<mace::string> eventContexts;///< all the contexts possessed by this event

        mace::map<mace::string, mace::set<mace::string> > subcontexts;
    }; // ThreadSpecific
};
#endif
