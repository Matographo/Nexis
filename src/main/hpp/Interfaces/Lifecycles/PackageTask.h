#ifndef PACKAGE_TASK_H
#define PACKAGE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PackageTask : public virtual NexisInterfaceRegistry {
public:
    PackageTask() {
        this->addInterface("PackageTask");
    }
    virtual ~PackageTask() = 0;
    virtual int package() = 0;
};


#endif