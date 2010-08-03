#ifndef __STATE_COMMUNICATOR_MMAP__
#define __STATE_COMMUNICATOR_MMAP__

#include <cassert>
#include <cstring>
#include <fcntl.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdio.h>

#include "StateCommunicator.h"

namespace macemc {

    template <typename T>
    class StateCommunicatorMMAP: public StateCommunicator<T> {
        private:
            pthread_mutex_t *locks[2];
            pthread_cond_t *cond_emptys[2];
            pthread_cond_t *cond_readys[2];
            unsigned *count[2];
            bool *delivering[2];
            int fd;
            char *tempFile;
            
            /* Memory region information.
             * Declared as a uint8_t pointer to ensure offsets are a fixed size (bytes). */
            uint8_t *region_beginning;
            size_t region_size;

            /* Don't want this available. */
            StateCommunicatorMMAP() {
                assert(false);
            }

        public:
            StateCommunicatorMMAP(int capacity, int node0, int proc0, int node1, int proc1) : StateCommunicator<T>(capacity, node0, proc0, node1, proc1) {
                void *mmap_result = NULL;
                int offset = 0;
                pthread_mutexattr_t mutex_attr;
                pthread_condattr_t cond_attr;

                region_size = 2 * capacity * sizeof(T) +
                              2 * sizeof(pthread_mutex_t) +
                              4 * sizeof(pthread_cond_t) +
                              2 * sizeof(unsigned) +
                              2 * sizeof(bool);

#ifdef __APPLE__
                const char *defaultName = "/tmp/parallelmc-shm.XXXXXXX";
                tempFile = new char[28];
                memcpy(tempFile, defaultName, 28);
                tempFile = mktemp(tempFile);

                assert(tempFile != NULL);
                
                fd = open(tempFile, O_RDWR | O_CREAT);
                if (fd < 0) {
                  perror("open tempFile");
                }
                mmap_result = mmap(NULL, region_size, PROT_READ | PROT_WRITE,
                                   MAP_SHARED, fd, 0);
#else
               mmap_result = mmap(NULL, region_size,
                                  PROT_READ | PROT_WRITE,
                                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);
#endif

                if (mmap_result == MAP_FAILED) {
                  perror("mmap()");
                }

                assert(mmap_result != MAP_FAILED);

                region_beginning = (uint8_t *) mmap_result;

                this->backing[0] = (T *) (region_beginning + offset);
                offset += capacity * sizeof(T);
                this->backing[1] = (T *) (region_beginning + offset);
                offset += capacity * sizeof(T);

                locks[0] = (pthread_mutex_t *) (region_beginning + offset);
                offset += sizeof(pthread_mutex_t);
                locks[1] = (pthread_mutex_t *) (region_beginning + offset);
                offset += sizeof(pthread_mutex_t);

                cond_emptys[0] = (pthread_cond_t *) (region_beginning + offset);
                offset += sizeof(pthread_cond_t);
                cond_emptys[1] = (pthread_cond_t *) (region_beginning + offset);
                offset += sizeof(pthread_cond_t);
                cond_readys[0] = (pthread_cond_t *) (region_beginning + offset);
                offset += sizeof(pthread_cond_t);
                cond_readys[1] = (pthread_cond_t *) (region_beginning + offset);
                offset += sizeof(pthread_cond_t);

                count[0] = (unsigned *) (region_beginning + offset);
                offset += sizeof(unsigned);
                count[1] = (unsigned *) (region_beginning + offset);
                offset += sizeof(unsigned);

                delivering[0] = (bool *) (region_beginning + offset);
                offset += sizeof(bool);
                delivering[1] = (bool *) (region_beginning + offset);
                offset += sizeof(bool);

                pthread_mutexattr_init(&mutex_attr);
                pthread_condattr_init(&cond_attr);

                pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
                pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);

                pthread_mutex_init(locks[0], &mutex_attr);
                pthread_mutex_init(locks[1], &mutex_attr);
                pthread_cond_init(cond_emptys[0], &cond_attr);
                pthread_cond_init(cond_emptys[1], &cond_attr);
                pthread_cond_init(cond_readys[0], &cond_attr);
                pthread_cond_init(cond_readys[1], &cond_attr);

                *count[0] = 0;
                *count[1] = 0;

                *delivering[0] = false;
                *delivering[1] = false;

                memset(this->backing[0], 0, capacity * sizeof(T));
                memset(this->backing[1], 0, capacity * sizeof(T));

                assert((size_t) offset == region_size);
            }

            bool put(T *item, int endpoint) {
                bool result = false;

                pthread_mutex_lock(locks[endpoint]);

                while (*delivering[endpoint] == true || *count[endpoint] == this->capacity) {
                    pthread_cond_wait(cond_emptys[endpoint], locks[endpoint]);
                }

                memcpy(this->backing[endpoint] + *count[endpoint], item, sizeof(T));
                *count[endpoint] += 1;

                if (*count[endpoint] == this->capacity) {
                    result = true;
                }

                pthread_mutex_unlock(locks[endpoint]);
                return result;
            }

            int deliver(int endpoint) {
                pthread_mutex_lock(locks[endpoint]);

                if (*delivering[endpoint] == true) {
                    pthread_mutex_unlock(locks[endpoint]);
                    return COMM_ALREADY_DELIVERING;
                }

                *delivering[endpoint] = true;
                pthread_mutex_unlock(locks[endpoint]);
                pthread_cond_signal(cond_readys[endpoint]);

                return 0;
            }

            int receive(T* data, int endpoint) {
                int other = other_endpoint(endpoint);
                int data_count = 0;

                pthread_mutex_lock(locks[other]);

                while (*delivering[other] == false) {
                    pthread_cond_wait(cond_readys[other], locks[other]);
                }

                data_count = *count[other];
                memcpy(data, this->backing[other], data_count * sizeof(T));
                *count[other] = 0;
                *delivering[other] = false;

                pthread_mutex_unlock(locks[other]);
                pthread_cond_signal(cond_emptys[other]);

                return data_count;
            }

            int receive_nonblocking(T* data, int endpoint) {
                int other = other_endpoint(endpoint);
                int data_count = 0;

                pthread_mutex_lock(locks[other]);

                if (*delivering[other] == false) {
                    pthread_mutex_unlock(locks[other]);
                    return 0;
                }

                data_count = *count[other];
                memcpy(data, this->backing[other], data_count * sizeof(T));
                *count[other] = 0;
                *delivering[other] = false;

                pthread_mutex_unlock(locks[other]);
                pthread_cond_signal(cond_emptys[other]);

                return data_count;
            }

            ~StateCommunicatorMMAP() {
                pthread_mutex_destroy(locks[0]);
                pthread_mutex_destroy(locks[1]);
                pthread_cond_destroy(cond_emptys[0]);
                pthread_cond_destroy(cond_emptys[1]);
                pthread_cond_destroy(cond_readys[0]);
                pthread_cond_destroy(cond_readys[1]);

#ifdef __APPLE__
                close(fd);
                unlink(tempFile);
                delete[] tempFile;
#endif

                munmap(region_beginning, region_size);
            }
    };
}

#endif  /* __STATE_COMMUNICATOR_MMAP__ */
