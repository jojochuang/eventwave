/*********************************************
*  GroupJoinHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _GROUPJOINHANDLER_H
#define _GROUPJOINHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include <string>
#include "MaceTypes.h"
#include "mace_constants.h"
#include "OverlayJoinHandler.h"
class GroupJoinHandler  {
  public:
  static GroupJoinHandler& NULL_;
  static const char* name; // = "GroupJoin";
  
  
  
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  virtual bool verifyJoinGroup(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& groupId
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& source
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  { return true; }
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  virtual void peerJoinedGroup(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& groupId
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& peer
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  { }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  virtual void joinResultGroup(
      #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& groupId
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      ,
      #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      const MaceKey& source
#line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      ,
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      join_status_t status
#line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  { }
#line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  
#line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  virtual void notifyJoinedGroups(
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      NodeSet groups
#line 76 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  { }
#line 80 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  
#line 82 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  virtual void notifySubscribedGroups(
      #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
      NodeSet groups
#line 87 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GroupJoinHandler.mh"
  { }
#line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  
#line 93 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GroupJoinHandler.h"
  virtual ~GroupJoinHandler() { }
};

#endif // _GROUPJOINHANDLER_H
