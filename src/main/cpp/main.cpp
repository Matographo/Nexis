#include <filesystem>
#include <chrono>
#include <iostream>
#include <csignal>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "LifecycleExecuter.h"
#include "PluginStructs.h"
#include "DataObject.h"
#include <fstream>
#include "YamlToDataObjectParser.h"
#include "TimeCalc.h"
#include "DynamicLibraryLoader.h"
#include "Interfaces/Utilities/NexisLogger.h"
#include "Interfaces/Utilities/NexisLoggerSpd.h"
#include "Interfaces/Utilities/NexisLogger.h"


nexis::NexisLoggerSpd* createLogger() {
    return new nexis::NexisLoggerSpd("NexisLogger", "%v", "info");
}

DataObject getData(nexis::NexisLoggerSpd * logger, const std::string &path) {
    logger->info("Reading build.yaml...");
    try {
        DataObject dataObject = parseYaml(path + "/build.yaml");
        logger->debug("build.yaml read successfully.");
        if(dataObject.hasKey("logger") && dataObject.asDictionary().at("logger").isDictionary()) {
            logger->setConfig(&dataObject.asDictionary().at("logger"));
        }


        return dataObject;
    } catch (std::runtime_error & e) {
        logger->err("build.yaml could not be read.");
        throw;
    }
}



void readConfig(nexis::NexisLogger * logger, DataObject * dataObject) {

}



void loadLibraries(nexis::NexisLogger * logger) {

}



