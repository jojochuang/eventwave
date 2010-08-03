#ifndef __MCMESSAGE_DATA_H__
#define __MCMESSAGE_DATA_H__

#include "mvector.h"
#include "MCMessage.h"

typedef mace::vector<unsigned> UIntList;

namespace macemc {

    class MCMessageData : public MCMessage {
        public:
            MCMessageData(std::string str) : MCMessage(str) {}
            MCMessageData(unsigned from_node, unsigned from_proc, unsigned hash, UIntList path);

            unsigned get_hash();
            UIntList *get_path();
    };
}

#endif  /* __MCMESSAGE_DATA_H__ */
