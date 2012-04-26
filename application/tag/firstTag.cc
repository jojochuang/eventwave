#include "SysUtil.h"
#include "lib/mace.h"

#include "TcpTransport-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>
#include "mlist.h"

#include "RandomUtil.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include "TagServiceClass.h"
#include "Tag-init.h"
 
using namespace std;
 
/*class TagResponseHandler : public TagDataHandler {
 
};*/ 
 
int main(int argc, char* argv[]) {
  
  params::loadparams(argc, argv);
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

  TagServiceClass& mt = Tag_namespace::new_Tag_Tag();
  mt.maceInit();
  //timeval tim;
  //gettimeofday(&tim, NULL);
  /*double t1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
  for (uint64_t i = 0; i < 4000000000; i++) {
  
  }
  gettimeofday(&tim, NULL);
  double t2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
  printf("%.6lf seconds elapsed\n", t2 - t1);*/
  SysUtil::sleep();
	return 0;
} 
