#ifndef BEFORE_TEST_TASK_H
#define BEFORE_TEST_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class BeforeTestTask : public virtual NexisInterfaceRegistry {
public:
    BeforeTestTask() {
        this->addInterface("BeforeTestTask");
    }
    virtual ~BeforeTestTask() = 0;
    virtual int beforeTest() = 0;
};


#endif