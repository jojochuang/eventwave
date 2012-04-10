#include "HierarchicalContextLock.h"
std::map<uint64_t, uint32_t>  mace::HierarchicalContextLock::committingEvents;
std::map<uint64_t, pthread_cond_t* >  mace::HierarchicalContextLock::enteringEvents;
uint64_t mace::HierarchicalContextLock::now_serving = 0;
uint64_t mace::HierarchicalContextLock::now_committing = 0;
uint32_t mace::HierarchicalContextLock::noLeafContexts = 0;
std::map<uint64_t, std::set<std::string> > mace::HierarchicalContextLock::eventSnapshotContextIDs;
pthread_mutex_t mace::HierarchicalContextLock::ticketbooth = PTHREAD_MUTEX_INITIALIZER;
