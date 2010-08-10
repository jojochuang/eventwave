/* 
 * BaseTransport.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, James W. Anderson, Charles Killian
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the names of Duke University nor The University of
 *      California, San Diego, nor the names of the authors or contributors
 *      may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
#ifndef BASE_TRANSPORT_H
#define BASE_TRANSPORT_H

#include <boost/shared_ptr.hpp>

#include "LockedSignal.h"
#include "SockUtil.h"
#include "ScopedTimer.h"
#include "CircularQueue.h"

#include "TransportHeader.h"
#include "BufferedTransportServiceClass.h"
#include "ConnectionAcceptanceServiceClass.h"
#include "Collections.h"

#include "Pipeline.h"

#include "mace-macros.h"

#ifdef STUPID_FD_SET_CONST_HACK
#define CONST_ISSET 
#else
#define CONST_ISSET const
#endif


class DeliveryData
{
  public:
    std::string shdr;
    mace::string s;
    MaceKey* src;
    NodeSet* suspended;

  DeliveryData( std::string shdr, mace::string s, MaceKey* src = 0, NodeSet* suspended = 0 )
    : shdr(shdr), s(s), src(src), suspended(suspended) {};

  DeliveryData() {
    shdr.clear();
    s.clear();
    src = 0;
    suspended = 0;
  }

  ~DeliveryData() {}
};


class BaseTransport : public virtual TransportServiceClass,
		      public virtual ConnectionAcceptanceServiceClass {
public:
  class SocketException : public Exception {
  public:
    SocketException(const std::string& m) : Exception(m) { }
    void rethrow() const { throw *this; }
  }; // SocketException

  class BindException : public SocketException {
  public:
    BindException(const std::string& m) : SocketException(m) { }
    void rethrow() const { throw *this; }
  }; // BindException

public:
  typedef mace::map<registration_uid_t, ReceiveDataHandler*, mace::SoftState> DataHandlerMap;
  typedef mace::map<registration_uid_t, NetworkErrorHandler*, mace::SoftState> NetworkHandlerMap;
  typedef mace::map<registration_uid_t, ConnectionStatusHandler*, mace::SoftState> ConnectionHandlerMap;
  typedef mace::map<registration_uid_t, ConnectionAcceptanceHandler*, mace::SoftState> AcceptanceHandlerMap;
  typedef CircularQueue<registration_uid_t> RegIdQueue;

  // SHYOO : Declaration of PthreadVector (
  //typedef std::vector<pthread_t> PthreadVector;
  // SHYOO : Declaration of PthreadVector )

protected:
  typedef mace::map<SockAddr, MaceAddr> SourceTranslationMap;
  enum transport_upcall_t { UPCALL_DELIVER, UPCALL_ERROR, UPCALL_CTS };
  static const int TRANSPORT_TRACE_DELIVER = 1;
  static const int TRANSPORT_TRACE_ERROR = 2;
  static const int TRANSPORT_TRACE_CTS = 3;
  static const int TRANSPORT_TRACE_FLUSH = 4;
  // SHYOO {{
  static const int DEFAULT_DELIVER_THREAD_NUM = 1;
  // SHYOO }}

public:
  BaseTransport(int portoff, MaceAddr addr = SockUtil::NULL_MACEADDR,
		int backlog = SOMAXCONN,
		SockAddr forwarder = SockUtil::NULL_MSOCKADDR,
		SockAddr local = SockUtil::NULL_MSOCKADDR);
  virtual ~BaseTransport();

  virtual bool isRunning() {
    if (!running && doClose) {
      closeSockets();
    }
    return starting || running;
  } // isRunning

  virtual void addSockets(fd_set& rset, fd_set& wset, socket_t& selectMax) {
    //     Log::log("BaseTransport::addSockets") << "Considering Adding " << transportSocket << " to sockets." << Log::endl;
    if (running) {
      //       Log::log("BaseTransport::addSockets") << "Yes, Adding " << transportSocket << " to sockets." << Log::endl;
      FD_SET(transportSocket, &rset);
      selectMax = std::max(transportSocket, selectMax);
    }
  } // addSockets


  const SockAddr& getNextHop(const MaceAddr& dest) const {
    if (!forwardingHost.isNull()) {
      return forwardingHost;
    }

    if ((!dest.proxy.isNull()) &&
	(dest.proxy != localAddr.local)) {
      if (!disableTranslations) {
	proxying = true;
      }
      // send it to the proxy
      return dest.proxy;
    }
    return dest.local;
  } // getNextHop

  virtual MaceKey getLocalAddress(registration_uid_t rid = -1) const {
    return srcKey;
  } // getLocalAddress

  virtual bool route(const MaceKey& src, const MaceKey& dest,
		     const std::string& s, bool rts, registration_uid_t rid) {
    return route(src.getMaceAddr(), dest, s, rts, rid);
  } // route

  virtual bool route(const MaceKey& dest, const std::string& s, bool rts,
		     registration_uid_t rid) {
    return route(srcAddr, dest, s, rts, rid);
  } // route

  virtual void setAuthoritativeConnectionAcceptor(registration_uid_t rid = -1);
  virtual void setConnectionToken(const mace::string& token,
				  registration_uid_t rid = -1);
  virtual void doIO(CONST_ISSET fd_set& rset, CONST_ISSET fd_set& wset,
		    uint64_t selectTime) = 0;

  virtual void run() throw(SocketException);
  virtual void shutdown();
  virtual void maceInit();
  virtual void maceExit();
  virtual void freeSockets() = 0;

  virtual registration_uid_t registerHandler(ReceiveDataHandler& h,
					     registration_uid_t rid = -1);
  virtual registration_uid_t registerHandler(NetworkErrorHandler& h,
					     registration_uid_t rid = -1);
  virtual registration_uid_t registerHandler(ConnectionStatusHandler& h,
					     registration_uid_t rid = -1);
  virtual registration_uid_t registerHandler(ConnectionAcceptanceHandler& h,
					     registration_uid_t rid = -1);
  virtual void unregisterHandler(ReceiveDataHandler& h,
				 registration_uid_t rid = -1);
  virtual void unregisterHandler(NetworkErrorHandler& h,
				 registration_uid_t rid = -1);
  virtual void unregisterHandler(ConnectionStatusHandler& h,
				 registration_uid_t rid = -1);
  virtual void unregisterHandler(ConnectionAcceptanceHandler& h,
				 registration_uid_t rid = -1);
  virtual void registerUniqueHandler(ReceiveDataHandler& h);
  virtual void registerUniqueHandler(NetworkErrorHandler& h);
  virtual void registerUniqueHandler(ConnectionStatusHandler& h);
  virtual void registerUniqueHandler(ConnectionAcceptanceHandler& h);

  void setPipeline(PipelineElement* p) {
    pipeline = p;
  }

public:
  static const uint64_t DEFAULT_WINDOW_SIZE = 5*1000*1000;
  // SHYOO : Number of deliverThread {{
//  static const uint32_t DEFAULT_DELIVER_THREAD_NUM = 2;
  // SHYOO : Number of deliverThread }}

  // SHYOO
//  struct DeliverDataStruct {
//    ReceiveDataHandler h;
//    MaceKey src;
//    MaceKey dest;
//    std::string s;
//    registration_uid_t rid;
//
//    DeliverDataStruct() {}
//
//    DeliverDataStruct(ReceiveDataHandler& h, MaceKey& src, MaceKey& dest,
//		   std::string& s, registration_uid_t rid) :
//      h(h), src(src), dest(dest), s(s), rid(rid) {
//    }
//  }; // struct DeliverDataStruct

//  typedef std::vector<DeliverDataStruct> DeliverDataStructVector;

//  PthreadVector deliverDataThread;		// FIXME : Is it correct to be static?

//  static DeliverDataStructVector dataVector;

protected:
  static void* startDeliverThread(void* arg);
  virtual int getSockType() = 0;
  virtual void runDeliverThread() = 0;
  virtual void closeConnections() = 0;
  // SHYOO : Following method is used to create multiple deliver data thread {{
  /* Keynote : Message를 deliver, 즉 받아들이는 경우를 parallize 해야한다.
     보내는 경우는 크게 중요하지 않은데, send 시의 시간은 그리 많이 걸리지 않기 때문이다.
     하지만 받는 경우는 그렇지 않다. [1][2] 2개의 메시지를 동시에 받았는데, 이 메시지를 순차적으로 하나씩 처리해서 윗단으로 올려보내야 한다.
     그런데 [1] -> [1].receivehandler->deliver->sleep(100) -> [1].return -> [2] -> [2].receivehandler->deliver->sleep(100) -> ...
     이런 식으로 순차적으로 처리를 하기 때문에 엄청난 시간이 걸리는 것이다!!!
     따라서, 우리가 할 일은 메시지를 받게 되었다면 이를 thread에 교대로 써서 집어넣는 것이다.
     이 각각의 작업, 즉 {[1] -> [1].receivehandler->deliver->sleep(100) -> [1].return} 은 deliverData() 가 담당하고 있다.
     따라서 이 deliverData()를 동시에 수행할 수 있도록 thread별로 할당해서 parallelize 하면 된다.
     deliverDataMulti를 이 wrapper class라고 하자. 그럼 이 클래스가 하는 일은,
     1. init()
       가장 먼저 수행되며, 필요한 thread들을 개수대로 초기화하는 역할을 한다. 각각의 thread들은 deliverThr[0] [1] 식으로 명명된다.
       또한 iterator를 가지며, 이것은 다음에 데이터가 들어왔을 때 몇 번째 deliverThr[]를 호출해야 하는지를 가르킨다.
     2. deliverDataMulti()
       - 수행시 먼저 lock() 을 해서 deliverData() 호출 자체는 동시에 이루어지지 않도록 한다.
       - iterator를 체크해서 해당 deliverThr[0]->deliver( variables ... ) 의 형식으로 넘겨서 호출하도록 한다.
       - lock()를 해제한다.
  */
     
