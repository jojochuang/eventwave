/*********************************************
*  GenericGameOfLifeServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _GENERICGAMEOFLIFESERVICECLASS_H
#define _GENERICGAMEOFLIFESERVICECLASS_H
#include "ServiceClass.h"

#include "mset.h"
enum JoinStatus { JOINED, JOINING, NONE };
class GenericGameOfLifeServiceClass : public virtual ServiceClass {
  public:
  static GenericGameOfLifeServiceClass& NULL_;
  static const char* name; // = "GenericGameOfLife";
  
  
  
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/GenericGameOfLifeServiceClass.mh"
  virtual void start(registration_uid_t rid = -1) { ABORT("Unimplemented method start in base class GenericGameOfLifeServiceClass called."); }
#line 22 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/GenericGameOfLifeServiceClass.h"
  virtual ~GenericGameOfLifeServiceClass() { }
};

#endif // _GENERICGAMEOFLIFESERVICECLASS_H
