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
  typedef std::vector<pthread_t> PthreadVector;
  // SHYOO : Declaration of PthreadVector )

protected:
  typedef mace::map<SockAddr, MaceAddr> SourceTranslationMap;
  enum transport_upcall_t { UPCALL_DELIVER, UPCALL_ERROR, UPCALL_CTS };
  static const int TRANSPORT_TRACE_DELIVER = 1;
  static const int TRANSPORT_TRACE_ERROR = 2;
  static const int TRANSPORT_TRACE_CTS = 3;
  static const int TRANSPORT_TRACE_FLUSH = 4;

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
  static const uint32_t DEFAULT_DELIVER_THREAD_NUM = 2;
  // SHYOO : Number of deliverThread }}

  // SHYOO
  struct DeliverDataStruct {
    ReceiveDataHandler h;
    MaceKey src;
    MaceKey dest;
    std::string s;
    registration_uid_t rid;

    DeliverDataStruct() {}

    DeliverDataStruct(ReceiveDataHandler& h, MaceKey& src, MaceKey& dest,
		   std::string& s, registration_uid_t rid) :
      h(h), src(src), dest(dest), s(s), rid(rid) {
    }
  }; // struct DeliverDataStruct

  typedef std::vector<DeliverDataStruct> DeliverDataStructVector;

  PthreadVector deliverDataThread;		// FIXME : Is it correct to be static?

  static DeliverDataStructVector dataVector;

protected:
  static void* startDeliverThread(void* arg);
  virtual int getSockType() = 0;
  virtual void runDeliverThread() = 0;
  virtual void closeConnections() = 0;
  // SHYOO : Following method is used to create multiple deliver data thread {{
  static void* startDeliverDataMulti(void *arg);
  virtual bool deliverDataMulti(const std::string& shdr, mace::string& s,
			   MaceKey* src = 0, NodeSet* suspended = 0);
  // SHYOO : Following method is used to create multiple deliver data thread }}
  virtual bool deliverData(const std::string& shdr, mace::string& s,
			   MaceKey* src = 0, NodeSet* suspended = 0);
  virtual bool acceptConnection(const MaceAddr& maddr, const mace::string& t);
  virtual bool sendData(const MaceAddr& src, const MaceKey& dest,
			const MaceAddr& nextHop, registration_uid_t rid,
			const std::string& ph, const std::string& s, bool checkQueueSize, bool rts) = 0;
  virtual void unregisterHandlers();

  void lock() const { ASSERT(pthread_mutex_lock(&tlock) == 0); }
  void unlock() const { ASSERT(pthread_mutex_unlock(&tlock) == 0); }
  void lockd() { ASSERT(pthread_mutex_lock(&dlock) == 0); }
  void unlockd() { ASSERT(pthread_mutex_unlock(&dlock) == 0); }
  void lockc() const { ASSERT(pthread_mutex_lock(&conlock) == 0); }
  void unlockc() const { ASSERT(pthread_mutex_unlock(&conlock) == 0); }
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

  mutable pthread_mutex_t conlock;

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

}; // BaseTransport

typedef boost::shared_ptr<BaseTransport> BaseTransportPtr;

#endif // BASE_TRANSPORT_H
