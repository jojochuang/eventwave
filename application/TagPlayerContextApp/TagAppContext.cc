#include "SysUtil.h"
#include "Util.h"
#include "TagPlayerServiceClass.h"
#include "lib/mace.h"
#include "lib/params.h"
#include "TagPlayerContext-init.h"
#include "load_protocols.h"
#include <sys/time.h>
#include <stdio.h>

using namespace std;

#define BUILDING_NUM 2
#define ROOM_NUM 2
 
class TagPlayerResponseHandler :public TagPlayerDataHandler {
   void printmsg(mace::string message,registration_uid_t rid){
     cout << " MESSAGE: " << message <<endl;
   }
   void printkidNum(uint16_t kidNum, registration_uid_t rid) {
     cout << " How many kids in this room: " << kidNum <<endl;
   }
};
 
int main(int argc, char* argv[])
{
  
  //time_t time0, time1;
  //uint16_t direction;
  //uint16_t newBuilding, newRoom;
  uint16_t node_id;
 // uint16_t action;
  
  mace::Init(argc, argv);
  load_protocols();
  //params::loadparams(argc,argv);

  //get the mace port
  node_id = params::get<uint16_t>("node_id");
  std::string port_string = boost::lexical_cast<std::string>(5377+node_id*5);
  //std::string server_string = "cloud01:"
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
  TagPlayerResponseHandler tprh;
  TagPlayerServiceClass& tagplayer = TagPlayerContext_namespace::new_TagPlayerContext_TagPlayer();
  tagplayer.maceInit();



//  cout<<"Finish Initial."<<endl;
  //tagplayer.registerUniqueHandler(tprh);
  
  //node_id = 1;
  /*direction = node_id%5;
  srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM+1;
       srand(time(NULL));
       newRoom = rand()%ROOM_NUM +1;
  tagplayer.movePlayer(node_id,direction);
  tagplayer.changeRoom(node_id,newBuilding,newRoom);
  SysUtil::sleep(2);	
  tagplayer.requireRoomMap(node_id,newBuilding,newRoom);*/
  //while(1){
    // timeval tim;
  //gettimeofday(&tim, NULL);
  //double t1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    //srand(time(NULL));
     //action = rand()%4;
     //srand(time(NULL));
      // newBuilding = rand()% BUILDING_NUM+1;
       //srand(time(NULL));
       //newRoom = rand()%ROOM_NUM +1;
   //tagplayer.changeRoom(node_id,newBuilding,newRoom);
    // for(uint16_t i=0;i<2;i++)
     //{
     //srand(time(NULL));
     
     //cout <<"ID:"<< node_id << endl;
    
     
     //SysUtil::sleep(2);
     //tagplayer.requireRoomMap(node_id,newBuilding,newRoom);
     //tagplayer.sendmsg(node_id);
     /*if(action==0 || action ==3)
     {
     	tagplayer.movePlayer(node_id+1,direction);
        srand(time(NULL));
        direction = rand()%5;
     	tagplayer.movePlayer(node_id+1,direction);
        
     }
     else if(action==1)
     {
       srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM+1;
       srand(time(NULL));
       newRoom = rand()%ROOM_NUM +1;
       tagplayer.changeRoom(node_id,newBuilding,newRoom);
       SysUtil::sleep(2);
       tagplayer.requireRoomMap(node_id,newBuilding,newRoom);
       
     }
     else if(action==2)
     {
       srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM;
       newRoom = rand()%ROOM_NUM;
       //
       tagplayer.requireRoomMap(node_id,newBuilding,newRoom);

     }*/
     /*else if(action==3)
     {
       tagplayer.checkKidNum(node_id+1,newBuilding,newRoom);
     }*/
     //}
  //}
  /* gettimeofday(&tim, NULL);
  double t2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
  printf("%.6lf seconds elapsed\n", t2 - t1);*/
  
  SysUtil::sleep();						                          
  tagplayer.maceExit();
  SysUtil::sleepm(1000);
  mace::Shutdown();
  return 0;
 
}
