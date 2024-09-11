#ifndef AFTER_DEPLOY_TASK_H
#define AFTER_DEPLOY_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterDeployTask : public virtual NexisInterfaceRegistry {
public:
    AfterDeployTask() {
        this->addInterface("AfterDeployTask");
    }
    virtual ~AfterDeployTask() = 0;
    virtual int afterDeploy() = 0;
};


#endif