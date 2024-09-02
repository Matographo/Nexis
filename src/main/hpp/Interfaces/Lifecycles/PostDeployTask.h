#ifndef POST_DEPLOY_TASK_H
#define POST_DEPLOY_TASK_H


class PostDeployTask {
public:
    virtual ~PostDeployTask() = 0;
    virtual void postDeploy() = 0;
};


#endif