#ifndef BEFORE_CLEAN_TASK_H
#define BEFORE_CLEAN_TASK_H


class BeforeCleanTask {
public:
    virtual ~BeforeCleanTask() = 0;
    virtual void beforeClean() = 0;
};

#endif