#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include <string>

#include "SysUtil.h"
#include "lib/mace.h"
#include "mlist.h"
#include "RandomUtil.h"
#include "mace-macros.h"
#include <ScopedLock.h>

#include "TcpTransport-init.h"
#include "CondorHeartBeat-init.h"
#include "load_protocols.h"
//global variables
static bool isClosed = false;


typedef mace::map<MaceAddr, mace::set<mace::string> > ContextMapping;
class ContextJobNode: public JobManagerDataHandler{
public:
    ContextJobNode() { }

    virtual void installSignalHandlers(){ }
    virtual void start(){
        master = MaceKey(ipv4, params::get<std::string>("MACE_AUTO_BOOTSTRAP_PEERS") );
        tcp = &( TcpTransport_namespace::new_TcpTransport_Transport() );
        me = tcp->localAddress();
        heartbeatApp = &(CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(*tcp)) ;
        heartbeatApp->registerUniqueHandler(*this);
        heartbeatApp->maceInit();
        std::cout<<"me="<<me<<",master="<<master<<std::endl;
    }
    virtual void stop(){
        std::cout<<"sleep finished"<<std::endl;
        heartbeatApp->maceExit();
        std::cout<<"maceExit() called"<<std::endl;
        Scheduler::haltScheduler();
        std::cout<<"scheduler halt"<<std::endl;
        delete tcp;
        delete heartbeatApp;
    }
protected:
    MaceKey me;
    MaceKey master;

    static HeartBeatServiceClass  *heartbeatApp;
private:
    TransportServiceClass* tcp;

};
HeartBeatServiceClass* ContextJobNode::heartbeatApp = NULL;

class WorkerJobHandler:public ContextJobNode {
public:
  WorkerJobHandler(){
      std::cout<<"i'm worker"<<std::endl;
      //installSignalHandlers();
      
      params::set("MACE_PORT", boost::lexical_cast<std::string>(30000 + params::get<uint32_t>("pid",0 )*5)  );
  }
  ~WorkerJobHandler(){
      ADD_SELECTORS("WorkerJobHandler::~WorkerJobHandler");
      if( jobpid > 0 ){
          maceout<<"Closing fifo fd"<<Log::endl;
          close(connfd);
          close(sockfd);
          unlink( socketFile );
      }
  }
  virtual void installSignalHandlers(){
      //SysUtil::signal(SIGUSR1, &WorkerJobHandler::snapshotCompleteHandler);
      SysUtil::signal(SIGABRT, &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGHUP,  &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGTERM, &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGINT,  &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGSEGV, &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGCHLD, &WorkerJobHandler::shutdownHandler);
      SysUtil::signal(SIGQUIT, &WorkerJobHandler::shutdownHandler);
      //SysUtil::signal(SIGCONT, &WorkerJobHandler::shutdownHandler);
    // SIGPIPE occurs when the reader of the FIFO/socket is disconnected but this process tries to write to the pipe.
    // the best practice is to ignore the signal so that write() returns an error and handles it locally, instead of installing a global signal handler.
    // http://stackoverflow.com/questions/108183/how-to-prevent-sigpipes-or-handle-them-properly
    SysUtil::signal(SIGPIPE, SIG_IGN);
  }
  void ignoreSnapshot( const bool ignore, registration_uid_t rid){ 
     isIgnoreSnapshot = ignore;
     if( ignore == false ){
         std::cout<<"Don't ignore snapshot. Send to master to resume."<<std::endl;
     }else{
         std::cout<<"ignore snapshot from the child process"<<std::endl;
     }
     // chuangw: XXX: it'd be better to tell unit_app process not to take snapshot at all, 
     // rather than let it take and ignore.
  }
  // this upcall should be received by the head node
  void requestMigrateContext( const mace::string& contextID, const MaceKey& destNode, const bool isRoot, registration_uid_t rid){ 
        ADD_SELECTORS("WorkerJobHandler::requestMigrateContext");
        std::ostringstream oss;
        oss<<"migratecontext "<< contextID << " " << destNode << " " << (uint32_t)isRoot;
        uint32_t cmdLen = oss.str().size();
        maceout<<"before write to ."<< Log::endl;
        write(connfd, &cmdLen, sizeof(cmdLen) );
        write(connfd, oss.str().data(), cmdLen);
        maceout<<"write cmdLen = "<< cmdLen <<" finished. "<< Log::endl;

  }
  void updateVirtualNodes( const mace::map< uint32_t, mace::MaceAddr >& vnodes, registration_uid_t rid){ 
    ADD_SELECTORS("WorkerJobHandler::updateVirtualNodes");
    std::ostringstream oss;
    mace::string buf;
    mace::serialize( buf, &vnodes );
    oss<<"update_vnode ";
    uint32_t cmdLen = oss.str().size();
    uint32_t bufLen = buf.size();
    maceout<<"before write to ."<< Log::endl;
    write(connfd, &cmdLen, sizeof(cmdLen) );
    write(connfd, oss.str().data(), cmdLen);
    write(connfd, &bufLen, sizeof(bufLen) );
    write(connfd, buf.data(), buf.size());
    maceout<<"write cmdLen = "<< cmdLen <<" finished. "<< Log::endl;
  }


