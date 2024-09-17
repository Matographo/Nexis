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
#include "BuildManager.h"


int startNexis(int argc, char** argv) {
    BuildManager buildManager;
    
    buildManager.startMessage();
    int returnCode = 0;
    
    if(returnCode == 0) returnCode = buildManager.loadBuildFile();
    if(returnCode == 0) returnCode = buildManager.processConfigs();
    if(returnCode == 0) returnCode = buildManager.loadPlugins();
    if(returnCode == 0) returnCode = buildManager.loadDependencies();
    if(returnCode == 0) returnCode = buildManager.executeTasks();
    
    buildManager.endMessage(returnCode);

    return returnCode;
}

int main(int argc, char** argv) {
    return startNexis(argc, argv);
}