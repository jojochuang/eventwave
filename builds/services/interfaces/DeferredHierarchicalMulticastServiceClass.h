/*********************************************
*  DeferredHierarchicalMulticastServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _DEFERREDHIERARCHICALMULTICASTSERVICECLASS_H
#define _DEFERREDHIERARCHICALMULTICASTSERVICECLASS_H
#include "DeferredMulticastServiceClass.h"
#include "ServiceClass.h"

#include "mace_constants.h"
class DeferredHierarchicalMulticastServiceClass : public virtual DeferredMulticastServiceClass, public virtual ServiceClass {
  public:
  static DeferredHierarchicalMulticastServiceClass& NULL_;
  static const char* name; // = "DeferredHierarchicalMulticast";
  
  
  
  #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
  virtual bool collect(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
      const MaceKey& dest
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
      const mace::string& s
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
  { return false; }
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
  
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
  #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
  virtual bool distribute(
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
      const MaceKey& dest
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
      ,
      #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
      const mace::string& s
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 53 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DeferredHierarchicalMulticastServiceClass.mh"
  { return false; }
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
  
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DeferredHierarchicalMulticastServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ForwardDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ForwardDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~DeferredHierarchicalMulticastServiceClass() { }
};

#endif // _DEFERREDHIERARCHICALMULTICASTSERVICECLASS_H
