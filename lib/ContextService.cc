#include "ContextService.h"
#include "ScopedContextRPC.h"
#include "ReadLine.h"
#include "AccessLine.h"
#include "params.h"
#include "HeadEventDispatch.h"

using mace::ReadLine;
std::map< uint64_t, std::set< pthread_cond_t* > > ContextService::contextWaitingThreads;
std::map< mace::string, std::set< pthread_cond_t* > > ContextService::contextWaitingThreads2;

pthread_mutex_t ContextService::waitExitMutex = PTHREAD_MUTEX_INITIALIZER;;
pthread_cond_t ContextService::waitExitCond = PTHREAD_COND_INITIALIZER;;

void ContextService::acquireContextLocks(uint32_t const  targetContextID, mace::vector<uint32_t> const & snapshotContextIDs) const {
    mace::map< MaceAddr, mace::vector< uint32_t > > ancestorContextNodes;
    acquireContextLocksCommon(targetContextID, snapshotContextIDs, ancestorContextNodes );
    
    for( mace::map< MaceAddr, mace::vector< uint32_t > >::iterator nodeIt = ancestorContextNodes.begin(); nodeIt != ancestorContextNodes.end(); nodeIt ++ ){
      mace::InternalMessage msg( mace::enter_context , ThreadStructure::myEvent(), nodeIt->second );

      sender->sendInternalMessage( nodeIt->first, msg );
    }
}
void ContextService::acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const{
  ADD_SELECTORS("ContextService::acquireContextLocksCommon");
  
  const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
  const mace::Event::EventServiceContextType& eventContexts =  ThreadStructure::getEventContexts( ).find( instanceUniqueID ) ->second;
  const bool hasSnapshot = ( ThreadStructure::getEventSnapshotContexts().find( instanceUniqueID ) == ThreadStructure::getEventSnapshotContexts().end() )?false:true;
  const mace::Event::EventServiceSnapshotContextType& eventSnapshot =  ThreadStructure::getEventSnapshotContexts().find( instanceUniqueID )->second;
  mace::set< uint32_t > ancestorContextIDs;
  if( targetContextID == 1 ){ // the target is global context. no ancestor
  }else{
    uint32_t nowID = targetContextID;
    do{
     uint32_t parentID = snapshotMapping.getParentContextID( nowID );
     if( eventContexts.find( parentID ) == eventContexts.end() && (hasSnapshot && eventSnapshot.find( parentID ) == eventSnapshot.end() ) ){
       ancestorContextIDs.insert( parentID );
     }else{
       break;
     }
     nowID = parentID;
    }while( nowID != 1 ); // loop until reaching the global (root) context
  }

  for(mace::vector<uint32_t>::const_iterator scIt = snapshotContextIDs.begin(); scIt != snapshotContextIDs.end(); scIt++ ){
    uint32_t nowID = *scIt;
    do{
     if( eventContexts.find( nowID ) == eventContexts.end() && 
       (hasSnapshot && eventSnapshot.find( nowID ) == eventSnapshot.end() ) &&
       ancestorContextIDs.find( nowID ) == ancestorContextIDs.end()   ){
       ancestorContextIDs.insert( nowID );
     }else{
       break;
     }
     if( nowID == 1 ){ break; }
     nowID = snapshotMapping.getParentContextID( nowID );
    }while( true ); // loop until reaching the global (root) context
  }
  // TODO: update eventContexts
  /*for( mace::set< uint32_t >::iterator acIt = ancestorContextIDs.begin(); acIt != ancestorContextIDs.end(); acIt++ ){
    ThreadStructure::insertEventContext( *acIt );
  }*/
  std::for_each( ancestorContextIDs.begin(), ancestorContextIDs.end(), ThreadStructure::insertEventContext );
}
void ContextService::doDeleteContext( mace::string const& contextName  ){
  ADD_SELECTORS("ContextService::doDeleteContext");
  mace::Event& newEvent = ThreadStructure::myEvent();
  // must be head
  ASSERT( isLocal( this->contextMapping.getHead() ) );
  newEvent.newEventID( mace::Event::DELETECONTEXT, ThreadStructure::myTicket() );
  newEvent.initialize(  );
  mace::AgentLock lock( mace::AgentLock::WRITE_MODE ); // global lock is used to ensure new events are created in order

  const mace::ContextMapping* snapshotContext = & ( contextMapping.getSnapshot( newEvent.getLastContextMappingVersion() ) );
  uint32_t contextID = mace::ContextMapping::hasContext2( *snapshotContext, contextName );
  if( contextID == 0 ){ // context not found
    maceerr<<"Context '"<< contextName <<"' does not exist. Ignore delete request"<< Log::endl;
    lock.downgrade( mace::AgentLock::READ_MODE );
    HeadEventDispatch::HeadEventTP::commitEvent( newEvent ); // commit
    return;
  }

  mace::Event::setLastContextMappingVersion( newEvent.eventID );
  newEvent.eventContextMappingVersion = newEvent.eventID;

  mace::MaceAddr removeMappingReturn = contextMapping.removeMapping( contextName );
  const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot( newEvent.eventID ) ; // create ctxmap snapshot
  ASSERT( ctxmapCopy != NULL );

  contextEventRecord.deleteContextEntry( contextName, contextID, newEvent.eventID );
  newEvent.setSkipID( instanceUniqueID, contextID, newEvent.eventID );

  BaseMaceService::globalNotifyNewContext( newEvent, instanceUniqueID );

  send__event_RemoveContextObject( newEvent.eventID, *ctxmapCopy, removeMappingReturn, contextID );
  BaseMaceService::globalNotifyNewEvent( newEvent, instanceUniqueID );

  lock.downgrade( mace::AgentLock::READ_MODE ); // downgrade to read mode to allow later events to enter.
}
void ContextService::handle__event_RemoveContextObject( uint64_t const eventID, mace::ContextMapping const& ctxmapCopy, MaceAddr const& dest, uint32_t contextID ){
    ThreadStructure::setEvent( eventID );
    ThreadStructure::myEvent().eventType = mace::Event::DELETECONTEXT;
    mace::ContextBaseClass *thisContext = getContextObjByID( contextID ); 
    // make sure previous events have released the context.
    mace::ContextLock ctxlock( *thisContext, mace::ContextLock::WRITE_MODE );
    ctxlock.downgrade( mace::ContextLock::NONE_MODE );
    eraseContextData( thisContext );// erase the context from this node.

    // TODO: commit the delete context event
}
void ContextService::copyContextData(mace::ContextBaseClass* thisContext, mace::string& s ) const{
    mace::serialize(s, thisContext );
}
void ContextService::eraseContextData(mace::ContextBaseClass* thisContext){
    ADD_SELECTORS("ContextService::eraseContextData");
    uint32_t contextID = thisContext->getID();
    mace::string contextName = thisContext->getName();
    macedbg(1)<<"Erase context object '" << contextName << "'"<<Log::endl;
    // (1) erase the context object
    delete thisContext;
    // (2) remove the context object from ctxobjIDMap & ctxobjNameMap
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjIDMap.find( contextID );
    ASSERT( cpIt != ctxobjIDMap.end() );
    ctxobjIDMap.erase( cpIt );
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt2 = ctxobjNameMap.find( contextName );
    ASSERT( cpIt2 != ctxobjNameMap.end() );
    ctxobjNameMap.erase( cpIt2 );
}

