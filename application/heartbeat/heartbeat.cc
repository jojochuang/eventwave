#include "SysUtil.h"
#include "lib/mace.h"
//#include "HeartBeatServiceClass.h"

#include "TcpTransport-init.h"
#include "CondorHeartBeat-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>

//static bool isHup = false;
#include "RandomUtil.h"

//global variables
uint32_t jobpid = 0;
bool isIgnoreSnapshot = false;
mace::string snapshotname;
HeartBeatServiceClass  *heartbeatApp=NULL;// = CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(tcp);
MaceKey me;
static bool isClosed = false;

void spawnJobHandler(int signum){
    std::cout<<"received SIGUSR1!"<<std::endl;
    // first argument is specification file name (default: job.spec)
    // second argument is job input file name (default: job.input)
    heartbeatApp->startService(std::string(""), std::string("") );
}
void snapshotCompleteHandler(int signum){
    std::cout<<"The job finished snapshot!"<<std::endl;
    if( isIgnoreSnapshot ){
        isClosed = true;
        return;
    }
    // TODO: read from snapshot
    std::fstream snapshotFile( snapshotname.c_str(), std::fstream::in );
    snapshotFile.seekg( 0, std::ios::end);
    int fileLen = snapshotFile.tellg();
    snapshotFile.seekg( 0, std::ios::beg);

    char* buf = new char[ fileLen ];
    //while( ! snapshotFile.eof() ){
        snapshotFile.read(buf, fileLen);
    //}
    snapshotFile.close();
    mace::string snapshot( buf, fileLen );
    std::cout<<"Ready to transmit snapshot to master!"<<std::endl;
    
    heartbeatApp->reportMigration(snapshot);

    delete buf;

    isClosed = true;
}

