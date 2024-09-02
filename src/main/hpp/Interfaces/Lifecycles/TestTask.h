#ifndef TEST_TASK_H
#define TEST_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class TestTask : public virtual NexisInterfaceRegistry {
public:
    TestTask() {
        this->addInterface("TestTask");
    }
    virtual ~TestTask() = 0;
    virtual int test() = 0;
};


#endif