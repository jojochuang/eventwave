#ifndef __STATE_COMMUNICATOR_UNIX__
#define __STATE_COMMUNICATOR_UNIX__

#include <cassert>
#include <cstring>

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "StateCommunicator.h"

namespace macemc {

    template <typename T>
    class StateCommunicatorUnix: public StateCommunicator<T> {
    private:
        int sockets[2];
        unsigned count;
        pthread_mutex_t put_lock;
        pthread_cond_t put_ready;

        StateCommunicatorUnix() {
            assert(false);
        }

    public:
        StateCommunicatorUnix(unsigned capacity, int node0, int proc0, int node1, int proc1) : StateCommunicator<T>(capacity, node0, proc0, node1, proc1) {
            int err = socketpair(AF_UNIX, SOCK_DGRAM, 0, sockets);

            assert(err == 0);

            count = 0;
            this->backing[0] = new T[capacity];
            this->backing[1] = new T[capacity];
            memset(this->backing[0], 0, capacity * sizeof(T));
            memset(this->backing[1], 0, capacity * sizeof(T));

            pthread_mutex_init(&put_lock, NULL);
            pthread_cond_init(&put_ready, NULL);
        }

        bool put(T *item, int endpoint) {
            bool result = false;

            pthread_mutex_lock(&put_lock);

            while (count == this->capacity) {
                pthread_cond_wait(&put_ready, &put_lock);
            }

            memcpy(this->backing[endpoint] + count, item, sizeof(T));
            count += 1;

            if (count == this->capacity) {
                /* Ready to send. */
                result = true;
            }

            pthread_mutex_unlock(&put_lock);

            return result;
        }

        int deliver(int endpoint) {
            int write_result;

            pthread_mutex_lock(&put_lock);

            write_result = write(sockets[endpoint], this->backing[endpoint],
                                 count * sizeof(T));

            assert((unsigned)write_result == count * sizeof(T));
            count = 0;

            pthread_mutex_unlock(&put_lock);
            pthread_cond_signal(&put_ready);

            return 0;
        }

        int receive(T* data, int endpoint) {
            int read_result;
            int select_result;
            fd_set rfds;

            FD_ZERO(&rfds);
            FD_SET(sockets[endpoint], &rfds);

            select_result = select(sockets[endpoint] + 1, &rfds, NULL, NULL, NULL);

            assert(select_result == 1);

            read_result = read(sockets[endpoint], data, this->capacity * sizeof(T));

            assert(read_result % sizeof(T) == 0 && read_result > 0);

            return (read_result / sizeof(T));
        }

        int receive_nonblocking(T* data, int endpoint) {
            int recv_result;

            recv_result = recv(sockets[endpoint], data, this->capacity * sizeof(T), MSG_DONTWAIT);

            if (recv_result == -1 && errno == EAGAIN) {
                return 0;
            }

            assert(recv_result % sizeof(T) == 0 && recv_result > 0);

            return (recv_result / sizeof(T));
        }

        ~StateCommunicatorUnix() {
            close(sockets[0]);
            close(sockets[1]);

            pthread_mutex_destroy(&put_lock);
            pthread_cond_destroy(&put_ready);

            delete[] this->backing[0];
            delete[] this->backing[1];
        }
    };
}

#endif  /* __STATE_COMMUNICATOR_UNIX__ */
