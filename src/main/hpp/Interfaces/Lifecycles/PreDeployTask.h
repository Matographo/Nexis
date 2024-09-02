#ifndef PRE_DEPLOY_TASK_H
#define PRE_DEPLOY_TASK_H


class PreDeployTask {
public:
    virtual ~PreDeployTask() = 0;
    virtual int preDeploy() = 0;
};


#endif