#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ThreadStructure.h"
#include "HighLevelEvent.h"
#include "ReadLine.h"
#include "ContextMapping.h"
#include "mace.h"
BOOST_AUTO_TEST_SUITE( lib_ReadLine )

BOOST_AUTO_TEST_CASE( Case1 )
{
  ThreadStructure::ScopedServiceInstance si( 1 );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  ctxSet.insert(""); // global

  contextIDs[ 1 ] = ctxSet;

  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  mace::ContextMapping contextMapping;
  contextMapping.snapshot();
  alock.downgrade( mace::AgentLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping );
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), mace::string("") );
}

BOOST_AUTO_TEST_CASE( Case2 )
{
  const uint32_t serviceID = 1;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 8;
  const char* contexts1[] = {"", "R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  mace::ContextMapping contextMapping;
  contextMapping.snapshot();
  alock.downgrade( mace::AgentLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping);
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), mace::string("") );
}
BOOST_AUTO_TEST_CASE( Case3 )
{
  const uint32_t serviceID = 1;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 7;
  const char* contexts1[] = {"R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  mace::ContextMapping contextMapping;
  contextMapping.snapshot();
  alock.downgrade( mace::AgentLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping );
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(5) );
  BOOST_REQUIRE( cutSet.find("R[0]")      != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[1]")      != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[2]")      != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("T")         != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("M[0,0]")    != cutSet.end() );
}

BOOST_AUTO_TEST_CASE( Case4 )
{
  const uint32_t serviceID = 1;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 14;
  const char* contexts1[] = {"R[1]", "R[2]", "R[0].C[0]", "R[0].C[1]", "R[0].C[2]", "R[0].C[3]", "R[1].C[0]", "R[1].C[1]", "R[1].C[2]", "R[1].C[3]","R[2].C[0]", "R[2].C[1]", "R[2].C[2]", "R[2].C[3]" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  currentEvent.eventContexts = contextIDs;
  
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  mace::ContextMapping contextMapping;
  contextMapping.snapshot();
  alock.downgrade( mace::AgentLock::NONE_MODE );
  
  mace::ReadLine rl(contextMapping);
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(6) );
  BOOST_REQUIRE( cutSet.find("R[0].C[0]") != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[0].C[1]") != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[0].C[2]") != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[0].C[3]") != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[1]")      != cutSet.end() );
  BOOST_REQUIRE( cutSet.find("R[2]")      != cutSet.end() );
}
// indirect ancestor contexts
// this is often encountered for sync calls.
BOOST_AUTO_TEST_CASE( Case5 )
{
  const uint32_t serviceID = 1;
  ThreadStructure::ScopedServiceInstance si( serviceID );
  mace::map<uint8_t, mace::set<mace::string> > contextIDs;
  mace::set<mace::string> ctxSet;
  const uint32_t setSize = 8;
  const char* contexts1[] = {"", "Build[0].Aisle" };
  for( uint32_t c = 0; c< setSize; c++ ) ctxSet.insert( contexts1[c] );

  contextIDs[ serviceID ] = ctxSet;

  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  currentEvent.eventID = 1;
  currentEvent.eventContexts = contextIDs;

  mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
  mace::ContextMapping contextMapping;
  contextMapping.snapshot();
  alock.downgrade( mace::AgentLock::NONE_MODE );
  
  mace::ReadLine rl( contextMapping);
  const mace::set<mace::string>& cutSet = rl.getCut();
  
  BOOST_REQUIRE_EQUAL( cutSet.size() , static_cast<size_t>(1) );
  BOOST_REQUIRE_EQUAL( *( cutSet.begin() ), mace::string("") );
}
// TODO: contexts already downgraded?
BOOST_AUTO_TEST_SUITE_END()
