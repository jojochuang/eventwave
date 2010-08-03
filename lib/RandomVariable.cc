#include "RandomVariable.h"
#include "RandomUtil.h"
#include <math.h>
#include <limits.h>

namespace RandomVariable {

  double pareto(double xm, double k) {
    double u = (double)RandomUtil::randInt() / UINT_MAX;
    return (xm / ( pow(u, (1/k))));
  }

}
