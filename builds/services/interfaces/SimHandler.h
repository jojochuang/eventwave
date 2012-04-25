/*********************************************
*  SimHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:23 2012
*********************************************/
#ifndef _SIMHANDLER_H
#define _SIMHANDLER_H
#include "massert.h"
#include "MaceTypes.h"


class SimHandler  {
  public:
  static SimHandler& NULL_;
  static const char* name; // = "Sim";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual int getNodeNumber(registration_uid_t rid = -1) const { ABORT("Unimplemented method getNodeNumber in base class SimHandler called."); }
#line 22 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual int getNodeCount(registration_uid_t rid = -1) const { ABORT("Unimplemented method getNodeCount in base class SimHandler called."); }
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual int getIncarnationNumber(registration_uid_t rid = -1) const { ABORT("Unimplemented method getIncarnationNumber in base class SimHandler called."); }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual  const MaceKey& getMaceKey(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
      int nodeNum
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getMaceKey in base class SimHandler called."); }
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual int getNodeNumber(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
      const MaceKey& node
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getNodeNumber in base class SimHandler called."); }
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/SimHandler.mh"
  virtual unsigned getStep(registration_uid_t rid = -1) const { ABORT("Unimplemented method getStep in base class SimHandler called."); }
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/SimHandler.h"
  virtual ~SimHandler() { }
};

#endif // _SIMHANDLER_H
