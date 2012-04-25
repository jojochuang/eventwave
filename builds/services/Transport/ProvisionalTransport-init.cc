/*********************************************
*  ProvisionalTransport init source file
*  Mace generated on:
*  Tue Apr 10 10:09:49 2012
*********************************************/
#include "ProvisionalTransport-init.h"
#include "params.h"
#include "ServiceConfig.h"
namespace ProvisionalTransport_namespace {
  BufferedTransportServiceClass& real_new_ProvisionalTransport_BufferedTransport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 14 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 18 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , bool ___shared);
  BufferedTransportServiceClass& new_ProvisionalTransport_BufferedTransport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 23 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_BufferedTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  BufferedTransportServiceClass& private_new_ProvisionalTransport_BufferedTransport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_BufferedTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  BufferedTransportServiceClass& new_ProvisionalTransport_BufferedTransport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_BufferedTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  BufferedTransportServiceClass& private_new_ProvisionalTransport_BufferedTransport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 76 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 85 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_BufferedTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  BufferedTransportServiceClass& configure_new_ProvisionalTransport_BufferedTransport(bool ___shared) {
    if (___shared) { return new_ProvisionalTransport_BufferedTransport(); }
    else { return private_new_ProvisionalTransport_BufferedTransport(); }
  }
  ProvisionalTransportServiceClass& real_new_ProvisionalTransport_ProvisionalTransport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 95 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 99 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , bool ___shared);
  ProvisionalTransportServiceClass& new_ProvisionalTransport_ProvisionalTransport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 108 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 117 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_ProvisionalTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  ProvisionalTransportServiceClass& private_new_ProvisionalTransport_ProvisionalTransport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 123 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 136 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_ProvisionalTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  ProvisionalTransportServiceClass& new_ProvisionalTransport_ProvisionalTransport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 142 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 151 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_ProvisionalTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  ProvisionalTransportServiceClass& private_new_ProvisionalTransport_ProvisionalTransport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 166 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_ProvisionalTransport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  ProvisionalTransportServiceClass& configure_new_ProvisionalTransport_ProvisionalTransport(bool ___shared) {
    if (___shared) { return new_ProvisionalTransport_ProvisionalTransport(); }
    else { return private_new_ProvisionalTransport_ProvisionalTransport(); }
  }
  TransportServiceClass& real_new_ProvisionalTransport_Transport(BufferedTransportServiceClass& router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 180 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , bool ___shared);
  TransportServiceClass& new_ProvisionalTransport_Transport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 185 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 189 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 198 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_Transport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  TransportServiceClass& private_new_ProvisionalTransport_Transport(BufferedTransportServiceClass& _router,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  maxQueueSize
#line 204 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      ,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 208 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
  ) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 217 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_Transport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  TransportServiceClass& new_ProvisionalTransport_Transport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 223 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 232 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_Transport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 1);
  }
  TransportServiceClass& private_new_ProvisionalTransport_Transport(uint32_t const  maxQueueSize,
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
      uint32_t const  queueThresholdArg
#line 238 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
      , BufferedTransportServiceClass& _router) {
    
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    BufferedTransportServiceClass& router = (&_router == &BufferedTransportServiceClass::NULL_) ?
    #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/ProvisionalTransport.mac"
    mace::ServiceConfig<BufferedTransportServiceClass>::configure("ProvisionalTransport.router",mace::makeStringSet("", ","),mace::makeStringSet("", ","),!1)
    : _router;
    
#line 247 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/ProvisionalTransport-init.cc"
    return real_new_ProvisionalTransport_Transport(router, (maxQueueSize == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.maxQueueSize", maxQueueSize) : maxQueueSize), (queueThresholdArg == UINT_MAX ? mace::ServiceConfig<void*>::get<uint32_t>("ProvisionalTransport.queueThresholdArg", queueThresholdArg) : queueThresholdArg), 0);
  }
  TransportServiceClass& configure_new_ProvisionalTransport_Transport(bool ___shared) {
    if (___shared) { return new_ProvisionalTransport_Transport(); }
    else { return private_new_ProvisionalTransport_Transport(); }
  }
} //end namespace
