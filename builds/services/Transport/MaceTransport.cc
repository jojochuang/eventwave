/*********************************************
*  MaceTransport main source file
*  Mace generated on:
*  Tue Apr 10 10:09:54 2012
*********************************************/
//BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"
#include "SimulatorBasics.h"
#include "MaceTransport.h"
#include "MaceTransport-macros.h"
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

bool operator==(const mace::map<int, mace::map<int, MaceTransport_namespace::MaceTransportService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, MaceTransport_namespace::MaceTransportService*, mace::SoftState>::const_iterator& rhs) {
  return lhs->second == rhs;
}
bool operator==(const mace::map<int, MaceTransport_namespace::MaceTransportService*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, MaceTransport_namespace::MaceTransportService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
  return lhs == rhs->second;
}
namespace mace {
  template<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;
}
namespace MaceTransport_namespace {
  mace::LogNode* MaceTransportService::rootLogNode = NULL;
  //    mace::LogNode* MaceTransportDummy::rootLogNode = NULL;
  //Selector Constants
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //const std::string selector_maceResume_demux_44;
  const LogIdSet* MaceTransportService::selectorId_maceResume_demux_44;
  //const std::string selector_registerUniqueHandler_demux_30;
  const LogIdSet* MaceTransportService::selectorId_registerUniqueHandler_demux_30;
  //const std::string selector_expire_localTimer_demux_50;
  const LogIdSet* MaceTransportService::selectorId_expire_localTimer_demux_50;
  //const std::string selector_checkAndNotifyFlushed_routine_16;
  const LogIdSet* MaceTransportService::selectorId_checkAndNotifyFlushed_routine_16;
  //const std::string selector_deliver_demux_52;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_52;
  //const std::string selector_route_downcall_6;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_6;
  //const std::string selector_cancelretransmissionTimer;
  const LogIdSet* MaceTransportService::selectorId_cancelretransmissionTimer;
  //const std::string selector_upcall_messageError_20_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_messageError_20_transition;
  //const std::string selector_upcallDeliver_routine_5;
  const LogIdSet* MaceTransportService::selectorId_upcallDeliver_routine_5;
  //const std::string selector_downcall_requestToSend_10_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_requestToSend_10_transition;
  //const std::string selector_send_downcall_18;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_18;
  //const std::string selector_incomingBufferedDataSize_demux_14;
  const LogIdSet* MaceTransportService::selectorId_incomingBufferedDataSize_demux_14;
  //const std::string selector_scheduler_expire_retransmissionTimer_17_transition;
  const LogIdSet* MaceTransportService::selectorId_scheduler_expire_retransmissionTimer_17_transition;
  //const std::string selector_canSend_demux_11;
  const LogIdSet* MaceTransportService::selectorId_canSend_demux_11;
  //const std::string selector_cancelctsTimer;
  const LogIdSet* MaceTransportService::selectorId_cancelctsTimer;
  //const std::string selector_upcall_deliver_14_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_deliver_14_transition;
  //const std::string selector_expirelocalTimer;
  const LogIdSet* MaceTransportService::selectorId_expirelocalTimer;
  //const std::string selector_route_downcall_10;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_10;
  //const std::string selector_clearToSend_upcall_3;
  const LogIdSet* MaceTransportService::selectorId_clearToSend_upcall_3;
  //const std::string selector_route_demux_38;
  const LogIdSet* MaceTransportService::selectorId_route_demux_38;
  //const std::string selector_getStatistics_demux_19;
  const LogIdSet* MaceTransportService::selectorId_getStatistics_demux_19;
  //const std::string selector_checkRetransmissionTimer_routine_19;
  const LogIdSet* MaceTransportService::selectorId_checkRetransmissionTimer_routine_19;
  //const std::string selector_resumeDeliver_demux_42;
  const LogIdSet* MaceTransportService::selectorId_resumeDeliver_demux_42;
  //const std::string selector_downcall_routeRTS_11_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_routeRTS_11_transition;
  //const std::string selector_registerUniqueHandler_demux_36;
  const LogIdSet* MaceTransportService::selectorId_registerUniqueHandler_demux_36;
  //const std::string selector_hasBufferedData_demux_22;
  const LogIdSet* MaceTransportService::selectorId_hasBufferedData_demux_22;
  //const std::string selector_downcall_hasOutgoingBufferedData_3_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_hasOutgoingBufferedData_3_transition;
  //const std::string selector_expire_retransmissionTimer_demux_49;
  const LogIdSet* MaceTransportService::selectorId_expire_retransmissionTimer_demux_49;
  //const std::string selector_deliver_demux_2;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_2;
  //const std::string selector_send_downcall_16;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_16;
  //const std::string selector_enqueue_routine_14;
  const LogIdSet* MaceTransportService::selectorId_enqueue_routine_14;
  //const std::string selector_upcallMessageError_routine_8;
  const LogIdSet* MaceTransportService::selectorId_upcallMessageError_routine_8;
  //const std::string selector_upcall_messageError_21_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_messageError_21_transition;
  //const std::string selector_messageError_demux_53;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_53;
  //const std::string selector_registerHandler_demux_31;
  const LogIdSet* MaceTransportService::selectorId_registerHandler_demux_31;
  //const std::string selector_setQueueSize_demux_18;
  const LogIdSet* MaceTransportService::selectorId_setQueueSize_demux_18;
  //const std::string selector_outgoingBufferedDataSize_demux_24;
  const LogIdSet* MaceTransportService::selectorId_outgoingBufferedDataSize_demux_24;
  //const std::string selector_resumeDeliver_downcall_2;
  const LogIdSet* MaceTransportService::selectorId_resumeDeliver_downcall_2;
  //const std::string selector_deliver_demux_5;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_5;
  //const std::string selector_messageError_upcall_2;
  const LogIdSet* MaceTransportService::selectorId_messageError_upcall_2;
  //const std::string selector_incomingMessageQueueSize_demux_15;
  const LogIdSet* MaceTransportService::selectorId_incomingMessageQueueSize_demux_15;
  //const std::string selector_upcallMessageError_routine_9;
  const LogIdSet* MaceTransportService::selectorId_upcallMessageError_routine_9;
  //const std::string selector_suspendDeliver_downcall_1;
  const LogIdSet* MaceTransportService::selectorId_suspendDeliver_downcall_1;
  //const std::string selector_upcallMessageErrors_routine_7;
  const LogIdSet* MaceTransportService::selectorId_upcallMessageErrors_routine_7;
  //const std::string selector_routeRTS_demux_25;
  const LogIdSet* MaceTransportService::selectorId_routeRTS_demux_25;
  //const std::string selector_send_downcall_21;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_21;
  //const std::string selector_bufferedDataSize_demux_21;
  const LogIdSet* MaceTransportService::selectorId_bufferedDataSize_demux_21;
  //const std::string selector_route_downcall_5;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_5;
  //const std::string selector_suspendDeliver_demux_40;
  const LogIdSet* MaceTransportService::selectorId_suspendDeliver_demux_40;
  //const std::string selector_cancellocalTimer;
  const LogIdSet* MaceTransportService::selectorId_cancellocalTimer;
  //const std::string selector_incrementAcked_routine_0;
  const LogIdSet* MaceTransportService::selectorId_incrementAcked_routine_0;
  //const std::string selector_hashState_demux_48;
  const LogIdSet* MaceTransportService::selectorId_hashState_demux_48;
  //const std::string selector_registerUniqueHandler_demux_33;
  const LogIdSet* MaceTransportService::selectorId_registerUniqueHandler_demux_33;
  //const std::string selector_maceReset_demux_46;
  const LogIdSet* MaceTransportService::selectorId_maceReset_demux_46;
  //const std::string selector_registerHandler_demux_28;
  const LogIdSet* MaceTransportService::selectorId_registerHandler_demux_28;
  //const std::string selector_route_downcall_14;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_14;
  //const std::string selector_route_downcall_9;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_9;
  //const std::string selector_expireretransmissionTimer;
  const LogIdSet* MaceTransportService::selectorId_expireretransmissionTimer;
  //const std::string selector_downcall_canSend_9_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_canSend_9_transition;
  //const std::string selector_notifyFlushed_upcall_4;
  const LogIdSet* MaceTransportService::selectorId_notifyFlushed_upcall_4;
  //const std::string selector_route_downcall_22;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_22;
  //const std::string selector_upcall_deliver_16_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_deliver_16_transition;
  //const std::string selector_downcall_getStatistics_6_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_getStatistics_6_transition;
  //const std::string selector_deliver_demux_4;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_4;
  //const std::string selector_upcall_messageError_22_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_messageError_22_transition;
  //const std::string selector_downcall_outgoingBufferedDataSize_7_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_outgoingBufferedDataSize_7_transition;
  //const std::string selector_maceInit_demux_43;
  const LogIdSet* MaceTransportService::selectorId_maceInit_demux_43;
  //const std::string selector_unregisterHandler_demux_29;
  const LogIdSet* MaceTransportService::selectorId_unregisterHandler_demux_29;
  //const std::string selector_upcall_messageError_24_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_messageError_24_transition;
  //const std::string selector_resumeDeliver_demux_41;
  const LogIdSet* MaceTransportService::selectorId_resumeDeliver_demux_41;
  //const std::string selector_upcall_deliver_13_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_deliver_13_transition;
  //const std::string selector_send_downcall_17;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_17;
  //const std::string selector_downcall_maceInit_0_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_maceInit_0_transition;
  //const std::string selector_maceExit_demux_45;
  const LogIdSet* MaceTransportService::selectorId_maceExit_demux_45;
  //const std::string selector_closeOutgoingConnection_routine_2;
  const LogIdSet* MaceTransportService::selectorId_closeOutgoingConnection_routine_2;
  //const std::string selector_schedulectsTimer;
  const LogIdSet* MaceTransportService::selectorId_schedulectsTimer;
  //const std::string selector_processDeliver_routine_10;
  const LogIdSet* MaceTransportService::selectorId_processDeliver_routine_10;
  //const std::string selector_error_upcall_1;
  const LogIdSet* MaceTransportService::selectorId_error_upcall_1;
  //const std::string selector_schedulelocalTimer;
  const LogIdSet* MaceTransportService::selectorId_schedulelocalTimer;
  //const std::string selector_closeIncomingConnection_routine_1;
  const LogIdSet* MaceTransportService::selectorId_closeIncomingConnection_routine_1;
  //const std::string selector_deliver_demux_1;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_1;
  //const std::string selector_registerHandler_demux_34;
  const LogIdSet* MaceTransportService::selectorId_registerHandler_demux_34;
  //const std::string selector_messageError_demux_10;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_10;
  //const std::string selector_hasOutgoingBufferedData_demux_23;
  const LogIdSet* MaceTransportService::selectorId_hasOutgoingBufferedData_demux_23;
  //const std::string selector_downcall_setWindowSize_5_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_setWindowSize_5_transition;
  //const std::string selector_sendReset_routine_12;
  const LogIdSet* MaceTransportService::selectorId_sendReset_routine_12;
  //const std::string selector_scheduleretransmissionTimer;
  const LogIdSet* MaceTransportService::selectorId_scheduleretransmissionTimer;
  //const std::string selector_route_downcall_11;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_11;
  //const std::string selector_localAddress_demux_47;
  const LogIdSet* MaceTransportService::selectorId_localAddress_demux_47;
  //const std::string selector_unregisterHandler_demux_32;
  const LogIdSet* MaceTransportService::selectorId_unregisterHandler_demux_32;
  //const std::string selector_route_downcall_7;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_7;
  //const std::string selector_updateFlushed_routine_15;
  const LogIdSet* MaceTransportService::selectorId_updateFlushed_routine_15;
  //const std::string selector_suspendDeliver_demux_39;
  const LogIdSet* MaceTransportService::selectorId_suspendDeliver_demux_39;
  //const std::string selector_route_demux_37;
  const LogIdSet* MaceTransportService::selectorId_route_demux_37;
  //const std::string selector_deliver_upcall_0;
  const LogIdSet* MaceTransportService::selectorId_deliver_upcall_0;
  //const std::string selector_requestFlushedNotification_demux_27;
  const LogIdSet* MaceTransportService::selectorId_requestFlushedNotification_demux_27;
  //const std::string selector_unregisterHandler_demux_35;
  const LogIdSet* MaceTransportService::selectorId_unregisterHandler_demux_35;
  //const std::string selector_expire_ctsTimer_demux_51;
  const LogIdSet* MaceTransportService::selectorId_expire_ctsTimer_demux_51;
  //const std::string selector_printConnection_routine_17;
  const LogIdSet* MaceTransportService::selectorId_printConnection_routine_17;
  //const std::string selector_messageError_demux_6;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_6;
  //const std::string selector_messageError_demux_8;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_8;
  //const std::string selector_availableBufferSize_demux_12;
  const LogIdSet* MaceTransportService::selectorId_availableBufferSize_demux_12;
  //const std::string selector_downcall_outgoingBufferedDataSize_4_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_outgoingBufferedDataSize_4_transition;
  //const std::string selector_outgoingBufferedDataSize_routine_21;
  const LogIdSet* MaceTransportService::selectorId_outgoingBufferedDataSize_routine_21;
  //const std::string selector_scheduler_expire_ctsTimer_19_transition;
  const LogIdSet* MaceTransportService::selectorId_scheduler_expire_ctsTimer_19_transition;
  //const std::string selector_expirectsTimer;
  const LogIdSet* MaceTransportService::selectorId_expirectsTimer;
  //const std::string selector_route_downcall_4;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_4;
  //const std::string selector_downcall_hasBufferedData_8_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_hasBufferedData_8_transition;
  //const std::string selector_send_downcall_19;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_19;
  //const std::string selector_resumeDeliver_downcall_3;
  const LogIdSet* MaceTransportService::selectorId_resumeDeliver_downcall_3;
  //const std::string selector_downcall_requestFlushedNotification_2_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_requestFlushedNotification_2_transition;
  //const std::string selector_route_downcall_8;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_8;
  //const std::string selector_route_downcall_15;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_15;
  //const std::string selector_downcall_route_1_transition;
  const LogIdSet* MaceTransportService::selectorId_downcall_route_1_transition;
  //const std::string selector_sendPackets_routine_13;
  const LogIdSet* MaceTransportService::selectorId_sendPackets_routine_13;
  //const std::string selector_route_downcall_23;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_23;
  //const std::string selector_incomingMessageQueueSize_demux_16;
  const LogIdSet* MaceTransportService::selectorId_incomingMessageQueueSize_demux_16;
  //const std::string selector_messageError_demux_9;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_9;
  //const std::string selector_error_demux_0;
  const LogIdSet* MaceTransportService::selectorId_error_demux_0;
  //const std::string selector_scheduler_expire_localTimer_18_transition;
  const LogIdSet* MaceTransportService::selectorId_scheduler_expire_localTimer_18_transition;
  //const std::string selector_upcall_deliver_12_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_deliver_12_transition;
  //const std::string selector_send_downcall_20;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_20;
  //const std::string selector_route_downcall_12;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_12;
  //const std::string selector_setWindowSize_demux_17;
  const LogIdSet* MaceTransportService::selectorId_setWindowSize_demux_17;
  //const std::string selector_routeRTS_demux_26;
  const LogIdSet* MaceTransportService::selectorId_routeRTS_demux_26;
  //const std::string selector_outgoingBufferedDataSize_demux_13;
  const LogIdSet* MaceTransportService::selectorId_outgoingBufferedDataSize_demux_13;
  //const std::string selector_messageError_demux_7;
  const LogIdSet* MaceTransportService::selectorId_messageError_demux_7;
  //const std::string selector_upcallMessageErrors_routine_6;
  const LogIdSet* MaceTransportService::selectorId_upcallMessageErrors_routine_6;
  //const std::string selector_deliverBuffered_routine_4;
  const LogIdSet* MaceTransportService::selectorId_deliverBuffered_routine_4;
  //const std::string selector_route_downcall_13;
  const LogIdSet* MaceTransportService::selectorId_route_downcall_13;
  //const std::string selector_deliver_demux_3;
  const LogIdSet* MaceTransportService::selectorId_deliver_demux_3;
  //const std::string selector_send_downcall_24;
  const LogIdSet* MaceTransportService::selectorId_send_downcall_24;
  //const std::string selector_upcall_deliver_15_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_deliver_15_transition;
  //const std::string selector_sendAck_routine_11;
  const LogIdSet* MaceTransportService::selectorId_sendAck_routine_11;
  //const std::string selector_inflightSize_routine_18;
  const LogIdSet* MaceTransportService::selectorId_inflightSize_routine_18;
  //const std::string selector_suspendDeliver_downcall_0;
  const LogIdSet* MaceTransportService::selectorId_suspendDeliver_downcall_0;
  //const std::string selector_upcall_messageError_23_transition;
  const LogIdSet* MaceTransportService::selectorId_upcall_messageError_23_transition;
  //const std::string selector_closeBidirectionalConnection_routine_3;
  const LogIdSet* MaceTransportService::selectorId_closeBidirectionalConnection_routine_3;
  //const std::string selector_checkRetransmissionTimerCount_routine_20;
  const LogIdSet* MaceTransportService::selectorId_checkRetransmissionTimerCount_routine_20;
  //const std::string selector_requestToSend_demux_20;
  const LogIdSet* MaceTransportService::selectorId_requestToSend_demux_20;
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //Change Tracker (optional)
  //BEGIN Mace::Compiler::ServiceImpl::printChangeTracker
  //END Mace::Compiler::ServiceImpl::printChangeTracker
  
  //service variable includes and uses
  
  
  //Transition and Guard Implementations
  //BEGIN Mace::Compiler::ServiceImpl::printTransitions
  bool MaceTransportService::guard_downcall_0_maceInit() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 351 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::downcall_0_maceInit() {
    #define selector selector_downcall_maceInit_0_transition
    #define selectorId selectorId_downcall_maceInit_0_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 351 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      queueThreshold = ((queueThresholdArg == UINT_MAX) ? maxQueueSize / 2 : queueThresholdArg);
      if (queueThreshold == 0) {
        queueThreshold = 1;
      }
    }
#line 365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_1_route(
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      std::string const & s
#line 377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t const  rid
#line 381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 391 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool MaceTransportService::downcall_1_route(
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const std::string& s
#line 404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t rid
#line 408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_route_1_transition
    #define selectorId selectorId_downcall_route_1_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      if (dest == localAddress()) {
        maceout << "scheduling localTimer for " << HashUtil::compute32bitHex(s) << Log::endl;
        localTimer.schedule(1, s, rid);
        return true;
      }
      if (dest != localAddress()) {
        OutgoingConnection& c = out.add(dest);
        if (c.canSend()) {
          enqueue(c, s, rid);
          sendPackets(c);
          return true;
        }
        return false;
      }
      ASSERT(0);
    }
#line 440 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_2_requestFlushedNotification(
      #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t const  rid
#line 448 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 458 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::downcall_2_requestFlushedNotification(
      #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t rid
#line 467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_requestFlushedNotification_2_transition
    #define selectorId selectorId_downcall_requestFlushedNotification_2_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      if (flushedCount == out.size()) {
        defer_upcall_notifyFlushed(rid);
      }
      else {
        notifyFlushed.insert(rid);
      }
    }
#line 490 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_3_hasOutgoingBufferedData() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 385 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool MaceTransportService::downcall_3_hasOutgoingBufferedData() {
    #define selector selector_downcall_hasOutgoingBufferedData_3_transition
    #define selectorId selectorId_downcall_hasOutgoingBufferedData_3_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 385 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      return (outgoingBufferedDataSize(-1) != 0);
    }
#line 527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_4_outgoingBufferedDataSize() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 389 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 541 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  uint32_t MaceTransportService::downcall_4_outgoingBufferedDataSize() {
    #define selector selector_downcall_outgoingBufferedDataSize_4_transition
    #define selectorId selectorId_downcall_outgoingBufferedDataSize_4_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 389 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      uint64_t r = 0;
      for (OutgoingConnectionMap::const_iterator i = out.begin(); i != out.end(); i++) {
        r += i->second.bufferedDataSize();
      }
      return r;
    }
#line 568 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_5_setWindowSize(
      #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & peer
#line 576 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      uint64_t const  size
#line 580 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 590 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::downcall_5_setWindowSize(
      #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& peer
#line 599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      uint64_t size
#line 603 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_setWindowSize_5_transition
    #define selectorId selectorId_downcall_setWindowSize_5_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      ASSERT(0);
    }
#line 621 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_6_getStatistics(
      #line 401 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & peer
#line 629 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 402 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass::Connection::type const  d
#line 633 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 401 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 643 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  const BufferStatisticsPtr MaceTransportService::downcall_6_getStatistics(
      #line 401 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& peer
