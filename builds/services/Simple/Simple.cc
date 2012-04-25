/*********************************************
*  Simple main source file
*  Mace generated on:
*  Tue Apr 10 10:10:28 2012
*********************************************/
//BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"

#include "Simple.h"
#include "Simple-macros.h"
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

bool operator==(const mace::map<int, mace::map<int, Simple_namespace::SimpleService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, Simple_namespace::SimpleService*, mace::SoftState>::const_iterator& rhs) {
  return lhs->second == rhs;
}
bool operator==(const mace::map<int, Simple_namespace::SimpleService*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, Simple_namespace::SimpleService*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
  return lhs == rhs->second;
}
namespace mace {
  template<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;
}
namespace Simple_namespace {
  mace::LogNode* SimpleService::rootLogNode = NULL;
  //    mace::LogNode* SimpleDummy::rootLogNode = NULL;
  //Selector Constants
  //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //const std::string selector_route_downcall_30;
  const LogIdSet* SimpleService::selectorId_route_downcall_30;
  //const std::string selector_send_downcall_61;
  const LogIdSet* SimpleService::selectorId_send_downcall_61;
  //const std::string selector_messageError_demux_32;
  const LogIdSet* SimpleService::selectorId_messageError_demux_32;
  //const std::string selector_messageError_demux_25;
  const LogIdSet* SimpleService::selectorId_messageError_demux_25;
  //const std::string selector_deliver_demux_12;
  const LogIdSet* SimpleService::selectorId_deliver_demux_12;
  //const std::string selector_upcall_messageError_33_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_33_transition;
  //const std::string selector_maceReset_demux_42;
  const LogIdSet* SimpleService::selectorId_maceReset_demux_42;
  //const std::string selector_upcall_messageError_44_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_44_transition;
  //const std::string selector_upcall_messageError_39_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_39_transition;
  //const std::string selector_messageError_demux_34;
  const LogIdSet* SimpleService::selectorId_messageError_demux_34;
  //const std::string selector_async_testMulti_async_2;
  const LogIdSet* SimpleService::selectorId_async_testMulti_async_2;
  //const std::string selector_route_downcall_35;
  const LogIdSet* SimpleService::selectorId_route_downcall_35;
  //const std::string selector_route_downcall_25;
  const LogIdSet* SimpleService::selectorId_route_downcall_25;
  //const std::string selector_rowAfter_demux_51;
  const LogIdSet* SimpleService::selectorId_rowAfter_demux_51;
  //const std::string selector_route_downcall_6;
  const LogIdSet* SimpleService::selectorId_route_downcall_6;
  //const std::string selector_send_downcall_58;
  const LogIdSet* SimpleService::selectorId_send_downcall_58;
  //const std::string selector_send_downcall_62;
  const LogIdSet* SimpleService::selectorId_send_downcall_62;
  //const std::string selector_send_downcall_53;
  const LogIdSet* SimpleService::selectorId_send_downcall_53;
  //const std::string selector_target_async_rowInit_sync_0;
  const LogIdSet* SimpleService::selectorId_target_async_rowInit_sync_0;
  //const std::string selector_upcall_deliver_23_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_23_transition;
  //const std::string selector_send_downcall_54;
  const LogIdSet* SimpleService::selectorId_send_downcall_54;
  //const std::string selector_expireresender_timer;
  const LogIdSet* SimpleService::selectorId_expireresender_timer;
  //const std::string selector_route_downcall_65;
  const LogIdSet* SimpleService::selectorId_route_downcall_65;
  //const std::string selector_route_downcall_20;
  const LogIdSet* SimpleService::selectorId_route_downcall_20;
  //const std::string selector_sync_sctest_1_transition;
  const LogIdSet* SimpleService::selectorId_sync_sctest_1_transition;
  //const std::string selector_upcall_deliver_25_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_25_transition;
  //const std::string selector_route_downcall_34;
  const LogIdSet* SimpleService::selectorId_route_downcall_34;
  //const std::string selector_upcall_deliver_26_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_26_transition;
  //const std::string selector_cancelctsTimer;
  const LogIdSet* SimpleService::selectorId_cancelctsTimer;
  //const std::string selector_upcall_deliver_14_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_14_transition;
  //const std::string selector_upcall_messageError_41_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_41_transition;
  //const std::string selector_route_downcall_10;
  const LogIdSet* SimpleService::selectorId_route_downcall_10;
  //const std::string selector_snapshot_sync_fn_sync_11;
  const LogIdSet* SimpleService::selectorId_snapshot_sync_fn_sync_11;
  //const std::string selector_deliver_demux_19;
  const LogIdSet* SimpleService::selectorId_deliver_demux_19;
  //const std::string selector_messageError_demux_22;
  const LogIdSet* SimpleService::selectorId_messageError_demux_22;
  //const std::string selector_route_downcall_42;
  const LogIdSet* SimpleService::selectorId_route_downcall_42;
  //const std::string selector_route_downcall_27;
  const LogIdSet* SimpleService::selectorId_route_downcall_27;
  //const std::string selector_localAddress_demux_43;
  const LogIdSet* SimpleService::selectorId_localAddress_demux_43;
  //const std::string selector_send_downcall_44;
  const LogIdSet* SimpleService::selectorId_send_downcall_44;
  //const std::string selector_route_downcall_17;
  const LogIdSet* SimpleService::selectorId_route_downcall_17;
  //const std::string selector_deliver_demux_2;
  const LogIdSet* SimpleService::selectorId_deliver_demux_2;
  //const std::string selector_messageError_demux_30;
  const LogIdSet* SimpleService::selectorId_messageError_demux_30;
  //const std::string selector_upcall_deliver_21_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_21_transition;
  //const std::string selector_route_downcall_37;
  const LogIdSet* SimpleService::selectorId_route_downcall_37;
  //const std::string selector_expiret;
  const LogIdSet* SimpleService::selectorId_expiret;
  //const std::string selector_send_downcall_48;
  const LogIdSet* SimpleService::selectorId_send_downcall_48;
  //const std::string selector_expire_resender_timer_demux_47;
  const LogIdSet* SimpleService::selectorId_expire_resender_timer_demux_47;
  //const std::string selector_deliver_demux_11;
  const LogIdSet* SimpleService::selectorId_deliver_demux_11;
  //const std::string selector_upcall_messageError_40_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_40_transition;
  //const std::string selector_deliver_demux_6;
  const LogIdSet* SimpleService::selectorId_deliver_demux_6;
  //const std::string selector_upcall_deliver_17_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_17_transition;
  //const std::string selector_send_downcall_66;
  const LogIdSet* SimpleService::selectorId_send_downcall_66;
  //const std::string selector_messageError_demux_37;
  const LogIdSet* SimpleService::selectorId_messageError_demux_37;
  //const std::string selector_cellInit_demux_54;
  const LogIdSet* SimpleService::selectorId_cellInit_demux_54;
  //const std::string selector_upcall_messageError_47_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_47_transition;
  //const std::string selector_deliver_demux_9;
  const LogIdSet* SimpleService::selectorId_deliver_demux_9;
  //const std::string selector_resumeDeliver_downcall_2;
  const LogIdSet* SimpleService::selectorId_resumeDeliver_downcall_2;
  //const std::string selector_deliver_demux_5;
  const LogIdSet* SimpleService::selectorId_deliver_demux_5;
  //const std::string selector_deliver_demux_15;
  const LogIdSet* SimpleService::selectorId_deliver_demux_15;
  //const std::string selector_target_async_rowAfter_sync_1;
  const LogIdSet* SimpleService::selectorId_target_async_rowAfter_sync_1;
  //const std::string selector_maceInit_demux_39;
  const LogIdSet* SimpleService::selectorId_maceInit_demux_39;
  //const std::string selector_maceExit_demux_41;
  const LogIdSet* SimpleService::selectorId_maceExit_demux_41;
  //const std::string selector_suspendDeliver_downcall_1;
  const LogIdSet* SimpleService::selectorId_suspendDeliver_downcall_1;
  //const std::string selector_messageError_demux_29;
  const LogIdSet* SimpleService::selectorId_messageError_demux_29;
  //const std::string selector_route_downcall_41;
  const LogIdSet* SimpleService::selectorId_route_downcall_41;
  //const std::string selector_upcall_deliver_9_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_9_transition;
  //const std::string selector_send_downcall_49;
  const LogIdSet* SimpleService::selectorId_send_downcall_49;
  //const std::string selector_upcall_deliver_28_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_28_transition;
  //const std::string selector_route_downcall_5;
  const LogIdSet* SimpleService::selectorId_route_downcall_5;
  //const std::string selector_upcall_messageError_35_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_35_transition;
  //const std::string selector_async_rowInit_async_0;
  const LogIdSet* SimpleService::selectorId_async_rowInit_async_0;
  //const std::string selector_upcall_messageError_45_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_45_transition;
  //const std::string selector_send_downcall_56;
  const LogIdSet* SimpleService::selectorId_send_downcall_56;
  //const std::string selector_messageError_demux_35;
  const LogIdSet* SimpleService::selectorId_messageError_demux_35;
  //const std::string selector_getStartContext_sync_10;
  const LogIdSet* SimpleService::selectorId_getStartContext_sync_10;
  //const std::string selector_route_downcall_32;
  const LogIdSet* SimpleService::selectorId_route_downcall_32;
  //const std::string selector_scheduler_expire_resender_timer_10_transition;
  const LogIdSet* SimpleService::selectorId_scheduler_expire_resender_timer_10_transition;
  //const std::string selector_upcall_deliver_19_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_19_transition;
  //const std::string selector_send_downcall_50;
  const LogIdSet* SimpleService::selectorId_send_downcall_50;
  //const std::string selector_messageError_demux_49;
  const LogIdSet* SimpleService::selectorId_messageError_demux_49;
  //const std::string selector_route_downcall_14;
  const LogIdSet* SimpleService::selectorId_route_downcall_14;
  //const std::string selector_deliver_demux_18;
  const LogIdSet* SimpleService::selectorId_deliver_demux_18;
  //const std::string selector_deliver_demux_48;
  const LogIdSet* SimpleService::selectorId_deliver_demux_48;
  //const std::string selector_send_downcall_55;
  const LogIdSet* SimpleService::selectorId_send_downcall_55;
  //const std::string selector_route_downcall_9;
  const LogIdSet* SimpleService::selectorId_route_downcall_9;
  //const std::string selector_route_downcall_22;
  const LogIdSet* SimpleService::selectorId_route_downcall_22;
  //const std::string selector_upcall_deliver_16_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_16_transition;
  //const std::string selector_deliver_demux_16;
  const LogIdSet* SimpleService::selectorId_deliver_demux_16;
  //const std::string selector_upcall_messageError_43_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_43_transition;
  //const std::string selector_upcall_deliver_20_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_20_transition;
  //const std::string selector_deliver_demux_4;
  const LogIdSet* SimpleService::selectorId_deliver_demux_4;
  //const std::string selector_send_downcall_46;
  const LogIdSet* SimpleService::selectorId_send_downcall_46;
  //const std::string selector_deliver_demux_7;
  const LogIdSet* SimpleService::selectorId_deliver_demux_7;
  //const std::string selector_upcall_deliver_22_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_22_transition;
  //const std::string selector_scheduler_expire_t_6_transition;
  const LogIdSet* SimpleService::selectorId_scheduler_expire_t_6_transition;
  //const std::string selector_target_sync_cellInit_sync_6;
  const LogIdSet* SimpleService::selectorId_target_sync_cellInit_sync_6;
  //const std::string selector_route_downcall_16;
  const LogIdSet* SimpleService::selectorId_route_downcall_16;
  //const std::string selector_route_downcall_64;
  const LogIdSet* SimpleService::selectorId_route_downcall_64;
  //const std::string selector_upcall_deliver_13_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_13_transition;
  //const std::string selector_downcall_maceInit_0_transition;
  const LogIdSet* SimpleService::selectorId_downcall_maceInit_0_transition;
  //const std::string selector_messageError_demux_31;
  const LogIdSet* SimpleService::selectorId_messageError_demux_31;
  //const std::string selector_hashState_demux_44;
  const LogIdSet* SimpleService::selectorId_hashState_demux_44;
  //const std::string selector_deliver_demux_13;
  const LogIdSet* SimpleService::selectorId_deliver_demux_13;
  //const std::string selector_sctest_demux_53;
  const LogIdSet* SimpleService::selectorId_sctest_demux_53;
  //const std::string selector_schedulectsTimer;
  const LogIdSet* SimpleService::selectorId_schedulectsTimer;
  //const std::string selector_messageError_demux_33;
  const LogIdSet* SimpleService::selectorId_messageError_demux_33;
  //const std::string selector_expire_ctsTimer_demux_45;
  const LogIdSet* SimpleService::selectorId_expire_ctsTimer_demux_45;
  //const std::string selector_deliver_demux_1;
  const LogIdSet* SimpleService::selectorId_deliver_demux_1;
  //const std::string selector_route_downcall_28;
  const LogIdSet* SimpleService::selectorId_route_downcall_28;
  //const std::string selector_upcall_messageError_30_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_30_transition;
  //const std::string selector_send_downcall_63;
  const LogIdSet* SimpleService::selectorId_send_downcall_63;
  //const std::string selector_async_testMulti_8_transition;
  const LogIdSet* SimpleService::selectorId_async_testMulti_8_transition;
  //const std::string selector_async_rowAfter_async_1;
  const LogIdSet* SimpleService::selectorId_async_rowAfter_async_1;
  //const std::string selector_messageError_demux_24;
  const LogIdSet* SimpleService::selectorId_messageError_demux_24;
  //const std::string selector_route_downcall_11;
  const LogIdSet* SimpleService::selectorId_route_downcall_11;
  //const std::string selector_upcall_deliver_27_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_27_transition;
  //const std::string selector_send_downcall_52;
  const LogIdSet* SimpleService::selectorId_send_downcall_52;
  //const std::string selector_route_downcall_36;
  const LogIdSet* SimpleService::selectorId_route_downcall_36;
  //const std::string selector_route_downcall_7;
  const LogIdSet* SimpleService::selectorId_route_downcall_7;
  //const std::string selector_route_downcall_33;
  const LogIdSet* SimpleService::selectorId_route_downcall_33;
  //const std::string selector_upcall_deliver_18_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_18_transition;
  //const std::string selector_target_async_testMulti_sync_2;
  const LogIdSet* SimpleService::selectorId_target_async_testMulti_sync_2;
  //const std::string selector_send_downcall_45;
  const LogIdSet* SimpleService::selectorId_send_downcall_45;
  //const std::string selector_route_downcall_24;
  const LogIdSet* SimpleService::selectorId_route_downcall_24;
  //const std::string selector_async_rowAfter_4_transition;
  const LogIdSet* SimpleService::selectorId_async_rowAfter_4_transition;
  //const std::string selector_send_downcall_47;
  const LogIdSet* SimpleService::selectorId_send_downcall_47;
  //const std::string selector_sync_sctest_sync_3;
  const LogIdSet* SimpleService::selectorId_sync_sctest_sync_3;
  //const std::string selector_upcall_messageError_31_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_31_transition;
  //const std::string selector_messageError_demux_20;
  const LogIdSet* SimpleService::selectorId_messageError_demux_20;
  //const std::string selector_route_downcall_43;
  const LogIdSet* SimpleService::selectorId_route_downcall_43;
  //const std::string selector_route_downcall_18;
  const LogIdSet* SimpleService::selectorId_route_downcall_18;
  //const std::string selector_schedulet;
  const LogIdSet* SimpleService::selectorId_schedulet;
  //const std::string selector_messageError_demux_26;
  const LogIdSet* SimpleService::selectorId_messageError_demux_26;
  //const std::string selector_route_downcall_19;
  const LogIdSet* SimpleService::selectorId_route_downcall_19;
  //const std::string selector_scheduler_expire_ctsTimer_7_transition;
  const LogIdSet* SimpleService::selectorId_scheduler_expire_ctsTimer_7_transition;
  //const std::string selector_send_downcall_59;
  const LogIdSet* SimpleService::selectorId_send_downcall_59;
  //const std::string selector_deliver_demux_10;
  const LogIdSet* SimpleService::selectorId_deliver_demux_10;
  //const std::string selector_messageError_demux_38;
  const LogIdSet* SimpleService::selectorId_messageError_demux_38;
  //const std::string selector_upcall_messageError_38_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_38_transition;
  //const std::string selector_expirectsTimer;
  const LogIdSet* SimpleService::selectorId_expirectsTimer;
  //const std::string selector_route_downcall_4;
  const LogIdSet* SimpleService::selectorId_route_downcall_4;
  //const std::string selector_sync_cellInit_3_transition;
  const LogIdSet* SimpleService::selectorId_sync_cellInit_3_transition;
  //const std::string selector_maceResume_demux_40;
  const LogIdSet* SimpleService::selectorId_maceResume_demux_40;
  //const std::string selector_target_sync_testRCX_sync_8;
  const LogIdSet* SimpleService::selectorId_target_sync_testRCX_sync_8;
  //const std::string selector_resumeDeliver_downcall_3;
  const LogIdSet* SimpleService::selectorId_resumeDeliver_downcall_3;
  //const std::string selector_route_downcall_39;
  const LogIdSet* SimpleService::selectorId_route_downcall_39;
  //const std::string selector_route_downcall_8;
  const LogIdSet* SimpleService::selectorId_route_downcall_8;
  //const std::string selector_route_downcall_15;
  const LogIdSet* SimpleService::selectorId_route_downcall_15;
  //const std::string selector_async_rowInit_2_transition;
  const LogIdSet* SimpleService::selectorId_async_rowInit_2_transition;
  //const std::string selector_send_downcall_57;
  const LogIdSet* SimpleService::selectorId_send_downcall_57;
  //const std::string selector_route_downcall_23;
  const LogIdSet* SimpleService::selectorId_route_downcall_23;
  //const std::string selector_cancelresender_timer;
  const LogIdSet* SimpleService::selectorId_cancelresender_timer;
  //const std::string selector_testRCX_demux_55;
  const LogIdSet* SimpleService::selectorId_testRCX_demux_55;
  //const std::string selector_messageError_demux_21;
  const LogIdSet* SimpleService::selectorId_messageError_demux_21;
  //const std::string selector_error_demux_0;
  const LogIdSet* SimpleService::selectorId_error_demux_0;
  //const std::string selector_route_downcall_26;
  const LogIdSet* SimpleService::selectorId_route_downcall_26;
  //const std::string selector_deliver_demux_14;
  const LogIdSet* SimpleService::selectorId_deliver_demux_14;
  //const std::string selector_upcall_deliver_12_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_12_transition;
  //const std::string selector_upcall_deliver_11_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_11_transition;
  //const std::string selector_sync_testRCX_5_transition;
  const LogIdSet* SimpleService::selectorId_sync_testRCX_5_transition;
  //const std::string selector_messageError_demux_36;
  const LogIdSet* SimpleService::selectorId_messageError_demux_36;
  //const std::string selector_route_downcall_38;
  const LogIdSet* SimpleService::selectorId_route_downcall_38;
  //const std::string selector_messageError_demux_28;
  const LogIdSet* SimpleService::selectorId_messageError_demux_28;
  //const std::string selector_rowInit_demux_50;
  const LogIdSet* SimpleService::selectorId_rowInit_demux_50;
  //const std::string selector_send_downcall_60;
  const LogIdSet* SimpleService::selectorId_send_downcall_60;
  //const std::string selector_upcall_messageError_42_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_42_transition;
  //const std::string selector_route_downcall_12;
  const LogIdSet* SimpleService::selectorId_route_downcall_12;
  //const std::string selector_target_sync_sctest_sync_4;
  const LogIdSet* SimpleService::selectorId_target_sync_sctest_sync_4;
  //const std::string selector_route_downcall_40;
  const LogIdSet* SimpleService::selectorId_route_downcall_40;
  //const std::string selector_deliver_demux_8;
  const LogIdSet* SimpleService::selectorId_deliver_demux_8;
  //const std::string selector_route_downcall_21;
  const LogIdSet* SimpleService::selectorId_route_downcall_21;
  //const std::string selector_upcall_messageError_32_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_32_transition;
  //const std::string selector_route_downcall_31;
  const LogIdSet* SimpleService::selectorId_route_downcall_31;
  //const std::string selector_route_downcall_13;
  const LogIdSet* SimpleService::selectorId_route_downcall_13;
  //const std::string selector_messageError_demux_27;
  const LogIdSet* SimpleService::selectorId_messageError_demux_27;
  //const std::string selector_upcall_messageError_29_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_29_transition;
  //const std::string selector_upcall_messageError_34_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_34_transition;
  //const std::string selector_expire_t_demux_46;
  const LogIdSet* SimpleService::selectorId_expire_t_demux_46;
  //const std::string selector_send_downcall_51;
  const LogIdSet* SimpleService::selectorId_send_downcall_51;
  //const std::string selector_scheduleresender_timer;
  const LogIdSet* SimpleService::selectorId_scheduleresender_timer;
  //const std::string selector_findContextByID_sync_9;
  const LogIdSet* SimpleService::selectorId_findContextByID_sync_9;
  //const std::string selector_deliver_demux_3;
  const LogIdSet* SimpleService::selectorId_deliver_demux_3;
  //const std::string selector_upcall_messageError_46_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_46_transition;
  //const std::string selector_upcall_messageError_37_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_37_transition;
  //const std::string selector_upcall_deliver_15_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_15_transition;
  //const std::string selector_sync_testRCX_sync_7;
  const LogIdSet* SimpleService::selectorId_sync_testRCX_sync_7;
  //const std::string selector_upcall_messageError_36_transition;
  const LogIdSet* SimpleService::selectorId_upcall_messageError_36_transition;
  //const std::string selector_upcall_deliver_24_transition;
  const LogIdSet* SimpleService::selectorId_upcall_deliver_24_transition;
  //const std::string selector_testMulti_demux_52;
  const LogIdSet* SimpleService::selectorId_testMulti_demux_52;
  //const std::string selector_sync_cellInit_sync_5;
  const LogIdSet* SimpleService::selectorId_sync_cellInit_sync_5;
  //const std::string selector_messageError_demux_23;
  const LogIdSet* SimpleService::selectorId_messageError_demux_23;
  //const std::string selector_cancelt;
  const LogIdSet* SimpleService::selectorId_cancelt;
  //const std::string selector_deliver_demux_17;
  const LogIdSet* SimpleService::selectorId_deliver_demux_17;
  //const std::string selector_suspendDeliver_downcall_0;
  const LogIdSet* SimpleService::selectorId_suspendDeliver_downcall_0;
  //const std::string selector_route_downcall_29;
  const LogIdSet* SimpleService::selectorId_route_downcall_29;
  //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
  //Change Tracker (optional)
  //BEGIN Mace::Compiler::ServiceImpl::printChangeTracker
  //END Mace::Compiler::ServiceImpl::printChangeTracker
  
  //service variable includes and uses
  
  
  //Transition and Guard Implementations
  //BEGIN Mace::Compiler::ServiceImpl::printTransitions
  bool SimpleService::guard_downcall_0_maceInit() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 101 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        state==init
#line 449 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::downcall_0_maceInit() {
    #define selector selector_downcall_maceInit_0_transition
    #define selectorId selectorId_downcall_maceInit_0_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 101 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      bool a = sync_sctest();
      a = false;
      return;
      rows = ROWS;
      columns = COLUMNS;
      
      matrix_rows = MATRIXROWS;
      matrix_columns = MATRIXCOLUMNS;
      
      initial_matrix.resize( rows );
      result.resize( rows );
      current_iteration = 0;
      finished_row = 0;
      init_rows = 0;
      runs = 0;
      for(int i=0;i< rows;i++){
        initial_matrix[i].resize( columns );
        result[i].resize( columns );
      }
      
      for( int i=0;i< rows; i++ ){
        async_rowInit( i,0 );
      }
    }
