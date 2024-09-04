#include <filesystem>
#include <chrono>
#include <iostream>
#include "NexisLoggerSpd.h"
#include "NexisLogger.h"
#include "LifecycleExecuter.h"
#include "PluginStructs.h"
#include "DataObject.h"
#include <fstream>
#include "YamlToDataObjectParser.h"



std::string readFileAsString(const std::string& filePath) {
    std::ifstream fileStream(filePath); // Öffnet die Datei im Eingabemodus
    if (!fileStream.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf(); // Liest den gesamten Dateiinhalt in einen stringstream

    return buffer.str(); // Gibt den Inhalt als String zurück
}


nexis::NexisLogger* createLogger() {
    return new nexis::NexisLoggerSpd("NexisLogger", "%v", "error");
}

DataObject getData(nexis::NexisLogger * logger, const std::string &path) {
    logger->info("Reading build.yaml...");
    try {
        std::string yamlContent = readFileAsString(path + "/build.yaml");
        DataObject dataObject = parseYaml(yamlContent);
        logger->debug("build.yaml read successfully.");
        nexis::NexisLoggerSpd * log = dynamic_cast<nexis::NexisLoggerSpd*>(logger);
        log->setConfig(dataObject);
        return dataObject;
    } catch (std::runtime_error & e) {
        logger->err("build.yaml could not be read.");
        logger->err(e.what());
        throw;
    }
}



void readConfig(nexis::NexisLogger * logger) {

}



void loadLibraries(nexis::NexisLogger * logger) {

}



PluginStruct* loadPlugins(nexis::NexisLogger * logger) {
    PluginStruct * plugins = new PluginStruct();
    return plugins;
}



void executeTasks(nexis::NexisLogger * logger, PluginStruct * plugins) {
    LifecycleExecuter lifecycleExecuter(plugins, logger);
    logger->info("Starting lifecycle...");
    lifecycleExecuter.startLifecycle(0);
    logger->info("Lifecycle ended.");
}



int startMainCycle(nexis::NexisLogger * logger, std::string &path) {
    getData(logger, path);
    readConfig(logger);
    loadLibraries(logger);
    logger->info("Loading plugins...");
    PluginStruct * plugins = loadPlugins(logger);
    logger->info("Plugins loaded.");
    logger->info("Executing tasks...");
    executeTasks(logger, plugins);
    logger->info("Tasks executed.");
    return 0;
}



int startNexis() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::string path = std::filesystem::current_path().string();

    nexis::NexisLogger * const logger = createLogger();
    logger->info("");
    logger->info("------------------------------------------------------------------------");
    logger->info("| Starting Nexis Build...");
    logger->info("------------------------------------------------------------------------");
    logger->info("");

    int returnCode = startMainCycle(logger, path);

    logger->info("");
    if(returnCode == 0) {
        logger->info("--------------------");
        logger->info("| BUILD SUCCESSFUL |");
    } else {
        logger->info("----------------");
        logger->err("| BUILD FAILED |");
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    logger->info("------------------------------------------------------------------------");
    logger->info("| Total time: " + std::to_string(duration) + " ms");
    logger->info("------------------------------------------------------------------------");
    logger->info("");

    spdlog::shutdown();
    

    return returnCode;
}



int main(int argc, char** argv) {
    return startNexis();
}