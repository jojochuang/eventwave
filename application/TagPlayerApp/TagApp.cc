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
  
  params::loadparams(argc,argv);

  load_protocols();
  //initial the service
  TagPlayerResponseHandler tprh;
  TagPlayerServiceClass& tagplayer = TagPlayer_namespace::new_TagPlayer_TagPlayer();
  tagplayer.maceInit();
  //cout<<"Finish Initial."<<endl;
  tagplayer.registerUniqueHandler(tprh);
  //node_id = 1;
  //direction = 0;
  //tagplayer.movePlayer(node_id,direction);
  //tagplayer.changeRoom(1,1,1);
  tagplayer.requireRoomMap(1,1,1);
  SysUtil::sleep();						                          
  return 0;
 
}
