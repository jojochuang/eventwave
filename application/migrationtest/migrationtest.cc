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
#include "MigrationTestHandler.h"
#include "MigrationTestServiceClass.h"
#include "ContextJobApplication.h"


  class DataHandler: public MigrationTestHandler {
  public:
    //void setService( Service* servobj ){ this->servobj = servobj; }
  private:
    /*Service* servobj;
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
    }*/
  };
template <class Service> 
Service* launchMigrationTestCase(const mace::string& service, const uint64_t runtime, const bool resume  ){
  mace::ContextJobApplication<Service, DataHandler> app;
  app.installSignalHandler();

  params::print(stdout);

  if( resume ){

  }else{
    typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
    mace::list<mace::string> localContexts;
    localContexts.push_back( "" ); // global
    localContexts.push_back( "A" ); 

    ContextMappingType contextMap;
    contextMap[ Util::getMaceAddr() ] = localContexts;
    mace::map< mace::string, ContextMappingType > contexts;
    contexts[ "MigrationTest" ] = contextMap;
    app.loadContext(contexts);
  }
  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  DataHandler dh;
  //dh.setService( app.getServiceObject() );

  app.startService( service, runtime, &dh );
  //app.template startService<MigrationTestHandler>( service, runtime, &dh );

  if( !resume ){
    MaceAddr destAddr = Util::getMaceAddr();
    destAddr.local.port = static_cast<uint16_t>( 5005 );
    BaseMaceService* serv = dynamic_cast<BaseMaceService*>(app.getServiceObject());
    serv->requestContextMigration("A", destAddr, false );
  }

  return app.getServiceObject();
}
mace::string setServiceName(){

  mace::string service;
  uint32_t test_case = params::get<uint32_t>("test_case");
  switch( test_case ){
    case 5:
      service = "TestCase5";
      break;
  }
  return service;
}
void startMigrationDestinationProcess( ){
  pid_t pid;
  mace::string service = setServiceName();
  uint64_t runtime = 10*1000*1000; 
  if( (pid = fork() ) == 0 ){
    // new process
    // the process is also part of the virtual node, except that no contexts are assigned to this node at beginning
    params::set("MACE_PORT", "5005");
    launchMigrationTestCase<MigrationTestServiceClass>( service, runtime, true );
  }else{ // old process
    params::set("MACE_PORT", "5000");
    launchMigrationTestCase<MigrationTestServiceClass>( service, runtime, false );
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
  startMigrationDestinationProcess( );

  return 0;
}
