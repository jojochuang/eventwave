/*********************************************
*  MaceTransport init source file
*  Mace generated on:
*  Tue Apr 10 10:09:55 2012
*********************************************/
#include "MaceTransport-init.h"
#include "params.h"
#include "ServiceConfig.h"
namespace MaceTransport_namespace {
  BufferedTransportServiceClass& real_new_MaceTransport_BufferedTransport(TransportServiceClass& router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 14 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 18 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 22 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , bool ___shared);
  BufferedTransportServiceClass& new_MaceTransport_BufferedTransport(TransportServiceClass& _router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
  ) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_BufferedTransport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  BufferedTransportServiceClass& private_new_MaceTransport_BufferedTransport(TransportServiceClass& _router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
  ) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 67 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_BufferedTransport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  BufferedTransportServiceClass& new_MaceTransport_BufferedTransport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , TransportServiceClass& _router) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 86 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_BufferedTransport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  BufferedTransportServiceClass& private_new_MaceTransport_BufferedTransport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 96 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , TransportServiceClass& _router) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_BufferedTransport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  BufferedTransportServiceClass& configure_new_MaceTransport_BufferedTransport(bool ___shared) {
    if (___shared) { return new_MaceTransport_BufferedTransport(); }
    else { return private_new_MaceTransport_BufferedTransport(); }
  }
  TransportServiceClass& real_new_MaceTransport_Transport(TransportServiceClass& router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 115 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 119 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , bool ___shared);
  TransportServiceClass& new_MaceTransport_Transport(TransportServiceClass& _router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 128 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 132 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
  ) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 145 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_Transport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  TransportServiceClass& private_new_MaceTransport_Transport(TransportServiceClass& _router,
      #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      bool const  UPCALL_MESSAGE_ERROR
#line 151 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 155 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 159 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
  ) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_Transport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  TransportServiceClass& new_MaceTransport_Transport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 174 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , TransportServiceClass& _router) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 187 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_Transport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  TransportServiceClass& private_new_MaceTransport_Transport(bool const  UPCALL_MESSAGE_ERROR,
      #line 91 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  maxQueueSize
#line 193 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      ,
      #line 92 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
      size_t const  queueThresholdArg
#line 197 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
      , TransportServiceClass& _router) {
    
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    TransportServiceClass& router = (&_router == &TransportServiceClass::NULL_) ?
    #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/MaceTransport.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("MaceTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("lowlatency", ","),!1)
    : _router;
    
#line 206 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/MaceTransport-init.cc"
    return real_new_MaceTransport_Transport(router, (UPCALL_MESSAGE_ERROR == false ? mace::ServiceConfig<void*>::get<bool>("MaceTransport.UPCALL_MESSAGE_ERROR", UPCALL_MESSAGE_ERROR) : UPCALL_MESSAGE_ERROR), (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<size_t>("MaceTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  TransportServiceClass& configure_new_MaceTransport_Transport(bool ___shared) {
    if (___shared) { return new_MaceTransport_Transport(); }
    else { return private_new_MaceTransport_Transport(); }
  }
} //end namespace
