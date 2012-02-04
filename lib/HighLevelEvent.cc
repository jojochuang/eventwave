#include "HighLevelEvent.h"

pthread_mutex_t mace::HighLevelEvent::eventMutex = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::HighLevelEvent::nextTicketNumber = 1;
uint64_t mace::HighLevelEvent::now_committing = 1;
uint64_t mace::HighLevelEvent::migrationEventID = 0;
pthread_cond_t mace::HighLevelEvent::migrationCond = PTHREAD_COND_INITIALIZER;
