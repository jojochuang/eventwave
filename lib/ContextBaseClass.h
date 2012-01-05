// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
namespace mace {
class ContextThreadSpecific;
class ContextBaseClass: public Serializable {
public:
    ContextBaseClass();
    ~ContextBaseClass();
    ContextThreadSpecific* contextThreadSpecific;
};

}
#include "ContextLock.h"
#endif
