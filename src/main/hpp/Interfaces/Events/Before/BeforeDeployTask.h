#ifndef BEFORE_DEPLOY_TASK_H
#define BEFORE_DEPLOY_TASK_H


class BeforeDeployTask {
public:
    virtual ~BeforeDeployTask() = 0;
    virtual int beforeDeploy() = 0;
};


#endif