#line 652 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 402 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass::Connection::type d
#line 656 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_getStatistics_6_transition
    #define selectorId selectorId_downcall_getStatistics_6_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 402 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      if (d == TransportServiceClass::Connection::OUTGOING) {
      }
      else {
        ASSERT(d == TransportServiceClass::Connection::INCOMING);
      }
      return BufferStatisticsPtr();
    }
#line 679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_7_outgoingBufferedDataSize(
      #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & peer
#line 687 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 697 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  uint32_t MaceTransportService::downcall_7_outgoingBufferedDataSize(
      #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& peer
#line 706 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_outgoingBufferedDataSize_7_transition
    #define selectorId selectorId_downcall_outgoingBufferedDataSize_7_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      OutgoingConnectionMap::const_iterator i = out.find(peer);
      if (i != out.end()) {
        return i->second.bufferedDataSize();
      }
      else {
        return 0;
      }
    }
#line 730 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_8_hasBufferedData(
      #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t const  rid
#line 738 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 748 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool MaceTransportService::downcall_8_hasBufferedData(
      #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t rid
#line 757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_hasBufferedData_8_transition
    #define selectorId selectorId_downcall_hasBufferedData_8_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      if (hasOutgoingBufferedData(rid)) {
        return true;
      }
      for (IncomingConnectionMap::const_iterator i = in.begin(); i != in.end(); i++) {
        if (!i->second.m.empty()) {
          return true;
        }
      }
      return false;
    }
#line 783 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_9_canSend(
      #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & peer
#line 791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 801 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool MaceTransportService::downcall_9_canSend(
      #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& peer
#line 810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_canSend_9_transition
    #define selectorId selectorId_downcall_canSend_9_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      OutgoingConnectionMap::const_iterator i = out.find(peer);
      if (i != out.end()) {
        return i->second.canSend();
      }
      return true;
    }
#line 832 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_10_requestToSend(
      #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & peer
#line 840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t const  rid
#line 844 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 854 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::downcall_10_requestToSend(
      #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& peer
#line 863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t rid
#line 867 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_requestToSend_10_transition
    #define selectorId selectorId_downcall_requestToSend_10_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      OutgoingConnection& c = out.add(peer);
      //     c.rts.push_back(RtsData(c.syn, rid));
      c.rts.push_back(rid);
      //     maceout << "pushed " << c.syn << " " << rid << " onto rts for " << peer << Log::endl;
      if (!c.canSend()) {
        return;
      }
      ctsTimer.schedule(1, peer);
    }
#line 892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_downcall_11_routeRTS(
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 900 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      std::string const & s
#line 904 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t const  rid
#line 908 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 918 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  bool MaceTransportService::downcall_11_routeRTS(
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 927 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const std::string& s
#line 931 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      registration_uid_t rid
#line 935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_downcall_routeRTS_11_transition
    #define selectorId selectorId_downcall_routeRTS_11_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      if (canSend(dest, rid)) {
        route(dest, s, rid);
        return true;
      }
      else {
        requestToSend(dest, rid);
        return false;
      }
    }
#line 960 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_upcall_12_deliver(
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & src
#line 968 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 972 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      Data const & m
#line 976 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 986 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::upcall_12_deliver(
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& src
#line 995 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 999 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const Data& m
#line 1003 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_upcall_deliver_12_transition
    #define selectorId selectorId_upcall_deliver_12_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      processDeliver(src, dest, m.seq, m.payload, m.getSerializedSize(), m.rid, m.syn,
          m.synecho);
    }
#line 1022 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_upcall_13_deliver(
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & src
#line 1030 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 1034 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      DataFragment const & m
#line 1038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 1048 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::upcall_13_deliver(
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& src
#line 1057 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 1061 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const DataFragment& m
#line 1065 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_upcall_deliver_13_transition
    #define selectorId selectorId_upcall_deliver_13_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      processDeliver(src, dest, m.seq, m.payload, m.getSerializedSize(), m.rid, m.syn,
          m.synecho, m.nfrag);
    }
#line 1084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_upcall_14_deliver(
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & src
#line 1092 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 1096 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      Fragment const & m
#line 1100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 1110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::upcall_14_deliver(
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& src
#line 1119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 1123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const Fragment& m
#line 1127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_upcall_deliver_14_transition
    #define selectorId selectorId_upcall_deliver_14_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      processDeliver(src, dest, m.seq, m.payload, m.getSerializedSize(), 0, 0, 0, 0,
          m.frag);
    }
#line 1146 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    
    #undef selector
    #undef selectorId
  }
  bool MaceTransportService::guard_upcall_15_deliver(
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & src
#line 1154 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      MaceKey const & dest
#line 1158 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      Ack const & ack
#line 1162 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        true
#line 1172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      return true;
    }
    return false;
  }
  void MaceTransportService::upcall_15_deliver(
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& src
#line 1181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const MaceKey& dest
#line 1185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ,
      #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      const Ack& ack
#line 1189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
  ) {
    #define selector selector_upcall_deliver_15_transition
    #define selectorId selectorId_upcall_deliver_15_transition
    MaceTime _curtime = 0;
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    {
      
      OutgoingConnectionMap::iterator ci = out.find(src);
      
      if (ci != out.end()) {
        maceout << "received ack from " << src << " for " << ack.seq << Log::endl;
        
        OutgoingConnection& c = ci->second;
        printConnection(c, "deliver");
        MessagePtrMap::iterator rti = c.rtbuf.begin();
        
        //       if (rti != ci->second.rtbuf.end()) {
          // 	maceout << "rtbuf.front=" << rti->first << " ack.seq=" << ack.seq << Log::endl;
          //       }
        
        //       if ((rti != ci->second.rtbuf.end()) && (rti->first <= ack.seq)) {
          bool nowarn = false;
          if (rti != c.rtbuf.end()) {
            maceout << "rtbuf.front=" << rti->first << " ack.seq=" << ack.seq << Log::endl;
            while ((rti != c.rtbuf.end()) && (rti->first <= ack.seq)) {
              MessageInfoPtr m = rti->second;
              maceout << "erasing " << *m << " from rtbuf" << Log::endl;
              c.connection.updateRTO(m->ts);
              c.connection.increaseCWND();
              incrementAcked(c, m->payload.size());
              c.rtbuf.erase(rti++);
              rti = c.rtbuf.begin();
              nowarn = true;
            }
          }
          
          if (!c.inflight.empty()) {
            MessagePtrMap::iterator mi = c.inflight.find(ack.seq);
            if ((mi == c.inflight.end()) && (c.inflight.rbegin()->first < ack.seq)) {
              // fix for MT bug # 6
              maceout << "clearing inflight" << Log::endl;
              mi = c.inflight.begin();
            }
            
            if (mi != c.inflight.end()) {
              MessageInfoPtr m = mi->second;
              c.connection.updateRTO(m->ts);
              
              mi = c.inflight.begin();
              while ((mi != c.inflight.end()) && (mi->first <= ack.seq)) {
                m = mi->second;
                maceout << "erasing " << *m << " from inflight" << Log::endl;
                retransmissionTimer.cancel(m->timer);
                c.inflight.erase(mi);
                c.connection.increaseCWND();
                incrementAcked(c, m->payload.size());
                mi = c.inflight.begin();
              }
              
              c.setLast(ack.seq);
              sendPackets(c);
              updateFlushed(c);
              return;
            }
          }
          
          if (ack.seq == c.last) {
            maceout << "received duplicate ack from " << src << " for " << ack.seq
            << Log::endl;
            
            c.connection.increaseCWND();
            c.setLast(ack.seq);
            if (c.fastRetransmit()) {
              MessagePtrMap::iterator minext = c.inflight.find(ack.seq + 1);
              if (minext != c.inflight.end()) {
                c.connection.timeout();
                MessageInfoPtr m = minext->second;
                maceout << "fast retransmit for " << m->seq << Log::endl;
                retransmissionTimer.cancel(m->timer);
                c.inflight.erase(minext);
                m->retries++;
                c.rtbuf[m->seq] = m;
              }
            }
            
            sendPackets(c);
            return;
          }
          
          if (nowarn) {
            return;
          }
        }
        
        macewarn << "received unknown ack from " << src << " for " << ack.seq << Log::endl;
        //     ASSERT(0); // XXX
      }
#line 1296 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_16_deliver(
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 1304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1308 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Reset const & rst
#line 1312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_expr
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
          true
#line 1322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_16_deliver(
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 1331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& rst
#line 1339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_deliver_16_transition
      #define selectorId selectorId_upcall_deliver_16_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        
        OutgoingConnectionMap::iterator ci = out.find(src);
        if (ci != out.end()) {
          OutgoingConnection& c = ci->second;
          maceout << "received reset from " << src << " with syn=" << rst.syn
          << " seq=" << rst.seq << Log::endl;
          if (!rst.syn ||
              (rst.syn >= c.syn) ||	// fix for MT bug # 7
              c.inflight.containsKey(rst.seq) ||
              c.rtbuf.containsKey(rst.seq)) {
            closeOutgoingConnection(src, c, TransportError::WRITE_ERROR, "connection reset");
          }
          else {
            maceout << "ignoring reset with syn " << rst.syn << " c.syn=" << c.syn
            << Log::endl;
          }
        }
      }
#line 1373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_scheduler_17_expire_retransmissionTimer(
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr const & m
#line 1385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_expr
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
          true
#line 1395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::scheduler_17_expire_retransmissionTimer(
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey& dest
#line 1404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr& m
#line 1408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_scheduler_expire_retransmissionTimer_17_transition
      #define selectorId selectorId_scheduler_expire_retransmissionTimer_17_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        OutgoingConnectionMap::iterator ci = out.find(dest);
        if (ci != out.end()) {
          maceout << "dest=" << dest << " " << *m << Log::endl;
          OutgoingConnection& c = ci->second;
          
          printConnection(c, "retransmissionTimer begin");
          
          bool clearTimeout = false;
          if (m->timeout) {
            c.connection.timeout();
            maceout << "connection.timeout() " << c.connection << Log::endl;
            clearTimeout = true;
          }
          
          MaceTime oldestInflight = curtime;
          for (MessagePtrMap::iterator i = c.inflight.begin(); i != c.inflight.end(); i++) {
            oldestInflight = MaceTime::min(oldestInflight, i->second->starttime);
            if (clearTimeout) {
              i->second->timeout = false;
            }
          }
          
          if (curtime.greaterThan(oldestInflight + (uint64_t)MAX_RTO, 0, 1)) {
            // peer failed
            closeBidirectionalConnection(dest, c, TransportError::WRITE_ERROR,
                "send timeout");
            return;
          }
          
          c.inflight.erase(m->seq);
          
          m->retries++;
          c.rtbuf[m->seq] = m;
          maceout << "queued " << *m << " for retransmission" << Log::endl;
          
          MessagePtrMap::iterator i = c.inflight.begin();
          while (i != c.inflight.end() && (i->first < m->seq) &&
              (i->second->ts.lessThan(m->ts))) {
            MessageInfoPtr mp = i->second;
            maceout << "queueing " << *mp << " for retransmission with older timeout"
            << Log::endl;
            mp->retries++;
            c.rtbuf[mp->seq] = mp;
            retransmissionTimer.cancel(mp->timer);
            c.inflight.erase(i);
            i = c.inflight.begin();
          }
          
          printConnection(c, "retransmissionTimer end");
          sendPackets(c);
        }
      }
#line 1476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_scheduler_18_expire_localTimer(
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string const & s
#line 1484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const & rid
#line 1488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_expr
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
          true
#line 1498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::scheduler_18_expire_localTimer(
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string& s
#line 1507 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t& rid
#line 1511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_scheduler_expire_localTimer_18_transition
      #define selectorId selectorId_scheduler_expire_localTimer_18_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        maceout << "delivering " << HashUtil::compute32bitHex(s) << Log::endl;
        upcall_deliver(localAddress(), localAddress(), s, rid);
      }
#line 1530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_scheduler_19_expire_ctsTimer(
        #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_expr
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
          true
#line 1548 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::scheduler_19_expire_ctsTimer(
        #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey& dest
#line 1557 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_scheduler_expire_ctsTimer_19_transition
      #define selectorId selectorId_scheduler_expire_ctsTimer_19_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        OutgoingConnectionMap::iterator i = out.find(dest);
        if (i != out.end()) {
          OutgoingConnection& c = i->second;
          while (!c.rts.empty() && c.canSend()) {
            // 	maceout << "c.rts.size=" << c.rts.size() << Log::endl;
            // 	const RtsData& d = c.rts.front();
            // 	maceout << "d.syn=" << d.syn << " c.syn=" << c.syn << " rid=" << d.rid
            // 		<< " dest=" << dest << Log::endl;
            // 	if (d.syn == c.syn) {
              //     	  upcall_clearToSend(dest, d.rid);
              // 	}
            upcall_clearToSend(dest, c.rts.front());
            c.rts.pop_front();
          }
        }
      }
#line 1589 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_20_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1597 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 1601 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Data const & message_deserialized
#line 1605 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 1609 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_var
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          true
#line 1619 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_20_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1628 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 1632 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& message_deserialized
#line 1636 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 1640 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_messageError_20_transition
      #define selectorId selectorId_upcall_messageError_20_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1656 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_21_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 1668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        DataFragment const & message_deserialized
#line 1672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 1676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_var
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          true
#line 1686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_21_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1695 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 1699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& message_deserialized
#line 1703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 1707 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_messageError_21_transition
      #define selectorId selectorId_upcall_messageError_21_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1723 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_22_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1731 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 1735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Fragment const & message_deserialized
#line 1739 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 1743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_var
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          true
#line 1753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_22_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 1766 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& message_deserialized
#line 1770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 1774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_messageError_22_transition
      #define selectorId selectorId_upcall_messageError_22_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1790 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_23_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 1802 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Ack const & message_deserialized
#line 1806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 1810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_var
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          true
#line 1820 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_23_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1829 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 1833 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& message_deserialized
#line 1837 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 1841 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_messageError_23_transition
      #define selectorId selectorId_upcall_messageError_23_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1857 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    bool MaceTransportService::guard_upcall_24_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 1865 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 1869 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Reset const & message_deserialized
#line 1873 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 1877 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // guard_type = state_var
      // transition is in write mode.
      // referenced variables =
      
      __eventContextType = 1;
      if(
          #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          true
#line 1887 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      ) {
        return true;
      }
      return false;
    }
    void MaceTransportService::upcall_24_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 1896 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 1900 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& message_deserialized
#line 1904 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 1908 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      #define selector selector_upcall_messageError_24_transition
      #define selectorId selectorId_upcall_messageError_24_transition
      MaceTime _curtime = 0;
      ADD_LOG_BACKING
      
      // Transition.pm:printTransitionFunction()
      // Locking type = 1
      __eventContextType = 1;
      
      
      
      
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
      { }
