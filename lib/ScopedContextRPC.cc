#include "ScopedContextRPC.h"

std::map< mace::string, mace::string > mace::ScopedContextRPC::returnValueMapping;
std::map< mace::string, pthread_cond_t* > mace::ScopedContextRPC::awaitingReturnMapping;
pthread_mutex_t mace::ScopedContextRPC::awaitingReturnMutex = PTHREAD_MUTEX_INITIALIZER;
