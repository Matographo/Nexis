#ifndef PRE_VALIDATE_TASK_H
#define PRE_VALIDATE_TASK_H


class PreValidateTask {
public:
    virtual ~PreValidateTask() = 0;
    virtual int preValidate() = 0;
};


#endif