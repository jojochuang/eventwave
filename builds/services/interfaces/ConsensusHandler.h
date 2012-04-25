/*********************************************
*  ConsensusHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _CONSENSUSHANDLER_H
#define _CONSENSUSHANDLER_H
#include "massert.h"
#include "MaceTypes.h"


class ConsensusHandler  {
  public:
  static ConsensusHandler& NULL_;
  static const char* name; // = "Consensus";
  
  
  
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
  virtual void notifyProposalChosen(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
      const mace::string& key
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
      const mace::string& value
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method notifyProposalChosen in base class ConsensusHandler called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
  virtual void notifyProposalNotChosen(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
      const mace::string& key
#line 35 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConsensusHandler.mh"
      const mace::string& value
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method notifyProposalNotChosen in base class ConsensusHandler called."); }
#line 41 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ConsensusHandler.h"
  virtual ~ConsensusHandler() { }
};

#endif // _CONSENSUSHANDLER_H
