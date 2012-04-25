/*********************************************
*  BandwidthTransportServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _BANDWIDTHTRANSPORTSERVICECLASS_H
#define _BANDWIDTHTRANSPORTSERVICECLASS_H
#include "TransportServiceClass.h"
#include "ServiceClass.h"

typedef TransportServiceClass::Connection::type BandwidthDirection;
class BandwidthTransportServiceClass : public virtual TransportServiceClass, public virtual ServiceClass {
  public:
  static BandwidthTransportServiceClass& NULL_;
  static const char* name; // = "BandwidthTransport";
  
  
  
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual void startSegment(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      BandwidthDirection bd
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method startSegment in base class BandwidthTransportServiceClass called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual void endSegment(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      BandwidthDirection bd
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method endSegment in base class BandwidthTransportServiceClass called."); }
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual double getBandwidth(
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      BandwidthDirection bd
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getBandwidth in base class BandwidthTransportServiceClass called."); }
#line 52 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual bool hasRoom(
      #line 37 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method hasRoom in base class BandwidthTransportServiceClass called."); }
#line 59 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual int queued(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 64 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method queued in base class BandwidthTransportServiceClass called."); }
#line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
  virtual void setWindowSize(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BandwidthTransportServiceClass.mh"
      const MaceKey& peer
#line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method setWindowSize in base class BandwidthTransportServiceClass called."); }
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BandwidthTransportServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(NetworkErrorHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(NetworkErrorHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~BandwidthTransportServiceClass() { }
};

#endif // _BANDWIDTHTRANSPORTSERVICECLASS_H
