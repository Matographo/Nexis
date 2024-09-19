#ifndef PROJECT_CREATOR_H
#define PROJECT_CREATOR_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include "Interfaces/Utilities/NexisLoggerSpd.h"
#include "FolderCreator.h"

class ProjectCreator {

public:
    ProjectCreator(nexis::NexisLoggerSpd* logger);
    ~ProjectCreator();
    
    void createProject(std::string projectName, std::string projectPath, std::string projectType, std::vector<std::string> projectLanguages, std::string projectTemplate);

private:
    nexis::NexisLoggerSpd* logger;
    std::string projectPath;
    
    std::string loadTemplate(std::string templatePath);
    std::string loadTemplates(std::vector<std::string> languages);
};

#endif // PROJECT_CREATOR_H