#include <cstring>

#ifndef _MACEMC_PREFIX_TREE_NODE_
#define _MACEMC_PREFIX_TREE_NODE_

namespace macemc {
  class PrefixTreeNode {
  private:
    PrefixTreeNode **children;
    PrefixTreeNode *parent;
    int maxChildren;
    int *subtreeSizes;
    int prefixCount;
    int indexAtParent;

    void updateChildCount(int index, int childCount);
  public:
    PrefixTreeNode(int numChildren, int parentIndex = 0) : parent(NULL), prefixCount(numChildren), indexAtParent(parentIndex) {
      children = new PrefixTreeNode*[numChildren];
      subtreeSizes = new int[numChildren];
      maxChildren = numChildren;

      for (int i = 0; i < numChildren; i++) {
        children[i] = NULL;
        subtreeSizes[i] = 1;
      }
    }
    
    ~PrefixTreeNode() {
      for (int i = 0; i < maxChildren; i++) {
        if (children[i] != NULL) {
          delete children[i];
        }
      }
      delete[] children;
      delete[] subtreeSizes;
    }

    void addChild(unsigned index, int numChildren);
    bool hasChild(unsigned index);
    // How many children the node can have _at most_
    int numChildren();
    PrefixTreeNode *getChild(unsigned index);
    void setParent(PrefixTreeNode *parent);
    int numPrefixes();
    bool checkTreeSanity();
  };
}
#endif // _MACEMC_PREFIX_TREE_NODE_
