#include "HighLevelEvent.h"

pthread_mutex_t mace::HighLevelEvent::eventMutex = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::HighLevelEvent::nextTicketNumber = 1;
uint64_t mace::HighLevelEvent::lastWriteContextMapping = 0;
//uint64_t mace::HighLevelEvent::now_committing = 1;
//std::queue<pthread_cond_t*> mace::HighLevelEvent::migrationRequests;

/*const uint8_t mace::HighLevelEvent::STARTEVENT = 0;
const uint8_t mace::HighLevelEvent::ENDEVENT   = 1;
const uint8_t mace::HighLevelEvent::TIMEREVENT = 2;
const uint8_t mace::HighLevelEvent::ASYNCEVENT = 3;
const uint8_t mace::HighLevelEvent::UPCALLEVENT= 4;
const uint8_t mace::HighLevelEvent::DOWNCALLEVENT= 5;
const uint8_t mace::HighLevelEvent::MIGRATIONEVENT = 6;
const uint8_t mace::HighLevelEvent::NEWCONTEXTEVENT = 7;
const uint8_t mace::HighLevelEvent::UNDEFEVENT = 8;*/
