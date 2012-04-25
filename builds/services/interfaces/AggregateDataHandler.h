/*********************************************
*  AggregateDataHandler.h
*  Mace generated on:
*  Tue Apr 10 10:09:21 2012
*********************************************/
#ifndef _AGGREGATEDATAHANDLER_H
#define _AGGREGATEDATAHANDLER_H
#include "massert.h"
#include "MaceTypes.h"

#include "mstring.h"
#include "mhash_map.h"
#include "MaceTypes.h"

// maps data -> generic blob---set by application
// typedef mace::hash_map<std::string, std::string, hash_string> AggregateBlobMap;

typedef mace::hash_map<MaceKey, int> AggregateNodeCountMap;

// maps node ids -> blob maps
typedef mace::hash_map<MaceKey, std::string> AggregateNodeBlobMap;
class AggregateDataHandler  {
  public:
  static AggregateDataHandler& NULL_;
  static const char* name; // = "AggregateData";
  
  
  
  #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
  virtual void collectAggregateData(
      #line 48 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      channel_id_t channelId
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 49 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      const AggregateNodeBlobMap& nmap
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 50 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      std::string& aggregate_data
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 51 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      const AggregateNodeCountMap& cmap
#line 46 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      int& count
#line 50 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      bool subscribed
#line 54 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      , registration_uid_t rid = -1)
  #line 52 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
  { }
#line 58 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
  
#line 60 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
  #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
  virtual void distributeAggregateData(
      #line 55 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      channel_id_t channelId
#line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 56 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      const std::string& distribute_data
#line 69 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 57 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      AggregateNodeBlobMap& child_map
#line 73 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 58 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      const int count
#line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 59 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      AggregateNodeCountMap& cmap
#line 81 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      ,
      #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
      const MaceKey& distributor
#line 85 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
      , registration_uid_t rid = -1)
  #line 60 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/AggregateDataHandler.mh"
  { }
#line 89 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
  
#line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/AggregateDataHandler.h"
  virtual ~AggregateDataHandler() { }
};

#endif // _AGGREGATEDATAHANDLER_H
