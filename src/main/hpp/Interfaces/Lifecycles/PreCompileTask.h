#ifndef PRE_COMPILE_TASK_H
#define PRE_COMPILE_TASK_H


class PreCompileTask {
public:
    virtual ~PreCompileTask() = 0;
    virtual void preCompile() = 0;
};


#endif