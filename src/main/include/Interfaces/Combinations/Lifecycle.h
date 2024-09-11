#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "ValidateTask.h"
#include "CompileTask.h"
#include "PackageTask.h"
#include "DeployTask.h"
#include "TestTask.h"

class Lifecycle : public ValidateTask, public CompileTask, public PackageTask, public DeployTask, public TestTask {
public:
    virtual ~Lifecycle() = 0;
};

#endif