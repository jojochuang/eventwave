#include "SysUtil.h"
#include "lib/mace.h"
//#include "HeartBeatServiceClass.h"

#include "TcpTransport-init.h"
#include "CondorHeartBeat-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>
#include "mlist.h"

//static bool isHup = false;
#include "RandomUtil.h"

//global variables
uint32_t jobpid = 0;
bool isIgnoreSnapshot = false;
mace::string snapshotname;
HeartBeatServiceClass  *heartbeatApp=NULL;// = CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(tcp);
MaceKey me;
static bool isClosed = false;

void executeScript( ){
    
    mace::string script = params::get<mace::string>("script");
    std::fstream fp( script.c_str(), std::fstream::in );
    if( fp.is_open() ){
        std::cout<<"executing script file '"<< script<< "'"<<std::endl;
    }else{
        return;
    }
    char buf[256];
    mace::list< mace::string > command;
    while( fp.good() ){
        fp.getline( buf, 256 );
        command.push_back( mace::string(buf) );
    }
    fp.close();
    // execute each line
    for( mace::list<mace::string >::iterator cmdIt=command.begin(); cmdIt != command.end(); cmdIt ++){
        istringstream iss( *cmdIt );
        char cmdbuf[256];
        iss>>cmdbuf;
        if( strcmp( cmdbuf, "sleep") == 0 ){
            int period;
            iss>>period;
            sleep( period );
        }else if( strcmp(cmdbuf, "show") == 0 ){
            iss>>cmdbuf;
            if( strcmp( cmdbuf, "job") == 0 )
                heartbeatApp->showJobStatus();
            else if( strcmp( cmdbuf,"node") == 0 )
                heartbeatApp->showNodeStatus();
        }else if( strcmp( cmdbuf, "migrate") == 0 ){
            uint32_t migrateCount;
            iss>>migrateCount;
            heartbeatApp->terminateRemote(migrateCount, 1);
        }else if( strcmp( cmdbuf, "launch_heartbeat") == 0 ){

        }else if( strcmp( cmdbuf,"start") == 0 ){
            char jobspecfile[256];
            char jobinputfile[256];
            iss>>jobspecfile;
            iss>>jobinputfile;
            heartbeatApp->startService( jobspecfile,jobinputfile );
        }else if( strcmp( cmdbuf, "kill") == 0 ){
            iss>>cmdbuf;
            if( strcmp( cmdbuf,"all") == 0 ){
                heartbeatApp->terminateRemoteAll();
            }else{
                uint32_t migrateCount;
                iss>>migrateCount;
                heartbeatApp->terminateRemote(migrateCount, 0);
            }
        }else if( strcmp( cmdbuf,"print") == 0 ){
            std::cout<< iss.str() << std::endl;

        }else if( strcmp( cmdbuf,"exit") == 0 ){
            isClosed = true;
            break;
        }else{
            if( cmdbuf[0] == '#' )
                continue;
            std::cerr<<"Unrecognized command: "<< cmdbuf<<std::endl;
        }
    }
}

