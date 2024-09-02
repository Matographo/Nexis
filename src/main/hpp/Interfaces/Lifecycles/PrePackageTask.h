#ifndef PRE_PACKAGE_TASK_H
#define PRE_PACKAGE_TASK_H


class PrePackageTask {
public:
    virtual ~PrePackageTask() = 0;
    virtual void prePackage() = 0;
};


#endif