#ifndef _MACE_TICKET_H
#define _MACE_TICKET_H

#include <list>
#include <pthread.h>

#include "mhash_map.h"
#include "mvector.h"
#include "mdeque.h"
#include "mhash_set.h"
#include "mace-macros.h"
#include "mset.h"

#include "Event.h"
namespace mace{
class ContextBaseClass;
}
class ThreadStructure {
    class ThreadSpecific;
    public:
    static const uint8_t UNDEFINED_THREAD_TYPE = 0;
    static const uint8_t ASYNC_THREAD_TYPE     = 1;
    static const uint8_t TRANSPORT_THREAD_TYPE = 2;
    static const uint8_t HEAD_THREAD_TYPE      = 3;
  private:
		//Ticket relevant member variables
    static uint64_t nextTicketNumber;
    static uint64_t current_valid_ticket;
    static pthread_mutex_t ticketMutex;

	public:
    static void releaseThreadSpecificMemory(){
      ThreadSpecific::releaseThreadSpecificMemory();
    }
    /*static void prepareStop(){
      	ThreadSpecific::init()->prepareStop();
    }*/
    //static void haltHeadEventDispatcher(const uint64_t exitID);
    static uint64_t newTicket() {
        ADD_SELECTORS("ThreadStructure::newTicket");
        ScopedLock sl(ticketMutex);
      	ThreadSpecific *t = ThreadSpecific::init();
        t->setTicket(nextTicketNumber);
        /*if( t->getStopFlag() ){
          
          haltHeadEventDispatcher(nextTicketNumber);
        }*/
        macedbg(1) << "Ticket " << nextTicketNumber << " sold!" << Log::endl;
        return nextTicketNumber++;
    }
    static uint64_t getHighestTicketNumber(){
      // TODO: lock
        return nextTicketNumber;
    }
    static void setTicket(uint64_t ticket){
        ADD_SELECTORS("ThreadStructure::setTicket");
      	ThreadSpecific::init()->setTicket(ticket);
    }
    static void setEvent(const mace::Event& event){
        ADD_SELECTORS("ThreadStructure::setEvent");
        macedbg(1)<<"Set event with id = "<< event.eventID << Log::endl;
      	ThreadSpecific::init()->setEvent(event);
    }
    static void setEventID(const uint64_t eventID){
        ADD_SELECTORS("ThreadStructure::setEventID");
        macedbg(1)<<"Set event id = "<< eventID << Log::endl;
      	ThreadSpecific::init()->setEventID(eventID);
    }
    /*static void createEvent(const int8_t eventType){
      	ThreadSpecific::init()->createEvent(eventType);
    }*/

    static uint64_t myTicket() {
      	const ThreadSpecific *t = ThreadSpecific::init();
      	return t->myTicket();
    }
    static mace::Event& myEvent() {
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->myEvent();
    }
    static const uint64_t getEventContextMappingVersion(){
      	const ThreadSpecific *t = ThreadSpecific::init();
      	return t->getEventContextMappingVersion();
    }
    static void setEventContextMappingVersion( ){
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->setEventContextMappingVersion( );
    }
    static void setEventContextMappingVersion(const uint64_t ver ){
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->setEventContextMappingVersion(ver );
    }

    /*static void setLastWriteContextMapping(){
      	ThreadSpecific *t = ThreadSpecific::init();
      	return t->setLastWriteContextMapping( );
    }*/

    static mace::ContextBaseClass* myContext(){
      	ThreadSpecific *t = ThreadSpecific::init();
        //ASSERTMSG(t->myContext() != NULL, "ThreadStructure::myContext() object returned NULL!");
      	return t->myContext();
    }
    static void setMyContext(mace::ContextBaseClass* thisContext){
        ADD_SELECTORS("ThreadStructure::setMyContext");
        //ASSERTMSG(thisContext != NULL, "ThreadStructure::setMyContext() received a NULL pointer!");
      	ThreadSpecific *t = ThreadSpecific::init();
        t->setMyContext( thisContext );
    }
    class ScopedContextObject{
        private:
        ThreadSpecific *t;
        mace::ContextBaseClass* origContextObj;
        public: ScopedContextObject(mace::ContextBaseClass* thisContext){
            t = ThreadSpecific::init();
            origContextObj = t->myContext();
            t->setMyContext( thisContext );
        }
        ~ScopedContextObject(){
            t->setMyContext( origContextObj );
        }
    };

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

