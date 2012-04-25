/*********************************************
*  OverlayServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _OVERLAYSERVICECLASS_H
#define _OVERLAYSERVICECLASS_H
#include "ServiceClass.h"
#include "OverlayJoinHandler.h"

#include "mset.h"
enum JoinStatus { JOINED, JOINING, NONE };
class OverlayServiceClass : public virtual ServiceClass {
  public:
  static OverlayServiceClass& NULL_;
  static const char* name; // = "Overlay";
  
  
  
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  virtual void setAuthoritativeJoinHandler(registration_uid_t rid = -1)
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  { }
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  virtual void joinOverlay(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
      const NodeSet& peerSet
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  { }
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  virtual JoinStatus getOverlayJoinStatus(registration_uid_t rid = -1) const { ABORT("Unimplemented method getOverlayJoinStatus in base class OverlayServiceClass called."); }
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  virtual void leaveOverlay(registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  { }
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  
#line 48 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  bool isJoinedOverlay(registration_uid_t rid = -1) const
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/OverlayServiceClass.mh"
  { return getOverlayJoinStatus() == JOINED; }
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  
#line 55 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/OverlayServiceClass.h"
  virtual registration_uid_t registerHandler(OverlayJoinHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(OverlayJoinHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(OverlayJoinHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(OverlayJoinHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~OverlayServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace provides {
    transitions {
      downcall maceInit() [merge = post; exec = once] {
        NodeSet peers;
        bool autoBoot;
        params::getBootstrapPeers(MaceKey::null, peers, autoBoot);
        if (autoBoot) {
          joinOverlay(peers, -1);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _OVERLAYSERVICECLASS_H
