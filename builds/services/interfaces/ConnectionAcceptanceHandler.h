/*********************************************
*  ConnectionAcceptanceHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:07 2012
*********************************************/
#ifndef _CONNECTIONACCEPTANCEHANDLER_H
#define _CONNECTIONACCEPTANCEHANDLER_H
#include "massert.h"
#include "MaceTypes.h"


class ConnectionAcceptanceHandler  {
  public:
  static ConnectionAcceptanceHandler& NULL_;
  static const char* name; // = "ConnectionAcceptance";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceHandler.mh"
  virtual bool acceptConnection(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceHandler.mh"
      const MaceKey& peer
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceHandler.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceHandler.mh"
      const mace::string& token
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceHandler.h"
      , registration_uid_t rid = -1)
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionAcceptanceHandler.mh"
  {
    return true;
  }
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceHandler.h"
  
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConnectionAcceptanceHandler.h"
  virtual ~ConnectionAcceptanceHandler() { }
};

#endif // _CONNECTIONACCEPTANCEHANDLER_H
