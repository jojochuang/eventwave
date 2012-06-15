
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void socketServer();
int main(int argc, char* argv[]){


  
  int app_pid;
  if( ( app_pid = fork() ) == 0 ){ 
    char sockname[64];
    char sock_param[] = "-socket";
    sprintf(sockname, "/tmp/cjtest%d.sock", getpid() );
    char testcase_param[] = "--run_test=scheduled";
    char *app_argv[] = {sock_param, sockname, testcase_param, NULL };
    int ret;
    ret = execvp("cjtest",app_argv );
  }else{
    openDomainSocket();
  }
}
void openDomainSocket(){
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