#line 494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_sync_1_sctest() const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 126 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        state==init
#line 508 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  bool SimpleService::sync_1_sctest() {
    #define selector selector_sync_sctest_1_transition
    #define selectorId selectorId_sync_sctest_1_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    __T__Context& thisContext __attribute((unused)) = T;
    bool& test __attribute((unused)) = thisContext.test;
    
    
    #line 126 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      return true;
    }
#line 539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_async_2_rowInit(
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const & row
#line 547 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  x
#line 551 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        state==init
#line 561 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::async_2_rowInit(
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      const int& row
#line 570 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int x
#line 574 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1) {
    #define selector selector_async_rowInit_2_transition
    #define selectorId selectorId_async_rowInit_2_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    __R__Context& thisContext __attribute((unused)) = R[row];
    int& init_cells __attribute((unused)) = thisContext.init_cells;
    int& finished_cell __attribute((unused)) = thisContext.finished_cell;
    const __R__Context& Rx __attribute((unused)) = R[x].getSnapshot();
    
    
    #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      finished_cell  = 0;
      init_cells  = 0;
      
      for( int j=0;j<columns;j++){
        bool a = sync_cellInit(row,j);
        a = false;
      }
    }
#line 608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_sync_3_cellInit(
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  row
#line 616 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  column
#line 620 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1, mace::string const & snapshotContext2) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        state==init
#line 630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  bool SimpleService::sync_3_cellInit(
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int row
#line 639 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int column
#line 643 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1, mace::string const & snapshotContext2) {
    #define selector selector_sync_cellInit_3_transition
    #define selectorId selectorId_sync_cellInit_3_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    const __R__Context& __R_snapshot __attribute((unused))= R[row].getSnapshot();
    const int& init_cells __attribute((unused)) = __R_snapshot.init_cells;
    const int& finished_cell __attribute((unused)) = __R_snapshot.finished_cell;
    __C__Context& thisContext __attribute((unused)) = R[row].C[column];
    int& matrix_row_from __attribute((unused)) = thisContext.matrix_row_from;
    int& matrix_column_from __attribute((unused)) = thisContext.matrix_column_from;
    Matrix& values __attribute((unused)) = thisContext.values;
    bool& receivedPivotRow __attribute((unused)) = thisContext.receivedPivotRow;
    bool& receivedPivotColumn __attribute((unused)) = thisContext.receivedPivotColumn;
    const __T__Context& TContext __attribute((unused)) = T.getSnapshot();
    const __R__Context& myRow __attribute((unused)) = R[row].getSnapshot();
    
    
    #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      
      // locally generates values
      values.resize( ( matrix_rows/rows) );
      for(int i=0;i< ( matrix_rows/rows); i++ ){
        values[i].resize( ( matrix_columns/columns) );
        for(int j=0;j< ( matrix_rows/rows); j++ ){
          values[i][j] = RandomUtil::randInt(1000);
        }
      }
      //      int row_init_cells = Row.init_cells;
      
      matrix_row_from    = row * ( matrix_rows / rows );
      matrix_column_from = column * ( matrix_columns / rows );
      
      receivedPivotRow = false;
      receivedPivotColumn = false;
      
      async_rowAfter(row);
      
      sync_testRCX(row,column,1);
      
      return true;
    }
#line 699 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_async_4_rowAfter(
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  row
#line 707 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        true
#line 717 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::async_4_rowAfter(
      #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int row
#line 726 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) {
    #define selector selector_async_rowAfter_4_transition
    #define selectorId selectorId_async_rowAfter_4_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    __R__Context& thisContext __attribute((unused)) = R[row];
    int& init_cells __attribute((unused)) = thisContext.init_cells;
    int& finished_cell __attribute((unused)) = thisContext.finished_cell;
    
    
    #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      //int rows_snapshot = rows;
    }
#line 753 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_sync_5_testRCX(
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  row
#line 761 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  column
#line 765 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const  x
#line 769 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        state==init
#line 779 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::sync_5_testRCX(
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int row
#line 788 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int column
#line 792 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int x
#line 796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3) {
    #define selector selector_sync_testRCX_5_transition
    #define selectorId selectorId_sync_testRCX_5_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    const __R__Context& __R_snapshot __attribute((unused))= R[row].getSnapshot();
    const int& init_cells __attribute((unused)) = __R_snapshot.init_cells;
    const int& finished_cell __attribute((unused)) = __R_snapshot.finished_cell;
    const __C__Context& __C_snapshot __attribute((unused))= R[row].C[column].getSnapshot();
    const int& matrix_row_from __attribute((unused)) = __C_snapshot.matrix_row_from;
    const int& matrix_column_from __attribute((unused)) = __C_snapshot.matrix_column_from;
    const Matrix& values __attribute((unused)) = __C_snapshot.values;
    const bool& receivedPivotRow __attribute((unused)) = __C_snapshot.receivedPivotRow;
    const bool& receivedPivotColumn __attribute((unused)) = __C_snapshot.receivedPivotColumn;
    __X__Context& thisContext __attribute((unused)) = R[row].C[column].X[x];
    bool& testX __attribute((unused)) = thisContext.testX;
    const __C__Context& myCell __attribute((unused)) = R[row].C[column].getSnapshot();
    const __T__Context& TContext __attribute((unused)) = T.getSnapshot();
    const __R__Context& myRow __attribute((unused)) = R[row].getSnapshot();
    
    
    #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
    }
#line 833 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_scheduler_6_expire_t(
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const & row
#line 841 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const & column
#line 845 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int const & x
#line 849 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        true
#line 859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::scheduler_6_expire_t(
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int& row
#line 868 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int& column
#line 872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int& x
#line 876 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) {
    #define selector selector_scheduler_expire_t_6_transition
    #define selectorId selectorId_scheduler_expire_t_6_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    const __R__Context& __R_snapshot __attribute((unused))= R[row].getSnapshot();
    const int& init_cells __attribute((unused)) = __R_snapshot.init_cells;
    const int& finished_cell __attribute((unused)) = __R_snapshot.finished_cell;
    const __C__Context& __C_snapshot __attribute((unused))= R[row].C[column].getSnapshot();
    const int& matrix_row_from __attribute((unused)) = __C_snapshot.matrix_row_from;
    const int& matrix_column_from __attribute((unused)) = __C_snapshot.matrix_column_from;
    const Matrix& values __attribute((unused)) = __C_snapshot.values;
    const bool& receivedPivotRow __attribute((unused)) = __C_snapshot.receivedPivotRow;
    const bool& receivedPivotColumn __attribute((unused)) = __C_snapshot.receivedPivotColumn;
    __X__Context& thisContext __attribute((unused)) = R[row].C[column].X[x];
    bool& testX __attribute((unused)) = thisContext.testX;
    
    
    #line 172 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      
    }
#line 911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_scheduler_7_expire_ctsTimer(
      #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      MaceKey const & dest
#line 919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        true
#line 929 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::scheduler_7_expire_ctsTimer(
      #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      MaceKey& dest
#line 938 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) {
    #define selector selector_scheduler_expire_ctsTimer_7_transition
    #define selectorId selectorId_scheduler_expire_ctsTimer_7_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    #line 175 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
    }
#line 955 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_async_8_testMulti(
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      uint32_t const  m1
#line 963 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::string const  str
#line 967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) const {
    // guard_type = state_expr
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
        true
#line 977 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::async_8_testMulti(
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      uint32_t m1
#line 986 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      mace::string str
#line 990 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) {
    #define selector selector_async_testMulti_8_transition
    #define selectorId selectorId_async_testMulti_8_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    // isUsedVariablesParsed = 0
    
    // used variables within transition =
    
    // Refer to ServiceImpl.pm:printTransition()
    
    __eventContextType = 1;
    __eventContextType = 1;
    
    __M__Context& thisContext __attribute((unused)) = M[ __M__Context__param( m1,str ) ];
    bool& test __attribute((unused)) = thisContext.test;
    
    
    #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    {
      
    }
#line 1016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    
    #undef selector
    #undef selectorId
  }
  bool SimpleService::guard_upcall_9_deliver(
      #line 321 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      MaceKey const & src
#line 1024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 322 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      MaceKey const & dest
#line 1028 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 323 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      __internal_Ack const & msg
#line 1032 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) const {
    // guard_type = state_var
    // transition is in write mode.
    // referenced variables =
    
    __eventContextType = 1;
    if(
        #line 329 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
        true
#line 1042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
    ) {
      return true;
    }
    return false;
  }
  void SimpleService::upcall_9_deliver(
      #line 321 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      const MaceKey& src
#line 1051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 322 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      const MaceKey& dest
#line 1055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ,
      #line 323 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
      const __internal_Ack& msg
#line 1059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
  ) {
    #define selector selector_upcall_deliver_9_transition
    #define selectorId selectorId_upcall_deliver_9_transition
    PREPARE_FUNCTION
    ADD_LOG_BACKING
    
    // Transition.pm:printTransitionFunction()
    // Locking type = 1
    __eventContextType = 1;
    
    
    
    
    {
      // TODO: need to lock on internal lock?
      ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
      //if( __internal_unAck.find( src ) == __internal_unAck.end() ){
        if( __internal_unAck.find( msg.ackctx ) == __internal_unAck.end() ){
          // Ack came from whom I have never sent message. WTF? Maybe failure occured?
          macedbg(1)<<"Ack came from "<<src<<",context="<< msg.ackctx <<" whom I haven't received Ack before. Did something just recovered from failure?"<<Log::endl;
        }else{
          
          macedbg(1)<<"Ack "<< msg.ackno <<" received"<<Log::endl;
          // remove buffers that sequence number is <= msg.ackno
          //mace::map<uint32_t, mace::string>::iterator bufferIt = __internal_unAck[src].begin();
          mace::map<uint32_t, mace::string>::iterator bufferIt = __internal_unAck[msg.ackctx].begin();
          //while( bufferIt != __internal_unAck[src].end() && bufferIt->first <= msg.ackno ){
            while( bufferIt != __internal_unAck[msg.ackctx].end() && bufferIt->first <= msg.ackno ){
              //__internal_unAck[src].erase( bufferIt );
              __internal_unAck[msg.ackctx].erase( bufferIt );
              macedbg(1)<<"Removing seqno "<< bufferIt->first <<" from __internal_unAck"<<Log::endl;
              //bufferIt = __internal_unAck[src].begin();
              bufferIt = __internal_unAck[msg.ackctx].begin();
            }
            
          }
          
        }
        
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_scheduler_10_expire_resender_timer() const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 403 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            true
#line 1111 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::scheduler_10_expire_resender_timer() {
        #define selector selector_scheduler_expire_resender_timer_10_transition
        #define selectorId selectorId_scheduler_expire_resender_timer_10_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator unAckPeers;
          // FIXME: resender should resend according to the sequence number...
          for(unAckPeers = __internal_unAck.begin(); unAckPeers != __internal_unAck.end(); unAckPeers++){
            for( mace::map<uint32_t, mace::string>::iterator unAckPacket= unAckPeers->second.begin(); unAckPacket != unAckPeers->second.end(); unAckPacket++ ){
              //std::cout<<"resending to "<< unAckPeers->first<< " , seqno="<< unAckPacket->first << std::endl;
              Message *msg;
              switch( Message::getType( unAckPacket->second ) ){
                case __async_at2_rowInit::messageType: msg = new __async_at2_rowInit(); msg->deserializeStr( unAckPacket->second );break;
                case __async_at4_rowAfter::messageType: msg = new __async_at4_rowAfter(); msg->deserializeStr( unAckPacket->second );break;
                case __async_at8_testMulti::messageType: msg = new __async_at8_testMulti(); msg->deserializeStr( unAckPacket->second );break;
                case __sync_at1_sctest::messageType: msg = new __sync_at1_sctest(); msg->deserializeStr( unAckPacket->second );break;
                case __sync_at3_cellInit::messageType: msg = new __sync_at3_cellInit(); msg->deserializeStr( unAckPacket->second );break;
                case __sync_at5_testRCX::messageType: msg = new __sync_at5_testRCX(); msg->deserializeStr( unAckPacket->second );break;
              }
              downcall_route( ContextMapping::getNodeByContext(unAckPeers->first), *msg );
              delete msg;
            }
          }
        }
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_upcall_11_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & src
#line 1155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & dest
#line 1159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          ContextMigrationRequest const & msg
#line 1163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 2608 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
            true
#line 1173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::upcall_11_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& src
#line 1182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& dest
#line 1186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const ContextMigrationRequest& msg
#line 1190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) {
        #define selector selector_upcall_deliver_11_transition
        #define selectorId selectorId_upcall_deliver_11_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          // wait for earlier events to finish // msg.eventId
          
          // we're accessing the internal structure as well as context structure
          ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
          
          mace::string ctxSnapshot;
          Serializable* sobj = findContextByID(msg.ctxId);
          mace::serialize( ctxSnapshot, sobj );
          
          // release the internal structure which are not used after migration.
          // __internal_msgseqno, __internal_lastAckedSeqno, __internal_receivedSeqno, __internal_unAck
          mace::map<mace::string, uint32_t>::iterator imsgseqno_it;
          mace::map<mace::string, uint32_t>::iterator ilastAckedSeqno_it;
          mace::map<mace::string, mace::map<uint32_t, uint8_t> >::iterator ireceivedSeqno_it;
          mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator iunAck_it;
          
          //MaceKey dummyNode = MaceKey::null;
          mace::string dummyContext = "";
          if( (imsgseqno_it= __internal_msgseqno.find(/*msg.ctxId*/ dummyContext ) ) != __internal_msgseqno.end() ){
            mace::serialize( ctxSnapshot, &(imsgseqno_it->second) );
            __internal_msgseqno.erase( imsgseqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (ilastAckedSeqno_it= __internal_lastAckedSeqno.find(/*msg.ctxId*/ dummyContext ) ) != __internal_lastAckedSeqno.end() ){
            mace::serialize( ctxSnapshot, &(ilastAckedSeqno_it->second) );
            __internal_lastAckedSeqno.erase( ilastAckedSeqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (ireceivedSeqno_it= __internal_receivedSeqno.find(/*msg.ctxId*/ dummyContext ) ) != __internal_receivedSeqno.end() ){
            mace::serialize( ctxSnapshot, &(ireceivedSeqno_it->second) );
            __internal_receivedSeqno.erase( ireceivedSeqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (iunAck_it= __internal_unAck.find(/*msg.ctxId*/ dummyContext ) ) != __internal_unAck.end() ){
            mace::serialize( ctxSnapshot, &(iunAck_it->second) );
            __internal_unAck.erase( iunAck_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          
          
          downcall_route( msg.dest, TransferContext( msg.ctxId, ctxSnapshot, msg.eventId ) );
        }
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_upcall_12_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & src
#line 1256 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & dest
#line 1260 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          TransferContext const & msg
#line 1264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 2608 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
            true
#line 1274 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::upcall_12_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& src
#line 1283 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& dest
#line 1287 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const TransferContext& msg
#line 1291 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) {
        #define selector selector_upcall_deliver_12_transition
        #define selectorId selectorId_upcall_deliver_12_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          mace::string ctxSnapshot;
          Serializable *sobj;
          // wait for earlier events to finish
          
          // traverse the context structure
          sobj = findContextByID( msg.ctxId );
          // create object using name string
          mace::deserialize( ctxSnapshot, sobj );
          
          mace::map<mace::string, uint32_t>::iterator imsgseqno_it;
          mace::map<mace::string, uint32_t>::iterator ilastAckedSeqno_it;
          mace::map<mace::string, mace::map<uint32_t, uint8_t> >::iterator ireceivedSeqno_it;
          mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator iunAck_it;
          
          //MaceKey dummyNode = MaceKey::null;
          mace::string dummyContext = "";
          if( (imsgseqno_it= __internal_msgseqno.find( dummyContext ) ) == __internal_msgseqno.end() ){
            mace::deserialize( ctxSnapshot, &(__internal_msgseqno[ dummyContext] ) );
            __internal_msgseqno.erase( imsgseqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (ilastAckedSeqno_it= __internal_lastAckedSeqno.find( dummyContext ) ) == __internal_lastAckedSeqno.end() ){
            mace::deserialize( ctxSnapshot, &(__internal_lastAckedSeqno[ dummyContext] ) );
            __internal_lastAckedSeqno.erase( ilastAckedSeqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (ireceivedSeqno_it= __internal_receivedSeqno.find(dummyContext ) ) == __internal_receivedSeqno.end() ){
            mace::deserialize( ctxSnapshot, &(__internal_receivedSeqno[ dummyContext] ) );
            __internal_receivedSeqno.erase( ireceivedSeqno_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          if( (iunAck_it= __internal_unAck.find(dummyContext ) ) == __internal_unAck.end() ){
            mace::deserialize( ctxSnapshot, &(__internal_unAck[ dummyContext] ) );
            __internal_unAck.erase( iunAck_it );
          }else{
            maceerr<<"Unexpected! "<<Log::endl;
          }
          
          downcall_route( ContextMapping::getHead(), ReportContextMigration(msg.ctxId, msg.eventId) );
          
          // update my local context mapping
          mace::list<mace::string> tmpCtxList;
          tmpCtxList.push_back( msg.ctxId );
          ContextMapping::updateMapping( localAddress(), tmpCtxList );
        }
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_upcall_13_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & src
#line 1359 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & dest
#line 1363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          ReportContextMigration const & msg
#line 1367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 2608 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
            true
#line 1377 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::upcall_13_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& src
#line 1386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& dest
#line 1390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const ReportContextMigration& msg
#line 1394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) {
        #define selector selector_upcall_deliver_13_transition
        #define selectorId selectorId_upcall_deliver_13_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          // commit the migration event
          if( ContextMapping::getHead() == localAddress() ){
            // send messages to all nodes( except the src of this message ) to update context mapping
            for( std::set<MaceKey>::iterator nodeit = ContextMapping::getAllNodes().begin();
                nodeit != ContextMapping::getAllNodes().end(); nodeit ++ ){
              downcall_route( *nodeit, ContextMappingUpdate( msg.ctxId, src )) ;
            }
          }else{
            maceerr<< "ReportContextMigration message should go to head only" << Log::endl;
          }
        }
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_upcall_14_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & src
#line 1425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & dest
#line 1429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          ContextMappingUpdate const & msg
#line 1433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 2608 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
            true
#line 1443 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::upcall_14_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& src
#line 1452 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& dest
#line 1456 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const ContextMappingUpdate& msg
#line 1460 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) {
        #define selector selector_upcall_deliver_14_transition
        #define selectorId selectorId_upcall_deliver_14_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          mace::list<mace::string> tmpCtxList;
          tmpCtxList.push_back( msg.ctxId );
          ContextMapping::updateMapping(msg.node, tmpCtxList );
        }
        #undef selector
        #undef selectorId
      }
      bool SimpleService::guard_upcall_15_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & src
#line 1484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          MaceKey const & dest
#line 1488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          HeadEvent const & msg
#line 1492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) const {
        // guard_type = state_var
        // transition is in write mode.
        // referenced variables =
        
        __eventContextType = 1;
        if(
            #line 2608 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
            true
#line 1502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          return true;
        }
        return false;
      }
      void SimpleService::upcall_15_deliver(
          #line 2600 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& src
#line 1511 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2601 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const MaceKey& dest
#line 1515 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ,
          #line 2602 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
          const HeadEvent& msg
#line 1519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
      ) {
        #define selector selector_upcall_deliver_15_transition
        #define selectorId selectorId_upcall_deliver_15_transition
        PREPARE_FUNCTION
        ADD_LOG_BACKING
        
        // Transition.pm:printTransitionFunction()
        // Locking type = 1
        __eventContextType = 1;
        
        
        
        {
          if( ContextMapping::getHead() == localAddress() ){
            //switch( msg.event.getEventType() ){
              switch( msg.event.eventType ){
                case mace::HighLevelEvent::STARTEVENT:
                break;
                case mace::HighLevelEvent::ENDEVENT:
                break;
                case mace::HighLevelEvent::TIMEREVENT:
                break;
                case mace::HighLevelEvent::ASYNCEVENT:
                break;
                case mace::HighLevelEvent::MIGRATIONEVENT:
                break;
                case mace::HighLevelEvent::UNDEFEVENT:
                break;
              }
            }
          }
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_16_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 1557 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 1561 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __async_at2_rowInit const & s_deserialized
#line 1565 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 1569 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 1579 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_16_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 1588 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 1592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __async_at2_rowInit& s_deserialized
#line 1596 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 1600 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_16_transition
          #define selectorId selectorId_upcall_deliver_16_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::asyncCallHandlerHack() line: 5820
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID;
          if( source == ContextMapping::getHead() ){ // assuming the head node does not have other contexts
            srcContextID = ContextMapping::getHeadContext();
          }else{
            srcContextID = s_deserialized.srcContextID; // third parameter
          }
          // chuangw: This message is sent between src->head, head->start
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          //std::cout<<"packet(__async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the same packet has already been received before
            sl.unlock();
            //std::cout<<"packet(__async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){ // erase the first sequence number not acknowledged
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              sl.unlock();
              mace::string snapshotContext0 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[0]);
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              target_async_rowInit(s_deserialized.row, s_deserialized.x, snapshotContext0);
            }else if( downcall_localAddress() == ContextMapping::getHead() ){
              mace::HighLevelEvent he( mace::HighLevelEvent::ASYNCEVENT );
              
              // make a copy of the message similar to the original, except the seqno & ticket
              uint32_t msgseqno = ++__internal_msgseqno[s_deserialized.startContextID];
              __async_at2_rowInit pcopy(s_deserialized.row,s_deserialized.x,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,he.getEventID(),msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
              
              sl.unlock();
              downcall_route( ContextMapping::getNodeByContext( s_deserialized.startContextID ) , pcopy);
              //AsyncDispatch::enqueueEvent(this, (AsyncDispatch::asyncfunc)&Simple_namespace::SimpleService::__async_head_fn2_rowInit,(void*)new  __async_at2_rowInit(s_deserialized) );
            }else{ // sanity check
              maceerr << "Message generated by async call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the head nor the start context" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_17_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 1672 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 1676 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_async_at2_rowInit const & s_deserialized
#line 1680 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 1684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 1694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_17_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 1703 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 1707 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_async_at2_rowInit& s_deserialized
#line 1711 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 1715 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_17_transition
          #define selectorId selectorId_upcall_deliver_17_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_async_at2_rowInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              rowInit(s_deserialized.row, s_deserialized.x, s_deserialized.snapshotContext1);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_async_at2_rowInit pcopy(s_deserialized.row,s_deserialized.x,s_deserialized.snapshotContext1,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_18_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 1787 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 1791 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __async_at4_rowAfter const & s_deserialized
#line 1795 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 1799 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 1809 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_18_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 1818 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 1822 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __async_at4_rowAfter& s_deserialized
#line 1826 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 1830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_18_transition
          #define selectorId selectorId_upcall_deliver_18_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::asyncCallHandlerHack() line: 5820
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID;
          if( source == ContextMapping::getHead() ){ // assuming the head node does not have other contexts
            srcContextID = ContextMapping::getHeadContext();
          }else{
            srcContextID = s_deserialized.srcContextID; // third parameter
          }
          // chuangw: This message is sent between src->head, head->start
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          //std::cout<<"packet(__async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the same packet has already been received before
            sl.unlock();
            //std::cout<<"packet(__async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){ // erase the first sequence number not acknowledged
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              target_async_rowAfter(s_deserialized.row);
            }else if( downcall_localAddress() == ContextMapping::getHead() ){
              mace::HighLevelEvent he( mace::HighLevelEvent::ASYNCEVENT );
              
              // make a copy of the message similar to the original, except the seqno & ticket
              uint32_t msgseqno = ++__internal_msgseqno[s_deserialized.startContextID];
              __async_at4_rowAfter pcopy(s_deserialized.row,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,he.getEventID(),msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
              
              sl.unlock();
              downcall_route( ContextMapping::getNodeByContext( s_deserialized.startContextID ) , pcopy);
              //AsyncDispatch::enqueueEvent(this, (AsyncDispatch::asyncfunc)&Simple_namespace::SimpleService::__async_head_fn4_rowAfter,(void*)new  __async_at4_rowAfter(s_deserialized) );
            }else{ // sanity check
              maceerr << "Message generated by async call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the head nor the start context" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_19_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 1901 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 1905 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_async_at4_rowAfter const & s_deserialized
#line 1909 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 1913 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 1923 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_19_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 1932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 1936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_async_at4_rowAfter& s_deserialized
#line 1940 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 1944 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_19_transition
          #define selectorId selectorId_upcall_deliver_19_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_async_at4_rowAfter) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              rowAfter(s_deserialized.row);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_async_at4_rowAfter pcopy(s_deserialized.row,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_20_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __async_at8_testMulti const & s_deserialized
#line 2024 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2028 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_20_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2051 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __async_at8_testMulti& s_deserialized
#line 2055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2059 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_20_transition
          #define selectorId selectorId_upcall_deliver_20_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::asyncCallHandlerHack() line: 5820
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID;
          if( source == ContextMapping::getHead() ){ // assuming the head node does not have other contexts
            srcContextID = ContextMapping::getHeadContext();
          }else{
            srcContextID = s_deserialized.srcContextID; // third parameter
          }
          // chuangw: This message is sent between src->head, head->start
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          //std::cout<<"packet(__async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the same packet has already been received before
            sl.unlock();
            //std::cout<<"packet(__async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){ // erase the first sequence number not acknowledged
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              target_async_testMulti(s_deserialized.m1, s_deserialized.str);
            }else if( downcall_localAddress() == ContextMapping::getHead() ){
              mace::HighLevelEvent he( mace::HighLevelEvent::ASYNCEVENT );
              
              // make a copy of the message similar to the original, except the seqno & ticket
              uint32_t msgseqno = ++__internal_msgseqno[s_deserialized.startContextID];
              __async_at8_testMulti pcopy(s_deserialized.m1,s_deserialized.str,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,he.getEventID(),msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
              
              sl.unlock();
              downcall_route( ContextMapping::getNodeByContext( s_deserialized.startContextID ) , pcopy);
              //AsyncDispatch::enqueueEvent(this, (AsyncDispatch::asyncfunc)&Simple_namespace::SimpleService::__async_head_fn8_testMulti,(void*)new  __async_at8_testMulti(s_deserialized) );
            }else{ // sanity check
              maceerr << "Message generated by async call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the head nor the start context" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_21_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2130 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2134 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_async_at8_testMulti const & s_deserialized
#line 2138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2142 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2152 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_21_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2165 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_async_at8_testMulti& s_deserialized
#line 2169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2173 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_21_transition
          #define selectorId selectorId_upcall_deliver_21_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_async_at8_testMulti) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              testMulti(s_deserialized.m1, s_deserialized.str);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_async_at8_testMulti pcopy(s_deserialized.m1,s_deserialized.str,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_22_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2245 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2249 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __sync_at1_sctest const & s_deserialized
#line 2253 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2267 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_22_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2280 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __sync_at1_sctest& s_deserialized
#line 2284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_22_transition
          #define selectorId selectorId_upcall_deliver_22_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          
          mace::string srcContextID = s_deserialized.srcContextID;
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          
          //std::cout<<"packet(__sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            sl.unlock();
            //std::cout<<"packet(__sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            mace::string srcContextID = s_deserialized.srcContextID;
            
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            
            // update acknowledge sequence number
            // __internal_lastAckedSeqno[source] = s_deserialized.seqno;
            //std::cout<<"packet(__sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              // don't request null lock to use the ticket. Because the following function will.
              sl.unlock();
              
              
              mace::string returnValueStr;
              target_sync_sctest();
              
              sl.lock();
              
              //mace::string srcContextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(srcContextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[srcContextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[srcContextID];
              }
              __sync_at1_sctest pcopy(s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,returnValueStr,s_deserialized.ticket,msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ srcContextID ][ msgseqno ] = buf;
              // make a copy of the message similar to the original, except the seqno
              
              
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_23_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2372 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_sync_at1_sctest const & s_deserialized
#line 2380 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2384 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_23_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2403 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2407 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_sync_at1_sctest& s_deserialized
#line 2411 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2415 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_23_transition
          #define selectorId selectorId_upcall_deliver_23_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_sync_at1_sctest) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              mace::string returnValueStr;
              bool returnValue = sctest ();
              mace::serialize(returnValueStr, &returnValue);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_sync_at1_sctest pcopy(s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,returnValueStr,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
              std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(s_deserialized.srcContextID);
              if(mutex_iter != mutexMapping.end()){
                returnValueMapping[s_deserialized.srcContextID] = s_deserialized.returnValue;
                pthread_mutex_unlock( &( mutex_iter->second)) ;
              }
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_24_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2494 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2498 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __sync_at3_cellInit const & s_deserialized
#line 2502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2516 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_24_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2525 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2529 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __sync_at3_cellInit& s_deserialized
#line 2533 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2537 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_24_transition
          #define selectorId selectorId_upcall_deliver_24_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          
          mace::string srcContextID = s_deserialized.srcContextID;
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          
          //std::cout<<"packet(__sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            sl.unlock();
            //std::cout<<"packet(__sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            mace::string srcContextID = s_deserialized.srcContextID;
            
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            
            // update acknowledge sequence number
            // __internal_lastAckedSeqno[source] = s_deserialized.seqno;
            //std::cout<<"packet(__sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              // don't request null lock to use the ticket. Because the following function will.
              sl.unlock();
              
              mace::string snapshotContext0 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[0]);
              
              mace::string snapshotContext1 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[1]);
              
              
              mace::string returnValueStr;
              target_sync_cellInit(s_deserialized.row, s_deserialized.column, snapshotContext0, snapshotContext1);
              
              sl.lock();
              
              //mace::string srcContextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(srcContextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[srcContextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[srcContextID];
              }
              __sync_at3_cellInit pcopy(s_deserialized.row,s_deserialized.column,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,returnValueStr,s_deserialized.ticket,msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ srcContextID ][ msgseqno ] = buf;
              // make a copy of the message similar to the original, except the seqno
              
              
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_25_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2625 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2629 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_sync_at3_cellInit const & s_deserialized
#line 2633 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2637 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2647 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_25_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2656 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2660 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_sync_at3_cellInit& s_deserialized
#line 2664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2668 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_25_transition
          #define selectorId selectorId_upcall_deliver_25_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_sync_at3_cellInit) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              mace::string returnValueStr;
              bool returnValue = cellInit (s_deserialized.row, s_deserialized.column, s_deserialized.snapshotContext1, s_deserialized.snapshotContext2);
              mace::serialize(returnValueStr, &returnValue);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_sync_at3_cellInit pcopy(s_deserialized.row,s_deserialized.column,s_deserialized.snapshotContext1,s_deserialized.snapshotContext2,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,returnValueStr,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
              std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(s_deserialized.srcContextID);
              if(mutex_iter != mutexMapping.end()){
                returnValueMapping[s_deserialized.srcContextID] = s_deserialized.returnValue;
                pthread_mutex_unlock( &( mutex_iter->second)) ;
              }
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_26_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2747 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __sync_at5_testRCX const & s_deserialized
#line 2755 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2759 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2769 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_26_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2778 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2782 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __sync_at5_testRCX& s_deserialized
#line 2786 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2790 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_26_transition
          #define selectorId selectorId_upcall_deliver_26_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          
          mace::string srcContextID = s_deserialized.srcContextID;
          mace::string currentContextID = ThreadStructure::getCurrentContext();
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          
          //std::cout<<"packet(__sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            sl.unlock();
            //std::cout<<"packet(__sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            mace::string srcContextID = s_deserialized.srcContextID;
            
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            
            // update acknowledge sequence number
            // __internal_lastAckedSeqno[source] = s_deserialized.seqno;
            //std::cout<<"packet(__sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.startContextID) == downcall_localAddress() ){
              // don't request null lock to use the ticket. Because the following function will.
              sl.unlock();
              
              mace::string snapshotContext0 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[0]);
              
              mace::string snapshotContext1 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[1]);
              
              mace::string snapshotContext2 = snapshot_sync_fn(currentContextID,  s_deserialized.snapshotContextIDs[2]);
              
              
              mace::string returnValueStr;
              target_sync_testRCX(s_deserialized.row, s_deserialized.column, s_deserialized.x, snapshotContext0, snapshotContext1, snapshotContext2);
              
              sl.lock();
              
              //mace::string srcContextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(srcContextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[srcContextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[srcContextID];
              }
              __sync_at5_testRCX pcopy(s_deserialized.row,s_deserialized.column,s_deserialized.x,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.snapshotContextIDs,returnValueStr,s_deserialized.ticket,msgseqno);
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ srcContextID ][ msgseqno ] = buf;
              // make a copy of the message similar to the original, except the seqno
              
              
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_27_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2880 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2884 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __target_sync_at5_testRCX const & s_deserialized
#line 2888 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 2892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 2902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_27_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 2911 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 2915 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __target_sync_at5_testRCX& s_deserialized
#line 2919 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 2923 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_27_transition
          #define selectorId selectorId_upcall_deliver_27_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::targetSyncCallHandlerHack() line: 5430
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          mace::string srcContextID = s_deserialized.srcContextID;
          //std::cout<<"packet(__target_sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            //std::cout<<"packet(__target_sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
              __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
              __internal_lastAckedSeqno[srcContextID]++;
              expectedSeqno++;
            }
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
            //std::cout<<"packet(__target_sync_at5_testRCX) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
            if( ContextMapping::getNodeByContext(s_deserialized.targetContextID) == downcall_localAddress() ){
              sl.unlock();
              
              ThreadStructure::setTicket( s_deserialized.ticket );
              testRCX(s_deserialized.row, s_deserialized.column, s_deserialized.x, s_deserialized.snapshotContext1, s_deserialized.snapshotContext2, s_deserialized.snapshotContext3);
              
              sl.lock();
              
              mace::string contextID = s_deserialized.srcContextID;
              uint32_t msgseqno;
              if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                msgseqno = 1;
                __internal_msgseqno[contextID] = msgseqno;
              }else{
                msgseqno = ++__internal_msgseqno[contextID];
              }
              __target_sync_at5_testRCX pcopy(s_deserialized.row,s_deserialized.column,s_deserialized.x,s_deserialized.snapshotContext1,s_deserialized.snapshotContext2,s_deserialized.snapshotContext3,s_deserialized.srcContextID,s_deserialized.startContextID,s_deserialized.targetContextID,s_deserialized.ticket,msgseqno);
              // make a copy of the message similar to the original, except the seqno
              mace::string buf;
              mace::serialize(buf, &pcopy);
              __internal_unAck[ contextID ][ msgseqno ] = buf;
              // event has finished at the target context. Respond to start context.
              downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
            }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
              
            }else{ // sanity check
              maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
              maceerr << "I am not the destination node!" << Log::endl;
              ABORT("IMPOSSIBLE MESSAGE DESTINATION");
            }
            
            
          }
          
          #undef selector
          #undef selectorId
        }
        bool SimpleService::guard_upcall_28_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & source