#line 1924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
    }
    //END Mace::Compiler::ServiceImpl::printTransitions
    
    //Structured Logging Functions
    mace::LogNode* canSend48Dummy::rootLogNode = NULL;
    mace::LogNode* outgoingBufferedDataSize50Dummy::rootLogNode = NULL;
    mace::LogNode* setWindowSize54Dummy::rootLogNode = NULL;
    mace::LogNode* getStatistics56Dummy::rootLogNode = NULL;
    mace::LogNode* requestToSend57Dummy::rootLogNode = NULL;
    mace::LogNode* hasBufferedData59Dummy::rootLogNode = NULL;
    mace::LogNode* hasOutgoingBufferedData60Dummy::rootLogNode = NULL;
    mace::LogNode* outgoingBufferedDataSize61Dummy::rootLogNode = NULL;
    mace::LogNode* routeRTS62Dummy::rootLogNode = NULL;
    mace::LogNode* requestFlushedNotification64Dummy::rootLogNode = NULL;
    mace::LogNode* route65Dummy::rootLogNode = NULL;
    mace::LogNode* maceInit71Dummy::rootLogNode = NULL;
    mace::LogNode* maceReset74Dummy::rootLogNode = NULL;
    mace::LogNode* hashState76Dummy::rootLogNode = NULL;
    mace::LogNode* deliver78Dummy::rootLogNode = NULL;
    mace::LogNode* deliver79Dummy::rootLogNode = NULL;
    mace::LogNode* deliver80Dummy::rootLogNode = NULL;
    mace::LogNode* deliver81Dummy::rootLogNode = NULL;
    mace::LogNode* deliver82Dummy::rootLogNode = NULL;
    mace::LogNode* messageError83Dummy::rootLogNode = NULL;
    mace::LogNode* messageError84Dummy::rootLogNode = NULL;
    mace::LogNode* messageError85Dummy::rootLogNode = NULL;
    mace::LogNode* messageError86Dummy::rootLogNode = NULL;
    mace::LogNode* messageError87Dummy::rootLogNode = NULL;
    mace::LogNode* expire_retransmissionTimer88Dummy::rootLogNode = NULL;
    mace::LogNode* expire_localTimer89Dummy::rootLogNode = NULL;
    mace::LogNode* expire_ctsTimer90Dummy::rootLogNode = NULL;
    mace::LogNode* suspendDeliver23Dummy::rootLogNode = NULL;
    mace::LogNode* suspendDeliver24Dummy::rootLogNode = NULL;
    mace::LogNode* resumeDeliver25Dummy::rootLogNode = NULL;
    mace::LogNode* resumeDeliver26Dummy::rootLogNode = NULL;
    mace::LogNode* route27Dummy::rootLogNode = NULL;
    mace::LogNode* route28Dummy::rootLogNode = NULL;
    mace::LogNode* route29Dummy::rootLogNode = NULL;
    mace::LogNode* route30Dummy::rootLogNode = NULL;
    mace::LogNode* route31Dummy::rootLogNode = NULL;
    mace::LogNode* route32Dummy::rootLogNode = NULL;
    mace::LogNode* route33Dummy::rootLogNode = NULL;
    mace::LogNode* route34Dummy::rootLogNode = NULL;
    mace::LogNode* route35Dummy::rootLogNode = NULL;
    mace::LogNode* route36Dummy::rootLogNode = NULL;
    mace::LogNode* route37Dummy::rootLogNode = NULL;
    mace::LogNode* route38Dummy::rootLogNode = NULL;
    mace::LogNode* send39Dummy::rootLogNode = NULL;
    mace::LogNode* send40Dummy::rootLogNode = NULL;
    mace::LogNode* send41Dummy::rootLogNode = NULL;
    mace::LogNode* send42Dummy::rootLogNode = NULL;
    mace::LogNode* send43Dummy::rootLogNode = NULL;
    mace::LogNode* send44Dummy::rootLogNode = NULL;
    mace::LogNode* upcall_notifyFlushed22Dummy::rootLogNode = NULL;
    mace::LogNode* incrementAcked0Dummy::rootLogNode = NULL;
    mace::LogNode* closeIncomingConnection1Dummy::rootLogNode = NULL;
    mace::LogNode* closeOutgoingConnection2Dummy::rootLogNode = NULL;
    mace::LogNode* closeBidirectionalConnection3Dummy::rootLogNode = NULL;
    mace::LogNode* deliverBuffered4Dummy::rootLogNode = NULL;
    mace::LogNode* upcallDeliver5Dummy::rootLogNode = NULL;
    mace::LogNode* processDeliver10Dummy::rootLogNode = NULL;
    mace::LogNode* sendAck11Dummy::rootLogNode = NULL;
    mace::LogNode* sendReset12Dummy::rootLogNode = NULL;
    mace::LogNode* sendPackets13Dummy::rootLogNode = NULL;
    mace::LogNode* enqueue14Dummy::rootLogNode = NULL;
    mace::LogNode* updateFlushed15Dummy::rootLogNode = NULL;
    mace::LogNode* checkAndNotifyFlushed16Dummy::rootLogNode = NULL;
    mace::LogNode* printConnection17Dummy::rootLogNode = NULL;
    mace::LogNode* inflightSize18Dummy::rootLogNode = NULL;
    mace::LogNode* checkRetransmissionTimer19Dummy::rootLogNode = NULL;
    mace::LogNode* checkRetransmissionTimerCount20Dummy::rootLogNode = NULL;
    mace::LogNode* outgoingBufferedDataSize21Dummy::rootLogNode = NULL;
    mace::LogNode* ConnectionInfo_updateRTODummy::rootLogNode = NULL;
    mace::LogNode* ConnectionInfo_increaseCWNDDummy::rootLogNode = NULL;
    mace::LogNode* ConnectionInfo_timeoutDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_canSendDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_updateCanSendOnWriteDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_updateCanSendOnEnqueueDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_bufferedDataSizeDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_hasQueuedMessagesDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_queuedMessagesSizeDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_nextSeqDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_getSynDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_setLastDummy::rootLogNode = NULL;
    mace::LogNode* OutgoingConnection_fastRetransmitDummy::rootLogNode = NULL;
    // logging funcs
    bool MaceTransportService::shouldLog_canSend48( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_availableBufferSize49( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_outgoingBufferedDataSize50( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_incomingBufferedDataSize51( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_incomingMessageQueueSize52( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_incomingMessageQueueSize53(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_setWindowSize54( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_setQueueSize55( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_getStatistics56( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_requestToSend57( const MaceKey& peer, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_bufferedDataSize58(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_hasBufferedData59(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_hasOutgoingBufferedData60(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_outgoingBufferedDataSize61(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_routeRTS62( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_routeRTS63( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_requestFlushedNotification64(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route65( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route66( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_suspendDeliver67(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_suspendDeliver68( const MaceKey& dest, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_resumeDeliver69(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_resumeDeliver70( const MaceKey& dest, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_maceInit71() const {
      return true;
    }
    bool MaceTransportService::shouldLog_maceResume72() const {
      return true;
    }
    bool MaceTransportService::shouldLog_maceExit73() const {
      return true;
    }
    bool MaceTransportService::shouldLog_maceReset74() const {
      return true;
    }
    bool MaceTransportService::shouldLog_localAddress75() const {
      return true;
    }
    bool MaceTransportService::shouldLog_hashState76() const {
      return true;
    }
    bool MaceTransportService::shouldLog_error77( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliver78( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliver79( const MaceKey& source,  const MaceKey& destination,  const DataFragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliver80( const MaceKey& source,  const MaceKey& destination,  const Fragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliver81( const MaceKey& source,  const MaceKey& destination,  const Ack& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliver82( const MaceKey& source,  const MaceKey& destination,  const Reset& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_messageError83( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_messageError84( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_messageError85( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_messageError86( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_messageError87( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_expire_retransmissionTimer88(MaceKey& p0, MessageInfoPtr& p1) const {
      return true;
    }
    bool MaceTransportService::shouldLog_expire_localTimer89(std::string& p0, registration_uid_t& p1) const {
      return true;
    }
    bool MaceTransportService::shouldLog_expire_ctsTimer90(MaceKey& p0) const {
      return true;
    }
    bool MaceTransportService::shouldLog_suspendDeliver23(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_suspendDeliver24( const MaceKey& dest, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_resumeDeliver25(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_resumeDeliver26( const MaceKey& dest, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route27( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route28( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route29( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route30( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route31( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route32( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route33( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route34( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send39( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send40( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send41( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send42( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send43( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_send44( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcall_notifyFlushed22(registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_incrementAcked0(OutgoingConnection& c, uint32_t size) const {
      return true;
    }
    bool MaceTransportService::shouldLog_closeIncomingConnection1( const MaceKey& src, TransportError::type error,  const std::string& errstr, bool upcallError) const {
      return true;
    }
    bool MaceTransportService::shouldLog_closeOutgoingConnection2( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr, bool upcallError) const {
      return true;
    }
    bool MaceTransportService::shouldLog_closeBidirectionalConnection3( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr) const {
      return true;
    }
    bool MaceTransportService::shouldLog_deliverBuffered4(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcallDeliver5(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest,  const std::string& payload, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcallMessageErrors6(MessagePtrMap::iterator i, MessagePtrMap::iterator end,  const MaceKey& dest, OutgoingConnection& c, IdSet& seen, TransportError::type error) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcallMessageErrors7(MessagePtrList::iterator i, MessagePtrList::iterator end,  const MaceKey& dest, OutgoingConnection& c, IdSet& seen, TransportError::type error) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcallMessageError8( const MaceKey& dest, MessageInfoPtr m, OutgoingConnection& c, IdSet& seen, TransportError::type error) const {
      return true;
    }
    bool MaceTransportService::shouldLog_upcallMessageError9( const MaceKey& dest, MessageInfoPtr m, OutgoingConnection& c, TransportError::type error) const {
      return true;
    }
    bool MaceTransportService::shouldLog_processDeliver10( const MaceKey& src,  const MaceKey& dest, seq_t seq, mace::string payload, uint32_t ssize, registration_uid_t rid, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t nfrag, uint32_t frag) const {
      return true;
    }
    bool MaceTransportService::shouldLog_sendAck11( const MaceKey& src, seq_t seq, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t sz, seq_t& ackseq, bool& discard) const {
      return true;
    }
    bool MaceTransportService::shouldLog_sendReset12( const MaceKey& dest, mace::MonotoneTime id, seq_t seq) const {
      return true;
    }
    bool MaceTransportService::shouldLog_sendPackets13(OutgoingConnection& c) const {
      return true;
    }
    bool MaceTransportService::shouldLog_enqueue14(OutgoingConnection& c,  const std::string& s, registration_uid_t rid) const {
      return true;
    }
    bool MaceTransportService::shouldLog_updateFlushed15(OutgoingConnection& c) const {
      return true;
    }
    bool MaceTransportService::shouldLog_checkAndNotifyFlushed16() const {
      return true;
    }
    bool MaceTransportService::shouldLog_printConnection17( const OutgoingConnection& c,  const std::string& s) const {
      return true;
    }
    bool MaceTransportService::shouldLog_inflightSize18() const {
      return true;
    }
    bool MaceTransportService::shouldLog_checkRetransmissionTimer19() const {
      return true;
    }
    bool MaceTransportService::shouldLog_checkRetransmissionTimerCount20() const {
      return true;
    }
    bool MaceTransportService::shouldLog_outgoingBufferedDataSize21() const {
      return true;
    }
    
    //Auto Type Methods
    //BEGIN: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
    
    bool ConnectionInfo::shouldLog_ConnectionInfo_updateRTO( const MaceTime& ts) const {
      return true;
    }
    void ConnectionInfo::updateRTO(
        #line 148 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceTime& ts
#line 2288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("ConnectionInfo::updateRTO");
      bool __test = shouldLog_ConnectionInfo_updateRTO(ts);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, ConnectionInfo_updateRTODummy(ts), 0);
        }
      }
      
      
      
      #line 148 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        int64_t m = curtime.time() - ts.time();
        if (sa == -1) {
          sa = m << 3;
          sv = 0;
          rto = m << 2;
        }
        else {
          m -= (sa >> 3);
          sa += m;
          if (m < 0) {
            m = -1 * m;
          }
          m -= (sv >> 2);
          sv += m;
          rto = (sa >> 3) + sv;
        }
        rto += MIN_RTO;
        
        if (rto > MAX_RTO) {
          rto = MAX_RTO;
        }
        else if (rto < MIN_RTO) {
          rto += MIN_RTO;
        }
        
        consecutiveTimeouts = 0;
        //       lastHeard = ts;
        acksReceived++;
      }
#line 2343 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool ConnectionInfo::shouldLog_ConnectionInfo_increaseCWND() const {
      return true;
    }
    void ConnectionInfo::increaseCWND() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("ConnectionInfo::increaseCWND");
      bool __test = shouldLog_ConnectionInfo_increaseCWND();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, ConnectionInfo_increaseCWNDDummy(), 0);
        }
      }
      
      
      
      #line 179 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (cwnd < ssthresh) {
          cwnd += 1.0;
        }
        else {
          cwnd += 1.0 / cwnd;
        }
        if (cwnd > MAX_WND) {
          cwnd = MAX_WND;
        }
        ASSERT(cwnd >= 1);
      }
#line 2385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool ConnectionInfo::shouldLog_ConnectionInfo_timeout() const {
      return true;
    }
    void ConnectionInfo::timeout() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("ConnectionInfo::timeout");
      bool __test = shouldLog_ConnectionInfo_timeout();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, ConnectionInfo_timeoutDummy(), 0);
        }
      }
      
      
      
      #line 192 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        rto <<= 1;
        
        if (rto > MAX_RTO) {
          rto = MAX_RTO;
        }
        
        ssthresh = cwnd / 2.0;
        cwnd = 1.0;
        
        consecutiveTimeouts++;
        timeoutCount++;
      }
#line 2428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    
    bool OutgoingConnection::shouldLog_OutgoingConnection_canSend() const {
      return true;
    }
    bool OutgoingConnection::canSend() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::canSend");
      bool __test = shouldLog_OutgoingConnection_canSend();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_canSendDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_canSend(), selectorId->compiler, "rv_bool");
      
    }
    bool OutgoingConnection::__mace_log_canSend() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::canSend");
      
      
      
      #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        return sendable;
      }
#line 2479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_updateCanSendOnWrite(uint64_t maxsize, uint64_t threshold) const {
      return true;
    }
    void OutgoingConnection::updateCanSendOnWrite(
        #line 234 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t maxsize
#line 2488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 234 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t threshold
#line 2492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::updateCanSendOnWrite");
      bool __test = shouldLog_OutgoingConnection_updateCanSendOnWrite(maxsize, threshold);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_updateCanSendOnWriteDummy(maxsize, threshold), 0);
        }
      }
      
      
      
      #line 234 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (!sendable && (bufferedDataSize() < std::min(maxsize, threshold))) {
          sendable = true;
        }
      }
#line 2522 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_updateCanSendOnEnqueue(uint64_t maxsize) const {
      return true;
    }
    void OutgoingConnection::updateCanSendOnEnqueue(
        #line 240 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t maxsize
#line 2531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::updateCanSendOnEnqueue");
      bool __test = shouldLog_OutgoingConnection_updateCanSendOnEnqueue(maxsize);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_updateCanSendOnEnqueueDummy(maxsize), 0);
        }
      }
      
      
      
      #line 240 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (sendable && (bufferedDataSize() > maxsize)) {
          sendable = false;
        }
      }
#line 2561 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_bufferedDataSize() const {
      return true;
    }
    size_t OutgoingConnection::bufferedDataSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::bufferedDataSize");
      bool __test = shouldLog_OutgoingConnection_bufferedDataSize();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_bufferedDataSizeDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_bufferedDataSize(), selectorId->compiler, "rv_size_t");
      
    }
    size_t OutgoingConnection::__mace_log_bufferedDataSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::bufferedDataSize");
      
      
      
      #line 246 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        return ((queued - sent) + (sent - acked));
      }
#line 2611 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_hasQueuedMessages() const {
      return true;
    }
    bool OutgoingConnection::hasQueuedMessages() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::hasQueuedMessages");
      bool __test = shouldLog_OutgoingConnection_hasQueuedMessages();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_hasQueuedMessagesDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_hasQueuedMessages(), selectorId->compiler, "rv_bool");
      
    }
    bool OutgoingConnection::__mace_log_hasQueuedMessages() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::hasQueuedMessages");
      
      
      
      #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        return !rtbuf.empty() || !sendbuf.empty();
      }
#line 2661 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_queuedMessagesSize() const {
      return true;
    }
    size_t OutgoingConnection::queuedMessagesSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::queuedMessagesSize");
      bool __test = shouldLog_OutgoingConnection_queuedMessagesSize();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_queuedMessagesSizeDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_queuedMessagesSize(), selectorId->compiler, "rv_size_t");
      
    }
    size_t OutgoingConnection::__mace_log_queuedMessagesSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::queuedMessagesSize");
      
      
      
      #line 254 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        return rtbuf.size() + sendbuf.size();
      }
#line 2711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_nextSeq() const {
      return true;
    }
    seq_t OutgoingConnection::nextSeq() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::nextSeq");
      bool __test = shouldLog_OutgoingConnection_nextSeq();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_nextSeqDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_nextSeq(), selectorId->compiler, "rv_seq_t");
      
    }
    seq_t OutgoingConnection::__mace_log_nextSeq() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::nextSeq");
      
      
      
      #line 258 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        curseq++;
        return curseq;
      }
#line 2762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_getSyn() const {
      return true;
    }
    mace::MonotoneTime OutgoingConnection::getSyn() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::getSyn");
      bool __test = shouldLog_OutgoingConnection_getSyn();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_getSynDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_getSyn(), selectorId->compiler, "rv_mace__MonotoneTime");
      
    }
    mace::MonotoneTime OutgoingConnection::__mace_log_getSyn() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::getSyn");
      
      
      
      #line 263 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (returnSyn) {
          returnSyn = false;
          return syn;
        }
        return 0;
      }
#line 2816 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_setLast(seq_t s) const {
      return true;
    }
    void OutgoingConnection::setLast(
        #line 271 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t s
#line 2825 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::setLast");
      bool __test = shouldLog_OutgoingConnection_setLast(s);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_setLastDummy(s), 0);
        }
      }
      
      
      
      #line 271 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (last == s) {
          dupacks++;
        }
        else {
          last = s;
          dupacks = 0;
        }
      }
#line 2859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    bool OutgoingConnection::shouldLog_OutgoingConnection_fastRetransmit() const {
      return true;
    }
    bool OutgoingConnection::fastRetransmit() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      ADD_SELECTORS("OutgoingConnection::fastRetransmit");
      bool __test = shouldLog_OutgoingConnection_fastRetransmit();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, OutgoingConnection_fastRetransmitDummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_fastRetransmit(), selectorId->compiler, "rv_bool");
      
    }
    bool OutgoingConnection::__mace_log_fastRetransmit() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      ADD_SELECTORS("OutgoingConnection::fastRetransmit");
      
      
      
      #line 281 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        return (dupacks >= FAST_RETRANSMIT_DUP);
      }
