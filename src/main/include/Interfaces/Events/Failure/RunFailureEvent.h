#ifndef RUN_FAILURE_EVENT_H
#define RUN_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class RunFailureEvent : public virtual NexisInterfaceRegistry {
public:
    RunFailureEvent() {
        this->addInterface("RunFailureEvent");
    }
    virtual ~RunFailureEvent() = 0;
    virtual int onRunFailure() = 0;
};


#endif