/*********************************************
*  ConsensusServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _CONSENSUSSERVICECLASS_H
#define _CONSENSUSSERVICECLASS_H
#include "ServiceClass.h"
#include "ConsensusHandler.h"


class ConsensusServiceClass : public virtual ServiceClass {
  public:
  static ConsensusServiceClass& NULL_;
  static const char* name; // = "Consensus";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusServiceClass.mh"
  virtual void propose(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusServiceClass.mh"
      const mace::string& key
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusServiceClass.h"
      ,
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusServiceClass.mh"
      const mace::string& value
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method propose in base class ConsensusServiceClass called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusServiceClass.h"
  virtual registration_uid_t registerHandler(ConsensusHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ConsensusHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ConsensusHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ConsensusHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~ConsensusServiceClass() { }
};

#endif // _CONSENSUSSERVICECLASS_H
