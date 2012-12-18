#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "HeadEventDispatch.h"

BOOST_AUTO_TEST_SUITE( lib_HeadEventDispatch )

int x = 1;
class Obj: public AsyncEventReceiver{
public:
  void startEvent(){
    HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&Obj::handler, (void*)&x );
  }
  void handler(void* param){
    /*int& val = *((int*)param);
     ASSERT( val == 1 );
      val = 2;*/
  }
};
BOOST_AUTO_TEST_CASE( test1 )
{
  HeadEventDispatch::init();
  Obj o;
  o.startEvent();

  BOOST_REQUIRE_EQUAL( true, true );
}
BOOST_AUTO_TEST_SUITE_END()
