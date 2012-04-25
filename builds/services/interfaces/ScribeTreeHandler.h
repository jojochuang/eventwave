/*********************************************
*  ScribeTreeHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:23 2012
*********************************************/
#ifndef _SCRIBETREEHANDLER_H
#define _SCRIBETREEHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "MaceTypes.h"
#include "mace.h"
class ScribeTreeHandler  {
  public:
  static ScribeTreeHandler& NULL_;
  static const char* name; // = "ScribeTree";
  
  
  
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
  virtual int selectParent(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
      const MaceKey& groupId
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
      ,
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
      const NodeSet& siblings
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
      MaceKey& pushdownId
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
      int joinSeq = 0
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
      , registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ScribeTreeHandler.mh"
  { return -1; }
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
  
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ScribeTreeHandler.h"
  virtual ~ScribeTreeHandler() { }
};

#endif // _SCRIBETREEHANDLER_H
