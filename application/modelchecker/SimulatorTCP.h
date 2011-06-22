#ifndef SIMULATOR_TCP_SERVICE_H
#define SIMULATOR_TCP_SERVICE_H

#include "Sim.h"
#include "SimNetwork.h"
#include "SimulatorTCPCommon.h"

namespace SimulatorTCP_namespace {

/**
 * Modelchecker-specific transport. Differs from the common class in the way
 * message events are queued (in SimEventWeighted). At most one message event
 * per node is queued so that events do not happen out of order. Modelchecker
 * has absolutely no sense of time or how slow things happen. It only cares
 * about interleavings.
 */
class SimulatorTCPService : public SimulatorTCPCommonService {
  public:
    SimulatorTCPService(uint32_t queue_size, uint16_t port, int node,
        bool messageErrors = false, int forwarder = -1)
      : SimulatorTCPCommonService(queue_size, port, node, messageErrors, forwarder),
        net(SimNetwork::Instance()), eventQueued(Sim::getNumNodes()) {
      net.registerHandler(port, *this);
    }

    ~SimulatorTCPService() { }

    bool route(const MaceKey& dest, const std::string& s, registration_uid_t registrationUid);

    /// Remove event queued by local for destNode
    bool removeEvent(int destNode, int local,
                     SimNetworkCommon::NetEventType type,
                     int weight) const;
  
    void addCTSEvent(int dest);
    /// Add and remove FLUSHED event from the queue
    void addFlushedEvent();
    bool removeFlushedEvent();
    virtual void prepareDestNotReady(int node, uint64_t t) {
      pendingDestNotReady[node] = 1;
    }
    
    inline uint32_t getNetMessageId() {
      return net.getMessageId();
    }

    inline SimulatorTransport* getNetTransport(int node, int port) {
      return net.getTransport(node, port);
    }

    void netSignal(int source, int dest, int port, SimulatorTransport::TransportSignal sig) {
      net.signal(source, dest, port, sig);
    }
 
    void addNetEvent(int destNode, SimNetworkCommon::NetEventType mType,
                     const std::string& desc, int weight) const;
    
    void enqueueEvent(int destNode);
    /// Checks to see if any DEST_NOT_READY that I sent is still pending
    bool isDestNotReadyPending(int destNode) const;
    /// Remove DEST_NOT_READY from event queue
    bool removeDestNotReadyEvent(int other);
    /// Remove message given SimulatorMessage equivalent
    bool removeEventFromQueue(const SimulatorMessage& msg) const;
    /// Remove any event that may be queued for the other node
    void removeEvents(int other) const;
    SimulatorMessage createMessageSourceReset(int other, uint32_t msgId);
    SimulatorMessage createMessageBidiReadError(int other, uint32_t msgId);
  
    const BufferStatisticsPtr getStatistics(const MaceKey& peer, Connection::type d, registration_uid_t registrationUid);


  private:
    SimNetwork& net;
    typedef std::vector<bool> EventQueuedList;
    EventQueuedList eventQueued; /// Is an event to a given destination queued?

};

}

#endif // SIMULATOR_TCP_SERVICE_H
