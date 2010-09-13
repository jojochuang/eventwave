#include "Ticket.h"

pthread_key_t Ticket::ThreadSpecific::pkey;
pthread_once_t Ticket::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
uint64_t Ticket::current_valid_ticket = 1;

Ticket::ThreadSpecific::ThreadSpecific() {
} // ThreadSpecific

Ticket::ThreadSpecific::~ThreadSpecific() {
} // ~ThreadSpecific

Ticket::ThreadSpecific* Ticket::ThreadSpecific::init() {
  pthread_once(&keyOnce, Ticket::ThreadSpecific::initKey);
  ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  if (t == 0) {
    t = new ThreadSpecific();
    assert(pthread_setspecific(pkey, t) == 0);
  }

  return t;
} // init

void Ticket::ThreadSpecific::initKey() {
  assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey

uint64_t Ticket::ThreadSpecific::myTicket() {
  return this->ticket;
} // getStackValue

uint64_t Ticket::ThreadSpecific::newTicket() {
		this->ticket++;
		return this->ticket;
} // increaseStackValue()

