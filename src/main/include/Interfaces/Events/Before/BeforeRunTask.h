#ifndef BEFORE_RUN_TASK_H
#define BEFORE_RUN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeRunTask : public virtual NexisInterfaceRegistry {
public:
    BeforeRunTask() {
        this->addInterface("BeforeRunTask");
    }
    virtual ~BeforeRunTask() = 0;
    virtual int beforeRun() = 0;
};


#endif