#ifndef RUN_TASK_H
#define RUN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class RunTask : public virtual NexisInterfaceRegistry {
public:
    RunTask() {
        this->addInterface("RunTask");
    }
    virtual ~RunTask() = 0;
    virtual int run() = 0;
};


#endif