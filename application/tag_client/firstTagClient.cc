#include "SysUtil.h"
#include "Util.h"
#include "TagClientServiceClass.h"
#include "lib/mace.h"
#include "lib/params.h"
#include "TagClient-init.h"
#include "load_protocols.h"
#include <sys/time.h>
#include <stdio.h>

using namespace std;

#define BUILDING_NUM 2
#define ROOM_NUM 2
 
int main(int argc, char* argv[])
{
  
  uint16_t node_id;
  
  mace::Init(argc, argv);
  load_protocols();

  //get the mace port
  node_id = params::get<uint16_t>("node_id");
  std::string port_string = boost::lexical_cast<std::string>(5377+node_id*5);
  params::set("MACE_PORT", port_string);
  params::print(stdout);
  //store all the players' ID and the MaceKey
  if( params::get<bool>("TRACE_ALL",false) == true )
      Log::autoAdd(".*");
  else if( params::containsKey("TRACE_SUBST") ){
    std::istringstream in( params::get<std::string>("TRACE_SUBST") );
      while(in){
        std::string logPattern;
        in >> logPattern;
        if( logPattern.length() == 0 ) break;
          Log::autoAdd(logPattern);
        }
  }

  
  load_protocols();
  //initial the service
  NullServiceClass& tagClient = TagClient_namespace::new_TagClient_Null();
  tagClient.maceInit();
  SysUtil::sleep();						                          
  return 0;
 
}
