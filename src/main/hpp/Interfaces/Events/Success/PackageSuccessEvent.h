#ifndef PACKAGE_SUCCESS_EVENT_H
#define PACKAGE_SUCCESS_EVENT_H


class PackageSuccessEvent {
public:
    virtual ~PackageSuccessEvent() = 0;
    virtual int onPackageSuccess() = 0;
};


#endif