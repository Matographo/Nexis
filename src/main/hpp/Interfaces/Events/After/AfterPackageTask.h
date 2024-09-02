#ifndef AFTER_PACKAGE_TASK_H
#define AFTER_PACKAGE_TASK_H


class AfterPackageTask {
public:
    virtual ~AfterPackageTask() = 0;
    virtual int afterPackage() = 0;
};


#endif