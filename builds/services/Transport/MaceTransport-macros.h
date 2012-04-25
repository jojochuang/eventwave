/*********************************************
*  MaceTransport macros file
*  Mace generated on:
*  Tue Apr 10 10:09:55 2012
*********************************************/
#ifndef MaceTransport_macros_h
#define MaceTransport_macros_h

#include "lib/mace-macros.h"


#define state_change(s) changeState(s, selectorId->log)
#define typeof_upcall_deliver ReceiveDataHandler
#define map_typeof_upcall_deliver map_ReceiveDataHandler
#define typeof_upcall_error NetworkErrorHandler
#define map_typeof_upcall_error map_NetworkErrorHandler
#define typeof_upcall_messageError NetworkErrorHandler
#define map_typeof_upcall_messageError map_NetworkErrorHandler
#define typeof_upcall_clearToSend ConnectionStatusHandler
#define map_typeof_upcall_clearToSend map_ConnectionStatusHandler
#define typeof_upcall_notifyFlushed ConnectionStatusHandler
#define map_typeof_upcall_notifyFlushed map_ConnectionStatusHandler

#endif //MaceTransport_macros_h
