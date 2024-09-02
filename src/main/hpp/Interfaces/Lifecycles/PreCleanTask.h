#ifndef PRE_CLEAN_TASK_H
#define PRE_CLEAN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreCleanTask : public virtual NexisInterfaceRegistry {
public:
    PreCleanTask() {
        this->addInterface("PreCleanTask");
    }
    virtual ~PreCleanTask() = 0;
    virtual int preClean() = 0;
};


#endif