#ifndef POST_VALIDATE_TASK_H
#define POST_VALIDATE_TASK_H


class PostValidateTask {
public:
    virtual ~PostValidateTask() = 0;
    virtual int postValidate() = 0;
};


#endif