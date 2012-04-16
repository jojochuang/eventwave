#include "SysUtil.h"
#include "Util.h"
#include "TagPlayerServiceClass.h"
#include "lib/mace.h"
#include "lib/params.h"
#include "TagPlayer-init.h"
#include "load_protocols.h"

using namespace std;

#define BUILDING_NUM 3
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
  uint16_t direction;
  uint16_t newBuilding, newRoom;
  uint16_t node_id,action;
  
  params::loadparams(argc,argv);

  load_protocols();
  //initial the service
  TagPlayerResponseHandler tprh;
  TagPlayerServiceClass& tagplayer = TagPlayer_namespace::new_TagPlayer_TagPlayer();
  tagplayer.maceInit();
  tagplayer.registerUniqueHandler(tprh);
  
  while(1){
     srand(time(NULL));
     node_id = rand()%10;
     srand(time(NULL));
     action = rand()%3;
     if(action==0)
     {
     	//tagplayer.movePlayer(node)id+1,direction);
        srand(time(NULL));
        direction = rand()%5;
     	tagplayer.movePlayer(node_id+1,direction);
        
     }
     else if(action==1)
     {
       srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM;
       newRoom = rand()%ROOM_NUM;
       tagplayer.changeRoom(node_id+1,newBuilding,newRoom);
       
     }
     else if(action==2)
     {
       srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM;
       newRoom = rand()%ROOM_NUM;
       tagplayer.checkKidNum(newBuilding,newRoom);

     }
  }
  
  SysUtil::sleep();						                          
  return 0;
 
}
