
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ThreadStructure.h"
#include "HighLevelEvent.h"
#include "ContextLock.h"
#include "AccessLine.h"
#include "ContextMapping.h"
#include "mace.h"
BOOST_AUTO_TEST_SUITE( lib_AccessLine )

BOOST_AUTO_TEST_CASE( Case1 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  ctxSet.insert(""); // global

  contextIDs[ serviceID ] = ctxSet;
  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::STARTEVENT );
  currentEvent.eventContexts = contextIDs;
  ThreadStructure::setEvent( currentEvent );
  //currentEvent.eventID = 1;
  mace::ContextMapping contextMapping;

  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  mace::HighLevelEvent::setLastContextMappingVersion( currentEvent.eventID );
  const std::pair< mace::MaceAddr, uint32_t> nm = contextMapping.newMapping( "" );
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );

  const ContextMapping& currentMapping = contextMapping.getSnapshot();
  

  AccessLine al(1, currentMapping);
}
BOOST_AUTO_TEST_SUITE_END()
