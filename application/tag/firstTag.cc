#include "SysUtil.h"
#include "lib/mace.h"

#include "TcpTransport-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>
#include "mlist.h"

#include "RandomUtil.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
//#include "TagServiceClass.h"
//#include "Tag-init.h"
#include "ContextJobApplication.h"
#include "../services/interfaces/NullServiceClass.h"
 
using namespace std;
 
/*class TagResponseHandler : public TagDataHandler {
 
};*/ 
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

void loadContextFromParam( const mace::string& service, mace::map< mace::string, ContextMappingType >& contexts, mace::map< mace::string, MaceAddr>& migrateContexts, mace::map< mace::string, MaceAddr>& migrateContexts2 ){
  if( ! params::containsKey("nodeset") || ! params::containsKey("mapping") ){
    return;
  }
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

  if( params::containsKey("migrateBatch") ){
    // create a number of migrations 
    StringVector migrateBatch = split(params::get<mace::string>("migrateBatch"), ':');
    std::string contextName = migrateBatch[0];
    uint32_t migrateFrom = atoi( migrateBatch[1].c_str() );
    uint32_t migrateTo = atoi( migrateBatch[2].c_str() );
    uint32_t nodeID = atoi( migrateBatch[3].c_str() );

    for( uint32_t index = migrateFrom; index <= migrateTo; index++ ){
      std::ostringstream oss;
      oss << contextName << "[" << index << "]";
      migrateContexts[ oss.str() ] = nodeAddrs[ nodeID ];
    }

  }else{

    if( !params::containsKey("migrate") ) return;
    StringVector migrate = split(params::get<mace::string>("migrate"), '\n');
    for( StringVector::const_iterator it = migrate.begin(); it != migrate.end(); it++ ) {
      StringVector kv = split(*it, ':');
      ASSERT(kv.size() == 2);
      
      uint32_t key;
      istringstream(kv[0]) >> key;
      ASSERT(key >= 0 && key < ns.size());
      migrateContexts[ kv[1] ] =  nodeAddrs[key];
    }

    if ( !params::containsKey("migrate2") ) return;
    StringVector migrate2 = split(params::get<mace::string>("migrate2"), '\n');
    for( StringVector::const_iterator it = migrate2.begin(); it != migrate2.end(); it++ ) {
      StringVector kv = split(*it, ':');
      ASSERT(kv.size() == 2);
      
      uint32_t key;
      istringstream(kv[0]) >> key;
      ASSERT(key >= 0 && key < ns.size());
      migrateContexts2[ kv[1] ] =  nodeAddrs[key];
    }
  }

}

bool ishead = false;
void writeOutProf( int signum ){
  if( ishead ){
    std::cout<<"Head node. perform global exit and clean up"<<std::endl;
  }else{
    std::cout<<"This is not a head node! You must terminate the head node first!"<<std::endl;
  }
  exit(EXIT_SUCCESS);
}
 
int main(int argc, char* argv[]) {
  //Log::autoAdd("^Tag");
  mace::Init(argc, argv);
  load_protocols();

  if( params::get<bool>("gprof", false ) ){

    SysUtil::signal( SIGINT, writeOutProf ); // intercept ctrl+c and call exit to force gprof output
    SysUtil::signal( SIGABRT, writeOutProf ); // intercept abort and call exit to force gprof output
    SysUtil::signal( SIGSEGV, writeOutProf ); // intercept seg fault and call exit to force gprof output
  }

  uint64_t runtime =  (uint64_t)(params::get<double>("run_time", 2) * 1000 * 1000);
  mace::string service = "Tag";
  
  mace::ContextJobApplication<NullServiceClass> app;
  app.installSignalHandler();

  params::print(stdout);

  typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
  mace::map< mace::string, ContextMappingType > contexts;
  mace::map< mace::string, MaceAddr> migrateContexts;
  mace::map< mace::string, MaceAddr> migrateContexts2;
  mace::map< mace::string, MaceAddr> migrateteBackContexts;

  loadContextFromParam( service,  contexts, migrateContexts, migrateContexts2 );
  app.loadContext(contexts);

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;


  // create new thread. one is used to launch the service, one is to initiates the migration request.

  app.startService( service );

  mace::list< mace::string > &nodectx = contexts[ service ][ Util::getMaceAddr() ];
  mace::list< mace::string >::iterator it = find( nodectx.begin(), nodectx.end(), mace::ContextMapping::getHeadContext() );
  if( it != nodectx.end() ){
    ishead = true;
  }

  if( ishead ){
    uint8_t serviceID = 0; 
    
    uint32_t migration_start = params::get<uint32_t>("migration_start",1);
    SysUtil::sleepm( 1000 * migration_start ); // sleep until migration
    
    std::cout << TimeUtil::timeu() << " Migration started." << std::endl;
    for( mace::map< mace::string, MaceAddr>::iterator migctxIt = migrateContexts.begin(); migctxIt != migrateContexts.end(); migctxIt++ ){
      app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
      SysUtil::sleepm( params::get<uint32_t>("sleep", 10) ); // sleep for 0.1 second
    }

    uint32_t migration_start2 = params::get<uint32_t>("migration_start2",1);
    if( migration_start2 > migration_start ) {
      SysUtil::sleepm( 1000 * (migration_start2-migration_start) ); // sleep until second migration
      
      std::cout << TimeUtil::timeu() << " Migration2 started." << std::endl;
      for( mace::map< mace::string, MaceAddr>::iterator migctxIt = migrateContexts2.begin(); migctxIt != migrateContexts2.end(); migctxIt++ ){
        app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
        SysUtil::sleepm( params::get<uint32_t>("sleep", 10) ); // sleep for 0.1 second
      }
    } else {
      std::cout << TimeUtil::timeu() << " Migration2 will not be started." << std::endl;
    }

    //uint32_t migration_start3 = params::get<uint32_t>("migration_start3",1);
    //SysUtil::sleepm( 1000 * migration_start ); // sleep for one second
    
    //std::cout << TimeUtil::timeu() << " Migration3 started." << std::endl;
    //for( mace::map< mace::string, MaceAddr>::iterator migctxIt = migrateContexts.begin(); migctxIt != migrateContexts.end(); migctxIt++ ){
      //app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
      //SysUtil::sleepm( params::get<uint32_t>("sleep", 10) ); // sleep for 0.1 second
    //}

  }
  app.waitService( runtime );

  if( ishead ){ // head node sents exit event
    app.globalExit();
  }

  return EXIT_SUCCESS;
} 
