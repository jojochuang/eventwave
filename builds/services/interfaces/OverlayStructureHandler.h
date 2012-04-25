/*********************************************
*  OverlayStructureHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:23 2012
*********************************************/
#ifndef _OVERLAYSTRUCTUREHANDLER_H
#define _OVERLAYSTRUCTUREHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mset.h"
class OverlayStructureHandler  {
  public:
  static OverlayStructureHandler& NULL_;
  static const char* name; // = "OverlayStructure";
  
  
  
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  virtual void notifySuccessors(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
      NodeSet successors
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
      , registration_uid_t rid = -1)
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  { }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  virtual void notifySuccessorAdded(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
      const MaceKey& id
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
      , registration_uid_t rid = -1)
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  { }
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  virtual void notifySuccessorRemoved(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
      const MaceKey& id
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
      , registration_uid_t rid = -1)
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  { }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  virtual void notifyIdSpaceChanged(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
      const KeyRange& range
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayStructureHandler.mh"
  { }
#line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  
#line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayStructureHandler.h"
  virtual ~OverlayStructureHandler() { }
};

#endif // _OVERLAYSTRUCTUREHANDLER_H
