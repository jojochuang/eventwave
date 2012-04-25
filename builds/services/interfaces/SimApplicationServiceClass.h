/*********************************************
*  SimApplicationServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _SIMAPPLICATIONSERVICECLASS_H
#define _SIMAPPLICATIONSERVICECLASS_H
#include "ServiceClass.h"
#include "SimHandler.h"


class SimApplicationServiceClass : public virtual ServiceClass {
  public:
  static SimApplicationServiceClass& NULL_;
  static const char* name; // = "SimApplication";
  
  
  
  virtual registration_uid_t registerHandler(SimHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(SimHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(SimHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(SimHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~SimApplicationServiceClass() { }
};

#endif // _SIMAPPLICATIONSERVICECLASS_H
