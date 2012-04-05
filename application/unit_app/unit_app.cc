/* 
 * unit_app.cc : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2012, Wei-Chiu Chuang, Charles Killian
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of the contributors, nor their associated universities 
 *      or organizations may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

#include "lib/Log.h"
#include "lib/mace.h"
#include "lib/SysUtil.h"
#include "lib/TimeUtil.h"
#include "lib/params.h"
#include "lib/mlist.h"
#include "lib/ContextMapping.h"
#include "lib/ServiceFactory.h"
#include "lib/Serializable.h"

#include <iostream>
#include <fstream>

#include "load_protocols.h"

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "ThreadStructure.h"
#include "ContextLock.h"
#include "mace-macros.h"

#include "services/interfaces/NullServiceClass.h"

NullServiceClass* globalMacedon;
bool stopped = false;

namespace mace{ 
void loadInitContext( mace::string tempFileName );

/**
 * XXX: chuangw: Handling signals in multi-thread process in Linux can be different from other Unix systems.
 * The following code assumes the main thread receives the signal. If child threads receives the signal, it can
 * be much more complicated.....
 * */

void childTerminateHandler(int signum){
    // received SIGCHLD
    ADD_SELECTORS("childTerminateHandler");
    pid_t pid;
    int status;
    while( (pid=waitpid(-1,&status, WNOHANG) ) > 0 );
}
void contextUpdateHandler(int signum){
    ADD_SELECTORS("contextUpdateHandler");
    // put temp file into a memory buffer, and then deserialize 
    // the context mapping from the memory buffer.
    char *buf;
    int fileLen = 0;
    std::cout<<"[unitapp]in contextUpdateHandler()"<<std::endl;
    mace::string tempFileName = params::get<mace::string>("initcontext");
    std::cout<<"[unitapp]reading from update contextfile "<< params::get<mace::string>("initcontext")<<std::endl;
    std::fstream tempFile( tempFileName.c_str(), std::fstream::in );
    tempFile.seekg( 0, std::ios::end);
    fileLen = tempFile.tellg();
    tempFile.seekg( 0, std::ios::beg);

    buf = new char[ fileLen ];
    tempFile.read(buf, fileLen);
    tempFile.close();
    std::cout<<"[unitapp]finished reading "<< params::get<mace::string>("initcontext")<<std::endl;
    // use the buf to create mace::string
    mace::MaceKey oldNode;

    mace::map<MaceKey, mace::list<mace::string> > mapping;
    mace::string orig_data( buf, fileLen );

    std::istringstream in( orig_data );

    mace::deserialize(in, &oldNode );
    mace::deserialize(in, &mapping );

    //assuming head does not move
    BaseMaceService* serv = dynamic_cast<BaseMaceService*>(globalMacedon);
    for( mace::map<MaceKey, mace::list<mace::string> >::iterator mit = mapping.begin(); mit != mapping.end(); mit++){
        std::cout<<"Updating the context mapping for node: "<< mit->first <<std::endl;
        mace::ContextMapping::updateMapping(mit->first, mit->second );

        // chuangw: need to update the internal state of the service
        //   need to know both old and new process address.
        serv->updateInternalContext( oldNode , mit->first );
    }

    delete buf;
}

