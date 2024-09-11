#ifndef COMPILE_SUCCESS_EVENT_H
#define COMPILE_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CompileSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    CompileSuccessEvent() {
        this->addInterface("CompileSuccessEvent");
    }
    virtual ~CompileSuccessEvent() = 0;
    virtual int onCompileSuccess() = 0;
};


#endif