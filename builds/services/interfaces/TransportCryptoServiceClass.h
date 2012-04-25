/*********************************************
*  TransportCryptoServiceClass.h
*  Mace generated on:
*  Tue Apr 10 10:09:06 2012
*********************************************/
#ifndef _TRANSPORTCRYPTOSERVICECLASS_H
#define _TRANSPORTCRYPTOSERVICECLASS_H
#include "ServiceClass.h"

#include <openssl/evp.h>
class TransportCryptoServiceClass : public virtual ServiceClass {
  public:
  static TransportCryptoServiceClass& NULL_;
  static const char* name; // = "TransportCrypto";
  
  typedef int type;
  static const type NONE = 0;
  static const type TLS = 1;
  
  #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportCryptoServiceClass.mh"
  virtual mace::string getX509CommonName(
      #line 39 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportCryptoServiceClass.mh"
      const MaceKey& peer
#line 25 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportCryptoServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getX509CommonName in base class TransportCryptoServiceClass called."); }
#line 27 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportCryptoServiceClass.h"
  #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportCryptoServiceClass.mh"
  virtual EVP_PKEY* getPublicKey(
      #line 40 "/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces/TransportCryptoServiceClass.mh"
      const MaceKey& peer
#line 32 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportCryptoServiceClass.h"
      , registration_uid_t rid = -1) const { ABORT("Unimplemented method getPublicKey in base class TransportCryptoServiceClass called."); }
#line 34 "/u/u24/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/TransportCryptoServiceClass.h"
  virtual ~TransportCryptoServiceClass() { }
};

#endif // _TRANSPORTCRYPTOSERVICECLASS_H
