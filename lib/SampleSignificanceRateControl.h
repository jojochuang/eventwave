#ifndef _SAMPLE_SIGNIFICANCE_RATE_CONTROL_H
#define _SAMPLE_SIGNIFICANCE_RATE_CONTROL_H

#include "mdeque.h"
#include "RateControl.h"

class SampleSignificanceRateControl : public virtual RateControl {
public:
  SampleSignificanceRateControl(double alpha, double beta,
				double ea, double eb, double k);
  virtual ~SampleSignificanceRateControl();
  bool update(double data);
  double getTarget();
  void update(uint64_t id, double r, bool full, uint64_t qsz, uint64_t& maxq);

protected:
  class SIGNIFICANCE_RESULT {
  public:
    typedef int type;
    static const type BAD = -1;
    static const type INDETERMINATE = 0;
    static const type GOOD = 1;
  };

  double computeSignificance(unsigned int sample, unsigned int total) const;
  SIGNIFICANCE_RESULT::type cmpSignificance(double s) const;

protected:
  const double SIG_ALPHA;
  const double SIG_BETA;
  const double EMWA_ALPHA;
  const double EMWA_BETA;
  const double K;
//   const uint32_t N;
//   const double XI;

  typedef mace::deque<double> DoubleList;
  DoubleList samples;
  double rtt;
  double rttvar;
  double prevtarget;
  double target;
  uint32_t minSamples;
  uint32_t maxSamples;
};

#endif // _SAMPLE_SIGNIFICANCE_RATE_CONTROL_H
