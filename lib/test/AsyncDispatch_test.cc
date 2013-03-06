
#include "mace.h"
#include "AsyncDispatch.h"
#include "pthread.h"
class Handler: public AsyncEventReceiver{
public:
  void func(void *p);
private:
  static pthread_mutex_t lock;
};

int count = 0;
Handler h;
pthread_mutex_t Handler::lock = PTHREAD_MUTEX_INITIALIZER;
#define NEVENT 1
void Handler::func(void *p){
  ScopedLock sl( lock );
  count++;
  int c = count;
  sl.unlock();
  for(int i =0; i< NEVENT;i ++){
    AsyncDispatch::enqueueEvent(this, (AsyncDispatch::asyncfunc)&Handler::func, (void*)( &c )  ) ;
  }
}
int main(){
  AsyncDispatch::init();
  int zero = 0;
  AsyncDispatch::enqueueEvent(&h, (AsyncDispatch::asyncfunc)&Handler::func, (void*)( &zero )  ) ;

  int total_time=10;
  int last_count = 0;
  for(int i=0;i< total_time; i++){
    sleep(1);
    std::cout<< count-last_count << std::endl;
    last_count = count;
  }
  
  AsyncDispatch::haltAndWait();
  //Scheduler::haltScheduler(); //Keep this last!
}
