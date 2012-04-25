/*********************************************
*  FileFindServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _FILEFINDSERVICECLASS_H
#define _FILEFINDSERVICECLASS_H
#include "ServiceClass.h"
#include "FileFindHandler.h"


class FileFindServiceClass : public virtual ServiceClass {
  public:
  static FileFindServiceClass& NULL_;
  static const char* name; // = "FileFind";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
  virtual void beginFind(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
      const std::string& path
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
      ,
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
      bool normalizePaths = false
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method beginFind in base class FileFindServiceClass called."); }
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
  virtual void cancelFind(registration_uid_t rid = -1) { ABORT("Unimplemented method cancelFind in base class FileFindServiceClass called."); }
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
  virtual void pauseFind(registration_uid_t rid = -1) { ABORT("Unimplemented method pauseFind in base class FileFindServiceClass called."); }
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
  #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindServiceClass.mh"
  virtual void resumeFind(registration_uid_t rid = -1) { ABORT("Unimplemented method resumeFind in base class FileFindServiceClass called."); }
#line 39 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindServiceClass.h"
  virtual registration_uid_t registerHandler(FileFindHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(FileFindHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(FileFindHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(FileFindHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~FileFindServiceClass() { }
};

#endif // _FILEFINDSERVICECLASS_H
