#ifndef SIMULATOR_TCP_SERVICE_H
#define SIMULATOR_TCP_SERVICE_H

#include "SimNetwork.h"
#include "SimulatorTCPCommon.h"

namespace SimulatorTCP_namespace {

/**
 * Simulator-specific reliable transport. Any new message events are queued in
 * the pending events (SimTimeUtil) ordered by their calculated time of
 * occurrence (in the future).
 */
class SimulatorTCPService : public SimulatorTCPCommonService {
  public:
    SimulatorTCPService(uint32_t queue_size, uint16_t port, int node,
        bool messageErrors = false, int forwarder = -1)
      : SimulatorTCPCommonService(queue_size, port, node, messageErrors, forwarder),
        net(SimNetwork::Instance()) {
      net.registerHandler(port, *this);
    }

    ~SimulatorTCPService() { }

    bool route(const MaceKey& dest, const std::string& s, registration_uid_t registrationUid);
  
    void addCTSEvent(int dest);
    /// Add and remove FLUSHED event from the queue
    void addFlushedEvent();
    bool removeFlushedEvent();
    void prepareDestNotReady(int node, uint64_t t);
  
    int getNumFlows() const;
    
    inline uint32_t getNetMessageId() {
      return net.getMessageId();
    }

    inline SimulatorTransport* getNetTransport(int node, int port) {
      return net.getTransport(node, port);
    }

    void netSignal(int source, int dest, int port, SimulatorTransport::TransportSignal sig) {
      net.signal(source, dest, port, sig);
    }
    
    /// Simulator enqueues events as they are created
    void enqueueEvent(int destNode) { }
    /// Remove DEST_NOT_READY from event queue
    bool removeDestNotReadyEvent(int other);
    /// Remove message given SimulatorMessage equivalent
    bool removeEventFromQueue(const SimulatorMessage& msg) const;
    /// Remove any event that may be queued for the other node
    void removeEvents(int other) const;
    SimulatorMessage createMessageSourceReset(int other, uint32_t msgId);
    SimulatorMessage createMessageBidiReadError(int other, uint32_t msgId);
  
    BufferStatisticsPtr getStats(int node);
    const BufferStatisticsPtr getStatistics(const MaceKey& peer, Connection::type d, registration_uid_t registrationUid);
  
  private:
    SimNetwork& net;

};

}

#endif // SIMULATOR_TCP_SERVICE_H
