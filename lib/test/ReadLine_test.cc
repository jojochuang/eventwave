#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ThreadStructure.h"
#include "ReadLine.h"
BOOST_AUTO_TEST_SUITE( lib_ReadLine )

BOOST_AUTO_TEST_CASE( Case1 )
{
  ThreadStructure::ScopedServiceInstance si( 1 );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  ctxSet.insert(""); // global

  contextIDs[ 1 ] = ctxSet;

  ThreadStructure::setEventContexts(contextIDs);
  
  mace::ReadLine rl;
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), mace::string("") );
}

BOOST_AUTO_TEST_SUITE_END()
