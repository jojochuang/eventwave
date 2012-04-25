/*********************************************
*  BufferedTransportServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:08 2012
*********************************************/
#ifndef _BUFFEREDTRANSPORTSERVICECLASS_H
#define _BUFFEREDTRANSPORTSERVICECLASS_H
#include "TransportServiceClass.h"
#include "ServiceClass.h"
#include "ConnectionStatusHandler.h"

#include "TransportServiceClass.h"
#include "TimeUtil.h"

struct TimeValueStat {
  public:
  TimeValueStat() : time(0), value(0) { }
  TimeValueStat(uint64_t t, uint32_t v) : time(t), value(v) { }
  uint64_t time;
  uint32_t value;
};

struct BufferStatistics {
  public:
  BufferStatistics(uint64_t w = 0, uint64_t s = 0, uint64_t ws = 0) :
  window(w), sum(s), windowSum(ws) { }
  typedef mace::deque<TimeValueStat, mace::SoftState> HistoryList;
  uint64_t window;
  uint64_t sum;
  uint64_t windowSum;
  HistoryList history;
  
  void append(uint32_t v) {
    uint64_t now = TimeUtil::timeu();
    update(now);
    history.push_back(TimeValueStat(now, v));
    sum += v;
    windowSum += v;
  }
  
  void update(const uint64_t& now) {
    while (!history.empty() && (now - window > history.front().time)) {
      windowSum -= history.front().value;
      history.pop_front();
    }
  }
  
};

typedef boost::shared_ptr<BufferStatistics> BufferStatisticsPtr;
class BufferedTransportServiceClass : public virtual TransportServiceClass, public virtual ServiceClass {
  public:
  static BufferedTransportServiceClass& NULL_;
  static const char* name; // = "BufferedTransport";
  
  
  
  #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual bool canSend(
      #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 63 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method canSend in base class BufferedTransportServiceClass called."); }
#line 65 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t availableBufferSize(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 70 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method availableBufferSize in base class BufferedTransportServiceClass called."); }
#line 72 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t outgoingBufferedDataSize(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 77 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 79 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t incomingBufferedDataSize(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 84 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method incomingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 86 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t incomingMessageQueueSize(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 91 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 93 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 77 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t incomingMessageQueueSize(registration_uid_t rid = -1) { ABORT("Unimplemented method incomingMessageQueueSize in base class BufferedTransportServiceClass called."); }
#line 96 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual void setWindowSize(
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 101 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint64_t microsec
#line 105 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method setWindowSize in base class BufferedTransportServiceClass called."); }
#line 107 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual void setQueueSize(
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 112 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t size
#line 116 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t threshold = UINT_MAX
#line 120 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method setQueueSize in base class BufferedTransportServiceClass called."); }
#line 122 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual  const BufferStatisticsPtr getStatistics(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 127 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      TransportServiceClass::Connection::type d
#line 131 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method getStatistics in base class BufferedTransportServiceClass called."); }
#line 133 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual void requestToSend(
      #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 138 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method requestToSend in base class BufferedTransportServiceClass called."); }
#line 140 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 82 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t bufferedDataSize(registration_uid_t rid = -1) { ABORT("Unimplemented method bufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 143 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 83 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual bool hasBufferedData(registration_uid_t rid = -1) { ABORT("Unimplemented method hasBufferedData in base class BufferedTransportServiceClass called."); }
#line 146 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 84 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual bool hasOutgoingBufferedData(registration_uid_t rid = -1) { ABORT("Unimplemented method hasOutgoingBufferedData in base class BufferedTransportServiceClass called."); }
#line 149 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 85 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual uint32_t outgoingBufferedDataSize(registration_uid_t rid = -1) { ABORT("Unimplemented method outgoingBufferedDataSize in base class BufferedTransportServiceClass called."); }
#line 152 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual bool routeRTS(
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 157 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 161 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 163 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual bool routeRTS(
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& src
#line 168 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 172 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 176 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) { ABORT("Unimplemented method routeRTS in base class BufferedTransportServiceClass called."); }
#line 178 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  #line 90 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
  virtual void requestFlushedNotification(registration_uid_t rid = -1) { ABORT("Unimplemented method requestFlushedNotification in base class BufferedTransportServiceClass called."); }
#line 181 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  virtual registration_uid_t registerHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ReceiveDataHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ReceiveDataHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ReceiveDataHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(NetworkErrorHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(NetworkErrorHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(NetworkErrorHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual registration_uid_t registerHandler(ConnectionStatusHandler& handler, registration_uid_t rid = -1) { ABORT("registerHandler method not implemented"); }
  virtual void unregisterHandler(ConnectionStatusHandler& handler, registration_uid_t rid = -1) { ABORT("unregisterHandler method not implemented"); }
  void unregisterUniqueHandler(ConnectionStatusHandler& handler) { unregisterHandler(handler); }
  virtual void registerUniqueHandler(ConnectionStatusHandler& handler) { ABORT("registerUniqueHandler method not implemented"); }
  virtual ~BufferedTransportServiceClass() { }
  
  #ifdef MACE_VOODOO
  mace services {
    method_remappings {
      uses {
        downcall_routeRTS(const MaceKey&, const Message& -> const std::string&, registration_uid_t);
        downcall_routeRTS(const MaceKey&, const MaceKey&, const Message& -> const std::string&, registration_uid_t);
      }
    }
  }
  #endif // MACE_VOODOO
};

#include "NumberGen.h"
#include "ScopedLock.h"
#include "ScopedLog.h"
#include "mace.h"
#include "Serializable.h"
#include "XmlRpcCollection.h"

class SynchronousBufferedTransport : public ConnectionStatusHandler {
  
