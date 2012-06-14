#ifndef CONTEXTJOBAPPLICATION_H
#define CONTEXTJOBAPPLICATION_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include "ServiceFactory.h"
#include "ContextMapping.h"
#include "ThreadStructure.h"
#include "ContextLock.h"
#include "Serializable.h"
#include "SysUtil.h"
#include "mvector.h"
typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
namespace mace{ 
// chuangw: XXX: what would happen if in the middle of reading/writing file, and a signal occurs??
template<class T> class ContextJobApplication{
public:
  ContextJobApplication(): fp_out(NULL), fp_err(NULL), isResuming(false) {
    openUDSocket();
    addLog( );
  }
  virtual ~ContextJobApplication(){
    removeRedirectLog();
  }
  virtual void startService(const mace::string& service, const uint64_t runtime){
    if( udsockInitConfigDone ){
      installSystemMonitor( );
    }
    mace::ServiceFactory<T>::print(stdout);
    maceContextService = &( mace::ServiceFactory<T>::create(service, true) );

    // after service is created, threads are created, but transport is not initialized.
    //if( params::containsKey("resumefrom") ){
    if( isResuming ){
      //resumeServiceFromFile( dynamic_cast<mace::Serializable*>(maceContextService), params::get<mace::string>("resumefrom") );
      std::cout<<"resuming from snapshot."<<std::endl;
      maceContextService->maceResume(); // initialize transport layer
    }else{
      maceContextService->maceInit();
    }
    if( runtime == 0 ){
      // runtime == 0 means indefinitely.
      while ( !stopped ){
          SysUtil::sleepm(100);
      }
    }else{
        SysUtil::sleepu(runtime);
    }
  }
  /*bool resumeServiceFromFile(mace::Serializable* maceContextService, mace::string serializeFileName ){
      ADD_SELECTORS("resumeServiceFromFile");
      mace::Serializable* serv = dynamic_cast<mace::Serializable*>(maceContextService);

      char resumeFileName[256];
      char current_dir[256];
      if( getcwd(current_dir,sizeof(current_dir)) == NULL ){
          perror("getcwd() failed to return the current directory name");
      }
      chdir("/tmp");
      sprintf(resumeFileName, "%s", serializeFileName.c_str() );
      std::ifstream ifs( resumeFileName, std::ifstream::in );
      mace::deserialize( ifs, serv );

      // TODO: need to consider layered services later. 

      ifs.close();
      chdir( current_dir );
      return true;
  }*/
  void loadContext(){
    // before service is created, load contexts
    if( params::containsKey("context") ){
      // open temp file.
      mace::string tempFileName = params::get<mace::string>("context");
      loadInitContext( tempFileName );
    }else if( params::containsKey("initprintable") ){
      mace::string tempFileName = params::get<mace::string>("initprintable");
      loadPrintableInitContext( tempFileName );
    }else{
      // the service will use the default mapping for contexts. (i.e., map all contexts to this physical node)
    }
  }
  virtual void installSignalHandler(){
    SysUtil::signal(SIGTERM, &shutdownHandler); 
    SysUtil::signal(SIGQUIT, &shutdownHandler); // CTRL+ slash
    SysUtil::signal(SIGUSR2, &snapshotHandler); // taking snapshot only
    SysUtil::signal(SIGUSR1, &contextUpdateHandler); // update context
    SysUtil::signal(SIGCHLD, &childTerminateHandler);
  }
  void addLog(){
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
  }
  void redirectLog( const std::string& logdirstr ){
    char logfile[1024];
    char logdir[1024];
    sprintf(logdir, "%s", logdirstr.c_str());
    struct stat logst;
    if( stat( logdir, &logst ) != 0){
        fprintf(stderr, "log directory %s doesn't exist!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/ua", logdirstr.c_str());
    if( stat( logdir, &logst ) != 0 ){ // not exist, create it.
        sprintf(logdir, "%s/ua", logdirstr.c_str());
        if( mkdir( logdir, 0755 ) != 0 ){
            fprintf(stderr, "log directory %s can't be created!\n", logdir);
            exit( EXIT_FAILURE);
        }
    }else if( !S_ISDIR(logst.st_mode) ){
        fprintf(stderr, "log directory %s exists but is not directory!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/ua/%d", logdirstr.c_str(), getpid());
    if( mkdir( logdir, 0755 ) != 0 ){
        //fprintf(stderr, "log directory %s can't be created!\n", logdir);
        //exit( EXIT_FAILURE);
    }
    sprintf(logfile, "%s/out-%d.log", logdir, getpid());
    close(1); //stdout
    fp_out = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stderr, "can't redirect stdout to logfile %s", logfile);
    }
    close(2); //stderr
    sprintf(logfile, "%s/err-%d.log", logdir, getpid());
    fp_err = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stdout, "can't redirect stdout to logfile %s", logfile);
    }
  }
  void loadInitContext( mace::string tempFileName ){
      // put temp file into a memory buffer, and then deserialize 
      // the context mapping from the memory buffer.
      char *buf;
      int fileLen = 0;

      std::fstream tempFile( tempFileName.c_str(), std::fstream::in );
      tempFile.seekg( 0, std::ios::end);
      fileLen = tempFile.tellg();
      tempFile.seekg( 0, std::ios::beg);

      buf = new char[ fileLen ];
      tempFile.read(buf, fileLen);
      tempFile.close();
      mace::string servName;
      mace::MaceAddr vhead;

      ContextMappingType mapping;
      mace::string orig_data( buf, fileLen );

      std::istringstream in( orig_data );

      mace::deserialize(in, &servName  );
      mace::deserialize(in, &vhead  );
      mace::deserialize(in, &mapping );

      mapping[ vhead ].push_back( mace::ContextMapping::getHeadContext() );
      mace::map< mace::string, ContextMappingType > servContext;
      servContext[ servName ] = mapping;

      mace::ContextMapping::setInitialMapping( servContext );
      delete buf;
  }
  void loadPrintableInitContext( mace::string& tempFileName ){
      // put temp file into a memory buffer, and then deserialize 
      // the context mapping from the memory buffer.
      char buf[1024];
      mace::map<MaceAddr, mace::list<mace::string> > mapping;
      MaceAddr headnode;
      std::fstream tempFile( tempFileName.c_str(), std::fstream::in );
      mace::string servName;
      while( ! tempFile.eof() ){
          tempFile.getline(buf, 1024);
          if( tempFile.eof() ) break;

          char *tok = strtok( buf, " ");
          if( strncmp( tok, "service:", 8 ) == 0 ){
              char* svname = strtok(NULL, " ");
              servName= svname ;
          } if( strncmp( tok, "head:", 5 ) == 0 ){
              char* node = strtok(NULL, " ");
              const MaceKey headKey( ipv4, node );
              headnode = headKey.getMaceAddr();
          }else{
              MaceAddr mknode = Util::getMaceAddr( tok );
              mace::list<mace::string> contextlist;
              tok = strtok(NULL," ");
              while( tok != NULL ){
                  mace::string context(tok);
                  if( strcmp( tok, "global" ) == 0 ){ 
                      // special case for global context
                      context = "";
                  }
                  contextlist.push_back( context );
                  tok = strtok(NULL, " ");
              }
              mapping[ mknode] = contextlist;

              std::cout<< mknode<< "is mapped to ";
              for( mace::list<mace::string>::iterator ctxit= contextlist.begin(); ctxit!= contextlist.end(); ctxit++ ){
                  std::cout<< *ctxit << ",";
              }
              std::cout<< std::endl;

          }
      }
      tempFile.close();

      mace::map< mace::string, ContextMappingType > servContext;
      mapping[ headnode ].push_back( mace::ContextMapping::getHeadContext() );

      servContext[ servName ] = mapping;

      mace::ContextMapping::setInitialMapping( servContext );
      //mace::ContextMapping::printAll();
  }
  virtual void installSystemMonitor(){
  // TODO: create a thread that monitors the system perofrmance and periodically report to the scheduler.
      pthread_create( &monitorThread, NULL, systemMonitor, (void *)this );
  }
