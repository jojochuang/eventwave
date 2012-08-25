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
#include "MigrationTestHandler.h"
#include "MigrationTestServiceClass.h"
#include "ContextJobApplication.h"


template <class Service> 
void launchTestCase(const mace::string& service, const uint64_t runtime  ){
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
  app.startService( service );
  app.waitService( runtime );

  app.globalExit();
}
template<class Service>
class DataHandler: public ServCompUpcallHandler {
public:
  void setService( Service* servobj ){ this->servobj = servobj; }
private:
  Service* servobj;
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
template <class Service> 
void launchUpcallTestCase(const mace::string& service, const uint64_t runtime  ){
  //mace::ContextJobApplication<Service> app;
  mace::ContextJobApplication<Service, DataHandler<Service> > app;
  app.installSignalHandler();

  params::print(stdout);

  app.loadContext();

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  DataHandler<Service> dh;
  dh.setService( app.getServiceObject() );

  //app.template startService<ServCompUpcallHandler>( service, &dh );
  app.startService( service, &dh );
  app.getServiceObject()->test(5);
  app.waitService( runtime );

  app.globalExit();

  delete app.getServiceObject() ;
  //SysUtil::sleepm( 1000 ); // sleep for one second
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
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 2) * 1000 * 1000);
  switch( test_case ){
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
      break;
    case 5:
      service = "TestCase5";
      launchTestCase<MigrationTestServiceClass>( service, runtime );
      break;
    case 6:
      service = "TestCase6";
      launchTestCase<MigrationTestServiceClass>( service, runtime );
      break;
    case 7:
      service = "TestCase7";
      launchTestCase<MigrationTestServiceClass>( service, runtime );
      break;
  }
  //mace::Shutdown();
  //kill( getpid() , SIGTERM );

  return 0;
}
