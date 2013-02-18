#include "ContextService.h"
#include "HeadEventDispatch.h"
#include "ScopedContextRPC.h"
#include "ReadLine.h"
#include "AccessLine.h"
using mace::ReadLine;
void ContextService::acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const{
  ADD_SELECTORS("ContextService::acquireContextLocksCommon");
  
  const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
  const mace::set< uint32_t >& eventContexts =  ThreadStructure::getEventContexts( ).find( instanceUniqueID ) ->second;
  const bool hasSnapshot = ( ThreadStructure::getEventSnapshotContexts().find( instanceUniqueID ) == ThreadStructure::getEventSnapshotContexts().end() )?false:true;
  const mace::map< uint32_t , mace::string>& eventSnapshot =  ThreadStructure::getEventSnapshotContexts().find( instanceUniqueID )->second;
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
     if( eventContexts.find( nowID ) == eventContexts.end() && (hasSnapshot && eventSnapshot.find( nowID ) == eventSnapshot.end() ) &&
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
  for( mace::set< uint32_t >::iterator acIt = ancestorContextIDs.begin(); acIt != ancestorContextIDs.end(); acIt++ ){
    ThreadStructure::insertEventContext( *acIt );
  }
}
void ContextService::copyContextData(mace::ContextBaseClass* thisContext, mace::string& s ) const{
    mace::serialize(s, thisContext );
}
void ContextService::eraseContextData(mace::ContextBaseClass* thisContext){
    // chuangw: this is a no-op function now, because it doesn't really matter if the context is just left there
    // In the future (i.e. post PLDI '13 submission), this function will do:
    // (1) erase the context object
    // (2) remove the context object from ctxobjIDMap & ctxobjNameMap
    // (3) remove from the parent context
}
void ContextService::handle__event_AllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType){

    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    // Context mapping is shared process-wide. Protect context mapping structure with AgentLock

    mace::HighLevelEvent currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );

    ThreadStructure::setEventContextMappingVersion();
    if( this->contextMapping.getHead() == Util::getMaceAddr() ){
      ASSERTMSG( this->contextMapping.hasSnapshot( eventID )  , "This physical node is the head node but yet it does not have this version of snapshot!" );
    }else{
      ASSERTMSG( !this->contextMapping.hasSnapshot( eventID ) , "This physical node is not supposed to have this version of snapshot when migration event starts!" );
      this->contextMapping.snapshotInsert( eventID, contextMapping );
      this->contextMapping = contextMapping; 
    }  

    if( destNode == Util::getMaceAddr() ){ 
      for( mace::map< uint32_t, mace::string >::const_iterator ctxIt = ContextID.begin(); ctxIt != ContextID.end(); ctxIt++ ){
        mace::ContextBaseClass *thisContext = createContextObject( ctxIt->second, ctxIt->first ); // create context object
        ASSERTMSG( thisContext != NULL, "createContextObject() returned NULL!");
        ASSERTMSG( thisContext->getNowServing() == eventID, "Context already exist!" );
      }

      if( eventType == 1 ){
        send__event_AllocateContextObjectResponse( src, src, eventID );
      }
    }
    alock.downgrade( mace::AgentLock::NONE_MODE );

}
void ContextService::handle__event_AllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const& eventID ){

          //ASSERT( contextMapping.getHead() == Util::getMaceAddr() );

          // wake up the head to proceed with dynamic context migration
          ScopedLock sl( ContextObjectCreationMutex );

          pthread_cond_signal( &ContextObjectCreationCond  );

          sl.unlock();
          mace::AgentLock::nullTicket();

}
void ContextService::handle__event_ContextMigrationRequest( MaceAddr const& src, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::HighLevelEvent const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& msgnextHops ){
    ASSERT( !rootOnly || (msgnextHops.size() == 1 && msgnextHops[0] == ctxId  ) );
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    ASSERT( contextMapping.hasSnapshot( prevContextMapVersion ) ); // make sure this node has the previous version of context mapping
    alock.downgrade( mace::AgentLock::NONE_MODE );

    ThreadStructure::setEvent( event );
    mace::HighLevelEvent& migrationEvent = ThreadStructure::myEvent();
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    
    // configure to use the old mapping (before migration )
    ThreadStructure::setEventContextMappingVersion( prevContextMapVersion );
    const mace::ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot() ;

    bool isRoot = false;
    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for( mace::vector< uint32_t >::const_iterator nextHopIt = msgnextHops.begin(); nextHopIt != msgnextHops.end(); nextHopIt ++ ){
      const uint32_t thisContextID = *nextHopIt;
      if( isRoot == false && thisContextID == ctxId ){ isRoot = true;}

      mace::ContextBaseClass *thisContext = getContextObjByID( thisContextID); // assuming context object already exists and this operation does not create new object.
      mace::string contextData;
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::WRITE_MODE );
      copyContextData( thisContext, contextData );

      send__event_TransferContext( dest, thisContext->getName(), thisContext->getID(),contextData, event.getEventID(), src, false);

      // If the entire context subtree will be migrated, send message to child contexts
      if( ! rootOnly ){
        ctxlock.downgrade( mace::ContextLock::NONE_MODE );
        eraseContextData( thisContext );// erase the context from this node.
        const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( ctxmapSnapshot, thisContextID );
        for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
          //const mace::string& nextHop  = mace::ContextMapping::getNameByID( ctxmapSnapshot, *subctxIter);
          const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, *subctxIter );
          ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
          nextHops[ nextHopAddr ].push_back( *subctxIter );
        }
      }
    }

    if( rootOnly ){
      ASSERT( isRoot );
      mace::__ScopedTransition__ st(this, ctxId);
      mace::ContextBaseClass *thisContext = getContextObjByID( ctxId); //getContextObjByName( ctxId);
      eraseContextData( thisContext );// erase the context from this node.
    }else{
      mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
      for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
        send__event_ContextMigrationRequest( addrIt->first, ctxId, dest, rootOnly, event.getEventID(), prevContextMapVersion, addrIt->second  );
      }
      if( isRoot ){
        send__event_commit( contextMapping.getHead(), migrationEvent.eventID, migrationEvent.eventType, migrationEvent.eventMessageCount );
      }
    }
}
void ContextService::handle__event_TransferContext( MaceAddr const& src, mace::string const& ctxId, uint32_t const& ctxNId, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse ){
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE);
    /*if( msg.isresponse ){
      mace::ScopedContextRPC::wakeup(msg.eventId);
      return;
    }*/
    
    mace::ContextBaseClass* thisContext = getContextObjByName(ctxId);
    
    alock.downgrade( mace::AgentLock::NONE_MODE );

    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    ThreadStructure::myEvent().eventID = eventId;
    ThreadStructure::myEvent().setSkipID( instanceUniqueID , ctxNId, eventId );
    ASSERT( thisContext->getNowServing() == eventId );
    // create object using name string
    mace::deserialize( checkpoint, thisContext );

    // local commit.
    // notice that the same event has also already downgraded the original context object copy.
    mace::ContextLock c_lock( *thisContext, mace::ContextLock::WRITE_MODE );
    c_lock.downgrade( mace::ContextLock::NONE_MODE );
    
    /*mace::string dummyContextData;
    __event_TransferContext m(msg.ctxId, dummyContextData , msg.eventId, msg.parentContextNode,  true);
    ASYNCDISPATCH( src , __ctx_dispatcher , __event_TransferContext , m )*/

}
void ContextService::handle__event_commit( uint64_t const& eventID, int8_t const& eventType, uint32_t const& eventMessageCount ){
    /* the commit msg is sent to head, head send to global context and goes down the entire context tree to downgrade the line.
    after that, the head performs commit which effectively releases deferred messages and application upcalls */
    mace::AgentLock::nullTicket();
    HeadEventDispatch::HeadEventTP::commitEvent( eventID, eventType, eventMessageCount );
}

