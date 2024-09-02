#ifndef BEFORE_CLEAN_TASK_H
#define BEFORE_CLEAN_TASK_H


class BeforeCleanTask {
public:
    virtual ~BeforeCleanTask() = 0;
    virtual int beforeClean() = 0;
};

#endif