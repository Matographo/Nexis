#ifndef AFTER_PACKAGE_TASK_H
#define AFTER_PACKAGE_TASK_H


class AfterPackageTask {
public:
    virtual ~AfterPackageTask() = 0;
    virtual void afterPackage() = 0;
};


#endif