/*********************************************
*  ConnectionAcceptanceServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:06 2012
*********************************************/
#ifndef _CONNECTIONACCEPTANCESERVICECLASS_H
#define _CONNECTIONACCEPTANCESERVICECLASS_H
#include "ServiceClass.h"
#include "ConnectionAcceptanceHandler.h"


class ConnectionAcceptanceServiceClass : public virtual ServiceClass {
  public:
  static ConnectionAcceptanceServiceClass& NULL_;
  static const char* name; // = "ConnectionAcceptance";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceServiceClass.mh"
  virtual void setAuthoritativeConnectionAcceptor(registration_uid_t rid = -1) { ABORT("Unimplemented method setAuthoritativeConnectionAcceptor in base class ConnectionAcceptanceServiceClass called."); }
#line 22 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceServiceClass.h"
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceServiceClass.mh"
  virtual void setConnectionToken(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceServiceClass.mh"
      const mace::string& token
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method setConnectionToken in base class ConnectionAcceptanceServiceClass called."); }
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceServiceClass.h"
  virtual registration_uid_t registerHandler(ConnectionAcceptanceHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ConnectionAcceptanceHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ConnectionAcceptanceHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ConnectionAcceptanceHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~ConnectionAcceptanceServiceClass() { }
};

#endif // _CONNECTIONACCEPTANCESERVICECLASS_H
