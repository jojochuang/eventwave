/*********************************************
*  ProvisionalTransport header file
*  Mace generated on:
*  Tue Apr 10 10:09:49 2012
*********************************************/

#ifndef ProvisionalTransport_header
#define ProvisionalTransport_header

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
#include "ProvisionalTransport-constants.h"
#include "lib/ContextBaseClass.h"
#include "lib/ContextLock.h"
#include "lib/ContextMapping.h"
#include "HighLevelEvent.h"

#include "lib/Message.h"
#include "BufferedTransportServiceClass.h"
#include "ProvisionalTransportServiceClass.h"
#include "TransportServiceClass.h"
#include "BufferedTransportServiceClass.h"
//END: Mace::Compiler::ServiceImpl::printIncludesH
//BEGIN: Mace::Compiler::ServiceImpl::printUsingH
using mace::BinaryLogObject;
using mace::Serializable;
using mace::SerializationException;
using mace::ContextMapping;
using mace::Message;
//END: Mace::Compiler::ServiceImpl::printUsingH
//BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
#line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
#include "Accumulator.h"
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
namespace ProvisionalTransport_namespace {
  
  void load_protocol();
  
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  const std::string selector_registerHandler_demux_22 = "ProvisionalTransport::registerHandler::(demux)";
  const std::string selector_route_downcall_30 = "ProvisionalTransport::route::Abort::(downcall)";
  const std::string selector_messageCanceled_upcall_6 = "ProvisionalTransport::messageCanceled::(upcall)";
  const std::string selector_downcall_maceInit_0_transition = "ProvisionalTransport::maceInit::(true)";
  const std::string selector_incomingBufferedDataSize_downcall_3 = "ProvisionalTransport::incomingBufferedDataSize::(downcall)";
  const std::string selector_routeRTS_downcall_23 = "ProvisionalTransport::routeRTS::Message::(downcall)";
  const std::string selector_send_downcall_37 = "ProvisionalTransport::send::Commit::(downcall)";
  const std::string selector_updateSendable_routine_1 = "ProvisionalTransport::updateSendable::(routine)";
  const std::string selector_outgoingBufferedDataSize_downcall_13 = "ProvisionalTransport::outgoingBufferedDataSize::(downcall)";
  const std::string selector_error_upcall_1 = "ProvisionalTransport::error::(upcall)";
  const std::string selector_getStatistics_downcall_8 = "ProvisionalTransport::getStatistics::(downcall)";
  const std::string selector_cancelFront_demux_11 = "ProvisionalTransport::cancelFront::(demux)";
  const std::string selector_downcall_incomingBufferedDataSize_7_transition = "ProvisionalTransport::incomingBufferedDataSize::(true)";
  const std::string selector_send_downcall_36 = "ProvisionalTransport::send::Data::(downcall)";
  const std::string selector_send_downcall_38 = "ProvisionalTransport::send::Abort::(downcall)";
  const std::string selector_route_downcall_28 = "ProvisionalTransport::route::Data::(downcall)";
  const std::string selector_clearToSend_demux_1 = "ProvisionalTransport::clearToSend::(demux)";
  const std::string selector_localAddress_demux_52 = "ProvisionalTransport::localAddress::(demux)";
  const std::string selector_messageStatus_demux_12 = "ProvisionalTransport::messageStatus::(demux)";
  const std::string selector_routeRTS_downcall_22 = "ProvisionalTransport::routeRTS::Abort::(downcall)";
  const std::string selector_outgoingBufferedDataSize_downcall_2 = "ProvisionalTransport::outgoingBufferedDataSize::(downcall)";
  const std::string selector_downcall_messageStatus_8_transition = "ProvisionalTransport::messageStatus::(true)";
  const std::string selector_suspendDeliver_demux_44 = "ProvisionalTransport::suspendDeliver::(demux)";
  const std::string selector_suspendDeliver_downcall_16 = "ProvisionalTransport::suspendDeliver::(downcall)";
  const std::string selector_hasOutgoingBufferedData_demux_37 = "ProvisionalTransport::hasOutgoingBufferedData::(demux)";
  const std::string selector_route_downcall_34 = "ProvisionalTransport::route::Abort::(downcall)";
  const std::string selector_incomingMessageQueueSize_demux_29 = "ProvisionalTransport::incomingMessageQueueSize::(demux)";
  const std::string selector_downcall_canSend_5_transition = "ProvisionalTransport::canSend::(true)";
  const std::string selector_route_downcall_33 = "ProvisionalTransport::route::Commit::(downcall)";
  const std::string selector_routeRTS_demux_40 = "ProvisionalTransport::routeRTS::(demux)";
  const std::string selector_clearToSend_upcall_3 = "ProvisionalTransport::clearToSend::(upcall)";
  const std::string selector_outgoingBufferedDataSize_demux_27 = "ProvisionalTransport::outgoingBufferedDataSize::(demux)";
  const std::string selector_messageError_demux_55 = "ProvisionalTransport::messageError::(demux)";
  const std::string selector_route_downcall_42 = "ProvisionalTransport::route::(downcall)";
  const std::string selector_route_downcall_27 = "ProvisionalTransport::route::Message::(downcall)";
  const std::string selector_routeRTS_downcall_20 = "ProvisionalTransport::routeRTS::Data::(downcall)";
  const std::string selector_maceReset_demux_51 = "ProvisionalTransport::maceReset::(demux)";
  const std::string selector_notifyFlushed_demux_2 = "ProvisionalTransport::notifyFlushed::(demux)";
  const std::string selector_unregisterHandler_demux_17 = "ProvisionalTransport::unregisterHandler::(demux)";
  const std::string selector_routeRTS_downcall_19 = "ProvisionalTransport::routeRTS::Message::(downcall)";
  const std::string selector_suspendDeliver_downcall_15 = "ProvisionalTransport::suspendDeliver::(downcall)";
  const std::string selector_deliver_upcall_0 = "ProvisionalTransport::deliver::(upcall)";
  const std::string selector_suspendDeliver_demux_45 = "ProvisionalTransport::suspendDeliver::(demux)";
  const std::string selector_hashState_demux_53 = "ProvisionalTransport::hashState::(demux)";
  const std::string selector_outgoingBufferedDataSize_demux_38 = "ProvisionalTransport::outgoingBufferedDataSize::(demux)";
  const std::string selector_canSend_downcall_0 = "ProvisionalTransport::canSend::(downcall)";
  const std::string selector_send_downcall_35 = "ProvisionalTransport::send::Message::(downcall)";
  const std::string selector_maceResume_demux_49 = "ProvisionalTransport::maceResume::(demux)";
  const std::string selector_route_demux_42 = "ProvisionalTransport::route::(demux)";
  const std::string selector_unregisterHandler_demux_23 = "ProvisionalTransport::unregisterHandler::(demux)";
  const std::string selector_deliver_demux_54 = "ProvisionalTransport::deliver::(demux)";
  const std::string selector_routeRTS_downcall_26 = "ProvisionalTransport::routeRTS::Abort::(downcall)";
  const std::string selector_setWindowSize_downcall_6 = "ProvisionalTransport::setWindowSize::(downcall)";
  const std::string selector_routeRTS_demux_39 = "ProvisionalTransport::routeRTS::(demux)";
  const std::string selector_messageError_demux_6 = "ProvisionalTransport::messageError::Data::(demux)";
  const std::string selector_messageError_demux_8 = "ProvisionalTransport::messageError::Abort::(demux)";
  const std::string selector_routeRTS_downcall_25 = "ProvisionalTransport::routeRTS::Commit::(downcall)";
  const std::string selector_setWindowSize_demux_31 = "ProvisionalTransport::setWindowSize::(demux)";
  const std::string selector_downcall_cancelFront_3_transition = "ProvisionalTransport::cancelFront::(true)";
  const std::string selector_registerUniqueHandler_demux_15 = "ProvisionalTransport::registerUniqueHandler::(demux)";
  const std::string selector_routeRTS_downcall_21 = "ProvisionalTransport::routeRTS::Commit::(downcall)";
  const std::string selector_upcall_messageError_14_transition = "ProvisionalTransport::messageError::Data::(true)";
  const std::string selector_registerHandler_demux_16 = "ProvisionalTransport::registerHandler::(demux)";
  const std::string selector_bufferedDataSize_demux_35 = "ProvisionalTransport::bufferedDataSize::(demux)";
  const std::string selector_downcall_route_2_transition = "ProvisionalTransport::route::(true)";
  const std::string selector_setQueueSize_demux_32 = "ProvisionalTransport::setQueueSize::(demux)";
  const std::string selector_incomingMessageQueueSize_downcall_5 = "ProvisionalTransport::incomingMessageQueueSize::(downcall)";
  const std::string selector_deliver_demux_5 = "ProvisionalTransport::deliver::Abort::(demux)";
  const std::string selector_canSend_demux_25 = "ProvisionalTransport::canSend::(demux)";
  const std::string selector_resumeDeliver_demux_47 = "ProvisionalTransport::resumeDeliver::(demux)";
  const std::string selector_routeRTS_downcall_39 = "ProvisionalTransport::routeRTS::(downcall)";
  const std::string selector_getStatistics_demux_33 = "ProvisionalTransport::getStatistics::(demux)";
  const std::string selector_hasBufferedData_demux_36 = "ProvisionalTransport::hasBufferedData::(demux)";
  const std::string selector_messageError_upcall_2 = "ProvisionalTransport::messageError::(upcall)";
  const std::string selector_upcall_messageError_16_transition = "ProvisionalTransport::messageError::Abort::(true)";
  const std::string selector_requestToSend_downcall_9 = "ProvisionalTransport::requestToSend::(downcall)";
  const std::string selector_upcall_deliver_10_transition = "ProvisionalTransport::deliver::Data::(true)";
  const std::string selector_upcall_messageError_15_transition = "ProvisionalTransport::messageError::Commit::(true)";
  const std::string selector_cancel_demux_10 = "ProvisionalTransport::cancel::(demux)";
  const std::string selector_availableBufferSize_demux_26 = "ProvisionalTransport::availableBufferSize::(demux)";
  const std::string selector_error_demux_0 = "ProvisionalTransport::error::(demux)";
  const std::string selector_messageSent_upcall_5 = "ProvisionalTransport::messageSent::(upcall)";
  const std::string selector_upcall_deliver_12_transition = "ProvisionalTransport::deliver::Abort::(true)";
  const std::string selector_upcall_deliver_11_transition = "ProvisionalTransport::deliver::Commit::(true)";
  const std::string selector_route_downcall_41 = "ProvisionalTransport::route::(downcall)";
  const std::string selector_requestToSend_demux_34 = "ProvisionalTransport::requestToSend::(demux)";
  const std::string selector_routeRTS_downcall_40 = "ProvisionalTransport::routeRTS::(downcall)";
  const std::string selector_registerUniqueHandler_demux_24 = "ProvisionalTransport::registerUniqueHandler::(demux)";
  const std::string selector_unregisterHandler_demux_14 = "ProvisionalTransport::unregisterHandler::(demux)";
  const std::string selector_upcall_clearToSend_13_transition = "ProvisionalTransport::clearToSend::(true)";
  const std::string selector_downcall_availableBufferSize_6_transition = "ProvisionalTransport::availableBufferSize::(true)";
  const std::string selector_routeRTS_downcall_24 = "ProvisionalTransport::routeRTS::Data::(downcall)";
  const std::string selector_cancel_routine_2 = "ProvisionalTransport::cancel::(routine)";
  const std::string selector_registerHandler_demux_13 = "ProvisionalTransport::registerHandler::(demux)";
  const std::string selector_sendData_routine_0 = "ProvisionalTransport::sendData::(routine)";
  const std::string selector_hasOutgoingBufferedData_downcall_12 = "ProvisionalTransport::hasOutgoingBufferedData::(downcall)";
  const std::string selector_route_downcall_32 = "ProvisionalTransport::route::Data::(downcall)";
  const std::string selector_messageError_demux_7 = "ProvisionalTransport::messageError::Commit::(demux)";
  const std::string selector_availableBufferSize_downcall_1 = "ProvisionalTransport::availableBufferSize::(downcall)";
  const std::string selector_requestFlushedNotification_demux_41 = "ProvisionalTransport::requestFlushedNotification::(demux)";
  const std::string selector_maceExit_demux_50 = "ProvisionalTransport::maceExit::(demux)";
  const std::string selector_upcall_error_9_transition = "ProvisionalTransport::error::(true)";
  const std::string selector_route_downcall_31 = "ProvisionalTransport::route::Message::(downcall)";
  const std::string selector_provisionalRoute_demux_9 = "ProvisionalTransport::provisionalRoute::(demux)";
  const std::string selector_incomingMessageQueueSize_downcall_4 = "ProvisionalTransport::incomingMessageQueueSize::(downcall)";
  const std::string selector_downcall_provisionalRoute_1_transition = "ProvisionalTransport::provisionalRoute::(true)";
  const std::string selector_notifyFlushed_upcall_4 = "ProvisionalTransport::notifyFlushed::(upcall)";
  const std::string selector_hasBufferedData_downcall_11 = "ProvisionalTransport::hasBufferedData::(downcall)";
  const std::string selector_resumeDeliver_demux_46 = "ProvisionalTransport::resumeDeliver::(demux)";
  const std::string selector_resumeDeliver_downcall_17 = "ProvisionalTransport::resumeDeliver::(downcall)";
  const std::string selector_bufferedDataSize_downcall_10 = "ProvisionalTransport::bufferedDataSize::(downcall)";
  const std::string selector_registerUniqueHandler_demux_21 = "ProvisionalTransport::registerUniqueHandler::(demux)";
  const std::string selector_resumeDeliver_downcall_18 = "ProvisionalTransport::resumeDeliver::(downcall)";
  const std::string selector_incomingBufferedDataSize_demux_28 = "ProvisionalTransport::incomingBufferedDataSize::(demux)";
  const std::string selector_deliver_demux_3 = "ProvisionalTransport::deliver::Data::(demux)";
  const std::string selector_send_downcall_43 = "ProvisionalTransport::send::(downcall)";
  const std::string selector_requestFlushedNotification_downcall_14 = "ProvisionalTransport::requestFlushedNotification::(downcall)";
  const std::string selector_unregisterHandler_demux_20 = "ProvisionalTransport::unregisterHandler::(demux)";
  const std::string selector_downcall_cancel_4_transition = "ProvisionalTransport::cancel::(true)";
  const std::string selector_registerHandler_demux_19 = "ProvisionalTransport::registerHandler::(demux)";
  const std::string selector_deliver_demux_4 = "ProvisionalTransport::deliver::Commit::(demux)";
  const std::string selector_setQueueSize_downcall_7 = "ProvisionalTransport::setQueueSize::(downcall)";
  const std::string selector_incomingMessageQueueSize_demux_30 = "ProvisionalTransport::incomingMessageQueueSize::(demux)";
  const std::string selector_route_demux_43 = "ProvisionalTransport::route::(demux)";
  const std::string selector_registerUniqueHandler_demux_18 = "ProvisionalTransport::registerUniqueHandler::(demux)";
  const std::string selector_maceInit_demux_48 = "ProvisionalTransport::maceInit::(demux)";
  const std::string selector_route_downcall_29 = "ProvisionalTransport::route::Commit::(downcall)";
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  class OutgoingMessageData;
  class OutgoingConnection;
  //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
  typedef mace::map<message_id_t, OutgoingMessageData> OutgoingMessageQueue;
  typedef mace::map<MaceKey, OutgoingConnection> OutgoingConnectionMap;
  typedef mace::map<message_id_t, mace::string> IncomingMessageMap;
  typedef mace::map<MaceKey, IncomingMessageMap> IncomingConnectionMap;
  typedef mace::map<message_id_t, MaceKey> MessageDestinationMap;
  //END: Mace::Compiler::ServiceImpl::printTypeDefs
  
