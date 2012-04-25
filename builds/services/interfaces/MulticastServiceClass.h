/*********************************************
*  MulticastServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _MULTICASTSERVICECLASS_H
#define _MULTICASTSERVICECLASS_H
#include "ServiceClass.h"
#include "ReceiveDataHandler.h"
#include "ForwardDataHandler.h"

#include <string>
#include "MaceTypes.h"
#include "OverlayServiceClass.h"
class MulticastServiceClass : public virtual ServiceClass {
  public:
  static MulticastServiceClass& NULL_;
  static const char* name; // = "Multicast";
  
  
  
  #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
  virtual bool multicast(
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
      const MaceKey& dest
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
      const mace::string& s
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
  { return false; }
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
  
#line 37 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
  #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
  virtual bool anycast(
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
      const MaceKey& dest
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
      const mace::string& s
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
      , registration_uid_t rid = -1)
  #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MulticastServiceClass.mh"
  { return false; }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MulticastServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ForwardDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ForwardDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~MulticastServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_multicast(const MaceKey&, const Message& -> const mace::string&, registration_uid_t);
        downcall_anycast(const MaceKey&, const Message& -> const mace::string&, registration_uid_t);
      }
      implements {
        upcalls {
          forward(const MaceKey&, const MaceKey&, MaceKey&, const Message& <- const std::string&);
          deliver(const MaceKey&, const MaceKey&, const Message& <- const std::string&);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _MULTICASTSERVICECLASS_H
