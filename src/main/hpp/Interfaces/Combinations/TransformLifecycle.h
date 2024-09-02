#ifndef TRANSFORM_LIFECYCLE_H
#define TRANSFORM_LIFECYCLE_H

#include "ValidateTask.h"
#include "CompileTask.h"

class TransformLifecycle : public ValidateTask, public CompileTask {
public:
    ~TransformLifecycle();
};

#endif