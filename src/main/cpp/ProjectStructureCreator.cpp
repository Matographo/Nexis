#include "ProjectStructureCreator.h"

void createProjectStructure(std::string path, std::string projectName) {
    FolderCreator folderCreator(path, projectName);
    
    folderCreator.add("src/");
    folderCreator.add("src/main/");
    folderCreator.add("src/main/res/");
    folderCreator.add("src/tests/");
    
    folderCreator.add("config/");
    folderCreator.add("config/dependencies/");
    folderCreator.add("config/project/");
    folderCreator.add("config/plugins/");
    folderCreator.add("config/custom/");

    folderCreator.add("README.md");
    folderCreator.add("build.yaml");

    folderCreator.create();
}