#include <filesystem>
#include <chrono>
#include "NexisLoggerSpd.h"
#include "NexisLogger.h"


nexis::NexisLogger * createLogger() {
    return new nexis::NexisLoggerSpd("NexisLogger", {"NexisLogger.log"}, "%v", "info");
}

void getData(nexis::NexisLogger * logger) {

}

void readConfig(nexis::NexisLogger * logger) {

}

void loadLibraries(nexis::NexisLogger * logger) {

}

void loadPlugins(nexis::NexisLogger * logger) {

}

void executeTasks(nexis::NexisLogger * logger) {

}

int startMainCycle(nexis::NexisLogger * logger) {
    getData(logger);
    readConfig(logger);
    loadLibraries(logger);
    loadPlugins(logger);
    executeTasks(logger);
    return 0;
}

int startNexis() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::string path = std::filesystem::current_path().string();

    nexis::NexisLogger * logger = createLogger();
    logger->info("-------------------------------");
    logger->info("Starting Nexis...");
    logger->info("-------------------------------");

    int returnCode = startMainCycle(logger);

    logger->info("Nexis ended.");
    
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    logger->info("-------------------------------");
    logger->info("Total time: " + std::to_string(duration) + " ms");
    logger->info("-------------------------------");
    

    return returnCode;
}


int main(int argc, char** argv) {
    return startNexis();
}