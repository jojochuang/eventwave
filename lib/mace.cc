/* 
 * mace.cc : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of the contributors, nor their associated universities 
 *      or organizations may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
#include <errno.h>
#include "mace.h"
#include "ScopedStackExecution.h"
#include "HighLevelEvent.h"
#include "AsyncDispatch.h"
#include "HierarchicalContextLock.h"

int32_t __eventContextType = 0;    // used in simulator to determine the context type of the event.

static pthread_mutex_t getRecursiveMutex() {
  pthread_mutex_t mutex;
  pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex, &mutexattr); 
	return mutex;
}

pthread_mutex_t BaseMaceService::synclock = getRecursiveMutex();
bool BaseMaceService::_printLower = false;

std::deque<BaseMaceService*> BaseMaceService::instances;
uint64_t BaseMaceService::lastSnapshot = 0;
uint64_t BaseMaceService::lastSnapshotReleased = 0;

BaseMaceService::BaseMaceService(bool enqueueService) 
{
  if (enqueueService) {
    instances.push_back(this);
  }
}

//chuangw: Obsoleted....
void BaseMaceService::globalSnapshot(const uint64_t& ver) {
  ADD_SELECTORS("BaseMaceService::globalSnapshot");
  macedbg(1) << "Global Snapshot Requested for Version " << ver << " lastSnapshot " << lastSnapshot << " lastSnapshotReleased " << lastSnapshotReleased << Log::endl;
  if (ver > lastSnapshot) {
    macedbg(1) << "Performing global snapshot." << Log::endl;
    for (std::deque<BaseMaceService*>::const_iterator i = instances.begin(); i != instances.end(); i++) {
      (*i)->snapshot(ver);
    }
    lastSnapshot = ver;
  }
  else {
    // Possibly log here?
  }
}
//chuangw: Obsoleted....
void BaseMaceService::globalSnapshotRelease(const uint64_t& ver) {
  ADD_SELECTORS("BaseMaceService::globalSnapshotRelease");
  macedbg(1) << "Global Snapshot Release Requested for Version " << ver << " lastSnapshot " << lastSnapshot << " lastSnapshotReleased " << lastSnapshotReleased << Log::endl;
  if (lastSnapshot >= lastSnapshotReleased && lastSnapshotReleased < ver) {
    macedbg(1) << "Performing global snapshot release." << Log::endl;
    for (std::deque<BaseMaceService*>::const_iterator i = instances.begin(); i != instances.end(); i++) {
      (*i)->snapshotRelease(ver);
    }
    lastSnapshotReleased = ver;
  }
}
void BaseMaceService::requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly){
  ThreadStructure::newTicket();

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE ); // this lock is used to make sure the event is created in order.
  mace::HighLevelEvent he( mace::HighLevelEvent::MIGRATIONEVENT );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  ThreadStructure::setEvent( he );
  mace::string dummybuf;
  mace::serialize( dummybuf, &he.getEventType() );
  mace::serialize( dummybuf, &serviceID );
  mace::serialize( dummybuf, &contextID );
  mace::serialize( dummybuf, &destNode );
  mace::serialize( dummybuf, &rootOnly );
  mace::HierarchicalContextLock hl(he, dummybuf );
}

/*void BaseMaceService::eventHeadHandler( const mace::Serializable& msg, const mace::__asyncExtraField& extra, const uint8_t eventType, const& mace::ContextLock* headContextLock ){

}*/

// #define AGENT_LOCK_DEBUG 0
// #define AGENT_LOCK_TIME 0
// // ---------------------------------------------- 
// // lock functions
// // ---------------------------------------------- 
// 
// void  BaseMaceService::Lock ()
// {
// #if AGENT_LOCK_DEBUG > 1
//   printf("%d Agent_lock in : %d %d %x %d %x %d \n", pthread_self(),
//       agentlock.__m_reserved,
//       agentlock.__m_count,
//       agentlock.__m_owner,
//       agentlock.__m_kind,
//       agentlock.__m_lock.__status,
//       agentlock.__m_lock.__spinlock
//       );
//   //        fflush(stdout);
// #endif
//   pthread_mutex_lock(&(agentlock));
// #if AGENT_LOCK_DEBUG > 0
//   printf("%d Agent_lock out %d\n" , pthread_self(),lock_count);
// #endif
// }
// 
// // ---------------------------------------------- 
// // unlock
// // ---------------------------------------------- 
// 
// void  BaseMaceService::Unlock ()
// {
// #if AGENT_LOCK_DEBUG > 1
//   printf("%d Agent_unlock in : %d %d %x %d %x %d \n", pthread_self(),
//       agentlock.__m_reserved,
//       agentlock.__m_count,
//       agentlock.__m_owner,
//       agentlock.__m_kind,
//       agentlock.__m_lock.__status,
//       agentlock.__m_lock.__spinlock
//       );
// #endif
//   pthread_mutex_unlock(&(agentlock));
// #if AGENT_LOCK_DEBUG > 0
//   printf("%d Agent_unlock out %d %d\n", pthread_self(), lock_count,lock_owner );
// #endif
// }

pthread_mutex_t mace::AgentLock::_agent_ticketbooth = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::AgentLock::now_serving = 1; // First ticket has number 1.
uint64_t mace::AgentLock::lastWrite = 1; // First ticket has number 1.
int mace::AgentLock::numReaders = 0;
int mace::AgentLock::numWriters = 0;
std::map<uint64_t, pthread_cond_t*> mace::AgentLock::conditionVariables;

uint64_t mace::AgentLock::now_committing = 1; // First ticket has number 1.
std::map<uint64_t, pthread_cond_t*> mace::AgentLock::commitConditionVariables;

pthread_mutex_t mace::AgentLock::ticketMutex = PTHREAD_MUTEX_INITIALIZER;
uint64_t mace::AgentLock::nextTicketNumber = 1;

pthread_key_t mace::AgentLock::ThreadSpecific::pkey;
pthread_once_t mace::AgentLock::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;

mace::AgentLock::ThreadSpecific::ThreadSpecific() : currentMode(-1), myTicketNum(std::numeric_limits<uint64_t>::max()), 
  snapshotVersion(0)
{
  pthread_cond_init(&threadCond, 0);
} // ThreadSpecific

mace::AgentLock::ThreadSpecific::~ThreadSpecific() {
  pthread_cond_destroy(&threadCond);
} // ~ThreadSpecific

mace::AgentLock::ThreadSpecific* mace::AgentLock::ThreadSpecific::init() {
  pthread_once(&keyOnce, mace::AgentLock::ThreadSpecific::initKey);
  ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  if (t == 0) {
    t = new ThreadSpecific();
    assert(pthread_setspecific(pkey, t) == 0);
  }

  return t;
} // init

void mace::AgentLock::ThreadSpecific::initKey() {
  assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey


/*
std::set<mace::commit_executor*> mace::registered;
std::set<mace::CommitWrapper*> mace::registered_class;
*/
void mace::Init(int argc, char** argv) {
  params::loadparams(argc, argv);
  Init();
}

void mace::Init() {
  Log::configure(); //This should probably be first

  //   Scheduler::init(); // This should probably be written.
  AsyncDispatch::init();
}

void mace::Shutdown() {
  AsyncDispatch::haltAndWait();

  Scheduler::haltScheduler(); //Keep this last!
}
