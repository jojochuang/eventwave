/*********************************************
*  DeferredRouteTransportWrapper main source file
*  Mace generated on:
*  Tue Apr 10 10:09:47 2012
*********************************************/
//BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"

#include "DeferredRouteTransportWrapper.h"
#include "DeferredRouteTransportWrapper-macros.h"
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

bool operator==(const mace::map<int, mace::map<int, DeferredRouteTransportWrapper_namespace::DeferredRouteTransportWrapperService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, DeferredRouteTransportWrapper_namespace::DeferredRouteTransportWrapperService*, mace::SoftState>::const_iterator& rhs) {
  return lhs->second == rhs;
}
bool operator==(const mace::map<int, DeferredRouteTransportWrapper_namespace::DeferredRouteTransportWrapperService*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, DeferredRouteTransportWrapper_namespace::DeferredRouteTransportWrapperService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
  return lhs == rhs->second;
}
namespace mace {
  template<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;
}
namespace DeferredRouteTransportWrapper_namespace {
  mace::LogNode* DeferredRouteTransportWrapperService::rootLogNode = NULL;
  //    mace::LogNode* DeferredRouteTransportWrapperDummy::rootLogNode = NULL;
  //Selector Constants
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //const std::string selector_upcall_deliver_2_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_upcall_deliver_2_transition;
  //const std::string selector_registerHandler_demux_3;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_3;
  //const std::string selector_resumeDeliver_downcall_2;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_resumeDeliver_downcall_2;
  //const std::string selector_downcall_maceInit_0_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_downcall_maceInit_0_transition;
  //const std::string selector_messageError_demux_25;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_messageError_demux_25;
  //const std::string selector_localAddress_demux_22;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_localAddress_demux_22;
  //const std::string selector_maceReset_demux_21;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_maceReset_demux_21;
  //const std::string selector_resumeDeliver_demux_16;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_resumeDeliver_demux_16;
  //const std::string selector_registerUniqueHandler_demux_8;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_8;
  //const std::string selector_registerHandler_demux_9;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_9;
  //const std::string selector_commitCallBack_routine_0;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_commitCallBack_routine_0;
  //const std::string selector_downcall_route_1_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_downcall_route_1_transition;
  //const std::string selector_messageError_upcall_2;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_messageError_upcall_2;
  //const std::string selector_registerUniqueHandler_demux_11;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_11;
  //const std::string selector_upcall_messageError_4_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_upcall_messageError_4_transition;
  //const std::string selector_suspendDeliver_demux_14;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_suspendDeliver_demux_14;
  //const std::string selector_suspendDeliver_downcall_1;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_suspendDeliver_downcall_1;
  //const std::string selector_error_upcall_1;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_error_upcall_1;
  //const std::string selector_route_downcall_6;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_6;
  //const std::string selector_unregisterHandler_demux_7;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_7;
  //const std::string selector_maceExit_demux_20;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_maceExit_demux_20;
  //const std::string selector_upcall_messageError_5_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_upcall_messageError_5_transition;
  //const std::string selector_send_downcall_12;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_send_downcall_12;
  //const std::string selector_error_demux_0;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_error_demux_0;
  //const std::string selector_deliver_demux_1;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_deliver_demux_1;
  //const std::string selector_route_downcall_5;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_5;
  //const std::string selector_maceResume_demux_19;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_maceResume_demux_19;
  //const std::string selector_route_downcall_11;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_11;
  //const std::string selector_forward_upcall_3;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_forward_upcall_3;
  //const std::string selector_route_downcall_7;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_7;
  //const std::string selector_route_downcall_10;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_10;
  //const std::string selector_resumeDeliver_demux_17;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_resumeDeliver_demux_17;
  //const std::string selector_registerUniqueHandler_demux_5;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_5;
  //const std::string selector_route_demux_12;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_demux_12;
  //const std::string selector_messageError_demux_2;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_messageError_demux_2;
  //const std::string selector_deliver_upcall_0;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_deliver_upcall_0;
  //const std::string selector_unregisterHandler_demux_4;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_4;
  //const std::string selector_maceInit_demux_18;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_maceInit_demux_18;
  //const std::string selector_registerHandler_demux_6;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_6;
  //const std::string selector_hashState_demux_23;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_hashState_demux_23;
  //const std::string selector_send_downcall_9;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_send_downcall_9;
  //const std::string selector_unregisterHandler_demux_10;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_10;
  //const std::string selector_suspendDeliver_demux_15;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_suspendDeliver_demux_15;
  //const std::string selector_route_downcall_4;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_downcall_4;
  //const std::string selector_upcall_error_3_transition;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_upcall_error_3_transition;
  //const std::string selector_deliver_demux_24;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_deliver_demux_24;
  //const std::string selector_suspendDeliver_downcall_0;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_suspendDeliver_downcall_0;
  //const std::string selector_route_demux_13;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_route_demux_13;
  //const std::string selector_send_downcall_8;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_send_downcall_8;
  //const std::string selector_resumeDeliver_downcall_3;
  const LogIdSet* DeferredRouteTransportWrapperService::selectorId_resumeDeliver_downcall_3;
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //Change Tracker (optional)
  //BEGIN Mace::Compiler::ServiceImpl::printChangeTracker
  //END Mace::Compiler::ServiceImpl::printChangeTracker
  
