#include "ContextBaseClass.h"
using namespace mace;
ContextBaseClass::ContextBaseClass(){
    contextThreadSpecific = new ContextThreadSpecific();
}
ContextBaseClass::~ContextBaseClass(){
    delete contextThreadSpecific;
}
