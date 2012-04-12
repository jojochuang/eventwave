#include "SysUtil.h"
#include "lib/mace.h"

#include "TcpTransport-init.h"
#include "CondorHeartBeat-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>
#include "mlist.h"

#include "RandomUtil.h"

//global variables
uint32_t jobpid = 0;
bool isIgnoreSnapshot = false;
mace::string snapshotname;
HeartBeatServiceClass  *heartbeatApp=NULL;
MaceKey me;
static bool isClosed = false;

void printHelp(){
    std::cout<<"'exit' to shutdown job manager."<<std::endl;
    std::cout<<"'start _spec_ _input_' to start service."<<std::endl;
    std::cout<<"'show job' to view status of running services"<<std::endl;
    std::cout<<"'show node' to view status of nodes"<<std::endl;
    std::cout<<"'kill all' to terminate all nodes"<<std::endl;
    std::cout<<"'kill _number_' to terminate some nodes"<<std::endl;
    std::cout<<"'migrate node _number_' to migrate nodes. (injected failure)"<<std::endl;
    std::cout<<"'migrate context _contextid_' to migrate nodes. (injected failure)"<<std::endl;
    std::cout<<"'help' to show help menu."<<std::endl;
/*
    std::cout<<"Enter 1 to shutdown job manager."<<std::endl;
    std::cout<<"Enter 2 to start service."<<std::endl;
    std::cout<<"Enter 3 to view status of running services"<<std::endl;
    std::cout<<"Enter 4 to view status of nodes"<<std::endl;
    std::cout<<"Enter 5 to terminate all nodes"<<std::endl;
    std::cout<<"Enter 6 to terminate some nodes"<<std::endl;
    std::cout<<"Enter 7 to migrate nodes. (injected failure)"<<std::endl;
    std::cout<<"Enter anything else to cancel."<<std::endl;
    */
}
int32_t executeCommon(istream& iss, int32_t cmdNo = -1){
    char cmdbuf[256];
    iss>>cmdbuf;
    if( iss.bad() || iss.fail() ){
        std::cerr<<"Can't read command at line "<<cmdNo<<"."<<std::endl;
        return 0;
    }
    if( strcmp( cmdbuf, "sleep") == 0 ){
        int period;
        iss>>period;
        if( iss.fail() ){
            std::cerr<<"failed to read sleep time. (not a number?)"<<std::endl;
        }else if( period >= 0 ){
            sleep( period );
        }else{
            std::cerr<<"sleep time less than zero"<<std::endl;
        }
    }else if( strcmp(cmdbuf, "show") == 0 ){
        iss>>cmdbuf;
        if( iss.fail() ){
            std::cerr<<"can't read properly after 'show' at line "<<cmdNo<<"."<<std::endl;
        }else if( strcmp( cmdbuf, "job") == 0 )
            heartbeatApp->showJobStatus();
        else if( strcmp( cmdbuf,"node") == 0 )
            heartbeatApp->showNodeStatus();
        else{
            std::cerr<<"Unexpected command parameter at line "<<cmdNo<<"."<<std::endl;
        }
    }else if( strcmp( cmdbuf, "migrate") == 0 ){
        iss>>cmdbuf;
        if( strcmp( cmdbuf, "node" ) == 0 ){
            int32_t migrateCount;
            iss>>migrateCount;
            if( iss.fail() ){
                std::cerr<<"failed to read number of migrated nodes. (not a number?)"<<std::endl;
            }else if( migrateCount > 0 ){
                heartbeatApp->terminateRemote(migrateCount, 1);
            }else{
                std::cerr<<"sleep time less than zero"<<std::endl;
            }
        }else if( strcmp( cmdbuf, "context" ) == 0 ){
            iss>>cmdbuf;
            if( iss.fail() ){
                std::cerr<<"failed to read context name"<<std::endl;
            }else{
                heartbeatApp->migrateContext(std::string(cmdbuf) );
            }
        }else{ // unexpect command
            std::cerr<<"Unexpected command parameter at line "<<cmdNo<<"."<<std::endl;
        }
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
        iss.getline( cmdbuf, sizeof(cmdbuf) );
        std::cout<< cmdbuf << std::endl;
    }else if( strcmp( cmdbuf,"exit") == 0 ){
        isClosed = true;
        return -1;
    }else if( strcmp( cmdbuf,"?") == 0 || strcmp( cmdbuf,"help") == 0 ){
        printHelp();
    }else if( strncmp( cmdbuf, "#", 1 ) == 0 ){
        return 0;
    }else{
        std::cerr<<"Unrecognized command: '"<< cmdbuf<<"' at line "<<cmdNo<<"."<<std::endl;
    }
    return 0;
}
void executeScript( ){
    
    mace::string script = params::get<mace::string>("script");
    std::fstream fp( script.c_str(), std::fstream::in );
    if( fp.is_open() ){
        std::cout<<"executing script file '"<< script<< "'"<<std::endl;
    }else{
        std::cerr<<"Failed to open script file '"<< script <<"'. Ignore it."<<std::endl;
        fp.close();
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
    uint32_t cmdNo=0;
    for( mace::list<mace::string >::iterator cmdIt=command.begin(); cmdIt != command.end(); cmdNo++,cmdIt ++){
        istringstream iss( *cmdIt );
        if( executeCommon( iss, cmdNo ) < 0 ){
            break;
        }
    }
}
void execCommand(){
    printHelp();
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
}

void *schedulerShell(void *threadid){
    std::cout<<"For help, type 'help' or '?'"<<std::endl;
    while(true){
        std::cout<<">>> ";
        if( executeCommon( std::cin ) < 0 ){
            break;
        }
    }
    pthread_exit(NULL);
    return NULL;
}
#include <pthread.h>
void createShell(){
// TODO: chuangw
//  create a new thread. In the new thread, wait for input
    pthread_t shellThread;
    /*int rc = */pthread_create( &shellThread, NULL, schedulerShell, (void *)NULL );
    void *status;
    pthread_join(shellThread, &status);
}
/*void spawnJobHandler(int signum){
 * this function was used for testing job creation. But this is not needed anymore - use script instead.
    std::cout<<"received SIGUSR1!"<<std::endl;
    // first argument is specification file name (default: job.spec)
    // second argument is job input file name (default: job.input)
    heartbeatApp->startService(std::string(""), std::string("") );
}*/
// SIGUSR1 handler (worker node)
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
    // XXX assuming snapshot size < 2 GB = 2^31 bytes
    int fileLen = snapshotFile.tellg();
    snapshotFile.seekg( 0, std::ios::beg);

    char* buf = new char[ fileLen ];
    snapshotFile.read(buf, fileLen);

    snapshotFile.close();
    chdir( current_dir );
    free(current_dir);
    mace::string snapshot( buf, fileLen );
    //std::cout<<"heartbeat process read in "<< snapshot.size() <<" bytes. original snapshot file length="<<fileLen<<std::endl;
    std::cout<<"Ready to transmit snapshot to master!"<<std::endl;
    
    heartbeatApp->reportMigration(snapshot);

    delete buf;

    isClosed = true;
}