#line 2909 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
    }
    
    
    //END: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
    
    //Routines
    //BEGIN Mace::Compiler::ServiceImpl::printRoutines
    
    static void initializeSelectors() {
      static bool _inited = false;
      if (!_inited) {
        log_id_t mid __attribute((unused)) = Log::getId("MethodMap");
        _inited = true;
        MaceTransportService::selectorId_maceResume_demux_44 = new LogIdSet(selector_maceResume_demux_44);
        MaceTransportService::selectorId_registerUniqueHandler_demux_30 = new LogIdSet(selector_registerUniqueHandler_demux_30);
        MaceTransportService::selectorId_expire_localTimer_demux_50 = new LogIdSet(selector_expire_localTimer_demux_50);
        MaceTransportService::selectorId_checkAndNotifyFlushed_routine_16 = new LogIdSet(selector_checkAndNotifyFlushed_routine_16);
        MaceTransportService::selectorId_deliver_demux_52 = new LogIdSet(selector_deliver_demux_52);
        MaceTransportService::selectorId_route_downcall_6 = new LogIdSet(selector_route_downcall_6);
        MaceTransportService::selectorId_cancelretransmissionTimer = new LogIdSet(selector_cancelretransmissionTimer);
        MaceTransportService::selectorId_upcall_messageError_20_transition = new LogIdSet(selector_upcall_messageError_20_transition);
        MaceTransportService::selectorId_upcallDeliver_routine_5 = new LogIdSet(selector_upcallDeliver_routine_5);
        MaceTransportService::selectorId_downcall_requestToSend_10_transition = new LogIdSet(selector_downcall_requestToSend_10_transition);
        MaceTransportService::selectorId_send_downcall_18 = new LogIdSet(selector_send_downcall_18);
        MaceTransportService::selectorId_incomingBufferedDataSize_demux_14 = new LogIdSet(selector_incomingBufferedDataSize_demux_14);
        MaceTransportService::selectorId_scheduler_expire_retransmissionTimer_17_transition = new LogIdSet(selector_scheduler_expire_retransmissionTimer_17_transition);
        MaceTransportService::selectorId_canSend_demux_11 = new LogIdSet(selector_canSend_demux_11);
        MaceTransportService::selectorId_cancelctsTimer = new LogIdSet(selector_cancelctsTimer);
        MaceTransportService::selectorId_upcall_deliver_14_transition = new LogIdSet(selector_upcall_deliver_14_transition);
        MaceTransportService::selectorId_expirelocalTimer = new LogIdSet(selector_expirelocalTimer);
        MaceTransportService::selectorId_route_downcall_10 = new LogIdSet(selector_route_downcall_10);
        MaceTransportService::selectorId_clearToSend_upcall_3 = new LogIdSet(selector_clearToSend_upcall_3);
        MaceTransportService::selectorId_route_demux_38 = new LogIdSet(selector_route_demux_38);
        MaceTransportService::selectorId_getStatistics_demux_19 = new LogIdSet(selector_getStatistics_demux_19);
        MaceTransportService::selectorId_checkRetransmissionTimer_routine_19 = new LogIdSet(selector_checkRetransmissionTimer_routine_19);
        MaceTransportService::selectorId_resumeDeliver_demux_42 = new LogIdSet(selector_resumeDeliver_demux_42);
        MaceTransportService::selectorId_downcall_routeRTS_11_transition = new LogIdSet(selector_downcall_routeRTS_11_transition);
        MaceTransportService::selectorId_registerUniqueHandler_demux_36 = new LogIdSet(selector_registerUniqueHandler_demux_36);
        MaceTransportService::selectorId_hasBufferedData_demux_22 = new LogIdSet(selector_hasBufferedData_demux_22);
        MaceTransportService::selectorId_downcall_hasOutgoingBufferedData_3_transition = new LogIdSet(selector_downcall_hasOutgoingBufferedData_3_transition);
        MaceTransportService::selectorId_expire_retransmissionTimer_demux_49 = new LogIdSet(selector_expire_retransmissionTimer_demux_49);
        MaceTransportService::selectorId_deliver_demux_2 = new LogIdSet(selector_deliver_demux_2);
        MaceTransportService::selectorId_send_downcall_16 = new LogIdSet(selector_send_downcall_16);
        MaceTransportService::selectorId_enqueue_routine_14 = new LogIdSet(selector_enqueue_routine_14);
        MaceTransportService::selectorId_upcallMessageError_routine_8 = new LogIdSet(selector_upcallMessageError_routine_8);
        MaceTransportService::selectorId_upcall_messageError_21_transition = new LogIdSet(selector_upcall_messageError_21_transition);
        MaceTransportService::selectorId_messageError_demux_53 = new LogIdSet(selector_messageError_demux_53);
        MaceTransportService::selectorId_registerHandler_demux_31 = new LogIdSet(selector_registerHandler_demux_31);
        MaceTransportService::selectorId_setQueueSize_demux_18 = new LogIdSet(selector_setQueueSize_demux_18);
        MaceTransportService::selectorId_outgoingBufferedDataSize_demux_24 = new LogIdSet(selector_outgoingBufferedDataSize_demux_24);
        MaceTransportService::selectorId_resumeDeliver_downcall_2 = new LogIdSet(selector_resumeDeliver_downcall_2);
        MaceTransportService::selectorId_deliver_demux_5 = new LogIdSet(selector_deliver_demux_5);
        MaceTransportService::selectorId_messageError_upcall_2 = new LogIdSet(selector_messageError_upcall_2);
        MaceTransportService::selectorId_incomingMessageQueueSize_demux_15 = new LogIdSet(selector_incomingMessageQueueSize_demux_15);
        MaceTransportService::selectorId_upcallMessageError_routine_9 = new LogIdSet(selector_upcallMessageError_routine_9);
        MaceTransportService::selectorId_suspendDeliver_downcall_1 = new LogIdSet(selector_suspendDeliver_downcall_1);
        MaceTransportService::selectorId_upcallMessageErrors_routine_7 = new LogIdSet(selector_upcallMessageErrors_routine_7);
        MaceTransportService::selectorId_routeRTS_demux_25 = new LogIdSet(selector_routeRTS_demux_25);
        MaceTransportService::selectorId_send_downcall_21 = new LogIdSet(selector_send_downcall_21);
        MaceTransportService::selectorId_bufferedDataSize_demux_21 = new LogIdSet(selector_bufferedDataSize_demux_21);
        MaceTransportService::selectorId_route_downcall_5 = new LogIdSet(selector_route_downcall_5);
        MaceTransportService::selectorId_suspendDeliver_demux_40 = new LogIdSet(selector_suspendDeliver_demux_40);
        MaceTransportService::selectorId_cancellocalTimer = new LogIdSet(selector_cancellocalTimer);
        MaceTransportService::selectorId_incrementAcked_routine_0 = new LogIdSet(selector_incrementAcked_routine_0);
        MaceTransportService::selectorId_hashState_demux_48 = new LogIdSet(selector_hashState_demux_48);
        MaceTransportService::selectorId_registerUniqueHandler_demux_33 = new LogIdSet(selector_registerUniqueHandler_demux_33);
        MaceTransportService::selectorId_maceReset_demux_46 = new LogIdSet(selector_maceReset_demux_46);
        MaceTransportService::selectorId_registerHandler_demux_28 = new LogIdSet(selector_registerHandler_demux_28);
        MaceTransportService::selectorId_route_downcall_14 = new LogIdSet(selector_route_downcall_14);
        MaceTransportService::selectorId_route_downcall_9 = new LogIdSet(selector_route_downcall_9);
        MaceTransportService::selectorId_expireretransmissionTimer = new LogIdSet(selector_expireretransmissionTimer);
        MaceTransportService::selectorId_downcall_canSend_9_transition = new LogIdSet(selector_downcall_canSend_9_transition);
        MaceTransportService::selectorId_notifyFlushed_upcall_4 = new LogIdSet(selector_notifyFlushed_upcall_4);
        MaceTransportService::selectorId_route_downcall_22 = new LogIdSet(selector_route_downcall_22);
        MaceTransportService::selectorId_upcall_deliver_16_transition = new LogIdSet(selector_upcall_deliver_16_transition);
        MaceTransportService::selectorId_downcall_getStatistics_6_transition = new LogIdSet(selector_downcall_getStatistics_6_transition);
        MaceTransportService::selectorId_deliver_demux_4 = new LogIdSet(selector_deliver_demux_4);
        MaceTransportService::selectorId_upcall_messageError_22_transition = new LogIdSet(selector_upcall_messageError_22_transition);
        MaceTransportService::selectorId_downcall_outgoingBufferedDataSize_7_transition = new LogIdSet(selector_downcall_outgoingBufferedDataSize_7_transition);
        MaceTransportService::selectorId_maceInit_demux_43 = new LogIdSet(selector_maceInit_demux_43);
        MaceTransportService::selectorId_unregisterHandler_demux_29 = new LogIdSet(selector_unregisterHandler_demux_29);
        MaceTransportService::selectorId_upcall_messageError_24_transition = new LogIdSet(selector_upcall_messageError_24_transition);
        MaceTransportService::selectorId_resumeDeliver_demux_41 = new LogIdSet(selector_resumeDeliver_demux_41);
        MaceTransportService::selectorId_upcall_deliver_13_transition = new LogIdSet(selector_upcall_deliver_13_transition);
        MaceTransportService::selectorId_send_downcall_17 = new LogIdSet(selector_send_downcall_17);
        MaceTransportService::selectorId_downcall_maceInit_0_transition = new LogIdSet(selector_downcall_maceInit_0_transition);
        MaceTransportService::selectorId_maceExit_demux_45 = new LogIdSet(selector_maceExit_demux_45);
        MaceTransportService::selectorId_closeOutgoingConnection_routine_2 = new LogIdSet(selector_closeOutgoingConnection_routine_2);
        MaceTransportService::selectorId_schedulectsTimer = new LogIdSet(selector_schedulectsTimer);
        MaceTransportService::selectorId_processDeliver_routine_10 = new LogIdSet(selector_processDeliver_routine_10);
        MaceTransportService::selectorId_error_upcall_1 = new LogIdSet(selector_error_upcall_1);
        MaceTransportService::selectorId_schedulelocalTimer = new LogIdSet(selector_schedulelocalTimer);
        MaceTransportService::selectorId_closeIncomingConnection_routine_1 = new LogIdSet(selector_closeIncomingConnection_routine_1);
        MaceTransportService::selectorId_deliver_demux_1 = new LogIdSet(selector_deliver_demux_1);
        MaceTransportService::selectorId_registerHandler_demux_34 = new LogIdSet(selector_registerHandler_demux_34);
        MaceTransportService::selectorId_messageError_demux_10 = new LogIdSet(selector_messageError_demux_10);
        MaceTransportService::selectorId_hasOutgoingBufferedData_demux_23 = new LogIdSet(selector_hasOutgoingBufferedData_demux_23);
        MaceTransportService::selectorId_downcall_setWindowSize_5_transition = new LogIdSet(selector_downcall_setWindowSize_5_transition);
        MaceTransportService::selectorId_sendReset_routine_12 = new LogIdSet(selector_sendReset_routine_12);
        MaceTransportService::selectorId_scheduleretransmissionTimer = new LogIdSet(selector_scheduleretransmissionTimer);
        MaceTransportService::selectorId_route_downcall_11 = new LogIdSet(selector_route_downcall_11);
        MaceTransportService::selectorId_localAddress_demux_47 = new LogIdSet(selector_localAddress_demux_47);
        MaceTransportService::selectorId_unregisterHandler_demux_32 = new LogIdSet(selector_unregisterHandler_demux_32);
        MaceTransportService::selectorId_route_downcall_7 = new LogIdSet(selector_route_downcall_7);
        MaceTransportService::selectorId_updateFlushed_routine_15 = new LogIdSet(selector_updateFlushed_routine_15);
        MaceTransportService::selectorId_suspendDeliver_demux_39 = new LogIdSet(selector_suspendDeliver_demux_39);
        MaceTransportService::selectorId_route_demux_37 = new LogIdSet(selector_route_demux_37);
        MaceTransportService::selectorId_deliver_upcall_0 = new LogIdSet(selector_deliver_upcall_0);
        MaceTransportService::selectorId_requestFlushedNotification_demux_27 = new LogIdSet(selector_requestFlushedNotification_demux_27);
        MaceTransportService::selectorId_unregisterHandler_demux_35 = new LogIdSet(selector_unregisterHandler_demux_35);
        MaceTransportService::selectorId_expire_ctsTimer_demux_51 = new LogIdSet(selector_expire_ctsTimer_demux_51);
        MaceTransportService::selectorId_printConnection_routine_17 = new LogIdSet(selector_printConnection_routine_17);
        MaceTransportService::selectorId_messageError_demux_6 = new LogIdSet(selector_messageError_demux_6);
        MaceTransportService::selectorId_messageError_demux_8 = new LogIdSet(selector_messageError_demux_8);
        MaceTransportService::selectorId_availableBufferSize_demux_12 = new LogIdSet(selector_availableBufferSize_demux_12);
        MaceTransportService::selectorId_downcall_outgoingBufferedDataSize_4_transition = new LogIdSet(selector_downcall_outgoingBufferedDataSize_4_transition);
        MaceTransportService::selectorId_outgoingBufferedDataSize_routine_21 = new LogIdSet(selector_outgoingBufferedDataSize_routine_21);
        MaceTransportService::selectorId_scheduler_expire_ctsTimer_19_transition = new LogIdSet(selector_scheduler_expire_ctsTimer_19_transition);
        MaceTransportService::selectorId_expirectsTimer = new LogIdSet(selector_expirectsTimer);
        MaceTransportService::selectorId_route_downcall_4 = new LogIdSet(selector_route_downcall_4);
        MaceTransportService::selectorId_downcall_hasBufferedData_8_transition = new LogIdSet(selector_downcall_hasBufferedData_8_transition);
        MaceTransportService::selectorId_send_downcall_19 = new LogIdSet(selector_send_downcall_19);
        MaceTransportService::selectorId_resumeDeliver_downcall_3 = new LogIdSet(selector_resumeDeliver_downcall_3);
        MaceTransportService::selectorId_downcall_requestFlushedNotification_2_transition = new LogIdSet(selector_downcall_requestFlushedNotification_2_transition);
        MaceTransportService::selectorId_route_downcall_8 = new LogIdSet(selector_route_downcall_8);
        MaceTransportService::selectorId_route_downcall_15 = new LogIdSet(selector_route_downcall_15);
        MaceTransportService::selectorId_downcall_route_1_transition = new LogIdSet(selector_downcall_route_1_transition);
        MaceTransportService::selectorId_sendPackets_routine_13 = new LogIdSet(selector_sendPackets_routine_13);
        MaceTransportService::selectorId_route_downcall_23 = new LogIdSet(selector_route_downcall_23);
        MaceTransportService::selectorId_incomingMessageQueueSize_demux_16 = new LogIdSet(selector_incomingMessageQueueSize_demux_16);
        MaceTransportService::selectorId_messageError_demux_9 = new LogIdSet(selector_messageError_demux_9);
        MaceTransportService::selectorId_error_demux_0 = new LogIdSet(selector_error_demux_0);
        MaceTransportService::selectorId_scheduler_expire_localTimer_18_transition = new LogIdSet(selector_scheduler_expire_localTimer_18_transition);
        MaceTransportService::selectorId_upcall_deliver_12_transition = new LogIdSet(selector_upcall_deliver_12_transition);
        MaceTransportService::selectorId_send_downcall_20 = new LogIdSet(selector_send_downcall_20);
        MaceTransportService::selectorId_route_downcall_12 = new LogIdSet(selector_route_downcall_12);
        MaceTransportService::selectorId_setWindowSize_demux_17 = new LogIdSet(selector_setWindowSize_demux_17);
        MaceTransportService::selectorId_routeRTS_demux_26 = new LogIdSet(selector_routeRTS_demux_26);
        MaceTransportService::selectorId_outgoingBufferedDataSize_demux_13 = new LogIdSet(selector_outgoingBufferedDataSize_demux_13);
        MaceTransportService::selectorId_messageError_demux_7 = new LogIdSet(selector_messageError_demux_7);
        MaceTransportService::selectorId_upcallMessageErrors_routine_6 = new LogIdSet(selector_upcallMessageErrors_routine_6);
        MaceTransportService::selectorId_deliverBuffered_routine_4 = new LogIdSet(selector_deliverBuffered_routine_4);
        MaceTransportService::selectorId_route_downcall_13 = new LogIdSet(selector_route_downcall_13);
        MaceTransportService::selectorId_deliver_demux_3 = new LogIdSet(selector_deliver_demux_3);
        MaceTransportService::selectorId_send_downcall_24 = new LogIdSet(selector_send_downcall_24);
        MaceTransportService::selectorId_upcall_deliver_15_transition = new LogIdSet(selector_upcall_deliver_15_transition);
        MaceTransportService::selectorId_sendAck_routine_11 = new LogIdSet(selector_sendAck_routine_11);
        MaceTransportService::selectorId_inflightSize_routine_18 = new LogIdSet(selector_inflightSize_routine_18);
        MaceTransportService::selectorId_suspendDeliver_downcall_0 = new LogIdSet(selector_suspendDeliver_downcall_0);
        MaceTransportService::selectorId_upcall_messageError_23_transition = new LogIdSet(selector_upcall_messageError_23_transition);
        MaceTransportService::selectorId_closeBidirectionalConnection_routine_3 = new LogIdSet(selector_closeBidirectionalConnection_routine_3);
        MaceTransportService::selectorId_checkRetransmissionTimerCount_routine_20 = new LogIdSet(selector_checkRetransmissionTimerCount_routine_20);
        MaceTransportService::selectorId_requestToSend_demux_20 = new LogIdSet(selector_requestToSend_demux_20);
        
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_canSend48", "canSend( const MaceKey& peer, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_outgoingBufferedDataSize50", "outgoingBufferedDataSize( const MaceKey& peer, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_setWindowSize54", "setWindowSize( const MaceKey& peer, uint64_t microsec, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_getStatistics56", "getStatistics( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_requestToSend57", "requestToSend( const MaceKey& peer, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_hasBufferedData59", "hasBufferedData(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_hasOutgoingBufferedData60", "hasOutgoingBufferedData(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_outgoingBufferedDataSize61", "outgoingBufferedDataSize(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_routeRTS62", "routeRTS( const MaceKey& dest,  const std::string& s, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_requestFlushedNotification64", "requestFlushedNotification(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route65", "route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_maceInit71", "maceInit()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_maceReset74", "maceReset()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_hashState76", "hashState() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliver78", "deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliver79", "deliver( const MaceKey& source,  const MaceKey& destination,  const DataFragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliver80", "deliver( const MaceKey& source,  const MaceKey& destination,  const Fragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliver81", "deliver( const MaceKey& source,  const MaceKey& destination,  const Ack& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliver82", "deliver( const MaceKey& source,  const MaceKey& destination,  const Reset& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_messageError83", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_messageError84", "messageError( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_messageError85", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_messageError86", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_messageError87", "messageError( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_expire_retransmissionTimer88", "expire_retransmissionTimer(MaceKey& p0, MessageInfoPtr& p1)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_expire_localTimer89", "expire_localTimer(std::string& p0, registration_uid_t& p1)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_expire_ctsTimer90", "expire_ctsTimer(MaceKey& p0)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_suspendDeliver23", "suspendDeliver(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_suspendDeliver24", "suspendDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_resumeDeliver25", "resumeDeliver(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_resumeDeliver26", "resumeDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route27", "route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route28", "route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route29", "route( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route30", "route( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route31", "route( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route32", "route( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route33", "route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route34", "route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route35", "route( const MaceKey& src,  const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route36", "route( const MaceKey& src,  const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route37", "route( const MaceKey& src,  const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_route38", "route( const MaceKey& src,  const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send39", "send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send40", "send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send41", "send( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send42", "send( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send43", "send( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_send44", "send( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_upcall_notifyFlushed22", "notifyFlushed(registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_incrementAcked0", "incrementAcked(OutgoingConnection& c, uint32_t size)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_closeIncomingConnection1", "closeIncomingConnection( const MaceKey& src, TransportError::type error,  const std::string& errstr, bool upcallError)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_closeOutgoingConnection2", "closeOutgoingConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr, bool upcallError)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_closeBidirectionalConnection3", "closeBidirectionalConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_deliverBuffered4", "deliverBuffered(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_upcallDeliver5", "upcallDeliver(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest,  const std::string& payload, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_processDeliver10", "processDeliver( const MaceKey& src,  const MaceKey& dest, seq_t seq, mace::string payload, uint32_t ssize, registration_uid_t rid, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t nfrag, uint32_t frag)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_sendAck11", "sendAck( const MaceKey& src, seq_t seq, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t sz, seq_t& ackseq, bool& discard)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_sendReset12", "sendReset( const MaceKey& dest, mace::MonotoneTime id, seq_t seq)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_sendPackets13", "sendPackets(OutgoingConnection& c)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_enqueue14", "enqueue(OutgoingConnection& c,  const std::string& s, registration_uid_t rid)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_updateFlushed15", "updateFlushed(OutgoingConnection& c)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_checkAndNotifyFlushed16", "checkAndNotifyFlushed()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_printConnection17", "printConnection( const OutgoingConnection& c,  const std::string& s) const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_inflightSize18", "inflightSize() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_checkRetransmissionTimer19", "checkRetransmissionTimer() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_checkRetransmissionTimerCount20", "checkRetransmissionTimerCount() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_outgoingBufferedDataSize21", "outgoingBufferedDataSize() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_ConnectionInfo_updateRTO", "updateRTO( const MaceTime& ts)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_ConnectionInfo_increaseCWND", "increaseCWND()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_ConnectionInfo_timeout", "timeout()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_canSend", "canSend() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_updateCanSendOnWrite", "updateCanSendOnWrite(uint64_t maxsize, uint64_t threshold)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_updateCanSendOnEnqueue", "updateCanSendOnEnqueue(uint64_t maxsize)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_bufferedDataSize", "bufferedDataSize() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_hasQueuedMessages", "hasQueuedMessages() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_queuedMessagesSize", "queuedMessagesSize() const"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_nextSeq", "nextSeq()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_getSyn", "getSyn()"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_setLast", "setLast(seq_t s)"), 0);
        Log::binaryLog(mid, MethodMap_namespace::MethodMap("MaceTransport_OutgoingConnection_fastRetransmit", "fastRetransmit() const"), 0);
        
      }
    }
    
    void MaceTransportService::incrementAcked(
        #line 676 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 676 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t size
#line 3157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_incrementAcked_routine_0
      #define selectorId selectorId_incrementAcked_routine_0
      ADD_LOG_BACKING
      bool __test = shouldLog_incrementAcked0(c, size);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, incrementAcked0Dummy(c, size), 0);
        }
      }
      
      
      
      #line 676 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        c.acked += size;
        c.updateCanSendOnWrite(maxQueueSize, queueThreshold);
        if (!c.rts.empty() && c.canSend()) {
          ctsTimer.schedule(1, c.getId());
        }
      }
#line 3191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::closeIncomingConnection(
        #line 684 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3202 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 684 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 685 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3210 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 685 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool upcallError
#line 3214 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_closeIncomingConnection_routine_1
      #define selectorId selectorId_closeIncomingConnection_routine_1
      ADD_LOG_BACKING
      bool __test = shouldLog_closeIncomingConnection1(src, error, errstr, upcallError);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, closeIncomingConnection1Dummy(src, error, errstr, upcallError), 0);
        }
      }
      
      
      
      #line 685 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        
        maceout << "closing incoming connection to " << src << Log::endl;
        //     if (closeOut) {
          //       OutgoingConnectionMap::iterator o = out.find(src);
          //       if (o != out.end()) {
            // 	closeConnection(src, o->second, error, errstr);
            //       }
          //       else {
            // 	closeOut = false;
            //       }
          //     }
        //     if (!closeOut) {
          if (upcallError) {
            // fix for MT10
            ctsTimer.cancel(src);
            if (out.containsKey(src)) {
              out.get(src).rts.clear();
            }
            upcallAllVoid(error, src, error, errstr);
          }
          //     }
        
        in.erase(src);
        MonotoneIdMap::iterator i = lastSyn.find(src);
        if (i != lastSyn.end()) {
          i->second++;
        }
        
      }
#line 3271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::closeOutgoingConnection(
        #line 716 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3282 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 716 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3286 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 717 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 717 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 718 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool upcallError
#line 3298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_closeOutgoingConnection_routine_2
      #define selectorId selectorId_closeOutgoingConnection_routine_2
      ADD_LOG_BACKING
      bool __test = shouldLog_closeOutgoingConnection2(dest, c, error, errstr, upcallError);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, closeOutgoingConnection2Dummy(dest, c, error, errstr, upcallError), 0);
        }
      }
      
      
      
      #line 718 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        maceout << "closing outdoing connection to " << dest << Log::endl;
        if (c.flushed) {
          flushedCount--;
        }
        
        // fix for MT bug 2
        for (MessagePtrMap::const_iterator i = c.inflight.begin();
            i != c.inflight.end(); i++) {
          retransmissionTimer.cancel(i->second->timer);
        }
        
        OutgoingConnection cc = c;
        out.erase(dest);
        
        if (upcallError) {
          // fix for MT10
          ctsTimer.cancel(dest);
          upcallAllVoid(error, dest, error, errstr);
        }
        
        if (UPCALL_MESSAGE_ERROR) {
          
          maceout << "upcalling message errors for " << cc << Log::endl;
          IdSet seen;
          upcallMessageErrors(cc.inflight.begin(), cc.inflight.end(), dest, cc, seen, error);
          upcallMessageErrors(cc.rtbuf.begin(), cc.rtbuf.end(), dest, cc, seen, error);
          upcallMessageErrors(cc.sendbuf.begin(), cc.sendbuf.end(), dest, cc, seen, error);
        }
        
        checkAndNotifyFlushed();
      }
#line 3357 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::closeBidirectionalConnection(
        #line 751 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3368 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 751 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 752 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 753 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_closeBidirectionalConnection_routine_3
      #define selectorId selectorId_closeBidirectionalConnection_routine_3
      ADD_LOG_BACKING
      bool __test = shouldLog_closeBidirectionalConnection3(dest, c, error, errstr);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, closeBidirectionalConnection3Dummy(dest, c, error, errstr), 0);
        }
      }
      
      
      
      #line 753 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        maceout << "closing bidirectional connection to " << dest << Log::endl;
        // bug fix for MT # 7
        closeOutgoingConnection(dest, c, error, errstr);
        closeIncomingConnection(dest, error, errstr, false);
      }
#line 3413 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::deliverBuffered(
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IncomingConnection& c
#line 3424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3432 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliverBuffered_routine_4
      #define selectorId selectorId_deliverBuffered_routine_4
      ADD_LOG_BACKING
      bool __test = shouldLog_deliverBuffered4(c, src, dest);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliverBuffered4Dummy(c, src, dest), 0);
        }
      }
      
      
      
      #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        MessagePtrMap::iterator i = c.m.begin();
        if (i != c.m.end()) {
          //       maceout << "seq=" << i->second->seq << " nextDeliver=" << c.nextDeliver << Log::endl;
        }
        while (i != c.m.end() && i->second->seq == c.nextDeliver) {
          MessageInfoPtr m = i->second;
          
          maceout << "seq=" << m->seq << " nfrag=" << m->nfrag
          << " fragrecv=" << m->fragrecv << Log::endl;
          
          if (m->nfrag) {
            if (m->nfrag == m->fragrecv) {
              // 	  maceout << "erasing " << i->second->seq << Log::endl;
              c.m.erase(i);
              i = c.m.begin();
              for (size_t j = 1; j < m->nfrag; j++) {
                ASSERT(i != c.m.end());
                // 	    maceout << "checking that " << i->first << " == " << m->seq + j
                // 		    << " m->seq=" << m->seq << " j=" << j << Log::endl;
                ASSERT(i->first == m->seq + j);
                ASSERT(i->second->seq == m->seq + j);
                m->payload.append(i->second->payload);
                c.m.erase(i);
                // 	    maceout << "erasing " << i->second->seq << Log::endl;
                i = c.m.begin();
              }
              c.nextDeliver += (m->nfrag - 1);
            }
            else {
              return;
            }
          }
          else {
            c.m.erase(i);
            i = c.m.begin();
          }
          maceout << "delivering " << m->seq << Log::endl;
          upcallDeliver(c, src, dest, m->payload, m->rid);
        }
      }
