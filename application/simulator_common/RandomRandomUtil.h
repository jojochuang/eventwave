#ifndef RANDOM_RANDOM_UTIL_H
#define RANDOM_RANDOM_UTIL_H

#include "SimRandomUtil.h"

class RandomRandomUtil : public SimRandomUtil {
  
public:
  RandomRandomUtil() : SimRandomUtil(1000) { }

  bool hasNextSub(bool isLive) {
    return true;
  }
  
  bool nextSub() {
    return false;
  }
  
  bool implementsPrintPath() {
    return true;
  }
  
  bool pathIsDone() {
    return true;
  }
  
  void dumpState() {

  }
  
  unsigned randIntImplSub(unsigned max) {
    return max;
  }

  static RandomRandomUtil* SetInstance() {
    RandomRandomUtil* t = NULL;
    
    if(_inst == NULL) { 
      _inst = t = new RandomRandomUtil(); 
    }
    return t;
  }

};

#endif // RANDOM_RANDOM_UTIL_H
