#include <stdint.h>
#include "SysUtil.h"
#include <signal.h>
#include "Scheduler.h"
#include "XmlRpcServer.h"
#include "XmlRpcUrlHandler.h"
#include "StringDHT.h"
#include "StringDHTXmlRpcHandler.h"

using namespace std;

XmlRpcServer* server;
StringDHT* dht;
bool halt = false;

void shutdownHandler(int sig) {
  halt = true;
} // shutdownHandler

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage: %s config\n", argv[0]);
    exit(1);
  }

  params::addRequired("listen", "port to listen for connections");
  params::addRequired("MACE_AUTO_BOOTSTRAP_PEERS", "overlay host(s) to join");
  params::loadparams(argc, argv);

  int port = params::get<int>("listen");

  Log::configure();
  //Log::autoAddAll();
  Log::autoAdd("DHT");

  try {
    server = new XmlRpcServer("/xmlrpc", port);

    SysUtil::signal(SIGINT, &shutdownHandler);
    SysUtil::signal(SIGTERM, &shutdownHandler);

    dht = new StringDHT();
    server->registerHandler("StringDHT", new StringDHTXmlRpcHandler<StringDHT>(dht));

    server->run();
    while (!halt) {
      SysUtil::sleepm(100);
    }
  } catch (const Exception& e) {
    cerr << e << endl;
    assert(0);
  }
  
  server->shutdown();
  dht->shutdown();
  Scheduler::haltScheduler();

  return 0;
} // main
