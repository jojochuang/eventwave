#include "DHT-init.h"
// #include "Pastry-init.h"
// #include "TcpTransport-init.h"

#include "StringDHT.h"

using mace::string;
using mace::pair;
using std::cout;
using std::endl;

StringDHT::StringDHT() {
//   tcp = &TcpTransport_namespace::new_TcpTransport_Transport();
//   tcp->maceInit();
//   overlay = &Pastry_namespace::new_Pastry_OverlayRouter(*tcp, *tcp);
//   overlay->maceInit();
//   dht = &DHT_namespace::new_DHT_DHT(*overlay);
  dhtsv = &DHT_namespace::new_DHT_DHT();
  dhtsv->maceInit();
  DHTDataHandler* h = new DHTDataHandler();
  dht = new SynchronousDHT(*dhtsv, *h);
} // StringDHT

StringDHT::~StringDHT() {
  shutdown();
  delete dhtsv;
} // ~StringDHT

void StringDHT::shutdown() {
  dhtsv->maceExit();
}

bool StringDHT::containsKey(const string& k) {
//   cout << "calling containsKey" << endl;
  boost::shared_ptr<SynchronousDHT::SyncContainsKeyResult> p = dht->syncContainsKey(MaceKey(sha160, k));
  bool r = p->result;
//   cout << "containsKey returned " << r << endl;
  return r;
} // containsKey

pair<string, bool> StringDHT::get(const string& k) {
  boost::shared_ptr<SynchronousDHT::SyncGetResult> p = dht->syncGet(MaceKey(sha160, k));
  return pair<string, bool>(p->value, p->found);
} // get

int StringDHT::put(const string& k, const string& v) {
  dht->put(MaceKey(sha160, k), v);
  return 0;
} // put

int StringDHT::remove(const string& k) {
  dht->remove(MaceKey(sha160, k));
  return 0;
} // remove

