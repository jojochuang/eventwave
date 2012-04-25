/*********************************************
*  DeferredRouteTransportWrapper macros file
*  Mace generated on:
*  Tue Apr 10 10:09:47 2012
*********************************************/
#ifndef DeferredRouteTransportWrapper_macros_h
#define DeferredRouteTransportWrapper_macros_h

#include "lib/mace-macros.h"


#define state_change(s) changeState(s, selectorId->log)
#define typeof_upcall_deliver ReceiveDataHandler
#define map_typeof_upcall_deliver map_ReceiveDataHandler
#define typeof_upcall_error NetworkErrorHandler
#define map_typeof_upcall_error map_NetworkErrorHandler
#define typeof_upcall_messageError NetworkErrorHandler
#define map_typeof_upcall_messageError map_NetworkErrorHandler
#define typeof_upcall_forward ForwardDataHandler
#define map_typeof_upcall_forward map_ForwardDataHandler

#endif //DeferredRouteTransportWrapper_macros_h
