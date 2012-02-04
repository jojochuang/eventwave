#include "HighLevelEvent.h"

pthread_mutex_t mace::HighLevelEvent::eventMutex = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::HighLevelEvent::nextTicketNumber = 1;
uint64_t mace::HighLevelEvent::now_committing = 1;
std::queue<pthread_cond_t*> mace::HighLevelEvent::migrationRequests;
