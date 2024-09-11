#ifndef PRE_PACKAGE_TASK_H
#define PRE_PACKAGE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PrePackageTask : public virtual NexisInterfaceRegistry {
public:
    PrePackageTask() {
        this->addInterface("PrePackageTask");
    }
    virtual ~PrePackageTask() = 0;
    virtual int prePackage() = 0;
};


#endif