void snapshotHandler(int signum){
    ADD_SELECTORS("snapshotHandler");
    // get new ticket, but don't use it. Effectively block all later events
    uint64_t myTicketNum = ThreadStructure::newTicket(true);
    // chuangw: TODO: Ticket::newTicket() does not block.
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
    // if the thread reaches here, all previous events have been committed, and all late events are blocked.
    // we can safely take snapshot

    mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);
    if( serv == NULL ){ // failed to dynamically cast to Serializable. abort
        std::cerr<<"Failed to dynamically cast to Serializable. Abort"<<std::endl;
        maceerr<<"Failed to dynamically cast to Serializable. Abort"<<Log::endl;
        //exit(EXIT_FAILURE);
        abort();
    }
    mace::string buf;
    mace::serialize( buf, serv );
    // chuangw: XXX: Do I need to keep all the old snapshot??
    std::cout<<"size of snapshot : "<< buf.size() <<std::endl;
    maceout<<"size of snapshot : "<< buf.size() <<Log::endl;

    char *current_dir = get_current_dir_name();
    if( chdir("/tmp") == -1 ){
        char errormsg[256];
        sprintf(errormsg, "main():%s:%d: can't chdir to /tmp", __FILE__, __LINE__ );
        perror(errormsg);
        //exit(EXIT_FAILURE);
        abort();
    }
    mace::string snapshotFileName = params::get<mace::string>("snapshot");
    std::cout<<"snapshot file name: "<<snapshotFileName.c_str()<<std::endl;
    maceout<<"snapshot file name: "<<snapshotFileName.c_str()<<Log::endl;
    // chuangw: FIXME: I saw serialized data, but it does not seem to get into the file!
    std::fstream ofs( snapshotFileName.c_str(), std::fstream::out );

    ofs.write( buf.data(), buf.size() );

    ofs.seekg( 0, std::ios::end);
    int fileLen = ofs.tellg();
    maceout<<"[unit_app] the snapshot file len = "<< fileLen<< Log::endl;
    ofs.close();
        chdir( current_dir );
        free(current_dir);
}
// chuangw: when the failure recovery library is mature, I would move it to
// lib/
bool resumeServiceFromFile(mace::Serializable* globalMacedon, mace::string serializeFileName ){
    ADD_SELECTORS("resumeServiceFromFile");
    mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);

    char resumeFileName[256];
        char *current_dir = get_current_dir_name();
        chdir("/tmp");
    sprintf(resumeFileName, "%s", serializeFileName.c_str() );
      //std::ifstream ifs( serializeFileName.c_str(), std::ifstream::in );
      std::ifstream ifs( resumeFileName, std::ifstream::in );
      //mace::deserialize( ifs, globalMacedon );
      mace::deserialize( ifs, serv );

     // TODO: need to consider layered services later. 

     ifs.close();
        chdir( current_dir );
        free(current_dir);
     return true;
}
void shutdownHandler(int signum){
    ADD_SELECTORS("shutdownHandler");
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

    stopped = true;
  
}
// chuangw: XXX: what would happen if in the middle of reading/writing file, and a signal occurs??
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
    mace::MaceKey vhead;

    mace::map<MaceKey, mace::list<mace::string> > mapping;
    mace::string orig_data( buf, fileLen );

    std::istringstream in( orig_data );

    mace::deserialize(in, &vhead  );
    mace::deserialize(in, &mapping );

    mace::ContextMapping::init(vhead, mapping );

    delete buf;
}
void loadPrintableInitContext( mace::string& tempFileName ){
    // put temp file into a memory buffer, and then deserialize 
    // the context mapping from the memory buffer.
    char buf[1024];
    mace::map<MaceKey, mace::list<mace::string> > mapping;
    MaceKey headnode;
    std::fstream tempFile( tempFileName.c_str(), std::fstream::in );
    while( ! tempFile.eof() ){
        tempFile.getline(buf, 1024);
        if( tempFile.eof() ) break;

        char *tok = strtok( buf, " ");
        if( strncmp( tok, "head:", 5 ) == 0 ){
            char* node = strtok(NULL, " ");
            headnode = MaceKey(ipv4, node );
        }else{
            MaceKey mknode = MaceKey(ipv4, tok );
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

        }
    }
    tempFile.close();

    mace::ContextMapping::init(headnode, mapping );

}
}
#include <sys/stat.h>
#include <sys/types.h>

