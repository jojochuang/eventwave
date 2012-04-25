/*********************************************
*  ProvisionalTransport main source file
*  Mace generated on:
*  Tue Apr 10 10:09:49 2012
*********************************************/
//BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"

#include "ProvisionalTransport.h"
#include "ProvisionalTransport-macros.h"
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

bool operator==(const mace::map<int, mace::map<int, ProvisionalTransport_namespace::ProvisionalTransportService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, ProvisionalTransport_namespace::ProvisionalTransportService*, mace::SoftState>::const_iterator& rhs) {
  return lhs->second == rhs;
}
bool operator==(const mace::map<int, ProvisionalTransport_namespace::ProvisionalTransportService*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, ProvisionalTransport_namespace::ProvisionalTransportService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
  return lhs == rhs->second;
}
namespace mace {
  template<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;
}
namespace ProvisionalTransport_namespace {
  mace::LogNode* ProvisionalTransportService::rootLogNode = NULL;
  //    mace::LogNode* ProvisionalTransportDummy::rootLogNode = NULL;
  //Selector Constants
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //const std::string selector_registerHandler_demux_22;
  const LogIdSet* ProvisionalTransportService::selectorId_registerHandler_demux_22;
  //const std::string selector_route_downcall_30;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_30;
  //const std::string selector_messageCanceled_upcall_6;
  const LogIdSet* ProvisionalTransportService::selectorId_messageCanceled_upcall_6;
  //const std::string selector_downcall_maceInit_0_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_maceInit_0_transition;
  //const std::string selector_incomingBufferedDataSize_downcall_3;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingBufferedDataSize_downcall_3;
  //const std::string selector_routeRTS_downcall_23;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_23;
  //const std::string selector_send_downcall_37;
  const LogIdSet* ProvisionalTransportService::selectorId_send_downcall_37;
  //const std::string selector_updateSendable_routine_1;
  const LogIdSet* ProvisionalTransportService::selectorId_updateSendable_routine_1;
  //const std::string selector_outgoingBufferedDataSize_downcall_13;
  const LogIdSet* ProvisionalTransportService::selectorId_outgoingBufferedDataSize_downcall_13;
  //const std::string selector_error_upcall_1;
  const LogIdSet* ProvisionalTransportService::selectorId_error_upcall_1;
  //const std::string selector_getStatistics_downcall_8;
  const LogIdSet* ProvisionalTransportService::selectorId_getStatistics_downcall_8;
  //const std::string selector_cancelFront_demux_11;
  const LogIdSet* ProvisionalTransportService::selectorId_cancelFront_demux_11;
  //const std::string selector_downcall_incomingBufferedDataSize_7_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_incomingBufferedDataSize_7_transition;
  //const std::string selector_send_downcall_36;
  const LogIdSet* ProvisionalTransportService::selectorId_send_downcall_36;
  //const std::string selector_send_downcall_38;
  const LogIdSet* ProvisionalTransportService::selectorId_send_downcall_38;
  //const std::string selector_route_downcall_28;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_28;
  //const std::string selector_clearToSend_demux_1;
  const LogIdSet* ProvisionalTransportService::selectorId_clearToSend_demux_1;
  //const std::string selector_localAddress_demux_52;
  const LogIdSet* ProvisionalTransportService::selectorId_localAddress_demux_52;
  //const std::string selector_messageStatus_demux_12;
  const LogIdSet* ProvisionalTransportService::selectorId_messageStatus_demux_12;
  //const std::string selector_routeRTS_downcall_22;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_22;
  //const std::string selector_outgoingBufferedDataSize_downcall_2;
  const LogIdSet* ProvisionalTransportService::selectorId_outgoingBufferedDataSize_downcall_2;
  //const std::string selector_downcall_messageStatus_8_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_messageStatus_8_transition;
  //const std::string selector_suspendDeliver_demux_44;
  const LogIdSet* ProvisionalTransportService::selectorId_suspendDeliver_demux_44;
  //const std::string selector_suspendDeliver_downcall_16;
  const LogIdSet* ProvisionalTransportService::selectorId_suspendDeliver_downcall_16;
  //const std::string selector_hasOutgoingBufferedData_demux_37;
  const LogIdSet* ProvisionalTransportService::selectorId_hasOutgoingBufferedData_demux_37;
  //const std::string selector_route_downcall_34;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_34;
  //const std::string selector_incomingMessageQueueSize_demux_29;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingMessageQueueSize_demux_29;
  //const std::string selector_downcall_canSend_5_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_canSend_5_transition;
  //const std::string selector_route_downcall_33;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_33;
  //const std::string selector_routeRTS_demux_40;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_demux_40;
  //const std::string selector_clearToSend_upcall_3;
  const LogIdSet* ProvisionalTransportService::selectorId_clearToSend_upcall_3;
  //const std::string selector_outgoingBufferedDataSize_demux_27;
  const LogIdSet* ProvisionalTransportService::selectorId_outgoingBufferedDataSize_demux_27;
  //const std::string selector_messageError_demux_55;
  const LogIdSet* ProvisionalTransportService::selectorId_messageError_demux_55;
  //const std::string selector_route_downcall_42;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_42;
  //const std::string selector_route_downcall_27;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_27;
  //const std::string selector_routeRTS_downcall_20;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_20;
  //const std::string selector_maceReset_demux_51;
  const LogIdSet* ProvisionalTransportService::selectorId_maceReset_demux_51;
  //const std::string selector_notifyFlushed_demux_2;
  const LogIdSet* ProvisionalTransportService::selectorId_notifyFlushed_demux_2;
  //const std::string selector_unregisterHandler_demux_17;
  const LogIdSet* ProvisionalTransportService::selectorId_unregisterHandler_demux_17;
  //const std::string selector_routeRTS_downcall_19;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_19;
  //const std::string selector_suspendDeliver_downcall_15;
  const LogIdSet* ProvisionalTransportService::selectorId_suspendDeliver_downcall_15;
  //const std::string selector_deliver_upcall_0;
  const LogIdSet* ProvisionalTransportService::selectorId_deliver_upcall_0;
  //const std::string selector_suspendDeliver_demux_45;
  const LogIdSet* ProvisionalTransportService::selectorId_suspendDeliver_demux_45;
  //const std::string selector_hashState_demux_53;
  const LogIdSet* ProvisionalTransportService::selectorId_hashState_demux_53;
  //const std::string selector_outgoingBufferedDataSize_demux_38;
  const LogIdSet* ProvisionalTransportService::selectorId_outgoingBufferedDataSize_demux_38;
  //const std::string selector_canSend_downcall_0;
  const LogIdSet* ProvisionalTransportService::selectorId_canSend_downcall_0;
  //const std::string selector_send_downcall_35;
  const LogIdSet* ProvisionalTransportService::selectorId_send_downcall_35;
  //const std::string selector_maceResume_demux_49;
  const LogIdSet* ProvisionalTransportService::selectorId_maceResume_demux_49;
  //const std::string selector_route_demux_42;
  const LogIdSet* ProvisionalTransportService::selectorId_route_demux_42;
  //const std::string selector_unregisterHandler_demux_23;
  const LogIdSet* ProvisionalTransportService::selectorId_unregisterHandler_demux_23;
  //const std::string selector_deliver_demux_54;
  const LogIdSet* ProvisionalTransportService::selectorId_deliver_demux_54;
  //const std::string selector_routeRTS_downcall_26;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_26;
  //const std::string selector_setWindowSize_downcall_6;
  const LogIdSet* ProvisionalTransportService::selectorId_setWindowSize_downcall_6;
  //const std::string selector_routeRTS_demux_39;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_demux_39;
  //const std::string selector_messageError_demux_6;
  const LogIdSet* ProvisionalTransportService::selectorId_messageError_demux_6;
  //const std::string selector_messageError_demux_8;
  const LogIdSet* ProvisionalTransportService::selectorId_messageError_demux_8;
  //const std::string selector_routeRTS_downcall_25;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_25;
  //const std::string selector_setWindowSize_demux_31;
  const LogIdSet* ProvisionalTransportService::selectorId_setWindowSize_demux_31;
  //const std::string selector_downcall_cancelFront_3_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_cancelFront_3_transition;
  //const std::string selector_registerUniqueHandler_demux_15;
  const LogIdSet* ProvisionalTransportService::selectorId_registerUniqueHandler_demux_15;
  //const std::string selector_routeRTS_downcall_21;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_21;
  //const std::string selector_upcall_messageError_14_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_messageError_14_transition;
  //const std::string selector_registerHandler_demux_16;
  const LogIdSet* ProvisionalTransportService::selectorId_registerHandler_demux_16;
  //const std::string selector_bufferedDataSize_demux_35;
  const LogIdSet* ProvisionalTransportService::selectorId_bufferedDataSize_demux_35;
  //const std::string selector_downcall_route_2_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_route_2_transition;
  //const std::string selector_setQueueSize_demux_32;
  const LogIdSet* ProvisionalTransportService::selectorId_setQueueSize_demux_32;
  //const std::string selector_incomingMessageQueueSize_downcall_5;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingMessageQueueSize_downcall_5;
  //const std::string selector_deliver_demux_5;
  const LogIdSet* ProvisionalTransportService::selectorId_deliver_demux_5;
  //const std::string selector_canSend_demux_25;
  const LogIdSet* ProvisionalTransportService::selectorId_canSend_demux_25;
  //const std::string selector_resumeDeliver_demux_47;
  const LogIdSet* ProvisionalTransportService::selectorId_resumeDeliver_demux_47;
  //const std::string selector_routeRTS_downcall_39;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_39;
  //const std::string selector_getStatistics_demux_33;
  const LogIdSet* ProvisionalTransportService::selectorId_getStatistics_demux_33;
  //const std::string selector_hasBufferedData_demux_36;
  const LogIdSet* ProvisionalTransportService::selectorId_hasBufferedData_demux_36;
  //const std::string selector_messageError_upcall_2;
  const LogIdSet* ProvisionalTransportService::selectorId_messageError_upcall_2;
  //const std::string selector_upcall_messageError_16_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_messageError_16_transition;
  //const std::string selector_requestToSend_downcall_9;
  const LogIdSet* ProvisionalTransportService::selectorId_requestToSend_downcall_9;
  //const std::string selector_upcall_deliver_10_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_deliver_10_transition;
  //const std::string selector_upcall_messageError_15_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_messageError_15_transition;
  //const std::string selector_cancel_demux_10;
  const LogIdSet* ProvisionalTransportService::selectorId_cancel_demux_10;
  //const std::string selector_availableBufferSize_demux_26;
  const LogIdSet* ProvisionalTransportService::selectorId_availableBufferSize_demux_26;
  //const std::string selector_error_demux_0;
  const LogIdSet* ProvisionalTransportService::selectorId_error_demux_0;
  //const std::string selector_messageSent_upcall_5;
  const LogIdSet* ProvisionalTransportService::selectorId_messageSent_upcall_5;
  //const std::string selector_upcall_deliver_12_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_deliver_12_transition;
  //const std::string selector_upcall_deliver_11_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_deliver_11_transition;
  //const std::string selector_route_downcall_41;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_41;
  //const std::string selector_requestToSend_demux_34;
  const LogIdSet* ProvisionalTransportService::selectorId_requestToSend_demux_34;
  //const std::string selector_routeRTS_downcall_40;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_40;
  //const std::string selector_registerUniqueHandler_demux_24;
  const LogIdSet* ProvisionalTransportService::selectorId_registerUniqueHandler_demux_24;
  //const std::string selector_unregisterHandler_demux_14;
  const LogIdSet* ProvisionalTransportService::selectorId_unregisterHandler_demux_14;
  //const std::string selector_upcall_clearToSend_13_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_clearToSend_13_transition;
  //const std::string selector_downcall_availableBufferSize_6_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_availableBufferSize_6_transition;
  //const std::string selector_routeRTS_downcall_24;
  const LogIdSet* ProvisionalTransportService::selectorId_routeRTS_downcall_24;
  //const std::string selector_cancel_routine_2;
  const LogIdSet* ProvisionalTransportService::selectorId_cancel_routine_2;
  //const std::string selector_registerHandler_demux_13;
  const LogIdSet* ProvisionalTransportService::selectorId_registerHandler_demux_13;
  //const std::string selector_sendData_routine_0;
  const LogIdSet* ProvisionalTransportService::selectorId_sendData_routine_0;
  //const std::string selector_hasOutgoingBufferedData_downcall_12;
  const LogIdSet* ProvisionalTransportService::selectorId_hasOutgoingBufferedData_downcall_12;
  //const std::string selector_route_downcall_32;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_32;
  //const std::string selector_messageError_demux_7;
  const LogIdSet* ProvisionalTransportService::selectorId_messageError_demux_7;
  //const std::string selector_availableBufferSize_downcall_1;
  const LogIdSet* ProvisionalTransportService::selectorId_availableBufferSize_downcall_1;
  //const std::string selector_requestFlushedNotification_demux_41;
  const LogIdSet* ProvisionalTransportService::selectorId_requestFlushedNotification_demux_41;
  //const std::string selector_maceExit_demux_50;
  const LogIdSet* ProvisionalTransportService::selectorId_maceExit_demux_50;
  //const std::string selector_upcall_error_9_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_upcall_error_9_transition;
  //const std::string selector_route_downcall_31;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_31;
  //const std::string selector_provisionalRoute_demux_9;
  const LogIdSet* ProvisionalTransportService::selectorId_provisionalRoute_demux_9;
  //const std::string selector_incomingMessageQueueSize_downcall_4;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingMessageQueueSize_downcall_4;
  //const std::string selector_downcall_provisionalRoute_1_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_provisionalRoute_1_transition;
  //const std::string selector_notifyFlushed_upcall_4;
  const LogIdSet* ProvisionalTransportService::selectorId_notifyFlushed_upcall_4;
  //const std::string selector_hasBufferedData_downcall_11;
  const LogIdSet* ProvisionalTransportService::selectorId_hasBufferedData_downcall_11;
  //const std::string selector_resumeDeliver_demux_46;
  const LogIdSet* ProvisionalTransportService::selectorId_resumeDeliver_demux_46;
  //const std::string selector_resumeDeliver_downcall_17;
  const LogIdSet* ProvisionalTransportService::selectorId_resumeDeliver_downcall_17;
  //const std::string selector_bufferedDataSize_downcall_10;
  const LogIdSet* ProvisionalTransportService::selectorId_bufferedDataSize_downcall_10;
  //const std::string selector_registerUniqueHandler_demux_21;
  const LogIdSet* ProvisionalTransportService::selectorId_registerUniqueHandler_demux_21;
  //const std::string selector_resumeDeliver_downcall_18;
  const LogIdSet* ProvisionalTransportService::selectorId_resumeDeliver_downcall_18;
  //const std::string selector_incomingBufferedDataSize_demux_28;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingBufferedDataSize_demux_28;
  //const std::string selector_deliver_demux_3;
  const LogIdSet* ProvisionalTransportService::selectorId_deliver_demux_3;
  //const std::string selector_send_downcall_43;
  const LogIdSet* ProvisionalTransportService::selectorId_send_downcall_43;
  //const std::string selector_requestFlushedNotification_downcall_14;
  const LogIdSet* ProvisionalTransportService::selectorId_requestFlushedNotification_downcall_14;
  //const std::string selector_unregisterHandler_demux_20;
  const LogIdSet* ProvisionalTransportService::selectorId_unregisterHandler_demux_20;
  //const std::string selector_downcall_cancel_4_transition;
  const LogIdSet* ProvisionalTransportService::selectorId_downcall_cancel_4_transition;
  //const std::string selector_registerHandler_demux_19;
  const LogIdSet* ProvisionalTransportService::selectorId_registerHandler_demux_19;
  //const std::string selector_deliver_demux_4;
  const LogIdSet* ProvisionalTransportService::selectorId_deliver_demux_4;
  //const std::string selector_setQueueSize_downcall_7;
  const LogIdSet* ProvisionalTransportService::selectorId_setQueueSize_downcall_7;
  //const std::string selector_incomingMessageQueueSize_demux_30;
  const LogIdSet* ProvisionalTransportService::selectorId_incomingMessageQueueSize_demux_30;
  //const std::string selector_route_demux_43;
  const LogIdSet* ProvisionalTransportService::selectorId_route_demux_43;
  //const std::string selector_registerUniqueHandler_demux_18;
  const LogIdSet* ProvisionalTransportService::selectorId_registerUniqueHandler_demux_18;
  //const std::string selector_maceInit_demux_48;
  const LogIdSet* ProvisionalTransportService::selectorId_maceInit_demux_48;
  //const std::string selector_route_downcall_29;
  const LogIdSet* ProvisionalTransportService::selectorId_route_downcall_29;
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //Change Tracker (optional)
  //BEGIN Mace::Compiler::ServiceImpl::printChangeTracker
  //END Mace::Compiler::ServiceImpl::printChangeTracker
  
