#ifndef PRE_CLEAN_TASK_H
#define PRE_CLEAN_TASK_H


class PreCleanTask {
public:
    virtual ~PreCleanTask() = 0;
    virtual void preClean() = 0;
};


#endif