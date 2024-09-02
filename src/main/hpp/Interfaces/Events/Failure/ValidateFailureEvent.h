#ifndef VALIDATE_FAILURE_EVENT_H
#define VALIDATE_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class ValidateFailureEvent : public virtual NexisInterfaceRegistry {
public:
    ValidateFailureEvent() {
        this->addInterface("ValidateFailureEvent");
    }
    virtual ~ValidateFailureEvent() = 0;
    virtual int onValidateFailure() = 0;
};


#endif