/* 
 * SimulatorTCP.cc : part of the Mace toolkit for building distributed systems
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
#include "Util.h"
#include "Log.h"
#include "SimulatorTCP.h"
#include "BaseTransport.h"
#include "Pipeline.h"
#include "NumberGen.h"
#include "MaceTime.h"
#include "Accumulator.h"
#include "mace_constants.h"
#include "MaceTypes.h"
#include "mace-macros.h"

using std::string;

int SimulatorTCP_load_protocol()
{
  return 0;
}

namespace SimulatorTCP_namespace {

// int TCPService::PT_tcp;

void SimulatorTCPService::printSocketState() const {
  ADD_SELECTORS("SimulatorTCPService::printSocketState");
  maceout << "localNode=" << localNode << " forwarder=" << forwarder
	  << " localPort=" << localPort
	  << Log::endl;

  for (int i = 0; i < Sim::getNumNodes(); i++) {
    maceout << "openSockets[" << i << "]=" << openSockets[i]
	    << " remoteErrors[" << i << "]=" << remoteErrors[i]
	    << " localErrors[" << i << "]=" << localErrors[i]
	    << Log::endl;
  }
}

SimulatorTCPService::SimulatorTCPService(int queue_size, int port,
					 int node, bool messageErrors,
					 int fw) :
  queueSize(queue_size), localPort(port), localNode(node),
  upcallMessageErrors(messageErrors),
  forwarder(fw),
  net(SimNetwork::Instance()),
  listening(false),
  stats(new BufferStatistics(BaseTransport::DEFAULT_WINDOW_SIZE)),
  queuedMessages(Sim::getNumNodes()), openSockets(Sim::getNumNodes()),
  remoteErrors(Sim::getNumNodes()), localErrors(Sim::getNumNodes()) {
  ADD_SELECTORS("TCP::constructor");

  ASSERT(forwarder != node);
  if (forwarder < 0) {
    forwarder = localNode;
  }

  maceout << "local_address " << Sim::getMaceKey(localNode) << " port " << localPort << " queue_size " << queue_size << Log::endl;
  net.registerHandler(port, *this);
}

void SimulatorTCPService::maceInit() { 
  listening = true;
}

bool SimulatorTCPService::isListening() {
  return listening;
}

void SimulatorTCPService::maceReset() {
  ADD_SELECTORS("SimulatorTCPService::maceReset");
  listening = false;
  handlers.clear();
  network_handlers.clear();

//   maceout << "reseting" << Log::endl;
//   printSocketState();
  
  for(int i = 0; i < Sim::getNumNodes(); i++) {
    if(openSockets[i]) {
      if(i == localNode) {
        clearQueue(i, 0, false);
        remoteErrors[i] = false;
        localErrors[i] = false;
      } else if(localErrors[i]) {
        if(remoteErrors[i]) {
          // 1,1,1,1,1,1
          clearQueue(i, 0, false);
          net.signal(localNode, i, localPort, SimulatorTransport::SOURCE_RESET);
          remoteErrors[i] = false;
        } else {
          // 1,0,1,0,1,1
          ASSERT(0);
        }
      } else {
        if(remoteErrors[i]) {
          // 0,1,1,1,0,0
          clearQueue(i, 0, false);
          net.signal(localNode, i, localPort, SimulatorTransport::SOURCE_RESET);
          remoteErrors[i] = false;
        } else {
          // 0,0,1,0,0,1
          clearQueue(i, 0, false);
          localErrors[i] = true;
          net.signal(localNode, i, localPort, SimulatorTransport::SOURCE_RESET);
          uint32_t msgId = net.getMessageId();
          queuedMessages[i].push_front(SimulatorMessage(localNode, i, forwarder, forwarder, msgId, SimulatorMessage::READ_ERROR, -1, ""));
        }
      }
    } else {
      if(localErrors[i]) {
        if(remoteErrors[i]) {
          // 1,1,0,1,1,0
          ASSERT(0);
        } else {
          // 1,0,0,0,1,1
          clearQueue(i, 0, false);
        }
      } else {
        if(remoteErrors[i]) {
          // 0,1,0,1,0,0
          ASSERT(0);
        } else {
          // 0,0,0,0,0,0
          clearQueue(i, 0, false);
        }
      }
    }
  }
}

registration_uid_t SimulatorTCPService::registerHandler(ReceiveDataHandler& handler, registration_uid_t handlerUid) {
  if(handlerUid == -1) {
    handlerUid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
  }
  handlers[handlerUid] = &handler;
  return handlerUid;
}

registration_uid_t SimulatorTCPService::registerHandler(ConnectionStatusHandler& handler, registration_uid_t handlerUid) {
  if(handlerUid == -1) {
    handlerUid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
  }
  connectionHandlers[handlerUid] = &handler;
  return handlerUid;
}

registration_uid_t SimulatorTCPService::registerHandler(NetworkErrorHandler& handler, registration_uid_t handlerUid) {
  if(handlerUid == -1) {
    handlerUid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
  }
  network_handlers[handlerUid] = &handler;
  return handlerUid;
}

void SimulatorTCPService::requestToSend(const MaceKey& dest, registration_uid_t rid) {
  rtsRequests[Sim::getNode(dest)].push_back(rid);
}

bool SimulatorTCPService::routeRTS(const MaceKey& dest, const std::string& s, registration_uid_t rid) {
  bool r = route(dest, s, rid);
  if (!r) {
    rtsRequests[Sim::getNode(dest)].push_back(rid);
  }
  return r;
}

void SimulatorTCPService::requestFlushedNotification(registration_uid_t rid) {
  flushRequests.insert(rid);
}

  std::string SimulatorTCPService::simulateFlushed() {
    for (RegSet::const_iterator i = flushRequests.begin(); i != flushRequests.end(); i++) {
      ConnectionHandlerMap::iterator k = connectionHandlers.find(*i);
      ASSERT(k != connectionHandlers.end());
      k->second->notifyFlushed(*i);
    }
    flushRequests.clear();
    return "";
  }

  std::string SimulatorTCPService::simulateCTS(int node) {
    RegList& l = rtsRequests[node];
    registration_uid_t rid = l.front();
    l.pop_front();
    ConnectionHandlerMap::iterator k = connectionHandlers.find(rid);
    ASSERT(k != connectionHandlers.end());
    k->second->clearToSend(Sim::getMaceKey(node), rid);
    return "";
  }

  bool SimulatorTCPService::hasFlushed() {
    size_t s = 0;
    for (MessageQueueMap::const_iterator i = queuedMessages.begin(); i != queuedMessages.end(); i++) {
      s += i->size();
    }

    return !flushRequests.empty() && s == 0;
  }

  bool SimulatorTCPService::hasCTS(int node) {
    if (!rtsRequests[node].empty()) {
      MessageQueue& mqueue = queuedMessages[node];
      if(mqueue.size() < queueSize) {
	return true;
      }
    }
    return false;
  }

bool SimulatorTCPService::route(const MaceKey& dest, const string& s, registration_uid_t handlerUid) {
  return route(Sim::getMaceKey(localNode), dest, s, handlerUid);
}

bool SimulatorTCPService::route(const MaceKey& src, const MaceKey& dest, const string& s, registration_uid_t handlerUid) {
  ADD_SELECTORS("SIMULATOR::TCP::route::pkt::(downcall)");
  maceout << "src=" << src << " dest=" << dest.toString() << " size=" << s.size() << " priority=" << 0 << " handlerUid=" << handlerUid << " port=" << localPort << Log::endl;
  uint32_t msgId = net.getMessageId();
  int destNode = Sim::getNode(dest);
  int destQueue = forwarder;
  MaceKey nextHop = dest;
  if (destQueue == localNode) {
    // no forwarder defined
    destQueue = destNode;
  }
  else {
    // send to forwarder
    nextHop = Sim::getMaceKey(destQueue);
  }

  int srcNode = Sim::getNode(src);
  
  MessageQueue& mqueue = queuedMessages[destQueue];
  if(mqueue.size() < queueSize) {
    maceout << "route([dest=" << nextHop << "][s_deserialized=pkt(id=" << msgId << ")])" << Log::endl;
    Log::binaryLog(selectorId->log,
		   LogicalClockPipeline::MessageId(msgId, 0, 0), 0);
    mqueue.push_back(SimulatorMessage(srcNode, destNode, forwarder, destQueue, msgId, SimulatorMessage::MESSAGE, handlerUid, s));
    return true;
  }
  maceout << "route([dest=" << nextHop << "][s_deserialized=pkt(id=" << msgId << ", SIM_DROP=1)])" << Log::endl;
  return false;
}

uint32_t SimulatorTCPService::outgoingBufferedDataSize(const MaceKey& peer, registration_uid_t registrationUid) {
  return 0;
}

const BufferStatisticsPtr SimulatorTCPService::getStatistics(const MaceKey& peer, Connection::type d, registration_uid_t registrationUid) {
  return stats;
}

bool SimulatorTCPService::canSend(const MaceKey& peer, registration_uid_t registrationUid) {
  int destNode = Sim::getNode(peer);
  
  return (queuedMessages[destNode].size() < queueSize);
}

bool SimulatorTCPService::isAvailableMessage(int destNode) {
  std::deque<SimulatorMessage>& deque = queuedMessages[destNode];
  return !deque.empty() && (localErrors[destNode] || !remoteErrors[destNode]);
}

SimulatorMessage SimulatorTCPService::getMessage(int destNode) {
  ASSERT(isAvailableMessage(destNode));
  SimulatorMessage str = *queuedMessages[destNode].begin();
  if(str.messageType == SimulatorMessage::MESSAGE) {
    openSockets[destNode] = true;
  }
  else if(str.messageType == SimulatorMessage::READ_ERROR) {
    localErrors[destNode] = false;
  }
  queuedMessages[destNode].pop_front();
  return str;
}

int SimulatorTCPService::getPort() { return localPort; }
MaceKey SimulatorTCPService::getLocalAddress(registration_uid_t regId) const { 
  ADD_FUNC_SELECTORS;
  maceLog("called getLocalAddress\n");
  return Sim::getMaceKey(forwarder);
}

std::string SimulatorTCPService::simulateEvent(const SimulatorMessage& msg) {
  ASSERT(msg.destination == localNode || msg.forwarder == localNode);
  if(msg.messageType == SimulatorMessage::MESSAGE) {
    recv(msg);
  } else if(msg.messageType == SimulatorMessage::DEST_NOT_READY) {
    ASSERT(!openSockets[msg.source]);
    transport_error(msg.source, TransportError::CONNECT_ERROR);
  } else { //msg.messageType == READ_ERROR 
    ASSERT(openSockets[msg.source]);
    ASSERT(remoteErrors[msg.source]);
    remoteErrors[msg.source] = false;
    transport_error(msg.source, TransportError::READ_ERROR);
  }
  return "";
}

void SimulatorTCPService::recv(const SimulatorMessage& msg) {
  static int netErrorWeight = params::get("NET_ERROR_WEIGHT", 0);
  static int numFailures = params::get("SIM_NUM_NET_ERRORS", 0);
  ADD_SELECTORS("SimulatorTCPService::recv::pkt");
  maceout << "from=" << Sim::getMaceKey(msg.source).toString() << " dsize=" << msg.msg.size() << Log::endl;
  int src = msg.forwarder;
  if (msg.forwarder == localNode) {
    src = msg.source;
  }
  openSockets[src] = true;
  if(!(remoteErrors[src] || localErrors[src]) && src != localNode && (numFailures < 0 || SimNetwork::getFailureCount() < numFailures)) { 
    maceout << "Socket error following message between " << localNode << " and dest " << msg.source << " on port " << localPort << "? (0-no, 1-yes) " << Log::endl;
    if(RandomUtil::randInt(2, 100, netErrorWeight)) { //In search mode, either error or non-error may occur.  In gusto mode, no errors may occur
      maceerr << "Note: message followed by error between " << localNode << " and dest " << src << " on port " << localPort << Log::endl;
      signal(src, SimulatorTransport::BIDI_READ_ERROR);
      net.signal(localNode, src, localPort, SimulatorTransport::BIDI_READ_ERROR);
      SimNetwork::incrementFailureCount();
    }
  } else {
    macedbg(1) << "Not considering read error: localError " << localErrors[src] << " remoteErrors " << remoteErrors[src] << " numFailures " << numFailures << Log::endl;
  }
  ReceiveHandlerMap::iterator i = handlers.find(msg.regId);
  if(i == handlers.end()) { macewarn << "Could not find handler with id " << msg.regId << " for message " << msg.messageId << " : dropping packet" << Log::endl; return; }
  mace::LogicalClock& inst = mace::LogicalClock::instance();
  inst.setMessageId(msg.messageId);
  i->second->deliver(Sim::getMaceKey(msg.source), Sim::getMaceKey(msg.destination), msg.msg, msg.regId);
}

void SimulatorTCPService::signal(int other, SimulatorTransport::TransportSignal sig) {
  ADD_SELECTORS("SimulatorTCPService::signal");

//   maceout << "other=" << other << Log::endl;
//   printSocketState();

  switch(sig) {
    case SimulatorTransport::SOURCE_RESET:
      {
        if(localErrors[other]) {
          ASSERT(!queuedMessages[other].empty());
          ASSERT(queuedMessages[other].front().messageType == SimulatorMessage::READ_ERROR);
          queuedMessages[other].pop_front();
          localErrors[other] = false;
        }
        else {
          ASSERT(openSockets[other] && !remoteErrors[other]);
          remoteErrors[other] = true;
        }
        break;
      }
    case SimulatorTransport::BIDI_READ_ERROR:
      {
        uint32_t msgId = net.getMessageId();
        maceout << "Simulator pushing back message " << msgId << " as READ_ERROR from " << localNode << " to " << other << Log::endl;
        queuedMessages[other].push_front(SimulatorMessage(localNode, other, forwarder, forwarder, msgId, SimulatorMessage::READ_ERROR, -1, ""));
        remoteErrors[other] = true;
        localErrors[other] = true;
        ASSERT(openSockets[other]);
        break;
      }
  }
}

void SimulatorTCPService::clearQueue(int destNode, int transportError, bool upcallError) {
  openSockets[destNode] = false;
  MessageQueue& mqm = queuedMessages[destNode];
  if(mqm.empty()) { return; }
  MessageQueue::iterator it = mqm.begin(); 
  if((*it).messageType != SimulatorMessage::MESSAGE) {
    it++;
  }
  if (upcallMessageErrors && upcallError) {
    MessageQueue::iterator it2 = it;
    while (it2 != mqm.end()) {
      SimulatorMessage& m = *it2;
      ASSERT(m.destination == destNode || m.nextHop == destNode);
      ASSERT(m.messageType == SimulatorMessage::MESSAGE);
      NetworkErrorHandler* handler = network_handlers[m.regId];
      handler->messageError(Sim::getMaceKey(destNode), transportError,
			    m.msg, m.regId);
      it2++;
    }
  }
  mqm.erase(it, mqm.end());
}

void SimulatorTCPService::transport_error(const int& destNode, int transportError) {
  //XXX: Not capturing the possibility of interleavings!
  clearQueue(destNode, transportError, true);
  NetworkHandlerMap::iterator i;
  for(i = network_handlers.begin(); i != network_handlers.end(); i++) {
    NetworkErrorHandler* handler = i->second;
    handler->error(Sim::getMaceKey(destNode), transportError, "error", i->first);
  }
}

uint32_t SimulatorTCPService::hashState() const {
  static uint32_t hashAnd = (queueSize + localPort) * localNode;
  static hash_string strHasher;
  uint32_t hashWork = hashAnd;
  for(ReceiveHandlerMap::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
    hashWork = (hashWork << 1) ^ i->first;
  }
  for(NetworkHandlerMap::const_iterator i = network_handlers.begin(); i != network_handlers.end(); i++) {
    hashWork = (hashWork << 1) ^ i->first;
  }
  int node;
  MessageQueueMap::const_iterator i;
  for(i = queuedMessages.begin(), node = 0; i != queuedMessages.end(); i++, node++) {
    hashWork += node;
    for(MessageQueue::const_iterator j = i->begin(); j != i->end(); j++) {
      hashWork ^= strHasher((*j).msg);
    }
  }
  return hashWork;
}

void SimulatorTCPService::print(std::ostream& out) const {
  //This stuff is staticish -- can be printed with node
  out << "[SimulatorTCP]" << std::endl;
  out << "[queueSize = " << queueSize << "][localPort = " << localPort << "][localKey = " << Sim::getMaceKey(localNode) << "]" << std::endl;
  out << "[RDH] ";
  for(ReceiveHandlerMap::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
    out << i->first << " ";
  }
  out << "[/RDH]" << std::endl;
  out << "[NEH] ";
  for(NetworkHandlerMap::const_iterator i = network_handlers.begin(); i != network_handlers.end(); i++) {
    out << i->first << " ";
  }
  out << "[/NEH]" << std::endl;
  out << "[socket state]" ;
  for(int i = 0; i < Sim::getNumNodes(); i++) {
    out << "[node " << i << "] " << localErrors[i] << "," << remoteErrors[i] << "," << openSockets[i] << " [/node " << i << "]";
  }
  out << "[/socket state]" << std::endl;
  out << "[/SimulatorTCP]" << std::endl;
}

void SimulatorTCPService::printState(std::ostream& out) const {
  //This stuff is staticish -- can be printed with node
  out << "[queueSize = " << queueSize << "][localPort = " << localPort << "][localKey = " << Sim::getMaceKey(localNode) << "]";
  out << "[RDH] ";
  for(ReceiveHandlerMap::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
    out << i->first << " ";
  }
  out << "[/RDH]";
  out << "[NEH] ";
  for(NetworkHandlerMap::const_iterator i = network_handlers.begin(); i != network_handlers.end(); i++) {
    out << i->first << " ";
  }
  out << "[/NEH]";
  //Do not print messages during state print -- they are printed under printNetworkState
}

void SimulatorTCPService::printNetwork(std::ostream& out) const {
  //This stuff is the network state, not node state (can be changed by other nodes in the network
//   out << "socketState:" << std::endl;
//   out << "localNode=" << localNode << " forwarder=" << forwarder
// 	  << " localPort=" << localPort
// 	  << std::endl;

//   for (int i = 0; i < Sim::getNumNodes(); i++) {
//     out << "openSockets[" << i << "]=" << openSockets[i]
// 	<< " remoteErrors[" << i << "]=" << remoteErrors[i]
// 	<< " localErrors[" << i << "]=" << localErrors[i]
// 	<< std::endl;
//   }

  out << "[messages]";
  int node;
  MessageQueueMap::const_iterator i;
  for(i = queuedMessages.begin(), node = 0; i != queuedMessages.end(); i++, node++) {
    if(i->size()) {
      out << "[toDest(" << node << ")] ";
      for(MessageQueue::const_iterator j = i->begin(); j != i->end(); j++) {
        out << (*j).messageId << "::" << (*j).messageType << " ";
      }
      out << "[/toDest(" << node << ")]";
    }
  }
  out << "[/messages]";
}
void SimulatorTCPService::printNetworkState(std::ostream& out) const {
  //This stuff is the network state, not node state (can be changed by other nodes in the network
  out << "[messages]";
  int node;
  MessageQueueMap::const_iterator i;
  for(i = queuedMessages.begin(), node = 0; i != queuedMessages.end(); i++, node++) {
    if(i->size()) {
      out << "[toDest(" << node << ")]";
      for(MessageQueue::const_iterator j = i->begin(); j != i->end(); j++) {
        out << " " << (*j).regId << " " << (*j).messageType << " " << Base64::encode((*j).msg) << " ";
      }
      out << "[/toDest(" << node << ")]";
    }
  }
  out << "[/messages]";
}

  bool SimulatorTCPService::checkSafetyProperties(mace::string& description, const _NodeMap_& nodes) {
    ADD_SELECTORS("SimulatorTCPService::testSafetyProperties");
    bool invalid = false;
    int i;
    int j;
    for(i = 0; !invalid && i < Sim::getNumNodes(); i++) {
      for(j = i; !invalid && j < Sim::getNumNodes(); j++) {
        if(nodes.get(i)->localErrors[j]) {
          if(nodes.get(i)->remoteErrors[j]) {
            if(nodes.get(i)->openSockets[j]) {
              // 1,1,1 - OK.  Need 1,1,1 from j.
              if(!(nodes.get(j)->localErrors[i] && nodes.get(j)->remoteErrors[i] && nodes.get(j)->openSockets[i])) {
                invalid = true;
              }
            } else {
              // 1,1,0 - INVALID!
              invalid = true;
            }
          } else {
            if(nodes.get(i)->openSockets[j]) {
              // 1,0,1 - INVALID!
              invalid = true;
            } else {
              // 1,0,0 - Ok.  Need 0,1,1 from j
              if(!(!nodes.get(j)->localErrors[i] && nodes.get(j)->remoteErrors[i] && nodes.get(j)->openSockets[i])) {
                invalid = true;
              }
            }
          }
        } else {
          if(nodes.get(i)->remoteErrors[j]) {
            if(nodes.get(i)->openSockets[j]) {
              // 0,1,1 - Ok.  Need 1,0,0 from j
              if(!(nodes.get(j)->localErrors[i] && !nodes.get(j)->remoteErrors[i] && !nodes.get(j)->openSockets[i])) {
                invalid = true;
              }
            } else {
              // 0,1,0 - INVALID!
              invalid = true;
            }
          } else {
            if(nodes.get(i)->openSockets[j]) {
              // 0,0,1 - Ok.  Need 0,0,1 from j
              if(!(!nodes.get(j)->localErrors[i] && !nodes.get(j)->remoteErrors[i] && nodes.get(j)->openSockets[i])) {
                invalid = true;
              }
            } else {
              // 0,0,0 - Ok.  Need 0,0,0 from j
              if(!(!nodes.get(j)->localErrors[i] && !nodes.get(j)->remoteErrors[i] && !nodes.get(j)->openSockets[i])) {
                invalid = true;
              }
            }
          }
        }
      }
    }
    if(invalid) {
      description = "SimulatorTCPService";
      i--;
      j--;
      maceerr << "Invalid socket state! nodes("<< (i) << "," << (j) << "): (l,r,o),(l,r,o): " << nodes.get(i)->localErrors[j] << "," << nodes.get(i)->remoteErrors[j] << "," << nodes.get(i)->openSockets[j] << "," << nodes.get(j)->localErrors[i] << "," << nodes.get(j)->remoteErrors[i] << "," << nodes.get(j)->openSockets[i] << Log::endl;
      return false;
    }
    return true;
  }

}
