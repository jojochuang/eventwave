/*********************************************
*  ScribeTreeServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _SCRIBETREESERVICECLASS_H
#define _SCRIBETREESERVICECLASS_H
#include "TreeServiceClass.h"
#include "GroupServiceClass.h"
#include "ServiceClass.h"
#include "ScribeTreeHandler.h"


class ScribeTreeServiceClass : public virtual TreeServiceClass, public virtual GroupServiceClass, public virtual ServiceClass {
  public:
  static ScribeTreeServiceClass& NULL_;
  static const char* name; // = "ScribeTree";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
  virtual int addChild(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
      const MaceKey& groupId
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
      const MaceKey& childId
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
      int joinSeq = 0
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
      , registration_uid_t rid = -1)
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
  { return -1; }
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
  
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
  virtual int pushdownChild(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
      const MaceKey& groupId
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
      const MaceKey& childId
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
      , registration_uid_t rid = -1)
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeServiceClass.mh"
  { return -1; }
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
  
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeServiceClass.h"
  virtual registration_uid_t registerHandler(GroupJoinHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(GroupJoinHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(GroupJoinHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(GroupJoinHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ScribeTreeHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ScribeTreeHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ScribeTreeHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ScribeTreeHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(TreeStructureHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(TreeStructureHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(TreeStructureHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~ScribeTreeServiceClass() { }
};

#endif // _SCRIBETREESERVICECLASS_H
