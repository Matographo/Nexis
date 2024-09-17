#include "PluginCaster.h"

PluginCaster::PluginCaster(nexis::NexisLogger * logger, PluginStruct* pluginStruct) {
    this->logger = logger;
    this->pluginStruct = pluginStruct;
    this->setPluginStruct();
}


void PluginCaster::setPluginStruct() {
    this->pluginCasts["BeforeBuildTask"] = &PluginCaster::castToBeforeBuildTask;
    this->pluginCasts["BeforeCleanTask"] = &PluginCaster::castToBeforeCleanTask;
    this->pluginCasts["BeforeCompileTask"] = &PluginCaster::castToBeforeCompileTask;
    this->pluginCasts["BeforeDeployTask"] = &PluginCaster::castToBeforeDeployTask;
    this->pluginCasts["BeforePackageTask"] = &PluginCaster::castToBeforePackageTask;
    this->pluginCasts["BeforeRunTask"] = &PluginCaster::castToBeforeRunTask;
    this->pluginCasts["BeforeTestTask"] = &PluginCaster::castToBeforeTestTask;
    this->pluginCasts["BeforeValidateTask"] = &PluginCaster::castToBeforeValidateTask;
    this->pluginCasts["AfterBuildTask"] = &PluginCaster::castToAfterBuildTask;
    this->pluginCasts["AfterCleanTask"] = &PluginCaster::castToAfterCleanTask;
    this->pluginCasts["AfterCompileTask"] = &PluginCaster::castToAfterCompileTask;
    this->pluginCasts["AfterDeployTask"] = &PluginCaster::castToAfterDeployTask;
    this->pluginCasts["AfterPackageTask"] = &PluginCaster::castToAfterPackageTask;
    this->pluginCasts["AfterRunTask"] = &PluginCaster::castToAfterRunTask;
    this->pluginCasts["AfterTestTask"] = &PluginCaster::castToAfterTestTask;
    this->pluginCasts["AfterValidateTask"] = &PluginCaster::castToAfterValidateTask;
    this->pluginCasts["CleanSuccessEvent"] = &PluginCaster::castToCleanSuccessEvent;
    this->pluginCasts["CompileSuccessEvent"] = &PluginCaster::castToCompileSuccessEvent;
    this->pluginCasts["DeploySuccessEvent"] = &PluginCaster::castToDeploySuccessEvent;
    this->pluginCasts["PackageSuccessEvent"] = &PluginCaster::castToPackageSuccessEvent;
    this->pluginCasts["RunSuccessEvent"] = &PluginCaster::castToRunSuccessEvent;
    this->pluginCasts["TestSuccessEvent"] = &PluginCaster::castToTestSuccessEvent;
    this->pluginCasts["ValidateSuccessEvent"] = &PluginCaster::castToValidateSuccessEvent;
    this->pluginCasts["CleanFailureEvent"] = &PluginCaster::castToCleanFailureEvent;
    this->pluginCasts["CompileFailureEvent"] = &PluginCaster::castToCompileFailureEvent;
    this->pluginCasts["DeployFailureEvent"] = &PluginCaster::castToDeployFailureEvent;
    this->pluginCasts["PackageFailureEvent"] = &PluginCaster::castToPackageFailureEvent;
    this->pluginCasts["RunFailureEvent"] = &PluginCaster::castToRunFailureEvent;
    this->pluginCasts["TestFailureEvent"] = &PluginCaster::castToTestFailureEvent;
    this->pluginCasts["ValidateFailureEvent"] = &PluginCaster::castToValidateFailureEvent;
    this->pluginCasts["PreCleanTask"] = &PluginCaster::castToPreCleanTask;
    this->pluginCasts["PreCompileTask"] = &PluginCaster::castToPreCompileTask;
    this->pluginCasts["PreDeployTask"] = &PluginCaster::castToPreDeployTask;
    this->pluginCasts["PrePackageTask"] = &PluginCaster::castToPrePackageTask;
    this->pluginCasts["PreRunTask"] = &PluginCaster::castToPreRunTask;
    this->pluginCasts["PreTestTask"] = &PluginCaster::castToPreTestTask;
    this->pluginCasts["PreValidateTask"] = &PluginCaster::castToPreValidateTask;
    this->pluginCasts["PostCleanTask"] = &PluginCaster::castToPostCleanTask;
    this->pluginCasts["PostCompileTask"] = &PluginCaster::castToPostCompileTask;
    this->pluginCasts["PostDeployTask"] = &PluginCaster::castToPostDeployTask;
    this->pluginCasts["PostPackageTask"] = &PluginCaster::castToPostPackageTask;
    this->pluginCasts["PostRunTask"] = &PluginCaster::castToPostRunTask;
    this->pluginCasts["PostTestTask"] = &PluginCaster::castToPostTestTask;
    this->pluginCasts["PostValidateTask"] = &PluginCaster::castToPostValidateTask;
    this->pluginCasts["CleanTask"] = &PluginCaster::castToCleanTask;
    this->pluginCasts["CompileTask"] = &PluginCaster::castToCompileTask;
    this->pluginCasts["DeployTask"] = &PluginCaster::castToDeployTask;
    this->pluginCasts["PackageTask"] = &PluginCaster::castToPackageTask;
    this->pluginCasts["RunTask"] = &PluginCaster::castToRunTask;
    this->pluginCasts["TestTask"] = &PluginCaster::castToTestTask;
    this->pluginCasts["ValidateTask"] = &PluginCaster::castToValidateTask;
}

