#include "MCMessage.h"
#include "MCMessagePrefixCount.h"

using namespace macemc;

MCMessagePrefixCount::MCMessagePrefixCount(unsigned from_node, unsigned from_proc, unsigned prefix_count) : MCMessage(MCMESSAGE_TYPE_PREFIX_COUNT, from_node, from_proc) {
    this->contents[DATA_INDEX] = prefix_count;
}

unsigned MCMessagePrefixCount::get_prefix_count() {
    return this->contents[DATA_INDEX];
}
