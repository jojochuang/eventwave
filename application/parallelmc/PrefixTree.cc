#include "PrefixTree.h"
#include "massert.h"

using namespace macemc;

void PrefixTree::addPrefix(const UIntList& path, const UIntList& bounds) {
  int pathSize = path.size();
  int boundSize = bounds.size();

//  ASSERT(path.size() == bounds.size());
  ASSERT(pathSize == boundSize);

  PrefixTreeNode *currentNode = root;

  int i = 0;

  while (i < pathSize) {
    int currentChild = path[i];
    int currentBound = bounds[i];


    if (currentNode == NULL) {
      ASSERT(root == NULL);
      root = new PrefixTreeNode(currentBound);
      currentNode = root;        
    }

    if (!currentNode->hasChild(currentChild) && i != pathSize - 1) {
      currentNode->addChild(currentChild, bounds[i + 1]);
    }

    currentNode = currentNode->getChild(currentChild);

    i++;
  }
}

int PrefixTree::numPrefixes() {
  return root->numPrefixes();
}

void PrefixTree::prefixes(PrefixList& prefixList) {
//  int numPrefixes = this->numPrefixes();

  // prefixList.reserve(numPrefixes);

  ASSERT(root != NULL);

  UIntList currentPath;

  prefixesHelper(root, currentPath, prefixList);
}

void PrefixTree::prefixesHelper(PrefixTreeNode *currentNode, UIntList& currentPath, PrefixList& prefixList) {
  ASSERT(currentNode != NULL);

  unsigned numChildren = currentNode->numChildren();

  for (unsigned i = 0; i < numChildren; i++) {
    currentPath.push_back(i);
    if (currentNode->hasChild(i)) {
      prefixesHelper(currentNode->getChild(i), currentPath, prefixList);
    } else {
      prefixList.push_back(new UIntList(currentPath));
    }
    currentPath.pop_back();
  }
}

bool PrefixTree::checkTreeSanity() {
  if (root != NULL) {
    return root->checkTreeSanity();
  }

  return true;
}

void PrefixTree::boundsForPrefix(UIntList& path, UIntList& bounds) {
  PrefixTreeNode *currentNode = root;
  unsigned pathSize = path.size();

  ASSERT(root != NULL);

  for (unsigned i = 0; i < pathSize; i++) {
    bounds.push_back(currentNode->numChildren());
    currentNode = currentNode->getChild(path[i]);
  }

  ASSERT(pathSize == bounds.size());
}
