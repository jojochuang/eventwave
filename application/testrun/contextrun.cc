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

  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 0) * 1000 * 1000);
  mace::string service = params::get<mace::string>("service");

  StringVector ns = split(params::get<mace::string>("nodeset"), '\n');
  //NodeSet ns = params::get<NodeSet>("nodeset");


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

  // Set for head node
  node_context[0].push_back( mace::ContextMapping::getHeadContext() ); //head context
  node_context[0].push_back( "" ); // global

  // key:value
  // context_peer_id:context_value
  // 2:A[0] 2:A[1] ...
  
  for( StringVector::const_iterator it = mapping.begin(); it != mapping.end(); it++ ) {
    StringVector kv = split(*it, ':');
    ASSERT(kv.size() == 2);
    
    uint32_t key;
    istringstream(kv[0]) >> key;
    ASSERT(key >= 0 && key < ns.size());
    node_context[key].push_back(kv[1]);
  }

  ContextMappingType contextMap;

  int i=0;

  //for( NodeSet::const_iterator it = ns.begin(); it != ns.end(); it++ ) {
  //std::cout << "nodeset[" << i << "] = " << *it << std::endl;
  //contextMap[ (*it).getMaceAddr() ] = node_context[ i++ ];
  //}
  for( StringVector::const_iterator it = ns.begin(); it != ns.end(); it++ ) {
    std::cout << "nodeset[" << i << "] = " << *it << std::endl;
    contextMap[ Util::getMaceAddr(*it) ] = node_context[ i++ ];
  }

  mace::map< mace::string, ContextMappingType > contexts;
  contexts[ service ] = contextMap;

  app.loadContext( contexts );

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service );
  app.waitService( runtime );
  std::cout << "Exiting at time " << TimeUtil::timeu() << std::endl;

  app.globalExit();

  return 0;
}





