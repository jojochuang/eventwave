#include "ContextMapping.h"
#include "Event.h"
#include "ThreadStructure.h"
namespace mace{
class AccessLine{
/**
 * This function checks if the current event is allowed to enter the context
 * 
 * \param contextID Context ID requested to enter
 * \param currentMapping the current context mapping relation
 * */
public:
  AccessLine( const uint8_t serviceID, const uint32_t targetContextID, const ContextMapping& currentMapping ) {
    if( !granted( serviceID, targetContextID, currentMapping ) ){
      failStop(targetContextID);
    }
  }

  static bool granted( const uint8_t serviceID, const uint32_t targetContextID, const ContextMapping& currentMapping ){
    ADD_SELECTORS("AccessLine::(constructor)");
    Event::EventSnapshotContextType const& snapshots = ThreadStructure::getEventSnapshotContexts();
    Event::EventSnapshotContextType::const_iterator sctxsIt;
    if( !snapshots.empty() && (sctxsIt = snapshots.find( serviceID ) ) != snapshots.end() ){
      const Event::EventServiceSnapshotContextType& snapshotContexts = sctxsIt->second;
      if( !snapshotContexts.empty() ){

        // if the target context has already been released. error
        for( Event::EventServiceSnapshotContextType::const_iterator sctxIt = snapshotContexts.begin(); sctxIt != snapshotContexts.end(); sctxIt++ ){
          uint32_t ctxID = sctxIt->first;
          if( ctxID == targetContextID ){
            return false;
          }
          // if the target context is the ancestor of any snapshot context, error
          uint32_t traverseID = ctxID;
          while( traverseID != 1 ){ // if not global context
            uint32_t parent = currentMapping.getParentContextID( traverseID );
            if( parent == targetContextID ){
              return false;
            }
            traverseID = parent;

          }
        }
      }
    }
    // if the target context is the child/offspring context of any of the context that the event currently owns, return true
    Event::EventContextType const& allContexts = ThreadStructure::getEventContexts();
    Event::EventContextType::const_iterator ctxsIt;
    if( !allContexts.empty() && (ctxsIt = allContexts.find( serviceID ) ) != allContexts.end() ){
      const Event::EventServiceContextType& contexts = ctxsIt->second;
      if( !contexts.empty() ){

        // if the target is currently being owned, return true
        if( contexts.find( targetContextID ) != contexts.end() ){
          return true;
        }
        // if any currently owned context is the ancestor of the target context, return true
        uint32_t ancestorID = targetContextID;
        while( ancestorID != 1 ){
          uint32_t parentID = currentMapping.getParentContextID( ancestorID );
          if( contexts.find( parentID ) != contexts.end() ){
            return true;
          }
          ancestorID = parentID;
        }
        return false;
      }
    }

    // if this event did not ever enter any contexts, it can enter any contexts.
    return true;
    
  }

  static bool checkDowngradeContext( const uint8_t serviceID, const uint32_t targetContextID, const ContextMapping& currentMapping ){
    ADD_SELECTORS("AccessLine::checkDowngradeContext");

    // goal: make sure the event does not hold any parent context locks.
    //
    //
    uint32_t parent = currentMapping.getParentContextID( targetContextID );
    //mace::string parentContextName = ContextMapping::getNameByID( currentMapping, parent);

    if( ThreadStructure::getCurrentServiceEventContexts().find( parent ) != ThreadStructure::getEventContexts( ).find( serviceID )->second.end() ){

    }

    return true;
  }
private:
  void failStop(const uint32_t targetContextID){
    ADD_SELECTORS("AccessLine::failStop");
    // Entering a context c is allowed if the event already holds the lock of context c, or if c is the child context of one of the contexts this event currently holds.
    // In other words, the write line is above c.
    maceerr<<"invalid context transition. Requested context ID = "<<targetContextID;

    ABORT( "STOP" );
  }
private:
  //const uint8_t serviceID;
};

}
