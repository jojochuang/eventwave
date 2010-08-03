#include <cassert>
#include "MCMessage.h"
#include "MCMessagePrefixRequest.h"

using namespace macemc;

MCMessagePrefixRequest::MCMessagePrefixRequest(unsigned from_node, unsigned from_proc, unsigned to_node, 
                                               unsigned to_proc, unsigned prefixes_needed) : MCMessage(MCMESSAGE_TYPE_PREFIX_REQUEST, from_node, from_proc, to_node, to_proc) {
  this->contents[DATA_INDEX] = prefixes_needed;
}

unsigned MCMessagePrefixRequest::get_prefixes_needed() {
    return this->contents[DATA_INDEX];
}
