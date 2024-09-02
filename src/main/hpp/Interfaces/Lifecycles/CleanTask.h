#ifndef CLEAN_TASK_H
#define CLEAN_TASK_H


class CleanTask {
public:
    virtual ~CleanTask() = 0;
    virtual int clean() = 0;
};


#endif