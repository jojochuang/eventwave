#include <ContextMapping.h>
#include <HighLevelEvent.h>
#include <ThreadStructure.h>
namespace mace{
class AccessLine{
/**
 * This function checks if the current event is allowed to enter the context
 * 
 * \param contextID Context ID requested to enter
 * \param currentMapping the current context mapping relation
 * */
public:
  AccessLine( const uint32_t targetContextID, const ContextMapping& currentMapping ){
    ADD_SELECTORS("AccessLine::(constructor)");
    
    typedef const mace::map< mace::string, mace::string> SnapshotContextType;
    SnapshotContextType& snapshotContexts = ThreadStructure::getCurrentServiceEventSnapshotContexts();

    for( SnapshotContextType::const_iterator sctxIt = snapshotContexts.begin(); sctxIt != snapshotContexts.end(); sctxIt++ ){
      uint32_t ctxID = currentMapping.findIDByName( sctxIt->first );
      if( ctxID == targetContextID ){
        failStop(targetContextID);
      }
      uint32_t traverseID = ctxID;
      while( traverseID != 1 ){ // if not global context
        uint32_t parent = currentMapping.getParentContextID( traverseID );
        if( parent == targetContextID ){
          failStop(targetContextID);
        }
        traverseID = parent;

      }
    }

  }

  static bool checkDowngradeContext( const mace::string& targetContextName, const ContextMapping& currentMapping ){
    ADD_SELECTORS("AccessLine::checkDowngradeContext");

    // goal: make sure the event does not hold any parent context locks.
    //
    //
    uint32_t ctxID = currentMapping.findIDByName( targetContextName );
    uint32_t parent = currentMapping.getParentContextID( ctxID );
    mace::string parentContextName = ContextMapping::getNameByID( currentMapping, parent);

    if( ThreadStructure::getCurrentServiceEventContexts().find( parentContextName ) != ThreadStructure::getCurrentServiceEventContexts().end() ){

    }

    return true;
  }
private:
  void failStop(const uint32_t targetContextID){
    // Entering a context c is allowed if the event already holds the lock of context c, or if c is the child context of one of the contexts this event currently holds.
    // In other words, the write line is above c.
    std::ostringstream errorOSS;
    errorOSS<<"invalid context transition. Requested context ID = targetContextID";

    ABORT( errorOSS.str().c_str() );
  }
};

}
