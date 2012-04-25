/*********************************************
*  RouteTransportWrapper main source file
*  Mace generated on:
*  Tue Apr 10 10:09:46 2012
*********************************************/
//BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"

#include "RouteTransportWrapper.h"
#include "RouteTransportWrapper-macros.h"
#include "Enum.h"
#include "Log.h"
#include "ScopedLock.h"
#include "MaceTime.h"
#include "ScopedLog.h"
#include "ScopedSerialize.h"
#include "pip_includer.h"
#include "AsyncDispatch.h"
#include "lib/MaceTime.h"
#include "lib/ServiceFactory.h"
#include "lib/ServiceConfig.h"
#include <boost/algorithm/string.hpp>

bool operator==(const mace::map<int, mace::map<int, RouteTransportWrapper_namespace::RouteTransportWrapperService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, RouteTransportWrapper_namespace::RouteTransportWrapperService*, mace::SoftState>::const_iterator& rhs) {
  return lhs->second == rhs;
}
bool operator==(const mace::map<int, RouteTransportWrapper_namespace::RouteTransportWrapperService*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, RouteTransportWrapper_namespace::RouteTransportWrapperService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
  return lhs == rhs->second;
}
namespace mace {
  template<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;
}
namespace RouteTransportWrapper_namespace {
  mace::LogNode* RouteTransportWrapperService::rootLogNode = NULL;
  //    mace::LogNode* RouteTransportWrapperDummy::rootLogNode = NULL;
  //Selector Constants
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //const std::string selector_upcall_deliver_2_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_upcall_deliver_2_transition;
  //const std::string selector_registerHandler_demux_3;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerHandler_demux_3;
  //const std::string selector_resumeDeliver_downcall_2;
  const LogIdSet* RouteTransportWrapperService::selectorId_resumeDeliver_downcall_2;
  //const std::string selector_downcall_maceInit_0_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_downcall_maceInit_0_transition;
  //const std::string selector_messageError_demux_25;
  const LogIdSet* RouteTransportWrapperService::selectorId_messageError_demux_25;
  //const std::string selector_localAddress_demux_22;
  const LogIdSet* RouteTransportWrapperService::selectorId_localAddress_demux_22;
  //const std::string selector_maceReset_demux_21;
  const LogIdSet* RouteTransportWrapperService::selectorId_maceReset_demux_21;
  //const std::string selector_resumeDeliver_demux_16;
  const LogIdSet* RouteTransportWrapperService::selectorId_resumeDeliver_demux_16;
  //const std::string selector_registerUniqueHandler_demux_8;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_8;
  //const std::string selector_registerHandler_demux_9;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerHandler_demux_9;
  //const std::string selector_downcall_route_1_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_downcall_route_1_transition;
  //const std::string selector_messageError_upcall_2;
  const LogIdSet* RouteTransportWrapperService::selectorId_messageError_upcall_2;
  //const std::string selector_registerUniqueHandler_demux_11;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_11;
  //const std::string selector_upcall_messageError_4_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_upcall_messageError_4_transition;
  //const std::string selector_suspendDeliver_demux_14;
  const LogIdSet* RouteTransportWrapperService::selectorId_suspendDeliver_demux_14;
  //const std::string selector_suspendDeliver_downcall_1;
  const LogIdSet* RouteTransportWrapperService::selectorId_suspendDeliver_downcall_1;
  //const std::string selector_error_upcall_1;
  const LogIdSet* RouteTransportWrapperService::selectorId_error_upcall_1;
  //const std::string selector_route_downcall_6;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_6;
  //const std::string selector_unregisterHandler_demux_7;
  const LogIdSet* RouteTransportWrapperService::selectorId_unregisterHandler_demux_7;
  //const std::string selector_maceExit_demux_20;
  const LogIdSet* RouteTransportWrapperService::selectorId_maceExit_demux_20;
  //const std::string selector_upcall_messageError_5_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_upcall_messageError_5_transition;
  //const std::string selector_send_downcall_12;
  const LogIdSet* RouteTransportWrapperService::selectorId_send_downcall_12;
  //const std::string selector_error_demux_0;
  const LogIdSet* RouteTransportWrapperService::selectorId_error_demux_0;
  //const std::string selector_deliver_demux_1;
  const LogIdSet* RouteTransportWrapperService::selectorId_deliver_demux_1;
  //const std::string selector_route_downcall_5;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_5;
  //const std::string selector_maceResume_demux_19;
  const LogIdSet* RouteTransportWrapperService::selectorId_maceResume_demux_19;
  //const std::string selector_route_downcall_11;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_11;
  //const std::string selector_forward_upcall_3;
  const LogIdSet* RouteTransportWrapperService::selectorId_forward_upcall_3;
  //const std::string selector_route_downcall_7;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_7;
  //const std::string selector_route_downcall_10;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_10;
  //const std::string selector_resumeDeliver_demux_17;
  const LogIdSet* RouteTransportWrapperService::selectorId_resumeDeliver_demux_17;
  //const std::string selector_registerUniqueHandler_demux_5;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_5;
  //const std::string selector_route_demux_12;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_demux_12;
  //const std::string selector_messageError_demux_2;
  const LogIdSet* RouteTransportWrapperService::selectorId_messageError_demux_2;
  //const std::string selector_deliver_upcall_0;
  const LogIdSet* RouteTransportWrapperService::selectorId_deliver_upcall_0;
  //const std::string selector_unregisterHandler_demux_4;
  const LogIdSet* RouteTransportWrapperService::selectorId_unregisterHandler_demux_4;
  //const std::string selector_maceInit_demux_18;
  const LogIdSet* RouteTransportWrapperService::selectorId_maceInit_demux_18;
  //const std::string selector_registerHandler_demux_6;
  const LogIdSet* RouteTransportWrapperService::selectorId_registerHandler_demux_6;
  //const std::string selector_hashState_demux_23;
  const LogIdSet* RouteTransportWrapperService::selectorId_hashState_demux_23;
  //const std::string selector_send_downcall_9;
  const LogIdSet* RouteTransportWrapperService::selectorId_send_downcall_9;
  //const std::string selector_unregisterHandler_demux_10;
  const LogIdSet* RouteTransportWrapperService::selectorId_unregisterHandler_demux_10;
  //const std::string selector_suspendDeliver_demux_15;
  const LogIdSet* RouteTransportWrapperService::selectorId_suspendDeliver_demux_15;
  //const std::string selector_route_downcall_4;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_downcall_4;
  //const std::string selector_upcall_error_3_transition;
  const LogIdSet* RouteTransportWrapperService::selectorId_upcall_error_3_transition;
  //const std::string selector_deliver_demux_24;
  const LogIdSet* RouteTransportWrapperService::selectorId_deliver_demux_24;
  //const std::string selector_suspendDeliver_downcall_0;
  const LogIdSet* RouteTransportWrapperService::selectorId_suspendDeliver_downcall_0;
  //const std::string selector_route_demux_13;
  const LogIdSet* RouteTransportWrapperService::selectorId_route_demux_13;
  //const std::string selector_send_downcall_8;
  const LogIdSet* RouteTransportWrapperService::selectorId_send_downcall_8;
  //const std::string selector_resumeDeliver_downcall_3;
  const LogIdSet* RouteTransportWrapperService::selectorId_resumeDeliver_downcall_3;
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //Change Tracker (optional)
  //BEGIN Mace::Compiler::ServiceImpl::printChangeTracker
  //END Mace::Compiler::ServiceImpl::printChangeTracker
  