void ContextService::handle__event_commit_context( mace::vector< uint32_t > const& msgnextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ){
    mace::AgentLock::nullTicket();

    mace::HighLevelEvent currentEvent( eventID );
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
      send__event_commit_context( addrIt->first, addrIt->second, eventID,ThreadStructure::myEvent().eventType, eventContextMappingVersion, eventSkipID, false, hasException, exceptionContextID );
      /*__event_commit_context commitMsg( addrIt->second, eventID,ThreadStructure::myEvent().eventType, eventContextMappingVersion, eventSkipID, false, hasException, exceptionContextID );
      ASYNCDISPATCH( addrIt->first , __ctx_dispatcher, __event_commit_context , commitMsg );*/
    }
}

void ContextService::handle__event_create_response( mace::HighLevelEvent const& event, uint32_t const& counter, MaceAddr const& targetAddress){
  ADD_SELECTORS("ContextService::handle__event_create_response");
  mace::AgentLock::nullTicket();
  // read from buffer
  
  ScopedLock sl( eventRequestBufferMutex );
  maceout<<"Event "<< event.eventID << ", counter = "<< counter <<" is sent to "<< targetAddress <<Log::endl;
  mace::hash_map< uint32_t, mace::pair<mace::string, mace::string > >::iterator ueIt = unfinishedEventRequest.find( counter );
  ASSERT( ueIt != unfinishedEventRequest.end() );
  mace::pair< mace::string, mace::string >& eventreq = ueIt->second;
  eventreq.first.erase(  eventreq.first.size() - eventreq.second.size() );
  __asyncExtraField extra;
  mace::deserialize( eventreq.second, &extra);
  extra.event = event;
  extra.isRequest = false;
  mace::string extra_str;
  mace::serialize( extra_str , &extra );
  eventreq.first.append( extra_str );

  const mace::MaceKey destNode( mace::ctxnode, targetAddress  );
  routeEventRequest( destNode, eventreq );
  unfinishedEventRequest.erase( ueIt );
  sl.unlock();

}

