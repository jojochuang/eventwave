#include <math.h>

#include "lib/Log.h"
#include "lib/mace.h"
#include "lib/TimeUtil.h"
#include "lib/params.h"
#include "lib/mlist.h"
#include "lib/mvector.h"
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


//typedef mace::list<mace::string> StringList;
//typedef mace::vector<StringList> StringListVector;
typedef mace::vector<mace::list<mace::string> > StringListVector;
typedef mace::vector<mace::string> StringVector;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while(std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
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

  //uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 2) * 1000 * 1000);
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 0) * 1000 * 1000);
  mace::string service = params::get<mace::string>("service");

  NodeSet ns = params::get<NodeSet>("nodeset");

  StringVector mapping = split(params::get<mace::string>("mapping"), '\n');

  mace::ContextJobApplication<MigrationTestServiceClass> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;

  StringListVector node_context;

  ASSERT(ns.size() > 0);
  for( uint32_t i=0; i<ns.size(); i++ ) {
    mace::list<mace::string> string_list;
    node_context.push_back(string_list);
  }
  //node_context.reserve(ns.size());

  //mace::list<mace::string> node1Context;
  //mace::list<mace::string> node2Context;
  //mace::list<mace::string> node3Context;
  //mace::list<mace::string> node4Context;
  //mace::list<mace::string> node5Context;

  // Set for head node
  node_context[0].push_back( mace::ContextMapping::getHeadContext() ); //head context
  node_context[0].push_back( "" ); // global
    //node1Context.push_back( mace::ContextMapping::getHeadContext() ); //head context
    //node1Context.push_back( "" ); // global

  // key:value
  // context_peer_id:context_value
  // 2:A[0] 2:A[1] ...
  
  for( StringVector::const_iterator it = mapping.begin(); it != mapping.end(); it++ ) {
    StringVector kv = split(*it, ':');
    ASSERT(kv.size() == 2);
    
    uint32_t key;
    istringstream(kv[0]) >> key;
    ASSERT(key > 0 && key < ns.size());
    node_context[key].push_back(kv[1]);

    //node2Context.push_back( "A[0]" );
    //node2Context.push_back( "A[1]" );
    //node2Context.push_back( "A[2]" );
    //node2Context.push_back( "A[3]" );

    //node2Context.push_back( "A[4]" );
    //node2Context.push_back( "A[5]" );
    //node2Context.push_back( "A[6]" );
    //node2Context.push_back( "A[7]" );

    //node3Context.push_back( "A[8]" );
    //node3Context.push_back( "A[9]" );
    //node3Context.push_back( "A[10]" );
    //node3Context.push_back( "A[11]" );

    //node3Context.push_back( "A[12]" );
    //node3Context.push_back( "A[13]" );
    //node3Context.push_back( "A[14]" );
    //node3Context.push_back( "A[15]" );
  }

  ContextMappingType contextMap;

  int i=0;
  for( NodeSet::iterator it = ns.begin(); it != ns.end(); it++ ) {
    contextMap[ (*it).getMaceAddr() ] = node_context[ i++ ];
  }

  mace::map< mace::string, ContextMappingType > contexts;
  contexts[ service ] = contextMap;

  app.loadContext( contexts );



    //MaceAddr node1Addr = Util::getMaceAddr("cloud02:6000");
    //MaceAddr node2Addr = Util::getMaceAddr("cloud03:6000");
    //MaceAddr node3Addr = Util::getMaceAddr("cloud04:6000");
    //MaceAddr node4Addr = Util::getMaceAddr("cloud05:6000");
    //MaceAddr node5Addr = Util::getMaceAddr("cloud06:6000");

    //ContextMappingType contextMap;
    //contextMap[ node1Addr ] = node1Context;
    //contextMap[ node2Addr ] = node2Context;
    //contextMap[ node3Addr ] = node3Context;
    //contextMap[ node4Addr ] = node4Context;
  //}

  //app.loadContext();


  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service );
  app.waitService( runtime );
  std::cout << "Exiting at time " << TimeUtil::timeu() << std::endl;

  app.globalExit();

  return 0;
}





