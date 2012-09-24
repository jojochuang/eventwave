#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ThreadStructure.h"
#include "HighLevelEvent.h"
#include "ReadLine.h"
#include "ContextMapping.h"
#include "HierarchicalContextLock.h"
#include "mace.h"



BOOST_AUTO_TEST_SUITE( lib_HierarchicalContextLock )

BOOST_AUTO_TEST_CASE( Case1 )
{
  mace::HighLevelEvent he( mace::HighLevelEvent::STARTEVENT );

  mace::string str;
  mace::HierarchicalContextLock( he, str );

  mace::HierarchicalContextLock::commit(he.eventID);
}
BOOST_AUTO_TEST_SUITE_END()
