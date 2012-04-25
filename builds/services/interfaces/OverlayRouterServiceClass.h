/*********************************************
*  OverlayRouterServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _OVERLAYROUTERSERVICECLASS_H
#define _OVERLAYROUTERSERVICECLASS_H
#include "OverlayServiceClass.h"
#include "ServiceClass.h"
#include "OverlayStructureHandler.h"


class OverlayRouterServiceClass : public virtual OverlayServiceClass, public virtual ServiceClass {
  public:
  static OverlayRouterServiceClass& NULL_;
  static const char* name; // = "OverlayRouter";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual bool idSpaceContains(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      const MaceKey& id
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      , registration_uid_t rid = -1)
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  { return false; }
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual NodeSet getSuccessors(registration_uid_t rid = -1) { ABORT("Unimplemented method getSuccessors in base class OverlayRouterServiceClass called."); }
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual KeyRange getIdSpace(registration_uid_t rid = -1) { ABORT("Unimplemented method getIdSpace in base class OverlayRouterServiceClass called."); }
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual MaceKey getNextHop(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      const MaceKey& dest
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getNextHop in base class OverlayRouterServiceClass called."); }
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual MaceKey getNextHop(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      const MaceKey& dest
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      MaceKey& overlayId
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getNextHop in base class OverlayRouterServiceClass called."); }
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  virtual void checkNode(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      const MaceKey& dest
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
      const MaceKey& overlayId
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
      , registration_uid_t rid = -1)
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayRouterServiceClass.mh"
  { }
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayRouterServiceClass.h"
  virtual registration_uid_t registerHandler(OverlayStructureHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(OverlayStructureHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(OverlayStructureHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(OverlayStructureHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(OverlayJoinHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(OverlayJoinHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(OverlayJoinHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(OverlayJoinHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~OverlayRouterServiceClass() { }
};

#endif // _OVERLAYROUTERSERVICECLASS_H
