/*********************************************
*  HierarchicalMulticastServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _HIERARCHICALMULTICASTSERVICECLASS_H
#define _HIERARCHICALMULTICASTSERVICECLASS_H
#include "MulticastServiceClass.h"
#include "ServiceClass.h"

#include "mace_constants.h"
class HierarchicalMulticastServiceClass : public virtual MulticastServiceClass, public virtual ServiceClass {
  public:
  static HierarchicalMulticastServiceClass& NULL_;
  static const char* name; // = "HierarchicalMulticast";
  
  
  
  #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
  virtual bool collect(
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
      const MaceKey& dest
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
      ,
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
      const mace::string& s
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
  { return false; }
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
  
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
  #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
  virtual bool distribute(
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
      const MaceKey& dest
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
      const mace::string& s
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HierarchicalMulticastServiceClass.mh"
  { return false; }
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
  
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HierarchicalMulticastServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ForwardDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ForwardDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~HierarchicalMulticastServiceClass() { }
};

#endif // _HIERARCHICALMULTICASTSERVICECLASS_H
