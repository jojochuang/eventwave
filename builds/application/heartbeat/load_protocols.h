#ifndef __LOAD_PROTOCOLS_H_
#define __LOAD_PROTOCOLS_H_


namespace CondorHeartBeat_namespace {
void load_protocol();
} 
namespace TcpTransport_namespace {
void load_protocol();
} 

void load_protocols() { 
      CondorHeartBeat_namespace::load_protocol();
      TcpTransport_namespace::load_protocol(); 
} 

#endif //__LOAD_PROTOCOLS_H_
