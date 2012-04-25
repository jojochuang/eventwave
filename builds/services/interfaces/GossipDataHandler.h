/*********************************************
*  GossipDataHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _GOSSIPDATAHANDLER_H
#define _GOSSIPDATAHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "MaceTypes.h"
#include "mstring.h"
#include "mhash_map.h"

// maps node ids -> data
typedef mace::hash_map<MaceKey, std::string> GossipMap;
class GossipDataHandler  {
  public:
  static GossipDataHandler& NULL_;
  static const char* name; // = "GossipData";
  
  
  
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
  virtual void deliverGossip(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
      channel_id_t channelId
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
      const GossipMap& gmap
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
      , registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
  { }
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
  
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
  virtual void setGossipData(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
      channel_id_t channelId
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
      ,
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
      std::string& data
#line 48 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
      , registration_uid_t rid = -1)
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipDataHandler.mh"
  { }
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
  
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipDataHandler.h"
  virtual ~GossipDataHandler() { }
};

#endif // _GOSSIPDATAHANDLER_H