    uint32_t spawnProcess(const mace::string& serviceName, const MaceAddr& vhead, const mace::string& monitorName, const ContextMapping& mapping, const mace::string& snapshot, const mace::string& input, const uint32_t myId, const MaceKey& vNode, registration_uid_t rid){
      ADD_SELECTORS("WorkerJobHandler::spawnProcess");
      createDomainSocket();
      if( (jobpid = fork()) == 0 ){
        mace::map<mace::string, mace::string > args;
        args["-service"] = serviceName;
        args["-monitor"] = monitorName;
        args["-pid"] = params::get<mace::string>("pid","0" );
        //args["-killparent"] = mace::string("1");
        args["-socket"] = mace::string( socketFile );
        if( params::containsKey("logdir") ){
            args["-logdir"] = params::get<mace::string>("logdir");
        }
        char **argv;
        int ret;
        mapToString(args, &argv);
        ret = execvp("unit_app/unit_app",argv/* argv, env parameter */ );
        releaseArgList( argv, args.size()*2+2 );
        return 0;
      }else{
        openDomainSocket();
        writeInitialContexts(serviceName, vhead, mapping, vNode);
        writeResumeSnapshot(snapshot);
        writeInput(input);
        writeDone();
        maceout<<"after writing fifo"<<Log::endl;
        return jobpid;
      }
    }
protected:
    static void shutdownHandler(int signum){
        switch( signum ){
            case SIGABRT: std::cout<<"SIGABRT"<<std::endl;break;
            case SIGHUP:  std::cout<<"SIGHUP"<<std::endl;break;
            case SIGTERM: std::cout<<"SIGTERM"<<std::endl;break;
            case SIGINT:  std::cout<<"SIGINT"<<std::endl;break;
            case SIGCONT: std::cout<<"SIGCONT"<<std::endl;break;
            case SIGSEGV: std::cout<<"SIGSEGV"<<std::endl;break;
            case SIGCHLD: std::cout<<"SIGCHLD"<<std::endl;break;
            case SIGQUIT: std::cout<<"SIGQUIT"<<std::endl;break;
        }
        heartbeatApp->notifySignal(signum);

        if( signum == SIGINT ){ // ctrl+c pressed
            isClosed = true;
        }
        if( signum == SIGTERM){
            if( jobpid > 0 ){
                kill( jobpid, SIGTERM );
            }else{
                std::cout<<"Not running jobs currently. Terminate"<<std::endl;
                isClosed = true;
            }
        }
        if( signum == SIGHUP ){
            isClosed = false;   // ignore SIGHUP. this was the bug from Condor
        }
    }
    /*static void snapshotCompleteHandler(int signum){
        std::cout<<"The job finished snapshot!"<<std::endl;
        if( isIgnoreSnapshot ){
            std::cout<<"ignore snapshot"<<std::endl;
            isClosed = true;
            return;
        }
        // TODO: read from snapshot
        char tmpSnapshot[256];

        char current_dir[256];
        if( getcwd(current_dir,sizeof(current_dir)) == NULL ){
            perror("getcwd() failed to return the current directory name");
        }
        chdir("/tmp");
        //sprintf(tmpSnapshot,"%s", snapshotname.c_str() );
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
        mace::string snapshot( buf, fileLen );
        //std::cout<<"heartbeat process read in "<< snapshot.size() <<" bytes. original snapshot file length="<<fileLen<<std::endl;
        std::cout<<"Ready to transmit snapshot to master!"<<std::endl;
        
        heartbeatApp->reportMigration(snapshot);

        delete buf;

        isClosed = true;
    }*/
// chuangw: To diagnose the output & error message on cloud machines, the following redirect stdout/stderr to a dedicated directory for each process.
// This is unnecessary for Condor nodes, because Condor does this automatically.
    void redirectLog( FILE*& fp_out, FILE*&fp_err ){
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
private:
  void createDomainSocket(){
    int len;
    struct sockaddr_un local;

    if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
      perror("socket");
      exit(1);
    }
    local.sun_family = AF_UNIX;
    sprintf(local.sun_path, "/tmp/socket-%d", getpid() );
    strcpy( socketFile, local.sun_path );
    unlink(local.sun_path);
    len = strlen(local.sun_path) + sizeof(local.sun_family);
    if (bind(sockfd, (struct sockaddr *)&local, len) == -1) {
      perror("bind");
      exit(1);
    }
  }
  void openDomainSocket(){
    ADD_SELECTORS("WorkerJobHandler::openDomainSocket");
    struct sockaddr_un remote;
    if (listen(sockfd, 5) == -1) {
      perror("listen");
      exit(1);
    }
    int t = sizeof(remote);
    if ((connfd = accept(sockfd, (struct sockaddr *)&remote,(socklen_t*) &t)) == -1) {
      perror("accept");
      exit(1);
    }
    maceout<<"domain socket is connected"<<Log::endl;
  }
  void writeInput(const mace::string& input){
      ScopedLock slock( fifoWriteLock );
      if( input.empty() ) return;
      ADD_SELECTORS("WorkerJobHandler::writeInput");
      std::ostringstream oss;
      oss<<"input";
        
      mace::string buf;
      mace::serialize( buf, &input );

      uint32_t cmdLen = oss.str().size(); 
      uint32_t bufLen = buf.size();
      write(connfd, &cmdLen, sizeof(cmdLen) );
      write(connfd, oss.str().data(), cmdLen );
      write(connfd, &bufLen, sizeof(bufLen) );
      write(connfd, buf.data(), buf.size());
  }
    void writeInitialContexts( const mace::string& serviceName, const mace::MaceAddr& vhead, const ContextMapping& mapping, const MaceKey& vNode){
      ScopedLock slock( fifoWriteLock );
      ADD_SELECTORS("WorkerJobHandler::writeInitialContexts");
      std::ostringstream oss;
      oss<<"loadcontext";
      maceout<<"Before writing ."<< Log::endl;
        
      mace::string buf;
      mace::serialize( buf, &serviceName );
      mace::serialize( buf, &vhead);
      mace::serialize( buf, &(mapping) );
      mace::serialize( buf, &(vNode) );

      uint32_t cmdLen = oss.str().size(); 
      uint32_t bufLen = buf.size();
      write(connfd, &cmdLen, sizeof(cmdLen) );
      write(connfd, oss.str().data(), cmdLen);
      write(connfd, &bufLen, sizeof(bufLen) );
      write(connfd, buf.data(), buf.size());
      maceout<<"Write  done."<< Log::endl;
    }
    void writeResumeSnapshot(const mace::string& snapshot){
      ScopedLock slock( fifoWriteLock );
      if( snapshot.empty() ) return;
      ADD_SELECTORS("WorkerJobHandler::writeResumeSnapshot");
      std::ostringstream oss;
      oss<<"snapshot";
        
      mace::string buf;
      mace::serialize( buf, &snapshot );

      uint32_t cmdLen = oss.str().size(); 
      uint32_t bufLen = buf.size();
      write(connfd, &cmdLen, sizeof(cmdLen) );
      write(connfd, oss.str().data(), cmdLen );
      write(connfd, &bufLen, sizeof(bufLen) );
      write(connfd, buf.data(), buf.size());
    }
    void writeDone(){
      ScopedLock slock( fifoWriteLock );
      ADD_SELECTORS("WorkerJobHandler::writeDone");
      std::ostringstream oss;
      oss<<"done";

      uint32_t cmdLen = oss.str().size();
      write(connfd, &cmdLen, sizeof(cmdLen) );
      write(connfd, oss.str().data(), cmdLen);
    }
    void releaseArgList( char **argv,int mapsize ){
        for(int argc=0;argc < mapsize; argc++ ){
            delete [] argv[argc];
        }
    }
    void mapToString(mace::map<mace::string, mace::string > &args, char*** _argv){
        ADD_SELECTORS("WorkerJobHandler::mapToSTring");
        char **argv = new char*[ args.size()*2+2 ];
        *_argv =  argv;
        
        int argcount = 0;
        argv[0] = new char[sizeof("unit_app"+1)];
        strcpy( argv[0], "unit_app" );
        argcount++;
        for( mace::map<mace::string, mace::string >::iterator argit = args.begin(); argit != args.end(); argit ++,argcount++ ){
            argv[argcount] = new char[ argit->first.size()+1 ];
            strcpy( argv[argcount], argit->first.c_str() );

            argcount++;
            argv[argcount] = new char[ argit->second.size()+1 ];
            strcpy( argv[argcount], argit->second.c_str() );
        }
        argv[argcount] = NULL;

        maceout<<"argcount="<<argcount<<Log::endl;
        for(int i=0;i< argcount;i++){
            maceout<<"argv["<<i<<"]="<< argv[i] << Log::endl;
        }
    }
protected:
    static uint32_t jobpid;
private:
    int sockfd;
    int connfd;
    char socketFile[108];
    static bool isIgnoreSnapshot;
    //static mace::string snapshotname;
    static pthread_mutex_t fifoWriteLock;
};
uint32_t WorkerJobHandler::jobpid = 0;
bool WorkerJobHandler::isIgnoreSnapshot = false;
//mace::string WorkerJobHandler::snapshotname;
pthread_mutex_t WorkerJobHandler::fifoWriteLock;

