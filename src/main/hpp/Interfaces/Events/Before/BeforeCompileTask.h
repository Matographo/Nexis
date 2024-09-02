#ifndef BEFORE_COMPILE_TASK_H
#define BEFORE_COMPILE_TASK_H


class BeforeCompileTask {
public:
    virtual ~BeforeCompileTask() = 0;
    virtual void beforeCompile() = 0;
};


#endif