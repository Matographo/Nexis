#ifndef AFTER_BUILD_TASK_H
#define AFTER_BUILD_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterBuildTask : public virtual NexisInterfaceRegistry {
public:
    AfterBuildTask() {
        this->addInterface("AfterBuildTask");
    }
    virtual ~AfterBuildTask() = 0;
    virtual int afterBuild() = 0;
};


#endif