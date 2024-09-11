#ifndef POST_VALIDATE_TASK_H
#define POST_VALIDATE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostValidateTask : public virtual NexisInterfaceRegistry {
public:
    PostValidateTask() {
        this->addInterface("PostValidateTask");
    }
    virtual ~PostValidateTask() = 0;
    virtual int postValidate() = 0;
};


#endif