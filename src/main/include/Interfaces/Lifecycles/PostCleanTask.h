#ifndef POST_CLEAN_TASK_H
#define POST_CLEAN_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostCleanTask : public virtual NexisInterfaceRegistry {
public:
    PostCleanTask() {
        this->addInterface("PostCleanTask");
    }
    virtual ~PostCleanTask() = 0;
    virtual int postClean() = 0;
};


#endif