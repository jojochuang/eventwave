/*
 * modelchecker.cc : part of the Mace toolkit for building distributed systems
 *
 * Copyright (c) 2007, Charles Killian, James W. Anderson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the names of Duke University nor The University of
 *      California, San Diego, nor the names of the authors or contributors
 *      may be used to endorse or promote products derived from
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

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <dirent.h>
#include <errno.h>
#include <sched.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "Accumulator.h"
#include "Event.h"
#include "LoadTest.h"
#include "Log.h"
#include "mace.h"
#include "mace_constants.h"
#include "macemc-getmtime.h"
#include "MaceTime.h"
#include "MCMessage.h"
#include "MCMessageData.h"
#include "MCMessageNodeInfo.h"
#include "MCMessageNodeReady.h"
#include "MCMessagePrefixRequest.h"
#include "MCMessagePrefixReply.h"
#include "MCMessagePrefixCount.h"
#include "NumberGen.h"
#include "pip_includer.h"
#include "PrefixBalancer.h"
#include "PrefixSearcherRandomUtil.h"
#include "PrefixTree.h"
#include "Properties.h"
#include "RouteTransportWrapper.h"
#include "Sim.h"
#include "SimApplication.h"
#include "SimNetwork.h"
#include "SimScheduler.h"
#include "Simulator.h"
#include "StateCommunicator.h"
#include "StateCommunicatorMMAP.h"
#include "StateCommunicatorTcp.h"
#include "StateCommunicatorUnix.h"
#include "SysUtil.h"
#include "ThreadCreate.h"

#ifdef MC_MPI
#include <mpi.h>
#include "StateCommunicatorMPI.h"
#endif

#undef exit

#define MAX(x,y) (x) > (y) ? (x) : (y)

using namespace macemc;

typedef RouteTransportWrapper_namespace::RouteTransportWrapperService RouteTransportWrapper;

struct comm_data {
  StateCommunicator<MCMessage> **communicators;
  StateCommunicator<MCMessage> *offnode_in;
  StateCommunicator<MCMessage> *offnode_out;
  bool multiple_nodes;
  std::string local_comm_method;
  std::string offnode_comm_method;
  int local_buffer_size;
  int offnode_buffer_size;
  unsigned *workerPrefixCounts;
};

typedef struct prefix_request {
  unsigned proc;
  unsigned node;
} PrefixRequest;

// #undef ASSERT
// #define ASSERT(x)  if(!x) { Log::log("ERROR::ASSERT") << *randomUtil << Log::endl; std::ofstream out(("error"+lexical_cast<std::string>(error_path++)+".path").c_str()); randomUtil->printVSErrorPath(out); out.close(); abort(); }

const int APP_EVENT = 0;
const int NET_EVENT = 1;
const int SCHED_EVENT = 2;

int base_port;
std::string* nodeString;

using boost::lexical_cast;

// namespace macemc {
//   void addRandTree();
// }

/* I'm gonna eat his children!  -Mike Tyson
 * Keeps track of child PIDs so that we can terminate children on ctrl-c. */
static std::vector<pid_t> children;

/* State statistics. */
static int uniqueStateCount = 0;
static int duplicateStateCount = 0;

/* Condition for workers to sleep on while waiting for work (when they run out). */
static pthread_mutex_t outOfPrefixesLock;
static pthread_cond_t prefixReceived;

/* Address information for inter-node communication mechanisms that use explicit
 * addressing (TCP). */
static std::vector<std::string *> nodeAddresses;

/* The file stream to which all output is written by default. We don't use
 * standard out because we want to separate the different processes and give
 * each its own file. */
static FILE* defaultOutputFile = NULL;

/* Keeps track of communication policies and state. */
struct comm_data comm;

void niceMkdir(const char *directory) {
  DIR *pDir;
  bool dirExists = false;
  pDir = opendir(directory);

  if (pDir != NULL) {
    dirExists = true;
    closedir(pDir);
  }

  if (!dirExists) {
    if (mkdir(directory, 0777) != 0) {
      perror("mkdir()");
    }
  }
}

void* monitor(void* dud) {
  ADD_FUNC_SELECTORS;
  bool divergence_assert = params::containsKey("divergence_assert");
  maceout << "monitor begun" << Log::endl;
  int timeout = params::get("divergence_timeout", 5);
  __Simulator__::expireMonitor();
  while(true) {
    SysUtil::sleep(timeout);
    if(__Simulator__::expireMonitor()) {
      Log::enableLogging();
      __Simulator__::Error("DIVERGENCE", divergence_assert);
    }
  }
  return NULL;
}

void issueLocalPrefixRequest(PrefixRequest *request) {
  unsigned from_node = request->node;
  unsigned from_proc = request->proc;
  unsigned nodeRank = __Simulator__::getNodeRank();
  unsigned processCount = __Simulator__::getProcessCount();

  unsigned max_num_prefixes;
  unsigned max_proc;
  unsigned current_prefix_count;
  unsigned total_available_prefix_count;
  unsigned maxPrefixCount;
  unsigned requesterPrefixCount;

  bool shouldSend;

  total_available_prefix_count = 0;

  for (unsigned i = 1; i < processCount; i++) {
    if (comm.workerPrefixCounts[i] > 0) {
      total_available_prefix_count += comm.workerPrefixCounts[i] - 1;
    }
  }

  if (total_available_prefix_count == 0) {
    Log::log("prefixes") << "Can't comply with request from node " << from_node  << ", process " << from_proc  << "; not enough prefixes." << Log::endl;

    int connectedNode = 0;
    int connectedProc = 0;

    comm.offnode_out->get_peer(connectedNode, connectedProc, ENDPOINT_OUTGOING);

    if ((unsigned) connectedNode == from_node) {
      Log::log("prefixes") << "Nobody can satisfy request. I give up." << Log::endl;
    } else {
      Log::log("prefixes") << "Forwarding prefix request from node " << from_node << " to node " << connectedNode << Log::endl;
      
      MCMessagePrefixRequest offnodePrefixRequest(from_node, from_proc, connectedNode, connectedProc);
      
      comm.offnode_out->put(&offnodePrefixRequest, ENDPOINT_OUTGOING);
      comm.offnode_out->deliver(ENDPOINT_OUTGOING);
    }

    return;
  }

  shouldSend = true;

  max_num_prefixes = 1;
  max_proc = 0;  

  for (unsigned i = 1; i < processCount; i++) {
    current_prefix_count = comm.workerPrefixCounts[i];
    
    if (current_prefix_count > max_num_prefixes) {
      max_num_prefixes = current_prefix_count;
      max_proc = i;
    }
  }
  
  if (from_node == nodeRank) {
    if (max_proc == from_proc) {
      shouldSend = false;
      Log::log("prefixes") << "Ignoring process " << from_proc << " on node " << nodeRank << "'s request; process already has the most prefixes" << Log::endl;
    } else {
      maxPrefixCount = comm.workerPrefixCounts[max_proc];
      requesterPrefixCount = comm.workerPrefixCounts[from_proc];
      
      if (maxPrefixCount == requesterPrefixCount || (maxPrefixCount - 1 == requesterPrefixCount)) {
        shouldSend = false;
        Log::log("prefixes") << "Ignoring process " << from_proc << " on node " << nodeRank << "'s request; would have no net effect on prefix balance" << Log::endl;
      } 
    }
  }
  
  if (shouldSend) {
    MCMessagePrefixRequest outgoingPrefixRequest(from_node, from_proc, nodeRank, max_proc);
    
    comm.communicators[max_proc]->put(&outgoingPrefixRequest, ENDPOINT_RELAY);
    comm.communicators[max_proc]->deliver(ENDPOINT_RELAY);      
  }
}

