#ifndef _SCOPED_CONTEXT_RPC_H
#define _SCOPED_CONTEXT_RPC_H
/**
 * \file ScopedContextRPC.h
 * \brief declares the ScopedContextRPC class.
 */
#include <pthread.h>

#include "m_map.h"
#include "mstring.h"
#include "ThreadStructure.h"
namespace mace{
/**
 * \brief provides a scoped RPC mechanism
 *
 * In fullcontext Mace, a routine call may be initiated at a context located at 
 * remote node. Therefore RPC mechanism is required to retrieve the return value
 * of the routine call.
 *
 * Common usage:
 * \code
 * uint32_t srcContextID; // the id of the caller context
 * uint32_t rv; // return value
 * mace::ScopedContextRPC rpc(srcContextID);
 * downcall_route( destNode, msg, __ctx );
 * rpc.get( rv ); // blcks until the RPC returns
 * \endcode
 *
 * At the remote node, to respond to such a RPC:
 * \code
 * uint32_t srcContextID; 
 * uint32_t rv = 1;
 * mace::ScopedContextRPC::wakeupWithValue( srcContextID, rv );
 * \endcode
 * */
class ScopedContextRPC{
public:
  ScopedContextRPC():isReturned(false),eventID(ThreadStructure::myEvent().eventID){
    ADD_SELECTORS("ScopedContextRPC::(constructor)");
    pthread_cond_init( &cond , NULL );
    pthread_mutex_lock(&awaitingReturnMutex);
    awaitingReturnMapping[eventID].push_back( &cond );
    macedbg(1)<<"event "<< eventID << " will be waiting for RPC return"<<Log::endl;
  }
  ~ScopedContextRPC(){
    if( !isReturned ){
      wait();
      isReturned = true;
    }
    if( returnValueMapping.find( eventID ) != returnValueMapping.end() ){
      returnValueMapping[ eventID ].pop_back();
      awaitingReturnMapping[ eventID ].pop_back();
      if( returnValueMapping[ eventID ].empty() ){
        returnValueMapping.erase( eventID );
        awaitingReturnMapping.erase( eventID );
      }
    }else{
      awaitingReturnMapping[ eventID ].pop_back();
      if( awaitingReturnMapping[ eventID ].empty() ){
        awaitingReturnMapping.erase( eventID );
      }
    }
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  template<class T> void get(T& obj){
    ADD_SELECTORS("ScopedContextRPC::(constructor)");
    macedbg(1)<<"wait for return"<<Log::endl;
    if( !isReturned ){
      wait();
      isReturned = true;
      returnValue_iter = returnValueMapping.find( eventID );
      ASSERTMSG( returnValue_iter != returnValueMapping.end(), "Can't find the return value because event not found!" );
      in.str( returnValue_iter->second.back() );
    }
    mace::deserialize( in, &obj );
    macedbg(1)<<"returned"<<Log::endl;
  }
  static void wakeup( const uint64_t eventID ){
    ADD_SELECTORS("ScopedContextRPC::(constructor)");
    macedbg(1)<<"wake up event "<< eventID << " with no return value"<<Log::endl;
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< uint64_t, std::vector< pthread_cond_t* > >::iterator cond_iter = awaitingReturnMapping.find( eventID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    ASSERTMSG( !cond_iter->second.empty(), "Conditional variable not found due to empty stack" );
    pthread_cond_signal( cond_iter->second.back() );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  static void wakeupWithValue( const uint64_t eventID, const mace::string& retValue ){
    ADD_SELECTORS("ScopedContextRPC::(constructor)");
    macedbg(1)<<"wake up event "<< eventID << " with return value"<<Log::endl;
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< uint64_t, std::vector< pthread_cond_t* > >::iterator cond_iter = awaitingReturnMapping.find( eventID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    ASSERTMSG( !cond_iter->second.empty(), "Conditional variable not found due to empty stack" );
    returnValueMapping[ eventID ].push_back( retValue );
    pthread_cond_signal( cond_iter->second.back() );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  static void wakeupWithValue( const mace::string& retValue, mace::Event const& event ){
    ADD_SELECTORS("ScopedContextRPC::(constructor)");
    macedbg(1)<<"wake up event "<< event.getEventID() << " with return value"<<Log::endl;
    mace::string event_str;
    mace::serialize( event_str, &event );
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< uint64_t, std::vector< pthread_cond_t* > >::iterator cond_iter = awaitingReturnMapping.find( event.getEventID() );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    ASSERTMSG( !cond_iter->second.empty(), "Conditional variable not found due to empty stack" );
    returnValueMapping[ event.getEventID() ].push_back( retValue );
    returnValueMapping[ event.getEventID() ].back().append( event_str );
    pthread_cond_signal( cond_iter->second.back() );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  static void setTransportThreads(uint32_t threads ){
    transportThreads = threads;
  }
  static void setAsyncThreads(uint32_t threads ){
    asyncThreads = threads;
  }

private:
  void wait(){
    pthread_cond_wait( &cond, &awaitingReturnMutex );
  }
  bool isReturned;
  const uint64_t eventID;
  pthread_cond_t cond;
  std::map< uint64_t, std::vector< mace::string > >::iterator returnValue_iter;
  std::istringstream in;

  static std::map< uint64_t, std::vector< mace::string > > returnValueMapping;
  static std::map< uint64_t, std::vector< pthread_cond_t* > > awaitingReturnMapping;
  static pthread_mutex_t awaitingReturnMutex;
  static uint32_t waitTransportThreads;
  static uint32_t waitAsyncThreads;
  static uint32_t transportThreads;
  static uint32_t asyncThreads;
}; // ScopedContextRPC

}
#endif // _SCOPED_CONTEXT_RPC_H
