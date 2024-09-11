#ifndef BEFORE_PACKAGE_TASK_H
#define BEFORE_PACKAGE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforePackageTask : public virtual NexisInterfaceRegistry {
public:
    BeforePackageTask() {
        this->addInterface("BeforePackageTask");
    }
    virtual ~BeforePackageTask() = 0;
    virtual int beforePackage() = 0;
};


#endif