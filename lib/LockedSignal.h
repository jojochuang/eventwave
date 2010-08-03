#ifndef _LOCKED_SIGNAL_H
#define _LOCKED_SIGNAL_H

#include "ScopedLock.h"
#include "TimeUtil.h"
#include <errno.h>

class LockedSignal {
public:
  LockedSignal() : waiting(false), signalled(false) {
    ASSERT(pthread_mutex_init(&mutex, 0) == 0);
    ASSERT(pthread_cond_init(&cond, 0) == 0);
  }
  
  virtual ~LockedSignal() {
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
  }

  void signal() {
    ScopedLock sl(mutex);
    if (!signalled) {
      signalled = true;
      if (waiting) {
        pthread_cond_signal(&cond);
      }
    }
  }

  int wait(uint64_t usec = 0) {
    if (usec == 0) {
      return lockWait(0);
    }
    else {
      struct timeval t;
      struct timespec ts;
      uint64_t fintime = TimeUtil::timeu() + usec;
      TimeUtil::fillTimeval(fintime, t);
      ts.tv_sec = t.tv_sec;
      ts.tv_nsec = t.tv_usec * 1000;
      return lockWait(&ts);
    }
  }

protected:

  int lockWait(const struct timespec* ts) {
    int r = 1;
    ScopedLock sl(mutex);
    if (!signalled) {
      waiting = true;
      if (ts) {
	r = pthread_cond_timedwait(&cond, &mutex, ts);
      }
      else {
	pthread_cond_wait(&cond, &mutex);
      }
    }
    waiting = false;
    signalled = false;
    return r != ETIMEDOUT;
  }

private:
  bool waiting;
  bool signalled;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
}; // class LockedSignal


#endif // _LOCKED_SIGNAL_H
