#ifndef PRE_TEST_TASK_H
#define PRE_TEST_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PreTestTask : public virtual NexisInterfaceRegistry {
public:
    PreTestTask() {
        this->addInterface("PreTestTask");
    }
    virtual ~PreTestTask() = 0;
    virtual int preTest() = 0;
};


#endif