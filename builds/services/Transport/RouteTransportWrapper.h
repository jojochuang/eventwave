/*********************************************
*  RouteTransportWrapper header file
*  Mace generated on:
*  Tue Apr 10 10:09:46 2012
*********************************************/

#ifndef RouteTransportWrapper_header
#define RouteTransportWrapper_header

//BEGIN: Mace::Compiler::ServiceImpl::printIncludesH
#include "lib/mace.h"
#include "lib/mace_constants.h"
#include "Enum.h"
//#include "lib/Util.h"
#include "lib/TimeUtil.h"
#include <map> //only include if can make upcalls
#include "lib/mace-macros.h"

#include "lib/Log.h"
#include "lib/MethodMap.h" // only need this for sql logging of method calls
#include "lib/ScopedLog.h"
#include "lib/SimpleLogObject.h"
#include "lib/ScopedStackExecution.h"
#include "lib/BinaryLogObject.h"
#include "lib/Serializable.h"
#include "lib/ScopedFingerprint.h"
#include "RouteTransportWrapper-constants.h"
#include "lib/ContextBaseClass.h"
#include "lib/ContextLock.h"
#include "lib/ContextMapping.h"
#include "HighLevelEvent.h"

#include "lib/Message.h"
#include "RouteServiceClass.h"
#include "TransportServiceClass.h"
#include "TransportServiceClass.h"
//END: Mace::Compiler::ServiceImpl::printIncludesH
//BEGIN: Mace::Compiler::ServiceImpl::printUsingH
using mace::BinaryLogObject;
using mace::Serializable;
using mace::SerializationException;
using mace::ContextMapping;
using mace::Message;
//END: Mace::Compiler::ServiceImpl::printUsingH
//BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
#line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"

#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
namespace RouteTransportWrapper_namespace {
  
