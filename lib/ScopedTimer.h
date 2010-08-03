#ifndef __SCOPED_TIMER_H
#define __SCOPED_TIMER_H

/**
 * \file ScopedTimer.h
 * \brief declares the ScopedTimer class for accumulating the time an object existed
 */
#include <deque>
#include "TimeUtil.h"

/**
 * \addtogroup Scoped
 * @{
 */

/**
 * \brief accumulate object lifetime into a variable
 *
 * Stores the start time in the constructor, and accumulates the destructor
 * time - start time into the time passed into the constructor.  The enabled
 * constructor flag allows for easy disabling of the timer without removing it
 * from the code.
 *
 * \todo James, do you think this should be in the mace namespace?
 */
class ScopedTimer {
public:
  typedef std::deque<uint64_t> TimeList;
  /**
   * \brief constructor.  creates object.
   *
   * if enabled, stores the start time in a variable for adding it to \c t later.
   *
   * \param t reference to uint64_t to add the lifespan of this object to
   * \param enabled if false the timer does nothing
   */
  ScopedTimer(uint64_t& t, bool enabled = true, TimeList* l = 0) :
    timer(t), start(enabled ? TimeUtil::timeu() : 0),
    enabled(enabled), times(l) { }
  /// on destruction, if enabled, adds the current time - start time to time from contructor.
  ~ScopedTimer() {
    if (enabled) {
      uint64_t diff = TimeUtil::timeu() - start;
      timer += diff;
      if (times) {
	times->push_back(diff);
      }	  
    }
  }

private:
  uint64_t& timer;
  uint64_t start;
  bool enabled;
  TimeList* times;
};

/**
 * @}
 */

#endif
