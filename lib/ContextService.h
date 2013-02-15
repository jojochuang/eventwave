#ifndef _CONTEXTSERVICE_H
#define _CONTEXTSERVICE_H

#include "mace.h"
#include "ContextBaseClass.h"
#include "mvector.h"
#include "m_map.h"
#include "mstring.h"
#include "mpair.h"
#include "pthread.h"
#include "ScopedLock.h"
#include "ContextMapping.h"

using mace::__asyncExtraField;
namespace mace{
  class __ServiceStackEvent__;
  class __ScopedRoutinePrep__;
};
class ContextService : public BaseMaceService
{
friend class mace::__ServiceStackEvent__;
friend class mace::__ScopedRoutinePrep__;
public:
  ContextService(bool enqueueService = true): 
    BaseMaceService(enqueueService)
    {
    pthread_mutex_init( &getContextObjectMutex, NULL );
    pthread_mutex_init( &ContextObjectCreationMutex, NULL );
    pthread_mutex_init( &eventRequestBufferMutex, NULL );
    pthread_cond_init( &ContextObjectCreationCond, NULL );
  }

  ~ContextService(){
    pthread_mutex_destroy( &getContextObjectMutex );
    pthread_mutex_destroy( &ContextObjectCreationMutex );
    pthread_mutex_destroy( &eventRequestBufferMutex );
    pthread_cond_destroy( &ContextObjectCreationCond );
  }
protected:
  mace::ContextBaseClass* getContextObjByID( uint32_t const contextID ) const{
    ADD_SELECTORS("ContextService::getContextObjByID");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjIDMap.find( contextID );
    if( cpIt == ctxobjIDMap.end() ){
      maceerr<<"context ID "<< contextID << " not found! Available context objects are: ";
      for( mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjIDMap.begin(); it!= ctxobjIDMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID ;
      }
      maceerr<< Log::endl;
      ABORT( "context id not found" );
    }

    return cpIt->second;
  }
  mace::ContextBaseClass* getContextObjByName( mace::string const& contextName ) const{
    ADD_SELECTORS("ContextService::getContextObjByName");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    if( cpIt == ctxobjNameMap.end() ){
      maceerr<<"context name "<< contextName << " not found! Available context objects are: ";
      for( mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjNameMap.begin(); it!= ctxobjNameMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID;
      }
      maceerr<< Log::endl;
      ABORT( "context name not found" );
    }
    return cpIt->second;
  }
  void copyContextData(mace::ContextBaseClass* thisContext, mace::string& s ) const;
  void eraseContextData(mace::ContextBaseClass* thisContext);
  void acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const;
  void asyncHead( mace::__asyncExtraField const& extra, int8_t const eventType);