//  static void* startDeliverDataMulti(void *arg);
//  virtual bool deliverDataMulti(const std::string& shdr, mace::string& s,
//			   MaceKey* src = 0, NodeSet* suspended = 0);
  // SHYOO : Following method is used to create multiple deliver data thread }}
public:
  virtual bool deliverData(const std::string& shdr, mace::string& s,
			   MaceKey* src = 0, NodeSet* suspended = 0);
protected:
  virtual bool acceptConnection(const MaceAddr& maddr, const mace::string& t);
  virtual bool sendData(const MaceAddr& src, const MaceKey& dest,
			const MaceAddr& nextHop, registration_uid_t rid,
			const std::string& ph, const std::string& s, bool checkQueueSize, bool rts) = 0;
  virtual void unregisterHandlers();

  void lock() const { ASSERT(pthread_mutex_lock(&tlock) == 0); }
  void unlock() const { ASSERT(pthread_mutex_unlock(&tlock) == 0); }
  void lockd() { ASSERT(pthread_mutex_lock(&dlock) == 0); }
  void unlockd() { ASSERT(pthread_mutex_unlock(&dlock) == 0); }
  void lockc() const { ASSERT(pthread_mutex_lock(&conlock) == 0); } // lock for connection
  void unlockc() const { ASSERT(pthread_mutex_unlock(&conlock) == 0); }
  void lockdt() const { ASSERT(pthread_mutex_lock(&dtlock) == 0); } // lock for deliver thread
  void unlockdt() const { ASSERT(pthread_mutex_unlock(&dtlock) == 0); }
  void waitForDeliverSignal() {
//     ADD_SELECTORS("BaseTransport::waitForDeliverSignal");
//     maceout << "waiting for deliver signal" << Log::endl;
    dsignal.wait();
//     maceout << "received signal" << Log::endl;
  }
  void signalDeliver() {
//     ADD_SELECTORS("BaseTransport::signalDeliver");
//     maceout << "signaling deliver" << Log::endl;
    dsignal.signal();
  }

  virtual bool route(const MaceAddr& src, const MaceKey& dest,
		     const std::string& s, bool rts, registration_uid_t rid) {
//     ADD_SELECTORS("BaseTransport::route");
    ScopedTimer st(routeTime);
    std::string str = s;
    std::string ph;

    if (pipeline) {
      pipeline->routeData(dest, ph, str, rid);
      if (str.empty()) {
        return false;
      }
    }

//     macedbg(1) << "Routing Message of size " << s.size() << " from " << localKey << " to " << dest << Log::endl;
    // SANITY_CHECK
//     DataHandlerMap::iterator i = dataHandlers.find(rid);
//     if (i == dataHandlers.end()) {
// //       maceerr << "no handler registered with " << rid << Log::endl;
//       return false;
//     }
  
    ASSERT(running);

    bool r = sendData(src, dest, dest.getMaceAddr(), rid, ph, str, true, rts);
//     traceout << r << Log::end;
    return r;
  } // route

