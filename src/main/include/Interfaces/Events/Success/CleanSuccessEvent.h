#ifndef CLEAN_SUCCESS_EVENT_H
#define CLEAN_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CleanSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    CleanSuccessEvent() {
        this->addInterface("CleanSuccessEvent");
    }
    virtual ~CleanSuccessEvent() = 0;
    virtual int onCleanSuccess() = 0;
};


#endif