protected:
  static void *systemMonitor(void* obj){
    ContextJobApplication<T>* thisptr = reinterpret_cast<ContextJobApplication<T> *>(obj);
    thisptr->realSystemMonitor();
    pthread_exit(NULL);
    return NULL;
  }
  static void *UDSocketComm(void* obj){
    ContextJobApplication<T>* thisptr = reinterpret_cast<ContextJobApplication<T> *>(obj);
    thisptr->realUDSocketComm();
    pthread_exit(NULL);
    return NULL;
  }
  void realSystemMonitor(){
    // TODO: CPU utilization? 
    // this monitor is only responsible for sending the system performance information. It does not make decision
    // about migration. That is left to the scheduler.
    while( !stopped ){
      // wait some time
      SysUtil::sleep( 60 );
      // gather system performance

      // write UDSocket to notify scheduler
    }
  }
  void realUDSocketComm(){
    struct sockaddr_un remote;
    int len;
    if ( (sockfd = socket( AF_UNIX, SOCK_STREAM, 0 ) )  == -1 ){
      perror("socket");
      return;
    }
    remote.sun_family = AF_UNIX;
    strcpy( remote.sun_path, params::get<std::string>("socket").c_str() );
    len = strlen(remote.sun_path) + sizeof(remote.sun_family);
    if (connect(sockfd, (struct sockaddr *)&remote, len) == -1) {
      perror("connect");
      exit(1);
    }

    std::cout<<"after open read udsock"<<std::endl;
    readUDSocketInitConfig();
    pthread_mutex_lock(&udsockMutex);
    udsockInitConfigDone = true;
    pthread_cond_signal(&udsockCond );
    pthread_mutex_unlock(&udsockMutex);
    std::cout<<"readUDSocketInitConfig finished"<<std::endl;
    do{
      std::string udsockdata;
      std::string cmd;
      ssize_t n = readUDSocket(cmd, udsockdata);
      if( n <= 0 ){
        std::cout<<"readUDSocket() returned zero(eof). leaving udsock thread"<<std::endl;
        break;
      }
      if( cmd.compare("done") == 0 ){
        std::cout<<"udsockComm]received 'done'. leaving"<<std::endl;
        break;
      }
      istringstream iss( udsockdata );
      if( cmd.compare("migratecontext") == 0 ){
          mace::string contextID;
          uint32_t isRoot;
          mace::string destKeyStr;
          iss>>contextID;
          iss>>destKeyStr;
          MaceKey destNode(destKeyStr);
          iss>>isRoot;
          std::cout<< "[udsockComm]contextID="<<contextID<<", destNode="<< destNode <<", isRoot="<<isRoot<<std::endl;
          BaseMaceService* serv = dynamic_cast<BaseMaceService*>(maceContextService);
          serv->requestContextMigration(contextID, destNode.getMaceAddr() , isRoot);
      }else if( cmd.compare("update_vnode") == 0 ){
          typedef mace::map<uint32_t, MaceAddr > VNodeMappingType;
          VNodeMappingType vnodes;

          mace::deserialize(iss, &vnodes );

          for( VNodeMappingType::iterator vnit = vnodes.begin(); vnit != vnodes.end(); vnit++ ){
              mace::ContextMapping::updateVirtualNodes( vnit->first, vnit->second );
          }
      }else if( cmd.compare("input") == 0 ){
      }else{
          std::cout<<"[udsockComm]Unrecognized command '"<<cmd<<"' from heartbeat process"<<std::endl;
      }
    // FIXME: how to stop?
    }while(1);

    std::cout<<"UDSocket thread exiting..."<<std::endl;

    close(sockfd);
    std::cout<<"udsock sockfd closed in UDSocket thread"<<std::endl;
    return;
  }
  void removeRedirectLog(){
    if( params::containsKey("logdir") ){
      if(fp_out != NULL)
          fclose(fp_out);
      if(fp_err != NULL)
          fclose(fp_err);
    }
  }
  void openUDSocket(){
    if( params::containsKey("socket") ){
      pthread_create( &commThread, NULL, UDSocketComm, (void *)this );
      pthread_mutex_lock(&udsockMutex);
      if( udsockInitConfigDone == false ){ // TODO: use pthread_barrier instead
        pthread_cond_wait(&udsockCond, &udsockMutex  );
      }
      pthread_mutex_unlock(&udsockMutex);
    }
  }
  static void shutdownHandler(int signum){
      ADD_SELECTORS("ContextService::shutdownHandler");
      std::cout<<"received SIGTERM or SIGINT! Ready to stop."<<std::endl;
      maceout<<"received SIGTERM or SIGINT! Ready to stop."<<Log::endl;

      /**
       * Memo on context migration implementation (chuangw)
       *
       * context migration starts by head. Head somehow detects migrating some contexts
       * is better. Head creates a context migration event to this physical node.
       *
       * When all previous write events to the context are finished, start taking snapshot of the context.
       * and block later events.
       *
       * */

      /**
       * Memo on node migration implementation (chuangw)
       *
       * When a SIGTERM is received, send a message to head to create an event.
       * When event is created and returned to this node, 
       * this node, after all previous write events are finished,
       * start taking snapshot. 
       *
       * 
       * */
      snapshotHandler(signum);

      if( params::get<bool>("killparent",false) == true ){
        std::cout<<" Tell heartbeat process the snapshot is finished"<< std::endl;
        maceout<<" Tell heartbeat process the snapshot is finished"<< Log::endl;
        //kill( getppid() , SIGUSR1);
      }

      maceout << "Exiting at time " << TimeUtil::timeu() << Log::endl;
      
      exit(EXIT_SUCCESS);

      // program will not reach here.
      // All done.
      //
      // chuangw: don't need to gracefully leave. all later events are blocked and we don't want to process them at all.
      // we're being terminate/migrated, why care about system resources being occupied? Not my business.
      maceContextService->maceExit();
      mace::Shutdown();
      if( params::containsKey("pid") ){
        void *status;
        pthread_cancel( commThread );
        pthread_join(commThread, &status);

        pthread_cancel( monitorThread );
        pthread_join( monitorThread, &status);

      }

      stopped = true;
    
  }
  static void snapshotHandler(int signum){
      ADD_SELECTORS("snapshotHandler");
      // chuangw: obsoleted code...... need to make a big change here.
      /*
      // get new ticket, but don't use it. Effectively block all later events
      uint64_t myTicketNum = ThreadStructure::newTicket(true);
      // chuangw: TODO: ThreadStructure::newTicket() does not block.
      // but ContextLock::_context_ticketbooth will block, 
      //
      // after blocking, only the return value of the previous sync call event   and migration event can pass through
      // 
      // migration event need to wait for all previous sync call events to return.
      
      std::cout<<"migration/snapshot ticket="<<myTicketNum<<std::endl;
      maceout<<"migration/snapshot ticket="<<myTicketNum<<Log::endl;
      while( true ){
          // check if all previous events committed every 1 millisecond.
          // XXX: chuangw: I know it's not the good way of doing it...but I'll just do it for the sake of simplicity.
          // it doesn't make difference to wait for one more millisecond anyway.
          SysUtil::sleepu(1000); 
          if( mace::ContextLock::lastCommittedTicket == myTicketNum - 1 ){
              break;
          }
      }
      */
      // if the thread reaches here, all previous events have been committed, and all late events are blocked.
      // we can safely take snapshot

      mace::Serializable* serv = dynamic_cast<mace::Serializable*>(maceContextService);
      if( serv == NULL ){ // failed to dynamically cast to Serializable. abort
          std::cerr<<"Failed to dynamically cast to Serializable. Abort"<<std::endl;
          maceerr<<"Failed to dynamically cast to Serializable. Abort"<<Log::endl;
          abort();
      }
      mace::string buf;
      mace::serialize( buf, serv );
      // chuangw: XXX: Do I need to keep all the old snapshot??
      std::cout<<"size of snapshot : "<< buf.size() <<std::endl;
      maceout<<"size of snapshot : "<< buf.size() <<Log::endl;

      char current_dir[256];
      if( getcwd(current_dir,sizeof(current_dir)) == NULL ){
          perror("getcwd() failed to return the current directory name");
      }
      if( chdir("/tmp") == -1 ){
          char errormsg[256];
          sprintf(errormsg, "main():%s:%d: can't chdir to /tmp", __FILE__, __LINE__ );
          perror(errormsg);
          abort();
      }
      mace::string snapshotFileName = params::get<mace::string>("snapshot");
      std::cout<<"snapshot file name: "<<snapshotFileName.c_str()<<std::endl;
      maceout<<"snapshot file name: "<<snapshotFileName.c_str()<<Log::endl;
      std::fstream ofs( snapshotFileName.c_str(), std::fstream::out );

      ofs.write( buf.data(), buf.size() );

      ofs.seekg( 0, std::ios::end);
      int fileLen = ofs.tellg();
      maceout<<"[unit_app] the snapshot file len = "<< fileLen<< Log::endl;
      ofs.close();

      chdir( current_dir );
  }
  static void contextUpdateHandler(int signum){
      ADD_SELECTORS("contextUpdateHandler");
      // put temp file into a memory buffer, and then deserialize 
      // the context mapping from the memory buffer.
      char *buf;
      int fileLen = 0;
      std::cout<<"[unitapp]in contextUpdateHandler()"<<std::endl;
      mace::string tempFileName = params::get<mace::string>("context");
      std::cout<<"[unitapp]reading from update contextfile "<< params::get<mace::string>("context")<<std::endl;
      std::fstream tempFile( tempFileName.c_str(), std::fstream::in );
      tempFile.seekg( 0, std::ios::end);
      fileLen = tempFile.tellg();
      tempFile.seekg( 0, std::ios::beg);

      buf = new char[ fileLen ];
      tempFile.read(buf, fileLen);
      tempFile.close();
      std::cout<<"[unitapp]finished reading "<< params::get<mace::string>("context")<<std::endl;
      mace::MaceAddr oldNode;

      mace::map<MaceAddr, mace::list<mace::string> > mapping;
      mace::string orig_data( buf, fileLen );

      std::istringstream in( orig_data );

      mace::deserialize(in, &oldNode );
      mace::deserialize(in, &mapping );

      //assuming head does not move
      BaseMaceService* serv = dynamic_cast<BaseMaceService*>(maceContextService);
      for( mace::map<MaceAddr, mace::list<mace::string> >::iterator mit = mapping.begin(); mit != mapping.end(); mit++){
          std::cout<<"Updating the context mapping for node: "<< mit->first <<std::endl;
          //mace::ContextMapping::updateMapping(mit->first, mit->second );

          // chuangw: need to update the internal state of the service
          //   need to know both old and new process address.
          serv->updateInternalContext( oldNode , mit->first );
      }

      delete buf;
  }
  /**
   * XXX: chuangw: Handling signals in multi-thread process in Linux can be different from other Unix systems.
   * The following code assumes the main thread receives the signal. If child threads receives the signal, it can
   * be much more complicated.....
   * */

  static void childTerminateHandler(int signum){
      // received SIGCHLD
      ADD_SELECTORS("childTerminateHandler");
      pid_t pid;
      int status;
      while( (pid=waitpid(-1,&status, WNOHANG) ) > 0 );
  }

