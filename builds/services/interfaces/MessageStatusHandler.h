/*********************************************
*  MessageStatusHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:10 2012
*********************************************/
#ifndef _MESSAGESTATUSHANDLER_H
#define _MESSAGESTATUSHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

typedef uint64_t message_id_t;
class MessageStatusHandler  {
  public:
  static MessageStatusHandler& NULL_;
  static const char* name; // = "MessageStatus";
  
  
  
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
  virtual void messageSent(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      message_id_t id
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      , registration_uid_t rid = -1)
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
  { }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
  
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
  virtual void messageCanceled(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      const MaceKey& src
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
      uint32_t bytes
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
      , registration_uid_t rid = -1)
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/MessageStatusHandler.mh"
  { }
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
  
#line 45 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/MessageStatusHandler.h"
  virtual ~MessageStatusHandler() { }
};

#endif // _MESSAGESTATUSHANDLER_H
