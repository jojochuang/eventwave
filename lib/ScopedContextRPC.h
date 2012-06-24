#ifndef _SCOPED_CONTEXT_RPC_H
#define _SCOPED_CONTEXT_RPC_H
/**
 * \file ScopedContextRPC.h
 * \brief declares the ScopedContextRPC class.
 */
#include "m_map.h"
#include "mstring.h"
#include <pthread.h>
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
 * mace::string srcContextID; // the id of the caller context
 * uint32_t rv; // return value
 * mace::ScopedContextRPC rpc(srcContextID);
 * downcall_route( destNode, msg, __ctx );
 * rpc.get( rv ); // blcks until the RPC returns
 * \endcode
 *
 * At the remote node, to respond to such a RPC:
 * \code
 * mace::stirng srcContextID; 
 * uint32_t rv = 1;
 * mace::ScopedContextRPC::wakeupWithValue( srcContextID, rv );
 * \endcode
 * */
class ScopedContextRPC{
public:
  ScopedContextRPC(const mace::string& contextID):isReturned(false),contextID(contextID){
    pthread_cond_init( &cond , NULL );
    pthread_mutex_lock(&awaitingReturnMutex);
    awaitingReturnMapping[contextID] = &cond;
  }
  ~ScopedContextRPC(){
    if( !isReturned ){
      wait();
      isReturned = true;
    }
    returnValueMapping.erase( contextID );
    awaitingReturnMapping.erase( contextID );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  template<class T> void get(T& obj){
    if( !isReturned ){
      wait();
      isReturned = true;
      returnValue_iter = returnValueMapping.find( contextID );
      ASSERTMSG( returnValue_iter != returnValueMapping.end(), "Can't find the return value!" );
      in.str( returnValue_iter->second );
    }
    mace::deserialize( in, &obj );
  }
  static void wakeup( const mace::string& contextID ){
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< mace::string, pthread_cond_t* >::iterator cond_iter = awaitingReturnMapping.find( contextID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    pthread_cond_signal( cond_iter->second );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  static void wakeupWithValue( const mace::string& contextID, const mace::string& retValue ){
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< mace::string, pthread_cond_t* >::iterator cond_iter = awaitingReturnMapping.find( contextID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    returnValueMapping[ contextID ] = retValue;
    pthread_cond_signal( cond_iter->second );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }

private:
  inline void wait(){
    pthread_cond_wait( &cond, &awaitingReturnMutex );
  }
  bool isReturned;
  const mace::string& contextID;
  pthread_cond_t cond;
  std::map< mace::string, mace::string >::iterator returnValue_iter;
  std::istringstream in;

  static std::map< mace::string, mace::string > returnValueMapping;
  static std::map< mace::string, pthread_cond_t* > awaitingReturnMapping;
  static pthread_mutex_t awaitingReturnMutex;
}; // ScopedContextRPC

}
#endif // _SCOPED_CONTEXT_RPC_H
