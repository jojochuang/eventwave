/*********************************************
*  Simple init declaration file
*  Mace generated on:
*  Tue Apr 10 10:10:29 2012
*********************************************/
#ifndef Simple_init_h
#define Simple_init_h

#include "Simple-constants.h"
//BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
#line 1 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
#include "boost/format.hpp"
#include <sstream>
#include <math.h>
#line 16 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"

//END: Mace::Compiler::ServiceImpl::printIncludeBufH
#include "NullServiceClass.h"
#include "TransportServiceClass.h"

namespace Simple_namespace {
  NullServiceClass& new_Simple_Null(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      TransportServiceClass& tcp = TransportServiceClass::NULL_
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  ROWS = DEFAULT_ROWS
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS = DEFAULT_COLUMNS
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS = DEFAULT_ROWS
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS = DEFAULT_COLUMNS
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
  );
  NullServiceClass& private_new_Simple_Null(
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      TransportServiceClass& tcp = TransportServiceClass::NULL_
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 29 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  ROWS = DEFAULT_ROWS
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS = DEFAULT_COLUMNS
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS = DEFAULT_ROWS
#line 59 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS = DEFAULT_COLUMNS
#line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
  );
  NullServiceClass& new_Simple_Null(int32_t const  ROWS,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS = DEFAULT_COLUMNS
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS = DEFAULT_ROWS
#line 72 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS = DEFAULT_COLUMNS
#line 76 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      TransportServiceClass& tcp = TransportServiceClass::NULL_
#line 80 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
  );
  NullServiceClass& private_new_Simple_Null(int32_t const  ROWS,
      #line 30 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  COLUMNS = DEFAULT_COLUMNS
#line 85 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXROWS = DEFAULT_ROWS
#line 89 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      int32_t const  MATRIXCOLUMNS = DEFAULT_COLUMNS
#line 93 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
      ,
      #line 11 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple/Simple.mac"
      TransportServiceClass& tcp = TransportServiceClass::NULL_
#line 97 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/Simple-init.h"
  );
} //end namespace
#endif // Simple_init_h