    static uint32_t getCurrentContext(){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->getCurrentContext();
    }

    static void popContext(){
        ThreadSpecific *t = ThreadSpecific::init();
        t->popContext();
    }

    static void pushContext(const uint32_t contextID){
        ADD_SELECTORS("ThreadStructure::pushContext");
        macedbg(1)<<"Set context ID as "<<contextID<<Log::endl;
        ThreadSpecific *t = ThreadSpecific::init();
        t->pushContext(contextID);
    }
    class ScopedContextID{
        private:
        ThreadSpecific *t;
        public: ScopedContextID(const uint32_t contextID){
            t = ThreadSpecific::init();
            t->pushContext(contextID);
        }
        ~ScopedContextID(){
            t->popContext();
        }
    };
    static void popServiceInstance(){
        ThreadSpecific *t = ThreadSpecific::init();
        t->popServiceInstance();
    }

    static void pushServiceInstance(const uint8_t sid){
        ADD_SELECTORS("ThreadStructure::pushServiceInstance");
        //macedbg(1)<<"Set context ID as "<<contextID<<Log::endl;
        ThreadSpecific *t = ThreadSpecific::init();
        t->pushServiceInstance(sid);
    }
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

    static bool deferExternalMessage( MaceKey const& dest,  std::string const&  message, registration_uid_t const rid ){
        ThreadSpecific *t = ThreadSpecific::init();
        uint8_t sid = t->getServiceInstance();
        return t->deferExternalMessage(sid, dest, message, rid);
    }
    static uint8_t getServiceInstance()  {
        ThreadSpecific *t = ThreadSpecific::init();
        return t->getServiceInstance();
    }
    // This is temporarily used in maceInit() and maceExit()
    static bool isOuterMostTransition( ){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->isOuterMostTransition();
    }
    static bool isApplicationDowncall( ){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->isApplicationDowncall();
    }
    // Determine if the current MaceInit is the first to be executed
    static bool isFirstMaceInit( ){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->isFirstMaceInit();
    }
    // Determine if the current MaceExit is the first to be executed
    static bool isFirstMaceExit( ){
        ThreadSpecific *t = ThreadSpecific::init();
        return t->isFirstMaceExit();
    }

