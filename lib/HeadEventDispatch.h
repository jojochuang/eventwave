#ifndef __HEAD_EVENT_DISPATCH_h
#define __HEAD_EVENT_DISPATCH_h

#include "mace.h"
#include "mace-macros.h"
#include "ThreadPool.h"
#include "Message.h"
#include "InternalMessage.h"

#include "MaceKey.h"
#include "CircularQueueList.h"
#include <deque>
#include "InternalMessageInterface.h"
using mace::InternalMessageSender;
/**
 * \file HeadEventDispatch.h
 * \brief declares the HeadEventDispatch class 
 */
class AsyncEventReceiver;
namespace mace{
  class AgentLock;
}
namespace HeadEventDispatch {
  typedef mace::map< uint64_t, uint64_t, mace::SoftState> EventRequestTSType;
  /// the timestamp where the event request is created
  extern EventRequestTSType eventRequestTime;
  /// the timestamp where the event request is processed
  extern EventRequestTSType eventStartTime;
  extern pthread_mutex_t startTimeMutex;
  extern pthread_mutex_t requestTimeMutex;

  extern pthread_mutex_t samplingMutex;
  extern bool sampleEventLatency;
  extern uint32_t accumulatedLatency;
  extern uint32_t accumulatedEvents;

  void insertEventStartTime(uint64_t eventID);
  void insertEventRequestTime(uint64_t eventID);
  void sampleLatency( bool flag );
  double getAverageLatency(  );

  void waitAfterCommit( uint64_t eventTicket );

  class HeadMigration {
public:
    static void setState( const uint16_t newState ){
      ScopedLock sl( lock );
      state = newState;
    }
    static const uint16_t getState( ){
      ScopedLock sl( lock );
      return state;
    }
    static void setMigrationEventID( const uint64_t eventID ){
      ScopedLock sl( lock );
      migrationEventID = eventID;
    }
    static const uint64_t getMigrationEventID( ){
      ScopedLock sl( lock );
      return migrationEventID;
    }
    static void setNewHead( const MaceAddr& head ){
      ScopedLock sl( lock );
      newHeadAddr = head;
    }
    static const MaceAddr getNewHead( ){
      ScopedLock sl( lock );
      return newHeadAddr;
    }
public:
    static const uint16_t HEAD_STATE_NORMAL = 0;
    static const uint16_t HEAD_STATE_MIGRATING = 1;
    static const uint16_t HEAD_STATE_MIGRATED = 2;
private:
    static pthread_mutex_t lock;
    static uint16_t state;
    static uint64_t migrationEventID;
    static mace::MaceAddr newHeadAddr;

  };

  typedef void (AsyncEventReceiver::*eventfunc)( mace::RequestType );
  class HeadEvent {
    public:
      AsyncEventReceiver* cl;
      eventfunc func;
      mace::RequestType param;
      uint64_t ticket;

    public:
      HeadEvent() : cl(NULL), func(NULL), param(NULL), ticket(0) {}
      HeadEvent(AsyncEventReceiver* cl, eventfunc func, 
#ifdef EVENTREQUEST_USE_SHARED_PTR
  mace::RequestType&
#else
  mace::RequestType
#endif
 param, uint64_t ticket ) : cl(cl), func(func), param(param), ticket(ticket) {}
      void fire() {
        ThreadStructure::setTicket( ticket );
        (cl->*func)(param);
      }
  };


  void init();
  void prepareHalt(const uint64_t exitID);
  void haltAndWait();
  void haltAndWaitCommit();
  void haltAndNoWaitCommit();

  class HeadEventTP;
  struct ThreadArg {
    HeadEventTP* p;
    uint32_t i;
  };

  /**
   * The thread pool of the head node for creating events
   *
   * The thread pool is of dynamic size between minThreadSize and maxThreadSize. This object is similar to ThreadPool.
   * 
   * */
  class HeadEventTP{
  friend class mace::AgentLock;
  public:
  //typedef mace::ThreadPool<HeadEventTP, HeadEvent> ThreadPoolType;
  private: 
    uint32_t idle; ///< number of idle threads
    bool* sleeping; ///< whether the thread is sleeping or not
    ThreadArg* args; ///< argument to the thread
    bool busyCommit; ///< whether or not the commit thread is sleeping
    const uint32_t minThreadSize; ///< minimum number of threads
    const uint32_t maxThreadSize; ///< max number of threads
    static pthread_t* headThread; ///< pthread_t array of threads
    static pthread_t headCommitThread; ///< pthread_t array of commit threads
    HeadEvent data; ///< record of an event request
    mace::Event* committingEvent; ///< pointer to the currently commiting event
    pthread_cond_t signalv; ///< conditional variable for head thread
    pthread_cond_t signalc; ///< conditional variable for commit thread


  static void doExecuteEvent(HeadEvent const& thisev);
  static void tryWakeup();
  public:
    /**
     * constructor
     * @param minThreadSize minimum number of threads
     * @param maxThreadSize maximum number of threads
     * */
    HeadEventTP( const uint32_t minThreadSize, const uint32_t maxThreadSize);

