#ifndef POST_RUN_TASK_H
#define POST_RUN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostRunTask : public virtual NexisInterfaceRegistry {
public:
    PostRunTask() {
        this->addInterface("PostRunTask");
    }
    virtual ~PostRunTask() = 0;
    virtual int postRun() = 0;
};


#endif