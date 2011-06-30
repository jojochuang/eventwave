/* 
 * ServiceTests.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian, James W. Anderson, Karthik Nagaraj
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

#include "LoadTest.h"
#include "Log.h"
#include "Sim.h"
#include "Simulator.h"
#include "SimulatorTCP.h"
#include "SimulatorUDP.h"
#include "mace-macros.h"

using SimulatorTCP_namespace::SimulatorTCPService;
using SimulatorUDP_namespace::SimulatorUDPService;

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
#ifdef UseSimGTreeApp
#include "SimGTreeApp.h"
#endif

#ifdef UseBrokenTree
#include "BrokenTree.h"
#endif
#ifdef UseRandTree
#include "RandTree.h"
#endif
#ifdef UseRandTree_v2
#include "RandTree_v2.h"
#endif
#ifdef UseOvercast
#include "Overcast.h"
#endif
#ifdef UsePastry
#include "Pastry.h"
#endif
#ifdef UseBamboo
#include "Bamboo.h"
#endif
#ifdef UseRouteTransportWrapper
#include "RouteTransportWrapper.h"
#endif
#ifdef UseScribeMS
#include "CacheRecursiveOverlayRoute.h"
#include "RecursiveOverlayRoute.h"
#include "ScribeMS.h"
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
#ifdef UseRanSub
#include "ReplayTree.h"
#endif
#ifdef UseRanSubAggregator
#include "RanSubAggregator.h"
#endif
#ifdef UsePaxos
#include "Paxos.h"
#include "PaxosMembership.h"
#endif

namespace macemc {

typedef SimulatorTCP_namespace::_NodeMap_ _TCP_NodeMap_;

#ifdef UseRandTree
  class RandTreeMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("RandTree");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("RandTree::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        RandTree_namespace::_NodeMap_ randTreeNodes;
        SimTreeApp_namespace::_NodeMap_ simTreeNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
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
          //app->maceInit();
        }

        TEST_PROPERTIES(RandTree, randTreeNodes);
        TEST_PROPERTIES(SimTreeApp, simTreeNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
      }

      virtual ~RandTreeMCTest() {}
  };

  void addRandTree() __attribute__((constructor));
  void addRandTree() {
    MCTest::addTest(new RandTreeMCTest());
  }
#endif


#ifdef UseRandTree_v2
  class RandTree_v2MCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("RandTree_v2");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("RandTree_v2::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        RandTree_v2_namespace::_NodeMap_ randTreeNodes;
        SimTreeApp_namespace::_NodeMap_ simTreeNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
          tcpNodes[i] = tcp;
          
          RandTree_v2_namespace::RandTree_v2Service* tree = new RandTree_v2_namespace::RandTree_v2Service(*tcp, 2);
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

        TEST_PROPERTIES(RandTree_v2, randTreeNodes);
        TEST_PROPERTIES(SimTreeApp, simTreeNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
      }

      virtual ~RandTree_v2MCTest() {}
  };

  void addRandTree_v2() __attribute__((constructor));
  void addRandTree_v2() {
    MCTest::addTest(new RandTree_v2MCTest());
  }
#endif


#ifdef UseBrokenTree
  class BrokenTreeMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("BrokenTree");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("BrokenTree::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        BrokenTree_namespace::_NodeMap_ brokenTreeNodes;
        SimTreeApp_namespace::_NodeMap_ simTreeNodes;

        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();

          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
          
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

        TEST_PROPERTIES(BrokenTree, brokenTreeNodes);
        TEST_PROPERTIES(SimTreeApp, simTreeNodes);
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
        const static mace::string s("Overcast");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("Overcast::loadTest");
        macedbg(0) << "called." << Log::endl;

        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        Overcast_namespace::_NodeMap_ overcastNodes;
        SimTreeApp_namespace::_NodeMap_ simTreeNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
          
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

        TEST_PROPERTIES(Overcast, overcastNodes);
        TEST_PROPERTIES(SimTreeApp, simTreeNodes);
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
        const static mace::string s("Pastry");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        
        ADD_SELECTORS("Pastry::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        Pastry_namespace::_NodeMap_ pastryNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
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

        TEST_PROPERTIES(Pastry, pastryNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
      }

      virtual ~PastryMCTest() {}
  };

  void addPastry() __attribute__((constructor));
  void addPastry() {
    MCTest::addTest(new PastryMCTest());
  }
#endif

#ifdef UseScribeMS
  class ScribeMSMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("ScribeMS");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        static const int PASTRY = 0;
        static const int BAMBOO = 1;
        static const int CHORD  = 2;
        static const int dhtService = params::get("DHT_SERVICE", 0);
        
        ADD_SELECTORS("ScribeMS::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);

        Pastry_namespace::_NodeMap_ pastryNodes;
        Bamboo_namespace::_NodeMap_ bambooNodes;
        Chord_namespace::_NodeMap_ chordNodes;

        SimGTreeApp_namespace::_NodeMap_ treeNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
          tcpNodes[i] = tcp;
          
          SimulatorUDPService* udp = new SimulatorUDPService(base_port+1, i);

          OverlayRouterServiceClass* ov_ = NULL;

          switch (dhtService) {
            case PASTRY : {
                            Pastry_namespace::PastryService* pastry = new Pastry_namespace::PastryService(*tcp, *udp);
                            ov_ = pastry;
                            servicesToDelete.push_back(pastry);
                            list.push_back(pastry);
                            pastryNodes[i] = pastry;
                            break;
                          }
            case BAMBOO : {
                            RouteTransportWrapper_namespace::RouteTransportWrapperService* rtw = new RouteTransportWrapper_namespace::RouteTransportWrapperService(*tcp);
                            servicesToDelete.push_back(rtw);
                            list.push_back(rtw);

                            Bamboo_namespace::BambooService* bamboo = new Bamboo_namespace::BambooService(*rtw, *udp);
                            ov_ = bamboo;
                            servicesToDelete.push_back(bamboo);
                            list.push_back(bamboo);
                            bambooNodes[i] = bamboo;
                            break;
                          }
            case CHORD  : {
                            ABORT("Test Not Implemented.");
                            break;
                          }
            default : {
                        ABORT("Need to set DHT_SERVICE to 0 (Pastry), 1 (Bamboo), or 2 (Chord)");
                        break;
                      }
          }
          

          RecursiveOverlayRoute_namespace::RecursiveOverlayRouteService* ror = new RecursiveOverlayRoute_namespace::RecursiveOverlayRouteService(*tcp, *ov_);
          servicesToDelete.push_back(ror);
          list.push_back(ror);

          CacheRecursiveOverlayRoute_namespace::CacheRecursiveOverlayRouteService* cror = new CacheRecursiveOverlayRoute_namespace::CacheRecursiveOverlayRouteService(*ov_, *tcp, 30);
          servicesToDelete.push_back(cror);
          list.push_back(cror);
          
          ScribeMS_namespace::ScribeMSService* tree = new ScribeMS_namespace::ScribeMSService(*ov_, *ror, *cror);
          servicesToDelete.push_back(tree);
          list.push_back(tree);

          SimGTreeApp_namespace::SimGTreeAppService* app = new SimGTreeApp_namespace::SimGTreeAppService(*ov_, *tree, *tree, SimOverlayRouterApp_namespace::ROOT_ONLY, 1, key, num_nodes);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          treeNodes[i] = app;
        }

        switch (dhtService) {
          case PASTRY : {
                          TEST_PROPERTIES(Pastry, pastryNodes);
                          break;
                        }
          case BAMBOO : {
                          TEST_PROPERTIES(Bamboo, bambooNodes);
                          break;
                        }
          case CHORD  : {
                          TEST_PROPERTIES(Chord, chordNodes);
                          break;
                        }
        }
        TEST_PROPERTIES(SimGTreeApp, treeNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
      }

      virtual ~ScribeMSMCTest() {}
  };

  void addScribeMS() __attribute__((constructor));
  void addScribeMS() {
    MCTest::addTest(new ScribeMSMCTest());
  }
#endif


#ifdef UseChord
  class ChordMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("Chord");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("Chord::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        Chord_namespace::_NodeMap_ chordNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
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

        TEST_PROPERTIES(Chord, chordNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
      }

      virtual ~ChordMCTest() {}
  };

  void addChord() __attribute__((constructor));
  void addChord() {
    MCTest::addTest(new ChordMCTest());
  }
#endif


// #ifdef UsePaxos
//   class PaxosMCTest : public MCTest {
//     public:
//       const mace::string& getTestString() {
//         const static mace::string s("Paxos");
//         return s;
//       }
//       void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
//         int base_port = params::get("MACE_PORT", 5377);
//         //         int queue_size = params::get("queue_size", 20);
//         mace::map<int, SimConsensusApp_namespace::SimConsensusAppService*, mace::SoftState> simAppNodes;
//         for(int i = 0; i < num_nodes; i++) {
//           ServiceClassList list;
//           Sim::setCurrentNode(i);
//           MaceKey key = Sim::getCurrentMaceKey();
//           SimulatorUDPService* udp = new SimulatorUDPService(base_port, i);
//           PaxosMembership_namespace::PaxosMembershipService* membership = new PaxosMembership_namespace::PaxosMembershipService(*udp);
//           membership->maceInit();

//           NodeSet allNodes;
//           for (int j = 0; j < num_nodes; j++) {
//             allNodes.insert(Sim::getMaceKey(j));
//           }

//           membership->setMembership(MaceKey::null, allNodes, -1);
//           servicesToDelete.push_back(membership);
//           list.push_back(membership);
//           Paxos_namespace::PaxosService* ch = new Paxos_namespace::PaxosService(*membership,*membership,*udp);
//           servicesToDelete.push_back(ch);
//           list.push_back(ch);
//           static int numProposers = params::get("NODES_TO_PROPOSE", allNodes.size());
//           SimConsensusApp_namespace::SimConsensusAppService* app = new SimConsensusApp_namespace::SimConsensusAppService(*ch, numProposers);
//           app->maceInit();
//           servicesToDelete.push_back(app);
//           list.push_back(app);
//           servicesToPrint.push_back(list);
//           simAppNodes[i] = app;
//           appNodes[i] = app;
//         }
//         propertiesToTest.push_back(new SpecificTestProperties<SimConsensusApp_namespace::SimConsensusAppService>(simAppNodes));
//         propertiesToTest.push_back(new SimEmptyProperty(SimNetwork::Instance()));
//       }
//       virtual ~PaxosMCTest() {}
//   };

//   void addPaxos() __attribute__((constructor));
//   void addPaxos() {
//     MCTest::addTest(new PaxosMCTest());
//   }
// #endif


#ifdef UseMaceTransport
  class MaceTransportMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("MaceTransport");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("MaceTransport::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        MaceTransport_namespace::_NodeMap_ transportNodes;
        SimTransportApp_namespace::_NodeMap_ simTransportNodes;

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

        TEST_PROPERTIES(MaceTransport, transportNodes);
        TEST_PROPERTIES(SimTransportApp, simTransportNodes); 
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
        const static mace::string s("ProvisionalTransport");
        return s;
      }
      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("ProvisionalTransport::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        ProvisionalTransport_namespace::_NodeMap_ transportNodes;
        SimPTransportApp_namespace::_NodeMap_ simTransportNodes;

        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          
          SimulatorTCPService* tcp = new SimulatorTCPService(1, base_port, i);
          list.push_back(tcp);
          
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

        //         TEST_PROPERTIES(ProvisionalTransport, transportNodes);
        TEST_PROPERTIES(SimPTransportApp, simTransportNodes); 
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
        const static mace::string s("RanSubAggregator");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("RanSubAggregator::loadTest");
        macedbg(0) << "called." << Log::endl;
      
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        RanSubAggregator_namespace::_NodeMap_ aggregateNodes;
        SimAggregateApp_namespace::_NodeMap_ simAggregateNodes;
        params::set("root", "1.0.0.0");
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          MaceKey key = Sim::getCurrentMaceKey();
          
          SimulatorTCPService* tcp = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(tcp);
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

        TEST_PROPERTIES(RanSubAggregator, aggregateNodes);
        TEST_PROPERTIES(SimAggregateApp, simAggregateNodes);
      }

      virtual ~RanSubAggregatorMCTest() {}
  };

  void addRanSubAggregator() __attribute__((constructor));
  void addRanSubAggregator() {
    MCTest::addTest(new RanSubAggregatorMCTest());
  }
#endif
  class SimulatorTCPMCTest : public MCTest {
    public:
      const mace::string& getTestString() {
        const static mace::string s("SimulatorTCP");
        return s;
      }

      void loadTest(TestPropertyList& propertiesToTest, ServiceList& servicesToDelete, NodeServiceClassList& servicesToPrint, SimApplicationServiceClass** appNodes, int num_nodes) {
        ADD_SELECTORS("SimulatorTCP::loadTest");
        macedbg(0) << "called." << Log::endl;
        
        int base_port = params::get("MACE_PORT", 5377);
        int queue_size = params::get("queue_size", 20);
        SimTransportApp_namespace::_NodeMap_ simTransportNodes;
        _TCP_NodeMap_ tcpNodes;
        
        for (int i = 0; i < num_nodes; i++) {
          ServiceClassList list;
          Sim::setCurrentNode(i);
          
          SimulatorTCPService* t = new SimulatorTCPService(queue_size, base_port, i);
          list.push_back(t);
          tcpNodes[i] = t;
          
          SimTransportApp_namespace::SimTransportAppService* app = new SimTransportApp_namespace::SimTransportAppService(*t);
          servicesToDelete.push_back(app);
          list.push_back(app);
          servicesToPrint.push_back(list);
          appNodes[i] = app;
          simTransportNodes[i] = app;
        }
        
        TEST_PROPERTIES(SimTransportApp, simTransportNodes);
        TEST_TCP_PROPERTIES(tcpNodes);
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimNetwork::Instance()));
        propertiesToTest.push_back(new SimulatorEmptyProperty(SimScheduler::Instance()));
      }
      
      virtual ~SimulatorTCPMCTest() {}
  };

  void addSimulatorTCP() __attribute__((constructor));
  void addSimulatorTCP() {
    MCTest::addTest(new SimulatorTCPMCTest());
  }
}
