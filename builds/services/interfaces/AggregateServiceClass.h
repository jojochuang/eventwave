/*********************************************
*  AggregateServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _AGGREGATESERVICECLASS_H
#define _AGGREGATESERVICECLASS_H
#include "ServiceClass.h"
#include "AggregateDataHandler.h"

#include "MaceTypes.h"
class AggregateServiceClass : public virtual ServiceClass {
  public:
  static AggregateServiceClass& NULL_;
  static const char* name; // = "Aggregate";
  
  
  
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual int aggregateSubscribe(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1)
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  { return 0; }
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual void aggregateUnsubscribe(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  { }
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual int getDistributeCount(
      #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1)
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  { return 0; }
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual AggregateNodeCountMap getCollectCounts(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getCollectCounts in base class AggregateServiceClass called."); }
#line 59 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual std::string getDistributeBlob(
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getDistributeBlob in base class AggregateServiceClass called."); }
#line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
  virtual AggregateNodeBlobMap getCollectBlobs(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateServiceClass.mh"
      channel_id_t channelId
#line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getCollectBlobs in base class AggregateServiceClass called."); }
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateServiceClass.h"
  virtual registration_uid_t registerHandler(AggregateDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(AggregateDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(AggregateDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(AggregateDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~AggregateServiceClass() { }
};

#endif // _AGGREGATESERVICECLASS_H
