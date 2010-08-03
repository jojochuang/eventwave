/* 
 * SimulatorUDP.cc : part of the Mace toolkit for building distributed systems
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
#include "SimulatorUDP.h"
#include "NumberGen.h"
#include "Accumulator.h"
#include "mace_constants.h"
#include "MaceTypes.h"
#include "mace-macros.h"

using std::string;

int SimulatorUDP_load_protocol()
{
  return 0;
}

namespace SimulatorUDP_namespace {

  SimulatorUDPService::SimulatorUDPService(int port, int node) : localPort(port), localNode(node), net(SimNetwork::Instance()), listening(false), queuedMessages(Sim::getNumNodes()) {
    ADD_SELECTORS("UDP::constructor");

    maceout << "local_address " << Sim::getMaceKey(node) << " port " << port << Log::endl;
    net.registerHandler(port, *this);
  }

  void SimulatorUDPService::maceInit() { 
    listening = true;
  }

  bool SimulatorUDPService::isListening() {
    return listening;
  }
  
  void SimulatorUDPService::maceReset() {
    listening = false;
    handlers.clear();
  }

  registration_uid_t SimulatorUDPService::registerHandler(ReceiveDataHandler& handler, registration_uid_t handlerUid) {
    if(handlerUid == -1) {
      handlerUid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
    }
    handlers[handlerUid] = &handler;
    return handlerUid;
  }

  registration_uid_t SimulatorUDPService::registerHandler(NetworkErrorHandler& handler, registration_uid_t handlerUid) {
    if(handlerUid == -1) {
      handlerUid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
    }
    return handlerUid;
  }

  bool SimulatorUDPService::route(const MaceKey& dest, const string& s, registration_uid_t handlerUid) {
    static bool allowErrors = params::get("USE_UDP_ERRORS", false);
    ADD_SELECTORS("SIMULATOR::UDP::route::pkt::(downcall)");
    maceout << "dest=" << dest.toString() << " size=" << s.size() << " priority=" << 0 << " handlerUid=" << handlerUid << Log::endl;
    uint32_t msgId = net.getMessageId();
    int destNode = Sim::getNode(dest);
    MessageQueue& mqueue = queuedMessages[destNode];
    maceout << "drop message routed from " << localNode << " to " << destNode << "? (0-no 1-yes) " << Log::endl;
    if(allowErrors && RandomUtil::randInt(2, 1, 0)) { //In search mode, either error or non-error may occur.  In gusto mode, no errors may occur
      maceout << "route([dest=" << dest << "][s_deserialized=pkt(id=" << msgId
        << ", SIM_DROP=1)])" << Log::endl;
    } else {
      maceout << "route([dest=" << dest << "][s_deserialized=pkt(id=" << msgId << ")])"
        << Log::endl;
      mqueue.push_back(SimulatorMessage(localNode, destNode, -1, -1, msgId, SimulatorMessage::MESSAGE, handlerUid, s));
    }
    return true; //UDP always appears to send message
  }

  bool SimulatorUDPService::isAvailableMessage(int destNode) {
    std::deque<SimulatorMessage>& deque = queuedMessages[destNode];
    return !deque.empty();
  }

  SimulatorMessage SimulatorUDPService::getMessage(int destNode) {
    static bool allowReorder = params::get("USE_UDP_REORDER", true);
    ADD_SELECTORS("SIMULATOR::UDP::getMessage");
    std::deque<SimulatorMessage>& deque = queuedMessages[destNode];
    ASSERT(isAvailableMessage(destNode));
    int msg = 0;
    //if (allowReorder && Sim::gusto) -- original, buggy code -- only allows reordering during gusto phase
    //if (allowReorder || Sim::gusto) -- possible "correct" code for practical model checking -- always allow reordering during gusto
    if (allowReorder && !Sim::getGusto()) {
      maceout << "Which message in queue to deliver?" << std::endl;
      if(! maceout.isNoop()) {
        int position = 0;
        for(MessageQueue::const_iterator j = deque.begin(); j != deque.end(); j++, position++) {
          maceout << position << ": message " << j->messageId << std::endl;
        }
      }
      maceout << Log::endl;
      msg = RandomUtil::randInt(deque.size());
    }
    MessageQueue::iterator i = deque.begin()+msg;
    SimulatorMessage str = *(i);
    deque.erase(i);
    return str;
  }

  int SimulatorUDPService::getPort() { return localPort; }
  MaceKey SimulatorUDPService::getLocalAddress(registration_uid_t regId) const { 
    ADD_SELECTORS("UDP::getLocalAddress");
    maceLog("called getLocalAddress\n");
    return Sim::getMaceKey(localNode); 
  }

  std::string SimulatorUDPService::simulateEvent(const SimulatorMessage& msg) {
    ASSERT(msg.destination == localNode);
    if(msg.messageType == SimulatorMessage::MESSAGE) {
      recv(msg);
      return "";
    } else if(msg.messageType == SimulatorMessage::DEST_NOT_READY) {
      ASSERT(isAvailableMessage(msg.source));
      SimulatorMessage m = getMessage(msg.source);
      return "id " + boost::lexical_cast<std::string>(m.messageId);
    } else { //msg.messageType == READ_ERROR
      ASSERT(0);
      return std::string();
    }
  }
  void SimulatorUDPService::recv(const SimulatorMessage& msg) {
    ADD_SELECTORS("UDP::recv");
    maceout << "from=" << Sim::getMaceKey(msg.source).toString() << " dsize=" << msg.msg.size() << Log::endl;
    ReceiveHandlerMap::iterator i = handlers.find(msg.regId);
    if(i == handlers.end()) { macewarn << "Could not find handler with id " << msg.regId << " for msgId " << msg.messageId << " : dropping packet" << Log::endl; return; }
    i->second->deliver(Sim::getMaceKey(msg.source), Sim::getMaceKey(msg.destination), msg.msg, msg.regId);
  }

  uint32_t SimulatorUDPService::hashState() const {
    static uint32_t hashAnd = (localPort) * localNode;
    static hash_string strHasher;
    uint32_t hashWork = hashAnd;
    for(mace::map < registration_uid_t, ReceiveDataHandler*, mace::SoftState>::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
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

  void SimulatorUDPService::printState(std::ostream& out) const {
    out << "[SimulatorUDP]" << std::endl;
    out << "[localPort = " << localPort << "][localKey = " << Sim::getMaceKey(localNode) << "]";
    out << "[RDH] ";
    for(mace::map < registration_uid_t, ReceiveDataHandler*, mace::SoftState>::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
      out << i->first << " ";
    }
    out << "[/RDH]";
    out << "[/SimulatorUDP]" << std::endl;
  }

  void SimulatorUDPService::print(std::ostream& out) const {
    out << "[localPort = " << localPort << "][localKey = " << Sim::getMaceKey(localNode) << "]";
    out << "[RDH] ";
    for(mace::map < registration_uid_t, ReceiveDataHandler*, mace::SoftState>::const_iterator i = handlers.begin(); i != handlers.end(); i++) {
      out << i->first << " ";
    }
    out << "[/RDH]";
    //This is getting printed by printNetwork();
    //     out << "[messages]";
    //     int node;
    //     MessageQueueMap::const_iterator i;
    //     for(i = queuedMessages.begin(), node=0; i != queuedMessages.end(); i++, node++) {
    //       out << "[toDest(" << node << ")]";
    //       for(MessageQueue::const_iterator j = i->begin(); j != i->end(); j++) {
    //         out << "[msg]" << (*j).messageId << "::" << (*j).messageType << "[/msg]";
    //       }
    //       out << "[/toDest(" << node << ")]";
    //     }
    //     out << "[/messages]";
  }

  void SimulatorUDPService::printNetwork(std::ostream& out) const {
    out << "[messages]";
    int node;
    MessageQueueMap::const_iterator i;
    for(i = queuedMessages.begin(), node=0; i != queuedMessages.end(); i++, node++) {
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
  void SimulatorUDPService::printNetworkState(std::ostream& out) const {
    out << "[messages]";
    int node;
    MessageQueueMap::const_iterator i;
    for(i = queuedMessages.begin(), node=0; i != queuedMessages.end(); i++, node++) {
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

}
