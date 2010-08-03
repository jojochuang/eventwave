/* 
 * SimulatorTCP.h : part of the Mace toolkit for building distributed systems
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
#ifndef SimulatorTCP_SERVICE_H
#define SimulatorTCP_SERVICE_H

#include "mace.h"
#include "RouteServiceClass.h"
#include "BufferedTransportServiceClass.h"
#include "m_map.h"
#include "SimNetwork.h"
#include <deque>
#include "Serializable.h"

namespace SimulatorTCP_namespace {

class SimulatorTCPService : public virtual BufferedTransportServiceClass, public virtual SimulatorTransport {
public:
  typedef std::deque<SimulatorMessage> MessageQueue;
  typedef mace::vector<MessageQueue, mace::SoftState> MessageQueueMap;
  typedef mace::vector<int> SocketState;
  static const int MAX_QUEUE_SIZE = 100000;
  //   static int PT_tcp;

public:
  SimulatorTCPService(int queue_size, int port, int node, bool messageErrors = false, int forwarder = -1);
  virtual ~SimulatorTCPService() { }

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
  registration_uid_t registerHandler(ConnectionStatusHandler& h, registration_uid_t rid = -1);
  void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t registrationUid = -1) { }
  void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t registrationUid = -1) { }
  void unregisterHandler(ConnectionStatusHandler& h, registration_uid_t rid = -1) { }
  bool route(const MaceKey& dest, const std::string& s, registration_uid_t registrationUid);
  bool route(const MaceKey& src, const MaceKey& dest, const std::string& s,
	     registration_uid_t registrationUid);
  uint32_t outgoingBufferedDataSize(const MaceKey& peer, registration_uid_t registrationUid = -1);
  const BufferStatisticsPtr getStatistics(const MaceKey& peer, Connection::type d, registration_uid_t registrationUid = -1);

  bool canSend(const MaceKey& peer, registration_uid_t registrationUid = -1);

  void requestToSend(const MaceKey& peer, registration_uid_t rid);
  bool routeRTS(const MaceKey& dest, const std::string& s, registration_uid_t rid);
  void requestFlushedNotification(registration_uid_t rid);

  void signal(int source, TransportSignal sig);

  std::string simulateEvent(const SimulatorMessage& msg);
  void recv(const SimulatorMessage& m);
  void transport_error(const int& destAddr, int transportError);

  std::string simulateFlushed();
  std::string simulateCTS(int node);
  bool hasFlushed();
  bool hasCTS(int node);

  bool isAvailableMessage(int dest);
  SimulatorMessage getMessage(int dest);
  int getPort();
  MaceKey getLocalAddress(registration_uid_t regId = -1) const;

  bool isListening();

  typedef mace::map<int, SimulatorTCPService*, mace::SoftState> _NodeMap_;
  static bool checkSafetyProperties(mace::string& description, const _NodeMap_& nodes);
  static bool checkLivenessProperties(mace::string& description, const _NodeMap_& nodes) {
    return true; //could do other perhaps, but not so general.
  }

  void printSocketState() const;

protected:
  void clearQueue(int destNode, int transportError, bool upcallError);

private:
  uint queueSize;
  int localPort;
  int localNode;
  bool upcallMessageErrors;
  int forwarder;
  SimNetwork& net;
  bool listening;
  BufferStatisticsPtr stats;
  typedef mace::deque<registration_uid_t> RegList;
  typedef mace::map<int, RegList, mace::SoftState> RtsMap;
  RtsMap rtsRequests;
  typedef mace::set<registration_uid_t> RegSet;
  RegSet flushRequests;
  typedef mace::map < registration_uid_t, ConnectionStatusHandler*, mace::SoftState> ConnectionHandlerMap;
  ConnectionHandlerMap connectionHandlers;
  typedef mace::map < registration_uid_t, ReceiveDataHandler*, mace::SoftState> ReceiveHandlerMap;
  ReceiveHandlerMap handlers;
  typedef mace::map < registration_uid_t, NetworkErrorHandler*, mace::SoftState> NetworkHandlerMap;
  NetworkHandlerMap network_handlers;

  MessageQueueMap queuedMessages;
  SocketState openSockets; // true if we have delivered a message to the dest, or if we have received a message
  SocketState remoteErrors; // true if there is an error message coming locally (controlled by signals)
  SocketState localErrors; // true if we have a queued error message
};

}

int SimulatorTCP_load_protocol();
SimulatorTCP_namespace::SimulatorTCPService *SimulatorTCPService_init_function();

#endif