  void load_protocol();
  
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  const std::string selector_upcall_deliver_2_transition = "RouteTransportWrapper::deliver::Data::(true)";
  const std::string selector_registerHandler_demux_3 = "RouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_resumeDeliver_downcall_2 = "RouteTransportWrapper::resumeDeliver::(downcall)";
  const std::string selector_downcall_maceInit_0_transition = "RouteTransportWrapper::maceInit::(true)";
  const std::string selector_messageError_demux_25 = "RouteTransportWrapper::messageError::(demux)";
  const std::string selector_localAddress_demux_22 = "RouteTransportWrapper::localAddress::(demux)";
  const std::string selector_maceReset_demux_21 = "RouteTransportWrapper::maceReset::(demux)";
  const std::string selector_resumeDeliver_demux_16 = "RouteTransportWrapper::resumeDeliver::(demux)";
  const std::string selector_registerUniqueHandler_demux_8 = "RouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_registerHandler_demux_9 = "RouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_downcall_route_1_transition = "RouteTransportWrapper::route::(true)";
  const std::string selector_messageError_upcall_2 = "RouteTransportWrapper::messageError::(upcall)";
  const std::string selector_registerUniqueHandler_demux_11 = "RouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_upcall_messageError_4_transition = "RouteTransportWrapper::messageError::Data::(true)";
  const std::string selector_suspendDeliver_demux_14 = "RouteTransportWrapper::suspendDeliver::(demux)";
  const std::string selector_suspendDeliver_downcall_1 = "RouteTransportWrapper::suspendDeliver::(downcall)";
  const std::string selector_error_upcall_1 = "RouteTransportWrapper::error::(upcall)";
  const std::string selector_route_downcall_6 = "RouteTransportWrapper::route::Message::(downcall)";
  const std::string selector_unregisterHandler_demux_7 = "RouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_maceExit_demux_20 = "RouteTransportWrapper::maceExit::(demux)";
  const std::string selector_upcall_messageError_5_transition = "RouteTransportWrapper::messageError::Data::(true)";
  const std::string selector_send_downcall_12 = "RouteTransportWrapper::send::(downcall)";
  const std::string selector_error_demux_0 = "RouteTransportWrapper::error::(demux)";
  const std::string selector_deliver_demux_1 = "RouteTransportWrapper::deliver::Data::(demux)";
  const std::string selector_route_downcall_5 = "RouteTransportWrapper::route::Data::(downcall)";
  const std::string selector_maceResume_demux_19 = "RouteTransportWrapper::maceResume::(demux)";
  const std::string selector_route_downcall_11 = "RouteTransportWrapper::route::(downcall)";
  const std::string selector_forward_upcall_3 = "RouteTransportWrapper::forward::(upcall)";
  const std::string selector_route_downcall_7 = "RouteTransportWrapper::route::Data::(downcall)";
  const std::string selector_route_downcall_10 = "RouteTransportWrapper::route::(downcall)";
  const std::string selector_resumeDeliver_demux_17 = "RouteTransportWrapper::resumeDeliver::(demux)";
  const std::string selector_registerUniqueHandler_demux_5 = "RouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_route_demux_12 = "RouteTransportWrapper::route::(demux)";
  const std::string selector_messageError_demux_2 = "RouteTransportWrapper::messageError::Data::(demux)";
  const std::string selector_deliver_upcall_0 = "RouteTransportWrapper::deliver::(upcall)";
  const std::string selector_unregisterHandler_demux_4 = "RouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_maceInit_demux_18 = "RouteTransportWrapper::maceInit::(demux)";
  const std::string selector_registerHandler_demux_6 = "RouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_hashState_demux_23 = "RouteTransportWrapper::hashState::(demux)";
  const std::string selector_send_downcall_9 = "RouteTransportWrapper::send::Data::(downcall)";
  const std::string selector_unregisterHandler_demux_10 = "RouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_suspendDeliver_demux_15 = "RouteTransportWrapper::suspendDeliver::(demux)";
  const std::string selector_route_downcall_4 = "RouteTransportWrapper::route::Message::(downcall)";
  const std::string selector_upcall_error_3_transition = "RouteTransportWrapper::error::(true)";
  const std::string selector_deliver_demux_24 = "RouteTransportWrapper::deliver::(demux)";
  const std::string selector_suspendDeliver_downcall_0 = "RouteTransportWrapper::suspendDeliver::(downcall)";
  const std::string selector_route_demux_13 = "RouteTransportWrapper::route::(demux)";
  const std::string selector_send_downcall_8 = "RouteTransportWrapper::send::Message::(downcall)";
  const std::string selector_resumeDeliver_downcall_3 = "RouteTransportWrapper::resumeDeliver::(downcall)";
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
  //END: Mace::Compiler::ServiceImpl::printTypeDefs
  
  //Message Declarations
  class Data;
  
  
  //Context Forward Declarations
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  
  class RouteTransportWrapperService;
  typedef RouteTransportWrapperService ServiceType;
  typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;
  typedef mace::map<int, RouteTransportWrapperService const *, mace::SoftState> _NodeMap_;
  typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;
  mace::map<mace::string, mace::string> returnValueMapping;
  std::map<mace::string, pthread_mutex_t> mutexMapping;
  static const char* __SERVICE__ __attribute((unused)) = "RouteTransportWrapper";
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
  //END: Mace::Compiler::ServiceImpl::printAutoTypes
  //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
  //END Mace::Compiler::ServiceImpl::printDeferTypes
  //BEGIN: Mace::Compiler::ServiceImpl::printService
  
  class ServiceTester;
  class RouteTransportWrapperService : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, public virtual RouteServiceClass, public virtual TransportServiceClass, public virtual ReceiveDataHandler, public virtual NetworkErrorHandler
  {
    private:
    
    friend class ServiceTester;
    
    
    int __inited;
    protected:
    enum _state_type { init,exited};
    typedef Enum<_state_type> state_type;
    
