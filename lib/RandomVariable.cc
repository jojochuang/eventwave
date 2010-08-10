#include "RandomVariable.h"
#include "RandomUtil.h"
#include "mace-macros.h"
#include <math.h>
#include <limits.h>

namespace RandomVariable {

  double pareto(double xm, double k) {
    double u = (double)RandomUtil::randInt() / UINT_MAX;
    return (xm / ( pow(u, (1/k))));
  }

  /* Computes zipf using f = 1/k^s * 1/SummationN(1/n^s).
   * N is the total number of elements
   * s is the exponent
   * k is the index of the element
   */
  int zipf(int n, double s) {
    ASSERT (n > 0 && s > 0);
    double d = 0; // Summation term
    for (int i = 0; i < n; i++)
      d += 1.0 / pow(i + 1, s);
    d = 1.0 / d;

    // (Sum of all frequency probabilities = 1)
    // Generate a random value. Cumulate frequencies till probability
    double random_prob = (double)RandomUtil::randInt() / UINT_MAX;
    double cumulative_prob = 0.0;
    for (int i = 0; i < n; i++) {
      cumulative_prob += d * 1.0 / pow(i + 1, s);
      if (cumulative_prob > random_prob)
        return i;
    }
    return n - 1;
  }

}
