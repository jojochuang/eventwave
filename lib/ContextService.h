#ifndef _CONTEXTSERVICE_H
#define _CONTEXTSERVICE_H
/**
 * \file ContextService.h
 * \brief declares ContextService, accessory trait classes and event messages
 */

#include "mace.h"
#include "ContextBaseClass.h"
#include "mvector.h"
#include "m_map.h"
#include "mstring.h"
#include "mpair.h"
#include "pthread.h"
#include "ScopedLock.h"
#include "ContextMapping.h"
#include "Message.h"
#include "Printable.h"
#include "Event.h"
#include "InternalMessage.h"
/**
 * \file ContextService.h
 * \brief declares the base class for all context'ed services.
 */

using mace::__asyncExtraField;
using mace::ContextMapping;
namespace mace{
  class __ServiceStackEvent__;
  class __ScopedTransition__;
  class __ScopedRoutine__;

  class OnePhysicalNode{};
  class DistributedLogicalNode{};
  template<typename N>
  struct Locality_trait {
    bool isLocal( MaceAddr const& dest ) const {return false; }
  };
  /// specialized trait template for distributed logical node service
  template<>
  struct Locality_trait<DistributedLogicalNode> {
    bool isLocal( MaceAddr const& dest ) const {
      if ( dest == Util::getMaceAddr() ){
        return true;
      }
      return false;
    }
  };
  /// specialized trait template for one-phyiscal-node logical node service
  template<>
  struct Locality_trait<OnePhysicalNode> {
    bool isLocal( MaceAddr const& dest ){
      return true;
    }
  };

  /**
   * \brief message object for the events that does not have implemented transition handlers
   *
   * used to waste the ticket
   */
  class NullEventMessage: public Message, public PrintPrintable{
  public:
    NullEventMessage( uint64_t const ticket ): event( ticket ){}
    mace::Event event;
    static const uint8_t messageType = 255;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return NullEventMessage::getMsgType(); }

    mace::Event& getEvent() { return event; }

    std::string toString() const { 
      mace::string str;
      return str;
    }
    void print(std::ostream& __out) const { }
    size_t getSerializedSize() const { return 0; }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { 
      return 0;
    }
    void sqlize(mace::LogNode* __node) const { }

    std::string serializeStr() const { 
      mace::string str;
      return str;
    }
    void deserializeStr(const std::string& __s) throw (mace::SerializationException) { }
  };

  class __event_MigrateContext: public Message, public PrintPrintable {
  public:
    __event_MigrateContext( uint64_t const ticket, uint8_t const serviceID, mace::string const& contextName, MaceAddr const& destNode, bool const rootOnly ):
      ticket( ticket ), serviceID( serviceID ), contextName( contextName ), destNode( destNode ), rootOnly( rootOnly ){}
    const uint64_t ticket;
    const uint8_t serviceID;
    const mace::string contextName;
    const MaceAddr destNode;
    const bool rootOnly;
    static const uint8_t messageType = 255;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return NullEventMessage::getMsgType(); }

    std::string toString() const { 
      mace::string str;
      return str;
    }
    void print(std::ostream& __out) const { }
    size_t getSerializedSize() const { return 0; }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { 
      return 0;
    }
    void sqlize(mace::LogNode* __node) const { }

    std::string serializeStr() const { 
      mace::string str;
      return str;
    }
    void deserializeStr(const std::string& __s) throw (mace::SerializationException) { }
  };
}




/**
 * \brief Base class for all context'ed Mace services
 *
 * Provides the APIs for processing any kinds of operation.
 */
class ContextService : public BaseMaceService
{
friend class mace::__ServiceStackEvent__;
friend class mace::__ScopedTransition__;
friend class mace::__ScopedRoutine__;
public:
  ContextService(bool enqueueService = true): 
    BaseMaceService(enqueueService)
    {
    pthread_mutex_init( &getContextObjectMutex, NULL );
    pthread_mutex_init( &eventRequestBufferMutex, NULL );
  }

  ~ContextService(){

    deleteAllContextObject( );
    pthread_mutex_destroy( &getContextObjectMutex );
    pthread_mutex_destroy( &eventRequestBufferMutex );


  }
protected:
  /// utility functions that can be used in user code.
  void migrateContext( mace::string const& paramid );

