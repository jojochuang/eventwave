#ifndef CONTEXTJOBAPPLICATION_H
#define CONTEXTJOBAPPLICATION_H

#include <sys/types.h>
#include <sys/stat.h>
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
namespace mace{ 
// chuangw: XXX: what would happen if in the middle of reading/writing file, and a signal occurs??
template<class T> class ContextJobApplication{
public:
  ContextJobApplication(): fp_out(NULL), fp_err(NULL) {
    openFIFO();
    addLog( );
  }
  virtual ~ContextJobApplication(){
    removeRedirectLog();
  }
  virtual void startService(const mace::string& service, const uint64_t runtime){
    //mace::ServiceFactory<NullServiceClass>::print(stdout);
    mace::ServiceFactory<T>::print(stdout);
    globalMacedon = &( mace::ServiceFactory<T>::create(service, true) );

    // after service is created, threads are created, but transport is not initialized.
    if( params::containsKey("resumefrom") ){
      resumeServiceFromFile( dynamic_cast<mace::Serializable*>(globalMacedon), params::get<mace::string>("resumefrom") );
      std::cout<<"resuming from snapshot."<<std::endl;
      globalMacedon->maceResume(); // initialize transport layer
    }else{
      globalMacedon->maceInit();
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
  bool resumeServiceFromFile(mace::Serializable* globalMacedon, mace::string serializeFileName ){
      ADD_SELECTORS("resumeServiceFromFile");
      mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);

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
  }
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
      // use the buf to create mace::string
      mace::string servName;
      mace::MaceAddr vhead;

      typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
      ContextMappingType mapping;
      mace::string orig_data( buf, fileLen );

      std::istringstream in( orig_data );

      // TODO: load virtual node MaceKey
      // mace::MaceKey vnode;
      // mace::deserialize(in, &vnode  );
      mace::deserialize(in, &servName  );
      mace::deserialize(in, &vhead  );
      mace::deserialize(in, &mapping );

      mapping[ vhead ].push_back( mace::ContextMapping::getHeadContext() );

      mace::map< mace::string, ContextMappingType > servContext;
      servContext[ servName ] = mapping;

      //mace::ContextMapping::setVirtualNodeMaceKey( vnode );
      mace::ContextMapping::setInitialMapping( servContext );


      //BaseMaceService* serv = dynamic_cast<BaseMaceService*>(globalMacedon);
      //serv->loadContextMapping( servContext );

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

      typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
      mace::map< mace::string, ContextMappingType > servContext;
      mapping[ headnode ].push_back( mace::ContextMapping::getHeadContext() );

      servContext[ servName ] = mapping;

      mace::ContextMapping::setInitialMapping( servContext );
      //mace::ContextMapping::printAll();
  }
protected:
  static void *fifoComm(void *threadid){
      //char fifoname[256];
      //sprintf(fifoname, "fifo-%d", params::get<uint32_t>("pid",0 ));
      fd = open( params::get<std::string>("fifo").c_str() , O_RDONLY);
      char fifobuf[256];
      do{
          uint32_t cmdLen;
          std::cout<<"before read FIFO"<<std::endl;
          int n = read(fd, &cmdLen, sizeof(cmdLen) );
          std::cout<<"after read cmdLen, before read command"<<std::endl;
          
          n = read(fd, fifobuf, cmdLen );
          std::cout<<"after read command. read len = "<<n<<std::endl;
          if( n == -1 ){
              perror("read");
          }else if( n < (int)cmdLen ){ // reaches end of fifo: writer closes the fifo
              break;
          }
          istringstream iss( fifobuf);
          std::string cmd;
          iss>>cmd;
          if( cmd.compare("migratecontext") == 0 ){
              mace::string contextID;
              uint32_t isRoot;
              mace::string destKeyStr;
              iss>>contextID;
              iss>>destKeyStr;
              MaceKey destNode(destKeyStr);
              iss>>isRoot;
              std::cout<< "contextID="<<contextID<<", destNode="<< destNode <<", isRoot="<<isRoot<<std::endl;
              BaseMaceService* serv = dynamic_cast<BaseMaceService*>(globalMacedon);
              serv->requestContextMigration(contextID, destNode.getMaceAddr() , isRoot);
          }else if( cmd.compare("loadcontext") == 0 ){
              mace::string servName;
              mace::MaceAddr vhead;
              typedef mace::map<MaceAddr, mace::list<mace::string> > ContextMappingType;
              ContextMappingType mapping;

              mace::deserialize(iss, &servName  );
              mace::deserialize(iss, &vhead  );
              mace::deserialize(iss, &mapping );

              mapping[ vhead ].push_back( mace::ContextMapping::getHeadContext() );

              mace::map< mace::string, ContextMappingType > servContext;
              servContext[ servName ] = mapping;

              mace::ContextMapping::setInitialMapping( servContext );
          }else if( cmd.compare("update_vnode") == 0 ){
              typedef mace::map<uint32_t, MaceAddr > VNodeMappingType;
              VNodeMappingType vnodes;

              mace::deserialize(iss, &vnodes );

              for( VNodeMappingType::iterator vnit = vnodes.begin(); vnit != vnodes.end(); vnit++ ){
                  mace::ContextMapping::updateVirtualNodes( vnit->first, vnit->second );
              }
          }else{
              std::cout<<"Unrecognized command '"<<cmd<<"' from heartbeat process"<<std::endl;
          }
      // FIXME: how to stop?
      }while(1);

      close(fd);
      pthread_exit(NULL);
      return NULL;
  }
  void removeRedirectLog(){
    if( params::containsKey("logdir") ){
      if(fp_out != NULL)
          fclose(fp_out);
      if(fp_err != NULL)
          fclose(fp_err);
    }
  }
  void openFIFO(){
    if( params::containsKey("fifo") ){
      pthread_create( &commThread, NULL, fifoComm, (void *)NULL );
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
        kill( getppid() , SIGUSR1);
      }

      maceout << "Exiting at time " << TimeUtil::timeu() << Log::endl;
      
      exit(EXIT_SUCCESS);

      // program will not reach here.
      // All done.
      //
      // chuangw: don't need to gracefully leave. all later events are blocked and we don't want to process them at all.
      // we're being terminate/migrated, why care about system resources being occupied? Not my business.
      globalMacedon->maceExit();
      mace::Shutdown();
      if( params::containsKey("pid") ){
        void *status;
        pthread_cancel( commThread );
        pthread_join(commThread, &status);
        close(fd);
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

      mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);
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
      BaseMaceService* serv = dynamic_cast<BaseMaceService*>(globalMacedon);
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
  FILE* fp_out, *fp_err;
  static T* globalMacedon;
  static bool stopped;
  static int fd;
  static pthread_t commThread;
};
template<class T> bool mace::ContextJobApplication<T>::stopped = false;
template<class T> T* mace::ContextJobApplication<T>::globalMacedon = NULL;
template<class T> pthread_t mace::ContextJobApplication<T>::commThread;
template<class T> int mace::ContextJobApplication<T>::fd;
} // end of mace:: namespace
#endif