    static mace::LogNode* rootLogNode;
    mutable VersionServiceMap versionMap;
    
    
    MaceKey computeLocalAddress() const {
      return downcall_localAddress();
    }
    public:
    //Constructor
    RouteTransportWrapperService(TransportServiceClass& __trans, bool ___shared = true);
    RouteTransportWrapperService(const RouteTransportWrapperService& other);
    //Destructor
    virtual ~RouteTransportWrapperService();
    
    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;
    
    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    private:
    
    const state_type& read_state() const;
    
    
    public:
    //Misc.
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "SNAPSHOT::RouteTransportWrapper";
      return desc;
    }
    
    LogClass getLogClass() const {
      return STATE_DUMP;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    
    static const LogIdSet* selectorId_upcall_deliver_2_transition;
    static const LogIdSet* selectorId_registerHandler_demux_3;
    static const LogIdSet* selectorId_resumeDeliver_downcall_2;
    static const LogIdSet* selectorId_downcall_maceInit_0_transition;
    static const LogIdSet* selectorId_messageError_demux_25;
    static const LogIdSet* selectorId_localAddress_demux_22;
    static const LogIdSet* selectorId_maceReset_demux_21;
    static const LogIdSet* selectorId_resumeDeliver_demux_16;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_8;
    static const LogIdSet* selectorId_registerHandler_demux_9;
    static const LogIdSet* selectorId_downcall_route_1_transition;
    static const LogIdSet* selectorId_messageError_upcall_2;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_11;
    static const LogIdSet* selectorId_upcall_messageError_4_transition;
    static const LogIdSet* selectorId_suspendDeliver_demux_14;
    static const LogIdSet* selectorId_suspendDeliver_downcall_1;
    static const LogIdSet* selectorId_error_upcall_1;
    static const LogIdSet* selectorId_route_downcall_6;
    static const LogIdSet* selectorId_unregisterHandler_demux_7;
    static const LogIdSet* selectorId_maceExit_demux_20;
    static const LogIdSet* selectorId_upcall_messageError_5_transition;
    static const LogIdSet* selectorId_send_downcall_12;
    static const LogIdSet* selectorId_error_demux_0;
    static const LogIdSet* selectorId_deliver_demux_1;
    static const LogIdSet* selectorId_route_downcall_5;
    static const LogIdSet* selectorId_maceResume_demux_19;
    static const LogIdSet* selectorId_route_downcall_11;
    static const LogIdSet* selectorId_forward_upcall_3;
    static const LogIdSet* selectorId_route_downcall_7;
    static const LogIdSet* selectorId_route_downcall_10;
    static const LogIdSet* selectorId_resumeDeliver_demux_17;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_5;
    static const LogIdSet* selectorId_route_demux_12;
    static const LogIdSet* selectorId_messageError_demux_2;
    static const LogIdSet* selectorId_deliver_upcall_0;
    static const LogIdSet* selectorId_unregisterHandler_demux_4;
    static const LogIdSet* selectorId_maceInit_demux_18;
    static const LogIdSet* selectorId_registerHandler_demux_6;
    static const LogIdSet* selectorId_hashState_demux_23;
    static const LogIdSet* selectorId_send_downcall_9;
    static const LogIdSet* selectorId_unregisterHandler_demux_10;
    static const LogIdSet* selectorId_suspendDeliver_demux_15;
    static const LogIdSet* selectorId_route_downcall_4;
    static const LogIdSet* selectorId_upcall_error_3_transition;
    static const LogIdSet* selectorId_deliver_demux_24;
    static const LogIdSet* selectorId_suspendDeliver_downcall_0;
    static const LogIdSet* selectorId_route_demux_13;
    static const LogIdSet* selectorId_send_downcall_8;
    static const LogIdSet* selectorId_resumeDeliver_downcall_3;
    
    protected:
    void dumpState(LOGLOGTYPE& logger) const;
    void processDeferred();
    const char* getStateName(state_type state) const;
    const char* getMessageName(uint8_t msgNum) const;
    void changeState(state_type stateNum, int selectorId);
    bool shouldLog_route13( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_route14( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver15(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver16( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver17(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver18( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_maceInit19() const;
    bool shouldLog_maceResume20() const;
    bool shouldLog_maceExit21() const;
    bool shouldLog_maceReset22() const;
    bool shouldLog_localAddress23() const;
    bool shouldLog_hashState24() const;
    bool shouldLog_error25( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const;
    bool shouldLog_deliver26( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError27( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver0(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver1( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver2(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver3( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_route4( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route5( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route6( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route7( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send8( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send9( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    
    
    public:
    void print(mace::PrintNode& __printer, const std::string& name) const;
    void print(std::ostream& logger) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;
    
    void serialize(std::string& str) const;
    int deserialize(std::istream& is) throw(SerializationException);
    
    //Provided Methods (calls into this service from a higher layer)
    registration_uid_t registerHandler(
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ReceiveDataHandler& handler
#line 290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ReceiveDataHandler& handler
#line 299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 23 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ReceiveDataHandler& handler
#line 308 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    registration_uid_t registerHandler(
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 313 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 317 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 25 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 25 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 27 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    registration_uid_t registerHandler(
        #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 336 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 340 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 345 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 349 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 354 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool route(
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool route(
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& src
#line 372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 384 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 412 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void maceInit();
    void maceResume();
    void maceExit();
    void maceReset();
    const MaceKey& localAddress() const;
    uint32_t hashState() const;
    
    //Used Handlers (calls into this service from a lower layer)
    void deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 446 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 454 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 459 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 471 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    
    //Registration Methods (for dynamic registration)
    
    
    protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.
    
    //Constructor Parameter (Variables)
    
    
    //ServiceVariables and Registration UIDs
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    TransportServiceClass& _trans;
#line 490 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    registration_uid_t trans;
    
    //Aspect Methods
    
    
    //Registration Typedefs and Maps
    typedef std::map<int, ReceiveDataHandler* > maptype_ReceiveDataHandler;
    maptype_ReceiveDataHandler map_ReceiveDataHandler;
    typedef std::map<int, NetworkErrorHandler* > maptype_NetworkErrorHandler;
    maptype_NetworkErrorHandler map_NetworkErrorHandler;
    typedef std::map<int, ForwardDataHandler* > maptype_ForwardDataHandler;
    maptype_ForwardDataHandler map_ForwardDataHandler;
    
    //State Variables
    
    
    //Timer Vars
    
    
    //Context Declaration
    
    
    //Timer Methods
    
    
    //Async Helper Methods
    
    
    //Async Helper Methods
    
    
    //Sync Methods
    
    
    //Sync Helper Methods
    
    
    //Merge Class Declarations
    
    
    //Downcall and Upcall helper methods
    
    void downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 536 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 541 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 545 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 550 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 559 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 564 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Message& s_deserialized
#line 568 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 572 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 577 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& s_deserialized
#line 581 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 585 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& src
#line 590 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 594 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Message& s_deserialized
#line 598 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 602 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& src
#line 607 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 611 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& s_deserialized
#line 615 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 619 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 624 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Message& s_deserialized
#line 628 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 632 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 637 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& s_deserialized
#line 641 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 645 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void upcall_deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 650 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 654 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 658 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 662 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void upcall_error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 667 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 671 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message = ""
#line 675 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void upcall_messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 688 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 692 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 696 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool upcall_forward(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const MaceKey& source
#line 701 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const MaceKey& destination
#line 705 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        MaceKey& nextHop
#line 709 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const std::string& s
#line 713 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
        registration_uid_t rid = -1
#line 717 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    
    //Serialized form Method Helpers
    
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& source
#line 725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& destination
#line 729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& s_deserialized
#line 733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 737 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    void messageError(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 742 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type errorCode
#line 746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& message_deserialized
#line 750 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 754 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    
    //Transition and Guard Method Declarations
    void downcall_0_maceInit();
    bool guard_downcall_0_maceInit() const;
    bool downcall_1_route(
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 763 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const std::string& msg
#line 767 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t regId
#line 771 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool guard_downcall_1_route(
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & dest
#line 776 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        std::string const & msg
#line 780 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t const  regId
#line 784 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ) const;
    void upcall_2_deliver(
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& src
#line 789 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 793 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& msg
#line 797 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool guard_upcall_2_deliver(
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & src
#line 802 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & dest
#line 806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        Data const & msg
#line 810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ) const;
    void upcall_3_error(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& nodeId
#line 815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type error_code
#line 819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const std::string& m
#line 823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t registrationUid
#line 827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool guard_upcall_3_error(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & nodeId
#line 832 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type const  error_code
#line 836 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        std::string const & m
#line 840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t const  registrationUid
#line 844 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ) const;
    void upcall_4_messageError(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 849 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type error_code
#line 853 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& msg
#line 857 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t regId
#line 861 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool guard_upcall_4_messageError(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & dest
#line 866 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type const  error_code
#line 870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        Data const & msg
#line 874 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t const  regId
#line 878 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ) const;
    void upcall_5_messageError(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const MaceKey& dest
#line 883 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type errorCode
#line 887 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        const Data& message_deserialized
#line 891 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t rid
#line 895 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    );
    bool guard_upcall_5_messageError(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        MaceKey const & dest
#line 900 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        TransportError::type const  errorCode
#line 904 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        Data const & message_deserialized
#line 908 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        registration_uid_t const  rid
#line 912 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ) const;
    
    //Routines
    
    
    
    //Deferal Variables
    
    
    //Local Address
    MaceKey __local_address;
    MaceKey downcall_localAddress() const;
    const MaceKey& downcall_localAddress(const registration_uid_t& rid) const;
    
    //Defer methods
    
    
    
    
    //Pre and Post Transition Demux Method Declarations
    
    
    public:
    
    
    static bool checkSafetyProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("RouteTransportWrapper::checkSafetyProperties");
      maceout << "Testing safety properties" << Log::endl;
      { maceout << "Safety Properties: check" << Log::endl; return true; }
    }
    
    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("RouteTransportWrapper::checkLivenessProperties");
      maceout << "Testing liveness properties" << Log::endl;
      { maceout << "Liveness Properties: check" << Log::endl; return true; }
    }
    
    protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("RouteTransportWrapper::castNode::MaceKey");
      if (key.isNullAddress()) { return _nodes_.end(); }
      if (key.addressFamily() != IPV4) {
        macedbg(0) << "Casting " << key << Log::endl;
        if (_keys_.empty()) { return _nodes_.end(); macedbg(0) << "keys empty, end" << Log::endl; }
        if (key.addressFamily() != _keys_.begin()->first.addressFamily()) { return _nodes_.end(); macedbg(0) << "address family mismatch, end" << Log::endl; }
        _KeyMap_::const_iterator i = _keys_.find(key);
        if (i == _keys_.end()) { return _nodes_.end(); macedbg(0) << "key not found, end" << Log::endl; }
        macedbg(0) << "Returning node " << i->second << Log::endl;
        return _nodes_.find(i->second);
      }
      return _nodes_.find(key.getMaceAddr().local.addr-1);
    }
    
    static _NodeMap_::const_iterator castNode(const NodeSet::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      if((*iter).isNullAddress()) { return _nodes_.end(); }
      return castNode(*iter, _nodes_, _keys_);
    }
    
    static _NodeMap_::const_iterator castNode(const mace::map<int, _NodeMap_::const_iterator, mace::SoftState>::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      return iter->second;
    }
    
    static _NodeMap_::const_iterator castNode(const _NodeMap_::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      return iter;
    }
    
    //Model Checking Safety Properties
    
    
    //Model Checking Liveness Properties
    
  };
  //END: Mace::Compiler::ServiceImpl::printService
  //BEGIN Mace::Compiler::ServiceImpl::generateMergeClasses
  //END Mace::Compiler::ServiceImpl::generateMergeClasses
  //BEGIN: Mace::Compiler::ServiceImpl::printRoutineObjects
  //END: Mace::Compiler::ServiceImpl::printRoutineObjects
  //BEGIN: Mace::Compiler::ServiceImpl::printMessages
  
  struct Data_struct {
    
    #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    MaceKey source
#line 996 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ;
    
    #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    MaceKey dest
#line 1001 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ;
    
    #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    registration_uid_t regId
#line 1006 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ;
    
    #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    mace::string data
#line 1011 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
    ;
  };
  
  class Data : public Message, public mace::PrintPrintable {
    private:
    Data_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Data() : _data_store_(new Data_struct()), serializedByteSize(0) , source(_data_store_->source), dest(_data_store_->dest), regId(_data_store_->regId), data(_data_store_->data) {}
    Data(MaceKey const & my_source, MaceKey const & my_dest, registration_uid_t const & my_regId, mace::string const & my_data) : _data_store_(NULL), serializedByteSize(0), source(my_source), dest(my_dest), regId(my_regId), data(my_data) {}
    Data(const Data& _orig) : _data_store_(new Data_struct( *_orig._data_store_)), serializedByteSize(0) , source(_data_store_->source), dest(_data_store_->dest), regId(_data_store_->regId), data(_data_store_->data) {
    }
    virtual ~Data() { delete _data_store_; _data_store_ = NULL; }
    
    MaceKey const & source;
    MaceKey const & dest;
    registration_uid_t const & regId;
    mace::string const & data;
    
    static const uint8_t messageType = 1;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Data::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Data(";
          __out << "source=";  mace::printItem(__out, &(source));
          __out << ", ";
          __out << "dest=";  mace::printItem(__out, &(dest));
          __out << ", ";
          __out << "regId=";  mace::printItem(__out, &(regId));
          __out << ", ";
          __out << "data=";  mace::printItem(__out, &(data));
          __out << ")";
    }
    size_t getSerializedSize() const {
      if (serializedByteSize == 0 && serializedCache.empty()) {
        serialize(serializedCache);
      }
      return serializedByteSize;
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      uint8_t messaget = messageType;
      size_t initsize = str.size();
      mace::serialize(str, &messaget);
      
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      mace::serialize(str, &source);
#line 1064 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      mace::serialize(str, &dest);
#line 1069 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      mace::serialize(str, &regId);
#line 1074 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      mace::serialize(str, &data);
#line 1079 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      uint8_t messaget = 255;
      serializedByteSize += mace::deserialize(__mace_in, &messaget);
      ASSERT(messaget == messageType);
      
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->source);
#line 1094 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->dest);
#line 1099 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->regId);
#line 1104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      
      #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->data);
#line 1109 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, source INT, dest INT, regId INT, data TEXT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_source", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_regId", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _sourceIndex = __node->children[0]->nextId;
      int _destIndex = __node->children[1]->nextId;
      int _regIdIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _sourceIndex;
      __out << "\t" << _destIndex;
      __out << "\t" << _regIdIndex;
      __out << "\t";
      if (Base64::isPrintable(data)) {
        __out << data;
      }
      else {
        __out << HashString::hash(data);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&source, __node->children[0]);
      mace::sqlize(&dest, __node->children[1]);
      mace::sqlize(&regId, __node->children[2]);
      
    }
    
    std::string serializeStr() const {
      if (serializedCache.empty()) {
        serialize(serializedCache);
      }
      return serializedCache;
    }
    void deserializeStr(const std::string& __s) throw (mace::SerializationException) {
      serializedCache = __s;
      Serializable::deserializeStr(__s);
    }
  };
  
  //END: Mace::Compiler::ServiceImpl::printMessages
  //BEGIN: Mace::Compiler::ServiceImpl::printTimerClasses
  //END: Mace::Compiler::ServiceImpl::printTimerClasses
  class route13Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    std::string* _s;
    const std::string& s;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_route13";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route13Dummy() : _dest(new MaceKey()), dest(*_dest), _s(new std::string()), s(*_s), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route13Dummy(const MaceKey& ___dest, const std::string& ___s, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s(NULL), s(___s), _rid(NULL), rid(___rid) { }
    
    
    ~route13Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_s != NULL) { delete _s; _s = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "route(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[s=";
          mace::printItem(out, &s);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, s TEXT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t";
      if (Base64::isPrintable(s)) {
        __out << s;
      }
      else {
        __out << HashString::hash(s);
      }
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class maceInit19Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_maceInit19";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::maceInit()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceInit19Dummy()  { }
    
    
    
    
    ~maceInit19Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "maceInit(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class maceReset22Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_maceReset22";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::maceReset()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceReset22Dummy()  { }
    
    
    
    
    ~maceReset22Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "maceReset(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class hashState24Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_hashState24";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::hashState() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hashState24Dummy()  { }
    
    
    
    
    ~hashState24Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "hashState(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class error25Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _nodeId;
    const MaceKey& nodeId;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    std::string* _message;
    const std::string& message;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_error25";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::error( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    error25Dummy() : _nodeId(new MaceKey()), nodeId(*_nodeId), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message(new std::string()), message(*_message), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    error25Dummy(const MaceKey& ___nodeId, const TransportError::type& ___errorCode, const std::string& ___message, const registration_uid_t& ___rid) : _nodeId(NULL), nodeId(___nodeId), _errorCode(NULL), errorCode(___errorCode), _message(NULL), message(___message), _rid(NULL), rid(___rid) { }
    
    
    ~error25Dummy() {
      if (_nodeId != NULL) { delete _nodeId; _nodeId = NULL; }
      if (_errorCode != NULL) { delete _errorCode; _errorCode = NULL; }
      if (_message != NULL) { delete _message; _message = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "error(";
          out << "[nodeId=";
          mace::printItem(out, &nodeId);
          out << "]";
          out << "[errorCode=";
          mace::printItem(out, &errorCode);
          out << "]";
          out << "[message=";
          mace::printItem(out, &message);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, nodeId INT, errorCode INT, message TEXT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_nodeId", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_errorCode", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _nodeIdIndex = __node->children[0]->nextId;
      int _errorCodeIndex = __node->children[1]->nextId;
      int _ridIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _nodeIdIndex;
      __out << "\t" << _errorCodeIndex;
      __out << "\t";
      if (Base64::isPrintable(message)) {
        __out << message;
      }
      else {
        __out << HashString::hash(message);
      }
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&nodeId, __node->children[0]);
      mace::sqlize(&errorCode, __node->children[1]);
      mace::sqlize(&rid, __node->children[2]);
      
    }
  };
  class deliver26Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    Data* _s_deserialized;
    const Data& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_deliver26";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver26Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver26Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver26Dummy() {
      if (_source != NULL) { delete _source; _source = NULL; }
      if (_destination != NULL) { delete _destination; _destination = NULL; }
      if (_s_deserialized != NULL) { delete _s_deserialized; _s_deserialized = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "deliver(";
          out << "[source=";
          mace::printItem(out, &source);
          out << "]";
          out << "[destination=";
          mace::printItem(out, &destination);
          out << "]";
          out << "[s_deserialized=";
          mace::printItem(out, &s_deserialized);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, source INT, destination INT, s_deserialized INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_source", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_destination", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_s_deserialized", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _sourceIndex = __node->children[0]->nextId;
      int _destinationIndex = __node->children[1]->nextId;
      int _s_deserializedIndex = __node->children[2]->nextId;
      int _ridIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _sourceIndex;
      __out << "\t" << _destinationIndex;
      __out << "\t" << _s_deserializedIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&source, __node->children[0]);
      mace::sqlize(&destination, __node->children[1]);
      mace::sqlize(&s_deserialized, __node->children[2]);
      mace::sqlize(&rid, __node->children[3]);
      
    }
  };
  class messageError27Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    Data* _message_deserialized;
    const Data& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_messageError27";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError27Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Data()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError27Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Data& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError27Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_errorCode != NULL) { delete _errorCode; _errorCode = NULL; }
      if (_message_deserialized != NULL) { delete _message_deserialized; _message_deserialized = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "messageError(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[errorCode=";
          mace::printItem(out, &errorCode);
          out << "]";
          out << "[message_deserialized=";
          mace::printItem(out, &message_deserialized);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, errorCode INT, message_deserialized INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_errorCode", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_message_deserialized", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _errorCodeIndex = __node->children[1]->nextId;
      int _message_deserializedIndex = __node->children[2]->nextId;
      int _ridIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _errorCodeIndex;
      __out << "\t" << _message_deserializedIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&errorCode, __node->children[1]);
      mace::sqlize(&message_deserialized, __node->children[2]);
      mace::sqlize(&rid, __node->children[3]);
      
    }
  };
  class suspendDeliver0Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_suspendDeliver0";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::suspendDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver0Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver0Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver0Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "suspendDeliver(";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _ridIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&rid, __node->children[0]);
      
    }
  };
  class suspendDeliver1Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_suspendDeliver1";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::suspendDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver1Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver1Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver1Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "suspendDeliver(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class resumeDeliver2Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_resumeDeliver2";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::resumeDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver2Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver2Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver2Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "resumeDeliver(";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _ridIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&rid, __node->children[0]);
      
    }
  };
  class resumeDeliver3Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_resumeDeliver3";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::resumeDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver3Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver3Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver3Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "resumeDeliver(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class route4Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_route4";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route4Dummy()  { }
    
    
    
    
    ~route4Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "route(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class route5Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Data* _s_deserialized;
    const Data& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_route5";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route5Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route5Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route5Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_s_deserialized != NULL) { delete _s_deserialized; _s_deserialized = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "route(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[s_deserialized=";
          mace::printItem(out, &s_deserialized);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, s_deserialized INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_s_deserialized", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _s_deserializedIndex = __node->children[1]->nextId;
      int _ridIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _s_deserializedIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&s_deserialized, __node->children[1]);
      mace::sqlize(&rid, __node->children[2]);
      
    }
  };
  class route6Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_route6";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route6Dummy()  { }
    
    
    
    
    ~route6Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "route(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class route7Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    Data* _s_deserialized;
    const Data& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_route7";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route7Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route7Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route7Dummy() {
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_s_deserialized != NULL) { delete _s_deserialized; _s_deserialized = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "route(";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[s_deserialized=";
          mace::printItem(out, &s_deserialized);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, src INT, dest INT, s_deserialized INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_s_deserialized", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _srcIndex = __node->children[0]->nextId;
      int _destIndex = __node->children[1]->nextId;
      int _s_deserializedIndex = __node->children[2]->nextId;
      int _ridIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _srcIndex;
      __out << "\t" << _destIndex;
      __out << "\t" << _s_deserializedIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&src, __node->children[0]);
      mace::sqlize(&dest, __node->children[1]);
      mace::sqlize(&s_deserialized, __node->children[2]);
      mace::sqlize(&rid, __node->children[3]);
      
    }
  };
  class send8Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_send8";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send8Dummy()  { }
    
    
    
    
    ~send8Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "send(";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class send9Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Data* _s_deserialized;
    const Data& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "RouteTransportWrapper_send9";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "RouteTransportWrapper::send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send9Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send9Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send9Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_s_deserialized != NULL) { delete _s_deserialized; _s_deserialized = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "send(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[s_deserialized=";
          mace::printItem(out, &s_deserialized);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, s_deserialized INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_s_deserialized", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _s_deserializedIndex = __node->children[1]->nextId;
      int _ridIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _s_deserializedIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&s_deserialized, __node->children[1]);
      mace::sqlize(&rid, __node->children[2]);
      
    }
  };
}
#endif