void *receiveUpdates(void *comm_to_relay) {
  ADD_FUNC_SELECTORS;

  int local_buffer_size = params::get<int>("LOCAL_BUFFER_SIZE", 10);
  int count = 0;
  StateCommunicator<MCMessage> *communicator = (StateCommunicator<MCMessage> *) comm_to_relay;
  MCMessage *messages = new MCMessage[local_buffer_size];
  MCMessageData *data_message = NULL;
  MCMessagePrefixRequest *prefix_request_message = NULL;
  MCMessagePrefixReply *prefix_reply_message = NULL;

  unsigned nodeRank = __Simulator__::getNodeRank();

  while (true) {
    count = communicator->receive(messages, ENDPOINT_WORKER);

    for (int i = 0; i < count; ++i) {
      // For prefix request message
      UIntList *prefix;
      int depth;

      switch (messages[i].get_type()) {
        case MCMESSAGE_TYPE_DATA:
          data_message = (MCMessageData *) messages + i;
          Log::log("IntraNode") << "Read hash: " << data_message->get_hash() << " from relay." << Log::endl;
          if (__Simulator__::shouldCheckForDuplicates()) {
            __Simulator__::addToStateMap(data_message->get_hash(), *(data_message->get_path()));
          }
          break;

        case MCMESSAGE_TYPE_PREFIX_REQUEST:
          prefix_request_message = (MCMessagePrefixRequest *) messages + i;

          depth = 0;
          prefix = __Simulator__::randomUtil->getPathPrefix(depth);

          if (depth == 0) {
            // Couldn't fulfill prefix request; must be out of prefixes
            Log::log("prefixes") << "Can't fulfill prefix request; sending NACK" << Log::endl;
          }

          prefix_reply_message = new MCMessagePrefixReply(nodeRank, __Simulator__::getProcessRank(), prefix_request_message->get_from_node(), 
                                                          prefix_request_message->get_from_proc(), depth, *prefix);
          
          communicator->put(prefix_reply_message, ENDPOINT_WORKER);
          communicator->deliver(ENDPOINT_WORKER);
          
          delete prefix_reply_message;
          delete prefix;
          break;
        case MCMESSAGE_TYPE_PREFIX_REPLY:
          prefix_reply_message = (MCMessagePrefixReply *) messages + i;

          prefix = prefix_reply_message->get_prefix();
          depth = prefix_reply_message->get_depth();

          if (depth == 0) {
            Log::log("prefixes") << "Got a NACK for my prefix request" << Log::endl;
          } else {
            Log::log("prefixes") << "Got a new prefix: " << *prefix << " at depth " << depth << Log::endl;
            __Simulator__::randomUtil->addPathPrefix(*prefix, depth);
            pthread_mutex_lock(&outOfPrefixesLock);
            pthread_cond_signal(&prefixReceived);
            pthread_mutex_unlock(&outOfPrefixesLock);
          }
          break;
        default:
          Log::log("IntraNode") << "Encountered unknown message type " <<  messages[i].get_type() << Log::endl;
          ASSERT(false);
          break;
      }
    }
  }
}

void handle_data_message(MCMessageData *message, int processCount) {
  for (unsigned i = 1; i < (unsigned) processCount; ++i) {
    if (message->get_from_proc() != i || message->get_from_node() != (unsigned) __Simulator__::getNodeRank()) {
      if (comm.communicators[i]->put(message, ENDPOINT_RELAY)) {
        comm.communicators[i]->deliver(ENDPOINT_RELAY);
      }
    }
  }

  if (comm.multiple_nodes) {
    int outgoingNode;
    int outgoingProc;

    comm.offnode_out->get_peer(outgoingNode, outgoingProc, ENDPOINT_OUTGOING);

    if (message->get_from_node() != (unsigned) outgoingNode) {
      if (comm.offnode_out->put(message, ENDPOINT_OUTGOING)) {
        comm.offnode_out->deliver(ENDPOINT_OUTGOING);
      }
    }
  }
}

void handle_prefix_request(MCMessagePrefixRequest *message, PrefixBalancer *prefixBalancer) {
  unsigned from_proc = message->get_from_proc();
  unsigned from_node = message->get_from_node();
  unsigned prefixes_needed = message->get_prefixes_needed();
  ASSERT(prefixes_needed == 1);
  unsigned nodeRank = __Simulator__::getNodeRank();

  Log::log("prefixes") << "Received request for prefix from process " << from_proc << " on node " << from_node << Log::endl;

  PrefixRequest req;
  req.proc = from_proc;
  req.node = from_node;

  if (from_node == nodeRank) {
    ASSERT(prefixBalancer != NULL);

    prefixBalancer->addRequest(from_proc, prefixes_needed);
  }

  issueLocalPrefixRequest(&req);
}

