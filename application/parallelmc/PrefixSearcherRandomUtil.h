#ifndef _PREFIX_SEARCHER_RANDOM_UTIL_
#define _PREFIX_SEARCHER_RANDOM_UTIL_

#include "params.h"
#include "SearchRandomUtil.h"

class PrefixSearcherRandomUtil : public SearchRandomUtil {
public:
  PrefixSearcherRandomUtil() : SearchRandomUtil() {}
  static PrefixSearcherRandomUtil* SetInstance();
  bool nextSub();
};

#endif // _PREFIX_SEARCHER_RANDOM_UTIL_