    /**
     * This function returns a set of contexts owned by the event
     * */
    static const mace::Event::EventContextType& getEventContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventContexts();
    }
    static const mace::Event::EventServiceContextType& getCurrentServiceEventContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getCurrentServiceEventContexts();
    }
    static const mace::Event::EventSnapshotContextType& getEventSnapshotContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventSnapshotContexts();
    }
    static const mace::Event::EventServiceSnapshotContextType& getCurrentServiceEventSnapshotContexts(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getCurrentServiceEventSnapshotContexts();
    }
    /*static const uint64_t getCurrentServiceEventSkipID(const mace::string& contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getCurrentServiceEventSkipID(contextID);
    }*/
    static const uint64_t getEventSkipID(const uint8_t serviceID, const uint32_t contextID, const mace::vector< uint32_t >& parentID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventSkipID(serviceID, contextID, parentID);
    }
    static const bool  isEventEnteredService(const uint8_t serviceID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->isEventEnteredService(serviceID);
    }
    /**
     * This function inserts a context id owned by the event
     * */
    static const bool insertEventContext(const uint32_t contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->insertEventContext(contextID);
    }
    /**
     * This function removes a context id (because event downgrades)
     * */
    static const bool removeEventContext(const uint32_t contextID){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->removeEventContext(contextID);
    }

    static void insertSnapshotContext(const uint32_t contextID, const mace::string& snapshot){
        ThreadSpecific *t = ThreadSpecific::init();
        t->insertSnapshotContext(contextID, snapshot);
    }
    /**
     * This function resets the contexts of an event (when returning from an sync call)
     * */
    /*static void setEventContexts(const mace::map<uint8_t, mace::set<mace::string> >& contextIDs){
        ThreadSpecific *t = ThreadSpecific::init();
        t->setEventContexts(contextIDs);
    }*/
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
    /*static mace::set<mace::string>& getEventChildContexts(const mace::string& contextID){
        //ThreadSpecific *t = ThreadSpecific::init();
        //return  t->getEventChildContexts( contextID );


        // TODO: use versionlized context map snapshot
    }*/

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

    /*static uint32_t incrementEventMessageCount(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->incrementEventMessageCount();
    }*/
    /*static const uint32_t& getEventMessageCount(){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->getEventMessageCount();
    }
    static void setEventMessageCount(const uint32_t count){
        ThreadSpecific *t = ThreadSpecific::init();
        return  t->setEventMessageCount(count);
    }*/
  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();
        static ThreadSpecific* init();
        static void releaseThreadSpecificMemory();
        uint64_t myTicket() const;
        mace::Event& myEvent();
        const uint64_t getEventContextMappingVersion() const;
        void setEventContextMappingVersion( );
        void setEventContextMappingVersion( const uint64_t ver );
        mace::ContextBaseClass* myContext() const;
        void setMyContext(mace::ContextBaseClass* thisContext);
        //void prepareStop();
        void setTicket(uint64_t ticketNum) { ticket = ticketNum; ticketIsServed = false; }
        void setEvent(const mace::Event& _event);
        void setEventID(const uint64_t& eventID);
        //void createEvent(const int8_t eventType);
        void markTicketServed() { ticketIsServed = true; }

        const uint32_t getCurrentContext() const;
        void pushContext(const uint32_t contextID);
        void popContext();
        void pushServiceInstance(const uint8_t uid);
        void popServiceInstance();
        bool deferExternalMessage( uint8_t sid, MaceKey const& dest,  std::string const&  message, registration_uid_t const rid );
        const uint8_t getServiceInstance() const;
        bool isOuterMostTransition( ) const;
        bool isApplicationDowncall( ) const;
        bool isFirstMaceInit( ) const;
        bool isFirstMaceExit( ) const;

        const mace::Event::EventContextType& getEventContexts() const;
        const mace::Event::EventServiceContextType & getCurrentServiceEventContexts() ;
        const mace::Event::EventSnapshotContextType & getEventSnapshotContexts() ;
        const mace::Event::EventServiceSnapshotContextType & getCurrentServiceEventSnapshotContexts() ;
        //const uint64_t getCurrentServiceEventSkipID(const mace::string& contextID) const;
        const uint64_t getEventSkipID(const uint8_t serviceID, const uint32_t contextID, const mace::vector< uint32_t >& parentID) const ;
        const bool isEventEnteredService(const uint8_t serviceID) const;
        const bool insertEventContext(const uint32_t contextID);
        const bool removeEventContext(const uint32_t contextID);
        const void insertSnapshotContext(const uint32_t contextID, const mace::string& snapshot);
        void setEventContexts(const mace::Event::EventContextType& contextIDs);
        //void setServiceInstance(const uint8_t uid);
        void initializeEventStack();
        void setThreadType( const uint8_t type );
        uint8_t getThreadType();
        //bool getStopFlag() const;

        //uint32_t incrementEventMessageCount();
        //void setEventMessageCount(const uint32_t count);
        //const uint32_t& getEventMessageCount() const;
      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        static unsigned int count;

        mace::Event event;

        //bool stopFlag;
        uint64_t ticket;
        bool ticketIsServed;

        mace::ContextBaseClass* thisContext;
        mace::deque< uint32_t > contextStack;

        //mace::map<mace::string, mace::set<mace::string> > subcontexts;
        mace::deque< uint8_t > serviceStack;
        uint8_t threadType; ///< thread type is defined when the thread is start/created
    }; // ThreadSpecific
};
#endif
