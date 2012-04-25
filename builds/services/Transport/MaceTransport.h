/*********************************************
*  MaceTransport header file
*  Mace generated on:
*  Tue Apr 10 10:09:54 2012
*********************************************/

#ifndef MaceTransport_header
#define MaceTransport_header

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
#include "MaceTransport-constants.h"
#include "lib/ContextBaseClass.h"
#include "lib/ContextLock.h"
#include "lib/ContextMapping.h"
#include "HighLevelEvent.h"

#include "lib/Message.h"
#include "lib/MaceTime.h"
#include "BufferedTransportServiceClass.h"
#include "TransportServiceClass.h"
#include "TransportServiceClass.h"
//END: Mace::Compiler::ServiceImpl::printIncludesH
//BEGIN: Mace::Compiler::ServiceImpl::printUsingH
using mace::BinaryLogObject;
using mace::Serializable;
using mace::SerializationException;
using mace::ContextMapping;
using mace::Message;
using mace::MaceTime;
//END: Mace::Compiler::ServiceImpl::printUsingH
//BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
#line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
#include <boost/shared_ptr.hpp>
#include "NodeCollection.h"
#include "UdpTransport.h"
#include "MaceTime.h"
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
namespace MaceTransport_namespace {
  
  void load_protocol();
  
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  const std::string selector_maceResume_demux_44 = "MaceTransport::maceResume::(demux)";
  const std::string selector_registerUniqueHandler_demux_30 = "MaceTransport::registerUniqueHandler::(demux)";
  const std::string selector_expire_localTimer_demux_50 = "MaceTransport::expire_localTimer::(demux)";
  const std::string selector_checkAndNotifyFlushed_routine_16 = "MaceTransport::checkAndNotifyFlushed::(routine)";
  const std::string selector_deliver_demux_52 = "MaceTransport::deliver::(demux)";
  const std::string selector_route_downcall_6 = "MaceTransport::route::DataFragment::(downcall)";
  const std::string selector_cancelretransmissionTimer = "MaceTransport::cancel::retransmissionTimer::(timer)";
  const std::string selector_upcall_messageError_20_transition = "MaceTransport::messageError::Data::(true)";
  const std::string selector_upcallDeliver_routine_5 = "MaceTransport::upcallDeliver::(routine)";
  const std::string selector_downcall_requestToSend_10_transition = "MaceTransport::requestToSend::(true)";
  const std::string selector_send_downcall_18 = "MaceTransport::send::DataFragment::(downcall)";
  const std::string selector_incomingBufferedDataSize_demux_14 = "MaceTransport::incomingBufferedDataSize::(demux)";
  const std::string selector_scheduler_expire_retransmissionTimer_17_transition = "MaceTransport::expire::expire_retransmissionTimer::(true)";
  const std::string selector_canSend_demux_11 = "MaceTransport::canSend::(demux)";
  const std::string selector_cancelctsTimer = "MaceTransport::cancel::ctsTimer::(timer)";
  const std::string selector_upcall_deliver_14_transition = "MaceTransport::deliver::Fragment::(true)";
  const std::string selector_expirelocalTimer = "MaceTransport::expire::localTimer::(timer)";
  const std::string selector_route_downcall_10 = "MaceTransport::route::Message::(downcall)";
  const std::string selector_clearToSend_upcall_3 = "MaceTransport::clearToSend::(upcall)";
  const std::string selector_route_demux_38 = "MaceTransport::route::(demux)";
  const std::string selector_getStatistics_demux_19 = "MaceTransport::getStatistics::(demux)";
  const std::string selector_checkRetransmissionTimer_routine_19 = "MaceTransport::checkRetransmissionTimer::(routine)";
  const std::string selector_resumeDeliver_demux_42 = "MaceTransport::resumeDeliver::(demux)";
  const std::string selector_downcall_routeRTS_11_transition = "MaceTransport::routeRTS::(true)";
  const std::string selector_registerUniqueHandler_demux_36 = "MaceTransport::registerUniqueHandler::(demux)";
  const std::string selector_hasBufferedData_demux_22 = "MaceTransport::hasBufferedData::(demux)";
  const std::string selector_downcall_hasOutgoingBufferedData_3_transition = "MaceTransport::hasOutgoingBufferedData::(true)";
  const std::string selector_expire_retransmissionTimer_demux_49 = "MaceTransport::expire_retransmissionTimer::(demux)";
  const std::string selector_deliver_demux_2 = "MaceTransport::deliver::DataFragment::(demux)";
  const std::string selector_send_downcall_16 = "MaceTransport::send::Message::(downcall)";
  const std::string selector_enqueue_routine_14 = "MaceTransport::enqueue::(routine)";
  const std::string selector_upcallMessageError_routine_8 = "MaceTransport::upcallMessageError::(routine)";
  const std::string selector_upcall_messageError_21_transition = "MaceTransport::messageError::DataFragment::(true)";
  const std::string selector_messageError_demux_53 = "MaceTransport::messageError::(demux)";
  const std::string selector_registerHandler_demux_31 = "MaceTransport::registerHandler::(demux)";
  const std::string selector_setQueueSize_demux_18 = "MaceTransport::setQueueSize::(demux)";
  const std::string selector_outgoingBufferedDataSize_demux_24 = "MaceTransport::outgoingBufferedDataSize::(demux)";
  const std::string selector_resumeDeliver_downcall_2 = "MaceTransport::resumeDeliver::(downcall)";
  const std::string selector_deliver_demux_5 = "MaceTransport::deliver::Reset::(demux)";
  const std::string selector_messageError_upcall_2 = "MaceTransport::messageError::(upcall)";
  const std::string selector_incomingMessageQueueSize_demux_15 = "MaceTransport::incomingMessageQueueSize::(demux)";
  const std::string selector_upcallMessageError_routine_9 = "MaceTransport::upcallMessageError::(routine)";
  const std::string selector_suspendDeliver_downcall_1 = "MaceTransport::suspendDeliver::(downcall)";
  const std::string selector_upcallMessageErrors_routine_7 = "MaceTransport::upcallMessageErrors::(routine)";
  const std::string selector_routeRTS_demux_25 = "MaceTransport::routeRTS::(demux)";
  const std::string selector_send_downcall_21 = "MaceTransport::send::Reset::(downcall)";
  const std::string selector_bufferedDataSize_demux_21 = "MaceTransport::bufferedDataSize::(demux)";
  const std::string selector_route_downcall_5 = "MaceTransport::route::Data::(downcall)";
  const std::string selector_suspendDeliver_demux_40 = "MaceTransport::suspendDeliver::(demux)";
  const std::string selector_cancellocalTimer = "MaceTransport::cancel::localTimer::(timer)";
  const std::string selector_incrementAcked_routine_0 = "MaceTransport::incrementAcked::(routine)";
  const std::string selector_hashState_demux_48 = "MaceTransport::hashState::(demux)";
  const std::string selector_registerUniqueHandler_demux_33 = "MaceTransport::registerUniqueHandler::(demux)";
  const std::string selector_maceReset_demux_46 = "MaceTransport::maceReset::(demux)";
  const std::string selector_registerHandler_demux_28 = "MaceTransport::registerHandler::(demux)";
  const std::string selector_route_downcall_14 = "MaceTransport::route::Ack::(downcall)";
  const std::string selector_route_downcall_9 = "MaceTransport::route::Reset::(downcall)";
  const std::string selector_expireretransmissionTimer = "MaceTransport::expire::retransmissionTimer::(timer)";
  const std::string selector_downcall_canSend_9_transition = "MaceTransport::canSend::(true)";
  const std::string selector_notifyFlushed_upcall_4 = "MaceTransport::notifyFlushed::(upcall)";
  const std::string selector_route_downcall_22 = "MaceTransport::route::(downcall)";
  const std::string selector_upcall_deliver_16_transition = "MaceTransport::deliver::Reset::(true)";
  const std::string selector_downcall_getStatistics_6_transition = "MaceTransport::getStatistics::(true)";
  const std::string selector_deliver_demux_4 = "MaceTransport::deliver::Ack::(demux)";
  const std::string selector_upcall_messageError_22_transition = "MaceTransport::messageError::Fragment::(true)";
  const std::string selector_downcall_outgoingBufferedDataSize_7_transition = "MaceTransport::outgoingBufferedDataSize::(true)";
  const std::string selector_maceInit_demux_43 = "MaceTransport::maceInit::(demux)";
  const std::string selector_unregisterHandler_demux_29 = "MaceTransport::unregisterHandler::(demux)";
  const std::string selector_upcall_messageError_24_transition = "MaceTransport::messageError::Reset::(true)";
  const std::string selector_resumeDeliver_demux_41 = "MaceTransport::resumeDeliver::(demux)";
  const std::string selector_upcall_deliver_13_transition = "MaceTransport::deliver::DataFragment::(true)";
  const std::string selector_send_downcall_17 = "MaceTransport::send::Data::(downcall)";
  const std::string selector_downcall_maceInit_0_transition = "MaceTransport::maceInit::(true)";
  const std::string selector_maceExit_demux_45 = "MaceTransport::maceExit::(demux)";
  const std::string selector_closeOutgoingConnection_routine_2 = "MaceTransport::closeOutgoingConnection::(routine)";
  const std::string selector_schedulectsTimer = "MaceTransport::schedule::ctsTimer::(timer)";
  const std::string selector_processDeliver_routine_10 = "MaceTransport::processDeliver::(routine)";
  const std::string selector_error_upcall_1 = "MaceTransport::error::(upcall)";
  const std::string selector_schedulelocalTimer = "MaceTransport::schedule::localTimer::(timer)";
  const std::string selector_closeIncomingConnection_routine_1 = "MaceTransport::closeIncomingConnection::(routine)";
  const std::string selector_deliver_demux_1 = "MaceTransport::deliver::Data::(demux)";
  const std::string selector_registerHandler_demux_34 = "MaceTransport::registerHandler::(demux)";
  const std::string selector_messageError_demux_10 = "MaceTransport::messageError::Reset::(demux)";
  const std::string selector_hasOutgoingBufferedData_demux_23 = "MaceTransport::hasOutgoingBufferedData::(demux)";
  const std::string selector_downcall_setWindowSize_5_transition = "MaceTransport::setWindowSize::(true)";
  const std::string selector_sendReset_routine_12 = "MaceTransport::sendReset::(routine)";
  const std::string selector_scheduleretransmissionTimer = "MaceTransport::schedule::retransmissionTimer::(timer)";
  const std::string selector_route_downcall_11 = "MaceTransport::route::Data::(downcall)";
  const std::string selector_localAddress_demux_47 = "MaceTransport::localAddress::(demux)";
  const std::string selector_unregisterHandler_demux_32 = "MaceTransport::unregisterHandler::(demux)";
  const std::string selector_route_downcall_7 = "MaceTransport::route::Fragment::(downcall)";
  const std::string selector_updateFlushed_routine_15 = "MaceTransport::updateFlushed::(routine)";
  const std::string selector_suspendDeliver_demux_39 = "MaceTransport::suspendDeliver::(demux)";
  const std::string selector_route_demux_37 = "MaceTransport::route::(demux)";
  const std::string selector_deliver_upcall_0 = "MaceTransport::deliver::(upcall)";
  const std::string selector_requestFlushedNotification_demux_27 = "MaceTransport::requestFlushedNotification::(demux)";
  const std::string selector_unregisterHandler_demux_35 = "MaceTransport::unregisterHandler::(demux)";
  const std::string selector_expire_ctsTimer_demux_51 = "MaceTransport::expire_ctsTimer::(demux)";
  const std::string selector_printConnection_routine_17 = "MaceTransport::printConnection::(routine)";
  const std::string selector_messageError_demux_6 = "MaceTransport::messageError::Data::(demux)";
  const std::string selector_messageError_demux_8 = "MaceTransport::messageError::Fragment::(demux)";
  const std::string selector_availableBufferSize_demux_12 = "MaceTransport::availableBufferSize::(demux)";
  const std::string selector_downcall_outgoingBufferedDataSize_4_transition = "MaceTransport::outgoingBufferedDataSize::(true)";
  const std::string selector_outgoingBufferedDataSize_routine_21 = "MaceTransport::outgoingBufferedDataSize::(routine)";
  const std::string selector_scheduler_expire_ctsTimer_19_transition = "MaceTransport::expire::expire_ctsTimer::(true)";
  const std::string selector_expirectsTimer = "MaceTransport::expire::ctsTimer::(timer)";
  const std::string selector_route_downcall_4 = "MaceTransport::route::Message::(downcall)";
  const std::string selector_downcall_hasBufferedData_8_transition = "MaceTransport::hasBufferedData::(true)";
  const std::string selector_send_downcall_19 = "MaceTransport::send::Fragment::(downcall)";
  const std::string selector_resumeDeliver_downcall_3 = "MaceTransport::resumeDeliver::(downcall)";
  const std::string selector_downcall_requestFlushedNotification_2_transition = "MaceTransport::requestFlushedNotification::(true)";
  const std::string selector_route_downcall_8 = "MaceTransport::route::Ack::(downcall)";
  const std::string selector_route_downcall_15 = "MaceTransport::route::Reset::(downcall)";
  const std::string selector_downcall_route_1_transition = "MaceTransport::route::(true)";
  const std::string selector_sendPackets_routine_13 = "MaceTransport::sendPackets::(routine)";
  const std::string selector_route_downcall_23 = "MaceTransport::route::(downcall)";
  const std::string selector_incomingMessageQueueSize_demux_16 = "MaceTransport::incomingMessageQueueSize::(demux)";
  const std::string selector_messageError_demux_9 = "MaceTransport::messageError::Ack::(demux)";
  const std::string selector_error_demux_0 = "MaceTransport::error::(demux)";
  const std::string selector_scheduler_expire_localTimer_18_transition = "MaceTransport::expire::expire_localTimer::(true)";
  const std::string selector_upcall_deliver_12_transition = "MaceTransport::deliver::Data::(true)";
  const std::string selector_send_downcall_20 = "MaceTransport::send::Ack::(downcall)";
  const std::string selector_route_downcall_12 = "MaceTransport::route::DataFragment::(downcall)";
  const std::string selector_setWindowSize_demux_17 = "MaceTransport::setWindowSize::(demux)";
  const std::string selector_routeRTS_demux_26 = "MaceTransport::routeRTS::(demux)";
  const std::string selector_outgoingBufferedDataSize_demux_13 = "MaceTransport::outgoingBufferedDataSize::(demux)";
  const std::string selector_messageError_demux_7 = "MaceTransport::messageError::DataFragment::(demux)";
  const std::string selector_upcallMessageErrors_routine_6 = "MaceTransport::upcallMessageErrors::(routine)";
  const std::string selector_deliverBuffered_routine_4 = "MaceTransport::deliverBuffered::(routine)";
  const std::string selector_route_downcall_13 = "MaceTransport::route::Fragment::(downcall)";
  const std::string selector_deliver_demux_3 = "MaceTransport::deliver::Fragment::(demux)";
  const std::string selector_send_downcall_24 = "MaceTransport::send::(downcall)";
  const std::string selector_upcall_deliver_15_transition = "MaceTransport::deliver::Ack::(true)";
  const std::string selector_sendAck_routine_11 = "MaceTransport::sendAck::(routine)";
  const std::string selector_inflightSize_routine_18 = "MaceTransport::inflightSize::(routine)";
  const std::string selector_suspendDeliver_downcall_0 = "MaceTransport::suspendDeliver::(downcall)";
  const std::string selector_upcall_messageError_23_transition = "MaceTransport::messageError::Ack::(true)";
  const std::string selector_closeBidirectionalConnection_routine_3 = "MaceTransport::closeBidirectionalConnection::(routine)";
  const std::string selector_checkRetransmissionTimerCount_routine_20 = "MaceTransport::checkRetransmissionTimerCount::(routine)";
  const std::string selector_requestToSend_demux_20 = "MaceTransport::requestToSend::(demux)";
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  class MessageInfo;
  class ConnectionInfo;
  class OutgoingConnection;
  class IncomingConnection;
  //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
  typedef mace::NodeCollection<OutgoingConnection> OutgoingConnectionMap;
  typedef mace::NodeCollection<IncomingConnection> IncomingConnectionMap;
  typedef uint32_t seq_t;
  typedef mace::hash_map<MaceTime, std::string> IdMessageMap;
  typedef mace::hash_set<registration_uid_t> RegIdSet;
  typedef mace::deque<registration_uid_t> RtsList;
  typedef boost::shared_ptr<MessageInfo> MessageInfoPtr;
  typedef mace::map<seq_t, MessageInfoPtr, mace::SoftState> MessagePtrMap;
  typedef mace::deque<MessageInfoPtr, mace::SoftState> MessagePtrList;
  typedef mace::set<mace::MonotoneTime> IdSet;
  typedef mace::map<MaceKey, mace::MonotoneTime> MonotoneIdMap;
  //END: Mace::Compiler::ServiceImpl::printTypeDefs
  
  //Message Declarations
  class Data;
  class DataFragment;
  class Fragment;
  class Ack;
  class Reset;
  
  
  //Context Forward Declarations
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  
  class MaceTransportService;
  typedef MaceTransportService ServiceType;
  typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;
  typedef mace::map<int, MaceTransportService const *, mace::SoftState> _NodeMap_;
  typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;
  mace::map<mace::string, mace::string> returnValueMapping;
  std::map<mace::string, pthread_mutex_t> mutexMapping;
  static const char* __SERVICE__ __attribute((unused)) = "MaceTransport";
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
  class MessageInfo : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    
    #line 120 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    seq_t get_seq() const { return seq; }
    
    #line 121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::string payload
#line 258 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    mace::string get_payload() const { return payload; }
    
    #line 122 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    registration_uid_t rid
#line 264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    registration_uid_t get_rid() const { return rid; }
    
    #line 123 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t frag
#line 270 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_frag() const { return frag; }
    
    #line 124 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t nfrag
#line 276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_nfrag() const { return nfrag; }
    
    #line 125 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t fragrecv
#line 282 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_fragrecv() const { return fragrecv; }
    
    #line 126 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime syn
#line 288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    mace::MonotoneTime get_syn() const { return syn; }
    
    #line 127 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MaceTime starttime
#line 294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MaceTime get_starttime() const { return starttime; }
    
    #line 128 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MaceTime ts
#line 300 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MaceTime get_ts() const { return ts; }
    
    #line 129 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MaceTime timer
#line 306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MaceTime get_timer() const { return timer; }
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint retries
#line 312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint get_retries() const { return retries; }
    
    #line 131 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool timeout
#line 318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    bool get_timeout() const { return timeout; }
    
