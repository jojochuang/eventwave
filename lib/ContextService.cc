#include "ContextService.h"
void ContextService::acquireContextLocksCommon(mace::ContextMapping& contextMapping, uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const{
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
