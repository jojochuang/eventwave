#ifndef SIMULATOR_UDP_SERVICE_H
#define SIMULATOR_UDP_SERVICE_H

#include "SimNetwork.h"
#include "SimulatorUDPCommon.h"

namespace SimulatorUDP_namespace {

class SimulatorUDPService : public SimulatorUDPCommonService {
  public:
    SimulatorUDPService(int port, int node) : SimulatorUDPCommonService(port, node), net(SimNetwork::Instance()) {
      net.registerHandler(port, *this);
    }

    ~SimulatorUDPService() { }

    void queueMessage(int destNode, uint32_t msgId, registration_uid_t handlerUid, const std::string& msg);
    
    inline uint32_t getNetMessageId() {
      return net.getMessageId();
    }
   
    void enqueueEvent(int destNode) { }

  private:
    SimNetwork& net;

};

}

#endif // SIMULATOR_UDP_SERVICE_H
