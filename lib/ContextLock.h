#ifndef _CONTEXTLOCK_H
#define _CONTEXTLOCK_H

// including headers
#include "GlobalCommit.h"
#include "ContextBaseClass.h"

// uses snapshot by default

namespace mace{

class ContextBaseClass;

class ContextThreadSpecific{

};
class ContextLock {
public:
    ContextLock( const ContextBaseClass& ctx ): context(ctx){

    }
    
private:
    const ContextBaseClass& context;
};

}

#endif
