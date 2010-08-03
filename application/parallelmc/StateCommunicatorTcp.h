#ifndef __STATE_COMMUNICATOR_TCP__
#define __STATE_COMMUNICATOR_TCP__

#include <cassert>
#include <cstring>
#include <pthread.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "StateCommunicator.h"
#include "TcpTransport.h"
#include "TcpTransport-init.h"
#include "TransportCallback.h"



namespace macemc {
  template <typename T>
  class StateCommunicatorTcp : public StateCommunicator<T> {
  private:
    BufferedTransportServiceClass *transport;
    TransportCallback tcb;

    // My destination's address
    MaceKey dest;

    unsigned count;
    pthread_mutex_t putLock;
    pthread_cond_t putReady;

    pthread_mutex_t receiveLock;
    pthread_cond_t receiveReady;

    StateCommunicatorTcp() {
      assert(false);
    }

    int drainMessageQueue(T *dataPtr) {
      int recvCount = 0;

      while (tcb.hasMessage()) {
        T demarshaledMessage(tcb.getNext());
        Log::log("InterNode") << "Receiving message of type " << demarshaledMessage.get_type() << " from node " << demarshaledMessage.get_from_node() << Log::endl;
        memcpy(dataPtr, &demarshaledMessage, sizeof(T));
        dataPtr++;
        recvCount++;
      }

      if (recvCount > 0) {
        Log::log("InterNode") << "Received " << recvCount << " messages." << Log::endl;
      }

      return recvCount;
    }

  public:
    StateCommunicatorTcp(unsigned capacity, int node0, int proc0, int node1, int proc1, const std::string& destination) : StateCommunicator<T>(capacity, node0, proc0, node1, proc1), tcb(capacity, &receiveLock, &receiveReady), dest(ipv4, destination) {
      this->backing[0] = new T[capacity];
      this->backing[1] = NULL;
      count = 0;

      pthread_mutex_init(&putLock, NULL);
      pthread_cond_init(&putReady, NULL);
      pthread_mutex_init(&receiveLock, NULL);
      pthread_cond_init(&receiveReady, NULL);

      transport = &TcpTransport_namespace::new_TcpTransport_BufferedTransport();
      transport->maceInit();
      transport->registerUniqueHandler((ReceiveDataHandler&)tcb);
      transport->registerUniqueHandler((NetworkErrorHandler&)tcb);
    }

    ~StateCommunicatorTcp() {
      transport->maceExit();
      delete transport;
      pthread_mutex_destroy(&putLock);
      pthread_cond_destroy(&putReady);
    }

    // enqueue to send
    bool put(T *item, int endpoint) {
      ASSERT(endpoint == ENDPOINT_OUTGOING);
      bool result = false;

      Log::log("InterNode") << "Sending message of type " << item->get_type() << Log::endl;

      pthread_mutex_lock(&putLock);

      ASSERT(count <= this->capacity);

      while (count == this->capacity) {
        pthread_cond_wait(&putReady, &putLock);
      }

      memcpy(this->backing[0] + count, item, sizeof(T));
      count++;

      if (count == this->capacity) {
        result = true;
      }
      pthread_mutex_unlock(&putLock);

      return result;
    }

    // send
    int deliver(int endpoint) {
      ASSERT(endpoint == ENDPOINT_OUTGOING);

      int sendSize;

      pthread_mutex_lock(&putLock);

      for (uint i = 0; i < count; i++) {
        sendSize = transport->send(dest, (this->backing[0][i]).marshal_str(), -1);
        ASSERT(sendSize);
      }

      count = 0;

      pthread_cond_signal(&putReady);
      pthread_mutex_unlock(&putLock);

      return 0;
    }

    int receive(T *data, int endpoint) {
      ASSERT(endpoint == ENDPOINT_INCOMING);

      unsigned recvCount = 0;
      T *dataPtr = data;

      pthread_mutex_lock(&receiveLock);
      while (!tcb.hasMessage()) {
        pthread_cond_wait(&receiveReady, &receiveLock);
      }
      pthread_mutex_unlock(&receiveLock);

      recvCount = drainMessageQueue(dataPtr);

      return recvCount;
    }

    int receive_nonblocking(T* data, int endpoint) {
      ASSERT(endpoint == ENDPOINT_INCOMING);
      unsigned recvCount = 0;
      T *dataPtr = data;

      if (tcb.hasMessage()) {
        recvCount = drainMessageQueue(dataPtr);
      }

      return recvCount;
    }
  };
}

#endif // __STATE_COMMUNICATOR_TCP__
