#include "LifecycleExecuter.h"

LifecycleExecuter::LifecycleExecuter(PluginStruct *plugins, nexis::NexisLogger * logger) {
    this->plugins = *plugins;
    this->logger  = logger;
}

LifecycleExecuter::~LifecycleExecuter() {
}

int LifecycleExecuter::clean() {
    CleanTasks tasks = this->plugins.cleanTasks;
    
    for (BeforeCleanTask* task : tasks.beforeCleanTask) {
        if (task->beforeClean() != 0) return 1;
    }

    for (PreCleanTask* task : tasks.preCleanTask) {
        if (task->preClean() != 0) return 1;
    }
    
    for (CleanTask* task : tasks.cleanTask) {
        if (task->clean() != 0) {

            for (CleanFailureEvent* event : tasks.cleanFailureEvent) {
                event->onCleanFailure();
            }
            
            return 1;

        } else {

            for (CleanSuccessEvent* event : tasks.cleanSuccessEvent) {
                event->onCleanSuccess();
            }

        }
    }
    
    for (PostCleanTask* task : tasks.postCleanTask) {
        if (task->postClean() != 0) return 1;
    }

    for (AfterCleanTask* task : tasks.afterCleanTask) {
        if (task->afterClean() != 0) return 1;
    }


    return 0;
}

int LifecycleExecuter::run() {
    RunTasks tasks = this->plugins.runTasks;

    for (BeforeRunTask* task : tasks.beforeRunTask) {
        if (task->beforeRun() != 0) return 1;
    }

    for (PreRunTask* task : tasks.preRunTask) {
        if (task->preRun() != 0) return 1;
    }
    
    for (RunTask* task : tasks.runTask) {
        if (task->run() != 0) {
            
            for (RunFailureEvent* event : tasks.runFailureEvent) {
                event->onRunFailure();
            }

            return 1;

        } else {

            for (RunSuccessEvent* event : tasks.runSuccessEvent) {
                event->onRunSuccess();
            }
        }
    }

    for (PostRunTask* task : tasks.postRunTask) {
        if (task->postRun() != 0) return 1;
    }

    for (AfterRunTask* task : tasks.afterRunTask) {
        if (task->afterRun() != 0) return 1;
    }

    return 0;
}

int LifecycleExecuter::validate() {
    ValidateTasks tasks = this->plugins.validateTasks;

    for (BeforeValidateTask* task : tasks.beforeValidateTask) {
        if (task->beforeValidate() != 0) return 1;
    }

    for (PreValidateTask* task : tasks.preValidateTask) {
        if (task->preValidate() != 0) return 1;
    }

    for (ValidateTask* task : tasks.validateTask) {
        if (task->validate() != 0) {

            for (ValidateFailureEvent* event : tasks.validateFailureEvent) {
                event->onValidateFailure();
            }

            return 1;

        } else {

            for (ValidateSuccessEvent* event : tasks.validateSuccessEvent) {
                event->onValidateSuccess();
            }

        }
    }

    for (PostValidateTask* task : tasks.postValidateTask) {
        if (task->postValidate() != 0) return 1;
    }

    for (AfterValidateTask* task : tasks.afterValidateTask) {
        if (task->afterValidate() != 0) return 1;
    }

    return 0;
}

int LifecycleExecuter::compile() {
    CompileTasks tasks = this->plugins.compileTasks;

    for (BeforeCompileTask* task : tasks.beforeCompileTask) {
        if (task->beforeCompile() != 0) return 1;
    }

    for (PreCompileTask* task : tasks.preCompileTask) {
        if (task->preCompile() != 0) return 1;
    }

    for (CompileTask* task : tasks.compileTask) {
        if (task->compile() != 0) {

            for (CompileFailureEvent* event : tasks.compileFailureEvent) {
                event->onCompileFailure();
            }

            return 1;

        } else {

            for (CompileSuccessEvent* event : tasks.compileSuccessEvent) {
                event->onCompileSuccess();
            }

        }
    }

    for (PostCompileTask* task : tasks.postCompileTask) {
        if (task->postCompile() != 0) return 1;
    }

    for (AfterCompileTask* task : tasks.afterCompileTask) {
        if (task->afterCompile() != 0) return 1;
    }
    
    return 0;
}