void ContextService::handleInternalMessages( mace::InternalMessage const& message, MaceAddr const& src ){

  switch( message.getMessageType() ){
    case mace::InternalMessage::UNKNOWN: break;
    case mace::InternalMessage::ALLOCATE_CONTEXT_OBJECT: {
     mace::AllocateContextObject_Message* m = static_cast< mace::AllocateContextObject_Message* >( message.getHelper() );
     handle__event_AllocateContextObject( src, m->destNode, m->ContextID, m->eventID, m->contextMapping, m->eventType );
      break;
    }
    case mace::InternalMessage::CONTEXT_MIGRATION_REQUEST:{
     mace::ContextMigrationRequest_Message* m = static_cast< mace::ContextMigrationRequest_Message* >( message.getHelper() );
     handle__event_ContextMigrationRequest( src, m->ctxId, m->dest, m->rootOnly, m->event, m->prevContextMapVersion, m->nextHops );
      break;
    }
    case mace::InternalMessage::TRANSFER_CONTEXT:{
     mace::TransferContext_Message* m = static_cast< mace::TransferContext_Message* >( message.getHelper() );
     handle__event_TransferContext( src, m->rootContextID, m->ctxId, m->ctxNId, m->checkpoint, m->eventId, m->parentContextNode, m->isresponse);
      break;
    }
    case mace::InternalMessage::CREATE:{
     mace::create_Message* m = static_cast< mace::create_Message* >( message.getHelper() );
     handle__event_create( src, m->extra, m->counter );
      break;
    }
    case mace::InternalMessage::CREATE_HEAD:{
     mace::create_head_Message* m = static_cast< mace::create_head_Message* >( message.getHelper() );
     handle__event_create_head( m->extra, m->counter, m->src );
      break;
    }
    case mace::InternalMessage::CREATE_RESPONSE:{
     mace::create_response_Message* m = static_cast< mace::create_response_Message* >( message.getHelper() );
     handle__event_create_response( m->event , m->counter , m->targetAddress);
      break;
    }
    case mace::InternalMessage::EXIT_COMMITTED:{
     handle__event_exit_committed(  );
      break;
    }
    case mace::InternalMessage::ENTER_CONTEXT:{
     mace::enter_context_Message* m = static_cast< mace::enter_context_Message* >( message.getHelper() );
     handle__event_enter_context( m->event, m->contextIDs );
      break;
    }
    case mace::InternalMessage::COMMIT:{
     mace::commit_Message* m = static_cast< mace::commit_Message* >( message.getHelper() );
     handle__event_commit( m->event );
      break;
    }
    case mace::InternalMessage::COMMIT_CONTEXT:{
     mace::commit_context_Message* m = static_cast< mace::commit_context_Message* >( message.getHelper() );
     handle__event_commit_context( m->nextHops, m->eventID, m->eventType, m->eventContextMappingVersion, m->eventSkipID, m->isresponse, m->hasException, m->exceptionContextID);
      break;
    }
    case mace::InternalMessage::SNAPSHOT:{
     mace::snapshot_Message* m = static_cast< mace::snapshot_Message* >( message.getHelper() );
     handle__event_snapshot( m->event , m->ctxID , m->snapshotContextID , m->snapshot);
      break;
    }
    case mace::InternalMessage::DOWNGRADE_CONTEXT:{
     mace::downgrade_context_Message* m = static_cast< mace::downgrade_context_Message* >( message.getHelper() );
     handle__event_downgrade_context( m->contextID , m->eventID , m->isresponse);
      break;
    }
    case mace::InternalMessage::EVICT:{
     handle__event_evict( src );
      break;
    }
    case mace::InternalMessage::MIGRATE_CONTEXT:{
     mace::migrate_context_Message* m = static_cast< mace::migrate_context_Message* >( message.getHelper() );
     handle__event_migrate_context( m->newNode, m->contextName, m->delay );
      break;
    }
    case mace::InternalMessage::MIGRATE_PARAM:{
     mace::migrate_param_Message* m = static_cast< mace::migrate_param_Message* >( message.getHelper() );
     handle__event_migrate_param( m->paramid  );
      break;
    }
    case mace::InternalMessage::REMOVE_CONTEXT_OBJECT:{
     mace::RemoveContextObject_Message* m = static_cast< mace::RemoveContextObject_Message* >( message.getHelper() );
     handle__event_RemoveContextObject( m->eventID , m->ctxmapCopy , m->dest , m->contextID);
      break;
    }
    case mace::InternalMessage::DELETE_CONTEXT:{
     mace::delete_context_Message* m = static_cast< mace::delete_context_Message* >( message.getHelper() );
     handle__event_delete_context( m->contextName  );
      break;
    }
    case mace::InternalMessage::NEW_HEAD_READY:{
     handle__event_new_head_ready( src  );
      break;
    }
    case mace::InternalMessage::ROUTINE_RETURN:{
     mace::routine_return_Message* m = static_cast< mace::routine_return_Message* >( message.getHelper() );
     handle__event_routine_return( m->returnValue, m->event  );
      break;
    }
    case mace::InternalMessage::ASYNC_EVENT:{
      mace::AsyncEvent_Message* h = static_cast< mace::AsyncEvent_Message*>( message.getHelper() );
       handleEventMessage( h );
       message.unlinkHelper();
       break;
     }
     case mace::InternalMessage::APPUPCALL:{
       mace::ApplicationUpcall* m = static_cast< mace::AsyncEvent_Message* >( message.getHelper() );
       processRPCApplicationUpcall( m, src );
       break;
     }
    case mace::InternalMessage::APPUPCALL_RETURN:{
     mace::appupcall_return_Message* m = static_cast< mace::appupcall_return_Message* >( message.getHelper() );
     handle__event_appupcall_return( m->returnValue, m->event  );
      break;
    }
    case mace::InternalMessage::ROUTINE:{
     mace::Routine_Message* m = static_cast< mace::Routine_Message* >( message.getHelper() );
      handleRoutineMessage( m, src);
      break;
    }
    //default: throw(InvalidMaceKeyException("Deserializing bad internal message type "+boost::lexical_cast<std::string>(msgType)+"!"));
    
  }
}
// Assuming events created from message delivery, or downcall transition can only take place at head node.
void ContextService::handleEventMessage( mace::AsyncEvent_Message* m ){
    ADD_SELECTORS("ContextService::handleEventMessage");
    mace::ContextBaseClass * contextObject = getContextObjByName( m->getExtra().targetContextID );
    macedbg(1)<<"Enqueue a message into context event dispatch queue: "<< m <<Log::endl;
    contextObject->enqueueEvent(this,m ); 

 }

void ContextService::handleRoutineMessage( mace::Routine_Message* m, mace::MaceAddr const& source ){
    ADD_SELECTORS("ContextService::handleEventMessage");
    mace::ContextBaseClass * contextObject = getContextObjByID( m->getTargetContextID() );
    macedbg(1)<<"Enqueue a message into context event dispatch queue: "<< m <<Log::endl;
    contextObject->enqueueRoutine(this, m, source ); 

 }

