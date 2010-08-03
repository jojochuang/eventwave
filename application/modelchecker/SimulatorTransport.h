/* 
 * SimulatorTransport.h : part of the Mace toolkit for building distributed systems
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
#ifndef _SIM_TRANSPORT__H_
#define _SIM_TRANSPORT__H_

#include <string>
#include "MaceTypes.h"
#include "TransportServiceClass.h"

struct SimulatorMessage {
  public:
  int source;
  int destination;
  int forwarder;
  int nextHop;
  uint32_t messageId;
  registration_uid_t regId;
  enum MessageType { MESSAGE, READ_ERROR, DEST_NOT_READY } messageType;
  std::string msg;
  SimulatorMessage(const int& s, const int& d, const int& f, const int& n, uint32_t id, const MessageType& t, registration_uid_t rid, const std::string& m)
    : source(s), destination(d), forwarder(f), nextHop(n), messageId(id), regId(rid), messageType(t), msg(m)
  {}
};

class SimulatorTransport : public virtual TransportServiceClass {
  public:
    enum TransportSignal { BIDI_READ_ERROR, SOURCE_RESET };
    virtual bool isAvailableMessage(int destNode) = 0;
    virtual SimulatorMessage getMessage(int destNode) = 0;
    virtual int getPort() = 0;
    virtual std::string simulateEvent(const SimulatorMessage& msg) = 0;
    virtual bool isListening() = 0;
    virtual void printNetwork(std::ostream& out) const = 0;
    virtual void printNetworkState(std::ostream& out) const = 0;
    virtual void signal(int source, TransportSignal sig) = 0;
  virtual std::string simulateFlushed() { ASSERT(0); return std::string(); }
  virtual std::string simulateCTS(int node) { ASSERT(0); return std::string(); }
  virtual bool hasFlushed() { return false; }
  virtual bool hasCTS(int node) { return false; }
};

#endif
