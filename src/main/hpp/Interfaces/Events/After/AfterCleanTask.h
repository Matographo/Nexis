#ifndef AFTER_CLEAN_TASK_H
#define AFTER_CLEAN_TASK_H


class AfterCleanTask {
public:
    virtual ~AfterCleanTask() = 0;
    virtual void afterClean() = 0;
};


#endif