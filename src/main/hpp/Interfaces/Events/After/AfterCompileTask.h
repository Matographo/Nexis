#ifndef AFTER_COMPILE_TASK_H
#define AFTER_COMPILE_TASK_H


class AfterCompileTask {
public:
    virtual ~AfterCompileTask() = 0;
    virtual void afterCompile() = 0;
};


#endif