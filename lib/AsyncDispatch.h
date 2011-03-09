#ifndef __ASYNC_DISPATCH_h
#define __ASYNC_DISPATCH_h

class AsyncEventReceiver;

namespace AsyncDispatch {

  typedef void (AsyncEventReceiver::*asyncfunc)(void*);

  void enqueueEvent(AsyncEventReceiver* sv, asyncfunc func, void* p);

  void init();
  void haltAndWait();

}

#endif
