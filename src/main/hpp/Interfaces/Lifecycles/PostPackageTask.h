#ifndef POST_PACKAGE_TASK_H
#define POST_PACKAGE_TASK_H


class PostPackageTask {
public:
    virtual ~PostPackageTask() = 0;
    virtual void postPackage() = 0;
};


#endif