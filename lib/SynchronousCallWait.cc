#include "SynchronousCallWait.h"

static pthread_mutex_t SynchronousCallWait::syncCallMutex = PTHREAD_MUTEX_INITIALIZER;
static ContextIDMutexMapType SynchronousCallWait::mapping;
