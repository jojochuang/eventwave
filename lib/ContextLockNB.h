#ifndef _CONTEXTLOCKNB_H
#define _CONTEXTLOCKNB_H

// including headers
#include "mace.h"
#include "GlobalCommit.h"
#include "ContextBaseClass.h"
#include "pthread.h"
#include "ThreadStructure.h"
#include "Message.h"
// uses snapshot by default

namespace mace{

class ContextBaseClass;
class ContextLockNB;

class ContextLock {
private:
    ContextBaseClass& context;
    ContextThreadSpecific *contextThreadSpecific;
  public:
    const int8_t requestedMode;
    //const int8_t priorMode;
    int8_t priorMode;
    uint64_t myTicketNum;
  private:
    static pthread_mutex_t _context_ticketbooth; // chuangw: single ticketbooth for now. we will see if it'd become a bottleneck.

  public:
    static const int8_t WRITE_MODE = 1;
    static const int8_t READ_MODE = 0;
    static const int8_t NONE_MODE = -1;
  public:

public:
    ContextLockNB( ContextBaseClass& ctx, int8_t requestedMode, const Message* msg ): context(ctx), contextThreadSpecific(ctx.init() ), requestedMode( requestedMode), myTicketNum(ThreadStructure::myEvent().eventID){
        ADD_SELECTORS("ContextLockNB::(constructor)");

    }
    void upgradeFromNone(){ 
      ADD_SELECTORS("ContextLockNB::upgradeFromNone");
      ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");
    }
    void nullTicket() {// chuangw: OK, I think.
      ADD_SELECTORS("ContextLockNB::nullTicket");
    }

    void ticketBoothWait(int8_t requestedMode){
      ADD_SELECTORS("ContextLockNB::ticketBoothWait");
    }

    ~ContextLock(){ 
    }
    
    void downgrade(int8_t newMode) {
      ADD_SELECTORS("ContextLockNB::downgrade");
    }
    void downgradeToNone(int8_t runningMode) {
        ADD_SELECTORS("ContextLockNB::downgradeToNone");
    }
    void downgradeToRead() {
      ADD_SELECTORS("ContextLockNB::downgradeToRead");
    }
    void commitOrderWait() {
      ADD_SELECTORS("ContextLockNB::commitOrderWait");
    }
};

}

#endif
