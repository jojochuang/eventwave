#include <cassert>
#include <climits>

#include "Log.h"
#include "PrefixBalancer.h"

using namespace macemc;

PrefixBalancer::PrefixBalancer(unsigned processCount) {
  requestCounts = new unsigned[processCount - 1];
  numZeroes = processCount - 1;
  this->processCount = processCount - 1;

  for (unsigned i = 0; i < this->processCount; i++) {
    requestCounts[i] = 0;
  }
}

PrefixBalancer::~PrefixBalancer() {
  delete[] requestCounts;
}

void PrefixBalancer::addRequest(unsigned proc, unsigned count) {
  proc--;

  requestCounts[proc] += count;

  if (requestCounts[proc] == count) {
    numZeroes--;
  }

  if (numZeroes == 0) {
    unsigned minRequestCount = UINT_MAX;

    for (unsigned i = 0; i < processCount; i++) {
      if (requestCounts[i] < minRequestCount) {
        minRequestCount = requestCounts[i];
      }
    }

    for (unsigned i = 0; i < processCount; i++) {
      requestCounts[i] -= minRequestCount;

      if (!requestCounts[i]) {
        numZeroes++;
      }
    }
  }

  Log::log("PrefixBalancer") << "Current prefix vector: [ ";

  for (unsigned i = 0; i < processCount; i++) {
    Log::log("PrefixBalancer") << requestCounts[i] << " ";
  }

  Log::log("PrefixBalancer") << "]" << Log::endl;
}

unsigned PrefixBalancer::getRecipient() {
  unsigned maxRequestCount = 0;
  unsigned maxProc = 0;

  for (unsigned i = 0; i < processCount; i++) {
    if (requestCounts[i] > maxRequestCount) {
      maxRequestCount = requestCounts[i];
      maxProc = i;
    }
  }

  if (requestCounts[maxProc] > 0) {
    requestCounts[maxProc]--;

    if (!requestCounts[maxProc]) {
      numZeroes++;
    }
  }

  return maxProc + 1;
}
