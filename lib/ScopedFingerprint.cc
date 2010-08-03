#include "ScopedFingerprint.h"

//namespace mace {
//string ScopedFingerprint::fingerprint;
//}

pthread_key_t mace::ScopedFingerprint::ThreadSpecific::pkey;
pthread_once_t mace::ScopedFingerprint::ThreadSpecific::keyOnce = PTHREAD_ONCE_INIT;
unsigned int mace::ScopedFingerprint::ThreadSpecific::count = 0;

mace::ScopedFingerprint::ThreadSpecific::ThreadSpecific() {
  count++;
  vtid = count;
  fingerprint = "";
} // ThreadSpecific

mace::ScopedFingerprint::ThreadSpecific::~ThreadSpecific() {
} // ~ThreadSpecific

mace::ScopedFingerprint::ThreadSpecific* mace::ScopedFingerprint::ThreadSpecific::init() {
  pthread_once(&keyOnce, mace::ScopedFingerprint::ThreadSpecific::initKey);
  ThreadSpecific* t = (ThreadSpecific*)pthread_getspecific(pkey);
  if (t == 0) {
    t = new ThreadSpecific();
    assert(pthread_setspecific(pkey, t) == 0);
  }

  return t;
} // init

void mace::ScopedFingerprint::ThreadSpecific::initKey() {
  assert(pthread_key_create(&pkey, NULL) == 0);
} // initKey

unsigned int mace::ScopedFingerprint::ThreadSpecific::getVtid() {
  ThreadSpecific* t = (ThreadSpecific*)init();
  return t->vtid;
} // getVtid

void mace::ScopedFingerprint::ThreadSpecific::clearFingerprint() {
  this->fingerprint = "";
} // clearFingerprint

void mace::ScopedFingerprint::ThreadSpecific::addFingerprint(const string& s) {
  this->fingerprint += s;
} // addFingerprint()

mace::string & mace::ScopedFingerprint::ThreadSpecific::getFingerprint() {
  string &res = this->fingerprint;
  return res;
} // getFingerprint()

