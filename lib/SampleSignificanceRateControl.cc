#include "maceConfig.h"
#ifdef HAVE_GSL
#include <gsl/gsl_sf.h>

#include "Log.h"
#include "Printable.h"
#include "massert.h"
#include "params.h"
#include "SampleSignificanceRateControl.h"

using namespace std;

class SampleSignificanceRateControlBLO : public mace::BinaryLogObject, public mace::PrintPrintable {
public:
  uint64_t id;
  double r;
  bool full;
  uint64_t queuesize;
  uint64_t maxqueuesize;
  string direction;
  double target;
  double prevtarget;
  uint32_t samples;
  uint32_t minsamples;
  uint32_t missed;
  double sig;
  double rtt;
  double rttvar;

  SampleSignificanceRateControlBLO() { }
  SampleSignificanceRateControlBLO(uint64_t _id,
				   double _r,
				   bool _full,
				   uint64_t _qs,
				   uint64_t _mqs,
				   const std::string& _dir,
				   double _target,
				   double _prevtarget,
				   uint32_t _samples,
				   uint32_t _minsamples,
				   uint32_t _missed,
				   double _sig,
				   double _rtt,
				   double _rttvar
    ) :
    id(_id),
    r(_r),
    full(_full),
    queuesize(_qs),
    maxqueuesize(_mqs),
    direction(_dir),
    target(_target),
    prevtarget(_prevtarget),
    samples(_samples),
    minsamples(_minsamples),
    missed(_missed),
    sig(_sig),
    rtt(_rtt),
    rttvar(_rttvar)
  { }

protected:
  static mace::LogNode* rootLogNode;

public:
  void serialize(std::string& __str) const { }
  int deserialize(std::istream& is) throw(mace::SerializationException) {
    return 0;
  }

  void print(std::ostream& __out) const {
    __out << "maxq=" << maxqueuesize << " q=" << queuesize << " " << direction
	  << " r=" << r
	  << " f=" << full
	  << " samples=" << samples
	  << " min=" << minsamples
	  << " missed=" << missed
	  << " s=" << sig
	  << " target=" << target
	  << " prev=" << prevtarget
	  << " rtt=" << rtt
	  << " rttvar=" << rttvar
	  << " id=" << id;
  }

  void sqlize(mace::LogNode& node) const { }

  const std::string& getLogType() const {
    static const std::string type = "RateControl";
    return type;
  }

  const std::string& getLogDescription() const {
    static const std::string desc = "RateControl";
    return desc;
  }
  
  LogClass getLogClass() const {
    return STRUCTURE;
  }
  
  mace::LogNode*& getChildRoot() const { 
    return rootLogNode;
  }
  
};

mace::LogNode* SampleSignificanceRateControlBLO::rootLogNode = 0;

SampleSignificanceRateControl::SampleSignificanceRateControl(double alpha,
							     double beta,
							     double ea,
							     double eb,
							     double k
							     ) :
  SIG_ALPHA(alpha), SIG_BETA(beta),
//   N(n),  XI((double)(N - 1) / N),
  EMWA_ALPHA(ea), EMWA_BETA(eb), K(k),
  rtt(0), rttvar(0), target(0),
//   targetSum(0), targetCount(0),
  minSamples(0), maxSamples(0) {
}

SampleSignificanceRateControl::~SampleSignificanceRateControl() {
}

bool SampleSignificanceRateControl::update(double r) {
  if (rtt == 0) {
    rtt = r;
    rttvar = 0;
  }
  else {
    rttvar = (1 - EMWA_BETA) * rttvar + EMWA_BETA * fabs(rtt - r);
    rtt = (1 - EMWA_ALPHA) * rtt + EMWA_ALPHA * r;
  }
  target = rtt + K * rttvar;
  return true;
}

double SampleSignificanceRateControl::getTarget() {
  ABORT("getTarget not supported");
}

