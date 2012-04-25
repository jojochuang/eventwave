/*********************************************
*  Simple header file
*  Mace generated on:
*  Tue Apr 10 10:10:28 2012
*********************************************/

#ifndef Simple_header
#define Simple_header

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
#include "Simple-constants.h"
#include "lib/ContextBaseClass.h"
#include "lib/ContextLock.h"
#include "lib/ContextMapping.h"
#include "HighLevelEvent.h"

#include "lib/Message.h"
#include "NullServiceClass.h"
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
#line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
#include "boost/format.hpp"
#include <sstream>
#include <math.h>
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
namespace Simple_namespace {
  
  void load_protocol();
  
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  const std::string selector_route_downcall_30 = "Simple::route::HeadEvent::(downcall)";
  const std::string selector_send_downcall_61 = "Simple::send::__sync_at5_testRCX::(downcall)";
  const std::string selector_messageError_demux_32 = "Simple::messageError::__sync_at1_sctest::(demux)";
  const std::string selector_messageError_demux_25 = "Simple::messageError::HeadEvent::(demux)";
  const std::string selector_deliver_demux_12 = "Simple::deliver::__target_async_at8_testMulti::(demux)";
  const std::string selector_upcall_messageError_33_transition = "Simple::messageError::ContextMappingUpdate::(true)";
  const std::string selector_maceReset_demux_42 = "Simple::maceReset::(demux)";
  const std::string selector_upcall_messageError_44_transition = "Simple::messageError::__target_sync_at3_cellInit::(true)";
  const std::string selector_upcall_messageError_39_transition = "Simple::messageError::__async_at8_testMulti::(true)";
  const std::string selector_messageError_demux_34 = "Simple::messageError::__sync_at3_cellInit::(demux)";
  const std::string selector_async_testMulti_async_2 = "Simple::async_testMulti::(async)";
  const std::string selector_route_downcall_35 = "Simple::route::__async_at8_testMulti::(downcall)";
  const std::string selector_route_downcall_25 = "Simple::route::__internal_Ack::(downcall)";
  const std::string selector_rowAfter_demux_51 = "Simple::rowAfter::(demux)";
  const std::string selector_route_downcall_6 = "Simple::route::ContextMigrationRequest::(downcall)";
  const std::string selector_send_downcall_58 = "Simple::send::__target_sync_at1_sctest::(downcall)";
  const std::string selector_send_downcall_62 = "Simple::send::__target_sync_at5_testRCX::(downcall)";
  const std::string selector_send_downcall_53 = "Simple::send::__async_at4_rowAfter::(downcall)";
  const std::string selector_target_async_rowInit_sync_0 = "Simple::target_async_rowInit::(sync)";
  const std::string selector_upcall_deliver_23_transition = "Simple::deliver::__target_sync_at1_sctest::(true)";
  const std::string selector_send_downcall_54 = "Simple::send::__target_async_at4_rowAfter::(downcall)";
  const std::string selector_expireresender_timer = "Simple::expire::resender_timer::(timer)";
  const std::string selector_route_downcall_65 = "Simple::route::(downcall)";
  const std::string selector_route_downcall_20 = "Simple::route::__target_sync_at3_cellInit::(downcall)";
  const std::string selector_sync_sctest_1_transition = "Simple::sctest::(state==init)";
  const std::string selector_upcall_deliver_25_transition = "Simple::deliver::__target_sync_at3_cellInit::(true)";
  const std::string selector_route_downcall_34 = "Simple::route::__target_async_at4_rowAfter::(downcall)";
  const std::string selector_upcall_deliver_26_transition = "Simple::deliver::__sync_at5_testRCX::(true)";
  const std::string selector_cancelctsTimer = "Simple::cancel::ctsTimer::(timer)";
  const std::string selector_upcall_deliver_14_transition = "Simple::deliver::ContextMappingUpdate::(true)";
  const std::string selector_upcall_messageError_41_transition = "Simple::messageError::__sync_at1_sctest::(true)";
  const std::string selector_route_downcall_10 = "Simple::route::HeadEvent::(downcall)";
  const std::string selector_snapshot_sync_fn_sync_11 = "Simple::snapshot_sync_fn::(sync)";
  const std::string selector_deliver_demux_19 = "Simple::deliver::__sync_at_snapshot::(demux)";
  const std::string selector_messageError_demux_22 = "Simple::messageError::TransferContext::(demux)";
  const std::string selector_route_downcall_42 = "Simple::route::__target_sync_at5_testRCX::(downcall)";
  const std::string selector_route_downcall_27 = "Simple::route::TransferContext::(downcall)";
  const std::string selector_localAddress_demux_43 = "Simple::localAddress::(demux)";
  const std::string selector_send_downcall_44 = "Simple::send::Message::(downcall)";
  const std::string selector_route_downcall_17 = "Simple::route::__sync_at1_sctest::(downcall)";
  const std::string selector_deliver_demux_2 = "Simple::deliver::ContextMigrationRequest::(demux)";
  const std::string selector_messageError_demux_30 = "Simple::messageError::__async_at8_testMulti::(demux)";
  const std::string selector_upcall_deliver_21_transition = "Simple::deliver::__target_async_at8_testMulti::(true)";
  const std::string selector_route_downcall_37 = "Simple::route::__sync_at1_sctest::(downcall)";
  const std::string selector_expiret = "Simple::expire::t::(timer)";
  const std::string selector_send_downcall_48 = "Simple::send::ReportContextMigration::(downcall)";
  const std::string selector_expire_resender_timer_demux_47 = "Simple::expire_resender_timer::(demux)";
  const std::string selector_deliver_demux_11 = "Simple::deliver::__async_at8_testMulti::(demux)";
  const std::string selector_upcall_messageError_40_transition = "Simple::messageError::__target_async_at8_testMulti::(true)";
  const std::string selector_deliver_demux_6 = "Simple::deliver::HeadEvent::(demux)";
  const std::string selector_upcall_deliver_17_transition = "Simple::deliver::__target_async_at2_rowInit::(true)";
  const std::string selector_send_downcall_66 = "Simple::send::(downcall)";
  const std::string selector_messageError_demux_37 = "Simple::messageError::__target_sync_at5_testRCX::(demux)";
  const std::string selector_cellInit_demux_54 = "Simple::cellInit::(demux)";
  const std::string selector_upcall_messageError_47_transition = "Simple::messageError::__sync_at_snapshot::(true)";
  const std::string selector_deliver_demux_9 = "Simple::deliver::__async_at4_rowAfter::(demux)";
  const std::string selector_resumeDeliver_downcall_2 = "Simple::resumeDeliver::(downcall)";
  const std::string selector_deliver_demux_5 = "Simple::deliver::ContextMappingUpdate::(demux)";
  const std::string selector_deliver_demux_15 = "Simple::deliver::__sync_at3_cellInit::(demux)";
  const std::string selector_target_async_rowAfter_sync_1 = "Simple::target_async_rowAfter::(sync)";
  const std::string selector_maceInit_demux_39 = "Simple::maceInit::(demux)";
  const std::string selector_maceExit_demux_41 = "Simple::maceExit::(demux)";
  const std::string selector_suspendDeliver_downcall_1 = "Simple::suspendDeliver::(downcall)";
  const std::string selector_messageError_demux_29 = "Simple::messageError::__target_async_at4_rowAfter::(demux)";
  const std::string selector_route_downcall_41 = "Simple::route::__sync_at5_testRCX::(downcall)";
  const std::string selector_upcall_deliver_9_transition = "Simple::deliver::__internal_Ack::(true)";
  const std::string selector_send_downcall_49 = "Simple::send::ContextMappingUpdate::(downcall)";
  const std::string selector_upcall_deliver_28_transition = "Simple::deliver::__sync_at_snapshot::(true)";
  const std::string selector_route_downcall_5 = "Simple::route::__internal_Ack::(downcall)";
  const std::string selector_upcall_messageError_35_transition = "Simple::messageError::__async_at2_rowInit::(true)";
  const std::string selector_async_rowInit_async_0 = "Simple::async_rowInit::(async)";
  const std::string selector_upcall_messageError_45_transition = "Simple::messageError::__sync_at5_testRCX::(true)";
  const std::string selector_send_downcall_56 = "Simple::send::__target_async_at8_testMulti::(downcall)";
  const std::string selector_messageError_demux_35 = "Simple::messageError::__target_sync_at3_cellInit::(demux)";
  const std::string selector_getStartContext_sync_10 = "Simple::getStartContext::(sync)";
  const std::string selector_route_downcall_32 = "Simple::route::__target_async_at2_rowInit::(downcall)";
  const std::string selector_scheduler_expire_resender_timer_10_transition = "Simple::expire::expire_resender_timer::(true)";
  const std::string selector_upcall_deliver_19_transition = "Simple::deliver::__target_async_at4_rowAfter::(true)";
  const std::string selector_send_downcall_50 = "Simple::send::HeadEvent::(downcall)";
  const std::string selector_messageError_demux_49 = "Simple::messageError::(demux)";
  const std::string selector_route_downcall_14 = "Simple::route::__target_async_at4_rowAfter::(downcall)";
  const std::string selector_deliver_demux_18 = "Simple::deliver::__target_sync_at5_testRCX::(demux)";
  const std::string selector_deliver_demux_48 = "Simple::deliver::(demux)";
  const std::string selector_send_downcall_55 = "Simple::send::__async_at8_testMulti::(downcall)";
  const std::string selector_route_downcall_9 = "Simple::route::ContextMappingUpdate::(downcall)";
  const std::string selector_route_downcall_22 = "Simple::route::__target_sync_at5_testRCX::(downcall)";
  const std::string selector_upcall_deliver_16_transition = "Simple::deliver::__async_at2_rowInit::(true)";
  const std::string selector_deliver_demux_16 = "Simple::deliver::__target_sync_at3_cellInit::(demux)";
  const std::string selector_upcall_messageError_43_transition = "Simple::messageError::__sync_at3_cellInit::(true)";
  const std::string selector_upcall_deliver_20_transition = "Simple::deliver::__async_at8_testMulti::(true)";
  const std::string selector_deliver_demux_4 = "Simple::deliver::ReportContextMigration::(demux)";
  const std::string selector_send_downcall_46 = "Simple::send::ContextMigrationRequest::(downcall)";
  const std::string selector_deliver_demux_7 = "Simple::deliver::__async_at2_rowInit::(demux)";
  const std::string selector_upcall_deliver_22_transition = "Simple::deliver::__sync_at1_sctest::(true)";
  const std::string selector_scheduler_expire_t_6_transition = "Simple::expire::expire_t::(true)";
  const std::string selector_target_sync_cellInit_sync_6 = "Simple::target_sync_cellInit::(sync)";
  const std::string selector_route_downcall_16 = "Simple::route::__target_async_at8_testMulti::(downcall)";
  const std::string selector_route_downcall_64 = "Simple::route::(downcall)";
  const std::string selector_upcall_deliver_13_transition = "Simple::deliver::ReportContextMigration::(true)";
  const std::string selector_downcall_maceInit_0_transition = "Simple::maceInit::(state==init)";
  const std::string selector_messageError_demux_31 = "Simple::messageError::__target_async_at8_testMulti::(demux)";
  const std::string selector_hashState_demux_44 = "Simple::hashState::(demux)";
  const std::string selector_deliver_demux_13 = "Simple::deliver::__sync_at1_sctest::(demux)";
  const std::string selector_sctest_demux_53 = "Simple::sctest::(demux)";
  const std::string selector_schedulectsTimer = "Simple::schedule::ctsTimer::(timer)";
  const std::string selector_messageError_demux_33 = "Simple::messageError::__target_sync_at1_sctest::(demux)";
  const std::string selector_expire_ctsTimer_demux_45 = "Simple::expire_ctsTimer::(demux)";
  const std::string selector_deliver_demux_1 = "Simple::deliver::__internal_Ack::(demux)";
  const std::string selector_route_downcall_28 = "Simple::route::ReportContextMigration::(downcall)";
  const std::string selector_upcall_messageError_30_transition = "Simple::messageError::ContextMigrationRequest::(true)";
  const std::string selector_send_downcall_63 = "Simple::send::__sync_at_snapshot::(downcall)";
  const std::string selector_async_testMulti_8_transition = "Simple::testMulti::(true)";
  const std::string selector_async_rowAfter_async_1 = "Simple::async_rowAfter::(async)";
  const std::string selector_messageError_demux_24 = "Simple::messageError::ContextMappingUpdate::(demux)";
  const std::string selector_route_downcall_11 = "Simple::route::__async_at2_rowInit::(downcall)";
  const std::string selector_upcall_deliver_27_transition = "Simple::deliver::__target_sync_at5_testRCX::(true)";
  const std::string selector_send_downcall_52 = "Simple::send::__target_async_at2_rowInit::(downcall)";
  const std::string selector_route_downcall_36 = "Simple::route::__target_async_at8_testMulti::(downcall)";
  const std::string selector_route_downcall_7 = "Simple::route::TransferContext::(downcall)";
  const std::string selector_route_downcall_33 = "Simple::route::__async_at4_rowAfter::(downcall)";
  const std::string selector_upcall_deliver_18_transition = "Simple::deliver::__async_at4_rowAfter::(true)";
  const std::string selector_target_async_testMulti_sync_2 = "Simple::target_async_testMulti::(sync)";
  const std::string selector_send_downcall_45 = "Simple::send::__internal_Ack::(downcall)";
  const std::string selector_route_downcall_24 = "Simple::route::Message::(downcall)";
  const std::string selector_async_rowAfter_4_transition = "Simple::rowAfter::(true)";
  const std::string selector_send_downcall_47 = "Simple::send::TransferContext::(downcall)";
  const std::string selector_sync_sctest_sync_3 = "Simple::sync_sctest::(sync)";
  const std::string selector_upcall_messageError_31_transition = "Simple::messageError::TransferContext::(true)";
  const std::string selector_messageError_demux_20 = "Simple::messageError::__internal_Ack::(demux)";
  const std::string selector_route_downcall_43 = "Simple::route::__sync_at_snapshot::(downcall)";
  const std::string selector_route_downcall_18 = "Simple::route::__target_sync_at1_sctest::(downcall)";
  const std::string selector_schedulet = "Simple::schedule::t::(timer)";
  const std::string selector_messageError_demux_26 = "Simple::messageError::__async_at2_rowInit::(demux)";
  const std::string selector_route_downcall_19 = "Simple::route::__sync_at3_cellInit::(downcall)";
  const std::string selector_scheduler_expire_ctsTimer_7_transition = "Simple::expire::expire_ctsTimer::(true)";
  const std::string selector_send_downcall_59 = "Simple::send::__sync_at3_cellInit::(downcall)";
  const std::string selector_deliver_demux_10 = "Simple::deliver::__target_async_at4_rowAfter::(demux)";
  const std::string selector_messageError_demux_38 = "Simple::messageError::__sync_at_snapshot::(demux)";
  const std::string selector_upcall_messageError_38_transition = "Simple::messageError::__target_async_at4_rowAfter::(true)";
  const std::string selector_expirectsTimer = "Simple::expire::ctsTimer::(timer)";
  const std::string selector_route_downcall_4 = "Simple::route::Message::(downcall)";
  const std::string selector_sync_cellInit_3_transition = "Simple::cellInit::(state==init)";
  const std::string selector_maceResume_demux_40 = "Simple::maceResume::(demux)";
  const std::string selector_target_sync_testRCX_sync_8 = "Simple::target_sync_testRCX::(sync)";
  const std::string selector_resumeDeliver_downcall_3 = "Simple::resumeDeliver::(downcall)";
  const std::string selector_route_downcall_39 = "Simple::route::__sync_at3_cellInit::(downcall)";
  const std::string selector_route_downcall_8 = "Simple::route::ReportContextMigration::(downcall)";
  const std::string selector_route_downcall_15 = "Simple::route::__async_at8_testMulti::(downcall)";
  const std::string selector_async_rowInit_2_transition = "Simple::rowInit::(state==init)";
  const std::string selector_send_downcall_57 = "Simple::send::__sync_at1_sctest::(downcall)";
  const std::string selector_route_downcall_23 = "Simple::route::__sync_at_snapshot::(downcall)";
  const std::string selector_cancelresender_timer = "Simple::cancel::resender_timer::(timer)";
  const std::string selector_testRCX_demux_55 = "Simple::testRCX::(demux)";
  const std::string selector_messageError_demux_21 = "Simple::messageError::ContextMigrationRequest::(demux)";
  const std::string selector_error_demux_0 = "Simple::error::(demux)";
  const std::string selector_route_downcall_26 = "Simple::route::ContextMigrationRequest::(downcall)";
  const std::string selector_deliver_demux_14 = "Simple::deliver::__target_sync_at1_sctest::(demux)";
  const std::string selector_upcall_deliver_12_transition = "Simple::deliver::TransferContext::(true)";
  const std::string selector_upcall_deliver_11_transition = "Simple::deliver::ContextMigrationRequest::(true)";
  const std::string selector_sync_testRCX_5_transition = "Simple::testRCX::(state==init)";
  const std::string selector_messageError_demux_36 = "Simple::messageError::__sync_at5_testRCX::(demux)";
  const std::string selector_route_downcall_38 = "Simple::route::__target_sync_at1_sctest::(downcall)";
  const std::string selector_messageError_demux_28 = "Simple::messageError::__async_at4_rowAfter::(demux)";
  const std::string selector_rowInit_demux_50 = "Simple::rowInit::(demux)";
  const std::string selector_send_downcall_60 = "Simple::send::__target_sync_at3_cellInit::(downcall)";
  const std::string selector_upcall_messageError_42_transition = "Simple::messageError::__target_sync_at1_sctest::(true)";
  const std::string selector_route_downcall_12 = "Simple::route::__target_async_at2_rowInit::(downcall)";
  const std::string selector_target_sync_sctest_sync_4 = "Simple::target_sync_sctest::(sync)";
  const std::string selector_route_downcall_40 = "Simple::route::__target_sync_at3_cellInit::(downcall)";
  const std::string selector_deliver_demux_8 = "Simple::deliver::__target_async_at2_rowInit::(demux)";
  const std::string selector_route_downcall_21 = "Simple::route::__sync_at5_testRCX::(downcall)";
  const std::string selector_upcall_messageError_32_transition = "Simple::messageError::ReportContextMigration::(true)";
  const std::string selector_route_downcall_31 = "Simple::route::__async_at2_rowInit::(downcall)";
  const std::string selector_route_downcall_13 = "Simple::route::__async_at4_rowAfter::(downcall)";
  const std::string selector_messageError_demux_27 = "Simple::messageError::__target_async_at2_rowInit::(demux)";
  const std::string selector_upcall_messageError_29_transition = "Simple::messageError::__internal_Ack::(true)";
  const std::string selector_upcall_messageError_34_transition = "Simple::messageError::HeadEvent::(true)";
  const std::string selector_expire_t_demux_46 = "Simple::expire_t::(demux)";
  const std::string selector_send_downcall_51 = "Simple::send::__async_at2_rowInit::(downcall)";
  const std::string selector_scheduleresender_timer = "Simple::schedule::resender_timer::(timer)";
  const std::string selector_findContextByID_sync_9 = "Simple::findContextByID::(sync)";
  const std::string selector_deliver_demux_3 = "Simple::deliver::TransferContext::(demux)";
  const std::string selector_upcall_messageError_46_transition = "Simple::messageError::__target_sync_at5_testRCX::(true)";
  const std::string selector_upcall_messageError_37_transition = "Simple::messageError::__async_at4_rowAfter::(true)";
  const std::string selector_upcall_deliver_15_transition = "Simple::deliver::HeadEvent::(true)";
  const std::string selector_sync_testRCX_sync_7 = "Simple::sync_testRCX::(sync)";
  const std::string selector_upcall_messageError_36_transition = "Simple::messageError::__target_async_at2_rowInit::(true)";
  const std::string selector_upcall_deliver_24_transition = "Simple::deliver::__sync_at3_cellInit::(true)";
  const std::string selector_testMulti_demux_52 = "Simple::testMulti::(demux)";
  const std::string selector_sync_cellInit_sync_5 = "Simple::sync_cellInit::(sync)";
  const std::string selector_messageError_demux_23 = "Simple::messageError::ReportContextMigration::(demux)";
  const std::string selector_cancelt = "Simple::cancel::t::(timer)";
  const std::string selector_deliver_demux_17 = "Simple::deliver::__sync_at5_testRCX::(demux)";
  const std::string selector_suspendDeliver_downcall_0 = "Simple::suspendDeliver::(downcall)";
  const std::string selector_route_downcall_29 = "Simple::route::ContextMappingUpdate::(downcall)";
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
  //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
  typedef mace::vector< mace::vector<double> > Matrix;
  //END: Mace::Compiler::ServiceImpl::printTypeDefs
  
