/*********************************************
*  Simple init source file
*  Mace generated on:
*  Tue Apr 10 10:10:29 2012
*********************************************/
#include "Simple-init.h"
#include "params.h"
#include "ServiceConfig.h"
#include "TcpTransport-init.h"
namespace Simple_namespace {
  NullServiceClass& real_new_Simple_Null(TransportServiceClass& tcp,
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  ROWS
#line 15 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS
#line 19 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS
#line 23 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      , bool ___shared);
  NullServiceClass& new_Simple_Null(TransportServiceClass& _tcp,
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  ROWS
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
  ) {
    
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TransportServiceClass& tcp = (&_tcp == &TransportServiceClass::NULL_) ?
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    : _tcp;
    
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    return real_new_Simple_Null(tcp, (ROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.ROWS", ROWS) : ROWS), (COLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.COLUMNS", COLUMNS) : COLUMNS), (MATRIXROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXROWS", MATRIXROWS) : MATRIXROWS), (MATRIXCOLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXCOLUMNS", MATRIXCOLUMNS) : MATRIXCOLUMNS), 1);
  }
  NullServiceClass& private_new_Simple_Null(TransportServiceClass& _tcp,
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  ROWS
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS
#line 72 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
  ) {
    
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TransportServiceClass& tcp = (&_tcp == &TransportServiceClass::NULL_) ?
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 79 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    : _tcp;
    
#line 82 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    return real_new_Simple_Null(tcp, (ROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.ROWS", ROWS) : ROWS), (COLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.COLUMNS", COLUMNS) : COLUMNS), (MATRIXROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXROWS", MATRIXROWS) : MATRIXROWS), (MATRIXCOLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXCOLUMNS", MATRIXCOLUMNS) : MATRIXCOLUMNS), 0);
  }
  NullServiceClass& new_Simple_Null(int32_t const  ROWS,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS
#line 88 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS
#line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS
#line 96 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      , TransportServiceClass& _tcp) {
    
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TransportServiceClass& tcp = (&_tcp == &TransportServiceClass::NULL_) ?
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 103 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    : _tcp;
    
#line 106 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    return real_new_Simple_Null(tcp, (ROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.ROWS", ROWS) : ROWS), (COLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.COLUMNS", COLUMNS) : COLUMNS), (MATRIXROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXROWS", MATRIXROWS) : MATRIXROWS), (MATRIXCOLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXCOLUMNS", MATRIXCOLUMNS) : MATRIXCOLUMNS), 1);
  }
  NullServiceClass& private_new_Simple_Null(int32_t const  ROWS,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS
#line 112 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS
#line 116 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS
#line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
      , TransportServiceClass& _tcp) {
    
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TransportServiceClass& tcp = (&_tcp == &TransportServiceClass::NULL_) ?
    #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
    TcpTransport_namespace::new_TcpTransport_Transport()
#line 127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    : _tcp;
    
#line 130 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.cc"
    return real_new_Simple_Null(tcp, (ROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.ROWS", ROWS) : ROWS), (COLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.COLUMNS", COLUMNS) : COLUMNS), (MATRIXROWS == DEFAULT_ROWS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXROWS", MATRIXROWS) : MATRIXROWS), (MATRIXCOLUMNS == DEFAULT_COLUMNS ? mace::ServiceConfig<void*>::get<int32_t>("Simple.MATRIXCOLUMNS", MATRIXCOLUMNS) : MATRIXCOLUMNS), 0);
  }
  NullServiceClass& configure_new_Simple_Null(bool ___shared) {
    if (___shared) { return new_Simple_Null(); }
    else { return private_new_Simple_Null(); }
  }
} //end namespace
