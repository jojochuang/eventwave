#ifndef __MCMESSAGE_NODE_INFO_H__
#define __MCMESSAGE_NODE_INFO_H__

#include "MCMessage.h"

namespace macemc {

    class MCMessageNodeInfo : public MCMessage {
        public:
            MCMessageNodeInfo(std::string str) : MCMessage(str) { }
            MCMessageNodeInfo(unsigned from_node, unsigned from_proc, unsigned node_rank, unsigned node_count);

            unsigned get_node_rank();
            unsigned get_node_count();
    };
}


#endif  /* __MCMESSAGE_NODE_INFO_H__ */
