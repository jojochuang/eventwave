#include "MCMessage.h"
#include "MCMessageData.h"

using namespace macemc;

MCMessageData::MCMessageData(unsigned from_node, unsigned from_proc, unsigned hash, UIntList path) : MCMessage(MCMESSAGE_TYPE_DATA, from_node, from_proc) {
    this->contents[DATA_INDEX] = hash;
    this->contents[DATA_INDEX + 1] = path.size();

    assert(path.size() <= (MCMESSAGE_DATA_SIZE - 2));

    for (unsigned i = 0; i < path.size(); ++i) {
        this->contents[DATA_INDEX + i + 2] = path[i];
    }
}

unsigned MCMessageData::get_hash() {
    return this->contents[DATA_INDEX];
}

UIntList *MCMessageData::get_path() {
    UIntList *result = new UIntList(this->contents[DATA_INDEX + 1]);

    for (unsigned i = 0; i < this->contents[DATA_INDEX + 1]; ++i) {
        (*result)[i] = this->contents[DATA_INDEX + i + 2];
    }

    return result;
}
