#ifndef VALIDATE_SUCCESS_EVENT_H
#define VALIDATE_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class ValidateSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    ValidateSuccessEvent() {
        this->addInterface("ValidateSuccessEvent");
    }
    virtual ~ValidateSuccessEvent() = 0;
    virtual int onValidateSuccess() = 0;
};


#endif