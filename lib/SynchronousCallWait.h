// TODO: chuangw
// When sync_foo() is called, store the mapping of context id to mutex.
// When received a transport packet, use this class to find & wake the caller thread.
//
#include "ScopedLock.h"
//#include "Log.h"
#include "mace-macros.h"
typedef std::map<std::string, std::pair<pthread_cond_t*, mace::string*> > ContextIDMutexMapType;

namespace mace{
class SynchronousCallWait{
public:
    /**
     * Wait for return value of the synchronous call
     * \param contextID The caller context ID
     * \param returnValue the object for receiving return value 
     * */
    SynchronousCallWait(std::string& contextID, mace::Serializable& returnValue){
        ADD_SELECTORS("SynchronousCallWait::(constructor)");
        ScopedLock sl( syncCallMutex );
        pthread_cond_init( &waitForReturn, NULL );
        mapping[ contextID ] = std::pair<pthread_cond_t*, mace::string* >(&(waitForReturn), &(serializedReturnValue) );

        pthread_cond_wait( &waitForReturn, &syncCallMutex );

        mace::deserialize( serializedReturnValue , &returnValue );

        mapping.erase( contextID );
    }

    ~SynchronousCallWait(){
        pthread_cond_destroy( &waitForReturn );
    }

    /**
     * Resumes the thread of the caller context.
     *
     * \param contextID a string representing the context id 
     * \param ret a Serializable object representing the return value of the synchronous call
     * \return whether the thread of the context id exists or not.
     * */
    static bool wake(std::string& contextID, mace::Serializable& ret){
        mace::string serRet;
        mace::serialize( serRet, &ret );
        return wake( contextID, serRet );
    }
    /**
     * Resumes the thread of the caller context.
     *
     * \param contextID a string representing the context id 
     * \param serRet a string representing the serialized return value of the synchronous call
     * \return whether the thread of the context id exists or not.
     * */
    static bool wake(std::string& contextID, mace::string& serRet){
        ADD_SELECTORS("SynchronousCallWait::wake");
        ScopedLock sl( syncCallMutex );

        ContextIDMutexMapType::iterator it= mapping.find( contextID );
        if( it == mapping.end() ){
            maceerr<<"Can't find contextID"<<Log::endl;
            return false;
        }else{
            // store the return value
            *(it->second.second) = serRet;

            pthread_cond_broadcast( it->second.first );

        }
        return true;
    }
private:
    pthread_cond_t waitForReturn;
    mace::string serializedReturnValue;
    static pthread_mutex_t syncCallMutex;
    static ContextIDMutexMapType mapping;
};
}
