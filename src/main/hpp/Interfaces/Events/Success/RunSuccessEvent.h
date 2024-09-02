#ifndef RUN_SUCCESS_EVENT_H
#define RUN_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class RunSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    RunSuccessEvent() {
        this->addInterface("RunSuccessEvent");
    }
    virtual ~RunSuccessEvent() = 0;
    virtual int onRunSuccess() = 0;
};


#endif