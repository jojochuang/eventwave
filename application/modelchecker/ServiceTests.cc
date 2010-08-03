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
#ifdef UseRandTree
#include "RandTree.h"
#endif

#include <iostream>
using namespace std;

#include "LoadTest.h"

#ifdef UseSimTreeApp
#include "SimTreeApp.h"
#endif
#ifdef UseSimOverlayRouterApp
#include "SimOverlayRouterApp.h"
#endif
#ifdef UseSimTransportApp
#include "SimTransportApp.h"
#endif
#ifdef UseSimPTransportApp
#include "SimPTransportApp.h"
#endif
#ifdef UseSimAggregateApp
#include "SimAggregateApp.h"
#endif
#ifdef UseSimConsensusApp
#include "SimConsensusApp.h"
#endif

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
#ifdef UseRandTree
#include "RandTree.h"
#endif
#ifdef UseOvercast
#include "Overcast.h"
#endif
#ifdef UsePastry
#include "Pastry.h"
#endif
#ifdef UseChord
#include "Chord.h"
#endif
#ifdef UseMaceTransport
#include "MaceTransport.h"
#endif
#ifdef UseProvisionalTransport
#include "ProvisionalTransport.h"
#endif
#ifdef UseRanSubAggregator
#include "ReplayTree.h"
#include "RanSubAggregator.h"
#endif

// #ifdef UseSimTreeApp
// #include "SimTreeApp.h"
// #endif
// #ifdef UseSimOverlayRouterApp
// #include "SimOverlayRouterApp.h"
// #endif
// #ifdef UseSimTransportApp
// #include "SimTransportApp.h"
// #endif
// #ifdef UseSimPTransportApp
// #include "SimPTransportApp.h"
// #endif
// #ifdef UseSimAggregateApp
// #include "SimAggregateApp.h"
// #endif
// #ifdef UseSimConsensusApp
// #include "SimConsensusApp.h"
// #endif

#include "Log.h"
#include "mace-macros.h"

