/* 
 * unit_app.cc : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian
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

// #include "lib/mace_constants.h"
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

#include "services/interfaces/NullServiceClass.h"
//#include "services/interfaces/HeartBeatServiceClass.h"

NullServiceClass* globalMacedon;
//HeartBeatServiceClass* globalMacedon;
bool stopped = false;
void loadInitContext( mace::string tempFileName );

void contextUpdateHandler(int signum){
    //loadInitContext( params::get<mace::string>("initcontext")  );
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

#include "Ticket.h"
#include "ContextLock.h"
void snapshotHandler(int signum){
    // TODO: serialize the service class, and store it into a file.
    //mace::AgentLock lock(mace::AgentLock::WRITE_MODE);

    // get new ticket, but don't use it.
    uint64_t myTicketNum = Ticket::newTicket();
    
    std::cout<<"migration/snapshot ticket="<<myTicketNum<<std::endl;
    while( true ){
        // check if all previous events committed every 1 millisecond.
        // chuangw: I know it's not the good way of doing it...but I'll just do it for the sake of simplicity.
        // it doesn't make difference to wait for one more millisecond anyway.
        SysUtil::sleepu(1000); 
        if( mace::ContextLock::lastCommittedTicket == myTicketNum - 1 ){
            break;
        }
    }
    // if the thread reaches here, all previous events have been committed, and all late events are blocked.
    // we can safely take snapshot

    mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);
    //char tempFileName[] = "ssobj_XXXXXX";
    mace::string buf;
    mace::serialize( buf, serv );
    // chuangw: XXX: Do I need to keep all the old snapshot??
    std::cout<<"size of snapshot : "<< buf.size() <<std::endl;

    /*if( mkstemp(tempFileName) == -1 ){
        std::cerr<<"error! mkstemp returns -1, errorno="<<errno<<std::endl;
        return;
    }else{
    }*/
    mace::string snapshotFileName = params::get<mace::string>("snapshot");
    std::cout<<"snapshot file name: "<<snapshotFileName.c_str()<<std::endl;
    // chuangw: FIXME: I saw serialized data, but it does not seem to get into the file!
    std::fstream ofs( snapshotFileName.c_str(), std::fstream::out );

    ofs.write( buf.data(), buf.size() );

    ofs.seekg( 0, std::ios::end);
    int fileLen = ofs.tellg();
    std::cout<<"[unit_app] the snapshot file len = "<< fileLen<< std::endl;
    ofs.close();
}
// chuangw: when the failure recovery library is mature, I would move it to
// lib/
bool resumeServiceFromFile(mace::Serializable* globalMacedon, mace::string serializeFileName ){
    mace::Serializable* serv = dynamic_cast<mace::Serializable*>(globalMacedon);

      std::ifstream ifs( serializeFileName.c_str(), std::ifstream::in );
      //mace::deserialize( ifs, globalMacedon );
      mace::deserialize( ifs, serv );

     // TODO: need to consider layered services later. 

     ifs.close();
     return true;
}
void shutdownHandler(int signum){
    std::cout<<"received SIGTERM or SIGINT! Ready to stop."<<std::endl;
    snapshotHandler(signum);

    if( params::get<bool>("killparent",false) == true ){
      std::cout<<" Tell heartbeat process the snapshot is finished"<< std::endl;
      kill( getppid() , SIGUSR1);
    }

    std::cout << "Exiting at time " << TimeUtil::timeu() << std::endl;
    
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
/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  SysUtil::signal(SIGTERM, &shutdownHandler); 
  SysUtil::signal(SIGQUIT, &shutdownHandler); // CTRL+ slash
  SysUtil::signal(SIGUSR2, &snapshotHandler); // taking snapshot only
  SysUtil::signal(SIGUSR1, &contextUpdateHandler); // update context
  // First load running parameters 
  params::addRequired("service");
  params::addRequired("run_time");

  mace::Init(argc, argv);


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
    loadInitContext( tempFileName );
  }else if( params::containsKey("initprintable") ){
    mace::string tempFileName = params::get<mace::string>("initprintable");
    loadPrintableInitContext( tempFileName );
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
  return 0;
}