void ContextService::handle__event_AllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType){
    mace::Event currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );

    ThreadStructure::setEventContextMappingVersion();

    MaceAddr headAddr;
    if( this->contextMapping.hasSnapshot( eventID ) ){
      ASSERTMSG( (headAddr = this->contextMapping.getHead() ) == Util::getMaceAddr(), "If this physical node has the context mapping version, it should be the head");
    }else{
      this->contextMapping.snapshotInsert( eventID, contextMapping );
      this->contextMapping = contextMapping; 
      ASSERTMSG( (headAddr = this->contextMapping.getHead() ) != Util::getMaceAddr(), "If this physical node does not have the context mapping version, it should not be the head");
    }

    if( isLocal( destNode ) && destNode != headAddr ){ 
      // if the context is at the head node, asyncHead() creates the context already
      for( mace::map< uint32_t, mace::string >::const_iterator ctxIt = ContextID.begin(); ctxIt != ContextID.end(); ctxIt++ ){
        mace::ContextBaseClass *thisContext = createContextObject( eventID, ctxIt->second, ctxIt->first ); // create context object
        ASSERTMSG( thisContext != NULL, "createContextObject() returned NULL!");
      }
    }

}
void ContextService::handle__event_ContextMigrationRequest( MaceAddr const& src, uint32_t const& rootContextID, MaceAddr const& dest, bool const& rootOnly, mace::Event const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& msgnextHops ){
    ASSERT( !rootOnly || (msgnextHops.size() == 1 && msgnextHops[0] == rootContextID  ) );

    ThreadStructure::setEvent( event );
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    
    // configure to use the old mapping (before migration )
    ThreadStructure::setEventContextMappingVersion( prevContextMapVersion );
    const mace::ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot() ;

    bool isRoot = false;
    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for( mace::vector< uint32_t >::const_iterator nextHopIt = msgnextHops.begin(); nextHopIt != msgnextHops.end(); nextHopIt ++ ){
      const uint32_t thisContextID = *nextHopIt;
      if( isRoot == false && thisContextID == rootContextID ){ isRoot = true;}

      mace::ContextBaseClass *thisContext = getContextObjByID( thisContextID); // assuming context object already exists and this operation does not create new object.
      mace::string contextData;
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::WRITE_MODE );
      copyContextData( thisContext, contextData );

      send__event_TransferContext( dest, rootContextID, thisContext->getName(), thisContext->getID(),contextData, event.getEventID(), src, false);

      // If the entire context subtree will be migrated, send message to child contexts
      if( ! rootOnly ){
        ctxlock.downgrade( mace::ContextLock::NONE_MODE );
        eraseContextData( thisContext );// erase the context from this node.
        const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( ctxmapSnapshot, thisContextID );
        for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
          const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, *subctxIter );
          ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
          nextHops[ nextHopAddr ].push_back( *subctxIter );
        }
      }
    }

    if( rootOnly ){
      ASSERT( isRoot );
      mace::ContextBaseClass *thisContext = getContextObjByID( rootContextID);
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::NONE_MODE );
      eraseContextData( thisContext );// erase the context from this node.
    }else{ // send migration message to subcontexts
      mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
      for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
        send__event_ContextMigrationRequest( addrIt->first, rootContextID, dest, rootOnly, event, prevContextMapVersion, addrIt->second  );
      }
    }
}
void ContextService::handle__event_TransferContext( MaceAddr const& src, uint32_t const rootContextID, mace::string const& contextName, uint32_t const& contextID, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse ){

    mace::ContextBaseClass* thisContext = getContextObjByName(contextName);
    
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    mace::Event& myEvent = ThreadStructure::myEvent();
    myEvent.eventType = mace::Event::MIGRATIONEVENT;
    myEvent.eventID = eventId;
    myEvent.setSkipID( instanceUniqueID , contextID, eventId );
    ASSERT( thisContext->getNowServing() == eventId );
    // create object using name string
    mace::deserialize( checkpoint, thisContext );

    // local commit.
    // notice that the same event has also already downgraded the original context object copy.
    mace::ContextLock c_lock( *thisContext, mace::ContextLock::WRITE_MODE );
    c_lock.downgrade( mace::ContextLock::NONE_MODE );
    if( rootContextID == contextID ){
      send__event_commit( contextMapping.getHead(), myEvent );
      myEvent.clearEventRequests();
      myEvent.clearEventUpcalls();
    }
    // TODO: send response
}
void ContextService::handle__event_create( MaceAddr const& src, __asyncExtraField const& extra, uint64_t const& counter ){
  if( mace::Event::isExit ) {
    wasteTicket();
    return;
  }
  mace::InternalMessage m(mace::create_head, extra, counter, src);
  HeadEventDispatch::HeadEventTP::executeEvent( const_cast<ContextService*>(this), (HeadEventDispatch::eventfunc)&ContextService::handleInternalMessagesWrapper, new mace::InternalMessage(m), true );

}
void ContextService::handle__event_commit( mace::Event const& event ) const{
    /* the commit msg is sent to head, head send to global context and goes down the entire context tree to downgrade the line.
    after that, the head performs commit which effectively releases deferred messages and application upcalls */
    HeadEventDispatch::HeadEventTP::commitEvent( event );
}

void ContextService::handle__event_commit_context( mace::vector< uint32_t > const& msgnextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const{
    // recursively downgrade contexts until it reaches exceptionContextID or reaches the bottom of context lattice
    ASSERT( !msgnextHops.empty() );

    mace::Event currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );
    if( isresponse ){
        pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
        pthread_cond_signal( mace::ContextBaseClass::eventCommitConds[eventID] );
        pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );
        return;
    }
    ThreadStructure::setEventContextMappingVersion ( eventContextMappingVersion );
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    ThreadStructure::myEvent().eventSkipID = eventSkipID;
    const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
    mace::vector< uint32_t >::const_iterator nextHopIt;
    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for(  nextHopIt = msgnextHops.begin(); nextHopIt != msgnextHops.end(); nextHopIt++ ){
      const uint32_t thisContextID = *nextHopIt;

      if( hasException && exceptionContextID == thisContextID ){ continue; }

      mace::ContextBaseClass * thisContext = getContextObjByID( thisContextID);
      mace::ContextLock cl( *thisContext, mace::ContextLock::NONE_MODE );
      
      const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( snapshotMapping, thisContextID );
      for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
        const uint32_t nextHop = *subctxIter;
        const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, nextHop );
        ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
        nextHops[ nextHopAddr ].push_back( nextHop );
      }
    }
    mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
    for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
      const_send__event_commit_context( addrIt->first, addrIt->second, eventID,ThreadStructure::myEvent().eventType, eventContextMappingVersion, eventSkipID, false, hasException, exceptionContextID );
    }
    //waitChildContextResponse();

    // respond to parent context
    /*if( msgnextHops[ 0 ] != 1 ){

    }*/
}

