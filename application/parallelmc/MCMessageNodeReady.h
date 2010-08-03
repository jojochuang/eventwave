#ifndef __MCMESSAGE_NODE_READY_
#define _MCMESSAGE_NODE_READY_

#include "MCMessage.h"

namespace macemc {
  class MCMessageNodeReady : public MCMessage {
  public:
    MCMessageNodeReady(std::string str) : MCMessage(str) {}
    MCMessageNodeReady(unsigned from_node) : MCMessage(MCMESSAGE_TYPE_NODE_READY, from_node, 0) {}
  };
}
#endif // _MCMESSAGE_NODE_READY_