/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  SysUtil::signal(SIGTERM, &mace::shutdownHandler); 
  SysUtil::signal(SIGQUIT, &mace::shutdownHandler); // CTRL+ slash
  SysUtil::signal(SIGUSR2, &mace::snapshotHandler); // taking snapshot only
  SysUtil::signal(SIGUSR1, &mace::contextUpdateHandler); // update context
  SysUtil::signal(SIGCHLD, &mace::childTerminateHandler);
  // First load running parameters 
  params::addRequired("service");
  params::addRequired("run_time");

  mace::Init(argc, argv);

  FILE* fp_out, *fp_err;
  if( params::containsKey("logdir") ){
    char logfile[1024];
    char logdir[1024];
    sprintf(logdir, "%s", (params::get<mace::string>("logdir") ).c_str());
    struct stat logst;
    if( stat( logdir, &logst ) != 0){
        fprintf(stderr, "log directory %s doesn't exist!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/ua", (params::get<mace::string>("logdir") ).c_str());
    if( stat( logdir, &logst ) != 0 ){ // not exist, create it.
        sprintf(logdir, "%s/ua", (params::get<mace::string>("logdir") ).c_str());
        if( mkdir( logdir, 0755 ) != 0 ){
            fprintf(stderr, "log directory %s can't be created!\n", logdir);
            exit( EXIT_FAILURE);
        }
    }else if( !S_ISDIR(logst.st_mode) ){
        fprintf(stderr, "log directory %s exists but is not directory!\n", logdir);
        exit( EXIT_FAILURE);
    }
    sprintf(logdir, "%s/ua/%d", (params::get<mace::string>("logdir") ).c_str(), getpid());
    if( mkdir( logdir, 0755 ) != 0 ){
        //fprintf(stderr, "log directory %s can't be created!\n", logdir);
        //exit( EXIT_FAILURE);
    }
    sprintf(logfile, "%s/ua-out-%d.log", logdir, getpid());
    close(1); //stdout
    fp_out = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stderr, "can't redirect stdout to logfile %s", logfile);
    }
    close(2); //stderr
    sprintf(logfile, "%s/ua-err-%d.log", logdir, getpid());
    fp_err = fopen(logfile, "a+");
    if( dup( fileno(fp_out) ) < 0 ){
        fprintf(stdout, "can't redirect stdout to logfile %s", logfile);
    }
  }

  // if -pid is set, set MACE_PORT based on -pid value.
  if( params::containsKey("pid") ){
    params::set("MACE_PORT", boost::lexical_cast<std::string>(20000 + params::get<uint32_t>("pid",0 )*5)  );
  }
  //   Log::autoAddAll();
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

  if( params::containsKey("initcontext") ){
    // open temp file.
    mace::string tempFileName = params::get<mace::string>("initcontext");
    mace::loadInitContext( tempFileName );
  }else if( params::containsKey("initprintable") ){
    mace::string tempFileName = params::get<mace::string>("initprintable");
    mace::loadPrintableInitContext( tempFileName );
  }else{
  }

  load_protocols();

  mace::string service = params::get<mace::string>("service");
  uint64_t runtime = (uint64_t)(params::get<double>("run_time") * 1000 * 1000);

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  mace::ServiceFactory<NullServiceClass>::print(stdout);
 // mace::ServiceFactory<HeartBeatServiceClass>::print(stdout);
  globalMacedon = &( mace::ServiceFactory<NullServiceClass>::create(service, true) );
  //globalMacedon = &( mace::ServiceFactory<HeartBeatServiceClass>::create(service, true) );

  // after service is created, threads are created, but transport is not initialized.
  if( params::containsKey("resumefrom") ){
      resumeServiceFromFile( dynamic_cast<mace::Serializable*>(globalMacedon), params::get<mace::string>("resumefrom") );
      std::cout<<"resuming from snapshot."<<std::endl;
      globalMacedon->maceResume(); // initialize transport layer
      // FIXME: need to update the internal packet buffer mapping
      // this is done when deserializing from the snapshot
  }else{
      globalMacedon->maceInit();
  }

  if( service == "FileSync" ){
      ASSERTMSG(params::containsKey("SYNC_NODES"), "Must list the nodes to sync with as SYNC_NODES");
      ASSERTMSG(params::containsKey("SYNC_DIR"), "Must list the directory to sync with as SYNC_DIR");
  }

  if( runtime == 0 ){
    // runtime == 0 means indefinitely.
    while ( !stopped ){
        SysUtil::sleepu(100);
    }
  }else{
      SysUtil::sleepu(runtime);
  }
  if( params::containsKey("logdir") ){
    if(fp_out != NULL)
        fclose(fp_out);
    if(fp_err != NULL)
    fclose(fp_err);
  }
  return 0;
}
