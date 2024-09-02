#ifndef VALIDATE_TASK_H
#define VALIDATE_TASK_H


class ValidateTask {
public:
    virtual ~ValidateTask() = 0;
    virtual void validate() = 0;
};


#endif