int LifecycleExecuter::test() {
    TestTasks tasks = this->plugins.testTasks;

    for (BeforeTestTask* task : tasks.beforeTestTask) {
        if (task->beforeTest() != 0) return 1;
    }

    for (PreTestTask* task : tasks.preTestTask) {
        if (task->preTest() != 0) return 1;
    }

    for (TestTask* task : tasks.testTask) {
        if (task->test() != 0) {

            for (TestFailureEvent* event : tasks.testFailureEvent) {
                event->onTestFailure();
            }

            return 1;

        } else {

            for (TestSuccessEvent* event : tasks.testSuccessEvent) {
                event->onTestSuccess();
            }

        }
    }

    for (PostTestTask* task : tasks.postTestTask) {
        if (task->postTest() != 0) return 1;
    }

    for (AfterTestTask* task : tasks.afterTestTask) {
        if (task->afterTest() != 0) return 1;
    }
    return 0;
}

int LifecycleExecuter::package() {
    PackageTasks tasks = this->plugins.packageTasks;

    for (BeforePackageTask* task : tasks.beforePackageTask) {
        if (task->beforePackage() != 0) return 1;
    }

    for (PrePackageTask* task : tasks.prePackageTask) {
        if (task->prePackage() != 0) return 1;
    }

    for (PackageTask* task : tasks.packageTask) {
        if (task->package() != 0) {

            for (PackageFailureEvent* event : tasks.packageFailureEvent) {
                event->onPackageFailure();
            }

            return 1;

        } else {

            for (PackageSuccessEvent* event : tasks.packageSuccessEvent) {
                event->onPackageSuccess();
            }

        }
    }

    for (PostPackageTask* task : tasks.postPackageTask) {
        if (task->postPackage() != 0) return 1;
    }

    for (AfterPackageTask* task : tasks.afterPackageTask) {
        if (task->afterPackage() != 0) return 1;
    }

    return 0;
}

int LifecycleExecuter::deploy() {
    DeployTasks tasks = this->plugins.deployTasks;

    for (BeforeDeployTask* task : tasks.beforeDeployTask) {
        if (task->beforeDeploy() != 0) return 1;
    }

    for (PreDeployTask* task : tasks.preDeployTask) {
        if (task->preDeploy() != 0) return 1;
    }

    for (DeployTask* task : tasks.deployTask) {
        if (task->deploy() != 0) {

            for (DeployFailureEvent* event : tasks.deployFailureEvent) {
                event->onDeployFailure();
            }

            return 1;

        } else {

            for (DeploySuccessEvent* event : tasks.deploySuccessEvent) {
                event->onDeploySuccess();
            }

        }
    }

    for (PostDeployTask* task : tasks.postDeployTask) {
        if (task->postDeploy() != 0) return 1;
    }

    for (AfterDeployTask* task : tasks.afterDeployTask) {
        if (task->afterDeploy() != 0) return 1;
    }

    return 0;
}


int LifecycleExecuter::startLifecycle(int cycleTasks) {
    LifecycleTasks tasks = this->getLifecycleTasks(cycleTasks);

    std::vector<std::pair<bool, std::function<int()>>> taskList = {
        {tasks.clean,    [this]() { return this->clean(); }},
        {tasks.run,      [this]() { return this->run(); }},
        {tasks.validate, [this]() { return this->validate(); }},
        {tasks.compile,  [this]() { return this->compile(); }},
        {tasks.test,     [this]() { return this->test(); }},
        {tasks.package,  [this]() { return this->package(); }},
        {tasks.deploy,   [this]() { return this->deploy(); }}
    };

    this->logger->info("Starting lifecycle tasks...");
    for (const auto& task : taskList) {
        if (task.first && task.second() != 0) {
            return 1;
        }
    }
    
    this->logger->info("Lifecycle tasks completed.");

    return 0;
}

LifecycleExecuter::LifecycleTasks LifecycleExecuter::getLifecycleTasks(int cycleTasks) {
    this->logger->debug("Getting lifecycle tasks...");
    LifecycleTasks tasks;
    tasks.clean    = cycleTasks & 1;
    tasks.run      = cycleTasks & 2;
    tasks.validate = cycleTasks & 4;
    tasks.compile  = cycleTasks & 8;
    tasks.test     = cycleTasks & 16;
    tasks.package  = cycleTasks & 32;
    tasks.deploy   = cycleTasks & 64;
    return tasks;
}
