#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ThreadStructure.h"
#include "HighLevelEvent.h"
#include "ContextLock.h"
#include "ReadLine.h"
#include "ContextMapping.h"
#include "mace.h"
BOOST_AUTO_TEST_SUITE( lib_ReadLine )

BOOST_AUTO_TEST_CASE( Case1 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  ctxSet.insert(""); // global

  contextIDs[ serviceID ] = ctxSet;

  //mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
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
  
  mace::ReadLine rl( contextMapping );
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), nm.second );
}

BOOST_AUTO_TEST_CASE( Case2 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 8;
  const char* contexts1[] = {"", "R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::ASYNCEVENT );
  currentEvent.eventContexts = contextIDs;
  ThreadStructure::setEvent( currentEvent );
  //currentEvent.eventID = 1;

  mace::ContextMapping contextMapping;
  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  for( uint32_t c = 0; c< setSize; c++ ) {
    const std::pair< mace::MaceAddr, uint32_t> nm = contextMapping.newMapping( contexts1[c] );
  }
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping);
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), contextMapping.findIDByName("") );
}
BOOST_AUTO_TEST_CASE( Case3 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 7;
  const char* contexts1[] = {"R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::ASYNCEVENT );
  currentEvent.eventContexts = contextIDs;
  ThreadStructure::setEvent( currentEvent );

  mace::ContextMapping contextMapping;
  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  const std::pair< mace::MaceAddr, uint32_t> nm = contextMapping.newMapping( "" );
  for( uint32_t c = 0; c< setSize; c++ ) {
    const std::pair< mace::MaceAddr, uint32_t> nm = contextMapping.newMapping( contexts1[c] );
  }
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping );
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(5) );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[0]") )      != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[1]") )      != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[2]") )      != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("T") )         != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("M[0,0]") )    != cutSet.end() );
}

BOOST_AUTO_TEST_CASE( Case4 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 14;
  const char* contexts1[] = {"R[1]", "R[2]", "R[0].C[0]", "R[0].C[1]", "R[0].C[2]", "R[0].C[3]", "R[1].C[0]", "R[1].C[1]", "R[1].C[2]", "R[1].C[3]","R[2].C[0]", "R[2].C[1]", "R[2].C[2]", "R[2].C[3]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::ASYNCEVENT );
  currentEvent.eventContexts = contextIDs;
  ThreadStructure::setEvent( currentEvent );
  
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::ContextMapping contextMapping;
  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  const std::pair< mace::MaceAddr, uint32_t> nm  = contextMapping.newMapping( "" );
  const std::pair< mace::MaceAddr, uint32_t> nm2 = contextMapping.newMapping( "R[0]" );
  for( uint32_t c = 0; c< setSize; c++ ) {
    const std::pair< mace::MaceAddr, uint32_t> nm = contextMapping.newMapping( contexts1[c] );
  }
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );
  
  mace::ReadLine rl(contextMapping);
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(6) );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[0].C[0]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[0].C[1]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[0].C[2]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[0].C[3]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[1]") )      != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("R[2]") )      != cutSet.end() );
}
// indirect ancestor contexts
// this is often encountered for sync calls.
BOOST_AUTO_TEST_CASE( Case5 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 2;
  const char* contexts1[] = {"", "Build[0].Aisle" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::ASYNCEVENT );
  currentEvent.eventContexts = contextIDs;
  ThreadStructure::setEvent( currentEvent );

  mace::ContextMapping contextMapping;
  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  const std::pair< mace::MaceAddr, uint32_t> nm  = contextMapping.newMapping( "" );
  const std::pair< mace::MaceAddr, uint32_t> nm2 = contextMapping.newMapping( "Build[0]" );
  const std::pair< mace::MaceAddr, uint32_t> nm3 = contextMapping.newMapping( "Build[0].Aisle" );
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping);
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), contextMapping.findIDByName("") );
}
BOOST_AUTO_TEST_CASE( Case6 )
{
  const uint32_t serviceID = 0;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::map<uint8_t, mace::map<mace::string, mace::string> > snapshot_contextIDs;
  mace::set<mace::string> ctxSet;
  mace::map<mace::string, mace::string> snapshot_ctxSet;

  const uint32_t setSize = 1;
  const char* contexts1[] = {"Worker[4]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );
  contextIDs[ serviceID ] = ctxSet;

  const uint32_t setSize2 = 1;
  const char* contexts2[] = {"" };
  for( uint32_t c = 0; c< setSize2; c++ ) {
    snapshot_ctxSet[  contexts2[c] ] = "";
  }
  snapshot_contextIDs[ serviceID ] = snapshot_ctxSet;

  mace::HighLevelEvent currentEvent( mace::HighLevelEvent::ASYNCEVENT );
  currentEvent.eventContexts = contextIDs;
  currentEvent.eventSnapshotContexts = snapshot_contextIDs;
  ThreadStructure::setEvent( currentEvent );

  mace::ContextMapping contextMapping;
  ThreadStructure::newTicket();
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  contextMapping.setDefaultAddress( Util::getMaceAddr() );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );
  const std::pair< mace::MaceAddr, bool> result1 = contextMapping.newMapping("");
  const std::pair< mace::MaceAddr, bool> result2 = contextMapping.newMapping("Worker[0]");
  const std::pair< mace::MaceAddr, bool> result3 = contextMapping.newMapping("Worker[1]");
  const std::pair< mace::MaceAddr, bool> result4 = contextMapping.newMapping("Worker[2]");
  const std::pair< mace::MaceAddr, bool> result5 = contextMapping.newMapping("Worker[3]");
  const std::pair< mace::MaceAddr, bool> result6 = contextMapping.newMapping("Worker[4]");
  contextMapping.snapshot();
  c_lock.downgrade( mace::ContextLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping);
  const mace::list< uint32_t >& cutSet = rl.getCut();
  
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("Worker[0]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("Worker[1]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("Worker[2]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("Worker[3]") ) != cutSet.end() );
  BOOST_REQUIRE( std::find( cutSet.begin(), cutSet.end(), contextMapping.findIDByName("Worker[4]") ) != cutSet.end() );
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(5) );
}
// TODO: contexts already downgraded?
BOOST_AUTO_TEST_SUITE_END()
