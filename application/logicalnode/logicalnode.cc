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
void executeTest1(const mace::string& service, const uint64_t runtime, const bool ismaster  ){
  mace::ContextJobApplication<Service> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;

  app.loadContext();
  if( ismaster ){
    MaceAddr slaveAddr = Util::getMaceAddr();
    slaveAddr.local.port = static_cast<uint16_t>( 6020 );
    mace::string slaveAddrStr = Util::getAddrString( slaveAddr.local , false );

    params::set("slave_address", slaveAddrStr);
    uint32_t master_start = params::get<uint32_t>("master_start",1);
    SysUtil::sleepm( 1000* master_start ); // sleep for one second
    params::set("ServiceConfig.Test1Ping.NODETYPE","1");
  }
  app.startService( service);
  app.waitService( runtime );

  app.globalExit();
}

template <class Service> 
void executeTest2(const mace::string& service, const uint64_t runtime, const bool ismaster  ){
  mace::ContextJobApplication<Service> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;

  app.loadContext();
  if( ismaster ){
    MaceAddr slaveAddr = Util::getMaceAddr();
    slaveAddr.local.port = static_cast<uint16_t>( 6020 );
    mace::string slaveAddrStr = Util::getAddrString( slaveAddr.local , false );

    params::set("slave_address", slaveAddrStr);
    uint32_t master_start = params::get<uint32_t>("master_start",1);
    SysUtil::sleepm( 1000* master_start ); // sleep for one second
    params::set("ServiceConfig.Test2OfferedLoad.NODETYPE","1");
  }
  app.startService( service);
  app.waitService( runtime );

  app.globalExit();
}

void launchTest1(){
  mace::string service = "Test1Ping";

  bool dofork = params::get<bool>("fork", false);
  bool master;
  if( dofork ){
    pid_t pid;
    if( (pid = fork() ) == 0 ){
// fork multiple processes from it.
// Advantage: easier to run
// Drawback: harder to separate logs between processes
      // new process
      master = false;
    }else{ // old process
      master = true;
    }

  }else{
    master = params::get<bool>("master") ;
  }
  if( master ){
    params::set("MACE_PORT", "6000");
    uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    executeTest1<NullServiceClass>( service, runtime, true );
  }else{
    params::set("MACE_PORT", "6020");
    uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    executeTest1<NullServiceClass>( service, runtime, false );
  }
}
void launchTest2(){
  mace::string service = "Test2OfferedLoad";

  bool dofork = params::get<bool>("fork", false);
  bool master;
  if( dofork ){
    pid_t pid;
    if( (pid = fork() ) == 0 ){
// fork multiple processes from it.
// Advantage: easier to run
// Drawback: harder to separate logs between processes
      // new process
      master = false;
    }else{ // old process
      master = true;
    }

  }else{
    master = params::get<bool>("master") ;
  }
  if( master ){
    params::set("MACE_PORT", "6000");
    uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    executeTest2<NullServiceClass>( service, runtime, true );
  }else{
    params::set("MACE_PORT", "6020");
    uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
    executeTest2<NullServiceClass>( service, runtime, false );
  }
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

  uint32_t test_case = params::get<uint32_t>("test_case");
  switch( test_case ){
    case 1:
      launchTest1();
      break;
    case 2:
      launchTest2();
      break;
  }

  return 0;
}
