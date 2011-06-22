#ifndef SIMULATOR_TRANSPORT_CRYPTO_H
#define SIMULATOR_TRANSPORT_CRYPTO_H

#include "TransportCryptoServiceClass.h"
#include "params.h"

namespace SimulatorTransportCrypto_namespace {

  class SimulatorTransportCryptoService : public virtual TransportCryptoServiceClass, public virtual BaseMaceService {
  public:
    void maceInit() { }
    void maceExit() { }
    mace::string getX509CommonName(const MaceKey& peer, registration_uid_t rid) const {
      return params::get("SIM_TRANSPORT_CRYPTO_COMMON_NAME", cn);
    }
    EVP_PKEY* getPublicKey(const MaceKey& peer, registration_uid_t rid) const {
      return (EVP_PKEY*)&key;
    }

  private:
    mace::string cn;
    EVP_PKEY key;
  };

}

#endif // SIMULATOR_TRANSPORT_CRYPTO_H