namespace macemc {

#ifdef UseRandTree
  class RandTreeMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("RandTree");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("RandTree::loadTest");
        macedbg(0) << "called." << Log::endl;
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, RandTree_namespace::RandTreeService*, mace::SoftState> randTreeNodes;
        mace::map<int, SimTreeApp_namespace::SimTreeAppService*, mace::SoftState> simTreeNodes;
        mace::map<int, SimulatorTCPService*, mace::SoftState> tcpNodes;
        for(int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          tcpNodes[i] = tcp;
          RandTree_namespace::RandTreeService* tree = new RandTree_namespace::RandTreeService(*tcp, 2);
          servicesToDelete.push_back(tree);
          list.push_back(tree);
          randTreeNodes[i] = tree;
          SimTreeApp_namespace::SimTreeAppService* app = new SimTreeApp_namespace::SimTreeAppService(*tree, *tree, SimTreeApp_namespace::NEXT_NODE, 1, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          simTreeNodes[i] = app;
          appNodes[i] = app;
          app->maceInit();
        }
        propertiesToTest.push_back(new SpecificTestProperties<RandTree_namespace::RandTreeService>(randTreeNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimTreeApp_namespace::SimTreeAppService>(simTreeNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimulatorTCPService>(tcpNodes));
      }
      virtual ~RandTreeMCTest() {}
  };

  void addRandTree() __attribute__((constructor));
  void addRandTree() {
    MCTest::addTest(new RandTreeMCTest());
  }

#endif

#ifdef UseBrokenTree
  class BrokenTreeMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("BrokenTree");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
	ADD_FUNC_SELECTORS;
	
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
	  Log::binaryLog(selectorId->log, 
			 StartEventReader_namespace::StartEventReader(i, 0, true),
			 0);
          app->maceInit();
	  Log::binaryLog(selectorId->log, 
			 StartEventReader_namespace::StartEventReader(i, 0, false),
			 0);
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
#endif
#ifdef UseOvercast  
  class OvercastMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("Overcast");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, Overcast_namespace::OvercastService*, mace::SoftState> overcastNodes;
        mace::map<int, SimTreeApp_namespace::SimTreeAppService*, mace::SoftState> simTreeNodes;
        for(int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          Overcast_namespace::OvercastService* tree = new Overcast_namespace::OvercastService(*tcp);
          servicesToDelete.push_back(tree);
          list.push_back(tree);
          overcastNodes[i] = tree;
          SimTreeApp_namespace::SimTreeAppService* app = new SimTreeApp_namespace::SimTreeAppService(*tree, *tree, SimTreeApp_namespace::ROOT_ONLY, 1, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          simTreeNodes[i] = app;
          appNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<Overcast_namespace::OvercastService>(overcastNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimTreeApp_namespace::SimTreeAppService>(simTreeNodes));
      }
      virtual ~OvercastMCTest() {}
  };

  void addOvercast() __attribute__((constructor));
  void addOvercast() {
    MCTest::addTest(new OvercastMCTest());
  }
#endif
#ifdef UsePastry
  class PastryMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("Pastry");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, Pastry_namespace::PastryService*, mace::SoftState> pastryNodes;
        mace::map<int, SimulatorTCPService*, mace::SoftState> tcpNodes;
        for(int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          tcpNodes[i] = tcp;
          SimulatorUDPService* udp = new SimulatorUDPService(base_port+1, i);
          Pastry_namespace::PastryService* tree = new Pastry_namespace::PastryService(*tcp, *udp);
          servicesToDelete.push_back(tree);
          list.push_back(tree);
          pastryNodes[i] = tree;
          SimOverlayRouterApp_namespace::SimOverlayRouterAppService* app = new SimOverlayRouterApp_namespace::SimOverlayRouterAppService(*tree, SimOverlayRouterApp_namespace::ROOT_ONLY, 1, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<Pastry_namespace::PastryService>(pastryNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimulatorTCPService>(tcpNodes));
      }
      virtual ~PastryMCTest() {}
  };

  void addPastry() __attribute__((constructor));
  void addPastry() {
    MCTest::addTest(new PastryMCTest());
  }
#endif
#ifdef UseChord
  class ChordMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("Chord");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, Chord_namespace::ChordService*, mace::SoftState> chordNodes;
        mace::map<int, SimulatorTCPService*, mace::SoftState> tcpNodes;
        for(int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          tcpNodes[i] = tcp;
          Chord_namespace::ChordService* ch = new Chord_namespace::ChordService(*tcp);
          servicesToDelete.push_back(ch);
          list.push_back(ch);
          chordNodes[i] = ch;
          SimOverlayRouterApp_namespace::SimOverlayRouterAppService* app = new SimOverlayRouterApp_namespace::SimOverlayRouterAppService(*ch, SimOverlayRouterApp_namespace::/*ROOT_ONLY*/RANDOM_LESSER, 1, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<Chord_namespace::ChordService>(chordNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimulatorTCPService>(tcpNodes));
      }
      virtual ~ChordMCTest() {}
  };

  void addChord() __attribute__((constructor));
  void addChord() {
    MCTest::addTest(new ChordMCTest());
  }
#endif
#ifdef UseMaceTransport
  class MaceTransportMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("MaceTransport");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, MaceTransport_namespace::MaceTransportService*, mace::SoftState> transportNodes;
        mace::map<int, SimTransportApp_namespace::SimTransportAppService*, mace::SoftState> simTransportNodes;
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          SimulatorUDPService* udp = new SimulatorUDPService(base_port, i);
          MaceTransport_namespace::MaceTransportService* t = new MaceTransport_namespace::MaceTransportService(*udp, true, queue_size, UINT_MAX);
          servicesToDelete.push_back(t);
          list.push_back(t);
          SimTransportApp_namespace::SimTransportAppService* app = new SimTransportApp_namespace::SimTransportAppService(*t);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          transportNodes[i] = t;
          simTransportNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<MaceTransport_namespace::MaceTransportService>(transportNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimTransportApp_namespace::SimTransportAppService>(simTransportNodes));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimNetwork::Instance()));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimScheduler::Instance()));
      }
      virtual ~MaceTransportMCTest() {}
  };

  void addMaceTransport() __attribute__((constructor));
  void addMaceTransport() {
    MCTest::addTest(new MaceTransportMCTest());
  }
