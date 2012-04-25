#ifndef __LOAD_PROTOCOLS_H_
#define __LOAD_PROTOCOLS_H_


namespace GenericTreeMulticast_namespace {
void load_protocol();
} 
namespace RouteTransportWrapper_namespace {
void load_protocol();
} 
namespace RandTree_namespace {
void load_protocol();
} 
namespace TcpTransport_namespace {
void load_protocol();
} 

void load_protocols() { 
      GenericTreeMulticast_namespace::load_protocol();
      RouteTransportWrapper_namespace::load_protocol();
      RandTree_namespace::load_protocol();
      TcpTransport_namespace::load_protocol(); 
} 

#endif //__LOAD_PROTOCOLS_H_
