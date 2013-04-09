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
#include "Message.h"
#include "Printable.h"
#include "Event.h"

using mace::__asyncExtraField;
using mace::ContextMapping;
namespace mace{
  class __ServiceStackEvent__;
  class __ScopedTransition__;
  class __ScopedRoutine__;

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
  /*class InternalMessageHelper : public Serializable, virtual public Printable  {
    
  };*/
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
  /*class InternalMessage: public Message, public PrintPrintable{
  private:
    uint8_t type;
    InternalMessageHelper* helper;
  public:
    InternalMessage(  ){}
    static const uint8_t messageType = 255;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return InternalMessage::getMsgType(); }

    std::string toString() const { 
      mace::string str;
      return str;
    }
    void print(std::ostream& __out) const { }
    size_t getSerializedSize() const { return 0; }
    void serialize(std::string& str) const { }

    virtual int deserialize(std::istream& in) throw(SerializationException) {
      int count = 0;
      count += mace::deserialize(in, &type);

      helper = HelperPtr();
      switch(address_family) {
      case UNDEFINED_ADDRESS: return count;
      case IPV4: helper = HelperPtr(new ipv4_MaceKey()); break;
      case SHA160: helper = HelperPtr(new sha160_MaceKey()); break;
      case SHA32: helper = HelperPtr(new sha32_MaceKey()); break;
      case STRING_ADDRESS: helper = HelperPtr(new string_MaceKey()); break;
      case CONTEXTNODE: helper = HelperPtr(new ctxnode_MaceKey()); break;
      case VNODE: helper = HelperPtr(new vnode_MaceKey()); break;
      default: throw(InvalidMaceKeyException("Deserializing bad address family "+boost::lexical_cast<std::string>(address_family)+"!"));
      }
      count += helper->deserialize(in); 
      return count;
    }
    void sqlize(mace::LogNode* __node) const { }

    std::string serializeStr() const { 
      mace::string str;
      return str;
    }
    void deserializeStr(const std::string& __s) throw (mace::SerializationException) { }
  };
  */
};
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
  void nullEventHead( void *p );
