#ifndef __STATE_COMMUNICATOR__
#define __STATE_COMMUNICATOR__

#include <cassert>

#define COMM_ALREADY_DELIVERING (1)

/* Used between relay and workers. */
#define ENDPOINT_RELAY (0)
#define ENDPOINT_WORKER (1)

/* Used between relays for off-node communication. */
#define ENDPOINT_INCOMING (0)
#define ENDPOINT_OUTGOING (1)

#define other_endpoint(endpoint) (endpoint == 0 ? 1 : 0)

namespace macemc {

    template <typename T>
    class StateCommunicator {
        private:

        protected:
            unsigned capacity;
            T *backing[2];

            /* Peer information - one for each endpoint. */
            int connected_nodes[2];
            int connected_procs[2];

            /* Don't want this instantiated. */
            StateCommunicator(unsigned capacity, int node0, int proc0, int node1, int proc1) {
                connected_nodes[0] = node0;
                connected_procs[0] = proc0;
                connected_nodes[1] = node1;
                connected_procs[1] = proc1;

                this->capacity = capacity;
            }

        public:
            virtual bool put(T *item, int endpoint) {
                assert(false);
                return false;
            }
            virtual int deliver(int endpoint) {
                assert(false);
                return 0;
            }
            virtual int receive(T* data, int endpoint) {
                assert(false);
                return 0;
            }

            virtual int receive_nonblocking(T* data, int endpoint) {
                assert(false);
                return 0;
            }

            void get_peer(int &node, int &proc, int endpoint) {
                node = connected_nodes[endpoint];
                proc = connected_procs[endpoint];
            }

            unsigned get_capacity() {
                return capacity;
            }

            virtual ~StateCommunicator() {
                /* Intentionally empty. */
            }
    };
}

#endif
