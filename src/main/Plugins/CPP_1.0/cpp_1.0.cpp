#include "cpp_1.0.h"


bool Cpp_Compiler::endsWith(const std::string& filePath, const std::string& suffix) {
    if (filePath.size() >= suffix.size()) {
        return filePath.compare(filePath.size() - suffix.size(), suffix.size(), suffix) == 0;
    }
    return false;
}

void Cpp_Compiler::findAllCppFiles(std::string path, std::vector<std::string> * cppFiles) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            
            if (endsWith(filePath, ".cpp") || endsWith(filePath, ".c")) {
                cppFiles->push_back(filePath);
            } 
        } else if (entry.is_directory()) {
            findAllCppFiles(entry.path().string(), cppFiles);
        }
    }
}

bool Cpp_Compiler::isFileUpToDate(std::string filePath, std::string pathToCompare) {
    std::filesystem::path sourceFile = std::filesystem::path(filePath);

    std::filesystem::path destinationFile = std::filesystem::path(pathToCompare) / sourceFile;

    if (!std::filesystem::exists(pathToCompare)) {
        return false;
    }

    auto sourceLastWriteTime      = std::filesystem::last_write_time(sourceFile);
    auto destinationLastWriteTime = std::filesystem::last_write_time(destinationFile);

    return (long long unsigned)sourceLastWriteTime.time_since_epoch().count() <= (long long unsigned)destinationLastWriteTime.time_since_epoch().count();
}

void Cpp_Compiler::findAllIncludeFiles(std::string path) {
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if(entry.is_directory() && std::filesystem::exists(entry.path().string() + "/include")) {
            this->includeString += " -I" + std::filesystem::relative(entry.path().string() + "/include", this->projectPath).string();
        }
    }
}

void Cpp_Compiler::findAllDirectories(std::string path, std::vector<std::string> * directories) {
    for(const auto& entry : std::filesystem::directory_iterator(path)) {
        if(entry.is_directory()) {
            directories->push_back(entry.path().string());
            findAllDirectories(entry.path().string(), directories);
        }
    }
}

int Cpp_Compiler::compileLibrary(std::string libraryPath) {
    if(!std::filesystem::is_directory(libraryPath)) {
        this->logger->warn("Library " + libraryPath + " is not a directory");
        return 0;
    }
    if(!std::filesystem::exists(libraryPath + "/src") && !std::filesystem::exists(libraryPath + "/cpp")) {
        this->logger->warn("Library " + libraryPath + " has no source files Folder");
        return 0;
    }
    
    std::string pathToSrc;
    if(std::filesystem::exists(libraryPath + "/cpp")) {
        pathToSrc = libraryPath + "/cpp";
    } else {
        pathToSrc = libraryPath + "/src";
    }

    std::string includeString = "";

    if(std::filesystem::exists(libraryPath + "/include")) {
        includeString = "-I" + libraryPath + "/include";
    }
    
    std::vector<std::string> cppFiles;
    this->findAllCppFiles(pathToSrc, &cppFiles);
    
    if(cppFiles.size() == 0) {
        this->logger->warn("Library " + libraryPath + " has no C++ source files");
        return 0;
    }
    
    std::string binPath = this->projectPath + "/build/bin/" + std::filesystem::path(libraryPath).filename().string() + ".so";
    
    std::string allPaths = "";
    for(std::string cppFile : this->cppFilePaths) {
        allPaths += cppFile + " ";
    }

    std::string command = this->compilerName + " -fPIC -shared " + includeString + " -o " + binPath + ".so " + allPaths;
    return 0;
}
 


Cpp_Compiler::Cpp_Compiler(nexis::NexisLogger *logger, DataObject *dataObject) : NexisPlugin(logger, dataObject) {
}

Cpp_Compiler::~Cpp_Compiler() {
}

int Cpp_Compiler::preCompile() {
    this->binPath    = this->projectPath + "/build/bin";
    this->resultPath = this->projectPath + "/build/result";
    this->srcPath    = this->projectPath + "/src/main/cpp";

    if(!this->dataObject->hasKey("projectName")) {
        this->projectName = "cpp_project";
    } else {
        this->projectName = this->dataObject->asDictionary().at("projectName").asString();
    }

    if(!std::filesystem::exists(this->srcPath)) {
        this->logger->err("C++ project has no source files");
        this->logger->err("C++ project must have a src/main/cpp directory");
        this->logger->err("To fix this issue, create a src/main/cpp directory in your project");
        return 1;
    }

    if(std::filesystem::exists(this->projectPath + "/src/main/include")) {
        this->includeString = "-Isrc/main/include";
    }
    
    if(std::filesystem::exists(this->projectPath    + "/src/libs")) {
        this->findAllIncludeFiles(this->projectPath + "/src/libs");
    }

    if(!std::filesystem::exists(this->binPath)) {
        std::filesystem::create_directories(this->binPath);
    }
    
    if(!std::filesystem::exists(this->resultPath)) {
        std::filesystem::create_directories(this->resultPath);
    }
    
    this->findAllCppFiles(this->srcPath, &this->cppFilePaths);

    this->compilerName = "g++";
    return 0;
}

int Cpp_Compiler::compile() {
    for(auto cppFilePath : this->cppFilePaths) {
        std::string fileName = std::filesystem::absolute(cppFilePath).filename().stem();
        if(!this->isFileUpToDate(cppFilePath, this->binPath + "/" + fileName + ".o")) {
            std::string fileName = std::filesystem::path(cppFilePath).stem();
            std::string command  = this->compilerName + " " + this->includeString + " -c " + cppFilePath + " -o " + this->binPath + "/" + fileName + ".o";
            logger->debug("Compiling C++ file: " + cppFilePath);
            logger->trace("Compile Command: " + command);
            int result = system(command.c_str());
            if(result != 0) {
                this->logger->err("Failed to compile C++ file: " + cppFilePath);
                return 1;
            }
        }
    }

    if(std::filesystem::exists(this->projectPath + "/src/libs")) {
        for (const auto& entry : std::filesystem::directory_iterator(this->projectPath + "/src/libs")) {
           if(entry.is_directory()) {
               std::string libraryPath = entry.path().string();
               if(this->compileLibrary(libraryPath) != 0) {
                   this->logger->err("Failed to compile C++ library: " + libraryPath);
                   return 1;
               }
           }
        }
    }
    
    return 0;
}

int Cpp_Compiler::validate() {
    if(!this->dataObject) {
        this->logger->err("C++ compiler has no configuration data");
        return 1;
    }
    if(!this->dataObject->hasKey("projectPath")) {
        this->logger->err("C++ compiler could not find project path");
        return 1;
    } else {
        this->projectPath = this->dataObject->asDictionary().at("projectPath").asString();
    }
    return 0;
}

int Cpp_Compiler::package() {
    std::string libPaths = "";
    for(std::string libBinPath : this->libBinPaths) {
        libPaths += libBinPath + " ";
    }
    std::string command = this->compilerName + " " + libPaths + this->binPath + "/*.o -o " + this->resultPath + "/" + this->projectName;
    logger->info("Linking C++ code to executable");
    logger->debug("Linking Command: " + command);
    int result = system(command.c_str());
    if(result != 0) {
        this->logger->err("Failed to Link C++ code to executable");
        return 1;
    }
    return 0;
}

extern "C" NexisPlugin * createPlugin(nexis::NexisLogger * logger, DataObject * dataObject) {
    return new Cpp_Compiler(logger, dataObject);
}

extern "C" void destroyPlugin(NexisPlugin * plugin) {
    delete plugin;
}