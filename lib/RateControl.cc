#include "maceConfig.h"
#include "RateControl.h"
#include "SmoothedEMWARateControl.h"
#ifdef HAVE_GSL
#include "SampleSignificanceRateControl.h"
#endif

#include "mace-macros.h"
#include "Log.h"
#include "TimeUtil.h"
#include "Printable.h"
#include "params.h"

using namespace std;

RateControl& RateControl::instance() {
  ADD_SELECTORS("RateControl::instance");
  string controlType = params::get<string>("RATE_CONTROL_ALGORITHM");
  const double EMWA_ALPHA = params::get("RATE_CONTROL_EMWA_ALPHA", 8.0);
  const double EMWA_BETA = params::get("RATE_CONTROL_EMWA_BETA", 4.0);
  const double EMWA_K = params::get("RATE_CONTROL_EMWA_K", 4.0);
  if (controlType == "SmoothedEMWA") {
    return *(new SmoothedEMWARateControl(1.0 / EMWA_ALPHA, 1.0 / EMWA_BETA,
					 EMWA_K));
  }
  #ifdef HAVE_GSL
  else if (controlType == "SampleSignificance") {
    const double SIG_ALPHA = params::get("RATE_CONTROL_SIG_ALPHA", 0.05);
    const double SIG_BETA = params::get("RATE_CONTROL_SIG_BETA", 0.2);
//     const uint32_t N = params::get("RATE_CONTROL_SIG_N", 1000);
    return *(new SampleSignificanceRateControl(SIG_ALPHA, SIG_BETA,
					       1.0 / EMWA_ALPHA,
					       1.0 / EMWA_BETA,
					       EMWA_K));
  }
  #endif
  else {
    maceerr << "unknown RateControl type: " << controlType << Log::endl;
    ABORT("unknown RateControl type");
  }
} // instance

