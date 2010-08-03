/* 
 * SimulatorUDP.h : part of the Mace toolkit for building distributed systems
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
#ifndef SimulatorUDP_SERVICE_H
#define SimulatorUDP_SERVICE_H

#include "mace.h"
#include "TransportServiceClass.h"
#include "m_map.h"
#include "SimNetwork.h"
#include <deque>
#include "Serializable.h"

namespace SimulatorUDP_namespace {

class SimulatorUDPService : public virtual TransportServiceClass, public virtual SimulatorTransport {
public:
  typedef std::deque<SimulatorMessage> MessageQueue;
  typedef mace::vector<MessageQueue, mace::SoftState> MessageQueueMap;

public:
  SimulatorUDPService(int port, int node);
  virtual ~SimulatorUDPService() { }

  void maceInit();
  void maceExit() {}
  void maceReset();
  uint32_t hashState() const;
  void print(std::ostream& out) const;
  void printState(std::ostream& out) const;
  void printNetwork(std::ostream& out) const;
  void printNetworkState(std::ostream& out) const;
  registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t registrationUid = -1);
  registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t registrationUid = -1);
  void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t registrationUid = -1) { }
  void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t registrationUid = -1) { }
  bool route(const MaceKey& dest, const std::string& s, registration_uid_t registrationUid);
  void signal(int source, TransportSignal sig) {}

  std::string simulateEvent(const SimulatorMessage& msg);
  void recv(const SimulatorMessage& msg);

  bool isAvailableMessage(int dest);
  SimulatorMessage getMessage(int dest);
  int getPort();
  MaceKey getLocalAddress(registration_uid_t regId = -1) const;

  bool isListening();

private:
  int localPort;
  int localNode;
  SimNetwork& net;
  bool listening;
  typedef mace::map < registration_uid_t, ReceiveDataHandler*, mace::SoftState> ReceiveHandlerMap;
  ReceiveHandlerMap handlers;

  MessageQueueMap queuedMessages;
};

}

int SimulatorUDP_load_protocol();
SimulatorUDP_namespace::SimulatorUDPService *SimulatorUDPService_init_function();

#endif
