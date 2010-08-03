#ifndef _SMOOTHED_EMWA_RATECONTROL_H
#define _SMOOTHED_EMWA_RATECONTROL_H

#include "RateControl.h"

class SmoothedEMWARateControl : public virtual RateControl {
public:
  SmoothedEMWARateControl(double alpha = 1.0/8.0,
			  double beta = 1.0/4.0,
			  double k = 4) :
    skip(0), notFull(0),
    ALPHA(alpha), BETA(beta), K(k),
    rtt(0), rttvar(0), target(0), prevrtt(0), prevrttvar(0), prevtarget(0) {
  }

  virtual ~SmoothedEMWARateControl() { }

  bool update(double r) {
    double prevtarget = target;
    if (rtt == 0) {
      rtt = r;
//       rttvar = r / 2;
      rttvar = 0;
    }
    else {
      rttvar = (1 - BETA) * rttvar + BETA * fabs(rtt - r);
      rtt = (1 - ALPHA) * rtt + ALPHA * r;
    }
    target = rtt + K * rttvar;
    if (prevtarget == 0) {
      return true;
    }
    return r <= prevtarget;
  } // update

  void update(uint64_t id, double r, bool full, uint64_t qsz, uint64_t& max);
  
  double getTarget() {
    return target;
  }

protected:
  uint32_t skip;
  uint32_t notFull;
  double ALPHA;
  double BETA;
  double K;
  double rtt;
  double rttvar;
  double target;
  double prevrtt;
  double prevrttvar;
  double prevtarget;
};

#endif // _SMOOTHED_EMWA_RATECONTROL_H
