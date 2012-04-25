/*********************************************
*  TreeMaintenanceServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _TREEMAINTENANCESERVICECLASS_H
#define _TREEMAINTENANCESERVICECLASS_H
#include "TreeServiceClass.h"
#include "ServiceClass.h"


class TreeMaintenanceServiceClass : public virtual TreeServiceClass, public virtual ServiceClass {
  public:
  static TreeMaintenanceServiceClass& NULL_;
  static const char* name; // = "TreeMaintenance";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeMaintenanceServiceClass.mh"
  void migrate(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeMaintenanceServiceClass.mh"
      const MaceKey& newParent
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeMaintenanceServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method migrate in base class TreeMaintenanceServiceClass called."); }
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeMaintenanceServiceClass.h"
  virtual registration_uid_t registerHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(TreeStructureHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(TreeStructureHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~TreeMaintenanceServiceClass() { }
};

#endif // _TREEMAINTENANCESERVICECLASS_H
