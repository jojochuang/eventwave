#ifndef __MCMESSAGE_PREFIX_COUNT_H__
#define __MCMESSAGE_PREFIX_COUNT_H__

#include "MCMessage.h"

namespace macemc {

    class MCMessagePrefixCount : public MCMessage {
        public:
            MCMessagePrefixCount(std::string str) : MCMessage(str) { }
            MCMessagePrefixCount(unsigned from_node, unsigned from_proc, unsigned prefix_count);

            unsigned get_prefix_count();
    };
}

#endif  /* __MCMESSAGE_PREFIX_COUNT_H__ */
