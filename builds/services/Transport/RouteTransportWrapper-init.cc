/*********************************************
*  RouteTransportWrapper init source file
*  Mace generated on:
*  Tue Apr 10 10:09:47 2012
*********************************************/
#include "RouteTransportWrapper-init.h"
#include "params.h"
#include "ServiceConfig.h"
namespace RouteTransportWrapper_namespace {
  RouteServiceClass& real_new_RouteTransportWrapper_Route(TransportServiceClass& trans, bool ___shared);
  RouteServiceClass& new_RouteTransportWrapper_Route(TransportServiceClass& _trans) {
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("RouteTransportWrapper.trans",mace::makeStringSet("", ","),mace::makeStringSet("TcpTransport", ","),!1)
    : _trans;
    
#line 20 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper-init.cc"
    return real_new_RouteTransportWrapper_Route(trans, 1);
  }
  RouteServiceClass& private_new_RouteTransportWrapper_Route(TransportServiceClass& _trans) {
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("RouteTransportWrapper.trans",mace::makeStringSet("", ","),mace::makeStringSet("TcpTransport", ","),!1)
    : _trans;
    
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper-init.cc"
    return real_new_RouteTransportWrapper_Route(trans, 0);
  }
  RouteServiceClass& configure_new_RouteTransportWrapper_Route(bool ___shared) {
    if (___shared) { return new_RouteTransportWrapper_Route(); }
    else { return private_new_RouteTransportWrapper_Route(); }
  }
  TransportServiceClass& real_new_RouteTransportWrapper_Transport(TransportServiceClass& trans, bool ___shared);
  TransportServiceClass& new_RouteTransportWrapper_Transport(TransportServiceClass& _trans) {
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("RouteTransportWrapper.trans",mace::makeStringSet("", ","),mace::makeStringSet("TcpTransport", ","),!1)
    : _trans;
    
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper-init.cc"
    return real_new_RouteTransportWrapper_Transport(trans, 1);
  }
  TransportServiceClass& private_new_RouteTransportWrapper_Transport(TransportServiceClass& _trans) {
    
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    TransportServiceClass& trans = (&_trans == &TransportServiceClass::NULL_) ?
    #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport/RouteTransportWrapper.mac"
    mace::ServiceConfig<TransportServiceClass>::configure("RouteTransportWrapper.trans",mace::makeStringSet("", ","),mace::makeStringSet("TcpTransport", ","),!1)
    : _trans;
    
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/RouteTransportWrapper-init.cc"
    return real_new_RouteTransportWrapper_Transport(trans, 0);
  }
  TransportServiceClass& configure_new_RouteTransportWrapper_Transport(bool ___shared) {
    if (___shared) { return new_RouteTransportWrapper_Transport(); }
    else { return private_new_RouteTransportWrapper_Transport(); }
  }
} //end namespace
