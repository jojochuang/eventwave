// Parent class for all context classes
// chuangw: FIXME: skeleton, empty class so far.
#ifndef CONTEXTBASECLASS_H
#define CONTEXTBASECLASS_H

#include "Serializable.h"
#include "ContextLock.h"
namespace mace {
class ContextBaseClass: public Serializable {
public:
    ContextThreadSpecific* contextThreadSpecific;
};

}
#endif
