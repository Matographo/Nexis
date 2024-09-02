#ifndef PACKAGE_TASK_H
#define PACKAGE_TASK_H


class PackageTask {
public:
    virtual ~PackageTask() = 0;
    virtual void package() = 0;
};


#endif