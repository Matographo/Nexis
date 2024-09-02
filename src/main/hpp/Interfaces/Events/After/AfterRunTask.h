#ifndef AFTER_RUN_TASK_H
#define AFTER_RUN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterRunTask : public virtual NexisInterfaceRegistry {
public:
    AfterRunTask() {
        this->addInterface("AfterRunTask");
    }
    virtual ~AfterRunTask() = 0;
    virtual int afterRun() = 0;
};


#endif