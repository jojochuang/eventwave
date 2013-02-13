#include "SysUtil.h"
#include "Util.h"
#include "TagPlayerServiceClass.h"
#include "lib/mace.h"
#include "lib/params.h"
#include "TagPlayer-init.h"
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
  //uint16_t node_id;
  
  params::loadparams(argc,argv);

  load_protocols();
  //initial the service
  TagPlayerResponseHandler tprh;
  TagPlayerServiceClass& tagplayer = TagPlayer_namespace::new_TagPlayer_TagPlayer();
  tagplayer.maceInit();
//  cout<<"Finish Initial."<<endl;
  tagplayer.registerUniqueHandler(tprh);
  //node_id = 1;
  //direction = 0;
  //tagplayer.movePlayer(node_id,direction);
  //tagplayer.changeRoom(1,1,1);
  tagplayer.requireRoomMap(1,1,1);
  /*while(1){
     timeval tim;
  gettimeofday(&tim, NULL);
  double t1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
     for(uint64_t i=0;i<10000;i++)
     {
     srand(time(NULL));
     
     cout <<"ID:"<< node_id << endl;
     srand(time(NULL));
     
     if(action==0)
     {
     	tagplayer.movePlayer(node)id+1,direction);
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
       tagplayer.requireRoomMap(node_id,newBuilding,newRoom);
       
     }
     else if(action==2)
     {
       srand(time(NULL));
       newBuilding = rand()% BUILDING_NUM;
       newRoom = rand()%ROOM_NUM;
       tagplayer.checkKidNum(node_id+1,newBuilding,newRoom);
      

     }
     }*/
  /* gettimeofday(&tim, NULL);
  double t2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
  printf("%.6lf seconds elapsed\n", t2 - t1);*/
  
  SysUtil::sleep();						                          
  return 0;
 
}