void shutdownHandler(int signum){
    switch( signum ){
        case SIGABRT: std::cout<<"SIGABRT"<<std::endl;break;
        case SIGHUP: std::cout<<"SIGHUP"<<std::endl;break;
        case SIGTERM: std::cout<<"SIGTERM"<<std::endl;break;
        case SIGINT: std::cout<<"SIGINT"<<std::endl;break;
        case SIGCONT: std::cout<<"SIGCONT"<<std::endl;break;
        case SIGSEGV: std::cout<<"SIGSEGV"<<std::endl;break;
        case SIGCHLD: std::cout<<"SIGCHLD"<<std::endl;break;
        case SIGQUIT: std::cout<<"SIGQUIT"<<std::endl;break;
    }
    // only send message to master if I'm worker
    if( params::get<int>("isworker",false) == true ){
        heartbeatApp->notifySignal(signum);
    }
    if( signum == SIGINT ){ // ctrl+c pressed
        // if I'm master, show help menu and get choice
        if( params::get<int>("isworker",false) == false ){
            //execCommand();
            isClosed = true;
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
        }else{
            isClosed = true;
        }
    }
    if( signum == SIGHUP ){
        isClosed = false;   // ignore SIGHUP. this was the bug from Condor
    }
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

  params::loadparams(argc, argv);

  FILE* fp_out, *fp_err;
  // chuangw: This is for condor nodes only. Need to copy the directory structure including unit_app executable to remote machine
  if( params::containsKey("nodetype") ){
    if( params::get<mace::string>("nodetype") == "condor" ){
        system("tar xvf everything.tar");
        //system("ls -al * */*");
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
        //sprintf(logdir, "%s/hb", (params::get<mace::string>("logdir") ).c_str());
        if( mkdir( logdir, 0755 ) != 0 ){
            fprintf(stderr, "log directory %s can't be created!\n", logdir);
            exit( EXIT_FAILURE);
        }
    }else if( !S_ISDIR(logst.st_mode) ){
        fprintf(stderr, "log directory %s exists but is not directory!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/hb/%d", (params::get<mace::string>("logdir") ).c_str(), getpid());
    if( stat( logdir, &logst ) != 0 ){ // not exist, create it.
        if( mkdir( logdir, 0755 ) != 0 ){
            fprintf(stderr, "log directory %s can't be created!\n", logdir);
            exit( EXIT_FAILURE);
        }
    }
    sprintf(logfile, "%s/hb/%d/out-%d.log", (params::get<mace::string>("logdir") ).c_str(), getpid(), getpid());
    close(1); //stdout
    fp_out = fopen(logfile, "a+");
    if( fp_out == NULL ){
        fprintf(stderr, "can't open log file %s!\n", logfile);
        exit( EXIT_FAILURE);
    }
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stderr, "can't redirect stdout to logfile %s", logfile);
        exit( EXIT_FAILURE);
    }
    close(2); //stderr
    sprintf(logfile, "%s/err-%d.log", logdir, getpid());
    fp_err = fopen(logfile, "a+");
    if( fp_err == NULL ){
        fprintf(stdout, "can't open log file %s!\n", logfile);
        exit( EXIT_FAILURE);
    }
    if( dup( fileno(fp_err) ) < 0 ){
        fprintf(stdout, "can't redirect stderr to logfile %s", logfile);
        exit( EXIT_FAILURE);
    }
  }

  if( params::get<int>("isworker",false) == true ){
    params::set("MACE_PORT", boost::lexical_cast<std::string>(30000 + params::get<uint32_t>("pid",0 )*5)  );
  }else{
    // master use default port number
     if( params::containsKey("JOBSCHEDULER_PORT") ){
         params::set("MACE_PORT", params::get<std::string>("JOBSCHEDULER_PORT") );
     }else{
         params::set("MACE_PORT","5000");
     }

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
  SysUtil::signal(SIGABRT, &shutdownHandler);
  SysUtil::signal(SIGHUP, &shutdownHandler);
  SysUtil::signal(SIGTERM, &shutdownHandler);
  SysUtil::signal(SIGINT, &shutdownHandler);
  SysUtil::signal(SIGSEGV, &shutdownHandler);
  SysUtil::signal(SIGCHLD, &shutdownHandler);
  SysUtil::signal(SIGQUIT, &shutdownHandler);
  //SysUtil::signal(SIGCONT, &shutdownHandler);


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
      }/*else{ // manual
        SysUtil::signal(SIGUSR1, &spawnJobHandler);
      }*/

      if( params::get<bool>("norelaunch", 1 ) ){
        std::cout<<"will not maintain spared process pool actively"<<std::endl;
      }

      createShell();
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