    /**
     * destructor
     * */
    ~HeadEventTP() ;

    /**
     * wait on the conditional variable
     * */
    void wait();
    /**
     * (event commit thread) wait on the conditional variable
     * */
    void commitWait() ;

    /**
     * signal one head thread
     * */
    void signalSingle() ;
    /**
     * signal all head threads
     * */
    void signalAll() ;
    /**
     * signal commit thread
     * */
    void signalCommitThread() ;
    /**
     * cond function
     * @return TRUE if the next event is ready to initialize
     * */
    bool hasPendingEvents();
    /**
     * cond function
     * @return TRUE if the next event is ready to commit
     * */
    bool hasUncommittedEvents();
    //static bool nextToCommit( uint64_t eventID);
    // setup
    /**
     * set up the thread structure to initialize the event
     * */
    void executeEventSetup();
    /**
     * set up the thread structure to commit the event
     * */
    void commitEventSetup( );
    // process
    /**
     * execute the callback function of the event request
     * */
    void executeEventProcess();
    /**
     * execute the callback function of the commit request
     * */
    void commitEventProcess() ;
    // finish
    /**
     * finish initializing the event 
     * */
    void executeEventFinish();
    /**
     * finish commit request
     * */
    void commitEventFinish() ;

    
    /**
     * this is where the head thread starts
     * */
    static void* startThread(void* arg) ;
    /**
     * this is where the commit thread starts
     * */
    static void* startCommitThread(void* arg) ;
    /**
     * execution of the head thread
     * @param n the id of the thread
     * */
    void run(uint32_t n);
    /**
     * execution of the commit thread
     * */
    void runCommit();

    /**
     * signal the head thread to stop and wait for its termination
     * */
    void haltAndWait();
    /**
     * signal the head thread to stop and return immediately
     * @param exitTicket the ticket id of exit event
     * */
    void prepareHalt(const uint64_t exitTicket);
    /**
     * signal the commit thread to stop and wait for its termination
     * */
    void haltAndWaitCommit();
    void haltAndNoWaitCommit();
    /**
     * put an event request in the head queue
     * @param sv the service that starts the request
     * @param func the callback function
     * @param p the request object
     * @param useTicket whether or not to use the current ticket as the ID of the new event.
     * */
    static void executeEvent(AsyncEventReceiver* sv, eventfunc func, mace::Message* p, bool useTicket);
    /**
     * Call by Event::commit() to put all sub event requests in the head queue
     * */
    static void executeEvent(eventfunc func, mace::Event::EventRequestType subevents, bool useTicket);
    /**
     * put an event in the commit queue
     * @param event the event object
     * */
    static void commitEvent(const mace::Event& event);
    static void accumulateEventLifeTIme(mace::Event const& event);
    static void accumulateEventRequestCommitTime(mace::Event const& event);
  };
  HeadEventTP* HeadEventTPInstance() ;

  class HeadTransportQueueElement {
    private: 
      InternalMessageSender* cl;
      mace::MaceAddr dest;
      mace::AsyncEvent_Message* eventObject;
      uint64_t instanceUniqueID;

    public:
      HeadTransportQueueElement() : cl(NULL), eventObject(NULL), instanceUniqueID(0) {}
      HeadTransportQueueElement(InternalMessageSender* cl, mace::MaceAddr const& dest, mace::AsyncEvent_Message* const eventObject, uint64_t instanceUniqueID) : cl(cl), dest(dest), eventObject(eventObject), instanceUniqueID(instanceUniqueID) {}
      void fire() {
        ADD_SELECTORS("HeadTransportQueueElement::fire");
        mace::InternalMessage msg( eventObject, instanceUniqueID );
        cl->sendInternalMessage(dest, msg);
        msg.unlinkHelper();
        delete eventObject;
      }
  };
  typedef std::queue< HeadTransportQueueElement > MessageQueue;
  class HeadTransportTP {
    typedef mace::ThreadPool<HeadTransportTP, HeadTransportQueueElement> ThreadPoolType;
    private:
      static pthread_mutex_t ht_lock;
      static MessageQueue mqueue;
      ThreadPoolType *tpptr;
      bool runDeliverCondition(ThreadPoolType* tp, uint threadId);
      void runDeliverSetup(ThreadPoolType* tp, uint threadId);
      void runDeliverProcessUnlocked(ThreadPoolType* tp, uint threadId);
      void runDeliverProcessFinish(ThreadPoolType* tp, uint threadId);
    public:
      HeadTransportTP(uint32_t minThreadSize, uint32_t maxThreadSize  );
      ~HeadTransportTP();

      void signal();

      void haltAndWait();
      static void lock(); // lock

      static void unlock(); // unlock
      static void sendEvent(InternalMessageSender* sv, mace::MaceAddr const& dest, mace::AsyncEvent_Message* const eventObject, uint64_t instanceUniqueID);

      static void init();
  };
}

#endif