#line 3500 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::upcallDeliver(
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IncomingConnection& c
#line 3511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 803 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& payload
#line 3523 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 803 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_upcallDeliver_routine_5
      #define selectorId selectorId_upcallDeliver_routine_5
      ADD_LOG_BACKING
      bool __test = shouldLog_upcallDeliver5(c, src, dest, payload, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, upcallDeliver5Dummy(c, src, dest, payload, rid), 0);
        }
      }
      
      
      
      #line 803 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        upcall_deliver(src, dest, payload, rid);
        c.nextDeliver++;
      }
#line 3558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::upcallMessageErrors(
        #line 808 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrMap::iterator i
#line 3569 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 808 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrMap::iterator end
#line 3573 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3577 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3581 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3585 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 810 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3589 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_upcallMessageErrors_routine_6
      #define selectorId selectorId_upcallMessageErrors_routine_6
      ADD_LOG_BACKING
      
      
      
      #line 810 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        while (i != end) {
          upcallMessageError(dest, i->second, c, seen, error);
          i++;
        }
      }
#line 3613 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::upcallMessageErrors(
        #line 817 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrList::iterator i
#line 3624 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 817 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrList::iterator end
#line 3628 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3632 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3636 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3640 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 819 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3644 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_upcallMessageErrors_routine_7
      #define selectorId selectorId_upcallMessageErrors_routine_7
      ADD_LOG_BACKING
      
      
      
      #line 819 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        while (i != end) {
          upcallMessageError(dest, *i, c, seen, error);
          i++;
        }
      }
#line 3668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::upcallMessageError(
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr m
#line 3683 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3687 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 827 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3691 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 827 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3695 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_upcallMessageError_routine_8
      #define selectorId selectorId_upcallMessageError_routine_8
      ADD_LOG_BACKING
      
      
      
      #line 827 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (!m->nfrag) {
          upcallMessageError(dest, m, c, error);
        }
        else if (!seen.contains(m->id)) {
          upcallMessageError(dest, m, c, error);
          seen.insert(m->id);
        }
      }
#line 3722 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::upcallMessageError(
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr m
#line 3737 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3741 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 838 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3745 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_upcallMessageError_routine_9
      #define selectorId selectorId_upcallMessageError_routine_9
      ADD_LOG_BACKING
      
      
      
      #line 838 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (m->nfrag) {
          const std::string& data = c.unfragged.get(m->id);
          maceout << "upcalling message error for " << HashUtil::compute32bitHex(data)
          << Log::endl;
          upcall_messageError(dest, error, data, m->rid);
        }
        else {
          maceout << "upcalling message error for " << HashUtil::compute32bitHex(m->payload)
          << Log::endl;
          upcall_messageError(dest, error, m->payload, m->rid);
        }
      }
#line 3776 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::processDeliver(
        #line 852 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 852 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 3795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::string payload
#line 3799 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t ssize
#line 3803 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 854 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3807 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 854 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn
#line 3811 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 855 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho
#line 3815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 856 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t nfrag
#line 3819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 856 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t frag
#line 3823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_processDeliver_routine_10
      #define selectorId selectorId_processDeliver_routine_10
      ADD_LOG_BACKING
      bool __test = shouldLog_processDeliver10(src, dest, seq, payload, ssize, rid, syn, synecho, nfrag, frag);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, processDeliver10Dummy(src, dest, seq, payload, ssize, rid, syn, synecho, nfrag, frag), 0);
        }
      }
      
      
      
      #line 856 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        ASSERT(src != localAddress());
        seq_t ackseq = 0;
        bool discard = false;
        IncomingConnection& c = sendAck(src, seq, syn, synecho, ssize, ackseq, discard);
        if (discard) {
          return;
        }
        
        maceout << src << " seq=" << seq << " ackseq=" << ackseq << " nextDeliver="
        << c.nextDeliver << " syn=" << syn << " nfrag=" << nfrag
        << " frag=" << frag << Log::endl;
        
        if (c.m.containsKey(seq)) {
          MessageInfoPtr minfo = c.m[seq];
          // fix for MT bug # 11
          minfo->retries++;
          if (minfo->retries >= FAST_RESET_DUP) {
            maceout << "performing fast reset on connection from " << src << Log::endl;
            sendReset(src, 0, seq);
            closeIncomingConnection(src, TransportError::READ_ERROR,
                "connection reset");
          }
          else {
            // fix for MT bug # 8
            maceout << "ignoring duplicate buffered message " << seq << " with "
            << minfo->retries << " retries" << Log::endl;
          }
          return;
        }
        
        if (frag || nfrag) {
          MessageInfoPtr minfo = MessageInfoPtr(new MessageInfo(seq, payload, rid,
                  frag, nfrag,
                  (nfrag ? 1 : 0)));
          c.m[seq] = minfo;
          
          if (nfrag) {
            // see if we already have fragments for this message
            seq_t last = seq + nfrag;
            MessagePtrMap::iterator i = c.m.find(seq);
            i++;
            while ((i != c.m.end()) && (i->second->seq < last)) {
              minfo->fragrecv++;
              maceout << "already received " << i->second->seq
              << ", incremented fragrecv to " << minfo->fragrecv << Log::endl;
              i++;
            }
            maceout << "received DataFragment seq=" << minfo->seq << " nfrag=" << minfo->nfrag
            << " last=" << last << " fragrecv=" << minfo->fragrecv << Log::endl;
          }
          else {
            ASSERT(frag);
            seq_t first = seq - frag;
            MessagePtrMap::iterator i = c.m.find(first);
            if (i != c.m.end()) {
              i->second->fragrecv++;
              maceout << "received Fragment seq=" << minfo->seq << " frag=" << minfo->frag
              << ", incremented fragrev=" << i->second->fragrecv << Log::endl;
            }
            else {
              maceout << "received Fragment seq=" << minfo->seq << " frag=" << minfo->frag
              << ", did not yet receive correpsonding data frag" << Log::endl;
            }
          }
        }
        else {
          if (ackseq < seq) {
            c.m[seq] = MessageInfoPtr(new MessageInfo(seq, payload, rid));
            return;
          }
          
          //       ASSERT(ackseq == seq);
          
          //       MaceKey nexthop = localAddress();
          //       bool f = upcall_forward(src, dest, nexthop, payload, COMM_TYPE_UNICAST, rid);
          //       if (!f) {
            // 	c.nextDeliver++;
            //       }
          //       else {
            ASSERT(seq == c.nextDeliver);
            upcallDeliver(c, src, dest, payload, rid);
            //       }
        }
        
        deliverBuffered(c, src, dest);
      }
#line 3937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    IncomingConnection& MaceTransportService::sendAck(
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 3951 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn
#line 3955 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho
#line 3959 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t sz
#line 3963 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t& ackseq
#line 3967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool& discard
#line 3971 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_sendAck_routine_11
      #define selectorId selectorId_sendAck_routine_11
      ADD_LOG_BACKING
      bool __test = shouldLog_sendAck11(src, seq, syn, synecho, sz, ackseq, discard);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, sendAck11Dummy(src, seq, syn, synecho, sz, ackseq, discard), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_sendAck(
              #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              src
#line 4000 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              seq
#line 4004 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              syn
#line 4008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              synecho
#line 4012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              sz
#line 4016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              ackseq
#line 4020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
              ,
              #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
              discard
#line 4024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          ), selectorId->compiler, "rv_IncomingConnection_");
      
      #undef selector
      #undef selectorId
      
    }
    
    IncomingConnection& MaceTransportService::__mace_log_sendAck(
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 4035 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 4039 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn
#line 4043 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho
#line 4047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t sz
#line 4051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t& ackseq
#line 4055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool& discard
#line 4059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_sendAck_routine_11
      #define selectorId selectorId_sendAck_routine_11
      ADD_LOG_BACKING
      
      
      
      #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        discard = false;
        if (syn) {
          maceout << "received syn=" << syn << " synecho=" << synecho
          << " from " << src << Log::endl;
          MonotoneIdMap::iterator i = lastSyn.find(src);
          if (i != lastSyn.end()) {
            if (syn < i->second) {
              maceout << "received syn with old time" << syn << " < " << i->second << Log::endl;
              discard = true;
              ackseq = 0;
              sendReset(src, syn, seq);
            }
            else if (i->second == syn) {
              maceout << "received duplicate syn " << syn << Log::endl;
            }
            else {
              OutgoingConnectionMap::iterator o = out.find(src);
              bool closeIn = true;
              if (o != out.end()) {
                OutgoingConnection& c = o->second;
                if (c.syn != synecho) {
                  maceout << "closing bidirectional connection synecho=" << synecho
                  << " syn=" << c.syn << Log::endl;
                  closeBidirectionalConnection(src, c, TransportError::READ_ERROR,
                      "connection reset");
                  closeIn = false;
                }
                if (closeIn) {
                  maceout << "closing incoming connection on unexpected syn" << Log::endl;
                  closeIncomingConnection(src, TransportError::READ_ERROR,
                      "connection reset");
                }
              }
            }
          }
        }
        IncomingConnection& c = in.add(src);
        if (discard) {
          return c;
        }
        c.bufStats->append(sz);
        if (c.expectSyn) {
          if (syn) {
            c.expectSyn = false;
            c.next = seq;
            c.nextDeliver = seq;
            // 	c.synSeq = seq;
            // 	c.syn = syn; // fix for bugs # 1 and # 3
            lastSyn[src] = syn; // fix for bugs # 1 and # 3
          }
          else {
            discard = true;
            sendReset(src, 0, seq);
            return c;
          }
        }
        
        maceout << "src=" << src << " seq=" << seq << " c.next=" << c.next << Log::endl;
        
        if (c.next == seq) {
          c.next++;
          MessagePtrMap::const_iterator i = c.m.begin();
          while (i != c.m.end() && i->second->seq <= c.next) {
            if (i->second->seq == c.next) {
              maceout << "incrementing c.next to " << c.next << Log::endl;
              c.next++; // fix for MT bug # 4
            }
            i++;
          }
        }
        else {
          if (seq > c.next) {
            macewarn << "received out-of-order message with seq " << seq
            << " > next " << c.next << Log::endl;
          }
          else {
            macewarn << "discarding message with seq=" << seq << " next=" << c.next
            << Log::endl;
            discard = true;
            c.discardedPackets++;
          }
          //       ackseq--; // fix for bug # 5 (moved from seq > c.next to both cases)
        }
        ackseq = c.next - 1;
        
        maceout << "sending ack to " << src << " for " << ackseq << Log::endl;
        downcall_route(src, Ack(ackseq));
        
        return c;
      }
#line 4168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::sendReset(
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 4179 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime id
#line 4183 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 4187 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_sendReset_routine_12
      #define selectorId selectorId_sendReset_routine_12
      ADD_LOG_BACKING
      bool __test = shouldLog_sendReset12(dest, id, seq);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, sendReset12Dummy(dest, id, seq), 0);
        }
      }
      
      
      
      #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (!id) {
          MonotoneIdMap::const_iterator i = lastSyn.find(dest);
          if (i != lastSyn.end()) {
            id = i->second;
          }
        }
        maceout << "sending reset to " << dest << " with syn=" << id << Log::endl;
        downcall_route(dest, Reset(id, seq));
      }
#line 4224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::sendPackets(
        #line 1049 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_sendPackets_routine_13
      #define selectorId selectorId_sendPackets_routine_13
      ADD_LOG_BACKING
      bool __test = shouldLog_sendPackets13(c);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, sendPackets13Dummy(c), 0);
        }
      }
      
      
      
      #line 1049 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        printConnection(c, "sendPackets");
        mace::MonotoneTime synecho = 0;
        MonotoneIdMap::const_iterator ii = lastSyn.find(c.getId());
        if (ii != lastSyn.end()) {
          synecho = ii->second;
        }
        while (c.hasQueuedMessages() && (c.inflight.size() < (size_t)c.connection.cwnd)) {
          MessageInfoPtr m;
          if (!c.rtbuf.empty()) {
            m = c.rtbuf.begin()->second;
            c.rtbuf.erase(c.rtbuf.begin());
            maceout << "got message from rtbuf, size remaining=" << c.rtbuf.size()
            << Log::endl;
            c.connection.packetsRetransmitted++;
          }
          else if (!c.sendbuf.empty()) {
            m = c.sendbuf.front();
            c.sendbuf.pop_front();
            maceout << "got message from sendbuf, size remaining=" << c.sendbuf.size()
            << Log::endl;
            c.sent += m->payload.size();
            c.connection.packetsSent++;
            c.updateCanSendOnWrite(maxQueueSize, queueThreshold);
          }
          else {
            ASSERT(0);
          }
          
          if (m) {
            ASSERT(!c.inflight.containsKey(m->seq));
            c.inflight[m->seq] = m;
            const MaceKey& dest = c.getId();
            
            m->ts = curtime;
            if (m->starttime == 0) {
              m->starttime = curtime;
            }
            
            maceout << "scheduling timer for " << c.connection.rto << " " << dest << " " << *m
            << Log::endl;
            m->timer = retransmissionTimer.schedule(c.connection.rto, dest, m);
            m->timeout = true;
            
            maceout << "sending " << *m << " payload size=" << m->payload.size() << Log::endl;
            
            size_t bytes = 0;
            if (m->nfrag) {
              if (m->frag) {
                bytes = downcall_send(dest, Fragment(m->seq, m->frag, m->payload));
              }
              else {
                bytes = downcall_send(dest, DataFragment(m->seq, m->rid, m->syn, synecho,
                        m->nfrag, m->payload));
              }
            }
            else {
              bytes = downcall_send(dest, Data(m->seq, m->rid, m->syn, synecho, m->payload));
            }
            c.bufStats->append(bytes);
          }
        }
        
        if (!c.hasQueuedMessages()) {
          maceout << "no more queued packets to " << c.getId() << Log::endl;
        }
        else {
          maceout << "inflight " << c.inflight.size() << " >= " << (size_t)c.connection.cwnd
          << " cwnd to " << c.getId() << Log::endl;
        }
      }
#line 4333 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::enqueue(
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4344 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 4348 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 4352 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_enqueue_routine_14
      #define selectorId selectorId_enqueue_routine_14
      ADD_LOG_BACKING
      bool __test = shouldLog_enqueue14(c, s, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, enqueue14Dummy(c, s, rid), 0);
        }
      }
      
      
      
      #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        maceout << "s.size=" << s.size()
        << " MAX_DATA_FRAGMENT_MESSAGE_SIZE=" << MAX_DATA_FRAGMENT_MESSAGE_SIZE
        << " MAX_FRAGMENT_MESSAGE_SIZE=" << MAX_FRAGMENT_MESSAGE_SIZE
        << " UdpTransport::MAX_MESSAGE_SIZE=" << UdpTransport::MAX_MESSAGE_SIZE
        << Log::endl;
        if (s.size() <= MAX_DATA_MESSAGE_SIZE) {
          MessageInfoPtr m = MessageInfoPtr(new MessageInfo(c.nextSeq(), s, rid, 0, 0, 0,
                  c.getSyn()));
          c.sendbuf.push_back(m);
          maceout << "enqueued " << *m << Log::endl;
        }
        else {
          size_t sz = s.size() - MAX_DATA_FRAGMENT_MESSAGE_SIZE;
          uint32_t nfrag = 1;
          nfrag += sz / MAX_FRAGMENT_MESSAGE_SIZE;
          if (sz % MAX_FRAGMENT_MESSAGE_SIZE) {
            nfrag++;
          }
          maceout << "nfrag=" << nfrag << Log::endl;
          size_t off = 0;
          mace::MonotoneTime mid = mace::getmtime();
          for (uint32_t i = 0; i < nfrag; i++) {
            size_t len = std::min(MAX_FRAGMENT_MESSAGE_SIZE, s.size() - off);
            if (i == 0) {
              len = MAX_DATA_FRAGMENT_MESSAGE_SIZE;
            }
            maceout << "enqueueing frag " << i << " off=" << off << " len=" << len
            << Log::endl;
            MessageInfoPtr m = MessageInfoPtr(new MessageInfo(c.nextSeq(),
                    s.substr(off, len),
                    rid, i, nfrag, 0, c.getSyn()));
            c.sendbuf.push_back(m);
            // 	m->id = curtime.time();
            m->id = mid;
            maceout << "enqueued " << *m << Log::endl;
            off += len;
          }
          c.unfragged[mid] = s;
        }
        c.queued += s.size();
        if (c.flushed) {
          flushedCount--;
          c.flushed = false;
        }
        //     printConnection(c, "enqueue");
        c.updateCanSendOnEnqueue(maxQueueSize);
      }
#line 4427 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::updateFlushed(
        #line 1170 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_updateFlushed_routine_15
      #define selectorId selectorId_updateFlushed_routine_15
      ADD_LOG_BACKING
      bool __test = shouldLog_updateFlushed15(c);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, updateFlushed15Dummy(c), 0);
        }
      }
      
      
      
      #line 1170 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        ASSERT(!c.flushed);
        if (c.bufferedDataSize() == 0) {
          c.flushed = true;
          flushedCount++;
          checkAndNotifyFlushed();
        }
      }
#line 4473 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::checkAndNotifyFlushed() {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_checkAndNotifyFlushed_routine_16
      #define selectorId selectorId_checkAndNotifyFlushed_routine_16
      ADD_LOG_BACKING
      bool __test = shouldLog_checkAndNotifyFlushed16();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, checkAndNotifyFlushed16Dummy(), 0);
        }
      }
      
      
      
      #line 1179 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (flushedCount == out.size()) {
          for (RegIdSet::const_iterator i = notifyFlushed.begin();
              i != notifyFlushed.end(); i++) {
            upcall_notifyFlushed(*i);
          }
          notifyFlushed.clear();
        }
      }
#line 4516 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    
    void MaceTransportService::printConnection(
        #line 1189 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const OutgoingConnection& c
#line 4527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1189 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 4531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_printConnection_routine_17
      #define selectorId selectorId_printConnection_routine_17
      ADD_LOG_BACKING
      bool __test = shouldLog_printConnection17(c, s);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, printConnection17Dummy(c, s), 0);
        }
      }
      
      
      
      #line 1189 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        if (maceout.isNoop()) {
          return;
        }
        
        if (!s.empty()) {
          maceout << s << ":" << std::endl;
        }
        maceout << c.connection << std::endl;
        maceout << "inflight=" << c.inflight.size() << " rtbuf=" << c.rtbuf.size()
        << " sendbuf=" << c.sendbuf.size()
        << " queued=" << c.queued << " sent=" << c.sent << " acked=" << c.acked
        << std::endl;
        if (1) {
          if (!c.inflight.empty()) {
            maceout << "inflight: " << c.inflight.begin()->first << " "
            << c.inflight.rbegin()->first << std::endl;
          }
          //       maceout << "inflight:" << std::endl;
          //       for (MessagePtrMap::const_iterator i = c.inflight.begin();
              // 	   i != c.inflight.end(); i++) {
            // // 	maceout << i->first << "=" << *(i->second) << std::endl;
            // 	maceout << i->first << std::endl;
            //       }
          if (!c.rtbuf.empty()) {
            maceout << "rtbuf: " << c.rtbuf.begin()->first << " "
            << c.rtbuf.rbegin()->first << std::endl;
          }
          //       maceout << "rtbuf:" << std::endl;
          //       for (MessagePtrMap::const_iterator i = c.rtbuf.begin(); i != c.rtbuf.end(); i++) {
            // // 	maceout << i->first << "=" << *(i->second) << std::endl;
            // 	maceout << i->first << std::endl;
            //       }
          if (!c.sendbuf.empty()) {
            maceout << "sendbuf: " << (*c.sendbuf.begin())->seq << " "
            << (*c.sendbuf.rbegin())->seq << std::endl;
          }
          //       maceout << "sendbuf:" << std::endl;
          //       for (MessagePtrList::const_iterator i = c.sendbuf.begin(); i != c.sendbuf.end(); i++) {
            // 	maceout << **i << std::endl;
            //       }
        }
        
        //     maceout << "unfragged: " << std::endl;
        //     for (IdMessageMap::const_iterator i = c.unfragged.begin(); i != c.unfragged.end(); i++) {
          //       maceout << i->first << "=" << i->second << std::endl;
          //     }
        //     maceout << Log::endl;
        //     maceout << "unfragged: " << std::endl;
        //     for (IdMessageMap::const_iterator i = c.unfragged.begin(); i != c.unfragged.end(); i++) {
          //       maceout << i->first << "=" << i->second << std::endl;
          //     }
        maceout << Log::endl;
      }
#line 4612 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    size_t MaceTransportService::inflightSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_inflightSize_routine_18
      #define selectorId selectorId_inflightSize_routine_18
      ADD_LOG_BACKING
      bool __test = shouldLog_inflightSize18();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, inflightSize18Dummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_inflightSize(), selectorId->compiler, "rv_size_t");
      
      #undef selector
      #undef selectorId
      
    }
    
    size_t MaceTransportService::__mace_log_inflightSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_inflightSize_routine_18
      #define selectorId selectorId_inflightSize_routine_18
      ADD_LOG_BACKING
      
      
      
      #line 1248 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        size_t r = 0;
        for (OutgoingConnectionMap::const_iterator i = out.begin(); i != out.end(); i++) {
          r += i->second.inflight.size();
        }
        return r;
      }
