/*********************************************
*  ConnectionStatusHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:09 2012
*********************************************/
#ifndef _CONNECTIONSTATUSHANDLER_H
#define _CONNECTIONSTATUSHANDLER_H
#include "massert.h"
#include "MaceTypes.h"


class ConnectionStatusHandler  {
  public:
  static ConnectionStatusHandler& NULL_;
  static const char* name; // = "ConnectionStatus";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
  virtual void clearToSend(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      const MaceKey& peer
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method clearToSend in base class ConnectionStatusHandler called."); }
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
  virtual void notifyFlushed(registration_uid_t rid = -1) { ABORT("Unimplemented method notifyFlushed in base class ConnectionStatusHandler called."); }
#line 29 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionStatusHandler.h"
  virtual ~ConnectionStatusHandler() { }
};

#endif // _CONNECTIONSTATUSHANDLER_H
