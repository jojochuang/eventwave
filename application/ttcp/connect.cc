#include "params.h"
#include "TcpTransport.h"
#include "TcpTransport-init.h"
#include "SysUtil.h"
#include "TimeUtil.h"

using namespace std;

BufferedTransportServiceClass* transport;

class TransportCallback : public ReceiveDataHandler, public NetworkErrorHandler {
public:
  void error(const MaceKey& id, TransportError::type code, const string& message,
	     registration_uid_t rid) {
    cout << "received error " << message << endl;
  }

  void deliver(const MaceKey& source, const MaceKey& destination,
	       const std::string& s, registration_uid_t rid) {
    cout << "read " << s.size() << endl;
  }
  
}; // TransportCallback

TransportCallback tcb;

int main(int argc, char** argv) {
//   params::set("MACE_LOCAL_ADDRESS", macelocal);
  params::set("MACE_BIND_LOCAL_ADDRESS", "1");
  params::set("MACE_ADDRESS_ALLOW_LOOPBACK", "1");
  params::set("MACE_WARN_LOOPBACK", "0");

  Log::autoAddAll();
  Log::setLevel(1);
  params::loadparams(argc, argv);

  transport = &TcpTransport_namespace::new_TcpTransport_BufferedTransport();
  transport->maceInit();
  transport->registerUniqueHandler((ReceiveDataHandler&)tcb);
  transport->registerUniqueHandler((NetworkErrorHandler&)tcb);

  int port = 10000;
  int count = 1026;
//   int count = 1;
  for (int i = port; i < port + count; i++) {
    MaceKey dest(ipv4, "127.0.0.1:" + StrUtil::toString(i));
    cout << "sending to " << dest << endl;
    transport->send(dest, string());
  }

  SysUtil::sleep();

  return 0;
}
