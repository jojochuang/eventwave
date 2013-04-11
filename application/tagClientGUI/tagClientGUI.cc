#include "SysUtil.h"
#include "lib/mace.h"

#include "TcpTransport-init.h"
#include "load_protocols.h"
#include <signal.h>
#include <string>
#include "mlist.h"

#include "RandomUtil.h"
#include <iostream>
#include <ncurses.h>
#include "TagClientServiceClass.h"
#include "TagClient-init.h"
#include "ContextJobApplication.h"
 
using namespace std;
 
/*class TagResponseHandler : public TagDataHandler {
 
};*/ 

void writeOutProf( int signum ){
  exit(EXIT_SUCCESS);
}

 
int main(int argc, char* argv[]) {
  mace::Init(argc, argv);
  load_protocols();

  if( params::get<bool>("gprof", false ) ){
    SysUtil::signal( SIGINT, writeOutProf ); // intercept ctrl+c and call exit to force gprof output
  }

  mace::string service = "TagClient";
  mace::ContextJobApplication<TagClientServiceClass> app;
  app.installSignalHandler();

  params::print(stdout);

  app.loadContext();

  std::cout << "Starting at time " << TimeUtil::timeu() << std::endl;
  app.startService( service );
  
  initscr();                  /* Start curses mode      */
  printw("Hello World !!!");  /* Print Hello World      */
  refresh();                  /* Print it on to the real screen */
  getch();                    /* Wait for user input */
  endwin();                   /* End curses mode      */

  app.globalExit();
  
  return 0;
} 
