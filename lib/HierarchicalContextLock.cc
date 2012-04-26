#include "HierarchicalContextLock.h"
mace::map<uint64_t, uint32_t>  mace::HierarchicalContextLock::committingEvents;
std::map<uint64_t, pthread_cond_t* >  mace::HierarchicalContextLock::enteringEvents;
uint64_t mace::HierarchicalContextLock::now_serving = 1;
uint64_t mace::HierarchicalContextLock::now_committing = 1;
uint32_t mace::HierarchicalContextLock::noLeafContexts = 0;
mace::map<uint64_t, mace::set<mace::string> > mace::HierarchicalContextLock::eventSnapshotContextIDs;
pthread_mutex_t mace::HierarchicalContextLock::ticketbooth = PTHREAD_MUTEX_INITIALIZER;
mace::map<uint64_t, mace::string> mace::HierarchicalContextLock::eventsQueue;
