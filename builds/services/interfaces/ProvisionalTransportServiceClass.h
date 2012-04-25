/*********************************************
*  ProvisionalTransportServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:06 2012
*********************************************/
#ifndef _PROVISIONALTRANSPORTSERVICECLASS_H
#define _PROVISIONALTRANSPORTSERVICECLASS_H
#include "BufferedTransportServiceClass.h"
#include "ServiceClass.h"
#include "MessageStatusHandler.h"


class ProvisionalTransportServiceClass : public virtual BufferedTransportServiceClass, public virtual ServiceClass {
  public:
  static ProvisionalTransportServiceClass& NULL_;
  static const char* name; // = "ProvisionalTransport";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
  virtual message_id_t provisionalRoute(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const MaceKey& dest
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const std::string& s
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method provisionalRoute in base class ProvisionalTransportServiceClass called."); }
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
  virtual size_t cancel(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      message_id_t id
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method cancel in base class ProvisionalTransportServiceClass called."); }
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
  virtual message_id_t cancelFront(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      const MaceKey& dest
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method cancelFront in base class ProvisionalTransportServiceClass called."); }
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
  virtual void messageStatus(
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      message_id_t id
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      ,
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      uint32_t& size
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      ,
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ProvisionalTransportServiceClass.mh"
      uint32_t& sent
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method messageStatus in base class ProvisionalTransportServiceClass called."); }
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ProvisionalTransportServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(NetworkErrorHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(NetworkErrorHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(MessageStatusHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(MessageStatusHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(MessageStatusHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(MessageStatusHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ConnectionStatusHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ConnectionStatusHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ConnectionStatusHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ConnectionStatusHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~ProvisionalTransportServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_provisionalRoute(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _PROVISIONALTRANSPORTSERVICECLASS_H
