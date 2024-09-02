#ifndef POST_VALIDATE_TASK_H
#define POST_VALIDATE_TASK_H


class PostValidateTask {
public:
    virtual ~PostValidateTask() = 0;
    virtual void postValidate() = 0;
};


#endif