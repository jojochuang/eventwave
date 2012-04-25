/*********************************************
*  RequestTransportServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _REQUESTTRANSPORTSERVICECLASS_H
#define _REQUESTTRANSPORTSERVICECLASS_H
#include "ServiceClass.h"
#include "ReceiveRequestHandler.h"


class RequestTransportServiceClass : public virtual ServiceClass {
  public:
  static RequestTransportServiceClass& NULL_;
  static const char* name; // = "RequestTransport";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
  virtual std::string routeRequest(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const MaceKey& dest
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const std::string& s
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      uint64_t timeout = 0
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method routeRequest in base class RequestTransportServiceClass called."); }
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
  virtual std::string routeRequest(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const MaceKey& dest
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const NodeList& alternates
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const std::string& s
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      uint64_t timeout = 0
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method routeRequest in base class RequestTransportServiceClass called."); }
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
  virtual void routeResponse(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const std::string& req
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const std::string& s
#line 62 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method routeResponse in base class RequestTransportServiceClass called."); }
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
  virtual void cancelRequest(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const std::string& req
#line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method cancelRequest in base class RequestTransportServiceClass called."); }
#line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
  virtual void cancelRequests(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/RequestTransportServiceClass.mh"
      const MaceKey& dest
#line 76 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method cancelRequests in base class RequestTransportServiceClass called."); }
#line 78 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/RequestTransportServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveRequestHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveRequestHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveRequestHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveRequestHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~RequestTransportServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_routeRequest(const MaceKey&, const Message& -> const std::string&, uint64_t timeout, registration_uid_t);
        downcall_routeRequest(const MaceKey&, const NodeList&, const Message& -> const std::string&, uint64_t timeout, registration_uid_t);
        downcall_routeResponse(const std::string&, const Message& -> const std::string&, registration_uid_t);
      }
      implements {
        upcalls {
          deliverRequest(const std::string&, const Message& <- const std::string&);
          deliverResponse(const MaceKey&, const Message& <- const std::string&,
              const std::string&);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _REQUESTTRANSPORTSERVICECLASS_H
