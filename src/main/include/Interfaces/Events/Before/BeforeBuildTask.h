#ifndef BEFORE_BUILD_TASK_H
#define BEFORE_BUILD_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeBuildTask : public virtual NexisInterfaceRegistry {
public:
    BeforeBuildTask() {
        this->addInterface("BeforeBuildTask");
    }
    virtual ~BeforeBuildTask() = 0;
    virtual int beforeBuild() = 0;
};

#endif