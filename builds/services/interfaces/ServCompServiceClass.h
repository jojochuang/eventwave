/*********************************************
*  ServCompServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _SERVCOMPSERVICECLASS_H
#define _SERVCOMPSERVICECLASS_H
#include "ServiceClass.h"


class ServCompServiceClass : public virtual ServiceClass {
  public:
  static ServCompServiceClass& NULL_;
  static const char* name; // = "ServComp";
  
  
  
  #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServCompServiceClass.mh"
  virtual uint32_t test(
      #line 2 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ServCompServiceClass.mh"
      uint32_t n
#line 23 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ServCompServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method test in base class ServCompServiceClass called."); }
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/ServCompServiceClass.h"
  virtual ~ServCompServiceClass() { }
};

#endif // _SERVCOMPSERVICECLASS_H