  //service variable includes and uses
  
  
  //Transition and Guard Implementations
  //BEGIN Mace::Compiler::ServiceImpl::printTransitions
  bool ProvisionalTransportService::guard_downcall_0_maceInit() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 109 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 313 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::downcall_0_maceInit() {
    #define selector selector_downcall_maceInit_0_transition
    #define selectorId selectorId_downcall_maceInit_0_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 109 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      threshold = ((queueThresholdArg == UINT_MAX) ? maxQueueSize / 2 : queueThresholdArg);
      if (threshold == 0) {
        threshold = 1;
      }
    }
#line 339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_1_provisionalRoute(
      #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 347 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      std::string const & s
#line 351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 117 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t const  rid
#line 355 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  message_id_t ProvisionalTransportService::downcall_1_provisionalRoute(
      #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 374 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const std::string& s
#line 378 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 117 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 382 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_provisionalRoute_1_transition
    #define selectorId selectorId_downcall_provisionalRoute_1_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 117 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      OutgoingConnection& c = out[dest];
      if (!c.sendable) {
        return 0;
      }
      message_id_t id = curtime;
      OutgoingMessageData& d = c.q[id];
      destinations[id] = dest;
      d.data = s;
      d.rid = rid;
      c.buffered += s.size();
      if (c.buffered > maxQueueSize) {
        c.sendable = false;
      }
      
      if (c.q.size() == 1) {
        sendData(dest);
      }
      return id;
    }
#line 417 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_2_route(
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      std::string const & s
#line 429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t const  rid
#line 433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool ProvisionalTransportService::downcall_2_route(
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 452 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const std::string& s
#line 456 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 460 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_route_2_transition
    #define selectorId selectorId_downcall_route_2_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      if (provisionalRoute(dest, s, rid) != 0) {
        return true;
      }
      else {
        return false;
      }
    }
#line 483 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_3_cancelFront(
      #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 491 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 501 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  message_id_t ProvisionalTransportService::downcall_3_cancelFront(
      #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 510 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_cancelFront_3_transition
    #define selectorId selectorId_downcall_cancelFront_3_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      OutgoingConnectionMap::iterator i = out.find(dest);
      if (i != out.end()) {
        OutgoingConnection& c = i->second;
        if (!c.q.empty()) {
          OutgoingMessageQueue::iterator k = c.q.begin();
          message_id_t id = k->first;
          cancel(dest, k->second, id, c);
          return id;
        }
      }
      return 0;
    }
#line 538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_4_cancel(
      #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      message_id_t const  id
#line 546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 556 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  size_t ProvisionalTransportService::downcall_4_cancel(
      #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      message_id_t id
#line 565 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_cancel_4_transition
    #define selectorId selectorId_downcall_cancel_4_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      MessageDestinationMap::const_iterator i = destinations.find(id);
      if (i != destinations.end()) {
        const MaceKey& dest = i->second;
        OutgoingConnection& c = out[dest];
        OutgoingMessageQueue::const_iterator k = c.q.find(id);
        if (k != c.q.end()) {
          return cancel(dest, k->second, id, c);
        }
      }
      return 0;
    }
#line 592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_5_canSend(
      #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 610 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool ProvisionalTransportService::downcall_5_canSend(
      #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 619 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_canSend_5_transition
    #define selectorId selectorId_downcall_canSend_5_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      OutgoingConnectionMap::const_iterator i = out.find(dest);
      if (i == out.end()) {
        return true;
      }
      return i->second.sendable;
    }
#line 641 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_6_availableBufferSize(
      #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 649 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  uint32_t ProvisionalTransportService::downcall_6_availableBufferSize(
      #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_availableBufferSize_6_transition
    #define selectorId selectorId_downcall_availableBufferSize_6_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      OutgoingConnectionMap::const_iterator i = out.find(dest);
      if (i == out.end()) {
        return maxQueueSize;
      }
      else if (!i->second.sendable) {
        return 0;
      }
      return maxQueueSize - i->second.buffered;
    }
#line 693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_7_incomingBufferedDataSize(
      #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & src
#line 701 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  uint32_t ProvisionalTransportService::downcall_7_incomingBufferedDataSize(
      #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 720 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_downcall_incomingBufferedDataSize_7_transition
    #define selectorId selectorId_downcall_incomingBufferedDataSize_7_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      IncomingMessageMap& m = in[src];
      size_t r = 0;
      for (IncomingMessageMap::const_iterator i = m.begin(); i != m.end(); i++) {
        r += i->second.size();
      }
      return r;
    }
#line 743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_downcall_8_messageStatus(
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      message_id_t const  id
#line 751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const & size
#line 755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const & sent
#line 759 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 769 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::downcall_8_messageStatus(
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      message_id_t id
#line 778 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t& size
#line 782 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t& sent
#line 786 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    #define selector selector_downcall_messageStatus_8_transition
    #define selectorId selectorId_downcall_messageStatus_8_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      MessageDestinationMap::const_iterator i = destinations.find(id);
      if (i != destinations.end()) {
        const OutgoingConnectionMap::const_iterator ci = out.find(i->second);
        if (ci != out.end()) {
          const OutgoingConnection& c = ci->second;
          OutgoingMessageQueue::const_iterator k = c.q.find(id);
          if (k != c.q.end()) {
            const OutgoingMessageData& m = k->second;
            size = m.data.size();
            sent = m.offset;
            return;
          }
        }
      }
      size = 0;
      sent = 1;
    }
#line 819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_9_error(
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & src
#line 827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type const  ec
#line 831 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      std::string const & message
#line 835 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 845 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_9_error(
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 854 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type ec
#line 858 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const std::string& message
#line 862 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_error_9_transition
    #define selectorId selectorId_upcall_error_9_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      out.erase(src);
      in.erase(src);
    }
