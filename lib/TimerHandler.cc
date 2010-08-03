#include "massert.h"
#include "TimerHandler.h"
#include "Scheduler.h"
#include "NumberGen.h"
#include "ScopedLock.h"

TimerHandler::TimerHandler(std::string desc, bool lk) :
  description(desc), locked(lk), scheduled(false), running(false),
  id(NumberGen::Instance("TimerHandler")->GetVal()) {

  pthread_mutex_init(&tlock, 0);
}

TimerHandler::~TimerHandler() {
  pthread_mutex_destroy(&tlock);
}

void TimerHandler::cancel() {
  if (locked) {
    lock();
  }
  if (scheduled) {
    Scheduler::Instance().cancel(*this);
  }
  scheduled = false;
  running = false;
  if (locked) {
    unlock();
  }
} // TimerHandler::cancel

uint64_t TimerHandler::schedule(uint64_t time, bool abs, bool align) {
  if (locked) {
    lock();
  }
  else {
    ASSERT(!scheduled);
  }
    
  scheduled = true;
  running = true;

  if (align && (time % (1000*1000) == 0)) {
    uint64_t now = TimeUtil::timeu();
    uint sec = time / (1000*1000);
    uint64_t sleep = 1000*1000;
    sleep -= (now % (1000 * 1000));
    if (sleep < 500*1000) {
      sleep += 1000*1000;
    }
    time = (sec - 1) * 1000*1000 + sleep;
  }
    
  uint64_t r = Scheduler::Instance().schedule(*this, time, abs);
  if (locked) {
    unlock();
  }
  return r;
} // TimerHandler::schedule
