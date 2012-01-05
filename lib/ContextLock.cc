#include "ContextLock.h"

pthread_mutex_t mace::CallBackFunctionObject::onceLock = PTHREAD_MUTEX_INITIALIZER;

