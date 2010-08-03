#ifndef __MCMESSAGE_H__
#define __MCMESSAGE_H__

#include <cassert>
#include <inttypes.h>
#include <stdlib.h>
#include <sstream>
#include <string>

#define MCMESSAGE_TYPE_DATA (100)
#define MCMESSAGE_TYPE_PREFIX_REQUEST (200)
#define MCMESSAGE_TYPE_PREFIX_REPLY (300)
#define MCMESSAGE_TYPE_PREFIX_COUNT (400)
#define MCMESSAGE_TYPE_NODE_INFO (500)
#define MCMESSAGE_TYPE_NODE_READY (600)

#define MCMESSAGE_DATA_SIZE (200)

#define MCMESSAGE_UNASSIGNED (0xfffffff)

/*
 Formatting convention for MCMessage
 index                          item
 -----                          ----
 0                              type
 1                              from_node
 2                              from_proc
 3                              to_node
 4                              to_proc
 5 - MCMESSAGE_DATA_SIZE + 5    data
 */
namespace macemc {

    class MCMessage {
    protected:
      static const unsigned TYPE_INDEX = 0;
      static const unsigned FROM_NODE_INDEX = 1;
      static const unsigned FROM_PROC_INDEX = 2;
      static const unsigned TO_NODE_INDEX = 3;
      static const unsigned TO_PROC_INDEX = 4;
      static const unsigned DATA_INDEX = 5;

      static const unsigned MESSAGE_SIZE = 5 + MCMESSAGE_DATA_SIZE;

      unsigned contents[MESSAGE_SIZE];

    public:
      MCMessage(std::string str);
      MCMessage(unsigned type = 0, 
                unsigned from_node = MCMESSAGE_UNASSIGNED,
                unsigned from_proc = MCMESSAGE_UNASSIGNED,
                unsigned to_node = MCMESSAGE_UNASSIGNED, 
                unsigned to_proc = MCMESSAGE_UNASSIGNED);

      unsigned get_type();
      unsigned get_from_node();
      unsigned get_from_proc();
      unsigned get_to_node();
      unsigned get_to_proc();

      void set_type(unsigned type);
      void set_from_node(unsigned from_node);
      void set_from_proc(unsigned from_proc);
      void set_to_node(unsigned to_node);
      void set_to_proc(unsigned to_proc);

      uint8_t *marshal_bytes();
      void demarshal_bytes(uint8_t *bytes);
            
      std::string marshal_str();
      void demarshal_str(std::string &str);
    };
}

#endif  /* __MESSAGE_H__ */