#line 881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_10_deliver(
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & src
#line 889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 893 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Data const & m
#line 897 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 907 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_10_deliver(
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 916 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& m
#line 924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_deliver_10_transition
    #define selectorId selectorId_upcall_deliver_10_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      in[src][m.id].append(m.data);
    }
#line 942 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_11_deliver(
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & src
#line 950 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 954 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Commit const & m
#line 958 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 968 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_11_deliver(
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 977 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 981 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& m
#line 985 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_deliver_11_transition
    #define selectorId selectorId_upcall_deliver_11_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      IncomingMessageMap& mm = in[src];
      mace::string& d = mm[m.id];
      d.append(m.data);
      upcall_deliver(src, dest, d, m.rid);
      mm.erase(m.id);
    }
#line 1007 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_12_deliver(
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & src
#line 1015 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 1019 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Abort const & m
#line 1023 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 1033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_12_deliver(
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 1042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& m
#line 1050 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_deliver_12_transition
    #define selectorId selectorId_upcall_deliver_12_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      static Accumulator* rcaccum = Accumulator::Instance(Accumulator::TRANSPORT_RECV_CANCELED);
      IncomingMessageMap& mm = in[src];
      IncomingMessageMap::iterator i = mm.find(m.id);
      if (i != mm.end()) {
        size_t s = i->second.size();
        rcaccum->accumulate(s);
        upcall_messageCanceled(src, s, m.rid);
        mm.erase(m.id);
      }
    }
#line 1076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_13_clearToSend(
      #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 1084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        true
#line 1094 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_13_clearToSend(
      #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1103 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_clearToSend_13_transition
    #define selectorId selectorId_upcall_clearToSend_13_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      sendData(dest);
    }
#line 1121 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_14_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 1129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type const  errorCode
#line 1133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Data const & message_deserialized
#line 1137 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t const  rid
#line 1141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        true
#line 1151 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_14_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1160 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 1164 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& message_deserialized
#line 1168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 1172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_messageError_14_transition
    #define selectorId selectorId_upcall_messageError_14_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
    { }
#line 1188 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_15_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 1196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type const  errorCode
#line 1200 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Commit const & message_deserialized
#line 1204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t const  rid
#line 1208 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        true
#line 1218 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_15_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1227 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 1231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& message_deserialized
#line 1235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 1239 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_messageError_15_transition
    #define selectorId selectorId_upcall_messageError_15_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
    { }
#line 1255 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool ProvisionalTransportService::guard_upcall_16_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      MaceKey const & dest
#line 1263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type const  errorCode
#line 1267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      Abort const & message_deserialized
#line 1271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t const  rid
#line 1275 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        true
#line 1285 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void ProvisionalTransportService::upcall_16_messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 1298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& message_deserialized
#line 1302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 1306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    #define selector selector_upcall_messageError_16_transition
    #define selectorId selectorId_upcall_messageError_16_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
    { }
