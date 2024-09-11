#ifndef DEPLOY_SUCCESS_EVENT_H
#define DEPLOY_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class DeploySuccessEvent : public virtual NexisInterfaceRegistry {
public:
    DeploySuccessEvent() {
        this->addInterface("DeploySuccessEvent");
    }
    virtual ~DeploySuccessEvent() = 0;
    virtual int onDeploySuccess() = 0;
};


#endif