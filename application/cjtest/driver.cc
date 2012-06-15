
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void socketServer(){

}
int main(int argc, char* argv[]){


  
  int app_pid;
  if( ( app_pid = fork() ) == 0 ){ 
    char* sockname = new char[64];
    char sock_param[] = "-socket";
    sprintf(sockname, "/tmp/cjtest%d.sock", getpid() );
    char *app_argv[] = {sock_param, sockname, NULL };
    int ret;
    ret = execvp("cjtest",app_argv );
    delete sockname;
  }else{
    socketServer();
  }
}
