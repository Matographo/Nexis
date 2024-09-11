#ifndef DEPLOY_FAILURE_EVENT_H
#define DEPLOY_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class DeployFailureEvent : public virtual NexisInterfaceRegistry {
public:
    DeployFailureEvent() {
        this->addInterface("DeployFailureEvent");
    }
    virtual ~DeployFailureEvent() = 0;
    virtual int onDeployFailure() = 0;
};


#endif