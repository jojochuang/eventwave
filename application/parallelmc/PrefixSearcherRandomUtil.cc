#include "PrefixSearcherRandomUtil.h"

bool PrefixSearcherRandomUtil::nextSub() {
  ADD_FUNC_SELECTORS;
  
  bool ret = false;

  unsigned depth = depths[currentPrefix];

  if (currentOutOf.size() != 0) {
    unsigned newDepth = std::min((size_t) depths[currentPrefix], _pathInts.size());

    for (; newDepth > 0; newDepth--) {
      if (depth > 1 && newDepth < depth) {
        currentSelections[newDepth - 1]++;
      }

      if (newDepth < depth && currentSelections[newDepth - 1] < currentOutOf[newDepth - 1]) {
        break;
      }
    }

    currentSelections.resize(newDepth);
    currentOutOf.resize(newDepth);

    if (newDepth == 0) {
      doneEarly[currentPrefix]++;
      
      depths[currentPrefix] += depthIncrement;
      currentPrefix = (currentPrefix + 1) % assignedPrefixes.size();
      depth = depths[currentPrefix];
      
      pathPrefix = assignedPrefixes[currentPrefix];
      pathPrefixOutOf = assignedBounds[currentPrefix];
      
      currentSelections.reserve(depth);
      currentOutOf.reserve(depth);
      maceout << "Searching up to depths of " << depth << ", " << (Sim::getPathNum()-1) << " paths searched so far." << Log::endl;
      phase = "SearchRandom:depth "+boost::lexical_cast<std::string>(depth);
      ret = true;
    }
  }
  resetGustoToggles();
  addGustoToggle(depth + _prefix.size());
  return ret;
}

PrefixSearcherRandomUtil* PrefixSearcherRandomUtil::SetInstance() {
  ADD_FUNC_SELECTORS;
  PrefixSearcherRandomUtil* t = NULL; 
  if(_inst == NULL) { 
    _inst = t = new PrefixSearcherRandomUtil();
    
    UIntList prefix;

    t->addPathPrefix(prefix, 1);
  }
  return t;
}
