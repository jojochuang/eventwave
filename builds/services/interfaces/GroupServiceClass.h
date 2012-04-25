/*********************************************
*  GroupServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _GROUPSERVICECLASS_H
#define _GROUPSERVICECLASS_H
#include "ServiceClass.h"
#include "GroupJoinHandler.h"

#include "OverlayServiceClass.h"
class GroupServiceClass : public virtual ServiceClass {
  public:
  static GroupServiceClass& NULL_;
  static const char* name; // = "Group";
  
  
  
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  virtual void createGroup(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
      const MaceKey& groupId
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
      , registration_uid_t rid = -1)
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  { }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  virtual void joinGroup(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
      const MaceKey& groupId
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
      , registration_uid_t rid = -1)
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  { }
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  virtual void leaveGroup(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
      const MaceKey& groupId
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  { }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  virtual JoinStatus getGroupJoinStatus(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
      const MaceKey& groupId
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getGroupJoinStatus in base class GroupServiceClass called."); }
#line 59 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  bool isJoinedGroup(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
      const MaceKey& groupId
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
      , registration_uid_t rid = -1) const
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  { return getGroupJoinStatus(groupId) == JOINED; }
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  virtual void setAuthoritativeGroupJoinHandler(registration_uid_t rid = -1)
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupServiceClass.mh"
  { }
#line 75 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  
#line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupServiceClass.h"
  virtual registration_uid_t registerHandler(GroupJoinHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(GroupJoinHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(GroupJoinHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(GroupJoinHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~GroupServiceClass() { }
};

#endif // _GROUPSERVICECLASS_H
