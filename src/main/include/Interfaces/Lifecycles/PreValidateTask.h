#ifndef PRE_VALIDATE_TASK_H
#define PRE_VALIDATE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreValidateTask : public virtual NexisInterfaceRegistry {
public:
    PreValidateTask() {
        this->addInterface("PreValidateTask");
    }
    virtual ~PreValidateTask() = 0;
    virtual int preValidate() = 0;
};


#endif