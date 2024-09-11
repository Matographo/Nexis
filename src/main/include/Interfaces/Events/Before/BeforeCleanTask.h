#ifndef BEFORE_CLEAN_TASK_H
#define BEFORE_CLEAN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeCleanTask : public virtual NexisInterfaceRegistry {
public:
    BeforeCleanTask() {
        this->addInterface("BeforeCleanTask");
    }
    virtual ~BeforeCleanTask() = 0;
    virtual int beforeClean() = 0;
};

#endif