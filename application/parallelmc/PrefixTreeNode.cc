#include "massert.h"
#include "PrefixTreeNode.h"

using namespace macemc;


void PrefixTreeNode::addChild(unsigned index, int numChildren) {
  if (children[index] != NULL) {
    ASSERT(false); // Can't add a child more than once to the same branch
  }
  children[index] = new PrefixTreeNode(numChildren, index);
  children[index]->setParent(this);

  this->updateChildCount(index, numChildren);
}

void PrefixTreeNode::updateChildCount(int index, int childCount) {
  ASSERT(subtreeSizes[index] < childCount);

  prefixCount -= subtreeSizes[index];
  subtreeSizes[index] = childCount;
  prefixCount += subtreeSizes[index];

  if (parent != NULL) {
    parent->updateChildCount(indexAtParent, prefixCount);
  }
}

bool PrefixTreeNode::hasChild(unsigned index) {
  return children[index] != NULL;
}

int PrefixTreeNode::numChildren() {
  return maxChildren;
}

PrefixTreeNode *PrefixTreeNode::getChild(unsigned index) {
  return children[index];
}

int PrefixTreeNode::numPrefixes() {
  return prefixCount;
}

void PrefixTreeNode::setParent(PrefixTreeNode *parent) {
  this->parent = parent;
}

bool PrefixTreeNode::checkTreeSanity() {
  int sum = 0;

  for (int i = 0; i < maxChildren; i++) {
    sum += subtreeSizes[i];
  }

  if (sum != prefixCount) {
    return false;
  }

  if (parent != NULL && parent->getChild(indexAtParent) != this) {
    return false;
  }

  for (int i = 0; i < maxChildren; i++) {
    if (children[i] != NULL && !(children[i]->checkTreeSanity())) {
      return false;
    }
  }

  return true;
}
