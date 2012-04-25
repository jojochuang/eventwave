/*********************************************
*  FileStatusHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:22 2012
*********************************************/
#ifndef _FILESTATUSHANDLER_H
#define _FILESTATUSHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "Enum.h"
#include <string>
class FileStatusHandler  {
  public:
  static FileStatusHandler& NULL_;
  static const char* name; // = "FileStatus";
  
  enum _file_status_t { SUCCESS, FAILURE };
  typedef Enum<_file_status_t> file_status_t;
  
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileStatusHandler.mh"
  virtual void FileStatus(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileStatusHandler.mh"
      FileStatusHandler::file_status_t status
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileStatusHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileStatusHandler.mh"
      const std::string& path
#line 30 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileStatusHandler.h"
      ,
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/FileStatusHandler.mh"
      const std::string& msg
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileStatusHandler.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method FileStatus in base class FileStatusHandler called."); }
#line 36 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/FileStatusHandler.h"
  virtual ~FileStatusHandler() { }
};

#endif // _FILESTATUSHANDLER_H
