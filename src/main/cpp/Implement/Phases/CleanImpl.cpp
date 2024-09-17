#include "Phases/CleanImpl.h"

CleanImpl::CleanImpl(nexis::NexisLogger* logger, DataObject* dataObject) {
    this->logger     = logger;
    this->dataObject = dataObject;
}

CleanImpl::~CleanImpl() {
}

int CleanImpl::clean() {
    logger->info("Cleaning up...");
    std::string pathToClean = "";
    if(dataObject->hasKey("projectPath")) {
        pathToClean = dataObject->asDictionary().at("projectPath").asString() ;
    }
    if(pathToClean.empty()) {
        logger->err("No project path found in data object");
        return 1;
    }
    
    pathToClean += "/build";
    
    if(!std::filesystem::exists(pathToClean)) {
        logger->info("Is already clean");
        return 0;
    }
    
    logger->info("Cleaning up " + pathToClean);

    int exitCode = std::filesystem::remove_all(pathToClean);
    
    if(exitCode != 0) {
        logger->err("Failed to clean up " + pathToClean);
        return 1;
    }

    return 0;
}