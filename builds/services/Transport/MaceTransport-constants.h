/*********************************************
*  MaceTransport constants header file
*  Mace generated on:
*  Tue Apr 10 10:09:55 2012
*********************************************/
#ifndef MaceTransport_constants_h
#define MaceTransport_constants_h

#include "MaceBasics.h"


namespace MaceTransport_namespace {
  //BEGIN: Mace::Compiler::ServiceImpl::printConstantsH
  static const
  #line 67 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  int64_t INIT_RTO = 1*1000*1000
#line 18 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 68 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  int64_t MAX_RTO = 3*1000*1000
#line 23 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 69 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  int64_t MIN_RTO = 15000
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 70 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  int64_t BW_STATS_PERIOD = 5*1000*1000
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 71 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  double MAX_WND = 1000.0*1000.0
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  uint16_t FAST_RETRANSMIT_DUP = 3
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  uint16_t FAST_RESET_DUP = 3
#line 48 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t TRANSPORT_HEADER_SIZE = (12+12+4+1+4)
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t UDP_MAX_MESSAGE_SIZE = (1500-64-TRANSPORT_HEADER_SIZE)
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t DATA_HEADER_SIZE = (4+4+8+8+4)
#line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t MAX_DATA_MESSAGE_SIZE = UDP_MAX_MESSAGE_SIZE-DATA_HEADER_SIZE
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t MAX_DATA_FRAGMENT_MESSAGE_SIZE = UDP_MAX_MESSAGE_SIZE-DATA_HEADER_SIZE-4
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  size_t MAX_FRAGMENT_MESSAGE_SIZE = (UDP_MAX_MESSAGE_SIZE-4-4-4)
#line 78 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  static const
  #line 86 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
  uint64_t DEFAULT_WINDOW_SIZE = 5*1000*1000
#line 83 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-constants.h"
  ;
  //END: Mace::Compiler::ServiceImpl::printConstantsH
  
} //end namespace MaceTransport_namespace

#endif // MaceTransport_constants_h
