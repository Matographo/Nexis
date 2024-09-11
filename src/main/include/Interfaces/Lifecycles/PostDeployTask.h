#ifndef POST_DEPLOY_TASK_H
#define POST_DEPLOY_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostDeployTask : public virtual NexisInterfaceRegistry {
public:
    PostDeployTask() {
        this->addInterface("PostDeployTask");
    }
    virtual ~PostDeployTask() = 0;
    virtual int postDeploy() = 0;
};


#endif