#ifndef NEXIS_MANAGER_H
#define NEXIS_MANAGER_H

#include <iostream>
#include <chrono>
#include "argparse.hpp"
#include "BuildManager.h"
#include "ProjectCreator.h"

class NexisManager {

public:
    NexisManager(int argc, char** argv);
    ~NexisManager();
    
    int makeChoice();

private:
    
    struct BuildTime {
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> stop;
    };
    BuildTime buildTime;

    BuildManager* buildManager = nullptr;
    nexis::NexisLoggerSpd* logger;
    DataObject* config = nullptr;
    argparse::ArgumentParser* program;
    argparse::ArgumentParser* phases;
    argparse::ArgumentParser* projectBuilder;
    std::string userPath;
    

    void setArguments(int argc, char** argv);
    void loadConfig();
    void processConfig();
    int createProject();
    int executeLifecycle();
    
    int getLifecycle(std::string phase);
    void startMessage();
    void endMessage(int returnCode);
    std::string calcBulidTime();
    std::string calcEndTime();
};

#endif // NEXIS_MANAGER_H