  /* common message handlers */
  void handleAllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType);
  void handleAllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const& eventID );

  void handleContextMigrationRequest( MaceAddr const& src, mace::string const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::HighLevelEvent const& event, uint64_t const& prevContextMapVersion, mace::vector< mace::string > const& nextHops );

  void handleTransferContext( MaceAddr const& src, mace::string const& ctxId, uint32_t const& ctxNId, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse );


  void handle__event_commit( uint64_t const& eventID, int8_t const& eventType, uint32_t const& eventMessageCount );
  void handle__event_commit_context( mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID );
  void handle__event_create_response( mace::HighLevelEvent const& event, uint32_t const& counter, MaceAddr const& targetAddress);
  void handle__event_enter_context( mace::HighLevelEvent const& event, mace::vector< uint32_t > const& contextIDs );
  void handle__event_exit_committed( );
  void handle__event_create_head( __asyncExtraField const& extra, uint64_t const& counter, MaceAddr const& src);
  void handle__event_snapshot( mace::HighLevelEvent const& event, mace::string const& ctxID, mace::string const& snapshotContextID, mace::string const& snapshot);
  void handle__event_downgrade_context( mace::string const& contextID, uint64_t const& eventID, bool const& isresponse );
  void handle__event_routine_return( mace::string const& returnValue, mace::HighLevelEvent const& event);
  //void handle__event_downgrade_context( MaceAddr const& src );
  /* message dispatch function */
  virtual void sendAllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const eventID ) = 0;
  virtual void sendContextMigrationRequest( MaceAddr const& msgdestination, mace::string const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::HighLevelEvent const& event, uint64_t const& prevContextMapVersion, mace::vector< mace::string > const& nextHops ) = 0;
  virtual void send__event_commit_context( MaceAddr const& msgdestination, mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) = 0;
  virtual void remoteAllocateGlobalContext( uint32_t const globalContextID, std::pair< mace::MaceAddr, uint32_t > const& newMappingReturn, const mace::ContextMapping* ctxmapCopy ) = 0;


  virtual mace::ContextBaseClass* createContextObject( mace::string const& contextName, uint32_t const contextID ) = 0;
  virtual void sendAllocateContextObjectMsg(const mace::ContextMapping* ctxmapCopy, MaceAddr const newHead, mace::map< uint32_t, mace::string > const& contextSet, int8_t const eventType ) = 0;
  virtual void getContextSnapshot( mace::vector<uint32_t> const& snapshotContextID ) const = 0;
  virtual void routeEventRequest( MaceKey const& destNode, mace::pair< mace::string, mace::string > const& eventreq ) = 0;

  void eventPrep(__asyncExtraField const& extra );
  void eventFinish();
  void enterInnerService (mace::string const& targetContextID ) const;
  void notifyNewEvent( const uint8_t serviceID ) ;
  void notifyNewContext( const uint8_t serviceID );
  void downgradeEventContext( );
  void requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly);
  void sendAsyncSnapshot( __asyncExtraField const& extra, mace::string const& thisContextID, mace::ContextBaseClass* const& thisContext );
protected:
  mutable pthread_mutex_t getContextObjectMutex;
  mutable pthread_mutex_t ContextObjectCreationMutex;
  mutable pthread_cond_t ContextObjectCreationCond;
  pthread_mutex_t eventRequestBufferMutex;

  mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState > ctxobjIDMap;
  mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState > ctxobjNameMap;
  mace::ContextMapping contextMapping;
  mace::ContextEventRecord contextEventRecord;
};

namespace mace{
class __ServiceStackEvent__ {
  private:
  ContextService* sv;
      public:
    __ServiceStackEvent__(const int8_t eventType, ContextService* service, const mace::string& targetContextName) : sv(service) {
      bool newEventCondition;
      switch( eventType ){
        case mace::HighLevelEvent::STARTEVENT:
          newEventCondition = ThreadStructure::isFirstMaceInit();
          break;
        case mace::HighLevelEvent::ENDEVENT:
          newEventCondition = ThreadStructure::isFirstMaceExit();
          break;
        default:
          newEventCondition = ThreadStructure::isOuterMostTransition();
      }
      if( newEventCondition && !mace::HighLevelEvent::isExit ){
          ThreadStructure::newTicket();
          __asyncExtraField extra;
          extra.targetContextID = targetContextName;
          sv->asyncHead( extra, mace::HighLevelEvent::DOWNCALLEVENT );
      }
    }
    ~__ServiceStackEvent__() {
      if( ThreadStructure::isOuterMostTransition() ){
        sv->eventFinish();
      }
  }
};
class __ScopedRoutinePrep__ {
  private:
  ContextService const* sv;
  mace::ContextBaseClass *oldContextObject;
      public:
    __ScopedRoutinePrep__( ContextService const* service, uint32_t const& targetContextID, mace::vector<uint32_t> const& snapshotContextIDs) : sv(service) {
      sv->getContextSnapshot(snapshotContextIDs);
      mace::ContextBaseClass * contextObject = sv->getContextObjByID( targetContextID );
      oldContextObject = ThreadStructure::myContext();
      ThreadStructure::setMyContext( contextObject );
      ThreadStructure::pushContext( contextObject->contextName );
      ThreadStructure::insertEventContext( contextObject->contextName );
      mace::ContextLock c_lock( *contextObject, mace::ContextLock::WRITE_MODE );
    }
    ~__ScopedRoutinePrep__() {
      ThreadStructure::popContext( );
      ThreadStructure::setMyContext (oldContextObject);
    }
};
}

#endif
