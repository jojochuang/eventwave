#ifndef _MACE_TICKET_H
#define _MACE_TICKET_H

#include <list>
#include <pthread.h>

#include "mvector.h"
#include "mhash_set.h"
#include "mace-macros.h"
		class Ticket {
				private:
						static uint64_t current_valid_ticket;
				public:
						static uint64_t newTicket() {
								ThreadSpecific *t = ThreadSpecific::init();
								return t->newTicket();
						}

						static uint64_t myTicket() {
								ThreadSpecific *t = ThreadSpecific::init();
								return t->myTicket();
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

				private:
						class ThreadSpecific {
								public:
										ThreadSpecific();
										~ThreadSpecific();
										static ThreadSpecific* init();
										uint64_t myTicket();
										uint64_t newTicket();

								private:
										static void initKey();

								private:
										static pthread_key_t pkey;
										static pthread_once_t keyOnce;
										static unsigned int count;
										uint64_t ticket;

						}; // ThreadSpecific
		};
#endif
