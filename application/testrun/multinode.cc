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
#include "boost/format.hpp"


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
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 2) * 1000 * 1000);
  service = "TestCase6";
  mace::ContextJobApplication<MigrationTestServiceClass> app;
  app.installSignalHandler();

  params::print(stdout);

  //if( params::get("head", false) ){
    // use static mapping
    typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
    mace::list<mace::string> node1Context;
    mace::list<mace::string> node2Context;
    mace::list<mace::string> node3Context;
    mace::list<mace::string> node4Context;
    mace::list<mace::string> node5Context;

    node1Context.push_back( mace::ContextMapping::getHeadContext() ); //head context
    node1Context.push_back( "" ); // global

    /*node2Context.push_back( "A[0]" );
    node2Context.push_back( "A[1]" );
    node2Context.push_back( "A[2]" );
    node2Context.push_back( "A[3]" );

    node3Context.push_back( "A[4]" );
    node3Context.push_back( "A[5]" );
    node3Context.push_back( "A[6]" );
    node3Context.push_back( "A[7]" );

    node4Context.push_back( "A[8]" );
    node4Context.push_back( "A[9]" );
    node4Context.push_back( "A[10]" );
    node4Context.push_back( "A[11]" );

    node5Context.push_back( "A[12]" );
    node5Context.push_back( "A[13]" );
    node5Context.push_back( "A[14]" );
    node5Context.push_back( "A[15]" );*/
    node2Context.push_back( "A[0]" );
    node2Context.push_back( "A[1]" );
    node2Context.push_back( "A[2]" );
    node2Context.push_back( "A[3]" );

    node2Context.push_back( "A[4]" );
    node2Context.push_back( "A[5]" );
    node2Context.push_back( "A[6]" );
    node2Context.push_back( "A[7]" );

    node3Context.push_back( "A[8]" );
    node3Context.push_back( "A[9]" );
    node3Context.push_back( "A[10]" );
    node3Context.push_back( "A[11]" );

    node3Context.push_back( "A[12]" );
    node3Context.push_back( "A[13]" );
    node3Context.push_back( "A[14]" );
    node3Context.push_back( "A[15]" );

    MaceAddr node1Addr = Util::getMaceAddr("cloud02:6000");

    MaceAddr node2Addr = Util::getMaceAddr("cloud03:6000");

    MaceAddr node3Addr = Util::getMaceAddr("cloud04:6000");

    MaceAddr node4Addr = Util::getMaceAddr("cloud05:6000");

    MaceAddr node5Addr = Util::getMaceAddr("cloud06:6000");

    ContextMappingType contextMap;
    contextMap[ node1Addr ] = node1Context;
    contextMap[ node2Addr ] = node2Context;
    contextMap[ node3Addr ] = node3Context;
    contextMap[ node4Addr ] = node4Context;
    mace::map< mace::string, ContextMappingType > contexts;
    contexts[ service ] = contextMap;

    app.loadContext( contexts );
  //}

  //app.loadContext();


  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service );
  app.waitService( runtime );

  app.globalExit();

  return 0;
}
