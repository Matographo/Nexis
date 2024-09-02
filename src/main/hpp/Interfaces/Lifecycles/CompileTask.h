#ifndef COMPILE_TASK_H
#define COMPILE_TASK_H


class CompileTask {
public:
    virtual ~CompileTask() = 0;
    virtual void compile() = 0;
};


#endif