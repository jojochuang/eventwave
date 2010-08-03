#include <cassert>
#include "mvector.h"

#include "MCMessage.h"
#include "MCMessageData.h"
#include "MCMessageNodeInfo.h"
#include "MCMessagePrefixCount.h"
#include "MCMessagePrefixReply.h"
#include "MCMessagePrefixRequest.h"
#include "MCMessageNodeReady.h"

using namespace macemc;

/*
 * Serves as the chief test for the proper functionality, 
 * marshaling and unmarshaling of parallelmc message types.
 */

void assertMessageBasics(MCMessage *message, 
                         unsigned type, 
                         unsigned from_node, 
                         unsigned from_proc, 
                         unsigned to_node = MCMESSAGE_UNASSIGNED, 
                         unsigned to_proc = MCMESSAGE_UNASSIGNED) {
  assert(message->get_type() == type);
  assert(message->get_from_node() == from_node);
  assert(message->get_from_proc() == from_proc);
  assert(message->get_to_node() == to_node);
  assert(message->get_to_proc() == to_proc);
}

void assertPathsEqual(UIntList *p1, UIntList *p2) {
  assert(p1->size() == p2->size());
  
  for (unsigned i = 0; i < p1->size(); i++) {
    assert((*p1)[i] == (*p2)[i]);
  }
}

void checkMCMessageData(MCMessageData &testMessage, unsigned from_node, 
                        unsigned from_proc, unsigned hash, UIntList *path) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_DATA, from_node, from_proc);
  assert(testMessage.get_hash() == hash);
  assertPathsEqual(path, testMessage.get_path());
}

void checkMCMessageNodeInfo(MCMessageNodeInfo &testMessage, unsigned from_node, 
                            unsigned from_proc, unsigned node_rank, 
                            unsigned node_count) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_NODE_INFO, from_node, from_proc);
  assert(testMessage.get_node_rank() == node_rank);
  assert(testMessage.get_node_count() == node_count);
}

void checkMCMessagePrefixCount(MCMessagePrefixCount &testMessage, unsigned from_node,
                               unsigned from_proc, unsigned prefix_count) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_PREFIX_COUNT, from_node, from_proc);
  assert(testMessage.get_prefix_count() == prefix_count);
}

void checkMCMessagePrefixReply(MCMessagePrefixReply &testMessage, unsigned from_node, 
                               unsigned from_proc, unsigned to_node, unsigned to_proc, 
                               unsigned depth, UIntList *prefix) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_PREFIX_REPLY, from_node, from_proc,
                      to_node, to_proc);
  assert(testMessage.get_depth() == depth);
  assertPathsEqual(testMessage.get_prefix(), prefix);
}

void checkMCMessagePrefixRequest(MCMessagePrefixRequest &testMessage, unsigned from_node, unsigned from_proc, unsigned to_node, unsigned to_proc, unsigned prefixes_needed) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_PREFIX_REQUEST, from_node, from_proc, to_node, to_proc);
  assert(testMessage.get_prefixes_needed() == prefixes_needed);
}

void checkMCMessageNodeReady(MCMessageNodeReady &testMessage, unsigned from_node) {
  assertMessageBasics(&testMessage, MCMESSAGE_TYPE_NODE_READY, from_node, 0);
  assert(testMessage.get_from_node() == from_node);
}

int main(int argc, char **argv) {
  unsigned from_node = 2;
  unsigned from_proc = 4;
  unsigned to_node = 6;
  unsigned to_proc = 8;

  std::string marshaledMessage;

  // =============
  // MCMessageData
  // =============

  UIntList path;
  
  for (int i = 0; i < MCMESSAGE_DATA_SIZE - 2; i++) {
    path.push_back(i);
  }
  
  unsigned hash = 1234567;
  
  MCMessageData testDataMessage(from_node, from_proc, hash, path);

  checkMCMessageData(testDataMessage, from_node, from_proc, hash, &path);

  marshaledMessage = testDataMessage.marshal_str();
  MCMessageData demarshaledDataMessage(marshaledMessage);

  checkMCMessageData(demarshaledDataMessage, from_node, from_proc, hash, &path);

  // =============
  // MCMessageNodeInfo
  // =============

  unsigned node_rank = 4;
  unsigned node_count = 17;

  MCMessageNodeInfo testNodeInfoMessage(from_node, from_proc, node_rank, node_count);

  checkMCMessageNodeInfo(testNodeInfoMessage, from_node, from_proc, node_rank, node_count);

  marshaledMessage = testNodeInfoMessage.marshal_str();
  MCMessageNodeInfo demarshaledNodeInfoMessage(marshaledMessage);

  checkMCMessageNodeInfo(demarshaledNodeInfoMessage, from_node, from_proc, node_rank, node_count);

  // ====================
  // MCMessagePrefixCount
  // ====================

  unsigned prefix_count = 42;

  MCMessagePrefixCount testCountMessage(from_node, from_proc, prefix_count);

  checkMCMessagePrefixCount(testCountMessage, from_node, from_proc, prefix_count);

  marshaledMessage = testCountMessage.marshal_str();
  MCMessagePrefixCount demarshaledCountMessage(marshaledMessage);

  checkMCMessagePrefixCount(demarshaledCountMessage, from_node, from_proc, prefix_count);

  // ====================
  // MCMessagePrefixReply
  // ====================

  unsigned depth = 72;
  

  MCMessagePrefixReply testReplyMessage(from_node, from_proc, to_node, to_proc, depth, path);

  checkMCMessagePrefixReply(testReplyMessage, from_node, from_proc, to_node, to_proc, depth, &path);
  
  marshaledMessage = testReplyMessage.marshal_str();
  MCMessagePrefixReply demarshaledReplyMessage(marshaledMessage);

  checkMCMessagePrefixReply(demarshaledReplyMessage, from_node, from_proc, to_node, to_proc, depth, &path);

  // ======================
  // MCMessagePrefixRequest
  // ======================

  unsigned prefixes_needed = 1000;

  MCMessagePrefixRequest testRequestMessage(from_node, from_proc, to_node, to_proc, prefixes_needed);

  checkMCMessagePrefixRequest(testRequestMessage, from_node, from_proc, to_node, to_proc, prefixes_needed);

  marshaledMessage = testRequestMessage.marshal_str();
  MCMessagePrefixRequest demarshaledRequestMessage(marshaledMessage);

  checkMCMessagePrefixRequest(demarshaledRequestMessage, from_node, from_proc, to_node, to_proc, prefixes_needed);
  
  // ==================
  // MCMessageNodeReady
  // ==================
  
  MCMessageNodeReady testNodeReadyMsg(from_node);
  checkMCMessageNodeReady(testNodeReadyMsg, from_node);
  
  marshaledMessage = testNodeReadyMsg.marshal_str();
  MCMessageNodeReady demarshaledNodeReadyMsg(marshaledMessage);
  
  checkMCMessageNodeReady(demarshaledNodeReadyMsg, from_node);
}

