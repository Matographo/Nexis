#ifndef BEFORE_COMPILE_TASK_H
#define BEFORE_COMPILE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeCompileTask : public virtual NexisInterfaceRegistry {
public:
    BeforeCompileTask() {
        this->addInterface("BeforeCompileTask");
    }
    virtual ~BeforeCompileTask() = 0;
    virtual int beforeCompile() = 0;
};


#endif