  //service variable includes and uses
  
  
  //Transition and Guard Implementations
  //BEGIN Mace::Compiler::ServiceImpl::printTransitions
  bool RouteTransportWrapperService::guard_downcall_0_maceInit() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        true
#line 157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void RouteTransportWrapperService::downcall_0_maceInit() {
    #define selector selector_downcall_maceInit_0_transition
    #define selectorId selectorId_downcall_maceInit_0_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    {
    }
#line 179 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool RouteTransportWrapperService::guard_downcall_1_route(
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & dest
#line 187 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      std::string const & msg
#line 191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t const  regId
#line 195 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        true
#line 205 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  bool RouteTransportWrapperService::downcall_1_route(
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 214 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const std::string& msg
#line 218 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t regId
#line 222 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    #define selector selector_downcall_route_1_transition
    #define selectorId selectorId_downcall_route_1_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    {
      MaceKey nextHop = dest;
      if(upcall_forward(__local_address, dest, nextHop, msg, regId)) {
        return downcall_route(nextHop, Data(__local_address, dest, regId, msg));
      }
      return true;
    }
#line 244 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool RouteTransportWrapperService::guard_upcall_2_deliver(
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & src
#line 252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & dest
#line 256 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      Data const & msg
#line 260 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        true
#line 270 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void RouteTransportWrapperService::upcall_2_deliver(
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& src
#line 279 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 283 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& msg
#line 287 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_deliver_2_transition
    #define selectorId selectorId_upcall_deliver_2_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    {
      MaceKey nextHop = __local_address;
      if(upcall_forward(msg.source, msg.dest, nextHop, msg.data, msg.regId)) {
        if(nextHop == __local_address) {
          upcall_deliver(msg.source, msg.dest, msg.data, msg.regId);
        } else {
          downcall_route(nextHop, msg);
        }
      }
    }
#line 312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool RouteTransportWrapperService::guard_upcall_3_error(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & nodeId
#line 320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type const  error_code
#line 324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      std::string const & m
#line 328 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t const  registrationUid
#line 332 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        true
#line 342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void RouteTransportWrapperService::upcall_3_error(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& nodeId
#line 351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type error_code
#line 355 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const std::string& m
#line 359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t registrationUid
#line 363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_error_3_transition
    #define selectorId selectorId_upcall_error_3_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    {
      upcallAllVoid(error, nodeId, error_code, m);
    }
#line 381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool RouteTransportWrapperService::guard_upcall_4_messageError(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & dest
#line 389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type const  error_code
#line 393 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      Data const & msg
#line 397 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t const  regId
#line 401 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
        true
#line 411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void RouteTransportWrapperService::upcall_4_messageError(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type error_code
#line 424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& msg
#line 428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t regId
#line 432 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_messageError_4_transition
    #define selectorId selectorId_upcall_messageError_4_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    {
      upcall_messageError(msg.dest, error_code, msg.data, msg.regId);
    }
#line 450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool RouteTransportWrapperService::guard_upcall_5_messageError(
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      MaceKey const & dest
#line 458 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type const  errorCode
#line 462 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      Data const & message_deserialized
#line 466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t const  rid
#line 470 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        true
#line 480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void RouteTransportWrapperService::upcall_5_messageError(
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type errorCode
#line 493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& message_deserialized
#line 497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 501 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_messageError_5_transition
    #define selectorId selectorId_upcall_messageError_5_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
    { }