  // functions that are generated in perl compiler
  //virtual void __ctx_dispatcher( mace::Message* __param ) = 0;
  virtual void __ctx_dispatcher( mace::EventRequest* __param ) = 0;
  /// interface for sending internal messages through transport service. The services are required to implement this interface.
  virtual void sendInternalMessage( MaceAddr const& dest, mace::InternalMessage const& msg ) = 0;
  /// interface for create context objects. The services are required to implement this interface.
  virtual mace::ContextBaseClass* createContextObject( uint64_t const eventID, mace::string const& contextName, uint32_t const contextID ) = 0;
  /// interface for routing event requests. The services are required to implement this interface.
  virtual void routeEventRequest( MaceKey const& destNode, mace::string const& eventreq ) = 0;

  // functions that are used by the code generated from perl compiler

  /// internal message handler
  void handleInternalMessages( mace::InternalMessage const& message, MaceAddr const& src  );
  /// acquire context locks
  void acquireContextLocks(uint32_t const  targetContextID, mace::vector<uint32_t> const & snapshotContextIDs) const ;
  /// initialize events
  mace::ContextMapping const&  asyncHead( mace::Event& event,  mace::__asyncExtraField const& extra, int8_t const eventType);
  /**
   * a downcall/upcall transition when it first enters a context and that it's an internal transition that does not generate  a new context,
   * must make sure it downgrades those contexts that it will not access
   * */
  void enterInnerService (mace::string const& targetContextID ) const;
  /**
   * Migrate context
   * If the context does not exist yet, ignore the request, but store the mapping so that when the context is created, it is created at the destination node.
   *
   * @param serviceID the numerical ID of the target service
   * @param contextID the numerical ID of the target context
   * @param destNode the destination node where the context will be migrated
   * @param rootOnly whether or not to migrate the subcontexts as well.
   * */
  void requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly);
  /**
   * initialize context mapping. This is supposed to be called in service constructor.
   *
   * @param servContext the mapping of physical nodes to list of contexts
   * */
  void loadContextMapping(const mace::map<mace::MaceAddr ,mace::list<mace::string > >& servContext);
  /**
   * send a message to request a ticket number for a new subevent
   * @param extra Extra object that contains the target context
   * @param event the event object
   * @param msg serialized event request 
   * */
  void requestRouteEvent ( __asyncExtraField& extra, mace::Event& event, mace::Serializable& msg ) const;
  /**
   * set up thread stack and event environment before starting a routine/downcall/upcall 
   *
   * @param event the event object
   * */
  void __beginRemoteMethod( mace::Event const& event ) const;
  /**
   * clean up thread stack and event environment after starting a routine/downcall/upcall 
   *
   * @param src the source physical node of this call
   * @param returnValueStr the serialized return value
   * */
  void __finishRemoteMethodReturn(  mace::MaceKey const& src, mace::string const& returnValueStr ) const;
  /**
   * called to resume the execution of an event that makes an upcall transition to the application
   * @param src the source physical node of the upcall
   * @param returnValueStr serialized return value
   * */
  void __appUpcallReturn( mace::MaceKey const& src, mace::string const& returnValueStr) const;
  /**
   * For the transitions that are not implemented, it will not use the ticket, so waste the ticket.
   * */
  void wasteTicket( void ) const;
  void notifyHeadExit();
  /**
   * wake up the threads that waits for the context to be created.
   *
   * @param contextID the numerical ID of the context
   * */
  void wakeupWaitingThreads(uint64_t contextID) const{
    std::map< uint64_t, std::set< pthread_cond_t* > >::iterator condSetIt = contextWaitingThreads.find( contextID );
    if( condSetIt != contextWaitingThreads.end() ){
      /*for( std::set< pthread_cond_t* >::iterator condIt = condSetIt->second.begin(); condIt != condSetIt->second.end(); condIt++ ){
        pthread_cond_signal( *condIt );
      }*/
      std::for_each( condSetIt->second.begin(), condSetIt->second.end(), pthread_cond_signal );
      contextWaitingThreads.erase( condSetIt );
    }
  }
  /**
   * wake up the threads that waits for the context to be created.
   *
   * @param contextName the canonical name of the context
   * */
  void wakeupWaitingThreads(mace::string const& contextName) const{
    std::map< mace::string, std::set< pthread_cond_t* > >::iterator condSetIt = contextWaitingThreads2.find( contextName );
    if( condSetIt != contextWaitingThreads2.end() ){
      /*for( std::set< pthread_cond_t* >::iterator condIt = condSetIt->second.begin(); condIt != condSetIt->second.end(); condIt++ ){
        pthread_cond_signal( *condIt );
      }*/
      std::for_each( condSetIt->second.begin(), condSetIt->second.end(), pthread_cond_signal );
      contextWaitingThreads2.erase( condSetIt );

    }
  }
  /** get the context object pointer by its canonical name 
   * @param contextName canonical name of the context
   * @return the pointer to the context object
   * */
  mace::ContextBaseClass* getContextObjByName( mace::string const& contextName ) const{
    ADD_SELECTORS("ContextService::getContextObjByName");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    if( cpIt == ctxobjNameMap.end() ){
      macedbg(1)<<"context name "<< contextName << " not found! wait ...";
      pthread_cond_t cond;
      pthread_cond_init( &cond, NULL );
      contextWaitingThreads2[ contextName ].insert( &cond );
      pthread_cond_wait( &cond, &getContextObjectMutex );
      pthread_cond_destroy( &cond );
      cpIt = ctxobjNameMap.find( contextName );
      ASSERT( cpIt != ctxobjNameMap.end() );
    }
    return cpIt->second;
  }
  /// push new sub event requests into the current Event structure so that when the current event commits, it knows to create these sub events.
  void addEventRequest( mace::EventRequest* reqObject){
    ThreadStructure::myEvent().deferEventRequest( instanceUniqueID, reqObject );
  }
  /** associate context object pointer to the numerical id and canonical name. Used by services to implement createContext() interface
   *
   * @param obj the pointer to the context object
   * @param contextID the numerical context ID
   * @param contextName the canonical context name
   * */
  void setContextObject( mace::ContextBaseClass* obj, uint32_t const contextID, mace::string const& contextName ){
    ASSERT( ctxobjNameMap.find( contextName ) == ctxobjNameMap.end() );
    ASSERT( ctxobjIDMap.find( contextID ) == ctxobjIDMap.end() );

    ctxobjNameMap[ contextName ] = obj;
    ctxobjIDMap[ contextID ] = obj;
  }
  /**
   * send an event. If the destination is the local physical node, push into the async dispatch queue. Otherwise send via transport service.
   * @param dest the destination physical node MaceKey
   * @param eventObject the pointer to the event object being sent
   * */
  void forwardEvent( mace::MaceAddr const& dest, mace::AsyncEvent_Message* const eventObject ){
    ADD_SELECTORS("ContextService::forwardEvent");
    if( isLocal( dest ) ){
      mace::ContextBaseClass * contextObject = getContextObjByName( eventObject->getExtra().targetContextID );
      macedbg(1)<<"Enqueue a message into context event dispatch queue: "<< eventObject <<Log::endl;
      contextObject->enqueueEvent(this,(mace::ctxeventfunc)&ContextService::__ctx_dispatcher,eventObject, eventObject->getEvent() ); 
    }else{
      mace::InternalMessage msg( eventObject );
      sendInternalMessage( dest, msg );
      //HeadEventDispatch::HeadTransportTP::sendEvent( this, (HeadEventDispatch::routefunc)static_cast< bool (${name}_namespace::${name}Service::*)( const MaceKey& , const Message&, registration_uid_t rid )>(&${name}_namespace::${name}Service::downcall_route) , destAddr, MSG, __ctx ); 

    }
  }
  /**
   * initialize an event and send it to the start context 
   *
   * @param msgObject the pointer to the event object 
   * */
  void createEvent(mace::AsyncEvent_Message* msgObject){
    if( mace::Event::isExit ){
      wasteTicket();
      return;
    }
    mace::ContextMapping const& snapshotMapping __attribute((unused)) = asyncHead( msgObject->getEvent(), msgObject->getExtra(), mace::Event::ASYNCEVENT );
    msgObject->getExtra().isRequest = false;
    const MaceAddr& destAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, msgObject->getExtra().targetContextID );
    forwardEvent( destAddr, msgObject );
  }
  /**
   * defer an upcall transition that does not return value if it enters application.
   * @param upcall the pointer to the upcall transition serialization message
   * */
  void deferApplicationUpcall( mace::AsyncEvent_Message* upcall ){
    mace::string upcall_str;
    mace::serialize( upcall_str, upcall );
    ThreadStructure::myEvent().deferApplicationUpcalls( instanceUniqueID, upcall_str);
  }
  template< typename T>
  T returnApplicationUpcall( mace::AsyncEvent_Message* upcall )
  {
    T ret;
    mace::InternalMessage im( upcall );
    mace::ScopedContextRPC rpc;
    forwardInternalMessage( contextMapping.getHead(), im );
    rpc.get( ret );
    rpc.get( ThreadStructure::myEvent() );
    return ret;
  }
