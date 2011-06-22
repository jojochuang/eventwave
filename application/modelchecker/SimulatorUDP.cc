#include "SimEventWeighted.h"
#include "SimulatorUDP.h"

namespace SimulatorUDP_namespace {

void SimulatorUDPService::addNetEvent(int destNode) {
  Event ev;
  ev.node = destNode;
  ev.type = Event::NETWORK;
  ev.simulatorVector.push_back(SimNetworkCommon::MESSAGE);
  ev.simulatorVector.push_back(localNode);
  ev.simulatorVector.push_back(localPort);
  ev.desc = "(MESSAGE EVENT,src,port)";

  SimEventWeighted::addEvent(SimNetwork::MESSAGE_WEIGHT, ev);
}

void SimulatorUDPService::enqueueEvent(int destNode) {
  if (isAvailableMessage(destNode)) {
    addNetEvent(destNode);
  }
}
  
void SimulatorUDPService::queueMessage(int destNode, uint32_t msgId, registration_uid_t handlerUid, const std::string& msg) {
  MessageQueue& mqueue = queuedMessages[destNode];

  mqueue.push_back(SimulatorMessage(localNode, destNode, msgId, -1, -1, 0, 0, SimulatorMessage::MESSAGE, handlerUid, msg));

  if (mqueue.size() == 0) {
    addNetEvent(destNode);
  }
}

}
