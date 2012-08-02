#include "HierarchicalContextLock.h"
std::map<uint64_t, pthread_cond_t* >  mace::HierarchicalContextLock::enteringEvents;
std::map<uint64_t, pthread_cond_t*> mace::HierarchicalContextLock::commitConditionVariables;
uint64_t mace::HierarchicalContextLock::now_serving = 1;
uint64_t mace::HierarchicalContextLock::now_committing = 1;
uint32_t mace::HierarchicalContextLock::noLeafContexts = 0;
mace::map<uint64_t, mace::set<mace::string> > mace::HierarchicalContextLock::eventSnapshotContextIDs;
pthread_mutex_t mace::HierarchicalContextLock::ticketbooth = PTHREAD_MUTEX_INITIALIZER;
mace::map<uint64_t, mace::string> mace::HierarchicalContextLock::eventsQueue;


pthread_key_t mace::HierarchicalContextLock::ThreadSpecific::pkey; pthread_once_t mace::HierarchicalContextLock::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;

mace::HierarchicalContextLock::ThreadSpecific::ThreadSpecific() 
{
  pthread_cond_init(&threadCond, 0);
} // ThreadSpecific

mace::HierarchicalContextLock::ThreadSpecific::~ThreadSpecific() {
  pthread_cond_destroy(&threadCond);
} // ~ThreadSpecific

mace::HierarchicalContextLock::ThreadSpecific* mace::HierarchicalContextLock::ThreadSpecific::init() {
  pthread_once(&keyOnce, mace::HierarchicalContextLock::ThreadSpecific::initKey);
  ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  if (t == 0) {
    t = new ThreadSpecific();
    assert(pthread_setspecific(pkey, t) == 0);
  }

  return t;
} // init

void mace::HierarchicalContextLock::ThreadSpecific::initKey() {
  assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey
