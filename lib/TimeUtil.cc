#include "TimeUtil.h"

TimeUtil& TimeUtil::Instance() {
  if (_inst == NULL) {
    _inst = new TimeUtil();
  }
  return *_inst;
}

uint64_t TimeUtil::timeuImpl() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return timeu(tv);
}

time_t TimeUtil::timeImpl() {
  return ::time(0);
}

void TimeUtil::fillTimeval(uint64_t t, struct timeval& tv) {
  tv.tv_sec = t / 1000000;
  tv.tv_usec = t % 1000000;
} // fillTimeval

uint64_t TimeUtil::timeu(const struct timeval& tv) {
  return (((uint64_t)tv.tv_sec * 1000000) + tv.tv_usec);  
} 

m_suseconds_t TimeUtil::timediff(const timeval& start, const timeval& end) {
  return ((int64_t)end.tv_usec - start.tv_usec) + (((int64_t)end.tv_sec - start.tv_sec) * 1000000);
} // timediff

double TimeUtil::timed() {
  return timeu() / 1000000.0;
} // timed

TimeUtil* TimeUtil::_inst = NULL;