#line 2995 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            MaceKey const & destination
#line 2999 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            __sync_at_snapshot const & s_deserialized
#line 3003 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t const  rid
#line 3007 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) const {
          // guard_type = state_var
          // transition is in write mode.
          // referenced variables =
          
          __eventContextType = 1;
          if(
              #line 2787 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
              true
#line 3017 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            return true;
          }
          return false;
        }
        void SimpleService::upcall_28_deliver(
            #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& source
#line 3026 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const MaceKey& destination
#line 3030 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            const __sync_at_snapshot& s_deserialized
#line 3034 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ,
            #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
            registration_uid_t rid
#line 3038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
        ) {
          #define selector selector_upcall_deliver_28_transition
          #define selectorId selectorId_upcall_deliver_28_transition
          PREPARE_FUNCTION
          ADD_LOG_BACKING
          
          // Transition.pm:printTransitionFunction()
          // Locking type = 1
          __eventContextType = 1;
          
          
          
          
          ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
          const mace::string& srcContextID = s_deserialized.srcContextID;
          const mace::string& snapshotContextID = s_deserialized.snapshotContextID;
          //std::cout<<"packet(__sync_at_snapshot) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
          if( s_deserialized.seqno <= __internal_lastAckedSeqno[srcContextID] ){
            // send back the last acknowledge sequence number
            downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
            sl.unlock();
            
            // std::cout<<"packet(__sync_at_snapshot) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" was ignored, but acked."<<std::endl;
          } else {
            // update received seqno queue & lastAckseqno
            // XXX: I know it's not efficient. But I want to keep it easier to understand. Will fix it once the code is stable.
            __internal_receivedSeqno[srcContextID][ s_deserialized.seqno ] = 1;
            // uint32_t expectedSeqno = __internal_lastAckedSeqno[source]+1;
            uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
            // while( expectedSeqno == __internal_receivedSeqno[source].begin()->first ){
              while( expectedSeqno == __internal_receivedSeqno[ srcContextID ].begin()->first ){
                __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
                __internal_lastAckedSeqno[srcContextID]++;
                expectedSeqno++;
              }
              
              downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
              
              // update acknowledge sequence number
              // __internal_lastAckedSeqno[srcContextID] = s_deserialized.seqno;
              // std::cout<<"packet(__sync_at_snapshot) from "<<source<<" has sequence number "<< s_deserialized.seqno <<" processed nominally"<<std::endl;
              if( ContextMapping::getNodeByContext(s_deserialized.snapshotContextID) == downcall_localAddress() ){
                // don't request null lock to use the ticket. Because the following function will.
                // mace::serialize(returnValue,  &s_deserialized.snapshotContextID);
                mace::string ctxSnapshot;
                
                Serializable* sobj = findContextByID(snapshotContextID);
                mace::serialize( ctxSnapshot, sobj );
                
                
                mace::string contextID = s_deserialized.srcContextID;
                uint32_t msgseqno;
                if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end() ){
                  msgseqno = 1;
                  __internal_msgseqno[contextID] = msgseqno;
                }else{
                  msgseqno = ++__internal_msgseqno[contextID];
                }
                __sync_at_snapshot pcopy(s_deserialized.srcContextID,s_deserialized.snapshotContextID,ctxSnapshot,msgseqno);
                mace::string buf;
                mace::serialize(buf, &pcopy);
                __internal_unAck[ contextID ][ msgseqno ] = buf;
                // make a copy of the message similar to the original, except the seqno
                
                downcall_route( ContextMapping::getNodeByContext(s_deserialized.srcContextID),  pcopy);
              }else if( ContextMapping::getNodeByContext(s_deserialized.srcContextID) == downcall_localAddress() ){
                std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(s_deserialized.srcContextID);
                if(mutex_iter != mutexMapping.end()){
                  returnValueMapping[s_deserialized.srcContextID] = s_deserialized.contextSnapshot;
                  pthread_mutex_unlock( &(mutex_iter->second) );
                }
                
              }else{ // sanity check
                maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
                maceerr << "I am not the destination node!" << Log::endl;
                ABORT("IMPOSSIBLE MESSAGE DESTINATION");
              }
              
              
            }
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_29_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3126 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3130 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __internal_Ack const & message_deserialized
#line 3134 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3148 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_29_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& message_deserialized
#line 3165 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3169 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_29_transition
            #define selectorId selectorId_upcall_messageError_29_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_30_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3193 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              ContextMigrationRequest const & message_deserialized
#line 3201 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3205 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3215 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_30_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3228 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& message_deserialized
#line 3232 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3236 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_30_transition
            #define selectorId selectorId_upcall_messageError_30_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3252 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_31_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3260 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3264 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransferContext const & message_deserialized
#line 3268 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3272 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3282 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_31_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3291 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3295 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& message_deserialized
#line 3299 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_31_transition
            #define selectorId selectorId_upcall_messageError_31_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3319 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_32_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3327 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              ReportContextMigration const & message_deserialized
#line 3335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3349 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_32_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3358 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3362 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& message_deserialized
#line 3366 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3370 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_32_transition
            #define selectorId selectorId_upcall_messageError_32_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_33_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              ContextMappingUpdate const & message_deserialized
#line 3402 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3406 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3416 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_33_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3425 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3429 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& message_deserialized
#line 3433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_33_transition
            #define selectorId selectorId_upcall_messageError_33_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3453 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_34_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3461 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3465 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              HeadEvent const & message_deserialized
#line 3469 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3473 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3483 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_34_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3496 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& message_deserialized
#line 3500 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_34_transition
            #define selectorId selectorId_upcall_messageError_34_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3520 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_35_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3528 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3532 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __async_at2_rowInit const & message_deserialized
#line 3536 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3540 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3550 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_35_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3559 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3563 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& message_deserialized
#line 3567 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3571 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_35_transition
            #define selectorId selectorId_upcall_messageError_35_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3587 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_36_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3595 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_async_at2_rowInit const & message_deserialized
#line 3603 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3607 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3617 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_36_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3626 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& message_deserialized
#line 3634 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3638 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_36_transition
            #define selectorId selectorId_upcall_messageError_36_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3654 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_37_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3662 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3666 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __async_at4_rowAfter const & message_deserialized
#line 3670 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3674 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3684 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_37_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3693 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3697 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& message_deserialized
#line 3701 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3705 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_37_transition
            #define selectorId selectorId_upcall_messageError_37_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3721 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_38_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3729 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3733 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_async_at4_rowAfter const & message_deserialized
#line 3737 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3741 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_38_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3760 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3764 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& message_deserialized
#line 3768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_38_transition
            #define selectorId selectorId_upcall_messageError_38_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3788 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_39_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3796 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __async_at8_testMulti const & message_deserialized
#line 3804 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3818 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_39_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3831 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& message_deserialized
#line 3835 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3839 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_39_transition
            #define selectorId selectorId_upcall_messageError_39_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3855 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_40_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3867 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_async_at8_testMulti const & message_deserialized
#line 3871 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3875 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3885 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_40_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& message_deserialized
#line 3902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_40_transition
            #define selectorId selectorId_upcall_messageError_40_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3922 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_41_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3930 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 3934 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __sync_at1_sctest const & message_deserialized
#line 3938 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 3942 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 3952 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_41_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 3961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 3965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& message_deserialized
#line 3969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 3973 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_41_transition
            #define selectorId selectorId_upcall_messageError_41_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 3989 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_42_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 3997 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4001 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_sync_at1_sctest const & message_deserialized
#line 4005 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4009 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4019 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_42_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4028 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4032 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& message_deserialized
#line 4036 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4040 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_42_transition
            #define selectorId selectorId_upcall_messageError_42_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4056 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_43_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 4064 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4068 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __sync_at3_cellInit const & message_deserialized
#line 4072 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4086 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_43_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4095 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4099 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& message_deserialized
#line 4103 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_43_transition
            #define selectorId selectorId_upcall_messageError_43_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_44_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 4131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4135 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_sync_at3_cellInit const & message_deserialized
#line 4139 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4143 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_44_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4162 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4166 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& message_deserialized
#line 4170 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_44_transition
            #define selectorId selectorId_upcall_messageError_44_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_45_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 4198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4202 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __sync_at5_testRCX const & message_deserialized
#line 4206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4210 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4220 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_45_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4229 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4233 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& message_deserialized
#line 4237 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4241 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_45_transition
            #define selectorId selectorId_upcall_messageError_45_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_46_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 4265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4269 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __target_sync_at5_testRCX const & message_deserialized
#line 4273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4277 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4287 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_46_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4296 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4300 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& message_deserialized
#line 4304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4308 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_46_transition
            #define selectorId selectorId_upcall_messageError_46_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          bool SimpleService::guard_upcall_47_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              MaceKey const & dest
#line 4332 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type const  errorCode
#line 4336 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              __sync_at_snapshot const & message_deserialized
#line 4340 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t const  rid
#line 4344 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) const {
            // guard_type = state_var
            // transition is in write mode.
            // referenced variables =
            
            __eventContextType = 1;
            if(
                #line 2695 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/ServiceImpl.pm"
                true
#line 4354 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            ) {
              return true;
            }
            return false;
          }
          void SimpleService::upcall_47_messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 4363 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 4367 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& message_deserialized
#line 4371 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 4375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            #define selector selector_upcall_messageError_47_transition
            #define selectorId selectorId_upcall_messageError_47_transition
            PREPARE_FUNCTION
            ADD_LOG_BACKING
            
            // Transition.pm:printTransitionFunction()
            // Locking type = 1
            __eventContextType = 1;
            
            
            
            
            #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
            { }