private:
  void processRPCApplicationUpcall( mace::ApplicationUpcall* msg);
  void handleInternalMessagesWrapper( void* __param  ){
    mace::InternalMessage* __msg = static_cast<mace::InternalMessage* >(__param);
    handleInternalMessages ( *__msg, Util::getMaceAddr() );
    delete __msg;
  }
  void __beginTransition( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs  ) const;
  void __beginMethod( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs ) const;
  void __finishTransition(mace::ContextBaseClass* oldContext) const;
  void __finishMethod(mace::ContextBaseClass* oldContext) const;
  void acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const;
  void downgradeContext( mace::string const& contextName ); // WC: not used?
  void nullEventHead( void *p );
  void doDeleteContext( mace::string const& contextName  );
  void deleteContext( mace::string const& contextName );
  void copyContextData(mace::ContextBaseClass* thisContext, mace::string& s ) const;
  void eraseContextData(mace::ContextBaseClass* thisContext);
  void downgradeEventContext( );
  void deleteAllContextObject( ) {
    ADD_SELECTORS("ContextService::deleteAllContextObject");
    ScopedLock sl(getContextObjectMutex);

    for( mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::iterator cpIt = ctxobjIDMap.begin(); cpIt != ctxobjIDMap.end(); cpIt++ ){
      delete cpIt->second;
    }
  }
  void sendAsyncSnapshot( __asyncExtraField const& extra, mace::string const& thisContextID, mace::ContextBaseClass* const& thisContext );
  mace::ContextBaseClass* getContextObjByID( uint32_t const contextID ) const{
    ADD_SELECTORS("ContextService::getContextObjByID");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjIDMap.find( contextID );
    if( cpIt == ctxobjIDMap.end() ){
      macedbg(1)<<"context ID "<< contextID << " not found! wait ...";
      pthread_cond_t cond;
      pthread_cond_init( &cond, NULL );
      contextWaitingThreads[ contextID ].insert( &cond );
      pthread_cond_wait( &cond, &getContextObjectMutex );
      pthread_cond_destroy( &cond );
      cpIt = ctxobjIDMap.find( contextID );
      ASSERT( cpIt != ctxobjIDMap.end() );
    }
    return cpIt->second;
  }
  void getContextSnapshot( mace::vector<uint32_t> const& snapshotContextID ) const {
    uint32_t nsnapshot = snapshotContextID.size();
    uint32_t receivedSnapshots = 0;
    while( receivedSnapshots < nsnapshot ){
      //uint32_t recvContextID;
      //mace::string recvContextSnapshot;
      //mace::ContextSnapshot::receive(recvContextID, recvContextSnapshot);
      //mace::ContextBaseClass * contextObject = getContextObjByID( recvContextID );
      //mace::deserialize( recvContextSnapshot, contextObject);
      receivedSnapshots++;
    }

  }
  /// send internal message either locally with async dispatch thread, or remotely with transport thread
  void forwardInternalMessage( MaceAddr const& dest, mace::InternalMessage const& msg ){
    ADD_SELECTORS("ContextService::forwardInternalMessage");
    if( isLocal( dest ) ){
      macedbg(1)<<"Enqueue a message into async dispatch queue: "<< msg <<Log::endl;
      AsyncDispatch::enqueueEvent(this,(AsyncDispatch::asyncfunc)&ContextService::handleInternalMessagesWrapper,(void*)new mace::InternalMessage( msg ) );
    }else{
      sendInternalMessage( dest, msg );
    }
  };
  void send__event_ContextMigrationRequest( MaceAddr const& destNode, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::Event const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& nextHops ){
    mace::InternalMessage msg( mace::ContextMigrationRequest, ctxId, dest, rootOnly, event, prevContextMapVersion, nextHops );
    forwardInternalMessage( destNode, msg );
  }
  void const_send__event_commit_context( MaceAddr const& destNode, mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const{
    mace::InternalMessage msg( mace::commit_context, nextHops, eventID, eventType, eventContextMappingVersion, eventSkipID, isresponse, hasException, exceptionContextID );
    ContextService *self = const_cast<ContextService *>( this );
    self->forwardInternalMessage( destNode, msg );
  }
  void send__event_commit( MaceAddr const& destNode, mace::Event const& event ){
    mace::InternalMessage msg( mace::commit, event );
    forwardInternalMessage( destNode, msg );
  }
  void const_send__event_commit( MaceAddr const& dest, mace::Event const& event ) const{
    ContextService *self = const_cast<ContextService *>( this );
    mace::InternalMessage msg( mace::commit, event );
    self->forwardInternalMessage( dest, msg );
  }
  void send__event_snapshot( MaceAddr const& dest, mace::Event const& event, mace::string const& targetContextID, mace::string const& snapshotContextID, mace::string const& snapshot ){
    mace::InternalMessage msg( mace::snapshot, event, targetContextID, snapshotContextID, snapshot );
    forwardInternalMessage( dest, msg );
  }
  void send__event_create_response( MaceAddr const& dest, mace::Event const& event, uint32_t const& counter, MaceAddr const& targetAddress){
    mace::InternalMessage msg( mace::create_response, event, counter, targetAddress );
    forwardInternalMessage( dest, msg );
  }
  void const_send__event_create( MaceAddr const& dest, __asyncExtraField const& extra, uint32_t const& counter) const {
    ContextService *self = const_cast<ContextService *>( this );
    mace::InternalMessage msg( mace::create, extra, counter );
    self->forwardInternalMessage( dest, msg );
  }
  void send__event_downgrade_context( MaceAddr const& dest, uint32_t const contextID, uint64_t const eventID, bool const isresponse ){
    mace::InternalMessage msg( mace::downgrade_context, contextID, eventID, isresponse );
    forwardInternalMessage( dest, msg );
  }
  void send__event_TransferContext( MaceAddr const& dest, uint32_t const rootContextID, mace::string const& ctxId, uint32_t const ctxNId, mace::string const& checkpoint, uint64_t const eventId, MaceAddr const& parentContextNode, bool const isresponse ){
    mace::InternalMessage msg( mace::TransferContext, rootContextID, ctxId, ctxNId, checkpoint, eventId, parentContextNode, isresponse );
    forwardInternalMessage( dest, msg );
  }
  void send__event_AllocateContextObjectMsg( uint64_t const eventID, const mace::ContextMapping* ctxmapCopy, MaceAddr const newHead, mace::map< uint32_t, mace::string > const& contextSet, int8_t const eventType ){

    mace::InternalMessage msg( mace::AllocateContextObject, newHead, contextSet, eventID, *ctxmapCopy, 0 );

    const mace::map < MaceAddr,uint32_t >& physicalNodes = mace::ContextMapping::getAllNodes( *ctxmapCopy);
    for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){
      if( isLocal( nodeIt->first ) ) continue; // don't send to head itself
      forwardInternalMessage( nodeIt->first, msg );
    }                                         
  }
  void send__event_migrate_context(mace::MaceAddr const& newNode, mace::string const& contextName, uint64_t const delay ){
    mace::InternalMessage msg( mace::migrate_context, newNode, contextName, delay );
    forwardInternalMessage( contextMapping.getHead(), msg );
  }
  void send__event_migrate_param(mace::string const& paramid ){
    mace::InternalMessage msg( mace::migrate_param, paramid );
    forwardInternalMessage( contextMapping.getHead(), msg );
  }
  void send__event_routine_return( mace::MaceAddr const& src, mace::string const& returnValueStr ) const{
    // src must not be local node
    ContextService *self = const_cast<ContextService *>( this );
    mace::InternalMessage msg( mace::routine_return, returnValueStr, ThreadStructure::myEvent() );
    self->sendInternalMessage( src ,  msg );
  }
  void send__event_RemoveContextObject( uint64_t const eventID, mace::ContextMapping const& ctxmapCopy, MaceAddr const& dest, uint32_t contextID ){
    mace::InternalMessage msg( mace::RemoveContextObject, eventID, ctxmapCopy, dest, contextID );

    const mace::map < MaceAddr,uint32_t >& physicalNodes = mace::ContextMapping::getAllNodes( ctxmapCopy);
    for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){
      sendInternalMessage( nodeIt->first ,  msg );
    }
    //std::for_each( physicalNodes.begin(), physicalNodes.end(), std::bind2nd( sendInternalMessage, msg) );
  }
  void send__event_delete_context( mace::string const& contextName ){
    mace::InternalMessage msg( mace::delete_context, contextName );
    sendInternalMessage( contextMapping.getHead() ,  msg );
  }
  void remoteAllocateGlobalContext( mace::string const& globalContextID, std::pair< mace::MaceAddr, uint32_t > const& newMappingReturn, const mace::ContextMapping* ctxmapCopy ){
    mace::map< uint32_t, mace::string > contextSet;
    contextSet[ newMappingReturn.second ] =  globalContextID ;

    mace::InternalMessage msg( mace::AllocateContextObject, newMappingReturn.first, contextSet, ThreadStructure::myEvent().eventID, *ctxmapCopy, 0 );
    sendInternalMessage( newMappingReturn.first ,  msg );
  }

  void notifyNewEvent( mace::Event & event,  const uint8_t serviceID ) ;
  void notifyNewContext( mace::Event & event, const uint8_t serviceID );
  bool isLocal( mace::MaceAddr const& dest ) const{
    return nodeLocality.isLocal( dest );
  }
  void handle__event_AllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType);

  void handle__event_ContextMigrationRequest( MaceAddr const& src, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::Event const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& nextHops );

  void handle__event_TransferContext( MaceAddr const& src, uint32_t const rootContextID, mace::string const& ctxId, uint32_t const& ctxNId, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse );


  void handle__event_create( MaceAddr const& src, __asyncExtraField const& extra, uint64_t const& counter );
  void handle__event_commit( mace::Event const& event ) const;
  void handle__event_commit_context( mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const;
  void handle__event_create_response( mace::Event const& event, uint32_t const& counter, MaceAddr const& targetAddress);
  void handle__event_enter_context( mace::Event const& event, mace::vector< uint32_t > const& contextIDs );
  void handle__event_exit_committed( );
  void handle__event_create_head( __asyncExtraField const& extra, uint64_t const& counter, MaceAddr const& src);
  void handle__event_snapshot( mace::Event const& event, mace::string const& ctxID, mace::string const& snapshotContextID, mace::string const& snapshot);
  void handle__event_downgrade_context( uint32_t const& contextID, uint64_t const& eventID, bool const& isresponse );
  void handle__event_routine_return( mace::string const& returnValue, mace::Event const& event);
  void handle__event_appupcall_return( mace::string const& returnValue, mace::Event const& event);
  void handle__event_new_head_ready(  MaceAddr const& src);
  void handle__event_evict( MaceAddr const& src );
  void handle__event_migrate_context( mace::MaceAddr const& newNode, mace::string const& contextName, uint64_t const delay );
  void handle__event_migrate_param( mace::string const& paramid );
  void handle__event_RemoveContextObject( uint64_t const eventID, mace::ContextMapping const& ctxmapCopy, MaceAddr const& dest, uint32_t contextID );
  void handle__event_delete_context( mace::string const& contextName );
  void handle__event_MigrateContext( void *p );
  static void waitExit(){
    ScopedLock sl( waitExitMutex );
    pthread_cond_wait( &waitExitCond, &waitExitMutex );
  }

  static void proceedExit(){
    ScopedLock sl( waitExitMutex );
    pthread_cond_signal( &waitExitCond );
  }
protected:
  mutable pthread_mutex_t getContextObjectMutex;

  mace::ContextMapping contextMapping;
private:
  mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState > ctxobjIDMap;
  mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState > ctxobjNameMap;
  static std::map< uint64_t, std::set< pthread_cond_t* > > contextWaitingThreads;
  static std::map< mace::string, std::set< pthread_cond_t* > > contextWaitingThreads2;
  static pthread_mutex_t waitExitMutex;
  static pthread_cond_t waitExitCond;
  mutable pthread_mutex_t eventRequestBufferMutex;
  /*mutable pthread_mutex_t eventContextCommitResponse;
  static std::map< uint64_t, pthread_cond_t* > */
  mace::ContextEventRecord contextEventRecord;
  mutable std::map< uint32_t, std::pair<mace::string*, mace::string > > unfinishedEventRequest;
  // TODO: make ContextService a templated class and the template parameter of the trait class uses the template parameter of ContextService
  mace::Locality_trait< mace::DistributedLogicalNode > nodeLocality;
};

