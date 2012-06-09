#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ContextMapping.h"


BOOST_AUTO_TEST_SUITE( lib_ContextMapping )
BOOST_AUTO_TEST_SUITE( ContextMapping_getInitialMapping )

BOOST_AUTO_TEST_CASE( DefaultAddress )
{
    BOOST_TEST_CHECKPOINT("Without setting default address, getNodeByContext() should return SockUtil::NULL_MACEADDR");
    mace::ContextMapping cm;
    BOOST_REQUIRE( cm.getNodeByContext("") == SockUtil::NULL_MACEADDR  );
    mace::MaceKey j = mace::MaceKey(mace::ipv4, "cloud01.cs.purdue.edu");

    BOOST_TEST_CHECKPOINT("If no mapped data, getNodeByContext() returns defaultAddress");
    cm.setDefaultAddress( j.getMaceAddr() );
    BOOST_REQUIRE( cm.getNodeByContext("") == j.getMaceAddr() );
}

BOOST_AUTO_TEST_CASE(ConstructorWithParameter)
{
    BOOST_TEST_CHECKPOINT("Test getNodeByContext() if mapping is supplied in constructor");
    mace::MaceKey vheadNode( mace::ipv4, "google.com" );
    mace::MaceAddr vhead = vheadNode.getMaceAddr();
    mace::MaceAddr node1 = mace::MaceKey( mace::ipv4, "cloud01.cs.purdue.edu" ).getMaceAddr();
    mace::MaceAddr node2 = mace::MaceKey( mace::ipv4, "cloud02.cs.purdue.edu" ).getMaceAddr();
    const char* contexts1[] = {"", "R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
    const char* contexts2[] = {"R[0].C[2]", "M[0,1]"};
    mace::list< mace::string > ctxlist1;
    for( uint32_t c = 0; c< 8; c++ ) ctxlist1.push_back( contexts1[c] );
    mace::list< mace::string > ctxlist2;
    for( uint32_t c = 0; c< 2; c++ ) ctxlist2.push_back( contexts2[c] );

    mace::map< mace::MaceAddr, mace::list<mace::string> > ctxmap;
    ctxmap[ node1 ] = ctxlist1;
    ctxmap[ node2 ] = ctxlist2;

    mace::ContextMapping cm2(vhead, ctxmap );

    BOOST_REQUIRE( cm2.getNodeByContext("") == node1 );
}

BOOST_AUTO_TEST_CASE(LoadMapping)
{
    BOOST_TEST_CHECKPOINT("Test getNodeByContext() if mapping is supplied in loadMapping()");
    mace::MaceKey vheadNode( mace::ipv4, "google.com" );
    mace::MaceAddr vhead = vheadNode.getMaceAddr();
    mace::MaceAddr node1 = mace::MaceKey( mace::ipv4, "cloud01.cs.purdue.edu" ).getMaceAddr();
    mace::MaceAddr node2 = mace::MaceKey( mace::ipv4, "cloud02.cs.purdue.edu" ).getMaceAddr();
    const char* contexts1[] = {"", "R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
    const char* contexts2[] = {"R[0].C[2]", "M[0,1]"};
    mace::list< mace::string > ctxlist1;
    for( uint32_t c = 0; c< 8; c++ ) ctxlist1.push_back( contexts1[c] );
    mace::list< mace::string > ctxlist2;
    for( uint32_t c = 0; c< 2; c++ ) ctxlist2.push_back( contexts2[c] );
    mace::list< mace::string > ctxlisthead;
    ctxlisthead.push_back( "__head" );

    mace::map< mace::MaceAddr, mace::list<mace::string> > ctxmap;
    ctxmap[ node1 ] = ctxlist1;
    ctxmap[ node2 ] = ctxlist2;
    ctxmap[ vhead ] = ctxlisthead;

    mace::ContextMapping cm2;
    cm2.loadMapping( ctxmap );

    BOOST_REQUIRE( cm2.getNodeByContext("") == node1 );
}
BOOST_AUTO_TEST_CASE(AccessedContext)
{
    BOOST_TEST_CHECKPOINT("Test accessedContext() returned false after the same context name is called the first time.");
    mace::MaceKey vheadNode( mace::ipv4, "google.com" );
    mace::MaceAddr vhead = vheadNode.getMaceAddr();
    mace::MaceAddr node1 = mace::MaceKey( mace::ipv4, "cloud01.cs.purdue.edu" ).getMaceAddr();
    mace::MaceAddr node2 = mace::MaceKey( mace::ipv4, "cloud02.cs.purdue.edu" ).getMaceAddr();
    const char* contexts1[] = {"", "R[0]", "R[1]", "R[2]", "T", "R[0].C[0]", "R[0].C[1]", "M[0,0]" };
    const char* contexts2[] = {"R[0].C[2]", "M[0,1]"};
    mace::list< mace::string > ctxlist1;
    for( uint32_t c = 0; c< 8; c++ ) ctxlist1.push_back( contexts1[c] );
    mace::list< mace::string > ctxlist2;
    for( uint32_t c = 0; c< 2; c++ ) ctxlist2.push_back( contexts2[c] );
    mace::list< mace::string > ctxlisthead;
    ctxlisthead.push_back( "__head" );

    mace::map< mace::MaceAddr, mace::list<mace::string> > ctxmap;
    ctxmap[ node1 ] = ctxlist1;
    ctxmap[ node2 ] = ctxlist2;
    ctxmap[ vhead ] = ctxlisthead;

    mace::ContextMapping cm2;
    cm2.loadMapping( ctxmap );

    BOOST_REQUIRE( cm2.accessedContext("") == false );
    BOOST_TEST_CHECKPOINT("Test accessedContext() returned true after the same context name is called the second time.");
    BOOST_REQUIRE( cm2.accessedContext("") == true );
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
