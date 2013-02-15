#include "ContextService.h"
void ContextService::acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const{
  ADD_SELECTORS("ContextService::acquireContextLocksCommon");
  
  const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
  const mace::set<mace::string>& eventContexts = ThreadStructure::getCurrentServiceEventContexts();
  const mace::map<mace::string, mace::string>& eventSnapshot = ThreadStructure::getCurrentServiceEventSnapshotContexts();
  mace::set< uint32_t > ancestorContextIDs;
  if( targetContextID == 1 ){ // the target is global context. no ancestor
  }else{
    uint32_t nowID = targetContextID;
    do{
     uint32_t parentID = snapshotMapping.getParentContextID( nowID );
     const mace::string& parentName = mace::ContextMapping::getNameByID( snapshotMapping, parentID );
     if( eventContexts.find( parentName ) == eventContexts.end() && eventSnapshot.find( parentName ) == eventSnapshot.end() ){
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
     const mace::string& contextName = mace::ContextMapping::getNameByID( snapshotMapping, nowID );
     if( eventContexts.find( contextName ) == eventContexts.end() && eventSnapshot.find( contextName ) == eventSnapshot.end() &&
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
    const mace::string& contextName = mace::ContextMapping::getNameByID( snapshotMapping, *acIt );
    ThreadStructure::insertEventContext( contextName );
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
void ContextService::handleAllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType){

    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    // Context mapping is shared process-wide. Protect context mapping structure with AgentLock

    mace::HighLevelEvent currentEvent( eventID );
    ThreadStructure::setEvent( currentEvent );

    ThreadStructure::setEventContextMappingVersion();
    if( contextMapping.getHead() == Util::getMaceAddr() ){
      ASSERTMSG( contextMapping.hasSnapshot( eventID )  , "This physical node is the head node but yet it does not have this version of snapshot!" );
    }else{
      ASSERTMSG( !contextMapping.hasSnapshot( eventID ) , "This physical node is not supposed to have this version of snapshot when migration event starts!" );
      contextMapping.snapshotInsert( eventID, contextMapping );
      contextMapping = contextMapping; 
    }  

    if( destNode == Util::getMaceAddr() ){ 
      for( mace::map< uint32_t, mace::string >::const_iterator ctxIt = ContextID.begin(); ctxIt != ContextID.end(); ctxIt++ ){
        mace::ContextBaseClass *thisContext = createContextObject( ctxIt->second, ctxIt->first ); // create context object
        ASSERTMSG( thisContext != NULL, "createContextObject() returned NULL!");
        ASSERTMSG( thisContext->getNowServing() == eventID, "Context already exist!" );
      }

      if( eventType == 1 ){
        sendAllocateContextObjectResponse( src, src, eventID );
      }
    }
    alock.downgrade( mace::AgentLock::NONE_MODE );

}
void ContextService::handleAllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const& eventID ){

          //ASSERT( contextMapping.getHead() == Util::getMaceAddr() );

          // wake up the head to proceed with dynamic context migration
          ScopedLock sl( ContextObjectCreationMutex );

          pthread_cond_signal( &ContextObjectCreationCond  );

          sl.unlock();
          mace::AgentLock::nullTicket();

}
void ContextService::handleContextMigrationRequest( MaceAddr const& src, mace::string const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::HighLevelEvent const& event, uint64_t const& prevContextMapVersion, mace::vector< mace::string > const& nextHops ){

            // TODO: update context mapping.
    ASSERT( !rootOnly || (nextHops.size() == 1 && nextHops[0].compare( ctxId ) == 0 ) );
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    ASSERT( contextMapping.hasSnapshot( prevContextMapVersion ) ); // make sure this node has the previous version of context mapping
    alock.downgrade( mace::AgentLock::NONE_MODE );

    ThreadStructure::setEvent( event );
    mace::HighLevelEvent& migrationEvent = ThreadStructure::myEvent();
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    
    // set event context mapping version to use the old mapping (before migration )
    ThreadStructure::setEventContextMappingVersion( prevContextMapVersion );
    const mace::ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot() ;

    mace::vector< mace::string >::const_iterator nextHopIt;
    bool isRoot = false;
    mace::map< mace::MaceAddr , mace::vector< mace::string > > nextHops;
    for( nextHopIt = nextHops.begin(); nextHopIt != nextHops.end(); nextHopIt ++ ){
      const mace::string& thisContextID = *nextHopIt;
      if( isRoot == false && thisContextID == ctxId ){ isRoot = true;}

      mace::ContextBaseClass *thisContext = getContextObjByName( thisContextID); // assuming context object already exists and this operation does not create new object.
      mace::string contextData;
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::WRITE_MODE );
      copyContextData( thisContext, contextData );
      TransferContext m( thisContextID, thisContext->getID(),contextData, event.getEventID(), src, false);
      const mace::MaceKey destNode( mace::ipv4, dest  );
      downcall_route( destNode , m  );

      // If the entire context subtree will be migrated, send message to child contexts
      if( ! rootOnly ){
        ctxlock.downgrade( mace::ContextLock::NONE_MODE );
        eraseContextData( thisContext );// erase the context from this node.
        const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( ctxmapSnapshot, thisContextID );
        for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
          const mace::string& nextHop  = mace::ContextMapping::getNameByID( ctxmapSnapshot, *subctxIter);
          const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, *subctxIter );
          ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
          nextHops[ nextHopAddr ].push_back( nextHop );
        }
      }
    }

    if( rootOnly ){
      ASSERT( isRoot );
      ThreadStructure::ScopedContextID sc( ctxId );
      eventFinish();
      mace::ContextBaseClass *thisContext = getContextObjByName( ctxId);
      eraseContextData( thisContext );// erase the context from this node.
    }else{
      mace::map< mace::MaceAddr , mace::vector< mace::string > >::iterator addrIt;
      for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
          /*ContextMigrationRequest nextctxId, dest, rootOnly, event.getEventID(), prevContextMapVersion, addrIt->second );
          ASYNCDISPATCH( addrIt->first , __ctx_dispatcher, ContextMigrationRequest , next);*/

          sendContextMigrationRequest( addrIt->first, ctxId, dest, rootOnly, event.getEventID(), prevContextMapVersion, addrIt->second  );
      }
      if( isRoot ){
        __event_commit commitRequest( migrationEvent.eventID, migrationEvent.eventType, migrationEvent.eventMessageCount  );
        ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher , __event_commit , commitRequest )
      }
    }


}
void ContextService::handleTransferContext( MaceAddr const& src, mace::string const& ctxId, uint32_t const& ctxNId, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse ){
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
    TransferContext m(msg.ctxId, dummyContextData , msg.eventId, msg.parentContextNode,  true);
    ASYNCDISPATCH( src , __ctx_dispatcher , TransferContext , m )*/

}
void ContextService::handle__event_commit( uint64_t const& eventID, int8_t const& eventType, uint32_t const& eventMessageCount ){
    /* the commit msg is sent to head, head send to global context and goes down the entire context tree to downgrade the line.
    after that, the head performs commit which effectively releases deferred messages and application upcalls */
    mace::AgentLock::nullTicket();
    HeadEventDispatch::HeadEventTP::commitEvent( msg.eventID, msg.eventType, msg.eventMessageCount );
}

