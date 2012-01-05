#ifndef _CONTEXTLOCK_H
#define _CONTEXTLOCK_H

// including headers
#include "GlobalCommit.h"
#include "ContextBaseClass.h"
#include "pthread.h"
#include "Ticket.h"
// uses snapshot by default

namespace mace{

class ContextBaseClass;

class RunOnceCallBack {
public:
    virtual void operator() (void) = 0;
    static pthread_mutex_t onceLock;
};
void runOnce(pthread_once_t& keyOnce, RunOnceCallBack& funcObj){
    if( keyOnce == PTHREAD_ONCE_INIT ){
        ScopedLock sl( RunOnceCallBack::onceLock );
        if( keyOnce == PTHREAD_ONCE_INIT ){
            funcObj();
            keyOnce = !PTHREAD_ONCE_INIT;
        }
    }
}

class ContextThreadSpecific: public RunOnceCallBack{
public:
    ContextThreadSpecific(){
        keyOnce = PTHREAD_ONCE_INIT;
    }
    ContextThreadSpecific* init() {
      runOnce( keyOnce, *this );
      ContextThreadSpecific* t = (ContextThreadSpecific*)pthread_getspecific(pkey);
      if (t == 0) {
        t = new ContextThreadSpecific();
        assert(pthread_setspecific(pkey, t) == 0);
      }
      // chuangw: XXX bug?! In AgentLock code, it seems ThreadSpecific instances are never released from the memory
      return t;
    }
    // runOnce(): this imitates phtread_once() but supports object methods
    void operator() (void){
        assert(pthread_key_create(&pkey, NULL) == 0);
    }
    int getCurrentMode() { return init()->currentMode; }
    void setCurrentMode(int newMode) { init()->currentMode = newMode; }
    int currentMode;
private:
    pthread_key_t pkey;
    pthread_once_t keyOnce;

};
class ContextLock {
private:
    const ContextBaseClass& context;
    ContextThreadSpecific *contextThreadSpecific;
  public:
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;
    static const int WRITE_MODE = 1;
    static const int READ_MODE = 0;
    static const int NONE_MODE = -1;
public:
    ContextLock( const ContextBaseClass& ctx, int requestedMode = WRITE_MODE ): context(ctx), contextThreadSpecific(ctx.contextThreadSpecific->init() ), requestedMode( requestedMode), priorMode(contextThreadSpecific->currentMode), myTicketNum(Ticket::myTicket()){
        //context.contextThreadSpecific.Init();
        ADD_SELECTORS("ContextLock::(constructor)");
      macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;
      if (priorMode == NONE_MODE) {
        // do what's needed
        if (requestedMode == NONE_MODE) {
          //Do nothing.
        }
        else {
            upgradeFromNone();
        }
      } else if (priorMode == READ_MODE) {
        ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
      } else if (priorMode == WRITE_MODE) {
        ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
      } else {
        ABORT("Unknown priorMode!");
      }
      macedbg(1) << "CONTINUING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;
    }
    void upgradeFromNone(){
        ADD_SELECTORS("ContextLock::upgradeFromNone");
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

          //ScopedLock sl(_agent_ticketbooth);
          //
          // initialize my ticket if haven't done so.
          //
          // change ticket if ticket is invalid
          //
          // wait until my ticket is served
          if (requestedMode == READ_MODE) {
          } else if (requestedMode == WRITE_MODE) {
          }
    }

    ~ContextLock(){
        ADD_SELECTORS("ContextLock::(destructor)");
        downgrade(NONE_MODE);
    }
    
    void downgrade(int newMode) {
      ADD_SELECTORS("ContextLock::downgrade");
      int runningMode = contextThreadSpecific->getCurrentMode();
      uint64_t myTicketNum = Ticket::myTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == NONE_MODE && runningMode != NONE_MODE) 
        downgradeToNone( runningMode );
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) 
        downgradeToRead();
      else 
        macewarn << "Why was downgrade called?  Current mode is: " << runningMode << " and mode requested is: " << newMode << Log::endl;
      macedbg(1) << "Downgrade exiting" << Log::endl;
    }
    static void downgradeToNone(int runningMode) {
      ADD_SELECTORS("ContextLock::downgradeToNone");
        //ScopedLock sl(_agent_ticketbooth);
    }
    static void downgradeToRead() {
      ADD_SELECTORS("ContextLock::downgradeToRead");
        macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        //ScopedLock sl(_agent_ticketbooth);
    }
};

}

#endif