void ContextService::handle__event_create_response( mace::Event const& event, uint32_t const& counter, MaceAddr const& targetAddress){
  ADD_SELECTORS("ContextService::handle__event_create_response");
  // read from buffer
  
  ScopedLock sl( eventRequestBufferMutex );
  maceout<<"Event "<< event.eventID << ", counter = "<< counter <<" is sent to "<< targetAddress <<Log::endl;
  std::map< uint32_t, std::pair<mace::string*, mace::string > >::iterator ueIt = unfinishedEventRequest.find( counter );
  ASSERT( ueIt != unfinishedEventRequest.end() );
  std::pair< mace::string*, mace::string >& eventreq = ueIt->second;
  eventreq.first->erase(  eventreq.first->size() - eventreq.second.size() ); //remove the Event field from message
  /*__asyncExtraField extra;
  mace::deserialize( eventreq.second, &extra);*/
  /*extra.event = event;
  extra.isRequest = false;*/
  mace::string event_str;
  mace::serialize( event_str , &event );
  eventreq.first->append( event_str );

  mace::string* eventmsg = eventreq.first;

  unfinishedEventRequest.erase( ueIt );
  sl.unlock();

  const mace::MaceKey destNode( mace::ctxnode, targetAddress  );
  //sender->routeEventRequest( destNode, *eventmsg );

  delete eventmsg;

}

void ContextService::handle__event_enter_context( mace::Event const& event, mace::vector< uint32_t > const& contextIDs ){
  ThreadStructure::setEvent( event );
  for( mace::vector< uint32_t >::const_iterator ctxidIt = contextIDs.begin(); ctxidIt != contextIDs.end(); ctxidIt++ ){
    mace::ContextBaseClass * thisContext = getContextObjByID( *ctxidIt );
    mace::ContextLock __contextLock( *thisContext, mace::ContextLock::WRITE_MODE); // acquire context lock. 
  }

}
void ContextService::handle__event_exit_committed( ){
  // this message is supposed to be received by non-head nodes.
  // if the main thread is blocking in maceExit(), wake it up
  proceedExit();
  // if maceExit() has not been called at this node....?
}
void ContextService::handle__event_create_head( __asyncExtraField const& extra, uint64_t const& counter, MaceAddr const& src){
  if( mace::Event::isExit ) {
    //mace::AgentLock::skipTicket();
    return;
  }
  asyncHead( ThreadStructure::myEvent(), extra, mace::Event::ASYNCEVENT );


  const MaceAddr& targetContextAddr = contextMapping.getNodeByContext( extra.targetContextID );
  send__event_create_response( src, ThreadStructure::myEvent(), counter, targetContextAddr );
}
void ContextService::handle__event_snapshot( mace::Event const& event, mace::string const& ctxID, mace::string const& snapshotContextID, mace::string const& snapshot){
  // store the snapshoeventt
  pthread_mutex_lock(&mace::ContextBaseClass::eventSnapshotMutex );
  std::pair< uint64_t, mace::string > key( event.eventID, ctxID );
  std::map<mace::string, mace::string>& snapshots = mace::ContextBaseClass::eventSnapshotStorage[ key ];
  snapshots[ snapshotContextID ] = snapshot;
  // if the event is waiting in the target context, notify it.
  std::map<uint64_t, pthread_cond_t*>::iterator condIt = mace::ContextBaseClass::eventSnapshotConds.find( event.eventID );
  if( condIt !=  mace::ContextBaseClass::eventSnapshotConds.end() ){
      pthread_cond_signal( condIt->second );
  }
  pthread_mutex_unlock(&mace::ContextBaseClass::eventSnapshotMutex );
}
void ContextService::handle__event_downgrade_context( uint32_t const& contextID, uint64_t const& eventID, bool const& isresponse ){
  if( isresponse ){
    mace::ScopedContextRPC::wakeup( eventID );
  }else{
    mace::Event currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );
    mace::ContextBaseClass *thisContext = getContextObjByID( contextID);
    mace::ContextLock cl( *thisContext, mace::ContextLock::READ_MODE );
  }
}
void ContextService::handle__event_routine_return( mace::string const& returnValue, mace::Event const& event){

  ThreadStructure::setEventContextMappingVersion ( event.eventContextMappingVersion );
  mace::ScopedContextRPC::wakeupWithValue( returnValue, event );
}
void ContextService::handle__event_appupcall_return( mace::string const& returnValue, mace::Event const& event){

  ThreadStructure::setEventContextMappingVersion ( event.eventContextMappingVersion );
  mace::ScopedContextRPC::wakeupWithValue( returnValue, event );
}
void ContextService::handle__event_evict( MaceAddr const& src ){
  
  // TODO: determine the contexts on the node
  mace::list< mace::string > contexts;
  // use the latest context mapping version
  contextMapping.getContextsOfNode( src, contexts );

  // TODO: call requestContextMigration() to migrate the contexts
  for( mace::list< mace::string >::iterator ctxIt = contexts.begin(); ctxIt != contexts.end(); ctxIt++ ){
    // app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
    requestContextMigrationCommon( instanceUniqueID, *ctxIt,src, false );
  }

  // go to the lower services
}
/**
 * TODO: unfinished
 *
 * */