void spawnJobHandler(int signum){
    std::cout<<"received SIGUSR1!"<<std::endl;
    // first argument is specification file name (default: job.spec)
    // second argument is job input file name (default: job.input)
    heartbeatApp->startService(std::string(""), std::string("") );
}
void snapshotCompleteHandler(int signum){
    std::cout<<"The job finished snapshot!"<<std::endl;
    if( isIgnoreSnapshot ){
        std::cout<<"ignore snapshot"<<std::endl;
        isClosed = true;
        return;
    }
    // TODO: read from snapshot
    char tmpSnapshot[256];

        char *current_dir = get_current_dir_name();
        chdir("/tmp");
    sprintf(tmpSnapshot,"%s", snapshotname.c_str() );
    //std::fstream snapshotFile( snapshotname.c_str(), std::fstream::in );
    std::fstream snapshotFile( tmpSnapshot, std::fstream::in );
    if( snapshotFile.is_open() ){
        std::cout<<"file opened successfully for reading"<<std::endl;
    }else{
        std::cout<<"file failed to open for reading"<<std::endl;
    }
    snapshotFile.seekg( 0, std::ios::end);
    int fileLen = snapshotFile.tellg();
    snapshotFile.seekg( 0, std::ios::beg);

    char* buf = new char[ fileLen ];
    //while( ! snapshotFile.eof() ){
        snapshotFile.read(buf, fileLen);

    //}
    snapshotFile.close();
        chdir( current_dir );
        free(current_dir);
    mace::string snapshot( buf, fileLen );
        std::cout<<"heartbeat process read in "<< snapshot.size() <<" bytes. original snapshot file length="<<fileLen<<std::endl;
    std::cout<<"Ready to transmit snapshot to master!"<<std::endl;
    //return;
    
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
     if( ignore == false ){
         std::cout<<"Don't ignore snapshot. Send to master to resume."<<std::endl;
     }else{
         std::cout<<"ignore snapshot from the child process"<<std::endl;
     }
     // chuangw: XXX: it'd be better to tell unit_app process not to take snapshot at all, 
     // rather than let it take and ignore.
  }
};
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
  load_protocols(); // enable service configuration 
  ADD_SELECTORS("main");
  //SysUtil::signal(SIGABRT, &shutdownHandler);
  SysUtil::signal(SIGHUP, &shutdownHandler);
  //kysUtil::signal(SIGHUP, SIG_IGN);
  SysUtil::signal(SIGTERM, &shutdownHandler);
  SysUtil::signal(SIGINT, &shutdownHandler);
  //SysUtil::signal(SIGCONT, &shutdownHandler);


  params::loadparams(argc, argv);

  FILE* fp_out, *fp_err;
  // chuangw: This is for condor nodes only. Need to copy the directory structure including unit_app executable to remote machine
  if( params::containsKey("nodetype") ){
    if( params::get<mace::string>("nodetype") == "condor" ){
        system("tar xvf everything.tar");
        system("ls -al * */*");
    }
  }

  // chuangw: To diagnose the output & error message on cloud machines, the following redirect stdout/stderr to a dedicated directory for each process.
  // This is unnecessary for Condor nodes, because Condor does this automatically.
  if( params::containsKey("logdir") ){
    char logfile[1024];
    char logdir[1024];
    sprintf(logdir, "%s", (params::get<mace::string>("logdir") ).c_str());
    struct stat logst;
    if( stat( logdir, &logst ) != 0){
        fprintf(stderr, "log directory %s doesn't exist!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/hb", (params::get<mace::string>("logdir") ).c_str());
    if( stat( logdir, &logst ) != 0 ){ // not exist, create it.
        sprintf(logdir, "%s/hb", (params::get<mace::string>("logdir") ).c_str());
        if( mkdir( logdir, 0755 ) != 0 ){
            fprintf(stderr, "log directory %s can't be created!\n", logdir);
            exit( EXIT_FAILURE);
        }
    }else if( !S_ISDIR(logst.st_mode) ){
        fprintf(stderr, "log directory %s exists but is not directory!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/hb/%d", (params::get<mace::string>("logdir") ).c_str(), getpid());
    if( mkdir( logdir, 0755 ) != 0 ){
        //fprintf(stderr, "log directory %s can't be created!\n", logdir);
        //exit( EXIT_FAILURE);
    }
    sprintf(logfile, "%s/hb-out-%d.log", logdir, getpid());
    close(1); //stdout
    fp_out = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stderr, "can't redirect stdout to logfile %s", logfile);
    }
    close(2); //stderr
    sprintf(logfile, "%s/hb-err-%d.log", logdir, getpid());
    fp_err = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stdout, "can't redirect stdout to logfile %s", logfile);
    }
  }

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
      if( params::containsKey("script") ){
        executeScript( );
      }else{ // manual
        SysUtil::signal(SIGUSR1, &spawnJobHandler);
      }
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

  if( params::containsKey("logdir") ){
    if(fp_out != NULL)
        fclose(fp_out);
    if(fp_err != NULL)
    fclose(fp_err);
  }

  return 0;
}
