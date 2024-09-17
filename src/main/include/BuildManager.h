#ifndef BUILD_MANAGER_H
#define BUILD_MANAGER_H

#include <string>
#include <chrono>
#include <filesystem>
#include "Interfaces/Utilities/NexisLoggerSpd.h"
#include "DataObject.h"
#include "TimeCalc.h"
#include "YamlToDataObjectParser.h"
#include "PluginStructs.h"
#include "DynamicLibraryLoader.h"
#include "LifecycleExecuter.h"
#include "PluginCaster.h"



class BuildManager {
private:
    struct BuildTime {
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> stop;
    };
    BuildTime buildTime;
    nexis::NexisLoggerSpd * logger;
    DataObject * config;
    std::string projectPath;
    std::string projectType;
    std::vector<std::tuple<std::string, DataObject*>> pluginPaths;
    std::vector<NexisPlugin*> pluginsS;
    PluginStruct * plugins;
    
    std::string calcBulidTime();
    std::string calcEndTime();
    
    void loadLoggerConfig();
    void loadAttributes();
    void loadPluginsConfig();
    void loadExecuterConfig();
    int checkConfig();
public:
    BuildManager();
    ~BuildManager();
    
    
    void startMessage();
    void endMessage(int returnCode);
    int loadBuildFile();
    int processConfigs();
    int loadPlugins();
    int loadDependencies();
    int executeTasks();
    
    std::string getProjectType();
};

#endif // BUILD_MANAGER_H