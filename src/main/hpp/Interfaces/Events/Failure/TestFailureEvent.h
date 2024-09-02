#ifndef TEST_FAILURE_EVENT_H
#define TEST_FAILURE_EVENT_H

#include "Interfaces/NexisInterfaceRegistry.h"

class TestFailureEvent : public virtual NexisInterfaceRegistry {
public:
    TestFailureEvent() {
        this->addInterface("TestFailureEvent");
    }
    virtual ~TestFailureEvent() = 0;
    virtual int onTestFailure() = 0;
};


#endif