#line 517 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  //END Mace::Compiler::ServiceImpl::printTransitions
  
  //Structured Logging Functions
  mace::LogNode* route13Dummy::rootLogNode = NULL;
  mace::LogNode* maceInit19Dummy::rootLogNode = NULL;
  mace::LogNode* maceReset22Dummy::rootLogNode = NULL;
  mace::LogNode* hashState24Dummy::rootLogNode = NULL;
  mace::LogNode* error25Dummy::rootLogNode = NULL;
  mace::LogNode* deliver26Dummy::rootLogNode = NULL;
  mace::LogNode* messageError27Dummy::rootLogNode = NULL;
  mace::LogNode* suspendDeliver0Dummy::rootLogNode = NULL;
  mace::LogNode* suspendDeliver1Dummy::rootLogNode = NULL;
  mace::LogNode* resumeDeliver2Dummy::rootLogNode = NULL;
  mace::LogNode* resumeDeliver3Dummy::rootLogNode = NULL;
  mace::LogNode* route4Dummy::rootLogNode = NULL;
  mace::LogNode* route5Dummy::rootLogNode = NULL;
  mace::LogNode* route6Dummy::rootLogNode = NULL;
  mace::LogNode* route7Dummy::rootLogNode = NULL;
  mace::LogNode* send8Dummy::rootLogNode = NULL;
  mace::LogNode* send9Dummy::rootLogNode = NULL;
  // logging funcs
  bool RouteTransportWrapperService::shouldLog_route13( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_route14( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_suspendDeliver15(registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_suspendDeliver16( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_resumeDeliver17(registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_resumeDeliver18( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_maceInit19() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_maceResume20() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_maceExit21() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_maceReset22() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_localAddress23() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_hashState24() const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_error25( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_deliver26( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_messageError27( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_suspendDeliver0(registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_suspendDeliver1( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_resumeDeliver2(registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_resumeDeliver3( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_route4( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_route5( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_route6( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_route7( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_send8( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool RouteTransportWrapperService::shouldLog_send9( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  
  //Auto Type Methods
  //BEGIN: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
  //END: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
  
  //Routines
  //BEGIN Mace::Compiler::ServiceImpl::printRoutines
  
  static void initializeSelectors() {
    static bool _inited = false;
    if (!_inited) {
      log_id_t mid __attribute((unused)) = Log::getId("MethodMap");
      _inited = true;
      RouteTransportWrapperService::selectorId_upcall_deliver_2_transition = new LogIdSet(selector_upcall_deliver_2_transition);
      RouteTransportWrapperService::selectorId_registerHandler_demux_3 = new LogIdSet(selector_registerHandler_demux_3);
      RouteTransportWrapperService::selectorId_resumeDeliver_downcall_2 = new LogIdSet(selector_resumeDeliver_downcall_2);
      RouteTransportWrapperService::selectorId_downcall_maceInit_0_transition = new LogIdSet(selector_downcall_maceInit_0_transition);
      RouteTransportWrapperService::selectorId_messageError_demux_25 = new LogIdSet(selector_messageError_demux_25);
      RouteTransportWrapperService::selectorId_localAddress_demux_22 = new LogIdSet(selector_localAddress_demux_22);
      RouteTransportWrapperService::selectorId_maceReset_demux_21 = new LogIdSet(selector_maceReset_demux_21);
      RouteTransportWrapperService::selectorId_resumeDeliver_demux_16 = new LogIdSet(selector_resumeDeliver_demux_16);
      RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_8 = new LogIdSet(selector_registerUniqueHandler_demux_8);
      RouteTransportWrapperService::selectorId_registerHandler_demux_9 = new LogIdSet(selector_registerHandler_demux_9);
      RouteTransportWrapperService::selectorId_downcall_route_1_transition = new LogIdSet(selector_downcall_route_1_transition);
      RouteTransportWrapperService::selectorId_messageError_upcall_2 = new LogIdSet(selector_messageError_upcall_2);
      RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_11 = new LogIdSet(selector_registerUniqueHandler_demux_11);
      RouteTransportWrapperService::selectorId_upcall_messageError_4_transition = new LogIdSet(selector_upcall_messageError_4_transition);
      RouteTransportWrapperService::selectorId_suspendDeliver_demux_14 = new LogIdSet(selector_suspendDeliver_demux_14);
      RouteTransportWrapperService::selectorId_suspendDeliver_downcall_1 = new LogIdSet(selector_suspendDeliver_downcall_1);
      RouteTransportWrapperService::selectorId_error_upcall_1 = new LogIdSet(selector_error_upcall_1);
      RouteTransportWrapperService::selectorId_route_downcall_6 = new LogIdSet(selector_route_downcall_6);
      RouteTransportWrapperService::selectorId_unregisterHandler_demux_7 = new LogIdSet(selector_unregisterHandler_demux_7);
      RouteTransportWrapperService::selectorId_maceExit_demux_20 = new LogIdSet(selector_maceExit_demux_20);
      RouteTransportWrapperService::selectorId_upcall_messageError_5_transition = new LogIdSet(selector_upcall_messageError_5_transition);
      RouteTransportWrapperService::selectorId_send_downcall_12 = new LogIdSet(selector_send_downcall_12);
      RouteTransportWrapperService::selectorId_error_demux_0 = new LogIdSet(selector_error_demux_0);
      RouteTransportWrapperService::selectorId_deliver_demux_1 = new LogIdSet(selector_deliver_demux_1);
      RouteTransportWrapperService::selectorId_route_downcall_5 = new LogIdSet(selector_route_downcall_5);
      RouteTransportWrapperService::selectorId_maceResume_demux_19 = new LogIdSet(selector_maceResume_demux_19);
      RouteTransportWrapperService::selectorId_route_downcall_11 = new LogIdSet(selector_route_downcall_11);
      RouteTransportWrapperService::selectorId_forward_upcall_3 = new LogIdSet(selector_forward_upcall_3);
      RouteTransportWrapperService::selectorId_route_downcall_7 = new LogIdSet(selector_route_downcall_7);
      RouteTransportWrapperService::selectorId_route_downcall_10 = new LogIdSet(selector_route_downcall_10);
      RouteTransportWrapperService::selectorId_resumeDeliver_demux_17 = new LogIdSet(selector_resumeDeliver_demux_17);
      RouteTransportWrapperService::selectorId_registerUniqueHandler_demux_5 = new LogIdSet(selector_registerUniqueHandler_demux_5);
      RouteTransportWrapperService::selectorId_route_demux_12 = new LogIdSet(selector_route_demux_12);
      RouteTransportWrapperService::selectorId_messageError_demux_2 = new LogIdSet(selector_messageError_demux_2);
      RouteTransportWrapperService::selectorId_deliver_upcall_0 = new LogIdSet(selector_deliver_upcall_0);
      RouteTransportWrapperService::selectorId_unregisterHandler_demux_4 = new LogIdSet(selector_unregisterHandler_demux_4);
      RouteTransportWrapperService::selectorId_maceInit_demux_18 = new LogIdSet(selector_maceInit_demux_18);
      RouteTransportWrapperService::selectorId_registerHandler_demux_6 = new LogIdSet(selector_registerHandler_demux_6);
      RouteTransportWrapperService::selectorId_hashState_demux_23 = new LogIdSet(selector_hashState_demux_23);
      RouteTransportWrapperService::selectorId_send_downcall_9 = new LogIdSet(selector_send_downcall_9);
      RouteTransportWrapperService::selectorId_unregisterHandler_demux_10 = new LogIdSet(selector_unregisterHandler_demux_10);
      RouteTransportWrapperService::selectorId_suspendDeliver_demux_15 = new LogIdSet(selector_suspendDeliver_demux_15);
      RouteTransportWrapperService::selectorId_route_downcall_4 = new LogIdSet(selector_route_downcall_4);
      RouteTransportWrapperService::selectorId_upcall_error_3_transition = new LogIdSet(selector_upcall_error_3_transition);
      RouteTransportWrapperService::selectorId_deliver_demux_24 = new LogIdSet(selector_deliver_demux_24);
      RouteTransportWrapperService::selectorId_suspendDeliver_downcall_0 = new LogIdSet(selector_suspendDeliver_downcall_0);
      RouteTransportWrapperService::selectorId_route_demux_13 = new LogIdSet(selector_route_demux_13);
      RouteTransportWrapperService::selectorId_send_downcall_8 = new LogIdSet(selector_send_downcall_8);
      RouteTransportWrapperService::selectorId_resumeDeliver_downcall_3 = new LogIdSet(selector_resumeDeliver_downcall_3);
      
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_route13", "route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_maceInit19", "maceInit()"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_maceReset22", "maceReset()"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_hashState24", "hashState() const"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_error25", "error( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_deliver26", "deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_messageError27", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_suspendDeliver0", "suspendDeliver(registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_suspendDeliver1", "suspendDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_resumeDeliver2", "resumeDeliver(registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_resumeDeliver3", "resumeDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_route4", "route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_route5", "route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_route6", "route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_route7", "route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_send8", "send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("RouteTransportWrapper_send9", "send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      
    }
  }
  //END Mace::Compiler::ServiceImpl::printRoutines
  
  //Timer Demux (and utility timer)
  //BEGIN Mace::Compiler::ServiceImpl::printTimerDemux
  //END Mace::Compiler::ServiceImpl::printTimerDemux
  
  //Load Protocol
  
  //BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol
  RouteServiceClass& configure_new_RouteTransportWrapper_Route(bool ___shared);
  TransportServiceClass& configure_new_RouteTransportWrapper_Transport(bool ___shared);
  
  void load_protocol() {
    StringSet attr = mace::makeStringSet("RouteTransportWrapper", ",");
    mace::ServiceFactory<RouteServiceClass>::registerService(&configure_new_RouteTransportWrapper_Route, "RouteTransportWrapper");
    mace::ServiceConfig<RouteServiceClass>::registerService("RouteTransportWrapper", attr);
    mace::ServiceFactory<TransportServiceClass>::registerService(&configure_new_RouteTransportWrapper_Transport, "RouteTransportWrapper");
    mace::ServiceConfig<TransportServiceClass>::registerService("RouteTransportWrapper", attr);
  }
  //END Mace::Compiler::ServiceImpl::printLoadProtocol
  
  //Constructors
  //BEGIN Mace::Compiler::ServiceImpl::printConstructor
  RouteServiceClass& real_new_RouteTransportWrapper_Route(TransportServiceClass& trans, bool ___shared) {
    return *(new RouteTransportWrapperService(trans,___shared));
  }
  TransportServiceClass& real_new_RouteTransportWrapper_Transport(TransportServiceClass& trans, bool ___shared) {
    return *(new RouteTransportWrapperService(trans,___shared));
  }
  RouteTransportWrapperService::RouteTransportWrapperService(TransportServiceClass& __trans, bool ___shared) :
  //(
      BaseMaceService(), __inited(0), _actual_state(init), state(_actual_state),
      _trans(__trans), trans(-1), __local_address(MaceKey::null)
      {
        initializeSelectors();
        __local_address = computeLocalAddress();
        
        if (___shared) {
          mace::ServiceFactory<RouteServiceClass>::registerInstance("RouteTransportWrapper", this);
          mace::ServiceFactory<TransportServiceClass>::registerInstance("RouteTransportWrapper", this);
        }
        ServiceClass::addToServiceList(*this);
        
        
        ADD_SELECTORS("RouteTransportWrapper::(constructor)");
        macedbg(1) << "Created queued instance " << this << Log::endl;
      }
      //)
  RouteTransportWrapperService::RouteTransportWrapperService(const RouteTransportWrapperService& _sv) :
  //(
      BaseMaceService(false), __inited(_sv.__inited), _actual_state(_sv.state), state(_actual_state),
      _trans(_sv._trans), trans(_sv.trans){
        ADD_SELECTORS("RouteTransportWrapper::(constructor)");
        macedbg(1) << "Created non-queued instance " << this << Log::endl;
      }
      //)
  //END Mace::Compiler::ServiceImpl::printConstructor
  
  //Destructor
  RouteTransportWrapperService::~RouteTransportWrapperService() {
    
    mace::ServiceFactory<RouteServiceClass>::unregisterInstance("RouteTransportWrapper", this);
    mace::ServiceFactory<TransportServiceClass>::unregisterInstance("RouteTransportWrapper", this);
  }
  
  // Methods for snapshotting...
  void RouteTransportWrapperService::snapshot(const uint64_t& ver) const {
    ADD_SELECTORS("RouteTransportWrapperService::snapshot");
    //Assumes state is locked.
    RouteTransportWrapperService* _sv = new RouteTransportWrapperService(*this);
    macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
    ASSERT(versionMap.empty() || versionMap.back().first < ver);
    versionMap.push_back(std::make_pair(ver,_sv));
  }
  void RouteTransportWrapperService::snapshotRelease(const uint64_t& ver) const {
    ADD_SELECTORS("RouteTransportWrapperService::snapshot");
    //Assumes state is locked.
    while (!versionMap.empty() && versionMap.front().first < ver) {
      macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
      delete versionMap.front().second;
      versionMap.pop_front();
    }
  }
  
  
  const ServiceType::state_type& RouteTransportWrapperService::read_state() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return state;
    }
    else if (currentMode == mace::AgentLock::READ_MODE) {
      VersionServiceMap::const_iterator i = versionMap.begin();
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return i->second->state;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  
  //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
  void RouteTransportWrapperService::dumpState(LOGLOGTYPE& logger) const {
    logger << "state_dump: " << *this << std::endl;
    return;
  }
  
  void RouteTransportWrapperService::print(mace::PrintNode& __pr, const std::string& name) const {
    mace::PrintNode __printer(name, "RouteTransportWrapperService");
    const char* __pr_stateName = getStateName(state);
    mace::printItem(__printer, "state", &__pr_stateName);
    
    
    __pr.addChild(__printer);
    return;
  }
  
  void RouteTransportWrapperService::print(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    
    
    __out << std::endl;
    if(_printLower) {
      __out  << _trans << std::endl;
    }
    return;
  }
  void RouteTransportWrapperService::printState(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    
    
    __out << std::endl;
    if(_printLower) {
      _trans.printState(__out);
    }
    return;
  }
  
  void RouteTransportWrapperService::sqlize(mace::LogNode* __node) const {
    int _index = __node->nextIndex();
    if (_index == 0) {
      std::ostringstream __out;
      __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, state TEXT);" << std::endl;
      __node->children = NULL;
      Log::logSqlCreate(__out.str(), __node);
    }
    std::ostringstream __out;
    __out << __node->logId << "\t" << _index << "\t" << getStateName(state);
    __out << std::endl;
    ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
    
  }
  
  void RouteTransportWrapperService::serialize(std::string& __str) const {
    mace::serialize(__str, &state);
    
    
    
    mace::serialize( __str, &__local_address );
    return;
  }
  
  int RouteTransportWrapperService::deserialize(std::istream& __in) throw(SerializationException){
    int serializedByteSize = 0;
    serializedByteSize += mace::deserialize(__in, &_actual_state);
    
    
    
    
    MaceKey oldLocalAddress;
    serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
    updateInternalContext( oldLocalAddress, __local_address );
    
    return serializedByteSize;
  }
  void RouteTransportWrapperService::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
    
  }
  
  void RouteTransportWrapperService::processDeferred() {  }
  const char* RouteTransportWrapperService::getMessageName(uint8_t messageType) const {
    switch(messageType) {
      case Data::messageType: return "RouteTransportWrapper::Data";
      default: ASSERT(false); return "INVALID MESSAGE NUMBER";
    }
  }
  void RouteTransportWrapperService::changeState(state_type stateNum, int selectorId) {
    _actual_state = stateNum;
    Log::logf(selectorId, "FSM: state changed to %s", getStateName(state));
  }
  const char* RouteTransportWrapperService::getStateName(state_type state) const {
    switch(static_cast<uint64_t>(state)) {
      case init: return "RouteTransportWrapper::init";
      case exited: return "RouteTransportWrapper::exited";
      default: ASSERT(false); return "INVALID STATE NUMBER";
    }
  }
  
  //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
  //BEGIN Mace::Compiler::ServiceImpl::printAPIDemux
  bool RouteTransportWrapperService::route(
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 916 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_route_demux_12
    #define selectorId selectorId_route_demux_12
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    bool __test = shouldLog_route13(dest, s, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route13Dummy(dest, s, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    } else
    if(guard_downcall_1_route(dest,s,rid)) {
      macecompiler(1) << "Firing Transition downcall route [ guards : (true) ] bool route( const MaceKey& dest,  const std::string& msg, registration_uid_t regId)" << Log::endl;
      
      
      
      return mace::logVal( downcall_1_route(dest,s,rid), selectorId->compiler, "rv_bool");
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 972 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::route(
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& src
#line 983 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 987 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 991 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 995 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_route_demux_13
    #define selectorId selectorId_route_demux_13
    ADD_LOG_BACKING
    bool __test = shouldLog_route14(src, dest, s, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "route(" << "[src=";
          mace::printItem(macecompiler(0), &src);
          macecompiler(0) << "]"
          << "[dest=";
          mace::printItem(macecompiler(0), &dest);
          macecompiler(0) << "]"
          << "[s=";
          mace::printItem(macecompiler(0), &s);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    macecompiler(1) << "COMPILER RUNTIME NOTICE: route called, but not implemented" << Log::endl;
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      {
        return false;
      }
#line 1040 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_suspendDeliver_demux_14
    #define selectorId selectorId_suspendDeliver_demux_14
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver15(rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "suspendDeliver(" << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    macecompiler(1) << "COMPILER RUNTIME NOTICE: suspendDeliver called, but not implemented" << Log::endl;
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 1085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1096 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_suspendDeliver_demux_15
    #define selectorId selectorId_suspendDeliver_demux_15
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver16(dest, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "suspendDeliver(" << "[dest=";
          mace::printItem(macecompiler(0), &dest);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    macecompiler(1) << "COMPILER RUNTIME NOTICE: suspendDeliver called, but not implemented" << Log::endl;
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 1137 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_resumeDeliver_demux_16
    #define selectorId selectorId_resumeDeliver_demux_16
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver17(rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "resumeDeliver(" << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    macecompiler(1) << "COMPILER RUNTIME NOTICE: resumeDeliver called, but not implemented" << Log::endl;
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 1182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1193 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_resumeDeliver_demux_17
    #define selectorId selectorId_resumeDeliver_demux_17
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver18(dest, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "resumeDeliver(" << "[dest=";
          mace::printItem(macecompiler(0), &dest);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    macecompiler(1) << "COMPILER RUNTIME NOTICE: resumeDeliver called, but not implemented" << Log::endl;
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 1234 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::maceInit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceInit_demux_18
    #define selectorId selectorId_maceInit_demux_18
    ADD_LOG_BACKING
    bool __test = shouldLog_maceInit19();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, maceInit19Dummy(), 0);
      }
    }
    
    
    
    if(__inited++ == 0) {
      //TODO: start utility timer as necessary
      
      _trans.maceInit();
      if (trans == -1) {
        trans  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
      }
      
      
      macecompiler(0) << "Registering handler with regId " << trans << " and type ReceiveDataHandler for service variable trans" << Log::endl;
      _trans.registerHandler((ReceiveDataHandler&)*this, trans);
      macecompiler(0) << "Registering handler with regId " << trans << " and type NetworkErrorHandler for service variable trans" << Log::endl;
      _trans.registerHandler((NetworkErrorHandler&)*this, trans);
      
      if(state == exited) {
        
        #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 1287 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
      } else
      if(guard_downcall_0_maceInit()) {
        macecompiler(1) << "Firing Transition downcall maceInit [ guards : (true) ] void maceInit()" << Log::endl;
        
        
        
        downcall_0_maceInit();
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 1302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::maceResume() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceResume_demux_19
    #define selectorId selectorId_maceResume_demux_19
    ADD_LOG_BACKING
    bool __test = shouldLog_maceResume20();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "maceResume(" << ")" << Log::endl;
    }
    
    
    
    if(__inited++ == 0) {
      //TODO: start utility timer as necessary
      
      _trans.maceInit();
      if (trans == -1) {
        trans  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
      }
      
      
      macecompiler(0) << "Registering handler with regId " << trans << " and type ReceiveDataHandler for service variable trans" << Log::endl;
      _trans.registerHandler((ReceiveDataHandler&)*this, trans);
      macecompiler(0) << "Registering handler with regId " << trans << " and type NetworkErrorHandler for service variable trans" << Log::endl;
      _trans.registerHandler((NetworkErrorHandler&)*this, trans);
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: maceResume called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 1357 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::maceExit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceExit_demux_20
    #define selectorId selectorId_maceExit_demux_20
    ADD_LOG_BACKING
    bool __test = shouldLog_maceExit21();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "maceExit(" << ")" << Log::endl;
    }
    
    
    
    if(--__inited == 0) {
      macecompiler(1) << "COMPILER RUNTIME NOTICE: maceExit called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 1399 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
      }
      
      //TODO: stop utility timer as necessary
      _actual_state = exited;
      
      _trans.unregisterHandler((ReceiveDataHandler&)*this, trans);
      _trans.unregisterHandler((NetworkErrorHandler&)*this, trans);
      
      _trans.maceExit();
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::maceReset() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceReset_demux_21
    #define selectorId selectorId_maceReset_demux_21
    ADD_LOG_BACKING
    bool __test = shouldLog_maceReset22();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, maceReset22Dummy(), 0);
      }
    }
    
    
    {
      
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
      { }
#line 1447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    //TODO: stop utility timer as necessary
    _actual_state = init;
    
    map_ReceiveDataHandler.clear();
    map_NetworkErrorHandler.clear();
    map_ForwardDataHandler.clear();
    
    _trans.maceReset();
    
    __inited = 0;
    
    #undef selector
    #undef selectorId
    
  }
  const MaceKey& RouteTransportWrapperService::localAddress() const {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_localAddress_demux_22
    #define selectorId selectorId_localAddress_demux_22
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      { return __local_address; }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t RouteTransportWrapperService::hashState() const {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_hashState_demux_23
    #define selectorId selectorId_hashState_demux_23
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    bool __test = shouldLog_hashState24();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, hashState24Dummy(), 0);
      }
    }
    
    
    {
      {
        static hash_string hasher;
        std::string s = toString();
        macedbg(0) << s << Log::endl;
        return hasher(s);
      }
    }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printAPIDemux
  //BEGIN Mace::Compiler::ServiceImpl::printAsyncDemux
  //END Mace::Compiler::ServiceImpl::printAsyncDemux
  //BEGIN Mace::Compiler::ServiceImpl::printSyncDemux
  //END Mace::Compiler::ServiceImpl::printSyncDemux
  //BEGIN Mace::Compiler::ServiceImpl::printAspectDemux
  //END Mace::Compiler::ServiceImpl::printAspectDemux
  //BEGIN Mace::Compiler::ServiceImpl::printHandlerRegistrations
  registration_uid_t RouteTransportWrapperService::registerHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ReceiveDataHandler.find(regId) == map_ReceiveDataHandler.end());
    map_ReceiveDataHandler[regId] = &handler;
    return regId;
  }
  
  void RouteTransportWrapperService::registerUniqueHandler(ReceiveDataHandler& handler) {
    ASSERT(map_ReceiveDataHandler.empty());
    map_ReceiveDataHandler[-1] = &handler;
  }
  
  void RouteTransportWrapperService::unregisterHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    ASSERT(map_ReceiveDataHandler[regId] == &handler);
    map_ReceiveDataHandler.erase(regId);
  }
  registration_uid_t RouteTransportWrapperService::registerHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_NetworkErrorHandler.find(regId) == map_NetworkErrorHandler.end());
    map_NetworkErrorHandler[regId] = &handler;
    return regId;
  }
  
  void RouteTransportWrapperService::registerUniqueHandler(NetworkErrorHandler& handler) {
    ASSERT(map_NetworkErrorHandler.empty());
    map_NetworkErrorHandler[-1] = &handler;
  }
  
  void RouteTransportWrapperService::unregisterHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    ASSERT(map_NetworkErrorHandler[regId] == &handler);
    map_NetworkErrorHandler.erase(regId);
  }
  registration_uid_t RouteTransportWrapperService::registerHandler(ForwardDataHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ForwardDataHandler.find(regId) == map_ForwardDataHandler.end());
    map_ForwardDataHandler[regId] = &handler;
    return regId;
  }
  
  void RouteTransportWrapperService::registerUniqueHandler(ForwardDataHandler& handler) {
    ASSERT(map_ForwardDataHandler.empty());
    map_ForwardDataHandler[-1] = &handler;
  }
  
  void RouteTransportWrapperService::unregisterHandler(ForwardDataHandler& handler, registration_uid_t regId) {
    ASSERT(map_ForwardDataHandler[regId] == &handler);
    map_ForwardDataHandler.erase(regId);
  }
  //END Mace::Compiler::ServiceImpl::printHandlerRegistrations
  
  //Handler demux (uses handlers)
  //BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux
  void RouteTransportWrapperService::error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 1600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 1604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 1608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 1612 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_error_demux_0
    #define selectorId selectorId_error_demux_0
    ADD_LOG_BACKING
    //locking=" .1.";
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    bool __test = shouldLog_error25(nodeId, errorCode, message, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, error25Dummy(nodeId, errorCode, message, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1646 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    } else
    if(guard_upcall_3_error(nodeId,errorCode,message,rid)) {
      macecompiler(1) << "Firing Transition upcall error [ guards : (true) ] void error( const MaceKey& nodeId, TransportError::type error_code,  const std::string& m, registration_uid_t registrationUid)" << Log::endl;
      
      
      
      upcall_3_error(nodeId,errorCode,message,rid);
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1661 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& source
#line 1672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& destination
#line 1676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& s_deserialized
#line 1680 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 1684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_deliver_demux_1
    #define selectorId selectorId_deliver_demux_1
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    bool __test = shouldLog_deliver26(source, destination, s_deserialized, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, deliver26Dummy(source, destination, s_deserialized, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 1717 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    } else
    if(guard_upcall_2_deliver(source,destination,s_deserialized)) {
      macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Data& msg)" << Log::endl;
      
      
      
      upcall_2_deliver(source,destination,s_deserialized);
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 1732 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::messageError(
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 1743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type errorCode
#line 1747 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& message_deserialized
#line 1751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 1755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_messageError_demux_2
    #define selectorId selectorId_messageError_demux_2
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    bool __test = shouldLog_messageError27(dest, errorCode, message_deserialized, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, messageError27Dummy(dest, errorCode, message_deserialized, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1788 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    } else
    if(guard_upcall_4_messageError(dest,errorCode,message_deserialized,rid)) {
      macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type error_code,  const Data& msg, registration_uid_t regId)" << Log::endl;
      
      
      
      upcall_4_messageError(dest,errorCode,message_deserialized,rid);
    } else
    if(guard_upcall_5_messageError(dest,errorCode,message_deserialized,rid)) {
      macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)" << Log::endl;
      
      
      
      upcall_5_messageError(dest,errorCode,message_deserialized,rid);
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printHandlerDemux
  
  //Downcall helpers (uses)
  //BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers
  
  MaceKey RouteTransportWrapperService::downcall_localAddress() const {
    return _trans.localAddress();
  }
  const MaceKey& RouteTransportWrapperService::downcall_localAddress(const registration_uid_t& rid) const {
    
    if (&rid == &trans) {
      return _trans.localAddress();
    }
    
    if (rid == trans) {
      return _trans.localAddress();
    }
    return MaceKey::null;
  }
  void RouteTransportWrapperService::downcall_suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_0
    #define selectorId selectorId_suspendDeliver_downcall_0
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver0(rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, suspendDeliver0Dummy(rid), 0);
      }
    }
    
    
    
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      _trans.suspendDeliver(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::downcall_suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_1
    #define selectorId selectorId_suspendDeliver_downcall_1
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver1(dest, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, suspendDeliver1Dummy(dest, rid), 0);
      }
    }
    
    
    
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      _trans.suspendDeliver(dest,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::downcall_resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1926 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_2
    #define selectorId selectorId_resumeDeliver_downcall_2
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver2(rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, resumeDeliver2Dummy(rid), 0);
      }
    }
    
    
    
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      _trans.resumeDeliver(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::downcall_resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1971 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_3
    #define selectorId selectorId_resumeDeliver_downcall_3
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver3(dest, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, resumeDeliver3Dummy(dest, rid), 0);
      }
    }
    
    
    
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      _trans.resumeDeliver(dest,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_4
    #define selectorId selectorId_route_downcall_4
    ADD_LOG_BACKING
    bool __test = shouldLog_route4(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route4Dummy(), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2071 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_5
    #define selectorId selectorId_route_downcall_5
    ADD_LOG_BACKING
    bool __test = shouldLog_route5(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route5Dummy(dest, s_deserialized, rid), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& src
#line 2114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2126 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_6
    #define selectorId selectorId_route_downcall_6
    ADD_LOG_BACKING
    bool __test = shouldLog_route6(src, dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route6Dummy(), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& src
#line 2169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2177 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_7
    #define selectorId selectorId_route_downcall_7
    ADD_LOG_BACKING
    bool __test = shouldLog_route7(src, dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route7Dummy(src, dest, s_deserialized, rid), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t RouteTransportWrapperService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2228 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2232 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_8
    #define selectorId selectorId_send_downcall_8
    ADD_LOG_BACKING
    bool __test = shouldLog_send8(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, send8Dummy(), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t RouteTransportWrapperService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2275 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2279 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2283 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_9
    #define selectorId selectorId_send_downcall_9
    ADD_LOG_BACKING
    bool __test = shouldLog_send9(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, send9Dummy(dest, s_deserialized, rid), 0);
      }
    }
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = trans; }
    
    if(rid == trans) {
      return _trans.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printDowncallHelpers
  
  //Upcall helpers (provides handlers)
  //BEGIN Mace::Compiler::ServiceImpl::printUpcallHelpers
  void RouteTransportWrapperService::upcall_deliver(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& source
#line 2330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& destination
#line 2334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const std::string& s
#line 2338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 2342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_deliver_upcall_0
    #define selectorId selectorId_deliver_upcall_0
    ADD_LOG_BACKING
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "deliver(" << "[source=";
          mace::printItem(macecompiler(0), &source);
          macecompiler(0) << "]"
          << "[destination=";
          mace::printItem(macecompiler(0), &destination);
          macecompiler(0) << "]"
          << "[s=";
          mace::printItem(macecompiler(0), &s);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    
    
    
    maptype_ReceiveDataHandler::iterator iter = map_ReceiveDataHandler.find(rid);
    if(iter == map_ReceiveDataHandler.end()) {
      maceWarn("No ReceiveDataHandler registered with uid %"PRIi32" for upcall deliver!", rid);
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 2385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    else {
      iter->second->deliver(source,destination,s,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::upcall_error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 2400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 2404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 2408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 2412 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_error_upcall_1
    #define selectorId selectorId_error_upcall_1
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "error(" << "[nodeId=";
          mace::printItem(macecompiler(0), &nodeId);
          macecompiler(0) << "]"
          << "[errorCode=";
          mace::printItem(macecompiler(0), &errorCode);
          macecompiler(0) << "]"
          << "[message=";
          mace::printItem(macecompiler(0), &message);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    
    
    
    maptype_NetworkErrorHandler::iterator iter = map_NetworkErrorHandler.find(rid);
    if(iter == map_NetworkErrorHandler.end()) {
      maceWarn("No NetworkErrorHandler registered with uid %"PRIi32" for upcall error!", rid);
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 2457 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    else {
      iter->second->error(nodeId,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::upcall_messageError(
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& dest
#line 2472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 2476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 2480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 2484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageError_upcall_2
    #define selectorId selectorId_messageError_upcall_2
    ADD_LOG_BACKING
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "messageError(" << "[dest=";
          mace::printItem(macecompiler(0), &dest);
          macecompiler(0) << "]"
          << "[errorCode=";
          mace::printItem(macecompiler(0), &errorCode);
          macecompiler(0) << "]"
          << "[message=";
          mace::printItem(macecompiler(0), &message);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    
    
    
    maptype_NetworkErrorHandler::iterator iter = map_NetworkErrorHandler.find(rid);
    if(iter == map_NetworkErrorHandler.end()) {
      maceWarn("No NetworkErrorHandler registered with uid %"PRIi32" for upcall messageError!", rid);
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 2527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    else {
      iter->second->messageError(dest,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  bool RouteTransportWrapperService::upcall_forward(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& source
#line 2542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& destination
#line 2546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      MaceKey& nextHop
#line 2550 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const std::string& s
#line 2554 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      registration_uid_t rid
#line 2558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_forward_upcall_3
    #define selectorId selectorId_forward_upcall_3
    ADD_LOG_BACKING
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if(!macecompiler(0).isNoop()) {
      macecompiler(0) << "forward(" << "[source=";
          mace::printItem(macecompiler(0), &source);
          macecompiler(0) << "]"
          << "[destination=";
          mace::printItem(macecompiler(0), &destination);
          macecompiler(0) << "]"
          << "[nextHop=";
          mace::printItem(macecompiler(0), &nextHop);
          macecompiler(0) << "]"
          << "[s=";
          mace::printItem(macecompiler(0), &s);
          macecompiler(0) << "]"
          << "[rid=";
          mace::printItem(macecompiler(0), &rid);
          macecompiler(0) << "]"
          << ")" << Log::endl;
    }
    
    
    
    
    
    maptype_ForwardDataHandler::iterator iter = map_ForwardDataHandler.find(rid);
    if(iter == map_ForwardDataHandler.end()) {
      maceWarn("No ForwardDataHandler registered with uid %"PRIi32" for upcall forward!", rid);
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      { return true; }
#line 2604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      
    }
    else {
      return iter->second->forward(source,destination,nextHop,s,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printUpcallHelpers
  
  //Async helpers
  
  //Serial Helper Demux
  //BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux
  void RouteTransportWrapperService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& source
#line 2625 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& destination
#line 2629 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const std::string& s
#line 2633 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 2637 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_deliver_demux_24
    #define selectorId selectorId_deliver_demux_24
    ADD_LOG_BACKING
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    
    //TODO: try/catch Serialize
    
    uint8_t msgNum_s = Message::getType(s);
    //TODO -- trace num
    
    switch(msgNum_s) {
      
      case Data::messageType: {
        Data s_deserialized;
        s_deserialized.deserializeStr(s);
        //TODO -- trace msg
        
        deliver(source,destination,s_deserialized,rid);
        
      }
      break;
      default: {
        maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 2676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
        ABORT("INVALID MESSAGE NUMBER");
      }
      break;
    }
    
    #undef selector
    #undef selectorId
    
  }
  void RouteTransportWrapperService::messageError(
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const MaceKey& dest
#line 2690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      TransportError::type errorCode
#line 2694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      const std::string& message
#line 2698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
      registration_uid_t rid
#line 2702 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageError_demux_25
    #define selectorId selectorId_messageError_demux_25
    ADD_LOG_BACKING
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    
    //TODO: try/catch Serialize
    
    uint8_t msgNum_message = Message::getType(message);
    //TODO -- trace num
    
    switch(msgNum_message) {
      
      case Data::messageType: {
        Data message_deserialized;
        message_deserialized.deserializeStr(message);
        //TODO -- trace msg
        
        messageError(dest,errorCode,message_deserialized,rid);
        
      }
      break;
      default: {
        maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 2741 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper.cc"
        
        ABORT("INVALID MESSAGE NUMBER");
      }
      break;
    }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printSerialHelperDemux
  
  //Model checking safety methods
  
  
  //Model checking liveness methods
  
  
} // end namespace

//END Mace::Compiler::ServiceImpl::printCCFile
