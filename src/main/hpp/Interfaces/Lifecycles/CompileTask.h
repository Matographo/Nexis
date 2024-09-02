#ifndef COMPILE_TASK_H
#define COMPILE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CompileTask : public virtual NexisInterfaceRegistry {
public:
    CompileTask() {
        this->addInterface("CompileTask");
    }
    virtual ~CompileTask() = 0;
    virtual int compile() = 0;
};


#endif