/*********************************************
*  MaceTransport init declaration file
*  Mace generated on:
*  Tue Apr 10 10:09:55 2012
*********************************************/
#ifndef MaceTransport_init_h
#define MaceTransport_init_h

#include "MaceTransport-constants.h"
//BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
#line 31 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
#include <boost/shared_ptr.hpp>
#include "NodeCollection.h"
#include "UdpTransport.h"
#include "MaceTime.h"
#line 17 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
#include "BufferedTransportServiceClass.h"
#include "TransportServiceClass.h"
#include "TransportServiceClass.h"

namespace MaceTransport_namespace {
  BufferedTransportServiceClass& new_MaceTransport_BufferedTransport(
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR = false
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  BufferedTransportServiceClass& private_new_MaceTransport_BufferedTransport(
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR = false
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  BufferedTransportServiceClass& new_MaceTransport_BufferedTransport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 62 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  BufferedTransportServiceClass& private_new_MaceTransport_BufferedTransport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 75 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 79 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 83 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  TransportServiceClass& new_MaceTransport_Transport(
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 88 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR = false
#line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 96 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 100 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  TransportServiceClass& private_new_MaceTransport_Transport(
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR = false
#line 109 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 113 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 117 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  TransportServiceClass& new_MaceTransport_Transport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 126 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 130 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
  TransportServiceClass& private_new_MaceTransport_Transport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize = UINT_MAX
#line 135 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg = UINT_MAX
#line 139 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      TransportServiceClass& router = TransportServiceClass::NULL_
#line 143 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.h"
  );
} //end namespace
#endif // MaceTransport_init_h