  //service variable includes and uses
  
  
  //Transition and Guard Implementations
  //BEGIN Mace::Compiler::ServiceImpl::printTransitions
  bool DeferredRouteTransportWrapperService::guard_downcall_0_maceInit() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        true
#line 159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void DeferredRouteTransportWrapperService::downcall_0_maceInit() {
    #define selector selector_downcall_maceInit_0_transition
    #define selectorId selectorId_downcall_maceInit_0_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      me = localAddress();
      
      mace::SpecificCommitWrapper<DeferredRouteTransportWrapperService>* executor = new mace::SpecificCommitWrapper<DeferredRouteTransportWrapperService>(this, &DeferredRouteTransportWrapperService::commitCallBack);
      mace::GlobalCommit::registerCommitExecutor(executor);
      pthread_mutex_init(&deliverMutex, 0);
    }
#line 186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool DeferredRouteTransportWrapperService::guard_downcall_1_route(
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & dest
#line 194 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      std::string const & msg
#line 198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t const  regId
#line 202 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = -1;
    if(
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        true
#line 212 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  bool DeferredRouteTransportWrapperService::downcall_1_route(
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 221 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const std::string& msg
#line 225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t regId
#line 229 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    #define selector selector_downcall_route_1_transition
    #define selectorId selectorId_downcall_route_1_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = -1
    __eventContextType = -1;
    
    
    
    
    #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      MaceKey nextHop = dest;
      
      maceout << "comparing my ticket("<<ThreadStructure::myTicket()<<") with current ticket("<<ThreadStructure::current_ticket()<<")" << Log::endl;
      
      if(upcall_forward(me, dest, nextHop, msg, regId)) {
        // we actually have to return the value from downcall_route() but this is simply ignored on Bamboo.
        // So we are just simply using queue to save message.
        if( ThreadStructure::myTicket() == ThreadStructure::current_ticket() ) {
          downcall_route(nextHop, Data(me, dest, regId, msg));
        } else {
          maceout << "enqueuing message..." << Log::endl;
          
          ScopedLock sl(deliverMutex);
          
          queued.insert(mace::pair<uint64_t, Packet>(ThreadStructure::myTicket(), Packet(me, dest, regId, msg)));    // queue else
        }
      }
      return true;
      
    }
#line 265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool DeferredRouteTransportWrapperService::guard_upcall_2_deliver(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & src
#line 273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & dest
#line 277 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      Data const & msg
#line 281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = -1;
    if(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        true
#line 291 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void DeferredRouteTransportWrapperService::upcall_2_deliver(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& src
#line 300 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& msg
#line 308 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_deliver_2_transition
    #define selectorId selectorId_upcall_deliver_2_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = -1
    __eventContextType = -1;
    
    
    
    
    #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      upcall_deliver(msg.source, msg.dest, msg.data, msg.regId);
    }
#line 326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool DeferredRouteTransportWrapperService::guard_upcall_3_error(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & nodeId
#line 334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type const  error_code
#line 338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      std::string const & m
#line 342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t const  registrationUid
#line 346 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = -1;
    if(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        true
#line 356 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void DeferredRouteTransportWrapperService::upcall_3_error(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& nodeId
#line 365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type error_code
#line 369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const std::string& m
#line 373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t registrationUid
#line 377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_error_3_transition
    #define selectorId selectorId_upcall_error_3_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = -1
    __eventContextType = -1;
    
    
    
    
    #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      upcallAllVoid(error, nodeId, error_code, m);
    }
#line 395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool DeferredRouteTransportWrapperService::guard_upcall_4_messageError(
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & dest
#line 403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type const  error_code
#line 407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      Data const & msg
#line 411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t const  regId
#line 415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = -1;
    if(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        true
#line 425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void DeferredRouteTransportWrapperService::upcall_4_messageError(
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 434 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type error_code
#line 438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& msg
#line 442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t regId
#line 446 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    #define selector selector_upcall_messageError_4_transition
    #define selectorId selectorId_upcall_messageError_4_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = -1
    __eventContextType = -1;
    
    
    
    
    #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      upcall_messageError(msg.dest, error_code, msg.data, msg.regId);
    }
