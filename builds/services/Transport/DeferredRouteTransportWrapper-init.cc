/*********************************************
*  DeferredRouteTransportWrapper init source file
*  Mace generated on:
*  Tue Apr 10 10:09:47 2012
*********************************************/
#include "DeferredRouteTransportWrapper-init.h"
#include "params.h"
#include "ServiceConfig.h"
#include "TcpTransport-init.h"
namespace DeferredRouteTransportWrapper_namespace {
  RouteServiceClass& real_new_DeferredRouteTransportWrapper_Route(TransportServiceClass& trans, bool ___shared);
  RouteServiceClass& new_DeferredRouteTransportWrapper_Route(TransportServiceClass& _trans) {
    
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 19 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    : _trans;
    
#line 22 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    return real_new_DeferredRouteTransportWrapper_Route(trans, 1);
  }
  RouteServiceClass& private_new_DeferredRouteTransportWrapper_Route(TransportServiceClass& _trans) {
    
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    : _trans;
    
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    return real_new_DeferredRouteTransportWrapper_Route(trans, 0);
  }
  RouteServiceClass& configure_new_DeferredRouteTransportWrapper_Route(bool ___shared) {
    if (___shared) { return new_DeferredRouteTransportWrapper_Route(); }
    else { return private_new_DeferredRouteTransportWrapper_Route(); }
  }
  TransportServiceClass& real_new_DeferredRouteTransportWrapper_Transport(TransportServiceClass& trans, bool ___shared);
  TransportServiceClass& new_DeferredRouteTransportWrapper_Transport(TransportServiceClass& _trans) {
    
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 48 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    : _trans;
    
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    return real_new_DeferredRouteTransportWrapper_Transport(trans, 1);
  }
  TransportServiceClass& private_new_DeferredRouteTransportWrapper_Transport(TransportServiceClass& _trans) {
    
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 12 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/DeferredRouteTransportWrapper.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    : _trans;
    
#line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/DeferredRouteTransportWrapper-init.cc"
    return real_new_DeferredRouteTransportWrapper_Transport(trans, 0);
  }
  TransportServiceClass& configure_new_DeferredRouteTransportWrapper_Transport(bool ___shared) {
    if (___shared) { return new_DeferredRouteTransportWrapper_Transport(); }
    else { return private_new_DeferredRouteTransportWrapper_Transport(); }
  }
} //end namespace
