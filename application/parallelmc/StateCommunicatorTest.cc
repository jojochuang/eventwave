#include <iostream>

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "StateCommunicator.h"
#include "StateCommunicatorMMAP.h"
#include "StateCommunicatorUnix.h"

#include "MCMessage.h"

#define UNIT_SIZE (10)
#define TEST_ITERATIONS (1000000)

using namespace macemc;

double time_difference(struct timeval begin, struct timeval end) {
    double result = 0;

    result = end.tv_sec - begin.tv_sec;
    result += (double) (end.tv_usec - begin.tv_usec) / 1000000;

    return result;
}

double test_send(StateCommunicator<MCMessage> *comm, MCMessage *messages) {
    struct timeval begin, end;

    std::cout << "Beginning new send test." << std::endl;
    
    gettimeofday(&begin, NULL);
    for (int i = 0; i < TEST_ITERATIONS; ++i) {
        for (int j = 0; j < UNIT_SIZE; ++j) {
            if (comm->put(&messages[j], ENDPOINT_RELAY)) {
                comm->deliver(ENDPOINT_RELAY);
            }
        }
    }
    gettimeofday(&end, NULL);

    return time_difference(begin, end);
}

double test_recv(StateCommunicator<MCMessage> *comm, MCMessage *messages) {
    struct timeval begin, end;

    std::cout << "Beginning new recv test." << std::endl;

    gettimeofday(&begin, NULL);
    for (int i = 0; i < TEST_ITERATIONS; ++i) {
        comm->receive(messages, ENDPOINT_WORKER);
    }
    gettimeofday(&end, NULL);

    return time_difference(begin, end);
}

int main(int argc, char **argv) {
    pid_t fork_result;
    StateCommunicator<MCMessage> *comm_mmap = new StateCommunicatorMMAP<MCMessage>(UNIT_SIZE, 0, 0, 1, 0);
    StateCommunicator<MCMessage> *comm_unix = new StateCommunicatorUnix<MCMessage>(UNIT_SIZE, 0, 0, 1, 0);
    MCMessage *messages = new MCMessage[UNIT_SIZE];

    assert(comm_mmap->get_capacity() == UNIT_SIZE);
    assert(comm_unix->get_capacity() == UNIT_SIZE);

    fork_result = fork();

    if (fork_result) {
        /* Parent */
        double result;

        result = test_send(comm_mmap, messages);

        std::cout << "[mmap] Sent: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        result = test_send(comm_unix, messages);

        std::cout << "[unix] Sent: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        /* Run #2 */

        result = test_send(comm_mmap, messages);

        std::cout << "[mmap] Sent: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        result = test_send(comm_unix, messages);

        std::cout << "[unix] Sent: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;
    } else {
        /* Child */
        double result;

        result = test_recv(comm_mmap, messages);

        std::cout << "[mmap] Received: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        result = test_recv(comm_unix, messages);

        std::cout << "[unix] Received: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        /* Run #2 */

        result = test_recv(comm_mmap, messages);

        std::cout << "[mmap] Received: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;

        result = test_recv(comm_unix, messages);

        std::cout << "[unix] Received: " << TEST_ITERATIONS * UNIT_SIZE << " units in "
                  << result << " seconds." << std::endl << std::endl;
    }

    return 0;
}
