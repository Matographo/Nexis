#ifndef PLUGIN_STRUCTS_H
#define PLUGIN_STRUCTS_H

#include <vector>

#include "CleanTask.h"
#include "BeforeCleanTask.h"
#include "AfterCleanTask.h"
#include "CleanSuccessEvent.h"
#include "CleanFailureEvent.h"
#include "PreCleanTask.h"
#include "PostCleanTask.h"

#include "CompileTask.h"
#include "BeforeCompileTask.h"
#include "AfterCompileTask.h"
#include "CompileSuccessEvent.h"
#include "CompileFailureEvent.h"
#include "PreCompileTask.h"
#include "PostCompileTask.h"

#include "TestTask.h"
#include "BeforeTestTask.h"
#include "AfterTestTask.h"
#include "TestSuccessEvent.h"
#include "TestFailureEvent.h"
#include "PreTestTask.h"
#include "PostTestTask.h"

#include "PackageTask.h"
#include "BeforePackageTask.h"
#include "AfterPackageTask.h"
#include "PackageSuccessEvent.h"
#include "PackageFailureEvent.h"
#include "PrePackageTask.h"
#include "PostPackageTask.h"

#include "DeployTask.h"
#include "BeforeDeployTask.h"
#include "AfterDeployTask.h"
#include "DeploySuccessEvent.h"
#include "DeployFailureEvent.h"
#include "PreDeployTask.h"
#include "PostDeployTask.h"

#include "RunTask.h"
#include "BeforeRunTask.h"
#include "AfterRunTask.h"
#include "RunSuccessEvent.h"
#include "RunFailureEvent.h"
#include "PreRunTask.h"
#include "PostRunTask.h"

#include "ValidateTask.h"
#include "BeforeValidateTask.h"
#include "AfterValidateTask.h"
#include "ValidateSuccessEvent.h"
#include "ValidateFailureEvent.h"
#include "PreValidateTask.h"
#include "PostValidateTask.h"


struct CleanTasks {
    std::vector<CleanTask*> cleanTask;
    std::vector<BeforeCleanTask*> beforeCleanTask;
    std::vector<AfterCleanTask*> afterCleanTask;
    std::vector<CleanSuccessEvent*> cleanSuccessEvent;
    std::vector<CleanFailureEvent*> cleanFailureEvent;
    std::vector<PreCleanTask*> preCleanTask;
    std::vector<PostCleanTask*> postCleanTask;
};

struct CompileTasks {
    std::vector<CompileTask*> compileTask;
    std::vector<BeforeCompileTask*> beforeCompileTask;
    std::vector<AfterCompileTask*> afterCompileTask;
    std::vector<CompileSuccessEvent*> compileSuccessEvent;
    std::vector<CompileFailureEvent*> compileFailureEvent;
    std::vector<PreCompileTask*> preCompileTask;
    std::vector<PostCompileTask*> postCompileTask;
};

struct TestTasks {
    std::vector<TestTask*> testTask;
    std::vector<BeforeTestTask*> beforeTestTask;
    std::vector<AfterTestTask*> afterTestTask;
    std::vector<TestSuccessEvent*> testSuccessEvent;
    std::vector<TestFailureEvent*> testFailureEvent;
    std::vector<PreTestTask*> preTestTask;
    std::vector<PostTestTask*> postTestTask;
};

struct PackageTasks {
    std::vector<PackageTask*> packageTask;
    std::vector<BeforePackageTask*> beforePackageTask;
    std::vector<AfterPackageTask*> afterPackageTask;
    std::vector<PackageSuccessEvent*> packageSuccessEvent;
    std::vector<PackageFailureEvent*> packageFailureEvent;
    std::vector<PrePackageTask*> prePackageTask;
    std::vector<PostPackageTask*> postPackageTask;
};

struct DeployTasks {
    std::vector<DeployTask*> deployTask;
    std::vector<BeforeDeployTask*> beforeDeployTask;
    std::vector<AfterDeployTask*> afterDeployTask;
    std::vector<DeploySuccessEvent*> deploySuccessEvent;
    std::vector<DeployFailureEvent*> deployFailureEvent;
    std::vector<PreDeployTask*> preDeployTask;
    std::vector<PostDeployTask*> postDeployTask;
};

struct RunTasks {
    std::vector<RunTask*> runTask;
    std::vector<BeforeRunTask*> beforeRunTask;
    std::vector<AfterRunTask*> afterRunTask;
    std::vector<RunSuccessEvent*> runSuccessEvent;
    std::vector<RunFailureEvent*> runFailureEvent;
    std::vector<PreRunTask*> preRunTask;
    std::vector<PostRunTask*> postRunTask;
};

struct ValidateTasks {
    std::vector<ValidateTask*> validateTask;
    std::vector<BeforeValidateTask*> beforeValidateTask;
    std::vector<AfterValidateTask*> afterValidateTask;
    std::vector<ValidateSuccessEvent*> validateSuccessEvent;
    std::vector<ValidateFailureEvent*> validateFailureEvent;
    std::vector<PreValidateTask*> preValidateTask;
    std::vector<PostValidateTask*> postValidateTask;
};

struct PluginStruct {
    CleanTasks cleanTasks;
    ValidateTasks validateTasks;
    CompileTasks compileTasks;
    TestTasks testTasks;
    PackageTasks packageTasks;
    DeployTasks deployTasks;
    RunTasks runTasks;
};



#endif