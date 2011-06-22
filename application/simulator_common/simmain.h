#ifndef SIMMAIN_H
#define SIMMAIN_H

#include "Log.h"
#include "Simulator.h"
#include "params.h"

namespace macemc {
  
void* monitor(void* dud) {
  ADD_FUNC_SELECTORS;
  bool divergence_assert = params::containsKey("divergence_assert");
  maceout << "monitor begun" << Log::endl;
  int timeout = params::get("divergence_timeout", 5);
  __Simulator__::expireMonitor();
  while (true) {
    SysUtil::sleep(timeout);
    if (__Simulator__::expireMonitor()) {
      Log::enableLogging();
      __Simulator__::Error("DIVERGENCE", divergence_assert);
    }
  }
  return NULL;
}

void sigHandler(int sig) {
//   std::cerr << "received signal " << sig << " my pid=" << getpid() << std::endl;
  if (sig == SIGINT && __Simulator__::randomUtil->handleInt()) {
    return;
  }
  Log::enableLogging();
  Log::log("ERROR::SIM::SIGNAL") << "Caught Signal " << sig << ", terminating" << Log::endl;
  __Simulator__::Error("SIGNAL");
}

void setupSigHandler() {
  SysUtil::signal(SIGABRT, sigHandler);
  SysUtil::signal(SIGINT, sigHandler);
  //   SysUtil::signal(SIGINT, sigHandler);
}

void setupParams(int argc, char **argv) {
  params::addRequired("num_nodes", "Number of nodes to simulate");
  params::addRequired("CHECKED_SERVICE", "Which service string to use");
  params::loadparams(argc, argv);
  params::set("MACE_SIMULATE_NODES", "MaceMC");

  // log the params to console
  params::print(stdout);

  // log the params to the binary log
  params::log();
}

void setupLogging() {
  Log::configure();    
  Log::disableDefaultWarning();
  Log::disableDefaultError();
  //   LogSelectorTimestamp printTime = LOG_TIMESTAMP_HUMAN;
  static const LogSelectorTimestamp printTime = LOG_TIMESTAMP_DISABLED;
  static const LogSelectorThreadId printThreadId = LOG_THREADID_DISABLED;

  Log::add("ERROR", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::autoAdd(".*ERROR::SIM.*", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("SearchRandomUtil::next", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("SearchStepRandomUtil::next", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("BestFirstRandomUtil::next", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("HALT",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("MCTest",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::autoAdd(".*monitor.*", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("Sim::pathComplete", stdout, printTime, LOG_NAME_ENABLED);
  Log::add("Sim::printStats", stdout, printTime, LOG_NAME_ENABLED);
  //   Log::add("DEBUG::static bool __Simulator__::isDuplicateState()",stdout,printTime,LOG_NAME_ENABLED);
  Log::autoAdd(".*LastNailRandomUtil::hasNext.*", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::add("LastNailRandomUtil::next", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  Log::autoAdd(".*LastNailRandomUtil::dumpState.*", stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  if (params::containsKey("TRACE_ALL")) {
    Log::autoAdd(".*",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  }
  if (params::containsKey("TRACE_ALL_BINARY")) {
    Log::autoAdd(".*",stdout, printTime, LOG_NAME_ENABLED, printThreadId, LOG_BINARY);
  }
  if (params::containsKey("TRACE_ALL_SQL")) {
    Log::autoAdd(".*",stdout, printTime, LOG_NAME_ENABLED, printThreadId, LOG_PGSQL);
  }

  if (params::containsKey("TRACE_SIMULATOR")) {
    Log::add("BestFirstRandomUtil::hasNext",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("main",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    //     Log::autoAdd("Simulator");
    Log::add("__Simulator__::getReadyEvents",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd(".*__Simulator__::isDuplicateState.*",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd(".*__Simulator__::initState.*",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd(".*simulateNode.*",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd("SimulateEventBegin",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd("SimulateEventEnd",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::autoAdd(".*simulateEvent.*",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("SearchRandomUtil::randInt",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("SearchStepRandomUtil::randInt",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("BestFirstRandomUtil::randInt",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("LastNailRandomUtil::randInt",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    Log::add("ReplayRandomUtil::randInt",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  }
  if (params::containsKey("TRACE_SUBST")) {
    std::istringstream in(params::get<std::string>("TRACE_SUBST"));
    while (in) {
      std::string s;
      in >> s;
      if (s.length() == 0) { break; }
      Log::autoAdd(s,stdout, printTime, LOG_NAME_ENABLED, printThreadId);
    }
  }
  if (params::containsKey("TRACE_STATE")) {
    Log::autoAdd(".*__Simulator__::dumpState.*");
  }
  if (params::containsKey("TRACE_STEP")) {
    Log::add("main",stdout, printTime, LOG_NAME_ENABLED, printThreadId);
  }
}

void clearAndReset(SimApplicationServiceClass **appNodes,
                   ServiceList& servicesToDelete,
                   TestPropertyList& propertiesToTest) {
  for (int i = 0; i < __Simulator__::num_nodes; i++) {
    appNodes[i]->maceExit();
  }

  for (size_t i = 0; i < servicesToDelete.size(); i++) {
    delete servicesToDelete[i];
  }

  SimScheduler::Instance().reset();
  SimNetwork::Instance().reset();
  SimApplication::reset();
  NumberGen::Reset();

  delete[] appNodes;

  for (size_t i = 0; i < propertiesToTest.size(); i++) {
    delete propertiesToTest[i];
  }
}

}

#endif // SIMMAIN_H
