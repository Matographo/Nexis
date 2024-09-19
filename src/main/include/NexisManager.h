#ifndef NEXIS_MANAGER_H
#define NEXIS_MANAGER_H

#include <iostream>
#include "argparse.hpp"
#include "BuildManager.h"
#include "ProjectCreator.h"

class NexisManager {

public:
    NexisManager(int argc, char** argv);
    ~NexisManager();
    
    int makeChoice();

private:

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
};

#endif // NEXIS_MANAGER_H