/*********************************************
*  DeferredRouteTransportWrapper header file
*  Mace generated on:
*  Tue Apr 10 10:09:47 2012
*********************************************/

#ifndef DeferredRouteTransportWrapper_header
#define DeferredRouteTransportWrapper_header

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
#include "DeferredRouteTransportWrapper-constants.h"
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
#line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
#include "lib/GlobalCommit.h"
#include "ThreadStructure.h"
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
namespace DeferredRouteTransportWrapper_namespace {
  
  void load_protocol();
  
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  const std::string selector_upcall_deliver_2_transition = "DeferredRouteTransportWrapper::deliver::Data::(true)";
  const std::string selector_registerHandler_demux_3 = "DeferredRouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_resumeDeliver_downcall_2 = "DeferredRouteTransportWrapper::resumeDeliver::(downcall)";
  const std::string selector_downcall_maceInit_0_transition = "DeferredRouteTransportWrapper::maceInit::(true)";
  const std::string selector_messageError_demux_25 = "DeferredRouteTransportWrapper::messageError::(demux)";
  const std::string selector_localAddress_demux_22 = "DeferredRouteTransportWrapper::localAddress::(demux)";
  const std::string selector_maceReset_demux_21 = "DeferredRouteTransportWrapper::maceReset::(demux)";
  const std::string selector_resumeDeliver_demux_16 = "DeferredRouteTransportWrapper::resumeDeliver::(demux)";
  const std::string selector_registerUniqueHandler_demux_8 = "DeferredRouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_registerHandler_demux_9 = "DeferredRouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_commitCallBack_routine_0 = "DeferredRouteTransportWrapper::commitCallBack::(routine)";
  const std::string selector_downcall_route_1_transition = "DeferredRouteTransportWrapper::route::(true)";
  const std::string selector_messageError_upcall_2 = "DeferredRouteTransportWrapper::messageError::(upcall)";
  const std::string selector_registerUniqueHandler_demux_11 = "DeferredRouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_upcall_messageError_4_transition = "DeferredRouteTransportWrapper::messageError::Data::(true)";
  const std::string selector_suspendDeliver_demux_14 = "DeferredRouteTransportWrapper::suspendDeliver::(demux)";
  const std::string selector_suspendDeliver_downcall_1 = "DeferredRouteTransportWrapper::suspendDeliver::(downcall)";
  const std::string selector_error_upcall_1 = "DeferredRouteTransportWrapper::error::(upcall)";
  const std::string selector_route_downcall_6 = "DeferredRouteTransportWrapper::route::Message::(downcall)";
  const std::string selector_unregisterHandler_demux_7 = "DeferredRouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_maceExit_demux_20 = "DeferredRouteTransportWrapper::maceExit::(demux)";
  const std::string selector_upcall_messageError_5_transition = "DeferredRouteTransportWrapper::messageError::Data::(true)";
  const std::string selector_send_downcall_12 = "DeferredRouteTransportWrapper::send::(downcall)";
  const std::string selector_error_demux_0 = "DeferredRouteTransportWrapper::error::(demux)";
  const std::string selector_deliver_demux_1 = "DeferredRouteTransportWrapper::deliver::Data::(demux)";
  const std::string selector_route_downcall_5 = "DeferredRouteTransportWrapper::route::Data::(downcall)";
  const std::string selector_maceResume_demux_19 = "DeferredRouteTransportWrapper::maceResume::(demux)";
  const std::string selector_route_downcall_11 = "DeferredRouteTransportWrapper::route::(downcall)";
  const std::string selector_forward_upcall_3 = "DeferredRouteTransportWrapper::forward::(upcall)";
  const std::string selector_route_downcall_7 = "DeferredRouteTransportWrapper::route::Data::(downcall)";
  const std::string selector_route_downcall_10 = "DeferredRouteTransportWrapper::route::(downcall)";
  const std::string selector_resumeDeliver_demux_17 = "DeferredRouteTransportWrapper::resumeDeliver::(demux)";
  const std::string selector_registerUniqueHandler_demux_5 = "DeferredRouteTransportWrapper::registerUniqueHandler::(demux)";
  const std::string selector_route_demux_12 = "DeferredRouteTransportWrapper::route::(demux)";
  const std::string selector_messageError_demux_2 = "DeferredRouteTransportWrapper::messageError::Data::(demux)";
  const std::string selector_deliver_upcall_0 = "DeferredRouteTransportWrapper::deliver::(upcall)";
  const std::string selector_unregisterHandler_demux_4 = "DeferredRouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_maceInit_demux_18 = "DeferredRouteTransportWrapper::maceInit::(demux)";
  const std::string selector_registerHandler_demux_6 = "DeferredRouteTransportWrapper::registerHandler::(demux)";
  const std::string selector_hashState_demux_23 = "DeferredRouteTransportWrapper::hashState::(demux)";
  const std::string selector_send_downcall_9 = "DeferredRouteTransportWrapper::send::Data::(downcall)";
  const std::string selector_unregisterHandler_demux_10 = "DeferredRouteTransportWrapper::unregisterHandler::(demux)";
  const std::string selector_suspendDeliver_demux_15 = "DeferredRouteTransportWrapper::suspendDeliver::(demux)";
  const std::string selector_route_downcall_4 = "DeferredRouteTransportWrapper::route::Message::(downcall)";
  const std::string selector_upcall_error_3_transition = "DeferredRouteTransportWrapper::error::(true)";
  const std::string selector_deliver_demux_24 = "DeferredRouteTransportWrapper::deliver::(demux)";
  const std::string selector_suspendDeliver_downcall_0 = "DeferredRouteTransportWrapper::suspendDeliver::(downcall)";
  const std::string selector_route_demux_13 = "DeferredRouteTransportWrapper::route::(demux)";
  const std::string selector_send_downcall_8 = "DeferredRouteTransportWrapper::send::Message::(downcall)";
  const std::string selector_resumeDeliver_downcall_3 = "DeferredRouteTransportWrapper::resumeDeliver::(downcall)";
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  class Packet;
  //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
  typedef mace::multimap<uint64_t, Packet> MessageQueue;
  //END: Mace::Compiler::ServiceImpl::printTypeDefs
  
