#ifndef __PREFIX_BALANCER_H__
#define __PREFIX_BALANCER_H__

namespace macemc {
  class PrefixBalancer {
  private:
    unsigned numZeroes;
    unsigned *requestCounts;
    unsigned processCount;
  public:
    PrefixBalancer(unsigned processCount);
    ~PrefixBalancer();
    void addRequest(unsigned proc, unsigned count = 1);
    unsigned getRecipient();
  };
}

#endif // __PREFIX_BALANCER_H__