#line 1322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  //END Mace::Compiler::ServiceImpl::printTransitions
  
  //Structured Logging Functions
  // logging funcs
  bool ProvisionalTransportService::shouldLog_provisionalRoute48( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_cancel49(message_id_t id, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_cancelFront50( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_messageStatus51(message_id_t id, uint32_t& size, uint32_t& sent, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_canSend52( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_availableBufferSize53( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_outgoingBufferedDataSize54( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingBufferedDataSize55( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingMessageQueueSize56( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingMessageQueueSize57(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_setWindowSize58( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_setQueueSize59( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_getStatistics60( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_requestToSend61( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_bufferedDataSize62(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_hasBufferedData63(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_hasOutgoingBufferedData64(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_outgoingBufferedDataSize65(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS66( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS67( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_requestFlushedNotification68(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route69( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route70( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_suspendDeliver71(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_suspendDeliver72( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_resumeDeliver73(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_resumeDeliver74( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_maceInit75() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_maceResume76() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_maceExit77() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_maceReset78() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_localAddress79() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_hashState80() const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_error81( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_clearToSend82( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_notifyFlushed83(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_deliver84( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_deliver85( const MaceKey& source,  const MaceKey& destination,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_deliver86( const MaceKey& source,  const MaceKey& destination,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_messageError87( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_messageError88( const MaceKey& dest, TransportError::type errorCode,  const Commit& message_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_messageError89( const MaceKey& dest, TransportError::type errorCode,  const Abort& message_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_canSend4( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_availableBufferSize5( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_outgoingBufferedDataSize6( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingBufferedDataSize7( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingMessageQueueSize8( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_incomingMessageQueueSize9(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_setWindowSize10( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_setQueueSize11( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_getStatistics12( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_requestToSend13( const MaceKey& peer, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_bufferedDataSize14(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_hasBufferedData15(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_hasOutgoingBufferedData16(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_outgoingBufferedDataSize17(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_requestFlushedNotification18(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_suspendDeliver19(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_suspendDeliver20( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_resumeDeliver21(registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_resumeDeliver22( const MaceKey& dest, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS23( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS24( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS25( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS26( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS27( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS28( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS29( const MaceKey& src,  const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_routeRTS30( const MaceKey& src,  const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route31( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route32( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route33( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route34( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_send39( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_send40( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_send41( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_send42( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_upcall_messageSent3(message_id_t id, registration_uid_t rid) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_sendData0( const MaceKey& dest) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_updateSendable1(OutgoingConnection& c) const {
    return true;
  }
  bool ProvisionalTransportService::shouldLog_cancel2( const MaceKey& dest,  const OutgoingMessageData& m, message_id_t id, OutgoingConnection& c) const {
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
      ProvisionalTransportService::selectorId_registerHandler_demux_22 = new LogIdSet(selector_registerHandler_demux_22);
      ProvisionalTransportService::selectorId_route_downcall_30 = new LogIdSet(selector_route_downcall_30);
      ProvisionalTransportService::selectorId_messageCanceled_upcall_6 = new LogIdSet(selector_messageCanceled_upcall_6);
      ProvisionalTransportService::selectorId_downcall_maceInit_0_transition = new LogIdSet(selector_downcall_maceInit_0_transition);
      ProvisionalTransportService::selectorId_incomingBufferedDataSize_downcall_3 = new LogIdSet(selector_incomingBufferedDataSize_downcall_3);
      ProvisionalTransportService::selectorId_routeRTS_downcall_23 = new LogIdSet(selector_routeRTS_downcall_23);
      ProvisionalTransportService::selectorId_send_downcall_37 = new LogIdSet(selector_send_downcall_37);
      ProvisionalTransportService::selectorId_updateSendable_routine_1 = new LogIdSet(selector_updateSendable_routine_1);
      ProvisionalTransportService::selectorId_outgoingBufferedDataSize_downcall_13 = new LogIdSet(selector_outgoingBufferedDataSize_downcall_13);
      ProvisionalTransportService::selectorId_error_upcall_1 = new LogIdSet(selector_error_upcall_1);
      ProvisionalTransportService::selectorId_getStatistics_downcall_8 = new LogIdSet(selector_getStatistics_downcall_8);
      ProvisionalTransportService::selectorId_cancelFront_demux_11 = new LogIdSet(selector_cancelFront_demux_11);
      ProvisionalTransportService::selectorId_downcall_incomingBufferedDataSize_7_transition = new LogIdSet(selector_downcall_incomingBufferedDataSize_7_transition);
      ProvisionalTransportService::selectorId_send_downcall_36 = new LogIdSet(selector_send_downcall_36);
      ProvisionalTransportService::selectorId_send_downcall_38 = new LogIdSet(selector_send_downcall_38);
      ProvisionalTransportService::selectorId_route_downcall_28 = new LogIdSet(selector_route_downcall_28);
      ProvisionalTransportService::selectorId_clearToSend_demux_1 = new LogIdSet(selector_clearToSend_demux_1);
      ProvisionalTransportService::selectorId_localAddress_demux_52 = new LogIdSet(selector_localAddress_demux_52);
      ProvisionalTransportService::selectorId_messageStatus_demux_12 = new LogIdSet(selector_messageStatus_demux_12);
      ProvisionalTransportService::selectorId_routeRTS_downcall_22 = new LogIdSet(selector_routeRTS_downcall_22);
      ProvisionalTransportService::selectorId_outgoingBufferedDataSize_downcall_2 = new LogIdSet(selector_outgoingBufferedDataSize_downcall_2);
      ProvisionalTransportService::selectorId_downcall_messageStatus_8_transition = new LogIdSet(selector_downcall_messageStatus_8_transition);
      ProvisionalTransportService::selectorId_suspendDeliver_demux_44 = new LogIdSet(selector_suspendDeliver_demux_44);
      ProvisionalTransportService::selectorId_suspendDeliver_downcall_16 = new LogIdSet(selector_suspendDeliver_downcall_16);
      ProvisionalTransportService::selectorId_hasOutgoingBufferedData_demux_37 = new LogIdSet(selector_hasOutgoingBufferedData_demux_37);
      ProvisionalTransportService::selectorId_route_downcall_34 = new LogIdSet(selector_route_downcall_34);
      ProvisionalTransportService::selectorId_incomingMessageQueueSize_demux_29 = new LogIdSet(selector_incomingMessageQueueSize_demux_29);
      ProvisionalTransportService::selectorId_downcall_canSend_5_transition = new LogIdSet(selector_downcall_canSend_5_transition);
      ProvisionalTransportService::selectorId_route_downcall_33 = new LogIdSet(selector_route_downcall_33);
      ProvisionalTransportService::selectorId_routeRTS_demux_40 = new LogIdSet(selector_routeRTS_demux_40);
      ProvisionalTransportService::selectorId_clearToSend_upcall_3 = new LogIdSet(selector_clearToSend_upcall_3);
      ProvisionalTransportService::selectorId_outgoingBufferedDataSize_demux_27 = new LogIdSet(selector_outgoingBufferedDataSize_demux_27);
      ProvisionalTransportService::selectorId_messageError_demux_55 = new LogIdSet(selector_messageError_demux_55);
      ProvisionalTransportService::selectorId_route_downcall_42 = new LogIdSet(selector_route_downcall_42);
      ProvisionalTransportService::selectorId_route_downcall_27 = new LogIdSet(selector_route_downcall_27);
      ProvisionalTransportService::selectorId_routeRTS_downcall_20 = new LogIdSet(selector_routeRTS_downcall_20);
      ProvisionalTransportService::selectorId_maceReset_demux_51 = new LogIdSet(selector_maceReset_demux_51);
      ProvisionalTransportService::selectorId_notifyFlushed_demux_2 = new LogIdSet(selector_notifyFlushed_demux_2);
      ProvisionalTransportService::selectorId_unregisterHandler_demux_17 = new LogIdSet(selector_unregisterHandler_demux_17);
      ProvisionalTransportService::selectorId_routeRTS_downcall_19 = new LogIdSet(selector_routeRTS_downcall_19);
      ProvisionalTransportService::selectorId_suspendDeliver_downcall_15 = new LogIdSet(selector_suspendDeliver_downcall_15);
      ProvisionalTransportService::selectorId_deliver_upcall_0 = new LogIdSet(selector_deliver_upcall_0);
      ProvisionalTransportService::selectorId_suspendDeliver_demux_45 = new LogIdSet(selector_suspendDeliver_demux_45);
      ProvisionalTransportService::selectorId_hashState_demux_53 = new LogIdSet(selector_hashState_demux_53);
      ProvisionalTransportService::selectorId_outgoingBufferedDataSize_demux_38 = new LogIdSet(selector_outgoingBufferedDataSize_demux_38);
      ProvisionalTransportService::selectorId_canSend_downcall_0 = new LogIdSet(selector_canSend_downcall_0);
      ProvisionalTransportService::selectorId_send_downcall_35 = new LogIdSet(selector_send_downcall_35);
      ProvisionalTransportService::selectorId_maceResume_demux_49 = new LogIdSet(selector_maceResume_demux_49);
      ProvisionalTransportService::selectorId_route_demux_42 = new LogIdSet(selector_route_demux_42);
      ProvisionalTransportService::selectorId_unregisterHandler_demux_23 = new LogIdSet(selector_unregisterHandler_demux_23);
      ProvisionalTransportService::selectorId_deliver_demux_54 = new LogIdSet(selector_deliver_demux_54);
      ProvisionalTransportService::selectorId_routeRTS_downcall_26 = new LogIdSet(selector_routeRTS_downcall_26);
      ProvisionalTransportService::selectorId_setWindowSize_downcall_6 = new LogIdSet(selector_setWindowSize_downcall_6);
      ProvisionalTransportService::selectorId_routeRTS_demux_39 = new LogIdSet(selector_routeRTS_demux_39);
      ProvisionalTransportService::selectorId_messageError_demux_6 = new LogIdSet(selector_messageError_demux_6);
      ProvisionalTransportService::selectorId_messageError_demux_8 = new LogIdSet(selector_messageError_demux_8);
      ProvisionalTransportService::selectorId_routeRTS_downcall_25 = new LogIdSet(selector_routeRTS_downcall_25);
      ProvisionalTransportService::selectorId_setWindowSize_demux_31 = new LogIdSet(selector_setWindowSize_demux_31);
      ProvisionalTransportService::selectorId_downcall_cancelFront_3_transition = new LogIdSet(selector_downcall_cancelFront_3_transition);
      ProvisionalTransportService::selectorId_registerUniqueHandler_demux_15 = new LogIdSet(selector_registerUniqueHandler_demux_15);
      ProvisionalTransportService::selectorId_routeRTS_downcall_21 = new LogIdSet(selector_routeRTS_downcall_21);
      ProvisionalTransportService::selectorId_upcall_messageError_14_transition = new LogIdSet(selector_upcall_messageError_14_transition);
      ProvisionalTransportService::selectorId_registerHandler_demux_16 = new LogIdSet(selector_registerHandler_demux_16);
      ProvisionalTransportService::selectorId_bufferedDataSize_demux_35 = new LogIdSet(selector_bufferedDataSize_demux_35);
      ProvisionalTransportService::selectorId_downcall_route_2_transition = new LogIdSet(selector_downcall_route_2_transition);
      ProvisionalTransportService::selectorId_setQueueSize_demux_32 = new LogIdSet(selector_setQueueSize_demux_32);
      ProvisionalTransportService::selectorId_incomingMessageQueueSize_downcall_5 = new LogIdSet(selector_incomingMessageQueueSize_downcall_5);
      ProvisionalTransportService::selectorId_deliver_demux_5 = new LogIdSet(selector_deliver_demux_5);
      ProvisionalTransportService::selectorId_canSend_demux_25 = new LogIdSet(selector_canSend_demux_25);
      ProvisionalTransportService::selectorId_resumeDeliver_demux_47 = new LogIdSet(selector_resumeDeliver_demux_47);
      ProvisionalTransportService::selectorId_routeRTS_downcall_39 = new LogIdSet(selector_routeRTS_downcall_39);
      ProvisionalTransportService::selectorId_getStatistics_demux_33 = new LogIdSet(selector_getStatistics_demux_33);
      ProvisionalTransportService::selectorId_hasBufferedData_demux_36 = new LogIdSet(selector_hasBufferedData_demux_36);
      ProvisionalTransportService::selectorId_messageError_upcall_2 = new LogIdSet(selector_messageError_upcall_2);
      ProvisionalTransportService::selectorId_upcall_messageError_16_transition = new LogIdSet(selector_upcall_messageError_16_transition);
      ProvisionalTransportService::selectorId_requestToSend_downcall_9 = new LogIdSet(selector_requestToSend_downcall_9);
      ProvisionalTransportService::selectorId_upcall_deliver_10_transition = new LogIdSet(selector_upcall_deliver_10_transition);
      ProvisionalTransportService::selectorId_upcall_messageError_15_transition = new LogIdSet(selector_upcall_messageError_15_transition);
      ProvisionalTransportService::selectorId_cancel_demux_10 = new LogIdSet(selector_cancel_demux_10);
      ProvisionalTransportService::selectorId_availableBufferSize_demux_26 = new LogIdSet(selector_availableBufferSize_demux_26);
      ProvisionalTransportService::selectorId_error_demux_0 = new LogIdSet(selector_error_demux_0);
      ProvisionalTransportService::selectorId_messageSent_upcall_5 = new LogIdSet(selector_messageSent_upcall_5);
      ProvisionalTransportService::selectorId_upcall_deliver_12_transition = new LogIdSet(selector_upcall_deliver_12_transition);
      ProvisionalTransportService::selectorId_upcall_deliver_11_transition = new LogIdSet(selector_upcall_deliver_11_transition);
      ProvisionalTransportService::selectorId_route_downcall_41 = new LogIdSet(selector_route_downcall_41);
      ProvisionalTransportService::selectorId_requestToSend_demux_34 = new LogIdSet(selector_requestToSend_demux_34);
      ProvisionalTransportService::selectorId_routeRTS_downcall_40 = new LogIdSet(selector_routeRTS_downcall_40);
      ProvisionalTransportService::selectorId_registerUniqueHandler_demux_24 = new LogIdSet(selector_registerUniqueHandler_demux_24);
      ProvisionalTransportService::selectorId_unregisterHandler_demux_14 = new LogIdSet(selector_unregisterHandler_demux_14);
      ProvisionalTransportService::selectorId_upcall_clearToSend_13_transition = new LogIdSet(selector_upcall_clearToSend_13_transition);
      ProvisionalTransportService::selectorId_downcall_availableBufferSize_6_transition = new LogIdSet(selector_downcall_availableBufferSize_6_transition);
      ProvisionalTransportService::selectorId_routeRTS_downcall_24 = new LogIdSet(selector_routeRTS_downcall_24);
      ProvisionalTransportService::selectorId_cancel_routine_2 = new LogIdSet(selector_cancel_routine_2);
      ProvisionalTransportService::selectorId_registerHandler_demux_13 = new LogIdSet(selector_registerHandler_demux_13);
      ProvisionalTransportService::selectorId_sendData_routine_0 = new LogIdSet(selector_sendData_routine_0);
      ProvisionalTransportService::selectorId_hasOutgoingBufferedData_downcall_12 = new LogIdSet(selector_hasOutgoingBufferedData_downcall_12);
      ProvisionalTransportService::selectorId_route_downcall_32 = new LogIdSet(selector_route_downcall_32);
      ProvisionalTransportService::selectorId_messageError_demux_7 = new LogIdSet(selector_messageError_demux_7);
      ProvisionalTransportService::selectorId_availableBufferSize_downcall_1 = new LogIdSet(selector_availableBufferSize_downcall_1);
      ProvisionalTransportService::selectorId_requestFlushedNotification_demux_41 = new LogIdSet(selector_requestFlushedNotification_demux_41);
      ProvisionalTransportService::selectorId_maceExit_demux_50 = new LogIdSet(selector_maceExit_demux_50);
      ProvisionalTransportService::selectorId_upcall_error_9_transition = new LogIdSet(selector_upcall_error_9_transition);
      ProvisionalTransportService::selectorId_route_downcall_31 = new LogIdSet(selector_route_downcall_31);
      ProvisionalTransportService::selectorId_provisionalRoute_demux_9 = new LogIdSet(selector_provisionalRoute_demux_9);
      ProvisionalTransportService::selectorId_incomingMessageQueueSize_downcall_4 = new LogIdSet(selector_incomingMessageQueueSize_downcall_4);
      ProvisionalTransportService::selectorId_downcall_provisionalRoute_1_transition = new LogIdSet(selector_downcall_provisionalRoute_1_transition);
      ProvisionalTransportService::selectorId_notifyFlushed_upcall_4 = new LogIdSet(selector_notifyFlushed_upcall_4);
      ProvisionalTransportService::selectorId_hasBufferedData_downcall_11 = new LogIdSet(selector_hasBufferedData_downcall_11);
      ProvisionalTransportService::selectorId_resumeDeliver_demux_46 = new LogIdSet(selector_resumeDeliver_demux_46);
      ProvisionalTransportService::selectorId_resumeDeliver_downcall_17 = new LogIdSet(selector_resumeDeliver_downcall_17);
      ProvisionalTransportService::selectorId_bufferedDataSize_downcall_10 = new LogIdSet(selector_bufferedDataSize_downcall_10);
      ProvisionalTransportService::selectorId_registerUniqueHandler_demux_21 = new LogIdSet(selector_registerUniqueHandler_demux_21);
      ProvisionalTransportService::selectorId_resumeDeliver_downcall_18 = new LogIdSet(selector_resumeDeliver_downcall_18);
      ProvisionalTransportService::selectorId_incomingBufferedDataSize_demux_28 = new LogIdSet(selector_incomingBufferedDataSize_demux_28);
      ProvisionalTransportService::selectorId_deliver_demux_3 = new LogIdSet(selector_deliver_demux_3);
      ProvisionalTransportService::selectorId_send_downcall_43 = new LogIdSet(selector_send_downcall_43);
      ProvisionalTransportService::selectorId_requestFlushedNotification_downcall_14 = new LogIdSet(selector_requestFlushedNotification_downcall_14);
      ProvisionalTransportService::selectorId_unregisterHandler_demux_20 = new LogIdSet(selector_unregisterHandler_demux_20);
      ProvisionalTransportService::selectorId_downcall_cancel_4_transition = new LogIdSet(selector_downcall_cancel_4_transition);
      ProvisionalTransportService::selectorId_registerHandler_demux_19 = new LogIdSet(selector_registerHandler_demux_19);
      ProvisionalTransportService::selectorId_deliver_demux_4 = new LogIdSet(selector_deliver_demux_4);
      ProvisionalTransportService::selectorId_setQueueSize_downcall_7 = new LogIdSet(selector_setQueueSize_downcall_7);
      ProvisionalTransportService::selectorId_incomingMessageQueueSize_demux_30 = new LogIdSet(selector_incomingMessageQueueSize_demux_30);
      ProvisionalTransportService::selectorId_route_demux_43 = new LogIdSet(selector_route_demux_43);
      ProvisionalTransportService::selectorId_registerUniqueHandler_demux_18 = new LogIdSet(selector_registerUniqueHandler_demux_18);
      ProvisionalTransportService::selectorId_maceInit_demux_48 = new LogIdSet(selector_maceInit_demux_48);
      ProvisionalTransportService::selectorId_route_downcall_29 = new LogIdSet(selector_route_downcall_29);
      
      
    }
  }
  
  void ProvisionalTransportService::sendData(
      #line 257 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1736 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_sendData_routine_0
    #define selectorId selectorId_sendData_routine_0
    ADD_LOG_BACKING
    
    
    
    #line 257 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      OutgoingConnection& c = out[dest];
      
      if (c.canceled) {
        if (downcall_routeRTS(dest, Abort(c.canceled, c.canceledRid))) {
          c.canceled = 0;
          c.canceledRid = 0;
        }
        else {
          return;
        }
      }
      
      bool accepted = true;
      while (!c.q.empty() && accepted) {
        OutgoingMessageQueue::iterator i = c.q.begin();
        message_id_t id = i->first;
        OutgoingMessageData& d = i->second;
        bool messageComplete = false;
        do {
          size_t len = std::min(BLOCK_SIZE, d.data.size() - d.offset);
          if (d.offset + len == d.data.size()) {
            accepted = downcall_routeRTS(dest, Commit(id, d.data.substr(d.offset, len), d.rid));
            if (accepted) {
              out[dest].q.erase(id);
              destinations.erase(id);
              defer_upcall_messageSent(id, d.rid);
              messageComplete = true;
            }
          }
          else {
            accepted = downcall_routeRTS(dest, Data(id, d.data.substr(d.offset, len)));
            if (accepted) {
              d.offset += len;
            }
          }
          
          if (accepted) {
            c.buffered -= len;
            updateSendable(c);
          }
        } while (accepted && !messageComplete);
      }
    }
#line 1798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
    
  }
  
  
  void ProvisionalTransportService::updateSendable(
      #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      OutgoingConnection& c
#line 1809 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_updateSendable_routine_1
    #define selectorId selectorId_updateSendable_routine_1
    ADD_LOG_BACKING
    
    
    
    #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      if (!c.sendable && (c.buffered < std::min(threshold, maxQueueSize))) {
        c.sendable = true;
      }
    }
#line 1832 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
    
  }
  
  
  size_t ProvisionalTransportService::cancel(
      #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 1843 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const OutgoingMessageData& m
#line 1847 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      message_id_t id
#line 1851 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 309 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      OutgoingConnection& c
#line 1855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_cancel_routine_2
    #define selectorId selectorId_cancel_routine_2
    ADD_LOG_BACKING
    
    
    
    #line 309 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    {
      
      if ((c.q.begin()->first == id) && (m.offset > 0)) {
        ASSERT(c.canceled == 0);
        if (!downcall_routeRTS(dest, Abort(id, m.rid))) {
          c.canceled = id;
          c.canceledRid = m.rid;
        }
      }
      size_t unsent = m.data.size() - m.offset;
      c.buffered -= unsent;
      updateSendable(c);
      c.q.erase(id);
      destinations.erase(id);
      return unsent;
    }
#line 1889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    #undef selector
    #undef selectorId
    
  }
  
  //END Mace::Compiler::ServiceImpl::printRoutines
  
  //Timer Demux (and utility timer)
  //BEGIN Mace::Compiler::ServiceImpl::printTimerDemux
  //END Mace::Compiler::ServiceImpl::printTimerDemux
  
  //Load Protocol
  
  //BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol
  BufferedTransportServiceClass& configure_new_ProvisionalTransport_BufferedTransport(bool ___shared);
  ProvisionalTransportServiceClass& configure_new_ProvisionalTransport_ProvisionalTransport(bool ___shared);
  TransportServiceClass& configure_new_ProvisionalTransport_Transport(bool ___shared);
  
  void load_protocol() {
    StringSet attr = mace::makeStringSet("ProvisionalTransport", ",");
    mace::ServiceFactory<BufferedTransportServiceClass>::registerService(&configure_new_ProvisionalTransport_BufferedTransport, "ProvisionalTransport");
    mace::ServiceConfig<BufferedTransportServiceClass>::registerService("ProvisionalTransport", attr);
    mace::ServiceFactory<ProvisionalTransportServiceClass>::registerService(&configure_new_ProvisionalTransport_ProvisionalTransport, "ProvisionalTransport");
    mace::ServiceConfig<ProvisionalTransportServiceClass>::registerService("ProvisionalTransport", attr);
    mace::ServiceFactory<TransportServiceClass>::registerService(&configure_new_ProvisionalTransport_Transport, "ProvisionalTransport");
    mace::ServiceConfig<TransportServiceClass>::registerService("ProvisionalTransport", attr);
  }
  //END Mace::Compiler::ServiceImpl::printLoadProtocol
  
  //Constructors
  //BEGIN Mace::Compiler::ServiceImpl::printConstructor
  BufferedTransportServiceClass& real_new_ProvisionalTransport_BufferedTransport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 1925 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 1929 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      , bool ___shared) {
    return *(new ProvisionalTransportService(router,maxQueueSize,queueThresholdArg,___shared));
  }
  ProvisionalTransportServiceClass& real_new_ProvisionalTransport_ProvisionalTransport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 1936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 1940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      , bool ___shared) {
    return *(new ProvisionalTransportService(router,maxQueueSize,queueThresholdArg,___shared));
  }
  TransportServiceClass& real_new_ProvisionalTransport_Transport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 1947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 1951 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      , bool ___shared) {
    return *(new ProvisionalTransportService(router,maxQueueSize,queueThresholdArg,___shared));
  }
  ProvisionalTransportService::ProvisionalTransportService(BufferedTransportServiceClass& __router, uint32_t const  _maxQueueSize, uint32_t const  _queueThresholdArg, bool ___shared) :
  //(
      BaseMaceService(), __inited(0), _actual_state(init), state(_actual_state),
      maxQueueSize(_maxQueueSize),
      queueThresholdArg(_queueThresholdArg),
      _router(__router), router(-1),
      out(),
      in(),
      destinations(),
      threshold(UINT_MAX), __local_address(MaceKey::null)
      {
        initializeSelectors();
        __local_address = computeLocalAddress();
        
        if (___shared) {
          mace::ServiceFactory<BufferedTransportServiceClass>::registerInstance("ProvisionalTransport", this);
          mace::ServiceFactory<ProvisionalTransportServiceClass>::registerInstance("ProvisionalTransport", this);
          mace::ServiceFactory<TransportServiceClass>::registerInstance("ProvisionalTransport", this);
        }
        ServiceClass::addToServiceList(*this);
        
        
        ADD_SELECTORS("ProvisionalTransport::(constructor)");
        macedbg(1) << "Created queued instance " << this << Log::endl;
      }
      //)
  ProvisionalTransportService::ProvisionalTransportService(const ProvisionalTransportService& _sv) :
  //(
      BaseMaceService(false), __inited(_sv.__inited), _actual_state(_sv.state), state(_actual_state),
      maxQueueSize(_sv.maxQueueSize),
      queueThresholdArg(_sv.queueThresholdArg),
      _router(_sv._router), router(_sv.router),
      out(_sv.out),
      in(_sv.in),
      destinations(_sv.destinations),
      threshold(_sv.threshold){
        ADD_SELECTORS("ProvisionalTransport::(constructor)");
        macedbg(1) << "Created non-queued instance " << this << Log::endl;
      }
      //)
  //END Mace::Compiler::ServiceImpl::printConstructor
  
  //Destructor
  ProvisionalTransportService::~ProvisionalTransportService() {
    
    mace::ServiceFactory<BufferedTransportServiceClass>::unregisterInstance("ProvisionalTransport", this);
    mace::ServiceFactory<ProvisionalTransportServiceClass>::unregisterInstance("ProvisionalTransport", this);
    mace::ServiceFactory<TransportServiceClass>::unregisterInstance("ProvisionalTransport", this);
  }
  
  // Methods for snapshotting...
  void ProvisionalTransportService::snapshot(const uint64_t& ver) const {
    ADD_SELECTORS("ProvisionalTransportService::snapshot");
    //Assumes state is locked.
    ProvisionalTransportService* _sv = new ProvisionalTransportService(*this);
    macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
    ASSERT(versionMap.empty() || versionMap.back().first < ver);
    versionMap.push_back(std::make_pair(ver,_sv));
  }
  void ProvisionalTransportService::snapshotRelease(const uint64_t& ver) const {
    ADD_SELECTORS("ProvisionalTransportService::snapshot");
    //Assumes state is locked.
    while (!versionMap.empty() && versionMap.front().first < ver) {
      macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
      delete versionMap.front().second;
      versionMap.pop_front();
    }
  }
  
  
  const ServiceType::state_type& ProvisionalTransportService::read_state() const {
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
  
  
  OutgoingConnectionMap const & ProvisionalTransportService::read_out() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return out;
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
      return i->second->out;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  IncomingConnectionMap const & ProvisionalTransportService::read_in() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return in;
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
      return i->second->in;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  MessageDestinationMap const & ProvisionalTransportService::read_destinations() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return destinations;
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
      return i->second->destinations;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  uint32_t const & ProvisionalTransportService::read_threshold() const {
    int currentMode = mace::AgentLock::getCurrentMode();
    if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
      return threshold;
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
      return i->second->threshold;
    }
    else {
      ABORT("Invalid attempt to access state from NONE_MODE!");
    }
  }
  
  
  //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
  void ProvisionalTransportService::dumpState(LOGLOGTYPE& logger) const {
    logger << "state_dump: " << *this << std::endl;
    return;
  }
  
  void ProvisionalTransportService::print(mace::PrintNode& __pr, const std::string& name) const {
    mace::PrintNode __printer(name, "ProvisionalTransportService");
    const char* __pr_stateName = getStateName(state);
    mace::printItem(__printer, "state", &__pr_stateName);
    mace::printItem(__printer, "out", &(out));
    mace::printItem(__printer, "in", &(in));
    mace::printItem(__printer, "destinations", &(destinations));
    mace::printItem(__printer, "threshold", &(threshold));
    
    __pr.addChild(__printer);
    return;
  }
  
  void ProvisionalTransportService::print(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    __out << "out=";  mace::printItem(__out, &(out));  __out << std::endl;
    __out << "in=";  mace::printItem(__out, &(in));  __out << std::endl;
    __out << "destinations=";  mace::printItem(__out, &(destinations));  __out << std::endl;
    __out << "threshold=";  mace::printItem(__out, &(threshold));  __out << std::endl;
    
    __out << std::endl;
    if(_printLower) {
      __out  << _router << std::endl;
    }
    return;
  }
  void ProvisionalTransportService::printState(std::ostream& __out) const {
    __out << "state=" << getStateName(state) << std::endl;
    __out << "out=";  mace::printState(__out, &(out), (out));
    __out << "in=";  mace::printState(__out, &(in), (in));
    __out << "destinations=";  mace::printState(__out, &(destinations), (destinations));
    __out << "threshold=";  mace::printState(__out, &(threshold), (threshold));
    
    __out << std::endl;
    if(_printLower) {
      _router.printState(__out);
    }
    return;
  }
  
  void ProvisionalTransportService::sqlize(mace::LogNode* __node) const {
    int _index = __node->nextIndex();
    if (_index == 0) {
      std::ostringstream __out;
      __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, state TEXT, out INT, in INT, destinations INT, threshold INT8);" << std::endl;
      __node->children = new mace::LogNode*[3];
      mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_out", Log::sqlEventsLog);
      __node->children[0] = __child0;
      mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_in", Log::sqlEventsLog);
      __node->children[1] = __child1;
      mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_destinations", Log::sqlEventsLog);
      __node->children[2] = __child2;
      Log::logSqlCreate(__out.str(), __node);
    }
    int _outIndex = __node->children[0]->nextId;
    int _inIndex = __node->children[1]->nextId;
    int _destinationsIndex = __node->children[2]->nextId;
    std::ostringstream __out;
    __out << __node->logId << "\t" << _index << "\t" << getStateName(state);
    __out << "\t" << _outIndex;
    __out << "\t" << _inIndex;
    __out << "\t" << _destinationsIndex;
    __out << "\t" << threshold;
    __out << std::endl;
    ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
    mace::sqlize(&out, __node->children[0]);
    mace::sqlize(&in, __node->children[1]);
    mace::sqlize(&destinations, __node->children[2]);
    
  }
  
  void ProvisionalTransportService::serialize(std::string& __str) const {
    mace::serialize(__str, &state);
    
    #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::serialize(__str, &out);
#line 2242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::serialize(__str, &in);
#line 2247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::serialize(__str, &destinations);
#line 2252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 86 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::serialize(__str, &threshold);
#line 2257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    
    mace::serialize( __str, &__local_address );
    return;
  }
  
  int ProvisionalTransportService::deserialize(std::istream& __in) throw(SerializationException){
    int serializedByteSize = 0;
    serializedByteSize += mace::deserialize(__in, &_actual_state);
    
    #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    serializedByteSize +=  mace::deserialize(__in, &out);
#line 2271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    serializedByteSize +=  mace::deserialize(__in, &in);
#line 2276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    serializedByteSize +=  mace::deserialize(__in, &destinations);
#line 2281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    #line 86 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    serializedByteSize +=  mace::deserialize(__in, &threshold);
#line 2286 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
    
    
    
    
    MaceKey oldLocalAddress;
    serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
    updateInternalContext( oldLocalAddress, __local_address );
    
    return serializedByteSize;
  }
  void ProvisionalTransportService::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
    
  }
  
  void ProvisionalTransportService::processDeferred() { while (!__deferralArgList_messageSent_message_id_t___registration_uid_t__.empty()) {
      uint64_t _firstcall = std::numeric_limits<uint64_t>::max();
      if (!__deferralArgList_messageSent_message_id_t___registration_uid_t__.empty()) { _firstcall = std::min(_firstcall, __deferralArgList_messageSent_message_id_t___registration_uid_t__.front().__calltime); }
      if (!__deferralArgList_messageSent_message_id_t___registration_uid_t__.empty() && _firstcall == __deferralArgList_messageSent_message_id_t___registration_uid_t__.front().__calltime) {
        __DeferralArgsFormessageSent_message_id_t___registration_uid_t__& a = __deferralArgList_messageSent_message_id_t___registration_uid_t__.front();
        upcall_messageSent(a.id, a.rid);
        __deferralArgList_messageSent_message_id_t___registration_uid_t__.pop_front();
      }
    }
  }
  const char* ProvisionalTransportService::getMessageName(uint8_t messageType) const {
    switch(messageType) {
      case Data::messageType: return "ProvisionalTransport::Data";
      case Commit::messageType: return "ProvisionalTransport::Commit";
      case Abort::messageType: return "ProvisionalTransport::Abort";
      default: ASSERT(false); return "INVALID MESSAGE NUMBER";
    }
  }
  void ProvisionalTransportService::changeState(state_type stateNum, int selectorId) {
    _actual_state = stateNum;
    
  }
  const char* ProvisionalTransportService::getStateName(state_type state) const {
    switch(static_cast<uint64_t>(state)) {
      case init: return "ProvisionalTransport::init";
      case exited: return "ProvisionalTransport::exited";
      default: ASSERT(false); return "INVALID STATE NUMBER";
    }
  }
  
  //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
  //BEGIN Mace::Compiler::ServiceImpl::printAPIDemux
  message_id_t ProvisionalTransportService::provisionalRoute(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const MaceKey& dest
#line 2336 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const std::string& s
#line 2340 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      registration_uid_t rid
#line 2344 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_provisionalRoute_demux_9
    #define selectorId selectorId_provisionalRoute_demux_9
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method provisionalRoute in base class ProvisionalTransportServiceClass called."); }
#line 2368 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_1_provisionalRoute(dest,s,rid)) {
      
      
      
      return downcall_1_provisionalRoute(dest,s,rid);
    } else
    {
      
      #line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method provisionalRoute in base class ProvisionalTransportServiceClass called."); }
#line 2381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  size_t ProvisionalTransportService::cancel(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      message_id_t id
#line 2392 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      registration_uid_t rid
#line 2396 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_cancel_demux_10
    #define selectorId selectorId_cancel_demux_10
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method cancel in base class ProvisionalTransportServiceClass called."); }
#line 2420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_4_cancel(id)) {
      
      
      
      return downcall_4_cancel(id);
    } else
    {
      
      #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method cancel in base class ProvisionalTransportServiceClass called."); }
#line 2433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  message_id_t ProvisionalTransportService::cancelFront(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const MaceKey& dest
#line 2444 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      registration_uid_t rid
#line 2448 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_cancelFront_demux_11
    #define selectorId selectorId_cancelFront_demux_11
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method cancelFront in base class ProvisionalTransportServiceClass called."); }
#line 2472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_3_cancelFront(dest)) {
      
      
      
      return downcall_3_cancelFront(dest);
    } else
    {
      
      #line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method cancelFront in base class ProvisionalTransportServiceClass called."); }
#line 2485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::messageStatus(
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      message_id_t id
#line 2496 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      uint32_t& size
#line 2500 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      uint32_t& sent
#line 2504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      registration_uid_t rid
#line 2508 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) const {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_messageStatus_demux_12
    #define selectorId selectorId_messageStatus_demux_12
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method messageStatus in base class ProvisionalTransportServiceClass called."); }
#line 2532 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_8_messageStatus(id,size,sent)) {
      
      
      
      downcall_8_messageStatus(id,size,sent);
    } else
    {
      
      #line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      { ABORT("Unimplemented method messageStatus in base class ProvisionalTransportServiceClass called."); }
#line 2545 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::canSend(
      #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2556 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2560 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_canSend_demux_25
    #define selectorId selectorId_canSend_demux_25
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method canSend in base class BufferedTransportServiceClass called."); }
#line 2584 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_5_canSend(peer)) {
      
      
      
      return downcall_5_canSend(peer);
    } else
    {
      
      #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method canSend in base class BufferedTransportServiceClass called."); }
#line 2597 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::availableBufferSize(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2612 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_availableBufferSize_demux_26
    #define selectorId selectorId_availableBufferSize_demux_26
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method availableBufferSize in base class BufferedTransportServiceClass called."); }
#line 2636 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_6_availableBufferSize(peer)) {
      
      
      
      return downcall_6_availableBufferSize(peer);
    } else
    {
      
      #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method availableBufferSize in base class BufferedTransportServiceClass called."); }
#line 2649 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::outgoingBufferedDataSize(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2660 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_outgoingBufferedDataSize_demux_27
    #define selectorId selectorId_outgoingBufferedDataSize_demux_27
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 2686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::incomingBufferedDataSize(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2697 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2701 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_incomingBufferedDataSize_demux_28
    #define selectorId selectorId_incomingBufferedDataSize_demux_28
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method incomingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 2725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_7_incomingBufferedDataSize(peer)) {
      
      
      
      return downcall_7_incomingBufferedDataSize(peer);
    } else
    {
      
      #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method incomingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 2738 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::incomingMessageQueueSize(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2749 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_incomingMessageQueueSize_demux_29
    #define selectorId selectorId_incomingMessageQueueSize_demux_29
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 2775 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::incomingMessageQueueSize(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 2786 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_incomingMessageQueueSize_demux_30
    #define selectorId selectorId_incomingMessageQueueSize_demux_30
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 2808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::setWindowSize(
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint64_t microsec
#line 2823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_setWindowSize_demux_31
    #define selectorId selectorId_setWindowSize_demux_31
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method setWindowSize in base class BufferedTransportServiceClass called."); }
#line 2849 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::setQueueSize(
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2860 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t size
#line 2864 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t threshold
#line 2868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_setQueueSize_demux_32
    #define selectorId selectorId_setQueueSize_demux_32
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method setQueueSize in base class BufferedTransportServiceClass called."); }
#line 2894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  const BufferStatisticsPtr ProvisionalTransportService::getStatistics(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2905 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      TransportServiceClass::Connection::type d
#line 2909 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2913 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_getStatistics_demux_33
    #define selectorId selectorId_getStatistics_demux_33
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method getStatistics in base class BufferedTransportServiceClass called."); }
#line 2935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::requestToSend(
      #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 2946 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 2950 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_requestToSend_demux_34
    #define selectorId selectorId_requestToSend_demux_34
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method requestToSend in base class BufferedTransportServiceClass called."); }
#line 2972 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::bufferedDataSize(
      #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 2983 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_bufferedDataSize_demux_35
    #define selectorId selectorId_bufferedDataSize_demux_35
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method bufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 3005 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::hasBufferedData(
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 3016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_hasBufferedData_demux_36
    #define selectorId selectorId_hasBufferedData_demux_36
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method hasBufferedData in base class BufferedTransportServiceClass called."); }
#line 3038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::hasOutgoingBufferedData(
      #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 3049 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_hasOutgoingBufferedData_demux_37
    #define selectorId selectorId_hasOutgoingBufferedData_demux_37
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method hasOutgoingBufferedData in base class BufferedTransportServiceClass called."); }
#line 3071 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::outgoingBufferedDataSize(
      #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 3082 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_outgoingBufferedDataSize_demux_38
    #define selectorId selectorId_outgoingBufferedDataSize_demux_38
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 3104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::routeRTS(
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 3115 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 3119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 3123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_routeRTS_demux_39
    #define selectorId selectorId_routeRTS_demux_39
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 3145 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::routeRTS(
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& src
#line 3156 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 3160 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 3164 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 3168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_routeRTS_demux_40
    #define selectorId selectorId_routeRTS_demux_40
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 3190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::requestFlushedNotification(
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 3201 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_requestFlushedNotification_demux_41
    #define selectorId selectorId_requestFlushedNotification_demux_41
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      { ABORT("Unimplemented method requestFlushedNotification in base class BufferedTransportServiceClass called."); }
#line 3223 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::route(
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 3234 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 3238 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 3242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_route_demux_42
    #define selectorId selectorId_route_demux_42
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 3266 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_downcall_2_route(dest,s,rid)) {
      
      
      
      return downcall_2_route(dest,s,rid);
    } else
    {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { return false; }
#line 3279 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::route(
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& src
#line 3290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 3294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 3298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 3302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_route_demux_43
    #define selectorId selectorId_route_demux_43
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      {
        return false;
      }
#line 3326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 3337 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_suspendDeliver_demux_44
    #define selectorId selectorId_suspendDeliver_demux_44
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 3359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 3370 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 3374 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_suspendDeliver_demux_45
    #define selectorId selectorId_suspendDeliver_demux_45
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 3396 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 3407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_resumeDeliver_demux_46
    #define selectorId selectorId_resumeDeliver_demux_46
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 3429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 3440 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 3444 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_resumeDeliver_demux_47
    #define selectorId selectorId_resumeDeliver_demux_47
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 3466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::maceInit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceInit_demux_48
    #define selectorId selectorId_maceInit_demux_48
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    
    if(__inited++ == 0) {
      //TODO: start utility timer as necessary
      
      _router.maceInit();
      if (router == -1) {
        router  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
      }
      
      
      _router.registerHandler((ReceiveDataHandler&)*this, router);
      _router.registerHandler((NetworkErrorHandler&)*this, router);
      _router.registerHandler((ConnectionStatusHandler&)*this, router);
      
      if(state == exited) {
        
        #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 3509 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
      } else
      if(guard_downcall_0_maceInit()) {
        
        
        
        downcall_0_maceInit();
      } else
      {
        
        #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 3522 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::maceResume() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceResume_demux_49
    #define selectorId selectorId_maceResume_demux_49
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    
    if(__inited++ == 0) {
      //TODO: start utility timer as necessary
      
      _router.maceInit();
      if (router == -1) {
        router  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
      }
      
      
      _router.registerHandler((ReceiveDataHandler&)*this, router);
      _router.registerHandler((NetworkErrorHandler&)*this, router);
      _router.registerHandler((ConnectionStatusHandler&)*this, router);
      
      {
        
        #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 3567 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
      }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::maceExit() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceExit_demux_50
    #define selectorId selectorId_maceExit_demux_50
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    
    if(--__inited == 0) {
      {
        
        #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 3600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
      }
      
      //TODO: stop utility timer as necessary
      _actual_state = exited;
      
      _router.unregisterHandler((ReceiveDataHandler&)*this, router);
      _router.unregisterHandler((NetworkErrorHandler&)*this, router);
      _router.unregisterHandler((ConnectionStatusHandler&)*this, router);
      
      _router.maceExit();
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::maceReset() {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_maceReset_demux_51
    #define selectorId selectorId_maceReset_demux_51
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
      { }
#line 3640 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    //TODO: stop utility timer as necessary
    _actual_state = init;
    
    map_ReceiveDataHandler.clear();
    map_NetworkErrorHandler.clear();
    map_ConnectionStatusHandler.clear();
    map_MessageStatusHandler.clear();
    
    _router.maceReset();
    out = OutgoingConnectionMap();
    in = IncomingConnectionMap();
    destinations = MessageDestinationMap();
    threshold = UINT_MAX;
    
    __inited = 0;
    
    #undef selector
    #undef selectorId
    
  }
  const MaceKey& ProvisionalTransportService::localAddress() const {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_localAddress_demux_52
    #define selectorId selectorId_localAddress_demux_52
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      { return __local_address; }
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::hashState() const {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_hashState_demux_53
    #define selectorId selectorId_hashState_demux_53
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
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
  registration_uid_t ProvisionalTransportService::registerHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ReceiveDataHandler.find(regId) == map_ReceiveDataHandler.end());
    map_ReceiveDataHandler[regId] = &handler;
    return regId;
  }
  
  void ProvisionalTransportService::registerUniqueHandler(ReceiveDataHandler& handler) {
    ASSERT(map_ReceiveDataHandler.empty());
    map_ReceiveDataHandler[-1] = &handler;
  }
  
  void ProvisionalTransportService::unregisterHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
    ASSERT(map_ReceiveDataHandler[regId] == &handler);
    map_ReceiveDataHandler.erase(regId);
  }
  registration_uid_t ProvisionalTransportService::registerHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_NetworkErrorHandler.find(regId) == map_NetworkErrorHandler.end());
    map_NetworkErrorHandler[regId] = &handler;
    return regId;
  }
  
  void ProvisionalTransportService::registerUniqueHandler(NetworkErrorHandler& handler) {
    ASSERT(map_NetworkErrorHandler.empty());
    map_NetworkErrorHandler[-1] = &handler;
  }
  
  void ProvisionalTransportService::unregisterHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
    ASSERT(map_NetworkErrorHandler[regId] == &handler);
    map_NetworkErrorHandler.erase(regId);
  }
  registration_uid_t ProvisionalTransportService::registerHandler(ConnectionStatusHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_ConnectionStatusHandler.find(regId) == map_ConnectionStatusHandler.end());
    map_ConnectionStatusHandler[regId] = &handler;
    return regId;
  }
  
  void ProvisionalTransportService::registerUniqueHandler(ConnectionStatusHandler& handler) {
    ASSERT(map_ConnectionStatusHandler.empty());
    map_ConnectionStatusHandler[-1] = &handler;
  }
  
  void ProvisionalTransportService::unregisterHandler(ConnectionStatusHandler& handler, registration_uid_t regId) {
    ASSERT(map_ConnectionStatusHandler[regId] == &handler);
    map_ConnectionStatusHandler.erase(regId);
  }
  registration_uid_t ProvisionalTransportService::registerHandler(MessageStatusHandler& handler, registration_uid_t regId) {
    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
    
    ASSERT(map_MessageStatusHandler.find(regId) == map_MessageStatusHandler.end());
    map_MessageStatusHandler[regId] = &handler;
    return regId;
  }
  
  void ProvisionalTransportService::registerUniqueHandler(MessageStatusHandler& handler) {
    ASSERT(map_MessageStatusHandler.empty());
    map_MessageStatusHandler[-1] = &handler;
  }
  
  void ProvisionalTransportService::unregisterHandler(MessageStatusHandler& handler, registration_uid_t regId) {
    ASSERT(map_MessageStatusHandler[regId] == &handler);
    map_MessageStatusHandler.erase(regId);
  }
  //END Mace::Compiler::ServiceImpl::printHandlerRegistrations
  
  //Handler demux (uses handlers)
  //BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux
  void ProvisionalTransportService::error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 3806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 3810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 3814 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 3818 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
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
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 3843 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_9_error(nodeId,errorCode,message)) {
      
      
      
      upcall_9_error(nodeId,errorCode,message);
    } else
    {
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 3856 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::clearToSend(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      const MaceKey& peer
#line 3867 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      registration_uid_t rid
#line 3871 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_clearToSend_demux_1
    #define selectorId selectorId_clearToSend_demux_1
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      { ABORT("Unimplemented method clearToSend in base class ConnectionStatusHandler called."); }
#line 3895 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_13_clearToSend(peer)) {
      
      
      
      upcall_13_clearToSend(peer);
    } else
    {
      
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      { ABORT("Unimplemented method clearToSend in base class ConnectionStatusHandler called."); }
#line 3908 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::notifyFlushed(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      registration_uid_t rid
#line 3919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_notifyFlushed_demux_2
    #define selectorId selectorId_notifyFlushed_demux_2
    ADD_LOG_BACKING
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    {
      
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      { ABORT("Unimplemented method notifyFlushed in base class ConnectionStatusHandler called."); }
#line 3941 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& source
#line 3952 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& destination
#line 3956 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 3960 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 3964 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_deliver_demux_3
    #define selectorId selectorId_deliver_demux_3
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 3988 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_10_deliver(source,destination,s_deserialized)) {
      
      
      
      upcall_10_deliver(source,destination,s_deserialized);
    } else
    {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 4001 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& source
#line 4012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& destination
#line 4016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 4020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 4024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_deliver_demux_4
    #define selectorId selectorId_deliver_demux_4
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 4048 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_11_deliver(source,destination,s_deserialized)) {
      
      
      
      upcall_11_deliver(source,destination,s_deserialized);
    } else
    {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 4061 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& source
#line 4072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& destination
#line 4076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 4080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 4084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_deliver_demux_5
    #define selectorId selectorId_deliver_demux_5
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 4108 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_12_deliver(source,destination,s_deserialized)) {
      
      
      
      upcall_12_deliver(source,destination,s_deserialized);
    } else
    {
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 4121 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 4132 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 4136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& message_deserialized
#line 4140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 4144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_messageError_demux_6
    #define selectorId selectorId_messageError_demux_6
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_14_messageError(dest,errorCode,message_deserialized,rid)) {
      
      
      
      upcall_14_messageError(dest,errorCode,message_deserialized,rid);
    } else
    {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 4192 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 4196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& message_deserialized
#line 4200 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 4204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_messageError_demux_7
    #define selectorId selectorId_messageError_demux_7
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4228 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_15_messageError(dest,errorCode,message_deserialized,rid)) {
      
      
      
      upcall_15_messageError(dest,errorCode,message_deserialized,rid);
    } else
    {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4241 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 4252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 4256 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& message_deserialized
#line 4260 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 4264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = 1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    PREPARE_FUNCTION
    #define selector selector_messageError_demux_8
    #define selectorId selectorId_messageError_demux_8
    ADD_LOG_BACKING
    
    mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
    mace::ScopedFingerprint __fingerprint(selector);
    mace::ScopedStackExecution __defer;
    
    
    if(state == exited) {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    } else
    if(guard_upcall_16_messageError(dest,errorCode,message_deserialized,rid)) {
      
      
      
      upcall_16_messageError(dest,errorCode,message_deserialized,rid);
    } else
    {
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 4301 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printHandlerDemux
  
  //Downcall helpers (uses)
  //BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers
  
  MaceKey ProvisionalTransportService::downcall_localAddress() const {
    return _router.localAddress();
  }
  const MaceKey& ProvisionalTransportService::downcall_localAddress(const registration_uid_t& rid) const {
    
    if (&rid == &router) {
      return _router.localAddress();
    }
    
    if (rid == router) {
      return _router.localAddress();
    }
    return MaceKey::null;
  }
  bool ProvisionalTransportService::downcall_canSend(
      #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_canSend_downcall_0
    #define selectorId selectorId_canSend_downcall_0
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.canSend(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_availableBufferSize(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4371 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_availableBufferSize_downcall_1
    #define selectorId selectorId_availableBufferSize_downcall_1
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.availableBufferSize(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_outgoingBufferedDataSize(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_outgoingBufferedDataSize_downcall_2
    #define selectorId selectorId_outgoingBufferedDataSize_downcall_2
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.outgoingBufferedDataSize(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_incomingBufferedDataSize(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4439 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_incomingBufferedDataSize_downcall_3
    #define selectorId selectorId_incomingBufferedDataSize_downcall_3
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.incomingBufferedDataSize(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_incomingMessageQueueSize(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4475 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_incomingMessageQueueSize_downcall_4
    #define selectorId selectorId_incomingMessageQueueSize_downcall_4
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.incomingMessageQueueSize(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_incomingMessageQueueSize(
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_incomingMessageQueueSize_downcall_5
    #define selectorId selectorId_incomingMessageQueueSize_downcall_5
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.incomingMessageQueueSize(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_setWindowSize(
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4543 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint64_t microsec
#line 4547 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_setWindowSize_downcall_6
    #define selectorId selectorId_setWindowSize_downcall_6
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.setWindowSize(peer,microsec,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_setQueueSize(
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4583 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t size
#line 4587 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t threshold
#line 4591 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4595 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_setQueueSize_downcall_7
    #define selectorId selectorId_setQueueSize_downcall_7
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.setQueueSize(peer,size,threshold,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  const BufferStatisticsPtr ProvisionalTransportService::downcall_getStatistics(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4627 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      TransportServiceClass::Connection::type d
#line 4631 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4635 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_getStatistics_downcall_8
    #define selectorId selectorId_getStatistics_downcall_8
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.getStatistics(peer,d,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_requestToSend(
      #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 4667 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      registration_uid_t rid
#line 4671 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_requestToSend_downcall_9
    #define selectorId selectorId_requestToSend_downcall_9
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.requestToSend(peer,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_bufferedDataSize(
      #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_bufferedDataSize_downcall_10
    #define selectorId selectorId_bufferedDataSize_downcall_10
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.bufferedDataSize(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_hasBufferedData(
      #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_hasBufferedData_downcall_11
    #define selectorId selectorId_hasBufferedData_downcall_11
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.hasBufferedData(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_hasOutgoingBufferedData(
      #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4767 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_hasOutgoingBufferedData_downcall_12
    #define selectorId selectorId_hasOutgoingBufferedData_downcall_12
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.hasOutgoingBufferedData(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  uint32_t ProvisionalTransportService::downcall_outgoingBufferedDataSize(
      #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4799 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_outgoingBufferedDataSize_downcall_13
    #define selectorId selectorId_outgoingBufferedDataSize_downcall_13
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.outgoingBufferedDataSize(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_requestFlushedNotification(
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      registration_uid_t rid
#line 4831 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_requestFlushedNotification_downcall_14
    #define selectorId selectorId_requestFlushedNotification_downcall_14
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.requestFlushedNotification(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_suspendDeliver(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 4863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_15
    #define selectorId selectorId_suspendDeliver_downcall_15
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.suspendDeliver(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 4895 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 4899 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_suspendDeliver_downcall_16
    #define selectorId selectorId_suspendDeliver_downcall_16
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.suspendDeliver(dest,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_resumeDeliver(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      registration_uid_t rid
#line 4931 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_17
    #define selectorId selectorId_resumeDeliver_downcall_17
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.resumeDeliver(rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::downcall_resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 4963 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      registration_uid_t rid
#line 4967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_resumeDeliver_downcall_18
    #define selectorId selectorId_resumeDeliver_downcall_18
    ADD_LOG_BACKING
    
    
    
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      _router.resumeDeliver(dest,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 4999 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Message& s_deserialized
#line 5003 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5007 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_19
    #define selectorId selectorId_routeRTS_downcall_19
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5041 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 5045 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5049 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_20
    #define selectorId selectorId_routeRTS_downcall_20
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5083 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 5087 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5091 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_21
    #define selectorId selectorId_routeRTS_downcall_21
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Commit> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5125 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 5129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_22
    #define selectorId selectorId_routeRTS_downcall_22
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Abort> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5171 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Message& s_deserialized
#line 5175 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5179 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_23
    #define selectorId selectorId_routeRTS_downcall_23
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5213 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5217 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 5221 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_24
    #define selectorId selectorId_routeRTS_downcall_24
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5259 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 5267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_25
    #define selectorId selectorId_routeRTS_downcall_25
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Commit> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_routeRTS(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5305 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5309 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 5313 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5317 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_routeRTS_downcall_26
    #define selectorId selectorId_routeRTS_downcall_26
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Abort> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.routeRTS(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Message& s_deserialized
#line 5355 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_27
    #define selectorId selectorId_route_downcall_27
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5393 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 5397 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5401 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_28
    #define selectorId selectorId_route_downcall_28
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5435 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 5439 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_29
    #define selectorId selectorId_route_downcall_29
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Commit> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5477 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 5481 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_30
    #define selectorId selectorId_route_downcall_30
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Abort> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5523 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Message& s_deserialized
#line 5527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_31
    #define selectorId selectorId_route_downcall_31
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5565 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5569 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 5573 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5577 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_32
    #define selectorId selectorId_route_downcall_32
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5611 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5615 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 5619 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5623 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_33
    #define selectorId selectorId_route_downcall_33
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Commit> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  bool ProvisionalTransportService::downcall_route(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& src
#line 5657 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5661 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 5665 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5669 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_route_downcall_34
    #define selectorId selectorId_route_downcall_34
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Abort> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.route(src,dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t ProvisionalTransportService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Message& s_deserialized
#line 5707 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_35
    #define selectorId selectorId_send_downcall_35
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t ProvisionalTransportService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5745 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Data& s_deserialized
#line 5749 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_36
    #define selectorId selectorId_send_downcall_36
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Data> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t ProvisionalTransportService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Commit& s_deserialized
#line 5791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_37
    #define selectorId selectorId_send_downcall_37
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Commit> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  size_t ProvisionalTransportService::downcall_send(
      #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 5829 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const Abort& s_deserialized
#line 5833 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 5837 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_send_downcall_38
    #define selectorId selectorId_send_downcall_38
    ADD_LOG_BACKING
    
    
    
    std::string s;
    ScopedSerialize<std::string, Abort> __ss_s_deserialized(s, s_deserialized);
    
    if(rid == -1) { rid = router; }
    
    if(rid == router) {
      return _router.send(dest,s,rid);
    } else
    { ABORT("Did not match any registration uid!"); }
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printDowncallHelpers
  
  //Upcall helpers (provides handlers)
  //BEGIN Mace::Compiler::ServiceImpl::printUpcallHelpers
  void ProvisionalTransportService::defer_upcall_messageSent(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      message_id_t id
#line 5875 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      registration_uid_t rid
#line 5879 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) { mace::ScopedStackExecution::addDefer(this); __deferralArgList_messageSent_message_id_t___registration_uid_t__.push_back(__DeferralArgsFormessageSent_message_id_t___registration_uid_t__(id,rid)); }void ProvisionalTransportService::upcall_deliver(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& source
#line 5883 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const MaceKey& destination
#line 5887 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      const std::string& s
#line 5891 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 5895 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_deliver_upcall_0
    #define selectorId selectorId_deliver_upcall_0
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_ReceiveDataHandler::iterator iter = map_ReceiveDataHandler.find(rid);
    if(iter == map_ReceiveDataHandler.end()) {
      maceWarn("No ReceiveDataHandler registered with uid %"PRIi32" for upcall deliver!", rid);
      
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
      { }
#line 5920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->deliver(source,destination,s,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_error(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& nodeId
#line 5935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 5939 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 5943 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 5947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
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
    
    
    
    
    
    maptype_NetworkErrorHandler::iterator iter = map_NetworkErrorHandler.find(rid);
    if(iter == map_NetworkErrorHandler.end()) {
      maceWarn("No NetworkErrorHandler registered with uid %"PRIi32" for upcall error!", rid);
      
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 5974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->error(nodeId,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_messageError(
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const MaceKey& dest
#line 5989 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      TransportError::type errorCode
#line 5993 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      const std::string& message
#line 5997 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
      registration_uid_t rid
#line 6001 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageError_upcall_2
    #define selectorId selectorId_messageError_upcall_2
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_NetworkErrorHandler::iterator iter = map_NetworkErrorHandler.find(rid);
    if(iter == map_NetworkErrorHandler.end()) {
      maceWarn("No NetworkErrorHandler registered with uid %"PRIi32" for upcall messageError!", rid);
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 6026 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->messageError(dest,errorCode,message,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_clearToSend(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      const MaceKey& peer
#line 6041 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      registration_uid_t rid
#line 6045 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_clearToSend_upcall_3
    #define selectorId selectorId_clearToSend_upcall_3
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_ConnectionStatusHandler::iterator iter = map_ConnectionStatusHandler.find(rid);
    if(iter == map_ConnectionStatusHandler.end()) {
      maceWarn("No ConnectionStatusHandler registered with uid %"PRIi32" for upcall clearToSend!", rid);
      
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      { ABORT("Unimplemented method clearToSend in base class ConnectionStatusHandler called."); }
#line 6070 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->clearToSend(peer,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_notifyFlushed(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      registration_uid_t rid
#line 6085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_notifyFlushed_upcall_4
    #define selectorId selectorId_notifyFlushed_upcall_4
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_ConnectionStatusHandler::iterator iter = map_ConnectionStatusHandler.find(rid);
    if(iter == map_ConnectionStatusHandler.end()) {
      maceWarn("No ConnectionStatusHandler registered with uid %"PRIi32" for upcall notifyFlushed!", rid);
      
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      { ABORT("Unimplemented method notifyFlushed in base class ConnectionStatusHandler called."); }
#line 6110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->notifyFlushed(rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_messageSent(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      message_id_t id
#line 6125 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      registration_uid_t rid
#line 6129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageSent_upcall_5
    #define selectorId selectorId_messageSent_upcall_5
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_MessageStatusHandler::iterator iter = map_MessageStatusHandler.find(rid);
    if(iter == map_MessageStatusHandler.end()) {
      maceWarn("No MessageStatusHandler registered with uid %"PRIi32" for upcall messageSent!", rid);
      
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      { }
#line 6154 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->messageSent(id,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::upcall_messageCanceled(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      const MaceKey& src
#line 6169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      uint32_t bytes
#line 6173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      registration_uid_t rid
#line 6177 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageCanceled_upcall_6
    #define selectorId selectorId_messageCanceled_upcall_6
    ADD_LOG_BACKING
    
    
    
    
    
    maptype_MessageStatusHandler::iterator iter = map_MessageStatusHandler.find(rid);
    if(iter == map_MessageStatusHandler.end()) {
      maceWarn("No MessageStatusHandler registered with uid %"PRIi32" for upcall messageCanceled!", rid);
      
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      { }
#line 6202 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      
    }
    else {
      iter->second->messageCanceled(src,bytes,rid);
    }
    
    
    #undef selector
    #undef selectorId
    
  }
  //END Mace::Compiler::ServiceImpl::printUpcallHelpers
  
  //Async helpers
  
  //Serial Helper Demux
  //BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux
  void ProvisionalTransportService::deliver(
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& source
#line 6223 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& destination
#line 6227 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const std::string& s
#line 6231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
      registration_uid_t rid
#line 6235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_deliver_demux_54
    #define selectorId selectorId_deliver_demux_54
    ADD_LOG_BACKING
    
    
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
      
      case Commit::messageType: {
        Commit s_deserialized;
        s_deserialized.deserializeStr(s);
        //TODO -- trace msg
        
        deliver(source,destination,s_deserialized,rid);
        
      }
      break;
      
      case Abort::messageType: {
        Abort s_deserialized;
        s_deserialized.deserializeStr(s);
        //TODO -- trace msg
        
        deliver(source,destination,s_deserialized,rid);
        
      }
      break;
      default: {
        maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 6292 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
        ABORT("INVALID MESSAGE NUMBER");
      }
      break;
    }
    
    #undef selector
    #undef selectorId
    
  }
  void ProvisionalTransportService::messageError(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const MaceKey& dest
#line 6306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      TransportError::type errorCode
#line 6310 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      const std::string& message
#line 6314 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
      ,
      #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      registration_uid_t rid
#line 6318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
  ) {
    // Method.pm:toString()
    
    __eventContextType = -1;
    
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    #define selector selector_messageError_demux_55
    #define selectorId selectorId_messageError_demux_55
    ADD_LOG_BACKING
    
    
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
      
      case Commit::messageType: {
        Commit message_deserialized;
        message_deserialized.deserializeStr(message);
        //TODO -- trace msg
        
        messageError(dest,errorCode,message_deserialized,rid);
        
      }
      break;
      
      case Abort::messageType: {
        Abort message_deserialized;
        message_deserialized.deserializeStr(message);
        //TODO -- trace msg
        
        messageError(dest,errorCode,message_deserialized,rid);
        
      }
      break;
      default: {
        maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 6375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.cc"
        
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
