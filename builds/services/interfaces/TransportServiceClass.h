/*********************************************
*  TransportServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:08 2012
*********************************************/
#ifndef _TRANSPORTSERVICECLASS_H
#define _TRANSPORTSERVICECLASS_H
#include "ServiceClass.h"
#include "ReceiveDataHandler.h"
#include "NetworkErrorHandler.h"


class TransportServiceClass : public virtual ServiceClass {
  public:
  static TransportServiceClass& NULL_;
  static const char* name; // = "Transport";
  
  struct Connection {
    typedef int type;
    static const type INCOMING = 0;
    static const type OUTGOING = 1;
    static const type NAT = 2;
  };
  
  #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual bool route(
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      ,
      #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      , registration_uid_t rid = -1)
  #line 54 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  { return false; }
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  
#line 40 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual bool route(
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& src
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      , registration_uid_t rid = -1)
  #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  {
    return false;
  }
#line 59 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  
#line 61 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 63 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  size_t send(
      #line 63 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      ,
      #line 63 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const std::string& s
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      , registration_uid_t rid = -1)
  #line 63 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  {
    bool r = route(dest, s, rid);
    if (r) {
      return s.size();
    }
    else {
      return 0;
    }
  }
#line 82 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  
#line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual void suspendDeliver(registration_uid_t rid = -1) { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 87 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual void suspendDeliver(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method suspendDeliver in base class TransportServiceClass called."); }
#line 94 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual void resumeDeliver(registration_uid_t rid = -1) { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 97 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
  virtual void resumeDeliver(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportServiceClass.mh"
      const MaceKey& dest
#line 102 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method resumeDeliver in base class TransportServiceClass called."); }
#line 104 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(NetworkErrorHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(NetworkErrorHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~TransportServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_route(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
        downcall_route(const MaceKey&, const MaceKey&, const Message& -> const std::string&, registration_uid_t);
        downcall_send(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
      }
      implements {
        upcalls {
          deliver(const MaceKey&, const MaceKey&, const Message& <- const std::string&);
          messageError(const MaceKey&, TransportError::type, const Message& <- const std::string&, registration_uid_t);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _TRANSPORTSERVICECLASS_H
