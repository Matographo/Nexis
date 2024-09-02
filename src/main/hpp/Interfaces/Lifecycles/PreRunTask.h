#ifndef PRE_RUN_TASK_H
#define PRE_RUN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreRunTask : public virtual NexisInterfaceRegistry {
public:
    PreRunTask() {
        this->addInterface("PreRunTask");
    }
    virtual ~PreRunTask() = 0;
    virtual int preRun() = 0;
};


#endif