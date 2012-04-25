/*********************************************
*  ReceiveRequestHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:23 2012
*********************************************/
#ifndef _RECEIVEREQUESTHANDLER_H
#define _RECEIVEREQUESTHANDLER_H
#include "massert.h"
#include "MaceTypes.h"


class ReceiveRequestHandler  {
  public:
  static ReceiveRequestHandler& NULL_;
  static const char* name; // = "ReceiveRequest";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
  virtual void deliverRequest(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
      const std::string& req
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
      const std::string& s
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method deliverRequest in base class ReceiveRequestHandler called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
  virtual void deliverResponse(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
      const MaceKey& src
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
      const std::string& s
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ReceiveRequestHandler.mh"
      const std::string& req
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method deliverResponse in base class ReceiveRequestHandler called."); }
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ReceiveRequestHandler.h"
  virtual ~ReceiveRequestHandler() { }
};

#endif // _RECEIVEREQUESTHANDLER_H
