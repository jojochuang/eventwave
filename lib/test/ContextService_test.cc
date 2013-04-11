#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>
#include "ContextService.h"
#include "AccessLine.h"
#include "MaceKey.h"

namespace mace{
  class __ServiceStackEvent__;
  class __ScopedTransition__;
  class __ScopedRoutine__;
};
// LocalService is for non-distributed service.
class __LocalTransition__;
class LocalService: public ContextService {
friend class __LocalTransition__;
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
  virtual void dispatchDeferredMessages(MaceKey const& dest, mace::string const& message,  registration_uid_t const rid ) {}// no messages
  virtual void getContextSnapshot( mace::vector<uint32_t> const& snapshotContextID ) const {}
  //virtual void routeEventRequest( MaceKey const& destNode, mace::pair< mace::string, mace::string > const& eventreq ) {
  virtual void routeEventRequest( MaceKey const& destNode, mace::string const& eventreq ){
    ABORT("Single-node service does not support event routing"); 
  } 
  virtual void __ctx_dispatcher( void *p ){ }
  virtual void sendInternalMessage( mace::MaceAddr const& dest, mace::InternalMessage const& message ){ }
};
class __LocalTransition__{
public:
    __LocalTransition__( LocalService* service, mace::string const& targetContextName = "", mace::vector< mace::string > const& snapshotContextNames = mace::vector< mace::string >() ) {
      mace::vector< uint32_t > snapshotContextIDs;
      mace::__ServiceStackEvent__ sse( mace::Event::STARTEVENT, service, targetContextName );
      const mace::ContextMapping& currentMapping = service->contextMapping.getSnapshot();
      const uint32_t targetContextID = currentMapping.findIDByName( targetContextName );
      for_each( snapshotContextNames.begin(), snapshotContextNames.end(), mace::addSnapshotContextID( currentMapping, snapshotContextIDs ) );
      mace::AccessLine al( service->instanceUniqueID, targetContextID, currentMapping );

      p = new mace::__ScopedTransition__( service, targetContextID );
    }
    ~__LocalTransition__(){
      delete p;
    }

private:
  mace::__ScopedTransition__* p;
};

// OneContextService is similar to mace-incontext system
template< class GlobalContextType >
class OneContextService: public LocalService {
friend class mace::__ServiceStackEvent__;
public:
  OneContextService():  LocalService()
  {
  }
private:
  GlobalContextType* globalContext;
  //mace::ContextBaseClass* createContextObject( mace::string const& contextName, uint32_t const contextID ) {
  mace::ContextBaseClass* createContextObject( uint64_t const eventID, mace::string const& contextName, uint32_t const contextID ){
    ScopedLock sl( getContextObjectMutex );
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    ASSERT ( cpIt == ctxobjNameMap.end()  );
    ASSERT( contextName.empty() );
    ASSERT( globalContext == NULL );

    globalContext = new GlobalContextType(contextName, eventID, instanceUniqueID, contextID );
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
    __LocalTransition__ lt( this );
    __real_maceInit();

  }
  void maceExit(){ // access the global context
    __LocalTransition__ lt( this );
    __real_maceExit();
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
