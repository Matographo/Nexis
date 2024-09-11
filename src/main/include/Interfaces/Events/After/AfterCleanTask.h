#ifndef AFTER_CLEAN_TASK_H
#define AFTER_CLEAN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterCleanTask : public virtual NexisInterfaceRegistry {
public:
    AfterCleanTask() {
        this->addInterface("AfterCleanTask");
    }
    virtual ~AfterCleanTask() = 0;
    virtual int afterClean() = 0;
};


#endif