private:
  ssize_t readUDSocket(std::string& udsockcmd, std::string& udsockstr){
    uint32_t cmdLen;
    std::cout<<"[ContextJobApplication::readUDSocket]before read UDSocket"<<std::endl;
    struct timeval tv;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET( sockfd, &rfds );
    do{
      tv.tv_sec = 10; tv.tv_usec = 0;
      select( sockfd+1, &rfds, NULL, NULL, &tv );

      if( FD_ISSET( sockfd, &rfds ) ){
        std::cout<<"[ContextJobApplication::readUDSocket]select() has data"<<std::endl;
        break;
      }else{
        std::cout<<"[ContextJobApplication::readUDSocket]select() timeout."<<std::endl;
      }
    }while( true );
    ssize_t n = read(sockfd, &cmdLen, sizeof(cmdLen) );
    std::cout<<"[ContextJobApplication::readUDSocket]after read cmdLen, before read command"<<std::endl;
    if( n == -1 ){
      perror("read");
      return n;
    }else if( n < (ssize_t)sizeof(cmdLen) ){ // reaches end of udsock: writer closes the udsock
      std::cerr<<"[ContextJobApplication::readUDSocket]returned string length "<< n <<" is less than expected length "<< sizeof(cmdLen) << std::endl;
      return n;
    }
    
    char *udsockbuf = new char[ cmdLen ];
    n = read(sockfd, udsockbuf, cmdLen );
    std::cout<<"[ContextJobApplication::readUDSocket]after read command. read len = "<<n<<std::endl;
    if( n == -1 ){
      perror("read");
      return n;
    }else if( n < (int)cmdLen ){ // reaches end of udsock: writer closes the udsock
      std::cerr<<"[ContextJobApplication::readUDSocket]returned string length "<< n <<" is less than expected length "<< cmdLen << std::endl;
      return n;
    }
    udsockcmd.assign( udsockbuf, cmdLen );
    delete udsockbuf;

    if( udsockcmd.compare( "done" ) == 0 ){
      return n;
    }

    uint32_t dataLen;
    std::cout<<"[ContextJobApplication::readUDSocket]before read UDSocket"<<std::endl;
    n = read(sockfd, &dataLen, sizeof(dataLen) );
    if( n == -1 ){
      perror("read");
      return n;
    }else if( n < (ssize_t)sizeof(dataLen) ){ // reaches end of udsock: writer closes the udsock
      std::cerr<<"[ContextJobApplication::readUDSocket]returned string length "<< n <<" is less than expected length "<< sizeof(dataLen) << std::endl;
      return n;
    }
    std::cout<<"[ContextJobApplication::readUDSocket]after read dataLen, before read command"<<std::endl;
    udsockbuf = new char[ dataLen ];
    n = read(sockfd, udsockbuf, dataLen );
    std::cout<<"[ContextJobApplication::readUDSocket]after read data. read len = "<<n<<std::endl;
    if( n == -1 ){
      perror("read");
      return n;
    }else if( n < (int)dataLen ){ // reaches end of udsock: writer closes the udsock
      std::cerr<<"[ContextJobApplication::readUDSocket]returned string length "<< n <<" is less than expected length "<< dataLen << std::endl;
      return n;
    }
    udsockstr.assign( udsockbuf, dataLen );
    delete udsockbuf;

    return n;
  }
  void readUDSocketInitConfig(){
    bool isDone = false;
    do{
      std::string cmd, udsockdata;
      readUDSocket(cmd, udsockdata);

      istringstream iss( udsockdata );
      std::cout<<"UDSocket command: "<< cmd<<std::endl;
      if( cmd.compare("loadcontext") == 0 ){
        readUDSocketInitialContexts(iss);
      }else if( cmd.compare("snapshot") == 0 ){
        //readUDSocketResumeSnapshot(iss);
      }else if( cmd.compare("done") == 0 ){
        isDone = true;
      }else if( cmd.compare("input") == 0 ){
        readUDSocketInput( iss );
      }else{
          std::cout<<"[ContextJobApplication::readUDSocketInitConfig]Unrecognized command '"<<cmd<<"' from heartbeat process"<<std::endl;
      }
    }while( !isDone );
  }
  void readUDSocketInitialContexts(std::istringstream& iss){
    std::cout<<"loading initial context mapping"<<std::endl;
    mace::string serviceName;
    mace::MaceAddr vhead;
    ContextMappingType mapping;
    MaceKey vNode;

    mace::deserialize( iss, &serviceName );
    std::cout<<"service name: "<< serviceName<< std::endl;
    mace::deserialize( iss, &vhead);
    std::cout<<"vhead : "<< vhead << std::endl;
    mace::deserialize( iss, &(mapping) );
    std::cout<<"mapping: "<< mapping<< std::endl;
    mace::deserialize(iss, &vNode );
    std::cout<<"vNode: "<< vNode<< std::endl;
    mace::ContextMapping::setVirtualNodeMaceKey( vNode );

    mapping[ vhead ].push_back( mace::ContextMapping::getHeadContext() );

    mace::map< mace::string, ContextMappingType > servContext;
    servContext[ serviceName ] = mapping;

    mace::ContextMapping::setInitialMapping( servContext );
    std::cout<<"Initial context mapping loaded"<< std::endl;
  }
  /* FIXME: this function should be called after the service object is created but before maceResume() is called */
  void readUDSocketResumeSnapshot(std::istringstream& iss){
    mace::Serializable* serv = dynamic_cast<mace::Serializable*>(maceContextService);
    mace::deserialize( iss, serv );
    isResuming = true;
  }
  void readUDSocketInput(std::istringstream& iss){
    mace::string input;
    mace::deserialize( iss, &input );
    params::set("input", input );
  }
  FILE* fp_out, *fp_err;
  bool  isResuming;
  static T* maceContextService;
  static bool stopped;
  static int sockfd;
  static pthread_t commThread;
  static pthread_t monitorThread;
  static pthread_mutex_t udsockMutex;
  static pthread_cond_t udsockCond;
  static bool udsockInitConfigDone;
};
template<class T> bool mace::ContextJobApplication<T>::stopped = false;
template<class T> T* mace::ContextJobApplication<T>::maceContextService = NULL;
template<class T> pthread_t mace::ContextJobApplication<T>::commThread;
template<class T> pthread_t mace::ContextJobApplication<T>::monitorThread;
template<class T> int mace::ContextJobApplication<T>::sockfd;
template<class T> pthread_mutex_t mace::ContextJobApplication<T>::udsockMutex;
template<class T> pthread_cond_t mace::ContextJobApplication<T>::udsockCond;
template<class T> bool mace::ContextJobApplication<T>::udsockInitConfigDone;
} // end of mace:: namespace
#endif