PluginStruct* loadPlugins(nexis::NexisLogger * logger, DataObject * DataObject, std::vector<std::string> * pluginPaths) {
    PluginStruct * plugins = new PluginStruct();
    
    for(std::string & pluginPath : *pluginPaths) {
            
        NexisPlugin * plugin   = loadDynamicLibrary(pluginPath, logger, DataObject);
        
        if(plugin == nullptr) {
            logger->err("Could not load Plugin " + pluginPath);
            throw std::runtime_error("Could not load Plugin " + pluginPath);
        }
        
        std::set<std::string> pluginRegister = plugin->getInterfaces();
        
        if(pluginRegister.find("BeforeBuildTask") != pluginRegister.end()) {
            BeforeBuildTask * interface = dynamic_cast<BeforeBuildTask*>(plugin);
            plugins->buildTasks.beforeBuildTask.push_back(interface);
        }
        
        if(pluginRegister.find("BeforeCleanTask") != pluginRegister.end()) {
            BeforeCleanTask * interface = dynamic_cast<BeforeCleanTask*>(plugin);
            plugins->cleanTasks.beforeCleanTask.push_back(interface);
        }

        if(pluginRegister.find("BeforeCompileTask") != pluginRegister.end()) {
            BeforeCompileTask * interface = dynamic_cast<BeforeCompileTask*>(plugin);
            plugins->compileTasks.beforeCompileTask.push_back(interface);
        }

        if(pluginRegister.find("BeforeDeployTask") != pluginRegister.end()) {
            BeforeDeployTask * interface = dynamic_cast<BeforeDeployTask*>(plugin);
            plugins->deployTasks.beforeDeployTask.push_back(interface);
        }

        if(pluginRegister.find("BeforePackageTask") != pluginRegister.end()) {
            BeforePackageTask * interface = dynamic_cast<BeforePackageTask*>(plugin);
            plugins->packageTasks.beforePackageTask.push_back(interface);
        }

        if(pluginRegister.find("BeforeRunTask") != pluginRegister.end()) {
            BeforeRunTask * interface = dynamic_cast<BeforeRunTask*>(plugin);
            plugins->runTasks.beforeRunTask.push_back(interface);
        }

        if(pluginRegister.find("BeforeTestTask") != pluginRegister.end()) {
            BeforeTestTask * interface = dynamic_cast<BeforeTestTask*>(plugin);
            plugins->testTasks.beforeTestTask.push_back(interface);
        }

        if(pluginRegister.find("BeforeValidateTask") != pluginRegister.end()) {
            BeforeValidateTask * interface = dynamic_cast<BeforeValidateTask*>(plugin);
            plugins->validateTasks.beforeValidateTask.push_back(interface);
        }

        if(pluginRegister.find("AfterBuildTask") != pluginRegister.end()) {
            AfterBuildTask * interface = dynamic_cast<AfterBuildTask*>(plugin);
            plugins->buildTasks.afterBuildTask.push_back(interface);
        }

        if(pluginRegister.find("AfterCleanTask") != pluginRegister.end()) {
            AfterCleanTask * interface = dynamic_cast<AfterCleanTask*>(plugin);
            plugins->cleanTasks.afterCleanTask.push_back(interface);
        }

        if(pluginRegister.find("AfterCompileTask") != pluginRegister.end()) {
            AfterCompileTask * interface = dynamic_cast<AfterCompileTask*>(plugin);
            plugins->compileTasks.afterCompileTask.push_back(interface);
        }

        if(pluginRegister.find("AfterDeployTask") != pluginRegister.end()) {
            AfterDeployTask * interface = dynamic_cast<AfterDeployTask*>(plugin);
            plugins->deployTasks.afterDeployTask.push_back(interface);
        }

        if(pluginRegister.find("AfterPackageTask") != pluginRegister.end()) {
            AfterPackageTask * interface = dynamic_cast<AfterPackageTask*>(plugin);
            plugins->packageTasks.afterPackageTask.push_back(interface);
        }

        if(pluginRegister.find("AfterRunTask") != pluginRegister.end()) {
            AfterRunTask * interface = dynamic_cast<AfterRunTask*>(plugin);
            plugins->runTasks.afterRunTask.push_back(interface);
        }

        if(pluginRegister.find("AfterTestTask") != pluginRegister.end()) {
            AfterTestTask * interface = dynamic_cast<AfterTestTask*>(plugin);
            plugins->testTasks.afterTestTask.push_back(interface);
        }

        if(pluginRegister.find("AfterValidateTask") != pluginRegister.end()) {
            AfterValidateTask * interface = dynamic_cast<AfterValidateTask*>(plugin);
            plugins->validateTasks.afterValidateTask.push_back(interface);
        }

        if(pluginRegister.find("CleanSuccessEvent") != pluginRegister.end()) {
            CleanSuccessEvent * interface = dynamic_cast<CleanSuccessEvent*>(plugin);
            plugins->cleanTasks.cleanSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("CompileSuccessEvent") != pluginRegister.end()) {
            CompileSuccessEvent * interface = dynamic_cast<CompileSuccessEvent*>(plugin);
            plugins->compileTasks.compileSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("DeploySuccessEvent") != pluginRegister.end()) {
            DeploySuccessEvent * interface = dynamic_cast<DeploySuccessEvent*>(plugin);
            plugins->deployTasks.deploySuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("PackageSuccessEvent") != pluginRegister.end()) {
            PackageSuccessEvent * interface = dynamic_cast<PackageSuccessEvent*>(plugin);
            plugins->packageTasks.packageSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("RunSuccessEvent") != pluginRegister.end()) {
            RunSuccessEvent * interface = dynamic_cast<RunSuccessEvent*>(plugin);
            plugins->runTasks.runSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("TestSuccessEvent") != pluginRegister.end()) {
            TestSuccessEvent * interface = dynamic_cast<TestSuccessEvent*>(plugin);
            plugins->testTasks.testSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("ValidateSuccessEvent") != pluginRegister.end()) {
            ValidateSuccessEvent * interface = dynamic_cast<ValidateSuccessEvent*>(plugin);
            plugins->validateTasks.validateSuccessEvent.push_back(interface);
        }

        if(pluginRegister.find("CleanFailureEvent") != pluginRegister.end()) {
            CleanFailureEvent * interface = dynamic_cast<CleanFailureEvent*>(plugin);
            plugins->cleanTasks.cleanFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("CompileFailureEvent") != pluginRegister.end()) {
            CompileFailureEvent * interface = dynamic_cast<CompileFailureEvent*>(plugin);
            plugins->compileTasks.compileFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("DeployFailureEvent") != pluginRegister.end()) {
            DeployFailureEvent * interface = dynamic_cast<DeployFailureEvent*>(plugin);
            plugins->deployTasks.deployFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("PackageFailureEvent") != pluginRegister.end()) {
            PackageFailureEvent * interface = dynamic_cast<PackageFailureEvent*>(plugin);
            plugins->packageTasks.packageFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("RunFailureEvent") != pluginRegister.end()) {
            RunFailureEvent * interface = dynamic_cast<RunFailureEvent*>(plugin);
            plugins->runTasks.runFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("TestFailureEvent") != pluginRegister.end()) {
            TestFailureEvent * interface = dynamic_cast<TestFailureEvent*>(plugin);
            plugins->testTasks.testFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("ValidateFailureEvent") != pluginRegister.end()) {
            ValidateFailureEvent * interface = dynamic_cast<ValidateFailureEvent*>(plugin);
            plugins->validateTasks.validateFailureEvent.push_back(interface);
        }

        if(pluginRegister.find("PreCleanTask") != pluginRegister.end()) {
            PreCleanTask * interface = dynamic_cast<PreCleanTask*>(plugin);
            plugins->cleanTasks.preCleanTask.push_back(interface);
        }

        if(pluginRegister.find("PreCompileTask") != pluginRegister.end()) {
            PreCompileTask * interface = dynamic_cast<PreCompileTask*>(plugin);
            plugins->compileTasks.preCompileTask.push_back(interface);
        }

        if(pluginRegister.find("PreDeployTask") != pluginRegister.end()) {
            PreDeployTask * interface = dynamic_cast<PreDeployTask*>(plugin);
            plugins->deployTasks.preDeployTask.push_back(interface);
        }

        if(pluginRegister.find("PrePackageTask") != pluginRegister.end()) {
            PrePackageTask * interface = dynamic_cast<PrePackageTask*>(plugin);
            plugins->packageTasks.prePackageTask.push_back(interface);
        }

        if(pluginRegister.find("PreRunTask") != pluginRegister.end()) {
            PreRunTask * interface = dynamic_cast<PreRunTask*>(plugin);
            plugins->runTasks.preRunTask.push_back(interface);
        }

        if(pluginRegister.find("PreTestTask") != pluginRegister.end()) {
            PreTestTask * interface = dynamic_cast<PreTestTask*>(plugin);
            plugins->testTasks.preTestTask.push_back(interface);
        }

        if(pluginRegister.find("PreValidateTask") != pluginRegister.end()) {
            PreValidateTask * interface = dynamic_cast<PreValidateTask*>(plugin);
            plugins->validateTasks.preValidateTask.push_back(interface);
        }

        if(pluginRegister.find("PostCleanTask") != pluginRegister.end()) {
            PostCleanTask * interface = dynamic_cast<PostCleanTask*>(plugin);
            plugins->cleanTasks.postCleanTask.push_back(interface);
        }

        if(pluginRegister.find("PostCompileTask") != pluginRegister.end()) {
            PostCompileTask * interface = dynamic_cast<PostCompileTask*>(plugin);
            plugins->compileTasks.postCompileTask.push_back(interface);
        }

        if(pluginRegister.find("PostDeployTask") != pluginRegister.end()) {
            PostDeployTask * interface = dynamic_cast<PostDeployTask*>(plugin);
            plugins->deployTasks.postDeployTask.push_back(interface);
        }

        if(pluginRegister.find("PostPackageTask") != pluginRegister.end()) {
            PostPackageTask * interface = dynamic_cast<PostPackageTask*>(plugin);
            plugins->packageTasks.postPackageTask.push_back(interface);
        }

        if(pluginRegister.find("PostRunTask") != pluginRegister.end()) {
            PostRunTask * interface = dynamic_cast<PostRunTask*>(plugin);
            plugins->runTasks.postRunTask.push_back(interface);
        }

        if(pluginRegister.find("PostTestTask") != pluginRegister.end()) {
            PostTestTask * interface = dynamic_cast<PostTestTask*>(plugin);
            plugins->testTasks.postTestTask.push_back(interface);
        }

        if(pluginRegister.find("PostValidateTask") != pluginRegister.end()) {
            PostValidateTask * interface = dynamic_cast<PostValidateTask*>(plugin);
            plugins->validateTasks.postValidateTask.push_back(interface);
        }

        if(pluginRegister.find("CleanTask") != pluginRegister.end()) {
            CleanTask * interface = dynamic_cast<CleanTask*>(plugin);
            plugins->cleanTasks.cleanTask.push_back(interface);
        }

        if(pluginRegister.find("CompileTask") != pluginRegister.end()) {
            CompileTask * interface = dynamic_cast<CompileTask*>(plugin);
            plugins->compileTasks.compileTask.push_back(interface);
        }

        if(pluginRegister.find("DeployTask") != pluginRegister.end()) {
            DeployTask * interface = dynamic_cast<DeployTask*>(plugin);
            plugins->deployTasks.deployTask.push_back(interface);
        }

        if(pluginRegister.find("PackageTask") != pluginRegister.end()) {
            PackageTask * interface = dynamic_cast<PackageTask*>(plugin);
            plugins->packageTasks.packageTask.push_back(interface);
        }

        if(pluginRegister.find("RunTask") != pluginRegister.end()) {
            RunTask * interface = dynamic_cast<RunTask*>(plugin);
            plugins->runTasks.runTask.push_back(interface);
        }

        if(pluginRegister.find("TestTask") != pluginRegister.end()) {
            TestTask * interface = dynamic_cast<TestTask*>(plugin);
            plugins->testTasks.testTask.push_back(interface);
        }

        if(pluginRegister.find("ValidateTask") != pluginRegister.end()) {
            ValidateTask * interface = dynamic_cast<ValidateTask*>(plugin);
            plugins->validateTasks.validateTask.push_back(interface);
        }
    }
    
    return plugins;
}



