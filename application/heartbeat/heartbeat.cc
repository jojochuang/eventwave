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
#include "HighLevelEvent.h"
#include "HierarchicalContextLock.h"

#include "TcpTransport-init.h"
#include "CondorHeartBeat-init.h"
#include "load_protocols.h"

#include "ContextJobNode.h"
//global variables
static bool isClosed = false;


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
                /*ThreadStructure::newTicket();
                mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
                ThreadStructure::ScopedContextID sc("");
                mace::HighLevelEvent he( mace::HighLevelEvent::DOWNCALLEVENT );
                alock.downgrade( mace::AgentLock::NONE_MODE );
                ThreadStructure::setEvent( he.getEventID() );
                //mace::ContextLock clock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

                mace::string buf;
                //mace::serialize( buf, &msg );
                mace::HierarchicalContextLock h1(he,buf);
                //storeHeadLog(h1, he );
                */
                heartbeatApp->terminateRemoteAll();

                //clock.downgrade( mace::ContextLock::NONE_MODE );
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


int main(int argc, char* argv[]) {
  ADD_SELECTORS("main");

  mace::Init(argc, argv);
  load_protocols(); // enable service configuration 

  ContextJobNode* node;

  /*if( params::get<int>("isworker",false) == true ){
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
  }else{*/
    node = new ContextJobScheduler();
  //}

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