void handle_prefix_reply(MCMessagePrefixReply *message, PrefixBalancer *prefixBalancer) {
  unsigned nodeRank = __Simulator__::getNodeRank();

  unsigned from_proc = message->get_from_proc();
  unsigned from_node = message->get_from_node();
  unsigned to_proc = message->get_to_proc();
  unsigned to_node = message->get_to_node();
  unsigned depth = message->get_depth();
  UIntList *prefix = message->get_prefix();

  if (depth == 0) {
    // We received a NACK on our request.

    Log::log("prefixes") << "Received a NACK for prefix request from node " << from_node << ", process " << from_proc << " destined for node " 
                         << to_node << " process " << to_proc << Log::endl;

    PrefixRequest tempReq;
    tempReq.node = to_node;
    tempReq.proc = to_proc;
    issueLocalPrefixRequest(&tempReq);
  } else {
    unsigned replyNode;
    unsigned replyProc;

    if (to_node != nodeRank) {
      replyNode = to_node;
      replyProc = to_proc;
    } else {
      ASSERT(prefixBalancer != NULL);
      replyNode = nodeRank;
      replyProc = prefixBalancer->getRecipient();
    }

    MCMessagePrefixReply outgoingPrefixReply(nodeRank, 0, replyNode, replyProc, 
                                                   depth, *prefix);

    if (replyNode == nodeRank) {
      comm.communicators[replyProc]->put(&outgoingPrefixReply, ENDPOINT_RELAY);
      comm.communicators[replyProc]->deliver(ENDPOINT_RELAY);
    } else {
      ASSERT(comm.multiple_nodes);
      comm.offnode_out->put(&outgoingPrefixReply, ENDPOINT_OUTGOING);
      comm.offnode_out->deliver(ENDPOINT_OUTGOING);
    }
  }  
}

void *relay_receiveUpdates() {
  int processCount = __Simulator__::getProcessCount();
  int nodeRank = __Simulator__::getNodeRank();
  int message_count = 0;
  bool do_yield;
  MCMessage *messages = new MCMessage[MAX(comm.local_buffer_size, comm.offnode_buffer_size)];
  MCMessageData *data_message = NULL;
  MCMessagePrefixRequest *prefix_request_message = NULL;
  MCMessagePrefixReply *prefix_reply_message = NULL;
  MCMessagePrefixCount *prefix_count_message = NULL;

  /* Allows the relay to filter out duplicate states by keeping track of all
   * hashes that have passed through it. */
  mace::hash_map<unsigned, bool> encounteredStates;

  /* Used by the relay to keep track of the number of outstanding prefix requests
   * at each local worker. */
  PrefixBalancer *prefixBalancer = new PrefixBalancer(processCount);

  unsigned prefixCountForWorker;  

  while (true) {
    do_yield = true;

    /* Try reading from each communicator. */
    for (int i = 1; i < processCount; ++i) {
      message_count = comm.communicators[i]->receive_nonblocking(messages, ENDPOINT_RELAY);

      if (message_count > 0) {
        do_yield = false;
        for (int j = 0; j < message_count; ++j) {
          switch (messages[j].get_type()) {
          case MCMESSAGE_TYPE_DATA:
            data_message = (MCMessageData *) messages + j;
//            Log::log("IntraNode") << "Read hash: " << data_message->get_hash() << " from worker: " << i << Log::endl;
            if (!encounteredStates.containsKey(data_message->get_hash())) {
              handle_data_message(data_message, processCount);
              encounteredStates[data_message->get_hash()] = true;
              uniqueStateCount++;
            } else {
              duplicateStateCount++;
            }
            break;
          case MCMESSAGE_TYPE_PREFIX_REQUEST:
            prefix_request_message = (MCMessagePrefixRequest *) messages + j;
            handle_prefix_request(prefix_request_message, prefixBalancer);
            break;
          case MCMESSAGE_TYPE_PREFIX_REPLY:
            prefix_reply_message = (MCMessagePrefixReply *) messages + j;
            handle_prefix_reply(prefix_reply_message, prefixBalancer);
            break;
          case MCMESSAGE_TYPE_PREFIX_COUNT:
            prefix_count_message = (MCMessagePrefixCount *) messages + j;

            prefixCountForWorker = prefix_count_message->get_prefix_count();

            // Make sure we're not getting this from a goofy place
            ASSERT(prefix_count_message->get_from_node() == (unsigned) nodeRank);

            Log::log("prefixes") << "Setting worker " << i << "'s prefix count to " 
                               << prefixCountForWorker << Log::endl;

            comm.workerPrefixCounts[i] = prefix_count_message->get_prefix_count();
            break;
          default:
          Log::log("IntraNode") << "Encountered unknown message type " <<  messages[j].get_type() << Log::endl;
            ASSERT(false);
          }
        }
      }
    }

    if (comm.multiple_nodes) {
      //Log::log("InterNode") << "Checking for incoming off-node messages." << Log::endl;
      message_count = comm.offnode_in->receive_nonblocking(messages, ENDPOINT_INCOMING);
      //Log::log("InterNode") << "Found " << message_count << " off-node messages." << Log::endl;
      if (message_count > 0) {
        do_yield = false;

        for (int i = 0; i < message_count; i++) {
          switch(messages[i].get_type()) {
          case MCMESSAGE_TYPE_PREFIX_REQUEST:
            prefix_request_message = (MCMessagePrefixRequest *) messages + i;
            Log::log("MCTest") << "Received prefix request from node " << prefix_request_message->get_from_node() << Log::endl;
            handle_prefix_request(prefix_request_message, prefixBalancer);
            break;
          case MCMESSAGE_TYPE_PREFIX_REPLY:
            prefix_reply_message = (MCMessagePrefixReply *) messages + i;
            Log::log("MCTest") << "Received prefix reply from node " << prefix_reply_message->get_from_node() << Log::endl;
            handle_prefix_reply(prefix_reply_message, prefixBalancer);
            break;
          case MCMESSAGE_TYPE_DATA:
            data_message = (MCMessageData *) messages + i;
            if (!encounteredStates.containsKey(data_message->get_hash())) {
              handle_data_message(data_message, processCount);
              encounteredStates[data_message->get_hash()] = true;
              uniqueStateCount++;
            } else {
              duplicateStateCount++;
            }
            break;
          default:
            Log::log("InterNode") << "Encountered unknown message type " <<  messages[i].get_type() << Log::endl;
            ASSERT(false);
          }
        }
      }
    }

    if (do_yield) {
      SysUtil::sleepu(params::get<int>("RELAY_SLEEP_TIME", 1000));
    }
  }
}

