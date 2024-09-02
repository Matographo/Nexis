#ifndef CLEAN_TASK_H
#define CLEAN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class CleanTask : public virtual NexisInterfaceRegistry {
public:
    CleanTask() {
        this->addInterface("CleanTask");
    }

    virtual ~CleanTask() = 0;
    virtual int clean() = 0;
};


#endif