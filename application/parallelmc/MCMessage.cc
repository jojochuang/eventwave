#include <cstring>

#include "Serializable.h"
#include "MCMessage.h"

using namespace macemc;

MCMessage::MCMessage(std::string str) {
  demarshal_str(str);
}

MCMessage::MCMessage(unsigned type, unsigned from_node, unsigned from_proc, 
                     unsigned to_node, unsigned to_proc) {
  this->contents[TYPE_INDEX] = type;
  this->contents[FROM_NODE_INDEX] = from_node;
  this->contents[FROM_PROC_INDEX] = from_proc;
  this->contents[TO_NODE_INDEX] = to_node;
  this->contents[TO_PROC_INDEX] = to_proc;
  
  memset(contents + DATA_INDEX, 0, MCMESSAGE_DATA_SIZE * sizeof(unsigned));
}

unsigned MCMessage::get_type() {
    return this->contents[TYPE_INDEX];
}

unsigned MCMessage::get_from_node() {
    return this->contents[FROM_NODE_INDEX];
}

unsigned MCMessage::get_from_proc() {
    return this->contents[FROM_PROC_INDEX];
}

unsigned MCMessage::get_to_node() {
    return this->contents[TO_NODE_INDEX];
}

unsigned MCMessage::get_to_proc() {
    return this->contents[TO_PROC_INDEX];
}

void MCMessage::set_type(unsigned type) {
    this->contents[TYPE_INDEX] = type;
}

void MCMessage::set_from_node(unsigned from_node) {
    this->contents[FROM_NODE_INDEX] = from_node;
}

void MCMessage::set_from_proc(unsigned from_proc) {
    this->contents[FROM_PROC_INDEX] = from_proc;
}

void MCMessage::set_to_node(unsigned to_node) {
    this->contents[TO_NODE_INDEX] = to_node;
}

void MCMessage::set_to_proc(unsigned to_proc) {
    this->contents[TO_PROC_INDEX] = to_proc;
}

uint8_t *MCMessage::marshal_bytes() {
  return (uint8_t *) (this->contents);
}

void MCMessage::demarshal_bytes(uint8_t *bytes) {  
  memcpy(this->contents, bytes, sizeof(unsigned) * MESSAGE_SIZE);
  return;
}

std::string MCMessage::marshal_str() {
  std::string s;

  for (unsigned i = 0; i < MESSAGE_SIZE; i++) {
    mace::serialize(s, &contents[i]);
  }

  return s;
}

void MCMessage::demarshal_str(std::string &str) {
  std::istringstream instream(str);

  for (unsigned i = 0; i < MESSAGE_SIZE; i++) {
    mace::deserialize(instream, &(contents[i]));
  }

  return;
}
