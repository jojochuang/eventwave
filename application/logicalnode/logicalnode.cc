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
//#include "MigrationTestHandler.h"
#include "ContextJobApplication.h"


template <class Service> 
void launchTest(const mace::string& service, const uint64_t runtime, const bool ismaster  ){
  mace::ContextJobApplication<Service> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;

  if( ismaster ){
    MaceAddr slaveAddr = Util::getMaceAddr();
    slaveAddr.local.port = static_cast<uint16_t>( 6005 );
    mace::string slaveAddrStr = Util::getAddrString( slaveAddr.local , false );

    params::set("slave_address", slaveAddrStr);
    app.startService( service );
    
    uint32_t master_start = params::get<uint32_t>("master_start",1);
    SysUtil::sleepm( 1000* master_start ); // sleep for one second
  }
  app.startService( service);
  app.waitService( runtime );

  app.globalExit();
}
mace::string setServiceName(){

  mace::string service;
  uint32_t test_case = params::get<uint32_t>("test_case");
  switch( test_case ){
    case 1:
      service = "Test1Ping";
      break;
  }
  return service;
}
// fork multiple processes from it.
// Advantage: easier to run
// Drawback: harder to separate logs between processes
void forkLogicalNodes(const mace::string& service){
  pid_t pid;

  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
  if( (pid = fork() ) == 0 ){
    // new process
    params::set("MACE_PORT", "6005");
    launchTest<NullServiceClass>( service, runtime, false );
  }else{ // old process
    params::set("MACE_PORT", "6000");
    launchTest<NullServiceClass>( service, runtime, true );
  }
}

void runMaster(const mace::string& service){
    params::set("MACE_PORT", "6000");
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    launchTest<NullServiceClass>( service, runtime, true );
}

void runSlave(const mace::string& service){
    params::set("MACE_PORT", "6005");
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    launchTest<NullServiceClass>( service, runtime, false );
}
/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  mace::Init(argc, argv);
  load_protocols();

  mace::string service = setServiceName();

  bool fork = params::get<bool>("fork");
  if( fork ){
    forkLogicalNodes(service);
  }else{
    int master = (int)( params::get<int>("master") );
    if( master ){
      runMaster(service);
    }else{
      runSlave(service);
    }
  }

  return 0;
}
