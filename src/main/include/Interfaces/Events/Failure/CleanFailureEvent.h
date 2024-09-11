#ifndef CLEAN_FAILURE_EVENT_H
#define CLEAN_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CleanFailureEvent : public virtual NexisInterfaceRegistry {
public:
    CleanFailureEvent() {
        this->addInterface("CleanFailureEvent");
    }
    virtual ~CleanFailureEvent() = 0;
    virtual int onCleanFailure() = 0;
};


#endif