/*********************************************
*  JobManagerDataHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _JOBMANAGERDATAHANDLER_H
#define _JOBMANAGERDATAHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mstring.h"
#include "mhash_map.h"
#include "MaceTypes.h"
class JobManagerDataHandler  {
  public:
  static JobManagerDataHandler& NULL_;
  static const char* name; // = "JobManagerData";
  
  
  
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
  virtual void gotJob(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
      const uint32_t jobpid
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
      ,
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
      const mace::string& snapshotfile
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
      , registration_uid_t rid = -1)
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
  {}
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
  
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
  #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
  virtual void ignoreSnapshot(
      #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
      const bool ignore
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
      , registration_uid_t rid = -1)
  #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/JobManagerDataHandler.mh"
  {}
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
  
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/JobManagerDataHandler.h"
  virtual ~JobManagerDataHandler() { }
};

#endif // _JOBMANAGERDATAHANDLER_H
