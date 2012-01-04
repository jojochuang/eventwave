#include "SysUtil.h"
#include "lib/mace.h"
//#include "HeartBeatServiceClass.h"

#include "TcpTransport-init.h"
#include "/scratch/chuangw/mace-incontext/build/services/CondorHeartBeat/CondorHeartBeat-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>

MaceKey me;
static bool isClosed = false;
//static bool isHup = false;
#include "RandomUtil.h"
HeartBeatServiceClass  *heartbeatApp=NULL;// = CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(tcp);
void spawnJobHandler(int signum){
    std::cout<<"received SIGUSR2!"<<std::endl;
    heartbeatApp->startService(std::string(""));
}
void shutdownHandler(int signum){
    heartbeatApp->notifySignal(signum);
    //std::cout<<"in shutdownHandler"<<std::endl;
    if( signum == SIGTERM || signum == SIGINT ) 
        isClosed = true;
    if( signum == SIGHUP )
        isClosed = false;   // ignore SIGHUP
        //isClosed = true;
        //isHup = true;

    switch( signum ){
        case SIGABRT: std::cout<<"SIGABRT"<<std::endl;break;
        case SIGHUP: std::cout<<"SIGHUP"<<std::endl;break;
        case SIGTERM: std::cout<<"SIGTERM"<<std::endl;break;
        case SIGINT: std::cout<<"SIGINT"<<std::endl;break;
        case SIGCONT: std::cout<<"SIGCONT"<<std::endl;break;
    }
}
int main(int argc, char* argv[]) {
  load_protocols(); // enable service configuration 
  ADD_SELECTORS("main");
  SysUtil::signal(SIGABRT, &shutdownHandler);
  SysUtil::signal(SIGHUP, &shutdownHandler);
  //SysUtil::signal(SIGHUP, SIG_IGN);
  SysUtil::signal(SIGTERM, &shutdownHandler);
  SysUtil::signal(SIGINT, &shutdownHandler);
  SysUtil::signal(SIGCONT, &shutdownHandler);


  params::loadparams(argc, argv);
  if( params::get<int>("isworker",false) == true ){
    params::set("MACE_PORT", boost::lexical_cast<std::string>(30000 + params::get<uint32_t>("pid",0 )*5)  );
  }else{
    // master use default port number
     params::set("MACE_PORT","5000");
  }

  if( params::get<bool>("TRACE_ALL",false) == true )
      Log::autoAdd(".*");
  else if( params::containsKey("TRACE_SUBST") ){
        std::istringstream in( params::get<std::string>("TRACE_SUBST") );
        while(in){
            std::string logPattern;
            in >> logPattern;
            if( logPattern.length() == 0 ) break;

            Log::autoAdd(logPattern);
        }
  }

  MaceKey master = MaceKey(ipv4, params::get<std::string>("MACE_AUTO_BOOTSTRAP_PEERS") );
  
  TransportServiceClass& tcp =
    TcpTransport_namespace::new_TcpTransport_Transport();
  //OverlayServiceClass& benchmark =
  //  HPL_namespace::new_HPL_Overlay(bootstrap, tcp);

  MaceKey me = tcp.localAddress();

  // Register receive handler
  //HPLReceiveHandler h;
  //gossip.registerUniqueHandler(h);
  
  //MicroBenchmark_namespace::func();

  //MPIApplicationServiceClass& benchmarkApp = MicroBenchmark_namespace::new_MicroBenchmark_MPIApplication();
  heartbeatApp = &(CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(tcp)) ;
  // Call maceInit
  heartbeatApp->maceInit();
  
  heartbeatApp->start();
  std::cout<<"me="<<me<<",master="<<master<<std::endl;

  if (me == master) {
        std::cout<<"i'm master"<<std::endl;
      SysUtil::signal(SIGUSR1, &spawnJobHandler);
  }else{
        std::cout<<"i'm worker"<<std::endl;
  }

    //int timeAfterHup = 0;
  while( isClosed == false ){
      SysUtil::sleepm(1000);
      /*if( isHup ){
        std::cout<<"time after hup: "<< timeAfterHup << std::endl;
        timeAfterHup ++;
      }*/
      //isClosed = true;
  }
  std::cout<<"sleep finished"<<std::endl;
  heartbeatApp->maceExit();
  std::cout<<"maceExit() called"<<std::endl;
  Scheduler::haltScheduler();
  std::cout<<"scheduler halt"<<std::endl;
  //gossip.subscribeGossip(0);

  /*benchmark.joinBenchmark( master );
  if (me == bootstrap) {
    //benchmark.queryLatencyTest();
  }else{
    std::string bootstrapper_node = params::get<std::string>("MACE_AUTO_BOOTSTRAP_PEERS");
    MaceKey master(ipv4, bootstrapper_node);
    // Just listen
    //std::cout << "Listening for gossips.." << std::endl;
    SysUtil::sleep(0);
    return 0;
  }*/
  //std::cout<<"Initiates Micro benchmark"<<std::endl;

  //benchmark.

  /*std::string msg = "hello-world-";
  int msgId = 0;
  while (1) {
    std::cout << "Enter 'y' to publish, 'n' to quit" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice == 'n')
      break;
    if (choice == 'y') {
      std::ostringstream ss;
      ss << msg << msgId++;
      std::cout << "Publishing : (" << ss.str() << ")" << std::endl;
      // Publish
      gossip.publishGossip(0, ss.str());
    }
  }*/
  delete heartbeatApp;

  return 0;
}
