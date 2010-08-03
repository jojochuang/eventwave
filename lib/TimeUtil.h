#include <time.h>
#include <sys/time.h>
#include <stdint.h>

#ifndef __TIME_UTIL_H
#define __TIME_UTIL_H

/**
 * \file TimeUtil.h
 * \brief Defines functions for getting the time of day.
 */

/// Define a Mace-friendly type for the difference in two times, in micro-seconds.
typedef int64_t m_suseconds_t;

namespace mace {

}

/**
 * \addtogroup Utils
 * @{
 */

/**
 * \brief A Mace-friendly class for getting the time of day.  
 *
 * Implemented using virtual functions to allow the simulator to provide
 * alternate implementations of the time functions.
 */
class TimeUtil {
  protected:
    static TimeUtil* _inst;
    TimeUtil() { }
    static TimeUtil& Instance();

    virtual uint64_t timeuImpl(); 
    virtual time_t timeImpl();

  public:
    static uint64_t timeu() { return Instance().timeuImpl(); } ///< return the current time as microseconds.
    static time_t time() { return Instance().timeImpl(); } ///< return the current time as seconds.

    static double timed(); ///< return the current time as a double value in seconds and partial microseconds.
    static void fillTimeval(uint64_t t, struct timeval& tv); ///< fills a timeval based on a timestamp t.
    static uint64_t timeu(const struct timeval& tv); ///< returns the number of microseconds represented by timeval \c tv.
    static m_suseconds_t timediff(const timeval& start, const timeval& end); ///< return the number of microseconds between start and end.

    virtual ~TimeUtil() {}
};

/** @} */

#endif //__TIME_UTIL_H