#line 464 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  bool DeferredRouteTransportWrapperService::guard_upcall_5_messageError(
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      MaceKey const & dest
#line 472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type const  errorCode
#line 476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      Data const & message_deserialized
#line 480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t const  rid
#line 484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        true
#line 494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    ) {
      return true;
    }
    return false;
  }
  void DeferredRouteTransportWrapperService::upcall_5_messageError(
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 503 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type errorCode
#line 507 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& message_deserialized
#line 511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
  }
  //END Mace::Compiler::ServiceImpl::printTransitions
  
  //Structured Logging Functions
  mace::LogNode* route14Dummy::rootLogNode = NULL;
  mace::LogNode* maceInit20Dummy::rootLogNode = NULL;
  mace::LogNode* maceReset23Dummy::rootLogNode = NULL;
  mace::LogNode* hashState25Dummy::rootLogNode = NULL;
  mace::LogNode* error26Dummy::rootLogNode = NULL;
  mace::LogNode* deliver27Dummy::rootLogNode = NULL;
  mace::LogNode* messageError28Dummy::rootLogNode = NULL;
  mace::LogNode* suspendDeliver1Dummy::rootLogNode = NULL;
  mace::LogNode* suspendDeliver2Dummy::rootLogNode = NULL;
  mace::LogNode* resumeDeliver3Dummy::rootLogNode = NULL;
  mace::LogNode* resumeDeliver4Dummy::rootLogNode = NULL;
  mace::LogNode* route5Dummy::rootLogNode = NULL;
  mace::LogNode* route6Dummy::rootLogNode = NULL;
  mace::LogNode* route7Dummy::rootLogNode = NULL;
  mace::LogNode* route8Dummy::rootLogNode = NULL;
  mace::LogNode* send9Dummy::rootLogNode = NULL;
  mace::LogNode* send10Dummy::rootLogNode = NULL;
  mace::LogNode* commitCallBack0Dummy::rootLogNode = NULL;
  // logging funcs
  bool DeferredRouteTransportWrapperService::shouldLog_route14( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_route15( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_suspendDeliver16(registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_suspendDeliver17( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_resumeDeliver18(registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_resumeDeliver19( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_maceInit20() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_maceResume21() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_maceExit22() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_maceReset23() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_localAddress24() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_hashState25() const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_error26( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_deliver27( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_messageError28( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_suspendDeliver1(registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_suspendDeliver2( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_resumeDeliver3(registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_resumeDeliver4( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_route5( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_route6( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_route7( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_route8( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_send9( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_send10( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool DeferredRouteTransportWrapperService::shouldLog_commitCallBack0(uint64_t myTicket) const {
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
      DeferredRouteTransportWrapperService::selectorId_upcall_deliver_2_transition = new LogIdSet(selector_upcall_deliver_2_transition);
      DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_3 = new LogIdSet(selector_registerHandler_demux_3);
      DeferredRouteTransportWrapperService::selectorId_resumeDeliver_downcall_2 = new LogIdSet(selector_resumeDeliver_downcall_2);
      DeferredRouteTransportWrapperService::selectorId_downcall_maceInit_0_transition = new LogIdSet(selector_downcall_maceInit_0_transition);
      DeferredRouteTransportWrapperService::selectorId_messageError_demux_25 = new LogIdSet(selector_messageError_demux_25);
      DeferredRouteTransportWrapperService::selectorId_localAddress_demux_22 = new LogIdSet(selector_localAddress_demux_22);
      DeferredRouteTransportWrapperService::selectorId_maceReset_demux_21 = new LogIdSet(selector_maceReset_demux_21);
      DeferredRouteTransportWrapperService::selectorId_resumeDeliver_demux_16 = new LogIdSet(selector_resumeDeliver_demux_16);
      DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_8 = new LogIdSet(selector_registerUniqueHandler_demux_8);
      DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_9 = new LogIdSet(selector_registerHandler_demux_9);
      DeferredRouteTransportWrapperService::selectorId_commitCallBack_routine_0 = new LogIdSet(selector_commitCallBack_routine_0);
      DeferredRouteTransportWrapperService::selectorId_downcall_route_1_transition = new LogIdSet(selector_downcall_route_1_transition);
      DeferredRouteTransportWrapperService::selectorId_messageError_upcall_2 = new LogIdSet(selector_messageError_upcall_2);
      DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_11 = new LogIdSet(selector_registerUniqueHandler_demux_11);
      DeferredRouteTransportWrapperService::selectorId_upcall_messageError_4_transition = new LogIdSet(selector_upcall_messageError_4_transition);
      DeferredRouteTransportWrapperService::selectorId_suspendDeliver_demux_14 = new LogIdSet(selector_suspendDeliver_demux_14);
      DeferredRouteTransportWrapperService::selectorId_suspendDeliver_downcall_1 = new LogIdSet(selector_suspendDeliver_downcall_1);
      DeferredRouteTransportWrapperService::selectorId_error_upcall_1 = new LogIdSet(selector_error_upcall_1);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_6 = new LogIdSet(selector_route_downcall_6);
      DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_7 = new LogIdSet(selector_unregisterHandler_demux_7);
      DeferredRouteTransportWrapperService::selectorId_maceExit_demux_20 = new LogIdSet(selector_maceExit_demux_20);
      DeferredRouteTransportWrapperService::selectorId_upcall_messageError_5_transition = new LogIdSet(selector_upcall_messageError_5_transition);
      DeferredRouteTransportWrapperService::selectorId_send_downcall_12 = new LogIdSet(selector_send_downcall_12);
      DeferredRouteTransportWrapperService::selectorId_error_demux_0 = new LogIdSet(selector_error_demux_0);
      DeferredRouteTransportWrapperService::selectorId_deliver_demux_1 = new LogIdSet(selector_deliver_demux_1);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_5 = new LogIdSet(selector_route_downcall_5);
      DeferredRouteTransportWrapperService::selectorId_maceResume_demux_19 = new LogIdSet(selector_maceResume_demux_19);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_11 = new LogIdSet(selector_route_downcall_11);
      DeferredRouteTransportWrapperService::selectorId_forward_upcall_3 = new LogIdSet(selector_forward_upcall_3);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_7 = new LogIdSet(selector_route_downcall_7);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_10 = new LogIdSet(selector_route_downcall_10);
      DeferredRouteTransportWrapperService::selectorId_resumeDeliver_demux_17 = new LogIdSet(selector_resumeDeliver_demux_17);
      DeferredRouteTransportWrapperService::selectorId_registerUniqueHandler_demux_5 = new LogIdSet(selector_registerUniqueHandler_demux_5);
      DeferredRouteTransportWrapperService::selectorId_route_demux_12 = new LogIdSet(selector_route_demux_12);
      DeferredRouteTransportWrapperService::selectorId_messageError_demux_2 = new LogIdSet(selector_messageError_demux_2);
      DeferredRouteTransportWrapperService::selectorId_deliver_upcall_0 = new LogIdSet(selector_deliver_upcall_0);
      DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_4 = new LogIdSet(selector_unregisterHandler_demux_4);
      DeferredRouteTransportWrapperService::selectorId_maceInit_demux_18 = new LogIdSet(selector_maceInit_demux_18);
      DeferredRouteTransportWrapperService::selectorId_registerHandler_demux_6 = new LogIdSet(selector_registerHandler_demux_6);
      DeferredRouteTransportWrapperService::selectorId_hashState_demux_23 = new LogIdSet(selector_hashState_demux_23);
      DeferredRouteTransportWrapperService::selectorId_send_downcall_9 = new LogIdSet(selector_send_downcall_9);
      DeferredRouteTransportWrapperService::selectorId_unregisterHandler_demux_10 = new LogIdSet(selector_unregisterHandler_demux_10);
      DeferredRouteTransportWrapperService::selectorId_suspendDeliver_demux_15 = new LogIdSet(selector_suspendDeliver_demux_15);
      DeferredRouteTransportWrapperService::selectorId_route_downcall_4 = new LogIdSet(selector_route_downcall_4);
      DeferredRouteTransportWrapperService::selectorId_upcall_error_3_transition = new LogIdSet(selector_upcall_error_3_transition);
      DeferredRouteTransportWrapperService::selectorId_deliver_demux_24 = new LogIdSet(selector_deliver_demux_24);
      DeferredRouteTransportWrapperService::selectorId_suspendDeliver_downcall_0 = new LogIdSet(selector_suspendDeliver_downcall_0);
      DeferredRouteTransportWrapperService::selectorId_route_demux_13 = new LogIdSet(selector_route_demux_13);
      DeferredRouteTransportWrapperService::selectorId_send_downcall_8 = new LogIdSet(selector_send_downcall_8);
      DeferredRouteTransportWrapperService::selectorId_resumeDeliver_downcall_3 = new LogIdSet(selector_resumeDeliver_downcall_3);
      
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_route14", "route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_maceInit20", "maceInit()"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_maceReset23", "maceReset()"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_hashState25", "hashState() const"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_error26", "error( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_deliver27", "deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_messageError28", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_suspendDeliver1", "suspendDeliver(registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_suspendDeliver2", "suspendDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_resumeDeliver3", "resumeDeliver(registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_resumeDeliver4", "resumeDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_route5", "route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_route6", "route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_route7", "route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_route8", "route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_send9", "send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_send10", "send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
      Log::binaryLog(mid, MethodMap_namespace::MethodMap("DeferredRouteTransportWrapper_commitCallBack0", "commitCallBack(uint64_t myTicket)"), 0);
      
    }
  }
  
  void DeferredRouteTransportWrapperService::commitCallBack(
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      uint64_t myTicket
#line 726 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_commitCallBack_routine_0
    #define selectorId selectorId_commitCallBack_routine_0
    ADD_LOG_BACKING
    bool __test = shouldLog_commitCallBack0(myTicket);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, commitCallBack0Dummy(myTicket), 0);
      }
    }
    
    
    
    #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    {
      maceout << "commitCallback called. Processing outstanding " << queued.size() << " messages." << Log::endl;
      MessageQueue::iterator i;
      for (i=queued.begin(); i!= queued.end(); i++) {
        Packet m = i->second;
        downcall_route(m.dest, Data(m.src, m.dest, m.regId, m.data));
      }
      queued.clear();
    }
#line 762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    #undef selector
    #undef selectorId
    
  }
  
  //END Mace::Compiler::ServiceImpl::printRoutines
  
  //Timer Demux (and utility timer)
  //BEGIN Mace::Compiler::ServiceImpl::printTimerDemux
  //END Mace::Compiler::ServiceImpl::printTimerDemux
  
  //Load Protocol
  
  //BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol
  RouteServiceClass& configure_new_DeferredRouteTransportWrapper_Route(bool ___shared);
  TransportServiceClass& configure_new_DeferredRouteTransportWrapper_Transport(bool ___shared);
  
  void load_protocol() {
    StringSet attr = mace::makeStringSet("DeferredRouteTransportWrapper", ",");
    mace::ServiceFactory<RouteServiceClass>::registerService(&configure_new_DeferredRouteTransportWrapper_Route, "DeferredRouteTransportWrapper");
    mace::ServiceConfig<RouteServiceClass>::registerService("DeferredRouteTransportWrapper", attr);
    mace::ServiceFactory<TransportServiceClass>::registerService(&configure_new_DeferredRouteTransportWrapper_Transport, "DeferredRouteTransportWrapper");
    mace::ServiceConfig<TransportServiceClass>::registerService("DeferredRouteTransportWrapper", attr);
  }
  //END Mace::Compiler::ServiceImpl::printLoadProtocol
  
  //Constructors
  //BEGIN Mace::Compiler::ServiceImpl::printConstructor
  RouteServiceClass& real_new_DeferredRouteTransportWrapper_Route(TransportServiceClass& trans, bool ___shared) {
    return *(new DeferredRouteTransportWrapperService(trans,___shared));
  }
  TransportServiceClass& real_new_DeferredRouteTransportWrapper_Transport(TransportServiceClass& trans, bool ___shared) {
    return *(new DeferredRouteTransportWrapperService(trans,___shared));
  }
  DeferredRouteTransportWrapperService::DeferredRouteTransportWrapperService(TransportServiceClass& __trans, bool ___shared) :
  //(
      BaseMaceService(), __inited(0), _actual_state(init), state(_actual_state),
      _trans(__trans), trans(-1),
      me(),
      queued(),
      deliverMutex(), __local_address(MaceKey::null)
      {
        initializeSelectors();
        __local_address = computeLocalAddress();
        
        if (___shared) {
          mace::ServiceFactory<RouteServiceClass>::registerInstance("DeferredRouteTransportWrapper", this);
          mace::ServiceFactory<TransportServiceClass>::registerInstance("DeferredRouteTransportWrapper", this);
        }
        ServiceClass::addToServiceList(*this);
        
        
        ADD_SELECTORS("DeferredRouteTransportWrapper::(constructor)");
        macedbg(1) << "Created queued instance " << this << Log::endl;
      }
      //)
  DeferredRouteTransportWrapperService::DeferredRouteTransportWrapperService(const DeferredRouteTransportWrapperService& _sv) :
  //(
      BaseMaceService(false), __inited(_sv.__inited), _actual_state(_sv.state), state(_actual_state),
      _trans(_sv._trans), trans(_sv.trans),
      me(_sv.me),
      queued(_sv.queued),
      deliverMutex(_sv.deliverMutex){
        ADD_SELECTORS("DeferredRouteTransportWrapper::(constructor)");
        macedbg(1) << "Created non-queued instance " << this << Log::endl;
      }
      //)
  //END Mace::Compiler::ServiceImpl::printConstructor
  
  //Destructor
  DeferredRouteTransportWrapperService::~DeferredRouteTransportWrapperService() {
    
    mace::ServiceFactory<RouteServiceClass>::unregisterInstance("DeferredRouteTransportWrapper", this);
    mace::ServiceFactory<TransportServiceClass>::unregisterInstance("DeferredRouteTransportWrapper", this);
  }
  
  // Methods for snapshotting...
  void DeferredRouteTransportWrapperService::snapshot(const uint64_t& ver) const {
    ADD_SELECTORS("DeferredRouteTransportWrapperService::snapshot");
    //Assumes state is locked.
    DeferredRouteTransportWrapperService* _sv = new DeferredRouteTransportWrapperService(*this);
    macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
    ASSERT(versionMap.empty() || versionMap.back().first < ver);
    versionMap.push_back(std::make_pair(ver,_sv));
  }
  void DeferredRouteTransportWrapperService::snapshotRelease(const uint64_t& ver) const {
    ADD_SELECTORS("DeferredRouteTransportWrapperService::snapshot");
    //Assumes state is locked.
    while (!versionMap.empty() && versionMap.front().first < ver) {
      macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
      delete versionMap.front().second;
      versionMap.pop_front();
    }
  }
  
  
  const ServiceType::state_type& DeferredRouteTransportWrapperService::read_state() const {
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
  
  
  MaceKey const & DeferredRouteTransportWrapperService::read_me() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return me;
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
      return i->second->me;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  MessageQueue const & DeferredRouteTransportWrapperService::read_queued() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return queued;
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
      return i->second->queued;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  pthread_mutex_t const & DeferredRouteTransportWrapperService::read_deliverMutex() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return deliverMutex;
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
      return i->second->deliverMutex;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
  void DeferredRouteTransportWrapperService::dumpState(LOGLOGTYPE& logger) const {
    logger << "state_dump: " << *this << std::endl;
    return;
  }
  
  void DeferredRouteTransportWrapperService::print(mace::PrintNode& __pr, const std::string& name) const {
    mace::PrintNode __printer(name, "DeferredRouteTransportWrapperService");
    const char* __pr_stateName = getStateName(state);
    mace::printItem(__printer, "state", &__pr_stateName);
    mace::printItem(__printer, "me", &(me));
    mace::printItem(__printer, "queued", &(queued));
    mace::printItem(__printer, "deliverMutex", &(deliverMutex));
    
    __pr.addChild(__printer);
    return;
  }
  
  void DeferredRouteTransportWrapperService::print(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    __out << "me=";  mace::printItem(__out, &(me));  __out << std::endl;
    __out << "queued=";  mace::printItem(__out, &(queued));  __out << std::endl;
    __out << "deliverMutex=";  mace::printItem(__out, &(deliverMutex));  __out << std::endl;
    
    __out << std::endl;
    if(_printLower) {
      __out  << _trans << std::endl;
    }
    return;
  }
  void DeferredRouteTransportWrapperService::printState(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    __out << "me=";  mace::printState(__out, &(me), (me));
    __out << "queued=";  mace::printState(__out, &(queued), (queued));
    __out << "deliverMutex=";  mace::printState(__out, &(deliverMutex), (deliverMutex));
    
    __out << std::endl;
    if(_printLower) {
      _trans.printState(__out);
    }
    return;
  }
  
  void DeferredRouteTransportWrapperService::sqlize(mace::LogNode* __node) const {
    int _index = __node->nextIndex();
    if (_index == 0) {
      std::ostringstream __out;
      __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, state TEXT, me INT, queued INT, deliverMutex INT);" << std::endl;
      __node->children = new mace::LogNode*[3];
      mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_me", Log::sqlEventsLog);
      __node->children[0] = __child0;
      mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_queued", Log::sqlEventsLog);
      __node->children[1] = __child1;
      mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_deliverMutex", Log::sqlEventsLog);
      __node->children[2] = __child2;
      Log::logSqlCreate(__out.str(), __node);
    }
    int _meIndex = __node->children[0]->nextId;
    int _queuedIndex = __node->children[1]->nextId;
    int _deliverMutexIndex = __node->children[2]->nextId;
    std::ostringstream __out;
    __out << __node->logId << "\t" << _index << "\t" << getStateName(state);
    __out << "\t" << _meIndex;
    __out << "\t" << _queuedIndex;
    __out << "\t" << _deliverMutexIndex;
    __out << std::endl;
    ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
    mace::sqlize(&me, __node->children[0]);
    mace::sqlize(&queued, __node->children[1]);
    mace::sqlize(&deliverMutex, __node->children[2]);
    
  }
  
  void DeferredRouteTransportWrapperService::serialize(std::string& __str) const {
    mace::serialize(__str, &state);
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    mace::serialize(__str, &me);
#line 1046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    
    #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    mace::serialize(__str, &queued);
#line 1051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    
    
    mace::serialize( __str, &__local_address );
    return;
  }
  
  int DeferredRouteTransportWrapperService::deserialize(std::istream& __in) throw(SerializationException){
    int serializedByteSize = 0;
    serializedByteSize += mace::deserialize(__in, &_actual_state);
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    serializedByteSize +=  mace::deserialize(__in, &me);
#line 1065 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    
    #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    serializedByteSize +=  mace::deserialize(__in, &queued);
#line 1070 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
    
    
    
    
    MaceKey oldLocalAddress;
    serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
    updateInternalContext( oldLocalAddress, __local_address );
    
    return serializedByteSize;
  }
  void DeferredRouteTransportWrapperService::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
    
  }
  
  void DeferredRouteTransportWrapperService::processDeferred() {  }
  const char* DeferredRouteTransportWrapperService::getMessageName(uint8_t messageType) const {
    switch(messageType) {
      case Data::messageType: return "DeferredRouteTransportWrapper::Data";
      default: ASSERT(false); return "INVALID MESSAGE NUMBER";
    }
  }
  void DeferredRouteTransportWrapperService::changeState(state_type stateNum, int selectorId) {
    _actual_state = stateNum;
    Log::logf(selectorId, "FSM: state changed to %s", getStateName(state));
  }
  const char* DeferredRouteTransportWrapperService::getStateName(state_type state) const {
    switch(static_cast<uint64_t>(state)) {
      case init: return "DeferredRouteTransportWrapper::init";
      case exited: return "DeferredRouteTransportWrapper::exited";
      default: ASSERT(false); return "INVALID STATE NUMBER";
    }
  }
  
  //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
  //BEGIN Mace::Compiler::ServiceImpl::printAPIDemux
  bool DeferredRouteTransportWrapperService::route(
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1109 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 1113 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1117 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_route_demux_12
    #define selectorId selectorId_route_demux_12
    ADD_LOG_BACKING
    bool __test = shouldLog_route14(dest, s, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route14Dummy(dest, s, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 1148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    } else
    if(guard_downcall_1_route(dest,s,rid)) {
      macecompiler(1) << "Firing Transition downcall route [ guards : (true) ] bool route( const MaceKey& dest,  const std::string& msg, registration_uid_t regId)" << Log::endl;
      
      
      
      return mace::logVal( downcall_1_route(dest,s,rid), selectorId->compiler, "rv_bool");
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 1163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool DeferredRouteTransportWrapperService::route(
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& src
#line 1174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 1182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_route15(src, dest, s, rid);
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
#line 1231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_suspendDeliver16(rid);
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
#line 1276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1287 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1291 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_suspendDeliver17(dest, rid);
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
#line 1328 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 1339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_resumeDeliver18(rid);
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
#line 1373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 1384 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 1388 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_resumeDeliver19(dest, rid);
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
#line 1425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::maceInit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceInit_demux_18
    #define selectorId selectorId_maceInit_demux_18
    ADD_LOG_BACKING
    bool __test = shouldLog_maceInit20();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, maceInit20Dummy(), 0);
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
#line 1478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
      } else
      if(guard_downcall_0_maceInit()) {
        macecompiler(1) << "Firing Transition downcall maceInit [ guards : (true) ] void maceInit()" << Log::endl;
        
        
        
        downcall_0_maceInit();
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 1493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::maceResume() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceResume_demux_19
    #define selectorId selectorId_maceResume_demux_19
    ADD_LOG_BACKING
    bool __test = shouldLog_maceResume21();
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
#line 1548 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::maceExit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceExit_demux_20
    #define selectorId selectorId_maceExit_demux_20
    ADD_LOG_BACKING
    bool __test = shouldLog_maceExit22();
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
#line 1590 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
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
  void DeferredRouteTransportWrapperService::maceReset() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceReset_demux_21
    #define selectorId selectorId_maceReset_demux_21
    ADD_LOG_BACKING
    bool __test = shouldLog_maceReset23();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, maceReset23Dummy(), 0);
      }
    }
    
    
    {
      
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
      { }
#line 1638 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    //TODO: stop utility timer as necessary
    _actual_state = init;
    
    map_ReceiveDataHandler.clear();
    map_NetworkErrorHandler.clear();
    map_ForwardDataHandler.clear();
    
    _trans.maceReset();
    me = MaceKey();
    queued = MessageQueue();
    deliverMutex = pthread_mutex_t();
    
    __inited = 0;
    
    #undef selector
    #undef selectorId
    
  }
  const MaceKey& DeferredRouteTransportWrapperService::localAddress() const {
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
  uint32_t DeferredRouteTransportWrapperService::hashState() const {
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
    bool __test = shouldLog_hashState25();
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, hashState25Dummy(), 0);
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
  registration_uid_t DeferredRouteTransportWrapperService::registerHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ReceiveDataHandler.find(regId) == map_ReceiveDataHandler.end());
    map_ReceiveDataHandler[regId] = &handler;
    return regId;
  }
  
  void DeferredRouteTransportWrapperService::registerUniqueHandler(ReceiveDataHandler& handler) {
    ASSERT(map_ReceiveDataHandler.empty());
    map_ReceiveDataHandler[-1] = &handler;
  }
  
  void DeferredRouteTransportWrapperService::unregisterHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    ASSERT(map_ReceiveDataHandler[regId] == &handler);
    map_ReceiveDataHandler.erase(regId);
  }
  registration_uid_t DeferredRouteTransportWrapperService::registerHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_NetworkErrorHandler.find(regId) == map_NetworkErrorHandler.end());
    map_NetworkErrorHandler[regId] = &handler;
    return regId;
  }
  
  void DeferredRouteTransportWrapperService::registerUniqueHandler(NetworkErrorHandler& handler) {
    ASSERT(map_NetworkErrorHandler.empty());
    map_NetworkErrorHandler[-1] = &handler;
  }
  
  void DeferredRouteTransportWrapperService::unregisterHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    ASSERT(map_NetworkErrorHandler[regId] == &handler);
    map_NetworkErrorHandler.erase(regId);
  }
  registration_uid_t DeferredRouteTransportWrapperService::registerHandler(ForwardDataHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ForwardDataHandler.find(regId) == map_ForwardDataHandler.end());
    map_ForwardDataHandler[regId] = &handler;
    return regId;
  }
  
  void DeferredRouteTransportWrapperService::registerUniqueHandler(ForwardDataHandler& handler) {
    ASSERT(map_ForwardDataHandler.empty());
    map_ForwardDataHandler[-1] = &handler;
  }
  
  void DeferredRouteTransportWrapperService::unregisterHandler(ForwardDataHandler& handler, registration_uid_t regId) {
    ASSERT(map_ForwardDataHandler[regId] == &handler);
    map_ForwardDataHandler.erase(regId);
  }
  //END Mace::Compiler::ServiceImpl::printHandlerRegistrations
  
  //Handler demux (uses handlers)
  //BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux
  void DeferredRouteTransportWrapperService::error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 1794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 1798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 1802 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 1806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_error_demux_0
    #define selectorId selectorId_error_demux_0
    ADD_LOG_BACKING
    //locking=" .-1.";
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::NONE_MODE);
    bool __test = shouldLog_error26(nodeId, errorCode, message, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, error26Dummy(nodeId, errorCode, message, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    } else
    if(guard_upcall_3_error(nodeId,errorCode,message,rid)) {
      macecompiler(1) << "Firing Transition upcall error [ guards : (true) ] void error( const MaceKey& nodeId, TransportError::type error_code,  const std::string& m, registration_uid_t registrationUid)" << Log::endl;
      
      
      
      upcall_3_error(nodeId,errorCode,message,rid);
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::deliver(
      #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& source
#line 1866 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& destination
#line 1870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 27 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& s_deserialized
#line 1874 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 1878 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_deliver_demux_1
    #define selectorId selectorId_deliver_demux_1
    ADD_LOG_BACKING
    bool __test = shouldLog_deliver27(source, destination, s_deserialized, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, deliver27Dummy(source, destination, s_deserialized, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 1909 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    } else
    if(guard_upcall_2_deliver(source,destination,s_deserialized)) {
      macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Data& msg)" << Log::endl;
      
      
      
      upcall_2_deliver(source,destination,s_deserialized);
    } else
    {
      macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 1924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::messageError(
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 1935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type errorCode
#line 1939 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& message_deserialized
#line 1943 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 1947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
    bool __test = shouldLog_messageError28(dest, errorCode, message_deserialized, rid);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer(__test);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, messageError28Dummy(dest, errorCode, message_deserialized, rid), 0);
      }
    }
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1980 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
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
#line 2002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printHandlerDemux
  
  //Downcall helpers (uses)
  //BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers
  
  MaceKey DeferredRouteTransportWrapperService::downcall_localAddress() const {
    return _trans.localAddress();
  }
  const MaceKey& DeferredRouteTransportWrapperService::downcall_localAddress(const registration_uid_t& rid) const {
    
    if (&rid == &trans) {
      return _trans.localAddress();
    }
    
    if (rid == trans) {
      return _trans.localAddress();
    }
    return MaceKey::null;
  }
  void DeferredRouteTransportWrapperService::downcall_suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 2032 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_0
    #define selectorId selectorId_suspendDeliver_downcall_0
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver1(rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, suspendDeliver1Dummy(rid), 0);
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
  void DeferredRouteTransportWrapperService::downcall_suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 2073 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 2077 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_1
    #define selectorId selectorId_suspendDeliver_downcall_1
    ADD_LOG_BACKING
    bool __test = shouldLog_suspendDeliver2(dest, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, suspendDeliver2Dummy(dest, rid), 0);
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
  void DeferredRouteTransportWrapperService::downcall_resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 2118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_2
    #define selectorId selectorId_resumeDeliver_downcall_2
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver3(rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, resumeDeliver3Dummy(rid), 0);
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
  void DeferredRouteTransportWrapperService::downcall_resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 2159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 2163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_3
    #define selectorId selectorId_resumeDeliver_downcall_3
    ADD_LOG_BACKING
    bool __test = shouldLog_resumeDeliver4(dest, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, resumeDeliver4Dummy(dest, rid), 0);
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
  bool DeferredRouteTransportWrapperService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2208 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2212 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_4
    #define selectorId selectorId_route_downcall_4
    ADD_LOG_BACKING
    bool __test = shouldLog_route5(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route5Dummy(), 0);
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
  bool DeferredRouteTransportWrapperService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2255 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2259 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_5
    #define selectorId selectorId_route_downcall_5
    ADD_LOG_BACKING
    bool __test = shouldLog_route6(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route6Dummy(dest, s_deserialized, rid), 0);
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
  bool DeferredRouteTransportWrapperService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& src
#line 2306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2310 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2314 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_6
    #define selectorId selectorId_route_downcall_6
    ADD_LOG_BACKING
    bool __test = shouldLog_route7(src, dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route7Dummy(), 0);
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
  bool DeferredRouteTransportWrapperService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& src
#line 2361 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_7
    #define selectorId selectorId_route_downcall_7
    ADD_LOG_BACKING
    bool __test = shouldLog_route8(src, dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, route8Dummy(src, dest, s_deserialized, rid), 0);
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
  size_t DeferredRouteTransportWrapperService::downcall_send(
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2416 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Message& s_deserialized
#line 2420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_8
    #define selectorId selectorId_send_downcall_8
    ADD_LOG_BACKING
    bool __test = shouldLog_send9(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, send9Dummy(), 0);
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
  size_t DeferredRouteTransportWrapperService::downcall_send(
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const Data& s_deserialized
#line 2471 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2475 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_9
    #define selectorId selectorId_send_downcall_9
    ADD_LOG_BACKING
    bool __test = shouldLog_send10(dest, s_deserialized, rid);
    
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
    
    if (mace::LogicalClock::instance().shouldLogPath()) {
      if (__test) {
        Log::binaryLog(selectorId->compiler, send10Dummy(dest, s_deserialized, rid), 0);
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
  void DeferredRouteTransportWrapperService::upcall_deliver(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& source
#line 2522 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& destination
#line 2526 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const std::string& s
#line 2530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 2534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2577 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    else {
      iter->second->deliver(source,destination,s,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::upcall_error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 2592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 2596 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 2600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 2604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2649 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    else {
      iter->second->error(nodeId,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::upcall_messageError(
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& dest
#line 2664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 2668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 2672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 2676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2719 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
    }
    else {
      iter->second->messageError(dest,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  bool DeferredRouteTransportWrapperService::upcall_forward(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& source
#line 2734 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& destination
#line 2738 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      MaceKey& nextHop
#line 2742 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const std::string& s
#line 2746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      registration_uid_t rid
#line 2750 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      
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
  void DeferredRouteTransportWrapperService::deliver(
      #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& source
#line 2817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& destination
#line 2821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 27 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const std::string& s
#line 2825 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 2829 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
        ABORT("INVALID MESSAGE NUMBER");
      }
      break;
    }
    
    #undef selector
    #undef selectorId
    
  }
  void DeferredRouteTransportWrapperService::messageError(
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const MaceKey& dest
#line 2882 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      TransportError::type errorCode
#line 2886 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      const std::string& message
#line 2890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      registration_uid_t rid
#line 2894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
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
#line 2933 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.cc"
        
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