int executeTasks(nexis::NexisLogger * logger, PluginStruct * plugins) {
    LifecycleExecuter lifecycleExecuter(plugins, logger);
    logger->info("Starting lifecycle...");
    int result = lifecycleExecuter.startLifecycle(44);
    logger->info("Lifecycle ended.");
    return result;
}



int startMainCycle(nexis::NexisLoggerSpd * logger, std::string &path) {
    int returnCode = 0;
    DataObject configData = getData(logger, path);
    configData.addToDictionary("projectPath", DataObject::createString(path));
    readConfig(logger, &configData);
    loadLibraries(logger);
    std::vector<std::string> pluginPaths = {"/home/leodora/Documents/Dev/C++/Nexis/build/result/cpp_1.0.so"};
    logger->info("Loading plugins...");
    PluginStruct * plugins = loadPlugins(logger, &configData, &pluginPaths);
    logger->info("Plugins loaded.");
    logger->info("Executing tasks...");
    returnCode = executeTasks(logger, plugins);
    logger->info("Tasks executed.");
    return returnCode;
}



int startNexis() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::string path = std::filesystem::current_path().string();

    nexis::NexisLoggerSpd * const logger = createLogger();
    logger->info("");
    logger->info("------------------------------------------------------------------------");
    logger->setFormat("%^%v%$");
    logger->info(" Starting Nexis Build...");
    logger->setFormat("%v");
    logger->info("------------------------------------------------------------------------");
    logger->info("");

    int returnCode = 0;
    try{
        returnCode = startMainCycle(logger, path);
    } catch (std::runtime_error & e) {
        logger->err("An error occurred during the build process.");
        logger->err(e.what());
        returnCode = 1;
    }
    
    logger->setLevel("info");
    logger->setFormat("%v");
    logger->setColors("info", "green");
    logger->setColors("err", "red");
    
    auto endTime                      = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::time_t endTimeT              = std::chrono::system_clock::to_time_t(endTime);
    std::tm * endTimeTm               = std::localtime(&endTimeT);

    std::ostringstream endTimeStr; 
    endTimeStr << std::put_time(endTimeTm, "%Y-%m-%d %H:%M:%S");

    logger->info("");
    logger->info("------------------------------------------------------------------------");
    logger->setFormat("%^%v%$");
    if(returnCode == 0) {
        logger->info(" BUILD SUCCESSFUL ");
    } else {
        logger->err(" BUILD FAILED ");
    }
    logger->setFormat("%v");
    logger->info(" Total time: " +  formatDuration(duration));
    logger->info(" Finished at: " + endTimeStr.str());
    logger->info("------------------------------------------------------------------------");
    logger->info("");

    spdlog::shutdown();
    
    return returnCode;
}



int main(int argc, char** argv) {
    return startNexis();
}