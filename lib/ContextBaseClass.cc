#include "ContextBaseClass.h"
using namespace mace;
ContextBaseClass::ContextBaseClass(){
    pthread_mutex_init(& _context_ticketbooth, NULL );
    now_serving = 1;
    lastWrite = 1;
    numReaders = 0;
    numWriters = 0;
    contextThreadSpecific = new ContextThreadSpecific();
}
ContextBaseClass::~ContextBaseClass(){
    delete contextThreadSpecific;
}