protected:
  mace::ContextBaseClass* getContextObjByID( uint32_t const contextID ) const{
    ADD_SELECTORS("ContextService::getContextObjByID");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjIDMap.find( contextID );
    if( cpIt == ctxobjIDMap.end() ){
      /*maceerr<<"context ID "<< contextID << " not found! Available context objects are: ";
      for( mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjIDMap.begin(); it!= ctxobjIDMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID ;
      }
      maceerr<< Log::endl;
      ABORT( "context id not found" );
      */
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
  void wakeupWaitingThreads(uint64_t contextID) const{
    std::map< uint64_t, std::set< pthread_cond_t* > >::iterator condSetIt = contextWaitingThreads.find( contextID );
    if( condSetIt != contextWaitingThreads.end() ){
      for( std::set< pthread_cond_t* >::iterator condIt = condSetIt->second.begin(); condIt != condSetIt->second.end(); condIt++ ){
        pthread_cond_signal( *condIt );
      }
      contextWaitingThreads.erase( condSetIt );

    }
  }
  void wakeupWaitingThreads(mace::string const& contextName) const{
    std::map< mace::string, std::set< pthread_cond_t* > >::iterator condSetIt = contextWaitingThreads2.find( contextName );
    if( condSetIt != contextWaitingThreads2.end() ){
      for( std::set< pthread_cond_t* >::iterator condIt = condSetIt->second.begin(); condIt != condSetIt->second.end(); condIt++ ){
        pthread_cond_signal( *condIt );
      }
      contextWaitingThreads2.erase( condSetIt );

    }
  }
  mace::ContextBaseClass* getContextObjByName( mace::string const& contextName ) const{
    ADD_SELECTORS("ContextService::getContextObjByName");
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    if( cpIt == ctxobjNameMap.end() ){
      /*maceerr<<"context name "<< contextName << " not found! Available context objects are: ";
      for( mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjNameMap.begin(); it!= ctxobjNameMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID;
      }
      maceerr<< Log::endl;
      ABORT( "context name not found" );
      */
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
  /* common message handlers */
  void handle__event_AllocateContextObject( MaceAddr const& src, MaceAddr const& destNode, mace::map< uint32_t, mace::string > const& ContextID, uint64_t const& eventID, mace::ContextMapping const& contextMapping, int8_t const& eventType);
  void handle__event_AllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const& eventID );

  void handle__event_ContextMigrationRequest( MaceAddr const& src, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::Event const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& nextHops );

  void handle__event_TransferContext( MaceAddr const& src, uint32_t const rootContextID, mace::string const& ctxId, uint32_t const& ctxNId, mace::string const& checkpoint, uint64_t const& eventId, MaceAddr const& parentContextNode, bool const& isresponse );


  void handle__event_commit( mace::Event const& event ) const;
  void handle__event_commit_context( mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const;
  void handle__event_create_response( mace::Event const& event, uint32_t const& counter, MaceAddr const& targetAddress);
  void handle__event_enter_context( mace::Event const& event, mace::vector< uint32_t > const& contextIDs );
  void handle__event_exit_committed( );
  void handle__event_create_head( __asyncExtraField const& extra, uint64_t const& counter, MaceAddr const& src);
  void handle__event_snapshot( mace::Event const& event, mace::string const& ctxID, mace::string const& snapshotContextID, mace::string const& snapshot);
  void handle__event_downgrade_context( uint32_t const& contextID, uint64_t const& eventID, bool const& isresponse );
  void handle__event_routine_return( mace::string const& returnValue, mace::Event const& event);
  void handle__event_new_head_ready(  MaceAddr const& src);
  void handle__event_evict( MaceAddr const& src );
  void handle__event_migrate_context( mace::MaceAddr const& newNode, mace::string const& contextName, uint64_t const delay );
  void handle__event_migrate_param( mace::string const& paramid );
  void handle__event_RemoveContextObject( uint64_t const eventID, mace::ContextMapping const& ctxmapCopy, MaceAddr const& dest, uint32_t contextID );
  void handle__event_delete_context( mace::string const& contextName );
  void handle__event_MigrateContext( void *p );
  /* message dispatch function */
  virtual void send__event_AllocateContextObjectResponse( MaceAddr const& src, MaceAddr const& destNode, uint64_t const eventID ) = 0;
  virtual void send__event_ContextMigrationRequest( MaceAddr const& msgdestination, uint32_t const& ctxId, MaceAddr const& dest, bool const& rootOnly, mace::Event const& event, uint64_t const& prevContextMapVersion, mace::vector< uint32_t > const& nextHops ) = 0;
  virtual void const_send__event_commit_context( MaceAddr const& msgdestination, mace::vector< uint32_t > const& nextHops, uint64_t const& eventID, int8_t const& eventType, uint64_t const& eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const& eventSkipID, bool const& isresponse, bool const& hasException, uint32_t const& exceptionContextID ) const = 0;
  virtual void send__event_commit( MaceAddr const& msgdestination, mace::Event const& event ) = 0;
  virtual void const_send__event_commit( MaceAddr const& msgdestination, mace::Event const& event ) const = 0;
  virtual void send__event_snapshot( MaceAddr const& msgdestination, mace::Event const& event, mace::string const& targetContextID, mace::string const& snapshotContextID, mace::string const& snapshot ) = 0;
  virtual void send__event_create_response( MaceAddr const& msgdestination, mace::Event const& event, uint32_t const& counter, MaceAddr const& targetAddress) = 0;
  virtual void const_send__event_create( MaceAddr const& msgdestination, __asyncExtraField const& extra, uint32_t const& counter) const = 0;
  virtual void send__event_downgrade_context( MaceAddr const& msgdestination, uint32_t const contextID, uint64_t const eventID, bool const isresponse ) = 0;

  virtual void remoteAllocateGlobalContext( mace::string const& globalContextID, std::pair< mace::MaceAddr, uint32_t > const& newMappingReturn, const mace::ContextMapping* ctxmapCopy ) = 0;
  virtual void send__event_TransferContext( MaceAddr const& msgdestination, uint32_t const rootContextID, mace::string const& ctxId, uint32_t const ctxNId, mace::string const& checkpoint, uint64_t const eventId, MaceAddr const& parentContextNode, bool const isresponse ) = 0;
  virtual void send__event_AllocateContextObjectMsg( uint64_t const eventID, const mace::ContextMapping* ctxmapCopy, MaceAddr const newHead, mace::map< uint32_t, mace::string > const& contextSet, int8_t const eventType ) = 0;
  virtual void send__event_migrate_context(mace::MaceAddr const& newNode, mace::string const& contextName, uint64_t const delay ) = 0;
  virtual void send__event_migrate_param(mace::string const& paramid ) = 0;
  virtual void send__event_routine_return( mace::MaceKey const& src, mace::string const& returnValueStr ) const = 0;
  virtual void send__event_RemoveContextObject( uint64_t const eventID, mace::ContextMapping const& ctxmapCopy, MaceAddr const& dest, uint32_t contextID ) = 0;
  virtual void send__event_delete_context( mace::string const& contextName ) = 0;


  virtual mace::ContextBaseClass* createContextObject( uint64_t const eventID, mace::string const& contextName, uint32_t const contextID ) = 0;
  void doDeleteContext( mace::string const& contextName  );
  void deleteContext( mace::string const& contextName );
  //void deleteContextObject( uint64_t const eventID, uint32_t const contextID );
  virtual void getContextSnapshot( mace::vector<uint32_t> const& snapshotContextID ) const = 0;
  virtual void routeEventRequest( MaceKey const& destNode, mace::string const& eventreq ) = 0;


  ////// functions that are common to all context'ed services

  void copyContextData(mace::ContextBaseClass* thisContext, mace::string& s ) const;
  void eraseContextData(mace::ContextBaseClass* thisContext);
  void acquireContextLocksCommon(uint32_t const targetContextID, mace::vector<uint32_t> const& snapshotContextIDs, mace::map< MaceAddr, mace::vector< uint32_t > >& ancestorContextNodes) const;
  //void asyncHead( mace::Event& event,  mace::__asyncExtraField const& extra, int8_t const eventType);
  mace::ContextMapping const&  asyncHead( mace::Event& event,  mace::__asyncExtraField const& extra, int8_t const eventType);
  //void __beginTransition(__asyncExtraField const& extra ) const;
  void __beginTransition( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs  ) const;
  //void __beginMethod(__asyncExtraField const& extra ) const;
  void __beginMethod( const uint32_t targetContextID, mace::vector<uint32_t> const& snapshotContextIDs ) const;
  void __finishTransition(mace::ContextBaseClass* oldContext) const;
  void __finishMethod(mace::ContextBaseClass* oldContext) const;
  void enterInnerService (mace::string const& targetContextID ) const;
  void notifyNewEvent( mace::Event & event,  const uint8_t serviceID ) ;
  void notifyNewContext( mace::Event & event, const uint8_t serviceID );
  void downgradeEventContext( );
  void requestContextMigrationCommon(const uint8_t serviceID, const mace::string& contextID, const MaceAddr& destNode, const bool rootOnly);
  void sendAsyncSnapshot( __asyncExtraField const& extra, mace::string const& thisContextID, mace::ContextBaseClass* const& thisContext );
  void loadContextMapping(const mace::map<mace::MaceAddr ,mace::list<mace::string > >& servContext);
  void downgradeContext( mace::string const& contextName );
  
  void requestRouteEvent ( __asyncExtraField& extra, mace::Event& event, mace::Serializable& msg ) const;
  void migrateContext( mace::string const& paramid );
  void __beginRemoteMethod( mace::Event const& event ) const;
  void __finishRemoteMethodReturn(  mace::MaceKey const& src, mace::string const& returnValueStr ) const;

  void wasteTicket( void ) const;
protected:
  mutable pthread_mutex_t getContextObjectMutex;
  mutable pthread_mutex_t ContextObjectCreationMutex;
  mutable pthread_cond_t ContextObjectCreationCond;
  mutable pthread_mutex_t eventRequestBufferMutex;

  static std::map< uint64_t, std::set< pthread_cond_t* > > contextWaitingThreads;
  static std::map< mace::string, std::set< pthread_cond_t* > > contextWaitingThreads2;

  mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState > ctxobjIDMap;
  mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState > ctxobjNameMap;
  mace::ContextMapping contextMapping;
  mace::ContextEventRecord contextEventRecord;
  //mutable mace::hash_map< uint32_t, mace::pair<mace::string*, mace::string > > unfinishedEventRequest;
  mutable std::map< uint32_t, std::pair<mace::string*, mace::string > > unfinishedEventRequest;
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
          newEventCondition = ThreadStructure::isFirstMaceInit();
          break;
        case mace::Event::ENDEVENT:
          newEventCondition = ThreadStructure::isFirstMaceExit();
          break;
        default:
          newEventCondition = ThreadStructure::isOuterMostTransition();
      }
      if( newEventCondition && !mace::Event::isExit ){
          ThreadStructure::newTicket();
          __asyncExtraField extra;
          extra.targetContextID = targetContextName;
          sv->asyncHead( ThreadStructure::myEvent(), extra, eventType );
      }
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
