#ifndef AFTER_TEST_TASK_H
#define AFTER_TEST_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class AfterTestTask : public virtual NexisInterfaceRegistry {
public:
    AfterTestTask() {
        this->addInterface("AfterTestTask");
    }
    virtual ~AfterTestTask() = 0;
    virtual int afterTest() = 0;
};


#endif