#ifndef __LOAD_PROTOCOLS_H_
#define __LOAD_PROTOCOLS_H_


namespace DHT_namespace {
void load_protocol();
} 
namespace Pastry_namespace {
void load_protocol();
} 
namespace TcpTransport_namespace {
void load_protocol();
} 

void load_protocols() { 
      DHT_namespace::load_protocol();
      Pastry_namespace::load_protocol();
      TcpTransport_namespace::load_protocol(); 
} 

#endif //__LOAD_PROTOCOLS_H_
