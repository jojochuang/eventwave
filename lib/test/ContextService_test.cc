#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>
#include "ContextService.h"
#include "AccessLine.h"
#include "MaceKey.h"
#include "HeadEventDispatch.h"

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
  virtual void dispatchDeferredMessages(MaceKey const& dest, mace::string const& message,  registration_uid_t const rid ) {}// no messages
  virtual void routeEventRequest( MaceKey const& destNode, mace::string const& eventreq ){
    ABORT("Single-node service does not support event routing"); 
  } 
  virtual void __ctx_dispatcher( void *p ){ }
  virtual void sendInternalMessage( mace::MaceAddr const& dest, mace::InternalMessage const& message ){ }
};
class __LocalTransition__{
public:
    __LocalTransition__( LocalService* service, int8_t const eventType, mace::string const& targetContextName = "", mace::vector< mace::string > const& snapshotContextNames = mace::vector< mace::string >() ) {
      mace::vector< uint32_t > snapshotContextIDs;
      mace::__ServiceStackEvent__ sse( eventType, service, targetContextName );
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

// InContextService is similar to mace-incontext system
template< class GlobalContextType >
class InContextService: public LocalService {
friend class mace::__ServiceStackEvent__;
public:
  InContextService():  LocalService() { }
private:
  GlobalContextType* globalContext;
  mace::ContextBaseClass* createContextObject( uint64_t const eventID, mace::string const& contextName, uint32_t const contextID ){
    ScopedLock sl( getContextObjectMutex );
    ASSERT( contextName.empty() );
    ASSERT( globalContext == NULL );

    globalContext = new GlobalContextType(contextName, eventID, instanceUniqueID, contextID );
    setContextObject( globalContext, contextID, contextName );
    return globalContext;

  }
};
namespace mace {
  // a specialized message type. This message is used for storing information and passed around between threads, therefore it will not do serialization
  class LocalMessage: public mace::Message, public mace::PrintPrintable{
    virtual void print( std::ostream& __out ) const {
      __out << "LocalMessage()";
    }
    virtual void serialize( std::string& str ) const{ } // empty
    virtual int deserialize( std::istream& __in ) throw (mace::SerializationException){ return 0;}
  };

}
template< class GlobalContextType >
class Test1Service: public InContextService< GlobalContextType > {
public:
  Test1Service():  InContextService< GlobalContextType >() { }
  void maceInit(){ // access the global context
    __LocalTransition__ lt( this, mace::Event::STARTEVENT );
    __real_maceInit();

  }
  void maceExit(){ // access the global context
    __LocalTransition__ lt( this, mace::Event::ENDEVENT );
    __real_maceExit();
  }
private:
  void __real_maceInit(){
    async_test();
  }
  void __real_maceExit(){

  }
  void async_test(){

    __async_req* req = new __async_req;
    HeadEventDispatch::HeadEventTP::executeEvent(this, (HeadEventDispatch::eventfunc)&Test1Service::__test_head, req, false );
  }
  void __test_head(mace::Message* _msg){
      __async_req* msg = static_cast<__async_req* >( _msg );
      asyncHead( msg->event, msg->extra, mace::Event::ASYNCEVENT  );

      mace::ContextBaseClass * contextObject = this->getContextObjByName( "" );
      contextObject->enqueueEvent( this, (mace::ctxeventfunc)&Test1Service::test, msg, msg->event );
  }
  void test(mace::Message* _msg){
    __async_req* msg = static_cast<__async_req* >( _msg );

    {
      __beginRemoteMethod( msg->event );
      mace::__ScopedTransition__ (this, msg->extra );

      async_test();
    }
   
    delete msg;
  }
  struct __async_req: public mace::LocalMessage{
    uint8_t getType() const{ return 1; }
    mace::Event event;
    mace::__asyncExtraField extra;
  };

};
class GlobalContext: public mace::ContextBaseClass{
public:
  GlobalContext( const mace::string& contextName, const uint64_t eventID, const uint8_t instanceUniqueID, const uint32_t contextID ):
    mace::ContextBaseClass( contextName, eventID, instanceUniqueID, contextID ){
  }
private:
  // declare context variables here
};

int main(int argc, char* argv[]){
  mace::Init( argc, argv );
  const char *_argv[] = {""};
  int _argc = 1;
  ::boost::unit_test::unit_test_main( &init_unit_test, _argc, const_cast<char**>(_argv) );

  mace::Shutdown();
}

BOOST_AUTO_TEST_SUITE( lib_ContextService )

BOOST_AUTO_TEST_CASE( Case1 )
{ // test single services
  // test: create start event, async event, timer event, message delivery event, downcall event, upcall event,
  //       test routines (local)
  BOOST_TEST_CHECKPOINT("Constructor");
  Test1Service<GlobalContext> service1;
  BOOST_TEST_CHECKPOINT("maceInit");
  service1.maceInit();
  SysUtil::sleep( 1 );
  BOOST_TEST_CHECKPOINT("maceExit");
  service1.maceExit();
}
BOOST_AUTO_TEST_SUITE_END()
