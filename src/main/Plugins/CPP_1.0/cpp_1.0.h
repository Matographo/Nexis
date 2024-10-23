#ifndef CPP_1_H
#define CPP_1_H

#include <filesystem>

#include "Interfaces/Lifecycles/CompileTask.h"
#include "Interfaces/Lifecycles/ValidateTask.h"
#include "Interfaces/Lifecycles/PackageTask.h"
#include "Interfaces/Lifecycles/PreCompileTask.h"

#include "Interfaces/Utilities/NexisLogger.h"
#include "DataObject.h"
#include "Interfaces/Utilities/NexisPlugin.h"

class Cpp_Compiler : public NexisPlugin, public CompileTask, public ValidateTask, 
                     public PackageTask, public PreCompileTask {
  public:
    Cpp_Compiler(nexis::NexisLogger *logger, DataObject *config, DataObject *properties);
    Cpp_Compiler(Cpp_Compiler &&) = default;
    Cpp_Compiler(const Cpp_Compiler &) = default;
    Cpp_Compiler &operator=(Cpp_Compiler &&) = default;
    Cpp_Compiler &operator=(const Cpp_Compiler &) = default;
    ~Cpp_Compiler();
    
    int compile() override;
    int validate() override;
    int package() override;
    int preCompile() override;


  private:
    std::vector<std::string> cppFilePaths;
    std::vector<std::string> libBinPaths;
    
    std::string projectPath;
    std::string includeString;
    std::string compilerName;
    std::string projectName;
    std::string binPath;
    std::string resultPath;
    std::string srcPath;

    

    bool isFileUpToDate(std::string filePath, std::string pathToCompare);
    void findAllCppFiles(std::string path, std::vector<std::string> * cppFiles);
    bool endsWith(const std::string &filePath, const std::string &suffix);
    void findAllIncludeFiles(std::string path);
    void findAllDirectories(std::string path, std::vector<std::string> * directories);
    
    int compileLibrary(std::string libraryPath);

};

#endif // CPP_1_H