  //Message Declarations
  class Data;
  class Commit;
  class Abort;
  
  
  //Context Forward Declarations
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  
  class ProvisionalTransportService;
  typedef ProvisionalTransportService ServiceType;
  typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;
  typedef mace::map<int, ProvisionalTransportService const *, mace::SoftState> _NodeMap_;
  typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;
  mace::map<mace::string, mace::string> returnValueMapping;
  std::map<mace::string, pthread_mutex_t> mutexMapping;
  static const char* __SERVICE__ __attribute((unused)) = "ProvisionalTransport";
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
  class OutgoingMessageData : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    
    #line 68 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    std::string data
#line 225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    std::string get_data() const { return data; }
    
    #line 69 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    registration_uid_t rid
#line 231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    registration_uid_t get_rid() const { return rid; }
    
    #line 70 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    uint32_t offset
#line 237 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    uint32_t get_offset() const { return offset; }
    OutgoingMessageData() : data(), rid(), offset(0) {}
    OutgoingMessageData(std::string const & _data, registration_uid_t const & _rid, uint32_t const & _offset = 0) : serializedByteSize(0), data(_data), rid(_rid), offset(_offset) {}
    virtual ~OutgoingMessageData() {}
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __OutgoingMessageDataPrinter(__name, "OutgoingMessageData");
      mace::printItem(__OutgoingMessageDataPrinter, "data", &(data));;
      mace::printItem(__OutgoingMessageDataPrinter, "rid", &(rid));;
      mace::printItem(__OutgoingMessageDataPrinter, "offset", &(offset));
      __pr.addChild(__OutgoingMessageDataPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "OutgoingMessageData("  ;
          __out << "data=";  mace::printItem(__out, &(data));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
          __out << ", ";
          __out << "offset=";  mace::printItem(__out, &(offset));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "OutgoingMessageData(" ;
          __out << "data=";  mace::printState(__out, &(data), (data));
          __out << ", ";
          __out << "rid=";  mace::printState(__out, &(rid), (rid));
          __out << ", ";
          __out << "offset=";  mace::printState(__out, &(offset), (offset));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      
      #line 68 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &data);
#line 274 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 69 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &rid);
#line 279 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 70 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &offset);
#line 284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      
      #line 68 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &data);
#line 293 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 69 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &rid);
#line 298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 70 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &offset);
#line 303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, data TEXT, rid INT, offset INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _ridIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(data)) {
        __out << data;
      }
      else {
        __out << HashString::hash(data);
      }
      __out << "\t" << _ridIndex;
      __out << "\t" << offset;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&rid, __node->children[0]);
      
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
        
        if (__var == "data") {
          mace::deserializeXML_RPC(__mace_in, & data, data);
        } else
        if (__var == "rid") {
          mace::deserializeXML_RPC(__mace_in, & rid, rid);
        } else
        if (__var == "offset") {
          mace::deserializeXML_RPC(__mace_in, & offset, offset);
        } else
        {
          throw(new mace::SerializationException("deserializing OutgoingMessageData: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 3) {
        throw(new mace::SerializationException("deserializing OutgoingMessageData: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>data</name><value>");
      mace::serializeXML_RPC(str, &(data), data);
      str.append("</value></member>");
      str.append("<member><name>rid</name><value>");
      mace::serializeXML_RPC(str, &(rid), rid);
      str.append("</value></member>");
      str.append("<member><name>offset</name><value>");
      mace::serializeXML_RPC(str, &(offset), offset);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  class OutgoingConnection : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    
    #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    OutgoingMessageQueue q
#line 403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    OutgoingMessageQueue get_q() const { return q; }
    
    #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    message_id_t canceled
#line 409 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    message_id_t get_canceled() const { return canceled; }
    
    #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    registration_uid_t canceledRid
#line 415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    registration_uid_t get_canceledRid() const { return canceledRid; }
    
    #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    uint32_t buffered
#line 421 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    uint32_t get_buffered() const { return buffered; }
    
    #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    bool sendable
#line 427 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    bool get_sendable() const { return sendable; }
    OutgoingConnection() : q(), canceled(0), canceledRid(0), buffered(0), sendable(true) {}
    OutgoingConnection(OutgoingMessageQueue const & _q, message_id_t const & _canceled = 0, registration_uid_t const & _canceledRid = 0, uint32_t const & _buffered = 0, bool const & _sendable = true) : serializedByteSize(0), q(_q), canceled(_canceled), canceledRid(_canceledRid), buffered(_buffered), sendable(_sendable) {}
    virtual ~OutgoingConnection() {}
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __OutgoingConnectionPrinter(__name, "OutgoingConnection");
      mace::printItem(__OutgoingConnectionPrinter, "q", &(q));;
      mace::printItem(__OutgoingConnectionPrinter, "canceled", &(canceled));;
      mace::printItem(__OutgoingConnectionPrinter, "canceledRid", &(canceledRid));;
      mace::printItem(__OutgoingConnectionPrinter, "buffered", &(buffered));;
      mace::printItem(__OutgoingConnectionPrinter, "sendable", &(sendable));
      __pr.addChild(__OutgoingConnectionPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "OutgoingConnection("  ;
          __out << "q=";  mace::printItem(__out, &(q));
          __out << ", ";
          __out << "canceled=";  mace::printItem(__out, &(canceled));
          __out << ", ";
          __out << "canceledRid=";  mace::printItem(__out, &(canceledRid));
          __out << ", ";
          __out << "buffered=";  mace::printItem(__out, &(buffered));
          __out << ", ";
          __out << "sendable=";  mace::printItem(__out, &(sendable));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "OutgoingConnection(" ;
          __out << "q=";  mace::printState(__out, &(q), (q));
          __out << ", ";
          __out << "canceled=";  mace::printState(__out, &(canceled), (canceled));
          __out << ", ";
          __out << "canceledRid=";  mace::printState(__out, &(canceledRid), (canceledRid));
          __out << ", ";
          __out << "buffered=";  mace::printState(__out, &(buffered), (buffered));
          __out << ", ";
          __out << "sendable=";  mace::printState(__out, &(sendable), (sendable));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &q);
#line 474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &canceled);
#line 479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &canceledRid);
#line 484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &buffered);
#line 489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &sendable);
#line 494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &q);
#line 503 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &canceled);
#line 508 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &canceledRid);
#line 513 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &buffered);
#line 518 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &sendable);
#line 523 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, q INT, canceled INT, canceledRid INT, buffered INT8, sendable INT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_q", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_canceled", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_canceledRid", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _qIndex = __node->children[0]->nextId;
      int _canceledIndex = __node->children[1]->nextId;
      int _canceledRidIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _qIndex;
      __out << "\t" << _canceledIndex;
      __out << "\t" << _canceledRidIndex;
      __out << "\t" << buffered;
      __out << "\t" << sendable;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&q, __node->children[0]);
      mace::sqlize(&canceled, __node->children[1]);
      mace::sqlize(&canceledRid, __node->children[2]);
      
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
        
        if (__var == "q") {
          mace::deserializeXML_RPC(__mace_in, & q, q);
        } else
        if (__var == "canceled") {
          mace::deserializeXML_RPC(__mace_in, & canceled, canceled);
        } else
        if (__var == "canceledRid") {
          mace::deserializeXML_RPC(__mace_in, & canceledRid, canceledRid);
        } else
        if (__var == "buffered") {
          mace::deserializeXML_RPC(__mace_in, & buffered, buffered);
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
      if (__fields != 5) {
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
      
      str.append("<member><name>q</name><value>");
      mace::serializeXML_RPC(str, &(q), q);
      str.append("</value></member>");
      str.append("<member><name>canceled</name><value>");
      mace::serializeXML_RPC(str, &(canceled), canceled);
      str.append("</value></member>");
      str.append("<member><name>canceledRid</name><value>");
      mace::serializeXML_RPC(str, &(canceledRid), canceledRid);
      str.append("</value></member>");
      str.append("<member><name>buffered</name><value>");
      mace::serializeXML_RPC(str, &(buffered), buffered);
      str.append("</value></member>");
      str.append("<member><name>sendable</name><value>");
      mace::serializeXML_RPC(str, &(sendable), sendable);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  //END: Mace::Compiler::ServiceImpl::printAutoTypes
  //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
  struct __DeferralArgsFormessageSent_message_id_t___registration_uid_t__ {
    uint64_t __calltime;
    __DeferralArgsFormessageSent_message_id_t___registration_uid_t__() : __calltime(TimeUtil::timeu()) { };
    __DeferralArgsFormessageSent_message_id_t___registration_uid_t__(
        
        #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
        message_id_t const & id
#line 641 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
        registration_uid_t const & rid = -1
#line 645 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) : __calltime(TimeUtil::timeu()), id(id), rid(rid){ }
    message_id_t id;
    registration_uid_t rid;};
  //END Mace::Compiler::ServiceImpl::printDeferTypes
  //BEGIN: Mace::Compiler::ServiceImpl::printService
  
  class ServiceTester;
  class ProvisionalTransportService : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, public virtual BufferedTransportServiceClass, public virtual ProvisionalTransportServiceClass, public virtual TransportServiceClass, public virtual ReceiveDataHandler, public virtual NetworkErrorHandler, public virtual ConnectionStatusHandler
  {
    private:
    
    friend class ServiceTester;
    
    friend class OutgoingMessageData;
    friend class OutgoingConnection;
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
    ProvisionalTransportService(BufferedTransportServiceClass& __router, uint32_t const  _maxQueueSize, uint32_t const  _queueThresholdArg, bool ___shared = true);
    ProvisionalTransportService(const ProvisionalTransportService& other);
    //Destructor
    virtual ~ProvisionalTransportService();
    
    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;
    
    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    private:
    
    const state_type& read_state() const;
    OutgoingConnectionMap const & read_out() const;
    IncomingConnectionMap const & read_in() const;
    MessageDestinationMap const & read_destinations() const;
    uint32_t const & read_threshold() const;
    
    public:
    //Misc.
    
    const std::string& getLogType() const {
      static std::string type = "ProvisionalTransport";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "SNAPSHOT::ProvisionalTransport";
      return desc;
    }
    
    LogClass getLogClass() const {
      return STATE_DUMP;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    
    static const LogIdSet* selectorId_registerHandler_demux_22;
    static const LogIdSet* selectorId_route_downcall_30;
    static const LogIdSet* selectorId_messageCanceled_upcall_6;
    static const LogIdSet* selectorId_downcall_maceInit_0_transition;
    static const LogIdSet* selectorId_incomingBufferedDataSize_downcall_3;
    static const LogIdSet* selectorId_routeRTS_downcall_23;
    static const LogIdSet* selectorId_send_downcall_37;
    static const LogIdSet* selectorId_updateSendable_routine_1;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_downcall_13;
    static const LogIdSet* selectorId_error_upcall_1;
    static const LogIdSet* selectorId_getStatistics_downcall_8;
    static const LogIdSet* selectorId_cancelFront_demux_11;
    static const LogIdSet* selectorId_downcall_incomingBufferedDataSize_7_transition;
    static const LogIdSet* selectorId_send_downcall_36;
    static const LogIdSet* selectorId_send_downcall_38;
    static const LogIdSet* selectorId_route_downcall_28;
    static const LogIdSet* selectorId_clearToSend_demux_1;
    static const LogIdSet* selectorId_localAddress_demux_52;
    static const LogIdSet* selectorId_messageStatus_demux_12;
    static const LogIdSet* selectorId_routeRTS_downcall_22;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_downcall_2;
    static const LogIdSet* selectorId_downcall_messageStatus_8_transition;
    static const LogIdSet* selectorId_suspendDeliver_demux_44;
    static const LogIdSet* selectorId_suspendDeliver_downcall_16;
    static const LogIdSet* selectorId_hasOutgoingBufferedData_demux_37;
    static const LogIdSet* selectorId_route_downcall_34;
    static const LogIdSet* selectorId_incomingMessageQueueSize_demux_29;
    static const LogIdSet* selectorId_downcall_canSend_5_transition;
    static const LogIdSet* selectorId_route_downcall_33;
    static const LogIdSet* selectorId_routeRTS_demux_40;
    static const LogIdSet* selectorId_clearToSend_upcall_3;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_demux_27;
    static const LogIdSet* selectorId_messageError_demux_55;
    static const LogIdSet* selectorId_route_downcall_42;
    static const LogIdSet* selectorId_route_downcall_27;
    static const LogIdSet* selectorId_routeRTS_downcall_20;
    static const LogIdSet* selectorId_maceReset_demux_51;
    static const LogIdSet* selectorId_notifyFlushed_demux_2;
    static const LogIdSet* selectorId_unregisterHandler_demux_17;
    static const LogIdSet* selectorId_routeRTS_downcall_19;
    static const LogIdSet* selectorId_suspendDeliver_downcall_15;
    static const LogIdSet* selectorId_deliver_upcall_0;
    static const LogIdSet* selectorId_suspendDeliver_demux_45;
    static const LogIdSet* selectorId_hashState_demux_53;
    static const LogIdSet* selectorId_outgoingBufferedDataSize_demux_38;
    static const LogIdSet* selectorId_canSend_downcall_0;
    static const LogIdSet* selectorId_send_downcall_35;
    static const LogIdSet* selectorId_maceResume_demux_49;
    static const LogIdSet* selectorId_route_demux_42;
    static const LogIdSet* selectorId_unregisterHandler_demux_23;
    static const LogIdSet* selectorId_deliver_demux_54;
    static const LogIdSet* selectorId_routeRTS_downcall_26;
    static const LogIdSet* selectorId_setWindowSize_downcall_6;
    static const LogIdSet* selectorId_routeRTS_demux_39;
    static const LogIdSet* selectorId_messageError_demux_6;
    static const LogIdSet* selectorId_messageError_demux_8;
    static const LogIdSet* selectorId_routeRTS_downcall_25;
    static const LogIdSet* selectorId_setWindowSize_demux_31;
    static const LogIdSet* selectorId_downcall_cancelFront_3_transition;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_15;
    static const LogIdSet* selectorId_routeRTS_downcall_21;
    static const LogIdSet* selectorId_upcall_messageError_14_transition;
    static const LogIdSet* selectorId_registerHandler_demux_16;
    static const LogIdSet* selectorId_bufferedDataSize_demux_35;
    static const LogIdSet* selectorId_downcall_route_2_transition;
    static const LogIdSet* selectorId_setQueueSize_demux_32;
    static const LogIdSet* selectorId_incomingMessageQueueSize_downcall_5;
    static const LogIdSet* selectorId_deliver_demux_5;
    static const LogIdSet* selectorId_canSend_demux_25;
    static const LogIdSet* selectorId_resumeDeliver_demux_47;
    static const LogIdSet* selectorId_routeRTS_downcall_39;
    static const LogIdSet* selectorId_getStatistics_demux_33;
    static const LogIdSet* selectorId_hasBufferedData_demux_36;
    static const LogIdSet* selectorId_messageError_upcall_2;
    static const LogIdSet* selectorId_upcall_messageError_16_transition;
    static const LogIdSet* selectorId_requestToSend_downcall_9;
    static const LogIdSet* selectorId_upcall_deliver_10_transition;
    static const LogIdSet* selectorId_upcall_messageError_15_transition;
    static const LogIdSet* selectorId_cancel_demux_10;
    static const LogIdSet* selectorId_availableBufferSize_demux_26;
    static const LogIdSet* selectorId_error_demux_0;
    static const LogIdSet* selectorId_messageSent_upcall_5;
    static const LogIdSet* selectorId_upcall_deliver_12_transition;
    static const LogIdSet* selectorId_upcall_deliver_11_transition;
    static const LogIdSet* selectorId_route_downcall_41;
    static const LogIdSet* selectorId_requestToSend_demux_34;
    static const LogIdSet* selectorId_routeRTS_downcall_40;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_24;
    static const LogIdSet* selectorId_unregisterHandler_demux_14;
    static const LogIdSet* selectorId_upcall_clearToSend_13_transition;
    static const LogIdSet* selectorId_downcall_availableBufferSize_6_transition;
    static const LogIdSet* selectorId_routeRTS_downcall_24;
    static const LogIdSet* selectorId_cancel_routine_2;
    static const LogIdSet* selectorId_registerHandler_demux_13;
    static const LogIdSet* selectorId_sendData_routine_0;
    static const LogIdSet* selectorId_hasOutgoingBufferedData_downcall_12;
    static const LogIdSet* selectorId_route_downcall_32;
    static const LogIdSet* selectorId_messageError_demux_7;
    static const LogIdSet* selectorId_availableBufferSize_downcall_1;
    static const LogIdSet* selectorId_requestFlushedNotification_demux_41;
    static const LogIdSet* selectorId_maceExit_demux_50;
    static const LogIdSet* selectorId_upcall_error_9_transition;
    static const LogIdSet* selectorId_route_downcall_31;
    static const LogIdSet* selectorId_provisionalRoute_demux_9;
    static const LogIdSet* selectorId_incomingMessageQueueSize_downcall_4;
    static const LogIdSet* selectorId_downcall_provisionalRoute_1_transition;
    static const LogIdSet* selectorId_notifyFlushed_upcall_4;
    static const LogIdSet* selectorId_hasBufferedData_downcall_11;
    static const LogIdSet* selectorId_resumeDeliver_demux_46;
    static const LogIdSet* selectorId_resumeDeliver_downcall_17;
    static const LogIdSet* selectorId_bufferedDataSize_downcall_10;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_21;
    static const LogIdSet* selectorId_resumeDeliver_downcall_18;
    static const LogIdSet* selectorId_incomingBufferedDataSize_demux_28;
    static const LogIdSet* selectorId_deliver_demux_3;
    static const LogIdSet* selectorId_send_downcall_43;
    static const LogIdSet* selectorId_requestFlushedNotification_downcall_14;
    static const LogIdSet* selectorId_unregisterHandler_demux_20;
    static const LogIdSet* selectorId_downcall_cancel_4_transition;
    static const LogIdSet* selectorId_registerHandler_demux_19;
    static const LogIdSet* selectorId_deliver_demux_4;
    static const LogIdSet* selectorId_setQueueSize_downcall_7;
    static const LogIdSet* selectorId_incomingMessageQueueSize_demux_30;
    static const LogIdSet* selectorId_route_demux_43;
    static const LogIdSet* selectorId_registerUniqueHandler_demux_18;
    static const LogIdSet* selectorId_maceInit_demux_48;
    static const LogIdSet* selectorId_route_downcall_29;
    
    protected:
    void dumpState(LOGLOGTYPE& logger) const;
    void processDeferred();
    const char* getStateName(state_type state) const;
    const char* getMessageName(uint8_t msgNum) const;
    void changeState(state_type stateNum, int selectorId);
    bool shouldLog_provisionalRoute48( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_cancel49(message_id_t id, registration_uid_t rid) const;
    bool shouldLog_cancelFront50( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_messageStatus51(message_id_t id, uint32_t& size, uint32_t& sent, registration_uid_t rid) const;
    bool shouldLog_canSend52( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_availableBufferSize53( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize54( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingBufferedDataSize55( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize56( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize57(registration_uid_t rid) const;
    bool shouldLog_setWindowSize58( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const;
    bool shouldLog_setQueueSize59( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const;
    bool shouldLog_getStatistics60( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const;
    bool shouldLog_requestToSend61( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_bufferedDataSize62(registration_uid_t rid) const;
    bool shouldLog_hasBufferedData63(registration_uid_t rid) const;
    bool shouldLog_hasOutgoingBufferedData64(registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize65(registration_uid_t rid) const;
    bool shouldLog_routeRTS66( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_routeRTS67( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_requestFlushedNotification68(registration_uid_t rid) const;
    bool shouldLog_route69( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_route70( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver71(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver72( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver73(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver74( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_maceInit75() const;
    bool shouldLog_maceResume76() const;
    bool shouldLog_maceExit77() const;
    bool shouldLog_maceReset78() const;
    bool shouldLog_localAddress79() const;
    bool shouldLog_hashState80() const;
    bool shouldLog_error81( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const;
    bool shouldLog_clearToSend82( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_notifyFlushed83(registration_uid_t rid) const;
    bool shouldLog_deliver84( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver85( const MaceKey& source,  const MaceKey& destination,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver86( const MaceKey& source,  const MaceKey& destination,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError87( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError88( const MaceKey& dest, TransportError::type errorCode,  const Commit& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError89( const MaceKey& dest, TransportError::type errorCode,  const Abort& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_canSend4( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_availableBufferSize5( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize6( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingBufferedDataSize7( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize8( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_incomingMessageQueueSize9(registration_uid_t rid) const;
    bool shouldLog_setWindowSize10( const MaceKey& peer, uint64_t microsec, registration_uid_t rid) const;
    bool shouldLog_setQueueSize11( const MaceKey& peer, uint32_t size, uint32_t threshold, registration_uid_t rid) const;
    bool shouldLog_getStatistics12( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid) const;
    bool shouldLog_requestToSend13( const MaceKey& peer, registration_uid_t rid) const;
    bool shouldLog_bufferedDataSize14(registration_uid_t rid) const;
    bool shouldLog_hasBufferedData15(registration_uid_t rid) const;
    bool shouldLog_hasOutgoingBufferedData16(registration_uid_t rid) const;
    bool shouldLog_outgoingBufferedDataSize17(registration_uid_t rid) const;
    bool shouldLog_requestFlushedNotification18(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver19(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver20( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver21(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver22( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_routeRTS23( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS24( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS25( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS26( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS27( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS28( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS29( const MaceKey& src,  const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_routeRTS30( const MaceKey& src,  const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route31( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route32( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route33( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route34( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send39( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send40( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send41( const MaceKey& dest,  const Commit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send42( const MaceKey& dest,  const Abort& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_upcall_messageSent3(message_id_t id, registration_uid_t rid) const;
    bool shouldLog_sendData0( const MaceKey& dest) const;
    bool shouldLog_updateSendable1(OutgoingConnection& c) const;
    bool shouldLog_cancel2( const MaceKey& dest,  const OutgoingMessageData& m, message_id_t id, OutgoingConnection& c) const;
    
    
    public:
    void print(mace::PrintNode& __printer, const std::string& name) const;
    void print(std::ostream& logger) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;
    
    void serialize(std::string& str) const;
    int deserialize(std::istream& is) throw(SerializationException);
    
    //Provided Methods (calls into this service from a higher layer)
    message_id_t provisionalRoute(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        const MaceKey& dest
#line 949 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        const std::string& s
#line 953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t cancel(
        #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        message_id_t id
#line 962 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 966 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    message_id_t cancelFront(
        #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        const MaceKey& dest
#line 971 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 975 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void messageStatus(
        #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        message_id_t id
#line 980 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        uint32_t& size
#line 984 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
        uint32_t& sent
#line 988 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 992 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    registration_uid_t registerHandler(
        #line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 997 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1001 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void unregisterHandler(
        #line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 1006 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1010 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void registerUniqueHandler(
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ReceiveDataHandler& handler
#line 1015 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    registration_uid_t registerHandler(
        #line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 1020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void unregisterHandler(
        #line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 1029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void registerUniqueHandler(
        #line 67 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        NetworkErrorHandler& handler
#line 1038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    registration_uid_t registerHandler(
        #line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        MessageStatusHandler& handler
#line 1043 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void unregisterHandler(
        #line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        MessageStatusHandler& handler
#line 1052 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1056 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void registerUniqueHandler(
        #line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        MessageStatusHandler& handler
#line 1061 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    registration_uid_t registerHandler(
        #line 72 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 1066 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 72 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1070 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void unregisterHandler(
        #line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 1075 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        registration_uid_t rid
#line 1079 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void registerUniqueHandler(
        #line 75 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
        ConnectionStatusHandler& handler
#line 1084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool canSend(
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t availableBufferSize(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1098 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t outgoingBufferedDataSize(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1111 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t incomingBufferedDataSize(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1116 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t incomingMessageQueueSize(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1125 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t incomingMessageQueueSize(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1134 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void setWindowSize(
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1139 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint64_t microsec
#line 1143 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1147 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void setQueueSize(
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1152 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t size
#line 1156 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t threshold
#line 1160 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1164 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    const BufferStatisticsPtr getStatistics(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        TransportServiceClass::Connection::type d
#line 1173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1177 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void requestToSend(
        #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t bufferedDataSize(
        #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool hasBufferedData(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool hasOutgoingBufferedData(
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1201 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t outgoingBufferedDataSize(
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool routeRTS(
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 1211 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 1215 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1219 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool routeRTS(
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& src
#line 1224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& dest
#line 1228 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const std::string& s
#line 1232 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid
#line 1236 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void requestFlushedNotification(
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid
#line 1241 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool route(
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1246 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 1250 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 1254 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool route(
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& src
#line 1259 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 1267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 1271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 1276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 1285 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 1290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1295 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 1299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
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
#line 1312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 1316 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 1320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 1324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 1329 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1333 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 1337 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 1341 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 1346 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1350 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 1354 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 1358 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void clearToSend(
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        const MaceKey& peer
#line 1363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
        registration_uid_t rid
#line 1367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid
#line 1372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    
    //Registration Methods (for dynamic registration)
    
    
    protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.
    
    //Constructor Parameter (Variables)
    
    #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    uint32_t const  maxQueueSize
#line 1388 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    uint32_t const  queueThresholdArg
#line 1393 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    //ServiceVariables and Registration UIDs
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& _router;
#line 1400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    registration_uid_t router;
    
    //Aspect Methods
    
    
    //Registration Typedefs and Maps
    typedef std::map<int, ReceiveDataHandler* > maptype_ReceiveDataHandler;
    maptype_ReceiveDataHandler map_ReceiveDataHandler;
    typedef std::map<int, NetworkErrorHandler* > maptype_NetworkErrorHandler;
    maptype_NetworkErrorHandler map_NetworkErrorHandler;
    typedef std::map<int, ConnectionStatusHandler* > maptype_ConnectionStatusHandler;
    maptype_ConnectionStatusHandler map_ConnectionStatusHandler;
    typedef std::map<int, MessageStatusHandler* > maptype_MessageStatusHandler;
    maptype_MessageStatusHandler map_MessageStatusHandler;
    
    //State Variables
    
    #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    OutgoingConnectionMap out
#line 1420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    IncomingConnectionMap in
#line 1425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    MessageDestinationMap destinations
#line 1430 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 86 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    uint32_t threshold
#line 1435 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    //Timer Vars
    
    
    //Context Declaration
    
    
    //Timer Methods
    
    
    //Async Helper Methods
    
    
    //Async Helper Methods
    
    
    //Sync Methods
    
    
    //Sync Helper Methods
    
    
    //Merge Class Declarations
    
    
    //Downcall and Upcall helper methods
    
    bool downcall_canSend(
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1471 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_availableBufferSize(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_outgoingBufferedDataSize(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_incomingBufferedDataSize(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_incomingMessageQueueSize(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1503 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1507 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_incomingMessageQueueSize(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1512 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_setWindowSize(
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1517 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint64_t microsec
#line 1521 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1525 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_setQueueSize(
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t size
#line 1534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        uint32_t threshold = UINT_MAX
#line 1538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    const BufferStatisticsPtr downcall_getStatistics(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1547 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        TransportServiceClass::Connection::type d
#line 1551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1555 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_requestToSend(
        #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        const MaceKey& peer
#line 1560 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
        registration_uid_t rid = -1
#line 1564 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_bufferedDataSize(
        #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1569 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_hasBufferedData(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1574 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_hasOutgoingBufferedData(
        #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1579 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    uint32_t downcall_outgoingBufferedDataSize(
        #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1584 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_requestFlushedNotification(
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1589 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1594 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 1603 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1613 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 1617 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Message& s_deserialized
#line 1626 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1635 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 1639 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1643 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1648 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 1652 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1656 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1661 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 1665 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1669 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1674 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1678 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Message& s_deserialized
#line 1682 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1691 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1695 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 1699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1708 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1712 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 1716 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1720 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_routeRTS(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 1733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1737 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1742 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Message& s_deserialized
#line 1746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1750 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 1759 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1763 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 1772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1776 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1781 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 1785 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1789 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Message& s_deserialized
#line 1802 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1811 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 1819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1828 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1832 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 1836 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1840 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 1845 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1849 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 3 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 1853 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1857 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1862 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Message& s_deserialized
#line 1866 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1875 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 1879 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1883 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1888 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 1892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1896 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t downcall_send(
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 1901 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 1905 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 7 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 1909 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 1914 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 1918 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 1922 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 1926 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 1931 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message = ""
#line 1939 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 1943 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 1948 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1952 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 1956 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 1960 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_clearToSend(
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        const MaceKey& peer
#line 1965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
        registration_uid_t rid = -1
#line 1969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_notifyFlushed(
        #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
        registration_uid_t rid = -1
#line 1974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_messageSent(
        #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
        message_id_t id
#line 1979 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
        registration_uid_t rid = -1
#line 1983 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void upcall_messageCanceled(
        #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
        const MaceKey& src
#line 1988 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
        uint32_t bytes
#line 1992 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
        registration_uid_t rid = -1
#line 1996 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    
    //Serialized form Method Helpers
    
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& source
#line 2004 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& destination
#line 2008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& s_deserialized
#line 2012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& source
#line 2021 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& destination
#line 2025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& s_deserialized
#line 2029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void deliver(
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& source
#line 2038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& destination
#line 2042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& s_deserialized
#line 2046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2050 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& message_deserialized
#line 2063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 2067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& message_deserialized
#line 2080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 2084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& message_deserialized
#line 2097 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid = -1
#line 2101 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    
    //Transition and Guard Method Declarations
    void downcall_0_maceInit();
    bool guard_downcall_0_maceInit() const;
    message_id_t downcall_1_provisionalRoute(
        #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const std::string& s
#line 2114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 117 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid
#line 2118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_1_provisionalRoute(
        #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 116 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        std::string const & s
#line 2127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 117 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t const  rid
#line 2131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    bool downcall_2_route(
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const std::string& s
#line 2140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid
#line 2144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_2_route(
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2149 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        std::string const & s
#line 2153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 138 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t const  rid
#line 2157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    message_id_t downcall_3_cancelFront(
        #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2162 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_3_cancelFront(
        #line 147 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    size_t downcall_4_cancel(
        #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        message_id_t id
#line 2172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_4_cancel(
        #line 161 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        message_id_t const  id
#line 2177 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    bool downcall_5_canSend(
        #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_5_canSend(
        #line 174 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2187 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    uint32_t downcall_6_availableBufferSize(
        #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2192 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_6_availableBufferSize(
        #line 182 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    uint32_t downcall_7_incomingBufferedDataSize(
        #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 2202 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_downcall_7_incomingBufferedDataSize(
        #line 193 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & src
#line 2207 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void downcall_8_messageStatus(
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        message_id_t id
#line 2212 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        uint32_t& size
#line 2216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        uint32_t& sent
#line 2220 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    bool guard_downcall_8_messageStatus(
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        message_id_t const  id
#line 2225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        uint32_t const & size
#line 2229 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 202 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        uint32_t const & sent
#line 2233 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_9_error(
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 2238 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type ec
#line 2242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const std::string& message
#line 2246 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_9_error(
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & src
#line 2251 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type const  ec
#line 2255 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 221 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        std::string const & message
#line 2259 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_10_deliver(
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 2264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2268 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& m
#line 2272 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_10_deliver(
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & src
#line 2277 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 226 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Data const & m
#line 2285 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_11_deliver(
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 2290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& m
#line 2298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_11_deliver(
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & src
#line 2303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2307 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 230 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Commit const & m
#line 2311 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_12_deliver(
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& src
#line 2316 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& m
#line 2324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_12_deliver(
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & src
#line 2329 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2333 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 238 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Abort const & m
#line 2337 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_13_clearToSend(
        #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_13_clearToSend(
        #line 250 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2347 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_14_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2352 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2356 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Data& message_deserialized
#line 2360 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid
#line 2364 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_14_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type const  errorCode
#line 2373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Data const & message_deserialized
#line 2377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t const  rid
#line 2381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_15_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Commit& message_deserialized
#line 2394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid
#line 2398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_15_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type const  errorCode
#line 2407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Commit const & message_deserialized
#line 2411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t const  rid
#line 2415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    void upcall_16_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type errorCode
#line 2424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const Abort& message_deserialized
#line 2428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t rid
#line 2432 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    bool guard_upcall_16_messageError(
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        MaceKey const & dest
#line 2437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        TransportError::type const  errorCode
#line 2441 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        Abort const & message_deserialized
#line 2445 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        registration_uid_t const  rid
#line 2449 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ) const;
    
    //Routines
    void sendData(
        #line 257 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2456 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    void updateSendable(
        #line 302 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        OutgoingConnection& c
#line 2461 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    size_t cancel(
        #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const MaceKey& dest
#line 2466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        const OutgoingMessageData& m
#line 2470 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 308 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        message_id_t id
#line 2474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 309 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
        OutgoingConnection& c
#line 2478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    
    //Deferal Variables
    mace::deque<__DeferralArgsFormessageSent_message_id_t___registration_uid_t__, mace::SoftState> __deferralArgList_messageSent_message_id_t___registration_uid_t__;
    
    
    //Local Address
    MaceKey __local_address;
    MaceKey downcall_localAddress() const;
    const MaceKey& downcall_localAddress(const registration_uid_t& rid) const;
    
    //Defer methods
    
    void defer_upcall_messageSent(
        #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
        message_id_t id
#line 2495 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
        ,
        #line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
        registration_uid_t rid = -1
#line 2499 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    );
    
    
    //Pre and Post Transition Demux Method Declarations
    
    
    public:
    
    
    static bool checkSafetyProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("ProvisionalTransport::checkSafetyProperties");
      maceout << "Testing safety properties" << Log::endl;
      { maceout << "Safety Properties: check" << Log::endl; return true; }
    }
    
    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("ProvisionalTransport::checkLivenessProperties");
      maceout << "Testing liveness properties" << Log::endl;
      { maceout << "Liveness Properties: check" << Log::endl; return true; }
    }
    
    protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("ProvisionalTransport::castNode::MaceKey");
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
    
    #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    message_id_t id
#line 2567 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::string data
#line 2572 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
  };
  
  class Data : public Message, public mace::PrintPrintable {
    private:
    Data_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Data() : _data_store_(new Data_struct()), serializedByteSize(0) , id(_data_store_->id), data(_data_store_->data) {}
    Data(message_id_t const & my_id, mace::string const & my_data) : _data_store_(NULL), serializedByteSize(0), id(my_id), data(my_data) {}
    Data(const Data& _orig) : _data_store_(new Data_struct( *_orig._data_store_)), serializedByteSize(0) , id(_data_store_->id), data(_data_store_->data) {
    }
    virtual ~Data() { delete _data_store_; _data_store_ = NULL; }
    
    message_id_t const & id;
    mace::string const & data;
    
    static const uint8_t messageType = 1;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Data::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Data(";
          __out << "id=";  mace::printItem(__out, &(id));
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
      
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &id);
#line 2619 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &data);
#line 2624 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
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
      
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->id);
#line 2639 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->data);
#line 2644 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, id INT, data TEXT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_id", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _idIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _idIndex;
      __out << "\t";
      if (Base64::isPrintable(data)) {
        __out << data;
      }
      else {
        __out << HashString::hash(data);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&id, __node->children[0]);
      
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
  
  
  struct Commit_struct {
    
    #line 96 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    message_id_t id
#line 2693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 97 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::string data
#line 2698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 98 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    registration_uid_t rid
#line 2703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
  };
  
  class Commit : public Message, public mace::PrintPrintable {
    private:
    Commit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Commit() : _data_store_(new Commit_struct()), serializedByteSize(0) , id(_data_store_->id), data(_data_store_->data), rid(_data_store_->rid) {}
    Commit(message_id_t const & my_id, mace::string const & my_data, registration_uid_t const & my_rid) : _data_store_(NULL), serializedByteSize(0), id(my_id), data(my_data), rid(my_rid) {}
    Commit(const Commit& _orig) : _data_store_(new Commit_struct( *_orig._data_store_)), serializedByteSize(0) , id(_data_store_->id), data(_data_store_->data), rid(_data_store_->rid) {
    }
    virtual ~Commit() { delete _data_store_; _data_store_ = NULL; }
    
    message_id_t const & id;
    mace::string const & data;
    registration_uid_t const & rid;
    
    static const uint8_t messageType = 2;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Commit::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Commit(";
          __out << "id=";  mace::printItem(__out, &(id));
          __out << ", ";
          __out << "data=";  mace::printItem(__out, &(data));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
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
      
      #line 96 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &id);
#line 2753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 97 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &data);
#line 2758 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 98 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &rid);
#line 2763 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
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
      
      #line 96 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->id);
#line 2778 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 97 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->data);
#line 2783 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 98 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rid);
#line 2788 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, id INT, data TEXT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_id", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _idIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _idIndex;
      __out << "\t";
      if (Base64::isPrintable(data)) {
        __out << data;
      }
      else {
        __out << HashString::hash(data);
      }
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&id, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
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
  
  
  struct Abort_struct {
    
    #line 102 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    message_id_t id
#line 2842 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
    
    #line 103 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    registration_uid_t rid
#line 2847 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
    ;
  };
  
  class Abort : public Message, public mace::PrintPrintable {
    private:
    Abort_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    Abort() : _data_store_(new Abort_struct()), serializedByteSize(0) , id(_data_store_->id), rid(_data_store_->rid) {}
    Abort(message_id_t const & my_id, registration_uid_t const & my_rid) : _data_store_(NULL), serializedByteSize(0), id(my_id), rid(my_rid) {}
    Abort(const Abort& _orig) : _data_store_(new Abort_struct( *_orig._data_store_)), serializedByteSize(0) , id(_data_store_->id), rid(_data_store_->rid) {
    }
    virtual ~Abort() { delete _data_store_; _data_store_ = NULL; }
    
    message_id_t const & id;
    registration_uid_t const & rid;
    
    static const uint8_t messageType = 3;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return Abort::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "Abort(";
          __out << "id=";  mace::printItem(__out, &(id));
          __out << ", ";
          __out << "rid=";  mace::printItem(__out, &(rid));
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
      
      #line 102 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &id);
#line 2894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 103 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      mace::serialize(str, &rid);
#line 2899 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
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
      
      #line 102 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->id);
#line 2914 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      
      #line 103 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rid);
#line 2919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, id INT, rid INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_id", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_rid", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _idIndex = __node->children[0]->nextId;
      int _ridIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _idIndex;
      __out << "\t" << _ridIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&id, __node->children[0]);
      mace::sqlize(&rid, __node->children[1]);
      
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
}
#endif
