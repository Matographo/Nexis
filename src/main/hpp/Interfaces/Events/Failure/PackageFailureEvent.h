#ifndef PACKAGE_FAILURE_EVENT_H
#define PACKAGE_FAILURE_EVENT_H


class PackageFailureEvent {
public:
    virtual ~PackageFailureEvent() = 0;
    virtual void onPackageFailure() = 0;
};


#endif