#ifndef POST_CLEAN_TASK_H
#define POST_CLEAN_TASK_H


class PostCleanTask {
public:
    virtual ~PostCleanTask() = 0;
    virtual void postClean() = 0;
};


#endif