#endif
#ifdef UseProvisionalTransport
  class ProvisionalTransportMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("ProvisionalTransport");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        mace::map<int, ProvisionalTransport_namespace::ProvisionalTransportService*, mace::SoftState> transportNodes;
        mace::map<int, SimPTransportApp_namespace::SimPTransportAppService*, mace::SoftState> simTransportNodes;
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          SimulatorTCPService* tcp = new SimulatorTCPService(1, base_port, i);
          ProvisionalTransport_namespace::ProvisionalTransportService* t = new ProvisionalTransport_namespace::ProvisionalTransportService(*tcp, 1, 1);
          servicesToDelete.push_back(t);
          list.push_back(t);
          SimPTransportApp_namespace::SimPTransportAppService* app = new SimPTransportApp_namespace::SimPTransportAppService(*tcp, *t);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          transportNodes[i] = t;
          simTransportNodes[i] = app;
        }
        //       propertiesToTest.push_back(new SpecificTestProperties<ProvisionalTransport_namespace::ProvisionalTransportService>(transportNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimPTransportApp_namespace::SimPTransportAppService>(simTransportNodes));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimNetwork::Instance()));
        //       propertiesToTest.push_back(new SimulatorEmptyProperty(SimScheduler::Instance()));
      }
      virtual ~ProvisionalTransportMCTest() {}
  };

  void addProvisionalTransport() __attribute__((constructor));
  void addProvisionalTransport() {
    MCTest::addTest(new ProvisionalTransportMCTest());
  }
#endif
#ifdef UseRanSubAggregator
  class RanSubAggregatorMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("RanSubAggregator");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, RanSubAggregator_namespace::RanSubAggregatorService*, mace::SoftState> aggregateNodes;
        mace::map<int, SimAggregateApp_namespace::SimAggregateAppService*, mace::SoftState> simAggregateNodes;
        params::set("root", "1.0.0.0");
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          ReplayTree_namespace::ReplayTreeService* t = new ReplayTree_namespace::ReplayTreeService(*tcp);
          servicesToDelete.push_back(t);
          list.push_back(t);
          RanSubAggregator_namespace::RanSubAggregatorService* rsagg = new RanSubAggregator_namespace::RanSubAggregatorService(*t, *tcp, 5*1000*1000);
          servicesToDelete.push_back(rsagg);
          list.push_back(rsagg);
          SimAggregateApp_namespace::SimAggregateAppService* app = new SimAggregateApp_namespace::SimAggregateAppService(*t, *rsagg, SimAggregateApp_namespace::ROOT_ONLY, 1, key);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          aggregateNodes[i] = rsagg;
          simAggregateNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<RanSubAggregator_namespace::RanSubAggregatorService>(aggregateNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimAggregateApp_namespace::SimAggregateAppService>(simAggregateNodes));
      }
      virtual ~RanSubAggregatorMCTest() {}
  };

  void addRanSubAggregator() __attribute__((constructor));
  void addRanSubAggregator() {
    MCTest::addTest(new RanSubAggregatorMCTest());
  }
#endif
#ifdef UseSimTransportApp
  class SimTCPMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        static const mace::string s("SimTCP");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        mace::map<int, SimTransportApp_namespace::SimTransportAppService*, mace::SoftState> simTransportNodes;
        mace::map<int, SimulatorTCPService*, mace::SoftState> tcpNodes;
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          SimulatorTCPService* t = new SimulatorTCPService(queue_size, base_port, i);
          tcpNodes[i] = t;
          SimTransportApp_namespace::SimTransportAppService* app = new SimTransportApp_namespace::SimTransportAppService(*t);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          simTransportNodes[i] = app;
        }
        propertiesToTest.push_back(new SpecificTestProperties<SimTransportApp_namespace::SimTransportAppService>(simTransportNodes));
        propertiesToTest.push_back(new SpecificTestProperties<SimulatorTCPService>(tcpNodes));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimNetwork::Instance()));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimScheduler::Instance()));
      }
      virtual ~SimTCPMCTest() {}
  };

  void addSimTCP() __attribute__((constructor));
  void addSimTCP() {
    MCTest::addTest(new SimTCPMCTest());
  }
#endif
}
