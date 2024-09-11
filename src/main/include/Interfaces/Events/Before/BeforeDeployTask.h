#ifndef BEFORE_DEPLOY_TASK_H
#define BEFORE_DEPLOY_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeDeployTask : public virtual NexisInterfaceRegistry {
public:
    BeforeDeployTask() {
        this->addInterface("BeforeDeployTask");
    }
    virtual ~BeforeDeployTask() = 0;
    virtual int beforeDeploy() = 0;
};


#endif