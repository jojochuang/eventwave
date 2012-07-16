#include <math.h>

#include "lib/Log.h"
#include "lib/mace.h"
#include "lib/TimeUtil.h"
#include "lib/params.h"
#include "lib/mlist.h"
#include "mace-macros.h"

#include <iostream>
#include <fstream>

#include "load_protocols.h"
#include "../services/interfaces/NullServiceClass.h"
#include "ContextJobApplication.h"

/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  mace::Init(argc, argv);
  //params::addRequired("service");
  load_protocols();
  mace::ContextJobApplication<NullServiceClass> app;
  app.installSignalHandler();

  /*if( params::containsKey("logdir") ){
    app.redirectLog( params::get<std::string>("logdir") );
  }*/
  // if -pid is set, set MACE_PORT based on -pid value. and open fifo channel to talk with heartbeat
  /*if( params::containsKey("pid") ){
    params::set("MACE_PORT", boost::lexical_cast<std::string>(20000 + params::get<uint32_t>("pid",0 )*5)  );
  }*/
  params::print(stdout);

  app.loadContext();

  mace::string service;
  if( params::get<uint32_t>("test_case") == 0 ){
    service = "TestCase0";
  }else if( params::get<uint32_t>("test_case") == 1 ){
    service = "TestCase1";
  }
  uint64_t runtime = 2*1000*1000; // = (uint64_t)(params::get<double>("run_time", 0) * 1000 * 1000);

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service, runtime);

  return 0;
}