void sigHandler(int sig) {
//   std::cerr << "received signal " << sig << " my pid=" << getpid() << std::endl;
  Log::log("Sim::printStats") << "Caught signal " << sig << Log::endl;
  Log::log("Sim::printStats") << "Unique states: " << uniqueStateCount << Log::endl;
  Log::log("Sim::printStats") << "Duplicate states: " << duplicateStateCount << Log::endl;

  if(sig == SIGINT && __Simulator__::randomUtil->handleInt()) {
    return;
  }

  /* Think of the children! */
  if (__Simulator__::getProcessRank() == 0) {
    for (unsigned i = 0; i < children.size(); ++i) {
      Log::log("Cleanup") << "Killing child " << i << " PID " << children[i] << Log::endl;
      if(kill(children[i], SIGTERM) == -1) {
        Log::log("Cleanup") << "Failed to kill invulnerable child " << i << " PID " << children[i] << Log::endl;
        perror("kill()");
      }

      // And now, for more desperate measures. SIGKILL: kills processes dead.

      if (kill(children[i], SIGKILL) == -1) {
        Log::log("Cleanup") << "Failed to nuke child " << i << " PID " << children[i] << ": it's like a cockroach!" << Log::endl;
        perror("kill()");
      }
    }
  }

  Log::enableLogging();
  Log::log("ERROR::SIM::SIGNAL") << "Caught Signal " << sig << ", terminating" << Log::endl;

/* Move along, nothing to see here ...
  if (defaultOutputFile != NULL && defaultOutputFile != stdout) {
    fclose(defaultOutputFile);
  }
*/
  __Simulator__::Error("SIGNAL");

  printf("PID %d: I'm a zombie!\n", getpid());
  exit(1);
}

void processPath(params::StringMap& paramCopy, int& num_nodes, int& num_dead_paths, MCTest *test, std::string& description, bool processDups) {
  ADD_SELECTORS("main");
  
  if(__Simulator__::randomUtil->next()) {
    __Simulator__::disableMonitor();
    Sim::printStats(__Simulator__::randomUtil->getPhase());
    __Simulator__::enableMonitor();
  }
  
  Sim::clearGusto();
  
  TestPropertyList propertiesToTest;
  ServiceList servicesToDelete;
  NodeServiceClassList servicesToPrint;
  SimApplicationServiceClass** appNodes = new SimApplicationServiceClass*[num_nodes];
  
  MonotoneTimeImpl::mt->reset();
  
  test->loadTest(propertiesToTest, servicesToDelete, servicesToPrint, appNodes, num_nodes);
  
  SimApplication::SetInstance(appNodes, servicesToPrint);
  
  if(__Simulator__::use_hash) {
    __Simulator__::initState();
  }
  
  if(__Simulator__::loggingStartStep > 0) {
    Log::disableLogging();
  }
  
  Sim::PathEndCause cause = Sim::TOO_MANY_STEPS;
  for(Sim::step = 0; Sim::step < Sim::maxStep; Sim::step++) {
    if(Sim::step == __Simulator__::loggingStartStep) {
      Log::enableLogging();
    }
    maceout << "Now on simulator step " << Sim::step << " (Rem, maxStep = " << Sim::maxStep << ")" << Log::endl;
    __Simulator__::signalMonitor();
    EventList readyEvents = __Simulator__::getReadyEvents();
    macedbg(0) << "Ready Events--size=" << readyEvents.size();
    if(readyEvents.size()) {
      macedbg(0) << std::endl << readyEvents;
    }
    macedbg(0) << Log::endl;
    if(readyEvents.size() > 0) {
      Event e = RandomUtil::random(readyEvents);
      try {
        __Simulator__::simulateNode(e);
      } catch(const Exception& e) {
        maceerr << "Uncaught Mace Exception " << e << Log::endl;
        ASSERT(0);
      } catch(const std::exception& se) {
        maceerr << "Uncaught std::exception " << se.what() << Log::endl;
        ASSERT(0);
      } catch(...) {
        maceerr << "Uncaught unknown throw" << Log::endl;
        ASSERT(0);
      }
      __Simulator__::dumpState();
      Sim::updateGusto();

      // Don't want to process duplicate states if we're doing some initial processing
      // to fill prefixes.
      if(processDups && __Simulator__::isDuplicateState()) {
        cause = Sim::DUPLICATE_STATE;
        break;
      }
      else if(__Simulator__::stoppingCondition(Sim::isLive, Sim::isSafe, propertiesToTest, description)) {
        cause = Sim::STOPPING_CONDITION;
        break;
      }
    } else {
      __Simulator__::stoppingCondition(Sim::isLive, Sim::isSafe, propertiesToTest, description);
      cause = Sim::NO_MORE_EVENTS;
      break;
    }
  }
  
  Sim::pathComplete(cause, Sim::isLive, Sim::isSafe, Sim::step, __Simulator__::randomUtil->pathDepth(), __Simulator__::randomUtil, description);
  
  //this could certainly move to Sim
  if(cause == Sim::NO_MORE_EVENTS && !Sim::isLive) {
    __Simulator__::Error(mace::string("NO_MORE_STEPS::")+description, ++num_dead_paths >= __Simulator__::max_dead_paths);
  } else if( cause == Sim::TOO_MANY_STEPS && __Simulator__::max_steps_error && !Sim::isLive ) {
    __Simulator__::Error(mace::string("MAX_STEPS::")+description, ++num_dead_paths >= __Simulator__::max_dead_paths);
  }
  
  for (int i = 0; i < num_nodes; i++) {
    appNodes[i]->maceExit();
  }
  
  for (size_t i = 0; i < servicesToDelete.size(); i++) {
    delete servicesToDelete[i];
  }
  
  SimScheduler::Instance().reset();
  SimNetwork::Instance().reset();
  SimApplication::reset();
  NumberGen::Reset();
  
  params::setParams(paramCopy);
  
  delete[] appNodes;
  
  for (size_t i = 0; i < propertiesToTest.size(); i++) {
    delete propertiesToTest[i];
  }
}

