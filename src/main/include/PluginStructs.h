#ifndef PLUGIN_STRUCTS_H
#define PLUGIN_STRUCTS_H

#include <vector>

#include "Interfaces/Events/Before/BeforeBuildTask.h"
#include "Interfaces/Events/After/AfterBuildTask.h"

#include "Interfaces/Lifecycles/CleanTask.h"
#include "Interfaces/Events/Before/BeforeCleanTask.h"
#include "Interfaces/Events/After/AfterCleanTask.h"
#include "Interfaces/Events/Success/CleanSuccessEvent.h"
#include "Interfaces/Events/Failure/CleanFailureEvent.h"
#include "Interfaces/Lifecycles/PreCleanTask.h"
#include "Interfaces/Lifecycles/PostCleanTask.h"

#include "Interfaces/Lifecycles/CompileTask.h"
#include "Interfaces/Events/Before/BeforeCompileTask.h"
#include "Interfaces/Events/After/AfterCompileTask.h"
#include "Interfaces/Events/Success/CompileSuccessEvent.h"
#include "Interfaces/Events/Failure/CompileFailureEvent.h"
#include "Interfaces/Lifecycles/PreCompileTask.h"
#include "Interfaces/Lifecycles/PostCompileTask.h"

#include "Interfaces/Lifecycles/TestTask.h"
#include "Interfaces/Events/Before/BeforeTestTask.h"
#include "Interfaces/Events/After/AfterTestTask.h"
#include "Interfaces/Events/Success/TestSuccessEvent.h"
#include "Interfaces/Events/Failure/TestFailureEvent.h"
#include "Interfaces/Lifecycles/PreTestTask.h"
#include "Interfaces/Lifecycles/PostTestTask.h"

#include "Interfaces/Lifecycles/PackageTask.h"
#include "Interfaces/Events/Before/BeforePackageTask.h"
#include "Interfaces/Events/After/AfterPackageTask.h"
#include "Interfaces/Events/Success/PackageSuccessEvent.h"
#include "Interfaces/Events/Failure/PackageFailureEvent.h"
#include "Interfaces/Lifecycles/PrePackageTask.h"
#include "Interfaces/Lifecycles/PostPackageTask.h"

#include "Interfaces/Lifecycles/DeployTask.h"
#include "Interfaces/Events/Before/BeforeDeployTask.h"
#include "Interfaces/Events/After/AfterDeployTask.h"
#include "Interfaces/Events/Success/DeploySuccessEvent.h"
#include "Interfaces/Events/Failure/DeployFailureEvent.h"
#include "Interfaces/Lifecycles/PreDeployTask.h"
#include "Interfaces/Lifecycles/PostDeployTask.h"

#include "Interfaces/Lifecycles/RunTask.h"
#include "Interfaces/Events/Before/BeforeRunTask.h"
#include "Interfaces/Events/After/AfterRunTask.h"
#include "Interfaces/Events/Success/RunSuccessEvent.h"
#include "Interfaces/Events/Failure/RunFailureEvent.h"
#include "Interfaces/Lifecycles/PreRunTask.h"
#include "Interfaces/Lifecycles/PostRunTask.h"

#include "Interfaces/Lifecycles/ValidateTask.h"
#include "Interfaces/Events/Before/BeforeValidateTask.h"
#include "Interfaces/Events/After/AfterValidateTask.h"
#include "Interfaces/Events/Success/ValidateSuccessEvent.h"
#include "Interfaces/Events/Failure/ValidateFailureEvent.h"
#include "Interfaces/Lifecycles/PreValidateTask.h"
#include "Interfaces/Lifecycles/PostValidateTask.h"


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

struct BuildTasks {
    std::vector<BeforeBuildTask*> beforeBuildTask;
    std::vector<AfterBuildTask*> afterBuildTask;
};

struct PluginStruct {
    BuildTasks buildTasks;
    CleanTasks cleanTasks;
    ValidateTasks validateTasks;
    CompileTasks compileTasks;
    TestTasks testTasks;
    PackageTasks packageTasks;
    DeployTasks deployTasks;
    RunTasks runTasks;
};



#endif