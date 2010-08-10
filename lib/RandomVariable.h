#ifndef RANDOM_VARIABLE_H
#define RANDOM_VARIABLE_H

/**
 * \file RandomVariable.h
 * \brief a utility for generating random variables
 */

/**
 * \addtogroup Utils
 * @{
 */

/**
 * The RandomVariable namespace is like the other utility classes, but it departs in several mechanisms. 
 * - the file name is not \e SomethingUtil.h
 * - there is no class with static methods
 *
 * Nonetheless, I am grouping it with the other utilities.
 */
namespace RandomVariable {

  double pareto(double xm, double k); ///< return a pareto distributed variable with parameters \c xm and \c k

  // return a random index between 0 and n-1 as per zipf distribution.
  // First index is most frequent
  int zipf(int n, double s); 

}

/** @} */

#endif //RANDOM_VARIABLE_H
