#ifndef POST_PACKAGE_TASK_H
#define POST_PACKAGE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostPackageTask {
public:
    virtual ~PostPackageTask() = 0;
    virtual int postPackage() = 0;
};


#endif