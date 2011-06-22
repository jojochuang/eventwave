#include "SimulatorCommon.h"

namespace macemc {

std::vector<uint32_t> __SimulatorCommon__::nodeState;
std::vector<std::string> __SimulatorCommon__::nodeStateStr;
std::vector<uint32_t> __SimulatorCommon__::initialNodeState;
std::vector<std::string> __SimulatorCommon__::initialNodeStateStr;
mace::hash_map<uint32_t, UIntList> __SimulatorCommon__::systemStates;
uint32_t __SimulatorCommon__::firstState;
bool __SimulatorCommon__::divergenceMonitor = true;
bool __SimulatorCommon__::use_broken_hash;
bool __SimulatorCommon__::use_hash;
bool __SimulatorCommon__::assert_safety;
bool __SimulatorCommon__::max_steps_error;
//bool __SimulatorCommon__::max_time_error;
bool __SimulatorCommon__::print_errors;
bool __SimulatorCommon__::monitorOverride;
bool __SimulatorCommon__::monitorWaiting;
//DistributionMap __SimulatorCommon__::distributions;
int __SimulatorCommon__::error_path = 1;
SimRandomUtil* __SimulatorCommon__::randomUtil;
hash_string __SimulatorCommon__::hasher;
unsigned __SimulatorCommon__::loggingStartStep = 0;
bool __SimulatorCommon__::doLogging = true;
int __SimulatorCommon__::max_dead_paths = 1;
int __SimulatorCommon__::num_nodes = 0;

}
