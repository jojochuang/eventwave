#ifndef _MACE_TICKET_H
#define _MACE_TICKET_H

#include <list>
#include <pthread.h>

#include "mvector.h"
#include "mhash_set.h"
#include "mace-macros.h"
#include "mset.h"

//#include "ContextBaseClass.h"
namespace mace{
class ContextBaseClass;
}
class ThreadStructure {
    class ThreadSpecific;
    public:
    static const uint8_t UNDEFINED_THREAD_TYPE = 0;
    static const uint8_t ASYNC_THREAD_TYPE = 1;
    static const uint8_t TRANSPORT_THREAD_TYPE = 2;
  private:
		//Ticket relevant member variables
    static uint64_t nextTicketNumber;
    static uint64_t current_valid_ticket;
    static pthread_mutex_t ticketMutex;

	public:
    static uint64_t newTicket() {
        ADD_SELECTORS("ThreadStructure::newTicket");
        ScopedLock sl(ticketMutex);
        ThreadSpecific::init()->setTicket(nextTicketNumber);
        macedbg(1) << "Ticket " << nextTicketNumber << " sold!" << Log::endl;
        return nextTicketNumber++;
    }
    static void setTicket(uint64_t ticket){
        ADD_SELECTORS("ThreadStructure::setTicket");
      	ThreadSpecific::init()->setTicket(ticket);
    }
    static void setEvent(uint64_t eventID){
        ADD_SELECTORS("ThreadStructure::setEvent");
        macedbg(1)<<"Set event id = "<< eventID << Log::endl;
      	ThreadSpecific::init()->setEvent(eventID);
    }

