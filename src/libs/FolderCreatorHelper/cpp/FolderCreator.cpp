#include "FolderCreator.h"

FolderCreator::FolderCreator(std::string basePath) {
    if(basePath.back() != '/') {
        basePath += "/";
    }
    this->basePath = basePath;
}

FolderCreator::FolderCreator(std::string basePath, std::vector<std::string> paths) {
    if(basePath.back() != '/') {
        basePath += "/";
    }
    this->basePath = basePath;
    add(paths);
}

FolderCreator::FolderCreator(std::string basePath, std::string projectName) {
    if(basePath.back() != '/') {
        basePath += "/";
    }
    this->basePath = basePath + projectName + "/";
    this->add("");
}

FolderCreator::FolderCreator(std::string basePath, std::string projectName, std::vector<std::string> paths) {
    if(basePath.back() != '/') {
        basePath += "/";
    }
    this->basePath = basePath + projectName + "/";
    add("");
    add(paths);
}

FolderCreator::~FolderCreator() {
}

void FolderCreator::add(std::string path) {
    this->paths.push_back(path);
}

void FolderCreator::create() {
    sortPaths();

    for (std::string path : this->paths) {
        path = this->basePath + path;
        if (path.back() == '/') {
            #ifdef _WIN32
                mkdir(path.c_str());
            #else
                mkdir(path.c_str(), 0777);  // Standardmodus für POSIX
            #endif
        } else {
            std::ofstream file(path);
            if (!file) {
                std::cerr << "Fehler beim Erstellen der Datei: " << path << std::endl;
            }
            file.close();
        }
    }
}

int FolderCreator::countSlashes(const std::string &path) {
    return std::count(path.begin(), path.end(), '/');
}

void FolderCreator::sortPaths() {
    std::sort(this->paths.begin(), this->paths.end(), [this](const std::string a, const std::string b) {
            int depthA = countSlashes(a);
            int depthB = countSlashes(b);
            if(depthA == depthB) {
                return a < b;
            }
            return depthA < depthB;
    });
}

std::string FolderCreator::getParentPath(const std::string &path) {
    size_t lastSlash;
    if(!path.empty() && path.back() != '/') {
        lastSlash = path.find_last_of('/');
    } else {
        std::string parentPath = path.substr(0, path.size() - 1);
        lastSlash = parentPath.find_last_of('/');
    }

    if (lastSlash == std::string::npos) {
        return "";
    }
    return path.substr(0, lastSlash + 1);
}

void FolderCreator::add(std::vector<std::string> paths) {
    for (std::string path : paths) {
        add(path);
    }
}

void FolderCreator::insertAll(std::vector<std::string> toAdd) {
    for(std::string path : toAdd) {
        this->paths.push_back(path);
    }
}

void FolderCreator::createAll() {
    sortPaths();
    
    std::unordered_set<std::string> createdPaths;
    std::vector<std::string> toCreate;

    for (const std::string path : this->paths) {
        std::cout << path << std::endl;
        std::string parentPath = getParentPath(path);
        while(!parentPath.empty() && createdPaths.find(parentPath) == createdPaths.end()) {
            toCreate.push_back(parentPath);
            createdPaths.insert(parentPath);
            parentPath = getParentPath(parentPath);
            std::cout << parentPath << std::endl;
        }
    }
    
    insertAll(toCreate);
    
    create();
}