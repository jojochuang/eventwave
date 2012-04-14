#include "SysUtil.h"
#include "Util.h"
 
using namespace std;
 
class TagPlayerResponseHandler :public TagPlayerDataHandler {
   void printmsg(mace::string message,registration_uid_t rid){
     maceout << " MESSAGE: " << message <<endl;
   }
   void printkidNum(uint16_t kidNum, registration_uid_t rid) {
     maceout << " How many kids in this room: " << kidNum <<endl;
   }
}
 
int main(int argc, char* argv[])
{
  time_t time0, time1;
  uint16_t direction;
  uint16_t newBuilding, newRoom;
  
  //store all the players' ID and the MaceKey, use parameter.default

  //initial the service
  TagPlayerResponseHandler tprh;
  TagPlayerServiceClass& tagplayer = TagPlayer_namespace::new_TagPlayer_TagPlayer();
  tagplayer.maceInit();
  tagplayer.registerUniqueHandler(tprh);

  //start the testing timer
  time0 = time(NULL);
  while(1){
   time1 = time(NULL);
   //pick up a player randomly to chat
   tagplayer.sendmsg(/*MaceKey of the player that want to chat*/);

   if(difftime(time1,time0)>=5)
   {
     //random move
     srand(time(NULL));
     direction = rand()%5;
     tagPlayer.movePlayer(direction);

     
   }
   if(difftime(time1,time0)>=20)
   {
      srand(time(NULL));
      newBuilding = rand()%/*building number*/;
      newRoom = rand()%/*Room number*/;
     //random change room
     tagPlayer.changeRoom(newBuilding,newRoom);
     tagPlayer.checkKidNum(newBuilding,newRoom);
   }
   time0 = time1;
  }
  
  SysUtil::sleep();						                          
  return 0;
 
}