void finalize() {
  ADD_FUNC_SELECTORS;
  Log::enableLogging();
  Log::log("Cleanup") << "Simulation complete!" << Log::endl;
  __Simulator__::disableMonitor();
//  Sim::printStats(__Simulator__::randomUtil->getPhase() + " -- possibly incomplete");
  __Simulator__::enableMonitor();
  Log::log("Cleanup") << "Final RandomUtil State: " << *__Simulator__::randomUtil << Log::endl;
  __Simulator__::randomUtil->dumpState();
  
  Log::log("Cleanup") << "***falling out of main***\n" << Log::endl;

#ifdef MC_MPI

  if (__Simulator__::getProcessRank() == 0 && !comm.offnode_comm_method.compare("mpi")) {
    MPI_Finalize();
  }

#endif

}

void resetRandUtil() {
  ADD_FUNC_SELECTORS;
  // Reset the random number generator with our new prefix this time.
  // This really ought to be done in a less roundabout way.
  __Simulator__::randomUtil->reset();
  __Simulator__::initializeRandomUtil(false);
}

static void init_logging() {
  const char *outputFileName = "output";
  bool throttleSpammyLogs = params::get<int>("THROTTLE_SPAMMY_LOGS", 0) > 0;

  defaultOutputFile = fopen(outputFileName, "w+");

  Log::configure();
  Log::disableDefaultWarning();
  Log::disableDefaultError();
  //   LogSelectorTimestamp printTime = LOG_TIMESTAMP_HUMAN;
  LogSelectorTimestamp printTime = LOG_TIMESTAMP_DISABLED;
  LogSelectorThreadId printThreadId = LOG_THREADID_DISABLED;
  Log::add("ERROR",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::autoAdd(".*ERROR::SIM.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("SearchRandomUtil::next",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("SearchStepRandomUtil::next",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("BestFirstRandomUtil::next",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("HALT",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::autoAdd(".*monitor\\(void.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);

  if (!throttleSpammyLogs) {
    Log::add("Sim::pathComplete",defaultOutputFile,printTime,LOG_NAME_ENABLED);
  }

  // Log::add("prefixPushed",defaultOutputFile,printTime,LOG_NAME_ENABLED);
  Log::add("Sim::printStats",defaultOutputFile,printTime,LOG_NAME_ENABLED);
  //   Log::add("DEBUG::static bool __Simulator__::isDuplicateState()",defaultOutputFile,printTime,LOG_NAME_ENABLED);
  Log::autoAdd(".*LastNailRandomUtil::hasNext.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("LastNailRandomUtil::next",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::autoAdd(".*LastNailRandomUtil::dumpState.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  if(params::containsKey("TRACE_ALL")) {
    Log::autoAddAll(defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  }
  if(params::containsKey("TRACE_SIMULATOR")) {
    Log::add("BestFirstRandomUtil::hasNext",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("main",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    //     Log::autoAdd("Simulator");
    Log::add("__Simulator__::getReadyEvents",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*__Simulator__::isDuplicateState.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*__Simulator__::initState.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*simulateNode.*",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("SearchRandomUtil::randInt",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("SearchStepRandomUtil::randInt",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("BestFirstRandomUtil::randInt",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("LastNailRandomUtil::randInt",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("ReplayRandomUtil::randInt",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  }
  //    Log::add("hitState", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);

  /* Parallel MC log selectors. */
  if (!throttleSpammyLogs) {
    Log::add("MCTest", defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("Hash", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("InterNode", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("IntraNode", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("prefixes", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("PrefixBalancer", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("TransportCallback", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
  }

  Log::add("Init", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("Cleanup", defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  Log::add("Time", defaultOutputFile, printTime, LOG_NAME_ENABLED, printThreadId);

  Log::log("Init") << "PID: " << getpid() << Log::endl;

  if(params::containsKey("TRACE_SUBST")) {
    std::istringstream in(params::get<std::string>("TRACE_SUBST"));
    while(in) {
      std::string s;
      in >> s;
      if(s.length() == 0) { break; }
      Log::autoAdd(s,defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
    }
  }
  if(params::containsKey("TRACE_STATE")) {
    Log::autoAdd(".*__Simulator__::dumpState.*");
  }
  if(params::containsKey("TRACE_STEP")) {
    Log::add("main",defaultOutputFile,printTime,LOG_NAME_ENABLED,printThreadId);
  }
}

void init_local_communication(int processCount) {
  comm.communicators = new StateCommunicator<MCMessage> *[processCount];
  comm.local_comm_method = params::get<std::string>("LOCAL_COMM_METHOD", "unix");
  comm.local_buffer_size = params::get<int>("LOCAL_BUFFER_SIZE", 10);

  if (!comm.local_comm_method.compare("mmap")) {
    /* Use mmap backed shared memory. */
    for (int i = 0; i < processCount; ++i) {
      comm.communicators[i] = new StateCommunicatorMMAP<MCMessage>(comm.local_buffer_size, -1, -1, -1, -1);
    }
  } else if (!comm.local_comm_method.compare("unix")) {
    /* Unix domain sockets. */
    for (int i = 0; i < processCount; ++i) {
      comm.communicators[i] = new StateCommunicatorUnix<MCMessage>(comm.local_buffer_size, -1, -1, -1, -1);
    }
  } else {
    /* Error - invalid selection. */
    ASSERT(false);
  }

  /* Workers don't need to know anything about offnode communication. 
   * Relays will adjust these later as necessary. */
  comm.multiple_nodes = false;
  comm.offnode_in = NULL;
  comm.offnode_out = NULL;

  comm.workerPrefixCounts = new unsigned[processCount];

  for (int i = 0; i < processCount; i++) {
    comm.workerPrefixCounts[i] = 0;
  }
}

void init_offnode_communication(unsigned &nodeRank, unsigned &nodeCount, int argc, char **argv) {
  comm.offnode_comm_method = params::get<std::string>("OFFNODE_COMM_METHOD", "none");
  comm.offnode_buffer_size = params::get<int>("OFFNODE_BUFFER_SIZE", 300);
  unsigned line_buffer_size = params::get<unsigned>("NODE_FILE_LINE_BUFFER_SIZE", 256);

  if (!comm.offnode_comm_method.compare("none")) {
    /* Single-node */
    comm.multiple_nodes = false;
    comm.offnode_in = NULL;
    comm.offnode_out = NULL;
  } else if (!comm.offnode_comm_method.compare("tcp")) {
    comm.multiple_nodes = true;

    std::string simNodesSetting = params::get<std::string>("MACE_SIMULATE_NODES", "");
    params::erase("MACE_SIMULATE_NODES");

    if (!params::containsKey("NODE_FILE")) {
      ASSERT(false);
    }

    std::string nodeFileName = params::get<std::string>("NODE_FILE", "none");

    std::ifstream nodeFile(nodeFileName.c_str());
    
    char lineBuffer[line_buffer_size];

    while(nodeFile.getline(lineBuffer, line_buffer_size)) {
      nodeAddresses.push_back(new std::string(lineBuffer));
    }

    nodeFile.close();

    nodeCount = nodeAddresses.size();

    if (!params::containsKey("NODE_RANK")) {
      ASSERT(false);
    }

    nodeRank = params::get<unsigned>("NODE_RANK");

    unsigned incomingRank = (nodeRank - 1) % nodeCount;
    unsigned outgoingRank = (nodeRank + 1) % nodeCount;

    comm.offnode_out = new StateCommunicatorTcp<MCMessage>(comm.offnode_buffer_size, incomingRank, 0, outgoingRank, 0, *nodeAddresses[outgoingRank]);
    comm.offnode_in = comm.offnode_out;

    if (simNodesSetting != "") {
      params::set("MACE_SIMULATE_NODES", simNodesSetting);
    }
  } else if (!comm.offnode_comm_method.compare("mpi")) {

#ifdef MC_MPI
    unsigned incomingNodeRank;
    unsigned outgoingNodeRank;

    comm.multiple_nodes = true;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, (int *) &nodeRank);
    MPI_Comm_size(MPI_COMM_WORLD, (int *) &nodeCount);

    incomingNodeRank = (nodeRank - 1) % nodeCount;
    outgoingNodeRank = (nodeRank + 1) % nodeCount;

    comm.offnode_in = new StateCommunicatorMPI<MCMessage>(comm.offnode_buffer_size, MPI_COMM_WORLD, nodeRank, incomingNodeRank);
    comm.offnode_out = new StateCommunicatorMPI<MCMessage>(comm.offnode_buffer_size, MPI_COMM_WORLD, nodeRank, outgoingNodeRank);

#else

    /* MPI requested, but support for MPI wasn't compiled in. */
    ASSERT(false);

#endif

  } else {
    /* Error - invalid selection. */
    ASSERT(false);
  }
}

/* Bootstraps TCP communication between nodes.

   This process is a gigantic kludge that assumes that nodes are initialized in reverse 
   order by ID.

   All nodes except nodeCount - 1: send MCMessageNodeReady to your successor and 
   forward all MCMessageNodeReady messages you receive. Once all MCMessageNodeReady 
   messages have been received, it's safe to begin.

   nodeCount - 1: count the number of MCMessageNodeReady messages you receive. Send 
   MCMessageNodeReady to your successor once all nodes have sent MCMessageNodeReady to 
   you.
 */

void bootstrapTcp() {
  unsigned nodeRank = __Simulator__::getNodeRank();
  unsigned nodeCount = __Simulator__::getNodeCount();

  MCMessageNodeReady *myNodeReadyMsg = new MCMessageNodeReady(nodeRank);
  MCMessageNodeReady *incomingNodeReadyMsg;

  StateCommunicator<MCMessage> *communicator = comm.offnode_out;
  unsigned count = 0;

  int local_buffer_size = params::get<int>("LOCAL_BUFFER_SIZE", 10);
  MCMessage *messages = new MCMessage[local_buffer_size];
  bool amLastNode = nodeRank == nodeCount - 1;
  unsigned from_node;


  if (!amLastNode) {
    Log::log("Init") << "Sending my ready message" << Log::endl;

    communicator->put(myNodeReadyMsg, ENDPOINT_OUTGOING);
    communicator->deliver(ENDPOINT_OUTGOING);
  }

  while (true) {
    Log::log("Init") << "Waiting on messages ..." << Log::endl;
    
    count = communicator->receive(messages, ENDPOINT_INCOMING);
    
    Log::log("Init") << "Received " << count << " messages" << Log::endl;

    for (unsigned i = 0; i < count; i++) {
      if (messages[i].get_type() != MCMESSAGE_TYPE_NODE_READY) {
        Log::log("Init") << "Got message of type " << messages[i].get_type() << Log::endl;
        ASSERT(false);
      } else {
        incomingNodeReadyMsg = (MCMessageNodeReady *) messages + i;

        from_node = incomingNodeReadyMsg->get_from_node();

        if (from_node != nodeRank && !amLastNode) {
          Log::log("Init") << "Forwarding message from " << from_node << Log::endl;
          communicator->put(incomingNodeReadyMsg, ENDPOINT_OUTGOING);
          communicator->deliver(ENDPOINT_OUTGOING);
        }

        if (amLastNode && from_node == 0) {
          Log::log("Init") << "Last node sending message" << Log::endl;
          communicator->put(myNodeReadyMsg, ENDPOINT_OUTGOING);
          communicator->deliver(ENDPOINT_OUTGOING);
        }

        if (from_node == nodeCount - 1) {
          return;
        }
      }
    }
  }
}

// Prefix searching requires that certain parameters be set to maximize the search's determinism
// and efficacy. This method sets those parameters appropriately.
void saveAndClearPrefixSearchParams(int &oldSearchDepth, int *oldNetErrorSettings) {
  oldSearchDepth = params::get<int>("SEARCH_DEPTH", 1);
  params::set("SEARCH_DEPTH", "1");

  oldNetErrorSettings[0] = params::get<int>("USE_UDP_REORDER",0);
  oldNetErrorSettings[1] = params::get<int>("USE_UDP_ERRORS",0);
  oldNetErrorSettings[2] = params::get<int>("USE_NET_ERRORS",0);
  oldNetErrorSettings[3] = params::get<int>("SIM_NODE_FAILURE",0);

  params::set("USE_UDP_REORDER", "0");
  params::set("USE_UDP_ERRORS", "0");
  params::set("USE_NET_ERRORS", "0");
  params::set("SIM_NODE_FAILURE", "0");
}

// Restores parameters set by saveAndClearSearchParameters to their previous values.
void restorePrefixSearchParams(int oldSearchDepth, int *oldNetErrorSettings) {
  std::ostringstream depthStream;
  depthStream << oldSearchDepth;
  
  params::set("SEARCH_DEPTH", depthStream.str());

  if (oldNetErrorSettings[0]) {
    params::set("USE_UDP_REORDER", "1");
  }

  if (oldNetErrorSettings[1]) {
    params::set("USE_UDP_ERRORS", "1");
  }

  if (oldNetErrorSettings[2]) {
    params::set("USE_NET_ERRORS", "1");
  }

  if (oldNetErrorSettings[3]) {
    params::set("SIM_NODE_FAILURE", "1");
  }
}

// Calculates prefixes. Returns false if we exceed the max number of paths before gathering
// all prefixes, true otherwise. 
bool calculatePrefixes(unsigned maxPaths, params::StringMap &paramCopy, MCTest *test) {
  int nodeRank = __Simulator__::getNodeRank();
  int nodeCount = __Simulator__::getNodeCount();
  int processRank = __Simulator__::getProcessRank();
  int processCount = __Simulator__::getProcessCount();
  int num_dead_paths = 0;
  int num_nodes = __Simulator__::num_nodes;
  mace::string description;

  StateCommunicator<MCMessage> *communicator;
  MCMessagePrefixCount *countMsg;

  Log::log("main") << "Starting prefix gathering" << Log::endl;

  unsigned numPrefixesNeeded = nodeCount * (processCount - 1) * params::get<int>("PREFIX_OVERPROVISION", 2);

  __Simulator__::randomUtil->enablePrefixLogging();
  __Simulator__::disableDuplicateChecking();

  do {
    Log::log("prefixes") << "Processing a path" << Log::endl;
    processPath(paramCopy, num_nodes, num_dead_paths, test, description, __Simulator__::shouldCheckForDuplicates());
  } while(Sim::getPathNum() < maxPaths && __Simulator__::randomUtil->hasNext(Sim::isLive) && __Simulator__::randomUtil->numPrefixes() < (numPrefixesNeeded));

  Log::log("prefixes") << "Done calculating prefixes! Got " << __Simulator__::randomUtil->numPrefixes()  << ", needed " << (numPrefixesNeeded)  << Log::endl;

  __Simulator__::randomUtil->disablePrefixLogging();
  __Simulator__::enableDuplicateChecking();

  unsigned numPrefixes = __Simulator__::randomUtil->numPrefixes();
  
  if (numPrefixes < numPrefixesNeeded) {
    // We hit the end of the simulation before we could get enough prefixes.
    
    return false;
  }

  Log::log("prefixes") << "Gathered enough prefixes (" << "needed " << numPrefixesNeeded << ", got " << numPrefixes << ") to parallelize!" << Log::endl;
 
  // Get list of prefixes accumulated in the previous do ... while loop
  // FIXME: This list ought to be freed
  PrefixList prefixList;
  __Simulator__::randomUtil->prefixes(prefixList);
 
  resetRandUtil();
 
  // Assign prefixes to this worker.
  
  int workerProcessCount = processCount - 1;
  int workerProcessRank = processRank - 1;
  
  int numPrefixesAssigned = 0;

  int searchDepth = params::get<int>("SEARCH_DEPTH");
  for (unsigned i = workerProcessCount * nodeRank + workerProcessRank; i < numPrefixes; i += (workerProcessCount * nodeCount)) {
    UIntList& currentPrefix = *prefixList[i];
    
    Log::log("prefixes") << "Process " << processRank << " Node " << nodeRank << ": prefix " << i << ": " << currentPrefix  << Log::endl;
    
    __Simulator__::randomUtil->addPathPrefix(currentPrefix, searchDepth);
    numPrefixesAssigned++;
  }

  // Send my prefix count to the relay

  Log::log("prefixes") << "Sending my prefix count to the relay" << Log::endl;
  communicator = __Simulator__::getCommunicator();

  countMsg = new MCMessagePrefixCount(nodeRank, processRank, numPrefixesAssigned);

  communicator->put(countMsg, ENDPOINT_WORKER);
  communicator->deliver(ENDPOINT_WORKER);

  return true;
}

void chdirToRootDir() {
  std::string rootDir = params::get<std::string>("OUTPUT_ROOT_DIR", ".");

  niceMkdir(rootDir.c_str());

  if (chdir(rootDir.c_str()) != 0) {
    perror("chdir(root)");
  }
}

void setNodeInfo(unsigned processRank, unsigned processCount, unsigned nodeRank, unsigned nodeCount) {
  __Simulator__::setProcessCount(processCount);
  __Simulator__::setProcessRank(processRank);
  __Simulator__::setNodeCount(nodeCount);
  __Simulator__::setNodeRank(nodeRank);
}

void chdirToChildDir() {
  std::ostringstream outDirStream;
  int nodeRank = __Simulator__::getNodeRank();
  int processRank = __Simulator__::getProcessRank();

  outDirStream << "output_" << nodeRank << "_" << processRank;

  const char *outDir = outDirStream.str().c_str();

  niceMkdir(outDir);

  if (chdir(outDir) != 0) {
    perror("chdir(child)");
  }
}

int main(int argc, char **argv)
{
  unsigned nodeRank, nodeCount, processRank, processCount;

  int num_nodes;
  int num_dead_paths;
  unsigned maxPaths;
  mace::string description;

  int oldSearchDepth;
  int oldNetErrorSettings[4];

  pthread_mutex_init(&outOfPrefixesLock, NULL);
  pthread_cond_init(&prefixReceived, NULL);

  // First load running parameters
  params::addRequired("num_nodes", "Number of nodes to simulate");
  params::addRequired("CHECKED_SERVICE", "Which service string to use");
  params::addRequired("PROCESSES_PER_NODE", "Number of model checker processes to run (per compute node)");
  params::loadparams(argc, argv);
  params::set("MACE_SIMULATE_NODES", "MaceMC");
  params::set("MACE_ADDRESS_ALLOW_LOOPBACK", "1");
  params::set("MACE_LOCAL_ADDRESS", "localhost");
  params::print(stdout);

  saveAndClearPrefixSearchParams(oldSearchDepth, oldNetErrorSettings);

  // chdir to the root directory, if specified
  chdirToRootDir();

  nodeRank = 0;
  nodeCount = 1;
  processRank = 0;
  processCount = params::get("PROCESSES_PER_NODE", 3);

  init_local_communication(processCount);

  for (unsigned i = 1; i < processCount; ++i) {
    pid_t child_pid = fork();
    if (child_pid) {
      /* Parent - continue loop. */
      children.push_back(child_pid);
    } else {
      /* Child - set rank and break loop. */
      processRank = i;
      break;
    }
  }

  /* Initialize off-node communication and distribute node rank info to workers. */
  if (processRank == 0) {
    init_offnode_communication(nodeRank, nodeCount, argc, argv);
    setNodeInfo(processRank, processCount, nodeRank, nodeCount);
    chdirToChildDir();
    init_logging();

    if (comm.multiple_nodes && params::get<std::string>("OFFNODE_COMM_METHOD", "none") == "tcp") {
      Log::log("Init") << "Starting TCP bootstrapping process" << Log::endl;
      bootstrapTcp();
      Log::log("Init") << "TCP bootstrapping process complete" << Log::endl;
    }
    
    MCMessageNodeInfo *procInfo = new MCMessageNodeInfo(nodeRank, processRank, nodeRank, nodeCount);

    for (unsigned i = 1; i < processCount; i++) {
      comm.communicators[i]->put(procInfo, ENDPOINT_RELAY);
      comm.communicators[i]->deliver(ENDPOINT_RELAY);
    }

    delete procInfo;
  } else {
    MCMessageNodeInfo *procInfo = new MCMessageNodeInfo(0, 0, 0, 0);

    ASSERT(comm.communicators[processRank]->receive(procInfo, ENDPOINT_WORKER) == 1);

    nodeRank = procInfo->get_node_rank();
    nodeCount = procInfo->get_node_count();

    setNodeInfo(processRank, processCount, nodeRank, nodeCount);
    chdirToChildDir();
    init_logging();

    delete procInfo;
  }

  __Simulator__::setCommunicator(comm.communicators[processRank]);

  BaseMaceService::_printLower = false;
  SysUtil::signal(SIGABRT, sigHandler);
  SysUtil::signal(SIGINT, sigHandler);
  SysUtil::signal(SIGTERM, sigHandler);

  Log::log("Init") << "Registered tests: " << MCTest::getRegisteredTests() << Log::endl;
  MCTest* test = MCTest::getTest(params::get<std::string>("CHECKED_SERVICE"));
  if (test == NULL) {
    Log::err() << "Invalid checked service type " << params::get<std::string>("CHECKED_SERVICE") << " specified!" << Log::endl;
    ASSERT(0);
  }

  // Make sure the running scheduler is our simulator one.
  SimScheduler::Instance();
  __Simulator__::initializeVars();

  // Make sure we've loaded the prefix checker for this phase.
  ASSERT(dynamic_cast<PrefixSearcherRandomUtil*>(__Simulator__::randomUtil) != 0);
  
  if (processRank == 0) {
    Log::log("Init") << "Starting relay_receiveUpdates()." << Log::endl;

    Accumulator::startLogging();

    relay_receiveUpdates();
  } else {
    if(__Simulator__::divergenceMonitor) {
      pthread_t tid;
      runNewThread(&tid, monitor, NULL, NULL);
    }

    pthread_t receiver_tid;
    runNewThread(&receiver_tid, receiveUpdates, (void *) comm.communicators[processRank], NULL);

    num_nodes = __Simulator__::num_nodes;
    base_port = params::get("MACE_PORT", 5377);
    mace::MonotoneTimeImpl::mt = macemc::MonotoneTimeImpl::mt = new MonotoneTimeImpl(num_nodes);
    Sim::init(num_nodes);
    nodeString = new std::string[num_nodes];
    Sim::maxStep = params::get("max_num_steps", UINT_MAX);
    SimNetwork::SetInstance(base_port);

    params::StringMap paramCopy = params::getParams();

    for(int i = 0; i < num_nodes; i++) {
      nodeString[i] = boost::lexical_cast<std::string>(i);
    }

    __Simulator__::logAddresses();
    maxPaths = (params::containsKey("MAX_PATHS")?params::get<int>("MAX_PATHS"):UINT_MAX);

    // Calculate prefixes
    if (!calculatePrefixes(maxPaths, paramCopy, test)) {
      if (defaultOutputFile != stdout) {
        fclose(defaultOutputFile);
      }
      finalize();
      return 0;
    }

    restorePrefixSearchParams(oldSearchDepth, oldNetErrorSettings);

    num_dead_paths = 0;

    Log::log("main") << "Starting simulation" << Log::endl;
    Log::log("Time") << "Start time: " << TimeUtil::time() << Log::endl;

    while (true) {
      do {
        processPath(paramCopy, num_nodes, num_dead_paths, test, description, __Simulator__::shouldCheckForDuplicates());
      } while(Sim::getPathNum() < maxPaths && __Simulator__::randomUtil->hasNext(Sim::isLive));

      // Quit if we've exceeded the max number of paths.
      if (Sim::getPathNum() >= maxPaths) {
        Log::log("prefixes") << "Exceeded max number of paths!" << Log::endl;
        break;
      }

      __Simulator__::disableMonitor();
      Log::log("prefixes") << "Finished all prefixes! Waiting for more." << Log::endl;
      Log::log("Time") << "Out of work: " << TimeUtil::time() << Log::endl;
      pthread_mutex_lock(&outOfPrefixesLock);
      
      StateCommunicator<MCMessage> *communicator = __Simulator__::getCommunicator();
      MCMessagePrefixRequest *requestMsg = new MCMessagePrefixRequest(nodeRank, processRank, nodeRank, 0, 1);

      communicator->put(requestMsg, ENDPOINT_WORKER);
      communicator->deliver(ENDPOINT_WORKER);

      pthread_cond_wait(&prefixReceived, &outOfPrefixesLock);
      pthread_mutex_unlock(&outOfPrefixesLock);
      Log::log("prefixes") << "Received a new prefix; resuming search" << Log::endl;
      __Simulator__::enableMonitor();
    }
  }
  
  if (defaultOutputFile != stdout) {
    fclose(defaultOutputFile);
  }
  finalize();
  return 0;
}

/* vim: set ts=2 sw=2: */