    static uint64_t myTicket() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myTicket();
    }
    static uint64_t myEvent() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myEvent();
    }

    static mace::ContextBaseClass* myContext(){
      	ThreadSpecific *t = ThreadSpecific::init();
        ASSERTMSG(t->myContext() != NULL, "ThreadStructure::myContext() object returned NULL!");
      	return t->myContext();
    }
    static void setMyContext(mace::ContextBaseClass* thisContext){
        ADD_SELECTORS("ThreadStructure::setMyContext");
        ASSERTMSG(thisContext != NULL, "ThreadStructure::setMyContext() received a NULL pointer!");
      	ThreadSpecific *t = ThreadSpecific::init();
        t->setMyContext( thisContext );
    }
    /*static void setServiceInstance(const uint8_t instanceUID){
        ADD_SELECTORS("ThreadStructure::setServiceInstance");
      	ThreadSpecific *t = ThreadSpecific::init();
        t->setServiceInstance( instanceUID );
    }*/

    static void markTicketServed() {// chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      t->markTicketServed();
      return;
    }

    static void releaseTicket() {// chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      current_valid_ticket = t->myTicket() + 1;
      return;
    }

    bool checkTicket() { // chuangw: XXX: not used currently
      ThreadSpecific *t = ThreadSpecific::init();
      if (current_valid_ticket == t->myTicket()) return true;
      else return false;
    }

    static uint64_t current_ticket() {
      return current_valid_ticket;
    }

    static mace::string getCurrentContext(){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->getCurrentContext();
    }

    static void popContext(){
        ThreadSpecific *t = ThreadSpecific::init();
        t->popContext();
    }

    static void pushContext(const mace::string& contextID){
        ADD_SELECTORS("ThreadStructure::pushContext");
        macedbg(1)<<"Set context ID as "<<contextID<<Log::endl;
        ThreadSpecific *t = ThreadSpecific::init();
        t->pushContext(contextID);
    }
    class ScopedContextID{
        private:
        ThreadSpecific *t;
        public: ScopedContextID(const mace::string& contextID){
            t = ThreadSpecific::init();
            t->pushContext(contextID);
        }
        ~ScopedContextID(){
            t->popContext();
        }
    };
    class ScopedServiceInstance{
        private:
        ThreadSpecific *t;
        public: ScopedServiceInstance(const uint8_t uid){
            t = ThreadSpecific::init();
            t->pushServiceInstance(uid);
        }
        ~ScopedServiceInstance(){
            t->popServiceInstance();
        }
    };
    // This is temporarily used in maceInit() and maceExit()
    static bool isOuterMostTransition( ){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->isOuterMostTransition();
    }

    /**
     * This function returns a set of contexts owned by the event
     * */
    static const mace::map<uint8_t, mace::set<mace::string> >& getEventContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventContexts();
    }
    /**
     * This function inserts a context id owned by the event
     * */
    static const bool insertEventContext(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->insertEventContext(contextID);
    }
    /**
     * This function removes a context id (because event downgrades)
     * */
    static const bool removeEventContext(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->removeEventContext(contextID);
    }
    /**
     * This function resets the contexts of an event (when returning from an sync call)
     * */
    static void setEventContexts(const mace::map<uint8_t, mace::set<mace::string> >& contextIDs){
        ThreadSpecific *t = ThreadSpecific::init();
        t->setEventContexts(contextIDs);
    }
    /**
     * This function erases all context IDs and resets message counter
     * */
    static void initializeEventStack(){
        ThreadSpecific *t = ThreadSpecific::init();
        t->initializeEventStack();
    }
    /**
     * This function returns a set of child-contexts of a context owned by the event
     * */
    static mace::set<mace::string>& getEventChildContexts(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventChildContexts( contextID );
    }

    /**
     * This function checks if the current event is allowed to enter the context
     * 
     * \param contextID Context ID requested to enter
     * */
    static bool checkValidContextRequest(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->checkValidContextRequest( contextID );
    }
    static void setThreadType( const uint8_t type ){
        ThreadSpecific *t = ThreadSpecific::init();
        t->setThreadType( type );
    }
    static uint8_t getThreadType(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getThreadType();
    }

    static bool isNoneContext(){
        return false; // TODO: not completed
    }

    static uint32_t incrementEventMessageCount(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->incrementEventMessageCount();
    }
    static const uint32_t& getEventMessageCount(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventMessageCount();
    }
    static void setEventMessageCount(const uint32_t count){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->setEventMessageCount(count);
    }
  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();
        static ThreadSpecific* init();
        uint64_t myTicket();
        uint64_t myEvent();
        mace::ContextBaseClass* myContext();
        void setMyContext(mace::ContextBaseClass* thisContext);
        void setTicket(uint64_t ticketNum) { ticket = ticketNum; ticketIsServed = false; }
        void setEvent(uint64_t _event) { eventID = _event; }
        void markTicketServed() { ticketIsServed = true; }

        const mace::string& getCurrentContext() const;
        void pushContext(const mace::string& contextID);
        void popContext();
        void pushServiceInstance(const uint8_t uid);
        void popServiceInstance();
        uint8_t getServiceInstance();
        bool isOuterMostTransition( ) const;

        mace::set<mace::string>& getEventChildContexts(const mace::string& contextID) {
            return subcontexts[contextID];
        }
        const mace::map< uint8_t, mace::set<mace::string> >& getEventContexts() const;
        const bool insertEventContext(const mace::string& contextID);
        const bool removeEventContext(const mace::string& contextID);
        void setEventContexts(const mace::map<uint8_t, mace::set<mace::string> >& contextIDs);
        //void setServiceInstance(const uint8_t uid);
        void initializeEventStack();
        bool checkValidContextRequest(const mace::string& contextID);
        void setThreadType( const uint8_t type );
        uint8_t getThreadType();

        uint32_t incrementEventMessageCount();
        void setEventMessageCount(const uint32_t count);
        const uint32_t& getEventMessageCount() const;
      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        static unsigned int count;
        uint64_t ticket;
        uint64_t eventID;
        bool ticketIsServed;

        mace::ContextBaseClass* thisContext;
        mace::vector< mace::string> contextStack;

        mace::map<uint8_t, mace::set<mace::string> > eventContexts;///< all the contexts possessed by this event

        mace::map<mace::string, mace::set<mace::string> > subcontexts;
        mace::vector< uint8_t > serviceStack;
        uint8_t threadType; ///< thread type is defined when the thread is start/created
        uint32_t eventMessageCount;
    }; // ThreadSpecific
};
#endif
