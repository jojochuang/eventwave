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
#include "ServCompUpcallHandler.h"
#include "ServCompServiceClass.h"
#include "ContextJobApplication.h"


template <class Service> 
Service* launchTestCase(const mace::string& service, const uint64_t runtime  ){
  mace::ContextJobApplication<Service> app;
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


  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service, runtime);

  return app.getServiceObject();
}
template <class Service> 
Service* launchUpcallTestCase(const mace::string& service, const uint64_t runtime  ){
  mace::ContextJobApplication<Service> app;
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


  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;


  class DataHandler: public ServCompUpcallHandler {
  public:
    void setService( Service* servobj ){ this->servobj = servobj; }
  private:
    Service* servobj;
    // TODO: when migratio finishes, send a upcall up to terminate the application.
    void testVoidUpcall_NoParam(registration_uid_t rid ){
      // test downcall into the service:
      //  expect the runtime creates a new event
      //servobj->test(5);
    }
    void testVoidUpcall_WithParam( uint32_t param ){
    }
    uint32_t testUpcallReturn( ){
      uint32_t ret = 1;
      return ret;
    }
    uint32_t testUpcallReturn( uint32_t param ){
      uint32_t ret = 2;
      return ret;
    }
  };
  DataHandler dh;
  dh.setService( app.getServiceObject() );

  //app.template startService<DataHandler>( service, runtime, &dh );
  app.template startService<ServCompUpcallHandler>( service, runtime, &dh );

  return app.getServiceObject();
}
void startMigrationDestinationProcess( ){
  pid_t pid;
  if( (pid = fork() ) == 0 ){
    // new process
  }else{ // old process

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
  mace::string service;
  uint32_t test_case = params::get<uint32_t>("test_case");
  uint64_t runtime = 10*1000*1000; 
  // step 1: set local port
  if( params::get<uint32_t>("transfernode",0) == 1 ){
    params::set("MACE_PORT", "5005");
  }else{
    params::set("MACE_PORT", "5000");
    // step 2: start a new process 
    startMigrationDestinationProcess( );
  }

  // start a number of new nodes
  // fork --> execv()
  switch( test_case ){
    /*case 0:
      service = "TestCase0";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
    case 1:
      service = "TestCase1";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
    case 2:
      service = "TestCase2";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
    case 3:
      service = "TestCase3";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
    case 4:
      service = "TestCase4";
      launchUpcallTestCase<ServCompServiceClass>( service, runtime );
      break;*/
    case 5:
      service = "TestCase5";
      launchUpcallTestCase<ServCompServiceClass>( service, runtime );
      break;
  }
  return 0;
}
