#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ContextService.h"
#include "AccessLine.h"

namespace mace{
  class __ServiceStackEvent__;
  class __ScopedTransition__;
  class __ScopedRoutine__;
};
// LocalService is for non-distributed service.
class LocalService: public ContextService {
public:
  LocalService():  ContextService()
  {
    mace::map<mace::MaceAddr ,mace::list<mace::string > > servContext;
    loadContextMapping( servContext);
  }
protected:
  virtual void snapshot(const uint64_t& ver) const {} // no op
  virtual void snapshotRelease(const uint64_t& ver) const {} // no op
  virtual void commitEvent( const uint64_t eventID ) {} // deprecated
  virtual void dispatchDeferredMessages(MaceKey const& dest, mace::Message* message,  registration_uid_t const rid ) {} // no messages
  virtual void send__event_AllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const eventID ) {}
  virtual void send__event_ContextMigrationRequest( MaceAddr const& msgdestination, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::HighLevelEvent const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& nextHops ) {}
  virtual void send__event_commit_context( MaceAddr const& msgdestination, mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) {}
  virtual void const_send__event_commit_context( MaceAddr const& msgdestination, mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const {}
  virtual void send__event_commit( MaceAddr const& msgdestination, uint64_t const& eventID, int8_t const& eventType, uint32_t const& eventMessageCount ) {}
  virtual void const_send__event_commit( MaceAddr const& msgdestination, uint64_t const& eventID, int8_t const& eventType, uint32_t const& eventMessageCount ) const {}
  virtual void send__event_snapshot( MaceAddr const& msgdestination, mace::HighLevelEvent const& event, mace::string const& targetContextID, mace::string const& snapshotContextID, mace::string const& snapshot ) {}
  virtual void send__event_create_response( MaceAddr const& msgdestination, mace::HighLevelEvent const& event, uint32_t const& counter, MaceAddr const& targetAddress) {}
  virtual void send__event_downgrade_context( MaceAddr const& msgdestination, uint32_t const contextID, uint64_t const eventID, bool const isresponse ) {}

  virtual void remoteAllocateGlobalContext( mace::string const& globalContextID, std::pair< mace::MaceAddr, uint32_t > const& newMappingReturn, const mace::ContextMapping* ctxmapCopy ) {}
  virtual void send__event_TransferContext( MaceAddr const& msgdestination, mace::string const& ctxId, uint32_t const ctxNId, mace::string const& checkpoint, uint64_t const eventId, MaceAddr const& parentContextNode, bool const isresponse ) {
    ABORT("Single-node service does not support context migration and context transfer"); 
  }

  virtual void send__event_AllocateContextObjectMsg(const mace::ContextMapping* ctxmapCopy, MaceAddr const newHead, mace::map< uint32_t, mace::string > const& contextSet, int8_t const eventType ) {}
  virtual void getContextSnapshot( mace::vector<uint32_t> const& snapshotContextID ) const {}
  virtual void routeEventRequest( MaceKey const& destNode, mace::pair< mace::string, mace::string > const& eventreq ) {
    ABORT("Single-node service does not support event routing"); 
  } 
};

template< class GlobalContextType >
class OneContextService: public LocalService {
friend class mace::__ServiceStackEvent__;
public:
  OneContextService():  LocalService()
  {
  }
private:
  GlobalContextType* globalContext;
  mace::ContextBaseClass* createContextObject( mace::string const& contextName, uint32_t const contextID ) {
    ScopedLock sl( getContextObjectMutex );
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    ASSERT ( cpIt == ctxobjNameMap.end()  );
    ASSERT( contextName.empty() );
    ASSERT( globalContext == NULL );

    globalContext = new GlobalContextType(contextName, ThreadStructure::myEvent().eventID, instanceUniqueID, contextID );
    ctxobjNameMap[ contextName ] = globalContext;
    ctxobjIDMap[ contextID ] = globalContext;
    return globalContext;

  }
};
template< class GlobalContextType >
class Test1Service: public OneContextService< GlobalContextType > {
public:
  Test1Service():  OneContextService< GlobalContextType >()
  {
  }
  void maceInit(){ // access the global context
    const mace::string targetContextName = "";
    mace::__ServiceStackEvent__ sse( mace::HighLevelEvent::STARTEVENT, this, targetContextName );
    const mace::ContextMapping& currentMapping = this->contextMapping.getSnapshot();
    const uint32_t targetContextID = currentMapping.findIDByName( targetContextName );
    mace::AccessLine al( this->instanceUniqueID, targetContextID, currentMapping );

    {
      mace::__ScopedTransition__ p( this, targetContextID );
      __real_maceInit();
    }

  }
  void maceExit(){

  }
private:
  void __real_maceInit(){

  }
  void __real_maceExit(){

  }
};
class GlobalContext: public mace::ContextBaseClass{
public:
  GlobalContext( const mace::string& contextName, const uint64_t eventID, const uint8_t instanceUniqueID, const uint32_t contextID ):
    mace::ContextBaseClass( contextName, eventID, instanceUniqueID, contextID ){
  }
private:
  // declare context variables here
};

BOOST_AUTO_TEST_SUITE( lib_ContextService )

BOOST_AUTO_TEST_CASE( Case1 )
{ // test single services
  // test: create start event, async event, timer event, message delivery event, downcall event, upcall event,
  //       test routines (local)
  //       without using specialized threads (head threads, commit threads, async, transport threads etc )
  BOOST_TEST_CHECKPOINT("Constructor");
  Test1Service<GlobalContext> service1;
  BOOST_TEST_CHECKPOINT("maceInit");
  service1.maceInit();
  BOOST_TEST_CHECKPOINT("maceExit");
  service1.maceExit();
}
BOOST_AUTO_TEST_SUITE_END()
