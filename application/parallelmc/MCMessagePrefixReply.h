#ifndef __MCMESSAGE_PREFIX_REPLY_H__
#define __MCMESSAGE_PREFIX_REPLY_H__

#include "mvector.h"

#include "MCMessage.h"

namespace macemc {

  class MCMessagePrefixReply : public MCMessage {
  public:
    MCMessagePrefixReply(std::string str) : MCMessage(str) {}
    MCMessagePrefixReply(unsigned from_node, unsigned from_proc, unsigned to_node, unsigned to_proc, unsigned depth, mace::vector<unsigned> prefix);
    
    unsigned get_depth();
    mace::vector<unsigned> *get_prefix();
  };
}

#endif  /* __MCMESSAGE_PREFIX_REPLY_H__ */