class ContextJobScheduler: public ContextJobNode{
public:
    ContextJobScheduler(){
        choosePool();
        setSchedulerPort();
         SysUtil::signal(SIGABRT, &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGHUP,  &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGTERM, &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGINT,  &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGSEGV, &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGCHLD, &ContextJobScheduler::shutdownHandler);
         SysUtil::signal(SIGQUIT, &ContextJobScheduler::shutdownHandler);
         //SysUtil::signal(SIGCONT, &ContextJobScheduler::shutdownHandler);
    }
    void start(){
        ContextJobNode::start();
        if( me != master ){
          // something is wrong! perhaps I'm not on the designated master host
          std::cout<<"I'm supposed to be master, but my MaceKey is not the default master MaceKey!!"<<std::endl;
          isClosed = true;
          return;
        }
        std::cout<<"i'm master"<<std::endl;

        if( params::get<bool>("norelaunch", 0 ) ){
            std::cout<<"will not maintain spared process pool actively"<<std::endl;
        }

        if( params::containsKey("script") ){
            executeScript( );
        }else{
            createShell();
        }
    }
private:
    void setSchedulerPort(){
        std::string masterAddr = params::get<std::string>("MACE_AUTO_BOOTSTRAP_PEERS");
        size_t i =  masterAddr.find(":");
        if( i != std::string::npos ){
            params::set("MACE_PORT", masterAddr.substr( i+ 1 ) );
        }
    }
    void choosePool(){
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
    static void printHelp(){
        std::cout<<"'exit' to shutdown job manager."<<std::endl;
        std::cout<<"'start _spec_ _input_' to start service.(input file name is optional)"<<std::endl;
        std::cout<<"'show job' to view status of running services"<<std::endl;
        std::cout<<"'show node' to view status of nodes"<<std::endl;
        std::cout<<"'kill all' to terminate all nodes"<<std::endl;
        std::cout<<"'kill _number_' to terminate some nodes"<<std::endl;
        std::cout<<"'migrate _jobid_ node _number_' to migrate nodes. (injected failure, obsoleted now)"<<std::endl;
        std::cout<<"'migrate _jobid_ context _contextid_' to migrate nodes."<<std::endl;
        std::cout<<"'migrate _jobid_ rootcontext _contextid_' to migrate nodes."<<std::endl;
        std::cout<<"'log _jobid_ _procid_ ' to examine logs of the unit_app process."<<std::endl;
        std::cout<<"'hblog _jobid_ _procid_ ' to examine logs of the heartbeat process."<<std::endl;
        std::cout<<"'split _jobid_ _nodeid_' to split contexts on node into half."<<std::endl;
        std::cout<<"'help' to show help menu."<<std::endl;
    }
    static int32_t executeCommon(istream& iss, int32_t cmdNo = -1){
        char cmdbuf[256];
        iss>>cmdbuf;
        if( iss.bad() || iss.fail() ){
            if( cmdNo != -1 )
                std::cerr<<"Can't read command at line "<<cmdNo<<"."<<std::endl;
            return -1;
        }
        std::string atLine;
        if( cmdNo != -1 )
            atLine = " at line "+boost::lexical_cast<std::string>(cmdNo)+".";
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
                std::cerr<<"can't read properly after 'show'"<<atLine<<std::endl;
            }else if( strcmp( cmdbuf, "job") == 0 )
                heartbeatApp->showJobStatus();
            else if( strcmp( cmdbuf,"node") == 0 )
                heartbeatApp->showNodeStatus();
            else{
                std::cerr<<"Unexpected command parameter"<<atLine<<std::endl;
            }
        }else if( strcmp( cmdbuf, "migrate") == 0 ){
            uint32_t jobID;
            iss>>jobID;
            if( iss.fail() ){
                    std::cerr<<"failed to read context name"<<std::endl;
            }else{
                iss>>cmdbuf;
                if( strcmp( cmdbuf, "node" ) == 0 ){
                    int32_t migrateCount;
                    iss>>migrateCount;
                    if( iss.fail() ){
                        std::cerr<<"failed to read number of migrated nodes. (not a number?)"<<std::endl;
                    }else if( migrateCount > 0 ){
                        heartbeatApp->terminateRemote(migrateCount, 1);
                    }else{
                        std::cerr<<"invalid number: need to be larger than zero"<<std::endl;
                    }
                }else if( strcmp( cmdbuf, "context" ) == 0 ){
                    iss>>cmdbuf;
                    if( iss.fail() ){
                        std::cerr<<"failed to read context name"<<std::endl;
                    }else{
                        heartbeatApp->migrateContext(jobID, cmdbuf, false );
                    }
                }else if( strcmp( cmdbuf, "rootcontext" ) == 0 ){
                    iss>>cmdbuf;
                    if( iss.fail() ){
                        std::cerr<<"failed to read context name"<<std::endl;
                    }else{
                        heartbeatApp->migrateContext(jobID, cmdbuf, true );
                    }
                }else{ // unexpect command
                    std::cerr<<"Unexpected command parameter"<<atLine<<std::endl;
                }
            }
        }else if( strcmp( cmdbuf, "split") == 0 ){
            uint32_t jobID;
            iss>>jobID;
            iss>>cmdbuf;
            MaceKey nodeKey(ipv4, cmdbuf);
            heartbeatApp->splitNodeContext(jobID, nodeKey.getMaceAddr() );
        }else if( strcmp( cmdbuf, "launch_heartbeat") == 0 ){

        }else if( strcmp( cmdbuf,"start") == 0 ){
            char jobspecfile[256];
            char jobinputfile[256];
            iss>>jobspecfile;
            if( iss.eof() ){
                heartbeatApp->startService( jobspecfile,"" );
            }else{
                iss>>jobinputfile;
                heartbeatApp->startService( jobspecfile,jobinputfile );
            }
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
        }else if( strcmp( cmdbuf,"log") == 0 ){
            if( !params::containsKey("logdir") ){
                std::cout<<"parameter 'logdir' undefined"<<atLine<<std::endl;
                return 0;
            }
            char cmdbuf[256];
            uint32_t jobid;
            uint32_t nodeid;
            mace::string nodeHostName;
            uint32_t node_unixpid;
            uint32_t uniapp_unixpid;

            iss>>jobid;
            if( iss.eof() ){
                std::cout<<"Not enough parameters"<<std::endl;
            }
            
            iss>>nodeid;
            
            if( heartbeatApp->getNodeInfo( jobid, nodeid, nodeHostName, node_unixpid, uniapp_unixpid ) ){
                sprintf(cmdbuf, "ssh %s \"cat %s/ua/%d/*\" |less", nodeHostName.c_str(),params::get<std::string>("logdir").c_str(), uniapp_unixpid );
                system( cmdbuf );
            }

        }else if( strcmp( cmdbuf,"hblog") == 0 ){
            if( !params::containsKey("logdir") ){
                std::cout<<"parameter 'logdir' undefined"<<atLine<<std::endl;
                return 0;
            }
            char cmdbuf[256];
            uint32_t jobid;
            uint32_t nodeid;
            mace::string nodeHostName;
            uint32_t node_unixpid;
            uint32_t uniapp_unixpid;

            iss>>jobid>>nodeid;
            if( heartbeatApp->getNodeInfo( jobid, nodeid, nodeHostName, node_unixpid, uniapp_unixpid ) ){
                sprintf(cmdbuf, "ssh %s \"cat %s/hb/%d/*\" |less", nodeHostName.c_str(),params::get<std::string>("logdir").c_str(), node_unixpid );
                system( cmdbuf );
            }

        }else if( strcmp( cmdbuf,"exit") == 0 ){
            isClosed = true;
            return -1;
        }else if( strcmp( cmdbuf,"?") == 0 || strcmp( cmdbuf,"help") == 0 ){
            printHelp();
        }else if( strncmp( cmdbuf, "#", 1 ) == 0 ){
            return 0;
        }else{
            std::cerr<<"Unrecognized command: '"<< cmdbuf<<"'"<<atLine<<std::endl;
        }
        return 0;
    }
    static void executeScript( ){
        
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

    static void *schedulerShell(void *threadid){
        std::cout<<"For help, type 'help' or '?'"<<std::endl;
        std::cin.exceptions( std::ios::badbit | std::ios::eofbit | std::ios::failbit );
        while(true){
            std::cout<<">>> ";
            std::string cmd;
            try{
                getline(std::cin, cmd);
            }catch( std::ios_base::failure& ex ){
                std::cout<< ex.what() << std::endl;
                break;
            }
            if( cmd.size() == 0 )continue;
            istringstream iss(cmd );
            if( ContextJobScheduler::executeCommon( iss ) < 0 ){
                break;
            }
        }
        isClosed = true;
        pthread_exit(NULL);
        return NULL;
    }
    void createShell(){
        pthread_t shellThread;
        int rc = pthread_create( &shellThread, NULL, ContextJobScheduler::schedulerShell, (void *)NULL );
        if( rc != 0 ){
            errno = rc;
            perror("pthread_create() failed");
            exit(EXIT_FAILURE);
        }
        void *status;
        rc = pthread_join(shellThread, &status);
        if( rc != 0 ){
            errno = rc;
            perror("pthread_join() failed");
            exit(EXIT_FAILURE);
        }
    }

    static void shutdownHandler(int signum){
        if( signum == SIGINT ){ // ctrl+c pressed
            isClosed = true;
        }
        if( signum == SIGTERM){
            isClosed = true;
        }
        if( signum == SIGHUP ){
            isClosed = false;   // ignore SIGHUP. this was the bug from Condor
        }
    }
};
class CondorNode: public WorkerJobHandler{
public:
  CondorNode(){
      system("tar xvf everything.tar");
      //system("ls -al * */*");
  }
  virtual void installSignalHandlers(){
    //SysUtil::signal(SIGUSR1, &WorkerJobHandler::snapshotCompleteHandler);
    SysUtil::signal(SIGABRT, &WorkerJobHandler::shutdownHandler);
    SysUtil::signal(SIGHUP,  &WorkerJobHandler::shutdownHandler);
    SysUtil::signal(SIGTERM, &CondorNode::vacateHandler);
    SysUtil::signal(SIGINT,  &WorkerJobHandler::shutdownHandler);
    SysUtil::signal(SIGSEGV, &WorkerJobHandler::shutdownHandler);
    SysUtil::signal(SIGCHLD, &WorkerJobHandler::shutdownHandler);
    SysUtil::signal(SIGQUIT, &WorkerJobHandler::shutdownHandler);
    //SysUtil::signal(SIGCONT, &WorkerJobHandler::shutdownHandler);
    // SIGPIPE occurs when the reader of the FIFO/socket is disconnected but this process tries to write to the pipe.
    // the best practice is to ignore the signal so that write() returns an error and handles it locally, instead of installing a global signal handler.
    // http://stackoverflow.com/questions/108183/how-to-prevent-sigpipes-or-handle-them-properly
    SysUtil::signal(SIGPIPE, SIG_IGN);
  }
private:
  static void vacateHandler(int signum){
    if( jobpid > 0 ){
      // when receiving SIGTERM, notify the master.
      heartbeatApp->vacate();
    }else{
      std::cout<<"Not running jobs currently. Terminate"<<std::endl;
      isClosed = true;
    }
  }
};
class CloudNode: public WorkerJobHandler{
public: 
    CloudNode():fp_out(NULL),fp_err(NULL){
      if(  params::containsKey("logdir") ){
        redirectLog( fp_out, fp_err );
      }
    }

