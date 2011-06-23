/* 
 * unit_app.cc : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian
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
/*************************************************************
   appmacedon: A simple MACEDON application
   Adolfo Rodriguez
   Usage:
   appmacedon [DEFAULT PARAMETER FILE] [OPTIONS]
     Options: 
       -protocol INT 
          (Which protocol to use from macedon.protocols)
       -bootstrap IP_ADDR 
          (IP of bootstrap node, typically the "root")
       -port INT 
          (Network port to use)
       -multicast_port INT 
          (Network multicast port, not currently implemented)
       -degree INT 
          (Maximum node fan-out)
       -run_time DOUBLE 
          (Amount of time to run)
       -hold_time DOUBLE 
          (Time after starting to disable overlay transformations)
       -streaming_time DOUBLE 
          (Time after starting of when to begin streaming)
       -streaming_rate INT 
          (Rate to send in Kbps)
       -data_packet_size INT 
          (Size in bytes of data packets)
       -parent_filename FILENAME 
          (File specifying nodes' parents)
       -topology INT 
          (Topology ID, 
           only for inclusion in trace entries, not used)
       -topology_size INT 
          (Size of topo (number of total nodes), 
           only for inclusion in trace entries, not used)
       -topology_seed INT 
          (Random seed, 
           only for inclusion in trace entries, not used)
       -num_nodes INT 
          (Number of nodes in overlay, 
           only for inclusion in trace entries, not used)
**************************************************************/

#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include "lib/mace_constants.h"
#include <string>
// using std::string;
#include "lib/Log.h"
#include "lib/pip_includer.h"
#include "lib/mace.h"
#include "lib/SysUtil.h"
#include "lib/Util.h"
#include "lib/TimeUtil.h"
#include "params.h"

#include "services/interfaces/NullServiceClass.h"
NullServiceClass *globalMacedon;

#ifdef Useransub_test
#include "services/RanSub/ransub_test-init.h"
#endif

#ifdef Usechord_test
#include "chord_test-init.h"
#endif

#ifdef UseLookupTest
#include "LookupTest-init.h"
#endif

int main (int argc, char **argv)
{
  // First load running parameters 
  //   Log::autoAddAll();
  params::addRequired("service");
  params::addRequired("run_time");
  params::loadparams(argc, argv);
  Log::configure();
  params::print(stdout);
  ANNOTATE_INIT();
  ANNOTATE_SET_PATH_ID_STR(NULL, 0, "main-%s", Util::getAddrString(Util::getMaceAddr()).c_str());

  mace::string service = params::get<mace::string>("service");
  uint64_t runtime = (uint64_t)(params::get<double>("run_time") * 1000 * 1000);

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

#ifdef Useransub_test
  if(service == "ransub_test") {
    globalMacedon = &ransub_test_namespace::new_ransub_test_Null();
  } else
#endif
#ifdef Usechord_test
  if(service == "chord_test") {
    globalMacedon = &chord_test_namespace::new_chord_test_Null();
  } else
#endif
#ifdef UseLookupTest
  if(service == "lookup_test") {
    ASSERT(params::containsKey("schedule"));
    globalMacedon = &LookupTest_namespace::new_LookupTest_Null();
  } else
#endif
  {
    std::cerr << "Unknown test service " << service << std::endl;
    ABORT("Unknown test service");
  }
  globalMacedon->maceInit();

  SysUtil::sleepu(runtime);
  
  std::cout << "Exiting at time " << TimeUtil::timeu() << std::endl;
  
  // All done.
  globalMacedon->maceExit();
  Scheduler::haltScheduler();
  return 0;

}
