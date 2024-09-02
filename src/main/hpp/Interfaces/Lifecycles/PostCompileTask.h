#ifndef POST_COMPILE_TASK_H
#define POST_COMPILE_TASK_H

#include "Interfaces/NexisInterfaceRegistry.h"

class PostCompileTask : public virtual NexisInterfaceRegistry {
public:
    PostCompileTask() {
        this->addInterface("PostCompileTask");
    }
    virtual ~PostCompileTask() = 0;
    virtual int postCompile() = 0;
};


#endif