  //Message Declarations
  class __internal_Ack;
  class ContextMigrationRequest;
  class TransferContext;
  class ReportContextMigration;
  class ContextMappingUpdate;
  class HeadEvent;
  class __async_at2_rowInit;
  class __target_async_at2_rowInit;
  class __async_at4_rowAfter;
  class __target_async_at4_rowAfter;
  class __async_at8_testMulti;
  class __target_async_at8_testMulti;
  class __sync_at1_sctest;
  class __target_sync_at1_sctest;
  class __sync_at3_cellInit;
  class __target_sync_at3_cellInit;
  class __sync_at5_testRCX;
  class __target_sync_at5_testRCX;
  class __sync_at_snapshot;
  
  
  //Context Forward Declarations
  class __R__Context;
  class __T__Context;
  class __M__Context;
  class __C__Context;
  class __X__Context;
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  
  class __R__Context : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
    public:
    __R__Context(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    __R__Context( const __R__Context& _ctx ) :
    init_cells(_ctx.init_cells),
    finished_cell(_ctx.finished_cell)
    { }
    
    virtual ~__R__Context() { }
    
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &C);
      mace::serialize(__str, &init_cells);
      mace::serialize(__str, &finished_cell);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &C);
      serializedByteSize += mace::deserialize(__in, &init_cells);
      serializedByteSize += mace::deserialize(__in, &finished_cell);
      
      return serializedByteSize;
      
    }
    
    
    public:
    // add timers declaration
    
    
    // add state var declaration
    
    #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int init_cells
#line 330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int finished_cell
#line 335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    // add child contexts
    mace::map<int,__C__Context> C;
    
    
    // take snapshot
    void snapshot( const uint64_t& ver ) const {
      ADD_SELECTORS("__R__Context::snapshot");
      __R__Context* _ctx = new __R__Context(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
      ADD_SELECTORS("__R__Context::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    // get snapshot using the current event id.
    const __R__Context& getSnapshot() const {
      VersionServiceMap::const_iterator i = versionMap.begin();
      // FIXME: need to use high level event id instead of low level event ticket.
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    
    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
      // if this context class has subclass, and the prefix of nextContextName matches my context name
      if( nextContextName.compare( 0, contextID.size(), contextID.c_str()  ) == 0 ){  }
      
      // or, this context has 'downgradeto' context and it matches nextContextName
      
      
      return false;
    }
    private:
    typedef std::deque<std::pair<uint64_t, const __R__Context* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
  };
  
  
  class __T__Context : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
    public:
    __T__Context(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    __T__Context( const __T__Context& _ctx ) :
    test(_ctx.test)
    { }
    
    virtual ~__T__Context() { }
    
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &test);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &test);
      
      return serializedByteSize;
      
    }
    
    
    public:
    // add timers declaration
    
    
    // add state var declaration
    
    #line 70 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    bool test
#line 428 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    // add child contexts
    
    
    // take snapshot
    void snapshot( const uint64_t& ver ) const {
      ADD_SELECTORS("__T__Context::snapshot");
      __T__Context* _ctx = new __T__Context(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
      ADD_SELECTORS("__T__Context::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    // get snapshot using the current event id.
    const __T__Context& getSnapshot() const {
      VersionServiceMap::const_iterator i = versionMap.begin();
      // FIXME: need to use high level event id instead of low level event ticket.
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    
    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
      // if this context class has subclass, and the prefix of nextContextName matches my context name
      
      // or, this context has 'downgradeto' context and it matches nextContextName
      
      
      return false;
    }
    private:
    typedef std::deque<std::pair<uint64_t, const __T__Context* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
  };
  
  
  class __M__Context__param: public mace::Serializable {
    public:
    __M__Context__param (  )  { }
    __M__Context__param (
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t& m1
#line 491 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string& str
#line 495 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ): m1(m1 ),str(str ) { }
    
    
    #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    uint32_t m1
#line 501 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    mace::string str
#line 506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    
    friend std::ostream& operator<<(std::ostream& os, const __M__Context__param &c){
      os<<c.m1<<c.str;
      return os;
    }
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &m1);
      mace::serialize(__str, &str);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &m1);
      serializedByteSize += mace::deserialize(__in, &str);
      
      return serializedByteSize;
      
    }
  };
  bool operator<( const __M__Context__param & A, const __M__Context__param & B ){
    if( A.m1 != B.m1 ) return A.m1 < B.m1;
    else if( A.str != B.str ) return A.str < B.str;
    
    
    return false;
  }
  
  class __M__Context : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
    public:
    __M__Context(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    __M__Context( const __M__Context& _ctx ) :
    test(_ctx.test)
    { }
    
    virtual ~__M__Context() { }
    
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &test);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &test);
      
      return serializedByteSize;
      
    }
    
    
    public:
    // add timers declaration
    
    
    // add state var declaration
    
    #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    bool test
#line 573 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    // add child contexts
    
    
    // take snapshot
    void snapshot( const uint64_t& ver ) const {
      ADD_SELECTORS("__M__Context::snapshot");
      __M__Context* _ctx = new __M__Context(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
      ADD_SELECTORS("__M__Context::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    // get snapshot using the current event id.
    const __M__Context& getSnapshot() const {
      VersionServiceMap::const_iterator i = versionMap.begin();
      // FIXME: need to use high level event id instead of low level event ticket.
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    
    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
      // if this context class has subclass, and the prefix of nextContextName matches my context name
      
      // or, this context has 'downgradeto' context and it matches nextContextName
      
      
      return false;
    }
    private:
    typedef std::deque<std::pair<uint64_t, const __M__Context* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
  };
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  
  class __C__Context : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
    public:
    __C__Context(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    __C__Context( const __C__Context& _ctx ) :
    matrix_row_from(_ctx.matrix_row_from),
    matrix_column_from(_ctx.matrix_column_from),
    values(_ctx.values),
    receivedPivotRow(_ctx.receivedPivotRow),
    receivedPivotColumn(_ctx.receivedPivotColumn)
    { }
    
    virtual ~__C__Context() { }
    
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &X);
      mace::serialize(__str, &matrix_row_from);
      mace::serialize(__str, &matrix_column_from);
      mace::serialize(__str, &values);
      mace::serialize(__str, &receivedPivotRow);
      mace::serialize(__str, &receivedPivotColumn);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &X);
      serializedByteSize += mace::deserialize(__in, &matrix_row_from);
      serializedByteSize += mace::deserialize(__in, &matrix_column_from);
      serializedByteSize += mace::deserialize(__in, &values);
      serializedByteSize += mace::deserialize(__in, &receivedPivotRow);
      serializedByteSize += mace::deserialize(__in, &receivedPivotColumn);
      
      return serializedByteSize;
      
    }
    
    
    public:
    // add timers declaration
    
    
    // add state var declaration
    
    #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int matrix_row_from
