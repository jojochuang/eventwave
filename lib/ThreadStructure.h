#ifndef _MACE_TICKET_H
#define _MACE_TICKET_H

#include <list>
#include <pthread.h>

#include "mvector.h"
#include "mhash_set.h"
#include "mace-macros.h"

const int MAX_CONTEXT_NUM = 10;
const int MAX_CONTEXT_CHAR_NUM = 50;

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

    static uint64_t myTicket() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myTicket();
    }

    static void markTicketServed() {
      ThreadSpecific *t = ThreadSpecific::init();
      t->markTicketServed();
      return;
    }

    static void releaseTicket() {
      ThreadSpecific *t = ThreadSpecific::init();
      current_valid_ticket = t->myTicket() + 1;
      return;
    }

    bool checkTicket() {
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

		static mace::string popContext(){
				ThreadSpecific *t = ThreadSpecific::init();
				return t->popContext();
		}

		static bool pushContext(mace::string contextID){
				ThreadSpecific *t = ThreadSpecific::init();
				bool result = t->pushContext(contextID.c_str());
				return result;
		}

  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();
        static ThreadSpecific* init();
        uint64_t myTicket();
        void setTicket(uint64_t ticketNum) { ticket = ticketNum; ticketIsServed = false; }
        void markTicketServed() { ticketIsServed = true; }

				mace::string getCurrentContext();
				bool pushContext(const char* contextID);
				mace::string popContext();

      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        static unsigned int count;
        uint64_t ticket;
        bool ticketIsServed;

				//context stack relevant members
				char contextStack[MAX_CONTEXT_NUM][MAX_CONTEXT_CHAR_NUM];
				int stackPointer;

    }; // ThreadSpecific
};
#endif