int PluginCaster::castToBeforeBuildTask(NexisPlugin* plugin) {
    BeforeBuildTask* task = dynamic_cast<BeforeBuildTask*>(plugin);
    this->pluginStruct->buildTasks.beforeBuildTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeCleanTask(NexisPlugin* plugin) {
    BeforeCleanTask* task = dynamic_cast<BeforeCleanTask*>(plugin);
    this->pluginStruct->cleanTasks.beforeCleanTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeCompileTask(NexisPlugin* plugin) {
    BeforeCompileTask* task = dynamic_cast<BeforeCompileTask*>(plugin);
    this->pluginStruct->compileTasks.beforeCompileTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeDeployTask(NexisPlugin* plugin) {
    BeforeDeployTask* task = dynamic_cast<BeforeDeployTask*>(plugin);
    this->pluginStruct->deployTasks.beforeDeployTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforePackageTask(NexisPlugin* plugin) {
    BeforePackageTask* task = dynamic_cast<BeforePackageTask*>(plugin);
    this->pluginStruct->packageTasks.beforePackageTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeRunTask(NexisPlugin* plugin) {
    BeforeRunTask* task = dynamic_cast<BeforeRunTask*>(plugin);
    this->pluginStruct->runTasks.beforeRunTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeTestTask(NexisPlugin* plugin) {
    BeforeTestTask* task = dynamic_cast<BeforeTestTask*>(plugin);
    this->pluginStruct->testTasks.beforeTestTask.push_back(task);
    return 0;
}

int PluginCaster::castToBeforeValidateTask(NexisPlugin* plugin) {
    BeforeValidateTask* task = dynamic_cast<BeforeValidateTask*>(plugin);
    this->pluginStruct->validateTasks.beforeValidateTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterBuildTask(NexisPlugin* plugin) {
    AfterBuildTask* task = dynamic_cast<AfterBuildTask*>(plugin);
    this->pluginStruct->buildTasks.afterBuildTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterCleanTask(NexisPlugin* plugin) {
    AfterCleanTask* task = dynamic_cast<AfterCleanTask*>(plugin);
    this->pluginStruct->cleanTasks.afterCleanTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterCompileTask(NexisPlugin* plugin) {
    AfterCompileTask* task = dynamic_cast<AfterCompileTask*>(plugin);
    this->pluginStruct->compileTasks.afterCompileTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterDeployTask(NexisPlugin* plugin) {
    AfterDeployTask* task = dynamic_cast<AfterDeployTask*>(plugin);
    this->pluginStruct->deployTasks.afterDeployTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterPackageTask(NexisPlugin* plugin) {
    AfterPackageTask* task = dynamic_cast<AfterPackageTask*>(plugin);
    this->pluginStruct->packageTasks.afterPackageTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterRunTask(NexisPlugin* plugin) {
    AfterRunTask* task = dynamic_cast<AfterRunTask*>(plugin);
    this->pluginStruct->runTasks.afterRunTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterTestTask(NexisPlugin* plugin) {
    AfterTestTask* task = dynamic_cast<AfterTestTask*>(plugin);
    this->pluginStruct->testTasks.afterTestTask.push_back(task);
    return 0;
}

int PluginCaster::castToAfterValidateTask(NexisPlugin* plugin) {
    AfterValidateTask* task = dynamic_cast<AfterValidateTask*>(plugin);
    this->pluginStruct->validateTasks.afterValidateTask.push_back(task);
    return 0;
}

int PluginCaster::castToCleanSuccessEvent(NexisPlugin* plugin) {
    CleanSuccessEvent* task = dynamic_cast<CleanSuccessEvent*>(plugin);
    this->pluginStruct->cleanTasks.cleanSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToCompileSuccessEvent(NexisPlugin* plugin) {
    CompileSuccessEvent* task = dynamic_cast<CompileSuccessEvent*>(plugin);
    this->pluginStruct->compileTasks.compileSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToDeploySuccessEvent(NexisPlugin* plugin) {
    DeploySuccessEvent* task = dynamic_cast<DeploySuccessEvent*>(plugin);
    this->pluginStruct->deployTasks.deploySuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToPackageSuccessEvent(NexisPlugin* plugin) {
    PackageSuccessEvent* task = dynamic_cast<PackageSuccessEvent*>(plugin);
    this->pluginStruct->packageTasks.packageSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToRunSuccessEvent(NexisPlugin* plugin) {
    RunSuccessEvent* task = dynamic_cast<RunSuccessEvent*>(plugin);
    this->pluginStruct->runTasks.runSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToTestSuccessEvent(NexisPlugin* plugin) {
    TestSuccessEvent* task = dynamic_cast<TestSuccessEvent*>(plugin);
    this->pluginStruct->testTasks.testSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToValidateSuccessEvent(NexisPlugin* plugin) {
    ValidateSuccessEvent* task = dynamic_cast<ValidateSuccessEvent*>(plugin);
    this->pluginStruct->validateTasks.validateSuccessEvent.push_back(task);
    return 0;
}

int PluginCaster::castToCleanFailureEvent(NexisPlugin* plugin) {
    CleanFailureEvent* task = dynamic_cast<CleanFailureEvent*>(plugin);
    this->pluginStruct->cleanTasks.cleanFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToCompileFailureEvent(NexisPlugin* plugin) {
    CompileFailureEvent* task = dynamic_cast<CompileFailureEvent*>(plugin);
    this->pluginStruct->compileTasks.compileFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToDeployFailureEvent(NexisPlugin* plugin) {
    DeployFailureEvent* task = dynamic_cast<DeployFailureEvent*>(plugin);
    this->pluginStruct->deployTasks.deployFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToPackageFailureEvent(NexisPlugin* plugin) {
    PackageFailureEvent* task = dynamic_cast<PackageFailureEvent*>(plugin);
    this->pluginStruct->packageTasks.packageFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToRunFailureEvent(NexisPlugin* plugin) {
    RunFailureEvent* task = dynamic_cast<RunFailureEvent*>(plugin);
    this->pluginStruct->runTasks.runFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToTestFailureEvent(NexisPlugin* plugin) {
    TestFailureEvent* task = dynamic_cast<TestFailureEvent*>(plugin);
    this->pluginStruct->testTasks.testFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToValidateFailureEvent(NexisPlugin* plugin) {
    ValidateFailureEvent* task = dynamic_cast<ValidateFailureEvent*>(plugin);
    this->pluginStruct->validateTasks.validateFailureEvent.push_back(task);
    return 0;
}

int PluginCaster::castToPreCleanTask(NexisPlugin* plugin) {
    PreCleanTask* task = dynamic_cast<PreCleanTask*>(plugin);
    this->pluginStruct->cleanTasks.preCleanTask.push_back(task);
    return 0;
}

int PluginCaster::castToPreCompileTask(NexisPlugin* plugin) {
    PreCompileTask* task = dynamic_cast<PreCompileTask*>(plugin);
    this->pluginStruct->compileTasks.preCompileTask.push_back(task);
    return 0;
}

int PluginCaster::castToPreDeployTask(NexisPlugin* plugin) {
    PreDeployTask* task = dynamic_cast<PreDeployTask*>(plugin);
    this->pluginStruct->deployTasks.preDeployTask.push_back(task);
    return 0;
}

int PluginCaster::castToPrePackageTask(NexisPlugin* plugin) {
    PrePackageTask* task = dynamic_cast<PrePackageTask*>(plugin);
    this->pluginStruct->packageTasks.prePackageTask.push_back(task);
    return 0;
}

int PluginCaster::castToPreRunTask(NexisPlugin* plugin) {
    PreRunTask* task = dynamic_cast<PreRunTask*>(plugin);
    this->pluginStruct->runTasks.preRunTask.push_back(task);
    return 0;
}

int PluginCaster::castToPreTestTask(NexisPlugin* plugin) {
    PreTestTask* task = dynamic_cast<PreTestTask*>(plugin);
    this->pluginStruct->testTasks.preTestTask.push_back(task);
    return 0;
}

int PluginCaster::castToPreValidateTask(NexisPlugin* plugin) {
    PreValidateTask* task = dynamic_cast<PreValidateTask*>(plugin);
    this->pluginStruct->validateTasks.preValidateTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostCleanTask(NexisPlugin* plugin) {
    PostCleanTask* task = dynamic_cast<PostCleanTask*>(plugin);
    this->pluginStruct->cleanTasks.postCleanTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostCompileTask(NexisPlugin* plugin) {
    PostCompileTask* task = dynamic_cast<PostCompileTask*>(plugin);
    this->pluginStruct->compileTasks.postCompileTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostDeployTask(NexisPlugin* plugin) {
    PostDeployTask* task = dynamic_cast<PostDeployTask*>(plugin);
    this->pluginStruct->deployTasks.postDeployTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostPackageTask(NexisPlugin* plugin) {
    PostPackageTask* task = dynamic_cast<PostPackageTask*>(plugin);
    this->pluginStruct->packageTasks.postPackageTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostRunTask(NexisPlugin* plugin) {
    PostRunTask* task = dynamic_cast<PostRunTask*>(plugin);
    this->pluginStruct->runTasks.postRunTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostTestTask(NexisPlugin* plugin) {
    PostTestTask* task = dynamic_cast<PostTestTask*>(plugin);
    this->pluginStruct->testTasks.postTestTask.push_back(task);
    return 0;
}

int PluginCaster::castToPostValidateTask(NexisPlugin* plugin) {
    PostValidateTask* task = dynamic_cast<PostValidateTask*>(plugin);
    this->pluginStruct->validateTasks.postValidateTask.push_back(task);
    return 0;
}

int PluginCaster::castToCleanTask(NexisPlugin* plugin) {
    CleanTask* task = dynamic_cast<CleanTask*>(plugin);
    this->pluginStruct->cleanTasks.cleanTask.push_back(task);
    return 0;
}

int PluginCaster::castToCompileTask(NexisPlugin* plugin) {
    CompileTask* task = dynamic_cast<CompileTask*>(plugin);
    this->pluginStruct->compileTasks.compileTask.push_back(task);
    return 0;
}

int PluginCaster::castToDeployTask(NexisPlugin* plugin) {
    DeployTask* task = dynamic_cast<DeployTask*>(plugin);
    this->pluginStruct->deployTasks.deployTask.push_back(task);
    return 0;
}

int PluginCaster::castToPackageTask(NexisPlugin* plugin) {
    PackageTask* task = dynamic_cast<PackageTask*>(plugin);
    this->pluginStruct->packageTasks.packageTask.push_back(task);
    return 0;
}

int PluginCaster::castToRunTask(NexisPlugin* plugin) {
    RunTask* task = dynamic_cast<RunTask*>(plugin);
    this->pluginStruct->runTasks.runTask.push_back(task);
    return 0;
}

int PluginCaster::castToTestTask(NexisPlugin* plugin) {
    TestTask* task = dynamic_cast<TestTask*>(plugin);
    this->pluginStruct->testTasks.testTask.push_back(task);
    return 0;
}

int PluginCaster::castToValidateTask(NexisPlugin* plugin) {
    ValidateTask* task = dynamic_cast<ValidateTask*>(plugin);
    this->pluginStruct->validateTasks.validateTask.push_back(task);
    return 0;
}

int PluginCaster::castPlugin(NexisPlugin* plugin) {
    if(!logger) {
        return 1;
    }

    if(!pluginStruct) {
        logger->err("PluginStruct is null");
        logger->err("Cannot cast plugin");
        return 1;
    }

    if (plugin == nullptr) {
        logger->err("Plugin is null");
        logger->err("Cannot cast plugin");
        return 1;
    }
    
    std::set<std::string> pluginRegister = plugin->getInterfaces();
    for(std::string interface : pluginRegister) {
        if(this->pluginCasts.find(interface) == this->pluginCasts.end()) {
            continue;
        }
        auto pluginCast = this->pluginCasts[interface];

        logger->trace("Casting plugin to " + interface);
        int result = (this->*pluginCast)(plugin);
        if(result != 0) {
            logger->err("Failed to cast plugin to " + interface);
            return 1;
        }
    }
    
    return 0;
}