#line 679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int matrix_column_from
#line 684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    Matrix values
#line 689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    bool receivedPivotRow
#line 694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 61 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    bool receivedPivotColumn
#line 699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    // add child contexts
    mace::map<int,__X__Context> X;
    
    
    // take snapshot
    void snapshot( const uint64_t& ver ) const {
      ADD_SELECTORS("__C__Context::snapshot");
      __C__Context* _ctx = new __C__Context(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
      ADD_SELECTORS("__C__Context::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    // get snapshot using the current event id.
    const __C__Context& getSnapshot() const {
      VersionServiceMap::const_iterator i = versionMap.begin();
      // FIXME: need to use high level event id instead of low level event ticket.
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    
    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
      // if this context class has subclass, and the prefix of nextContextName matches my context name
      if( nextContextName.compare( 0, contextID.size(), contextID.c_str()  ) == 0 ){  }
      
      // or, this context has 'downgradeto' context and it matches nextContextName
      
      
      return false;
    }
    private:
    typedef std::deque<std::pair<uint64_t, const __C__Context* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
  };
  
  //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
  
  class __X__Context : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
    public:
    __X__Context(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    __X__Context( const __X__Context& _ctx ) :
    testX(_ctx.testX)
    { }
    
    virtual ~__X__Context() { }
    
    void serialize(std::string& __str) const {
      
      mace::serialize(__str, &testX);
      
      
    }
    int deserialize(std::istream& __in)  throw (mace::SerializationException){
      
      int serializedByteSize = 0;
      serializedByteSize += mace::deserialize(__in, &testX);
      
      return serializedByteSize;
      
    }
    
    
    public:
    // add timers declaration
    
    
    // add state var declaration
    
    #line 64 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    bool testX
#line 793 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    // add child contexts
    
    
    // take snapshot
    void snapshot( const uint64_t& ver ) const {
      ADD_SELECTORS("__X__Context::snapshot");
      __X__Context* _ctx = new __X__Context(*this);
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
      ADD_SELECTORS("__X__Context::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }
    // get snapshot using the current event id.
    const __X__Context& getSnapshot() const {
      VersionServiceMap::const_iterator i = versionMap.begin();
      // FIXME: need to use high level event id instead of low level event ticket.
      uint64_t sver = mace::AgentLock::snapshotVersion();
      while (i != versionMap.end()) {
        if (i->first == sver) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << Log::endl;
        std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << ThreadStructure::myTicket() << std::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    
    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
      // if this context class has subclass, and the prefix of nextContextName matches my context name
      
      // or, this context has 'downgradeto' context and it matches nextContextName
      
      
      return false;
    }
    private:
    typedef std::deque<std::pair<uint64_t, const __X__Context* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
  };
  
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  //EOF: Mace::Compiler::ServiceImpl::printContextClasses
  
  class SimpleService;
  typedef SimpleService ServiceType;
  typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;
  typedef mace::map<int, SimpleService const *, mace::SoftState> _NodeMap_;
  typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;
  mace::map<mace::string, mace::string> returnValueMapping;
  std::map<mace::string, pthread_mutex_t> mutexMapping;
  static const char* __SERVICE__ __attribute((unused)) = "Simple";
  //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
  //END: Mace::Compiler::ServiceImpl::printAutoTypes
  //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
  //END Mace::Compiler::ServiceImpl::printDeferTypes
  //BEGIN: Mace::Compiler::ServiceImpl::printService
  
  class ServiceTester;
  class SimpleService : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, public virtual NullServiceClass, public virtual ReceiveDataHandler, public virtual NetworkErrorHandler
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
    SimpleService(TransportServiceClass& __tcp, int32_t const  _ROWS, int32_t const  _COLUMNS, int32_t const  _MATRIXROWS, int32_t const  _MATRIXCOLUMNS, bool ___shared = true);
    SimpleService(const SimpleService& other);
    //Destructor
    virtual ~SimpleService();
    
    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;
    
    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    private:
    
    const state_type& read_state() const;
    Matrix const & read_initial_matrix() const;
    int const & read_rows() const;
    int const & read_columns() const;
    int const & read_matrix_rows() const;
    int const & read_matrix_columns() const;
    int const & read_current_iteration() const;
    int const & read_init_rows() const;
    int const & read_finished_row() const;
    int const & read_returnedValues() const;
    Matrix const & read_result() const;
    int const & read_runs() const;
    
    
    
    
    
    
    public:
    //Misc.
    
    const std::string& getLogType() const {
      static std::string type = "Simple";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "SNAPSHOT::Simple";
      return desc;
    }
    
    LogClass getLogClass() const {
      return STATE_DUMP;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    
    static const LogIdSet* selectorId_route_downcall_30;
    static const LogIdSet* selectorId_send_downcall_61;
    static const LogIdSet* selectorId_messageError_demux_32;
    static const LogIdSet* selectorId_messageError_demux_25;
    static const LogIdSet* selectorId_deliver_demux_12;
    static const LogIdSet* selectorId_upcall_messageError_33_transition;
    static const LogIdSet* selectorId_maceReset_demux_42;
    static const LogIdSet* selectorId_upcall_messageError_44_transition;
    static const LogIdSet* selectorId_upcall_messageError_39_transition;
    static const LogIdSet* selectorId_messageError_demux_34;
    static const LogIdSet* selectorId_async_testMulti_async_2;
    static const LogIdSet* selectorId_route_downcall_35;
    static const LogIdSet* selectorId_route_downcall_25;
    static const LogIdSet* selectorId_rowAfter_demux_51;
    static const LogIdSet* selectorId_route_downcall_6;
    static const LogIdSet* selectorId_send_downcall_58;
    static const LogIdSet* selectorId_send_downcall_62;
    static const LogIdSet* selectorId_send_downcall_53;
    static const LogIdSet* selectorId_target_async_rowInit_sync_0;
    static const LogIdSet* selectorId_upcall_deliver_23_transition;
    static const LogIdSet* selectorId_send_downcall_54;
    static const LogIdSet* selectorId_expireresender_timer;
    static const LogIdSet* selectorId_route_downcall_65;
    static const LogIdSet* selectorId_route_downcall_20;
    static const LogIdSet* selectorId_sync_sctest_1_transition;
    static const LogIdSet* selectorId_upcall_deliver_25_transition;
    static const LogIdSet* selectorId_route_downcall_34;
    static const LogIdSet* selectorId_upcall_deliver_26_transition;
    static const LogIdSet* selectorId_cancelctsTimer;
    static const LogIdSet* selectorId_upcall_deliver_14_transition;
    static const LogIdSet* selectorId_upcall_messageError_41_transition;
    static const LogIdSet* selectorId_route_downcall_10;
    static const LogIdSet* selectorId_snapshot_sync_fn_sync_11;
    static const LogIdSet* selectorId_deliver_demux_19;
    static const LogIdSet* selectorId_messageError_demux_22;
    static const LogIdSet* selectorId_route_downcall_42;
    static const LogIdSet* selectorId_route_downcall_27;
    static const LogIdSet* selectorId_localAddress_demux_43;
    static const LogIdSet* selectorId_send_downcall_44;
    static const LogIdSet* selectorId_route_downcall_17;
    static const LogIdSet* selectorId_deliver_demux_2;
    static const LogIdSet* selectorId_messageError_demux_30;
    static const LogIdSet* selectorId_upcall_deliver_21_transition;
    static const LogIdSet* selectorId_route_downcall_37;
    static const LogIdSet* selectorId_expiret;
    static const LogIdSet* selectorId_send_downcall_48;
    static const LogIdSet* selectorId_expire_resender_timer_demux_47;
    static const LogIdSet* selectorId_deliver_demux_11;
    static const LogIdSet* selectorId_upcall_messageError_40_transition;
    static const LogIdSet* selectorId_deliver_demux_6;
    static const LogIdSet* selectorId_upcall_deliver_17_transition;
    static const LogIdSet* selectorId_send_downcall_66;
    static const LogIdSet* selectorId_messageError_demux_37;
    static const LogIdSet* selectorId_cellInit_demux_54;
    static const LogIdSet* selectorId_upcall_messageError_47_transition;
    static const LogIdSet* selectorId_deliver_demux_9;
    static const LogIdSet* selectorId_resumeDeliver_downcall_2;
    static const LogIdSet* selectorId_deliver_demux_5;
    static const LogIdSet* selectorId_deliver_demux_15;
    static const LogIdSet* selectorId_target_async_rowAfter_sync_1;
    static const LogIdSet* selectorId_maceInit_demux_39;
    static const LogIdSet* selectorId_maceExit_demux_41;
    static const LogIdSet* selectorId_suspendDeliver_downcall_1;
    static const LogIdSet* selectorId_messageError_demux_29;
    static const LogIdSet* selectorId_route_downcall_41;
    static const LogIdSet* selectorId_upcall_deliver_9_transition;
    static const LogIdSet* selectorId_send_downcall_49;
    static const LogIdSet* selectorId_upcall_deliver_28_transition;
    static const LogIdSet* selectorId_route_downcall_5;
    static const LogIdSet* selectorId_upcall_messageError_35_transition;
    static const LogIdSet* selectorId_async_rowInit_async_0;
    static const LogIdSet* selectorId_upcall_messageError_45_transition;
    static const LogIdSet* selectorId_send_downcall_56;
    static const LogIdSet* selectorId_messageError_demux_35;
    static const LogIdSet* selectorId_getStartContext_sync_10;
    static const LogIdSet* selectorId_route_downcall_32;
    static const LogIdSet* selectorId_scheduler_expire_resender_timer_10_transition;
    static const LogIdSet* selectorId_upcall_deliver_19_transition;
    static const LogIdSet* selectorId_send_downcall_50;
    static const LogIdSet* selectorId_messageError_demux_49;
    static const LogIdSet* selectorId_route_downcall_14;
    static const LogIdSet* selectorId_deliver_demux_18;
    static const LogIdSet* selectorId_deliver_demux_48;
    static const LogIdSet* selectorId_send_downcall_55;
    static const LogIdSet* selectorId_route_downcall_9;
    static const LogIdSet* selectorId_route_downcall_22;
    static const LogIdSet* selectorId_upcall_deliver_16_transition;
    static const LogIdSet* selectorId_deliver_demux_16;
    static const LogIdSet* selectorId_upcall_messageError_43_transition;
    static const LogIdSet* selectorId_upcall_deliver_20_transition;
    static const LogIdSet* selectorId_deliver_demux_4;
    static const LogIdSet* selectorId_send_downcall_46;
    static const LogIdSet* selectorId_deliver_demux_7;
    static const LogIdSet* selectorId_upcall_deliver_22_transition;
    static const LogIdSet* selectorId_scheduler_expire_t_6_transition;
    static const LogIdSet* selectorId_target_sync_cellInit_sync_6;
    static const LogIdSet* selectorId_route_downcall_16;
    static const LogIdSet* selectorId_route_downcall_64;
    static const LogIdSet* selectorId_upcall_deliver_13_transition;
    static const LogIdSet* selectorId_downcall_maceInit_0_transition;
    static const LogIdSet* selectorId_messageError_demux_31;
    static const LogIdSet* selectorId_hashState_demux_44;
    static const LogIdSet* selectorId_deliver_demux_13;
    static const LogIdSet* selectorId_sctest_demux_53;
    static const LogIdSet* selectorId_schedulectsTimer;
    static const LogIdSet* selectorId_messageError_demux_33;
    static const LogIdSet* selectorId_expire_ctsTimer_demux_45;
    static const LogIdSet* selectorId_deliver_demux_1;
    static const LogIdSet* selectorId_route_downcall_28;
    static const LogIdSet* selectorId_upcall_messageError_30_transition;
    static const LogIdSet* selectorId_send_downcall_63;
    static const LogIdSet* selectorId_async_testMulti_8_transition;
    static const LogIdSet* selectorId_async_rowAfter_async_1;
    static const LogIdSet* selectorId_messageError_demux_24;
    static const LogIdSet* selectorId_route_downcall_11;
    static const LogIdSet* selectorId_upcall_deliver_27_transition;
    static const LogIdSet* selectorId_send_downcall_52;
    static const LogIdSet* selectorId_route_downcall_36;
    static const LogIdSet* selectorId_route_downcall_7;
    static const LogIdSet* selectorId_route_downcall_33;
    static const LogIdSet* selectorId_upcall_deliver_18_transition;
    static const LogIdSet* selectorId_target_async_testMulti_sync_2;
    static const LogIdSet* selectorId_send_downcall_45;
    static const LogIdSet* selectorId_route_downcall_24;
    static const LogIdSet* selectorId_async_rowAfter_4_transition;
    static const LogIdSet* selectorId_send_downcall_47;
    static const LogIdSet* selectorId_sync_sctest_sync_3;
    static const LogIdSet* selectorId_upcall_messageError_31_transition;
    static const LogIdSet* selectorId_messageError_demux_20;
    static const LogIdSet* selectorId_route_downcall_43;
    static const LogIdSet* selectorId_route_downcall_18;
    static const LogIdSet* selectorId_schedulet;
    static const LogIdSet* selectorId_messageError_demux_26;
    static const LogIdSet* selectorId_route_downcall_19;
    static const LogIdSet* selectorId_scheduler_expire_ctsTimer_7_transition;
    static const LogIdSet* selectorId_send_downcall_59;
    static const LogIdSet* selectorId_deliver_demux_10;
    static const LogIdSet* selectorId_messageError_demux_38;
    static const LogIdSet* selectorId_upcall_messageError_38_transition;
    static const LogIdSet* selectorId_expirectsTimer;
    static const LogIdSet* selectorId_route_downcall_4;
    static const LogIdSet* selectorId_sync_cellInit_3_transition;
    static const LogIdSet* selectorId_maceResume_demux_40;
    static const LogIdSet* selectorId_target_sync_testRCX_sync_8;
    static const LogIdSet* selectorId_resumeDeliver_downcall_3;
    static const LogIdSet* selectorId_route_downcall_39;
    static const LogIdSet* selectorId_route_downcall_8;
    static const LogIdSet* selectorId_route_downcall_15;
    static const LogIdSet* selectorId_async_rowInit_2_transition;
    static const LogIdSet* selectorId_send_downcall_57;
    static const LogIdSet* selectorId_route_downcall_23;
    static const LogIdSet* selectorId_cancelresender_timer;
    static const LogIdSet* selectorId_testRCX_demux_55;
    static const LogIdSet* selectorId_messageError_demux_21;
    static const LogIdSet* selectorId_error_demux_0;
    static const LogIdSet* selectorId_route_downcall_26;
    static const LogIdSet* selectorId_deliver_demux_14;
    static const LogIdSet* selectorId_upcall_deliver_12_transition;
    static const LogIdSet* selectorId_upcall_deliver_11_transition;
    static const LogIdSet* selectorId_sync_testRCX_5_transition;
    static const LogIdSet* selectorId_messageError_demux_36;
    static const LogIdSet* selectorId_route_downcall_38;
    static const LogIdSet* selectorId_messageError_demux_28;
    static const LogIdSet* selectorId_rowInit_demux_50;
    static const LogIdSet* selectorId_send_downcall_60;
    static const LogIdSet* selectorId_upcall_messageError_42_transition;
    static const LogIdSet* selectorId_route_downcall_12;
    static const LogIdSet* selectorId_target_sync_sctest_sync_4;
    static const LogIdSet* selectorId_route_downcall_40;
    static const LogIdSet* selectorId_deliver_demux_8;
    static const LogIdSet* selectorId_route_downcall_21;
    static const LogIdSet* selectorId_upcall_messageError_32_transition;
    static const LogIdSet* selectorId_route_downcall_31;
    static const LogIdSet* selectorId_route_downcall_13;
    static const LogIdSet* selectorId_messageError_demux_27;
    static const LogIdSet* selectorId_upcall_messageError_29_transition;
    static const LogIdSet* selectorId_upcall_messageError_34_transition;
    static const LogIdSet* selectorId_expire_t_demux_46;
    static const LogIdSet* selectorId_send_downcall_51;
    static const LogIdSet* selectorId_scheduleresender_timer;
    static const LogIdSet* selectorId_findContextByID_sync_9;
    static const LogIdSet* selectorId_deliver_demux_3;
    static const LogIdSet* selectorId_upcall_messageError_46_transition;
    static const LogIdSet* selectorId_upcall_messageError_37_transition;
    static const LogIdSet* selectorId_upcall_deliver_15_transition;
    static const LogIdSet* selectorId_sync_testRCX_sync_7;
    static const LogIdSet* selectorId_upcall_messageError_36_transition;
    static const LogIdSet* selectorId_upcall_deliver_24_transition;
    static const LogIdSet* selectorId_testMulti_demux_52;
    static const LogIdSet* selectorId_sync_cellInit_sync_5;
    static const LogIdSet* selectorId_messageError_demux_23;
    static const LogIdSet* selectorId_cancelt;
    static const LogIdSet* selectorId_deliver_demux_17;
    static const LogIdSet* selectorId_suspendDeliver_downcall_0;
    static const LogIdSet* selectorId_route_downcall_29;
    
    protected:
    void dumpState(LOGLOGTYPE& logger) const;
    void processDeferred();
    const char* getStateName(state_type state) const;
    const char* getMessageName(uint8_t msgNum) const;
    void changeState(state_type stateNum, int selectorId);
    bool shouldLog_maceInit67() const;
    bool shouldLog_maceResume68() const;
    bool shouldLog_maceExit69() const;
    bool shouldLog_maceReset70() const;
    bool shouldLog_localAddress71() const;
    bool shouldLog_hashState72() const;
    bool shouldLog_error73( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const;
    bool shouldLog_deliver74( const MaceKey& source,  const MaceKey& destination,  const __internal_Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver75( const MaceKey& source,  const MaceKey& destination,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver76( const MaceKey& source,  const MaceKey& destination,  const TransferContext& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver77( const MaceKey& source,  const MaceKey& destination,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver78( const MaceKey& source,  const MaceKey& destination,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver79( const MaceKey& source,  const MaceKey& destination,  const HeadEvent& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver80( const MaceKey& source,  const MaceKey& destination,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver81( const MaceKey& source,  const MaceKey& destination,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver82( const MaceKey& source,  const MaceKey& destination,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver83( const MaceKey& source,  const MaceKey& destination,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver84( const MaceKey& source,  const MaceKey& destination,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver85( const MaceKey& source,  const MaceKey& destination,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver86( const MaceKey& source,  const MaceKey& destination,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver87( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver88( const MaceKey& source,  const MaceKey& destination,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver89( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver90( const MaceKey& source,  const MaceKey& destination,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver91( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_deliver92( const MaceKey& source,  const MaceKey& destination,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError93( const MaceKey& dest, TransportError::type errorCode,  const __internal_Ack& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError94( const MaceKey& dest, TransportError::type errorCode,  const ContextMigrationRequest& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError95( const MaceKey& dest, TransportError::type errorCode,  const TransferContext& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError96( const MaceKey& dest, TransportError::type errorCode,  const ReportContextMigration& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError97( const MaceKey& dest, TransportError::type errorCode,  const ContextMappingUpdate& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError98( const MaceKey& dest, TransportError::type errorCode,  const HeadEvent& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError99( const MaceKey& dest, TransportError::type errorCode,  const __async_at2_rowInit& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError100( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at2_rowInit& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError101( const MaceKey& dest, TransportError::type errorCode,  const __async_at4_rowAfter& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError102( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at4_rowAfter& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError103( const MaceKey& dest, TransportError::type errorCode,  const __async_at8_testMulti& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError104( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at8_testMulti& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError105( const MaceKey& dest, TransportError::type errorCode,  const __sync_at1_sctest& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError106( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at1_sctest& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError107( const MaceKey& dest, TransportError::type errorCode,  const __sync_at3_cellInit& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError108( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at3_cellInit& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError109( const MaceKey& dest, TransportError::type errorCode,  const __sync_at5_testRCX& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError110( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at5_testRCX& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_messageError111( const MaceKey& dest, TransportError::type errorCode,  const __sync_at_snapshot& message_deserialized, registration_uid_t rid) const;
    bool shouldLog_expire_ctsTimer112(MaceKey& p0) const;
    bool shouldLog_expire_t113(int& p0, int& p1, int& p2) const;
    bool shouldLog_expire_resender_timer114() const;
    bool shouldLog_suspendDeliver0(registration_uid_t rid) const;
    bool shouldLog_suspendDeliver1( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_resumeDeliver2(registration_uid_t rid) const;
    bool shouldLog_resumeDeliver3( const MaceKey& dest, registration_uid_t rid) const;
    bool shouldLog_route4( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route5( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route6( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route7( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route8( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route9( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route10( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route11( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route12( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route13( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route14( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route15( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route16( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route17( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route18( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route19( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route20( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route21( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route22( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route23( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route24( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route25( const MaceKey& src,  const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route26( const MaceKey& src,  const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route27( const MaceKey& src,  const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route28( const MaceKey& src,  const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route29( const MaceKey& src,  const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route30( const MaceKey& src,  const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route31( const MaceKey& src,  const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route32( const MaceKey& src,  const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route33( const MaceKey& src,  const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route34( const MaceKey& src,  const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route39( const MaceKey& src,  const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route40( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route41( const MaceKey& src,  const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route42( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_route43( const MaceKey& src,  const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send44( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send45( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send46( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send47( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send48( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send49( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send50( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send51( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send52( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send53( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send54( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send55( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send56( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send57( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send58( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send59( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send60( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send61( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send62( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const;
    bool shouldLog_send63( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const;
    
    
    public:
    void print(mace::PrintNode& __printer, const std::string& name) const;
    void print(std::ostream& logger) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;
    
    void serialize(std::string& str) const;
    int deserialize(std::istream& is) throw(SerializationException);
    
    //Provided Methods (calls into this service from a higher layer)
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
#line 1278 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const MaceKey& destination
#line 1282 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
        const std::string& s
#line 1286 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 1290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void error(
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& nodeId
#line 1295 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 1303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 1307 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const MaceKey& dest
#line 1312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        TransportError::type errorCode
#line 1316 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
        const std::string& message
#line 1320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
        registration_uid_t rid
#line 1324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    
    //Registration Methods (for dynamic registration)
    
    
    protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.
    
    //Constructor Parameter (Variables)
    
    #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int32_t const  ROWS
#line 1340 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int32_t const  COLUMNS
#line 1345 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int32_t const  MATRIXROWS
#line 1350 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int32_t const  MATRIXCOLUMNS
#line 1355 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    //ServiceVariables and Registration UIDs
    
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TransportServiceClass& _tcp;
#line 1362 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    registration_uid_t tcp;
    
    //Aspect Methods
    
    
    //Registration Typedefs and Maps
    
    
    //State Variables
    
    #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    Matrix initial_matrix
#line 1375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int rows
#line 1380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int columns
#line 1385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int matrix_rows
#line 1390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int matrix_columns
#line 1395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int current_iteration
#line 1400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int init_rows
#line 1405 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int finished_row
#line 1410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int returnedValues
#line 1415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    Matrix result
#line 1420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int runs
#line 1425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 203 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
    mace::map< mace::string, uint32_t> __internal_msgseqno
#line 1430 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
    mace::map<mace::string, uint32_t > __internal_lastAckedSeqno
#line 1435 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 236 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
    mace::map<mace::string, mace::map<uint32_t,uint8_t>  > __internal_receivedSeqno
#line 1440 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 251 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
    mace::map<mace::string, mace::map<uint32_t, mace::string> > __internal_unAck
#line 1445 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 266 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
    mace::map<mace::string, uint32_t> __internal_contextPrevEvent
#line 1450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    //Timer Vars
    class ctsTimer_MaceTimer;
    ctsTimer_MaceTimer &ctsTimer;
    class t_MaceTimer;
    t_MaceTimer &t;
    class resender_timer_MaceTimer;
    resender_timer_MaceTimer &resender_timer;
    
    //Context Declaration
    mace::map<int,__R__Context> R;
    
    
    __T__Context T;
    
    mace::map<__M__Context__param,__M__Context> M;
    
    
    //Timer Methods
    void expire_ctsTimer(MaceKey& p0);
    void expire_t(int& p0, int& p1, int& p2);
    void expire_resender_timer();
    
    //Async Helper Methods
    void rowInit(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const int& row
#line 1479 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1483 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1);
    void rowAfter(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void testMulti(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t m1
#line 1493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string str
#line 1497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    
    //Async Helper Methods
    void async_rowInit(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const int& row
#line 1504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1508 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void async_rowAfter(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1513 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void async_testMulti(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t m1
#line 1518 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string str
#line 1522 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    
    //Sync Methods
    bool sctest();
    bool cellInit(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2);
    void testRCX(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1543 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1547 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3);
    
    //Sync Helper Methods
    void target_async_rowInit(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const int& row
#line 1554 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1);
    void target_async_rowAfter(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1563 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void target_async_testMulti(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t m1
#line 1568 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string str
#line 1572 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool sync_sctest();
    bool target_sync_sctest();
    bool sync_cellInit(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1579 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1583 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool target_sync_cellInit(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1588 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2);
    void sync_testRCX(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1597 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1601 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1605 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void target_sync_testRCX(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 1610 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 1614 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 1618 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3);
    Serializable* findContextByID(mace::string contextID);
    mace::string getStartContext(mace::vector<mace::string>& allContextIDs);
    mace::string snapshot_sync_fn(mace::string srcContextID, mace::string snapshotContextID);
    
    //Merge Class Declarations
    
    
    //Downcall and Upcall helper methods
    
    void downcall_suspendDeliver(
        #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1632 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void downcall_suspendDeliver(
        #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1637 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 1641 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void downcall_resumeDeliver(
        #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        registration_uid_t rid = -1
#line 1646 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void downcall_resumeDeliver(
        #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
        const MaceKey& dest
#line 1651 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
        registration_uid_t rid = -1
#line 1655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1660 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const Message& s_deserialized
#line 1664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1673 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& s_deserialized
#line 1677 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1681 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& s_deserialized
#line 1690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& s_deserialized
#line 1703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1707 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1712 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& s_deserialized
#line 1716 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1720 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& s_deserialized
#line 1729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1738 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& s_deserialized
#line 1742 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& s_deserialized
#line 1755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1759 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1764 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& s_deserialized
#line 1768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1777 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& s_deserialized
#line 1781 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1785 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1790 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& s_deserialized
#line 1794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1803 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& s_deserialized
#line 1807 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1811 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1816 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& s_deserialized
#line 1820 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1824 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1829 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& s_deserialized
#line 1833 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1837 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1842 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& s_deserialized
#line 1846 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1850 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& s_deserialized
#line 1859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& s_deserialized
#line 1872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1876 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& s_deserialized
#line 1885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& s_deserialized
#line 1898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1907 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& s_deserialized
#line 1911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 1920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1924 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const Message& s_deserialized
#line 1928 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 1937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1941 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& s_deserialized
#line 1945 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1949 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 1954 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1958 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& s_deserialized
#line 1962 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1966 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 1971 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1975 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& s_deserialized
#line 1979 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 1983 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 1988 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 1992 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& s_deserialized
#line 1996 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2000 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2005 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2009 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& s_deserialized
#line 2013 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2017 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2022 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2026 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& s_deserialized
#line 2030 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2034 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2039 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2043 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& s_deserialized
#line 2047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2056 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2060 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& s_deserialized
#line 2064 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2068 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2073 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2077 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& s_deserialized
#line 2081 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2090 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2094 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& s_deserialized
#line 2098 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2111 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& s_deserialized
#line 2115 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2124 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2128 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& s_deserialized
#line 2132 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2145 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& s_deserialized
#line 2149 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2158 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2162 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& s_deserialized
#line 2166 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2170 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2175 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2179 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& s_deserialized
#line 2183 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2187 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2192 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& s_deserialized
#line 2200 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2209 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2213 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& s_deserialized
#line 2217 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2221 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2226 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2230 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& s_deserialized
#line 2234 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2238 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool downcall_route(
        #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& src
#line 2243 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& s_deserialized
#line 2251 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2255 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2260 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const Message& s_deserialized
#line 2264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2268 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& s_deserialized
#line 2277 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2286 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& s_deserialized
#line 2290 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2294 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& s_deserialized
#line 2303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2307 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& s_deserialized
#line 2316 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2325 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& s_deserialized
#line 2329 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2333 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& s_deserialized
#line 2342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2346 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& s_deserialized
#line 2355 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2364 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& s_deserialized
#line 2368 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& s_deserialized
#line 2381 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2385 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& s_deserialized
#line 2394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& s_deserialized
#line 2407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2416 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& s_deserialized
#line 2420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& s_deserialized
#line 2433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& s_deserialized
#line 2446 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2455 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& s_deserialized
#line 2459 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2468 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& s_deserialized
#line 2472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2476 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2481 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& s_deserialized
#line 2485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& s_deserialized
#line 2498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    size_t downcall_send(
        #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2507 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& s_deserialized
#line 2511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    
    
    //Serialized form Method Helpers
    
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2524 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2528 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& s_deserialized
#line 2532 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2536 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2541 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2545 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& s_deserialized
#line 2549 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2553 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2562 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& s_deserialized
#line 2566 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2570 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2575 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2579 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& s_deserialized
#line 2583 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2587 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2596 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& s_deserialized
#line 2600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2609 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2613 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& s_deserialized
#line 2617 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2621 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2626 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& s_deserialized
#line 2634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2638 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2643 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& s_deserialized
#line 2651 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2660 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& s_deserialized
#line 2668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2677 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2681 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& s_deserialized
#line 2685 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& s_deserialized
#line 2702 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2706 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2715 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& s_deserialized
#line 2719 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2723 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2728 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2732 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& s_deserialized
#line 2736 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2740 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2745 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2749 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& s_deserialized
#line 2753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2766 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& s_deserialized
#line 2770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2779 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2783 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& s_deserialized
#line 2787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& s_deserialized
#line 2804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2813 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& s_deserialized
#line 2821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2825 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 2830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 2834 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& s_deserialized
#line 2838 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid = -1
#line 2842 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2847 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2851 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& message_deserialized
#line 2855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2864 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& message_deserialized
#line 2872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2876 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2881 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& message_deserialized
#line 2889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2893 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& message_deserialized
#line 2906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& message_deserialized
#line 2923 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2927 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& message_deserialized
#line 2940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2944 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2949 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& message_deserialized
#line 2957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2966 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2970 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& message_deserialized
#line 2974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2978 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 2983 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 2987 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& message_deserialized
#line 2991 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 2995 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3000 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3004 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& message_deserialized
#line 3008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3017 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3021 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& message_deserialized
#line 3025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3034 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& message_deserialized
#line 3042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& message_deserialized
#line 3059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3068 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& message_deserialized
#line 3076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& message_deserialized
#line 3093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3097 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& message_deserialized
#line 3110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& message_deserialized
#line 3127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& message_deserialized
#line 3144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    void messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& message_deserialized
#line 3161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid = -1
#line 3165 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    
    //Transition and Guard Method Declarations
    void downcall_0_maceInit();
    bool guard_downcall_0_maceInit() const;
    bool sync_1_sctest();
    bool guard_sync_1_sctest() const;
    void async_2_rowInit(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const int& row
#line 3176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 3180 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1);
    bool guard_async_2_rowInit(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const & row
#line 3185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  x
#line 3189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1) const;
    bool sync_3_cellInit(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 3194 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 3198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2);
    bool guard_sync_3_cellInit(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  row
#line 3203 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  column
#line 3207 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2) const;
    void async_4_rowAfter(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 3212 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_async_4_rowAfter(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  row
#line 3217 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void sync_5_testRCX(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int row
#line 3222 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int column
#line 3226 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int x
#line 3230 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3);
    bool guard_sync_5_testRCX(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  row
#line 3235 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  column
#line 3239 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const  x
#line 3243 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3) const;
    void scheduler_6_expire_t(
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int& row
#line 3248 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int& column
#line 3252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int& x
#line 3256 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_scheduler_6_expire_t(
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const & row
#line 3261 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const & column
#line 3265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        int const & x
#line 3269 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void scheduler_7_expire_ctsTimer(
        #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey& dest
#line 3274 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_scheduler_7_expire_ctsTimer(
        #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 3279 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void async_8_testMulti(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t m1
#line 3284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string str
#line 3288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_async_8_testMulti(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        uint32_t const  m1
#line 3293 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        mace::string const  str
#line 3297 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_9_deliver(
        #line 321 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        const MaceKey& src
#line 3302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 322 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        const MaceKey& dest
#line 3306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 323 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        const __internal_Ack& msg
#line 3310 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_9_deliver(
        #line 321 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        MaceKey const & src
#line 3315 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 322 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        MaceKey const & dest
#line 3319 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 323 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        __internal_Ack const & msg
#line 3323 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void scheduler_10_expire_resender_timer();
    bool guard_scheduler_10_expire_resender_timer() const;
    void upcall_11_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& src
#line 3330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& dest
#line 3334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const ContextMigrationRequest& msg
#line 3338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_11_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & src
#line 3343 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & dest
#line 3347 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        ContextMigrationRequest const & msg
#line 3351 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_12_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& src
#line 3356 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& dest
#line 3360 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const TransferContext& msg
#line 3364 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_12_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & src
#line 3369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & dest
#line 3373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        TransferContext const & msg
#line 3377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_13_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& src
#line 3382 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& dest
#line 3386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const ReportContextMigration& msg
#line 3390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_13_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & src
#line 3395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & dest
#line 3399 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        ReportContextMigration const & msg
#line 3403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_14_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& src
#line 3408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& dest
#line 3412 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const ContextMappingUpdate& msg
#line 3416 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_14_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & src
#line 3421 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & dest
#line 3425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        ContextMappingUpdate const & msg
#line 3429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_15_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& src
#line 3434 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const MaceKey& dest
#line 3438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        const HeadEvent& msg
#line 3442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_15_deliver(
        #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & src
#line 3447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        MaceKey const & dest
#line 3451 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
        HeadEvent const & msg
#line 3455 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_16_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3460 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3464 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& s_deserialized
#line 3468 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3472 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_16_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3477 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3481 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at2_rowInit const & s_deserialized
#line 3485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_17_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& s_deserialized
#line 3502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_17_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at2_rowInit const & s_deserialized
#line 3519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3523 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_18_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3528 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3532 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& s_deserialized
#line 3536 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3540 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_18_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3545 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3549 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at4_rowAfter const & s_deserialized
#line 3553 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3557 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_19_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3562 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3566 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& s_deserialized
#line 3570 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3574 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_19_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3579 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3583 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at4_rowAfter const & s_deserialized
#line 3587 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3591 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_20_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3596 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& s_deserialized
#line 3604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_20_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3613 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3617 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at8_testMulti const & s_deserialized
#line 3621 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3625 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_21_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& s_deserialized
#line 3638 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3642 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_21_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3651 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at8_testMulti const & s_deserialized
#line 3655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_22_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& s_deserialized
#line 3672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_22_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3681 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3685 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at1_sctest const & s_deserialized
#line 3689 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_23_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3702 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& s_deserialized
#line 3706 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3710 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_23_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3715 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3719 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at1_sctest const & s_deserialized
#line 3723 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3727 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_24_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3732 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3736 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& s_deserialized
#line 3740 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3744 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_24_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3749 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at3_cellInit const & s_deserialized
#line 3757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3761 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_25_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3766 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& s_deserialized
#line 3774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3778 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_25_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3783 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at3_cellInit const & s_deserialized
#line 3791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_26_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& s_deserialized
#line 3808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3812 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_26_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3821 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at5_testRCX const & s_deserialized
#line 3825 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3829 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_27_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3834 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3838 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& s_deserialized
#line 3842 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3846 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_27_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3851 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at5_testRCX const & s_deserialized
#line 3859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_28_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& source
#line 3868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& destination
#line 3872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& s_deserialized
#line 3876 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t rid
#line 3880 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_28_deliver(
        #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & source
#line 3885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & destination
#line 3889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at_snapshot const & s_deserialized
#line 3893 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
        registration_uid_t const  rid
#line 3897 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_29_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __internal_Ack& message_deserialized
#line 3910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 3914 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_29_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 3919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 3923 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __internal_Ack const & message_deserialized
#line 3927 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 3931 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_30_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMigrationRequest& message_deserialized
#line 3944 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 3948 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_30_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 3953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 3957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        ContextMigrationRequest const & message_deserialized
#line 3961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 3965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_31_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 3970 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 3974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const TransferContext& message_deserialized
#line 3978 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 3982 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_31_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 3987 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 3991 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransferContext const & message_deserialized
#line 3995 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 3999 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_32_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4004 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ReportContextMigration& message_deserialized
#line 4012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_32_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4021 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        ReportContextMigration const & message_deserialized
#line 4029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_33_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const ContextMappingUpdate& message_deserialized
#line 4046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4050 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_33_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        ContextMappingUpdate const & message_deserialized
#line 4063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_34_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const HeadEvent& message_deserialized
#line 4080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_34_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4093 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        HeadEvent const & message_deserialized
#line 4097 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4101 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_35_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at2_rowInit& message_deserialized
#line 4114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_35_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at2_rowInit const & message_deserialized
#line 4131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4135 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_36_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at2_rowInit& message_deserialized
#line 4148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4152 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_36_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at2_rowInit const & message_deserialized
#line 4165 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_37_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at4_rowAfter& message_deserialized
#line 4182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_37_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4195 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at4_rowAfter const & message_deserialized
#line 4199 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4203 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_38_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4208 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4212 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at4_rowAfter& message_deserialized
#line 4216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4220 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_38_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4229 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at4_rowAfter const & message_deserialized
#line 4233 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4237 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_39_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4246 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __async_at8_testMulti& message_deserialized
#line 4250 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4254 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_39_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4259 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4263 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __async_at8_testMulti const & message_deserialized
#line 4267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4271 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_40_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4280 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_async_at8_testMulti& message_deserialized
#line 4284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_40_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4293 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4297 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_async_at8_testMulti const & message_deserialized
#line 4301 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4305 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_41_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4310 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4314 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at1_sctest& message_deserialized
#line 4318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_41_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4327 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at1_sctest const & message_deserialized
#line 4335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_42_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4344 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4348 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at1_sctest& message_deserialized
#line 4352 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4356 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_42_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4361 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at1_sctest const & message_deserialized
#line 4369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4373 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_43_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4378 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4382 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at3_cellInit& message_deserialized
#line 4386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_43_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4395 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4399 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at3_cellInit const & message_deserialized
#line 4403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_44_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4412 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4416 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at3_cellInit& message_deserialized
#line 4420 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4424 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_44_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at3_cellInit const & message_deserialized
#line 4437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4441 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_45_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4446 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4450 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at5_testRCX& message_deserialized
#line 4454 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4458 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_45_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4467 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at5_testRCX const & message_deserialized
#line 4471 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4475 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_46_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4480 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __target_sync_at5_testRCX& message_deserialized
#line 4488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_46_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4501 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __target_sync_at5_testRCX const & message_deserialized
#line 4505 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4509 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ) const;
    void upcall_47_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const MaceKey& dest
#line 4514 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type errorCode
#line 4518 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        const __sync_at_snapshot& message_deserialized
#line 4522 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t rid
#line 4526 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    );
    bool guard_upcall_47_messageError(
        #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        MaceKey const & dest
#line 4531 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        TransportError::type const  errorCode
#line 4535 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        __sync_at_snapshot const & message_deserialized
#line 4539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
        ,
        #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        registration_uid_t const  rid
#line 4543 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
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
      ADD_SELECTORS("Simple::checkSafetyProperties");
      maceout << "Testing safety properties" << Log::endl;
      { maceout << "Safety Properties: check" << Log::endl; return true; }
    }
    
    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("Simple::checkLivenessProperties");
      maceout << "Testing liveness properties" << Log::endl;
      { maceout << "Liveness Properties: check" << Log::endl; return true; }
    }
    
    protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
      ADD_SELECTORS("Simple::castNode::MaceKey");
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
  
  struct __internal_Ack_struct {
    uint32_t ackno;
    mace::string ackctx;
  };
  
  class __internal_Ack : public Message, public mace::PrintPrintable {
    private:
    __internal_Ack_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __internal_Ack() : _data_store_(new __internal_Ack_struct()), serializedByteSize(0) , ackno(_data_store_->ackno), ackctx(_data_store_->ackctx) {}
    __internal_Ack(uint32_t const & my_ackno, mace::string const & my_ackctx) : _data_store_(NULL), serializedByteSize(0), ackno(my_ackno), ackctx(my_ackctx) {}
    __internal_Ack(const __internal_Ack& _orig) : _data_store_(new __internal_Ack_struct( *_orig._data_store_)), serializedByteSize(0) , ackno(_data_store_->ackno), ackctx(_data_store_->ackctx) {
    }
    virtual ~__internal_Ack() { delete _data_store_; _data_store_ = NULL; }
    
    uint32_t const & ackno;
    mace::string const & ackctx;
    
    static const uint8_t messageType = 1;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __internal_Ack::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__internal_Ack(";
          __out << "ackno=";  mace::printItem(__out, &(ackno));
          __out << ", ";
          __out << "ackctx=";  mace::printItem(__out, &(ackctx));
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
      mace::serialize(str, &ackno);
      mace::serialize(str, &ackctx);
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
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ackno);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ackctx);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ackno INT8, ackctx TEXT);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << ackno;
      __out << "\t";
      if (Base64::isPrintable(ackctx)) {
        __out << ackctx;
      }
      else {
        __out << HashString::hash(ackctx);
      }
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct ContextMigrationRequest_struct {
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::string ctxId
#line 4725 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    MaceKey dest
#line 4730 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    uint64_t eventId
#line 4735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
  };
  
  class ContextMigrationRequest : public Message, public mace::PrintPrintable {
    private:
    ContextMigrationRequest_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    ContextMigrationRequest() : _data_store_(new ContextMigrationRequest_struct()), serializedByteSize(0) , ctxId(_data_store_->ctxId), dest(_data_store_->dest), eventId(_data_store_->eventId) {}
    ContextMigrationRequest(mace::string const & my_ctxId, MaceKey const & my_dest, uint64_t const & my_eventId) : _data_store_(NULL), serializedByteSize(0), ctxId(my_ctxId), dest(my_dest), eventId(my_eventId) {}
    ContextMigrationRequest(const ContextMigrationRequest& _orig) : _data_store_(new ContextMigrationRequest_struct( *_orig._data_store_)), serializedByteSize(0) , ctxId(_data_store_->ctxId), dest(_data_store_->dest), eventId(_data_store_->eventId) {
    }
    virtual ~ContextMigrationRequest() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & ctxId;
    MaceKey const & dest;
    uint64_t const & eventId;
    
    static const uint8_t messageType = 2;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return ContextMigrationRequest::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "ContextMigrationRequest(";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "dest=";  mace::printItem(__out, &(dest));
          __out << ", ";
          __out << "eventId=";  mace::printItem(__out, &(eventId));
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &ctxId);
#line 4785 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &dest);
#line 4790 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &eventId);
#line 4795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
#line 4810 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->dest);
#line 4815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventId);
#line 4820 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ctxId TEXT, dest INT, eventId NUMERIC(20, 0));" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_dest", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _destIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(ctxId)) {
        __out << ctxId;
      }
      else {
        __out << HashString::hash(ctxId);
      }
      __out << "\t" << _destIndex;
      __out << "\t" << eventId;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&dest, __node->children[0]);
      
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
  
  
  struct TransferContext_struct {
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::string ctxId
#line 4870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::string checkpoint
#line 4875 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    uint64_t eventId
#line 4880 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
  };
  
  class TransferContext : public Message, public mace::PrintPrintable {
    private:
    TransferContext_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    TransferContext() : _data_store_(new TransferContext_struct()), serializedByteSize(0) , ctxId(_data_store_->ctxId), checkpoint(_data_store_->checkpoint), eventId(_data_store_->eventId) {}
    TransferContext(mace::string const & my_ctxId, mace::string const & my_checkpoint, uint64_t const & my_eventId) : _data_store_(NULL), serializedByteSize(0), ctxId(my_ctxId), checkpoint(my_checkpoint), eventId(my_eventId) {}
    TransferContext(const TransferContext& _orig) : _data_store_(new TransferContext_struct( *_orig._data_store_)), serializedByteSize(0) , ctxId(_data_store_->ctxId), checkpoint(_data_store_->checkpoint), eventId(_data_store_->eventId) {
    }
    virtual ~TransferContext() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & ctxId;
    mace::string const & checkpoint;
    uint64_t const & eventId;
    
    static const uint8_t messageType = 3;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return TransferContext::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "TransferContext(";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "checkpoint=";  mace::printItem(__out, &(checkpoint));
          __out << ", ";
          __out << "eventId=";  mace::printItem(__out, &(eventId));
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &ctxId);
#line 4930 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &checkpoint);
#line 4935 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &eventId);
#line 4940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
#line 4955 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->checkpoint);
#line 4960 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventId);
#line 4965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ctxId TEXT, checkpoint TEXT, eventId NUMERIC(20, 0));" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(ctxId)) {
        __out << ctxId;
      }
      else {
        __out << HashString::hash(ctxId);
      }
      __out << "\t";
      if (Base64::isPrintable(checkpoint)) {
        __out << checkpoint;
      }
      else {
        __out << HashString::hash(checkpoint);
      }
      __out << "\t" << eventId;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct ReportContextMigration_struct {
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::string ctxId
#line 5017 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    uint64_t eventId
#line 5022 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
  };
  
  class ReportContextMigration : public Message, public mace::PrintPrintable {
    private:
    ReportContextMigration_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    ReportContextMigration() : _data_store_(new ReportContextMigration_struct()), serializedByteSize(0) , ctxId(_data_store_->ctxId), eventId(_data_store_->eventId) {}
    ReportContextMigration(mace::string const & my_ctxId, uint64_t const & my_eventId) : _data_store_(NULL), serializedByteSize(0), ctxId(my_ctxId), eventId(my_eventId) {}
    ReportContextMigration(const ReportContextMigration& _orig) : _data_store_(new ReportContextMigration_struct( *_orig._data_store_)), serializedByteSize(0) , ctxId(_data_store_->ctxId), eventId(_data_store_->eventId) {
    }
    virtual ~ReportContextMigration() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & ctxId;
    uint64_t const & eventId;
    
    static const uint8_t messageType = 4;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return ReportContextMigration::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "ReportContextMigration(";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "eventId=";  mace::printItem(__out, &(eventId));
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &ctxId);
#line 5069 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &eventId);
#line 5074 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
#line 5089 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventId);
#line 5094 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ctxId TEXT, eventId NUMERIC(20, 0));" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(ctxId)) {
        __out << ctxId;
      }
      else {
        __out << HashString::hash(ctxId);
      }
      __out << "\t" << eventId;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct ContextMappingUpdate_struct {
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::string ctxId
#line 5139 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    MaceKey node
#line 5144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
  };
  
  class ContextMappingUpdate : public Message, public mace::PrintPrintable {
    private:
    ContextMappingUpdate_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    ContextMappingUpdate() : _data_store_(new ContextMappingUpdate_struct()), serializedByteSize(0) , ctxId(_data_store_->ctxId), node(_data_store_->node) {}
    ContextMappingUpdate(mace::string const & my_ctxId, MaceKey const & my_node) : _data_store_(NULL), serializedByteSize(0), ctxId(my_ctxId), node(my_node) {}
    ContextMappingUpdate(const ContextMappingUpdate& _orig) : _data_store_(new ContextMappingUpdate_struct( *_orig._data_store_)), serializedByteSize(0) , ctxId(_data_store_->ctxId), node(_data_store_->node) {
    }
    virtual ~ContextMappingUpdate() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & ctxId;
    MaceKey const & node;
    
    static const uint8_t messageType = 5;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return ContextMappingUpdate::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "ContextMappingUpdate(";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "node=";  mace::printItem(__out, &(node));
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &ctxId);
#line 5191 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &node);
#line 5196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
#line 5211 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->node);
#line 5216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, ctxId TEXT, node INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_node", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _nodeIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(ctxId)) {
        __out << ctxId;
      }
      else {
        __out << HashString::hash(ctxId);
      }
      __out << "\t" << _nodeIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&node, __node->children[0]);
      
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
  
  
  struct HeadEvent_struct {
    
    #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
    mace::HighLevelEvent event
#line 5265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
  };
  
  class HeadEvent : public Message, public mace::PrintPrintable {
    private:
    HeadEvent_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    HeadEvent() : _data_store_(new HeadEvent_struct()), serializedByteSize(0) , event(_data_store_->event) {}
    HeadEvent(mace::HighLevelEvent const & my_event) : _data_store_(NULL), serializedByteSize(0), event(my_event) {}
    HeadEvent(const HeadEvent& _orig) : _data_store_(new HeadEvent_struct( *_orig._data_store_)), serializedByteSize(0) , event(_data_store_->event) {
    }
    virtual ~HeadEvent() { delete _data_store_; _data_store_ = NULL; }
    
    mace::HighLevelEvent const & event;
    
    static const uint8_t messageType = 6;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return HeadEvent::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "HeadEvent(";
          __out << "event=";  mace::printItem(__out, &(event));
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      mace::serialize(str, &event);
#line 5309 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
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
      
      #line 2371 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
#line 5324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, event INT);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_event", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _eventIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << _eventIndex;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&event, __node->children[0]);
      
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
  
  
  struct __async_at2_rowInit_struct {
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 5366 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int x
#line 5371 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __async_at2_rowInit : public Message, public mace::PrintPrintable {
    private:
    __async_at2_rowInit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __async_at2_rowInit() : _data_store_(new __async_at2_rowInit_struct()), serializedByteSize(0) , row(_data_store_->row), x(_data_store_->x), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __async_at2_rowInit(int const & my_row, int const & my_x, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), x(my_x), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), ticket(my_ticket), seqno(my_seqno) {}
    __async_at2_rowInit(const __async_at2_rowInit& _orig) : _data_store_(new __async_at2_rowInit_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), x(_data_store_->x), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__async_at2_rowInit() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & x;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 7;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __async_at2_rowInit::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__async_at2_rowInit(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "x=";  mace::printItem(__out, &(x));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 5442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &x);
#line 5447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 5468 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->x);
#line 5473 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, x INT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << x;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_async_at2_rowInit_struct {
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 5546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int x
#line 5551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string snapshotContext1;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_async_at2_rowInit : public Message, public mace::PrintPrintable {
    private:
    __target_async_at2_rowInit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_async_at2_rowInit() : _data_store_(new __target_async_at2_rowInit_struct()), serializedByteSize(0) , row(_data_store_->row), x(_data_store_->x), snapshotContext1(_data_store_->snapshotContext1), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_async_at2_rowInit(int const & my_row, int const & my_x, mace::string const & my_snapshotContext1, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), x(my_x), snapshotContext1(my_snapshotContext1), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), ticket(my_ticket), seqno(my_seqno) {}
    __target_async_at2_rowInit(const __target_async_at2_rowInit& _orig) : _data_store_(new __target_async_at2_rowInit_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), x(_data_store_->x), snapshotContext1(_data_store_->snapshotContext1), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_async_at2_rowInit() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & x;
    mace::string const & snapshotContext1;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 8;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_async_at2_rowInit::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_async_at2_rowInit(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "x=";  mace::printItem(__out, &(x));
          __out << ", ";
          __out << "snapshotContext1=";  mace::printItem(__out, &(snapshotContext1));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 5622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &x);
#line 5627 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &snapshotContext1);
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 5648 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->x);
#line 5653 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext1);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, x INT, snapshotContext1 TEXT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << x;
      __out << "\t";
      if (Base64::isPrintable(snapshotContext1)) {
        __out << snapshotContext1;
      }
      else {
        __out << HashString::hash(snapshotContext1);
      }
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __async_at4_rowAfter_struct {
    
    #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 5728 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __async_at4_rowAfter : public Message, public mace::PrintPrintable {
    private:
    __async_at4_rowAfter_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __async_at4_rowAfter() : _data_store_(new __async_at4_rowAfter_struct()), serializedByteSize(0) , row(_data_store_->row), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __async_at4_rowAfter(int const & my_row, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), ticket(my_ticket), seqno(my_seqno) {}
    __async_at4_rowAfter(const __async_at4_rowAfter& _orig) : _data_store_(new __async_at4_rowAfter_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__async_at4_rowAfter() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 9;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __async_at4_rowAfter::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__async_at4_rowAfter(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 5796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 5817 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_async_at4_rowAfter_struct {
    
    #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 5889 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_async_at4_rowAfter : public Message, public mace::PrintPrintable {
    private:
    __target_async_at4_rowAfter_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_async_at4_rowAfter() : _data_store_(new __target_async_at4_rowAfter_struct()), serializedByteSize(0) , row(_data_store_->row), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_async_at4_rowAfter(int const & my_row, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), ticket(my_ticket), seqno(my_seqno) {}
    __target_async_at4_rowAfter(const __target_async_at4_rowAfter& _orig) : _data_store_(new __target_async_at4_rowAfter_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_async_at4_rowAfter() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 10;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_async_at4_rowAfter::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_async_at4_rowAfter(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 5953 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 5973 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __async_at8_testMulti_struct {
    
    #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    uint32_t m1
#line 6039 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    mace::string str
#line 6044 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __async_at8_testMulti : public Message, public mace::PrintPrintable {
    private:
    __async_at8_testMulti_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __async_at8_testMulti() : _data_store_(new __async_at8_testMulti_struct()), serializedByteSize(0) , m1(_data_store_->m1), str(_data_store_->str), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __async_at8_testMulti(uint32_t const & my_m1, mace::string const & my_str, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), m1(my_m1), str(my_str), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), ticket(my_ticket), seqno(my_seqno) {}
    __async_at8_testMulti(const __async_at8_testMulti& _orig) : _data_store_(new __async_at8_testMulti_struct( *_orig._data_store_)), serializedByteSize(0) , m1(_data_store_->m1), str(_data_store_->str), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__async_at8_testMulti() { delete _data_store_; _data_store_ = NULL; }
    
    uint32_t const & m1;
    mace::string const & str;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 11;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __async_at8_testMulti::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__async_at8_testMulti(";
          __out << "m1=";  mace::printItem(__out, &(m1));
          __out << ", ";
          __out << "str=";  mace::printItem(__out, &(str));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &m1);
#line 6115 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &str);
#line 6120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->m1);
#line 6141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->str);
#line 6146 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, m1 INT8, str TEXT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << m1;
      __out << "\t";
      if (Base64::isPrintable(str)) {
        __out << str;
      }
      else {
        __out << HashString::hash(str);
      }
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_async_at8_testMulti_struct {
    
    #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    uint32_t m1
#line 6225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    mace::string str
#line 6230 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_async_at8_testMulti : public Message, public mace::PrintPrintable {
    private:
    __target_async_at8_testMulti_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_async_at8_testMulti() : _data_store_(new __target_async_at8_testMulti_struct()), serializedByteSize(0) , m1(_data_store_->m1), str(_data_store_->str), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_async_at8_testMulti(uint32_t const & my_m1, mace::string const & my_str, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), m1(my_m1), str(my_str), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), ticket(my_ticket), seqno(my_seqno) {}
    __target_async_at8_testMulti(const __target_async_at8_testMulti& _orig) : _data_store_(new __target_async_at8_testMulti_struct( *_orig._data_store_)), serializedByteSize(0) , m1(_data_store_->m1), str(_data_store_->str), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_async_at8_testMulti() { delete _data_store_; _data_store_ = NULL; }
    
    uint32_t const & m1;
    mace::string const & str;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 12;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_async_at8_testMulti::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_async_at8_testMulti(";
          __out << "m1=";  mace::printItem(__out, &(m1));
          __out << ", ";
          __out << "str=";  mace::printItem(__out, &(str));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &m1);
#line 6297 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &str);
#line 6302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->m1);
#line 6322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->str);
#line 6327 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, m1 INT8, str TEXT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << m1;
      __out << "\t";
      if (Base64::isPrintable(str)) {
        __out << str;
      }
      else {
        __out << HashString::hash(str);
      }
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __sync_at1_sctest_struct {
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    mace::string returnValue;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __sync_at1_sctest : public Message, public mace::PrintPrintable {
    private:
    __sync_at1_sctest_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __sync_at1_sctest() : _data_store_(new __sync_at1_sctest_struct()), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __sync_at1_sctest(mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, mace::string const & my_returnValue, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), returnValue(my_returnValue), ticket(my_ticket), seqno(my_seqno) {}
    __sync_at1_sctest(const __sync_at1_sctest& _orig) : _data_store_(new __sync_at1_sctest_struct( *_orig._data_store_)), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__sync_at1_sctest() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    mace::string const & returnValue;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 13;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __sync_at1_sctest::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__sync_at1_sctest(";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &returnValue);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, returnValue TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t";
      if (Base64::isPrintable(returnValue)) {
        __out << returnValue;
      }
      else {
        __out << HashString::hash(returnValue);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_sync_at1_sctest_struct {
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::string returnValue;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_sync_at1_sctest : public Message, public mace::PrintPrintable {
    private:
    __target_sync_at1_sctest_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_sync_at1_sctest() : _data_store_(new __target_sync_at1_sctest_struct()), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_sync_at1_sctest(mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::string const & my_returnValue, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), returnValue(my_returnValue), ticket(my_ticket), seqno(my_seqno) {}
    __target_sync_at1_sctest(const __target_sync_at1_sctest& _orig) : _data_store_(new __target_sync_at1_sctest_struct( *_orig._data_store_)), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_sync_at1_sctest() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::string const & returnValue;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 14;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_sync_at1_sctest::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_sync_at1_sctest(";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &returnValue);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, returnValue TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(returnValue)) {
        __out << returnValue;
      }
      else {
        __out << HashString::hash(returnValue);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __sync_at3_cellInit_struct {
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 6699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int column
#line 6704 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    mace::string returnValue;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __sync_at3_cellInit : public Message, public mace::PrintPrintable {
    private:
    __sync_at3_cellInit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __sync_at3_cellInit() : _data_store_(new __sync_at3_cellInit_struct()), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __sync_at3_cellInit(int const & my_row, int const & my_column, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, mace::string const & my_returnValue, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), column(my_column), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), returnValue(my_returnValue), ticket(my_ticket), seqno(my_seqno) {}
    __sync_at3_cellInit(const __sync_at3_cellInit& _orig) : _data_store_(new __sync_at3_cellInit_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__sync_at3_cellInit() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & column;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    mace::string const & returnValue;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 15;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __sync_at3_cellInit::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__sync_at3_cellInit(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "column=";  mace::printItem(__out, &(column));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 6779 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &column);
#line 6784 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &returnValue);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 6806 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->column);
#line 6811 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, column INT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, returnValue TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << column;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t";
      if (Base64::isPrintable(returnValue)) {
        __out << returnValue;
      }
      else {
        __out << HashString::hash(returnValue);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_sync_at3_cellInit_struct {
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 6892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int column
#line 6897 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string snapshotContext1;
    mace::string snapshotContext2;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::string returnValue;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_sync_at3_cellInit : public Message, public mace::PrintPrintable {
    private:
    __target_sync_at3_cellInit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_sync_at3_cellInit() : _data_store_(new __target_sync_at3_cellInit_struct()), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), snapshotContext1(_data_store_->snapshotContext1), snapshotContext2(_data_store_->snapshotContext2), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_sync_at3_cellInit(int const & my_row, int const & my_column, mace::string const & my_snapshotContext1, mace::string const & my_snapshotContext2, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::string const & my_returnValue, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), column(my_column), snapshotContext1(my_snapshotContext1), snapshotContext2(my_snapshotContext2), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), returnValue(my_returnValue), ticket(my_ticket), seqno(my_seqno) {}
    __target_sync_at3_cellInit(const __target_sync_at3_cellInit& _orig) : _data_store_(new __target_sync_at3_cellInit_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), snapshotContext1(_data_store_->snapshotContext1), snapshotContext2(_data_store_->snapshotContext2), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_sync_at3_cellInit() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & column;
    mace::string const & snapshotContext1;
    mace::string const & snapshotContext2;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::string const & returnValue;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 16;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_sync_at3_cellInit::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_sync_at3_cellInit(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "column=";  mace::printItem(__out, &(column));
          __out << ", ";
          __out << "snapshotContext1=";  mace::printItem(__out, &(snapshotContext1));
          __out << ", ";
          __out << "snapshotContext2=";  mace::printItem(__out, &(snapshotContext2));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 6976 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &column);
#line 6981 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &snapshotContext1);
      mace::serialize(str, &snapshotContext2);
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &returnValue);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 7004 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->column);
#line 7009 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext1);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext2);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, column INT, snapshotContext1 TEXT, snapshotContext2 TEXT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, returnValue TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << column;
      __out << "\t";
      if (Base64::isPrintable(snapshotContext1)) {
        __out << snapshotContext1;
      }
      else {
        __out << HashString::hash(snapshotContext1);
      }
      __out << "\t";
      if (Base64::isPrintable(snapshotContext2)) {
        __out << snapshotContext2;
      }
      else {
        __out << HashString::hash(snapshotContext2);
      }
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(returnValue)) {
        __out << returnValue;
      }
      else {
        __out << HashString::hash(returnValue);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __sync_at5_testRCX_struct {
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 7100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int column
#line 7105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int x
#line 7110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    mace::vector<mace::string> snapshotContextIDs;
    mace::string returnValue;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __sync_at5_testRCX : public Message, public mace::PrintPrintable {
    private:
    __sync_at5_testRCX_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __sync_at5_testRCX() : _data_store_(new __sync_at5_testRCX_struct()), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), x(_data_store_->x), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __sync_at5_testRCX(int const & my_row, int const & my_column, int const & my_x, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, mace::vector<mace::string> const & my_snapshotContextIDs, mace::string const & my_returnValue, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), column(my_column), x(my_x), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), snapshotContextIDs(my_snapshotContextIDs), returnValue(my_returnValue), ticket(my_ticket), seqno(my_seqno) {}
    __sync_at5_testRCX(const __sync_at5_testRCX& _orig) : _data_store_(new __sync_at5_testRCX_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), x(_data_store_->x), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), snapshotContextIDs(_data_store_->snapshotContextIDs), returnValue(_data_store_->returnValue), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__sync_at5_testRCX() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & column;
    int const & x;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    mace::vector<mace::string> const & snapshotContextIDs;
    mace::string const & returnValue;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 17;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __sync_at5_testRCX::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__sync_at5_testRCX(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "column=";  mace::printItem(__out, &(column));
          __out << ", ";
          __out << "x=";  mace::printItem(__out, &(x));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 7188 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &column);
#line 7193 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &x);
#line 7198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      mace::serialize(str, &returnValue);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 7220 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->column);
#line 7225 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->x);
#line 7230 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextIDs);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, column INT, x INT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, snapshotContextIDs INT, returnValue TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = new mace::LogNode*[1];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << column;
      __out << "\t" << x;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t";
      if (Base64::isPrintable(returnValue)) {
        __out << returnValue;
      }
      else {
        __out << HashString::hash(returnValue);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      
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
  
  
  struct __target_sync_at5_testRCX_struct {
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int row
#line 7312 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int column
#line 7317 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    int x
#line 7322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
    ;
    mace::string snapshotContext1;
    mace::string snapshotContext2;
    mace::string snapshotContext3;
    mace::string srcContextID;
    mace::string startContextID;
    mace::string targetContextID;
    uint64_t ticket;
    uint32_t seqno;
  };
  
  class __target_sync_at5_testRCX : public Message, public mace::PrintPrintable {
    private:
    __target_sync_at5_testRCX_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __target_sync_at5_testRCX() : _data_store_(new __target_sync_at5_testRCX_struct()), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), x(_data_store_->x), snapshotContext1(_data_store_->snapshotContext1), snapshotContext2(_data_store_->snapshotContext2), snapshotContext3(_data_store_->snapshotContext3), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {}
    __target_sync_at5_testRCX(int const & my_row, int const & my_column, int const & my_x, mace::string const & my_snapshotContext1, mace::string const & my_snapshotContext2, mace::string const & my_snapshotContext3, mace::string const & my_srcContextID, mace::string const & my_startContextID, mace::string const & my_targetContextID, uint64_t const & my_ticket, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), row(my_row), column(my_column), x(my_x), snapshotContext1(my_snapshotContext1), snapshotContext2(my_snapshotContext2), snapshotContext3(my_snapshotContext3), srcContextID(my_srcContextID), startContextID(my_startContextID), targetContextID(my_targetContextID), ticket(my_ticket), seqno(my_seqno) {}
    __target_sync_at5_testRCX(const __target_sync_at5_testRCX& _orig) : _data_store_(new __target_sync_at5_testRCX_struct( *_orig._data_store_)), serializedByteSize(0) , row(_data_store_->row), column(_data_store_->column), x(_data_store_->x), snapshotContext1(_data_store_->snapshotContext1), snapshotContext2(_data_store_->snapshotContext2), snapshotContext3(_data_store_->snapshotContext3), srcContextID(_data_store_->srcContextID), startContextID(_data_store_->startContextID), targetContextID(_data_store_->targetContextID), ticket(_data_store_->ticket), seqno(_data_store_->seqno) {
    }
    virtual ~__target_sync_at5_testRCX() { delete _data_store_; _data_store_ = NULL; }
    
    int const & row;
    int const & column;
    int const & x;
    mace::string const & snapshotContext1;
    mace::string const & snapshotContext2;
    mace::string const & snapshotContext3;
    mace::string const & srcContextID;
    mace::string const & startContextID;
    mace::string const & targetContextID;
    uint64_t const & ticket;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 18;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __target_sync_at5_testRCX::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__target_sync_at5_testRCX(";
          __out << "row=";  mace::printItem(__out, &(row));
          __out << ", ";
          __out << "column=";  mace::printItem(__out, &(column));
          __out << ", ";
          __out << "x=";  mace::printItem(__out, &(x));
          __out << ", ";
          __out << "snapshotContext1=";  mace::printItem(__out, &(snapshotContext1));
          __out << ", ";
          __out << "snapshotContext2=";  mace::printItem(__out, &(snapshotContext2));
          __out << ", ";
          __out << "snapshotContext3=";  mace::printItem(__out, &(snapshotContext3));
          __out << ", ";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "startContextID=";  mace::printItem(__out, &(startContextID));
          __out << ", ";
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "ticket=";  mace::printItem(__out, &(ticket));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &row);
#line 7404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &column);
#line 7409 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::serialize(str, &x);
#line 7414 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      mace::serialize(str, &snapshotContext1);
      mace::serialize(str, &snapshotContext2);
      mace::serialize(str, &snapshotContext3);
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &startContextID);
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &ticket);
      mace::serialize(str, &seqno);
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
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->row);
#line 7437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->column);
#line 7442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->x);
#line 7447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.h"
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext1);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext2);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContext3);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->startContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ticket);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, row INT, column INT, x INT, snapshotContext1 TEXT, snapshotContext2 TEXT, snapshotContext3 TEXT, srcContextID TEXT, startContextID TEXT, targetContextID TEXT, ticket NUMERIC(20, 0), seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << row;
      __out << "\t" << column;
      __out << "\t" << x;
      __out << "\t";
      if (Base64::isPrintable(snapshotContext1)) {
        __out << snapshotContext1;
      }
      else {
        __out << HashString::hash(snapshotContext1);
      }
      __out << "\t";
      if (Base64::isPrintable(snapshotContext2)) {
        __out << snapshotContext2;
      }
      else {
        __out << HashString::hash(snapshotContext2);
      }
      __out << "\t";
      if (Base64::isPrintable(snapshotContext3)) {
        __out << snapshotContext3;
      }
      else {
        __out << HashString::hash(snapshotContext3);
      }
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(startContextID)) {
        __out << startContextID;
      }
      else {
        __out << HashString::hash(startContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << ticket;
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  
  
  struct __sync_at_snapshot_struct {
    mace::string srcContextID;
    mace::string snapshotContextID;
    mace::string contextSnapshot;
    uint32_t seqno;
  };
  
  class __sync_at_snapshot : public Message, public mace::PrintPrintable {
    private:
    __sync_at_snapshot_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    public:
    __sync_at_snapshot() : _data_store_(new __sync_at_snapshot_struct()), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), snapshotContextID(_data_store_->snapshotContextID), contextSnapshot(_data_store_->contextSnapshot), seqno(_data_store_->seqno) {}
    __sync_at_snapshot(mace::string const & my_srcContextID, mace::string const & my_snapshotContextID, mace::string const & my_contextSnapshot, uint32_t const & my_seqno) : _data_store_(NULL), serializedByteSize(0), srcContextID(my_srcContextID), snapshotContextID(my_snapshotContextID), contextSnapshot(my_contextSnapshot), seqno(my_seqno) {}
    __sync_at_snapshot(const __sync_at_snapshot& _orig) : _data_store_(new __sync_at_snapshot_struct( *_orig._data_store_)), serializedByteSize(0) , srcContextID(_data_store_->srcContextID), snapshotContextID(_data_store_->snapshotContextID), contextSnapshot(_data_store_->contextSnapshot), seqno(_data_store_->seqno) {
    }
    virtual ~__sync_at_snapshot() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & srcContextID;
    mace::string const & snapshotContextID;
    mace::string const & contextSnapshot;
    uint32_t const & seqno;
    
    static const uint8_t messageType = 19;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return __sync_at_snapshot::getMsgType(); }
    std::string toString() const { return mace::PrintPrintable::toString(); }
    void print(std::ostream& __out) const {
      __out << "__sync_at_snapshot(";
          __out << "srcContextID=";  mace::printItem(__out, &(srcContextID));
          __out << ", ";
          __out << "snapshotContextID=";  mace::printItem(__out, &(snapshotContextID));
          __out << ", ";
          __out << "contextSnapshot=";  mace::printItem(__out, &(contextSnapshot));
          __out << ", ";
          __out << "seqno=";  mace::printItem(__out, &(seqno));
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
      mace::serialize(str, &srcContextID);
      mace::serialize(str, &snapshotContextID);
      mace::serialize(str, &contextSnapshot);
      mace::serialize(str, &seqno);
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
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->srcContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextSnapshot);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->seqno);
      return serializedByteSize;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, srcContextID TEXT, snapshotContextID TEXT, contextSnapshot TEXT, seqno INT8);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(srcContextID)) {
        __out << srcContextID;
      }
      else {
        __out << HashString::hash(srcContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(snapshotContextID)) {
        __out << snapshotContextID;
      }
      else {
        __out << HashString::hash(snapshotContextID);
      }
      __out << "\t";
      if (Base64::isPrintable(contextSnapshot)) {
        __out << contextSnapshot;
      }
      else {
        __out << HashString::hash(contextSnapshot);
      }
      __out << "\t" << seqno;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
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
  class SimpleService::ctsTimer_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    ctsTimer_MaceTimer(SimpleService *a)
    : TimerHandler("SimpleService::ctsTimer", 1), agent_(a)
    {
    }
    
    virtual ~ctsTimer_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    uint64_t schedule(const uint64_t& interval , MaceKey const & p0) {
      #define selector selector_schedulectsTimer
      #define selectorId selectorId_schedulectsTimer
      PREPARE_FUNCTION
      
      TimerData* td = new TimerData(p0);
      td->pipPathId = annotate_get_path_id_copy(&td->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      //	  TimerData* td = new TimerData(p0);
      uint64_t t = mace::getmtime() + interval;
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
    
    void cancel(const uint64_t& expireTime) {
      #define selector selector_cancelctsTimer
      #define selectorId selectorId_cancelctsTimer
      
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer at " << expireTime << Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(expireTime);
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
    
    
    uint64_t nextScheduled() const {
      return timerData.empty()?0:timerData.begin()->first;
    }
    bool isScheduled(const uint64_t& expireTime) const { return timerData.containsKey(expireTime); }
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
      mace::ScopedStackExecution::addDefer(agent_);
      
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
        
        while((i != timerData.end()) && (i->first < (curtime + Scheduler::CLOCK_RESOLUTION))) {
          TimerData* temptd = i->second;
          timerData.erase(i);
          if (true) { macecompiler(0) << "calling expire into service for ctsTimer " << i->first <<  Log::endl; }
          agent_->expire_ctsTimer(temptd->p0);
          delete temptd;
          i = timerData.begin();
          
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
    SimpleService *agent_;
    
    
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
  
  class SimpleService::t_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    t_MaceTimer(SimpleService *a)
    : TimerHandler("SimpleService::t", 1), agent_(a)
    {
    }
    
    virtual ~t_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    uint64_t schedule(const uint64_t& interval , int const & p0, int const & p1, int const & p2) {
      #define selector selector_schedulet
      #define selectorId selectorId_schedulet
      PREPARE_FUNCTION
      
      TimerData* td = new TimerData(p0, p1, p2);
      td->pipPathId = annotate_get_path_id_copy(&td->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      //	  TimerData* td = new TimerData(p0, p1, p2);
      uint64_t t = mace::getmtime() + interval;
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
      #define selector selector_cancelt
      #define selectorId selectorId_cancelt
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
    
    void cancel(const uint64_t& expireTime) {
      #define selector selector_cancelt
      #define selectorId selectorId_cancelt
      
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer at " << expireTime << Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.find(expireTime);
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
    
    void cancel(int const & p0) {
      #define selector selector_cancelt
      #define selectorId selectorId_cancelt
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout << ", p2="; mace::printItem(maceout, &temptd->p2); maceout <<  Log::endl; }
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
    
    
    void cancel(int const & p0, int const & p1) {
      #define selector selector_cancelt
      #define selectorId selectorId_cancelt
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout << ", p1="; mace::printItem(maceout, &p1); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0) && (temptd->p1 == p1)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout << ", p2="; mace::printItem(maceout, &temptd->p2); maceout <<  Log::endl; }
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
    
    
    void cancel(int const & p0, int const & p1, int const & p2) {
      #define selector selector_cancelt
      #define selectorId selectorId_cancelt
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (true) { maceout << "canceling timer for " << ", p0="; mace::printItem(maceout, &p0); maceout << ", p1="; mace::printItem(maceout, &p1); maceout << ", p2="; mace::printItem(maceout, &p2); maceout <<  Log::endl; }
      
      mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
      bool reschedule = false;
      while (i != timerData.end()) {
        TimerData* temptd = i->second;
        if ((temptd->p0 == p0) && (temptd->p1 == p1) && (temptd->p2 == p2)) {
          if (true) { maceout << "erasing " << i->first << " : " << ", p0="; mace::printItem(maceout, &temptd->p0); maceout << ", p1="; mace::printItem(maceout, &temptd->p1); maceout << ", p2="; mace::printItem(maceout, &temptd->p2); maceout <<  Log::endl; }
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
    
    
    uint64_t nextScheduled() const {
      return timerData.empty()?0:timerData.begin()->first;
    }
    bool isScheduled(const uint64_t& expireTime) const { return timerData.containsKey(expireTime); }
    size_t scheduledCount() const { return timerData.size(); }
    
    void print(mace::PrintNode& __printer, const std::string& __name) const {
      
      mace::PrintNode __tpr("t", "timer");
      size_t pos = 0;
      for (mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
        mace::PrintNode __pr(StrUtil::toString(pos), "TimerData");
        TimerData* td __attribute((unused)) = i->second;
        mace::printItem(__pr, "scheduled", &(i->first));
        mace::printItem(__pr, "p0", &td->p0);
        mace::printItem(__pr, "p1", &td->p1);
        mace::printItem(__pr, "p2", &td->p2);
        pos++;
        __tpr.addChild(__pr);
      }
      __printer.addChild(__tpr);
      
    }
    void print(std::ostream& __out) const {
      
      __out << "timer<t>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled=" << i->first << ", p0="; mace::printItem(__out, &td->p0); __out << ", p1="; mace::printItem(__out, &td->p1); __out << ", p2="; mace::printItem(__out, &td->p2); __out <<  "]";
          }
          __out << ")";
      
    }
    void printState(std::ostream& __out) const {
      
      __out << "timer<t>(";
          for(mace::map<uint64_t, TimerData*, mace::SoftState>::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            TimerData* td __attribute((unused)) = i->second;
            __out << "[scheduled" << ", p0="; mace::printState(__out, &td->p0, td->p0); __out << ", p1="; mace::printState(__out, &td->p1, td->p1); __out << ", p2="; mace::printState(__out, &td->p2, td->p2); __out <<  "]";
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
        mace::serialize(__str, &td->p0);mace::serialize(__str, &td->p1);mace::serialize(__str, &td->p2);
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
        int p0;
        int p1;
        int p2;;
        serializedByteSize += mace::deserialize(__in, &p0);serializedByteSize += mace::deserialize(__in, &p1);serializedByteSize += mace::deserialize(__in, &p2);
        TimerData* td = new TimerData(p0, p1, p2);
        timerData[key] = td;
      }
      return serializedByteSize;
      
    }
    
    
    protected:
    void expire() {
      #define selector selector_expiret
      #define selectorId selectorId_expiret
      PREPARE_FUNCTION
      
      ADD_LOG_BACKING
      //ScopedLock __scopedLock(BaseMaceService::agentlock);
      mace::ContextLock __lock(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE); // Run timers in exclusive mode for now. XXX
      maceout<<"ticket = "<< ThreadStructure::myTicket() <<Log::endl;
      
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      mace::ScopedStackExecution::addDefer(agent_);
      
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
            agent_->expire_t(temptd->p0, temptd->p1, temptd->p2);
            delete temptd;
          }
          else {
            if (true) { maceout << i->first << " canceled!" << Log::endl; }
          }
        }
      }
      else {
        mace::map<uint64_t, TimerData*, mace::SoftState>::iterator i = timerData.begin();
        
        while((i != timerData.end()) && (i->first < (curtime + Scheduler::CLOCK_RESOLUTION))) {
          TimerData* temptd = i->second;
          timerData.erase(i);
          if (true) { macecompiler(0) << "calling expire into service for t " << i->first <<  Log::endl; }
          agent_->expire_t(temptd->p0, temptd->p1, temptd->p2);
          delete temptd;
          i = timerData.begin();
          
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
    SimpleService *agent_;
    
    
    class TimerData {
      
      public:
      char* pipPathId;
      int pipPathIdLen;
      TimerData() : pipPathId(NULL), pipPathIdLen(0) { }
      ~TimerData() { ::free(pipPathId); }
      TimerData(int const & p0, int const & p1, int const & p2) : p0(p0), p1(p1), p2(p2){ }
      int p0;
      int p1;
      int p2;
    };
    
    mace::map<uint64_t, TimerData*, mace::SoftState> timerData;
  };
  
  class SimpleService::resender_timer_MaceTimer : private TimerHandler, public mace::PrintPrintable {
    public:
    resender_timer_MaceTimer(SimpleService *a)
    : TimerHandler("SimpleService::resender_timer", 1), agent_(a) , nextScheduledTime() , timerData(0)
    {
    }
    
    virtual ~resender_timer_MaceTimer() {
      cancel();
    }
    
    bool isScheduled() const {
      return TimerHandler::isScheduled() || TimerHandler::isRunning();
    }
    
    uint64_t schedule(const uint64_t& interval ) {
      #define selector selector_scheduleresender_timer
      #define selectorId selectorId_scheduleresender_timer
      PREPARE_FUNCTION
      
      timerData = new TimerData();
      timerData->pipPathId = annotate_get_path_id_copy(&timerData->pipPathIdLen);
      
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      
      ASSERTMSG(!isScheduled(), Attempting to schedule an already scheduled timer: resender_timer);
      nextScheduledTime = TimerHandler::schedule(interval, false);
      return nextScheduledTime;
      
      #undef selector
      #undef selectorId
    }
    uint64_t reschedule(const uint64_t& interval ) {
      cancel();
      return schedule(interval );
    }
    void cancel() {
      #define selector selector_cancelresender_timer
      #define selectorId selectorId_cancelresender_timer
      PREPARE_FUNCTION
      ADD_LOG_BACKING
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
      
      if (TimerHandler::isRunning()) {
        TimerHandler::cancel();
        nextScheduledTime = 0;
        delete timerData;
        timerData = 0;
      }
      
      #undef selector
      #undef selectorId
    }
    
    uint64_t nextScheduled() const {
      return nextScheduledTime;
    }
    
    
    
    void print(mace::PrintNode& __printer, const std::string& __name) const {
      
      TimerData* td __attribute((unused)) = timerData;
      mace::PrintNode __pr("resender_timer", "timer");
      mace::printItem(__pr, "scheduled", &nextScheduledTime);
      if (nextScheduledTime) {
        
      }
      __printer.addChild(__pr);
      
    }
    void print(std::ostream& __out) const {
      
      if (nextScheduledTime) {
        TimerData* td __attribute((unused)) = timerData;
        __out << "timer<resender_timer>(scheduled=" << nextScheduledTime <<  ")";
      }
      else {
        __out << "timer<resender_timer>(not scheduled)";
      }
      
    }
    void printState(std::ostream& __out) const {
      
      if (nextScheduledTime) {
        TimerData* td __attribute((unused)) = timerData;
        __out << "timer<resender_timer>(scheduled" << ")";
      }
      else {
        __out << "timer<resender_timer>(not scheduled)";
      }
      
    }
    
    void serialize(std::string& __str) const {
      
      if(nextScheduledTime) {
        mace::serialize(__str, &nextScheduledTime);
      } else {
        uint64_t dummy = 0;
        mace::serialize(__str, &dummy);
      }
      
    }
    int deserialize(std::istream& __in) {
      
      return mace::deserialize(__in, &nextScheduledTime);
      
    }
    
    
    protected:
    void expire() {
      #define selector selector_expireresender_timer
      #define selectorId selectorId_expireresender_timer
      PREPARE_FUNCTION
      ANNOTATE_SET_PATH_ID(NULL, 0, timerData->pipPathId, timerData->pipPathIdLen);
      ADD_LOG_BACKING
      //ScopedLock __scopedLock(BaseMaceService::agentlock);
      mace::ContextLock __lock(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE); // Run timers in exclusive mode for now. XXX
      maceout<<"ticket = "<< ThreadStructure::myTicket() <<Log::endl;
      
      mace::ScopedFingerprint __fingerprint(selector);
      mace::ScopedStackExecution __defer;
      mace::ScopedStackExecution::addDefer(agent_);
      
      ScopedLog __scopedLog(selector, 0, selectorId->compiler, true, true,
          true && mace::LogicalClock::instance().shouldLogPath(), PIP && !0);
      
      if (!isRunning()) {
        return;
      }
      
      clearRunning();
      
      
      TimerData* temptd = timerData;
      timerData = 0;
      agent_->expire_resender_timer();
      delete temptd;
      
      #undef selector
      #undef selectorId
    }
    
    
    protected:
    SimpleService *agent_;
    uint64_t nextScheduledTime;
    
    class TimerData {
      
      public:
      char* pipPathId;
      int pipPathIdLen;
      TimerData() : pipPathId(NULL), pipPathIdLen(0) { }
      ~TimerData() { ::free(pipPathId); }
      
    };
    
    TimerData *timerData;
  };
  
  //END: Mace::Compiler::ServiceImpl::printTimerClasses
  class maceInit67Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_maceInit67";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::maceInit()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceInit67Dummy()  { }
    
    
    
    
    ~maceInit67Dummy() {
      
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
  class maceReset70Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_maceReset70";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::maceReset()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    maceReset70Dummy()  { }
    
    
    
    
    ~maceReset70Dummy() {
      
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
  class hashState72Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_hashState72";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::hashState() const";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    hashState72Dummy()  { }
    
    
    
    
    ~hashState72Dummy() {
      
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
  class deliver74Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __internal_Ack* _s_deserialized;
    const __internal_Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver74";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __internal_Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver74Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __internal_Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver74Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __internal_Ack& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver74Dummy() {
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
  class deliver75Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    ContextMigrationRequest* _s_deserialized;
    const ContextMigrationRequest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver75";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver75Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new ContextMigrationRequest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver75Dummy(const MaceKey& ___source, const MaceKey& ___destination, const ContextMigrationRequest& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver75Dummy() {
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
  class deliver76Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    TransferContext* _s_deserialized;
    const TransferContext& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver76";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const TransferContext& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver76Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new TransferContext()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver76Dummy(const MaceKey& ___source, const MaceKey& ___destination, const TransferContext& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver76Dummy() {
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
  class deliver77Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    ReportContextMigration* _s_deserialized;
    const ReportContextMigration& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver77";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const ReportContextMigration& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver77Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new ReportContextMigration()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver77Dummy(const MaceKey& ___source, const MaceKey& ___destination, const ReportContextMigration& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver77Dummy() {
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
  class deliver78Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    ContextMappingUpdate* _s_deserialized;
    const ContextMappingUpdate& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver78";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver78Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new ContextMappingUpdate()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver78Dummy(const MaceKey& ___source, const MaceKey& ___destination, const ContextMappingUpdate& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    HeadEvent* _s_deserialized;
    const HeadEvent& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver79";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const HeadEvent& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver79Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new HeadEvent()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver79Dummy(const MaceKey& ___source, const MaceKey& ___destination, const HeadEvent& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __async_at2_rowInit* _s_deserialized;
    const __async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver80";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver80Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver80Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __target_async_at2_rowInit* _s_deserialized;
    const __target_async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver81";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver81Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver81Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __async_at4_rowAfter* _s_deserialized;
    const __async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver82";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver82Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver82Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
  class deliver83Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __target_async_at4_rowAfter* _s_deserialized;
    const __target_async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver83";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver83Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver83Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver83Dummy() {
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
  class deliver84Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __async_at8_testMulti* _s_deserialized;
    const __async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver84";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver84Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver84Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver84Dummy() {
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
  class deliver85Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __target_async_at8_testMulti* _s_deserialized;
    const __target_async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver85";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver85Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver85Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver85Dummy() {
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
  class deliver86Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __sync_at1_sctest* _s_deserialized;
    const __sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver86";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver86Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver86Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver86Dummy() {
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
  class deliver87Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __target_sync_at1_sctest* _s_deserialized;
    const __target_sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver87";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver87Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver87Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver87Dummy() {
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
  class deliver88Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __sync_at3_cellInit* _s_deserialized;
    const __sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver88";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver88Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver88Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver88Dummy() {
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
  class deliver89Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __target_sync_at3_cellInit* _s_deserialized;
    const __target_sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver89";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver89Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver89Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver89Dummy() {
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
  class deliver90Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __sync_at5_testRCX* _s_deserialized;
    const __sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver90";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver90Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver90Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver90Dummy() {
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
  class deliver91Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __target_sync_at5_testRCX* _s_deserialized;
    const __target_sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver91";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver91Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __target_sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver91Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __target_sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver91Dummy() {
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
  class deliver92Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _source;
    const MaceKey& source;
    MaceKey* _destination;
    const MaceKey& destination;
    __sync_at_snapshot* _s_deserialized;
    const __sync_at_snapshot& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_deliver92";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    deliver92Dummy() : _source(new MaceKey()), source(*_source), _destination(new MaceKey()), destination(*_destination), _s_deserialized(new __sync_at_snapshot()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    deliver92Dummy(const MaceKey& ___source, const MaceKey& ___destination, const __sync_at_snapshot& ___s_deserialized, const registration_uid_t& ___rid) : _source(NULL), source(___source), _destination(NULL), destination(___destination), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~deliver92Dummy() {
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
  class messageError93Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __internal_Ack* _message_deserialized;
    const __internal_Ack& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError93";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __internal_Ack& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError93Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __internal_Ack()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError93Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __internal_Ack& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError93Dummy() {
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
  class messageError94Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    ContextMigrationRequest* _message_deserialized;
    const ContextMigrationRequest& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError94";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMigrationRequest& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError94Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new ContextMigrationRequest()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError94Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const ContextMigrationRequest& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError94Dummy() {
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
  class messageError95Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    TransferContext* _message_deserialized;
    const TransferContext& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError95";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const TransferContext& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError95Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new TransferContext()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError95Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const TransferContext& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError95Dummy() {
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
  class messageError96Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    ReportContextMigration* _message_deserialized;
    const ReportContextMigration& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError96";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const ReportContextMigration& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError96Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new ReportContextMigration()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError96Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const ReportContextMigration& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError96Dummy() {
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
  class messageError97Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    ContextMappingUpdate* _message_deserialized;
    const ContextMappingUpdate& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError97";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMappingUpdate& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError97Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new ContextMappingUpdate()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError97Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const ContextMappingUpdate& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError97Dummy() {
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
  class messageError98Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    HeadEvent* _message_deserialized;
    const HeadEvent& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError98";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const HeadEvent& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError98Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new HeadEvent()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError98Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const HeadEvent& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError98Dummy() {
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
  class messageError99Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __async_at2_rowInit* _message_deserialized;
    const __async_at2_rowInit& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError99";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at2_rowInit& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError99Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __async_at2_rowInit()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError99Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __async_at2_rowInit& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError99Dummy() {
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
  class messageError100Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_async_at2_rowInit* _message_deserialized;
    const __target_async_at2_rowInit& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError100";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at2_rowInit& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError100Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_async_at2_rowInit()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError100Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_async_at2_rowInit& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError100Dummy() {
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
  class messageError101Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __async_at4_rowAfter* _message_deserialized;
    const __async_at4_rowAfter& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError101";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at4_rowAfter& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError101Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __async_at4_rowAfter()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError101Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __async_at4_rowAfter& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError101Dummy() {
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
  class messageError102Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_async_at4_rowAfter* _message_deserialized;
    const __target_async_at4_rowAfter& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError102";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at4_rowAfter& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError102Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_async_at4_rowAfter()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError102Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_async_at4_rowAfter& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError102Dummy() {
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
  class messageError103Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __async_at8_testMulti* _message_deserialized;
    const __async_at8_testMulti& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError103";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at8_testMulti& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError103Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __async_at8_testMulti()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError103Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __async_at8_testMulti& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError103Dummy() {
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
  class messageError104Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_async_at8_testMulti* _message_deserialized;
    const __target_async_at8_testMulti& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError104";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at8_testMulti& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError104Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_async_at8_testMulti()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError104Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_async_at8_testMulti& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError104Dummy() {
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
  class messageError105Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __sync_at1_sctest* _message_deserialized;
    const __sync_at1_sctest& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError105";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at1_sctest& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError105Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __sync_at1_sctest()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError105Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __sync_at1_sctest& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError105Dummy() {
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
  class messageError106Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_sync_at1_sctest* _message_deserialized;
    const __target_sync_at1_sctest& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError106";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at1_sctest& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError106Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_sync_at1_sctest()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError106Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_sync_at1_sctest& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError106Dummy() {
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
  class messageError107Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __sync_at3_cellInit* _message_deserialized;
    const __sync_at3_cellInit& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError107";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at3_cellInit& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError107Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __sync_at3_cellInit()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError107Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __sync_at3_cellInit& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError107Dummy() {
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
  class messageError108Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_sync_at3_cellInit* _message_deserialized;
    const __target_sync_at3_cellInit& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError108";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at3_cellInit& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError108Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_sync_at3_cellInit()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError108Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_sync_at3_cellInit& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError108Dummy() {
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
  class messageError109Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __sync_at5_testRCX* _message_deserialized;
    const __sync_at5_testRCX& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError109";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at5_testRCX& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError109Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __sync_at5_testRCX()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError109Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __sync_at5_testRCX& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError109Dummy() {
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
  class messageError110Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __target_sync_at5_testRCX* _message_deserialized;
    const __target_sync_at5_testRCX& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError110";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at5_testRCX& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError110Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __target_sync_at5_testRCX()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError110Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __target_sync_at5_testRCX& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError110Dummy() {
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
  class messageError111Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransportError::type* _errorCode;
    const TransportError::type& errorCode;
    __sync_at_snapshot* _message_deserialized;
    const __sync_at_snapshot& message_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_messageError111";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at_snapshot& message_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    messageError111Dummy() : _dest(new MaceKey()), dest(*_dest), _errorCode(new TransportError::type()), errorCode(*_errorCode), _message_deserialized(new __sync_at_snapshot()), message_deserialized(*_message_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    messageError111Dummy(const MaceKey& ___dest, const TransportError::type& ___errorCode, const __sync_at_snapshot& ___message_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _errorCode(NULL), errorCode(___errorCode), _message_deserialized(NULL), message_deserialized(___message_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~messageError111Dummy() {
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
  class expire_ctsTimer112Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _p0;
    const MaceKey& p0;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_expire_ctsTimer112";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::expire_ctsTimer(MaceKey& p0)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_ctsTimer112Dummy() : _p0(new MaceKey()), p0(*_p0) { }
    
    
    expire_ctsTimer112Dummy(const MaceKey& ___p0) : _p0(NULL), p0(___p0) { }
    
    
    ~expire_ctsTimer112Dummy() {
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
  class expire_t113Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    int* _p0;
    const int& p0;
    int* _p1;
    const int& p1;
    int* _p2;
    const int& p2;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_expire_t113";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::expire_t(int& p0, int& p1, int& p2)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_t113Dummy() : _p0(new int()), p0(*_p0), _p1(new int()), p1(*_p1), _p2(new int()), p2(*_p2) { }
    
    
    expire_t113Dummy(const int& ___p0, const int& ___p1, const int& ___p2) : _p0(NULL), p0(___p0), _p1(NULL), p1(___p1), _p2(NULL), p2(___p2) { }
    
    
    ~expire_t113Dummy() {
      if (_p0 != NULL) { delete _p0; _p0 = NULL; }
      if (_p1 != NULL) { delete _p1; _p1 = NULL; }
      if (_p2 != NULL) { delete _p2; _p2 = NULL; }
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "expire_t(";
          out << "[p0=";
          mace::printItem(out, &p0);
          out << "]";
          out << "[p1=";
          mace::printItem(out, &p1);
          out << "]";
          out << "[p2=";
          mace::printItem(out, &p2);
          out << "]";
          out << ")";
    }
    void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, p0 INT, p1 INT, p2 INT);" << std::endl;
        __node->children = NULL;
        Log::logSqlCreate(__out.str(), __node);
      }
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t" << p0;
      __out << "\t" << p1;
      __out << "\t" << p2;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      
    }
  };
  class expire_resender_timer114Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_expire_resender_timer114";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::expire_resender_timer()";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    expire_resender_timer114Dummy()  { }
    
    
    
    
    ~expire_resender_timer114Dummy() {
      
    }
    
    void serialize(std::string& __str) const {
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      return bytes;
    }
    void print(std::ostream& out) const {
      out << "expire_resender_timer(";
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
  class suspendDeliver0Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_suspendDeliver0";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::suspendDeliver(registration_uid_t rid)";
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
      static std::string type = "Simple_suspendDeliver1";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::suspendDeliver( const MaceKey& dest, registration_uid_t rid)";
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
      static std::string type = "Simple_resumeDeliver2";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::resumeDeliver(registration_uid_t rid)";
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
      static std::string type = "Simple_resumeDeliver3";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::resumeDeliver( const MaceKey& dest, registration_uid_t rid)";
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
      static std::string type = "Simple_route4";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
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
    __internal_Ack* _s_deserialized;
    const __internal_Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route5";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route5Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __internal_Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route5Dummy(const MaceKey& ___dest, const __internal_Ack& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMigrationRequest* _s_deserialized;
    const ContextMigrationRequest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route6";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route6Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMigrationRequest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route6Dummy(const MaceKey& ___dest, const ContextMigrationRequest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    MaceKey* _dest;
    const MaceKey& dest;
    TransferContext* _s_deserialized;
    const TransferContext& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route7";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route7Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new TransferContext()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route7Dummy(const MaceKey& ___dest, const TransferContext& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route7Dummy() {
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
  class route8Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    ReportContextMigration* _s_deserialized;
    const ReportContextMigration& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route8";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route8Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ReportContextMigration()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route8Dummy(const MaceKey& ___dest, const ReportContextMigration& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route8Dummy() {
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
  class route9Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMappingUpdate* _s_deserialized;
    const ContextMappingUpdate& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route9";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route9Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMappingUpdate()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route9Dummy(const MaceKey& ___dest, const ContextMappingUpdate& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route9Dummy() {
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
  class route10Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    HeadEvent* _s_deserialized;
    const HeadEvent& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route10";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route10Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new HeadEvent()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route10Dummy(const MaceKey& ___dest, const HeadEvent& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route10Dummy() {
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
  class route11Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at2_rowInit* _s_deserialized;
    const __async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route11";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route11Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route11Dummy(const MaceKey& ___dest, const __async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route11Dummy() {
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
  class route12Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at2_rowInit* _s_deserialized;
    const __target_async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route12";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route12Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route12Dummy(const MaceKey& ___dest, const __target_async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route12Dummy() {
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
  class route13Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at4_rowAfter* _s_deserialized;
    const __async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route13";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route13Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route13Dummy(const MaceKey& ___dest, const __async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route13Dummy() {
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
  class route14Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at4_rowAfter* _s_deserialized;
    const __target_async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route14";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route14Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route14Dummy(const MaceKey& ___dest, const __target_async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route14Dummy() {
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
  class route15Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at8_testMulti* _s_deserialized;
    const __async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route15";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route15Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route15Dummy(const MaceKey& ___dest, const __async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route15Dummy() {
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
  class route16Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at8_testMulti* _s_deserialized;
    const __target_async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route16";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route16Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route16Dummy(const MaceKey& ___dest, const __target_async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route16Dummy() {
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
  class route17Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at1_sctest* _s_deserialized;
    const __sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route17";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route17Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route17Dummy(const MaceKey& ___dest, const __sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route17Dummy() {
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
  class route18Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at1_sctest* _s_deserialized;
    const __target_sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route18";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route18Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route18Dummy(const MaceKey& ___dest, const __target_sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route18Dummy() {
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
  class route19Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at3_cellInit* _s_deserialized;
    const __sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route19";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route19Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route19Dummy(const MaceKey& ___dest, const __sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route19Dummy() {
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
  class route20Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at3_cellInit* _s_deserialized;
    const __target_sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route20";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route20Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route20Dummy(const MaceKey& ___dest, const __target_sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route20Dummy() {
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
  class route21Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at5_testRCX* _s_deserialized;
    const __sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route21";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route21Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route21Dummy(const MaceKey& ___dest, const __sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route21Dummy() {
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
  class route22Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at5_testRCX* _s_deserialized;
    const __target_sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route22";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route22Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route22Dummy(const MaceKey& ___dest, const __target_sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route22Dummy() {
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
  class route23Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at_snapshot* _s_deserialized;
    const __sync_at_snapshot& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route23";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route23Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at_snapshot()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route23Dummy(const MaceKey& ___dest, const __sync_at_snapshot& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route23Dummy() {
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
  class route24Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route24";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route24Dummy()  { }
    
    
    
    
    ~route24Dummy() {
      
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
  class route25Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __internal_Ack* _s_deserialized;
    const __internal_Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route25";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route25Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __internal_Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route25Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __internal_Ack& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route25Dummy() {
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
  class route26Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMigrationRequest* _s_deserialized;
    const ContextMigrationRequest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route26";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route26Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMigrationRequest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route26Dummy(const MaceKey& ___src, const MaceKey& ___dest, const ContextMigrationRequest& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route26Dummy() {
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
  class route27Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    TransferContext* _s_deserialized;
    const TransferContext& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route27";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route27Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new TransferContext()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route27Dummy(const MaceKey& ___src, const MaceKey& ___dest, const TransferContext& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route27Dummy() {
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
  class route28Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    ReportContextMigration* _s_deserialized;
    const ReportContextMigration& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route28";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route28Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ReportContextMigration()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route28Dummy(const MaceKey& ___src, const MaceKey& ___dest, const ReportContextMigration& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route28Dummy() {
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
  class route29Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMappingUpdate* _s_deserialized;
    const ContextMappingUpdate& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route29";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route29Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMappingUpdate()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route29Dummy(const MaceKey& ___src, const MaceKey& ___dest, const ContextMappingUpdate& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route29Dummy() {
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
  class route30Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    HeadEvent* _s_deserialized;
    const HeadEvent& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route30";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route30Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new HeadEvent()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route30Dummy(const MaceKey& ___src, const MaceKey& ___dest, const HeadEvent& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route30Dummy() {
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
  class route31Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at2_rowInit* _s_deserialized;
    const __async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route31";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route31Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route31Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route31Dummy() {
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
  class route32Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at2_rowInit* _s_deserialized;
    const __target_async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route32";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route32Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route32Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route32Dummy() {
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
  class route33Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at4_rowAfter* _s_deserialized;
    const __async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route33";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route33Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route33Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route33Dummy() {
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
  class route34Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at4_rowAfter* _s_deserialized;
    const __target_async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route34";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route34Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route34Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __async_at8_testMulti* _s_deserialized;
    const __async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route35";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route35Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route35Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __target_async_at8_testMulti* _s_deserialized;
    const __target_async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route36";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route36Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route36Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __sync_at1_sctest* _s_deserialized;
    const __sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route37";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route37Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route37Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
    __target_sync_at1_sctest* _s_deserialized;
    const __target_sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route38";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route38Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route38Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
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
  class route39Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at3_cellInit* _s_deserialized;
    const __sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route39";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route39Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route39Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route39Dummy() {
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
  class route40Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at3_cellInit* _s_deserialized;
    const __target_sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route40";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route40Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route40Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route40Dummy() {
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
  class route41Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at5_testRCX* _s_deserialized;
    const __sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route41";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route41Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route41Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route41Dummy() {
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
  class route42Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at5_testRCX* _s_deserialized;
    const __target_sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route42";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route42Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route42Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __target_sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route42Dummy() {
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
  class route43Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _src;
    const MaceKey& src;
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at_snapshot* _s_deserialized;
    const __sync_at_snapshot& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_route43";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::route( const MaceKey& src,  const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    route43Dummy() : _src(new MaceKey()), src(*_src), _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at_snapshot()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    route43Dummy(const MaceKey& ___src, const MaceKey& ___dest, const __sync_at_snapshot& ___s_deserialized, const registration_uid_t& ___rid) : _src(NULL), src(___src), _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~route43Dummy() {
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
  class send44Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send44";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send44Dummy()  { }
    
    
    
    
    ~send44Dummy() {
      
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
  class send45Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __internal_Ack* _s_deserialized;
    const __internal_Ack& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send45";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send45Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __internal_Ack()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send45Dummy(const MaceKey& ___dest, const __internal_Ack& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send45Dummy() {
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
  class send46Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMigrationRequest* _s_deserialized;
    const ContextMigrationRequest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send46";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send46Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMigrationRequest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send46Dummy(const MaceKey& ___dest, const ContextMigrationRequest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send46Dummy() {
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
  class send47Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    TransferContext* _s_deserialized;
    const TransferContext& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send47";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send47Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new TransferContext()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send47Dummy(const MaceKey& ___dest, const TransferContext& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send47Dummy() {
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
  class send48Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    ReportContextMigration* _s_deserialized;
    const ReportContextMigration& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send48";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send48Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ReportContextMigration()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send48Dummy(const MaceKey& ___dest, const ReportContextMigration& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send48Dummy() {
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
  class send49Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    ContextMappingUpdate* _s_deserialized;
    const ContextMappingUpdate& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send49";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send49Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new ContextMappingUpdate()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send49Dummy(const MaceKey& ___dest, const ContextMappingUpdate& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send49Dummy() {
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
  class send50Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    HeadEvent* _s_deserialized;
    const HeadEvent& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send50";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send50Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new HeadEvent()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send50Dummy(const MaceKey& ___dest, const HeadEvent& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send50Dummy() {
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
  class send51Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at2_rowInit* _s_deserialized;
    const __async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send51";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send51Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send51Dummy(const MaceKey& ___dest, const __async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send51Dummy() {
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
  class send52Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at2_rowInit* _s_deserialized;
    const __target_async_at2_rowInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send52";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send52Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at2_rowInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send52Dummy(const MaceKey& ___dest, const __target_async_at2_rowInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send52Dummy() {
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
  class send53Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at4_rowAfter* _s_deserialized;
    const __async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send53";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send53Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send53Dummy(const MaceKey& ___dest, const __async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send53Dummy() {
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
  class send54Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at4_rowAfter* _s_deserialized;
    const __target_async_at4_rowAfter& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send54";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send54Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at4_rowAfter()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send54Dummy(const MaceKey& ___dest, const __target_async_at4_rowAfter& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send54Dummy() {
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
  class send55Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __async_at8_testMulti* _s_deserialized;
    const __async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send55";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send55Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send55Dummy(const MaceKey& ___dest, const __async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send55Dummy() {
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
  class send56Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_async_at8_testMulti* _s_deserialized;
    const __target_async_at8_testMulti& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send56";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send56Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_async_at8_testMulti()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send56Dummy(const MaceKey& ___dest, const __target_async_at8_testMulti& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send56Dummy() {
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
  class send57Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at1_sctest* _s_deserialized;
    const __sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send57";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send57Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send57Dummy(const MaceKey& ___dest, const __sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send57Dummy() {
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
  class send58Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at1_sctest* _s_deserialized;
    const __target_sync_at1_sctest& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send58";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send58Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at1_sctest()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send58Dummy(const MaceKey& ___dest, const __target_sync_at1_sctest& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send58Dummy() {
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
  class send59Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at3_cellInit* _s_deserialized;
    const __sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send59";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send59Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send59Dummy(const MaceKey& ___dest, const __sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send59Dummy() {
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
  class send60Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at3_cellInit* _s_deserialized;
    const __target_sync_at3_cellInit& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send60";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send60Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at3_cellInit()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send60Dummy(const MaceKey& ___dest, const __target_sync_at3_cellInit& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send60Dummy() {
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
  class send61Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at5_testRCX* _s_deserialized;
    const __sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send61";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send61Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send61Dummy(const MaceKey& ___dest, const __sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send61Dummy() {
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
  class send62Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __target_sync_at5_testRCX* _s_deserialized;
    const __target_sync_at5_testRCX& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send62";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send62Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __target_sync_at5_testRCX()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send62Dummy(const MaceKey& ___dest, const __target_sync_at5_testRCX& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send62Dummy() {
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
  class send63Dummy : public mace::BinaryLogObject, public mace::PrintPrintable {
    protected:
    static mace::LogNode* rootLogNode;
    public:
    MaceKey* _dest;
    const MaceKey& dest;
    __sync_at_snapshot* _s_deserialized;
    const __sync_at_snapshot& s_deserialized;
    registration_uid_t* _rid;
    const registration_uid_t& rid;
    
    const std::string& getLogType() const {
      static std::string type = "Simple_send63";
      return type;
    }
    
    const std::string& getLogDescription() const {
      static const std::string desc = "Simple::send( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)";
      return desc;
    }
    
    LogClass getLogClass() const {
      return SERVICE_BINLOG;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
    
    send63Dummy() : _dest(new MaceKey()), dest(*_dest), _s_deserialized(new __sync_at_snapshot()), s_deserialized(*_s_deserialized), _rid(new registration_uid_t()), rid(*_rid) { }
    
    
    send63Dummy(const MaceKey& ___dest, const __sync_at_snapshot& ___s_deserialized, const registration_uid_t& ___rid) : _dest(NULL), dest(___dest), _s_deserialized(NULL), s_deserialized(___s_deserialized), _rid(NULL), rid(___rid) { }
    
    
    ~send63Dummy() {
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
