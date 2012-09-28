#include "ContextLock.h"
pthread_mutex_t mace::ContextLock::_context_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