void ContextService::handle__event_enter_context( mace::HighLevelEvent const& event, mace::vector< uint32_t > const& contextIDs ){
  mace::AgentLock::nullTicket();
  ThreadStructure::setEvent( event );
  for( mace::vector< uint32_t >::const_iterator ctxidIt = contextIDs.begin(); ctxidIt != contextIDs.end(); ctxidIt++ ){
    mace::ContextBaseClass * thisContext = getContextObjByID( *ctxidIt );
    mace::ContextLock __contextLock( *thisContext, mace::ContextLock::WRITE_MODE); // acquire context lock. 
  }

}
void ContextService::handle__event_exit_committed( ){
  // this message is supposed to be received by non-head nodes.
  mace::AgentLock::nullTicket();
  // if the main thread is blocking in maceExit(), wake it up
  mace::HighLevelEvent::proceedExit();
  // if maceExit() has not been called at this node....?
}
void ContextService::handle__event_create_head( __asyncExtraField const& extra, uint64_t const& counter, MaceAddr const& src){
  if( mace::HighLevelEvent::isExit ) {
    mace::AgentLock::nullTicket();
    return;
  }
  asyncHead( extra, mace::HighLevelEvent::ASYNCEVENT );


  const MaceAddr& targetContextAddr = contextMapping.getNodeByContext( extra.targetContextID );
  send__event_create_response( src, ThreadStructure::myEvent(), counter, targetContextAddr );
}
void ContextService::handle__event_snapshot( mace::HighLevelEvent const& event, mace::string const& ctxID, mace::string const& snapshotContextID, mace::string const& snapshot){

    // store the snapshoeventt
    mace::AgentLock::nullTicket();
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
  mace::AgentLock::nullTicket();
  if( isresponse ){
    mace::ScopedContextRPC::wakeup( eventID );
  }else{
    mace::HighLevelEvent currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );
// XXX: make sure I'm not holding any lock
    mace::ContextBaseClass *thisContext = getContextObjByID( contextID);
    mace::ContextLock cl( *thisContext, mace::ContextLock::READ_MODE );
    //__event_downgrade_context dgmsg( "", eventID, true );
  }
}
void ContextService::handle__event_routine_return( mace::string const& returnValue, mace::HighLevelEvent const& event){
  mace::AgentLock::nullTicket();

  ThreadStructure::setEventContextMappingVersion ( event.eventContextMappingVersion );
  mace::ScopedContextRPC::wakeupWithValue( event.eventID, returnValue );
}
/*void ContextService::handle__event_evict( MaceAddr const& src ){

}*/
void ContextService::asyncHead( mace::__asyncExtraField const& extra, int8_t const eventType){
  mace::HighLevelEvent& newEvent = ThreadStructure::myEvent( );

  mace::AgentLock lock( mace::AgentLock::WRITE_MODE ); // global lock is used to ensure new events are created in order
  newEvent.newEventID( eventType );
  lock.downgrade( mace::AgentLock::NONE_MODE );

  { // Release global AgentLock. Acquire head context lock to allow paralellism
    mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

    newEvent.initialize(  );

    bool contextExist = contextMapping.hasContext( extra.targetContextID );
    if( contextExist ){
      contextEventRecord.updateContext( extra.targetContextID, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );
    }else{// create a new context
      mace::HighLevelEvent::setLastContextMappingVersion( newEvent.eventID );
      newEvent.eventContextMappingVersion = newEvent.eventID;
      std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( extra.targetContextID );
      // make a copy because contextMapping is shared among threads and it will be sent out by __event_AllocateContextObject message
      const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
      ASSERT( ctxmapCopy != NULL );
      contextEventRecord.createContextEntry( extra.targetContextID, newMappingReturn.second, newEvent.eventID );
      newEvent.setSkipID( instanceUniqueID, newMappingReturn.second, newEvent.eventID );

      // notify other services about the new context
      BaseMaceService::globalNotifyNewContext( instanceUniqueID );

      mace::map< uint32_t, mace::string > contextSet; // empty set

        if( newMappingReturn.first == Util::getMaceAddr() ){
          createContextObject( extra.targetContextID  , newMappingReturn.second  ); // global context is the first context, so id=1
        }


      send__event_AllocateContextObjectMsg( ctxmapCopy, SockUtil::NULL_MACEADDR, contextSet, 0 );

    }

    // notify other services about this event
    BaseMaceService::globalNotifyNewEvent( instanceUniqueID );
                    
    /*mace::string buf;
    mace::serialize(buf,&msg);
    mace::HierarchicalContextLock hl( newEvent, buf );
    storeHeadLog(hl, newEvent );*/
    c_lock.downgrade( mace::ContextLock::NONE_MODE );
  }

}
//void ContextService::__beginTransition(__asyncExtraField const& extra ) const{
void ContextService::__beginTransition( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs  ) const {
  ThreadStructure::pushServiceInstance( instanceUniqueID ); 
  __beginMethod( targetContextID, snapshotContextIDs );
}
//void ContextService::__beginMethod(__asyncExtraField const& extra ) const{
void ContextService::__beginMethod( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs ) const {
    ADD_SELECTORS("ContextService::__beginMethod");
  ThreadStructure::pushContext( targetContextID );
  ThreadStructure::insertEventContext( targetContextID );
  mace::ContextBaseClass * thisContext = getContextObjByID( targetContextID ); //getContextObjByName( extra.targetContextID );
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
  if( ThreadStructure::isOuterMostTransition() ){
    // inform the head to commit before downgrade contexts
    mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
    // if call in a start or end event, it doesn't mean the event is finished
    // inform head node this event is ready to do global commit
    //if( currentEvent.eventType != mace::HighLevelEvent::STARTEVENT && currentEvent.eventType != mace::HighLevelEvent::ENDEVENT ){
      const_send__event_commit( contextMapping.getHead(), currentEvent.eventID, currentEvent.eventType, currentEvent.eventMessageCount );
    //}

    // remove redundant information
    // the head just need event ID and event message count
    /*for( mace::HighLevelEvent::EventContextType::iterator evCtxIt = currentEvent.eventContexts.begin(); evCtxIt != currentEvent.eventContexts.end(); evCtxIt++){
      evCtxIt->second.clear();
    }
    for( mace::HighLevelEvent::SkipRecordType::iterator evSkipIt = currentEvent.eventSkipID.begin(); evSkipIt != currentEvent.eventSkipID.end(); evSkipIt++){
      evSkipIt->second.clear();
    }*/
  }
  const mace::set< uint32_t >& contexts = ThreadStructure::getCurrentServiceEventContexts();
  if( contexts.find( ThreadStructure::getCurrentContext() ) != contexts.end() ){
    downgradeCurrentContext();
  }
  globalDowngradeEventContext(); // downgrade all remaining contexts that the event has
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
      if( !ThreadStructure::isEventEnteredService() && targetContextID != globalContextName ){
          // Since it is the first transition of this service,
          // it has to downgrade higher-level contexts before entering the call.
          // this is similar to async calls
          mace::HighLevelEvent& he = ThreadStructure::myEvent();
          uint32_t targetContextNID = snapshotMapping.findIDByName( targetContextID );
          const_send__event_commit_context( mace::ContextMapping::getNodeByContext( snapshotMapping, globalContextID ), nextHops, he.eventID, he.eventType, he.eventContextMappingVersion, he.eventSkipID, false, true, targetContextNID );
          /*__event_commit_context commit_msg( nextHops, he.eventID, he.eventType, he.eventContextMappingVersion, he.eventSkipID, false, true, targetContextNID );
          CONST_ASYNCDISPATCH( mace::ContextMapping::getNodeByContext( snapshotMapping, globalContextID ), __ctx_dispatcher , __event_commit_context , commit_msg )*/
      }
}
void ContextService::notifyNewEvent( const uint8_t serviceID ) {
    ADD_SELECTORS("ContextService::notifyNewEvent");

    if( serviceID == instanceUniqueID ) { return; }
    // no need to lock -- this is called when ContextLock is in WRITE_MODE
    //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewEvent" );
    ASSERTMSG( mace::ContextBaseClass::headContext.getCurrentMode() == mace::ContextLock::WRITE_MODE, "notifyNewEvent() must be called only when head node is in ContextLock::WRITE_MODE" );

    mace::HighLevelEvent& he = ThreadStructure::myEvent();

    if( he.getEventType() == mace::HighLevelEvent::MIGRATIONEVENT ){
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
void ContextService::notifyNewContext( const uint8_t serviceID ) {
    ADD_SELECTORS("ContextService::notifyNewContext");
    // no need to lock -- this is called when ContextLock is in WRITE_MODE
    //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewContext" );
    ASSERTMSG( mace::ContextBaseClass::headContext.getCurrentMode() == mace::ContextLock::WRITE_MODE, "notifyNewContext() must be called only when head node is in ContextLock::WRITE_MODE" );

    mace::HighLevelEvent& he = ThreadStructure::myEvent();

    if( serviceID == instanceUniqueID ) { return; }
    if( he.eventType == mace::HighLevelEvent::STARTEVENT ){
      const mace::string globalContextID = "";
      // if it's a start event, the head has to create a mapping to global context
      // to prevent race condition, the global context of every service in the composition has to be created explicitly in the first event (that is, maceInit)

      std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( globalContextID );
      const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
      ASSERT( ctxmapCopy != NULL );
      contextEventRecord.createContextEntry( globalContextID, newMappingReturn.second, he.eventID );
      he.setSkipID( instanceUniqueID, newMappingReturn.second, he.eventID );

      if( newMappingReturn.first == Util::getMaceAddr() ){ // the new context co-locates with the head
        mace::ContextBaseClass *globalContext = createContextObject( globalContextID, newMappingReturn.second );
        ASSERT( globalContext != NULL );
      }else{
        remoteAllocateGlobalContext( globalContextID, newMappingReturn, ctxmapCopy );
      }
      return;
    }

    ASSERTMSG( !contextMapping.hasSnapshot( ), "The new context is not created in this service, why does it have this version of context mapping?" );
    const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
    ASSERT( ctxmapCopy != NULL );

    mace::map< uint32_t, mace::string > contextSet; // empty set
    send__event_AllocateContextObjectMsg( ctxmapCopy, SockUtil::NULL_MACEADDR, contextSet, 0 );
}
void ContextService::downgradeEventContext( ){
  ADD_SELECTORS("ContextService::downgradeEventContext");

  mace::HighLevelEvent& myEvent = ThreadStructure::myEvent();
  const uint64_t myTicket = myEvent.getEventID();
  uint8_t commitInitiatorServiceID = 0;
  if( myEvent.eventType == mace::HighLevelEvent::ENDEVENT ){
    commitInitiatorServiceID = ThreadStructure::getServiceInstance();
  }
  ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
  ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContextID() );
  // (1) move the block/write/read lines down to the bottom of the context hierarchy.
  // send the commit message to the read-line cut 

  switch( myEvent.eventType ){
    case mace::HighLevelEvent::NEWCONTEXTEVENT:
      return;
      break;
    case mace::HighLevelEvent::ENDEVENT:
      if( commitInitiatorServiceID != instanceUniqueID ){
        return;
      }
      break;
    case mace::HighLevelEvent::STARTEVENT:
      return;
      break;
  }
  // if new-context-event, all contexts will be entered, no need to commit contexts again
  bool enteredService = ThreadStructure::isEventEnteredService();
  const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
  mace::ReadLine rl( snapshotMapping ); 
  if( !enteredService && rl.getCut().empty() ){ // this means the event did not enter this service.
    
    mace::vector< uint32_t > nextHops;
    uint32_t globalContextID = snapshotMapping.findIDByName("");
    nextHops.push_back( globalContextID );
    send__event_commit_context( mace::ContextMapping::getNodeByContext(  snapshotMapping, globalContextID ),nextHops, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
    /*__event_commit_context commit_msg( nextHops, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
    ASYNCDISPATCH( mace::ContextMapping::getNodeByContext(  snapshotMapping, globalContextID ), __ctx_dispatcher , __event_commit_context , commit_msg )*/
  }else{

    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for( mace::list< uint32_t >::const_iterator cutIt = rl.getCut().begin(); cutIt != rl.getCut().end(); cutIt ++ ){
      const uint32_t childContextID = *cutIt;
      const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, childContextID );
      nextHops[ nextHopAddr ].push_back( childContextID );
    }
    mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
    for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
      send__event_commit_context( addrIt->first, addrIt->second, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );

      /*__event_commit_context commit_msg( addrIt->second, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
      ASYNCDISPATCH( addrIt->first, __ctx_dispatcher , __event_commit_context , commit_msg )*/
    }
  }

}
void ContextService::requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextName, const MaceAddr& destNode, const bool rootOnly){
  ADD_SELECTORS("ContextService::requestContextMigrationCommon");
  //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Context migration is requested, but this physical node is not head node." );
  // 1. create ticket to acquire AgentLock
  ThreadStructure::newTicket(); 

  mace::HighLevelEvent& newEvent = ThreadStructure::myEvent( );
  // 2. acquire AgentLock, and then get the event ID. Remember to release AgentLock right after.
  mace::AgentLock alock( mace::AgentLock::WRITE_MODE ); // this lock is used to make sure the event is created in order.
  newEvent.newEventID( mace::HighLevelEvent::MIGRATIONEVENT );
  alock.downgrade( mace::AgentLock::NONE_MODE );

  // 3. acquire the head context lock. Then initializes the migration event
  mace::ContextLock clock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

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
    clock.downgrade( mace::ContextLock::NONE_MODE );
    HeadEventDispatch::HeadEventTP::commitEvent( newEvent.eventID, newEvent.eventType, newEvent.eventMessageCount ); // commit
    return;
  }
  const MaceAddr& origNode = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, contextName );
  // 5. Ok. Let's roll.
  //    Create a new version of context map. Update the event skip id
  mace::HighLevelEvent::setLastContextMappingVersion( newEvent.eventID );
  const uint64_t prevContextMappingVersion = newEvent.eventContextMappingVersion;
  newEvent.eventContextMappingVersion = newEvent.eventID; // switch to the new context mapping version

  contextEventRecord.updateContext( contextName, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );

  // If rootOnly is true, migrate just one context
  // Otherwise, migrate the entire subtree. All contexts in the subtree will be migrated to the same node.
  mace::map< uint32_t, mace::string > offsprings;
  if( rootOnly ){
    std::pair<bool, uint32_t>  updatedContext = contextMapping.updateMapping( destNode, contextName ); 
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
   

  // notify other services about the new context
  BaseMaceService::globalNotifyNewContext( instanceUniqueID );
  BaseMaceService::globalNotifyNewEvent( instanceUniqueID );

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
  ScopedLock sl( ContextObjectCreationMutex );

  send__event_AllocateContextObjectMsg( ctxmapCopy, SockUtil::NULL_MACEADDR, offsprings, 1 ); 

  /*const mace::map < MaceAddr, uint32_t >& physicalNodes = contextMapping.getAllNodes(); 
  macedbg(1)<< "The logical node is composed of: "<< physicalNodes << Log::endl;
  __event_AllocateContextObject allocateCtxMsg( destNode, offsprings, ThreadStructure::myEvent().eventID, *ctxmapCopy , 1);
  // chuangw: temporary solution. make sure absolutely that the context object is created 
  for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){ // chuangw: this message has to be sent to all nodes of the same logical node to update the context mapping.
    ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, __event_AllocateContextObject, allocateCtxMsg )
  }*/
  
  pthread_cond_wait( &ContextObjectCreationCond, &ContextObjectCreationMutex );

  sl.unlock();

  const uint32_t contextID = ctxmapSnapshot.findIDByName( contextName );

  mace::vector< uint32_t > nextHops;
  nextHops.push_back( contextID );
  send__event_ContextMigrationRequest( origNode, contextID, destNode, rootOnly, ThreadStructure::myEvent(), prevContextMappingVersion, nextHops  );

  clock.downgrade( mace::ContextLock::NONE_MODE );

}
void ContextService::sendAsyncSnapshot( __asyncExtraField const& extra, mace::string const& thisContextID, mace::ContextBaseClass* const& thisContext ){
  ThreadStructure::myEvent().eventID = extra.event.eventID;
  mace::set<mace::string>::iterator snapshotIt = extra.snapshotContextIDs.find( thisContextID );
  if( snapshotIt != extra.snapshotContextIDs.end() ){
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::READ_MODE );// get read lock
      mace::string snapshot;// get snapshot
      mace::serialize(snapshot, thisContext );
      // send to the target context node.
      send__event_snapshot( contextMapping.getNodeByContext( extra.targetContextID ), extra.event,extra.targetContextID, *snapshotIt, snapshot );

      ctxlock.downgrade( mace::ContextLock::NONE_MODE );
  }else{
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::NONE_MODE );// get read lock
  }
}
// helper functions for maintaining context mapping
void ContextService::loadContextMapping(const mace::map<mace::MaceAddr ,mace::list<mace::string > >& servContext){
    mace::AgentLock lock( mace::AgentLock::WRITE_MODE );
    contextMapping.setDefaultAddress ( Util::getMaceAddr() );
    contextMapping.loadMapping( servContext );
    contextMapping.snapshot( static_cast<uint64_t>( 0 ) );
}
void ContextService::downgradeContext( mace::string const& contextName ) {
  // TODO: 
  //(1) assert: the event has acquired the context before.
  const mace::ContextMapping& currentMapping = contextMapping.getSnapshot();
  const mace::set< uint32_t >& eventContexts = ThreadStructure::getCurrentServiceEventContexts();
  const uint32_t contextID = currentMapping.findIDByName( contextName );
  ASSERTMSG( eventContexts.find( contextID ) != eventContexts.end(), "The event does not have the context" );   
  mace::AccessLine::checkDowngradeContext( instanceUniqueID, contextID, currentMapping );
  //(2) figure out the physical address of the context
  //(3) if it's local, call it. If not, send message and wait for response
  send__event_downgrade_context( mace::ContextMapping::getNodeByContext( currentMapping, contextID ), ThreadStructure::getCurrentContext(), ThreadStructure::myEvent().eventID, false );

  ThreadStructure::removeEventContext( ThreadStructure::getCurrentContext() );
}
