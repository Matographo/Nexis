#include "ProjectCreator.h"

ProjectCreator::ProjectCreator(nexis::NexisLoggerSpd* logger) {
    this->logger = logger;
}

ProjectCreator::~ProjectCreator() {
}

void ProjectCreator::createProject(std::string projectName, std::string projectPath, std::string projectType, std::vector<std::string> projectLanguages, std::string projectTemplate) {
    this->projectPath = projectPath;
    this->logger->info("Start creating project");
    
    FolderCreator folderCreator(projectPath, projectName);
    folderCreator.add("src/");
    folderCreator.add("src/main/");
    folderCreator.add("src/res/");
    folderCreator.add("src/tests/");

    folderCreator.add("build.yaml");
    
    folderCreator.create();
    
    this->projectPath = projectPath + "/" + projectName;

    std::stringstream buildFile;
    buildFile << "projectName: " << projectName << std::endl;
    if(projectTemplate == "") {
        buildFile << "type: " << projectType << std::endl;
    }
    
    if(projectTemplate == "") {
        buildFile << "language: ";
        if(projectLanguages.size() == 1) {
            buildFile << projectLanguages[0] << std::endl;
        } else {
            buildFile << "[";
            for(std::string language : projectLanguages) {
                buildFile << "\"" << language;
                if(language != projectLanguages.back()) {
                    buildFile << "\", ";
                } else {
                    buildFile << "\"";
                }
            }
            buildFile << "]" << std::endl;
            
            buildFile << std::endl;
        }
    }
    
    
    
    if(projectTemplate != "") {
        buildFile << this->loadTemplate(projectTemplate) << std::endl;
    } else {
        buildFile << this->loadTemplates(projectLanguages) << std::endl;
    }

    
    std::ofstream buildFileWriter(this->projectPath + "/build.yaml");
    buildFileWriter << buildFile.str();
    buildFileWriter.close();
}

std::string ProjectCreator::loadTemplate(std::string templatePath) {
    std::string buildFile = templatePath + "/build.include";
    std::string buildType = templatePath + "/build.type";
    std::string buildLanguage = templatePath + "/build.language";
    std::stringstream returnValue;
    
    if(std::filesystem::exists(buildType)) {
        std::ifstream buildTypeReader(buildType);
        std::string line;
        std::vector<std::string> types;
        while(std::getline(buildTypeReader, line)) {
            types.push_back(line);
        }
        if(types.size() == 1) {
            for(std::string type : types) {
                returnValue << type << std::endl;
            }
        } else {
            this->logger->err("No type specified in build.type file");
        }
    }

    if(std::filesystem::exists(buildLanguage)) {
        std::ifstream buildLanguageReader(buildLanguage);
        std::string line;
        std::vector<std::string> languages;
        while(std::getline(buildLanguageReader, line)) {
            languages.push_back(line);
        }
        if(languages.size() == 1) {
            for(std::string language : languages) {
                returnValue << language << std::endl;
            }
        } else {
            this->logger->err("No language specified in build.language file");
        }
    }
    

    returnValue << std::endl << "includes: on" << std::endl << std::endl;

    if(std::filesystem::exists(buildFile)) {
        std::ifstream buildFileReader(buildFile);
        std::string line;
        std::vector<std::string> templates;
        while(std::getline(buildFileReader, line)) {
            templates.push_back(line);
        }
        if(templates.size() > 0) {
            returnValue << "include: " << std::endl;
            for(std::string templ : templates) {
                returnValue << "  " << templ << std::endl;
            }
        }
    }
    
    for(const auto& entry : std::filesystem::recursive_directory_iterator(templatePath)) {
        if(!(entry.is_regular_file() && (entry.path().filename() == "build.include" || entry.path().filename() == "build.type" || entry.path().filename() == "build.language"))) {
            auto pathInCache = std::filesystem::relative(entry.path(), templatePath);
            std::filesystem::path pathInProject = projectPath / pathInCache;
            
            if(entry.is_directory() && !std::filesystem::exists(pathInProject)) {
                std::filesystem::create_directory(pathInProject);
            } else if(!std::filesystem::exists(pathInProject) && entry.is_regular_file()) {
                if(!std::filesystem::exists(entry.path().parent_path())) {
                    std::filesystem::create_directories(entry.path().parent_path());
                }
                std::filesystem::copy_file(entry.path(), pathInProject, std::filesystem::copy_options::update_existing);
            }
        }
    }
    
    return returnValue.str();
}

std::string ProjectCreator::loadTemplates(std::vector<std::string> languages) {
    std::stringstream returnValue;
    
    returnValue << std::endl << "includes: on" << std::endl << std::endl;
    
    std::string homePath = std::getenv("HOME");
    for(const std::string language : languages) {
        std::string path = homePath + "/.nexis/templates/" + language + "Default";
        for(const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
            if(!(entry.is_regular_file() && (entry.path().filename() == "build.include" || entry.path().filename() == "build.type" || entry.path().filename() == "build.language"))) {
                auto pathInCache = std::filesystem::relative(entry.path(), path);
                std::filesystem::path pathInProject = projectPath / pathInCache;
                
                if(entry.is_directory() && !std::filesystem::exists(pathInProject)) {
                    std::filesystem::create_directory(pathInProject);
                } else if(!std::filesystem::exists(pathInProject) && entry.is_regular_file()) {
                    if(!std::filesystem::exists(entry.path().parent_path())) {
                        std::filesystem::create_directories(entry.path().parent_path());
                    }
                    std::filesystem::copy_file(entry.path(), pathInProject, std::filesystem::copy_options::update_existing);
                }
            }
        }
    }


    return returnValue.str();
}