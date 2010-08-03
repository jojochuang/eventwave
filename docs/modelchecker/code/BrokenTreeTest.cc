/* 
 * ServiceTests.cc : part of the Mace toolkit for building distributed systems
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
#include <iostream>
using namespace std;

#include "LoadTest.h"
#include "SimTreeApp.h"

#include "Sim.h"
#include "SimulatorTCP.h"
using SimulatorTCP_namespace::SimulatorTCPService;
#include "SimulatorUDP.h"
using SimulatorUDP_namespace::SimulatorUDPService;
#include "Simulator.h"

#ifdef UseBrokenTree
#include "BrokenTree.h"
#include "RouteTransportWrapper.h"
#endif


#include "SimOverlayRouterApp.h"
#include "SimTransportApp.h"
#include "SimPTransportApp.h"
#include "SimAggregateApp.h"
#include "SimConsensusApp.h"

#include "Log.h"
#include "mace-macros.h"

namespace macemc {

  class BrokenTreeMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("BrokenTree");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, BrokenTree_namespace::BrokenTreeService*, mace::SoftState> brokenTreeNodes;
        mace::map<int, SimTreeApp_namespace::SimTreeAppService*, mace::SoftState> simTreeNodes;
        for(int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          RouteTransportWrapper_namespace::RouteTransportWrapperService* rtw = new RouteTransportWrapper_namespace::RouteTransportWrapperService(*tcp);
          servicesToDelete.push_back(rtw);
          list.push_back(rtw);
          BrokenTree_namespace::BrokenTreeService* tree = new BrokenTree_namespace::BrokenTreeService(*rtw, Sim::getMaceKey(0), num_nodes);
          servicesToDelete.push_back(tree);
          list.push_back(tree);
          brokenTreeNodes[i] = tree;
          SimTreeApp_namespace::SimTreeAppService* app = new SimTreeApp_namespace::SimTreeAppService(*tree, *tree, SimTreeApp_namespace::ROOT_ONLY, 0, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          simTreeNodes[i] = app;
          appNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<BrokenTree_namespace::BrokenTreeService>(brokenTreeNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimTreeApp_namespace::SimTreeAppService>(simTreeNodes));
      }
      virtual ~BrokenTreeMCTest() {}
  };

  void addBrokenTree() __attribute__((constructor));
  void addBrokenTree() {
    MCTest::addTest(new BrokenTreeMCTest());
  }
}
