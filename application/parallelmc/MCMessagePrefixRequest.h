#ifndef __MCMESSAGE_PREFIX_REQUEST_H__
#define __MCMESSAGE_PREFIX_REQUEST_H__

#include "MCMessage.h"

namespace macemc {

  class MCMessagePrefixRequest : public MCMessage {
  public:
    MCMessagePrefixRequest(std::string str) : MCMessage(str) {}
    MCMessagePrefixRequest(unsigned from_node, unsigned from_proc, unsigned to_node, unsigned to_proc, unsigned prefixes_needed = 1);
    
    unsigned get_prefixes_needed();
  };
}

#endif  /* __MCMESSAGE_PREFIX_REQUEST_H__ */