    #line 132 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime id
#line 324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    mace::MonotoneTime get_id() const { return id; }
    MessageInfo() : seq(), payload(), rid(), frag(0), nfrag(0), fragrecv(0), syn(0), starttime(0), ts(0), timer(0), retries(0), timeout(true), id(0) {}
    MessageInfo(seq_t const & _seq, mace::string const & _payload, registration_uid_t const & _rid, uint32_t const & _frag = 0, uint32_t const & _nfrag = 0, uint32_t const & _fragrecv = 0, mace::MonotoneTime const & _syn = 0, MaceTime const & _starttime = 0, MaceTime const & _ts = 0, MaceTime const & _timer = 0, uint const & _retries = 0, bool const & _timeout = true, mace::MonotoneTime const & _id = 0) : serializedByteSize(0), seq(_seq), payload(_payload), rid(_rid), frag(_frag), nfrag(_nfrag), fragrecv(_fragrecv), syn(_syn), starttime(_starttime), ts(_ts), timer(_timer), retries(_retries), timeout(_timeout), id(_id) {}
    virtual ~MessageInfo() {}
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __MessageInfoPrinter(__name, "MessageInfo");
      mace::printItem(__MessageInfoPrinter, "seq", &(seq));;
      mace::printItem(__MessageInfoPrinter, "payload", &(payload));;
      mace::printItem(__MessageInfoPrinter, "rid", &(rid));;
      mace::printItem(__MessageInfoPrinter, "frag", &(frag));;
      mace::printItem(__MessageInfoPrinter, "nfrag", &(nfrag));;
      mace::printItem(__MessageInfoPrinter, "fragrecv", &(fragrecv));;
      mace::printItem(__MessageInfoPrinter, "syn", &(syn));;
      mace::printItem(__MessageInfoPrinter, "starttime", &(starttime));;
      mace::printItem(__MessageInfoPrinter, "ts", &(ts));;
      mace::printItem(__MessageInfoPrinter, "timer", &(timer));;
      mace::printItem(__MessageInfoPrinter, "retries", &(retries));;
      mace::printItem(__MessageInfoPrinter, "timeout", &(timeout));;
      mace::printItem(__MessageInfoPrinter, "id", &(id));
      __pr.addChild(__MessageInfoPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "MessageInfo("  ;
          __out << "seq=";  mace::printItem(__out, &(seq));
          __out << ", ";
          __out << "payload=";  mace::printItem(__out, &(payload));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
          __out << ", ";
          __out << "frag=";  mace::printItem(__out, &(frag));
          __out << ", ";
          __out << "nfrag=";  mace::printItem(__out, &(nfrag));
          __out << ", ";
          __out << "fragrecv=";  mace::printItem(__out, &(fragrecv));
          __out << ", ";
          __out << "syn=";  mace::printItem(__out, &(syn));
          __out << ", ";
          __out << "starttime=";  mace::printItem(__out, &(starttime));
          __out << ", ";
          __out << "ts=";  mace::printItem(__out, &(ts));
          __out << ", ";
          __out << "timer=";  mace::printItem(__out, &(timer));
          __out << ", ";
          __out << "retries=";  mace::printItem(__out, &(retries));
          __out << ", ";
          __out << "timeout=";  mace::printItem(__out, &(timeout));
          __out << ", ";
          __out << "id=";  mace::printItem(__out, &(id));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "MessageInfo(" ;
          __out << "seq=";  mace::printState(__out, &(seq), (seq));
          __out << ", ";
          __out << "payload=";  mace::printState(__out, &(payload), (payload));
          __out << ", ";
          __out << "rid=";  mace::printState(__out, &(rid), (rid));
          __out << ", ";
          __out << "frag=";  mace::printState(__out, &(frag), (frag));
          __out << ", ";
          __out << "nfrag=";  mace::printState(__out, &(nfrag), (nfrag));
          __out << ", ";
          __out << "fragrecv=";  mace::printState(__out, &(fragrecv), (fragrecv));
          __out << ", ";
          __out << "syn=";  mace::printState(__out, &(syn), (syn));
          __out << ", ";
          __out << "retries=";  mace::printState(__out, &(retries), (retries));
          __out << ", ";
          __out << "timeout=";  mace::printState(__out, &(timeout), (timeout));
          __out << ", ";
          __out << "id=";  mace::printState(__out, &(id), (id));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      
      #line 120 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 405 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &payload);
#line 410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 122 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &rid);
#line 415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 123 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &frag);
#line 420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 124 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &nfrag);
#line 425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 125 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &fragrecv);
#line 430 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 126 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &syn);
#line 435 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 127 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &starttime);
#line 440 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 128 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &ts);
#line 445 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 129 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &timer);
#line 450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &retries);
#line 455 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 131 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &timeout);
#line 460 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 132 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &id);
#line 465 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      
      #line 120 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &seq);
#line 474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &payload);
#line 479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 122 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &rid);
#line 484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 123 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &frag);
#line 489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 124 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &nfrag);
#line 494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 125 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &fragrecv);
#line 499 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 126 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &syn);
#line 504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 127 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &starttime);
#line 509 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 128 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &ts);
#line 514 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 129 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &timer);
#line 519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &retries);
#line 524 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 131 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &timeout);
#line 529 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 132 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &id);
#line 534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, seq INT, payload TEXT, rid INT, frag INT8, nfrag INT8, fragrecv INT8, syn INT, starttime INT, ts INT, timer INT, retries INT, timeout INT, id INT);" << std::endl;
        __node->children = new mace::LogNode*[8];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_starttime", Log::sqlEventsLog);
        __node->children[3] = __child3;
        mace::LogNode* __child4 = new mace::LogNode(__node->logName + "_ts", Log::sqlEventsLog);
        __node->children[4] = __child4;
        mace::LogNode* __child5 = new mace::LogNode(__node->logName + "_timer", Log::sqlEventsLog);
        __node->children[5] = __child5;
        mace::LogNode* __child6 = new mace::LogNode(__node->logName + "_retries", Log::sqlEventsLog);
        __node->children[6] = __child6;
        mace::LogNode* __child7 = new mace::LogNode(__node->logName + "_id", Log::sqlEventsLog);
        __node->children[7] = __child7;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _seqIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      int _synIndex = __node->children[2]->nextId;
      int _starttimeIndex = __node->children[3]->nextId;
      int _tsIndex = __node->children[4]->nextId;
      int _timerIndex = __node->children[5]->nextId;
      int _retriesIndex = __node->children[6]->nextId;
      int _idIndex = __node->children[7]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _seqIndex;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << "\t" << _ridIndex;
      __out << "\t" << frag;
      __out << "\t" << nfrag;
      __out << "\t" << fragrecv;
      __out << "\t" << _synIndex;
      __out << "\t" << _starttimeIndex;
      __out << "\t" << _tsIndex;
      __out << "\t" << _timerIndex;
      __out << "\t" << _retriesIndex;
      __out << "\t" << timeout;
      __out << "\t" << _idIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&seq, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      mace::sqlize(&syn, __node->children[2]);
      mace::sqlize(&starttime, __node->children[3]);
      mace::sqlize(&ts, __node->children[4]);
      mace::sqlize(&timer, __node->children[5]);
      mace::sqlize(&retries, __node->children[6]);
      mace::sqlize(&id, __node->children[7]);
      
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
    }
    
    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
      int __fields = 0;
      std::istream::pos_type __m_offset = __mace_in.tellg();
      mace::SerializationUtil::expectTag(__mace_in, "<struct>");
      