#line 4675 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    bool MaceTransportService::checkRetransmissionTimer() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_checkRetransmissionTimer_routine_19
      #define selectorId selectorId_checkRetransmissionTimer_routine_19
      ADD_LOG_BACKING
      bool __test = shouldLog_checkRetransmissionTimer19();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, checkRetransmissionTimer19Dummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_checkRetransmissionTimer(), selectorId->compiler, "rv_bool");
      
      #undef selector
      #undef selectorId
      
    }
    
    bool MaceTransportService::__mace_log_checkRetransmissionTimer() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_checkRetransmissionTimer_routine_19
      #define selectorId selectorId_checkRetransmissionTimer_routine_19
      ADD_LOG_BACKING
      
      
      
      #line 1256 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        for (OutgoingConnectionMap::const_iterator i = out.begin(); i != out.end(); i++) {
          const OutgoingConnection& c = i->second;
          for (MessagePtrMap::const_iterator mi = c.inflight.begin();
              mi != c.inflight.end(); mi++) {
            if (!retransmissionTimer.isScheduled(mi->second->timer)) {
              return false;
            }
          }
        }
        return true;
      }
#line 4743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    bool MaceTransportService::checkRetransmissionTimerCount() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_checkRetransmissionTimerCount_routine_20
      #define selectorId selectorId_checkRetransmissionTimerCount_routine_20
      ADD_LOG_BACKING
      bool __test = shouldLog_checkRetransmissionTimerCount20();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, checkRetransmissionTimerCount20Dummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_checkRetransmissionTimerCount(), selectorId->compiler, "rv_bool");
      
      #undef selector
      #undef selectorId
      
    }
    
    bool MaceTransportService::__mace_log_checkRetransmissionTimerCount() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_checkRetransmissionTimerCount_routine_20
      #define selectorId selectorId_checkRetransmissionTimerCount_routine_20
      ADD_LOG_BACKING
      
      
      
      #line 1269 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        size_t count = 0;
        for (OutgoingConnectionMap::const_iterator i = out.begin(); i != out.end(); i++) {
          const OutgoingConnection& c = i->second;
          count += c.inflight.size();
        }
        return count == retransmissionTimer.scheduledCount();
      }
#line 4807 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    uint64_t MaceTransportService::outgoingBufferedDataSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_outgoingBufferedDataSize_routine_21
      #define selectorId selectorId_outgoingBufferedDataSize_routine_21
      ADD_LOG_BACKING
      bool __test = shouldLog_outgoingBufferedDataSize21();
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, outgoingBufferedDataSize21Dummy(), 0);
        }
      }
      
      
      
      return mace::logVal(__mace_log_outgoingBufferedDataSize(), selectorId->compiler, "rv_uint64_t");
      
      #undef selector
      #undef selectorId
      
    }
    
    uint64_t MaceTransportService::__mace_log_outgoingBufferedDataSize() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_outgoingBufferedDataSize_routine_21
      #define selectorId selectorId_outgoingBufferedDataSize_routine_21
      ADD_LOG_BACKING
      
      
      
      #line 1278 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      {
        uint64_t r = 0;
        for (OutgoingConnectionMap::const_iterator i = out.begin(); i != out.end(); i++) {
          r += i->second.bufferedDataSize();
        }
        return r;
      }
#line 4870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      #undef selector
      #undef selectorId
      
    }
    
    //END Mace::Compiler::ServiceImpl::printRoutines
    
    //Timer Demux (and utility timer)
    //BEGIN Mace::Compiler::ServiceImpl::printTimerDemux
    void MaceTransportService::expire_retransmissionTimer(MaceKey& p0, MessageInfoPtr& p1) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_expire_retransmissionTimer_demux_49
      #define selectorId selectorId_expire_retransmissionTimer_demux_49
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_expire_retransmissionTimer88(p0, p1);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, expire_retransmissionTimer88Dummy(p0, p1), 0);
        }
      }
      
      
      if(state == exited) {
        { }
      } else
      if(guard_scheduler_17_expire_retransmissionTimer(p0,p1)) {
        macecompiler(1) << "Firing Transition scheduler retransmissionTimer [ guards : (true) ] void expire_retransmissionTimer(MaceKey& dest, MessageInfoPtr& m)" << Log::endl;
        
        
        
        scheduler_17_expire_retransmissionTimer(p0,p1);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        { }
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::expire_localTimer(std::string& p0, registration_uid_t& p1) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_expire_localTimer_demux_50
      #define selectorId selectorId_expire_localTimer_demux_50
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_expire_localTimer89(p0, p1);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, expire_localTimer89Dummy(p0, p1), 0);
        }
      }
      
      
      if(state == exited) {
        { }
      } else
      if(guard_scheduler_18_expire_localTimer(p0,p1)) {
        macecompiler(1) << "Firing Transition scheduler localTimer [ guards : (true) ] void expire_localTimer(std::string& s, registration_uid_t& rid)" << Log::endl;
        
        
        
        scheduler_18_expire_localTimer(p0,p1);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        { }
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::expire_ctsTimer(MaceKey& p0) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_expire_ctsTimer_demux_51
      #define selectorId selectorId_expire_ctsTimer_demux_51
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_expire_ctsTimer90(p0);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, expire_ctsTimer90Dummy(p0), 0);
        }
      }
      
      
      if(state == exited) {
        { }
      } else
      if(guard_scheduler_19_expire_ctsTimer(p0)) {
        macecompiler(1) << "Firing Transition scheduler ctsTimer [ guards : (true) ] void expire_ctsTimer(MaceKey& dest)" << Log::endl;
        
        
        
        scheduler_19_expire_ctsTimer(p0);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        { }
      }
      
      #undef selector
      #undef selectorId
      
    }
    //END Mace::Compiler::ServiceImpl::printTimerDemux
    
    //Load Protocol
    
    //BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol
    BufferedTransportServiceClass& configure_new_MaceTransport_BufferedTransport(bool ___shared);
    TransportServiceClass& configure_new_MaceTransport_Transport(bool ___shared);
    
    void load_protocol() {
      StringSet attr = mace::makeStringSet("MaceTransport", ",");
      mace::ServiceFactory<BufferedTransportServiceClass>::registerService(&configure_new_MaceTransport_BufferedTransport, "MaceTransport");
      mace::ServiceConfig<BufferedTransportServiceClass>::registerService("MaceTransport", attr);
      mace::ServiceFactory<TransportServiceClass>::registerService(&configure_new_MaceTransport_Transport, "MaceTransport");
      mace::ServiceConfig<TransportServiceClass>::registerService("MaceTransport", attr);
    }
    //END Mace::Compiler::ServiceImpl::printLoadProtocol
    
    //Constructors
    //BEGIN Mace::Compiler::ServiceImpl::printConstructor
    BufferedTransportServiceClass& real_new_MaceTransport_BufferedTransport(TransportServiceClass& router,
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool const  UPCALL_MESSAGE_ERROR
#line 5044 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        size_t const  maxQueueSize
#line 5048 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        size_t const  queueThresholdArg
#line 5052 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        , bool ___shared) {
      return *(new MaceTransportService(router,UPCALL_MESSAGE_ERROR,maxQueueSize,queueThresholdArg,___shared));
    }
    TransportServiceClass& real_new_MaceTransport_Transport(TransportServiceClass& router,
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool const  UPCALL_MESSAGE_ERROR
#line 5059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        size_t const  maxQueueSize
#line 5063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        size_t const  queueThresholdArg
#line 5067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        , bool ___shared) {
      return *(new MaceTransportService(router,UPCALL_MESSAGE_ERROR,maxQueueSize,queueThresholdArg,___shared));
    }
    MaceTransportService::MaceTransportService(TransportServiceClass& __router, bool const  _UPCALL_MESSAGE_ERROR, size_t const  _maxQueueSize, size_t const  _queueThresholdArg, bool ___shared) :
    //(
        BaseMaceService(), __inited(0), _actual_state(init), state(_actual_state),
        UPCALL_MESSAGE_ERROR(_UPCALL_MESSAGE_ERROR),
        maxQueueSize(_maxQueueSize),
        queueThresholdArg(_queueThresholdArg),
        _router(__router), router(-1),
        out(),
        in(),
        lastSyn(),
        notifyFlushed(),
        flushedCount(0),
        queueThreshold(queueThresholdArg),
        retransmissionTimer(*(new retransmissionTimer_MaceTimer(this))),
        localTimer(*(new localTimer_MaceTimer(this))),
        ctsTimer(*(new ctsTimer_MaceTimer(this))), __local_address(MaceKey::null)
        {
          initializeSelectors();
          __local_address = computeLocalAddress();
          
          if (___shared) {
            mace::ServiceFactory<BufferedTransportServiceClass>::registerInstance("MaceTransport", this);
            mace::ServiceFactory<TransportServiceClass>::registerInstance("MaceTransport", this);
          }
          ServiceClass::addToServiceList(*this);
          
          
          if (macesim::SimulatorFlags::simulated()) {
            static bool defaultTest = params::get<bool>("AutoTestProperties", 1);
            static bool testThisService = params::get<bool>("AutoTestProperties.MaceTransport", defaultTest);
            if (testThisService) {
              static int testId = NumberGen::Instance(NumberGen::TEST_ID)->GetVal();
              macesim::SpecificTestProperties<MaceTransportService>::registerInstance(testId, this);
            }
          }
          
          ADD_SELECTORS("MaceTransport::(constructor)");
          macedbg(1) << "Created queued instance " << this << Log::endl;
        }
        //)
    MaceTransportService::MaceTransportService(const MaceTransportService& _sv) :
    //(
        BaseMaceService(false), __inited(_sv.__inited), _actual_state(_sv.state), state(_actual_state),
        UPCALL_MESSAGE_ERROR(_sv.UPCALL_MESSAGE_ERROR),
        maxQueueSize(_sv.maxQueueSize),
        queueThresholdArg(_sv.queueThresholdArg),
        _router(_sv._router), router(_sv.router),
        out(_sv.out),
        in(_sv.in),
        lastSyn(_sv.lastSyn),
        notifyFlushed(_sv.notifyFlushed),
        flushedCount(_sv.flushedCount),
        queueThreshold(_sv.queueThreshold),
        retransmissionTimer(*(new retransmissionTimer_MaceTimer(this))),
        localTimer(*(new localTimer_MaceTimer(this))),
        ctsTimer(*(new ctsTimer_MaceTimer(this))){
          ADD_SELECTORS("MaceTransport::(constructor)");
          macedbg(1) << "Created non-queued instance " << this << Log::endl;
        }
        //)
    //END Mace::Compiler::ServiceImpl::printConstructor
    
    //Destructor
    MaceTransportService::~MaceTransportService() {
      delete &retransmissionTimer;
      delete &localTimer;
      delete &ctsTimer;
      mace::ServiceFactory<BufferedTransportServiceClass>::unregisterInstance("MaceTransport", this);
      mace::ServiceFactory<TransportServiceClass>::unregisterInstance("MaceTransport", this);
    }
    
    // Methods for snapshotting...
    void MaceTransportService::snapshot(const uint64_t& ver) const {
      ADD_SELECTORS("MaceTransportService::snapshot");
      //Assumes state is locked.
      MaceTransportService* _sv = new MaceTransportService(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
      ASSERT(versionMap.empty() || versionMap.back().first < ver);
      versionMap.push_back(std::make_pair(ver,_sv));
    }
    void MaceTransportService::snapshotRelease(const uint64_t& ver) const {
      ADD_SELECTORS("MaceTransportService::snapshot");
      //Assumes state is locked.
      while (!versionMap.empty() && versionMap.front().first < ver) {
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    
    
    const ServiceType::state_type& MaceTransportService::read_state() const {
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
    
    
    OutgoingConnectionMap const & MaceTransportService::read_out() const {
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
    
    
    IncomingConnectionMap const & MaceTransportService::read_in() const {
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
    
    
    MonotoneIdMap const & MaceTransportService::read_lastSyn() const {
      int currentMode = mace::AgentLock::getCurrentMode();
      if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
        return lastSyn;
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
        return i->second->lastSyn;
      }
      else {
        ABORT("Invalid attempt to access state from NONE_MODE!");
      }
    }
    
    
    RegIdSet const & MaceTransportService::read_notifyFlushed() const {
      int currentMode = mace::AgentLock::getCurrentMode();
      if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
        return notifyFlushed;
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
        return i->second->notifyFlushed;
      }
      else {
        ABORT("Invalid attempt to access state from NONE_MODE!");
      }
    }
    
    
    uint32_t const & MaceTransportService::read_flushedCount() const {
      int currentMode = mace::AgentLock::getCurrentMode();
      if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
        return flushedCount;
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
        return i->second->flushedCount;
      }
      else {
        ABORT("Invalid attempt to access state from NONE_MODE!");
      }
    }
    
    
    uint32_t const & MaceTransportService::read_queueThreshold() const {
      int currentMode = mace::AgentLock::getCurrentMode();
      if (USING_RWLOCK || currentMode == mace::AgentLock::WRITE_MODE) {
        return queueThreshold;
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
        return i->second->queueThreshold;
      }
      else {
        ABORT("Invalid attempt to access state from NONE_MODE!");
      }
    }
    
    
    //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
    void MaceTransportService::dumpState(LOGLOGTYPE& logger) const {
      logger << "state_dump: " << *this << std::endl;
      return;
    }
    
    void MaceTransportService::print(mace::PrintNode& __pr, const std::string& name) const {
      mace::PrintNode __printer(name, "MaceTransportService");
      const char* __pr_stateName = getStateName(state);
      mace::printItem(__printer, "state", &__pr_stateName);
      mace::printItem(__printer, "out", &(out));
      mace::printItem(__printer, "in", &(in));
      mace::printItem(__printer, "lastSyn", &(lastSyn));
      mace::printItem(__printer, "notifyFlushed", &(notifyFlushed));
      mace::printItem(__printer, "flushedCount", &(flushedCount));
      mace::printItem(__printer, "queueThreshold", &(queueThreshold));
      mace::printItem(__printer, "retransmissionTimer", &retransmissionTimer);
      mace::printItem(__printer, "localTimer", &localTimer);
      mace::printItem(__printer, "ctsTimer", &ctsTimer);
      __pr.addChild(__printer);
      return;
    }
    
    void MaceTransportService::print(std::ostream& __out) const {
      __out << "state=" << getStateName(state) << std::endl;
      __out << "out=";  mace::printItem(__out, &(out));  __out << std::endl;
      __out << "in=";  mace::printItem(__out, &(in));  __out << std::endl;
      __out << "lastSyn=";  mace::printItem(__out, &(lastSyn));  __out << std::endl;
      __out << "notifyFlushed=";  mace::printItem(__out, &(notifyFlushed));  __out << std::endl;
      __out << "flushedCount=";  mace::printItem(__out, &(flushedCount));  __out << std::endl;
      __out << "queueThreshold=";  mace::printItem(__out, &(queueThreshold));  __out << std::endl;
      __out << retransmissionTimer; __out << std::endl;
      __out << localTimer; __out << std::endl;
      __out << ctsTimer; __out << std::endl;
      __out << std::endl;
      if(_printLower) {
        __out  << _router << std::endl;
      }
      return;
    }
    void MaceTransportService::printState(std::ostream& __out) const {
      __out << "state=" << getStateName(state) << std::endl;
      __out << "out=";  mace::printState(__out, &(out), (out));
      __out << "in=";  mace::printState(__out, &(in), (in));
      __out << "lastSyn=";  mace::printState(__out, &(lastSyn), (lastSyn));
      __out << "notifyFlushed=";  mace::printState(__out, &(notifyFlushed), (notifyFlushed));
      __out << "flushedCount=";  mace::printState(__out, &(flushedCount), (flushedCount));
      __out << "queueThreshold=";  mace::printState(__out, &(queueThreshold), (queueThreshold));
      retransmissionTimer.printState(__out);
      localTimer.printState(__out);
      ctsTimer.printState(__out);
      __out << std::endl;
      if(_printLower) {
        _router.printState(__out);
      }
      return;
    }
    
    void MaceTransportService::sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, state TEXT, out INT, in INT, lastSyn INT, notifyFlushed INT, flushedCount INT8, queueThreshold INT8);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_out", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_in", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_lastSyn", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_notifyFlushed", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _outIndex = __node->children[0]->nextId;
      int _inIndex = __node->children[1]->nextId;
      int _lastSynIndex = __node->children[2]->nextId;
      int _notifyFlushedIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index << "\t" << getStateName(state);
      __out << "\t" << _outIndex;
      __out << "\t" << _inIndex;
      __out << "\t" << _lastSynIndex;
      __out << "\t" << _notifyFlushedIndex;
      __out << "\t" << flushedCount;
      __out << "\t" << queueThreshold;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&out, __node->children[0]);
      mace::sqlize(&in, __node->children[1]);
      mace::sqlize(&lastSyn, __node->children[2]);
      mace::sqlize(&notifyFlushed, __node->children[3]);
      
    }
    
    void MaceTransportService::serialize(std::string& __str) const {
      mace::serialize(__str, &state);
      
      #line 301 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(__str, &lastSyn);
#line 5451 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(__str, &notifyFlushed);
#line 5456 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 303 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(__str, &flushedCount);
#line 5461 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 304 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(__str, &queueThreshold);
#line 5466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      
      localTimer.serialize(__str);
      ctsTimer.serialize(__str);
      mace::serialize( __str, &__local_address );
      return;
    }
    
    int MaceTransportService::deserialize(std::istream& __in) throw(SerializationException){
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &_actual_state);
      
      #line 301 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__in, &lastSyn);