void ContextService::handle__event_commit_context( mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ){
    mace::AgentLock::nullTicket();

    mace::HighLevelEvent currentEvent( msg.eventID );
    ThreadStructure::setEvent( currentEvent );
    if( msg.isresponse ){
        pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
        pthread_cond_signal( mace::ContextBaseClass::eventCommitConds[msg.eventID] );
        pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );
        return;
    }
    ThreadStructure::setEventContextMappingVersion ( msg.eventContextMappingVersion );
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    ThreadStructure::myEvent().eventSkipID = msg.eventSkipID;
    const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
    mace::vector< uint32_t >::const_iterator nextHopIt;
    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for(  nextHopIt = msg.nextHops.begin(); nextHopIt != msg.nextHops.end(); nextHopIt++ ){
      const uint32_t thisContextID = *nextHopIt;

      if( msg.hasException && msg.exceptionContextID == thisContextID ){ continue; }

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
      send__event_commit_context( addrIt->first, addrIt->second, msg.eventID,ThreadStructure::myEvent().eventType, msg.eventContextMappingVersion, msg.eventSkipID, false, msg.hasException, msg.exceptionContextID );
      /*__event_commit_context commitMsg( addrIt->second, msg.eventID,ThreadStructure::myEvent().eventType, msg.eventContextMappingVersion, msg.eventSkipID, false, msg.hasException, msg.exceptionContextID );
      ASYNCDISPATCH( addrIt->first , __ctx_dispatcher, __event_commit_context , commitMsg );*/
    }
}
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
    // make a copy because contextMapping is shared among threads and it will be sent out by AllocateContextObject message
    const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
    ASSERT( ctxmapCopy != NULL );
    contextEventRecord.createContextEntry( extra.targetContextID, newMappingReturn.second, newEvent.eventID );
    newEvent.setSkipID( instanceUniqueID, newMappingReturn.second, newEvent.eventID );

    // notify other services about the new context
    BaseMaceService::globalNotifyNewContext( instanceUniqueID );

    sendAllocateContextObjectMsg( ctxmapCopy );

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
void ContextService::eventPrep(__asyncExtraField const& extra ){

  // FIXME: chuangw: i don't have to to make snapshot taking work. will come back later.
  ThreadStructure::setEvent( extra.event );
  ThreadStructure::pushContext( extra.targetContextID );
  ThreadStructure::insertEventContext( extra.targetContextID );
  mace::ContextBaseClass * thisContext = getContextObjByName( extra.targetContextID );
  ThreadStructure::setMyContext( thisContext );
  if( !extra.snapshotContextIDs.empty()  ){
    size_t nsnapshots = extra.snapshotContextIDs.size();
    uint64_t ticket = ThreadStructure::myTicket();
    // wait for snapshots
    pthread_mutex_lock( &mace::ContextBaseClass::eventSnapshotMutex  );
    std::pair< uint64_t, mace::string > key( ticket, extra.targetContextID );
    while( mace::ContextBaseClass::eventSnapshotStorage[ key ].size() < nsnapshots /* waiting for some snapshots to arrive */ ){
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
  mace::ContextLock __contextLock( *thisContext , mace::ContextLock::WRITE_MODE); // acquire context lock. 
}
void ContextService::eventFinish(){
  // inform the head to commit before downgrade contexts
  mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
  // if call in a start or end event, it doesn't mean the event is finished
  if( currentEvent.eventType != mace::HighLevelEvent::STARTEVENT &&
    currentEvent.eventType != mace::HighLevelEvent::ENDEVENT ){
    __event_commit commitRequest( currentEvent.eventID, currentEvent.eventType, currentEvent.eventMessageCount  );
    ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher , __event_commit , commitRequest )
  }

  // inform head node this event is ready to do global commit
  const mace::set< mace::string >& contexts = ThreadStructure::getCurrentServiceEventContexts();
  if( contexts.find( ThreadStructure::getCurrentContext() ) != contexts.end() ){
    downgradeCurrentContext();
  }
  globalDowngradeEventContext(); // downgrade all remaining contexts that the event has
  // remove redundant information
  // the head just need event ID and event message count
  /*for( mace::HighLevelEvent::EventContextType::iterator evCtxIt = currentEvent.eventContexts.begin(); evCtxIt != currentEvent.eventContexts.end(); evCtxIt++){
    evCtxIt->second.clear();
  }
  for( mace::HighLevelEvent::SkipRecordType::iterator evSkipIt = currentEvent.eventSkipID.begin(); evSkipIt != currentEvent.eventSkipID.end(); evSkipIt++){
    evSkipIt->second.clear();
  }*/

  ThreadStructure::popContext( );
        
}
void ContextService::enterInnerService (mace::string const& targetContextID ){
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
          __event_commit_context commit_msg( nextHops, he.eventID, he.eventType, he.eventContextMappingVersion, he.eventSkipID, false, true, targetContextNID );
          CONST_ASYNCDISPATCH( mace::ContextMapping::getNodeByContext( snapshotMapping, globalContextID ), __ctx_dispatcher , __event_commit_context , commit_msg )
      }
}
