/*********************************************
*  DHTDataHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _DHTDATAHANDLER_H
#define _DHTDATAHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mstring.h"
class DHTDataHandler  {
  public:
  static DHTDataHandler& NULL_;
  static const char* name; // = "DHTData";
  
  
  
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
  virtual void dhtContainsKeyResult(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const MaceKey& key
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      bool result
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
      , registration_uid_t rid = -1)
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
  { }
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
  
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
  virtual void dhtGetResult(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const MaceKey& key
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const std::string& value
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      bool found
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
      , registration_uid_t rid = -1)
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
  { }
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
  
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTDataHandler.h"
  virtual ~DHTDataHandler() { }
};

#endif // _DHTDATAHANDLER_H
