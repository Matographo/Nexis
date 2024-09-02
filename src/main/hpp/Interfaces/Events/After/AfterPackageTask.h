#ifndef AFTER_PACKAGE_TASK_H
#define AFTER_PACKAGE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterPackageTask : public virtual NexisInterfaceRegistry {
public:
    AfterPackageTask() {
        this->addInterface("AfterPackageTask");
    }
    virtual ~AfterPackageTask() = 0;
    virtual int afterPackage() = 0;
};


#endif