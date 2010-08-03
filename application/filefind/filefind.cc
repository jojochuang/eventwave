// #include <sys/wait.h>
#include <signal.h>

#include "params.h"
#include "Scheduler.h"
#include "Find-init.h"
#include "SysUtil.h"

using namespace mace;
using namespace Find_namespace;
using std::cout;
using std::cerr;
using std::endl;

bool done = false;

void shutdownHandler(int sig) {
  done = true;
} // shutdownHandler

class F : public FileFindHandler {
public:
  void atFile(const std::string& path, const stat_t& sbuf, registration_uid_t rid) {
    cout << "FILE " << path << endl;
  }
  bool atDir(const std::string& path, const stat_t& sbuf, registration_uid_t rid) {
    cout << "DIR  " << path << endl;
    return true;
  }
  void leavingDir(const std::string& path, const StringList& contents, registration_uid_t rid) {
    cout << "---- leaving " << path << ": " << contents << endl;
  }
  void atLink(const std::string& path, const stat_t& sbuf, registration_uid_t rid) {
    cout << "LINK " << path << endl;
  }
  bool statError(const std::string& path, const FileException& e, registration_uid_t rid) {
    cout << "stat error " << path << " " << e << endl;
    return true;
  }
  bool readDirError(const std::string& path, const FileException& e, registration_uid_t rid) {
    cout << "read dir error " << path << " " << e << endl;
    return true;
  }
  void findComplete(const std::string& root, registration_uid_t rid) {
//     cout << "find complete for " << root << endl;
    shutdownHandler(0);
  }
};

int main(int argc, const char** argv) {
  if (argc != 2) {
    cerr << "usage: " << argv[0] << " path" << endl;
    return 0;
  }

//   Log::autoAddAll();

  SysUtil::signal(SIGINT, &shutdownHandler);
  SysUtil::signal(SIGTERM, &shutdownHandler);
  
  FileFindServiceClass* finder = &new_Find_FileFind();
  F fh;
  finder->maceInit();
  finder->registerUniqueHandler(fh);
  finder->beginFind(argv[1]);

  while (!done) {
    SysUtil::sleepm(100);
  }

  finder->maceExit();
  Scheduler::haltScheduler();
  return 0;
}
