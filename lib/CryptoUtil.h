#ifndef _CRYPTO_UTIL_H
#define _CRYPTO_UTIL_H

#include <string>
#include <openssl/evp.h>

#include "ScopedLock.h"

class CryptoUtil {
public:
  static void sign(const std::string& buf, std::string& signature);
  static bool verify(const std::string& buf, const std::string& signature,
		     EVP_PKEY* pubkey);
  static void printKey(EVP_PKEY* k, std::string& s);
  static std::string getPublicKey();

private:
  static void loadPrivateKey();
  static void loadPublicKey();

  static pthread_mutex_t slock;
  static EVP_PKEY* privateKey;
  static EVP_PKEY* publicKey;
}; // CryptoUtil

#endif // _CRYPTO_UTIL_H
