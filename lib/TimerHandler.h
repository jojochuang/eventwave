#ifndef _TIMER_HANDLER_H
#define _TIMER_HANDLER_H

#include <pthread.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>       
#include <string>
#include <cassert>

/// base class for timers which can be scheduled with the scheduler
class TimerHandler {
public:
  /// Timers are constructed with a description string, so you can ask them what timer they are.
  TimerHandler(std::string desc = "", int simulatedWeight = 1, bool locked = false);

  virtual ~TimerHandler();

  /// called by the scheduler to fire the timer
  void fire() {
    scheduled = false;
    expire();
  }

  /**
   * \brief call this on the timer handler to schedule it with the scheduler
   *
   * @param time the time to schedule in microseconds
   * @param abs true means time is absolute, false means it is now+time
   * @param align if true the timer will try to schedule itself for a second boundary (no parts of a second)
   *
   * @return the absolute time the timer is scheduled for
   */
  uint64_t schedule(uint64_t time, bool abs = false, bool align = false);

  /// used to cancel a timer.
  void cancel();
  const std::string& getDescription() const { return description; } ///< returns the description of the timer
  unsigned getId() const { return id; } ///< returns the unique timer id
  bool isScheduled() const { return scheduled; } ///< returns true if the timer is currently scheduled
  bool isRunning() const { return running; } ///< returns true if the timer is scheduled or trying to fire (acquiring a lock)
  bool operator==(const TimerHandler& other) const { return getId() == other.getId(); }

  int getSimWeight() const { return simWeight; }

protected:

  virtual void expire() = 0; ///< implemented by each timer subclass with the action to take when the timer fires
  /// call this during expire to indicate that the timer is firing (lock acquired) and is ready to be scheduled again.
  void clearRunning() { 
    running = false;
  }

  void lock() { assert(pthread_mutex_lock(&tlock) == 0); }
  void unlock() { assert(pthread_mutex_unlock(&tlock) == 0); }

private:
  std::string description; ///< each timer has a description of what time of timer it is.
  const int simWeight; ///< Simulated timer weight (specifically for app events)
  bool locked;
  bool scheduled; ///< true if the scheduler has state for this timer
  bool running; ///< true if the scheduler has state for the timer, and until clearRunning is called (or cancel is called)
  /// a unique id for the timer
  /**
   * \todo I'm not sure if this field is presently being used, but it might be
   * a good alternative to storing timer pointers and casting.
   */
  unsigned id;
  pthread_mutex_t tlock;
}; // TimerHandler

#endif // _TIMER_HANDLER_H
