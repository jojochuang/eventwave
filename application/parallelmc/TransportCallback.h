#ifndef __PARALLELMC_TRANSPORT_CALLBACK_
#define __PARALLELMC_TRANSPORT_CALLBACK_

#include <queue>
#include <pthread.h>

#include "TcpTransport.h"
#include "TcpTransport-init.h"

namespace macemc {
  class TransportCallback : public ReceiveDataHandler, public NetworkErrorHandler {
  private:
    pthread_mutex_t queueLock;
    pthread_mutex_t *receiveLock;
    pthread_cond_t *receiveReady;
    uint numEltsInQueue;
    std::queue<std::string> messageQueue;
    unsigned capacity;

  public:
    TransportCallback(unsigned capacity, pthread_mutex_t *recvMutex, pthread_cond_t *recvCond) {
      pthread_mutex_init(&queueLock, NULL);
      numEltsInQueue = 0;
      this->capacity = capacity;
      receiveLock = recvMutex;
      receiveReady = recvCond;
    }
    void error(const MaceKey& id, TransportError::type code, const std::string& message,
               registration_uid_t rid) {
      std::cout << "(" << id << ") Error " << code << ":" << message << std::endl;
      
      //     ASSERT(false);
    }
    
    void deliver(const MaceKey& source, const MaceKey& destination,
                 const std::string& s, registration_uid_t rid) {
      pthread_mutex_lock(&queueLock);
      messageQueue.push(s);
      numEltsInQueue++;
      pthread_mutex_unlock(&queueLock);
      pthread_mutex_lock(receiveLock);
      pthread_cond_signal(receiveReady);
      pthread_mutex_unlock(receiveLock);
    }

    bool hasMessage() {
      pthread_mutex_lock(&queueLock);
      bool result = numEltsInQueue > 0;
      pthread_mutex_unlock(&queueLock);
      return result;
    }

    std::string getNext() {
      pthread_mutex_lock(&queueLock);
      ASSERT(numEltsInQueue > 0);
      std::string nextMessage = messageQueue.front();
      messageQueue.pop();
      numEltsInQueue--;
      pthread_mutex_unlock(&queueLock);

      return nextMessage;
    }
    
  }; // TransportCallback
}

#endif // __PARALLELMC_TRANSPORT_CALLBACK_