void SampleSignificanceRateControl::update(uint64_t id, double r,
					   bool full, uint64_t qsz,
					   uint64_t& maxq) {
//   static const uint32_t MIN_SAMPLES = params::get("RATE_CONTROL_SIG_MIN_SAMPLES", 100);
//   static const uint32_t MAX_SAMPLES = params::get("RATE_CONTROL_SIG_MAX_SAMPLES", 100);
  static const log_id_t lid = Log::getId("RateControl::update");
  static const uint32_t QMULT = params::get("RATE_CONTROL_SIG_QMULT", 1);
  static bool loggedParams = false;
  if (!loggedParams) {
    loggedParams = true;
    Log::log("RateControl::params")
      << " SIG_ALPHA=" << SIG_ALPHA
      << " SIG_BETA=" << SIG_BETA
//       << " N=" << N
//       << " XI=" << XI
      << " EMWA_ALPHA=" << EMWA_ALPHA
      << " EMWA_BETA=" << EMWA_BETA
      << " K=" << K
      << Log::endl;
  }

//   double prevtarget = target;
  update(r);
  
  if (minSamples == 0) {
    minSamples = maxq * QMULT;
  }
  if (maxSamples == 0) {
    maxSamples = maxq * QMULT;
  }
  
//   targetCount++;
//   if (targetCount < minSamples) {
//     targetSum += r;
//   }
//   else if (target == 0 && targetCount >= minSamples) {
//     targetSum += r;
//     target = targetSum / targetCount;
//   }
//   else {
//     target = (XI * target) + (1 - XI) * r;
//   }

  string dir = "x";
  samples.push_back(r);
  if (samples.size() < minSamples) {
    Log::binaryLog(lid, new SampleSignificanceRateControlBLO(
		     id, r, full, qsz, maxq, dir, target, 0, samples.size(),
		     minSamples, 0, 0, rtt, rttvar));
    return;
  }
  while (samples.size() > maxSamples) {
    samples.pop_front();
  }

  if (prevtarget == 0) {
    prevtarget = target;
  }

  uint32_t hit = 0;
  uint32_t missed = 0;
  for (DoubleList::const_iterator i = samples.begin(); i != samples.end(); i++) {
    if (*i <= prevtarget) {
      hit++;
    }
    else {
      missed++;
    }
  }

  double oldtarget = prevtarget;
  uint32_t total = hit + missed;
  double sig = computeSignificance(missed, total);
  SIGNIFICANCE_RESULT::type result = cmpSignificance(sig);
  if (result == SIGNIFICANCE_RESULT::BAD) {
//     target = 0;
//     targetCount = 0;
//     targetSum = 0;
    samples.clear();
    maxq--;
    dir = "-";
    prevtarget = target;
  }
  else if (result == SIGNIFICANCE_RESULT::GOOD) {
//     target = 0;
//     targetCount = 0;
//     targetSum = 0;
    samples.clear();
    maxq++;
    dir = "+";
    prevtarget = target;
  }
  else {
    ASSERT(result == SIGNIFICANCE_RESULT::INDETERMINATE);
    string dir = "0";
  }
  minSamples = maxq * QMULT;
  maxSamples = maxq * QMULT;
  Log::binaryLog(lid, new SampleSignificanceRateControlBLO(
		   id, r, full, qsz, maxq, dir, target, oldtarget, total,
		   minSamples, missed, sig, rtt, rttvar));
} // update

double SampleSignificanceRateControl::computeSignificance(unsigned int sample,
							  unsigned int total) const {
  // r = sample , n = total
  ASSERT(sample <= total);
  double p = 0;
  for (unsigned int i = 0; i <= sample; i++) {
    p += gsl_sf_choose(total, i) * pow(0.5, i) * pow(0.5, total - i);
  }
  return p;
} // computeSignificance

SampleSignificanceRateControl::SIGNIFICANCE_RESULT::type SampleSignificanceRateControl::cmpSignificance(double s) const {
  if (s > SIG_BETA) {
    return SIGNIFICANCE_RESULT::BAD;
  }
  else if (s < SIG_ALPHA) {
    return SIGNIFICANCE_RESULT::GOOD;
  }
  return SIGNIFICANCE_RESULT::INDETERMINATE;
} // cmpSignificance

#endif // HAVE_GSL
