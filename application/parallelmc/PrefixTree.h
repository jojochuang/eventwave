#include <vector>
#include "Sim.h"
#include "SimRandomUtil.h"
#include "PrefixTreeNode.h"

#ifndef _MACEMC_PREFIX_TREE_
#define _MACEMC_PREFIX_TREE_

typedef std::vector<UIntList*> PrefixList;

namespace macemc {
  class PrefixTree {
  private:
    PrefixTreeNode *root;

  public:
    PrefixTree() : root(NULL) {}

    ~PrefixTree() {
      delete root;
    }

    void addPrefix(const UIntList& path, const UIntList& bounds);
    int numPrefixes();
    void prefixes(PrefixList& prefixList);
    bool checkTreeSanity();
    void boundsForPrefix(UIntList& path, UIntList& bounds);

  private:
    void prefixesHelper(PrefixTreeNode *currentNode, UIntList& currentPath, PrefixList& prefixList);
  };
}
#endif // _MACEMC_PREFIX_TREE_
