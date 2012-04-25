/*********************************************
*  FileFindHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _FILEFINDHANDLER_H
#define _FILEFINDHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct stat stat_t;
class FileFindHandler  {
  public:
  static FileFindHandler& NULL_;
  static const char* name; // = "FileFind";
  
  
  
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual void atFile(
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 28 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const stat_t& sbuf
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 38 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { }
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual bool atDir(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 43 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const stat_t& sbuf
#line 47 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { return true; }
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 53 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual void leavingDir(
      #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const StringList& contents
#line 62 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 41 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { }
#line 66 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 68 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual void atLink(
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const stat_t& sbuf
#line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 42 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { }
#line 81 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 83 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual bool statError(
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 88 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const FileException& e
#line 92 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 44 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { return true; }
#line 96 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 98 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual bool readDirError(
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& path
#line 103 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      ,
      #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const FileException& e
#line 107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 46 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { return true; }
#line 111 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 113 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  virtual void findComplete(
      #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
      const std::string& root
#line 118 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
      , registration_uid_t rid = -1)
  #line 47 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileFindHandler.mh"
  { }
#line 122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  
#line 124 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileFindHandler.h"
  virtual ~FileFindHandler() { }
};

#endif // _FILEFINDHANDLER_H
