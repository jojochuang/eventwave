#include "MCMessage.h"
#include "StateCommunicatorTcp.h"
#include "params.h"
#include "SysUtil.h"
#include <cassert>
#include <iostream>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define NUM_ITERATIONS 100
#define BUFFER_SIZE 10
/* Required by some BSDs */
#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif

using namespace macemc;

int main (int argc, char **argv) {
  pid_t fork_result;

  StateCommunicatorTcp<MCMessage> *comm_tcp;
  MCMessage *outMessage = new MCMessage();
  MCMessage *inMessages = new MCMessage[BUFFER_SIZE];

  std::string port;
  std::string receiver;

  std::string SRCPORT = "9472";
  std::string DESTPORT = "9423";

  pthread_mutex_t *coordLock;
  pthread_cond_t *readyToReceive;
  pthread_cond_t *receiverFinished;
  bool *receiverStarted;

  pthread_mutexattr_t mutex_attr;
  pthread_condattr_t cond_attr;

  void *mmap_result = NULL;
  size_t region_size = sizeof(pthread_mutex_t) + 
                       2 * sizeof(pthread_cond_t) + 
                       sizeof(bool);

  mmap_result = mmap(NULL, region_size, PROT_READ | PROT_WRITE, 
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  if (mmap_result == MAP_FAILED) {
    perror("mmap()");
  }

  int offset = 0;

  coordLock = (pthread_mutex_t *) mmap_result + offset;
  offset += sizeof(pthread_mutex_t);
  readyToReceive = (pthread_cond_t *) mmap_result + offset;
  offset += sizeof(pthread_cond_t);
  receiverFinished = (pthread_cond_t *) mmap_result + offset;
  offset += sizeof(pthread_cond_t);
  receiverStarted = (bool *) mmap_result + offset;
  offset += sizeof(bool);

  *receiverStarted = false;

  pthread_mutexattr_init(&mutex_attr);
  pthread_condattr_init(&cond_attr);

  pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
  pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);

  pthread_mutex_init(coordLock, &mutex_attr);
  pthread_cond_init(readyToReceive, &cond_attr);
  pthread_cond_init(receiverFinished, &cond_attr);

  fork_result = fork();

  if (fork_result) {
    receiver = "IPV4/localhost:" + DESTPORT;
    port = SRCPORT;
  } else {
    receiver = "IPV4/localhost:" + SRCPORT;
    port = DESTPORT;
  }

  params::set("MACE_ADDRESS_ALLOW_LOOPBACK", "1");
  params::set("MACE_LOCAL_ADDRESS", "localhost");
  params::set("MACE_PORT", port);
 
  comm_tcp = new StateCommunicatorTcp<MCMessage>(BUFFER_SIZE, 0, 0, 1, 0, receiver);

  pthread_mutex_lock(coordLock);

  if (fork_result && !(*receiverStarted)) {
    pthread_cond_wait(readyToReceive, coordLock);
  } else {
    *receiverStarted = true;
    pthread_cond_signal(readyToReceive);
  }

  pthread_mutex_unlock(coordLock);

  if (fork_result) {
    // Sender
    
    for (int i = 0; i < NUM_ITERATIONS; i++) {
      int j = 0;

      do {
        j++;
      } while (!comm_tcp->put(outMessage, 0));


      if (j != BUFFER_SIZE) {
        std::cout << "j is " << j << std::endl;
      }
      
      assert(j == BUFFER_SIZE);
      
      comm_tcp->deliver(0);
      
      std::cout << port << " sent " << i << std::endl;
      sched_yield();
    }

    std::cout << "Waiting for receiver to finish" << std::endl;
    pthread_mutex_lock(coordLock);
    pthread_cond_wait(receiverFinished, coordLock);
    pthread_mutex_unlock(coordLock);
  } else {
    // Receiver
    int iterations_received = 0;

    while (iterations_received < NUM_ITERATIONS) {
      int num_received = 0;

      while (num_received < BUFFER_SIZE) {
        int recv_result = comm_tcp->receive_nonblocking(inMessages, 0);
        
        if (recv_result > 0) {
          std::cout << port << " received " << recv_result << " msgs" << std::endl;
          num_received += recv_result;
        }
      }
      
      std::cout << port << " received iteration " << iterations_received << std::endl;

      iterations_received++;
      sched_yield();
    }

    std::cout << "Signaling sender" << std::endl;
    pthread_mutex_lock(coordLock);
    pthread_cond_signal(receiverFinished);
    pthread_mutex_unlock(coordLock);
  }


  std::cout << port << " Done!" << std::endl;

  if (fork_result) {
    int status;
    waitpid(fork_result, &status, 0);
  }

  return 0;
}
