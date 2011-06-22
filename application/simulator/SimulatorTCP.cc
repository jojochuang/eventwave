#include <math.h>

#include "BaseTransport.h"
#include "Sim.h"
#include "SimulatorTCP.h"
#include "SimTimeUtil.h"

namespace SimulatorTCP_namespace {

bool SimulatorTCPService::route(const MaceKey& dest, const std::string& s, registration_uid_t handlerUid) {
  ADD_SELECTORS("SIMULATOR::TCP::route::pkt::(downcall)");
  maceout << "dest=" << dest.toString() << " size=" << s.size() << " priority=" << 0 << " handlerUid=" << handlerUid << Log::endl;
  uint32_t msgId = net.getMessageId();
  int destNode = Sim::getNode(dest);
  int destQueue = forwarder;
  MaceKey nextHop = dest;
  if (destQueue == localNode) {
    // no forwarder defined
    destQueue = destNode;
  }
  else {
    // send to forwarder
    nextHop = Sim::getMaceKey(destQueue);
  }

  MessageQueue& mqueue = queuedMessages[destQueue];
  if(mqueue.size() < queueSize) {
    maceout << "route([dest=" << dest << "][s_deserialized=pkt(id=" << msgId << ")])" << Log::endl;
    uint64_t sendTime = SimTimeUtil::nodeTimeu(localNode);
    uint64_t latencyStartTime = std::max(sendTime, mqueue.empty() ? sendTime : mqueue.back().arrivalTime - SimNetwork::getFixedLatency(localNode, destNode));
    uint64_t arrivalTime = SimTimeUtil::getNextTime(latencyStartTime + SimNetwork::getLatency(localNode, destNode, s.size()));
    uint64_t latency = arrivalTime - sendTime;
    macedbg(1) << "Message latency " << latency << " sendTime " << sendTime << " arrivalTime " << arrivalTime << Log::endl;
    BufferStatisticsPtr bufStat = stats[destNode];

    if (bufStat == NULL) {
      bufStat = BufferStatisticsPtr(new BufferStatistics(BaseTransport::DEFAULT_WINDOW_SIZE));
      stats[destNode] = bufStat;
    }
    // let's just break up every entry in the filter to be 4000 bytes
    int numEvts = (int)ceil(s.size() / 4000.0);
    uint bytesPut = 0;

    for (int i = 0; i < numEvts; i++) {
      int bytesToPut = std::min((size_t)4000u, s.size() - bytesPut);
      bufStat->history.push_back(TimeValueStat(sendTime + i * latency, bytesToPut));
      bufStat->sum += bytesToPut;
      bytesPut += bytesToPut;
    }
    ASSERT(bytesPut == s.size());
    if (!remoteErrors[destNode] && !pendingDestNotReady[destNode]) {
      // XXX: Should event be queued for destQueue instead of destNode?
      Event ev;
      ev.node = destNode;
      ev.type = Event::NETWORK;
      ev.simulatorVector.push_back(SimNetworkCommon::MESSAGE);
      ev.simulatorVector.push_back(localNode);
      ev.simulatorVector.push_back(localPort);
      ev.desc = "(MESSAGE EVENT,src,port)";
      SimTimeUtil::addEvent(arrivalTime, ev);
    }
    mqueue.push_back(SimulatorMessage(localNode, destNode, msgId, forwarder, destQueue, sendTime, arrivalTime, SimulatorMessage::MESSAGE, handlerUid, s));

    removeFlushedEvent();

    return true;
  }
  maceout << "route([dest=" << dest << "][s_deserialized=pkt(id=" << msgId << ", SIM_DROP=1)])" << Log::endl;
  return false;
}

void SimulatorTCPService::addFlushedEvent() {
  if (hasFlushed() && flushEventQueued == 0) {
    Event ev;
    ev.node = localNode;
    ev.type = Event::NETWORK;
    ev.simulatorVector.push_back(SimNetworkCommon::FLUSHED);
    ev.simulatorVector.push_back(localNode);
    ev.simulatorVector.push_back(localPort);
    ev.desc = "Flushed";
    uint64_t time = SimTimeUtil::getNextTime(SimTimeUtil::nodeTimeu(localNode)+1);
    SimTimeUtil::addEvent(time, ev);
    flushEventQueued = time; // time of queueing, for easy deletion
  }
}

