/*********************************************
*  TreeServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _TREESERVICECLASS_H
#define _TREESERVICECLASS_H
#include "ServiceClass.h"
#include "TreeStructureHandler.h"


class TreeServiceClass : public virtual ServiceClass {
  public:
  static TreeServiceClass& NULL_;
  static const char* name; // = "Tree";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  virtual bool isMember(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
      const MaceKey& groupId
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
      , registration_uid_t rid = -1) const
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  { return false; }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  virtual bool isRoot(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
      const MaceKey& groupId
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
      , registration_uid_t rid = -1) const
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  { return false; }
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  virtual MaceKey getParent(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
      const MaceKey& groupId
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getParent in base class TreeServiceClass called."); }
#line 48 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
  virtual  const NodeSet& getChildren(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TreeServiceClass.mh"
      const MaceKey& groupId
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getChildren in base class TreeServiceClass called."); }
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TreeServiceClass.h"
  virtual registration_uid_t registerHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(TreeStructureHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(TreeStructureHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~TreeServiceClass() { }
};

#endif // _TREESERVICECLASS_H
