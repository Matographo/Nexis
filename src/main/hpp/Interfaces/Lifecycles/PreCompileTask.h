#ifndef PRE_COMPILE_TASK_H
#define PRE_COMPILE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreCompileTask : public virtual NexisInterfaceRegistry {
public:
    PreCompileTask() {
        this->addInterface("PreCompileTask");
    }
    virtual ~PreCompileTask() = 0;
    virtual int preCompile() = 0;
};


#endif