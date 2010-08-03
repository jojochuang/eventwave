#include "MCMessage.h"
#include "MCMessagePrefixReply.h"

using namespace macemc;

MCMessagePrefixReply::MCMessagePrefixReply(unsigned from_node, unsigned from_proc, 
                                           unsigned to_node, unsigned to_proc, unsigned depth, 
                                           mace::vector<unsigned> prefix) : MCMessage(MCMESSAGE_TYPE_PREFIX_REPLY, from_node, from_proc, to_node, to_proc) {
    unsigned prefixSize = prefix.size();

    this->contents[DATA_INDEX] = depth;
    this->contents[DATA_INDEX + 1] = prefixSize;

    assert(prefixSize < 2 || prefixSize - 2 <= MCMESSAGE_DATA_SIZE);

    for (unsigned i = 0; i < prefixSize; ++i) {
        this->contents[DATA_INDEX + i + 2] = prefix[i];
    }
}

unsigned MCMessagePrefixReply::get_depth() {
    return this->contents[DATA_INDEX];
}

mace::vector<unsigned> *MCMessagePrefixReply::get_prefix() {
    mace::vector<unsigned> *result = new mace::vector<unsigned>(this->contents[DATA_INDEX + 1]);

    for (unsigned i = 0; i < this->contents[DATA_INDEX + 1]; ++i) {
        (*result)[i] = this->contents[DATA_INDEX + i + 2];
    }

    return result;
}