      std::string tag = mace::SerializationUtil::getTag(__mace_in);
      while (tag == "<member>") {
        __fields++;
        mace::SerializationUtil::expectTag(__mace_in, "<name>");
        std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
        mace::SerializationUtil::expectTag(__mace_in, "</name>");
        mace::SerializationUtil::expectTag(__mace_in, "<value>");
        
        if (__var == "seq") {
          mace::deserializeXML_RPC(__mace_in, & seq, seq);
        } else
        if (__var == "payload") {
          mace::deserializeXML_RPC(__mace_in, & payload, payload);
        } else
        if (__var == "rid") {
          mace::deserializeXML_RPC(__mace_in, & rid, rid);
        } else
        if (__var == "frag") {
          mace::deserializeXML_RPC(__mace_in, & frag, frag);
        } else
        if (__var == "nfrag") {
          mace::deserializeXML_RPC(__mace_in, & nfrag, nfrag);
        } else
        if (__var == "fragrecv") {
          mace::deserializeXML_RPC(__mace_in, & fragrecv, fragrecv);
        } else
        if (__var == "syn") {
          mace::deserializeXML_RPC(__mace_in, & syn, syn);
        } else
        if (__var == "starttime") {
          mace::deserializeXML_RPC(__mace_in, & starttime, starttime);
        } else
        if (__var == "ts") {
          mace::deserializeXML_RPC(__mace_in, & ts, ts);
        } else
        if (__var == "timer") {
          mace::deserializeXML_RPC(__mace_in, & timer, timer);
        } else
        if (__var == "retries") {
          mace::deserializeXML_RPC(__mace_in, & retries, retries);
        } else
        if (__var == "timeout") {
          mace::deserializeXML_RPC(__mace_in, & timeout, timeout);
        } else
        if (__var == "id") {
          mace::deserializeXML_RPC(__mace_in, & id, id);
        } else
        {
          throw(new mace::SerializationException("deserializing MessageInfo: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 13) {
        throw(new mace::SerializationException("deserializing MessageInfo: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>seq</name><value>");
      mace::serializeXML_RPC(str, &(seq), seq);
      str.append("</value></member>");
      str.append("<member><name>payload</name><value>");
      mace::serializeXML_RPC(str, &(payload), payload);
      str.append("</value></member>");
      str.append("<member><name>rid</name><value>");
      mace::serializeXML_RPC(str, &(rid), rid);
      str.append("</value></member>");
      str.append("<member><name>frag</name><value>");
      mace::serializeXML_RPC(str, &(frag), frag);
      str.append("</value></member>");
      str.append("<member><name>nfrag</name><value>");
      mace::serializeXML_RPC(str, &(nfrag), nfrag);
      str.append("</value></member>");
      str.append("<member><name>fragrecv</name><value>");
      mace::serializeXML_RPC(str, &(fragrecv), fragrecv);
      str.append("</value></member>");
      str.append("<member><name>syn</name><value>");
      mace::serializeXML_RPC(str, &(syn), syn);
      str.append("</value></member>");
      str.append("<member><name>starttime</name><value>");
      mace::serializeXML_RPC(str, &(starttime), starttime);
      str.append("</value></member>");
      str.append("<member><name>ts</name><value>");
      mace::serializeXML_RPC(str, &(ts), ts);
      str.append("</value></member>");
      str.append("<member><name>timer</name><value>");
      mace::serializeXML_RPC(str, &(timer), timer);
      str.append("</value></member>");
      str.append("<member><name>retries</name><value>");
      mace::serializeXML_RPC(str, &(retries), retries);
      str.append("</value></member>");
      str.append("<member><name>timeout</name><value>");
      mace::serializeXML_RPC(str, &(timeout), timeout);
      str.append("</value></member>");
      str.append("<member><name>id</name><value>");
      mace::serializeXML_RPC(str, &(id), id);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  class ConnectionInfo : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    
    #line 136 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    int64_t sa
#line 732 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    int64_t get_sa() const { return sa; }
    
    #line 137 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    int64_t sv
#line 738 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    int64_t get_sv() const { return sv; }
    
    #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    int64_t rto
#line 744 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    int64_t get_rto() const { return rto; }
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint consecutiveTimeouts
#line 750 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint get_consecutiveTimeouts() const { return consecutiveTimeouts; }
    
    #line 141 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    double cwnd
#line 756 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    double get_cwnd() const { return cwnd; }
    
    #line 142 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    double ssthresh
#line 762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    double get_ssthresh() const { return ssthresh; }
    
    #line 143 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t packetsSent
#line 768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_packetsSent() const { return packetsSent; }
    
    #line 144 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t acksReceived
#line 774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_acksReceived() const { return acksReceived; }
    
    #line 145 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t packetsRetransmitted
#line 780 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_packetsRetransmitted() const { return packetsRetransmitted; }
    
    #line 146 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t timeoutCount
#line 786 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_timeoutCount() const { return timeoutCount; }
    ConnectionInfo(int64_t const & _sa = -1, int64_t const & _sv = 0, int64_t const & _rto = INIT_RTO, uint const & _consecutiveTimeouts = 0, double const & _cwnd = 1.0, double const & _ssthresh = MAX_WND, uint32_t const & _packetsSent = 0, uint32_t const & _acksReceived = 0, uint32_t const & _packetsRetransmitted = 0, uint32_t const & _timeoutCount = 0) : serializedByteSize(0), sa(_sa), sv(_sv), rto(_rto), consecutiveTimeouts(_consecutiveTimeouts), cwnd(_cwnd), ssthresh(_ssthresh), packetsSent(_packetsSent), acksReceived(_acksReceived), packetsRetransmitted(_packetsRetransmitted), timeoutCount(_timeoutCount) {}
    virtual ~ConnectionInfo() {}
    void updateRTO(
        #line 148 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceTime& ts
#line 794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void increaseCWND();
    void timeout();bool shouldLog_ConnectionInfo_updateRTO( const MaceTime& ts) const;
    
    bool shouldLog_ConnectionInfo_increaseCWND() const;
    
    bool shouldLog_ConnectionInfo_timeout() const;
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __ConnectionInfoPrinter(__name, "ConnectionInfo");
      mace::printItem(__ConnectionInfoPrinter, "rto", &(rto));;
      mace::printItem(__ConnectionInfoPrinter, "consecutiveTimeouts", &(consecutiveTimeouts));;
      mace::printItem(__ConnectionInfoPrinter, "cwnd", &(cwnd));;
      mace::printItem(__ConnectionInfoPrinter, "ssthresh", &(ssthresh));;
      mace::printItem(__ConnectionInfoPrinter, "packetsSent", &(packetsSent));;
      mace::printItem(__ConnectionInfoPrinter, "acksReceived", &(acksReceived));;
      mace::printItem(__ConnectionInfoPrinter, "packetsRetransmitted", &(packetsRetransmitted));;
      mace::printItem(__ConnectionInfoPrinter, "timeoutCount", &(timeoutCount));
      __pr.addChild(__ConnectionInfoPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "ConnectionInfo("  ;
          __out << "rto=";  mace::printItem(__out, &(rto));
          __out << ", ";
          __out << "consecutiveTimeouts=";  mace::printItem(__out, &(consecutiveTimeouts));
          __out << ", ";
          __out << "cwnd=";  mace::printItem(__out, &(cwnd));
          __out << ", ";
          __out << "ssthresh=";  mace::printItem(__out, &(ssthresh));
          __out << ", ";
          __out << "packetsSent=";  mace::printItem(__out, &(packetsSent));
          __out << ", ";
          __out << "acksReceived=";  mace::printItem(__out, &(acksReceived));
          __out << ", ";
          __out << "packetsRetransmitted=";  mace::printItem(__out, &(packetsRetransmitted));
          __out << ", ";
          __out << "timeoutCount=";  mace::printItem(__out, &(timeoutCount));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "ConnectionInfo(" ;
          __out << "consecutiveTimeouts=";  mace::printState(__out, &(consecutiveTimeouts), (consecutiveTimeouts));
          __out << ", ";
          __out << "cwnd=";  mace::printState(__out, &(cwnd), (cwnd));
          __out << ", ";
          __out << "ssthresh=";  mace::printState(__out, &(ssthresh), (ssthresh));
          __out << ", ";
          __out << "packetsSent=";  mace::printState(__out, &(packetsSent), (packetsSent));
          __out << ", ";
          __out << "acksReceived=";  mace::printState(__out, &(acksReceived), (acksReceived));
          __out << ", ";
          __out << "packetsRetransmitted=";  mace::printState(__out, &(packetsRetransmitted), (packetsRetransmitted));
          __out << ", ";
          __out << "timeoutCount=";  mace::printState(__out, &(timeoutCount), (timeoutCount));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      
      #line 136 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &sa);
#line 856 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 137 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &sv);
#line 861 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &rto);
#line 866 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &consecutiveTimeouts);
#line 871 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 141 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &cwnd);
#line 876 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 142 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &ssthresh);
#line 881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 143 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &packetsSent);
#line 886 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 144 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &acksReceived);
#line 891 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 145 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &packetsRetransmitted);
#line 896 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 146 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &timeoutCount);
#line 901 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      
      #line 136 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &sa);
#line 910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 137 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &sv);
#line 915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &rto);
#line 920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &consecutiveTimeouts);
#line 925 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 141 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &cwnd);
#line 930 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 142 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &ssthresh);
#line 935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 143 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &packetsSent);
#line 940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 144 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &acksReceived);
#line 945 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 145 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &packetsRetransmitted);
#line 950 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 146 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &timeoutCount);
#line 955 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, rto INT8, consecutiveTimeouts INT, cwnd DOUBLE PRECISION, ssthresh DOUBLE PRECISION, packetsSent INT8, acksReceived INT8, packetsRetransmitted INT8, timeoutCount INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_consecutiveTimeouts", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _consecutiveTimeoutsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << rto;
      __out << "\t" << _consecutiveTimeoutsIndex;
      __out << "\t" << cwnd;
      __out << "\t" << ssthresh;
      __out << "\t" << packetsSent;
      __out << "\t" << acksReceived;
      __out << "\t" << packetsRetransmitted;
      __out << "\t" << timeoutCount;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&consecutiveTimeouts, __node->children[0]);
      
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
    }
    
    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
      int __fields = 0;
      std::istream::pos_type __m_offset = __mace_in.tellg();
      mace::SerializationUtil::expectTag(__mace_in, "<struct>");
      
      std::string tag = mace::SerializationUtil::getTag(__mace_in);
      while (tag == "<member>") {
        __fields++;
        mace::SerializationUtil::expectTag(__mace_in, "<name>");
        std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
        mace::SerializationUtil::expectTag(__mace_in, "</name>");
        mace::SerializationUtil::expectTag(__mace_in, "<value>");
        
        if (__var == "sa") {
          mace::deserializeXML_RPC(__mace_in, & sa, sa);
        } else
        if (__var == "sv") {
          mace::deserializeXML_RPC(__mace_in, & sv, sv);
        } else
        if (__var == "rto") {
          mace::deserializeXML_RPC(__mace_in, & rto, rto);
        } else
        if (__var == "consecutiveTimeouts") {
          mace::deserializeXML_RPC(__mace_in, & consecutiveTimeouts, consecutiveTimeouts);
        } else
        if (__var == "cwnd") {
          mace::deserializeXML_RPC(__mace_in, & cwnd, cwnd);
        } else
        if (__var == "ssthresh") {
          mace::deserializeXML_RPC(__mace_in, & ssthresh, ssthresh);
        } else
        if (__var == "packetsSent") {
          mace::deserializeXML_RPC(__mace_in, & packetsSent, packetsSent);
        } else
        if (__var == "acksReceived") {
          mace::deserializeXML_RPC(__mace_in, & acksReceived, acksReceived);
        } else
        if (__var == "packetsRetransmitted") {
          mace::deserializeXML_RPC(__mace_in, & packetsRetransmitted, packetsRetransmitted);
        } else
        if (__var == "timeoutCount") {
          mace::deserializeXML_RPC(__mace_in, & timeoutCount, timeoutCount);
        } else
        {
          throw(new mace::SerializationException("deserializing ConnectionInfo: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 10) {
        throw(new mace::SerializationException("deserializing ConnectionInfo: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>sa</name><value>");
      mace::serializeXML_RPC(str, &(sa), sa);
      str.append("</value></member>");
      str.append("<member><name>sv</name><value>");
      mace::serializeXML_RPC(str, &(sv), sv);
      str.append("</value></member>");
      str.append("<member><name>rto</name><value>");
      mace::serializeXML_RPC(str, &(rto), rto);
      str.append("</value></member>");
      str.append("<member><name>consecutiveTimeouts</name><value>");
      mace::serializeXML_RPC(str, &(consecutiveTimeouts), consecutiveTimeouts);
      str.append("</value></member>");
      str.append("<member><name>cwnd</name><value>");
      mace::serializeXML_RPC(str, &(cwnd), cwnd);
      str.append("</value></member>");
      str.append("<member><name>ssthresh</name><value>");
      mace::serializeXML_RPC(str, &(ssthresh), ssthresh);
      str.append("</value></member>");
      str.append("<member><name>packetsSent</name><value>");
      mace::serializeXML_RPC(str, &(packetsSent), packetsSent);
      str.append("</value></member>");
      str.append("<member><name>acksReceived</name><value>");
      mace::serializeXML_RPC(str, &(acksReceived), acksReceived);
      str.append("</value></member>");
      str.append("<member><name>packetsRetransmitted</name><value>");
      mace::serializeXML_RPC(str, &(packetsRetransmitted), packetsRetransmitted);
      str.append("</value></member>");
      str.append("<member><name>timeoutCount</name><value>");
      mace::serializeXML_RPC(str, &(timeoutCount), timeoutCount);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  class OutgoingConnection : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    private:
    MaceKey _id;
    public:
    const MaceKey& getId() const { return _id; }
    double getScore() const { return 0.0; }
    public:
    
    #line 209 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    ConnectionInfo connection
#line 1101 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    ConnectionInfo get_connection() const { return connection; }
    
    #line 210 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MessagePtrMap inflight
#line 1107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MessagePtrMap get_inflight() const { return inflight; }
    
    #line 211 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MessagePtrMap rtbuf
#line 1113 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MessagePtrMap get_rtbuf() const { return rtbuf; }
    
    #line 212 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MessagePtrList sendbuf
#line 1119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MessagePtrList get_sendbuf() const { return sendbuf; }
    
    #line 213 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    IdMessageMap unfragged
#line 1125 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    IdMessageMap get_unfragged() const { return unfragged; }
    
    #line 214 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    RtsList rts
#line 1131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    RtsList get_rts() const { return rts; }
    
    #line 218 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t curseq
#line 1137 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    seq_t get_curseq() const { return curseq; }
    
    #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime syn
#line 1143 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    mace::MonotoneTime get_syn() const { return syn; }
    
    #line 220 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool returnSyn
#line 1149 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    bool get_returnSyn() const { return returnSyn; }
    
    #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t dupacks
#line 1155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_dupacks() const { return dupacks; }
    
    #line 222 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t last
#line 1161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    seq_t get_last() const { return last; }
    
    #line 223 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint64_t queued
#line 1167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint64_t get_queued() const { return queued; }
    
    #line 224 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint64_t sent
#line 1173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint64_t get_sent() const { return sent; }
    
    #line 225 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint64_t acked
#line 1179 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint64_t get_acked() const { return acked; }
    
    #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool flushed
#line 1185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    bool get_flushed() const { return flushed; }
    
    #line 227 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool sendable
#line 1191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    bool get_sendable() const { return sendable; }
    
    #line 228 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    BufferStatisticsPtr bufStats
#line 1197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    BufferStatisticsPtr get_bufStats() const { return bufStats; }
    OutgoingConnection(MaceKey __id = MaceKey()) : serializedByteSize(0), _id(__id), connection(), inflight(), rtbuf(), sendbuf(), unfragged(), rts(), curseq(mace::getmtime()*1000*1000), syn(mace::getmtime()), returnSyn(true), dupacks(0), last(0), queued(0), sent(0), acked(0), flushed(false), sendable(true), bufStats(BufferStatisticsPtr(new BufferStatistics(DEFAULT_WINDOW_SIZE))) {}
    OutgoingConnection(MaceKey __id, ConnectionInfo const & _connection, MessagePtrMap const & _inflight, MessagePtrMap const & _rtbuf, MessagePtrList const & _sendbuf, IdMessageMap const & _unfragged, RtsList const & _rts, seq_t const & _curseq = mace::getmtime()*1000*1000, mace::MonotoneTime const & _syn = mace::getmtime(), bool const & _returnSyn = true, uint32_t const & _dupacks = 0, seq_t const & _last = 0, uint64_t const & _queued = 0, uint64_t const & _sent = 0, uint64_t const & _acked = 0, bool const & _flushed = false, bool const & _sendable = true, BufferStatisticsPtr const & _bufStats = BufferStatisticsPtr(new BufferStatistics(DEFAULT_WINDOW_SIZE))) : serializedByteSize(0), _id(__id), connection(_connection), inflight(_inflight), rtbuf(_rtbuf), sendbuf(_sendbuf), unfragged(_unfragged), rts(_rts), curseq(_curseq), syn(_syn), returnSyn(_returnSyn), dupacks(_dupacks), last(_last), queued(_queued), sent(_sent), acked(_acked), flushed(_flushed), sendable(_sendable), bufStats(_bufStats) {}
    virtual ~OutgoingConnection() {}
    bool canSend() const;
    void updateCanSendOnWrite(
        #line 234 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t maxsize
#line 1207 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 234 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t threshold
#line 1211 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void updateCanSendOnEnqueue(
        #line 240 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t maxsize
#line 1216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t bufferedDataSize() const;
    bool hasQueuedMessages() const;
    size_t queuedMessagesSize() const;
    seq_t nextSeq();
    mace::MonotoneTime getSyn();
    void setLast(
        #line 271 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t s
#line 1226 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool fastRetransmit() const;bool shouldLog_OutgoingConnection_canSend() const;
    
    bool shouldLog_OutgoingConnection_updateCanSendOnWrite(uint64_t maxsize, uint64_t threshold) const;
    
    bool shouldLog_OutgoingConnection_updateCanSendOnEnqueue(uint64_t maxsize) const;
    
    bool shouldLog_OutgoingConnection_bufferedDataSize() const;
    
    bool shouldLog_OutgoingConnection_hasQueuedMessages() const;
    
    bool shouldLog_OutgoingConnection_queuedMessagesSize() const;
    
    bool shouldLog_OutgoingConnection_nextSeq() const;
    
    bool shouldLog_OutgoingConnection_getSyn() const;
    
    bool shouldLog_OutgoingConnection_setLast(seq_t s) const;
    
    bool shouldLog_OutgoingConnection_fastRetransmit() const;
    
    bool __mace_log_canSend() const;
    size_t __mace_log_bufferedDataSize() const;
    bool __mace_log_hasQueuedMessages() const;
    size_t __mace_log_queuedMessagesSize() const;
    seq_t __mace_log_nextSeq();
    mace::MonotoneTime __mace_log_getSyn();
    bool __mace_log_fastRetransmit() const;    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __OutgoingConnectionPrinter(__name, "OutgoingConnection");
      mace::printItem(__OutgoingConnectionPrinter, "id", &_id);
      mace::printItem(__OutgoingConnectionPrinter, "connection", &(connection));;
      mace::printItem(__OutgoingConnectionPrinter, "inflight", &(inflight));;
      mace::printItem(__OutgoingConnectionPrinter, "rtbuf", &(rtbuf));;
      mace::printItem(__OutgoingConnectionPrinter, "sendbuf", &(sendbuf));;
      mace::printItem(__OutgoingConnectionPrinter, "unfragged", &(unfragged));;
      mace::printItem(__OutgoingConnectionPrinter, "rts", &(rts));;
      mace::printItem(__OutgoingConnectionPrinter, "curseq", &(curseq));;
      mace::printItem(__OutgoingConnectionPrinter, "syn", &(syn));;
      mace::printItem(__OutgoingConnectionPrinter, "returnSyn", &(returnSyn));;
      mace::printItem(__OutgoingConnectionPrinter, "dupacks", &(dupacks));;
      mace::printItem(__OutgoingConnectionPrinter, "last", &(last));;
      mace::printItem(__OutgoingConnectionPrinter, "queued", &(queued));;
      mace::printItem(__OutgoingConnectionPrinter, "sent", &(sent));;
      mace::printItem(__OutgoingConnectionPrinter, "acked", &(acked));;
      mace::printItem(__OutgoingConnectionPrinter, "flushed", &(flushed));;
      mace::printItem(__OutgoingConnectionPrinter, "sendable", &(sendable));
      __pr.addChild(__OutgoingConnectionPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "OutgoingConnection("  << _id << ", " ;
          __out << "connection=";  mace::printItem(__out, &(connection));
          __out << ", ";
          __out << "inflight=";  mace::printItem(__out, &(inflight));
          __out << ", ";
          __out << "rtbuf=";  mace::printItem(__out, &(rtbuf));
          __out << ", ";
          __out << "sendbuf=";  mace::printItem(__out, &(sendbuf));
          __out << ", ";
          __out << "unfragged=";  mace::printItem(__out, &(unfragged));
          __out << ", ";
          __out << "rts=";  mace::printItem(__out, &(rts));
          __out << ", ";
          __out << "curseq=";  mace::printItem(__out, &(curseq));
          __out << ", ";
          __out << "syn=";  mace::printItem(__out, &(syn));
          __out << ", ";
          __out << "returnSyn=";  mace::printItem(__out, &(returnSyn));
          __out << ", ";
          __out << "dupacks=";  mace::printItem(__out, &(dupacks));
          __out << ", ";
          __out << "last=";  mace::printItem(__out, &(last));
          __out << ", ";
          __out << "queued=";  mace::printItem(__out, &(queued));
          __out << ", ";
          __out << "sent=";  mace::printItem(__out, &(sent));
          __out << ", ";
          __out << "acked=";  mace::printItem(__out, &(acked));
          __out << ", ";
          __out << "flushed=";  mace::printItem(__out, &(flushed));
          __out << ", ";
          __out << "sendable=";  mace::printItem(__out, &(sendable));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "OutgoingConnection("  << _id << ", ";
          __out << "connection=";  mace::printState(__out, &(connection), (connection));
          __out << ", ";
          __out << "inflight=";  mace::printState(__out, &(inflight), (inflight));
          __out << ", ";
          __out << "rtbuf=";  mace::printState(__out, &(rtbuf), (rtbuf));
          __out << ", ";
          __out << "sendbuf=";  mace::printState(__out, &(sendbuf), (sendbuf));
          __out << ", ";
          __out << "unfragged=";  mace::printState(__out, &(unfragged), (unfragged));
          __out << ", ";
          __out << "rts=";  mace::printState(__out, &(rts), (rts));
          __out << ", ";
          __out << "curseq=";  mace::printState(__out, &(curseq), (curseq));
          __out << ", ";
          __out << "syn=";  mace::printState(__out, &(syn), (syn));
          __out << ", ";
          __out << "returnSyn=";  mace::printState(__out, &(returnSyn), (returnSyn));
          __out << ", ";
          __out << "dupacks=";  mace::printState(__out, &(dupacks), (dupacks));
          __out << ", ";
          __out << "last=";  mace::printState(__out, &(last), (last));
          __out << ", ";
          __out << "queued=";  mace::printState(__out, &(queued), (queued));
          __out << ", ";
          __out << "sent=";  mace::printState(__out, &(sent), (sent));
          __out << ", ";
          __out << "acked=";  mace::printState(__out, &(acked), (acked));
          __out << ", ";
          __out << "flushed=";  mace::printState(__out, &(flushed), (flushed));
          __out << ", ";
          __out << "sendable=";  mace::printState(__out, &(sendable), (sendable));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      mace::serialize(str, &_id);
      
      #line 209 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &connection);
#line 1351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      
      
      
      #line 213 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &unfragged);
#line 1359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 214 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &rts);
#line 1364 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 218 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &curseq);
#line 1369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &syn);
#line 1374 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 220 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &returnSyn);
#line 1379 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &dupacks);
#line 1384 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 222 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &last);
#line 1389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 223 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &queued);
#line 1394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 224 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &sent);
#line 1399 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 225 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &acked);
#line 1404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &flushed);
#line 1409 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 227 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &sendable);
#line 1414 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__mace_in, &_id);
      
      #line 209 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &connection);
#line 1425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      
      
      
      #line 213 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &unfragged);
#line 1433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 214 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &rts);
#line 1438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 218 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &curseq);
#line 1443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &syn);
#line 1448 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 220 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &returnSyn);
#line 1453 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &dupacks);
#line 1458 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 222 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &last);
#line 1463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 223 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &queued);
#line 1468 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 224 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &sent);
#line 1473 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 225 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &acked);
#line 1478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &flushed);
#line 1483 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 227 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &sendable);
#line 1488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, connection INT, inflight INT, rtbuf INT, sendbuf INT, unfragged INT, rts INT, curseq INT, syn INT, returnSyn INT, dupacks INT8, last INT, queued NUMERIC(20, 0), sent NUMERIC(20, 0), acked NUMERIC(20, 0), flushed INT, sendable INT);" << std::endl;
        __node->children = new mace::LogNode*[9];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_connection", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_inflight", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_rtbuf", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_sendbuf", Log::sqlEventsLog);
        __node->children[3] = __child3;
        mace::LogNode* __child4 = new mace::LogNode(__node->logName + "_unfragged", Log::sqlEventsLog);
        __node->children[4] = __child4;
        mace::LogNode* __child5 = new mace::LogNode(__node->logName + "_rts", Log::sqlEventsLog);
        __node->children[5] = __child5;
        mace::LogNode* __child6 = new mace::LogNode(__node->logName + "_curseq", Log::sqlEventsLog);
        __node->children[6] = __child6;
        mace::LogNode* __child7 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[7] = __child7;
        mace::LogNode* __child8 = new mace::LogNode(__node->logName + "_last", Log::sqlEventsLog);
        __node->children[8] = __child8;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _connectionIndex = __node->children[0]->nextId;
      int _inflightIndex = __node->children[1]->nextId;
      int _rtbufIndex = __node->children[2]->nextId;
      int _sendbufIndex = __node->children[3]->nextId;
      int _unfraggedIndex = __node->children[4]->nextId;
      int _rtsIndex = __node->children[5]->nextId;
      int _curseqIndex = __node->children[6]->nextId;
      int _synIndex = __node->children[7]->nextId;
      int _lastIndex = __node->children[8]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _connectionIndex;
      __out << "\t" << _inflightIndex;
      __out << "\t" << _rtbufIndex;
      __out << "\t" << _sendbufIndex;
      __out << "\t" << _unfraggedIndex;
      __out << "\t" << _rtsIndex;
      __out << "\t" << _curseqIndex;
      __out << "\t" << _synIndex;
      __out << "\t" << returnSyn;
      __out << "\t" << dupacks;
      __out << "\t" << _lastIndex;
      __out << "\t" << queued;
      __out << "\t" << sent;
      __out << "\t" << acked;
      __out << "\t" << flushed;
      __out << "\t" << sendable;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&connection, __node->children[0]);
      mace::sqlize(&inflight, __node->children[1]);
      mace::sqlize(&rtbuf, __node->children[2]);
      mace::sqlize(&sendbuf, __node->children[3]);
      mace::sqlize(&unfragged, __node->children[4]);
      mace::sqlize(&rts, __node->children[5]);
      mace::sqlize(&curseq, __node->children[6]);
      mace::sqlize(&syn, __node->children[7]);
      mace::sqlize(&last, __node->children[8]);
      
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
    }
    
    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
      int __fields = 0;
      std::istream::pos_type __m_offset = __mace_in.tellg();
      mace::SerializationUtil::expectTag(__mace_in, "<struct>");
      
      std::string tag = mace::SerializationUtil::getTag(__mace_in);
      while (tag == "<member>") {
        __fields++;
        mace::SerializationUtil::expectTag(__mace_in, "<name>");
        std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
        mace::SerializationUtil::expectTag(__mace_in, "</name>");
        mace::SerializationUtil::expectTag(__mace_in, "<value>");
        
        if (__var == "_id") {
          mace::deserializeXML_RPC(__mace_in, &_id, _id);
        } else
        if (__var == "connection") {
          mace::deserializeXML_RPC(__mace_in, & connection, connection);
        } else
        if (__var == "unfragged") {
          mace::deserializeXML_RPC(__mace_in, & unfragged, unfragged);
        } else
        if (__var == "rts") {
          mace::deserializeXML_RPC(__mace_in, & rts, rts);
        } else
        if (__var == "curseq") {
          mace::deserializeXML_RPC(__mace_in, & curseq, curseq);
        } else
        if (__var == "syn") {
          mace::deserializeXML_RPC(__mace_in, & syn, syn);
        } else
        if (__var == "returnSyn") {
          mace::deserializeXML_RPC(__mace_in, & returnSyn, returnSyn);
        } else
        if (__var == "dupacks") {
          mace::deserializeXML_RPC(__mace_in, & dupacks, dupacks);
        } else
        if (__var == "last") {
          mace::deserializeXML_RPC(__mace_in, & last, last);
        } else
        if (__var == "queued") {
          mace::deserializeXML_RPC(__mace_in, & queued, queued);
        } else
        if (__var == "sent") {
          mace::deserializeXML_RPC(__mace_in, & sent, sent);
        } else
        if (__var == "acked") {
          mace::deserializeXML_RPC(__mace_in, & acked, acked);
        } else
        if (__var == "flushed") {
          mace::deserializeXML_RPC(__mace_in, & flushed, flushed);
        } else
        if (__var == "sendable") {
          mace::deserializeXML_RPC(__mace_in, & sendable, sendable);
        } else
        {
          throw(new mace::SerializationException("deserializing OutgoingConnection: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 13) {
        throw(new mace::SerializationException("deserializing OutgoingConnection: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>_id</name><value>");
      mace::serializeXML_RPC(str, &(_id), _id);
      str.append("</value></member>");
      str.append("<member><name>connection</name><value>");
      mace::serializeXML_RPC(str, &(connection), connection);
      str.append("</value></member>");
      str.append("<member><name>unfragged</name><value>");
      mace::serializeXML_RPC(str, &(unfragged), unfragged);
      str.append("</value></member>");
      str.append("<member><name>rts</name><value>");
      mace::serializeXML_RPC(str, &(rts), rts);
      str.append("</value></member>");
      str.append("<member><name>curseq</name><value>");
      mace::serializeXML_RPC(str, &(curseq), curseq);
      str.append("</value></member>");
      str.append("<member><name>syn</name><value>");
      mace::serializeXML_RPC(str, &(syn), syn);
      str.append("</value></member>");
      str.append("<member><name>returnSyn</name><value>");
      mace::serializeXML_RPC(str, &(returnSyn), returnSyn);
      str.append("</value></member>");
      str.append("<member><name>dupacks</name><value>");
      mace::serializeXML_RPC(str, &(dupacks), dupacks);
      str.append("</value></member>");
      str.append("<member><name>last</name><value>");
      mace::serializeXML_RPC(str, &(last), last);
      str.append("</value></member>");
      str.append("<member><name>queued</name><value>");
      mace::serializeXML_RPC(str, &(queued), queued);
      str.append("</value></member>");
      str.append("<member><name>sent</name><value>");
      mace::serializeXML_RPC(str, &(sent), sent);
      str.append("</value></member>");
      str.append("<member><name>acked</name><value>");
      mace::serializeXML_RPC(str, &(acked), acked);
      str.append("</value></member>");
      str.append("<member><name>flushed</name><value>");
      mace::serializeXML_RPC(str, &(flushed), flushed);
      str.append("</value></member>");
      str.append("<member><name>sendable</name><value>");
      mace::serializeXML_RPC(str, &(sendable), sendable);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  class IncomingConnection : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    private:
    MaceKey _id;
    public:
    const MaceKey& getId() const { return _id; }
    double getScore() const { return 0.0; }
    public:
    
    #line 287 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MessagePtrMap m
#line 1699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    MessagePtrMap get_m() const { return m; }
    
    #line 290 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t next
#line 1705 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    seq_t get_next() const { return next; }
    
    #line 291 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t nextDeliver
#line 1711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    seq_t get_nextDeliver() const { return nextDeliver; }
    
    #line 292 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool expectSyn
#line 1717 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    bool get_expectSyn() const { return expectSyn; }
    
    #line 293 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t discardedPackets
#line 1723 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    uint32_t get_discardedPackets() const { return discardedPackets; }
    
    #line 294 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    BufferStatisticsPtr bufStats
#line 1729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    BufferStatisticsPtr get_bufStats() const { return bufStats; }
    IncomingConnection(MaceKey __id = MaceKey()) : serializedByteSize(0), _id(__id), m(), next(), nextDeliver(), expectSyn(true), discardedPackets(0), bufStats(BufferStatisticsPtr(new BufferStatistics(DEFAULT_WINDOW_SIZE))) {}
    IncomingConnection(MaceKey __id, MessagePtrMap const & _m, seq_t const & _next, seq_t const & _nextDeliver, bool const & _expectSyn = true, uint32_t const & _discardedPackets = 0, BufferStatisticsPtr const & _bufStats = BufferStatisticsPtr(new BufferStatistics(DEFAULT_WINDOW_SIZE))) : serializedByteSize(0), _id(__id), m(_m), next(_next), nextDeliver(_nextDeliver), expectSyn(_expectSyn), discardedPackets(_discardedPackets), bufStats(_bufStats) {}
    virtual ~IncomingConnection() {}
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __IncomingConnectionPrinter(__name, "IncomingConnection");
      mace::printItem(__IncomingConnectionPrinter, "id", &_id);
      mace::printItem(__IncomingConnectionPrinter, "m", &(m));;
      mace::printItem(__IncomingConnectionPrinter, "next", &(next));;
      mace::printItem(__IncomingConnectionPrinter, "nextDeliver", &(nextDeliver));;
      mace::printItem(__IncomingConnectionPrinter, "expectSyn", &(expectSyn));;
      mace::printItem(__IncomingConnectionPrinter, "discardedPackets", &(discardedPackets));
      __pr.addChild(__IncomingConnectionPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "IncomingConnection("  << _id << ", " ;
          __out << "m=";  mace::printItem(__out, &(m));
          __out << ", ";
          __out << "next=";  mace::printItem(__out, &(next));
          __out << ", ";
          __out << "nextDeliver=";  mace::printItem(__out, &(nextDeliver));
          __out << ", ";
          __out << "expectSyn=";  mace::printItem(__out, &(expectSyn));
          __out << ", ";
          __out << "discardedPackets=";  mace::printItem(__out, &(discardedPackets));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "IncomingConnection("  << _id << ", ";
          __out << "m=";  mace::printState(__out, &(m), (m));
          __out << ", ";
          __out << "next=";  mace::printState(__out, &(next), (next));
          __out << ", ";
          __out << "nextDeliver=";  mace::printState(__out, &(nextDeliver), (nextDeliver));
          __out << ", ";
          __out << "expectSyn=";  mace::printState(__out, &(expectSyn), (expectSyn));
          __out << ", ";
          __out << "discardedPackets=";  mace::printState(__out, &(discardedPackets), (discardedPackets));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      mace::serialize(str, &_id);
      
      
      #line 290 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &next);
#line 1779 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 291 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &nextDeliver);
#line 1784 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 292 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &expectSyn);
#line 1789 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 293 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &discardedPackets);
#line 1794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__mace_in, &_id);
      
      
      #line 290 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &next);
#line 1806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 291 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &nextDeliver);
#line 1811 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 292 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &expectSyn);
#line 1816 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 293 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &discardedPackets);
#line 1821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, m INT, next INT, nextDeliver INT, expectSyn INT, discardedPackets INT8);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_m", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_next", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_nextDeliver", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _mIndex = __node->children[0]->nextId;
      int _nextIndex = __node->children[1]->nextId;
      int _nextDeliverIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _mIndex;
      __out << "\t" << _nextIndex;
      __out << "\t" << _nextDeliverIndex;
      __out << "\t" << expectSyn;
      __out << "\t" << discardedPackets;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&m, __node->children[0]);
      mace::sqlize(&next, __node->children[1]);
      mace::sqlize(&nextDeliver, __node->children[2]);
      
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
    }
    
    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
      int __fields = 0;
      std::istream::pos_type __m_offset = __mace_in.tellg();
      mace::SerializationUtil::expectTag(__mace_in, "<struct>");
      
      std::string tag = mace::SerializationUtil::getTag(__mace_in);
      while (tag == "<member>") {
        __fields++;
        mace::SerializationUtil::expectTag(__mace_in, "<name>");
        std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
        mace::SerializationUtil::expectTag(__mace_in, "</name>");
        mace::SerializationUtil::expectTag(__mace_in, "<value>");
        
        if (__var == "_id") {
          mace::deserializeXML_RPC(__mace_in, &_id, _id);
        } else
        if (__var == "next") {
          mace::deserializeXML_RPC(__mace_in, & next, next);
        } else
        if (__var == "nextDeliver") {
          mace::deserializeXML_RPC(__mace_in, & nextDeliver, nextDeliver);
        } else
        if (__var == "expectSyn") {
          mace::deserializeXML_RPC(__mace_in, & expectSyn, expectSyn);
        } else
        if (__var == "discardedPackets") {
          mace::deserializeXML_RPC(__mace_in, & discardedPackets, discardedPackets);
        } else
        {
          throw(new mace::SerializationException("deserializing IncomingConnection: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 4) {
        throw(new mace::SerializationException("deserializing IncomingConnection: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>_id</name><value>");
      mace::serializeXML_RPC(str, &(_id), _id);
      str.append("</value></member>");
      str.append("<member><name>next</name><value>");
      mace::serializeXML_RPC(str, &(next), next);
      str.append("</value></member>");
      str.append("<member><name>nextDeliver</name><value>");
      mace::serializeXML_RPC(str, &(nextDeliver), nextDeliver);
      str.append("</value></member>");
      str.append("<member><name>expectSyn</name><value>");
      mace::serializeXML_RPC(str, &(expectSyn), expectSyn);
      str.append("</value></member>");
      str.append("<member><name>discardedPackets</name><value>");
      mace::serializeXML_RPC(str, &(discardedPackets), discardedPackets);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  //END: Mace::Compiler::ServiceImpl::printAutoTypes
  //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
  struct __DeferralArgsFornotifyFlushed_registration_uid_t__ {
    uint64_t __calltime;
    __DeferralArgsFornotifyFlushed_registration_uid_t__() : __calltime(TimeUtil::timeu()) { };
    __DeferralArgsFornotifyFlushed_registration_uid_t__(
        
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t const & rid = -1
#line 1940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) : __calltime(TimeUtil::timeu()), rid(rid){ }
    registration_uid_t rid;};
  //END Mace::Compiler::ServiceImpl::printDeferTypes
  //BEGIN: Mace::Compiler::ServiceImpl::printService
  
  class ServiceTester;
  class MaceTransportService : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, public virtual BufferedTransportServiceClass, public virtual TransportServiceClass, public virtual ReceiveDataHandler, public virtual NetworkErrorHandler
  {
    private:
    
    friend class ServiceTester;
    
    friend class MessageInfo;
    friend class ConnectionInfo;
    friend class OutgoingConnection;
    friend class IncomingConnection;
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
    MaceTransportService(TransportServiceClass& __router, bool const  _UPCALL_MESSAGE_ERROR, size_t const  _maxQueueSize, size_t const  _queueThresholdArg, bool ___shared = true);
    MaceTransportService(const MaceTransportService& other);
    //Destructor
    virtual ~MaceTransportService();
    
    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;
    
    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    private:
    
    const state_type& read_state() const;
    OutgoingConnectionMap const & read_out() const;
    IncomingConnectionMap const & read_in() const;
    MonotoneIdMap const & read_lastSyn() const;
    RegIdSet const & read_notifyFlushed() const;
    uint32_t const & read_flushedCount() const;
    uint32_t const & read_queueThreshold() const;
    
    public:
    //Misc.
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "SNAPSHOT::MaceTransport";
      return desc;
    }
    
    LogClass getLogClass() const {
      return STATE_DUMP;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    
    static const LogIdSet* selectorId_maceResume_demux_44;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_30;
    static const LogIdSet* selectorId_expire_localTimer_demux_50;
    static const LogIdSet* selectorId_checkAndNotifyFlushed_routine_16;
    static const LogIdSet* selectorId_deliver_demux_52;
    static const LogIdSet* selectorId_route_downcall_6;
    static const LogIdSet* selectorId_cancelretransmissionTimer;
    static const LogIdSet* selectorId_upcall_messageError_20_transition;
    static const LogIdSet* selectorId_upcallDeliver_routine_5;
    static const LogIdSet* selectorId_downcall_requestToSend_10_transition;
    static const LogIdSet* selectorId_send_downcall_18;
    static const LogIdSet* selectorId_incomingBufferedDataSize_demux_14;
    static const LogIdSet* selectorId_scheduler_expire_retransmissionTimer_17_transition;
    static const LogIdSet* selectorId_canSend_demux_11;
    static const LogIdSet* selectorId_cancelctsTimer;
    static const LogIdSet* selectorId_upcall_deliver_14_transition;
    static const LogIdSet* selectorId_expirelocalTimer;
    static const LogIdSet* selectorId_route_downcall_10;
    static const LogIdSet* selectorId_clearToSend_upcall_3;
    static const LogIdSet* selectorId_route_demux_38;
    static const LogIdSet* selectorId_getStatistics_demux_19;
    static const LogIdSet* selectorId_checkRetransmissionTimer_routine_19;
    static const LogIdSet* selectorId_resumeDeliver_demux_42;
    static const LogIdSet* selectorId_downcall_routeRTS_11_transition;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_36;
    static const LogIdSet* selectorId_hasBufferedData_demux_22;
    static const LogIdSet* selectorId_downcall_hasOutgoingBufferedData_3_transition;
    static const LogIdSet* selectorId_expire_retransmissionTimer_demux_49;
    static const LogIdSet* selectorId_deliver_demux_2;
    static const LogIdSet* selectorId_send_downcall_16;
    static const LogIdSet* selectorId_enqueue_routine_14;
    static const LogIdSet* selectorId_upcallMessageError_routine_8;
    static const LogIdSet* selectorId_upcall_messageError_21_transition;
    static const LogIdSet* selectorId_messageError_demux_53;
    static const LogIdSet* selectorId_registerHandler_demux_31;
    static const LogIdSet* selectorId_setQueueSize_demux_18;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_demux_24;
    static const LogIdSet* selectorId_resumeDeliver_downcall_2;
    static const LogIdSet* selectorId_deliver_demux_5;
    static const LogIdSet* selectorId_messageError_upcall_2;
    static const LogIdSet* selectorId_incomingMessageQueueSize_demux_15;
    static const LogIdSet* selectorId_upcallMessageError_routine_9;
    static const LogIdSet* selectorId_suspendDeliver_downcall_1;
    static const LogIdSet* selectorId_upcallMessageErrors_routine_7;
    static const LogIdSet* selectorId_routeRTS_demux_25;
    static const LogIdSet* selectorId_send_downcall_21;
    static const LogIdSet* selectorId_bufferedDataSize_demux_21;
    static const LogIdSet* selectorId_route_downcall_5;
    static const LogIdSet* selectorId_suspendDeliver_demux_40;
    static const LogIdSet* selectorId_cancellocalTimer;
    static const LogIdSet* selectorId_incrementAcked_routine_0;
    static const LogIdSet* selectorId_hashState_demux_48;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_33;
    static const LogIdSet* selectorId_maceReset_demux_46;
    static const LogIdSet* selectorId_registerHandler_demux_28;
    static const LogIdSet* selectorId_route_downcall_14;
    static const LogIdSet* selectorId_route_downcall_9;
    static const LogIdSet* selectorId_expireretransmissionTimer;
    static const LogIdSet* selectorId_downcall_canSend_9_transition;
    static const LogIdSet* selectorId_notifyFlushed_upcall_4;
    static const LogIdSet* selectorId_route_downcall_22;
    static const LogIdSet* selectorId_upcall_deliver_16_transition;
    static const LogIdSet* selectorId_downcall_getStatistics_6_transition;
    static const LogIdSet* selectorId_deliver_demux_4;
    static const LogIdSet* selectorId_upcall_messageError_22_transition;
    static const LogIdSet* selectorId_downcall_outgoingBufferedDataSize_7_transition;
    static const LogIdSet* selectorId_maceInit_demux_43;
    static const LogIdSet* selectorId_unregisterHandler_demux_29;
    static const LogIdSet* selectorId_upcall_messageError_24_transition;
    static const LogIdSet* selectorId_resumeDeliver_demux_41;
    static const LogIdSet* selectorId_upcall_deliver_13_transition;
    static const LogIdSet* selectorId_send_downcall_17;
    static const LogIdSet* selectorId_downcall_maceInit_0_transition;
    static const LogIdSet* selectorId_maceExit_demux_45;
    static const LogIdSet* selectorId_closeOutgoingConnection_routine_2;
    static const LogIdSet* selectorId_schedulectsTimer;
    static const LogIdSet* selectorId_processDeliver_routine_10;
    static const LogIdSet* selectorId_error_upcall_1;
    static const LogIdSet* selectorId_schedulelocalTimer;
    static const LogIdSet* selectorId_closeIncomingConnection_routine_1;
    static const LogIdSet* selectorId_deliver_demux_1;
    static const LogIdSet* selectorId_registerHandler_demux_34;
    static const LogIdSet* selectorId_messageError_demux_10;
    static const LogIdSet* selectorId_hasOutgoingBufferedData_demux_23;
    static const LogIdSet* selectorId_downcall_setWindowSize_5_transition;
    static const LogIdSet* selectorId_sendReset_routine_12;
    static const LogIdSet* selectorId_scheduleretransmissionTimer;
    static const LogIdSet* selectorId_route_downcall_11;
    static const LogIdSet* selectorId_localAddress_demux_47;
    static const LogIdSet* selectorId_unregisterHandler_demux_32;
    static const LogIdSet* selectorId_route_downcall_7;
    static const LogIdSet* selectorId_updateFlushed_routine_15;
    static const LogIdSet* selectorId_suspendDeliver_demux_39;
    static const LogIdSet* selectorId_route_demux_37;
    static const LogIdSet* selectorId_deliver_upcall_0;
    static const LogIdSet* selectorId_requestFlushedNotification_demux_27;
    static const LogIdSet* selectorId_unregisterHandler_demux_35;
    static const LogIdSet* selectorId_expire_ctsTimer_demux_51;
    static const LogIdSet* selectorId_printConnection_routine_17;
    static const LogIdSet* selectorId_messageError_demux_6;
    static const LogIdSet* selectorId_messageError_demux_8;
    static const LogIdSet* selectorId_availableBufferSize_demux_12;
    static const LogIdSet* selectorId_downcall_outgoingBufferedDataSize_4_transition;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_routine_21;
    static const LogIdSet* selectorId_scheduler_expire_ctsTimer_19_transition;
    static const LogIdSet* selectorId_expirectsTimer;
    static const LogIdSet* selectorId_route_downcall_4;
    static const LogIdSet* selectorId_downcall_hasBufferedData_8_transition;
    static const LogIdSet* selectorId_send_downcall_19;
    static const LogIdSet* selectorId_resumeDeliver_downcall_3;
    static const LogIdSet* selectorId_downcall_requestFlushedNotification_2_transition;
    static const LogIdSet* selectorId_route_downcall_8;
    static const LogIdSet* selectorId_route_downcall_15;
    static const LogIdSet* selectorId_downcall_route_1_transition;
    static const LogIdSet* selectorId_sendPackets_routine_13;
    static const LogIdSet* selectorId_route_downcall_23;
    static const LogIdSet* selectorId_incomingMessageQueueSize_demux_16;
    static const LogIdSet* selectorId_messageError_demux_9;
    static const LogIdSet* selectorId_error_demux_0;
    static const LogIdSet* selectorId_scheduler_expire_localTimer_18_transition;
    static const LogIdSet* selectorId_upcall_deliver_12_transition;
    static const LogIdSet* selectorId_send_downcall_20;
    static const LogIdSet* selectorId_route_downcall_12;
    static const LogIdSet* selectorId_setWindowSize_demux_17;
    static const LogIdSet* selectorId_routeRTS_demux_26;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_demux_13;
    static const LogIdSet* selectorId_messageError_demux_7;
    static const LogIdSet* selectorId_upcallMessageErrors_routine_6;
    static const LogIdSet* selectorId_deliverBuffered_routine_4;
    static const LogIdSet* selectorId_route_downcall_13;
    static const LogIdSet* selectorId_deliver_demux_3;
    static const LogIdSet* selectorId_send_downcall_24;
    static const LogIdSet* selectorId_upcall_deliver_15_transition;
    static const LogIdSet* selectorId_sendAck_routine_11;
    static const LogIdSet* selectorId_inflightSize_routine_18;
    static const LogIdSet* selectorId_suspendDeliver_downcall_0;
    static const LogIdSet* selectorId_upcall_messageError_23_transition;
    static const LogIdSet* selectorId_closeBidirectionalConnection_routine_3;
    static const LogIdSet* selectorId_checkRetransmissionTimerCount_routine_20;
    static const LogIdSet* selectorId_requestToSend_demux_20;
    
    protected:
    void dumpState(LOGLOGTYPE& logger) const;
    void processDeferred();
    const char* getStateName(state_type state) const;
    const char* getMessageName(uint8_t msgNum) const;
    void changeState(state_type stateNum, int selectorId);
    bool shouldLog_canSend48( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_availableBufferSize49( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize50( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingBufferedDataSize51( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize52( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize53(registration_uid_t rid) const;
    bool shouldLog_setWindowSize54( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const;
    bool shouldLog_setQueueSize55( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const;
    bool shouldLog_getStatistics56( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const;
    bool shouldLog_requestToSend57( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_bufferedDataSize58(registration_uid_t rid) const;
    bool shouldLog_hasBufferedData59(registration_uid_t rid) const;
    bool shouldLog_hasOutgoingBufferedData60(registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize61(registration_uid_t rid) const;
    bool shouldLog_routeRTS62( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_routeRTS63( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_requestFlushedNotification64(registration_uid_t rid) const;
    bool shouldLog_route65( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_route66( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver67(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver68( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver69(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver70( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_maceInit71() const;
    bool shouldLog_maceResume72() const;
    bool shouldLog_maceExit73() const;
    bool shouldLog_maceReset74() const;
    bool shouldLog_localAddress75() const;
    bool shouldLog_hashState76() const;
    bool shouldLog_error77( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const;
    bool shouldLog_deliver78( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver79( const MaceKey& source,  const MaceKey& destination,  const DataFragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver80( const MaceKey& source,  const MaceKey& destination,  const Fragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver81( const MaceKey& source,  const MaceKey& destination,  const Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver82( const MaceKey& source,  const MaceKey& destination,  const Reset& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError83( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError84( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError85( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError86( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError87( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_expire_retransmissionTimer88(MaceKey& p0, MessageInfoPtr& p1) const;
    bool shouldLog_expire_localTimer89(std::string& p0, registration_uid_t& p1) const;
    bool shouldLog_expire_ctsTimer90(MaceKey& p0) const;
    bool shouldLog_suspendDeliver23(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver24( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver25(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver26( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_route27( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route28( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route29( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route30( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route31( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route32( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route33( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route34( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send39( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send40( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send41( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send42( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send43( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send44( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_upcall_notifyFlushed22(registration_uid_t rid) const;
    bool shouldLog_incrementAcked0(OutgoingConnection& c, uint32_t size) const;
    bool shouldLog_closeIncomingConnection1( const MaceKey& src, TransportError::type error,  const std::string& errstr, bool upcallError) const;
    bool shouldLog_closeOutgoingConnection2( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr, bool upcallError) const;
    bool shouldLog_closeBidirectionalConnection3( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr) const;
    bool shouldLog_deliverBuffered4(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest) const;
    bool shouldLog_upcallDeliver5(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest,  const std::string& payload, registration_uid_t rid) const;
    bool shouldLog_upcallMessageErrors6(MessagePtrMap::iterator i, MessagePtrMap::iterator end,  const MaceKey& dest, OutgoingConnection& c, IdSet& seen, TransportError::type error) const;
    bool shouldLog_upcallMessageErrors7(MessagePtrList::iterator i, MessagePtrList::iterator end,  const MaceKey& dest, OutgoingConnection& c, IdSet& seen, TransportError::type error) const;
    bool shouldLog_upcallMessageError8( const MaceKey& dest, MessageInfoPtr m, OutgoingConnection& c, IdSet& seen, TransportError::type error) const;
    bool shouldLog_upcallMessageError9( const MaceKey& dest, MessageInfoPtr m, OutgoingConnection& c, TransportError::type error) const;
    bool shouldLog_processDeliver10( const MaceKey& src,  const MaceKey& dest, seq_t seq, mace::string payload, uint32_t ssize, registration_uid_t rid, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t nfrag, uint32_t frag) const;
    bool shouldLog_sendAck11( const MaceKey& src, seq_t seq, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t sz, seq_t& ackseq, bool& discard) const;
    bool shouldLog_sendReset12( const MaceKey& dest, mace::MonotoneTime id, seq_t seq) const;
    bool shouldLog_sendPackets13(OutgoingConnection& c) const;
    bool shouldLog_enqueue14(OutgoingConnection& c,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_updateFlushed15(OutgoingConnection& c) const;
    bool shouldLog_checkAndNotifyFlushed16() const;
    bool shouldLog_printConnection17( const OutgoingConnection& c,  const std::string& s) const;
    bool shouldLog_inflightSize18() const;
    bool shouldLog_checkRetransmissionTimer19() const;
    bool shouldLog_checkRetransmissionTimerCount20() const;
    bool shouldLog_outgoingBufferedDataSize21() const;
    
    
    public:
    void print(mace::PrintNode& __printer, const std::string& name) const;
    void print(std::ostream& logger) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;
    
    void serialize(std::string& str) const;
    int deserialize(std::istream& is) throw(SerializationException);
    
    //Provided Methods (calls into this service from a higher layer)
    bool canSend(
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t availableBufferSize(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2272 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t outgoingBufferedDataSize(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2285 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t incomingBufferedDataSize(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t incomingMessageQueueSize(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t incomingMessageQueueSize(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2308 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void setWindowSize(
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2313 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint64_t microsec
#line 2317 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2321 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void setQueueSize(
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t size
#line 2330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t threshold
#line 2334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    const BufferStatisticsPtr getStatistics(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2343 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        TransportServiceClass::Connection::type d
#line 2347 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void requestToSend(
        #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 2356 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2360 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t bufferedDataSize(
        #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool hasBufferedData(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2370 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool hasOutgoingBufferedData(
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    uint32_t outgoingBufferedDataSize(
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool routeRTS(
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 2385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 2389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2393 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool routeRTS(
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& src
#line 2398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 2402 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 2406 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void requestFlushedNotification(
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 2415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    registration_uid_t registerHandler(
        #line 181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 2420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void unregisterHandler(
        #line 182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 2429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void registerUniqueHandler(
        #line 184 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 2438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    registration_uid_t registerHandler(
        #line 185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 2443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void unregisterHandler(
        #line 186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 2452 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2456 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void registerUniqueHandler(
        #line 188 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 2461 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    registration_uid_t registerHandler(
        #line 189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 2466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2470 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void unregisterHandler(
        #line 190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 2475 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 2479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void registerUniqueHandler(
        #line 192 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 2484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool route(
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 2493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 2497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool route(
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& src
#line 2502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 2510 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 2514 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 2519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2524 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 2528 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 2533 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 2542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
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
#line 2555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 2559 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 2563 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 2567 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 2572 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 2576 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 2580 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 2584 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 2589 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 2593 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 2597 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 2601 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    
    //Registration Methods (for dynamic registration)
    
    
    protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.
    
    //Constructor Parameter (Variables)
    
    #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    bool const  UPCALL_MESSAGE_ERROR
#line 2617 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    size_t const  maxQueueSize
#line 2622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    size_t const  queueThresholdArg
#line 2627 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    //ServiceVariables and Registration UIDs
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& _router;
#line 2634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    registration_uid_t router;
    
    //Aspect Methods
    
    
    //Registration Typedefs and Maps
    typedef std::map<int, ReceiveDataHandler* > maptype_ReceiveDataHandler;
    maptype_ReceiveDataHandler map_ReceiveDataHandler;
    typedef std::map<int, NetworkErrorHandler* > maptype_NetworkErrorHandler;
    maptype_NetworkErrorHandler map_NetworkErrorHandler;
    typedef std::map<int, ConnectionStatusHandler* > maptype_ConnectionStatusHandler;
    maptype_ConnectionStatusHandler map_ConnectionStatusHandler;
    
    //State Variables
    
    #line 299 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    OutgoingConnectionMap out
#line 2652 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 300 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    IncomingConnectionMap in
#line 2657 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 301 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    MonotoneIdMap lastSyn
#line 2662 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    RegIdSet notifyFlushed
#line 2667 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 303 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t flushedCount
#line 2672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 304 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t queueThreshold
#line 2677 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    //Timer Vars
    class retransmissionTimer_MaceTimer;
    retransmissionTimer_MaceTimer &retransmissionTimer;
    class localTimer_MaceTimer;
    localTimer_MaceTimer &localTimer;
    class ctsTimer_MaceTimer;
    ctsTimer_MaceTimer &ctsTimer;
    
    //Context Declaration
    
    
    //Timer Methods
    void expire_retransmissionTimer(MaceKey& p0, MessageInfoPtr& p1);
    void expire_localTimer(std::string& p0, registration_uid_t& p1);
    void expire_ctsTimer(MaceKey& p0);
    
    //Async Helper Methods
    
    
    //Async Helper Methods
    
    
    //Sync Methods
    
    
    //Sync Helper Methods
    
    
    //Merge Class Declarations
    
    
    //Downcall and Upcall helper methods
    
    void downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 2716 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2721 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 2725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 2730 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 2735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 2739 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2744 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 2748 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2752 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 2761 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2765 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 2774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2778 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2783 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 2787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 2800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2809 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 2813 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2822 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2826 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 2830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2834 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2839 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2843 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 2847 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2851 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2856 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2860 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 2864 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2873 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2877 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 2881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 2898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 2907 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 2915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Message& s_deserialized
#line 2928 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 2941 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2945 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2950 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 2954 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2958 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2963 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 2967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2971 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2976 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 2980 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2984 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t downcall_send(
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 2989 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 2993 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 2997 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcall_deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 3002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 3006 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 3010 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3014 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcall_error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 3019 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 3023 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message = ""
#line 3027 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 3031 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcall_messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 3036 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 3040 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 3044 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 3048 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcall_clearToSend(
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        const MaceKey& peer
#line 3053 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
        registration_uid_t rid = -1
#line 3057 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcall_notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid = -1
#line 3062 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    
    //Serialized form Method Helpers
    
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 3070 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 3074 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& s_deserialized
#line 3078 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3082 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 3087 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 3091 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& s_deserialized
#line 3095 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3099 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 3104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 3108 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& s_deserialized
#line 3112 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3116 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 3121 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 3125 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& s_deserialized
#line 3129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& source
#line 3138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& destination
#line 3142 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& s_deserialized
#line 3146 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 3150 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& message_deserialized
#line 3163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 3167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& message_deserialized
#line 3180 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 3184 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3193 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& message_deserialized
#line 3197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 3201 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3210 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& message_deserialized
#line 3214 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 3218 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3223 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3227 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& message_deserialized
#line 3231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = -1
#line 3235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    
    //Transition and Guard Method Declarations
    void downcall_0_maceInit();
    bool guard_downcall_0_maceInit() const;
    bool downcall_1_route(
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3244 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 3248 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_1_route(
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string const & s
#line 3261 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 358 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void downcall_2_requestFlushedNotification(
        #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3270 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_2_requestFlushedNotification(
        #line 376 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3275 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    bool downcall_3_hasOutgoingBufferedData();
    bool guard_downcall_3_hasOutgoingBufferedData() const;
    uint32_t downcall_4_outgoingBufferedDataSize();
    bool guard_downcall_4_outgoingBufferedDataSize() const;
    void downcall_5_setWindowSize(
        #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& peer
#line 3284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t size
#line 3288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_5_setWindowSize(
        #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & peer
#line 3293 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 397 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint64_t const  size
#line 3297 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    const BufferStatisticsPtr downcall_6_getStatistics(
        #line 401 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& peer
#line 3302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 402 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportServiceClass::Connection::type d
#line 3306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_6_getStatistics(
        #line 401 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & peer
#line 3311 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 402 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportServiceClass::Connection::type const  d
#line 3315 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    uint32_t downcall_7_outgoingBufferedDataSize(
        #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& peer
#line 3320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_7_outgoingBufferedDataSize(
        #line 411 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & peer
#line 3325 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    bool downcall_8_hasBufferedData(
        #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_8_hasBufferedData(
        #line 421 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    bool downcall_9_canSend(
        #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& peer
#line 3340 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_9_canSend(
        #line 433 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & peer
#line 3345 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void downcall_10_requestToSend(
        #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& peer
#line 3350 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3354 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_10_requestToSend(
        #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & peer
#line 3359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 441 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    bool downcall_11_routeRTS(
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3368 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 3372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_downcall_11_routeRTS(
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string const & s
#line 3385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 452 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3389 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_12_deliver(
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& m
#line 3402 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_12_deliver(
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 3407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 463 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Data const & m
#line 3415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_13_deliver(
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& m
#line 3428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_13_deliver(
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 3433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 468 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        DataFragment const & m
#line 3441 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_14_deliver(
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3446 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& m
#line 3454 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_14_deliver(
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 3459 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 473 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Fragment const & m
#line 3467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_15_deliver(
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& ack
#line 3480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_15_deliver(
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 3485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 478 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Ack const & ack
#line 3493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_16_deliver(
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& rst
#line 3506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_16_deliver(
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & src
#line 3511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 571 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Reset const & rst
#line 3519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void scheduler_17_expire_retransmissionTimer(
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey& dest
#line 3524 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr& m
#line 3528 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_scheduler_17_expire_retransmissionTimer(
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3533 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 591 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr const & m
#line 3537 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void scheduler_18_expire_localTimer(
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string& s
#line 3542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t& rid
#line 3546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_scheduler_18_expire_localTimer(
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        std::string const & s
#line 3551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 645 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const & rid
#line 3555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void scheduler_19_expire_ctsTimer(
        #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey& dest
#line 3560 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_scheduler_19_expire_ctsTimer(
        #line 654 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3565 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_20_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3570 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3574 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Data& message_deserialized
#line 3578 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3582 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_20_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3587 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 3591 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Data const & message_deserialized
#line 3595 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_21_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const DataFragment& message_deserialized
#line 3612 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3616 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_21_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3621 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 3625 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        DataFragment const & message_deserialized
#line 3629 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3633 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_22_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3638 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3642 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Fragment& message_deserialized
#line 3646 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3650 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_22_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 3659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Fragment const & message_deserialized
#line 3663 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3667 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_23_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Ack& message_deserialized
#line 3680 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_23_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 3693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Ack const & message_deserialized
#line 3697 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3701 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    void upcall_24_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3706 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type errorCode
#line 3710 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const Reset& message_deserialized
#line 3714 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3718 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    bool guard_upcall_24_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MaceKey const & dest
#line 3723 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type const  errorCode
#line 3727 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        Reset const & message_deserialized
#line 3731 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t const  rid
#line 3735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    
    //Routines
    void incrementAcked(
        #line 676 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3742 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 676 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t size
#line 3746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void closeIncomingConnection(
        #line 684 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 684 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 685 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3759 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 685 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool upcallError = true
#line 3763 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void closeOutgoingConnection(
        #line 716 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 716 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 717 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3776 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 717 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3780 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 718 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool upcallError = true
#line 3784 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void closeBidirectionalConnection(
        #line 751 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3789 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 751 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3793 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 752 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3797 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 753 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& errstr
#line 3801 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void deliverBuffered(
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IncomingConnection& c
#line 3806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 760 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3814 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcallDeliver(
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IncomingConnection& c
#line 3819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 802 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 803 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& payload
#line 3831 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 803 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 3835 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcallMessageErrors(
        #line 808 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrMap::iterator i
#line 3840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 808 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrMap::iterator end
#line 3844 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3848 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3852 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 809 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3856 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 810 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3860 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcallMessageErrors(
        #line 817 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrList::iterator i
#line 3865 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 817 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessagePtrList::iterator end
#line 3869 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3873 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3877 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 818 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 819 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcallMessageError(
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr m
#line 3894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 826 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 827 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        IdSet& seen
#line 3902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 827 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void upcallMessageError(
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        MessageInfoPtr m
#line 3915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 837 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 3919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 838 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        TransportError::type error
#line 3923 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void processDeliver(
        #line 852 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3928 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 852 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 3936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::string payload
#line 3940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 853 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t ssize
#line 3944 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 854 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid = 0
#line 3948 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 854 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn = 0
#line 3952 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 855 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho = 0
#line 3956 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 856 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t nfrag = 0
#line 3960 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 856 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t frag = 0
#line 3964 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    IncomingConnection& sendAck(
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 3969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 3973 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn
#line 3977 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho
#line 3981 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t sz
#line 3985 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t& ackseq
#line 3989 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool& discard
#line 3993 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void sendReset(
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& dest
#line 3998 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime id
#line 4002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1038 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 4006 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void sendPackets(
        #line 1049 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4011 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void enqueue(
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 4020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1121 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        registration_uid_t rid
#line 4024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void updateFlushed(
        #line 1170 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        OutgoingConnection& c
#line 4029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    void checkAndNotifyFlushed();
    void printConnection(
        #line 1189 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const OutgoingConnection& c
#line 4035 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 1189 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const std::string& s
#line 4039 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ) const;
    size_t inflightSize() const;
    bool checkRetransmissionTimer() const;
    bool checkRetransmissionTimerCount() const;
    uint64_t outgoingBufferedDataSize() const;
    IncomingConnection& __mace_log_sendAck(
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        const MaceKey& src
#line 4048 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t seq
#line 4052 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 944 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime syn
#line 4056 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        mace::MonotoneTime synecho
#line 4060 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        uint32_t sz
#line 4064 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 945 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        seq_t& ackseq
#line 4068 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
        ,
        #line 946 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
        bool& discard
#line 4072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    size_t __mace_log_inflightSize() const;
    bool __mace_log_checkRetransmissionTimer() const;
    bool __mace_log_checkRetransmissionTimerCount() const;
    uint64_t __mace_log_outgoingBufferedDataSize() const;
    
    //Deferal Variables
    mace::deque<__DeferralArgsFornotifyFlushed_registration_uid_t__, mace::SoftState> __deferralArgList_notifyFlushed_registration_uid_t__;
    
    
    //Local Address
    MaceKey __local_address;
    MaceKey downcall_localAddress() const;
    const MaceKey& downcall_localAddress(const registration_uid_t& rid) const;
    
    //Defer methods
    
    void defer_upcall_notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid = -1
#line 4093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    );
    
    
    //Pre and Post Transition Demux Method Declarations
    
    
    public:
    
    
    static bool checkSafetyProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("MaceTransport::checkSafetyProperties");
      maceout << "Testing safety properties" << Log::endl;
      if(!modelProperty_retransmissionTimerScheduled(_nodes_, _keys_)) { maceerr << "Safety property retransmissionTimerScheduled: failed" << Log::endl; description = "MaceTransport::retransmissionTimerScheduled"; return false; } else
      if(!modelProperty_retransmissionTimerScheduledCount(_nodes_, _keys_)) { maceerr << "Safety property retransmissionTimerScheduledCount: failed" << Log::endl; description = "MaceTransport::retransmissionTimerScheduledCount"; return false; } else
      { maceout << "Safety Properties: check" << Log::endl; return true; }
    }
    
    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("MaceTransport::checkLivenessProperties");
      maceout << "Testing liveness properties" << Log::endl;
      if(!modelProperty_inflightEmpty(_nodes_, _keys_)) { maceout << "Liveness property inflightEmpty: failed" << Log::endl; description = "MaceTransport::inflightEmpty"; return false; } else
      if(!modelProperty_bufferedDataEmpty(_nodes_, _keys_)) { maceout << "Liveness property bufferedDataEmpty: failed" << Log::endl; description = "MaceTransport::bufferedDataEmpty"; return false; } else
      if(!modelProperty_sequenceNumbersMatch(_nodes_, _keys_)) { maceout << "Liveness property sequenceNumbersMatch: failed" << Log::endl; description = "MaceTransport::sequenceNumbersMatch"; return false; } else
      { maceout << "Liveness Properties: check" << Log::endl; return true; }
    }
    
    protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("MaceTransport::castNode::MaceKey");
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
    // Property retransmissionTimerScheduled : ( for all elements n in \nodes it is true that n.checkRetransmissionTimer() )
    static bool modelProperty_retransmissionTimerScheduled(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool retransmissionTimerScheduled_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    
    // Property retransmissionTimerScheduledCount : ( for all elements n in \nodes it is true that n.checkRetransmissionTimerCount() )
    static bool modelProperty_retransmissionTimerScheduledCount(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool retransmissionTimerScheduledCount_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    
    
    //Model Checking Liveness Properties
    // Property inflightEmpty : ( for all elements n in \nodes it is true that ( n.inflightSize() == 0 ) )
    static bool modelProperty_inflightEmpty(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool inflightEmpty_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool inflightEmpty_Equation_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n);
    
    // Property bufferedDataEmpty : ( for all elements n in \nodes it is true that ( n.outgoingBufferedDataSize() == 0 ) )
    static bool modelProperty_bufferedDataEmpty(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool bufferedDataEmpty_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool bufferedDataEmpty_Equation_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n);
    
    // Property sequenceNumbersMatch : ( for all elements n in \nodes it is true that ( for all elements c in n.out it is true that ( ( ! c->first.in.contains(n)) or ( ( c->second.curseq + 1 ) == c->first.in.get(n).nextDeliver ) ) ) )
    static bool modelProperty_sequenceNumbersMatch(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool sequenceNumbersMatch_Quantification_0(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_);
    static bool sequenceNumbersMatch_Quantification_1(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n);
    static bool sequenceNumbersMatch_JoinExpression_5(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c);
    static bool sequenceNumbersMatch_Equation_2(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c);
    static bool sequenceNumbersMatch_Equation_4(_NodeMap_ const & _nodes_, _KeyMap_ const & _keys_, _NodeMap_::const_iterator const & n, OutgoingConnectionMap::const_iterator const & c);
    
  };
  //END: Mace::Compiler::ServiceImpl::printService
  //BEGIN Mace::Compiler::ServiceImpl::generateMergeClasses
  //END Mace::Compiler::ServiceImpl::generateMergeClasses
  //BEGIN: Mace::Compiler::ServiceImpl::printRoutineObjects
  //END: Mace::Compiler::ServiceImpl::printRoutineObjects
  //BEGIN: Mace::Compiler::ServiceImpl::printMessages
  
  struct Data_struct {
    
    #line 316 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 4190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 317 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    registration_uid_t rid
#line 4195 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 318 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime syn
#line 4200 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 319 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime synecho
#line 4205 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 320 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::string payload
#line 4210 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
  };
  
  class Data : public Message, public mace::PrintPrintable {
    private:
    Data_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Data() : _data_store_(new Data_struct()), serializedByteSize(0) , seq(_data_store_->seq), rid(_data_store_->rid), syn(_data_store_->syn), synecho(_data_store_->synecho), payload(_data_store_->payload) {}
    Data(seq_t const & my_seq, registration_uid_t const & my_rid, mace::MonotoneTime const & my_syn, mace::MonotoneTime const & my_synecho, mace::string const & my_payload) : _data_store_(NULL), serializedByteSize(0), seq(my_seq), rid(my_rid), syn(my_syn), synecho(my_synecho), payload(my_payload) {}
    Data(const Data& _orig) : _data_store_(new Data_struct( *_orig._data_store_)), serializedByteSize(0) , seq(_data_store_->seq), rid(_data_store_->rid), syn(_data_store_->syn), synecho(_data_store_->synecho), payload(_data_store_->payload) {
    }
    virtual ~Data() { delete _data_store_; _data_store_ = NULL; }
    
    seq_t const & seq;
    registration_uid_t const & rid;
    mace::MonotoneTime const & syn;
    mace::MonotoneTime const & synecho;
    mace::string const & payload;
    
    static const uint8_t messageType = 1;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Data::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Data(";
          __out << "seq=";  mace::printItem(__out, &(seq));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
          __out << ", ";
          __out << "syn=";  mace::printItem(__out, &(syn));
          __out << ", ";
          __out << "synecho=";  mace::printItem(__out, &(synecho));
          __out << ", ";
          __out << "payload=";  mace::printItem(__out, &(payload));
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
      
      #line 316 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 4266 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 317 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &rid);
#line 4271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 318 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &syn);
#line 4276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 319 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &synecho);
#line 4281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 320 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &payload);
#line 4286 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
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
      
      #line 316 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seq);
#line 4301 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 317 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rid);
#line 4306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 318 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->syn);
#line 4311 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 319 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->synecho);
#line 4316 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 320 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->payload);
#line 4321 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, seq INT, rid INT, syn INT, synecho INT, payload TEXT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_synecho", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _seqIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      int _synIndex = __node->children[2]->nextId;
      int _synechoIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _seqIndex;
      __out << "\t" << _ridIndex;
      __out << "\t" << _synIndex;
      __out << "\t" << _synechoIndex;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&seq, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      mace::sqlize(&syn, __node->children[2]);
      mace::sqlize(&synecho, __node->children[3]);
      
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
  
  
  struct DataFragment_struct {
    
    #line 324 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 4385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 325 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    registration_uid_t rid
#line 4390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 326 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime syn
#line 4395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 327 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime synecho
#line 4400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 328 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t nfrag
#line 4405 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 329 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::string payload
#line 4410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
  };
  
  class DataFragment : public Message, public mace::PrintPrintable {
    private:
    DataFragment_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    DataFragment() : _data_store_(new DataFragment_struct()), serializedByteSize(0) , seq(_data_store_->seq), rid(_data_store_->rid), syn(_data_store_->syn), synecho(_data_store_->synecho), nfrag(_data_store_->nfrag), payload(_data_store_->payload) {}
    DataFragment(seq_t const & my_seq, registration_uid_t const & my_rid, mace::MonotoneTime const & my_syn, mace::MonotoneTime const & my_synecho, uint32_t const & my_nfrag, mace::string const & my_payload) : _data_store_(NULL), serializedByteSize(0), seq(my_seq), rid(my_rid), syn(my_syn), synecho(my_synecho), nfrag(my_nfrag), payload(my_payload) {}
    DataFragment(const DataFragment& _orig) : _data_store_(new DataFragment_struct( *_orig._data_store_)), serializedByteSize(0) , seq(_data_store_->seq), rid(_data_store_->rid), syn(_data_store_->syn), synecho(_data_store_->synecho), nfrag(_data_store_->nfrag), payload(_data_store_->payload) {
    }
    virtual ~DataFragment() { delete _data_store_; _data_store_ = NULL; }
    
    seq_t const & seq;
    registration_uid_t const & rid;
    mace::MonotoneTime const & syn;
    mace::MonotoneTime const & synecho;
    uint32_t const & nfrag;
    mace::string const & payload;
    
    static const uint8_t messageType = 2;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return DataFragment::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "DataFragment(";
          __out << "seq=";  mace::printItem(__out, &(seq));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
          __out << ", ";
          __out << "syn=";  mace::printItem(__out, &(syn));
          __out << ", ";
          __out << "synecho=";  mace::printItem(__out, &(synecho));
          __out << ", ";
          __out << "nfrag=";  mace::printItem(__out, &(nfrag));
          __out << ", ";
          __out << "payload=";  mace::printItem(__out, &(payload));
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
      
      #line 324 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 4469 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 325 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &rid);
#line 4474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 326 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &syn);
#line 4479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 327 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &synecho);
#line 4484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 328 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &nfrag);
#line 4489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 329 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &payload);
#line 4494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
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
      
      #line 324 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seq);
#line 4509 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 325 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rid);
#line 4514 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 326 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->syn);
#line 4519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 327 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->synecho);
#line 4524 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 328 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->nfrag);
#line 4529 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 329 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->payload);
#line 4534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, seq INT, rid INT, syn INT, synecho INT, nfrag INT8, payload TEXT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_synecho", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _seqIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      int _synIndex = __node->children[2]->nextId;
      int _synechoIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _seqIndex;
      __out << "\t" << _ridIndex;
      __out << "\t" << _synIndex;
      __out << "\t" << _synechoIndex;
      __out << "\t" << nfrag;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&seq, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      mace::sqlize(&syn, __node->children[2]);
      mace::sqlize(&synecho, __node->children[3]);
      
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
  
  
  struct Fragment_struct {
    
    #line 333 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 4599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 334 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    uint32_t frag
#line 4604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 335 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::string payload
#line 4609 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
  };
  
  class Fragment : public Message, public mace::PrintPrintable {
    private:
    Fragment_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Fragment() : _data_store_(new Fragment_struct()), serializedByteSize(0) , seq(_data_store_->seq), frag(_data_store_->frag), payload(_data_store_->payload) {}
    Fragment(seq_t const & my_seq, uint32_t const & my_frag, mace::string const & my_payload) : _data_store_(NULL), serializedByteSize(0), seq(my_seq), frag(my_frag), payload(my_payload) {}
    Fragment(const Fragment& _orig) : _data_store_(new Fragment_struct( *_orig._data_store_)), serializedByteSize(0) , seq(_data_store_->seq), frag(_data_store_->frag), payload(_data_store_->payload) {
    }
    virtual ~Fragment() { delete _data_store_; _data_store_ = NULL; }
    
    seq_t const & seq;
    uint32_t const & frag;
    mace::string const & payload;
    
    static const uint8_t messageType = 3;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Fragment::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Fragment(";
          __out << "seq=";  mace::printItem(__out, &(seq));
          __out << ", ";
          __out << "frag=";  mace::printItem(__out, &(frag));
          __out << ", ";
          __out << "payload=";  mace::printItem(__out, &(payload));
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
      
      #line 333 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 4659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 334 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &frag);
#line 4664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 335 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &payload);
#line 4669 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
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
      
      #line 333 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seq);
#line 4684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 334 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->frag);
#line 4689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 335 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->payload);
#line 4694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, seq INT, frag INT8, payload TEXT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _seqIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _seqIndex;
      __out << "\t" << frag;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&seq, __node->children[0]);
      
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
  
  
  struct Ack_struct {
    
    #line 340 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 4744 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
  };
  
  class Ack : public Message, public mace::PrintPrintable {
    private:
    Ack_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Ack() : _data_store_(new Ack_struct()), serializedByteSize(0) , seq(_data_store_->seq) {}
    Ack(seq_t const & my_seq) : _data_store_(NULL), serializedByteSize(0), seq(my_seq) {}
    Ack(const Ack& _orig) : _data_store_(new Ack_struct( *_orig._data_store_)), serializedByteSize(0) , seq(_data_store_->seq) {
    }
    virtual ~Ack() { delete _data_store_; _data_store_ = NULL; }
    
    seq_t const & seq;
    
    static const uint8_t messageType = 4;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Ack::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Ack(";
          __out << "seq=";  mace::printItem(__out, &(seq));
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
      
      #line 340 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 4788 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
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
      
      #line 340 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seq);
#line 4803 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, seq INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _seqIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _seqIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&seq, __node->children[0]);
      
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
  
  
  struct Reset_struct {
    
    #line 344 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::MonotoneTime syn
#line 4845 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
    
    #line 345 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    seq_t seq
#line 4850 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
    ;
  };
  
  class Reset : public Message, public mace::PrintPrintable {
    private:
    Reset_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Reset() : _data_store_(new Reset_struct()), serializedByteSize(0) , syn(_data_store_->syn), seq(_data_store_->seq) {}
    Reset(mace::MonotoneTime const & my_syn, seq_t const & my_seq) : _data_store_(NULL), serializedByteSize(0), syn(my_syn), seq(my_seq) {}
    Reset(const Reset& _orig) : _data_store_(new Reset_struct( *_orig._data_store_)), serializedByteSize(0) , syn(_data_store_->syn), seq(_data_store_->seq) {
    }
    virtual ~Reset() { delete _data_store_; _data_store_ = NULL; }
    
    mace::MonotoneTime const & syn;
    seq_t const & seq;
    
    static const uint8_t messageType = 5;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Reset::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Reset(";
          __out << "syn=";  mace::printItem(__out, &(syn));
          __out << ", ";
          __out << "seq=";  mace::printItem(__out, &(seq));
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
      
      #line 344 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &syn);
#line 4897 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 345 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      mace::serialize(str, &seq);
#line 4902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
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
      
      #line 344 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->syn);
#line 4917 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      
      #line 345 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seq);
#line 4922 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, syn INT, seq INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _synIndex = __node->children[0]->nextId;
      int _seqIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _synIndex;
      __out << "\t" << _seqIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&syn, __node->children[0]);
      mace::sqlize(&seq, __node->children[1]);
      
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
  class MaceTransportService::retransmissionTimer_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    retransmissionTimer_MaceTimer(MaceTransportService *a)
    : TimerHandler("MaceTransportService::retransmissionTimer", 1), agent_(a)
    {
    }
    
    virtual ~retransmissionTimer_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    MaceTime schedule(const MaceTime& interval , MaceKey const & p0, MessageInfoPtr const & p1) {
      #define selector selector_scheduleretransmissionTimer
      #define selectorId selectorId_scheduleretransmissionTimer
      PREPARE_FUNCTION
      
      TimerData* td = new TimerData(p0, p1);
      td->pipPathId = annotate_get_path_id_copy(&td->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      //	  TimerData* td = new TimerData(p0, p1);
      uint64_t t = mace::getmtime() + interval.time();
      if (1 && Scheduler::simulated()) {
        t = mace::getmtime();
      }
      // maceout << "interval=" << interval << " t=" << t << Log::endl;
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(t);
      while(i != timerData.end() && i->first == t) {
        // maceout << "found duplicate timer scheduled for " << t << Log::endl;
        i++;
        t++;
      }
      // 	  std::cerr << "assigning timer to " << t << std::endl;
      timerData[t] = td;
      if (timerData.begin()->first == t) {
        TimerHandler::cancel();
        if (true) { maceout << "calling schedule for " << t << Log::endl; }
        ASSERT(TimerHandler::schedule(t, true) == t);
      }
      return t;
      
      #undef selector
      #undef selectorId
    }
    
    void cancel() {
      #define selector selector_cancelretransmissionTimer
      #define selectorId selectorId_cancelretransmissionTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      TimerHandler::cancel();
      maceout << "canceling all timers" << Log::endl;
      for(mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin(); i != timerData.end(); i++) {
        delete i->second;
      }
      // maceout << "clearing timerData" << Log::endl;
      timerData.clear();
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(const MaceTime& expireTime) {
      #define selector selector_cancelretransmissionTimer
      #define selectorId selectorId_cancelretransmissionTimer
      
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer at " << expireTime << Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(expireTime.time());
      if (i == timerData.end()) {
        if (true) { maceout << "timer not found, returning" << Log::endl; }
        return;
      }
      delete i->second;
      if (i == timerData.begin()) {
        if (true) { maceout << "calling TimerHandler::cancel on" << getId() << Log::endl; }
        TimerHandler::cancel();
        timerData.erase(i);
        if (!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      else {
        if (true) { maceout << "erasing from timerData " << i->first << Log::endl; }
        timerData.erase(i);
      }
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(MaceKey const & p0) {
      #define selector selector_cancelretransmissionTimer
      #define selectorId selectorId_cancelretransmissionTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout <<  Log::endl; }
          delete i->second;
          timerData.erase(i++);
          reschedule = true;
        }
        else {
          i++;
        }
      }
      if (reschedule) {
        if (true) { maceout << "calling TimerHandler::cancel on " << getId() << Log::endl; }
        TimerHandler::cancel();
        if(!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    void cancel(MaceKey const & p0, MessageInfoPtr const & p1) {
      #define selector selector_cancelretransmissionTimer
      #define selectorId selectorId_cancelretransmissionTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout << ", p1="; mace::printItem(maceout, &p1); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0) && (temptd->p1 == p1)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout <<  Log::endl; }
          delete i->second;
          timerData.erase(i++);
          reschedule = true;
        }
        else {
          i++;
        }
      }
      if (reschedule) {
        if (true) { maceout << "calling TimerHandler::cancel on " << getId() << Log::endl; }
        TimerHandler::cancel();
        if(!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    MaceTime nextScheduled() const {
      return timerData.empty()?0:timerData.begin()->first;
    }
    bool isScheduled(const MaceTime& expireTime) const { return timerData.containsKey(expireTime.time()); }
    size_t scheduledCount() const { return timerData.size(); }
    
    void print(mace::PrintNode& __printer, const std::string& __name) const {
      
      mace::PrintNode __tpr("retransmissionTimer", "timer");
      size_t pos = 0;
      for (mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        mace::PrintNode __pr(StrUtil::toString(pos), "TimerData");
        TimerData* td __attribute((unused)) = i->second;
        mace::printItem(__pr, "scheduled", &(i->first));
        mace::printItem(__pr, "p0", &td->p0);
        mace::printItem(__pr, "p1", &td->p1);
        pos++;
        __tpr.addChild(__pr);
      }
      __printer.addChild(__tpr);
      
    }
    void print(std::ostream& __out) const {
      
      __out << "timer<retransmissionTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled=" << i->first << ", p0="; mace::printItem(__out, &td->p0); __out << ", p1="; mace::printItem(__out, &td->p1); __out <<  "]";
          }
          __out << ")";
      
    }
    void printState(std::ostream& __out) const {
      
      __out << "timer<retransmissionTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled" << ", p0="; mace::printState(__out, &td->p0, td->p0); __out << ", p1="; mace::printState(__out, &td->p1, td->p1); __out <<  "]";
          }
          __out << ")";
      
    }
    
    
    protected:
    void expire() {
      #define selector selector_expireretransmissionTimer
      #define selectorId selectorId_expireretransmissionTimer
      PREPARE_FUNCTION
      
      ADD_LOG_BACKING
      //ScopedLock __scopedLock(BaseMaceService::agentlock);
      mace::ContextLock __lock(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE); // Run timers in exclusive mode for now. XXX
      maceout<<"ticket = "<< ThreadStructure::myTicket() <<Log::endl;
      
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true,
          true && mace::LogicalClock::instance().shouldLogPath(), PIP && !1);
      
      if (!isRunning()) {
        return;
      }
      
      clearRunning();
      
      
      ASSERT(!timerData.empty());
      if (1 && Scheduler::simulated()) {
        unsigned ntimers = RandomUtil::randInt(timerData.size()) + 1;
        if (true) { maceout << "firing " << ntimers << " random timers" << Log::endl; }
        std::vector<std::pair<uint64_t, TimerData*> > toFire;
        mace::map<uint64_t, TimerData*, mace::SoftState> copy = timerData;
        for (unsigned i = 0; i < ntimers; i++) {
          unsigned which = RandomUtil::randInt(copy.size());
          mace::map<uint64_t, TimerData*, mace::SoftState>::iterator mi = copy.begin();
          for (unsigned j = 0; j < which; j++) {
            mi++;
          }
          toFire.push_back(*mi);
          if (true) { maceout << "selecting " << mi->first << Log::endl; }
          copy.erase(mi);
        }
        for (std::vector<std::pair<uint64_t, TimerData*> >::iterator i = toFire.begin();
            i != toFire.end(); i++) {
          if (timerData.containsKey(i->first)) {
            TimerData* temptd = i->second;
            ANNOTATE_SET_PATH_ID(NULL, 0, temptd->pipPathId, temptd->pipPathIdLen);
            ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            timerData.erase(i->first);
            if (true) { maceout << "firing " << i->first << Log::endl; }
            agent_->expire_retransmissionTimer(temptd->p0, temptd->p1);
            delete temptd;
          }
          else {
            if (true) { maceout << i->first << " canceled!" << Log::endl; }
          }
        }
      }
      else {
        mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
        int trueWeight = 1;
        int falseWeight = 0;
        while((i != timerData.end()) && MaceTime(i->first - Scheduler::CLOCK_RESOLUTION).lessThan(curtime, trueWeight, falseWeight)) {
          TimerData* temptd = i->second;
          timerData.erase(i);
          if (true) { macecompiler(0) << "calling expire into service for retransmissionTimer " << i->first <<  Log::endl; }
          agent_->expire_retransmissionTimer(temptd->p0, temptd->p1);
          delete temptd;
          i = timerData.begin();
          trueWeight = 0;
          falseWeight = 1;
        }
      }
      if (!timerData.empty() && !TimerHandler::isScheduled()) {
        if (true) { maceout << "calling resched for " << timerData.begin()->first << Log::endl; }
        TimerHandler::schedule(timerData.begin()->first, true);
      }
      else if (timerData.empty() && TimerHandler::isScheduled()) {
        if (true) { maceout << "canceling already expired timer" <<Log::endl; }
        TimerHandler::cancel();
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    protected:
    MaceTransportService *agent_;
    
    
    class TimerData {
      
      public:
      char* pipPathId;
      int pipPathIdLen;
      TimerData() : pipPathId(NULL), pipPathIdLen(0) { }
      ~TimerData() { ::free(pipPathId); }
      TimerData(MaceKey const & p0, MessageInfoPtr const & p1) : p0(p0), p1(p1){ }
      MaceKey p0;
      MessageInfoPtr p1;
    };
    
    mace::map<uint64_t, TimerData*, mace::SoftState> timerData;
  };
  
  class MaceTransportService::localTimer_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    localTimer_MaceTimer(MaceTransportService *a)
    : TimerHandler("MaceTransportService::localTimer", 1), agent_(a)
    {
    }
    
    virtual ~localTimer_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    MaceTime schedule(const MaceTime& interval , std::string const & p0, registration_uid_t const & p1) {
      #define selector selector_schedulelocalTimer
      #define selectorId selectorId_schedulelocalTimer
      PREPARE_FUNCTION
      
      TimerData* td = new TimerData(p0, p1);
      td->pipPathId = annotate_get_path_id_copy(&td->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      //	  TimerData* td = new TimerData(p0, p1);
      uint64_t t = mace::getmtime() + interval.time();
      if (0 && Scheduler::simulated()) {
        t = mace::getmtime();
      }
      // maceout << "interval=" << interval << " t=" << t << Log::endl;
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(t);
      while(i != timerData.end() && i->first == t) {
        // maceout << "found duplicate timer scheduled for " << t << Log::endl;
        i++;
        t++;
      }
      // 	  std::cerr << "assigning timer to " << t << std::endl;
      timerData[t] = td;
      if (timerData.begin()->first == t) {
        TimerHandler::cancel();
        if (true) { maceout << "calling schedule for " << t << Log::endl; }
        ASSERT(TimerHandler::schedule(t, true) == t);
      }
      return t;
      
      #undef selector
      #undef selectorId
    }
    
    void cancel() {
      #define selector selector_cancellocalTimer
      #define selectorId selectorId_cancellocalTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      TimerHandler::cancel();
      maceout << "canceling all timers" << Log::endl;
      for(mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin(); i != timerData.end(); i++) {
        delete i->second;
      }
      // maceout << "clearing timerData" << Log::endl;
      timerData.clear();
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(const MaceTime& expireTime) {
      #define selector selector_cancellocalTimer
      #define selectorId selectorId_cancellocalTimer
      
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer at " << expireTime << Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(expireTime.time());
      if (i == timerData.end()) {
        if (true) { maceout << "timer not found, returning" << Log::endl; }
        return;
      }
      delete i->second;
      if (i == timerData.begin()) {
        if (true) { maceout << "calling TimerHandler::cancel on" << getId() << Log::endl; }
        TimerHandler::cancel();
        timerData.erase(i);
        if (!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      else {
        if (true) { maceout << "erasing from timerData " << i->first << Log::endl; }
        timerData.erase(i);
      }
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(std::string const & p0) {
      #define selector selector_cancellocalTimer
      #define selectorId selectorId_cancellocalTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout <<  Log::endl; }
          delete i->second;
          timerData.erase(i++);
          reschedule = true;
        }
        else {
          i++;
        }
      }
      if (reschedule) {
        if (true) { maceout << "calling TimerHandler::cancel on " << getId() << Log::endl; }
        TimerHandler::cancel();
        if(!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    void cancel(std::string const & p0, registration_uid_t const & p1) {
      #define selector selector_cancellocalTimer
      #define selectorId selectorId_cancellocalTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout << ", p1="; mace::printItem(maceout, &p1); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0) && (temptd->p1 == p1)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout <<  Log::endl; }
          delete i->second;
          timerData.erase(i++);
          reschedule = true;
        }
        else {
          i++;
        }
      }
      if (reschedule) {
        if (true) { maceout << "calling TimerHandler::cancel on " << getId() << Log::endl; }
        TimerHandler::cancel();
        if(!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    MaceTime nextScheduled() const {
      return timerData.empty()?0:timerData.begin()->first;
    }
    bool isScheduled(const MaceTime& expireTime) const { return timerData.containsKey(expireTime.time()); }
    size_t scheduledCount() const { return timerData.size(); }
    
    void print(mace::PrintNode& __printer, const std::string& __name) const {
      
      mace::PrintNode __tpr("localTimer", "timer");
      size_t pos = 0;
      for (mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        mace::PrintNode __pr(StrUtil::toString(pos), "TimerData");
        TimerData* td __attribute((unused)) = i->second;
        mace::printItem(__pr, "scheduled", &(i->first));
        mace::printItem(__pr, "p0", &td->p0);
        mace::printItem(__pr, "p1", &td->p1);
        pos++;
        __tpr.addChild(__pr);
      }
      __printer.addChild(__tpr);
      
    }
    void print(std::ostream& __out) const {
      
      __out << "timer<localTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled=" << i->first << ", p0="; mace::printItem(__out, &td->p0); __out << ", p1="; mace::printItem(__out, &td->p1); __out <<  "]";
          }
          __out << ")";
      
    }
    void printState(std::ostream& __out) const {
      
      __out << "timer<localTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled" << ", p0="; mace::printState(__out, &td->p0, td->p0); __out << ", p1="; mace::printState(__out, &td->p1, td->p1); __out <<  "]";
          }
          __out << ")";
      
    }
    
    void serialize(std::string& __str) const {
      
      uint32_t sz = timerData.size();
      mace::serialize(__str, &sz);
      for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        uint64_t key = i->first;
        mace::serialize(__str, &key);
        TimerData* td __attribute((unused)) = i->second;
        mace::serialize(__str, &td->p0);mace::serialize(__str, &td->p1);
      }
      
    }
    int deserialize(std::istream& __in) {
      
      int serializedByteSize = 0;
      uint32_t sz;
      serializedByteSize += sizeof(sz);
      mace::deserialize(__in, &sz);
      
      for(size_t i = 0; i < sz; i++) {
        uint64_t key;
        serializedByteSize += mace::deserialize(__in, &key);
        std::string p0;
        registration_uid_t p1;;
        serializedByteSize += mace::deserialize(__in, &p0);serializedByteSize += mace::deserialize(__in, &p1);
        TimerData* td = new TimerData(p0, p1);
        timerData[key] = td;
      }
      return serializedByteSize;
      
    }
    
    
    protected:
    void expire() {
      #define selector selector_expirelocalTimer
      #define selectorId selectorId_expirelocalTimer
      PREPARE_FUNCTION
      
      ADD_LOG_BACKING
      //ScopedLock __scopedLock(BaseMaceService::agentlock);
      mace::ContextLock __lock(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE); // Run timers in exclusive mode for now. XXX
      maceout<<"ticket = "<< ThreadStructure::myTicket() <<Log::endl;
      
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true,
          true && mace::LogicalClock::instance().shouldLogPath(), PIP && !1);
      
      if (!isRunning()) {
        return;
      }
      
      clearRunning();
      
      
      ASSERT(!timerData.empty());
      if (0 && Scheduler::simulated()) {
        unsigned ntimers = RandomUtil::randInt(timerData.size()) + 1;
        if (true) { maceout << "firing " << ntimers << " random timers" << Log::endl; }
        std::vector<std::pair<uint64_t, TimerData*> > toFire;
        mace::map<uint64_t, TimerData*, mace::SoftState> copy = timerData;
        for (unsigned i = 0; i < ntimers; i++) {
          unsigned which = RandomUtil::randInt(copy.size());
          mace::map<uint64_t, TimerData*, mace::SoftState>::iterator mi = copy.begin();
          for (unsigned j = 0; j < which; j++) {
            mi++;
          }
          toFire.push_back(*mi);
          if (true) { maceout << "selecting " << mi->first << Log::endl; }
          copy.erase(mi);
        }
        for (std::vector<std::pair<uint64_t, TimerData*> >::iterator i = toFire.begin();
            i != toFire.end(); i++) {
          if (timerData.containsKey(i->first)) {
            TimerData* temptd = i->second;
            ANNOTATE_SET_PATH_ID(NULL, 0, temptd->pipPathId, temptd->pipPathIdLen);
            ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            timerData.erase(i->first);
            if (true) { maceout << "firing " << i->first << Log::endl; }
            agent_->expire_localTimer(temptd->p0, temptd->p1);
            delete temptd;
          }
          else {
            if (true) { maceout << i->first << " canceled!" << Log::endl; }
          }
        }
      }
      else {
        mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
        int trueWeight = 1;
        int falseWeight = 0;
        while((i != timerData.end()) && MaceTime(i->first - Scheduler::CLOCK_RESOLUTION).lessThan(curtime, trueWeight, falseWeight)) {
          TimerData* temptd = i->second;
          timerData.erase(i);
          if (true) { macecompiler(0) << "calling expire into service for localTimer " << i->first <<  Log::endl; }
          agent_->expire_localTimer(temptd->p0, temptd->p1);
          delete temptd;
          i = timerData.begin();
          trueWeight = 0;
          falseWeight = 1;
        }
      }
      if (!timerData.empty() && !TimerHandler::isScheduled()) {
        if (true) { maceout << "calling resched for " << timerData.begin()->first << Log::endl; }
        TimerHandler::schedule(timerData.begin()->first, true);
      }
      else if (timerData.empty() && TimerHandler::isScheduled()) {
        if (true) { maceout << "canceling already expired timer" <<Log::endl; }
        TimerHandler::cancel();
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    protected:
    MaceTransportService *agent_;
    
    
    class TimerData {
      
      public:
      char* pipPathId;
      int pipPathIdLen;
      TimerData() : pipPathId(NULL), pipPathIdLen(0) { }
      ~TimerData() { ::free(pipPathId); }
      TimerData(std::string const & p0, registration_uid_t const & p1) : p0(p0), p1(p1){ }
      std::string p0;
      registration_uid_t p1;
    };
    
    mace::map<uint64_t, TimerData*, mace::SoftState> timerData;
  };
  
  class MaceTransportService::ctsTimer_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    ctsTimer_MaceTimer(MaceTransportService *a)
    : TimerHandler("MaceTransportService::ctsTimer", 1), agent_(a)
    {
    }
    
    virtual ~ctsTimer_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    MaceTime schedule(const MaceTime& interval , MaceKey const & p0) {
      #define selector selector_schedulectsTimer
      #define selectorId selectorId_schedulectsTimer
      PREPARE_FUNCTION
      
      TimerData* td = new TimerData(p0);
      td->pipPathId = annotate_get_path_id_copy(&td->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      //	  TimerData* td = new TimerData(p0);
      uint64_t t = mace::getmtime() + interval.time();
      if (0 && Scheduler::simulated()) {
        t = mace::getmtime();
      }
      // maceout << "interval=" << interval << " t=" << t << Log::endl;
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(t);
      while(i != timerData.end() && i->first == t) {
        // maceout << "found duplicate timer scheduled for " << t << Log::endl;
        i++;
        t++;
      }
      // 	  std::cerr << "assigning timer to " << t << std::endl;
      timerData[t] = td;
      if (timerData.begin()->first == t) {
        TimerHandler::cancel();
        if (true) { maceout << "calling schedule for " << t << Log::endl; }
        ASSERT(TimerHandler::schedule(t, true) == t);
      }
      return t;
      
      #undef selector
      #undef selectorId
    }
    
    void cancel() {
      #define selector selector_cancelctsTimer
      #define selectorId selectorId_cancelctsTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      TimerHandler::cancel();
      maceout << "canceling all timers" << Log::endl;
      for(mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin(); i != timerData.end(); i++) {
        delete i->second;
      }
      // maceout << "clearing timerData" << Log::endl;
      timerData.clear();
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(const MaceTime& expireTime) {
      #define selector selector_cancelctsTimer
      #define selectorId selectorId_cancelctsTimer
      
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer at " << expireTime << Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(expireTime.time());
      if (i == timerData.end()) {
        if (true) { maceout << "timer not found, returning" << Log::endl; }
        return;
      }
      delete i->second;
      if (i == timerData.begin()) {
        if (true) { maceout << "calling TimerHandler::cancel on" << getId() << Log::endl; }
        TimerHandler::cancel();
        timerData.erase(i);
        if (!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      else {
        if (true) { maceout << "erasing from timerData " << i->first << Log::endl; }
        timerData.erase(i);
      }
      
      #undef selector
      #undef selectorId
    }
    
    void cancel(MaceKey const & p0) {
      #define selector selector_cancelctsTimer
      #define selectorId selectorId_cancelctsTimer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout <<  Log::endl; }
          delete i->second;
          timerData.erase(i++);
          reschedule = true;
        }
        else {
          i++;
        }
      }
      if (reschedule) {
        if (true) { maceout << "calling TimerHandler::cancel on " << getId() << Log::endl; }
        TimerHandler::cancel();
        if(!timerData.empty()) {
          if (true) { maceout << "calling schedule for " << timerData.begin()->first << Log::endl; }
          TimerHandler::schedule(timerData.begin()->first, true);
        }
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    MaceTime nextScheduled() const {
      return timerData.empty()?0:timerData.begin()->first;
    }
    bool isScheduled(const MaceTime& expireTime) const { return timerData.containsKey(expireTime.time()); }
    size_t scheduledCount() const { return timerData.size(); }
    
    void print(mace::PrintNode& __printer, const std::string& __name) const {
      
      mace::PrintNode __tpr("ctsTimer", "timer");
      size_t pos = 0;
      for (mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        mace::PrintNode __pr(StrUtil::toString(pos), "TimerData");
        TimerData* td __attribute((unused)) = i->second;
        mace::printItem(__pr, "scheduled", &(i->first));
        mace::printItem(__pr, "p0", &td->p0);
        pos++;
        __tpr.addChild(__pr);
      }
      __printer.addChild(__tpr);
      
    }
    void print(std::ostream& __out) const {
      
      __out << "timer<ctsTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled=" << i->first << ", p0="; mace::printItem(__out, &td->p0); __out <<  "]";
          }
          __out << ")";
      
    }
    void printState(std::ostream& __out) const {
      
      __out << "timer<ctsTimer>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled" << ", p0="; mace::printState(__out, &td->p0, td->p0); __out <<  "]";
          }
          __out << ")";
      
    }
    
    void serialize(std::string& __str) const {
      
      uint32_t sz = timerData.size();
      mace::serialize(__str, &sz);
      for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        uint64_t key = i->first;
        mace::serialize(__str, &key);
        TimerData* td __attribute((unused)) = i->second;
        mace::serialize(__str, &td->p0);
      }
      
    }
    int deserialize(std::istream& __in) {
      
      int serializedByteSize = 0;
      uint32_t sz;
      serializedByteSize += sizeof(sz);
      mace::deserialize(__in, &sz);
      
      for(size_t i = 0; i < sz; i++) {
        uint64_t key;
        serializedByteSize += mace::deserialize(__in, &key);
        MaceKey p0;;
        serializedByteSize += mace::deserialize(__in, &p0);
        TimerData* td = new TimerData(p0);
        timerData[key] = td;
      }
      return serializedByteSize;
      
    }
    
    
    protected:
    void expire() {
      #define selector selector_expirectsTimer
      #define selectorId selectorId_expirectsTimer
      PREPARE_FUNCTION
      
      ADD_LOG_BACKING
      //ScopedLock __scopedLock(BaseMaceService::agentlock);
      mace::ContextLock __lock(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE); // Run timers in exclusive mode for now. XXX
      maceout<<"ticket = "<< ThreadStructure::myTicket() <<Log::endl;
      
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true,
          true && mace::LogicalClock::instance().shouldLogPath(), PIP && !1);
      
      if (!isRunning()) {
        return;
      }
      
      clearRunning();
      
      
      ASSERT(!timerData.empty());
      if (0 && Scheduler::simulated()) {
        unsigned ntimers = RandomUtil::randInt(timerData.size()) + 1;
        if (true) { maceout << "firing " << ntimers << " random timers" << Log::endl; }
        std::vector<std::pair<uint64_t, TimerData*> > toFire;
        mace::map<uint64_t, TimerData*, mace::SoftState> copy = timerData;
        for (unsigned i = 0; i < ntimers; i++) {
          unsigned which = RandomUtil::randInt(copy.size());
          mace::map<uint64_t, TimerData*, mace::SoftState>::iterator mi = copy.begin();
          for (unsigned j = 0; j < which; j++) {
            mi++;
          }
          toFire.push_back(*mi);
          if (true) { maceout << "selecting " << mi->first << Log::endl; }
          copy.erase(mi);
        }
        for (std::vector<std::pair<uint64_t, TimerData*> >::iterator i = toFire.begin();
            i != toFire.end(); i++) {
          if (timerData.containsKey(i->first)) {
            TimerData* temptd = i->second;
            ANNOTATE_SET_PATH_ID(NULL, 0, temptd->pipPathId, temptd->pipPathIdLen);
            ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            timerData.erase(i->first);
            if (true) { maceout << "firing " << i->first << Log::endl; }
            agent_->expire_ctsTimer(temptd->p0);
            delete temptd;
          }
          else {
            if (true) { maceout << i->first << " canceled!" << Log::endl; }
          }
        }
      }
      else {
        mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
        int trueWeight = 1;
        int falseWeight = 0;
        while((i != timerData.end()) && MaceTime(i->first - Scheduler::CLOCK_RESOLUTION).lessThan(curtime, trueWeight, falseWeight)) {
          TimerData* temptd = i->second;
          timerData.erase(i);
          if (true) { macecompiler(0) << "calling expire into service for ctsTimer " << i->first <<  Log::endl; }
          agent_->expire_ctsTimer(temptd->p0);
          delete temptd;
          i = timerData.begin();
          trueWeight = 0;
          falseWeight = 1;
        }
      }
      if (!timerData.empty() && !TimerHandler::isScheduled()) {
        if (true) { maceout << "calling resched for " << timerData.begin()->first << Log::endl; }
        TimerHandler::schedule(timerData.begin()->first, true);
      }
      else if (timerData.empty() && TimerHandler::isScheduled()) {
        if (true) { maceout << "canceling already expired timer" <<Log::endl; }
        TimerHandler::cancel();
      }
      
      #undef selector
      #undef selectorId
    }
    
    
    protected:
    MaceTransportService *agent_;
    
    
    class TimerData {
      
      public:
      char* pipPathId;
      int pipPathIdLen;
      TimerData() : pipPathId(NULL), pipPathIdLen(0) { }
      ~TimerData() { ::free(pipPathId); }
      TimerData(MaceKey const & p0) : p0(p0){ }
      MaceKey p0;
    };
    
    mace::map<uint64_t, TimerData*, mace::SoftState> timerData;
  };
  
  //END: Mace::Compiler::ServiceImpl::printTimerClasses
  class ConnectionInfo_updateRTODummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceTime* _ts;
    const MaceTime& ts;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_ConnectionInfo_updateRTO";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::updateRTO( const MaceTime& ts)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    ConnectionInfo_updateRTODummy() : _ts(new MaceTime()), ts(*_ts) { }
    
    
    ConnectionInfo_updateRTODummy(const MaceTime& ___ts) : _ts(NULL), ts(___ts) { }
    
    
    ~ConnectionInfo_updateRTODummy() {
      if (_ts != NULL) { delete _ts; _ts = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "updateRTO(";
          out << "[ts=";
          mace::printItem(out, &ts);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ts INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_ts", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _tsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _tsIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&ts, __node->children[0]);
      
    }
  };
  class ConnectionInfo_increaseCWNDDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_ConnectionInfo_increaseCWND";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::increaseCWND()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    ConnectionInfo_increaseCWNDDummy()  { }
    
    
    
    
    ~ConnectionInfo_increaseCWNDDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "increaseCWND(";
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
  class ConnectionInfo_timeoutDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_ConnectionInfo_timeout";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::timeout()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    ConnectionInfo_timeoutDummy()  { }
    
    
    
    
    ~ConnectionInfo_timeoutDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "timeout(";
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
  class OutgoingConnection_canSendDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_canSend";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::canSend() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_canSendDummy()  { }
    
    
    
    
    ~OutgoingConnection_canSendDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "canSend(";
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
  class OutgoingConnection_updateCanSendOnWriteDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    uint64_t* _maxsize;
    const uint64_t& maxsize;
    uint64_t* _threshold;
    const uint64_t& threshold;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_updateCanSendOnWrite";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::updateCanSendOnWrite(uint64_t maxsize, uint64_t threshold)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_updateCanSendOnWriteDummy() : _maxsize(new uint64_t()), maxsize(*_maxsize), _threshold(new uint64_t()), threshold(*_threshold) { }
    
    
    OutgoingConnection_updateCanSendOnWriteDummy(const uint64_t& ___maxsize, const uint64_t& ___threshold) : _maxsize(NULL), maxsize(___maxsize), _threshold(NULL), threshold(___threshold) { }
    
    
    ~OutgoingConnection_updateCanSendOnWriteDummy() {
      if (_maxsize != NULL) { delete _maxsize; _maxsize = NULL; }
      if (_threshold != NULL) { delete _threshold; _threshold = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "updateCanSendOnWrite(";
          out << "[maxsize=";
          mace::printItem(out, &maxsize);
          out << "]";
          out << "[threshold=";
          mace::printItem(out, &threshold);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, maxsize NUMERIC(20, 0), threshold NUMERIC(20, 0));" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << maxsize;
      __out << "\t" << threshold;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class OutgoingConnection_updateCanSendOnEnqueueDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    uint64_t* _maxsize;
    const uint64_t& maxsize;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_updateCanSendOnEnqueue";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::updateCanSendOnEnqueue(uint64_t maxsize)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_updateCanSendOnEnqueueDummy() : _maxsize(new uint64_t()), maxsize(*_maxsize) { }
    
    
    OutgoingConnection_updateCanSendOnEnqueueDummy(const uint64_t& ___maxsize) : _maxsize(NULL), maxsize(___maxsize) { }
    
    
    ~OutgoingConnection_updateCanSendOnEnqueueDummy() {
      if (_maxsize != NULL) { delete _maxsize; _maxsize = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "updateCanSendOnEnqueue(";
          out << "[maxsize=";
          mace::printItem(out, &maxsize);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, maxsize NUMERIC(20, 0));" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << maxsize;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class OutgoingConnection_bufferedDataSizeDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_bufferedDataSize";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::bufferedDataSize() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_bufferedDataSizeDummy()  { }
    
    
    
    
    ~OutgoingConnection_bufferedDataSizeDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "bufferedDataSize(";
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
  class OutgoingConnection_hasQueuedMessagesDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_hasQueuedMessages";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::hasQueuedMessages() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_hasQueuedMessagesDummy()  { }
    
    
    
    
    ~OutgoingConnection_hasQueuedMessagesDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "hasQueuedMessages(";
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
  class OutgoingConnection_queuedMessagesSizeDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_queuedMessagesSize";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::queuedMessagesSize() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_queuedMessagesSizeDummy()  { }
    
    
    
    
    ~OutgoingConnection_queuedMessagesSizeDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "queuedMessagesSize(";
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
  class OutgoingConnection_nextSeqDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_nextSeq";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::nextSeq()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_nextSeqDummy()  { }
    
    
    
    
    ~OutgoingConnection_nextSeqDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "nextSeq(";
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
  class OutgoingConnection_getSynDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_getSyn";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::getSyn()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_getSynDummy()  { }
    
    
    
    
    ~OutgoingConnection_getSynDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "getSyn(";
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
  class OutgoingConnection_setLastDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    seq_t* _s;
    const seq_t& s;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_setLast";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::setLast(seq_t s)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_setLastDummy() : _s(new seq_t()), s(*_s) { }
    
    
    OutgoingConnection_setLastDummy(const seq_t& ___s) : _s(NULL), s(___s) { }
    
    
    ~OutgoingConnection_setLastDummy() {
      if (_s != NULL) { delete _s; _s = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "setLast(";
          out << "[s=";
          mace::printItem(out, &s);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, s INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_s", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _sIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _sIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&s, __node->children[0]);
      
    }
  };
  class OutgoingConnection_fastRetransmitDummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_OutgoingConnection_fastRetransmit";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::fastRetransmit() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    OutgoingConnection_fastRetransmitDummy()  { }
    
    
    
    
    ~OutgoingConnection_fastRetransmitDummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "fastRetransmit(";
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
  class canSend48Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _peer;
    const MaceKey& peer;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_canSend48";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::canSend( const MaceKey& peer, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    canSend48Dummy() : _peer(new MaceKey()), peer(*_peer), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    canSend48Dummy(const MaceKey& ___peer, const registration_uid_t& ___rid) : _peer(NULL), peer(___peer), _rid(NULL), rid(___rid) { }
    
    
    ~canSend48Dummy() {
      if (_peer != NULL) { delete _peer; _peer = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "canSend(";
          out << "[peer=";
          mace::printItem(out, &peer);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, peer INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_peer", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _peerIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _peerIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&peer, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class outgoingBufferedDataSize50Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _peer;
    const MaceKey& peer;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_outgoingBufferedDataSize50";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::outgoingBufferedDataSize( const MaceKey& peer, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    outgoingBufferedDataSize50Dummy() : _peer(new MaceKey()), peer(*_peer), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    outgoingBufferedDataSize50Dummy(const MaceKey& ___peer, const registration_uid_t& ___rid) : _peer(NULL), peer(___peer), _rid(NULL), rid(___rid) { }
    
    
    ~outgoingBufferedDataSize50Dummy() {
      if (_peer != NULL) { delete _peer; _peer = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "outgoingBufferedDataSize(";
          out << "[peer=";
          mace::printItem(out, &peer);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, peer INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_peer", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _peerIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _peerIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&peer, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class setWindowSize54Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _peer;
    const MaceKey& peer;
    uint64_t* _microsec;
    const uint64_t& microsec;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_setWindowSize54";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::setWindowSize( const MaceKey& peer, uint64_t microsec, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    setWindowSize54Dummy() : _peer(new MaceKey()), peer(*_peer), _microsec(new uint64_t()), microsec(*_microsec), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    setWindowSize54Dummy(const MaceKey& ___peer, const uint64_t& ___microsec, const registration_uid_t& ___rid) : _peer(NULL), peer(___peer), _microsec(NULL), microsec(___microsec), _rid(NULL), rid(___rid) { }
    
    
    ~setWindowSize54Dummy() {
      if (_peer != NULL) { delete _peer; _peer = NULL; }
      if (_microsec != NULL) { delete _microsec; _microsec = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "setWindowSize(";
          out << "[peer=";
          mace::printItem(out, &peer);
          out << "]";
          out << "[microsec=";
          mace::printItem(out, &microsec);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, peer INT, microsec NUMERIC(20, 0), rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_peer", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _peerIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _peerIndex;
      __out << "\t" << microsec;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&peer, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class getStatistics56Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _peer;
    const MaceKey& peer;
    TransportServiceClass::Connection::type* _d;
    const TransportServiceClass::Connection::type& d;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_getStatistics56";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::getStatistics( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    getStatistics56Dummy() : _peer(new MaceKey()), peer(*_peer), _d(new TransportServiceClass::Connection::type()), d(*_d), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    getStatistics56Dummy(const MaceKey& ___peer, const TransportServiceClass::Connection::type& ___d, const registration_uid_t& ___rid) : _peer(NULL), peer(___peer), _d(NULL), d(___d), _rid(NULL), rid(___rid) { }
    
    
    ~getStatistics56Dummy() {
      if (_peer != NULL) { delete _peer; _peer = NULL; }
      if (_d != NULL) { delete _d; _d = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "getStatistics(";
          out << "[peer=";
          mace::printItem(out, &peer);
          out << "]";
          out << "[d=";
          mace::printItem(out, &d);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, peer INT, d INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_peer", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_d", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _peerIndex = __node->children[0]->nextId;
      int _dIndex = __node->children[1]->nextId;
      int _ridIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _peerIndex;
      __out << "\t" << _dIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&peer, __node->children[0]);
      mace::sqlize(&d, __node->children[1]);
      mace::sqlize(&rid, __node->children[2]);
      
    }
  };
  class requestToSend57Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _peer;
    const MaceKey& peer;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_requestToSend57";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::requestToSend( const MaceKey& peer, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    requestToSend57Dummy() : _peer(new MaceKey()), peer(*_peer), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    requestToSend57Dummy(const MaceKey& ___peer, const registration_uid_t& ___rid) : _peer(NULL), peer(___peer), _rid(NULL), rid(___rid) { }
    
    
    ~requestToSend57Dummy() {
      if (_peer != NULL) { delete _peer; _peer = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "requestToSend(";
          out << "[peer=";
          mace::printItem(out, &peer);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, peer INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_peer", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _peerIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _peerIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&peer, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class hasBufferedData59Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_hasBufferedData59";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::hasBufferedData(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hasBufferedData59Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    hasBufferedData59Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~hasBufferedData59Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "hasBufferedData(";
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
  class hasOutgoingBufferedData60Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_hasOutgoingBufferedData60";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::hasOutgoingBufferedData(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hasOutgoingBufferedData60Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    hasOutgoingBufferedData60Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~hasOutgoingBufferedData60Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "hasOutgoingBufferedData(";
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
  class outgoingBufferedDataSize61Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_outgoingBufferedDataSize61";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::outgoingBufferedDataSize(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    outgoingBufferedDataSize61Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    outgoingBufferedDataSize61Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~outgoingBufferedDataSize61Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "outgoingBufferedDataSize(";
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
  class routeRTS62Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_routeRTS62";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::routeRTS( const MaceKey& dest,  const std::string& s, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    routeRTS62Dummy() : _dest(new MaceKey()), dest(*_dest), _s(new std::string()), s(*_s), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    routeRTS62Dummy(const MaceKey& ___dest, const std::string& ___s, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s(NULL), s(___s), _rid(NULL), rid(___rid) { }
    
    
    ~routeRTS62Dummy() {
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
      out << "routeRTS(";
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
  class requestFlushedNotification64Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_requestFlushedNotification64";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::requestFlushedNotification(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    requestFlushedNotification64Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    requestFlushedNotification64Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~requestFlushedNotification64Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "requestFlushedNotification(";
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
  class route65Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_route65";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route65Dummy() : _dest(new MaceKey()), dest(*_dest), _s(new std::string()), s(*_s), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route65Dummy(const MaceKey& ___dest, const std::string& ___s, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s(NULL), s(___s), _rid(NULL), rid(___rid) { }
    
    
    ~route65Dummy() {
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
  class maceInit71Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_maceInit71";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::maceInit()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceInit71Dummy()  { }
    
    
    
    
    ~maceInit71Dummy() {
      
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
  class maceReset74Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_maceReset74";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::maceReset()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceReset74Dummy()  { }
    
    
    
    
    ~maceReset74Dummy() {
      
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
  class hashState76Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_hashState76";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::hashState() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hashState76Dummy()  { }
    
    
    
    
    ~hashState76Dummy() {
      
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
  class deliver78Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_deliver78";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver78Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver78Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver78Dummy() {
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
  class deliver79Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    DataFragment* _s_deserialized;
    const DataFragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_deliver79";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliver( const MaceKey& source,  const MaceKey& destination,  const DataFragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver79Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new DataFragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver79Dummy(const MaceKey& ___source, const MaceKey& ___destination, const DataFragment& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver79Dummy() {
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
  class deliver80Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    Fragment* _s_deserialized;
    const Fragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_deliver80";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliver( const MaceKey& source,  const MaceKey& destination,  const Fragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver80Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Fragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver80Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Fragment& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver80Dummy() {
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
  class deliver81Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    Ack* _s_deserialized;
    const Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_deliver81";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliver( const MaceKey& source,  const MaceKey& destination,  const Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver81Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver81Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Ack& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver81Dummy() {
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
  class deliver82Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    Reset* _s_deserialized;
    const Reset& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_deliver82";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliver( const MaceKey& source,  const MaceKey& destination,  const Reset& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver82Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Reset()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver82Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Reset& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver82Dummy() {
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
  class messageError83Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_messageError83";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError83Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Data()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError83Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Data& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError83Dummy() {
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
  class messageError84Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    DataFragment* _message_deserialized;
    const DataFragment& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_messageError84";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::messageError( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError84Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new DataFragment()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError84Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const DataFragment& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError84Dummy() {
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
  class messageError85Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    Fragment* _message_deserialized;
    const Fragment& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_messageError85";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::messageError( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError85Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Fragment()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError85Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Fragment& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError85Dummy() {
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
  class messageError86Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    Ack* _message_deserialized;
    const Ack& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_messageError86";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::messageError( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError86Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Ack()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError86Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Ack& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError86Dummy() {
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
  class messageError87Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    Reset* _message_deserialized;
    const Reset& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_messageError87";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::messageError( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError87Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Reset()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError87Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Reset& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError87Dummy() {
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
  class expire_retransmissionTimer88Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _p0;
    const MaceKey& p0;
    MessageInfoPtr* _p1;
    const MessageInfoPtr& p1;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_expire_retransmissionTimer88";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::expire_retransmissionTimer(MaceKey& p0, MessageInfoPtr& p1)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_retransmissionTimer88Dummy() : _p0(new MaceKey()), p0(*_p0), _p1(new MessageInfoPtr()), p1(*_p1) { }
    
    
    expire_retransmissionTimer88Dummy(const MaceKey& ___p0, const MessageInfoPtr& ___p1) : _p0(NULL), p0(___p0), _p1(NULL), p1(___p1) { }
    
    
    ~expire_retransmissionTimer88Dummy() {
      if (_p0 != NULL) { delete _p0; _p0 = NULL; }
      if (_p1 != NULL) { delete _p1; _p1 = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "expire_retransmissionTimer(";
          out << "[p0=";
          mace::printItem(out, &p0);
          out << "]";
          out << "[p1=";
          mace::printItem(out, &p1);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, p0 INT, p1 INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_p0", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_p1", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _p0Index = __node->children[0]->nextId;
      int _p1Index = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _p0Index;
      __out << "\t" << _p1Index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&p0, __node->children[0]);
      mace::sqlize(&p1, __node->children[1]);
      
    }
  };
  class expire_localTimer89Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    std::string* _p0;
    const std::string& p0;
    registration_uid_t* _p1;
    const registration_uid_t& p1;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_expire_localTimer89";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::expire_localTimer(std::string& p0, registration_uid_t& p1)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_localTimer89Dummy() : _p0(new std::string()), p0(*_p0), _p1(new registration_uid_t()), p1(*_p1) { }
    
    
    expire_localTimer89Dummy(const std::string& ___p0, const registration_uid_t& ___p1) : _p0(NULL), p0(___p0), _p1(NULL), p1(___p1) { }
    
    
    ~expire_localTimer89Dummy() {
      if (_p0 != NULL) { delete _p0; _p0 = NULL; }
      if (_p1 != NULL) { delete _p1; _p1 = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "expire_localTimer(";
          out << "[p0=";
          mace::printItem(out, &p0);
          out << "]";
          out << "[p1=";
          mace::printItem(out, &p1);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, p0 TEXT, p1 INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_p1", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _p1Index = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(p0)) {
        __out << p0;
      }
      else {
        __out << HashString::hash(p0);
      }
      __out << "\t" << _p1Index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&p1, __node->children[0]);
      
    }
  };
  class expire_ctsTimer90Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _p0;
    const MaceKey& p0;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_expire_ctsTimer90";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::expire_ctsTimer(MaceKey& p0)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_ctsTimer90Dummy() : _p0(new MaceKey()), p0(*_p0) { }
    
    
    expire_ctsTimer90Dummy(const MaceKey& ___p0) : _p0(NULL), p0(___p0) { }
    
    
    ~expire_ctsTimer90Dummy() {
      if (_p0 != NULL) { delete _p0; _p0 = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "expire_ctsTimer(";
          out << "[p0=";
          mace::printItem(out, &p0);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, p0 INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_p0", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _p0Index = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _p0Index;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&p0, __node->children[0]);
      
    }
  };
  class suspendDeliver23Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_suspendDeliver23";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::suspendDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver23Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver23Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver23Dummy() {
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
  class suspendDeliver24Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_suspendDeliver24";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::suspendDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver24Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver24Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver24Dummy() {
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
  class resumeDeliver25Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_resumeDeliver25";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::resumeDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver25Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver25Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver25Dummy() {
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
  class resumeDeliver26Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_resumeDeliver26";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::resumeDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver26Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver26Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver26Dummy() {
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
  class route27Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route27";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route27Dummy()  { }
    
    
    
    
    ~route27Dummy() {
      
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
  class route28Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_route28";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route28Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route28Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route28Dummy() {
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
  class route29Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    DataFragment* _s_deserialized;
    const DataFragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route29";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route29Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new DataFragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route29Dummy(const MaceKey& ___dest, const DataFragment& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route29Dummy() {
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
  class route30Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Fragment* _s_deserialized;
    const Fragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route30";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route30Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Fragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route30Dummy(const MaceKey& ___dest, const Fragment& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route30Dummy() {
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
  class route31Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Ack* _s_deserialized;
    const Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route31";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route31Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route31Dummy(const MaceKey& ___dest, const Ack& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route31Dummy() {
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
  class route32Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Reset* _s_deserialized;
    const Reset& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route32";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route32Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Reset()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route32Dummy(const MaceKey& ___dest, const Reset& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route32Dummy() {
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
  class route33Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route33";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route33Dummy()  { }
    
    
    
    
    ~route33Dummy() {
      
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
  class route34Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_route34";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route34Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route34Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route34Dummy() {
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
  class route35Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    DataFragment* _s_deserialized;
    const DataFragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route35";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route35Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new DataFragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route35Dummy(const MaceKey& ___src, const MaceKey& ___dest, const DataFragment& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route35Dummy() {
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
  class route36Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    Fragment* _s_deserialized;
    const Fragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route36";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route36Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Fragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route36Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Fragment& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route36Dummy() {
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
  class route37Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    Ack* _s_deserialized;
    const Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route37";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route37Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route37Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Ack& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route37Dummy() {
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
  class route38Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    Reset* _s_deserialized;
    const Reset& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_route38";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::route( const MaceKey& src,  const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route38Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Reset()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route38Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Reset& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route38Dummy() {
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
  class send39Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_send39";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send39Dummy()  { }
    
    
    
    
    ~send39Dummy() {
      
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
  class send40Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "MaceTransport_send40";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send40Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send40Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send40Dummy() {
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
  class send41Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    DataFragment* _s_deserialized;
    const DataFragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_send41";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send41Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new DataFragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send41Dummy(const MaceKey& ___dest, const DataFragment& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send41Dummy() {
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
  class send42Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Fragment* _s_deserialized;
    const Fragment& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_send42";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send42Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Fragment()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send42Dummy(const MaceKey& ___dest, const Fragment& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send42Dummy() {
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
  class send43Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Ack* _s_deserialized;
    const Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_send43";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send43Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send43Dummy(const MaceKey& ___dest, const Ack& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send43Dummy() {
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
  class send44Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    Reset* _s_deserialized;
    const Reset& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_send44";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::send( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send44Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Reset()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send44Dummy(const MaceKey& ___dest, const Reset& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send44Dummy() {
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
  class upcall_notifyFlushed22Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_upcall_notifyFlushed22";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::notifyFlushed(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    upcall_notifyFlushed22Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    upcall_notifyFlushed22Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~upcall_notifyFlushed22Dummy() {
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "notifyFlushed(";
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
  class incrementAcked0Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    uint32_t* _size;
    const uint32_t& size;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_incrementAcked0";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::incrementAcked(OutgoingConnection& c, uint32_t size)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    incrementAcked0Dummy() : _c(new OutgoingConnection()), c(*_c), _size(new uint32_t()), size(*_size) { }
    
    
    incrementAcked0Dummy(const OutgoingConnection& ___c, const uint32_t& ___size) : _c(NULL), c(___c), _size(NULL), size(___size) { }
    
    
    ~incrementAcked0Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_size != NULL) { delete _size; _size = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "incrementAcked(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[size=";
          mace::printItem(out, &size);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT, size INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << "\t" << size;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      
    }
  };
  class closeIncomingConnection1Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    TransportError::type* _error;
    const TransportError::type& error;
    std::string* _errstr;
    const std::string& errstr;
    bool* _upcallError;
    const bool& upcallError;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_closeIncomingConnection1";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::closeIncomingConnection( const MaceKey& src, TransportError::type error,  const std::string& errstr, bool upcallError)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    closeIncomingConnection1Dummy() : _src(new MaceKey()), src(*_src), _error(new TransportError::type()), error(*_error), _errstr(new std::string()), errstr(*_errstr), _upcallError(new bool()), upcallError(*_upcallError) { }
    
    
    closeIncomingConnection1Dummy(const MaceKey& ___src, const TransportError::type& ___error, const std::string& ___errstr, const bool& ___upcallError) : _src(NULL), src(___src), _error(NULL), error(___error), _errstr(NULL), errstr(___errstr), _upcallError(NULL), upcallError(___upcallError) { }
    
    
    ~closeIncomingConnection1Dummy() {
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_error != NULL) { delete _error; _error = NULL; }
      if (_errstr != NULL) { delete _errstr; _errstr = NULL; }
      if (_upcallError != NULL) { delete _upcallError; _upcallError = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "closeIncomingConnection(";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[error=";
          mace::printItem(out, &error);
          out << "]";
          out << "[errstr=";
          mace::printItem(out, &errstr);
          out << "]";
          out << "[upcallError=";
          mace::printItem(out, &upcallError);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, src INT, error INT, errstr TEXT, upcallError INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_error", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _srcIndex = __node->children[0]->nextId;
      int _errorIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _srcIndex;
      __out << "\t" << _errorIndex;
      __out << "\t";
      if (Base64::isPrintable(errstr)) {
        __out << errstr;
      }
      else {
        __out << HashString::hash(errstr);
      }
      __out << "\t" << upcallError;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&src, __node->children[0]);
      mace::sqlize(&error, __node->children[1]);
      
    }
  };
  class closeOutgoingConnection2Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    TransportError::type* _error;
    const TransportError::type& error;
    std::string* _errstr;
    const std::string& errstr;
    bool* _upcallError;
    const bool& upcallError;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_closeOutgoingConnection2";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::closeOutgoingConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr, bool upcallError)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    closeOutgoingConnection2Dummy() : _dest(new MaceKey()), dest(*_dest), _c(new OutgoingConnection()), c(*_c), _error(new TransportError::type()), error(*_error), _errstr(new std::string()), errstr(*_errstr), _upcallError(new bool()), upcallError(*_upcallError) { }
    
    
    closeOutgoingConnection2Dummy(const MaceKey& ___dest, const OutgoingConnection& ___c, const TransportError::type& ___error, const std::string& ___errstr, const bool& ___upcallError) : _dest(NULL), dest(___dest), _c(NULL), c(___c), _error(NULL), error(___error), _errstr(NULL), errstr(___errstr), _upcallError(NULL), upcallError(___upcallError) { }
    
    
    ~closeOutgoingConnection2Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_error != NULL) { delete _error; _error = NULL; }
      if (_errstr != NULL) { delete _errstr; _errstr = NULL; }
      if (_upcallError != NULL) { delete _upcallError; _upcallError = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "closeOutgoingConnection(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[error=";
          mace::printItem(out, &error);
          out << "]";
          out << "[errstr=";
          mace::printItem(out, &errstr);
          out << "]";
          out << "[upcallError=";
          mace::printItem(out, &upcallError);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, c INT, error INT, errstr TEXT, upcallError INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_error", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _cIndex = __node->children[1]->nextId;
      int _errorIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _cIndex;
      __out << "\t" << _errorIndex;
      __out << "\t";
      if (Base64::isPrintable(errstr)) {
        __out << errstr;
      }
      else {
        __out << HashString::hash(errstr);
      }
      __out << "\t" << upcallError;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&c, __node->children[1]);
      mace::sqlize(&error, __node->children[2]);
      
    }
  };
  class closeBidirectionalConnection3Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    TransportError::type* _error;
    const TransportError::type& error;
    std::string* _errstr;
    const std::string& errstr;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_closeBidirectionalConnection3";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::closeBidirectionalConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    closeBidirectionalConnection3Dummy() : _dest(new MaceKey()), dest(*_dest), _c(new OutgoingConnection()), c(*_c), _error(new TransportError::type()), error(*_error), _errstr(new std::string()), errstr(*_errstr) { }
    
    
    closeBidirectionalConnection3Dummy(const MaceKey& ___dest, const OutgoingConnection& ___c, const TransportError::type& ___error, const std::string& ___errstr) : _dest(NULL), dest(___dest), _c(NULL), c(___c), _error(NULL), error(___error), _errstr(NULL), errstr(___errstr) { }
    
    
    ~closeBidirectionalConnection3Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_error != NULL) { delete _error; _error = NULL; }
      if (_errstr != NULL) { delete _errstr; _errstr = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "closeBidirectionalConnection(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[error=";
          mace::printItem(out, &error);
          out << "]";
          out << "[errstr=";
          mace::printItem(out, &errstr);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, c INT, error INT, errstr TEXT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_error", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _cIndex = __node->children[1]->nextId;
      int _errorIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _cIndex;
      __out << "\t" << _errorIndex;
      __out << "\t";
      if (Base64::isPrintable(errstr)) {
        __out << errstr;
      }
      else {
        __out << HashString::hash(errstr);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&c, __node->children[1]);
      mace::sqlize(&error, __node->children[2]);
      
    }
  };
  class deliverBuffered4Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    IncomingConnection* _c;
    const IncomingConnection& c;
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_deliverBuffered4";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::deliverBuffered(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliverBuffered4Dummy() : _c(new IncomingConnection()), c(*_c), _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest) { }
    
    
    deliverBuffered4Dummy(const IncomingConnection& ___c, const MaceKey& ___src, const MaceKey& ___dest) : _c(NULL), c(___c), _src(NULL), src(___src), _dest(NULL), dest(___dest) { }
    
    
    ~deliverBuffered4Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "deliverBuffered(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT, src INT, dest INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      int _srcIndex = __node->children[1]->nextId;
      int _destIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << "\t" << _srcIndex;
      __out << "\t" << _destIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      mace::sqlize(&src, __node->children[1]);
      mace::sqlize(&dest, __node->children[2]);
      
    }
  };
  class upcallDeliver5Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    IncomingConnection* _c;
    const IncomingConnection& c;
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    std::string* _payload;
    const std::string& payload;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_upcallDeliver5";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::upcallDeliver(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest,  const std::string& payload, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    upcallDeliver5Dummy() : _c(new IncomingConnection()), c(*_c), _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _payload(new std::string()), payload(*_payload), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    upcallDeliver5Dummy(const IncomingConnection& ___c, const MaceKey& ___src, const MaceKey& ___dest, const std::string& ___payload, const registration_uid_t& ___rid) : _c(NULL), c(___c), _src(NULL), src(___src), _dest(NULL), dest(___dest), _payload(NULL), payload(___payload), _rid(NULL), rid(___rid) { }
    
    
    ~upcallDeliver5Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_payload != NULL) { delete _payload; _payload = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "upcallDeliver(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[payload=";
          mace::printItem(out, &payload);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT, src INT, dest INT, payload TEXT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[4];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[3] = __child3;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      int _srcIndex = __node->children[1]->nextId;
      int _destIndex = __node->children[2]->nextId;
      int _ridIndex = __node->children[3]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << "\t" << _srcIndex;
      __out << "\t" << _destIndex;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      mace::sqlize(&src, __node->children[1]);
      mace::sqlize(&dest, __node->children[2]);
      mace::sqlize(&rid, __node->children[3]);
      
    }
  };
  class processDeliver10Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    seq_t* _seq;
    const seq_t& seq;
    mace::string* _payload;
    const mace::string& payload;
    uint32_t* _ssize;
    const uint32_t& ssize;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    mace::MonotoneTime* _syn;
    const mace::MonotoneTime& syn;
    mace::MonotoneTime* _synecho;
    const mace::MonotoneTime& synecho;
    uint32_t* _nfrag;
    const uint32_t& nfrag;
    uint32_t* _frag;
    const uint32_t& frag;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_processDeliver10";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::processDeliver( const MaceKey& src,  const MaceKey& dest, seq_t seq, mace::string payload, uint32_t ssize, registration_uid_t rid, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t nfrag, uint32_t frag)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    processDeliver10Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _seq(new seq_t()), seq(*_seq), _payload(new mace::string()), payload(*_payload), _ssize(new uint32_t()), ssize(*_ssize), _rid(new registration_uid_t()), rid(*_rid), _syn(new mace::MonotoneTime()), syn(*_syn), _synecho(new mace::MonotoneTime()), synecho(*_synecho), _nfrag(new uint32_t()), nfrag(*_nfrag), _frag(new uint32_t()), frag(*_frag) { }
    
    
    processDeliver10Dummy(const MaceKey& ___src, const MaceKey& ___dest, const seq_t& ___seq, const mace::string& ___payload, const uint32_t& ___ssize, const registration_uid_t& ___rid, const mace::MonotoneTime& ___syn, const mace::MonotoneTime& ___synecho, const uint32_t& ___nfrag, const uint32_t& ___frag) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _seq(NULL), seq(___seq), _payload(NULL), payload(___payload), _ssize(NULL), ssize(___ssize), _rid(NULL), rid(___rid), _syn(NULL), syn(___syn), _synecho(NULL), synecho(___synecho), _nfrag(NULL), nfrag(___nfrag), _frag(NULL), frag(___frag) { }
    
    
    ~processDeliver10Dummy() {
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_seq != NULL) { delete _seq; _seq = NULL; }
      if (_payload != NULL) { delete _payload; _payload = NULL; }
      if (_ssize != NULL) { delete _ssize; _ssize = NULL; }
      if (_rid != NULL) { delete _rid; _rid = NULL; }
      if (_syn != NULL) { delete _syn; _syn = NULL; }
      if (_synecho != NULL) { delete _synecho; _synecho = NULL; }
      if (_nfrag != NULL) { delete _nfrag; _nfrag = NULL; }
      if (_frag != NULL) { delete _frag; _frag = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "processDeliver(";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[seq=";
          mace::printItem(out, &seq);
          out << "]";
          out << "[payload=";
          mace::printItem(out, &payload);
          out << "]";
          out << "[ssize=";
          mace::printItem(out, &ssize);
          out << "]";
          out << "[rid=";
          mace::printItem(out, &rid);
          out << "]";
          out << "[syn=";
          mace::printItem(out, &syn);
          out << "]";
          out << "[synecho=";
          mace::printItem(out, &synecho);
          out << "]";
          out << "[nfrag=";
          mace::printItem(out, &nfrag);
          out << "]";
          out << "[frag=";
          mace::printItem(out, &frag);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, src INT, dest INT, seq INT, payload TEXT, ssize INT8, rid INT, syn INT, synecho INT, nfrag INT8, frag INT8);" << std::endl;
        __node->children = new mace::LogNode*[6];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[3] = __child3;
        mace::LogNode* __child4 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[4] = __child4;
        mace::LogNode* __child5 = new mace::LogNode(__node->logName + "_synecho", Log::sqlEventsLog);
        __node->children[5] = __child5;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _srcIndex = __node->children[0]->nextId;
      int _destIndex = __node->children[1]->nextId;
      int _seqIndex = __node->children[2]->nextId;
      int _ridIndex = __node->children[3]->nextId;
      int _synIndex = __node->children[4]->nextId;
      int _synechoIndex = __node->children[5]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _srcIndex;
      __out << "\t" << _destIndex;
      __out << "\t" << _seqIndex;
      __out << "\t";
      if (Base64::isPrintable(payload)) {
        __out << payload;
      }
      else {
        __out << HashString::hash(payload);
      }
      __out << "\t" << ssize;
      __out << "\t" << _ridIndex;
      __out << "\t" << _synIndex;
      __out << "\t" << _synechoIndex;
      __out << "\t" << nfrag;
      __out << "\t" << frag;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&src, __node->children[0]);
      mace::sqlize(&dest, __node->children[1]);
      mace::sqlize(&seq, __node->children[2]);
      mace::sqlize(&rid, __node->children[3]);
      mace::sqlize(&syn, __node->children[4]);
      mace::sqlize(&synecho, __node->children[5]);
      
    }
  };
  class sendAck11Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    seq_t* _seq;
    const seq_t& seq;
    mace::MonotoneTime* _syn;
    const mace::MonotoneTime& syn;
    mace::MonotoneTime* _synecho;
    const mace::MonotoneTime& synecho;
    uint32_t* _sz;
    const uint32_t& sz;
    seq_t* _ackseq;
    const seq_t& ackseq;
    bool* _discard;
    const bool& discard;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_sendAck11";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::sendAck( const MaceKey& src, seq_t seq, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t sz, seq_t& ackseq, bool& discard)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    sendAck11Dummy() : _src(new MaceKey()), src(*_src), _seq(new seq_t()), seq(*_seq), _syn(new mace::MonotoneTime()), syn(*_syn), _synecho(new mace::MonotoneTime()), synecho(*_synecho), _sz(new uint32_t()), sz(*_sz), _ackseq(new seq_t()), ackseq(*_ackseq), _discard(new bool()), discard(*_discard) { }
    
    
    sendAck11Dummy(const MaceKey& ___src, const seq_t& ___seq, const mace::MonotoneTime& ___syn, const mace::MonotoneTime& ___synecho, const uint32_t& ___sz, const seq_t& ___ackseq, const bool& ___discard) : _src(NULL), src(___src), _seq(NULL), seq(___seq), _syn(NULL), syn(___syn), _synecho(NULL), synecho(___synecho), _sz(NULL), sz(___sz), _ackseq(NULL), ackseq(___ackseq), _discard(NULL), discard(___discard) { }
    
    
    ~sendAck11Dummy() {
      if (_src != NULL) { delete _src; _src = NULL; }
      if (_seq != NULL) { delete _seq; _seq = NULL; }
      if (_syn != NULL) { delete _syn; _syn = NULL; }
      if (_synecho != NULL) { delete _synecho; _synecho = NULL; }
      if (_sz != NULL) { delete _sz; _sz = NULL; }
      if (_ackseq != NULL) { delete _ackseq; _ackseq = NULL; }
      if (_discard != NULL) { delete _discard; _discard = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "sendAck(";
          out << "[src=";
          mace::printItem(out, &src);
          out << "]";
          out << "[seq=";
          mace::printItem(out, &seq);
          out << "]";
          out << "[syn=";
          mace::printItem(out, &syn);
          out << "]";
          out << "[synecho=";
          mace::printItem(out, &synecho);
          out << "]";
          out << "[sz=";
          mace::printItem(out, &sz);
          out << "]";
          out << "[ackseq=";
          mace::printItem(out, &ackseq);
          out << "]";
          out << "[discard=";
          mace::printItem(out, &discard);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, src INT, seq INT, syn INT, synecho INT, sz INT8, ackseq INT, discard INT);" << std::endl;
        __node->children = new mace::LogNode*[5];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_syn", Log::sqlEventsLog);
        __node->children[2] = __child2;
        mace::LogNode* __child3 = new mace::LogNode(__node->logName + "_synecho", Log::sqlEventsLog);
        __node->children[3] = __child3;
        mace::LogNode* __child4 = new mace::LogNode(__node->logName + "_ackseq", Log::sqlEventsLog);
        __node->children[4] = __child4;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _srcIndex = __node->children[0]->nextId;
      int _seqIndex = __node->children[1]->nextId;
      int _synIndex = __node->children[2]->nextId;
      int _synechoIndex = __node->children[3]->nextId;
      int _ackseqIndex = __node->children[4]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _srcIndex;
      __out << "\t" << _seqIndex;
      __out << "\t" << _synIndex;
      __out << "\t" << _synechoIndex;
      __out << "\t" << sz;
      __out << "\t" << _ackseqIndex;
      __out << "\t" << discard;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&src, __node->children[0]);
      mace::sqlize(&seq, __node->children[1]);
      mace::sqlize(&syn, __node->children[2]);
      mace::sqlize(&synecho, __node->children[3]);
      mace::sqlize(&ackseq, __node->children[4]);
      
    }
  };
  class sendReset12Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    mace::MonotoneTime* _id;
    const mace::MonotoneTime& id;
    seq_t* _seq;
    const seq_t& seq;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_sendReset12";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::sendReset( const MaceKey& dest, mace::MonotoneTime id, seq_t seq)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    sendReset12Dummy() : _dest(new MaceKey()), dest(*_dest), _id(new mace::MonotoneTime()), id(*_id), _seq(new seq_t()), seq(*_seq) { }
    
    
    sendReset12Dummy(const MaceKey& ___dest, const mace::MonotoneTime& ___id, const seq_t& ___seq) : _dest(NULL), dest(___dest), _id(NULL), id(___id), _seq(NULL), seq(___seq) { }
    
    
    ~sendReset12Dummy() {
      if (_dest != NULL) { delete _dest; _dest = NULL; }
      if (_id != NULL) { delete _id; _id = NULL; }
      if (_seq != NULL) { delete _seq; _seq = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "sendReset(";
          out << "[dest=";
          mace::printItem(out, &dest);
          out << "]";
          out << "[id=";
          mace::printItem(out, &id);
          out << "]";
          out << "[seq=";
          mace::printItem(out, &seq);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, dest INT, id INT, seq INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_id", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_seq", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      int _idIndex = __node->children[1]->nextId;
      int _seqIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _destIndex;
      __out << "\t" << _idIndex;
      __out << "\t" << _seqIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      mace::sqlize(&id, __node->children[1]);
      mace::sqlize(&seq, __node->children[2]);
      
    }
  };
  class sendPackets13Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_sendPackets13";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::sendPackets(OutgoingConnection& c)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    sendPackets13Dummy() : _c(new OutgoingConnection()), c(*_c) { }
    
    
    sendPackets13Dummy(const OutgoingConnection& ___c) : _c(NULL), c(___c) { }
    
    
    ~sendPackets13Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "sendPackets(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      
    }
  };
  class enqueue14Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    std::string* _s;
    const std::string& s;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_enqueue14";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::enqueue(OutgoingConnection& c,  const std::string& s, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    enqueue14Dummy() : _c(new OutgoingConnection()), c(*_c), _s(new std::string()), s(*_s), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    enqueue14Dummy(const OutgoingConnection& ___c, const std::string& ___s, const registration_uid_t& ___rid) : _c(NULL), c(___c), _s(NULL), s(___s), _rid(NULL), rid(___rid) { }
    
    
    ~enqueue14Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
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
      out << "enqueue(";
          out << "[c=";
          mace::printItem(out, &c);
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
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT, s TEXT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
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
      mace::sqlize(&c, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
    }
  };
  class updateFlushed15Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_updateFlushed15";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::updateFlushed(OutgoingConnection& c)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    updateFlushed15Dummy() : _c(new OutgoingConnection()), c(*_c) { }
    
    
    updateFlushed15Dummy(const OutgoingConnection& ___c) : _c(NULL), c(___c) { }
    
    
    ~updateFlushed15Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "updateFlushed(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      
    }
  };
  class checkAndNotifyFlushed16Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_checkAndNotifyFlushed16";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::checkAndNotifyFlushed()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    checkAndNotifyFlushed16Dummy()  { }
    
    
    
    
    ~checkAndNotifyFlushed16Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "checkAndNotifyFlushed(";
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
  class printConnection17Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    OutgoingConnection* _c;
    const OutgoingConnection& c;
    std::string* _s;
    const std::string& s;
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_printConnection17";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::printConnection( const OutgoingConnection& c,  const std::string& s) const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    printConnection17Dummy() : _c(new OutgoingConnection()), c(*_c), _s(new std::string()), s(*_s) { }
    
    
    printConnection17Dummy(const OutgoingConnection& ___c, const std::string& ___s) : _c(NULL), c(___c), _s(NULL), s(___s) { }
    
    
    ~printConnection17Dummy() {
      if (_c != NULL) { delete _c; _c = NULL; }
      if (_s != NULL) { delete _s; _s = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "printConnection(";
          out << "[c=";
          mace::printItem(out, &c);
          out << "]";
          out << "[s=";
          mace::printItem(out, &s);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, c INT, s TEXT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_c", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _cIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _cIndex;
      __out << "\t";
      if (Base64::isPrintable(s)) {
        __out << s;
      }
      else {
        __out << HashString::hash(s);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&c, __node->children[0]);
      
    }
  };
  class inflightSize18Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_inflightSize18";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::inflightSize() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    inflightSize18Dummy()  { }
    
    
    
    
    ~inflightSize18Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "inflightSize(";
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
  class checkRetransmissionTimer19Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_checkRetransmissionTimer19";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::checkRetransmissionTimer() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    checkRetransmissionTimer19Dummy()  { }
    
    
    
    
    ~checkRetransmissionTimer19Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "checkRetransmissionTimer(";
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
  class checkRetransmissionTimerCount20Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_checkRetransmissionTimerCount20";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::checkRetransmissionTimerCount() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    checkRetransmissionTimerCount20Dummy()  { }
    
    
    
    
    ~checkRetransmissionTimerCount20Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "checkRetransmissionTimerCount(";
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
  class outgoingBufferedDataSize21Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "MaceTransport_outgoingBufferedDataSize21";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "MaceTransport::outgoingBufferedDataSize() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    outgoingBufferedDataSize21Dummy()  { }
    
    
    
    
    ~outgoingBufferedDataSize21Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "outgoingBufferedDataSize(";
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
}
#endif
