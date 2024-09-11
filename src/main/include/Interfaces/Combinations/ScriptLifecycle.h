#ifndef SCRIPT_LIFECYCLE_H
#define SCRIPT_LIFECYCLE_H

#include "ValidateTask.h"
#include "TestTask.h"

class ScriptLifecycle : public ValidateTask, public TestTask {
public:
    virtual ~ScriptLifecycle() = 0;
};

#endif