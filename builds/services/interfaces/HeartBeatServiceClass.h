/*********************************************
*  HeartBeatServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:20 2012
*********************************************/
#ifndef _HEARTBEATSERVICECLASS_H
#define _HEARTBEATSERVICECLASS_H
#include "ServiceClass.h"
#include "JobManagerDataHandler.h"

#include "mset.h"
enum JoinStatus { JOINED, JOINING, NONE };

#include "mlist.h"
#include "MaceKey.h"
class HeartBeatServiceClass : public virtual ServiceClass {
  public:
  static HeartBeatServiceClass& NULL_;
  static const char* name; // = "HeartBeat";
  
  
  
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void start(registration_uid_t rid = -1) { ABORT("Unimplemented method start in base class HeartBeatServiceClass called."); }
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void notifySignal(
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      int signum
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method notifySignal in base class HeartBeatServiceClass called."); }
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void startService(
      #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      const std::string& specFileName
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      ,
      #line 43 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      const std::string& inputFileName
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method startService in base class HeartBeatServiceClass called."); }
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void reportMigration(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      mace::string& snapshot
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method reportMigration in base class HeartBeatServiceClass called."); }
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 45 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void showJobStatus(registration_uid_t rid = -1) { ABORT("Unimplemented method showJobStatus in base class HeartBeatServiceClass called."); }
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void showNodeStatus(registration_uid_t rid = -1) { ABORT("Unimplemented method showNodeStatus in base class HeartBeatServiceClass called."); }
#line 57 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void terminateRemoteAll(registration_uid_t rid = -1) { ABORT("Unimplemented method terminateRemoteAll in base class HeartBeatServiceClass called."); }
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void terminateRemote(
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      const mace::list< MaceKey >& nodes
#line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      ,
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      bool migrate
#line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method terminateRemote in base class HeartBeatServiceClass called."); }
#line 71 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void terminateRemote(
      #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      uint32_t nodes
#line 76 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      ,
      #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      bool migrate
#line 80 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method terminateRemote in base class HeartBeatServiceClass called."); }
#line 82 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
  virtual void migrateContext(
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/HeartBeatServiceClass.mh"
      const std::string& contextID
#line 87 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method migrateContext in base class HeartBeatServiceClass called."); }
#line 89 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/HeartBeatServiceClass.h"
  virtual registration_uid_t registerHandler(JobManagerDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(JobManagerDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(JobManagerDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(JobManagerDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~HeartBeatServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_route(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
        downcall_route(const MaceKey&, const MaceKey&, const Message& -> const std::string&, registration_uid_t);
        downcall_send(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
      }
      implements {
        upcalls {
          messageError(const MaceKey&, TransportError::type, const Message& <- const std::string&, registration_uid_t);
        }
      }
    }
  }
  #endif // MACE_VOODOO
  
  #ifdef MACE_VOODOO
  mace provides {
    transitions {
      downcall maceInit() [merge = post; exec = once] {
        NodeSet peers;
        bool autoBoot;
        params::getBootstrapPeers(MaceKey::null, peers, autoBoot);
        if (autoBoot) {
          joinOverlay(peers, -1);
        }
      }
    }
  }
  #endif // MACE_VOODOO
};

#endif // _HEARTBEATSERVICECLASS_H
