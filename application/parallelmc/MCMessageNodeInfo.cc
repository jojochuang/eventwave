#include "MCMessage.h"
#include "MCMessageNodeInfo.h"

using namespace macemc;

MCMessageNodeInfo::MCMessageNodeInfo(unsigned from_node, unsigned from_proc, unsigned node_rank, unsigned node_count) : MCMessage(MCMESSAGE_TYPE_NODE_INFO, from_node, from_proc) {
    this->contents[DATA_INDEX] = node_rank;
    this->contents[DATA_INDEX + 1] = node_count;
}

unsigned MCMessageNodeInfo::get_node_rank() {
    return this->contents[DATA_INDEX];
}

unsigned MCMessageNodeInfo::get_node_count() {
    return this->contents[DATA_INDEX + 1];
}
