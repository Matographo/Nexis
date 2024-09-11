#ifndef PACKAGE_FAILURE_EVENT_H
#define PACKAGE_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PackageFailureEvent : public virtual NexisInterfaceRegistry {
public:
    PackageFailureEvent() {
        this->addInterface("PackageFailureEvent");
    }
    virtual ~PackageFailureEvent() = 0;
    virtual int onPackageFailure() = 0;
};


#endif