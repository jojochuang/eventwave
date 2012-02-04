#include "SynchronousCallWait.h"

pthread_mutex_t mace::SynchronousCallWait::syncCallMutex = PTHREAD_MUTEX_INITIALIZER;
ContextIDMutexMapType mace::SynchronousCallWait::mapping;
