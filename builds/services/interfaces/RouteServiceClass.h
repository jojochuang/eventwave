/*********************************************
*  RouteServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:06 2012
*********************************************/
#ifndef _ROUTESERVICECLASS_H
#define _ROUTESERVICECLASS_H
#include "TransportServiceClass.h"
#include "ServiceClass.h"
#include "ForwardDataHandler.h"


class RouteServiceClass : public virtual TransportServiceClass, public virtual ServiceClass {
  public:
  static RouteServiceClass& NULL_;
  static const char* name; // = "Route";
  
  
  
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(NetworkErrorHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(NetworkErrorHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ForwardDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ForwardDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ForwardDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~RouteServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      implements {
        upcalls {
          forward(const MaceKey&, const MaceKey&, MaceKey&, const Message& <- const std::string&);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _ROUTESERVICECLASS_H