private:

  void setupSocket();
  void closeSockets();

private:
  uint initCount;

protected:
  uint16_t port; // baseport
  uint32_t saddr;
  uint16_t portOffset;
  MaceAddr localAddr;
  MaceKey localKey;
  MaceAddr srcAddr;
  MaceKey srcKey;
  int backlog;
  SockAddr forwardingHost;
  SockAddr localHost;

  socket_t transportSocket;

  bool starting;
  bool running;
  bool shuttingDown;
  bool doClose;
  mutable bool proxying;

  mutable pthread_mutex_t tlock;

  mutable pthread_mutex_t conlock;    // lock for connection
  mutable pthread_mutex_t dtlock;     // lock for deliver thread

  LockedSignal dsignal;
  pthread_t deliverThread;
  pthread_mutex_t dlock;

  SourceTranslationMap translations;
  bool disableTranslations;

  mace::string connectionToken;
  ConnectionAcceptanceHandler* authoritativeConnectionAcceptor;
  registration_uid_t authoritativeConnectionAcceptorRid;

  DataHandlerMap dataHandlers;
  RegIdQueue dataUnreg;
  NetworkHandlerMap errorHandlers;
  RegIdQueue errorUnreg;
  ConnectionHandlerMap connectionHandlers;
  RegIdQueue connectionUnreg;
  AcceptanceHandlerMap acceptanceHandlers;
  RegIdQueue acceptanceUnreg;

  TransportHeader hdr;

  uint64_t routeTime;
  uint64_t sendDataTime;
  uint64_t doIOTime;

  PipelineElement* pipeline;

