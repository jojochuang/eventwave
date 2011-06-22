#include "SimulatorUDP.h"
#include "SimTimeUtil.h"

namespace SimulatorUDP_namespace {

  void SimulatorUDPService::queueMessage(int destNode, uint32_t msgId, registration_uid_t handlerUid, const std::string& msg) {
    MessageQueue& mqueue = queuedMessages[destNode];

    uint64_t sendTime = SimTimeUtil::nodeTimeu(localNode);
    uint64_t arrivalTime = SimTimeUtil::getNextTime(sendTime + SimNetwork::getLatency(localNode, destNode, msg.size()));

    Event ev;
    ev.node = destNode;
    ev.type = Event::NETWORK;
    ev.simulatorVector.push_back(SimNetwork::MESSAGE);
    ev.simulatorVector.push_back(localNode);
    ev.simulatorVector.push_back(localPort);
    ev.desc = "(MESSAGE EVENT,src,port)";
    SimTimeUtil::addEvent(arrivalTime, ev);

    mqueue.push_back(SimulatorMessage(localNode, destNode, msgId, -1, -1,
                                      sendTime, arrivalTime, SimulatorMessage::MESSAGE, handlerUid, msg));
  }

}