    ~CloudNode(){
        if(fp_out != NULL)
            fclose(fp_out);
        if(fp_err != NULL)
            fclose(fp_err);
    }
private:
  FILE* fp_out, *fp_err;
};
class AmazonS3Node: public WorkerJobHandler{
public:
    AmazonS3Node(){
        ABORT("Amazon S3 Node is not yet support now");
    }
};


int main(int argc, char* argv[]) {
  ADD_SELECTORS("main");

  mace::Init(argc, argv);
  load_protocols(); // enable service configuration 

  ContextJobNode* node;

  if( params::get<int>("isworker",false) == true ){
    if( params::containsKey("nodetype") ){
      if( params::get<mace::string>("nodetype") == "condor" ){
          node = new CondorNode();
      }else if( params::get<mace::string>("nodetype") == "amazon" ){
          node = new AmazonS3Node();
      }
    }else{ // by default, assuming the service is running on the cloud machines, out test bed.
      node = new CloudNode();
    }
    node->installSignalHandlers();
  }else{
    node = new ContextJobScheduler();
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

  node->start();
/*  SysUtil::sleep(1);
  mace::string serviceName("Tag");
  MaceAddr vhead = MaceKey(ipv4, "cloud01.cs.purdue.edu:5000").getMaceAddr();
  mace::string monitorName("");
  ContextMapping mapping;
  mace::string snapshot("");
  mace::string input("");
  uint32_t myid = 1;
  registration_uid_t rid = 0;
  node->spawnProcess(serviceName, vhead, monitorName, mapping, snapshot, input, myid, rid);
*/
  while( isClosed == false ){
      SysUtil::sleepm(100);
  }

  node->stop();

  delete node;

  return EXIT_SUCCESS;
}