namespace mace{
class __ServiceStackEvent__ {
  private:
  ContextService* sv;
      public:
    __ServiceStackEvent__(const int8_t eventType, ContextService* service, const mace::string& targetContextName) : sv(service) {
      bool newEventCondition;
      switch( eventType ){
        case mace::Event::STARTEVENT:
          //sv->registerInstanceID();
          newEventCondition = ThreadStructure::isFirstMaceInit();
          break;
        case mace::Event::ENDEVENT:
          newEventCondition = ThreadStructure::isFirstMaceExit();
          break;
        default:
          //newEventCondition = ThreadStructure::isOuterMostTransition();
          newEventCondition = ThreadStructure::isApplicationDowncall();
      }
      if( newEventCondition && !mace::Event::isExit ){
        /*if( eventType == mace::Event::ENDEVENT ){
          ThreadStructure::prepareStop();
        }*/
        ThreadStructure::newTicket();
        __asyncExtraField extra;
        extra.targetContextID = targetContextName;
        sv->asyncHead( ThreadStructure::myEvent(), extra, eventType );
      }
      sv->enterInnerService(targetContextName);
    }
    //~__ServiceStackEvent__() { }
};
class __ScopedTransition__ {
  protected:
    ContextService const* sv;
    mace::ContextBaseClass *oldContextObject;
  public:
    __ScopedTransition__( ContextService const* service, uint32_t const& targetContextID, mace::vector<uint32_t> const& snapshotContextIDs = mace::vector<uint32_t>() ) 
      : sv(service), oldContextObject( ThreadStructure::myContext() ) {
      sv->__beginTransition( targetContextID, snapshotContextIDs );
    }
    __ScopedTransition__( ContextService const* service, __asyncExtraField const& extra ) 
      : sv(service),  oldContextObject( ThreadStructure::myContext() )
    {
      const mace::ContextMapping& snapshotMapping = sv->contextMapping.getSnapshot();
      const uint32_t targetContextID = snapshotMapping.findIDByName( extra.targetContextID );
      mace::vector<uint32_t> snapshotContextIDs;
      for_each( extra.snapshotContextIDs.begin(), extra.snapshotContextIDs.begin(), mace::addSnapshotContextID( snapshotMapping, snapshotContextIDs  ) );
      sv->__beginTransition( targetContextID, snapshotContextIDs );
    }
    ~__ScopedTransition__() {
      sv->__finishTransition( oldContextObject );
    }
};
class __ScopedRoutine__ {
  protected:
    ContextService const* sv;
    mace::ContextBaseClass *oldContextObject;
  public:
  __ScopedRoutine__( ContextService const* service, uint32_t const& targetContextID, mace::vector<uint32_t> const& snapshotContextIDs = mace::vector<uint32_t>() ) 
    : sv(service), oldContextObject( ThreadStructure::myContext() ) {
    sv->__beginMethod( targetContextID, snapshotContextIDs );
  }
  ~__ScopedRoutine__() {
    sv->__finishMethod( oldContextObject ); 
  }
};
}

#endif
