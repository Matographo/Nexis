#ifndef PACKAGE_SUCCESS_EVENT_H
#define PACKAGE_SUCCESS_EVENT_H


class PackageSuccessEvent {
public:
    virtual ~PackageSuccessEvent() = 0;
    virtual void onPackageSuccess() = 0;
};


#endif