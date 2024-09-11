#ifndef PACKAGE_SUCCESS_EVENT_H
#define PACKAGE_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PackageSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    PackageSuccessEvent() {
        this->addInterface("PackageSuccessEvent");
    }
    virtual ~PackageSuccessEvent() = 0;
    virtual int onPackageSuccess() = 0;
};


#endif