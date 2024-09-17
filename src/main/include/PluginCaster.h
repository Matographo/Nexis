#ifndef PLUGIN_CASTER_H
#define PLUGIN_CASTER_H

#include <string>
#include <set>
#include <map>
#include <any>
#include <tuple>
#include <functional>
#include "Interfaces/Utilities/NexisPlugin.h"
#include "PluginStructs.h"
#include "Interfaces/Utilities/NexisLogger.h"

class PluginCaster {
private:
    PluginStruct * pluginStruct;

    std::map<std::string, int(PluginCaster::*)(NexisPlugin *)> pluginCasts;
    nexis::NexisLogger * logger;
    
    void setPluginStruct();
    
    int castToBeforeBuildTask(NexisPlugin * plugin);
    int castToAfterBuildTask(NexisPlugin * plugin);
    int castToCleanTask(NexisPlugin * plugin);
    int castToBeforeCleanTask(NexisPlugin * plugin);
    int castToAfterCleanTask(NexisPlugin * plugin);
    int castToCleanSuccessEvent(NexisPlugin * plugin);
    int castToCleanFailureEvent(NexisPlugin * plugin);
    int castToPreCleanTask(NexisPlugin * plugin);
    int castToPostCleanTask(NexisPlugin * plugin);
    int castToCompileTask(NexisPlugin * plugin);
    int castToBeforeCompileTask(NexisPlugin * plugin);
    int castToAfterCompileTask(NexisPlugin * plugin);
    int castToCompileSuccessEvent(NexisPlugin * plugin);
    int castToCompileFailureEvent(NexisPlugin * plugin);
    int castToPreCompileTask(NexisPlugin * plugin);
    int castToPostCompileTask(NexisPlugin * plugin);
    int castToTestTask(NexisPlugin * plugin);
    int castToBeforeTestTask(NexisPlugin * plugin);
    int castToAfterTestTask(NexisPlugin * plugin);
    int castToTestSuccessEvent(NexisPlugin * plugin);
    int castToTestFailureEvent(NexisPlugin * plugin);
    int castToPreTestTask(NexisPlugin * plugin);
    int castToPostTestTask(NexisPlugin * plugin);
    int castToPackageTask(NexisPlugin * plugin);
    int castToBeforePackageTask(NexisPlugin * plugin);
    int castToAfterPackageTask(NexisPlugin * plugin);
    int castToPackageSuccessEvent(NexisPlugin * plugin);
    int castToPackageFailureEvent(NexisPlugin * plugin);
    int castToPrePackageTask(NexisPlugin * plugin);
    int castToPostPackageTask(NexisPlugin * plugin);
    int castToDeployTask(NexisPlugin * plugin);
    int castToBeforeDeployTask(NexisPlugin * plugin);
    int castToAfterDeployTask(NexisPlugin * plugin);
    int castToDeploySuccessEvent(NexisPlugin * plugin);
    int castToDeployFailureEvent(NexisPlugin * plugin);
    int castToPreDeployTask(NexisPlugin * plugin);
    int castToPostDeployTask(NexisPlugin * plugin);
    int castToRunTask(NexisPlugin * plugin);
    int castToBeforeRunTask(NexisPlugin * plugin);
    int castToAfterRunTask(NexisPlugin * plugin);
    int castToRunSuccessEvent(NexisPlugin * plugin);
    int castToRunFailureEvent(NexisPlugin * plugin);
    int castToPreRunTask(NexisPlugin * plugin);
    int castToPostRunTask(NexisPlugin * plugin);
    int castToValidateTask(NexisPlugin * plugin);
    int castToBeforeValidateTask(NexisPlugin * plugin);
    int castToAfterValidateTask(NexisPlugin * plugin);
    int castToValidateSuccessEvent(NexisPlugin * plugin);
    int castToValidateFailureEvent(NexisPlugin * plugin);
    int castToPreValidateTask(NexisPlugin * plugin);
    int castToPostValidateTask(NexisPlugin * plugin);
    

    
    
public:
    PluginCaster(nexis::NexisLogger * logger, PluginStruct * pluginStruct);
    ~PluginCaster() = default;
    
    int castPlugin(NexisPlugin* plugin);
};

#endif // PLUGIN_CASTER_H