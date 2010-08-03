#include "PrefixTree.h"
#include "SimRandomUtil.h"
#include "massert.h"
#include <iostream>

using namespace macemc;

int main(int argc, char **argv) {
  PrefixTree tree;
  UIntList path;
  UIntList outOf;

  for (int i = 0; i < 20; i++) {
    // [0] [2]
    path.push_back(0);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();

    // [1] [2]
    path.push_back(1);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();

    // [00] [22]
    path.push_back(0);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [01] [22]
    path.push_back(0);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear(); 

    // [10] [22]
    path.push_back(1);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [11] [22]
    path.push_back(1);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear(); 

    // [000] [224]
    path.push_back(0);
    path.push_back(0);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [001] [224]
    path.push_back(0);
    path.push_back(0);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [002] [224]
    path.push_back(0);
    path.push_back(0);
    path.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [003] [224]
    path.push_back(0);
    path.push_back(0);
    path.push_back(3);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [010] [222]
    path.push_back(0);
    path.push_back(1);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [011] [222]
    path.push_back(0);
    path.push_back(1);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [100] [222]
    path.push_back(1);
    path.push_back(0);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [101] [222]
    path.push_back(1);
    path.push_back(0);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [110] [224]
    path.push_back(1);
    path.push_back(1);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [111] [224]
    path.push_back(1);
    path.push_back(1);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [112] [224]
    path.push_back(1);
    path.push_back(1);
    path.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [113] [224]
    path.push_back(1);
    path.push_back(1);
    path.push_back(3);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0000] [2243]
    path.push_back(0);
    path.push_back(0);
    path.push_back(0);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(3);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0001] [2243]
    path.push_back(0);
    path.push_back(0);
    path.push_back(0);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(3);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0002] [2243]
    path.push_back(0);
    path.push_back(0);
    path.push_back(0);
    path.push_back(2);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(3);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0010] [2242]
    path.push_back(0);
    path.push_back(0);
    path.push_back(1);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0011] [2242]
    path.push_back(0);
    path.push_back(0);
    path.push_back(1);
    path.push_back(1);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(2);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();  

    // [0020] [2244]
    path.push_back(0);
    path.push_back(0);
    path.push_back(2);
    path.push_back(0);
    outOf.push_back(2);
    outOf.push_back(2);
    outOf.push_back(4);
    outOf.push_back(4);
    tree.addPrefix(path, outOf);
    path.clear();
    outOf.clear();
  }
  ASSERT(tree.checkTreeSanity());

  PrefixList prefixes;
  tree.prefixes(prefixes);

  ASSERT(prefixes.size() == (unsigned) tree.numPrefixes());

  for(PrefixList::iterator iter = prefixes.begin(); iter != prefixes.end(); iter++) {
    std::cout << **iter << std::endl;
  }
}
