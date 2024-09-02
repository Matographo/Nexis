#ifndef DEPLOY_SUCCESS_EVENT_H
#define DEPLOY_SUCCESS_EVENT_H


class DeploySuccessEvent {
public:
    virtual ~DeploySuccessEvent() = 0;
    virtual void onDeploySuccess() = 0;
};


#endif