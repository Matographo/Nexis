#ifndef POST_TEST_TASK_H
#define POST_TEST_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostTestTask : public virtual NexisInterfaceRegistry {
public:
    PostTestTask() {
        this->addInterface("PostTestTask");
    }
    virtual ~PostTestTask() = 0;
    virtual int postTest() = 0;
};


#endif