#line 5482 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__in, &notifyFlushed);
#line 5487 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 303 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__in, &flushedCount);
#line 5492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      #line 304 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__in, &queueThreshold);
#line 5497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
      
      
      
      serializedByteSize +=  localTimer.deserialize(__in);
      serializedByteSize +=  ctsTimer.deserialize(__in);
      
      MaceKey oldLocalAddress;
      serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
      updateInternalContext( oldLocalAddress, __local_address );
      
      return serializedByteSize;
    }
    void MaceTransportService::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
      
    }
    
    void MaceTransportService::processDeferred() { while (!__deferralArgList_notifyFlushed_registration_uid_t__.empty()) {
        uint64_t _firstcall = std::numeric_limits<uint64_t>::max();
        if (!__deferralArgList_notifyFlushed_registration_uid_t__.empty()) { _firstcall = std::min(_firstcall, __deferralArgList_notifyFlushed_registration_uid_t__.front().__calltime); }
        if (!__deferralArgList_notifyFlushed_registration_uid_t__.empty() && _firstcall == __deferralArgList_notifyFlushed_registration_uid_t__.front().__calltime) {
          __DeferralArgsFornotifyFlushed_registration_uid_t__& a = __deferralArgList_notifyFlushed_registration_uid_t__.front();
          upcall_notifyFlushed(a.rid);
          __deferralArgList_notifyFlushed_registration_uid_t__.pop_front();
        }
      }
    }
    const char* MaceTransportService::getMessageName(uint8_t messageType) const {
      switch(messageType) {
        case Data::messageType: return "MaceTransport::Data";
        case DataFragment::messageType: return "MaceTransport::DataFragment";
        case Fragment::messageType: return "MaceTransport::Fragment";
        case Ack::messageType: return "MaceTransport::Ack";
        case Reset::messageType: return "MaceTransport::Reset";
        default: ASSERT(false); return "INVALID MESSAGE NUMBER";
      }
    }
    void MaceTransportService::changeState(state_type stateNum, int selectorId) {
      _actual_state = stateNum;
      Log::logf(selectorId, "FSM: state changed to %s", getStateName(state));
    }
    const char* MaceTransportService::getStateName(state_type state) const {
      switch(static_cast<uint64_t>(state)) {
        case init: return "MaceTransport::init";
        case exited: return "MaceTransport::exited";
        default: ASSERT(false); return "INVALID STATE NUMBER";
      }
    }
    
    //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
    //BEGIN Mace::Compiler::ServiceImpl::printAPIDemux
    bool MaceTransportService::canSend(
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_canSend_demux_11
      #define selectorId selectorId_canSend_demux_11
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_canSend48(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, canSend48Dummy(peer, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method canSend in base class BufferedTransportServiceClass called."); }
#line 5588 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_9_canSend(peer)) {
        macecompiler(1) << "Firing Transition downcall canSend [ guards : (true) ] bool canSend( const MaceKey& peer)" << Log::endl;
        
        
        
        return mace::logVal( downcall_9_canSend(peer), selectorId->compiler, "rv_bool");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method canSend in base class BufferedTransportServiceClass called."); }
#line 5603 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::availableBufferSize(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5614 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5618 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_availableBufferSize_demux_12
      #define selectorId selectorId_availableBufferSize_demux_12
      ADD_LOG_BACKING
      bool __test = shouldLog_availableBufferSize49(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "availableBufferSize(" << "[peer=";
            mace::printItem(macecompiler(0), &peer);
            macecompiler(0) << "]"
            << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: availableBufferSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method availableBufferSize in base class BufferedTransportServiceClass called."); }
#line 5655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::outgoingBufferedDataSize(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5666 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5670 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_outgoingBufferedDataSize_demux_13
      #define selectorId selectorId_outgoingBufferedDataSize_demux_13
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_outgoingBufferedDataSize50(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, outgoingBufferedDataSize50Dummy(peer, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 5703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_7_outgoingBufferedDataSize(peer)) {
        macecompiler(1) << "Firing Transition downcall outgoingBufferedDataSize [ guards : (true) ] uint32_t outgoingBufferedDataSize( const MaceKey& peer)" << Log::endl;
        
        
        
        return mace::logVal( downcall_7_outgoingBufferedDataSize(peer), selectorId->compiler, "rv_uint32_t");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 5718 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::incomingBufferedDataSize(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_incomingBufferedDataSize_demux_14
      #define selectorId selectorId_incomingBufferedDataSize_demux_14
      ADD_LOG_BACKING
      bool __test = shouldLog_incomingBufferedDataSize51(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "incomingBufferedDataSize(" << "[peer=";
            mace::printItem(macecompiler(0), &peer);
            macecompiler(0) << "]"
            << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: incomingBufferedDataSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method incomingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 5770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::incomingMessageQueueSize(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5781 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5785 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_incomingMessageQueueSize_demux_15
      #define selectorId selectorId_incomingMessageQueueSize_demux_15
      ADD_LOG_BACKING
      bool __test = shouldLog_incomingMessageQueueSize52(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "incomingMessageQueueSize(" << "[peer=";
            mace::printItem(macecompiler(0), &peer);
            macecompiler(0) << "]"
            << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: incomingMessageQueueSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 5822 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::incomingMessageQueueSize(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 5833 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_incomingMessageQueueSize_demux_16
      #define selectorId selectorId_incomingMessageQueueSize_demux_16
      ADD_LOG_BACKING
      bool __test = shouldLog_incomingMessageQueueSize53(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "incomingMessageQueueSize(" << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: incomingMessageQueueSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 5867 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::setWindowSize(
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5878 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint64_t microsec
#line 5882 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5886 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_setWindowSize_demux_17
      #define selectorId selectorId_setWindowSize_demux_17
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_setWindowSize54(peer, microsec, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, setWindowSize54Dummy(peer, microsec, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method setWindowSize in base class BufferedTransportServiceClass called."); }
#line 5919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_5_setWindowSize(peer,microsec)) {
        macecompiler(1) << "Firing Transition downcall setWindowSize [ guards : (true) ] void setWindowSize( const MaceKey& peer, uint64_t size)" << Log::endl;
        
        
        
        downcall_5_setWindowSize(peer,microsec);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method setWindowSize in base class BufferedTransportServiceClass called."); }
#line 5934 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::setQueueSize(
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 5945 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t size
#line 5949 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t threshold
#line 5953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 5957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_setQueueSize_demux_18
      #define selectorId selectorId_setQueueSize_demux_18
      ADD_LOG_BACKING
      bool __test = shouldLog_setQueueSize55(peer, size, threshold, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "setQueueSize(" << "[peer=";
            mace::printItem(macecompiler(0), &peer);
            macecompiler(0) << "]"
            << "[size=";
            mace::printItem(macecompiler(0), &size);
            macecompiler(0) << "]"
            << "[threshold=";
            mace::printItem(macecompiler(0), &threshold);
            macecompiler(0) << "]"
            << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: setQueueSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method setQueueSize in base class BufferedTransportServiceClass called."); }
#line 6000 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    const BufferStatisticsPtr MaceTransportService::getStatistics(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 6011 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        TransportServiceClass::Connection::type d
#line 6015 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 6019 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_getStatistics_demux_19
      #define selectorId selectorId_getStatistics_demux_19
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_getStatistics56(peer, d, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, getStatistics56Dummy(peer, d, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method getStatistics in base class BufferedTransportServiceClass called."); }
#line 6052 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_6_getStatistics(peer,d)) {
        macecompiler(1) << "Firing Transition downcall getStatistics [ guards : (true) ]  const BufferStatisticsPtr getStatistics( const MaceKey& peer, TransportServiceClass::Connection::type d)" << Log::endl;
        
        
        
        return mace::logVal( downcall_6_getStatistics(peer,d), selectorId->compiler, "rv__const_BufferStatisticsPtr");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method getStatistics in base class BufferedTransportServiceClass called."); }
#line 6067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::requestToSend(
        #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 6078 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 6082 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_requestToSend_demux_20
      #define selectorId selectorId_requestToSend_demux_20
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_requestToSend57(peer, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, requestToSend57Dummy(peer, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method requestToSend in base class BufferedTransportServiceClass called."); }
#line 6115 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_10_requestToSend(peer,rid)) {
        macecompiler(1) << "Firing Transition downcall requestToSend [ guards : (true) ] void requestToSend( const MaceKey& peer, registration_uid_t rid)" << Log::endl;
        
        
        
        downcall_10_requestToSend(peer,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method requestToSend in base class BufferedTransportServiceClass called."); }
#line 6130 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::bufferedDataSize(
        #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 6141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_bufferedDataSize_demux_21
      #define selectorId selectorId_bufferedDataSize_demux_21
      ADD_LOG_BACKING
      bool __test = shouldLog_bufferedDataSize58(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "bufferedDataSize(" << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: bufferedDataSize called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method bufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 6175 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::hasBufferedData(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 6186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_hasBufferedData_demux_22
      #define selectorId selectorId_hasBufferedData_demux_22
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_hasBufferedData59(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, hasBufferedData59Dummy(rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method hasBufferedData in base class BufferedTransportServiceClass called."); }
#line 6219 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_8_hasBufferedData(rid)) {
        macecompiler(1) << "Firing Transition downcall hasBufferedData [ guards : (true) ] bool hasBufferedData(registration_uid_t rid)" << Log::endl;
        
        
        
        return mace::logVal( downcall_8_hasBufferedData(rid), selectorId->compiler, "rv_bool");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method hasBufferedData in base class BufferedTransportServiceClass called."); }
#line 6234 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::hasOutgoingBufferedData(
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 6245 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_hasOutgoingBufferedData_demux_23
      #define selectorId selectorId_hasOutgoingBufferedData_demux_23
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_hasOutgoingBufferedData60(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, hasOutgoingBufferedData60Dummy(rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method hasOutgoingBufferedData in base class BufferedTransportServiceClass called."); }
#line 6278 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_3_hasOutgoingBufferedData()) {
        macecompiler(1) << "Firing Transition downcall hasOutgoingBufferedData [ guards : (true) ] bool hasOutgoingBufferedData()" << Log::endl;
        
        
        
        return mace::logVal( downcall_3_hasOutgoingBufferedData(), selectorId->compiler, "rv_bool");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method hasOutgoingBufferedData in base class BufferedTransportServiceClass called."); }
#line 6293 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::outgoingBufferedDataSize(
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 6304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_outgoingBufferedDataSize_demux_24
      #define selectorId selectorId_outgoingBufferedDataSize_demux_24
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_outgoingBufferedDataSize61(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, outgoingBufferedDataSize61Dummy(rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 6337 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_4_outgoingBufferedDataSize()) {
        macecompiler(1) << "Firing Transition downcall outgoingBufferedDataSize [ guards : (true) ] uint32_t outgoingBufferedDataSize()" << Log::endl;
        
        
        
        return mace::logVal( downcall_4_outgoingBufferedDataSize(), selectorId->compiler, "rv_uint32_t");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 6352 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::routeRTS(
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 6363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 6367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 6371 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_routeRTS_demux_25
      #define selectorId selectorId_routeRTS_demux_25
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_routeRTS62(dest, s, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, routeRTS62Dummy(dest, s, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 6404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_11_routeRTS(dest,s,rid)) {
        macecompiler(1) << "Firing Transition downcall routeRTS [ guards : (true) ] bool routeRTS( const MaceKey& dest,  const std::string& s, registration_uid_t rid)" << Log::endl;
        
        
        
        return mace::logVal( downcall_11_routeRTS(dest,s,rid), selectorId->compiler, "rv_bool");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 6419 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::routeRTS(
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& src
#line 6430 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 6434 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 6438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 6442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_routeRTS_demux_26
      #define selectorId selectorId_routeRTS_demux_26
      ADD_LOG_BACKING
      bool __test = shouldLog_routeRTS63(src, dest, s, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "routeRTS(" << "[src=";
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
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: routeRTS called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 6485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::requestFlushedNotification(
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 6496 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_requestFlushedNotification_demux_27
      #define selectorId selectorId_requestFlushedNotification_demux_27
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_requestFlushedNotification64(rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, requestFlushedNotification64Dummy(rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method requestFlushedNotification in base class BufferedTransportServiceClass called."); }
#line 6529 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_2_requestFlushedNotification(rid)) {
        macecompiler(1) << "Firing Transition downcall requestFlushedNotification [ guards : (true) ] void requestFlushedNotification(registration_uid_t rid)" << Log::endl;
        
        
        
        downcall_2_requestFlushedNotification(rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        { ABORT("Unimplemented method requestFlushedNotification in base class BufferedTransportServiceClass called."); }
#line 6544 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::route(
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 6555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 6559 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 6563 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_route_demux_37
      #define selectorId selectorId_route_demux_37
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_route65(dest, s, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route65Dummy(dest, s, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        { return false; }
#line 6596 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_downcall_1_route(dest,s,rid)) {
        macecompiler(1) << "Firing Transition downcall route [ guards : (true) ] bool route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)" << Log::endl;
        
        
        
        return mace::logVal( downcall_1_route(dest,s,rid), selectorId->compiler, "rv_bool");
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        { return false; }
#line 6611 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::route(
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& src
#line 6622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 6626 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 6630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 6634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_route_demux_38
      #define selectorId selectorId_route_demux_38
      ADD_LOG_BACKING
      bool __test = shouldLog_route66(src, dest, s, rid);
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
#line 6679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 6690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_suspendDeliver_demux_39
      #define selectorId selectorId_suspendDeliver_demux_39
      ADD_LOG_BACKING
      bool __test = shouldLog_suspendDeliver67(rid);
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
#line 6724 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 6735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 6739 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_suspendDeliver_demux_40
      #define selectorId selectorId_suspendDeliver_demux_40
      ADD_LOG_BACKING
      bool __test = shouldLog_suspendDeliver68(dest, rid);
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
#line 6776 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 6787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_resumeDeliver_demux_41
      #define selectorId selectorId_resumeDeliver_demux_41
      ADD_LOG_BACKING
      bool __test = shouldLog_resumeDeliver69(rid);
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
#line 6821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 6832 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 6836 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_resumeDeliver_demux_42
      #define selectorId selectorId_resumeDeliver_demux_42
      ADD_LOG_BACKING
      bool __test = shouldLog_resumeDeliver70(dest, rid);
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
#line 6873 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::maceInit() {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_maceInit_demux_43
      #define selectorId selectorId_maceInit_demux_43
      ADD_LOG_BACKING
      bool __test = shouldLog_maceInit71();
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, maceInit71Dummy(), 0);
        }
      }
      
      
      
      if(__inited++ == 0) {
        //TODO: start utility timer as necessary
        
        _router.maceInit();
        if (router == -1) {
          router  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
        }
        
        
        macecompiler(0) << "Registering handler with regId " << router << " and type ReceiveDataHandler for service variable router" << Log::endl;
        _router.registerHandler((ReceiveDataHandler&)*this, router);
        macecompiler(0) << "Registering handler with regId " << router << " and type NetworkErrorHandler for service variable router" << Log::endl;
        _router.registerHandler((NetworkErrorHandler&)*this, router);
        
        if(state == exited) {
          
          #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
          { }
#line 6926 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
        } else
        if(guard_downcall_0_maceInit()) {
          macecompiler(1) << "Firing Transition downcall maceInit [ guards : (true) ] void maceInit()" << Log::endl;
          
          
          
          downcall_0_maceInit();
        } else
        {
          macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
          
          #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
          { }
#line 6941 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
        }
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::maceResume() {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_maceResume_demux_44
      #define selectorId selectorId_maceResume_demux_44
      ADD_LOG_BACKING
      bool __test = shouldLog_maceResume72();
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "maceResume(" << ")" << Log::endl;
      }
      
      
      
      if(__inited++ == 0) {
        //TODO: start utility timer as necessary
        
        _router.maceInit();
        if (router == -1) {
          router  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
        }
        
        
        macecompiler(0) << "Registering handler with regId " << router << " and type ReceiveDataHandler for service variable router" << Log::endl;
        _router.registerHandler((ReceiveDataHandler&)*this, router);
        macecompiler(0) << "Registering handler with regId " << router << " and type NetworkErrorHandler for service variable router" << Log::endl;
        _router.registerHandler((NetworkErrorHandler&)*this, router);
        
        macecompiler(1) << "COMPILER RUNTIME NOTICE: maceResume called, but not implemented" << Log::endl;
        {
          macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
          
          #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
          { }
#line 6996 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
        }
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::maceExit() {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_maceExit_demux_45
      #define selectorId selectorId_maceExit_demux_45
      ADD_LOG_BACKING
      bool __test = shouldLog_maceExit73();
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
#line 7038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
        }
        
        //TODO: stop utility timer as necessary
        _actual_state = exited;
        retransmissionTimer.cancel();
        localTimer.cancel();
        ctsTimer.cancel();
        _router.unregisterHandler((ReceiveDataHandler&)*this, router);
        _router.unregisterHandler((NetworkErrorHandler&)*this, router);
        
        _router.maceExit();
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::maceReset() {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_maceReset_demux_46
      #define selectorId selectorId_maceReset_demux_46
      ADD_LOG_BACKING
      bool __test = shouldLog_maceReset74();
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, maceReset74Dummy(), 0);
        }
      }
      
      
      {
        
        #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
        { }
#line 7088 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      //TODO: stop utility timer as necessary
      _actual_state = init;
      retransmissionTimer.cancel();
      localTimer.cancel();
      ctsTimer.cancel();
      map_ReceiveDataHandler.clear();
      map_NetworkErrorHandler.clear();
      map_ConnectionStatusHandler.clear();
      
      _router.maceReset();
      out = OutgoingConnectionMap();
      in = IncomingConnectionMap();
      lastSyn = MonotoneIdMap();
      notifyFlushed = RegIdSet();
      flushedCount = 0;
      queueThreshold = queueThresholdArg;
      
      __inited = 0;
      
      #undef selector
      #undef selectorId
      
    }
    const MaceKey& MaceTransportService::localAddress() const {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_localAddress_demux_47
      #define selectorId selectorId_localAddress_demux_47
      ADD_LOG_BACKING
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      
      
      {
        
        { return __local_address; }
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    uint32_t MaceTransportService::hashState() const {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_hashState_demux_48
      #define selectorId selectorId_hashState_demux_48
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_hashState76();
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, hashState76Dummy(), 0);
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
    registration_uid_t MaceTransportService::registerHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
      if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
      
      ASSERT(map_ReceiveDataHandler.find(regId) == map_ReceiveDataHandler.end());
      map_ReceiveDataHandler[regId] = &handler;
      return regId;
    }
    
    void MaceTransportService::registerUniqueHandler(ReceiveDataHandler& handler) {
      ASSERT(map_ReceiveDataHandler.empty());
      map_ReceiveDataHandler[-1] = &handler;
    }
    
    void MaceTransportService::unregisterHandler(ReceiveDataHandler& handler, registration_uid_t regId) {
      ASSERT(map_ReceiveDataHandler[regId] == &handler);
      map_ReceiveDataHandler.erase(regId);
    }
    registration_uid_t MaceTransportService::registerHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
      if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
      
      ASSERT(map_NetworkErrorHandler.find(regId) == map_NetworkErrorHandler.end());
      map_NetworkErrorHandler[regId] = &handler;
      return regId;
    }
    
    void MaceTransportService::registerUniqueHandler(NetworkErrorHandler& handler) {
      ASSERT(map_NetworkErrorHandler.empty());
      map_NetworkErrorHandler[-1] = &handler;
    }
    
    void MaceTransportService::unregisterHandler(NetworkErrorHandler& handler, registration_uid_t regId) {
      ASSERT(map_NetworkErrorHandler[regId] == &handler);
      map_NetworkErrorHandler.erase(regId);
    }
    registration_uid_t MaceTransportService::registerHandler(ConnectionStatusHandler& handler, registration_uid_t regId) {
      if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
      
      ASSERT(map_ConnectionStatusHandler.find(regId) == map_ConnectionStatusHandler.end());
      map_ConnectionStatusHandler[regId] = &handler;
      return regId;
    }
    
    void MaceTransportService::registerUniqueHandler(ConnectionStatusHandler& handler) {
      ASSERT(map_ConnectionStatusHandler.empty());
      map_ConnectionStatusHandler[-1] = &handler;
    }
    
    void MaceTransportService::unregisterHandler(ConnectionStatusHandler& handler, registration_uid_t regId) {
      ASSERT(map_ConnectionStatusHandler[regId] == &handler);
      map_ConnectionStatusHandler.erase(regId);
    }
    //END Mace::Compiler::ServiceImpl::printHandlerRegistrations
    
    //Handler demux (uses handlers)
    //BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux
    void MaceTransportService::error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 7249 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 7253 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 7257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 7261 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_error_demux_0
      #define selectorId selectorId_error_demux_0
      ADD_LOG_BACKING
      //locking=" .-1.";
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::NONE_MODE);
      bool __test = shouldLog_error77(nodeId, errorCode, message, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
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
      
      
      macecompiler(1) << "COMPILER RUNTIME NOTICE: error called, but not implemented" << Log::endl;
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7307 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 7318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 7322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 7326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 7330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliver_demux_1
      #define selectorId selectorId_deliver_demux_1
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_deliver78(source, destination, s_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliver78Dummy(source, destination, s_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_12_deliver(source,destination,s_deserialized)) {
        macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Data& m)" << Log::endl;
        
        
        
        upcall_12_deliver(source,destination,s_deserialized);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7378 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 7389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 7393 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 7397 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 7401 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliver_demux_2
      #define selectorId selectorId_deliver_demux_2
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_deliver79(source, destination, s_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliver79Dummy(source, destination, s_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7434 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_13_deliver(source,destination,s_deserialized)) {
        macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const DataFragment& m)" << Log::endl;
        
        
        
        upcall_13_deliver(source,destination,s_deserialized);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7449 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 7460 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 7464 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 7468 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 7472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliver_demux_3
      #define selectorId selectorId_deliver_demux_3
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_deliver80(source, destination, s_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliver80Dummy(source, destination, s_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7505 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_14_deliver(source,destination,s_deserialized)) {
        macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Fragment& m)" << Log::endl;
        
        
        
        upcall_14_deliver(source,destination,s_deserialized);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7520 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 7531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 7535 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 7539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 7543 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliver_demux_4
      #define selectorId selectorId_deliver_demux_4
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_deliver81(source, destination, s_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliver81Dummy(source, destination, s_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7576 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_15_deliver(source,destination,s_deserialized)) {
        macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Ack& ack)" << Log::endl;
        
        
        
        upcall_15_deliver(source,destination,s_deserialized);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7591 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 7602 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 7606 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 7610 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 7614 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_deliver_demux_5
      #define selectorId selectorId_deliver_demux_5
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_deliver82(source, destination, s_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, deliver82Dummy(source, destination, s_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_16_deliver(source,destination,s_deserialized)) {
        macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const Reset& rst)" << Log::endl;
        
        
        
        upcall_16_deliver(source,destination,s_deserialized);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        { }
#line 7662 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 7673 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 7677 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& message_deserialized
#line 7681 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 7685 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_messageError_demux_6
      #define selectorId selectorId_messageError_demux_6
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_messageError83(dest, errorCode, message_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, messageError83Dummy(dest, errorCode, message_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7718 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_20_messageError(dest,errorCode,message_deserialized,rid)) {
        macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)" << Log::endl;
        
        
        
        upcall_20_messageError(dest,errorCode,message_deserialized,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 7744 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 7748 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& message_deserialized
#line 7752 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 7756 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_messageError_demux_7
      #define selectorId selectorId_messageError_demux_7
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_messageError84(dest, errorCode, message_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, messageError84Dummy(dest, errorCode, message_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7789 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_21_messageError(dest,errorCode,message_deserialized,rid)) {
        macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid)" << Log::endl;
        
        
        
        upcall_21_messageError(dest,errorCode,message_deserialized,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 7815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 7819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& message_deserialized
#line 7823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 7827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_messageError_demux_8
      #define selectorId selectorId_messageError_demux_8
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_messageError85(dest, errorCode, message_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, messageError85Dummy(dest, errorCode, message_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7860 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_22_messageError(dest,errorCode,message_deserialized,rid)) {
        macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid)" << Log::endl;
        
        
        
        upcall_22_messageError(dest,errorCode,message_deserialized,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7875 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 7886 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 7890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& message_deserialized
#line 7894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 7898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_messageError_demux_9
      #define selectorId selectorId_messageError_demux_9
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_messageError86(dest, errorCode, message_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, messageError86Dummy(dest, errorCode, message_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7931 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_23_messageError(dest,errorCode,message_deserialized,rid)) {
        macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid)" << Log::endl;
        
        
        
        upcall_23_messageError(dest,errorCode,message_deserialized,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 7946 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 7957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 7961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& message_deserialized
#line 7965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 7969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = 1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      MaceTime _curtime = 0;
      #define selector selector_messageError_demux_10
      #define selectorId selectorId_messageError_demux_10
      ADD_LOG_BACKING
      
      mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
      bool __test = shouldLog_messageError87(dest, errorCode, message_deserialized, rid);
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer(__test);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, messageError87Dummy(dest, errorCode, message_deserialized, rid), 0);
        }
      }
      
      
      if(state == exited) {
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 8002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      } else
      if(guard_upcall_24_messageError(dest,errorCode,message_deserialized,rid)) {
        macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid)" << Log::endl;
        
        
        
        upcall_24_messageError(dest,errorCode,message_deserialized,rid);
      } else
      {
        macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
        
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        { }
#line 8017 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      
      #undef selector
      #undef selectorId
      
    }
    //END Mace::Compiler::ServiceImpl::printHandlerDemux
    
    //Downcall helpers (uses)
    //BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers
    
    MaceKey MaceTransportService::downcall_localAddress() const {
      return _router.localAddress();
    }
    const MaceKey& MaceTransportService::downcall_localAddress(const registration_uid_t& rid) const {
      
      if (&rid == &router) {
        return _router.localAddress();
      }
      
      if (rid == router) {
        return _router.localAddress();
      }
      return MaceKey::null;
    }
    void MaceTransportService::downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 8047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_suspendDeliver_downcall_0
      #define selectorId selectorId_suspendDeliver_downcall_0
      ADD_LOG_BACKING
      bool __test = shouldLog_suspendDeliver23(rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, suspendDeliver23Dummy(rid), 0);
        }
      }
      
      
      
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        _router.suspendDeliver(rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 8088 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 8092 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_suspendDeliver_downcall_1
      #define selectorId selectorId_suspendDeliver_downcall_1
      ADD_LOG_BACKING
      bool __test = shouldLog_suspendDeliver24(dest, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, suspendDeliver24Dummy(dest, rid), 0);
        }
      }
      
      
      
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        _router.suspendDeliver(dest,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 8133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_resumeDeliver_downcall_2
      #define selectorId selectorId_resumeDeliver_downcall_2
      ADD_LOG_BACKING
      bool __test = shouldLog_resumeDeliver25(rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, resumeDeliver25Dummy(rid), 0);
        }
      }
      
      
      
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        _router.resumeDeliver(rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 8174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 8178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_resumeDeliver_downcall_3
      #define selectorId selectorId_resumeDeliver_downcall_3
      ADD_LOG_BACKING
      bool __test = shouldLog_resumeDeliver26(dest, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, resumeDeliver26Dummy(dest, rid), 0);
        }
      }
      
      
      
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        _router.resumeDeliver(dest,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8219 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 8223 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8227 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_4
      #define selectorId selectorId_route_downcall_4
      ADD_LOG_BACKING
      bool __test = shouldLog_route27(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route27Dummy(), 0);
        }
      }
      
      
      
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
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8270 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 8274 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8278 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_5
      #define selectorId selectorId_route_downcall_5
      ADD_LOG_BACKING
      bool __test = shouldLog_route28(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route28Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
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
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8321 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 8325 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8329 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_6
      #define selectorId selectorId_route_downcall_6
      ADD_LOG_BACKING
      bool __test = shouldLog_route29(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route29Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, DataFragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 8376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_7
      #define selectorId selectorId_route_downcall_7
      ADD_LOG_BACKING
      bool __test = shouldLog_route30(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route30Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Fragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8423 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 8427 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8431 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_8
      #define selectorId selectorId_route_downcall_8
      ADD_LOG_BACKING
      bool __test = shouldLog_route31(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route31Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Ack> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 8478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8482 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_9
      #define selectorId selectorId_route_downcall_9
      ADD_LOG_BACKING
      bool __test = shouldLog_route32(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route32Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Reset> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8525 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8529 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 8533 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8537 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_10
      #define selectorId selectorId_route_downcall_10
      ADD_LOG_BACKING
      bool __test = shouldLog_route33(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route33Dummy(), 0);
        }
      }
      
      
      
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
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8580 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8584 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 8588 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_11
      #define selectorId selectorId_route_downcall_11
      ADD_LOG_BACKING
      bool __test = shouldLog_route34(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route34Dummy(src, dest, s_deserialized, rid), 0);
        }
      }
      
      
      
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
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8635 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8639 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 8643 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_12
      #define selectorId selectorId_route_downcall_12
      ADD_LOG_BACKING
      bool __test = shouldLog_route35(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route35Dummy(src, dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, DataFragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(src,dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 8698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8702 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_13
      #define selectorId selectorId_route_downcall_13
      ADD_LOG_BACKING
      bool __test = shouldLog_route36(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route36Dummy(src, dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Fragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(src,dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8745 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8749 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 8753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_14
      #define selectorId selectorId_route_downcall_14
      ADD_LOG_BACKING
      bool __test = shouldLog_route37(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route37Dummy(src, dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Ack> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(src,dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    bool MaceTransportService::downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 8800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 8808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8812 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_route_downcall_15
      #define selectorId selectorId_route_downcall_15
      ADD_LOG_BACKING
      bool __test = shouldLog_route38(src, dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, route38Dummy(src, dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Reset> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.route(src,dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 8859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_16
      #define selectorId selectorId_send_downcall_16
      ADD_LOG_BACKING
      bool __test = shouldLog_send39(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send39Dummy(), 0);
        }
      }
      
      
      
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
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 8910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8914 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_17
      #define selectorId selectorId_send_downcall_17
      ADD_LOG_BACKING
      bool __test = shouldLog_send40(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send40Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
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
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 8957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 8961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 8965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_18
      #define selectorId selectorId_send_downcall_18
      ADD_LOG_BACKING
      bool __test = shouldLog_send41(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send41Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, DataFragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.send(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 9008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 9012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 9016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_19
      #define selectorId selectorId_send_downcall_19
      ADD_LOG_BACKING
      bool __test = shouldLog_send42(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send42Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Fragment> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.send(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 9059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 9063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 9067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_20
      #define selectorId selectorId_send_downcall_20
      ADD_LOG_BACKING
      bool __test = shouldLog_send43(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send43Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Ack> __ss_s_deserialized(s, s_deserialized);
      
      if(rid == -1) { rid = router; }
      
      if(rid == router) {
        return _router.send(dest,s,rid);
      } else
      { ABORT("Did not match any registration uid!"); }
      
      #undef selector
      #undef selectorId
      
    }
    size_t MaceTransportService::downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 9110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 9114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 9118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_send_downcall_21
      #define selectorId selectorId_send_downcall_21
      ADD_LOG_BACKING
      bool __test = shouldLog_send44(dest, s_deserialized, rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, send44Dummy(dest, s_deserialized, rid), 0);
        }
      }
      
      
      
      std::string s;
      ScopedSerialize<std::string, Reset> __ss_s_deserialized(s, s_deserialized);
      
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
    void MaceTransportService::defer_upcall_notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid
#line 9165 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) { mace::ScopedStackExecution::addDefer(this); __deferralArgList_notifyFlushed_registration_uid_t__.push_back(__DeferralArgsFornotifyFlushed_registration_uid_t__(rid)); }void MaceTransportService::upcall_deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 9169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 9173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 9177 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 9181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
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
#line 9224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      else {
        iter->second->deliver(source,destination,s,rid);
      }
      
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::upcall_error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 9239 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 9243 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 9247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 9251 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
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
#line 9296 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      else {
        iter->second->error(nodeId,errorCode,message,rid);
      }
      
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::upcall_messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 9311 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 9315 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 9319 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 9323 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
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
#line 9366 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      else {
        iter->second->messageError(dest,errorCode,message,rid);
      }
      
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::upcall_clearToSend(
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        const MaceKey& peer
#line 9381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
        registration_uid_t rid
#line 9385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_clearToSend_upcall_3
      #define selectorId selectorId_clearToSend_upcall_3
      ADD_LOG_BACKING
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if(!macecompiler(0).isNoop()) {
        macecompiler(0) << "clearToSend(" << "[peer=";
            mace::printItem(macecompiler(0), &peer);
            macecompiler(0) << "]"
            << "[rid=";
            mace::printItem(macecompiler(0), &rid);
            macecompiler(0) << "]"
            << ")" << Log::endl;
      }
      
      
      
      
      
      maptype_ConnectionStatusHandler::iterator iter = map_ConnectionStatusHandler.find(rid);
      if(iter == map_ConnectionStatusHandler.end()) {
        maceWarn("No ConnectionStatusHandler registered with uid %"PRIi32" for upcall clearToSend!", rid);
        
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
        { ABORT("Unimplemented method clearToSend in base class ConnectionStatusHandler called."); }
#line 9422 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      else {
        iter->second->clearToSend(peer,rid);
      }
      
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::upcall_notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid
#line 9437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_notifyFlushed_upcall_4
      #define selectorId selectorId_notifyFlushed_upcall_4
      ADD_LOG_BACKING
      bool __test = shouldLog_upcall_notifyFlushed22(rid);
      
      ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (mace::LogicalClock::instance().shouldLogPath()) {
        if (__test) {
          Log::binaryLog(selectorId->compiler, upcall_notifyFlushed22Dummy(rid), 0);
        }
      }
      
      
      
      
      
      maptype_ConnectionStatusHandler::iterator iter = map_ConnectionStatusHandler.find(rid);
      if(iter == map_ConnectionStatusHandler.end()) {
        maceWarn("No ConnectionStatusHandler registered with uid %"PRIi32" for upcall notifyFlushed!", rid);
        
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        { ABORT("Unimplemented method notifyFlushed in base class ConnectionStatusHandler called."); }
#line 9471 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        
      }
      else {
        iter->second->notifyFlushed(rid);
      }
      
      
      #undef selector
      #undef selectorId
      
    }
    //END Mace::Compiler::ServiceImpl::printUpcallHelpers
    
    //Async helpers
    
    //Serial Helper Demux
    //BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux
    void MaceTransportService::deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 9492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 9496 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 9500 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 9504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_deliver_demux_52
      #define selectorId selectorId_deliver_demux_52
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
        
        case DataFragment::messageType: {
          DataFragment s_deserialized;
          s_deserialized.deserializeStr(s);
          //TODO -- trace msg
          
          deliver(source,destination,s_deserialized,rid);
          
        }
        break;
        
        case Fragment::messageType: {
          Fragment s_deserialized;
          s_deserialized.deserializeStr(s);
          //TODO -- trace msg
          
          deliver(source,destination,s_deserialized,rid);
          
        }
        break;
        
        case Ack::messageType: {
          Ack s_deserialized;
          s_deserialized.deserializeStr(s);
          //TODO -- trace msg
          
          deliver(source,destination,s_deserialized,rid);
          
        }
        break;
        
        case Reset::messageType: {
          Reset s_deserialized;
          s_deserialized.deserializeStr(s);
          //TODO -- trace msg
          
          deliver(source,destination,s_deserialized,rid);
          
        }
        break;
        default: {
          maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
          
          #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
          { }
#line 9583 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
          ABORT("INVALID MESSAGE NUMBER");
        }
        break;
      }
      
      #undef selector
      #undef selectorId
      
    }
    void MaceTransportService::messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 9597 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 9601 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& message
#line 9605 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 9609 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
    ) {
      // Method.pm:toString()
      
      __eventContextType = -1;
      
      // Method.pm:toString().
      // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
      // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
      
      
      #define selector selector_messageError_demux_53
      #define selectorId selectorId_messageError_demux_53
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
        
        case DataFragment::messageType: {
          DataFragment message_deserialized;
          message_deserialized.deserializeStr(message);
          //TODO -- trace msg
          
          messageError(dest,errorCode,message_deserialized,rid);
          
        }
        break;
        
        case Fragment::messageType: {
          Fragment message_deserialized;
          message_deserialized.deserializeStr(message);
          //TODO -- trace msg
          
          messageError(dest,errorCode,message_deserialized,rid);
          
        }
        break;
        
        case Ack::messageType: {
          Ack message_deserialized;
          message_deserialized.deserializeStr(message);
          //TODO -- trace msg
          
          messageError(dest,errorCode,message_deserialized,rid);
          
        }
        break;
        
        case Reset::messageType: {
          Reset message_deserialized;
          message_deserialized.deserializeStr(message);
          //TODO -- trace msg
          
          messageError(dest,errorCode,message_deserialized,rid);
          
        }
        break;
        default: {
          maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
          
          #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
          { }
#line 9688 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.cc"
          
          ABORT("INVALID MESSAGE NUMBER");
        }
        break;
      }
      
      #undef selector
      #undef selectorId
      
    }
    //END Mace::Compiler::ServiceImpl::printSerialHelperDemux
    
    //Model checking safety methods
    // Property retransmissionTimerScheduled : ( for all elements n in \nodes it is true that n.checkRetransmissionTimer() )
    bool MaceTransportService::modelProperty_retransmissionTimerScheduled(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { ADD_SELECTORS("MaceTransport::modelProperty_retransmissionTimerScheduled");
      bool retval = retransmissionTimerScheduled_Quantification_0(_nodes_, _keys_);
      maceout << "Property retransmissionTimerScheduled: " << retval << Log::endl;
      return retval;
    }
    bool MaceTransportService::retransmissionTimerScheduled_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::retransmissionTimerScheduled_Quantification_0");
      bool quantity = true;
      
      for (_NodeMap_::const_iterator n = _nodes_.begin(); n != _nodes_.end(); n++) {
        if (!castNode(n, _nodes_, _keys_)->second->checkRetransmissionTimer()) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << _nodes_.size() <<  " ( for all elements n in \nodes it is true that n.checkRetransmissionTimer() )" << Log::endl;
      return quantity;
    }
    
    // Property retransmissionTimerScheduledCount : ( for all elements n in \nodes it is true that n.checkRetransmissionTimerCount() )
    bool MaceTransportService::modelProperty_retransmissionTimerScheduledCount(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { ADD_SELECTORS("MaceTransport::modelProperty_retransmissionTimerScheduledCount");
      bool retval = retransmissionTimerScheduledCount_Quantification_0(_nodes_, _keys_);
      maceout << "Property retransmissionTimerScheduledCount: " << retval << Log::endl;
      return retval;
    }
    bool MaceTransportService::retransmissionTimerScheduledCount_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::retransmissionTimerScheduledCount_Quantification_0");
      bool quantity = true;
      
      for (_NodeMap_::const_iterator n = _nodes_.begin(); n != _nodes_.end(); n++) {
        if (!castNode(n, _nodes_, _keys_)->second->checkRetransmissionTimerCount()) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << _nodes_.size() <<  " ( for all elements n in \nodes it is true that n.checkRetransmissionTimerCount() )" << Log::endl;
      return quantity;
    }
    
    
    //Model checking liveness methods
    // Property inflightEmpty : ( for all elements n in \nodes it is true that ( n.inflightSize() == 0 ) )
    bool MaceTransportService::modelProperty_inflightEmpty(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { ADD_SELECTORS("MaceTransport::modelProperty_inflightEmpty");
      bool retval = inflightEmpty_Quantification_0(_nodes_, _keys_);
      maceout << "Property inflightEmpty: " << retval << Log::endl;
      return retval;
    }
    bool MaceTransportService::inflightEmpty_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::inflightEmpty_Quantification_0");
      bool quantity = true;
      
      for (_NodeMap_::const_iterator n = _nodes_.begin(); n != _nodes_.end(); n++) {
        if (!inflightEmpty_Equation_1(_nodes_, _keys_, n)) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << _nodes_.size() <<  " ( for all elements n in \nodes it is true that ( n.inflightSize() == 0 ) )" << Log::endl;
      return quantity;
    }
    bool MaceTransportService::inflightEmpty_Equation_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { return ( castNode(n, _nodes_, _keys_)->second->inflightSize() == 0 ); }
    
    // Property bufferedDataEmpty : ( for all elements n in \nodes it is true that ( n.outgoingBufferedDataSize() == 0 ) )
    bool MaceTransportService::modelProperty_bufferedDataEmpty(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { ADD_SELECTORS("MaceTransport::modelProperty_bufferedDataEmpty");
      bool retval = bufferedDataEmpty_Quantification_0(_nodes_, _keys_);
      maceout << "Property bufferedDataEmpty: " << retval << Log::endl;
      return retval;
    }
    bool MaceTransportService::bufferedDataEmpty_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::bufferedDataEmpty_Quantification_0");
      bool quantity = true;
      
      for (_NodeMap_::const_iterator n = _nodes_.begin(); n != _nodes_.end(); n++) {
        if (!bufferedDataEmpty_Equation_1(_nodes_, _keys_, n)) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << _nodes_.size() <<  " ( for all elements n in \nodes it is true that ( n.outgoingBufferedDataSize() == 0 ) )" << Log::endl;
      return quantity;
    }
    bool MaceTransportService::bufferedDataEmpty_Equation_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { return ( castNode(n, _nodes_, _keys_)->second->outgoingBufferedDataSize() == 0 ); }
    
    // Property sequenceNumbersMatch : ( for all elements n in \nodes it is true that ( for all elements c in n.out it is true that ( ( ! c->first.in.contains(n)) or ( ( c->second.curseq + 1 ) == c->first.in.get(n).nextDeliver ) ) ) )
    bool MaceTransportService::modelProperty_sequenceNumbersMatch(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { ADD_SELECTORS("MaceTransport::modelProperty_sequenceNumbersMatch");
      bool retval = sequenceNumbersMatch_Quantification_0(_nodes_, _keys_);
      maceout << "Property sequenceNumbersMatch: " << retval << Log::endl;
      return retval;
    }
    bool MaceTransportService::sequenceNumbersMatch_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::sequenceNumbersMatch_Quantification_0");
      bool quantity = true;
      
      for (_NodeMap_::const_iterator n = _nodes_.begin(); n != _nodes_.end(); n++) {
        if (!sequenceNumbersMatch_Quantification_1(_nodes_, _keys_, n)) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << _nodes_.size() <<  " ( for all elements n in \nodes it is true that ( for all elements c in n.out it is true that ( ( ! c->first.in.contains(n)) or ( ( c->second.curseq + 1 ) == c->first.in.get(n).nextDeliver ) ) ) )" << Log::endl;
      return quantity;
    }
    bool MaceTransportService::sequenceNumbersMatch_Quantification_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {
      ADD_SELECTORS("MaceTransport::sequenceNumbersMatch_Quantification_1");
      bool quantity = true;
      
      for (OutgoingConnectionMap::const_iterator c = castNode(n, _nodes_, _keys_)->second->out.begin(); c != castNode(n, _nodes_, _keys_)->second->out.end(); c++) {
        if (!sequenceNumbersMatch_JoinExpression_5(_nodes_, _keys_, n, c)) {
          quantity = false; break;
        }
      }
      maceout << "quantity: " << (quantity?"true":"false") << " size: " << castNode(n, _nodes_, _keys_)->second->out.size() <<  " ( for all elements c in n.out it is true that ( ( ! c->first.in.contains(n)) or ( ( c->second.curseq + 1 ) == c->first.in.get(n).nextDeliver ) ) )" << Log::endl;
      return quantity;
    }
    bool MaceTransportService::sequenceNumbersMatch_JoinExpression_5(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    {return sequenceNumbersMatch_Equation_2(_nodes_, _keys_, n, c) || sequenceNumbersMatch_Equation_4(_nodes_, _keys_, n, c); }
    bool MaceTransportService::sequenceNumbersMatch_Equation_2(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { return ( ! castNode(c->first, _nodes_, _keys_)->second->in.contains(castNode(n, _nodes_, _keys_)->second->localAddress()) ); }
    bool MaceTransportService::sequenceNumbersMatch_Equation_4(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c)
    // Method.pm:toString().
    // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
    // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
    
    
    
    { return ( (c->second.curseq + 1) == castNode(c->first, _nodes_, _keys_)->second->in.get(castNode(n, _nodes_, _keys_)->second->localAddress()).nextDeliver ); }
    
    
  } // end namespace
  
  //END Mace::Compiler::ServiceImpl::printCCFile
