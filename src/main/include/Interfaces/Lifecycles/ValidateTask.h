#ifndef VALIDATE_TASK_H
#define VALIDATE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class ValidateTask : public virtual NexisInterfaceRegistry {
public:
    ValidateTask() {
        this->addInterface("ValidateTask");
    }
    virtual ~ValidateTask() = 0;
    virtual int validate() = 0;
};


#endif