/*********************************************
*  OverlayJoinHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:23 2012
*********************************************/
#ifndef _OVERLAYJOINHANDLER_H
#define _OVERLAYJOINHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mace_constants.h"

typedef int join_status_t;
const join_status_t JOIN_ACCEPTED = 0;
const join_status_t JOIN_UNREACHABLE = 1;
const join_status_t JOIN_UNAUTHORIZED = 2;
const join_status_t JOIN_UNJOINED = 3;
class OverlayJoinHandler  {
  public:
  static OverlayJoinHandler& NULL_;
  static const char* name; // = "OverlayJoin";
  
  
  
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  virtual void peerJoinedOverlay(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
      const MaceKey& peer
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  { }
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  virtual void joinResultOverlay(
      #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
      const MaceKey& source
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
      ,
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
      join_status_t status
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  { }
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  virtual bool verifyJoinOverlay(
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
      const MaceKey& source
#line 56 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
      , registration_uid_t rid = -1)
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayJoinHandler.mh"
  { return true; }
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  
#line 62 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayJoinHandler.h"
  virtual ~OverlayJoinHandler() { }
};

#endif // _OVERLAYJOINHANDLER_H
