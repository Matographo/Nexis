#ifndef DEPLOY_FAILURE_EVENT_H
#define DEPLOY_FAILURE_EVENT_H


class DeployFailureEvent {
public:
    virtual ~DeployFailureEvent() = 0;
    virtual void onDeployFailure() = 0;
};


#endif