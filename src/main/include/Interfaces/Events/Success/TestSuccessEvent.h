#ifndef TEST_SUCCESS_EVENT_H
#define TEST_SUCCESS_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class TestSuccessEvent : public virtual NexisInterfaceRegistry {
public:
    TestSuccessEvent() {
        this->addInterface("TestSuccessEvent");
    }
    virtual ~TestSuccessEvent() = 0;
    virtual int onTestSuccess() = 0;
};


#endif