  //Message Declarations
  class Data;
  
  
  //Context Forward Declarations
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  
  class DeferredRouteTransportWrapperService;
  typedef DeferredRouteTransportWrapperService ServiceType;
  typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;
  typedef mace::map<int, DeferredRouteTransportWrapperService const *, mace::SoftState> _NodeMap_;
  typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;
  mace::map<mace::string, mace::string> returnValueMapping;
  std::map<mace::string, pthread_mutex_t> mutexMapping;
  static const char* __SERVICE__ __attribute((unused)) = "DeferredRouteTransportWrapper";
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
  class Packet : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    
    #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MaceKey src
#line 141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    MaceKey get_src() const { return src; }
    
    #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MaceKey dest
#line 147 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    MaceKey get_dest() const { return dest; }
    
    #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    registration_uid_t regId
#line 153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    registration_uid_t get_regId() const { return regId; }
    
    #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    mace::string data
#line 159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    mace::string get_data() const { return data; }
    Packet() : src(), dest(), regId(), data() {}
    Packet(MaceKey const & _src, MaceKey const & _dest, registration_uid_t const & _regId, mace::string const & _data) : serializedByteSize(0), src(_src), dest(_dest), regId(_regId), data(_data) {}
    virtual ~Packet() {}
    
    void print(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode __PacketPrinter(__name, "Packet");
      mace::printItem(__PacketPrinter, "src", &(src));;
      mace::printItem(__PacketPrinter, "dest", &(dest));;
      mace::printItem(__PacketPrinter, "regId", &(regId));;
      mace::printItem(__PacketPrinter, "data", &(data));
      __pr.addChild(__PacketPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "Packet("  ;
          __out << "src=";  mace::printItem(__out, &(src));
          __out << ", ";
          __out << "dest=";  mace::printItem(__out, &(dest));
          __out << ", ";
          __out << "regId=";  mace::printItem(__out, &(regId));
          __out << ", ";
          __out << "data=";  mace::printItem(__out, &(data));
          __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "Packet(" ;
          __out << "src=";  mace::printState(__out, &(src), (src));
          __out << ", ";
          __out << "dest=";  mace::printState(__out, &(dest), (dest));
          __out << ", ";
          __out << "regId=";  mace::printState(__out, &(regId), (regId));
          __out << ", ";
          __out << "data=";  mace::printState(__out, &(data), (data));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      
      #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &src);
#line 201 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &dest);
#line 206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &regId);
#line 211 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &data);
#line 216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      
      #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &src);
#line 225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &dest);
#line 230 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &regId);
#line 235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &data);
#line 240 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, src INT, dest INT, regId INT, data TEXT);" << std::endl;
        __node->children = new mace::LogNode*[3];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_src", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[1] = __child1;
        mace::LogNode* __child2 = new mace::LogNode(__node->logName + "_regId", Log::sqlEventsLog);
        __node->children[2] = __child2;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _srcIndex = __node->children[0]->nextId;
      int _destIndex = __node->children[1]->nextId;
      int _regIdIndex = __node->children[2]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _srcIndex;
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
      mace::sqlize(&src, __node->children[0]);
      mace::sqlize(&dest, __node->children[1]);
      mace::sqlize(&regId, __node->children[2]);
      
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
        
        if (__var == "src") {
          mace::deserializeXML_RPC(__mace_in, & src, src);
        } else
        if (__var == "dest") {
          mace::deserializeXML_RPC(__mace_in, & dest, dest);
        } else
        if (__var == "regId") {
          mace::deserializeXML_RPC(__mace_in, & regId, regId);
        } else
        if (__var == "data") {
          mace::deserializeXML_RPC(__mace_in, & data, data);
        } else
        {
          throw(new mace::SerializationException("deserializing Packet: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 4) {
        throw(new mace::SerializationException("deserializing Packet: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>src</name><value>");
      mace::serializeXML_RPC(str, &(src), src);
      str.append("</value></member>");
      str.append("<member><name>dest</name><value>");
      mace::serializeXML_RPC(str, &(dest), dest);
      str.append("</value></member>");
      str.append("<member><name>regId</name><value>");
      mace::serializeXML_RPC(str, &(regId), regId);
      str.append("</value></member>");
      str.append("<member><name>data</name><value>");
      mace::serializeXML_RPC(str, &(data), data);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
  };
  //END: Mace::Compiler::ServiceImpl::printAutoTypes
  //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
  //END Mace::Compiler::ServiceImpl::printDeferTypes
  //BEGIN: Mace::Compiler::ServiceImpl::printService
  
  class ServiceTester;
  class DeferredRouteTransportWrapperService : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, public virtual RouteServiceClass, public virtual TransportServiceClass, public virtual ReceiveDataHandler, public virtual NetworkErrorHandler
  {
    private:
    
    friend class ServiceTester;
    
    friend class Packet;
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
    DeferredRouteTransportWrapperService(TransportServiceClass& __trans, bool ___shared = true);
    DeferredRouteTransportWrapperService(const DeferredRouteTransportWrapperService& other);
    //Destructor
    virtual ~DeferredRouteTransportWrapperService();
    
    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;
    
    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    private:
    
    const state_type& read_state() const;
    MaceKey const & read_me() const;
    MessageQueue const & read_queued() const;
    pthread_mutex_t const & read_deliverMutex() const;
    
    public:
    //Misc.
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "SNAPSHOT::DeferredRouteTransportWrapper";
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
    static const LogIdSet* selectorId_commitCallBack_routine_0;
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
    bool shouldLog_route14( const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_route15( const MaceKey& src,  const MaceKey& dest,  const std::string& s, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver16(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver17( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver18(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver19( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_maceInit20() const;
    bool shouldLog_maceResume21() const;
    bool shouldLog_maceExit22() const;
    bool shouldLog_maceReset23() const;
    bool shouldLog_localAddress24() const;
    bool shouldLog_hashState25() const;
    bool shouldLog_error26( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const;
    bool shouldLog_deliver27( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError28( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_suspendDeliver1(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver2( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver3(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver4( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_route5( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route6( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route7( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route8( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send9( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send10( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_commitCallBack0(uint64_t myTicket) const;
    
    
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
#line 512 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 516 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ReceiveDataHandler& handler
#line 521 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 525 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 23 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ReceiveDataHandler& handler
#line 530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    registration_uid_t registerHandler(
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 535 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 25 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 544 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 25 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 548 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 27 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        NetworkErrorHandler& handler
#line 553 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    registration_uid_t registerHandler(
        #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 28 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 562 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void unregisterHandler(
        #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 567 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        registration_uid_t rid
#line 571 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void registerUniqueHandler(
        #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RouteServiceClass.h"
        ForwardDataHandler& handler
#line 576 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool route(
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 581 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 585 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 589 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool route(
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& src
#line 594 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 598 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const std::string& s
#line 602 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 606 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 611 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 616 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 620 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid
#line 625 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid
#line 634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
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
#line 647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 651 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 681 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 685 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    
    //Registration Methods (for dynamic registration)
    
    
    protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.
    
    //Constructor Parameter (Variables)
    
    
    //ServiceVariables and Registration UIDs
    
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TransportServiceClass& _trans;
#line 712 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
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
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MaceKey me
#line 730 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    
    #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MessageQueue queued
#line 735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    
    #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    pthread_mutex_t deliverMutex
#line 740 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
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
    
    void downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 777 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 781 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 786 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Message& s_deserialized
#line 804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 813 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& s_deserialized
#line 817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& src
#line 826 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Message& s_deserialized
#line 834 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 838 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool downcall_route(
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& src
#line 843 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 847 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& s_deserialized
#line 851 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    size_t downcall_send(
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 860 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Message& s_deserialized
#line 864 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    size_t downcall_send(
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 873 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& s_deserialized
#line 877 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void upcall_deliver(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& source
#line 886 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void upcall_error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 903 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 907 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message = ""
#line 911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void upcall_messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 928 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid = -1
#line 932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool upcall_forward(
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const MaceKey& source
#line 937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const MaceKey& destination
#line 941 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        MaceKey& nextHop
#line 945 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
        const std::string& s
#line 949 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
        registration_uid_t rid = -1
#line 953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    
    //Serialized form Method Helpers
    
    void deliver(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& source
#line 961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& destination
#line 965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 27 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& s_deserialized
#line 969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 973 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    void messageError(
        #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 978 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type errorCode
#line 982 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& message_deserialized
#line 986 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid = -1
#line 990 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    
    //Transition and Guard Method Declarations
    void downcall_0_maceInit();
    bool guard_downcall_0_maceInit() const;
    bool downcall_1_route(
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 999 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const std::string& msg
#line 1003 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t regId
#line 1007 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool guard_downcall_1_route(
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & dest
#line 1012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        std::string const & msg
#line 1016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t const  regId
#line 1020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ) const;
    void upcall_2_deliver(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& src
#line 1025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 1029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& msg
#line 1033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool guard_upcall_2_deliver(
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & src
#line 1038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & dest
#line 1042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        Data const & msg
#line 1046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ) const;
    void upcall_3_error(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& nodeId
#line 1051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type error_code
#line 1055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const std::string& m
#line 1059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t registrationUid
#line 1063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool guard_upcall_3_error(
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & nodeId
#line 1068 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type const  error_code
#line 1072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        std::string const & m
#line 1076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t const  registrationUid
#line 1080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ) const;
    void upcall_4_messageError(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 1085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type error_code
#line 1089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& msg
#line 1093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t regId
#line 1097 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool guard_upcall_4_messageError(
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & dest
#line 1102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type const  error_code
#line 1106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        Data const & msg
#line 1110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t const  regId
#line 1114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ) const;
    void upcall_5_messageError(
        #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const MaceKey& dest
#line 1119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type errorCode
#line 1123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        const Data& message_deserialized
#line 1127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t rid
#line 1131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    bool guard_upcall_5_messageError(
        #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        MaceKey const & dest
#line 1136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        TransportError::type const  errorCode
#line 1140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        Data const & message_deserialized
#line 1144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
        ,
        #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        registration_uid_t const  rid
#line 1148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ) const;
    
    //Routines
    void commitCallBack(
        #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
        uint64_t myTicket
#line 1155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    );
    
    
    //Deferal Variables
    
    
    //Local Address
    MaceKey __local_address;
    MaceKey downcall_localAddress() const;
    const MaceKey& downcall_localAddress(const registration_uid_t& rid) const;
    
    //Defer methods
    
    
    
    
    //Pre and Post Transition Demux Method Declarations
    
    
    public:
    
    
    static bool checkSafetyProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("DeferredRouteTransportWrapper::checkSafetyProperties");
      maceout << "Testing safety properties" << Log::endl;
      { maceout << "Safety Properties: check" << Log::endl; return true; }
    }
    
    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("DeferredRouteTransportWrapper::checkLivenessProperties");
      maceout << "Testing liveness properties" << Log::endl;
      { maceout << "Liveness Properties: check" << Log::endl; return true; }
    }
    
    protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("DeferredRouteTransportWrapper::castNode::MaceKey");
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
    
    #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MaceKey source
#line 1236 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    
    #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    MaceKey dest
#line 1241 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    
    #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    registration_uid_t regId
#line 1246 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
    ;
    
    #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    mace::string data
#line 1251 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
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
      
      #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &source);
#line 1304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &dest);
#line 1309 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &regId);
#line 1314 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      mace::serialize(str, &data);
#line 1319 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
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
      
      #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->source);
#line 1334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->dest);
#line 1339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 21 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->regId);
#line 1344 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
      
      #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->data);
#line 1349 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper.h"
      
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
  class route14Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_route14";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route14Dummy() : _dest(new MaceKey()), dest(*_dest), _s(new std::string()), s(*_s), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route14Dummy(const MaceKey& ___dest, const std::string& ___s, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s(NULL), s(___s), _rid(NULL), rid(___rid) { }
    
    
    ~route14Dummy() {
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
  class maceInit20Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_maceInit20";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::maceInit()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceInit20Dummy()  { }
    
    
    
    
    ~maceInit20Dummy() {
      
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
  class maceReset23Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_maceReset23";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::maceReset()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceReset23Dummy()  { }
    
    
    
    
    ~maceReset23Dummy() {
      
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
  class hashState25Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_hashState25";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::hashState() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hashState25Dummy()  { }
    
    
    
    
    ~hashState25Dummy() {
      
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
  class error26Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_error26";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::error( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    error26Dummy() : _nodeId(new MaceKey()), nodeId(*_nodeId), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message(new std::string()), message(*_message), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    error26Dummy(const MaceKey& ___nodeId, const TransportError::type& ___errorCode, const std::string& ___message, const registration_uid_t& ___rid) : _nodeId(NULL), nodeId(___nodeId), _errorCode(NULL), errorCode(___errorCode), _message(NULL), message(___message), _rid(NULL), rid(___rid) { }
    
    
    ~error26Dummy() {
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
  class deliver27Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_deliver27";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver27Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver27Dummy(const MaceKey& ___source, const MaceKey& ___destination, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver27Dummy() {
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
  class messageError28Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_messageError28";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError28Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new Data()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError28Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const Data& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError28Dummy() {
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
  class suspendDeliver1Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_suspendDeliver1";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::suspendDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver1Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver1Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver1Dummy() {
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
  class suspendDeliver2Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_suspendDeliver2";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::suspendDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    suspendDeliver2Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    suspendDeliver2Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~suspendDeliver2Dummy() {
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
  class resumeDeliver3Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_resumeDeliver3";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::resumeDeliver(registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver3Dummy() : _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver3Dummy(const registration_uid_t& ___rid) : _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver3Dummy() {
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
  class resumeDeliver4Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_resumeDeliver4";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::resumeDeliver( const MaceKey& dest, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    resumeDeliver4Dummy() : _dest(new MaceKey()), dest(*_dest), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    resumeDeliver4Dummy(const MaceKey& ___dest, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _rid(NULL), rid(___rid) { }
    
    
    ~resumeDeliver4Dummy() {
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
  class route5Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_route5";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route5Dummy()  { }
    
    
    
    
    ~route5Dummy() {
      
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
  class route6Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_route6";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route6Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route6Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route6Dummy() {
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
  class route7Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_route7";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route7Dummy()  { }
    
    
    
    
    ~route7Dummy() {
      
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
  class route8Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_route8";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route8Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route8Dummy(const MaceKey& ___src, const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route8Dummy() {
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
  class send9Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_send9";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send9Dummy()  { }
    
    
    
    
    ~send9Dummy() {
      
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
  class send10Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
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
      static std::string type = "DeferredRouteTransportWrapper_send10";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send10Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new Data()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send10Dummy(const MaceKey& ___dest, const Data& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send10Dummy() {
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
  class commitCallBack0Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    uint64_t* _myTicket;
    const uint64_t& myTicket;
    
    const std::string& getLogType() const {
      static std::string type = "DeferredRouteTransportWrapper_commitCallBack0";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "DeferredRouteTransportWrapper::commitCallBack(uint64_t myTicket)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    commitCallBack0Dummy() : _myTicket(new uint64_t()), myTicket(*_myTicket) { }
    
    
    commitCallBack0Dummy(const uint64_t& ___myTicket) : _myTicket(NULL), myTicket(___myTicket) { }
    
    
    ~commitCallBack0Dummy() {
      if (_myTicket != NULL) { delete _myTicket; _myTicket = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "commitCallBack(";
          out << "[myTicket=";
          mace::printItem(out, &myTicket);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, myTicket NUMERIC(20, 0));" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << myTicket;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
}
#endif
