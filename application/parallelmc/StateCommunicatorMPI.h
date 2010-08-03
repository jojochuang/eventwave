#ifndef __STATE_COMMUNICATOR_MPI_H__
#define __STATE_COMMUNICATOR_MPI_H__

#include <cassert>
#include <list>

#include <mpi.h>
#include <pthread.h>

#include "StateCommunicator.h"

#define STATE_COMMUNICATOR_MPI_TAG (111)

namespace macemc {

    template <typename T>
    class StateCommunicatorMPI : public StateCommunicator<T> {
        private:
            unsigned count;
            int rank;
            int rank_other;
            MPI_Comm mpi_comm;

            pthread_mutex_t put_lock;
            pthread_cond_t put_ready;

            StateCommunicatorMPI() {
                assert(false);
            }

            /* I can't believe I'm doing this... */
            template <typename Q>
            class OutstandingMPISend {
                private:
                    MPI_Request request;
                    Q *buffer;

                public:
                    OutstandingMPISend(Q *buffer) {
                        this->buffer = buffer;
                    }

                    MPI_Request *get_request_ptr() {
                        return &request;
                    }

                    bool is_done() {
                        int mpi_result;
                        int flag;

                        mpi_result = MPI_Test(&request, &flag, MPI_STATUS_IGNORE);

                        assert(mpi_result == MPI_SUCCESS);

                        return (flag != 0);
                    }

                    ~OutstandingMPISend() {
                        delete[] buffer;
                    }
            };

            std::list<OutstandingMPISend<T> *> outstanding_sends;

        public:
            StateCommunicatorMPI(unsigned capacity, MPI_Comm mpi_comm, int rank, int rank_other) : StateCommunicator<T>(capacity, rank_other, 0, rank_other, 0) {
                this->rank = rank;
                this->rank_other = rank_other;
                this->mpi_comm = mpi_comm;

                this->backing[0] = new T[capacity];
                this->backing[1] = NULL;

                count = 0;

                pthread_mutex_init(&put_lock, NULL);
                pthread_cond_init(&put_ready, NULL);
            }

            bool put(T *item, int endpoint) {
                bool result = false;

                pthread_mutex_lock(&put_lock);

                while (count == this->capacity) {
                    pthread_cond_wait(&put_ready, &put_lock);
                }

                memcpy(this->backing[0] + count, item, sizeof(T));
                count += 1;

                if (count == this->capacity) {
                    /* Ready to send. */
                    result = true;
                }

                pthread_mutex_unlock(&put_lock);

                return result;
            }

            int deliver(int endpoint) {
                int send_result;
                OutstandingMPISend<T> *new_send;

                pthread_mutex_lock(&put_lock);

                new_send = new OutstandingMPISend<T>(this->backing[0]);
                send_result = MPI_Isend(this->backing[0], count * sizeof(T), MPI_BYTE,
                                       rank_other, STATE_COMMUNICATOR_MPI_TAG,
                                       mpi_comm, new_send->get_request_ptr());

                assert(send_result == MPI_SUCCESS);

                outstanding_sends.push_back(new_send);
                Log::log("MCTest") << "Added a new item to the outstanding sends list.  Current count is " << outstanding_sends.size() << Log::endl;

                this->backing[0] = new T[this->capacity];
                count = 0;

                pthread_mutex_unlock(&put_lock);
                pthread_cond_signal(&put_ready);

                /* Check the outstanding_send list to see what can be removed. */
                while (!outstanding_sends.empty()) {
                    OutstandingMPISend<T> *front = outstanding_sends.front();

                    if (front->is_done()) {
                        outstanding_sends.pop_front();
                        delete front;
                        Log::log("MCTest") << "Removed item from outstanding list.  Current count is " << outstanding_sends.size() << Log::endl;
                    } else {
                        break;
                    }
                }

                return 0;
            }

            int receive(T *data, int endpoint) {
                /* KW: Right now, we have no case in which we want to use this. */
                assert(false);
                return -1;
            }

            int receive_nonblocking(T *data, int endpoint) {
                int mpi_result;
                int ready;
                int received_count = 0;

                mpi_result = MPI_Iprobe(rank_other, STATE_COMMUNICATOR_MPI_TAG,
                                        mpi_comm, &ready, MPI_STATUS_IGNORE);

                assert(mpi_result == MPI_SUCCESS);

                if (ready) {
                    MPI_Status status;
                    int byte_count;

                    mpi_result = MPI_Recv(data, this->capacity * sizeof(T), MPI_BYTE,
                                          rank_other, STATE_COMMUNICATOR_MPI_TAG,
                                          mpi_comm, &status);

                    assert(mpi_result == MPI_SUCCESS);

                    mpi_result = MPI_Get_count(&status, MPI_BYTE, &byte_count);

                    assert(mpi_result == MPI_SUCCESS);
                    assert(byte_count % sizeof(T) == 0 && byte_count > 0);

                    received_count = byte_count / sizeof(T);
                }

                return received_count;
            }

            ~StateCommunicatorMPI() {
                pthread_mutex_destroy(&put_lock);
                pthread_cond_destroy(&put_ready);

                delete[] this->backing[0];
            }
    };
}

#endif  /* __STATE_COMMUNICATOR_MPI_H__ */
