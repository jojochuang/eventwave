#include "ContextBaseClass.h"
using namespace mace;
ContextBaseClass::ContextBaseClass(): 
    pkey(),
    keyOnce( PTHREAD_ONCE_INIT ),
    now_serving(1),
    now_committing(1),
    lastWrite (1),
    numReaders(0),
    numWriters(0)
{
    contextThreadSpecific = new ContextThreadSpecific(*this);
}
ContextBaseClass::~ContextBaseClass(){
    delete contextThreadSpecific;
}
