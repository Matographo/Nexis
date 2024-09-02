#ifndef BEFORE_VALIDATE_TASK_H
#define BEFORE_VALIDATE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeValidateTask : public virtual NexisInterfaceRegistry {
public:
    BeforeValidateTask() {
        this->addInterface("BeforeValidateTask");
    }
    virtual ~BeforeValidateTask() = 0;
    virtual int beforeValidate() = 0;
};


#endif