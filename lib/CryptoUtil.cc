#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

#include "CryptoUtil.h"
#include "Base64.h"
#include "Scheduler.h"
#include "Log.h"
#include "params.h"

pthread_mutex_t CryptoUtil::slock = PTHREAD_MUTEX_INITIALIZER;
EVP_PKEY* CryptoUtil::privateKey = 0;
EVP_PKEY* CryptoUtil::publicKey = 0;

void CryptoUtil::sign(const std::string& buf, std::string& signature) {
  if (Scheduler::simulated()) {
    return;
  }

  loadPrivateKey();

  EVP_MD_CTX* ctx = new EVP_MD_CTX();
  EVP_MD_CTX_init(ctx);
  if (EVP_SignInit(ctx, EVP_sha1()) == 0) {
    Log::sslerror("EVP_SignInit");
    ABORT("EVP_SignInit");
  }
  if (EVP_SignUpdate(ctx, buf.c_str(), buf.size()) == 0) {
    Log::sslerror("EVP_SignUpdate");
    ABORT("EVP_SignUpdate");
  }
  unsigned char* sigbuf = new unsigned char[EVP_PKEY_size(privateKey)];
  unsigned int size;
  if (EVP_SignFinal(ctx, sigbuf, &size, privateKey) == 0) {
    Log::sslerror("EVP_SignFinal");
    ABORT("EVP_SignFinal");
  }

  signature.clear();
  signature.append((const char*)sigbuf, size);

  EVP_MD_CTX_cleanup(ctx);
  delete ctx;
  delete[] sigbuf;
} // sign

bool CryptoUtil::verify(const std::string& buf, const std::string& sig,
			EVP_PKEY* pubkey) {
  if (Scheduler::simulated()) {
    return true;
  }
  EVP_MD_CTX* ctx = new EVP_MD_CTX();
  EVP_MD_CTX_init(ctx);
  if (EVP_VerifyInit(ctx, EVP_sha1()) == 0) {
    Log::sslerror("EVP_VerifyInit");
    ABORT("EVP_VerifyInit");
  }
  if (EVP_VerifyUpdate(ctx, buf.c_str(), buf.size()) == 0) {
    Log::sslerror("EVP_VerifyUpdate");
    ABORT("EVP_VerifyUpdate");
  }
  int r = EVP_VerifyFinal(ctx, (unsigned char*)sig.c_str(), sig.size(), pubkey);
  if (r < 0) {
    Log::sslerror("EVP_SignFinal");
    ABORT("EVP_SignFinal");
  }

  EVP_MD_CTX_cleanup(ctx);
  delete ctx;

  return r;
} // verify

std::string CryptoUtil::getPublicKey() {
  loadPublicKey();
  std::string s;
  printKey(publicKey, s);
  return s;
} // getPublicKey

void CryptoUtil::printKey(EVP_PKEY* k, std::string& s) {
  uint32_t size = 8192;
  unsigned char* tmp = new unsigned char[size];
  unsigned char* copy = tmp;
  int r = i2d_RSAPublicKey(EVP_PKEY_get1_RSA(k), &copy);
  if (r <= 0) {
    Log::sslerror("i2d_RSAPublicKey");
    ABORT("i2d_RSAPublicKey");
  }
  s.append((char*)tmp, r);

  delete[] tmp;
  s = Base64::encode(s);
} // printKey

void CryptoUtil::loadPrivateKey() {
  ScopedLock sl(slock);
  if (privateKey == 0) {
    if (!params::containsKey(params::MACE_PRIVATE_KEY_FILE)) {
      Log::err() << "parameter MACE_PRIVATE_KEY_FILE not set" << Log::endl;
      exit(-1);
    }
    std::string keyFile = params::get<std::string>(params::MACE_PRIVATE_KEY_FILE);
    FILE* fp = ::fopen(keyFile.c_str(), "r");
    if (fp == NULL) {
      Log::perror("open " + keyFile);
      exit(-1);
    }
    privateKey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    if (privateKey == NULL) {
      Log::sslerror("PEM_read_PrivateKey " + keyFile);
      exit(-1);
    }
  }
} // loadPrivateKey

void CryptoUtil::loadPublicKey() {
  ScopedLock sl(slock);
  if (publicKey == 0) {
    if (!params::containsKey(params::MACE_CERT_FILE)) {
      Log::err() << "parameter MACE_CERT_FILE not set" << Log::endl;
      exit(-1);
    }
    std::string keyFile = params::get<std::string>(params::MACE_CERT_FILE);
    FILE* fp = ::fopen(keyFile.c_str(), "r");
    if (fp == NULL) {
      Log::perror("open " + keyFile);
      exit(-1);
    }
    X509* x509 = PEM_read_X509(fp, 0, 0, 0);
    publicKey = X509_get_pubkey(x509);
    // XXX does this invalidate publicKey?
//     X509_free(x509);
    fclose(fp);
    if (publicKey == NULL) {
      Log::sslerror("X509_get_pubkey " + keyFile);
      exit(-1);
    }
  }
} // loadPublicKey
