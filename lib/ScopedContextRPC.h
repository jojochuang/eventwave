#ifndef _SCOPED_CONTEXT_RPC_H
#define _SCOPED_CONTEXT_RPC_H
#include "m_map.h"
#include "mstring.h"
#include <pthread.h>
namespace mace{
class ScopedContextRPC{
public:
  ScopedContextRPC(const mace::string& contextID):isReturned(false),contextID(contextID){
    pthread_cond_init( &cond , NULL );
    pthread_mutex_lock(&awaitingReturnMutex);
    awaitingReturnMapping[contextID] = &cond;
  }
  ~ScopedContextRPC(){
    returnValueMapping.erase( contextID );
    awaitingReturnMapping.erase( contextID );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  template<class T> T get(){
    T obj;
    if( !isReturned ){
      wait();
      isReturned = true;
      returnValue_iter = returnValueMapping.find( contextID );
      ASSERTMSG( returnValue_iter != returnValueMapping.end(), "Can't find the return value!" );
      in.str( returnValue_iter->second );
    }
    mace::deserialize( in, &obj );
    return obj;
  }
  static void wakeup( const mace::string& contextID ){
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< mace::string, pthread_cond_t* >::iterator cond_iter = awaitingReturnMapping.find( contextID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    pthread_cond_signal( cond_iter->second );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }
  void wakeupWithValue( const mace::string& contextID, const mace::string& retValue ){
    pthread_mutex_lock(&awaitingReturnMutex);
    std::map< mace::string, pthread_cond_t* >::iterator cond_iter = awaitingReturnMapping.find( contextID );
    ASSERTMSG( cond_iter != awaitingReturnMapping.end(), "Conditional variable not found" );
    returnValueMapping[ contextID ] = retValue;
    pthread_cond_signal( cond_iter->second );
    pthread_mutex_unlock(&awaitingReturnMutex);
  }

private:
  void wait(){
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
};

}
#endif // _SCOPED_CONTEXT_RPC_H
