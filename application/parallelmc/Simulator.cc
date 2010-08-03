/*
 * Simulator.cc : part of the Mace toolkit for building distributed systems
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

#include <pthread.h>
#include "PrintNodeFormatter.h"
#include "Simulator.h"
#include "SearchRandomUtil.h"
#include "SearchStepRandomUtil.h"
//#include "BestFirstRandomUtil.h"
typedef SearchRandomUtil BestFirstRandomUtil;
#include "ReplayRandomUtil.h"
#include "LastNailRandomUtil.h"
#include "PrefixSearcherRandomUtil.h"

namespace macemc {

  std::vector<uint32_t> __Simulator__::nodeState;
  std::vector<std::string> __Simulator__::nodeStateStr;
  std::vector<uint32_t> __Simulator__::initialNodeState;
  std::vector<std::string> __Simulator__::initialNodeStateStr;
  mace::hash_map<uint32_t, UIntList> __Simulator__::systemStates;
  uint32_t __Simulator__::firstState;
  bool __Simulator__::divergenceMonitor = true;
  bool __Simulator__::use_broken_hash;
  bool __Simulator__::use_hash;
  bool __Simulator__::assert_safety;
  bool __Simulator__::max_steps_error;
  bool __Simulator__::print_errors;
  bool __Simulator__::monitorOverride;
  bool __Simulator__::monitorWaiting;
  int __Simulator__::error_path = 1;
  SimRandomUtil* __Simulator__::randomUtil;
  hash_string __Simulator__::hasher;
  unsigned __Simulator__::loggingStartStep = 0;
  int __Simulator__::max_dead_paths = 1;
  int __Simulator__::num_nodes = 0;

  pthread_mutex_t __Simulator__::stateTableLock;

  StateCommunicator<MCMessage> *__Simulator__::communicator;

  int __Simulator__::nodeRank;
  int __Simulator__::nodeCount;
  int __Simulator__::processRank;
  int __Simulator__::processCount;
  bool __Simulator__::checkForDuplicateStates;

  void __Simulator__::dumpState() {
    ADD_SELECTORS("__Simulator__::dumpState");
    if(! maceout.isNoop()) {
      SimApplication& app = SimApplication::Instance();
      mace::PrintNode pr("root", "");
      app.print(pr, "SimApplication");
      std::ostringstream os;
      mace::PrintNodeFormatter::print(os, pr);
      maceout << "Begin Printer State" << std::endl << os.str() << Log::endl;
      maceout << "End Printer State" << Log::endl;
//       std::ostringstream longos;
//       mace::PrintNodeFormatter::printWithTypes(longos, pr);
//       maceout << longos.str() << std::endl;

//       maceout << "Application State: " << app << std::endl;
      Sim& net = SimNetwork::Instance();
      maceout << "Network State: " << net << Log::endl;
//         Sim& sched = SimScheduler::Instance();
//         maceout << "Scheduler State: " << sched << Log::endl;
    }
  }

  void __Simulator__::initializeRandomUtil(bool prefixSearch) {
    if(params::containsKey("RANDOM_REPLAY_FILE")) {
      use_hash = false;
      assert_safety = true;
      if(params::get<std::string>("RANDOM_REPLAY_FILE") == "-") {
        print_errors = true;
        RandomUtil::seedRandom(TimeUtil::timeu());
      } else {
        print_errors = false;
        RandomUtil::seedRandom(0);
      }
      max_steps_error = true;
      randomUtil = ReplayRandomUtil::SetInstance();
      divergenceMonitor = params::get("RUN_DIVERGENCE_MONITOR",false);
    } else if(params::containsKey("LAST_NAIL_REPLAY_FILE")) {
      RandomUtil::seedRandom(0);
      max_dead_paths = INT_MAX;
      use_hash = false;
      assert_safety = false;
      //     print_errors = false;
      print_errors = true;
      max_steps_error = false;
      randomUtil = LastNailRandomUtil::SetInstance();
      divergenceMonitor = params::get("RUN_DIVERGENCE_MONITOR",true);
      std::string statfilestr = "lastnail_" + params::get<std::string>("STAT_FILE", "stats.log");
      params::set("ERROR_PATH_FILE_TAG", "-lastnail-");
      FILE* statfile = fopen(statfilestr.c_str(), "w");
      if(statfile == NULL) {
        Log::perror("Could not open stat file");
        exit(1);
      }
      Log::add("Sim::printStats",statfile,LOG_TIMESTAMP_DISABLED,LOG_NAME_DISABLED,LOG_THREADID_DISABLED);
      Log::add("DEBUG::Sim::printStats",statfile,LOG_TIMESTAMP_DISABLED,LOG_NAME_DISABLED,LOG_THREADID_DISABLED);
    } else {
      RandomUtil::seedRandom(0);
      print_errors = true;
      assert_safety = false;
      max_steps_error = true;
      if (params::get("USE_BEST_FIRST", true)) {
        randomUtil = BestFirstRandomUtil::SetInstance();
      }
      else if(params::get("USE_STEP_SEARCH", false)) {
        randomUtil = SearchStepRandomUtil::SetInstance();
      } else if (prefixSearch) {
        Log::log("Init") << "Installing prefix creator random util" << Log::endl;
        randomUtil = PrefixSearcherRandomUtil::SetInstance();
      } else {
        Log::log("Init") << "Installing search random util" << Log::endl;
        randomUtil = SearchRandomUtil::SetInstance();
      }
      divergenceMonitor = params::get("RUN_DIVERGENCE_MONITOR",true);
      FILE* statfile = fopen(params::get<std::string>("STAT_FILE", "stats.log").c_str(), "w");
      if(statfile == NULL) {
        Log::perror("Could not open stat file");
        exit(1);
      }
      Log::add("Sim::printStats",statfile,LOG_TIMESTAMP_DISABLED,LOG_NAME_DISABLED,LOG_THREADID_DISABLED);
      Log::add("DEBUG::Sim::printStats",statfile,LOG_TIMESTAMP_DISABLED,LOG_NAME_DISABLED,LOG_THREADID_DISABLED);
    }
  }

  void __Simulator__::initializeVars() {
    use_hash = params::get("USE_STATE_HASHES", false);
    use_broken_hash = params::get("USE_BROKEN_HASH", false);
    loggingStartStep = params::get<unsigned>("LOGGING_START_STEP", 0);
    max_dead_paths = params::get("MAX_DEAD_PATHS", 1);
    num_nodes = params::get<int>("num_nodes");

    // Make sure our random number generator is the appropriate one
    initializeRandomUtil(true);
  }

}
/* vim: set ts=2 sw=2: */
