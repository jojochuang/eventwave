#include "ContextLock.h"
pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::ContextLock::smallestAbsentEvent = 1;
std::map<uint64_t, pthread_cond_t*> mace::ContextLock::notready_events;
uint64_t mace::ContextLock::lastCommittedTicket = 0;
