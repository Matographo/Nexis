#ifndef AFTER_DEPLOY_TASK_H
#define AFTER_DEPLOY_TASK_H


class AfterDeployTask {
public:
    virtual ~AfterDeployTask() = 0;
    virtual void afterDeploy() = 0;
};


#endif