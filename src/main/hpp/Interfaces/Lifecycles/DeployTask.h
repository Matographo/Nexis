#ifndef DEPLOY_TASK_H
#define DEPLOY_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class DeployTask : public virtual NexisInterfaceRegistry {
public:
    DeployTask() {
        this->addInterface("DeployTask");
    }
    virtual ~DeployTask() = 0;
    virtual int deploy() = 0;
};


#endif