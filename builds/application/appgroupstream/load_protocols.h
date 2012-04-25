#ifndef __LOAD_PROTOCOLS_H_
#define __LOAD_PROTOCOLS_H_


namespace Bamboo_namespace {
void load_protocol();
} 
namespace ReplayTree_namespace {
void load_protocol();
} 
namespace RandTree_namespace {
void load_protocol();
} 
namespace GenericTreeMulticast_namespace {
void load_protocol();
} 
namespace SignedMulticast_namespace {
void load_protocol();
} 
namespace Pastry_namespace {
void load_protocol();
} 
namespace Scribe_namespace {
void load_protocol();
} 
namespace CacheRecursiveOverlayRoute_namespace {
void load_protocol();
} 
namespace TcpTransport_namespace {
void load_protocol();
} 
namespace UdpTransport_namespace {
void load_protocol();
} 

void load_protocols() { 
      Bamboo_namespace::load_protocol();
      ReplayTree_namespace::load_protocol();
      RandTree_namespace::load_protocol();
      GenericTreeMulticast_namespace::load_protocol();
      SignedMulticast_namespace::load_protocol();
      Pastry_namespace::load_protocol();
      Scribe_namespace::load_protocol();
      CacheRecursiveOverlayRoute_namespace::load_protocol();
      TcpTransport_namespace::load_protocol();
      UdpTransport_namespace::load_protocol(); 
} 

#endif //__LOAD_PROTOCOLS_H_