public:
  // SHYOO

      class DeliveryTransport
      {
        private:
          uint current_id;    // current_id
          uint threadCount;
          std::vector<DeliveryData> data;
          std::vector<BaseTransport*> obj;
          std::vector<bool> is_idle;
          std::vector<bool> is_message;
          std::vector<pthread_mutex_t> lock;
          pthread_mutex_t slock;
          // SHYOO: 함수 포인터에 대한 멤버 변수:
          bool (BaseTransport::**pFunc)( const std::string&, mace::string&, MaceKey*, NodeSet* );

      public:
        // FIXME : 추후 1개 이상의 thread를 만들도록 할 것.
        DeliveryTransport(uint16_t numThreads = 1)
          : threadCount(numThreads)
        {
          lock.reserve(numThreads);

          pFunc = new (bool (BaseTransport::*[numThreads])( const std::string&, mace::string&, MaceKey*, NodeSet* ));

          for(uint16_t i=0; i<numThreads; i++ )
          {
            data.push_back(DeliveryData());    // This should be modified in first!!
            is_idle.push_back(true);
            is_message.push_back(false);
            obj.push_back(0);
            pthread_mutex_init(&lock[i], 0);
          }

          pthread_mutex_init(&slock, 0);
          current_id = 0;
        }

        ~DeliveryTransport()
        {
          delete [] pFunc;

          for(uint16_t i=0; i<threadCount; i++ )
          {
            pthread_mutex_destroy(&lock[i]);
          }
          pthread_mutex_destroy(&slock);
        }

        void setMessage( const std::string& shdr, mace::string& s, BaseTransport *base_obj, bool(BaseTransport::*fun)(const std::string&, mace::string&, MaceKey*, NodeSet*), MaceKey* src = 0, NodeSet* suspended = 0)
        {
          locks();
          assert(threadCount > 0);
          assert(current_id < threadCount);
          assert(current_id >= 0 );

          setLock(current_id);    // set lock so to guarantee existing runDeliver() to be exited earlier.

          data[current_id].shdr = shdr;
          data[current_id].s = s;
          data[current_id].src = src;
          data[current_id].suspended = suspended;
          obj[current_id] = base_obj;
          pFunc[current_id] = fun;
          is_message[current_id] = true;

          current_id = (current_id+1)%threadCount;
          unlocks();
        }

        bool isIdle( uint id )
        {
          return is_idle[id] && is_message[id];
        }

        void runDeliver( uint id )
        {
          is_idle[id] = false;
          //bool ret = deliverData( data[id].shdr, data[id].s, data[id].src, data[id].suspended );

          /*bool ret = */(obj[id]->*pFunc[id])( data[id].shdr, data[id].s, data[id].src, data[id].suspended );

          is_message[id] = false;
          releaseLock(id);
          is_idle[id] = true;

          // CHECKME : ret is not returned. Please check whether the returned value is used or not.
        }

        protected:
          void setLock( uint16_t id ) { ASSERT(pthread_mutex_lock(&lock[id]) == 0); }
          void releaseLock( uint16_t id ) { ASSERT(pthread_mutex_unlock(&lock[id]) == 0); }
          void locks() { ASSERT(pthread_mutex_lock(&slock) == 0); }
          void unlocks() { ASSERT(pthread_mutex_lock(&slock) == 0); }
      };

  DeliveryTransport dt;

  void deliverSetMessage( const std::string& shdr, mace::string& s, BaseTransport *base_obj, bool(BaseTransport::*fun)(const std::string&, mace::string&, MaceKey*, NodeSet*), MaceKey* src = 0, NodeSet* suspended = 0)
  {
    dt.setMessage(shdr, s, base_obj, &BaseTransport::deliverData, src, suspended );
  }

}; // BaseTransport

typedef boost::shared_ptr<BaseTransport> BaseTransportPtr;

#endif // BASE_TRANSPORT_H
