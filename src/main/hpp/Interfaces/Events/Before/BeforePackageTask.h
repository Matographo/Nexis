#ifndef BEFORE_PACKAGE_TASK_H
#define BEFORE_PACKAGE_TASK_H


class BeforePackageTask {
public:
    virtual ~BeforePackageTask() = 0;
    virtual void beforePackage() = 0;
};


#endif