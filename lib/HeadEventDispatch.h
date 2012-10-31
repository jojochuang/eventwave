#ifndef __HEAD_EVENT_DISPATCH_h
#define __HEAD_EVENT_DISPATCH_h

//class AsyncEventReceiver;
//#include "ScopedContextRPC.h"
#include "mace.h"
#include "mace-macros.h"
class AsyncEventReceiver;
namespace HeadEventDispatch {

  //typedef void (HeadEventReceiver::*asyncfunc)(void*);
  typedef void (AsyncEventReceiver::*eventfunc)(void*);

  //void enqueueEvent(AsyncEventReceiver* sv, asyncfunc func, void* p);
  void executeEvent(AsyncEventReceiver* sv, eventfunc func, void* p);

  void init();
  void haltAndWait();

  extern uint32_t maxUncommittedEvents;
}

#endif
