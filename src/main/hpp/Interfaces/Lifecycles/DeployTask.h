#ifndef DEPLOY_TASK_H
#define DEPLOY_TASK_H


class DeployTask {
public:
    virtual ~DeployTask() = 0;
    virtual int deploy() = 0;
};


#endif