/* 
 * SimApplication.h : part of the Mace toolkit for building distributed systems
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
#ifndef _SIM_APP_H_
#define _SIM_APP_H_

#include "MaceTypes.h"
#include "mvector.h"
#include "OverlayServiceClass.h"
#include "Sim.h"
#include "SimApplicationServiceClass.h"
#include "SimHandler.h"
#include "mace-macros.h"

class SimApplication : public Sim {
private:
  class SimNodeHandler : public SimHandler, public PrintPrintable {
  protected:
    int nodeNum;
    int incarnationNumber;
    SimApplicationServiceClass* node;
    bool eventSimulated;

  public:
    SimNodeHandler(int nn, SimApplicationServiceClass* no) : nodeNum(nn), incarnationNumber(0), node(no), eventSimulated(false) {
      node->registerUniqueHandler(*this);
    }

    const MaceKey& getMaceKey(int n, registration_uid_t rid = -1) const {
      return Sim::getMaceKey(n);
    }
    int getNodeNumber(const MaceKey& node, registration_uid_t rid = -1) const {
      return Sim::getNode(node);
    }
    int getNodeNumber(registration_uid_t rid = -1) const {
      return nodeNum;
    }
    int getNodeCount(registration_uid_t rid = -1) const {
      return Sim::getNumNodes();
    }
    int getIncarnationNumber(registration_uid_t rid = -1) const {
      return incarnationNumber;
    }
    unsigned getStep(registration_uid_t rid = -1) const {
      return Sim::step;
    }
    int eventsWaiting(EventList& ev) const {
      static int appWeight = params::get("APPLICATION_EVENT_WEIGHT", 40);
      static int failWeight = params::get("EVENT_FAILURE_WEIGHT", 0);
      static int numFailures = params::get("SIM_NUM_FAILURES", 0);
      typedef mace::deque<int> IntList;
      static IntList failNodes = params::getList<int>("SIM_FAIL_NODES");

      int eventsAdded = 0;
      if((!Sim::gusto || failWeight) && eventSimulated &&
	 (numFailures < 0 || failureCount < numFailures) &&
	 (failNodes.empty() || std::find(failNodes.begin(), failNodes.end(),
					 nodeNum) != failNodes.end())) {
        //push back failure event
        EventWeight ew;
        Event& e = ew.first;
        e.node = nodeNum;
        e.type = Event::APPLICATION;
        e.simulatorVector.push_back(SimApplication::RESET); 
        e.desc = "(Node Reset)";
        ew.second = failWeight;
        ev.push_back(ew);
        eventsAdded++;
      }
      int wt = appWeight;
      if(node->eventsWaiting(wt)) {
        //push back app event
        EventWeight ew;
        Event& e = ew.first;
        e.node = nodeNum;
        e.type = Event::APPLICATION;
        e.simulatorVector.push_back(SimApplication::APP); 
        e.desc = "(SimApp)";
        ew.second = wt;
        ev.push_back(ew);
        eventsAdded++;
      }
      return eventsAdded;
    }
    std::string simulateEvent(const Event& e) {
      ADD_SELECTORS("SimApplication::simulateEvent");
      eventSimulated = true;
      switch(e.simulatorVector[0]) {
        case SimApplication::RESET:
	  failureCount++;
          maceout << "simulating failure of " << e.node << Log::endl;
          this->reincarnate();
          return "FAILURE";
        case SimApplication::APP:
          return node->simulateEvent();
        default: ASSERT(e.simulatorVector[0] == SimApplication::RESET || e.simulatorVector[0] == SimApplication::APP);
      }
      ASSERT(0);
      return std::string();
    }
    void reincarnate() {
      eventSimulated = false;
      node->maceReset();
      node->registerUniqueHandler(*this);
      incarnationNumber++;
    }
    uint32_t hashState() const {
      return nodeNum * incarnationNumber + incarnationNumber;
    }
    void reset() {
      reincarnate();
      incarnationNumber = 0;
    }
    void print(std::ostream& out) const {
      out << "[nodeHandler " << nodeNum << " incarnation " << incarnationNumber << "]";
    }
  };

protected:
  static SimApplication* _sim_inst;
  static int failureCount;
  SimApplication(SimApplicationServiceClass** tnodes, const mace::vector<mace::vector<ServiceClass*, mace::SoftState>, mace::SoftState>& toprint) : Sim(), nodes(tnodes), nodeHandlers(new SimNodeHandler*[Sim::getNumNodes()]), toPrint(toprint) { 
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      nodeHandlers[i] = new SimNodeHandler(i, nodes[i]);
    }
  }
  static bool CheckInstance() { 
    ASSERT(_sim_inst != NULL);
    return true;
  }
  
  SimApplicationServiceClass** nodes;
  SimNodeHandler** nodeHandlers;
  const mace::vector<mace::vector<ServiceClass*, mace::SoftState>, mace::SoftState >& toPrint;

public:
  static SimApplication& Instance() { static bool dud __attribute((unused)) = CheckInstance(); return *_sim_inst; }
  static void SetInstance(SimApplicationServiceClass** nodes, const mace::vector<mace::vector<ServiceClass*, mace::SoftState>, mace::SoftState>& toprint) {
    ASSERT(_sim_inst == NULL);
    ASSERT(nodes != NULL);
    _sim_inst = new SimApplication(nodes, toprint);
    failureCount = 0;
  }

  uint32_t hashState() const {
    uint32_t hash = 0;
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      hash = (hash << 1) ^ nodes[i]->hashState();
    }
    return hash;
  }
  void print(mace::PrintNode& printer, const std::string& name) const {
    for (int i = 0; i < Sim::getNumNodes(); i++) {
      mace::PrintNode pr("node " + StrUtil::toString(i), "SimApplication");
      size_t sn = 0;
      for (mace::vector<ServiceClass*, mace::SoftState>::const_iterator ii = toPrint[i].begin(); ii != toPrint[i].end(); ii++) {
	(*ii)->print(pr, (*ii)->getLogType());
	sn++;
      }
      printer.addChild(pr);
    }
  }
  void print(std::ostream& out) const {
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      out << " [ Node " << i << ": ";
      for (mace::vector<ServiceClass*, mace::SoftState>::const_iterator ii = toPrint[i].begin(); ii != toPrint[i].end(); ii++) {
        out << " [SERVICE[ " << *(*ii) << " ]SERVICE] ";
      }
      out << " ] ";
    }
  }
  void printState(std::ostream& out) const {
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      out << " [ Node " << i << ": ";
      for (mace::vector<ServiceClass*, mace::SoftState>::const_iterator ii = toPrint[i].begin(); ii != toPrint[i].end(); ii++) {
        out << " [SERVICE[ ";
        (*ii)->printState(out);
        out << " ]SERVICE] ";
      }
      out << " ] ";
    }
  }
  enum AppEventType { APP, RESET };
  EventList getNodeFailureEvents() const {
    EventList ev;
    for(int i = 0; i < Sim::getNumNodes(); i++) {
    }
    return ev;
  }
  void eventsWaiting(EventList& ev) const {
    ADD_SELECTORS("SimApplication::eventsWaiting");
    int eventsAdded = 0;
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      eventsAdded += nodeHandlers[i]->eventsWaiting(ev);
    }
    maceout << "Added " << eventsAdded << " events to the event list" << Log::endl;
  }
  std::string simulateEvent(const Event& e) {
    ADD_SELECTORS("SimApplication::simulateEvent");
    ASSERT(e.node < Sim::getNumNodes());
    ASSERT(nodes != NULL);
    return nodeHandlers[e.node]->simulateEvent(e);
  }
  uint32_t hashNode(int node) const {
    ASSERT(node < Sim::getNumNodes());
    ASSERT(nodes != NULL);
    return nodes[node]->hashState()^nodeHandlers[node]->hashState();
  }
  std::string toString(int node) const {
    ASSERT(node < Sim::getNumNodes());
    ASSERT(nodes != NULL);
    std::ostringstream out;
    for (mace::vector<ServiceClass*, mace::SoftState>::const_iterator ii = toPrint[node].begin(); ii != toPrint[node].end(); ii++) {
      out << " [SERVICE[ " << **ii << " ]SERVICE] ";
    }
    out << std::endl << nodeHandlers[node]->toString();
    return out.str();
  }
  std::string toStateString(int node) const {
    ASSERT(node < Sim::getNumNodes());
    ASSERT(nodes != NULL);
    std::ostringstream out;
    for (mace::vector<ServiceClass*, mace::SoftState>::const_iterator ii = toPrint[node].begin(); ii != toPrint[node].end(); ii++) {
      out << " [SERVICE[ " << (*ii)->toStateString() << " ]SERVICE] ";
    }
    out << std::endl << nodeHandlers[node]->toStateString();
    return out.str();
  }
  static void reset() {
    delete _sim_inst;
    _sim_inst = NULL;
  }
  virtual ~SimApplication() {
    for(int i = 0; i < Sim::getNumNodes(); i++) {
      delete nodeHandlers[i];
    }
    delete[] nodeHandlers;
    nodeHandlers = NULL;
  }
};

#endif
