/*********************************************
*  ForwardDataHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:08 2012
*********************************************/
#ifndef _FORWARDDATAHANDLER_H
#define _FORWARDDATAHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mace_constants.h"
class ForwardDataHandler  {
  public:
  static ForwardDataHandler& NULL_;
  static const char* name; // = "ForwardData";
  
  
  
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
  virtual bool forward(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& source
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const MaceKey& destination
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      MaceKey& nextHop
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
      const std::string& s
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ForwardDataHandler.mh"
  { return true; }
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
  
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ForwardDataHandler.h"
  virtual ~ForwardDataHandler() { }
};

#endif // _FORWARDDATAHANDLER_H
