/*********************************************
*  GossipServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _GOSSIPSERVICECLASS_H
#define _GOSSIPSERVICECLASS_H
#include "ServiceClass.h"
#include "GossipDataHandler.h"


class GossipServiceClass : public virtual ServiceClass {
  public:
  static GossipServiceClass& NULL_;
  static const char* name; // = "Gossip";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
  virtual void publishGossip(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      channel_id_t channelId
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      const std::string& data
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method publishGossip in base class GossipServiceClass called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
  virtual GossipMap getGossip(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      channel_id_t channelId
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getGossip in base class GossipServiceClass called."); }
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
  virtual void revokeGossip(
      #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      channel_id_t channelId
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method revokeGossip in base class GossipServiceClass called."); }
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
  virtual void subscribeGossip(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      channel_id_t channelId
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method subscribeGossip in base class GossipServiceClass called."); }
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
  virtual void unsubscribeGossip(
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GossipServiceClass.mh"
      channel_id_t channelId
#line 56 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method unsubscribeGossip in base class GossipServiceClass called."); }
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GossipServiceClass.h"
  virtual registration_uid_t registerHandler(GossipDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(GossipDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(GossipDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(GossipDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~GossipServiceClass() { }
};

#endif // _GOSSIPSERVICECLASS_H
