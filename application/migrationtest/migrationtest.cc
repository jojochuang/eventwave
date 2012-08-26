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
void launchMigrationTestCase(const mace::string& service, const uint64_t runtime, const bool resume  ){
  mace::ContextJobApplication<Service, DataHandler> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
    // create initial context mapping
    mace::list<mace::string> localContexts;
    mace::list<mace::string> remoteContexts;
    localContexts.push_back( mace::ContextMapping::getHeadContext() ); //head context
    localContexts.push_back( "" ); // global
    localContexts.push_back( "A[0]" ); 

    remoteContexts.push_back( "A[1]" ); 
    remoteContexts.push_back( "A[2]" ); 
    localContexts.push_back( "A[3]" ); 

    ContextMappingType contextMap;
    MaceAddr localAddr = Util::getMaceAddr();
    localAddr.local.port = static_cast<uint16_t>( 5000 );
    MaceAddr remoteAddr = Util::getMaceAddr();
    remoteAddr.local.port = static_cast<uint16_t>( 5005 );

    contextMap[ localAddr ] = localContexts;
    contextMap[ remoteAddr ] = remoteContexts;
    mace::map< mace::string, ContextMappingType > contexts;
    contexts[ service ] = contextMap;
  if( resume ){
    app.loadContext(contexts);
  }else{
    app.loadContext(contexts);
  }
  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  DataHandler dh;

  // create new thread. one is used to launch the service, one is to initiates the migration request.
  //pthread_create( &sourceThread, NULL, startSourceProcess, (void *)NULL );

  if( resume ){
  app.startService( service, &dh );
  }else{
    uint32_t migration_start = params::get<uint32_t>("migration_start",1);
    //SysUtil::sleepm( 1000* migration_start ); // sleep for one second
  app.startService( service, &dh );
    MaceAddr destAddr = Util::getMaceAddr();
    destAddr.local.port = static_cast<uint16_t>( 5005 );
    //BaseMaceService* serv = dynamic_cast<BaseMaceService*>(app.getServiceObject());
    uint8_t serviceID = 0; // 
    //serv->requestContextMigration( serviceID, "A", destAddr, false );
    
    SysUtil::sleepm( 1000* migration_start ); // sleep for one second
    app.getServiceObject()->requestContextMigration( serviceID, "A[0]", destAddr, false );
    /*app.getServiceObject()->requestContextMigration( serviceID, "A[1]", destAddr, false );
    app.getServiceObject()->requestContextMigration( serviceID, "A[2]", destAddr, false );
    app.getServiceObject()->requestContextMigration( serviceID, "A[3]", destAddr, false );*/
  }
  app.waitService( runtime );

  if( !resume ){ // head node sents exit event
    //mace::HierarchicalContextLock::exit();
    app.globalExit();
  }
}
mace::string setServiceName(){

  mace::string service;
  uint32_t test_case = params::get<uint32_t>("test_case");
  switch( test_case ){
    case 5:
      service = "TestCase5";
      break;
    case 6:
      service = "TestCase6";
      break;
  }
  return service;
}
/*pthread_t sourceThread;
void* startSourceProcess(void *p ){
    pthread_exit(NULL);
    return NULL;
}*/
void startMigrationDestinationProcess( ){
  //pid_t pid;
  mace::string service = setServiceName();
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
  
  int master = (int)( params::get<int>("master") );
  if( !master ){
  //if( (pid = fork() ) == 0 ){
    // new process
    // the process is also part of the virtual node, except that no contexts are assigned to this node at beginning
    params::set("MACE_PORT", "5005");
    launchMigrationTestCase<MigrationTestServiceClass>( service, runtime, true );
  }else{
  //}else{ // old process
    params::set("MACE_PORT", "5000");
    launchMigrationTestCase<MigrationTestServiceClass>( service, runtime, false );
  //}
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

  //kill( getpid() , SIGTERM );
  return 0;
}
