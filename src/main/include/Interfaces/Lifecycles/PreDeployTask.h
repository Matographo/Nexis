#ifndef PRE_DEPLOY_TASK_H
#define PRE_DEPLOY_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreDeployTask : public virtual NexisInterfaceRegistry {
public:
    PreDeployTask() {
        this->addInterface("PreDeployTask");
    }
    virtual ~PreDeployTask() = 0;
    virtual int preDeploy() = 0;
};


#endif