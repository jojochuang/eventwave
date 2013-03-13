#include "Event.h"
#include "ThreadStructure.h"
using namespace mace;
int main(){

  Event e( Event::STARTEVENT );
  uint8_t sid = 0;

  uint32_t ctxid = 1;

  e.eventContexts[sid].insert( ctxid );
  for( uint32_t count = 0;  count < 1000*1000*10; count++ ){
    ThreadStructure::setEvent( e );
  }


  /*Event e2( Event::STARTEVENT );
  // test speed.
  while( count < 1000*1000 ){
    e.eventContexts[sid].insert( 1 );
    e.eventContexts.clear();
  }*/
}
