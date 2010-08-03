#ifndef STRING_DHT_H
#define STRING_DHT_H

#include "mpair.h"
#include "DHTServiceClass.h"
// #include "TransportServiceClass.h"
// #include "OverlayRouterServiceClass.h"

class StringDHT {
public:
  StringDHT();
  virtual ~StringDHT();
  void shutdown();
  virtual bool containsKey(const mace::string& k);
  virtual mace::pair<mace::string, bool> get(const mace::string& k);
  virtual int put(const mace::string& k, const mace::string& v);
  virtual int remove(const mace::string& k);

private:
//   TransportServiceClass* tcp;
//   OverlayRouterServiceClass* overlay;
  DHTServiceClass* dhtsv;
//   DHTServiceManager* dhtsm;
  SynchronousDHT* dht;
}; // StringDHT

#endif // STRING_DHT_H
