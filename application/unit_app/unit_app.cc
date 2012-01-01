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
#include "lib/ServiceFactory.h"

#include "load_protocols.h"

#include "services/interfaces/NullServiceClass.h"

void loadInitContext( mace::string& tempFileName ){
    fstream tempFile( tempFileName.c_str(), fstream::in );

    // put temp file into a memory buffer, and then deserialize 
    // the context mapping from the memory buffer.
    char buf[1024*10];
    int fileLen = 0;
    while( ! tempFile.eof() ){
        fileLen = tempFile.read(buf, 1024*10);
    }

    // use the buf to create mace::string

    mace::map<MaceKey, mace::list<mace::string> > mapping;
    mace::string orig_data( buf, fileLen );

    std::istringstream in( orig_data );
    mace::deserialize(in, &mapping );

    ContextMapping::init( mapping );

    tempFile.close();
}
/**
 * Uses the "service" variable and the ServiceFactory to instantiate a
 * NullServiceClass registered with the name service.  Runs for "run_time"
 * seconds.
 */
int main (int argc, char **argv)
{
  // First load running parameters 
  params::addRequired("service");
  params::addRequired("run_time");

  mace::Init(argc, argv);

  //   Log::autoAddAll();
  params::print(stdout);

  if( params::containsKey<mace::string>("initcontext") ){
    // open temp file.
    mace::string tempFileName = params::get<mace::string>("initcontext");
    loadInitContext( tempFileName );
  }

  load_protocols();

  mace::string service = params::get<mace::string>("service");
  uint64_t runtime = (uint64_t)(params::get<double>("run_time") * 1000 * 1000);

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;

  mace::ServiceFactory<NullServiceClass>::print(stdout);
  NullServiceClass& globalMacedon = mace::ServiceFactory<NullServiceClass>::create(service, true);
  globalMacedon.maceInit();

  ASSERTMSG(params::containsKey("SYNC_NODES"), "Must list the nodes to sync with as SYNC_NODES");
  ASSERTMSG(params::containsKey("SYNC_DIR"), "Must list the directory to sync with as SYNC_DIR");

  SysUtil::sleepu(runtime);
  
  std::cout << "Exiting at time " << TimeUtil::timeu() << std::endl;
  
  // All done.
  globalMacedon.maceExit();

  mace::Shutdown();
  return 0;
}
