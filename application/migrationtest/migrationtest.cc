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

void loadContextFromParam( const mace::string& service, mace::map< mace::string, ContextMappingType >& contexts, mace::map< mace::string, MaceAddr>& migrateContexts){
  NodeSet ns = params::get<NodeSet>("nodeset");

  StringVector mapping = split(params::get<mace::string>("mapping"), '\n');

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
  std::vector< MaceAddr > nodeAddrs;
  for( NodeSet::iterator it = ns.begin(); it != ns.end(); it++ ) {
    std::cout << "nodeset[" << i << "] = " << *it << std::endl;
    contextMap[ (*it).getMaceAddr() ] = node_context[ i++ ];
    nodeAddrs.push_back(  (*it).getMaceAddr() );
  }

  contexts[ service ] = contextMap;

  StringVector migrate = split(params::get<mace::string>("migrate"), '\n');
  for( StringVector::const_iterator it = migrate.begin(); it != migrate.end(); it++ ) {
    StringVector kv = split(*it, ':');
    ASSERT(kv.size() == 2);
    
    uint32_t key;
    istringstream(kv[0]) >> key;
    ASSERT(key >= 0 && key < ns.size());
    migrateContexts[ kv[1] ] =  nodeAddrs[key];
  }
}

template <class Service> 
void launchMigrationTestCase(const mace::string& service, const uint64_t runtime, const bool ishead  ){
  mace::ContextJobApplication<Service, DataHandler> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
  mace::map< mace::string, ContextMappingType > contexts;
  mace::map< mace::string, MaceAddr> migrateContexts;
  if( !ishead ){
    NodeSet ns = params::get<NodeSet>("nodeset");
    ASSERT(ns.size() > 0);
    ContextMappingType contextMap;
    MaceAddr headAddr =  ns.begin()->getMaceAddr();
    contextMap[ headAddr  ].push_back( mace::ContextMapping::getHeadContext() ); // set head node macekey
    contexts[ service ] = contextMap;
    app.loadContext(contexts);
  }else{
    loadContextFromParam( service,  contexts, migrateContexts );
    app.loadContext(contexts);
  }
  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  DataHandler dh;

  // create new thread. one is used to launch the service, one is to initiates the migration request.

  if( !ishead ){
    app.startService( service, &dh );
  }else{
    app.startService( service, &dh );
    /*MaceAddr destAddr = Util::getMaceAddr();
    destAddr.local.port = static_cast<uint16_t>( 5005 );*/
    uint8_t serviceID = 0; 
    
    uint32_t migration_start = params::get<uint32_t>("migration_start",1);
    SysUtil::sleepm( 1000* migration_start ); // sleep for one second

    for( mace::map< mace::string, MaceAddr>::iterator migctxIt = migrateContexts.begin(); migctxIt != migrateContexts.end(); migctxIt++ ){
      app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
      //app.getServiceObject()->requestContextMigration( serviceID, "", destAddr, false );
    }
  }
  app.waitService( runtime );

  if( ishead ){ // head node sents exit event
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
  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 10) * 1000 * 1000);
  
  int master = (int)( params::get<int>("master") );
  launchMigrationTestCase<MigrationTestServiceClass>( service, runtime, master );

  return 0;
}