void shutdownHandler(int signum){
    // only send message to master if I'm worker
    if( params::get<int>("isworker",false) == true ){
        heartbeatApp->notifySignal(signum);
    }
    switch( signum ){
        case SIGABRT: std::cout<<"SIGABRT"<<std::endl;break;
        case SIGHUP: std::cout<<"SIGHUP"<<std::endl;break;
        case SIGTERM: std::cout<<"SIGTERM"<<std::endl;break;
        case SIGINT: std::cout<<"SIGINT"<<std::endl;break;
        case SIGCONT: std::cout<<"SIGCONT"<<std::endl;break;
    }
    if( signum == SIGINT ){ // ctrl+c pressed
        // if I'm master, show help menu and get choice
        if( params::get<int>("isworker",false) == false ){
            std::cout<<"Enter 1 to shutdown job manager."<<std::endl;
            std::cout<<"Enter 2 to start service."<<std::endl;
            std::cout<<"Enter 3 to view status of running services"<<std::endl;
            std::cout<<"Enter 4 to view status of nodes"<<std::endl;
            std::cout<<"Enter 5 to terminate all nodes"<<std::endl;
            std::cout<<"Enter 6 to terminate some nodes"<<std::endl;
            std::cout<<"Enter 7 to migrate nodes. (injected failure)"<<std::endl;
            std::cout<<"Enter anything else to cancel."<<std::endl;
            char choicebuf[256];
            std::cin.getline(choicebuf, 256);
            
            if( choicebuf[0] == '1' ){
                isClosed = true;
            }else if( choicebuf[0] == '2' ){
                char jobspecfile[256];
                char jobinputfile[256];
                std::cout<<"Job spec file name? (default: job.spec)"<<std::endl;
                std::cin.getline(jobspecfile, 256);
                std::cout<<"Input file name? (default: job.input)"<<std::endl;
                std::cin.getline(jobinputfile, 256);
                heartbeatApp->startService( jobspecfile,jobinputfile );
            }else if( choicebuf[0] == '3' ){
                heartbeatApp->showJobStatus();
            }else if( choicebuf[0] == '4' ){
                heartbeatApp->showNodeStatus();
            }else if( choicebuf[0] == '5' ){
                heartbeatApp->terminateRemoteAll();
            }else if( choicebuf[0] == '6' || choicebuf[0] == '7'){
                char nodename[256];
                mace::list< MaceKey > migratedNodes;
                do{
                    std::cout<<"Specify the node to migrate (hostname:port)"<<std::endl;
                    std::cin.getline(nodename, 256);
                    if( nodename[0] != 0 ){
                        MaceKey node(ipv4, nodename);
                        if( node != MaceKey::null )
                            migratedNodes.push_back(  node );
                    }
                }while( nodename[0] != 0 );
                if( choicebuf[0] == 6 ) //terminate w/o migrate
                    heartbeatApp->terminateRemote(migratedNodes,0);
                else // '7' // terminate & migrate
                    heartbeatApp->terminateRemote(migratedNodes, 1);
            }
        }else{
            isClosed = true;
        }
    }
    if( signum == SIGTERM){
        if( params::get<int>("isworker",false) == true ){
            if( jobpid > 0 ){
                // TODO: signal the job process
                kill( jobpid, SIGTERM );
                // don't shutdown just yet. need to send snapshot to master
            }else{
                std::cout<<"Not running jobs currently. Terminate"<<std::endl;
                isClosed = true;
            }
        }
    }
    if( signum == SIGHUP )
        isClosed = false;   // ignore SIGHUP. this was the bug from Condor
        //isClosed = true;
        //isHup = true;

}
class JobHandler: public JobManagerDataHandler {
public:
  void gotJob( const uint32_t jpid, const mace::string& snapshotfile, registration_uid_t rid){ 
     ::jobpid = jpid;
     ::snapshotname = snapshotfile;
     std::cout<<"assigned a job, child pid="<< jpid<<", snapshot to be used: "<<snapshotfile<<std::endl;
  }
  void ignoreSnapshot( const bool ignore, registration_uid_t rid){ 
     ::isIgnoreSnapshot = ignore;
     std::cout<<"ignore snapshot from the child process"<<std::endl;
  }
};
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

     if( params::containsKey("pool") ){
       if( params::get<std::string>("pool") == std::string("cloud") ){
            std::cout<<"use cloud machines to run jobs"<<std::endl;
       }else if(params::get<std::string>("pool") == std::string("condor") ) {
            std::cout<<"use condor machines to run jobs"<<std::endl;
       }
     }else if( params::containsKey("cloud") ){
            std::cout<<"use cloud machines to run jobs"<<std::endl;
     }else if( params::containsKey("condor") ){
            std::cout<<"use condor machines to run jobs"<<std::endl;
     }else{
        while(true){
            std::cout<<"Choose 'cloud' or 'condor' to run job?"<<std::endl;
            char choicebuf[256];
            std::cin.getline(choicebuf, 256);
            
            if( strncmp(choicebuf,"cloud",5)==0 ){
                params::set("pool", "cloud");
                break;
            }else if( strncmp(choicebuf,"condor",6)==0 ){
                params::set("pool", "condor");
                break;
            }else{
            }
        }
     }
  }
  params::print(stdout);

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

  MaceKey me = tcp.localAddress();
  heartbeatApp = &(CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(tcp)) ;
  
  JobHandler jh;
  heartbeatApp->registerUniqueHandler(jh);

  // Call maceInit
  heartbeatApp->maceInit();
  
  heartbeatApp->start();
  std::cout<<"me="<<me<<",master="<<master<<std::endl;

  if (me == master) {
        std::cout<<"i'm master"<<std::endl;
      SysUtil::signal(SIGUSR1, &spawnJobHandler);
  }else{
        std::cout<<"i'm worker"<<std::endl;
      SysUtil::signal(SIGUSR1, &snapshotCompleteHandler);
  }

  while( isClosed == false ){
      SysUtil::sleepm(100);
  }
  std::cout<<"sleep finished"<<std::endl;
  heartbeatApp->maceExit();
  std::cout<<"maceExit() called"<<std::endl;
  Scheduler::haltScheduler();
  std::cout<<"scheduler halt"<<std::endl;
  delete heartbeatApp;

  return 0;
}
