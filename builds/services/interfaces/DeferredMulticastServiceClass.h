/*********************************************
*  DeferredMulticastServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _DEFERREDMULTICASTSERVICECLASS_H
#define _DEFERREDMULTICASTSERVICECLASS_H
#include "ServiceClass.h"
#include "ReceiveDataHandler.h"
#include "ForwardDataHandler.h"

#include <string>
#include "MaceTypes.h"
#include "OverlayServiceClass.h"
class DeferredMulticastServiceClass : public virtual ServiceClass {
  public:
  static DeferredMulticastServiceClass& NULL_;
  static const char* name; // = "DeferredMulticast";
  
  
  
  #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
  virtual bool multicast(
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
      const MaceKey& dest
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
      const mace::string& s
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
  { return false; }
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
  
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
  #line 61 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
  virtual bool anycast(
      #line 61 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
      const MaceKey& dest
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
      ,
      #line 61 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
      const mace::string& s
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 61 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredMulticastServiceClass.mh"
  { return false; }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredMulticastServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ForwardDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ForwardDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~DeferredMulticastServiceClass() { }
};

#endif // _DEFERREDMULTICASTSERVICECLASS_H