#line 4391 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            #undef selector
            #undef selectorId
          }
          //END Mace::Compiler::ServiceImpl::printTransitions
          
          //Structured Logging Functions
          mace::LogNode* maceInit67Dummy::rootLogNode = NULL;
          mace::LogNode* maceReset70Dummy::rootLogNode = NULL;
          mace::LogNode* hashState72Dummy::rootLogNode = NULL;
          mace::LogNode* deliver74Dummy::rootLogNode = NULL;
          mace::LogNode* deliver75Dummy::rootLogNode = NULL;
          mace::LogNode* deliver76Dummy::rootLogNode = NULL;
          mace::LogNode* deliver77Dummy::rootLogNode = NULL;
          mace::LogNode* deliver78Dummy::rootLogNode = NULL;
          mace::LogNode* deliver79Dummy::rootLogNode = NULL;
          mace::LogNode* deliver80Dummy::rootLogNode = NULL;
          mace::LogNode* deliver81Dummy::rootLogNode = NULL;
          mace::LogNode* deliver82Dummy::rootLogNode = NULL;
          mace::LogNode* deliver83Dummy::rootLogNode = NULL;
          mace::LogNode* deliver84Dummy::rootLogNode = NULL;
          mace::LogNode* deliver85Dummy::rootLogNode = NULL;
          mace::LogNode* deliver86Dummy::rootLogNode = NULL;
          mace::LogNode* deliver87Dummy::rootLogNode = NULL;
          mace::LogNode* deliver88Dummy::rootLogNode = NULL;
          mace::LogNode* deliver89Dummy::rootLogNode = NULL;
          mace::LogNode* deliver90Dummy::rootLogNode = NULL;
          mace::LogNode* deliver91Dummy::rootLogNode = NULL;
          mace::LogNode* deliver92Dummy::rootLogNode = NULL;
          mace::LogNode* messageError93Dummy::rootLogNode = NULL;
          mace::LogNode* messageError94Dummy::rootLogNode = NULL;
          mace::LogNode* messageError95Dummy::rootLogNode = NULL;
          mace::LogNode* messageError96Dummy::rootLogNode = NULL;
          mace::LogNode* messageError97Dummy::rootLogNode = NULL;
          mace::LogNode* messageError98Dummy::rootLogNode = NULL;
          mace::LogNode* messageError99Dummy::rootLogNode = NULL;
          mace::LogNode* messageError100Dummy::rootLogNode = NULL;
          mace::LogNode* messageError101Dummy::rootLogNode = NULL;
          mace::LogNode* messageError102Dummy::rootLogNode = NULL;
          mace::LogNode* messageError103Dummy::rootLogNode = NULL;
          mace::LogNode* messageError104Dummy::rootLogNode = NULL;
          mace::LogNode* messageError105Dummy::rootLogNode = NULL;
          mace::LogNode* messageError106Dummy::rootLogNode = NULL;
          mace::LogNode* messageError107Dummy::rootLogNode = NULL;
          mace::LogNode* messageError108Dummy::rootLogNode = NULL;
          mace::LogNode* messageError109Dummy::rootLogNode = NULL;
          mace::LogNode* messageError110Dummy::rootLogNode = NULL;
          mace::LogNode* messageError111Dummy::rootLogNode = NULL;
          mace::LogNode* expire_ctsTimer112Dummy::rootLogNode = NULL;
          mace::LogNode* expire_t113Dummy::rootLogNode = NULL;
          mace::LogNode* expire_resender_timer114Dummy::rootLogNode = NULL;
          mace::LogNode* suspendDeliver0Dummy::rootLogNode = NULL;
          mace::LogNode* suspendDeliver1Dummy::rootLogNode = NULL;
          mace::LogNode* resumeDeliver2Dummy::rootLogNode = NULL;
          mace::LogNode* resumeDeliver3Dummy::rootLogNode = NULL;
          mace::LogNode* route4Dummy::rootLogNode = NULL;
          mace::LogNode* route5Dummy::rootLogNode = NULL;
          mace::LogNode* route6Dummy::rootLogNode = NULL;
          mace::LogNode* route7Dummy::rootLogNode = NULL;
          mace::LogNode* route8Dummy::rootLogNode = NULL;
          mace::LogNode* route9Dummy::rootLogNode = NULL;
          mace::LogNode* route10Dummy::rootLogNode = NULL;
          mace::LogNode* route11Dummy::rootLogNode = NULL;
          mace::LogNode* route12Dummy::rootLogNode = NULL;
          mace::LogNode* route13Dummy::rootLogNode = NULL;
          mace::LogNode* route14Dummy::rootLogNode = NULL;
          mace::LogNode* route15Dummy::rootLogNode = NULL;
          mace::LogNode* route16Dummy::rootLogNode = NULL;
          mace::LogNode* route17Dummy::rootLogNode = NULL;
          mace::LogNode* route18Dummy::rootLogNode = NULL;
          mace::LogNode* route19Dummy::rootLogNode = NULL;
          mace::LogNode* route20Dummy::rootLogNode = NULL;
          mace::LogNode* route21Dummy::rootLogNode = NULL;
          mace::LogNode* route22Dummy::rootLogNode = NULL;
          mace::LogNode* route23Dummy::rootLogNode = NULL;
          mace::LogNode* route24Dummy::rootLogNode = NULL;
          mace::LogNode* route25Dummy::rootLogNode = NULL;
          mace::LogNode* route26Dummy::rootLogNode = NULL;
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
          mace::LogNode* route39Dummy::rootLogNode = NULL;
          mace::LogNode* route40Dummy::rootLogNode = NULL;
          mace::LogNode* route41Dummy::rootLogNode = NULL;
          mace::LogNode* route42Dummy::rootLogNode = NULL;
          mace::LogNode* route43Dummy::rootLogNode = NULL;
          mace::LogNode* send44Dummy::rootLogNode = NULL;
          mace::LogNode* send45Dummy::rootLogNode = NULL;
          mace::LogNode* send46Dummy::rootLogNode = NULL;
          mace::LogNode* send47Dummy::rootLogNode = NULL;
          mace::LogNode* send48Dummy::rootLogNode = NULL;
          mace::LogNode* send49Dummy::rootLogNode = NULL;
          mace::LogNode* send50Dummy::rootLogNode = NULL;
          mace::LogNode* send51Dummy::rootLogNode = NULL;
          mace::LogNode* send52Dummy::rootLogNode = NULL;
          mace::LogNode* send53Dummy::rootLogNode = NULL;
          mace::LogNode* send54Dummy::rootLogNode = NULL;
          mace::LogNode* send55Dummy::rootLogNode = NULL;
          mace::LogNode* send56Dummy::rootLogNode = NULL;
          mace::LogNode* send57Dummy::rootLogNode = NULL;
          mace::LogNode* send58Dummy::rootLogNode = NULL;
          mace::LogNode* send59Dummy::rootLogNode = NULL;
          mace::LogNode* send60Dummy::rootLogNode = NULL;
          mace::LogNode* send61Dummy::rootLogNode = NULL;
          mace::LogNode* send62Dummy::rootLogNode = NULL;
          mace::LogNode* send63Dummy::rootLogNode = NULL;
          // logging funcs
          bool SimpleService::shouldLog_maceInit67() const {
            return true;
          }
          bool SimpleService::shouldLog_maceResume68() const {
            return true;
          }
          bool SimpleService::shouldLog_maceExit69() const {
            return true;
          }
          bool SimpleService::shouldLog_maceReset70() const {
            return true;
          }
          bool SimpleService::shouldLog_localAddress71() const {
            return true;
          }
          bool SimpleService::shouldLog_hashState72() const {
            return true;
          }
          bool SimpleService::shouldLog_error73( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver74( const MaceKey& source,  const MaceKey& destination,  const __internal_Ack& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver75( const MaceKey& source,  const MaceKey& destination,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver76( const MaceKey& source,  const MaceKey& destination,  const TransferContext& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver77( const MaceKey& source,  const MaceKey& destination,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver78( const MaceKey& source,  const MaceKey& destination,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver79( const MaceKey& source,  const MaceKey& destination,  const HeadEvent& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver80( const MaceKey& source,  const MaceKey& destination,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver81( const MaceKey& source,  const MaceKey& destination,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver82( const MaceKey& source,  const MaceKey& destination,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver83( const MaceKey& source,  const MaceKey& destination,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver84( const MaceKey& source,  const MaceKey& destination,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver85( const MaceKey& source,  const MaceKey& destination,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver86( const MaceKey& source,  const MaceKey& destination,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver87( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver88( const MaceKey& source,  const MaceKey& destination,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver89( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver90( const MaceKey& source,  const MaceKey& destination,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver91( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_deliver92( const MaceKey& source,  const MaceKey& destination,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError93( const MaceKey& dest, TransportError::type errorCode,  const __internal_Ack& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError94( const MaceKey& dest, TransportError::type errorCode,  const ContextMigrationRequest& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError95( const MaceKey& dest, TransportError::type errorCode,  const TransferContext& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError96( const MaceKey& dest, TransportError::type errorCode,  const ReportContextMigration& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError97( const MaceKey& dest, TransportError::type errorCode,  const ContextMappingUpdate& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError98( const MaceKey& dest, TransportError::type errorCode,  const HeadEvent& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError99( const MaceKey& dest, TransportError::type errorCode,  const __async_at2_rowInit& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError100( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at2_rowInit& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError101( const MaceKey& dest, TransportError::type errorCode,  const __async_at4_rowAfter& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError102( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at4_rowAfter& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError103( const MaceKey& dest, TransportError::type errorCode,  const __async_at8_testMulti& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError104( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at8_testMulti& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError105( const MaceKey& dest, TransportError::type errorCode,  const __sync_at1_sctest& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError106( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at1_sctest& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError107( const MaceKey& dest, TransportError::type errorCode,  const __sync_at3_cellInit& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError108( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at3_cellInit& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError109( const MaceKey& dest, TransportError::type errorCode,  const __sync_at5_testRCX& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError110( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at5_testRCX& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_messageError111( const MaceKey& dest, TransportError::type errorCode,  const __sync_at_snapshot& message_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_expire_ctsTimer112(MaceKey& p0) const {
            return true;
          }
          bool SimpleService::shouldLog_expire_t113(int& p0, int& p1, int& p2) const {
            return true;
          }
          bool SimpleService::shouldLog_expire_resender_timer114() const {
            return true;
          }
          bool SimpleService::shouldLog_suspendDeliver0(registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_suspendDeliver1( const MaceKey& dest, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_resumeDeliver2(registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_resumeDeliver3( const MaceKey& dest, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route4( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route5( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route6( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route7( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route8( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route9( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route10( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route11( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route12( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route13( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route14( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route15( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route16( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route17( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route18( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route19( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route20( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route21( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route22( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route23( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route24( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route25( const MaceKey& src,  const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route26( const MaceKey& src,  const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route27( const MaceKey& src,  const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route28( const MaceKey& src,  const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route29( const MaceKey& src,  const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route30( const MaceKey& src,  const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route31( const MaceKey& src,  const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route32( const MaceKey& src,  const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route33( const MaceKey& src,  const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route34( const MaceKey& src,  const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route35( const MaceKey& src,  const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route36( const MaceKey& src,  const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route37( const MaceKey& src,  const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route38( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route39( const MaceKey& src,  const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route40( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route41( const MaceKey& src,  const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route42( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_route43( const MaceKey& src,  const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send44( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send45( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send46( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send47( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send48( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send49( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send50( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send51( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send52( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send53( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send54( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send55( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send56( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send57( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send58( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send59( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send60( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send61( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send62( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid) const {
            return true;
          }
          bool SimpleService::shouldLog_send63( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid) const {
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
              SimpleService::selectorId_route_downcall_30 = new LogIdSet(selector_route_downcall_30);
              SimpleService::selectorId_send_downcall_61 = new LogIdSet(selector_send_downcall_61);
              SimpleService::selectorId_messageError_demux_32 = new LogIdSet(selector_messageError_demux_32);
              SimpleService::selectorId_messageError_demux_25 = new LogIdSet(selector_messageError_demux_25);
              SimpleService::selectorId_deliver_demux_12 = new LogIdSet(selector_deliver_demux_12);
              SimpleService::selectorId_upcall_messageError_33_transition = new LogIdSet(selector_upcall_messageError_33_transition);
              SimpleService::selectorId_maceReset_demux_42 = new LogIdSet(selector_maceReset_demux_42);
              SimpleService::selectorId_upcall_messageError_44_transition = new LogIdSet(selector_upcall_messageError_44_transition);
              SimpleService::selectorId_upcall_messageError_39_transition = new LogIdSet(selector_upcall_messageError_39_transition);
              SimpleService::selectorId_messageError_demux_34 = new LogIdSet(selector_messageError_demux_34);
              SimpleService::selectorId_async_testMulti_async_2 = new LogIdSet(selector_async_testMulti_async_2);
              SimpleService::selectorId_route_downcall_35 = new LogIdSet(selector_route_downcall_35);
              SimpleService::selectorId_route_downcall_25 = new LogIdSet(selector_route_downcall_25);
              SimpleService::selectorId_rowAfter_demux_51 = new LogIdSet(selector_rowAfter_demux_51);
              SimpleService::selectorId_route_downcall_6 = new LogIdSet(selector_route_downcall_6);
              SimpleService::selectorId_send_downcall_58 = new LogIdSet(selector_send_downcall_58);
              SimpleService::selectorId_send_downcall_62 = new LogIdSet(selector_send_downcall_62);
              SimpleService::selectorId_send_downcall_53 = new LogIdSet(selector_send_downcall_53);
              SimpleService::selectorId_target_async_rowInit_sync_0 = new LogIdSet(selector_target_async_rowInit_sync_0);
              SimpleService::selectorId_upcall_deliver_23_transition = new LogIdSet(selector_upcall_deliver_23_transition);
              SimpleService::selectorId_send_downcall_54 = new LogIdSet(selector_send_downcall_54);
              SimpleService::selectorId_expireresender_timer = new LogIdSet(selector_expireresender_timer);
              SimpleService::selectorId_route_downcall_65 = new LogIdSet(selector_route_downcall_65);
              SimpleService::selectorId_route_downcall_20 = new LogIdSet(selector_route_downcall_20);
              SimpleService::selectorId_sync_sctest_1_transition = new LogIdSet(selector_sync_sctest_1_transition);
              SimpleService::selectorId_upcall_deliver_25_transition = new LogIdSet(selector_upcall_deliver_25_transition);
              SimpleService::selectorId_route_downcall_34 = new LogIdSet(selector_route_downcall_34);
              SimpleService::selectorId_upcall_deliver_26_transition = new LogIdSet(selector_upcall_deliver_26_transition);
              SimpleService::selectorId_cancelctsTimer = new LogIdSet(selector_cancelctsTimer);
              SimpleService::selectorId_upcall_deliver_14_transition = new LogIdSet(selector_upcall_deliver_14_transition);
              SimpleService::selectorId_upcall_messageError_41_transition = new LogIdSet(selector_upcall_messageError_41_transition);
              SimpleService::selectorId_route_downcall_10 = new LogIdSet(selector_route_downcall_10);
              SimpleService::selectorId_snapshot_sync_fn_sync_11 = new LogIdSet(selector_snapshot_sync_fn_sync_11);
              SimpleService::selectorId_deliver_demux_19 = new LogIdSet(selector_deliver_demux_19);
              SimpleService::selectorId_messageError_demux_22 = new LogIdSet(selector_messageError_demux_22);
              SimpleService::selectorId_route_downcall_42 = new LogIdSet(selector_route_downcall_42);
              SimpleService::selectorId_route_downcall_27 = new LogIdSet(selector_route_downcall_27);
              SimpleService::selectorId_localAddress_demux_43 = new LogIdSet(selector_localAddress_demux_43);
              SimpleService::selectorId_send_downcall_44 = new LogIdSet(selector_send_downcall_44);
              SimpleService::selectorId_route_downcall_17 = new LogIdSet(selector_route_downcall_17);
              SimpleService::selectorId_deliver_demux_2 = new LogIdSet(selector_deliver_demux_2);
              SimpleService::selectorId_messageError_demux_30 = new LogIdSet(selector_messageError_demux_30);
              SimpleService::selectorId_upcall_deliver_21_transition = new LogIdSet(selector_upcall_deliver_21_transition);
              SimpleService::selectorId_route_downcall_37 = new LogIdSet(selector_route_downcall_37);
              SimpleService::selectorId_expiret = new LogIdSet(selector_expiret);
              SimpleService::selectorId_send_downcall_48 = new LogIdSet(selector_send_downcall_48);
              SimpleService::selectorId_expire_resender_timer_demux_47 = new LogIdSet(selector_expire_resender_timer_demux_47);
              SimpleService::selectorId_deliver_demux_11 = new LogIdSet(selector_deliver_demux_11);
              SimpleService::selectorId_upcall_messageError_40_transition = new LogIdSet(selector_upcall_messageError_40_transition);
              SimpleService::selectorId_deliver_demux_6 = new LogIdSet(selector_deliver_demux_6);
              SimpleService::selectorId_upcall_deliver_17_transition = new LogIdSet(selector_upcall_deliver_17_transition);
              SimpleService::selectorId_send_downcall_66 = new LogIdSet(selector_send_downcall_66);
              SimpleService::selectorId_messageError_demux_37 = new LogIdSet(selector_messageError_demux_37);
              SimpleService::selectorId_cellInit_demux_54 = new LogIdSet(selector_cellInit_demux_54);
              SimpleService::selectorId_upcall_messageError_47_transition = new LogIdSet(selector_upcall_messageError_47_transition);
              SimpleService::selectorId_deliver_demux_9 = new LogIdSet(selector_deliver_demux_9);
              SimpleService::selectorId_resumeDeliver_downcall_2 = new LogIdSet(selector_resumeDeliver_downcall_2);
              SimpleService::selectorId_deliver_demux_5 = new LogIdSet(selector_deliver_demux_5);
              SimpleService::selectorId_deliver_demux_15 = new LogIdSet(selector_deliver_demux_15);
              SimpleService::selectorId_target_async_rowAfter_sync_1 = new LogIdSet(selector_target_async_rowAfter_sync_1);
              SimpleService::selectorId_maceInit_demux_39 = new LogIdSet(selector_maceInit_demux_39);
              SimpleService::selectorId_maceExit_demux_41 = new LogIdSet(selector_maceExit_demux_41);
              SimpleService::selectorId_suspendDeliver_downcall_1 = new LogIdSet(selector_suspendDeliver_downcall_1);
              SimpleService::selectorId_messageError_demux_29 = new LogIdSet(selector_messageError_demux_29);
              SimpleService::selectorId_route_downcall_41 = new LogIdSet(selector_route_downcall_41);
              SimpleService::selectorId_upcall_deliver_9_transition = new LogIdSet(selector_upcall_deliver_9_transition);
              SimpleService::selectorId_send_downcall_49 = new LogIdSet(selector_send_downcall_49);
              SimpleService::selectorId_upcall_deliver_28_transition = new LogIdSet(selector_upcall_deliver_28_transition);
              SimpleService::selectorId_route_downcall_5 = new LogIdSet(selector_route_downcall_5);
              SimpleService::selectorId_upcall_messageError_35_transition = new LogIdSet(selector_upcall_messageError_35_transition);
              SimpleService::selectorId_async_rowInit_async_0 = new LogIdSet(selector_async_rowInit_async_0);
              SimpleService::selectorId_upcall_messageError_45_transition = new LogIdSet(selector_upcall_messageError_45_transition);
              SimpleService::selectorId_send_downcall_56 = new LogIdSet(selector_send_downcall_56);
              SimpleService::selectorId_messageError_demux_35 = new LogIdSet(selector_messageError_demux_35);
              SimpleService::selectorId_getStartContext_sync_10 = new LogIdSet(selector_getStartContext_sync_10);
              SimpleService::selectorId_route_downcall_32 = new LogIdSet(selector_route_downcall_32);
              SimpleService::selectorId_scheduler_expire_resender_timer_10_transition = new LogIdSet(selector_scheduler_expire_resender_timer_10_transition);
              SimpleService::selectorId_upcall_deliver_19_transition = new LogIdSet(selector_upcall_deliver_19_transition);
              SimpleService::selectorId_send_downcall_50 = new LogIdSet(selector_send_downcall_50);
              SimpleService::selectorId_messageError_demux_49 = new LogIdSet(selector_messageError_demux_49);
              SimpleService::selectorId_route_downcall_14 = new LogIdSet(selector_route_downcall_14);
              SimpleService::selectorId_deliver_demux_18 = new LogIdSet(selector_deliver_demux_18);
              SimpleService::selectorId_deliver_demux_48 = new LogIdSet(selector_deliver_demux_48);
              SimpleService::selectorId_send_downcall_55 = new LogIdSet(selector_send_downcall_55);
              SimpleService::selectorId_route_downcall_9 = new LogIdSet(selector_route_downcall_9);
              SimpleService::selectorId_route_downcall_22 = new LogIdSet(selector_route_downcall_22);
              SimpleService::selectorId_upcall_deliver_16_transition = new LogIdSet(selector_upcall_deliver_16_transition);
              SimpleService::selectorId_deliver_demux_16 = new LogIdSet(selector_deliver_demux_16);
              SimpleService::selectorId_upcall_messageError_43_transition = new LogIdSet(selector_upcall_messageError_43_transition);
              SimpleService::selectorId_upcall_deliver_20_transition = new LogIdSet(selector_upcall_deliver_20_transition);
              SimpleService::selectorId_deliver_demux_4 = new LogIdSet(selector_deliver_demux_4);
              SimpleService::selectorId_send_downcall_46 = new LogIdSet(selector_send_downcall_46);
              SimpleService::selectorId_deliver_demux_7 = new LogIdSet(selector_deliver_demux_7);
              SimpleService::selectorId_upcall_deliver_22_transition = new LogIdSet(selector_upcall_deliver_22_transition);
              SimpleService::selectorId_scheduler_expire_t_6_transition = new LogIdSet(selector_scheduler_expire_t_6_transition);
              SimpleService::selectorId_target_sync_cellInit_sync_6 = new LogIdSet(selector_target_sync_cellInit_sync_6);
              SimpleService::selectorId_route_downcall_16 = new LogIdSet(selector_route_downcall_16);
              SimpleService::selectorId_route_downcall_64 = new LogIdSet(selector_route_downcall_64);
              SimpleService::selectorId_upcall_deliver_13_transition = new LogIdSet(selector_upcall_deliver_13_transition);
              SimpleService::selectorId_downcall_maceInit_0_transition = new LogIdSet(selector_downcall_maceInit_0_transition);
              SimpleService::selectorId_messageError_demux_31 = new LogIdSet(selector_messageError_demux_31);
              SimpleService::selectorId_hashState_demux_44 = new LogIdSet(selector_hashState_demux_44);
              SimpleService::selectorId_deliver_demux_13 = new LogIdSet(selector_deliver_demux_13);
              SimpleService::selectorId_sctest_demux_53 = new LogIdSet(selector_sctest_demux_53);
              SimpleService::selectorId_schedulectsTimer = new LogIdSet(selector_schedulectsTimer);
              SimpleService::selectorId_messageError_demux_33 = new LogIdSet(selector_messageError_demux_33);
              SimpleService::selectorId_expire_ctsTimer_demux_45 = new LogIdSet(selector_expire_ctsTimer_demux_45);
              SimpleService::selectorId_deliver_demux_1 = new LogIdSet(selector_deliver_demux_1);
              SimpleService::selectorId_route_downcall_28 = new LogIdSet(selector_route_downcall_28);
              SimpleService::selectorId_upcall_messageError_30_transition = new LogIdSet(selector_upcall_messageError_30_transition);
              SimpleService::selectorId_send_downcall_63 = new LogIdSet(selector_send_downcall_63);
              SimpleService::selectorId_async_testMulti_8_transition = new LogIdSet(selector_async_testMulti_8_transition);
              SimpleService::selectorId_async_rowAfter_async_1 = new LogIdSet(selector_async_rowAfter_async_1);
              SimpleService::selectorId_messageError_demux_24 = new LogIdSet(selector_messageError_demux_24);
              SimpleService::selectorId_route_downcall_11 = new LogIdSet(selector_route_downcall_11);
              SimpleService::selectorId_upcall_deliver_27_transition = new LogIdSet(selector_upcall_deliver_27_transition);
              SimpleService::selectorId_send_downcall_52 = new LogIdSet(selector_send_downcall_52);
              SimpleService::selectorId_route_downcall_36 = new LogIdSet(selector_route_downcall_36);
              SimpleService::selectorId_route_downcall_7 = new LogIdSet(selector_route_downcall_7);
              SimpleService::selectorId_route_downcall_33 = new LogIdSet(selector_route_downcall_33);
              SimpleService::selectorId_upcall_deliver_18_transition = new LogIdSet(selector_upcall_deliver_18_transition);
              SimpleService::selectorId_target_async_testMulti_sync_2 = new LogIdSet(selector_target_async_testMulti_sync_2);
              SimpleService::selectorId_send_downcall_45 = new LogIdSet(selector_send_downcall_45);
              SimpleService::selectorId_route_downcall_24 = new LogIdSet(selector_route_downcall_24);
              SimpleService::selectorId_async_rowAfter_4_transition = new LogIdSet(selector_async_rowAfter_4_transition);
              SimpleService::selectorId_send_downcall_47 = new LogIdSet(selector_send_downcall_47);
              SimpleService::selectorId_sync_sctest_sync_3 = new LogIdSet(selector_sync_sctest_sync_3);
              SimpleService::selectorId_upcall_messageError_31_transition = new LogIdSet(selector_upcall_messageError_31_transition);
              SimpleService::selectorId_messageError_demux_20 = new LogIdSet(selector_messageError_demux_20);
              SimpleService::selectorId_route_downcall_43 = new LogIdSet(selector_route_downcall_43);
              SimpleService::selectorId_route_downcall_18 = new LogIdSet(selector_route_downcall_18);
              SimpleService::selectorId_schedulet = new LogIdSet(selector_schedulet);
              SimpleService::selectorId_messageError_demux_26 = new LogIdSet(selector_messageError_demux_26);
              SimpleService::selectorId_route_downcall_19 = new LogIdSet(selector_route_downcall_19);
              SimpleService::selectorId_scheduler_expire_ctsTimer_7_transition = new LogIdSet(selector_scheduler_expire_ctsTimer_7_transition);
              SimpleService::selectorId_send_downcall_59 = new LogIdSet(selector_send_downcall_59);
              SimpleService::selectorId_deliver_demux_10 = new LogIdSet(selector_deliver_demux_10);
              SimpleService::selectorId_messageError_demux_38 = new LogIdSet(selector_messageError_demux_38);
              SimpleService::selectorId_upcall_messageError_38_transition = new LogIdSet(selector_upcall_messageError_38_transition);
              SimpleService::selectorId_expirectsTimer = new LogIdSet(selector_expirectsTimer);
              SimpleService::selectorId_route_downcall_4 = new LogIdSet(selector_route_downcall_4);
              SimpleService::selectorId_sync_cellInit_3_transition = new LogIdSet(selector_sync_cellInit_3_transition);
              SimpleService::selectorId_maceResume_demux_40 = new LogIdSet(selector_maceResume_demux_40);
              SimpleService::selectorId_target_sync_testRCX_sync_8 = new LogIdSet(selector_target_sync_testRCX_sync_8);
              SimpleService::selectorId_resumeDeliver_downcall_3 = new LogIdSet(selector_resumeDeliver_downcall_3);
              SimpleService::selectorId_route_downcall_39 = new LogIdSet(selector_route_downcall_39);
              SimpleService::selectorId_route_downcall_8 = new LogIdSet(selector_route_downcall_8);
              SimpleService::selectorId_route_downcall_15 = new LogIdSet(selector_route_downcall_15);
              SimpleService::selectorId_async_rowInit_2_transition = new LogIdSet(selector_async_rowInit_2_transition);
              SimpleService::selectorId_send_downcall_57 = new LogIdSet(selector_send_downcall_57);
              SimpleService::selectorId_route_downcall_23 = new LogIdSet(selector_route_downcall_23);
              SimpleService::selectorId_cancelresender_timer = new LogIdSet(selector_cancelresender_timer);
              SimpleService::selectorId_testRCX_demux_55 = new LogIdSet(selector_testRCX_demux_55);
              SimpleService::selectorId_messageError_demux_21 = new LogIdSet(selector_messageError_demux_21);
              SimpleService::selectorId_error_demux_0 = new LogIdSet(selector_error_demux_0);
              SimpleService::selectorId_route_downcall_26 = new LogIdSet(selector_route_downcall_26);
              SimpleService::selectorId_deliver_demux_14 = new LogIdSet(selector_deliver_demux_14);
              SimpleService::selectorId_upcall_deliver_12_transition = new LogIdSet(selector_upcall_deliver_12_transition);
              SimpleService::selectorId_upcall_deliver_11_transition = new LogIdSet(selector_upcall_deliver_11_transition);
              SimpleService::selectorId_sync_testRCX_5_transition = new LogIdSet(selector_sync_testRCX_5_transition);
              SimpleService::selectorId_messageError_demux_36 = new LogIdSet(selector_messageError_demux_36);
              SimpleService::selectorId_route_downcall_38 = new LogIdSet(selector_route_downcall_38);
              SimpleService::selectorId_messageError_demux_28 = new LogIdSet(selector_messageError_demux_28);
              SimpleService::selectorId_rowInit_demux_50 = new LogIdSet(selector_rowInit_demux_50);
              SimpleService::selectorId_send_downcall_60 = new LogIdSet(selector_send_downcall_60);
              SimpleService::selectorId_upcall_messageError_42_transition = new LogIdSet(selector_upcall_messageError_42_transition);
              SimpleService::selectorId_route_downcall_12 = new LogIdSet(selector_route_downcall_12);
              SimpleService::selectorId_target_sync_sctest_sync_4 = new LogIdSet(selector_target_sync_sctest_sync_4);
              SimpleService::selectorId_route_downcall_40 = new LogIdSet(selector_route_downcall_40);
              SimpleService::selectorId_deliver_demux_8 = new LogIdSet(selector_deliver_demux_8);
              SimpleService::selectorId_route_downcall_21 = new LogIdSet(selector_route_downcall_21);
              SimpleService::selectorId_upcall_messageError_32_transition = new LogIdSet(selector_upcall_messageError_32_transition);
              SimpleService::selectorId_route_downcall_31 = new LogIdSet(selector_route_downcall_31);
              SimpleService::selectorId_route_downcall_13 = new LogIdSet(selector_route_downcall_13);
              SimpleService::selectorId_messageError_demux_27 = new LogIdSet(selector_messageError_demux_27);
              SimpleService::selectorId_upcall_messageError_29_transition = new LogIdSet(selector_upcall_messageError_29_transition);
              SimpleService::selectorId_upcall_messageError_34_transition = new LogIdSet(selector_upcall_messageError_34_transition);
              SimpleService::selectorId_expire_t_demux_46 = new LogIdSet(selector_expire_t_demux_46);
              SimpleService::selectorId_send_downcall_51 = new LogIdSet(selector_send_downcall_51);
              SimpleService::selectorId_scheduleresender_timer = new LogIdSet(selector_scheduleresender_timer);
              SimpleService::selectorId_findContextByID_sync_9 = new LogIdSet(selector_findContextByID_sync_9);
              SimpleService::selectorId_deliver_demux_3 = new LogIdSet(selector_deliver_demux_3);
              SimpleService::selectorId_upcall_messageError_46_transition = new LogIdSet(selector_upcall_messageError_46_transition);
              SimpleService::selectorId_upcall_messageError_37_transition = new LogIdSet(selector_upcall_messageError_37_transition);
              SimpleService::selectorId_upcall_deliver_15_transition = new LogIdSet(selector_upcall_deliver_15_transition);
              SimpleService::selectorId_sync_testRCX_sync_7 = new LogIdSet(selector_sync_testRCX_sync_7);
              SimpleService::selectorId_upcall_messageError_36_transition = new LogIdSet(selector_upcall_messageError_36_transition);
              SimpleService::selectorId_upcall_deliver_24_transition = new LogIdSet(selector_upcall_deliver_24_transition);
              SimpleService::selectorId_testMulti_demux_52 = new LogIdSet(selector_testMulti_demux_52);
              SimpleService::selectorId_sync_cellInit_sync_5 = new LogIdSet(selector_sync_cellInit_sync_5);
              SimpleService::selectorId_messageError_demux_23 = new LogIdSet(selector_messageError_demux_23);
              SimpleService::selectorId_cancelt = new LogIdSet(selector_cancelt);
              SimpleService::selectorId_deliver_demux_17 = new LogIdSet(selector_deliver_demux_17);
              SimpleService::selectorId_suspendDeliver_downcall_0 = new LogIdSet(selector_suspendDeliver_downcall_0);
              SimpleService::selectorId_route_downcall_29 = new LogIdSet(selector_route_downcall_29);
              
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_maceInit67", "maceInit()"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_maceReset70", "maceReset()"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_hashState72", "hashState() const"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver74", "deliver( const MaceKey& source,  const MaceKey& destination,  const __internal_Ack& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver75", "deliver( const MaceKey& source,  const MaceKey& destination,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver76", "deliver( const MaceKey& source,  const MaceKey& destination,  const TransferContext& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver77", "deliver( const MaceKey& source,  const MaceKey& destination,  const ReportContextMigration& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver78", "deliver( const MaceKey& source,  const MaceKey& destination,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver79", "deliver( const MaceKey& source,  const MaceKey& destination,  const HeadEvent& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver80", "deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver81", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver82", "deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver83", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver84", "deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver85", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver86", "deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver87", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver88", "deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver89", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver90", "deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver91", "deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_deliver92", "deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError93", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __internal_Ack& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError94", "messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMigrationRequest& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError95", "messageError( const MaceKey& dest, TransportError::type errorCode,  const TransferContext& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError96", "messageError( const MaceKey& dest, TransportError::type errorCode,  const ReportContextMigration& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError97", "messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMappingUpdate& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError98", "messageError( const MaceKey& dest, TransportError::type errorCode,  const HeadEvent& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError99", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at2_rowInit& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError100", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at2_rowInit& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError101", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at4_rowAfter& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError102", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at4_rowAfter& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError103", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at8_testMulti& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError104", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at8_testMulti& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError105", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at1_sctest& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError106", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at1_sctest& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError107", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at3_cellInit& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError108", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at3_cellInit& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError109", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at5_testRCX& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError110", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at5_testRCX& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_messageError111", "messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at_snapshot& message_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_expire_ctsTimer112", "expire_ctsTimer(MaceKey& p0)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_expire_t113", "expire_t(int& p0, int& p1, int& p2)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_expire_resender_timer114", "expire_resender_timer()"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_suspendDeliver0", "suspendDeliver(registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_suspendDeliver1", "suspendDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_resumeDeliver2", "resumeDeliver(registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_resumeDeliver3", "resumeDeliver( const MaceKey& dest, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route4", "route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route5", "route( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route6", "route( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route7", "route( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route8", "route( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route9", "route( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route10", "route( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route11", "route( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route12", "route( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route13", "route( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route14", "route( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route15", "route( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route16", "route( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route17", "route( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route18", "route( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route19", "route( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route20", "route( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route21", "route( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route22", "route( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route23", "route( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route24", "route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route25", "route( const MaceKey& src,  const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route26", "route( const MaceKey& src,  const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route27", "route( const MaceKey& src,  const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route28", "route( const MaceKey& src,  const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route29", "route( const MaceKey& src,  const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route30", "route( const MaceKey& src,  const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route31", "route( const MaceKey& src,  const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route32", "route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route33", "route( const MaceKey& src,  const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route34", "route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route35", "route( const MaceKey& src,  const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route36", "route( const MaceKey& src,  const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route37", "route( const MaceKey& src,  const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route38", "route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route39", "route( const MaceKey& src,  const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route40", "route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route41", "route( const MaceKey& src,  const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route42", "route( const MaceKey& src,  const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_route43", "route( const MaceKey& src,  const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send44", "send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send45", "send( const MaceKey& dest,  const __internal_Ack& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send46", "send( const MaceKey& dest,  const ContextMigrationRequest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send47", "send( const MaceKey& dest,  const TransferContext& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send48", "send( const MaceKey& dest,  const ReportContextMigration& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send49", "send( const MaceKey& dest,  const ContextMappingUpdate& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send50", "send( const MaceKey& dest,  const HeadEvent& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send51", "send( const MaceKey& dest,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send52", "send( const MaceKey& dest,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send53", "send( const MaceKey& dest,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send54", "send( const MaceKey& dest,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send55", "send( const MaceKey& dest,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send56", "send( const MaceKey& dest,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send57", "send( const MaceKey& dest,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send58", "send( const MaceKey& dest,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send59", "send( const MaceKey& dest,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send60", "send( const MaceKey& dest,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send61", "send( const MaceKey& dest,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send62", "send( const MaceKey& dest,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)"), 0);
              Log::binaryLog(mid, MethodMap_namespace::MethodMap("Simple_send63", "send( const MaceKey& dest,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)"), 0);
              
            }
          }
          //END Mace::Compiler::ServiceImpl::printRoutines
          
          //Timer Demux (and utility timer)
          //BEGIN Mace::Compiler::ServiceImpl::printTimerDemux
          void SimpleService::expire_ctsTimer(MaceKey& p0) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_expire_ctsTimer_demux_45
            #define selectorId selectorId_expire_ctsTimer_demux_45
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_expire_ctsTimer112(p0);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, expire_ctsTimer112Dummy(p0), 0);
              }
            }
            
            
            if(state == exited) {
              { }
            } else
            if(guard_scheduler_7_expire_ctsTimer(p0)) {
              macecompiler(1) << "Firing Transition scheduler ctsTimer [ guards : (true) ] void expire_ctsTimer(MaceKey& dest)" << Log::endl;
              
              
              
              scheduler_7_expire_ctsTimer(p0);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              { }
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::expire_t(int& p0, int& p1, int& p2) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_expire_t_demux_46
            #define selectorId selectorId_expire_t_demux_46
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_expire_t113(p0, p1, p2);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, expire_t113Dummy(p0, p1, p2), 0);
              }
            }
            
            
            if(state == exited) {
              { }
            } else
            if(guard_scheduler_6_expire_t(p0,p1,p2)) {
              macecompiler(1) << "Firing Transition scheduler t [ guards : (true) ] void expire_t(int& row, int& column, int& x)" << Log::endl;
              
              
              
              scheduler_6_expire_t(p0,p1,p2);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              { }
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::expire_resender_timer() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_expire_resender_timer_demux_47
            #define selectorId selectorId_expire_resender_timer_demux_47
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_expire_resender_timer114();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, expire_resender_timer114Dummy(), 0);
              }
            }
            
            
            if(state == exited) {
              { }
            } else
            if(guard_scheduler_10_expire_resender_timer()) {
              macecompiler(1) << "Firing Transition scheduler resender_timer [ guards : (true) ] void expire_resender_timer()" << Log::endl;
              
              
              resender_timer.reschedule(500*1000);
              
              scheduler_10_expire_resender_timer();
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              resender_timer.reschedule(500*1000);
              { }
            }
            
            #undef selector
            #undef selectorId
            
          }
          //END Mace::Compiler::ServiceImpl::printTimerDemux
          
          //Load Protocol
          
          //BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol
          NullServiceClass& configure_new_Simple_Null(bool ___shared);
          
          void load_protocol() {
            StringSet attr = mace::makeStringSet("Simple", ",");
            mace::ServiceFactory<NullServiceClass>::registerService(&configure_new_Simple_Null, "Simple");
            mace::ServiceConfig<NullServiceClass>::registerService("Simple", attr);
          }
          //END Mace::Compiler::ServiceImpl::printLoadProtocol
          
          //Constructors
          //BEGIN Mace::Compiler::ServiceImpl::printConstructor
          NullServiceClass& real_new_Simple_Null(TransportServiceClass& tcp,
              #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int32_t const  ROWS
#line 5333 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int32_t const  COLUMNS
#line 5337 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int32_t const  MATRIXROWS
#line 5341 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int32_t const  MATRIXCOLUMNS
#line 5345 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , bool ___shared) {
            return *(new SimpleService(tcp,ROWS,COLUMNS,MATRIXROWS,MATRIXCOLUMNS,___shared));
          }
          SimpleService::SimpleService(TransportServiceClass& __tcp, int32_t const  _ROWS, int32_t const  _COLUMNS, int32_t const  _MATRIXROWS, int32_t const  _MATRIXCOLUMNS, bool ___shared) :
          //(
              BaseMaceService(), __inited(0), _actual_state(init), state(_actual_state),
              ROWS(_ROWS),
              COLUMNS(_COLUMNS),
              MATRIXROWS(_MATRIXROWS),
              MATRIXCOLUMNS(_MATRIXCOLUMNS),
              _tcp(__tcp), tcp(-1),
              initial_matrix(),
              rows(),
              columns(),
              matrix_rows(),
              matrix_columns(),
              current_iteration(),
              init_rows(),
              finished_row(),
              returnedValues(),
              result(),
              runs(),
              __internal_msgseqno(),
              __internal_lastAckedSeqno(),
              __internal_receivedSeqno(),
              __internal_unAck(),
              __internal_contextPrevEvent(),
              ctsTimer(*(new ctsTimer_MaceTimer(this))),
              t(*(new t_MaceTimer(this))),
              resender_timer(*(new resender_timer_MaceTimer(this))), __local_address(MaceKey::null)
              {
                initializeSelectors();
                __local_address = computeLocalAddress();
                
                if (___shared) {
                  mace::ServiceFactory<NullServiceClass>::registerInstance("Simple", this);
                }
                ServiceClass::addToServiceList(*this);
                
                
                ADD_SELECTORS("Simple::(constructor)");
                macedbg(1) << "Created queued instance " << this << Log::endl;
              }
              //)
          SimpleService::SimpleService(const SimpleService& _sv) :
          //(
              BaseMaceService(false), __inited(_sv.__inited), _actual_state(_sv.state), state(_actual_state),
              ROWS(_sv.ROWS),
              COLUMNS(_sv.COLUMNS),
              MATRIXROWS(_sv.MATRIXROWS),
              MATRIXCOLUMNS(_sv.MATRIXCOLUMNS),
              _tcp(_sv._tcp), tcp(_sv.tcp),
              initial_matrix(_sv.initial_matrix),
              rows(_sv.rows),
              columns(_sv.columns),
              matrix_rows(_sv.matrix_rows),
              matrix_columns(_sv.matrix_columns),
              current_iteration(_sv.current_iteration),
              init_rows(_sv.init_rows),
              finished_row(_sv.finished_row),
              returnedValues(_sv.returnedValues),
              result(_sv.result),
              runs(_sv.runs),
              __internal_msgseqno(_sv.__internal_msgseqno),
              __internal_lastAckedSeqno(_sv.__internal_lastAckedSeqno),
              __internal_receivedSeqno(_sv.__internal_receivedSeqno),
              __internal_unAck(_sv.__internal_unAck),
              __internal_contextPrevEvent(_sv.__internal_contextPrevEvent),
              ctsTimer(*(new ctsTimer_MaceTimer(this))),
              t(*(new t_MaceTimer(this))),
              resender_timer(*(new resender_timer_MaceTimer(this))){
                ADD_SELECTORS("Simple::(constructor)");
                macedbg(1) << "Created non-queued instance " << this << Log::endl;
              }
              //)
          //END Mace::Compiler::ServiceImpl::printConstructor
          
          //Destructor
          SimpleService::~SimpleService() {
            delete &ctsTimer;
            delete &t;
            delete &resender_timer;
            mace::ServiceFactory<NullServiceClass>::unregisterInstance("Simple", this);
          }
          
          // Methods for snapshotting...
          void SimpleService::snapshot(const uint64_t& ver) const {
            ADD_SELECTORS("SimpleService::snapshot");
            //Assumes state is locked.
            SimpleService* _sv = new SimpleService(*this);
            macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
            ASSERT(versionMap.empty() || versionMap.back().first < ver);
            versionMap.push_back(std::make_pair(ver,_sv));
          }
          void SimpleService::snapshotRelease(const uint64_t& ver) const {
            ADD_SELECTORS("SimpleService::snapshot");
            //Assumes state is locked.
            while (!versionMap.empty() && versionMap.front().first < ver) {
              macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
              delete versionMap.front().second;
              versionMap.pop_front();
            }
          }
          
          
          const ServiceType::state_type& SimpleService::read_state() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return state;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->state;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          Matrix const & SimpleService::read_initial_matrix() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return initial_matrix;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->initial_matrix;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_rows() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return rows;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->rows;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_columns() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return columns;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->columns;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_matrix_rows() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return matrix_rows;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->matrix_rows;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_matrix_columns() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return matrix_columns;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->matrix_columns;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_current_iteration() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return current_iteration;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->current_iteration;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_init_rows() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return init_rows;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->init_rows;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_finished_row() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return finished_row;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->finished_row;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_returnedValues() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return returnedValues;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->returnedValues;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          Matrix const & SimpleService::read_result() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return result;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->result;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          int const & SimpleService::read_runs() const {
            int currentMode = mace::ContextBaseClass::globalContext.getCurrentMode();
            if (USING_RWLOCK || currentMode == mace::ContextLock::WRITE_MODE) {
              return runs;
            }
            else if (currentMode == mace::ContextLock::READ_MODE) {
              VersionServiceMap::const_iterator i = versionMap.begin();
              uint64_t sver = mace::ContextBaseClass::globalContext.getSnapshotVersion();
              while (i != versionMap.end()) {
                if (i->first == sver) {
                  break;
                }
                i++;
              }
              if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::ContextBaseClass::globalContext.getCurrentMode() << " ticket " << ThreadStructure::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
              }
              return i->second->runs;
            }
            else {
              ABORT("Invalid attempt to access state from NONE_MODE!");
            }
          }
          
          
          
          
          
          
          
          //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
          void SimpleService::dumpState(LOGLOGTYPE& logger) const {
            logger << "state_dump: " << *this << std::endl;
            return;
          }
          
          void SimpleService::print(mace::PrintNode& __pr, const std::string& name) const {
            mace::PrintNode __printer(name, "SimpleService");
            const char* __pr_stateName = getStateName(state);
            mace::printItem(__printer, "state", &__pr_stateName);
            mace::printItem(__printer, "initial_matrix", &(initial_matrix));
            mace::printItem(__printer, "rows", &(rows));
            mace::printItem(__printer, "columns", &(columns));
            mace::printItem(__printer, "matrix_rows", &(matrix_rows));
            mace::printItem(__printer, "matrix_columns", &(matrix_columns));
            mace::printItem(__printer, "current_iteration", &(current_iteration));
            mace::printItem(__printer, "init_rows", &(init_rows));
            mace::printItem(__printer, "finished_row", &(finished_row));
            mace::printItem(__printer, "returnedValues", &(returnedValues));
            mace::printItem(__printer, "result", &(result));
            mace::printItem(__printer, "runs", &(runs));
            mace::printItem(__printer, "__internal_msgseqno", &(__internal_msgseqno));
            mace::printItem(__printer, "__internal_lastAckedSeqno", &(__internal_lastAckedSeqno));
            mace::printItem(__printer, "__internal_receivedSeqno", &(__internal_receivedSeqno));
            mace::printItem(__printer, "__internal_unAck", &(__internal_unAck));
            mace::printItem(__printer, "__internal_contextPrevEvent", &(__internal_contextPrevEvent));
            mace::printItem(__printer, "ctsTimer", &ctsTimer);
            mace::printItem(__printer, "t", &t);
            mace::printItem(__printer, "resender_timer", &resender_timer);
            __pr.addChild(__printer);
            return;
          }
          
          void SimpleService::print(std::ostream& __out) const {
            __out << "state=" << getStateName(state) << std::endl;
            __out << "initial_matrix=";  mace::printItem(__out, &(initial_matrix));  __out << std::endl;
            __out << "rows=";  mace::printItem(__out, &(rows));  __out << std::endl;
            __out << "columns=";  mace::printItem(__out, &(columns));  __out << std::endl;
            __out << "matrix_rows=";  mace::printItem(__out, &(matrix_rows));  __out << std::endl;
            __out << "matrix_columns=";  mace::printItem(__out, &(matrix_columns));  __out << std::endl;
            __out << "current_iteration=";  mace::printItem(__out, &(current_iteration));  __out << std::endl;
            __out << "init_rows=";  mace::printItem(__out, &(init_rows));  __out << std::endl;
            __out << "finished_row=";  mace::printItem(__out, &(finished_row));  __out << std::endl;
            __out << "returnedValues=";  mace::printItem(__out, &(returnedValues));  __out << std::endl;
            __out << "result=";  mace::printItem(__out, &(result));  __out << std::endl;
            __out << "runs=";  mace::printItem(__out, &(runs));  __out << std::endl;
            __out << "__internal_msgseqno=";  mace::printItem(__out, &(__internal_msgseqno));  __out << std::endl;
            __out << "__internal_lastAckedSeqno=";  mace::printItem(__out, &(__internal_lastAckedSeqno));  __out << std::endl;
            __out << "__internal_receivedSeqno=";  mace::printItem(__out, &(__internal_receivedSeqno));  __out << std::endl;
            __out << "__internal_unAck=";  mace::printItem(__out, &(__internal_unAck));  __out << std::endl;
            __out << "__internal_contextPrevEvent=";  mace::printItem(__out, &(__internal_contextPrevEvent));  __out << std::endl;
            __out << ctsTimer; __out << std::endl;
            __out << t; __out << std::endl;
            __out << resender_timer; __out << std::endl;
            __out << std::endl;
            if(_printLower) {
              __out  << _tcp << std::endl;
            }
            return;
          }
          void SimpleService::printState(std::ostream& __out) const {
            __out << "state=" << getStateName(state) << std::endl;
            __out << "initial_matrix=";  mace::printState(__out, &(initial_matrix), (initial_matrix));
            __out << "rows=";  mace::printState(__out, &(rows), (rows));
            __out << "columns=";  mace::printState(__out, &(columns), (columns));
            __out << "matrix_rows=";  mace::printState(__out, &(matrix_rows), (matrix_rows));
            __out << "matrix_columns=";  mace::printState(__out, &(matrix_columns), (matrix_columns));
            __out << "current_iteration=";  mace::printState(__out, &(current_iteration), (current_iteration));
            __out << "init_rows=";  mace::printState(__out, &(init_rows), (init_rows));
            __out << "finished_row=";  mace::printState(__out, &(finished_row), (finished_row));
            __out << "returnedValues=";  mace::printState(__out, &(returnedValues), (returnedValues));
            __out << "result=";  mace::printState(__out, &(result), (result));
            __out << "runs=";  mace::printState(__out, &(runs), (runs));
            __out << "__internal_msgseqno=";  mace::printState(__out, &(__internal_msgseqno), (__internal_msgseqno));
            __out << "__internal_lastAckedSeqno=";  mace::printState(__out, &(__internal_lastAckedSeqno), (__internal_lastAckedSeqno));
            __out << "__internal_receivedSeqno=";  mace::printState(__out, &(__internal_receivedSeqno), (__internal_receivedSeqno));
            __out << "__internal_unAck=";  mace::printState(__out, &(__internal_unAck), (__internal_unAck));
            __out << "__internal_contextPrevEvent=";  mace::printState(__out, &(__internal_contextPrevEvent), (__internal_contextPrevEvent));
            ctsTimer.printState(__out);
            t.printState(__out);
            resender_timer.printState(__out);
            __out << std::endl;
            if(_printLower) {
              _tcp.printState(__out);
            }
            return;
          }
          
          void SimpleService::sqlize(mace::LogNode* __node) const {
            int _index = __node->nextIndex();
            if (_index == 0) {
              std::ostringstream __out;
              __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, state TEXT, initial_matrix INT, rows INT, columns INT, matrix_rows INT, matrix_columns INT, current_iteration INT, init_rows INT, finished_row INT, returnedValues INT, result INT, runs INT, __internal_msgseqno INT, __internal_lastAckedSeqno INT, __internal_receivedSeqno INT, __internal_unAck INT, __internal_contextPrevEvent INT);" << std::endl;
              __node->children = new mace::LogNode*[7];
              mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_initial_matrix", Log::sqlEventsLog);
              __node->children[0] = __child0;
              mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_result", Log::sqlEventsLog);
              __node->children[1] = __child1;
              mace::LogNode* __child2 = new mace::LogNode(__node->logName + "___internal_msgseqno", Log::sqlEventsLog);
              __node->children[2] = __child2;
              mace::LogNode* __child3 = new mace::LogNode(__node->logName + "___internal_lastAckedSeqno", Log::sqlEventsLog);
              __node->children[3] = __child3;
              mace::LogNode* __child4 = new mace::LogNode(__node->logName + "___internal_receivedSeqno", Log::sqlEventsLog);
              __node->children[4] = __child4;
              mace::LogNode* __child5 = new mace::LogNode(__node->logName + "___internal_unAck", Log::sqlEventsLog);
              __node->children[5] = __child5;
              mace::LogNode* __child6 = new mace::LogNode(__node->logName + "___internal_contextPrevEvent", Log::sqlEventsLog);
              __node->children[6] = __child6;
              Log::logSqlCreate(__out.str(), __node);
            }
            int _initial_matrixIndex = __node->children[0]->nextId;
            int _resultIndex = __node->children[1]->nextId;
            int ___internal_msgseqnoIndex = __node->children[2]->nextId;
            int ___internal_lastAckedSeqnoIndex = __node->children[3]->nextId;
            int ___internal_receivedSeqnoIndex = __node->children[4]->nextId;
            int ___internal_unAckIndex = __node->children[5]->nextId;
            int ___internal_contextPrevEventIndex = __node->children[6]->nextId;
            std::ostringstream __out;
            __out << __node->logId << "\t" << _index << "\t" << getStateName(state);
            __out << "\t" << _initial_matrixIndex;
            __out << "\t" << rows;
            __out << "\t" << columns;
            __out << "\t" << matrix_rows;
            __out << "\t" << matrix_columns;
            __out << "\t" << current_iteration;
            __out << "\t" << init_rows;
            __out << "\t" << finished_row;
            __out << "\t" << returnedValues;
            __out << "\t" << _resultIndex;
            __out << "\t" << runs;
            __out << "\t" << ___internal_msgseqnoIndex;
            __out << "\t" << ___internal_lastAckedSeqnoIndex;
            __out << "\t" << ___internal_receivedSeqnoIndex;
            __out << "\t" << ___internal_unAckIndex;
            __out << "\t" << ___internal_contextPrevEventIndex;
            __out << std::endl;
            ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
            mace::sqlize(&initial_matrix, __node->children[0]);
            mace::sqlize(&result, __node->children[1]);
            mace::sqlize(&__internal_msgseqno, __node->children[2]);
            mace::sqlize(&__internal_lastAckedSeqno, __node->children[3]);
            mace::sqlize(&__internal_receivedSeqno, __node->children[4]);
            mace::sqlize(&__internal_unAck, __node->children[5]);
            mace::sqlize(&__internal_contextPrevEvent, __node->children[6]);
            
          }
          
          void SimpleService::serialize(std::string& __str) const {
            mace::serialize(__str, &state);
            
            #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &initial_matrix);
#line 5932 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &rows);
#line 5937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &columns);
#line 5942 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &matrix_rows);
#line 5947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &matrix_columns);
#line 5952 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &current_iteration);
#line 5957 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &init_rows);
#line 5962 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &finished_row);
#line 5967 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &returnedValues);
#line 5972 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &result);
#line 5977 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            mace::serialize(__str, &runs);
#line 5982 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 203 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            mace::serialize(__str, &__internal_msgseqno);
#line 5987 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            mace::serialize(__str, &__internal_lastAckedSeqno);
#line 5992 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 236 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            mace::serialize(__str, &__internal_receivedSeqno);
#line 5997 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 251 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            mace::serialize(__str, &__internal_unAck);
#line 6002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 266 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            mace::serialize(__str, &__internal_contextPrevEvent);
#line 6007 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            R.serialize(__str);
            T.serialize(__str);
            M.serialize(__str);
            ctsTimer.serialize(__str);
            t.serialize(__str);
            resender_timer.serialize(__str);
            mace::serialize( __str, &__local_address );
            return;
          }
          
          int SimpleService::deserialize(std::istream& __in) throw(SerializationException){
            int serializedByteSize = 0;
            serializedByteSize += mace::deserialize(__in, &_actual_state);
            
            #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &initial_matrix);
#line 6025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &rows);
#line 6030 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &columns);
#line 6035 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &matrix_rows);
#line 6040 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &matrix_columns);
#line 6045 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &current_iteration);
#line 6050 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &init_rows);
#line 6055 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &finished_row);
#line 6060 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &returnedValues);
#line 6065 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &result);
#line 6070 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
            serializedByteSize +=  mace::deserialize(__in, &runs);
#line 6075 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 203 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            serializedByteSize +=  mace::deserialize(__in, &__internal_msgseqno);
#line 6080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 219 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            serializedByteSize +=  mace::deserialize(__in, &__internal_lastAckedSeqno);
#line 6085 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 236 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            serializedByteSize +=  mace::deserialize(__in, &__internal_receivedSeqno);
#line 6090 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 251 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            serializedByteSize +=  mace::deserialize(__in, &__internal_unAck);
#line 6095 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            
            #line 266 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler/MaceCompiler.pm"
            serializedByteSize +=  mace::deserialize(__in, &__internal_contextPrevEvent);
#line 6100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
            
            serializedByteSize +=  R.deserialize(__in);
            serializedByteSize +=  T.deserialize(__in);
            serializedByteSize +=  M.deserialize(__in);
            serializedByteSize +=  ctsTimer.deserialize(__in);
            serializedByteSize +=  t.deserialize(__in);
            serializedByteSize +=  resender_timer.deserialize(__in);
            
            MaceKey oldLocalAddress;
            serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
            updateInternalContext( oldLocalAddress, __local_address );
            
            return serializedByteSize;
          }
          void SimpleService::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
            
            
            // assuming this method is called to resume from a previous process, XXX: is there any other use for serializing service class?
            // update internal message buffer using the old
            /*ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex);
            if( __internal_unAck.find( oldNode ) != __internal_unAck.end() ){
              __internal_unAck[ newNode ] = __internal_unAck[ oldNode ];
              __internal_unAck.erase( oldNode );
            }
            if( __internal_receivedSeqno.find( oldNode ) != __internal_receivedSeqno.end() ){
              __internal_receivedSeqno[ newNode ] = __internal_receivedSeqno[ oldNode ];
              __internal_receivedSeqno.erase( oldNode );
            }
            if( __internal_lastAckedSeqno.find( oldNode ) != __internal_lastAckedSeqno.end() ){
              __internal_lastAckedSeqno[ newNode ] = __internal_lastAckedSeqno[ oldNode ];
              __internal_lastAckedSeqno.erase( oldNode );
            }
            if( __internal_msgseqno.find( oldNode ) != __internal_msgseqno.end() ){
              __internal_msgseqno[ newNode ] = __internal_msgseqno[ oldNode ];
              __internal_msgseqno.erase( oldNode );
            }*/
            
          }
          
          void SimpleService::processDeferred() {
            
            static const log_id_t logid = Log::getId("SNAPSHOT::Simple");
            // log to both text and binary logs for now until we come up with a good solution
            if (mace::LogicalClock::instance().shouldLogPath()) {
              Log::binaryLog(logid, *this);
            }
          }
          
          const char* SimpleService::getMessageName(uint8_t messageType) const {
            switch(messageType) {
              case __internal_Ack::messageType: return "Simple::__internal_Ack";
              case ContextMigrationRequest::messageType: return "Simple::ContextMigrationRequest";
              case TransferContext::messageType: return "Simple::TransferContext";
              case ReportContextMigration::messageType: return "Simple::ReportContextMigration";
              case ContextMappingUpdate::messageType: return "Simple::ContextMappingUpdate";
              case HeadEvent::messageType: return "Simple::HeadEvent";
              case __async_at2_rowInit::messageType: return "Simple::__async_at2_rowInit";
              case __target_async_at2_rowInit::messageType: return "Simple::__target_async_at2_rowInit";
              case __async_at4_rowAfter::messageType: return "Simple::__async_at4_rowAfter";
              case __target_async_at4_rowAfter::messageType: return "Simple::__target_async_at4_rowAfter";
              case __async_at8_testMulti::messageType: return "Simple::__async_at8_testMulti";
              case __target_async_at8_testMulti::messageType: return "Simple::__target_async_at8_testMulti";
              case __sync_at1_sctest::messageType: return "Simple::__sync_at1_sctest";
              case __target_sync_at1_sctest::messageType: return "Simple::__target_sync_at1_sctest";
              case __sync_at3_cellInit::messageType: return "Simple::__sync_at3_cellInit";
              case __target_sync_at3_cellInit::messageType: return "Simple::__target_sync_at3_cellInit";
              case __sync_at5_testRCX::messageType: return "Simple::__sync_at5_testRCX";
              case __target_sync_at5_testRCX::messageType: return "Simple::__target_sync_at5_testRCX";
              case __sync_at_snapshot::messageType: return "Simple::__sync_at_snapshot";
              default: ASSERT(false); return "INVALID MESSAGE NUMBER";
            }
          }
          void SimpleService::changeState(state_type stateNum, int selectorId) {
            _actual_state = stateNum;
            Log::logf(selectorId, "FSM: state changed to %s", getStateName(state));
          }
          const char* SimpleService::getStateName(state_type state) const {
            switch(static_cast<uint64_t>(state)) {
              case init: return "Simple::init";
              case exited: return "Simple::exited";
              default: ASSERT(false); return "INVALID STATE NUMBER";
            }
          }
          
          //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
          //BEGIN Mace::Compiler::ServiceImpl::printAPIDemux
          void SimpleService::maceInit() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_maceInit_demux_39
            #define selectorId selectorId_maceInit_demux_39
            ADD_LOG_BACKING
            bool __test = shouldLog_maceInit67();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, maceInit67Dummy(), 0);
              }
            }
            
            
            
            if(__inited++ == 0) {
              //TODO: start utility timer as necessary
              
              _tcp.maceInit();
              if (tcp == -1) {
                tcp  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
              }
              
              resender_timer.schedule(params::get<uint32_t>("FIRST_RESEND_TIME", 1000*1000) );
              macecompiler(0) << "Registering handler with regId " << tcp << " and type ReceiveDataHandler for service variable tcp" << Log::endl;
              _tcp.registerHandler((ReceiveDataHandler&)*this, tcp);
              macecompiler(0) << "Registering handler with regId " << tcp << " and type NetworkErrorHandler for service variable tcp" << Log::endl;
              _tcp.registerHandler((NetworkErrorHandler&)*this, tcp);
              
              if( mace::ContextMapping::getNodeByContext("") == localAddress() ){
                mace::HighLevelEvent he( mace::HighLevelEvent::STARTEVENT );
                downcall_route( mace::ContextMapping::getHead(), HeadEvent(he) );
                ThreadStructure::setTicket( 0 );
                mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
                if(state == exited) {
                  
                  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
                  { }
#line 6238 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                  
                } else
                if(guard_downcall_0_maceInit()) {
                  macecompiler(1) << "Firing Transition downcall maceInit [ guards : (state==init) ] void maceInit()" << Log::endl;
                  
                  
                  
                  downcall_0_maceInit();
                } else
                {
                  macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
                  
                  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
                  { }
#line 6253 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                  
                }
              }
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::maceResume() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_maceResume_demux_40
            #define selectorId selectorId_maceResume_demux_40
            ADD_LOG_BACKING
            bool __test = shouldLog_maceResume68();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "maceResume(" << ")" << Log::endl;
            }
            
            
            
            if(__inited++ == 0) {
              //TODO: start utility timer as necessary
              
              _tcp.maceInit();
              if (tcp == -1) {
                tcp  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
              }
              
              resender_timer.schedule(params::get<uint32_t>("FIRST_RESEND_TIME", 1000*1000) );
              macecompiler(0) << "Registering handler with regId " << tcp << " and type ReceiveDataHandler for service variable tcp" << Log::endl;
              _tcp.registerHandler((ReceiveDataHandler&)*this, tcp);
              macecompiler(0) << "Registering handler with regId " << tcp << " and type NetworkErrorHandler for service variable tcp" << Log::endl;
              _tcp.registerHandler((NetworkErrorHandler&)*this, tcp);
              
              macecompiler(1) << "COMPILER RUNTIME NOTICE: maceResume called, but not implemented" << Log::endl;
              {
                macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
                
                #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
                { }
#line 6310 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                
              }
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::maceExit() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_maceExit_demux_41
            #define selectorId selectorId_maceExit_demux_41
            ADD_LOG_BACKING
            bool __test = shouldLog_maceExit69();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "maceExit(" << ")" << Log::endl;
            }
            
            
            
            if(--__inited == 0) {
              if( mace::ContextMapping::getNodeByContext("") == localAddress() ){
                mace::HighLevelEvent he( mace::HighLevelEvent::ENDEVENT );
                downcall_route( mace::ContextMapping::getHead(), HeadEvent(he) );
                ThreadStructure::setTicket( 0 );
                mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
                macecompiler(1) << "COMPILER RUNTIME NOTICE: maceExit called, but not implemented" << Log::endl;
                {
                  macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
                  
                  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
                  { }
#line 6358 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                  
                }
              }
              
              //TODO: stop utility timer as necessary
              _actual_state = exited;
              ctsTimer.cancel();
              t.cancel();
              resender_timer.cancel();
              _tcp.unregisterHandler((ReceiveDataHandler&)*this, tcp);
              _tcp.unregisterHandler((NetworkErrorHandler&)*this, tcp);
              
              _tcp.maceExit();
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::maceReset() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_maceReset_demux_42
            #define selectorId selectorId_maceReset_demux_42
            ADD_LOG_BACKING
            bool __test = shouldLog_maceReset70();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, maceReset70Dummy(), 0);
              }
            }
            
            
            {
              
              #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServiceClass.h"
              { }
#line 6410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            //TODO: stop utility timer as necessary
            _actual_state = init;
            ctsTimer.cancel();
            t.cancel();
            resender_timer.cancel();
            
            _tcp.maceReset();
            initial_matrix = Matrix();
            rows = int();
            columns = int();
            matrix_rows = int();
            matrix_columns = int();
            current_iteration = int();
            init_rows = int();
            finished_row = int();
            returnedValues = int();
            result = Matrix();
            runs = int();
            __internal_msgseqno = mace::map< mace::string, uint32_t>();
            __internal_lastAckedSeqno = mace::map<mace::string, uint32_t >();
            __internal_receivedSeqno = mace::map<mace::string, mace::map<uint32_t,uint8_t>  >();
            __internal_unAck = mace::map<mace::string, mace::map<uint32_t, mace::string> >();
            __internal_contextPrevEvent = mace::map<mace::string, uint32_t>();
            
            __inited = 0;
            
            #undef selector
            #undef selectorId
            
          }
          const MaceKey& SimpleService::localAddress() const {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_localAddress_demux_43
            #define selectorId selectorId_localAddress_demux_43
            ADD_LOG_BACKING
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            
            
            {
              
              { return __local_address; }
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          uint32_t SimpleService::hashState() const {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_hashState_demux_44
            #define selectorId selectorId_hashState_demux_44
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_hashState72();
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, hashState72Dummy(), 0);
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
          void SimpleService::rowInit(
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const int& row
#line 6517 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 6521 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_rowInit_demux_50
            #define selectorId selectorId_rowInit_demux_50
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            if( this->R.find( row ) == this->R.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R.find( row ) == this->R.end() )
              this->R[row] = __R__Context(contextDebugID);
            }
            
            mace::ContextLock __contextLock1(this->R[ row  ], mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "rowInit(" << "[row=";
                  mace::printItem(macecompiler(0), &row);
                  macecompiler(0) << "]"
                  << "[x=";
                  mace::printItem(macecompiler(0), &x);
                  macecompiler(0) << "]"
                  << "[snapshotContext1=";
                  mace::printItem(macecompiler(0), &snapshotContext1);
                  macecompiler(0) << "]"
                  << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
            } else
            if(guard_async_2_rowInit(row,x,snapshotContext1)) {
              macecompiler(1) << "Firing Transition async rowInit [ guards : (state==init) ] void rowInit( const int& row, int x, mace::string const & snapshotContext1)" << Log::endl;
              
              
              
              async_2_rowInit(row,x,snapshotContext1);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
            }
            
            // when async call is finished, the event downgrades to anonymous context.
            // Send a message to head to notify the event has committed.
            // mace::ContextLock::downgradeToAnonymous();
            // __internal_commit commitMsg( eventID );
            // downcall_route( ContextMapping::getHead(), commitMsg );
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::rowAfter(
              #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 6598 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_rowAfter_demux_51
            #define selectorId selectorId_rowAfter_demux_51
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            if( this->R.find( row ) == this->R.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R.find( row ) == this->R.end() )
              this->R[row] = __R__Context(contextDebugID);
            }
            
            mace::ContextLock __contextLock1(this->R[ row  ], mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "rowAfter(" << "[row=";
                  mace::printItem(macecompiler(0), &row);
                  macecompiler(0) << "]"
                  << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
            } else
            if(guard_async_4_rowAfter(row)) {
              macecompiler(1) << "Firing Transition async rowAfter [ guards : (true) ] void rowAfter(int row)" << Log::endl;
              
              
              
              async_4_rowAfter(row);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
            }
            
            // when async call is finished, the event downgrades to anonymous context.
            // Send a message to head to notify the event has committed.
            // mace::ContextLock::downgradeToAnonymous();
            // __internal_commit commitMsg( eventID );
            // downcall_route( ContextMapping::getHead(), commitMsg );
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::testMulti(
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              uint32_t m1
#line 6669 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              mace::string str
#line 6673 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_testMulti_demux_52
            #define selectorId selectorId_testMulti_demux_52
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            if( this->M.find( __M__Context__param(m1,str) ) == this->M.end() ){
              mace::string contextDebugID = std::string("")+"M["+ boost::lexical_cast<std::string>(__M__Context__param(m1,str)) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->M.find( __M__Context__param(m1,str) ) == this->M.end() )
              this->M[ __M__Context__param(m1,str) ] = __M__Context(contextDebugID);
            }
            
            mace::ContextLock __contextLock1(this->M [ __M__Context__param(m1,str) ], mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("")+"M["+ boost::lexical_cast<std::string>(__M__Context__param(m1,str)) + "]");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "testMulti(" << "[m1=";
                  mace::printItem(macecompiler(0), &m1);
                  macecompiler(0) << "]"
                  << "[str=";
                  mace::printItem(macecompiler(0), &str);
                  macecompiler(0) << "]"
                  << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
            } else
            if(guard_async_8_testMulti(m1,str)) {
              macecompiler(1) << "Firing Transition async testMulti [ guards : (true) ] void testMulti(uint32_t m1, mace::string str)" << Log::endl;
              
              
              
              async_8_testMulti(m1,str);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
            }
            
            // when async call is finished, the event downgrades to anonymous context.
            // Send a message to head to notify the event has committed.
            // mace::ContextLock::downgradeToAnonymous();
            // __internal_commit commitMsg( eventID );
            // downcall_route( ContextMapping::getHead(), commitMsg );
            
            #undef selector
            #undef selectorId
            
          }
          //END Mace::Compiler::ServiceImpl::printAsyncDemux
          //BEGIN Mace::Compiler::ServiceImpl::printSyncDemux
          bool SimpleService::sctest() {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_sctest_demux_53
            #define selectorId selectorId_sctest_demux_53
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            mace::ContextLock __contextLock1(this->T, mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("")+"T");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "sctest(" << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
              
              bool returnValue = false;
              
              return returnValue;
              // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3419
              
            } else
            if(guard_sync_1_sctest()) {
              macecompiler(1) << "Firing Transition sync sctest [ guards : (state==init) ] bool sctest()" << Log::endl;
              
              
              
              return mace::logVal( sync_1_sctest(), selectorId->compiler, "rv_bool");
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              
              bool returnValue = false;
              
              return returnValue;
              // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3419
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::cellInit(
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 6812 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 6816 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1, mace::string const & snapshotContext2) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_cellInit_demux_54
            #define selectorId selectorId_cellInit_demux_54
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            if( this->R.find( row ) == this->R.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R.find( row ) == this->R.end() )
              this->R[row] = __R__Context(contextDebugID);
            }
            
            // don't take the snapshot of the parent context (for now)
            //mace::ContextLock __contextLock1(this->R[ row  ], mace::ContextLock::READ_MODE);
            
            if( this->R[ row  ].C.find( column ) == this->R[ row  ].C.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]" + "C["+ boost::lexical_cast<std::string>(column) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R[ row  ].C.find( column ) == this->R[ row  ].C.end() )
              this->R[ row  ].C[column] = __C__Context(contextDebugID);
            }
            
            mace::ContextLock __contextLock2(this->R[ row  ].C[ column  ], mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]" + "C["+ boost::lexical_cast<std::string>(column) + "]");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "cellInit(" << "[row=";
                  mace::printItem(macecompiler(0), &row);
                  macecompiler(0) << "]"
                  << "[column=";
                  mace::printItem(macecompiler(0), &column);
                  macecompiler(0) << "]"
                  << "[snapshotContext1=";
                  mace::printItem(macecompiler(0), &snapshotContext1);
                  macecompiler(0) << "]"
                  << "[snapshotContext2=";
                  mace::printItem(macecompiler(0), &snapshotContext2);
                  macecompiler(0) << "]"
                  << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
              
              bool returnValue = false;
              
              return returnValue;
              // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3419
              
            } else
            if(guard_sync_3_cellInit(row,column,snapshotContext1,snapshotContext2)) {
              macecompiler(1) << "Firing Transition sync cellInit [ guards : (state==init) ] bool cellInit(int row, int column, mace::string const & snapshotContext1, mace::string const & snapshotContext2)" << Log::endl;
              
              
              
              return mace::logVal( sync_3_cellInit(row,column,snapshotContext1,snapshotContext2), selectorId->compiler, "rv_bool");
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              
              bool returnValue = false;
              
              return returnValue;
              // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3419
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::testRCX(
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 6912 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 6916 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 6920 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_testRCX_demux_55
            #define selectorId selectorId_testRCX_demux_55
            ADD_LOG_BACKING
            
            //mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::READ_MODE);
            
            if( this->R.find( row ) == this->R.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R.find( row ) == this->R.end() )
              this->R[row] = __R__Context(contextDebugID);
            }
            
            // don't take the snapshot of the parent context (for now)
            //mace::ContextLock __contextLock1(this->R[ row  ], mace::ContextLock::READ_MODE);
            
            if( this->R[ row  ].C.find( column ) == this->R[ row  ].C.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]" + "C["+ boost::lexical_cast<std::string>(column) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R[ row  ].C.find( column ) == this->R[ row  ].C.end() )
              this->R[ row  ].C[column] = __C__Context(contextDebugID);
            }
            
            // don't take the snapshot of the parent context (for now)
            //mace::ContextLock __contextLock2(this->R[ row  ].C[ column  ], mace::ContextLock::READ_MODE);
            
            if( this->R[ row  ].C[ column  ].X.find( x ) == this->R[ row  ].C[ column  ].X.end() ){
              mace::string contextDebugID = std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]" + "C["+ boost::lexical_cast<std::string>(column) + "]" + "X["+ boost::lexical_cast<std::string>(x) + "]";
              ScopedLock sl( mace::ContextBaseClass::newContextMutex );
              if( this->R[ row  ].C[ column  ].X.find( x ) == this->R[ row  ].C[ column  ].X.end() )
              this->R[ row  ].C[ column  ].X[x] = __X__Context(contextDebugID);
            }
            
            mace::ContextLock __contextLock3(this->R[ row  ].C[ column  ].X[ x  ], mace::ContextLock::WRITE_MODE);
            
            // Push current contextID into thread's contextID stack
            ThreadStructure::pushContext(std::string("") + "R["+ boost::lexical_cast<std::string>(row) + "]" + "C["+ boost::lexical_cast<std::string>(column) + "]" + "X["+ boost::lexical_cast<std::string>(x) + "]");
            
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer;
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if(!macecompiler(0).isNoop()) {
              macecompiler(0) << "testRCX(" << "[row=";
                  mace::printItem(macecompiler(0), &row);
                  macecompiler(0) << "]"
                  << "[column=";
                  mace::printItem(macecompiler(0), &column);
                  macecompiler(0) << "]"
                  << "[x=";
                  mace::printItem(macecompiler(0), &x);
                  macecompiler(0) << "]"
                  << "[snapshotContext1=";
                  mace::printItem(macecompiler(0), &snapshotContext1);
                  macecompiler(0) << "]"
                  << "[snapshotContext2=";
                  mace::printItem(macecompiler(0), &snapshotContext2);
                  macecompiler(0) << "]"
                  << "[snapshotContext3=";
                  mace::printItem(macecompiler(0), &snapshotContext3);
                  macecompiler(0) << "]"
                  << ")" << Log::endl;
            }
            
            
            if(state == exited) {
              
            } else
            if(guard_sync_5_testRCX(row,column,x,snapshotContext1,snapshotContext2,snapshotContext3)) {
              macecompiler(1) << "Firing Transition sync testRCX [ guards : (state==init) ] void testRCX(int row, int column, int x, mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3)" << Log::endl;
              
              
              
              sync_5_testRCX(row,column,x,snapshotContext1,snapshotContext2,snapshotContext3);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          //END Mace::Compiler::ServiceImpl::printSyncDemux
          //BEGIN Mace::Compiler::ServiceImpl::printAspectDemux
          //END Mace::Compiler::ServiceImpl::printAspectDemux
          //BEGIN Mace::Compiler::ServiceImpl::printHandlerRegistrations
          //END Mace::Compiler::ServiceImpl::printHandlerRegistrations
          
          //Handler demux (uses handlers)
          //BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux
          void SimpleService::error(
              #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              const MaceKey& nodeId
#line 7028 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              TransportError::type errorCode
#line 7032 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              const std::string& message
#line 7036 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/NetworkErrorHandler.h"
              registration_uid_t rid
#line 7040 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            bool __test = shouldLog_error73(nodeId, errorCode, message, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
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
#line 7087 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7098 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& s_deserialized
#line 7106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            bool __test = shouldLog_deliver74(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver74Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7144 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_9_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const __internal_Ack& msg)" << Log::endl;
              
              
              
              upcall_9_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7170 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& s_deserialized
#line 7178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_2
            #define selectorId selectorId_deliver_demux_2
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver75(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver75Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7216 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_11_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const ContextMigrationRequest& msg)" << Log::endl;
              
              
              
              upcall_11_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7231 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7242 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7246 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& s_deserialized
#line 7250 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7254 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            bool __test = shouldLog_deliver76(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver76Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_12_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const TransferContext& msg)" << Log::endl;
              
              
              
              upcall_12_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7303 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7314 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7318 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& s_deserialized
#line 7322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            bool __test = shouldLog_deliver77(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver77Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7360 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_13_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const ReportContextMigration& msg)" << Log::endl;
              
              
              
              upcall_13_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& s_deserialized
#line 7394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            bool __test = shouldLog_deliver78(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver78Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7432 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_14_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const ContextMappingUpdate& msg)" << Log::endl;
              
              
              
              upcall_14_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7447 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7458 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7462 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& s_deserialized
#line 7466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7470 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_6
            #define selectorId selectorId_deliver_demux_6
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver79(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver79Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7504 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_15_deliver(source,destination,s_deserialized)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& src,  const MaceKey& dest,  const HeadEvent& msg)" << Log::endl;
              
              
              
              upcall_15_deliver(source,destination,s_deserialized);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7519 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7530 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7534 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& s_deserialized
#line 7538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_7
            #define selectorId selectorId_deliver_demux_7
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver80(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver80Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7576 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_16_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at2_rowInit& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_16_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7591 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7602 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7606 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& s_deserialized
#line 7610 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7614 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_8
            #define selectorId selectorId_deliver_demux_8
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver81(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver81Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7648 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_17_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at2_rowInit& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_17_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7663 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7674 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7678 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& s_deserialized
#line 7682 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_9
            #define selectorId selectorId_deliver_demux_9
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver82(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver82Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7720 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_18_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at4_rowAfter& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_18_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7735 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7746 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7750 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& s_deserialized
#line 7754 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7758 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_10
            #define selectorId selectorId_deliver_demux_10
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver83(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver83Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7792 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_19_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at4_rowAfter& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_19_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7807 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7818 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7822 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& s_deserialized
#line 7826 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_11
            #define selectorId selectorId_deliver_demux_11
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver84(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver84Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7864 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_20_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __async_at8_testMulti& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_20_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7879 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7890 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& s_deserialized
#line 7898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_12
            #define selectorId selectorId_deliver_demux_12
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver85(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver85Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7936 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_21_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_async_at8_testMulti& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_21_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 7951 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 7962 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 7966 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& s_deserialized
#line 7970 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 7974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_13
            #define selectorId selectorId_deliver_demux_13
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver86(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver86Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8008 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_22_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at1_sctest& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_22_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8023 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8034 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8038 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& s_deserialized
#line 8042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_14
            #define selectorId selectorId_deliver_demux_14
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver87(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver87Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_23_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at1_sctest& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_23_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8095 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8110 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& s_deserialized
#line 8114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_15
            #define selectorId selectorId_deliver_demux_15
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver88(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver88Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8152 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_24_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at3_cellInit& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_24_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& s_deserialized
#line 8186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_16
            #define selectorId selectorId_deliver_demux_16
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver89(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver89Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8224 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_25_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at3_cellInit& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_25_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8239 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8250 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8254 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& s_deserialized
#line 8258 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8262 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_17
            #define selectorId selectorId_deliver_demux_17
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver90(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver90Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8296 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_26_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at5_testRCX& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_26_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8311 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8322 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8326 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& s_deserialized
#line 8330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_18
            #define selectorId selectorId_deliver_demux_18
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver91(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver91Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8368 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_27_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __target_sync_at5_testRCX& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_27_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8383 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 8394 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 8398 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& s_deserialized
#line 8402 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 8406 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_deliver_demux_19
            #define selectorId selectorId_deliver_demux_19
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_deliver92(source, destination, s_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, deliver92Dummy(source, destination, s_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8440 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_28_deliver(source,destination,s_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall deliver [ guards : (true) ] void deliver( const MaceKey& source,  const MaceKey& destination,  const __sync_at_snapshot& s_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_28_deliver(source,destination,s_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
              { }
#line 8455 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8466 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8470 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& message_deserialized
#line 8474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_20
            #define selectorId selectorId_messageError_demux_20
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError93(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError93Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8512 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_29_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __internal_Ack& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_29_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8527 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8538 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8542 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& message_deserialized
#line 8546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8550 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_21
            #define selectorId selectorId_messageError_demux_21
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError94(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError94Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8584 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_30_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMigrationRequest& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_30_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8610 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8614 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& message_deserialized
#line 8618 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_22
            #define selectorId selectorId_messageError_demux_22
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError95(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError95Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8656 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_31_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const TransferContext& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_31_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8671 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8682 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8686 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& message_deserialized
#line 8690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_23
            #define selectorId selectorId_messageError_demux_23
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError96(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError96Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8728 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_32_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const ReportContextMigration& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_32_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8754 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8758 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& message_deserialized
#line 8762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8766 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_24
            #define selectorId selectorId_messageError_demux_24
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError97(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError97Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8800 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_33_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const ContextMappingUpdate& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_33_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8826 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8830 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& message_deserialized
#line 8834 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8838 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_25
            #define selectorId selectorId_messageError_demux_25
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError98(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError98Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8872 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_34_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const HeadEvent& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_34_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8887 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8902 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& message_deserialized
#line 8906 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_26
            #define selectorId selectorId_messageError_demux_26
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError99(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError99Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8944 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_35_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at2_rowInit& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_35_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 8959 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 8970 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 8974 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& message_deserialized
#line 8978 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 8982 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_27
            #define selectorId selectorId_messageError_demux_27
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError100(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError100Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_36_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at2_rowInit& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_36_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9031 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9042 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9046 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& message_deserialized
#line 9050 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9054 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_28
            #define selectorId selectorId_messageError_demux_28
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError101(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError101Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9088 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_37_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at4_rowAfter& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_37_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9103 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& message_deserialized
#line 9122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9126 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_29
            #define selectorId selectorId_messageError_demux_29
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError102(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError102Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9160 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_38_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at4_rowAfter& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_38_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9175 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9190 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& message_deserialized
#line 9194 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_30
            #define selectorId selectorId_messageError_demux_30
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError103(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError103Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9232 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_39_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __async_at8_testMulti& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_39_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9258 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9262 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& message_deserialized
#line 9266 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9270 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_31
            #define selectorId selectorId_messageError_demux_31
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError104(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError104Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_40_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_async_at8_testMulti& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_40_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9319 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9330 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9334 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& message_deserialized
#line 9338 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9342 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_32
            #define selectorId selectorId_messageError_demux_32
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError105(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError105Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9376 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_41_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at1_sctest& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_41_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9391 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9402 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9406 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& message_deserialized
#line 9410 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9414 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_33
            #define selectorId selectorId_messageError_demux_33
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError106(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError106Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9448 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_42_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at1_sctest& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_42_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9463 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9474 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9478 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& message_deserialized
#line 9482 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9486 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_34
            #define selectorId selectorId_messageError_demux_34
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError107(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError107Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9520 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_43_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at3_cellInit& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_43_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9535 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9546 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9550 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& message_deserialized
#line 9554 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9558 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_35
            #define selectorId selectorId_messageError_demux_35
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError108(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError108Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9592 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_44_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at3_cellInit& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_44_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9607 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9618 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9622 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& message_deserialized
#line 9626 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9630 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_36
            #define selectorId selectorId_messageError_demux_36
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError109(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError109Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9664 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_45_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at5_testRCX& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_45_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9679 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9690 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9694 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& message_deserialized
#line 9698 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9702 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_37
            #define selectorId selectorId_messageError_demux_37
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError110(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError110Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9736 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_46_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __target_sync_at5_testRCX& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_46_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9751 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 9762 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 9766 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& message_deserialized
#line 9770 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 9774 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = 1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            PREPARE_FUNCTION
            #define selector selector_messageError_demux_38
            #define selectorId selectorId_messageError_demux_38
            ADD_LOG_BACKING
            
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            bool __test = shouldLog_messageError111(dest, errorCode, message_deserialized, rid);
            mace::ScopedFingerprint __fingerprint(selector);
            mace::ScopedStackExecution __defer(__test);
            mace::ScopedStackExecution::addDefer(this);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, messageError111Dummy(dest, errorCode, message_deserialized, rid), 0);
              }
            }
            
            
            if(state == exited) {
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            } else
            if(guard_upcall_47_messageError(dest,errorCode,message_deserialized,rid)) {
              macecompiler(1) << "Firing Transition upcall messageError [ guards : (true) ] void messageError( const MaceKey& dest, TransportError::type errorCode,  const __sync_at_snapshot& message_deserialized, registration_uid_t rid)" << Log::endl;
              
              
              
              upcall_47_messageError(dest,errorCode,message_deserialized,rid);
            } else
            {
              macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
              
              #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
              { }
#line 9823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              
            }
            
            #undef selector
            #undef selectorId
            
          }
          //END Mace::Compiler::ServiceImpl::printHandlerDemux
          
          //Downcall helpers (uses)
          //BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers
          
          MaceKey SimpleService::downcall_localAddress() const {
            return _tcp.localAddress();
          }
          const MaceKey& SimpleService::downcall_localAddress(const registration_uid_t& rid) const {
            
            if (&rid == &tcp) {
              return _tcp.localAddress();
            }
            
            if (rid == tcp) {
              return _tcp.localAddress();
            }
            return MaceKey::null;
          }
          void SimpleService::downcall_suspendDeliver(
              #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
              registration_uid_t rid
#line 9853 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            
            
            
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              _tcp.suspendDeliver(rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::downcall_suspendDeliver(
              #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
              const MaceKey& dest
#line 9894 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
              registration_uid_t rid
#line 9898 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            
            
            
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              _tcp.suspendDeliver(dest,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::downcall_resumeDeliver(
              #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
              registration_uid_t rid
#line 9939 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            
            
            
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              _tcp.resumeDeliver(rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::downcall_resumeDeliver(
              #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
              const MaceKey& dest
#line 9980 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
              registration_uid_t rid
#line 9984 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            
            
            
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              _tcp.resumeDeliver(dest,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10025 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const Message& s_deserialized
#line 10029 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10033 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10076 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& s_deserialized
#line 10080 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10084 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
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
            ScopedSerialize<std::string, __internal_Ack> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& s_deserialized
#line 10131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10135 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_6
            #define selectorId selectorId_route_downcall_6
            ADD_LOG_BACKING
            bool __test = shouldLog_route6(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route6Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMigrationRequest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& s_deserialized
#line 10182 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10186 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_7
            #define selectorId selectorId_route_downcall_7
            ADD_LOG_BACKING
            bool __test = shouldLog_route7(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route7Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, TransferContext> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10229 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& s_deserialized
#line 10233 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10237 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_8
            #define selectorId selectorId_route_downcall_8
            ADD_LOG_BACKING
            bool __test = shouldLog_route8(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route8Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ReportContextMigration> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10280 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& s_deserialized
#line 10284 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10288 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_9
            #define selectorId selectorId_route_downcall_9
            ADD_LOG_BACKING
            bool __test = shouldLog_route9(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route9Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMappingUpdate> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10331 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& s_deserialized
#line 10335 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10339 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_10
            #define selectorId selectorId_route_downcall_10
            ADD_LOG_BACKING
            bool __test = shouldLog_route10(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route10Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, HeadEvent> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10382 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& s_deserialized
#line 10386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10390 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_11
            #define selectorId selectorId_route_downcall_11
            ADD_LOG_BACKING
            bool __test = shouldLog_route11(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route11Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10433 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& s_deserialized
#line 10437 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10441 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_12
            #define selectorId selectorId_route_downcall_12
            ADD_LOG_BACKING
            bool __test = shouldLog_route12(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route12Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10484 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& s_deserialized
#line 10488 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10492 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_13
            #define selectorId selectorId_route_downcall_13
            ADD_LOG_BACKING
            bool __test = shouldLog_route13(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route13Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10535 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& s_deserialized
#line 10539 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10543 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_14
            #define selectorId selectorId_route_downcall_14
            ADD_LOG_BACKING
            bool __test = shouldLog_route14(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route14Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10586 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& s_deserialized
#line 10590 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10594 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_15
            #define selectorId selectorId_route_downcall_15
            ADD_LOG_BACKING
            bool __test = shouldLog_route15(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route15Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10637 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& s_deserialized
#line 10641 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10645 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_16
            #define selectorId selectorId_route_downcall_16
            ADD_LOG_BACKING
            bool __test = shouldLog_route16(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route16Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10688 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& s_deserialized
#line 10692 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10696 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_17
            #define selectorId selectorId_route_downcall_17
            ADD_LOG_BACKING
            bool __test = shouldLog_route17(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route17Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10739 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& s_deserialized
#line 10743 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10747 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_18
            #define selectorId selectorId_route_downcall_18
            ADD_LOG_BACKING
            bool __test = shouldLog_route18(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route18Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10790 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& s_deserialized
#line 10794 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10798 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_19
            #define selectorId selectorId_route_downcall_19
            ADD_LOG_BACKING
            bool __test = shouldLog_route19(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route19Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10841 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& s_deserialized
#line 10845 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10849 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_20
            #define selectorId selectorId_route_downcall_20
            ADD_LOG_BACKING
            bool __test = shouldLog_route20(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route20Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& s_deserialized
#line 10896 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10900 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_21
            #define selectorId selectorId_route_downcall_21
            ADD_LOG_BACKING
            bool __test = shouldLog_route21(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route21Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10943 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& s_deserialized
#line 10947 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 10951 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_22
            #define selectorId selectorId_route_downcall_22
            ADD_LOG_BACKING
            bool __test = shouldLog_route22(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route22Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 10994 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& s_deserialized
#line 10998 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11002 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_23
            #define selectorId selectorId_route_downcall_23
            ADD_LOG_BACKING
            bool __test = shouldLog_route23(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route23Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at_snapshot> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11045 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11049 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const Message& s_deserialized
#line 11053 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11057 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_24
            #define selectorId selectorId_route_downcall_24
            ADD_LOG_BACKING
            bool __test = shouldLog_route24(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route24Dummy(), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& s_deserialized
#line 11108 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11112 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_25
            #define selectorId selectorId_route_downcall_25
            ADD_LOG_BACKING
            bool __test = shouldLog_route25(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route25Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __internal_Ack> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& s_deserialized
#line 11163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11167 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_26
            #define selectorId selectorId_route_downcall_26
            ADD_LOG_BACKING
            bool __test = shouldLog_route26(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route26Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMigrationRequest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11210 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11214 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& s_deserialized
#line 11218 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11222 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_27
            #define selectorId selectorId_route_downcall_27
            ADD_LOG_BACKING
            bool __test = shouldLog_route27(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route27Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, TransferContext> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11269 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& s_deserialized
#line 11273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11277 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_28
            #define selectorId selectorId_route_downcall_28
            ADD_LOG_BACKING
            bool __test = shouldLog_route28(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route28Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ReportContextMigration> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11320 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11324 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& s_deserialized
#line 11328 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11332 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_29
            #define selectorId selectorId_route_downcall_29
            ADD_LOG_BACKING
            bool __test = shouldLog_route29(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route29Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMappingUpdate> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11375 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11379 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& s_deserialized
#line 11383 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11387 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_30
            #define selectorId selectorId_route_downcall_30
            ADD_LOG_BACKING
            bool __test = shouldLog_route30(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route30Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, HeadEvent> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11430 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11434 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& s_deserialized
#line 11438 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11442 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_31
            #define selectorId selectorId_route_downcall_31
            ADD_LOG_BACKING
            bool __test = shouldLog_route31(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route31Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11485 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11489 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& s_deserialized
#line 11493 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11497 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_32
            #define selectorId selectorId_route_downcall_32
            ADD_LOG_BACKING
            bool __test = shouldLog_route32(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route32Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11540 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11544 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& s_deserialized
#line 11548 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11552 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_33
            #define selectorId selectorId_route_downcall_33
            ADD_LOG_BACKING
            bool __test = shouldLog_route33(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route33Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11595 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11599 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& s_deserialized
#line 11603 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11607 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_34
            #define selectorId selectorId_route_downcall_34
            ADD_LOG_BACKING
            bool __test = shouldLog_route34(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route34Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11650 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11654 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& s_deserialized
#line 11658 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11662 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_35
            #define selectorId selectorId_route_downcall_35
            ADD_LOG_BACKING
            bool __test = shouldLog_route35(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route35Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11705 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11709 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& s_deserialized
#line 11713 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11717 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_36
            #define selectorId selectorId_route_downcall_36
            ADD_LOG_BACKING
            bool __test = shouldLog_route36(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route36Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11760 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11764 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& s_deserialized
#line 11768 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11772 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_37
            #define selectorId selectorId_route_downcall_37
            ADD_LOG_BACKING
            bool __test = shouldLog_route37(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route37Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11815 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11819 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& s_deserialized
#line 11823 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11827 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_38
            #define selectorId selectorId_route_downcall_38
            ADD_LOG_BACKING
            bool __test = shouldLog_route38(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route38Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11870 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11874 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& s_deserialized
#line 11878 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11882 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_39
            #define selectorId selectorId_route_downcall_39
            ADD_LOG_BACKING
            bool __test = shouldLog_route39(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route39Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11925 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11929 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& s_deserialized
#line 11933 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11937 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_40
            #define selectorId selectorId_route_downcall_40
            ADD_LOG_BACKING
            bool __test = shouldLog_route40(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route40Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 11980 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 11984 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& s_deserialized
#line 11988 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 11992 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_41
            #define selectorId selectorId_route_downcall_41
            ADD_LOG_BACKING
            bool __test = shouldLog_route41(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route41Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 12035 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12039 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& s_deserialized
#line 12043 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12047 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_42
            #define selectorId selectorId_route_downcall_42
            ADD_LOG_BACKING
            bool __test = shouldLog_route42(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route42Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          bool SimpleService::downcall_route(
              #line 4 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& src
#line 12090 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 5 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12094 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 6 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& s_deserialized
#line 12098 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 8 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_route_downcall_43
            #define selectorId selectorId_route_downcall_43
            ADD_LOG_BACKING
            bool __test = shouldLog_route43(src, dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, route43Dummy(src, dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at_snapshot> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.route(src,dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12145 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const Message& s_deserialized
#line 12149 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12153 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_44
            #define selectorId selectorId_send_downcall_44
            ADD_LOG_BACKING
            bool __test = shouldLog_send44(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send44Dummy(), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, Message> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12196 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __internal_Ack& s_deserialized
#line 12200 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_45
            #define selectorId selectorId_send_downcall_45
            ADD_LOG_BACKING
            bool __test = shouldLog_send45(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send45Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __internal_Ack> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMigrationRequest& s_deserialized
#line 12251 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12255 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_46
            #define selectorId selectorId_send_downcall_46
            ADD_LOG_BACKING
            bool __test = shouldLog_send46(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send46Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMigrationRequest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12298 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const TransferContext& s_deserialized
#line 12302 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12306 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_47
            #define selectorId selectorId_send_downcall_47
            ADD_LOG_BACKING
            bool __test = shouldLog_send47(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send47Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, TransferContext> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12349 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ReportContextMigration& s_deserialized
#line 12353 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12357 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_48
            #define selectorId selectorId_send_downcall_48
            ADD_LOG_BACKING
            bool __test = shouldLog_send48(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send48Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ReportContextMigration> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12400 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const ContextMappingUpdate& s_deserialized
#line 12404 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12408 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_49
            #define selectorId selectorId_send_downcall_49
            ADD_LOG_BACKING
            bool __test = shouldLog_send49(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send49Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, ContextMappingUpdate> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12451 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const HeadEvent& s_deserialized
#line 12455 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12459 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_50
            #define selectorId selectorId_send_downcall_50
            ADD_LOG_BACKING
            bool __test = shouldLog_send50(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send50Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, HeadEvent> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12502 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at2_rowInit& s_deserialized
#line 12506 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12510 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_51
            #define selectorId selectorId_send_downcall_51
            ADD_LOG_BACKING
            bool __test = shouldLog_send51(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send51Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12553 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at2_rowInit& s_deserialized
#line 12557 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12561 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_52
            #define selectorId selectorId_send_downcall_52
            ADD_LOG_BACKING
            bool __test = shouldLog_send52(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send52Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at2_rowInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12604 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at4_rowAfter& s_deserialized
#line 12608 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12612 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_53
            #define selectorId selectorId_send_downcall_53
            ADD_LOG_BACKING
            bool __test = shouldLog_send53(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send53Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12655 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at4_rowAfter& s_deserialized
#line 12659 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12663 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_54
            #define selectorId selectorId_send_downcall_54
            ADD_LOG_BACKING
            bool __test = shouldLog_send54(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send54Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at4_rowAfter> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12706 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __async_at8_testMulti& s_deserialized
#line 12710 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12714 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_55
            #define selectorId selectorId_send_downcall_55
            ADD_LOG_BACKING
            bool __test = shouldLog_send55(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send55Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12757 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_async_at8_testMulti& s_deserialized
#line 12761 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12765 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_56
            #define selectorId selectorId_send_downcall_56
            ADD_LOG_BACKING
            bool __test = shouldLog_send56(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send56Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_async_at8_testMulti> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12808 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at1_sctest& s_deserialized
#line 12812 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12816 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_57
            #define selectorId selectorId_send_downcall_57
            ADD_LOG_BACKING
            bool __test = shouldLog_send57(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send57Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12859 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at1_sctest& s_deserialized
#line 12863 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12867 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_58
            #define selectorId selectorId_send_downcall_58
            ADD_LOG_BACKING
            bool __test = shouldLog_send58(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send58Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at1_sctest> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12910 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at3_cellInit& s_deserialized
#line 12914 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12918 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_59
            #define selectorId selectorId_send_downcall_59
            ADD_LOG_BACKING
            bool __test = shouldLog_send59(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send59Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 12961 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at3_cellInit& s_deserialized
#line 12965 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 12969 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_60
            #define selectorId selectorId_send_downcall_60
            ADD_LOG_BACKING
            bool __test = shouldLog_send60(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send60Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at3_cellInit> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 13012 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at5_testRCX& s_deserialized
#line 13016 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 13020 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_61
            #define selectorId selectorId_send_downcall_61
            ADD_LOG_BACKING
            bool __test = shouldLog_send61(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send61Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 13063 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __target_sync_at5_testRCX& s_deserialized
#line 13067 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 13071 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_62
            #define selectorId selectorId_send_downcall_62
            ADD_LOG_BACKING
            bool __test = shouldLog_send62(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send62Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __target_sync_at5_testRCX> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          size_t SimpleService::downcall_send(
              #line 10 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 13114 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const __sync_at_snapshot& s_deserialized
#line 13118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 17 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 13122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_send_downcall_63
            #define selectorId selectorId_send_downcall_63
            ADD_LOG_BACKING
            bool __test = shouldLog_send63(dest, s_deserialized, rid);
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, __test && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            if (mace::LogicalClock::instance().shouldLogPath()) {
              if (__test) {
                Log::binaryLog(selectorId->compiler, send63Dummy(dest, s_deserialized, rid), 0);
              }
            }
            
            
            
            std::string s;
            ScopedSerialize<std::string, __sync_at_snapshot> __ss_s_deserialized(s, s_deserialized);
            
            if(rid == -1) { rid = tcp; }
            
            if(rid == tcp) {
              return _tcp.send(dest,s,rid);
            } else
            { ABORT("Did not match any registration uid!"); }
            
            #undef selector
            #undef selectorId
            
          }
          //END Mace::Compiler::ServiceImpl::printDowncallHelpers
          
          //Upcall helpers (provides handlers)
          //BEGIN Mace::Compiler::ServiceImpl::printUpcallHelpers
          //END Mace::Compiler::ServiceImpl::printUpcallHelpers
          
          //Async helpers
          void SimpleService::async_rowInit(
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const int& row
#line 13172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 13176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          {
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            mace::string currContextID = ThreadStructure::getCurrentContext();
            
            // send a message to head node
            ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
            const MaceKey& headNode = ContextMapping::getHead();
            uint32_t msgseqno = ++__internal_msgseqno[ ContextMapping::getHeadContext()];
            __async_at2_rowInit pcopy(row, x, currContextID, startContextID, targetContextID, snapshotContextIDs, 0, msgseqno );
            mace::string buf;
            mace::serialize(buf, &pcopy);
            __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
            downcall_route(headNode,pcopy);
          }
          void SimpleService::async_rowAfter(
              #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13208 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          {
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            mace::string currContextID = ThreadStructure::getCurrentContext();
            
            // send a message to head node
            ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
            const MaceKey& headNode = ContextMapping::getHead();
            uint32_t msgseqno = ++__internal_msgseqno[ ContextMapping::getHeadContext()];
            __async_at4_rowAfter pcopy(row, currContextID, startContextID, targetContextID, snapshotContextIDs, 0, msgseqno );
            mace::string buf;
            mace::serialize(buf, &pcopy);
            __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
            downcall_route(headNode,pcopy);
          }
          void SimpleService::async_testMulti(
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              uint32_t m1
#line 13240 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              mace::string str
#line 13244 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          {
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "M[" + boost::lexical_cast<std::string>(__M__Context__param(m1,str) ) + "]";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            mace::string currContextID = ThreadStructure::getCurrentContext();
            
            // send a message to head node
            ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
            const MaceKey& headNode = ContextMapping::getHead();
            uint32_t msgseqno = ++__internal_msgseqno[ ContextMapping::getHeadContext()];
            __async_at8_testMulti pcopy(m1, str, currContextID, startContextID, targetContextID, snapshotContextIDs, 0, msgseqno );
            mace::string buf;
            mace::serialize(buf, &pcopy);
            __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;
            downcall_route(headNode,pcopy);
          }
          void SimpleService::target_async_rowInit(
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const int& row
#line 13276 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 130 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 13280 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]";
            
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              rowInit(row, x, snapshotContext1) ;
              ThreadStructure::popContext();
              return;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_async_at2_rowInit pcopy(row, x, snapshotContext1, currentContextID, currentContextID, contextID, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              sl.unlock();
              return;
              
            }else{
              
              sl.unlock();
              return;
              
            }
          }
          void SimpleService::target_async_rowAfter(
              #line 164 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13347 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]";
            
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              rowAfter(row) ;
              ThreadStructure::popContext();
              return;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_async_at4_rowAfter pcopy(row, currentContextID, currentContextID, contextID, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              sl.unlock();
              return;
              
            }else{
              
              sl.unlock();
              return;
              
            }
          }
          void SimpleService::target_async_testMulti(
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              uint32_t m1
#line 13414 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 177 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              mace::string str
#line 13418 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "M[" + boost::lexical_cast<std::string>(__M__Context__param(m1,str) ) + "]";
            
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              testMulti(m1, str) ;
              ThreadStructure::popContext();
              return;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_async_at8_testMulti pcopy(m1, str, currentContextID, currentContextID, contextID, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              sl.unlock();
              return;
              
            }else{
              
              sl.unlock();
              return;
              
            }
          }
          bool SimpleService::sync_sctest()
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          
          {
            // chuangw: XXX: I don't understand.... sync calls should simply go to the "target" context
            // chuangw: FIXME: the snapshot id is wrong........ variables in the context index need to be parsed.
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "T";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            
            mace::string currContextID = ThreadStructure::getCurrentContext();
            //uint64_t myTicket = ThreadStructure::myTicket();
            bool returnValue;
            mace::string returnValueStr; // chuangw: XXX: not used
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(startContextID);
            // chuangw: The context is on the same physical node, so make a function call directly and return the value.
            if(destNode == downcall_localAddress()){
              sl.unlock();
              ThreadStructure::pushContext(currContextID);
              
              returnValue = target_sync_sctest();;
              ThreadStructure::popContext();
              return returnValue;
            }
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(startContextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[startContextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[startContextID];
            }
            __sync_at1_sctest pcopy(currContextID, startContextID, targetContextID, snapshotContextIDs, returnValueStr, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[currContextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              bool returnValue = false;
              
              sl.unlock();
              return returnValue;
            }else{
              std::istringstream in(returnValue_iter->second);
              mace::deserialize(in,  &returnValue);
              sl.unlock();
              return returnValue;
            }
          }
          bool SimpleService::target_sync_sctest()
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "T";
            bool returnValue;
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              returnValue = sctest() ;
              ThreadStructure::popContext();
              return returnValue;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_sync_at1_sctest pcopy(currentContextID, currentContextID, contextID, returnValueStr, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              
              bool returnValue = false;
              
              sl.unlock();
              return returnValue;
              
            }else{
              
              std::istringstream in(returnValue_iter->second);
              bool returnValue;
              mace::deserialize(in,  &returnValue);
              sl.unlock();
              return returnValue;
              
            }
          }
          bool SimpleService::sync_cellInit(
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13629 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 13633 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          
          {
            // chuangw: XXX: I don't understand.... sync calls should simply go to the "target" context
            // chuangw: FIXME: the snapshot id is wrong........ variables in the context index need to be parsed.
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]" + "."  +  "C[" + boost::lexical_cast<std::string>(column) + "]";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            
            mace::string currContextID = ThreadStructure::getCurrentContext();
            //uint64_t myTicket = ThreadStructure::myTicket();
            bool returnValue;
            mace::string returnValueStr; // chuangw: XXX: not used
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(startContextID);
            // chuangw: The context is on the same physical node, so make a function call directly and return the value.
            if(destNode == downcall_localAddress()){
              sl.unlock();
              ThreadStructure::pushContext(currContextID);
              
              mace::string snapshot0 = snapshot_sync_fn(currContextID, snapshotContextIDs[0]);
              
              mace::string snapshot1 = snapshot_sync_fn(currContextID, snapshotContextIDs[1]);
              
              returnValue = target_sync_cellInit(row, column, snapshot0, snapshot1);;
              ThreadStructure::popContext();
              return returnValue;
            }
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(startContextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[startContextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[startContextID];
            }
            __sync_at3_cellInit pcopy(row, column, currContextID, startContextID, targetContextID, snapshotContextIDs, returnValueStr, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[currContextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              bool returnValue = false;
              
              sl.unlock();
              return returnValue;
            }else{
              std::istringstream in(returnValue_iter->second);
              mace::deserialize(in,  &returnValue);
              sl.unlock();
              return returnValue;
            }
          }
          bool SimpleService::target_sync_cellInit(
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13716 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 139 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 13720 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1, mace::string const & snapshotContext2)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]" + "."  +  "C[" + boost::lexical_cast<std::string>(column) + "]";
            bool returnValue;
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              returnValue = cellInit(row, column, snapshotContext1, snapshotContext2) ;
              ThreadStructure::popContext();
              return returnValue;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_sync_at3_cellInit pcopy(row, column, snapshotContext1, snapshotContext2, currentContextID, currentContextID, contextID, returnValueStr, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              
              bool returnValue = false;
              
              sl.unlock();
              return returnValue;
              
            }else{
              
              std::istringstream in(returnValue_iter->second);
              bool returnValue;
              mace::deserialize(in,  &returnValue);
              sl.unlock();
              return returnValue;
              
            }
          }
          void SimpleService::sync_testRCX(
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13793 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 13797 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 13801 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          )
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          
          {
            // chuangw: XXX: I don't understand.... sync calls should simply go to the "target" context
            // chuangw: FIXME: the snapshot id is wrong........ variables in the context index need to be parsed.
            mace::string srcContextID = ThreadStructure::getCurrentContext();
            mace::string targetContextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]" + "."  +  "C[" + boost::lexical_cast<std::string>(column) + "]" + "."  +  "X[" + boost::lexical_cast<std::string>(x) + "]";
            mace::vector<mace::string> snapshotContextIDs;
            ;
            
            mace::vector<mace::string> allContextIDs = snapshotContextIDs;
            allContextIDs.push_back(targetContextID);
            mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
            
            mace::string currContextID = ThreadStructure::getCurrentContext();
            //uint64_t myTicket = ThreadStructure::myTicket();
            
            mace::string returnValueStr; // chuangw: XXX: not used
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(startContextID);
            // chuangw: The context is on the same physical node, so make a function call directly and return the value.
            if(destNode == downcall_localAddress()){
              sl.unlock();
              ThreadStructure::pushContext(currContextID);
              
              mace::string snapshot0 = snapshot_sync_fn(currContextID, snapshotContextIDs[0]);
              
              mace::string snapshot1 = snapshot_sync_fn(currContextID, snapshotContextIDs[1]);
              
              mace::string snapshot2 = snapshot_sync_fn(currContextID, snapshotContextIDs[2]);
              
              target_sync_testRCX(row, column, x, snapshot0, snapshot1, snapshot2);;
              ThreadStructure::popContext();
              return;
            }
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(startContextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[startContextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[startContextID];
            }
            __sync_at5_testRCX pcopy(row, column, x, currContextID, startContextID, targetContextID, snapshotContextIDs, returnValueStr, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[currContextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              sl.unlock();
              return;
            }else{
              std::istringstream in(returnValue_iter->second);
              
              sl.unlock();
              return;
            }
          }
          void SimpleService::target_sync_testRCX(
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int row
#line 13884 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int column
#line 13888 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 167 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              int x
#line 13892 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              , mace::string const & snapshotContext1, mace::string const & snapshotContext2, mace::string const & snapshotContext3)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          // Generated by Mace::Compiler::ServiceImpl::createTargetHelperMethod() line: 3404
          {
            mace::string contextID = std::string("") +  "R[" + boost::lexical_cast<std::string>(row) + "]" + "."  +  "C[" + boost::lexical_cast<std::string>(column) + "]" + "."  +  "X[" + boost::lexical_cast<std::string>(x) + "]";
            
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              
              ThreadStructure::pushContext(contextID);
              testRCX(row, column, x, snapshotContext1, snapshotContext2, snapshotContext3) ;
              ThreadStructure::popContext();
              return;
              
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(contextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[contextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[contextID];
            }
            mace::string returnValueStr;
            __target_sync_at5_testRCX pcopy(row, column, x, snapshotContext1, snapshotContext2, snapshotContext3, currentContextID, currentContextID, contextID, ThreadStructure::myTicket(), msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[contextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
            if(returnValue_iter == returnValueMapping.end()){
              
              sl.unlock();
              return;
              
            }else{
              
              sl.unlock();
              return;
              
            }
          }
          Serializable* SimpleService::findContextByID(mace::string contextID)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          {
            
            mace::Serializable* sobj;
            
            std::vector<std::string> snapshotContextIDs;
            boost::split(snapshotContextIDs, contextID, boost::is_any_of(";"), boost::token_compress_on);
            
            for( std::vector<std::string>::iterator ctxIt= snapshotContextIDs.begin(); ctxIt!= snapshotContextIDs.end(); ctxIt++){
              std::vector<std::string> ctxStrs;
              boost::split(ctxStrs, *ctxIt, boost::is_any_of(":]"), boost::token_compress_on);
              
              std::vector<std::string> ctxStr0;
              boost::split(ctxStr0, ctxStrs[0], boost::is_any_of("[,]") );
              if( ctxStr0[0] == "R" ){
                
                __R__Context* parentContext0 = &(this -> R [ boost::lexical_cast<int>( ctxStr0[1] ) ] );
                sobj = dynamic_cast<mace::Serializable*>(parentContext0);
                
                std::vector<std::string> ctxStr1;
                boost::split(ctxStr1, ctxStrs[0], boost::is_any_of("[,]") );
                if( ctxStr1[0] == "C" ){
                  
                  __C__Context* parentContext1 = &(parentContext0 -> C [ boost::lexical_cast<int>( ctxStr1[1] ) ] );
                  sobj = dynamic_cast<mace::Serializable*>(parentContext1);
                  
                  std::vector<std::string> ctxStr2;
                  boost::split(ctxStr2, ctxStrs[1], boost::is_any_of("[,]") );
                  if( ctxStr2[0] == "X" ){
                    
                    __X__Context* parentContext2 = &(parentContext1 -> X [ boost::lexical_cast<int>( ctxStr2[1] ) ] );
                    sobj = dynamic_cast<mace::Serializable*>(parentContext2);
                    
                    
                  }
                  
                }
                
              }
              else if( ctxStr0[0] == "T" ){
                
                __T__Context* parentContext0 = &(this -> T );
                sobj = dynamic_cast<mace::Serializable*>(parentContext0);
                
                
              }
              else if( ctxStr0[0] == "M" ){
                uint32_t param1 = boost::lexical_cast<uint32_t>( ctxStr0[1] );
                mace::string param2 = boost::lexical_cast<mace::string>( ctxStr0[2] );
                __M__Context* parentContext0 = &(this -> M [ __M__Context__param (param1,param2) ] );
                sobj = dynamic_cast<mace::Serializable*>(parentContext0);
                
                
              }
              
            }
            return sobj;
            
          }
          mace::string SimpleService::getStartContext(mace::vector<mace::string>& allContextIDs)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          {
            
            // find the longest common prefix
            // Notice that this only works for tree but not DAG hierarchy.
            if( allContextIDs.size() == 0 )
            return mace::string("");
            
            size_t pos = 0;
            bool sameChar = true;
            do{
              char compChar;
              if( allContextIDs[0].size() > pos ){
                compChar = allContextIDs[0][pos];
              }else{
                break;
              }
              for( mace::vector<mace::string>::iterator it = allContextIDs.begin(); it != allContextIDs.end(); it++ ){
                if( it->size() < pos ){
                  sameChar = false;
                  break;
                }else if( (*it)[pos] != compChar ){
                  sameChar = false;
                  break;
                }
              }
              if( sameChar )
              pos++;
            }while( sameChar == true );
            
            return allContextIDs[0].substr(0, pos);
            
            
          }
          mace::string SimpleService::snapshot_sync_fn(mace::string srcContextID, mace::string snapshotContextID)
          // Method.pm:toString().
          // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
          // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
          
          
          
          
          {
            mace::string ctxSnapshot;
            
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
            
            const MaceKey& destNode = ContextMapping::getNodeByContext(snapshotContextID);
            if(destNode == downcall_localAddress()){
              sl.unlock();
              ThreadStructure::pushContext(snapshotContextID);
              
              Serializable* sobj = findContextByID(snapshotContextID);
              mace::serialize( ctxSnapshot, sobj );
              
              ThreadStructure::popContext();
              return ctxSnapshot;
            }
            mace::string currentContextID = ThreadStructure::getCurrentContext();
            mace::string contextSnapshot;
            
            uint32_t msgseqno = 0;
            if(__internal_msgseqno.find(snapshotContextID) == __internal_msgseqno.end()){
              msgseqno = 1;
              __internal_msgseqno[snapshotContextID] = msgseqno;
            }else{
              msgseqno = ++__internal_msgseqno[snapshotContextID];
            }
            __sync_at_snapshot pcopy(srcContextID, snapshotContextID, contextSnapshot, msgseqno);
            mace::string buf;
            mace::serialize(buf,  &pcopy);
            __internal_unAck[snapshotContextID][msgseqno] = buf; //pcopy;
            
            
            if( mutexMapping.find(currentContextID) == mutexMapping.end() ){
              pthread_mutex_t contextMutex;
              mutexMapping[currentContextID] = contextMutex;
            }
            std::map<mace::string,  pthread_mutex_t>::iterator mutex_iter = mutexMapping.find(currentContextID);
            pthread_mutex_t contextMutex = mutex_iter->second;
            sl.unlock();
            downcall_route( destNode, pcopy );
            pthread_mutex_lock(&contextMutex);
            
            sl.lock();
            mace::map<mace::string,  mace::string>::iterator ctxSnapshot_iter = returnValueMapping.find(currentContextID);
            if(ctxSnapshot_iter == returnValueMapping.end()){
              sl.unlock();
              return ctxSnapshot;
            }else{
              std::istringstream in(ctxSnapshot_iter->second);
              mace::deserialize(in,  &ctxSnapshot);
              sl.unlock();
              return ctxSnapshot;
            }
          }
          
          //Serial Helper Demux
          //BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux
          void SimpleService::deliver(
              #line 19 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& source
#line 14129 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& destination
#line 14133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 20 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const std::string& s
#line 14137 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveDataHandler.h"
              registration_uid_t rid
#line 14141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_deliver_demux_48
            #define selectorId selectorId_deliver_demux_48
            ADD_LOG_BACKING
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            
            //TODO: try/catch Serialize
            
            uint8_t msgNum_s = Message::getType(s);
            //TODO -- trace num
            
            switch(msgNum_s) {
              
              case __internal_Ack::messageType: {
                __internal_Ack s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case ContextMigrationRequest::messageType: {
                ContextMigrationRequest s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case TransferContext::messageType: {
                TransferContext s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case ReportContextMigration::messageType: {
                ReportContextMigration s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case ContextMappingUpdate::messageType: {
                ContextMappingUpdate s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case HeadEvent::messageType: {
                HeadEvent s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __async_at2_rowInit::messageType: {
                __async_at2_rowInit s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_async_at2_rowInit::messageType: {
                __target_async_at2_rowInit s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __async_at4_rowAfter::messageType: {
                __async_at4_rowAfter s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_async_at4_rowAfter::messageType: {
                __target_async_at4_rowAfter s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __async_at8_testMulti::messageType: {
                __async_at8_testMulti s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_async_at8_testMulti::messageType: {
                __target_async_at8_testMulti s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __sync_at1_sctest::messageType: {
                __sync_at1_sctest s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at1_sctest::messageType: {
                __target_sync_at1_sctest s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __sync_at3_cellInit::messageType: {
                __sync_at3_cellInit s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at3_cellInit::messageType: {
                __target_sync_at3_cellInit s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __sync_at5_testRCX::messageType: {
                __sync_at5_testRCX s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at5_testRCX::messageType: {
                __target_sync_at5_testRCX s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              
              case __sync_at_snapshot::messageType: {
                __sync_at_snapshot s_deserialized;
                s_deserialized.deserializeStr(s);
                //TODO -- trace msg
                
                deliver(source,destination,s_deserialized,rid);
                
              }
              break;
              default: {
                maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
                
                #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveDataHandler.mh"
                { }
#line 14360 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                
                ABORT("INVALID MESSAGE NUMBER");
              }
              break;
            }
            
            #undef selector
            #undef selectorId
            
          }
          void SimpleService::messageError(
              #line 22 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const MaceKey& dest
#line 14374 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              TransportError::type errorCode
#line 14378 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              const std::string& message
#line 14382 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
              ,
              #line 24 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
              registration_uid_t rid
#line 14386 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
          ) {
            // Method.pm:toString()
            
            __eventContextType = -1;
            
            // Method.pm:toString().
            // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
            // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().
            
            
            #define selector selector_messageError_demux_49
            #define selectorId selectorId_messageError_demux_49
            ADD_LOG_BACKING
            
            ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true && mace::LogicalClock::instance().shouldLogPath(), PIP);
            
            
            //TODO: try/catch Serialize
            
            uint8_t msgNum_message = Message::getType(message);
            //TODO -- trace num
            
            switch(msgNum_message) {
              
              case __internal_Ack::messageType: {
                __internal_Ack message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case ContextMigrationRequest::messageType: {
                ContextMigrationRequest message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case TransferContext::messageType: {
                TransferContext message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case ReportContextMigration::messageType: {
                ReportContextMigration message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case ContextMappingUpdate::messageType: {
                ContextMappingUpdate message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case HeadEvent::messageType: {
                HeadEvent message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __async_at2_rowInit::messageType: {
                __async_at2_rowInit message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_async_at2_rowInit::messageType: {
                __target_async_at2_rowInit message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __async_at4_rowAfter::messageType: {
                __async_at4_rowAfter message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_async_at4_rowAfter::messageType: {
                __target_async_at4_rowAfter message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __async_at8_testMulti::messageType: {
                __async_at8_testMulti message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_async_at8_testMulti::messageType: {
                __target_async_at8_testMulti message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __sync_at1_sctest::messageType: {
                __sync_at1_sctest message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at1_sctest::messageType: {
                __target_sync_at1_sctest message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __sync_at3_cellInit::messageType: {
                __sync_at3_cellInit message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at3_cellInit::messageType: {
                __target_sync_at3_cellInit message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __sync_at5_testRCX::messageType: {
                __sync_at5_testRCX message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __target_sync_at5_testRCX::messageType: {
                __target_sync_at5_testRCX message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              
              case __sync_at_snapshot::messageType: {
                __sync_at_snapshot message_deserialized;
                message_deserialized.deserializeStr(message);
                //TODO -- trace msg
                
                messageError(dest,errorCode,message_deserialized,rid);
                
              }
              break;
              default: {
                maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
                
                #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/NetworkErrorHandler.mh"
                { }
#line 14605 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple.cc"
                
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
