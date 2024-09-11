#ifndef AFTER_VALIDATE_TASK_H
#define AFTER_VALIDATE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterValidateTask : public virtual NexisInterfaceRegistry {
public:
    AfterValidateTask() {
        this->addInterface("AfterValidateTask");
    }
    virtual ~AfterValidateTask() = 0;
    virtual int afterValidate() = 0;
};


#endif