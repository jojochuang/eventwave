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
#include <unistd.h>
#include <sys/types.h>
#include "mace_constants.h"
#include <string>
#include <sstream>
#include "NumberGen.h"
#include "Log.h"
#include "pip_includer.h"
#include "mace.h"

#include "MaceTime.h"

#include "Event.h"
#include "Sim.h"
#include "SimNetwork.h"
#include "RouteTransportWrapper.h"
typedef RouteTransportWrapper_namespace::RouteTransportWrapperService RouteTransportWrapper;
#include "SimScheduler.h"
#include "SimApplication.h"
#include "ThreadCreate.h"
#include "SysUtil.h"
#include "Properties.h"
#include "Simulator.h"
#include "macemc-getmtime.h"
#include "LoadTest.h"
using namespace macemc;

#undef exit
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

void sigHandler(int sig) {
//   std::cerr << "received signal " << sig << " my pid=" << getpid() << std::endl;
  if(sig == SIGINT && __Simulator__::randomUtil->handleInt()) {
    return;
  }
  Log::enableLogging();
  Log::log("ERROR::SIM::SIGNAL") << "Caught Signal " << sig << ", terminating" << Log::endl;
  __Simulator__::Error("SIGNAL");
}

int main(int argc, char **argv)
{
  //   addRandTree();
//   BaseMaceService::_printLower = true;
  BaseMaceService::_printLower = false;
  SysUtil::signal(SIGABRT, sigHandler);
  SysUtil::signal(SIGINT, sigHandler);
  //   SysUtil::signal(SIGINT, sigHandler);


  // First load running parameters 
  params::addRequired("num_nodes", "Number of nodes to simulate");
  params::addRequired("CHECKED_SERVICE", "Which service string to use");
  params::loadparams(argc, argv);
  params::set("MACE_SIMULATE_NODES", "MaceMC");
  params::print(stdout);

  { //logging
    Log::configure();
    Log::disableDefaultWarning();
    Log::disableDefaultError();
    //   LogSelectorTimestamp printTime = LOG_TIMESTAMP_HUMAN;
    LogSelectorTimestamp printTime = LOG_TIMESTAMP_DISABLED;
    LogSelectorThreadId printThreadId = LOG_THREADID_DISABLED;
    Log::add("ERROR",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*ERROR::SIM.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("SearchRandomUtil::next",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("SearchStepRandomUtil::next",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("BestFirstRandomUtil::next",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("HALT",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("MCTest",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*monitor\\(void.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("Sim::pathComplete",stdout,printTime,LOG_NAME_ENABLED);
    Log::add("Sim::printStats",stdout,printTime,LOG_NAME_ENABLED);
    //   Log::add("DEBUG::static bool __Simulator__::isDuplicateState()",stdout,printTime,LOG_NAME_ENABLED);
    Log::autoAdd(".*LastNailRandomUtil::hasNext.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::add("LastNailRandomUtil::next",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    Log::autoAdd(".*LastNailRandomUtil::dumpState.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    if(params::containsKey("TRACE_ALL")) {
      Log::autoAddAll(stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    }
    if(params::containsKey("TRACE_ALL_SQL")) {
      Log::autoAddAll(stdout,printTime,LOG_NAME_ENABLED,printThreadId, LOG_PGSQL);
    }
    if(params::containsKey("TRACE_SIMULATOR")) {
      Log::add("BestFirstRandomUtil::hasNext",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("main",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      //     Log::autoAdd("Simulator");
      Log::add("__Simulator__::getReadyEvents",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::autoAdd(".*__Simulator__::isDuplicateState.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::autoAdd(".*__Simulator__::initState.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::autoAdd(".*simulateNode.*",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("SearchRandomUtil::randInt",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("SearchStepRandomUtil::randInt",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("BestFirstRandomUtil::randInt",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("LastNailRandomUtil::randInt",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      Log::add("ReplayRandomUtil::randInt",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    }
    if(params::containsKey("TRACE_SUBST")) {
      std::istringstream in(params::get<std::string>("TRACE_SUBST"));
      while(in) {
        std::string s;
        in >> s;
        if(s.length() == 0) { break; }
        Log::autoAdd(s,stdout,printTime,LOG_NAME_ENABLED,printThreadId);
      }
    }
    if(params::containsKey("TRACE_STATE")) {
      Log::autoAdd(".*__Simulator__::dumpState.*");
    }
    if(params::containsKey("TRACE_STEP")) {
      Log::add("main",stdout,printTime,LOG_NAME_ENABLED,printThreadId);
    }
  } //end logging

  Log::log("MCTest") << "Registered tests: " << MCTest::getRegisteredTests() << Log::endl;
  MCTest* test = MCTest::getTest(params::get<std::string>("CHECKED_SERVICE"));
  if (test == NULL) {
    Log::err() << "Invalid checked service type " << params::get<std::string>("CHECKED_SERVICE") << " specified!" << Log::endl;
    ASSERT(0);
  }
  
  if (params::containsKey("SIM_NODE_FAILURE")) {
    ABORT("Parameter SIM_NODE_FAILURE removed.  Instead, use SIM_NUM_FAILURES (-1 means any number,m 0 means none, other gives maximum number.");
  }
  if (params::containsKey("USE_NET_ERRORS")) {
    ABORT("Parameter USE_NET_ERRORS removed.  Instead, use SIM_NUM_NET_ERRORS (-1 means any number,m 0 means none, other gives maximum number.");
  }
  
  // Make sure the running scheduler is our simulator one.
  SimScheduler::Instance();
  __Simulator__::initializeVars();

  if(__Simulator__::divergenceMonitor) {
    pthread_t tid;
    runNewThread(&tid, monitor, NULL, NULL);
  }

  int num_nodes = __Simulator__::num_nodes;
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
  Log::log("main") << "Starting simulation" << Log::endl;

  int num_dead_paths = 0;
  unsigned maxPaths = (params::containsKey("MAX_PATHS")?params::get<int>("MAX_PATHS"):UINT_MAX);
  mace::string description;
  do {
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
          ABORT("Uncaught Mace Exception");
        } catch(const std::exception& se) {
          maceerr << "Uncaught std::exception " << se.what() << Log::endl;
          ABORT("Uncaught std::exception");
        } catch(...) {
          maceerr << "Uncaught unknown throw" << Log::endl;
          ABORT("Uncaught unknown throw");
        }
        __Simulator__::dumpState();
        Sim::updateGusto();
        if(__Simulator__::isDuplicateState()) {
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
  } while(Sim::getPathNum() < maxPaths && __Simulator__::randomUtil->hasNext(Sim::isLive));
  Log::enableLogging();
  Log::log("HALT") << "Simulation complete!" << Log::endl;
  __Simulator__::disableMonitor();
  Sim::printStats(__Simulator__::randomUtil->getPhase() + " -- possibly incomplete");
  __Simulator__::enableMonitor();
  Log::log("HALT") << "Final RandomUtil State: " << *__Simulator__::randomUtil << Log::endl;
  __Simulator__::randomUtil->dumpState();

  printf("***falling out of main***\n");
  return 0;

}

