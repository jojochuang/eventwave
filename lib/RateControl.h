#ifndef _RATE_CONTROL_H
#define _RATE_CONTROL_H

#include <math.h>
#include <stdint.h>
#include "massert.h"

class RateControl {
public:
  virtual ~RateControl() { }
  virtual bool update(double data) = 0;
  virtual double getTarget() = 0;
  virtual void update(uint64_t id, double r, bool full,
		      uint64_t qsz, uint64_t& max) = 0;

  static RateControl& instance();
};


#endif // _RATE_CONTROL_H

