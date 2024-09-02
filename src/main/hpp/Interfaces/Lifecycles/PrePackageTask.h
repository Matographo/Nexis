#ifndef PRE_PACKAGE_TASK_H
#define PRE_PACKAGE_TASK_H


class PrePackageTask {
public:
    virtual ~PrePackageTask() = 0;
    virtual int prePackage() = 0;
};


#endif