  bool SimulatorTCPService::removeFlushedEvent() {
    if (flushEventQueued == 0)
      return false;

    SimEvent::getEvents().erase(flushEventQueued);
    flushEventQueued = 0;
    return true;
  }

void SimulatorTCPService::addCTSEvent(int dest) {
  if (hasCTS(dest) && !rtsEventsQueued.containsKey(dest)) {
    Event ev;
    ev.node = localNode;
    ev.type = Event::NETWORK;
    ev.simulatorVector.push_back(SimNetworkCommon::CTS);
    ev.simulatorVector.push_back(dest);
    ev.simulatorVector.push_back(localPort);
    ev.desc = "(CTS,dest node,port)";

    uint64_t time = SimTimeUtil::getNextTime(SimTimeUtil::nodeTimeu(localNode)+1);
    SimTimeUtil::addEvent(time, ev);

    rtsEventsQueued[dest] = time;
  }
}

int SimulatorTCPService::getNumFlows() const {
  static const size_t FLOW_THRESHOLD = 300;
  int numFlows = 0;

  for (MessageQueueMap::const_iterator i = queuedMessages.begin(); i != queuedMessages.end(); i++) {
    size_t byteCount = 0;
    for (MessageQueue::const_iterator j = i->begin(); j != i->end(); j++) {
      byteCount += j->msg.size();
      if (byteCount > FLOW_THRESHOLD) {
        numFlows++;
        break;
      }
    }
  }
  return numFlows;
}

void SimulatorTCPService::prepareDestNotReady(int other, uint64_t time) {
  ADD_SELECTORS("SimulatorTCPCommon::prepareDestNotReady");
  macedbg(0) << "localNode: " << localNode << " localPort: " << localPort << " other: " << other << Log::endl;
  MessageQueue& mqueue = queuedMessages[other];
  ASSERT(!mqueue.empty());
  SimulatorMessage m = mqueue.front();
  mqueue.pop_front();
  removeEvents(other);
  //   remoteErrors[other] = true;
  pendingDestNotReady[other] = time;
  mqueue.push_front(m);
}

bool SimulatorTCPService::removeDestNotReadyEvent(int other) {
  uint64_t t = pendingDestNotReady[other];
  pendingDestNotReady[other] = 0;
  return SimEvent::getEvents().erase(t);
}

bool SimulatorTCPService::removeEventFromQueue(const SimulatorMessage& msg) const {
  return SimEvent::getEvents().erase(msg.arrivalTime);
}
  
void SimulatorTCPService::removeEvents(int other) const {
  const MessageQueue& mqueue = queuedMessages[other];
  for (MessageQueue::const_iterator i = mqueue.begin(); i != mqueue.end(); i++) {
    if (i->messageType == SimulatorMessage::MESSAGE) {
      ASSERT(removeEventFromQueue(*i));
    }
  }
}

SimulatorMessage SimulatorTCPService::createMessageSourceReset(int other, uint32_t msgId) {
  uint64_t sendTime = SimTimeUtil::nodeTimeu(localNode);
  uint64_t arrivalTime = SimTimeUtil::getNextTime(sendTime+1);
  Event ev;
  ev.node = other;
  ev.type = Event::NETWORK;
  ev.simulatorVector.push_back(SimNetworkCommon::MESSAGE);
  ev.simulatorVector.push_back(localNode);
  ev.simulatorVector.push_back(localPort);
  ev.desc = "(MESSAGE EVENT,src,port)";
  SimTimeUtil::addEvent(arrivalTime, ev);
  ASSERTMSG(arrivalTime < queuedMessages[other].front().arrivalTime,
            "Error cannot be scheduled after first queued message");

  return SimulatorMessage(localNode, other, msgId, -1, -1,
                          sendTime, arrivalTime, SimulatorMessage::READ_ERROR, -1, "");
}

SimulatorMessage SimulatorTCPService::createMessageBidiReadError(int other, uint32_t msgId) {
  uint64_t sendTime = SimTimeUtil::nodeTimeu(localNode);
  uint64_t arrivalTime = SimTimeUtil::getNextTime(sendTime+1);

  Event ev;
  ev.node = other;
  ev.type = Event::NETWORK;
  ev.simulatorVector.push_back(SimNetworkCommon::MESSAGE);
  ev.simulatorVector.push_back(localNode);
  ev.simulatorVector.push_back(localPort);
  ev.desc = "(MESSAGE EVENT,src,port)";
  SimTimeUtil::addEvent(arrivalTime, ev);

  return SimulatorMessage(localNode, other, msgId, -1, -1,
                          sendTime, arrivalTime, SimulatorMessage::READ_ERROR, -1, "");
}

BufferStatisticsPtr SimulatorTCPService::getStats(int node) {
  StatsMap::const_iterator i = stats.find(node);

  if (i != stats.end()) {
    return i->second;
  }
  return BufferStatisticsPtr();
}

const BufferStatisticsPtr SimulatorTCPService::getStatistics(const MaceKey& peer, Connection::type d, registration_uid_t registrationUid) {
  int destNode = Sim::getNode(peer);
  BufferStatisticsPtr ret;

  if (d == Connection::OUTGOING) {
    ret = getStats(destNode);
  }
  else {
    // for the incoming direction, just look up the outgoing stats on the remote
    // transport
    SimulatorTransport* trans = getNetTransport(destNode, getPort());
    ASSERT(trans);
    ret = trans->getStats(localNode);
  }
  if (ret != NULL) {
    uint64_t nodeTime = SimTimeUtil::nodeTimeu(localNode);
    ret->update(nodeTime);
    // always calculate the windowSum manually so we can exclude events
    // in the history list that have not happened yet on this node
    size_t windowSum = 0;
    for (BufferStatistics::HistoryList::const_iterator i = ret->history.begin(); 
        i != ret->history.end(); i++) {
      if (i->time <= nodeTime) {
        windowSum += i->value;
      }
      else {
        break;
      }
    }
    ret->windowSum = windowSum;
  }
  return ret;
}

}
