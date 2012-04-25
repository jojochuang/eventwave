/*********************************************
*  DHTServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:19 2012
*********************************************/
#ifndef _DHTSERVICECLASS_H
#define _DHTSERVICECLASS_H
#include "ServiceClass.h"
#include "DHTDataHandler.h"


class DHTServiceClass : public virtual ServiceClass {
  public:
  static DHTServiceClass& NULL_;
  static const char* name; // = "DHT";
  
  
  
  #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
  virtual void containsKey(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 24 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method containsKey in base class DHTServiceClass called."); }
#line 26 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
  virtual void get(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 31 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method get in base class DHTServiceClass called."); }
#line 33 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
  virtual void put(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 38 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const std::string& value
#line 42 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method put in base class DHTServiceClass called."); }
#line 44 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
  virtual void remove(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 49 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method remove in base class DHTServiceClass called."); }
#line 51 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  virtual registration_uid_t registerHandler(DHTDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(DHTDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(DHTDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(DHTDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~DHTServiceClass() { }
};

#include "NumberGen.h"
#include "ScopedLock.h"
#include "ScopedLog.h"
#include "mace.h"
#include "Serializable.h"
#include "XmlRpcCollection.h"

class SynchronousDHT : public DHTDataHandler {
  
  public:
  class SyncContainsKeyResult : public mace::Serializable {
    public:
    SyncContainsKeyResult() { }
    SyncContainsKeyResult(
        #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
        const MaceKey& key
#line 75 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
        ,
        #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
        bool result
#line 79 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
    ) : key(key), result(result) { }
    MaceKey key;
    bool result;
    
    void serialize(std::string& str) const { ABORT("serialize method not implemented"); }
    int deserialize(std::istream& in) throw(mace::SerializationException) { ABORT("deserialize method not implemented"); }
    void serializeXML_RPC(std::string& s) const throw(mace::SerializationException) {
      s.append("<struct>");
      s.append("<member><name>key</name><value>");
      mace::serializeXML_RPC(s, &key, key);
      s.append("</value></member>");
      s.append("<member><name>result</name><value>");
      mace::serializeXML_RPC(s, &result, result);
      s.append("</value></member>");
      
      s.append("</struct>");
    }
    int deserializeXML_RPC(std::istream& in) throw(mace::SerializationException) {
      std::istream::pos_type __offset = in.tellg();
      in >> skipws;
      mace::SerializationUtil::expect(in, "<struct>");
      in >> skipws;
      for (size_t _i = 0; _i < 2; _i++) {
        mace::SerializationUtil::expect(in, "<member>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "<name>");
        std::string _k = mace::SerializationUtil::get(in, '<');
        mace::SerializationUtil::expect(in, "</name>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "<value>");
        if (_k == "key") {
          mace::deserializeXML_RPC(in, &key, key);
        }
        else if (_k == "result") {
          mace::deserializeXML_RPC(in, &result, result);
        }
        else {
          throw mace::SerializationException("unknown member: " + _k);
        }
        mace::SerializationUtil::expect(in, "</value>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "</member>");
        in >> skipws;
      }
      
      mace::SerializationUtil::expect(in, "</struct>");
      return in.tellg() - __offset;
    }
    
  };
  
  class SyncGetResult : public mace::Serializable {
    public:
    SyncGetResult() { }
    SyncGetResult(
        #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
        const MaceKey& key
#line 137 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
        ,
        #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
        const std::string& value
#line 141 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
        ,
        #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
        bool found
#line 145 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
    ) : key(key), value(value), found(found) { }
    MaceKey key;
    std::string value;
    bool found;
    
    void serialize(std::string& str) const { ABORT("serialize method not implemented"); }
    int deserialize(std::istream& in) throw(mace::SerializationException) { ABORT("deserialize method not implemented"); }
    void serializeXML_RPC(std::string& s) const throw(mace::SerializationException) {
      s.append("<struct>");
      s.append("<member><name>key</name><value>");
      mace::serializeXML_RPC(s, &key, key);
      s.append("</value></member>");
      s.append("<member><name>value</name><value>");
      mace::serializeXML_RPC(s, &value, value);
      s.append("</value></member>");
      s.append("<member><name>found</name><value>");
      mace::serializeXML_RPC(s, &found, found);
      s.append("</value></member>");
      
      s.append("</struct>");
    }
    int deserializeXML_RPC(std::istream& in) throw(mace::SerializationException) {
      std::istream::pos_type __offset = in.tellg();
      in >> skipws;
      mace::SerializationUtil::expect(in, "<struct>");
      in >> skipws;
      for (size_t _i = 0; _i < 3; _i++) {
        mace::SerializationUtil::expect(in, "<member>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "<name>");
        std::string _k = mace::SerializationUtil::get(in, '<');
        mace::SerializationUtil::expect(in, "</name>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "<value>");
        if (_k == "key") {
          mace::deserializeXML_RPC(in, &key, key);
        }
        else if (_k == "value") {
          mace::deserializeXML_RPC(in, &value, value);
        }
        else if (_k == "found") {
          mace::deserializeXML_RPC(in, &found, found);
        }
        else {
          throw mace::SerializationException("unknown member: " + _k);
        }
        mace::SerializationUtil::expect(in, "</value>");
        in >> skipws;
        mace::SerializationUtil::expect(in, "</member>");
        in >> skipws;
      }
      
      mace::SerializationUtil::expect(in, "</struct>");
      return in.tellg() - __offset;
    }
    
  };
  
  
  private:
  DHTServiceClass& _sc;
  DHTDataHandler& dHTDataHandler;
  registration_uid_t rid;
  
  typedef mace::map<MaceKey, boost::shared_ptr<SyncGetResult>, mace::SoftState> SyncGetResultMap;
  typedef mace::map<MaceKey, uint64_t, mace::SoftState> SyncGetResultAsyncMap;
  SyncGetResultMap getResults;
  SyncGetResultAsyncMap getFlags;
  pthread_cond_t getSignal;
  
  typedef mace::map<MaceKey, boost::shared_ptr<SyncContainsKeyResult>, mace::SoftState> SyncContainsKeyResultMap;
  typedef mace::map<MaceKey, uint64_t, mace::SoftState> SyncContainsKeyResultAsyncMap;
  SyncContainsKeyResultMap containsKeyResults;
  SyncContainsKeyResultAsyncMap containsKeyFlags;
  pthread_cond_t containsKeySignal;
  
  public:
  SynchronousDHT(DHTServiceClass& sc, DHTDataHandler& dHTDataHandler) : _sc(sc), dHTDataHandler(dHTDataHandler) {
    rid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
    _sc.registerHandler((DHTDataHandler&)*this, rid);
    pthread_cond_init(&containsKeySignal, 0);
    pthread_cond_init(&getSignal, 0);
  }
  
  registration_uid_t getRegistrationUid() const {
    return rid;
  }
  
  void containsKey(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 237 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    ScopedLock sl(BaseMaceService::synclock);
    
    ASSERT(!containsKeyFlags.containsKey(key));
    containsKeyFlags[key] = 0;
    _sc.containsKey(key, rid);
  }
  
  void get(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 249 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    ScopedLock sl(BaseMaceService::synclock);
    
    ASSERT(!getFlags.containsKey(key));
    getFlags[key] = 0;
    _sc.get(key, rid);
  }
  
  void put(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 261 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const std::string& value
#line 265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    _sc.put(key, value, rid);
  }
  
  void remove(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    _sc.remove(key, rid);
  }
  
  boost::shared_ptr<SyncContainsKeyResult> syncContainsKey(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 281 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    ADD_SELECTORS("SynchronousDHT::syncContainsKey");
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true, PIP);
    ScopedLock sl(BaseMaceService::synclock);
    
    while (containsKeyFlags.containsKey(key)) {
      pthread_cond_wait(&containsKeySignal, &BaseMaceService::synclock);
    }
    containsKeyFlags[key] = TimeUtil::timeu();
    _sc.containsKey(key, rid);
    while (!containsKeyResults.containsKey(key)) {
      pthread_cond_wait(&containsKeySignal, &BaseMaceService::synclock);
    }
    boost::shared_ptr<SyncContainsKeyResult> p = containsKeyResults[key];
    containsKeyResults.erase(key);
    containsKeyFlags.erase(key);
    pthread_cond_broadcast(&containsKeySignal);
    return p;
  } // syncContainsKey
  boost::shared_ptr<SyncGetResult> syncGet(
      #line 33 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTServiceClass.mh"
      const MaceKey& key
#line 304 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
  ) {
    ADD_SELECTORS("SynchronousDHT::syncGet");
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true, PIP);
    ScopedLock sl(BaseMaceService::synclock);
    
    while (getFlags.containsKey(key)) {
      pthread_cond_wait(&getSignal, &BaseMaceService::synclock);
    }
    getFlags[key] = TimeUtil::timeu();
    _sc.get(key, rid);
    while (!getResults.containsKey(key)) {
      pthread_cond_wait(&getSignal, &BaseMaceService::synclock);
    }
    boost::shared_ptr<SyncGetResult> p = getResults[key];
    getResults.erase(key);
    getFlags.erase(key);
    pthread_cond_broadcast(&getSignal);
    return p;
  } // syncGet
  
  void dhtGetResult(
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const MaceKey& key
#line 328 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      ,
      #line 35 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const std::string& value
#line 332 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      ,
      #line 36 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      bool found
#line 336 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1)  {
    ADD_SELECTORS("SynchronousDHT::dhtGetResult");
    ScopedLock sl(BaseMaceService::synclock);
    
    SyncGetResultAsyncMap::iterator i = getFlags.find(key);
    if (i == getFlags.end()) {
      ABORT("Cannot find key in flag map");
    }
    if (i->second == 0) {
      dHTDataHandler.dhtGetResult(key, value, found, rid);
      getFlags.erase(i);
    }
    else {
      getResults[key] = boost::shared_ptr<SyncGetResult>(new SyncGetResult(key, value, found));
      uint64_t now = TimeUtil::timeu();
      uint64_t diff = now - i->second;
      maceout << diff << " " << key << Log::endl;
      pthread_cond_broadcast(&getSignal);
    }
  } // dhtGetResult
  
  void dhtContainsKeyResult(
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      const MaceKey& key
#line 361 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      ,
      #line 34 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/DHTDataHandler.mh"
      bool result
#line 365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/DHTServiceClass.h"
      , registration_uid_t rid = -1)  {
    ADD_SELECTORS("SynchronousDHT::dhtContainsKeyResult");
    ScopedLock sl(BaseMaceService::synclock);
    
    SyncContainsKeyResultAsyncMap::iterator i = containsKeyFlags.find(key);
    if (i == containsKeyFlags.end()) {
      ABORT("Cannot find key in flag map");
    }
    if (i->second == 0) {
      dHTDataHandler.dhtContainsKeyResult(key, result, rid);
      containsKeyFlags.erase(i);
    }
    else {
      containsKeyResults[key] = boost::shared_ptr<SyncContainsKeyResult>(new SyncContainsKeyResult(key, result));
      uint64_t now = TimeUtil::timeu();
      uint64_t diff = now - i->second;
      maceout << diff << " " << key << Log::endl;
      pthread_cond_broadcast(&containsKeySignal);
    }
  } // dhtContainsKeyResult
};


#endif // _DHTSERVICECLASS_H
