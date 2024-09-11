#ifndef COMPILE_FAILURE_EVENT_H
#define COMPILE_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CompileFailureEvent : public virtual NexisInterfaceRegistry {
public:
    CompileFailureEvent() {
        this->addInterface("CompileFailureEvent");
    }
    virtual ~CompileFailureEvent() = 0;
    virtual int onCompileFailure() = 0;
};


#endif