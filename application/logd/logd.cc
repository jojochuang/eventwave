#include <signal.h>
#include "CircularBuffer.h"
#include "SysUtil.h"
#include "FileUtil.h"
#include "params.h"

using namespace std;

bool halt = false;
int sigcount = 0;

void shutdownHandler(int sig) {
  sigcount++;
  if (sigcount > 2) {
    halt = true;
  }
} // shutdownHandler

int main(int argc, char* argv[]) {
  params::addRequired("logfile", "path for log file");
  params::addRequired("size", "maximum log size in MB");
  params::loadparams(argc, argv);

  SysUtil::signal(SIGINT, &shutdownHandler);
  SysUtil::signal(SIGTERM, &shutdownHandler);
  SysUtil::signal(SIGPIPE, &shutdownHandler);

  uint32_t size = params::get<uint32_t>("size");
  size *= 1024 * 1024;

  CircularBuffer buf(size);

  const uint32_t BUFLEN = 4096;
  char rbuf[BUFLEN];

  int infd = fileno(stdin);

  int r = 0;
  do {
    r = FileUtil::read(infd, rbuf, BUFLEN);
    if (r > 0) {
      buf.write(rbuf, r);
    }
  } while (!halt && r > 0);

  string path = params::get<string>("logfile");
  int fd = FileUtil::create(path, S_IRUSR|S_IWUSR);
  buf.copy(fd);
  FileUtil::close(fd);
}
