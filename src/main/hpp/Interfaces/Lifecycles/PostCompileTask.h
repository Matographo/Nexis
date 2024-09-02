#ifndef POST_COMPILE_TASK_H
#define POST_COMPILE_TASK_H


class PostCompileTask {
public:
    virtual ~PostCompileTask() = 0;
    virtual int postCompile() = 0;
};


#endif