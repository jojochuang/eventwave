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
#include "boost/format.hpp"


template <class Service> 
void launchTestCase(const mace::string& service, const uint64_t runtime  ){
  mace::ContextJobApplication<Service> app;
  app.installSignalHandler();

  params::print(stdout);

  app.loadContext();

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  if( params::get("use_console", false) == true ){
    app.createConsole();
  }
  app.startService( service );
  app.setTimedMigration();
  app.waitService( runtime );

  //app.globalExit();
}

pthread_mutex_t lock;
uint64_t lastApplicationUpcallTicket = 0;
template<class Service>
class DataHandler: public ServCompUpcallHandler {
public:
  void setService( Service* servobj ){ this->servobj = servobj; }

  ~DataHandler(){
    ADD_FUNC_SELECTORS

    macedbg(1)<<"data handler is deallocated"<<Log::endl;
  }
private:
  Service* servobj;

  void respond ( uint32_t param, registration_uid_t rid = -1){
    ADD_FUNC_SELECTORS
  }

  uint32_t ask( uint32_t param, registration_uid_t rid = -1){
    ADD_FUNC_SELECTORS

    // correctness: synchronous application upcall must proceed in the order of event ticket.
    ScopedLock sl( lock );

    ASSERT( ThreadStructure::myEvent().eventID >= lastApplicationUpcallTicket );

    lastApplicationUpcallTicket = ThreadStructure::myEvent().eventID;

    return param;
  }

};
template <class Service> 
void launchUpcallTestCase(const mace::string& service, const uint64_t runtime  ){
  DataHandler<Service> dh;
  mace::ContextJobApplication<Service, DataHandler<Service> > app;
  app.installSignalHandler();

  params::print(stdout);
  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  dh.setService( app.getServiceObject() );

  app.loadContext();
  app.startService( service, &dh );
  app.waitService( runtime );
}
void writeOutProf( int signum ){
  exit(EXIT_SUCCESS);
}
/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  SysUtil::signal( SIGINT, writeOutProf ); // intercept ctrl+c and call exit to force gprof output
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
      launchUpcallTestCase<ServCompServiceClass>( service, runtime );
      break;
    case 6:
      service = "TestCase6";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
    case 7:
      service = "TestCase7";
      launchTestCase<NullServiceClass>( service, runtime );
      break;
  }
  //mace::Shutdown();
  //kill( getpid() , SIGTERM );

  return 0;
}
