#ifndef AFTER_COMPILE_TASK_H
#define AFTER_COMPILE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterCompileTask : public virtual NexisInterfaceRegistry {
public:
    AfterCompileTask() {
        this->addInterface("AfterCompileTask");
    }
    virtual ~AfterCompileTask() = 0;
    virtual int afterCompile() = 0;
};


#endif