void ContextService::handle__event_new_head_ready( MaceAddr const& src ){
  // TODO: make sure it's the old head

  // create 'head migration' event. This event contains the new context mapping where the new head is the head
  mace::Event& newEvent = ThreadStructure::myEvent( );
  newEvent.newEventID( mace::Event::HEADMIGRATIONEVENT );
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE ); // this lock is used to make sure the event is created in order.

  {
    newEvent.initialize(  );

    // update context mapping information
    const MaceAddr newHead = src;

    contextMapping.newHead( newHead );

    // this node will also likely inform the scheduler the address change of the logical node.

    // inform the change
    const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot

    // chuangw: incomplete....
    /*mace::map< uint32_t, mace::string > emptyContextSet;

    __event_AllocateContextObject allocateCtxMsg( newHead, emptyContextSet, newEvent.getEventID(), *ctxmapCopy, 0 );
    // send message to the new head about the latest context mapping
    ASYNCDISPATCH( newHead , __ctx_dispatcher, __event_AllocateContextObject , allocateCtxMsg );*/

    mace::map< uint32_t, mace::string > contextSet; // empty set
    send__event_AllocateContextObjectMsg( newEvent.eventID, ctxmapCopy, newHead, contextSet, 0 ); 

    // set a flag to indicate future event requests to this old head should be forward to the new head
    // --> set head status to "migrating"
    // --> set the head migrating event id
    HeadEventDispatch::HeadMigration::setState( HeadEventDispatch::HeadMigration::HEAD_STATE_MIGRATING );
    HeadEventDispatch::HeadMigration::setMigrationEventID( newEvent.getEventID() );
    HeadEventDispatch::HeadMigration::setNewHead( newHead );



    //c_lock.downgrade( mace::ContextLock::NONE_MODE );
  }

}
void ContextService::handle__event_migrate_context( mace::MaceAddr const& newNode, mace::string const& contextName, uint64_t const delay ){

}
#include "StrUtil.h"
void ContextService::handle__event_migrate_param( mace::string const& paramid ){
  // 1. split paramid into an array of parameter id
  StringList paramlist = StrUtil::split( " ", paramid);

  for (StringList::const_iterator i = paramlist.begin(); i != paramlist.end(); i++) {
    std::string const& param_id = *i;
    MaceAddr dest = MaceKey(ipv4, params::get<std::string>( param_id + ".dest" ) ).getMaceAddr();
    StringList contexts = StrUtil::split(" \n", params::get<mace::string>( param_id + ".contexts" ));
    uint8_t service = static_cast<uint8_t>(params::get<uint32_t>( param_id + ".service" ));
    ASSERT( service == instanceUniqueID );
    for( StringList::iterator ctxIt = contexts.begin(); ctxIt != contexts.end(); ctxIt ++ ){
      mace::string contextName = *ctxIt;
      std::cout << " migrate context "<< contextName <<" of service "<< service <<std::endl;
      requestContextMigrationCommon(service, contextName, dest , false);
    }
  }
}
void ContextService::handle__event_delete_context( mace::string const& contextName ){
  doDeleteContext( contextName );
}
mace::ContextMapping const& ContextService::asyncHead( mace::Event& newEvent, mace::__asyncExtraField const& extra, int8_t const eventType){
  ADD_SELECTORS("ContextService::asyncHead");
  // SHYOO : Add artificial delay to test head node performance.
  static int32_t sleep_time = -1;
  if( sleep_time == -1) {
    sleep_time = (int32_t) params::get<uint32_t>("HEAD_NODE_USLEEP", 0);
  }
  newEvent.newEventID( eventType, ThreadStructure::myTicket() );
  newEvent.initialize(  );
  mace::AgentLock lock( mace::AgentLock::WRITE_MODE ); // global lock is used to ensure new events are created in order
  macedbg(1)<<"initialize a new event ticket = "<< newEvent.eventID << ", type="<< eventType << " target context = "<< extra.targetContextID << Log::endl;
  if( sleep_time > 0 ) {
    usleep(sleep_time);
  }

  // WC: this case happens when the ticket shouldn't be used.
  if( eventType == mace::Event::UNDEFEVENT ){

    lock.downgrade( mace::AgentLock::READ_MODE ); // downgrade to read mode to allow later events to enter.
    // chuangw: this is returned simply to satisfy the function signature. The return value is not valid and should not be used.
    return contextMapping;
  }
  const mace::ContextMapping* snapshotContext = & ( contextMapping.getSnapshot( newEvent.getLastContextMappingVersion() ) );
  uint32_t contextID = mace::ContextMapping::hasContext2( *snapshotContext, extra.targetContextID );
  if( contextID > 0 ){ // the context exists
    contextEventRecord.updateContext( contextID, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );
  }else{// create a new context

    mace::Event::setLastContextMappingVersion( newEvent.eventID );
    newEvent.eventContextMappingVersion = newEvent.eventID;
    std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( extra.targetContextID );
    const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot( newEvent.eventID ) ; // create ctxmap snapshot
    ASSERT( ctxmapCopy != NULL );
    contextEventRecord.createContextEntry( extra.targetContextID, newMappingReturn.second, newEvent.eventID );
    newEvent.setSkipID( instanceUniqueID, newMappingReturn.second, newEvent.eventID );

    // notify other services about the new context
    BaseMaceService::globalNotifyNewContext( newEvent, instanceUniqueID );

    mace::map< uint32_t, mace::string > contextSet; 
    contextSet[ newMappingReturn.second ] =  extra.targetContextID;

    if( isLocal( newMappingReturn.first ) ){
      createContextObject( newEvent.eventID, extra.targetContextID  , newMappingReturn.second  );
    }
    send__event_AllocateContextObjectMsg( newEvent.eventID, ctxmapCopy, newMappingReturn.first, contextSet, 0 );

    snapshotContext = ctxmapCopy;
  }

  // notify other services about this event
  BaseMaceService::globalNotifyNewEvent( newEvent, instanceUniqueID );
                  
  static bool recordFinishTime = params::get("EVENT_LIFE_TIME",false);
  if( recordFinishTime ){
    HeadEventDispatch::insertEventStartTime(newEvent.getEventID());
  }

  // if it's the ENDEVENT (maceExit) is called, shutdown HeadEventDispatch thread
  if( eventType == mace::Event::ENDEVENT ){
    HeadEventDispatch::prepareHalt( newEvent.getEventID() );
  }
  lock.downgrade( mace::AgentLock::READ_MODE ); // downgrade to read mode to allow later events to enter.

  return *snapshotContext;
}
void ContextService::__beginTransition( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs  ) const {
  ThreadStructure::pushServiceInstance( instanceUniqueID ); 
  __beginMethod( targetContextID, snapshotContextIDs );
}
void ContextService::__beginMethod( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs ) const {
    ADD_SELECTORS("ContextService::__beginMethod");
  ThreadStructure::pushContext( targetContextID );
  ThreadStructure::insertEventContext( targetContextID );
  mace::ContextBaseClass * thisContext = getContextObjByID( targetContextID );
  ThreadStructure::setMyContext( thisContext );



  getContextSnapshot(snapshotContextIDs);


/*
  // FIXME: chuangw: i don't have to to make snapshot taking work. will come back later.
  if( !extra.snapshotContextIDs.empty()  ){
    size_t nsnapshots = extra.snapshotContextIDs.size();
    uint64_t ticket = ThreadStructure::myTicket();
    // wait for snapshots
    pthread_mutex_lock( &mace::ContextBaseClass::eventSnapshotMutex  );
    std::pair< uint64_t, mace::string > key( ticket, extra.targetContextID );
    while( mace::ContextBaseClass::eventSnapshotStorage[ key ].size() < nsnapshots ){
        // add cond variable to a public static map
        pthread_cond_t cond;
        pthread_cond_init( &cond, NULL );
        mace::ContextBaseClass::eventSnapshotConds[ ticket ] = &cond;
        pthread_cond_wait(&cond , &mace::ContextBaseClass::eventSnapshotMutex);
        macedbg(1)<<extra.targetContextID<<" received snapshot number: "<< mace::ContextBaseClass::eventSnapshotStorage[ key ].size() <<Log::endl;
    }
    // copy the snapshot
    pthread_mutex_unlock( &mace::ContextBaseClass::eventSnapshotMutex);

    for( mace::set<mace::string>::const_iterator ssIt= extra.snapshotContextIDs.begin(); ssIt != extra.snapshotContextIDs.end(); ssIt++ ){
        mace::ContextBaseClass *ssContext = getContextObjByName( *ssIt ); // XXX: make sure I'm not holding any lock??
        std::pair<uint64_t, mace::string> key( ticket, extra.targetContextID );
        ssContext->setSnapshot( ticket, mace::ContextBaseClass::eventSnapshotStorage[key][ *ssIt ] );
    }
  }
*/

  mace::ContextLock __contextLock( *thisContext , mace::ContextLock::WRITE_MODE); // acquire context lock. 
}
void ContextService::__finishTransition(mace::ContextBaseClass* oldContext) const {
  bool isOuterMostTransition;
  // chuangw: it seems to be an ok heuristic for dtermining which service is the outer-most.
  mace::Event& currentEvent = ThreadStructure::myEvent();
  if( currentEvent.eventType == mace::Event::STARTEVENT ){
    // for start, it's the last (outermost) transition that should commit the event.
    isOuterMostTransition = ( instanceUniqueID == 0 )?true: false;
  }else if( currentEvent.eventType == mace::Event::ENDEVENT ){
    // for endevent, it's the first (innermost) transition that should commit the event.
    isOuterMostTransition = ( instanceUniqueID == instanceID.size()-1  )?true: false;
  }else{
    isOuterMostTransition = ThreadStructure::isOuterMostTransition();
  }

  if( currentEvent.eventType == mace::Event::STARTEVENT || currentEvent.eventType == mace::Event::ENDEVENT || isOuterMostTransition){
    const mace::Event::EventServiceContextType& contexts = ThreadStructure::getCurrentServiceEventContexts();
    if( contexts.find( ThreadStructure::getCurrentContext() ) != contexts.end() ){
      downgradeCurrentContext();
    }

    globalDowngradeEventContext(); // downgrade all remaining contexts that the event has ever entered.
  }
  if( isOuterMostTransition ){
    // inform the head to commit before downgrading contexts. this event is ready to do global commit
    currentEvent.clearSkipID();
    currentEvent.clearContexts();
    currentEvent.clearSnapshotContexts();
    MaceAddr const& headAddr = contextMapping.getHead();
    if( isLocal( headAddr ) ){
      HeadEventDispatch::HeadEventTP::commitEvent( currentEvent );
    }else{
      const_send__event_commit( headAddr, currentEvent );
      currentEvent.clearEventRequests();
    }
  }
  __finishMethod(oldContext);
  ThreadStructure::popServiceInstance( ); 
}
void ContextService::__finishMethod(mace::ContextBaseClass* oldContext) const {
  ThreadStructure::popContext( );
  ThreadStructure::setMyContext( oldContext );
}
void ContextService::enterInnerService (mace::string const& targetContextID ) const{
      mace::vector< uint32_t > nextHops;
      const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
      const mace::string globalContextName("");
      uint32_t globalContextID = snapshotMapping.findIDByName( globalContextName );
      nextHops.push_back( globalContextID );
      if( !ThreadStructure::isEventEnteredService(instanceUniqueID) && targetContextID != globalContextName ){
          // Since it is the first transition of this service,
          // it has to downgrade higher-level contexts before entering the call.
          // this is similar to async calls
          mace::Event& he = ThreadStructure::myEvent();
          uint32_t targetContextNID = snapshotMapping.findIDByName( targetContextID );
          const_send__event_commit_context( mace::ContextMapping::getNodeByContext( snapshotMapping, globalContextID ), nextHops, he.eventID, he.eventType, he.eventContextMappingVersion, he.eventSkipID, false, true, targetContextNID );
      }
}
void ContextService::notifyNewEvent( mace::Event & he, const uint8_t serviceID ) {
    ADD_SELECTORS("ContextService::notifyNewEvent");

    if( serviceID == instanceUniqueID ) { return; }
    // no need to lock -- this is called when ContextLock is in WRITE_MODE
    //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewEvent" );
    //ASSERTMSG( mace::ContextBaseClass::headContext.getCurrentMode() == mace::ContextLock::WRITE_MODE, "notifyNewEvent() must be called only when head node is in ContextLock::WRITE_MODE" );
    ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "notifyNewEvent() must be called only when head node is in AgentLock::WRITE_MODE" );

    //mace::Event& he = ThreadStructure::myEvent();

    if( he.getEventType() == mace::Event::MIGRATIONEVENT ){
      // if it's a migration event and is not initiated in this service, don't update context event record
      // because the migration event will not enter this service at all.
      return;
    }

    // If the event is not created in this service, it is guaranteed the all the contexts in this service will be
    // explicitly downgraded by this event. So all later events entering this service should wait for this event
    // i.e. It is as if the event in this service starts from the global context
    const mace::string globalContext = ""; 

    contextEventRecord.updateContext( globalContext, he.eventID, he.getSkipIDStorage( instanceUniqueID ) );
}
void ContextService::notifyNewContext(mace::Event & he,  const uint8_t serviceID ) {
    ADD_SELECTORS("ContextService::notifyNewContext");
    // no need to lock -- this is called when ContextLock is in WRITE_MODE
    //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewContext" );
    ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "notifyNewContext() must be called only when head node is in AgentLock::WRITE_MODE" );

    //mace::Event& he = ThreadStructure::myEvent();

    if( serviceID == instanceUniqueID ) { return; }
    if( he.eventType == mace::Event::STARTEVENT ){
      const mace::string globalContextID = "";
      // if it's a start event, the head has to create a mapping to global context
      // to prevent race condition, the global context of every service in the composition has to be created explicitly in the first event (that is, maceInit)

      std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( globalContextID );
      const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot( he.eventID ) ; // create ctxmap snapshot
      ASSERT( ctxmapCopy != NULL );
      contextEventRecord.createContextEntry( globalContextID, newMappingReturn.second, he.eventID );
      he.setSkipID( instanceUniqueID, newMappingReturn.second, he.eventID );

      if( isLocal( newMappingReturn.first ) ){ // the new context co-locates with the head
        mace::ContextBaseClass *globalContext = createContextObject( he.eventID, globalContextID, newMappingReturn.second );
        ASSERT( globalContext != NULL );
      }else{
        remoteAllocateGlobalContext( globalContextID, newMappingReturn, ctxmapCopy );
      }
      return;
    }

    ASSERTMSG( !contextMapping.hasSnapshot( he.eventID ), "The new context is not created in this service, why does it have this version of context mapping?" );
    const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot( he.eventID  ) ; // create ctxmap snapshot
    ASSERT( ctxmapCopy != NULL );

    mace::map< uint32_t, mace::string > contextSet; // empty set
    send__event_AllocateContextObjectMsg( he.eventID, ctxmapCopy, SockUtil::NULL_MACEADDR, contextSet, 0 );
}
void ContextService::downgradeEventContext( ){
  ADD_SELECTORS("ContextService::downgradeEventContext");

  mace::Event& myEvent = ThreadStructure::myEvent();
  const uint64_t myTicket = myEvent.getEventID();
  uint8_t commitInitiatorServiceID = 0;
  if( myEvent.eventType == mace::Event::ENDEVENT ){
    commitInitiatorServiceID = ThreadStructure::getServiceInstance();
  }
  ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
  ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContextID() );
  // (1) move the block/write/read lines down to the bottom of the context hierarchy.
  // send the commit message to the read-line cut 

  switch( myEvent.eventType ){
    case mace::Event::NEWCONTEXTEVENT:
      return;
      break;
    case mace::Event::ENDEVENT:
      if( commitInitiatorServiceID != instanceUniqueID ){
        return;
      }
      break;
    case mace::Event::STARTEVENT:
      return;
      break;
  }
  // if new-context-event, all contexts will be entered, no need to commit contexts again
  bool enteredService = ThreadStructure::isEventEnteredService(instanceUniqueID);
  const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot( myEvent.eventContextMappingVersion );
  mace::ReadLine rl( snapshotMapping ); 
  if( !enteredService && rl.getCut().empty() ){ // this means the event did not enter this service.
    
    mace::vector< uint32_t > nextHops;
    uint32_t globalContextID = snapshotMapping.findIDByName("");
    nextHops.push_back( globalContextID );
    const_send__event_commit_context( mace::ContextMapping::getNodeByContext(  snapshotMapping, globalContextID ),nextHops, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
  }else{

    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for( mace::list< uint32_t >::const_iterator cutIt = rl.getCut().begin(); cutIt != rl.getCut().end(); cutIt ++ ){
      const uint32_t childContextID = *cutIt;
      const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, childContextID );
      nextHops[ nextHopAddr ].push_back( childContextID );
    }
    mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
    for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
      const_send__event_commit_context( addrIt->first, addrIt->second, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
    }
  }

}
void ContextService::requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextName, const MaceAddr& destNode, const bool rootOnly){
  ADD_SELECTORS("ContextService::requestContextMigrationCommon");
  //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Context migration is requested, but this physical node is not head node." );
  // 1. create ticket to acquire AgentLock
  ThreadStructure::newTicket(); 
  mace::__event_MigrateContext *msg = new mace::__event_MigrateContext( ThreadStructure::myTicket(), serviceID, contextName, destNode, rootOnly );
  HeadEventDispatch::HeadEventTP::executeEvent( const_cast<ContextService*>(this), (HeadEventDispatch::eventfunc)&ContextService::handle__event_MigrateContext, msg, true ); 
}
void ContextService::handle__event_MigrateContext( void *p ){
  ADD_SELECTORS("ContextService::handle__event_MigrateContext");


  mace::__event_MigrateContext *msg = static_cast< mace::__event_MigrateContext * >( p );

  ThreadStructure::setTicket( msg->ticket );
  const mace::string& contextName = msg->contextName;
  const MaceAddr& destNode = msg->destNode;
  const bool rootOnly = msg->rootOnly;

  mace::Event& newEvent = ThreadStructure::myEvent( );
  newEvent.newEventID( mace::Event::MIGRATIONEVENT );
  // 2. acquire AgentLock, and then get the event ID. Remember to release AgentLock right after.
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE ); // this lock is used to make sure the event is created in order.

  // 3. Then initializes the migration event

  newEvent.initialize(  );

  // 4. Get the latest contextmap snapshot to determine the existence of context.
  //    If it doesn't exist, just store the context and the destination node as the default mapping
  //    so that when the context is created in the future, it will be created at that node.
  const ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot( );
  if( !contextMapping.hasContext( contextName ) ){
    maceout<<"Requested context does not exist. Ignore it but set it as the default mapping when the context is created in the future."<<Log::endl;
    mace::map<mace::MaceAddr ,mace::list<mace::string > > servContext;
    servContext[ destNode ].push_back( contextName );
    contextMapping.loadMapping( servContext );
    alock.downgrade( mace::AgentLock::READ_MODE );
    //clock.downgrade( mace::ContextLock::NONE_MODE );
    HeadEventDispatch::HeadEventTP::commitEvent( newEvent ); // commit
    return;
  }
  const MaceAddr& origNode = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, contextName );
  // ignore the requests that migrate a context to its original physical node
  if( origNode == destNode ){
    alock.downgrade( mace::AgentLock::READ_MODE );
    HeadEventDispatch::HeadEventTP::commitEvent( newEvent ); // commit
    return;
  }
  // 5. Ok. Let's roll.
  //    Create a new version of context map. Update the event skip id
  mace::Event::setLastContextMappingVersion( newEvent.eventID );
  const uint64_t prevContextMappingVersion = newEvent.eventContextMappingVersion;
  newEvent.eventContextMappingVersion = newEvent.eventID; // switch to the new context mapping version

  contextEventRecord.updateContext( contextName, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );

  // If rootOnly is true, migrate just one context
  // Otherwise, migrate the entire subtree. All contexts in the subtree will be migrated to the same node.
  mace::map< uint32_t, mace::string > offsprings;
  std::pair<bool, uint32_t>  updatedContext;
  if( rootOnly ){
    updatedContext = contextMapping.updateMapping( destNode, contextName ); 
    offsprings[ updatedContext.second ] =  contextName;

  }else{ // TODO: also update the mapping of child & all offspring contexts.
    // right now: support migrating the entire context subtree only if they all reside on the same physical node.
    offsprings = ContextMapping::getSubTreeContexts( ctxmapSnapshot, contextName );
    mace::set< mace::string > offspringContextNames;
    for( mace::map< uint32_t, mace::string >::iterator osIt = offsprings.begin(); osIt != offsprings.end(); osIt ++ ){
      offspringContextNames.insert( osIt->second );
    }
    
    contextMapping.updateMapping< mace::set<mace::string> >( destNode, offspringContextNames );
  }
  const mace::ContextMapping* ctxmapCopy = contextMapping.snapshot( ); // after the update, create ctxmap snapshot
  ASSERT( ctxmapCopy != NULL );
  macedbg(1)<<" The new version "<< newEvent.eventContextMappingVersion << " context map: "<< *ctxmapCopy << Log::endl;
   
  if( isLocal( destNode ) ){
    for( mace::map< uint32_t, mace::string >::const_iterator osIt = offsprings.begin(); osIt != offsprings.end(); osIt++ ){
      createContextObject( newEvent.eventID, osIt->second  , osIt->first  );
    }
  }

  // notify other services about the new context
  BaseMaceService::globalNotifyNewContext( newEvent, instanceUniqueID );
  BaseMaceService::globalNotifyNewEvent( newEvent, instanceUniqueID );

  // 6. Store this event and arguments for implementing failure recovery
  //    Commented because we are not implementing failure recovery now.
  /*mace::string dummybuf;
  mace::serialize( dummybuf, &newEvent.getEventType() );
  mace::serialize( dummybuf, &serviceID );
  mace::serialize( dummybuf, &contextName );
  mace::serialize( dummybuf, &destNode );
  mace::serialize( dummybuf, &rootOnly );
  mace::HierarchicalContextLock hl(newEvent, dummybuf );*/

  // 7. get the list of nodes belonging to the same logical node after the migration
  //    Send message to them to tell them a new context map is available, and create the new context object
  send__event_AllocateContextObjectMsg( newEvent.eventID, ctxmapCopy, destNode, offsprings, 0 ); 

  const uint32_t contextID = ctxmapSnapshot.findIDByName( contextName );

  mace::vector< uint32_t > nextHops;
  nextHops.push_back( contextID );
  send__event_ContextMigrationRequest( origNode, contextID, destNode, rootOnly, ThreadStructure::myEvent(), prevContextMappingVersion, nextHops  );

  static bool recordFinishTime = params::get("EVENT_LIFE_TIME",false);
  if( recordFinishTime ){
    HeadEventDispatch::insertEventStartTime(newEvent.getEventID());
  }
  alock.downgrade( mace::AgentLock::READ_MODE );

  delete msg;
}
void ContextService::sendAsyncSnapshot( __asyncExtraField const& extra, mace::string const& thisContextID, mace::ContextBaseClass* const& thisContext ){
  //ThreadStructure::myEvent().eventID = extra.event.eventID;
  mace::Event& myEvent = ThreadStructure::myEvent();
  mace::set<mace::string>::iterator snapshotIt = extra.snapshotContextIDs.find( thisContextID );
  if( snapshotIt != extra.snapshotContextIDs.end() ){
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::READ_MODE );// get read lock
      mace::string snapshot;// get snapshot
      mace::serialize(snapshot, thisContext );
      // send to the target context node.
      send__event_snapshot( contextMapping.getNodeByContext( extra.targetContextID ), myEvent,extra.targetContextID, *snapshotIt, snapshot );

      ctxlock.downgrade( mace::ContextLock::NONE_MODE );
  }else{
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::NONE_MODE );// get read lock
  }
}
// helper functions for maintaining context mapping
void ContextService::loadContextMapping(const mace::map<mace::MaceAddr ,mace::list<mace::string > >& servContext){
    contextMapping.setDefaultAddress ( Util::getMaceAddr() );
    contextMapping.loadMapping( servContext );
    contextMapping.snapshot( static_cast<uint64_t>( 0 ) );
}
void ContextService::downgradeContext( mace::string const& contextName ) {
  // TODO: 
  //(1) assert: the event has acquired the context before.
  const mace::ContextMapping& currentMapping = contextMapping.getSnapshot();
  const mace::Event::EventServiceContextType& eventContexts = ThreadStructure::getCurrentServiceEventContexts();
  const uint32_t contextID = currentMapping.findIDByName( contextName );
  ASSERTMSG( eventContexts.find( contextID ) != eventContexts.end(), "The event does not have the context" );   
  mace::AccessLine::checkDowngradeContext( instanceUniqueID, contextID, currentMapping );
  //(2) figure out the physical address of the context
  //(3) if it's local, call it. If not, send message and wait for response
  send__event_downgrade_context( mace::ContextMapping::getNodeByContext( currentMapping, contextID ), ThreadStructure::getCurrentContext(), ThreadStructure::myEvent().eventID, false );

  ThreadStructure::removeEventContext( ThreadStructure::getCurrentContext() );
}
void ContextService::requestRouteEvent ( __asyncExtraField& extra, mace::Event& event, mace::Serializable& msg ) const{
  ADD_SELECTORS("ContextService::requestRouteEvent");
  static uint32_t counter = 0;
  mace::string* msg_str = new mace::string();
  mace::string event_str;
  mace::serialize(*msg_str, &msg);
  mace::serialize(event_str, &event);
  ScopedLock sl( eventRequestBufferMutex );
  uint32_t req_counter = counter;
  ASSERT( unfinishedEventRequest.find(req_counter) == unfinishedEventRequest.end() );
  unfinishedEventRequest[req_counter] =  std::pair<mace::string*,mace::string>(msg_str, event_str);
  counter ++;
  sl.unlock();
  maceout<<"sending out event creation request. "<< extra<< ", counter = "<< req_counter << Log::endl;
  const_send__event_create( contextMapping.getHead(), extra, req_counter );
}
void ContextService::migrateContext( mace::string const& paramid ){
  send__event_migrate_param( paramid );
}
void ContextService::deleteContext( mace::string const& contextName ){
  send__event_delete_context( contextName );
}
void ContextService::__beginRemoteMethod( mace::Event const& event ) const {
  ThreadStructure::setEvent( event );
}
void ContextService::__finishRemoteMethodReturn( mace::MaceAddr const& src, mace::string const& returnValueStr ) const{
  send__event_routine_return( src, returnValueStr );
}
void ContextService::__appUpcallReturn( mace::MaceKey const& src, mace::string const& returnValueStr ) const{
  send__event_routine_return( src.getMaceAddr(), returnValueStr );
}
void ContextService::nullEventHead( void *p ){
  mace::NullEventMessage* nullEventMessage = static_cast< mace::NullEventMessage* >( p );
  __asyncExtraField extra;
  asyncHead( nullEventMessage->getEvent(), extra, mace::Event::UNDEFEVENT );
  HeadEventDispatch::HeadEventTP::commitEvent( nullEventMessage->getEvent() ); // commit

  delete nullEventMessage;
}
void ContextService::wasteTicket( void ) const{
  mace::NullEventMessage* nullEventMessage = new mace::NullEventMessage( ThreadStructure::myTicket() );
  HeadEventDispatch::HeadEventTP::executeEvent( const_cast<ContextService*>(this), (HeadEventDispatch::eventfunc)&ContextService::nullEventHead, nullEventMessage, true ); 
}
void ContextService::notifyHeadExit(){
  if( ThreadStructure::isOuterMostTransition() ){
    if( isLocal( mace::ContextMapping::getHead(contextMapping) ) ){
      mace::Event& myEvent = ThreadStructure::myEvent();
      HeadEventDispatch::HeadEventTP::commitEvent( myEvent );
      // wait to confirm the event is committed.
      // remind other physical nodes the exit event has committed.
      const mace::map< MaceAddr, uint32_t >& nodes = contextMapping.getAllNodes();
      for( mace::map< MaceAddr, uint32_t >::const_iterator nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt ++ ){
        if( isLocal( nodeIt->first ) ) continue;
        mace::InternalMessage msg( mace::exit_committed );
        sender->sendInternalMessage( nodeIt->first, msg );
      }
    }else{
      // wait for exit event to commit.
      waitExit();
    }
  }
}
void ContextService::processRPCApplicationUpcall( mace::ApplicationUpcall* msg, MaceAddr const& src){
  // make sure this is the head node.
  ASSERT( contextMapping.getHead() == Util::getMaceAddr() );
  ThreadStructure::ScopedContextID sci( mace::ContextMapping::HEAD_CONTEXT_ID );

  HeadEventDispatch::waitAfterCommit( ThreadStructure::myEvent().eventID-1 );
  // wait until this event becomes the next to commit
  //
  // set up the current event
  //ThreadStructure::setEvent( msg->getEvent() );
  //
  // execute unprocessed application upcalls (which do not have return value)
  // and clear upcalls in the event
  ThreadStructure::myEvent().executeApplicationUpcalls();
  //
  // return back ( return value and update event )
  mace::string returnValue;
  this->executeDeferredUpcall( msg, returnValue );
  mace::InternalMessage m( mace::appupcall_return, returnValue, ThreadStructure::myEvent() );
  sender->sendInternalMessage( src, m);
}
void ContextService::addTransportEventRequest( mace::AsyncEvent_Message* reqObject){
  HeadEventDispatch::HeadEventTP::executeEvent(this,(HeadEventDispatch::eventfunc)&ContextService::createEvent, reqObject, true );
}
void ContextService::forwardHeadTransportThread( mace::MaceAddr const& dest, mace::AsyncEvent_Message* const eventObject ){
    HeadEventDispatch::HeadTransportTP::sendEvent( sender, dest, eventObject, instanceUniqueID );

}
