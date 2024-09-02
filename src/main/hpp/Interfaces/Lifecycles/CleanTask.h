#ifndef CLEAN_TASK_H
#define CLEAN_TASK_H


class CleanTask {
public:
    virtual ~CleanTask() = 0;
    virtual void clean() = 0;
};


#endif