  public:
  
  private:
  BufferedTransportServiceClass& _sc;
  ConnectionStatusHandler& connectionStatusHandler;
  registration_uid_t rid;
  
  uint64_t requestFlushedNotificationFlag;
  pthread_cond_t requestFlushedNotificationSignal;
  
  public:
  SynchronousBufferedTransport(BufferedTransportServiceClass& sc, ConnectionStatusHandler& connectionStatusHandler) : _sc(sc), connectionStatusHandler(connectionStatusHandler), requestFlushedNotificationFlag(0) {
    rid = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
    _sc.registerHandler((ConnectionStatusHandler&)*this, rid);
    pthread_cond_init(&requestFlushedNotificationSignal, 0);
  }
  
  registration_uid_t getRegistrationUid() const {
    return rid;
  }
  
  bool canSend(
      #line 72 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 241 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.canSend(peer, rid);
  }
  
  uint32_t availableBufferSize(
      #line 73 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 249 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.availableBufferSize(peer, rid);
  }
  
  uint32_t outgoingBufferedDataSize(
      #line 74 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 257 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.outgoingBufferedDataSize(peer, rid);
  }
  
  uint32_t incomingBufferedDataSize(
      #line 75 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 265 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.incomingBufferedDataSize(peer, rid);
  }
  
  uint32_t incomingMessageQueueSize(
      #line 76 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 273 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.incomingMessageQueueSize(peer, rid);
  }
  
  uint32_t incomingMessageQueueSize() {
    return _sc.incomingMessageQueueSize(rid);
  }
  
  void setWindowSize(
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 285 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 78 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint64_t microsec
#line 289 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    _sc.setWindowSize(peer, microsec, rid);
  }
  
  void setQueueSize(
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 297 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t size
#line 301 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 79 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      uint32_t threshold = UINT_MAX
#line 305 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    _sc.setQueueSize(peer, size, threshold, rid);
  }
  
  const BufferStatisticsPtr getStatistics(
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 313 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 80 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      TransportServiceClass::Connection::type d
#line 317 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.getStatistics(peer, d, rid);
  }
  
  void requestToSend(
      #line 81 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& peer
#line 325 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    _sc.requestToSend(peer, rid);
  }
  
  uint32_t bufferedDataSize() {
    return _sc.bufferedDataSize(rid);
  }
  
  bool hasBufferedData() {
    return _sc.hasBufferedData(rid);
  }
  
  bool hasOutgoingBufferedData() {
    return _sc.hasOutgoingBufferedData(rid);
  }
  
  uint32_t outgoingBufferedDataSize() {
    return _sc.outgoingBufferedDataSize(rid);
  }
  
  bool routeRTS(
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 349 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 87 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 353 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.routeRTS(dest, s, rid);
  }
  
  bool routeRTS(
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& src
#line 361 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 88 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const MaceKey& dest
#line 365 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      ,
      #line 89 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/BufferedTransportServiceClass.mh"
      const std::string& s
#line 369 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
  ) {
    return _sc.routeRTS(src, dest, s, rid);
  }
  
  void requestFlushedNotification() {
    ScopedLock sl(BaseMaceService::synclock);
    requestFlushedNotificationFlag = TimeUtil::timeu();
    _sc.requestFlushedNotification(rid);
  }
  
  void clearToSend(
      #line 32 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/ConnectionStatusHandler.mh"
      const MaceKey& peer
#line 383 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/BufferedTransportServiceClass.h"
      , registration_uid_t rid = -1) {
    connectionStatusHandler.clearToSend(peer, rid);
  }
  
  void flush() {
    ADD_SELECTORS("SynchronousBufferedTransport::flush");
    ScopedLog __scoped_log(selector, 0, selectorId->compiler, true, true, true, PIP);
    ScopedLock sl(BaseMaceService::synclock);
    
    _sc.requestFlushedNotification(rid);
    pthread_cond_wait(&requestFlushedNotificationSignal, &BaseMaceService::synclock);
  } // flush
  
  void notifyFlushed(registration_uid_t rid = -1)  {
    ADD_SELECTORS("SynchronousBufferedTransport::notifyFlushed");
    ScopedLock sl(BaseMaceService::synclock);
    
    if (requestFlushedNotificationFlag) {
      connectionStatusHandler.notifyFlushed(rid);
      uint64_t now = TimeUtil::timeu();
      uint64_t diff = now - requestFlushedNotificationFlag;
      requestFlushedNotificationFlag = 0;
      maceout << diff << Log::endl;
    }
    pthread_cond_broadcast(&requestFlushedNotificationSignal);
  } // notifyFlushed
};


#endif // _BUFFEREDTRANSPORTSERVICECLASS_H
