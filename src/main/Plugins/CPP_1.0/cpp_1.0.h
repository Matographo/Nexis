#ifndef CPP_1_H
#define CPP_1_H

#include "CompileTask.h"
#include "TestTask.h"
#include "ValidateTask.h"
#include "PackageTask.h"
#include "DeployTask.h"

class Cpp_Compiler : public CompileTask, public TestTask, public ValidateTask, 
                     public PackageTask, public DeployTask {
  public:
    Cpp_Compiler();
    Cpp_Compiler(Cpp_Compiler &&) = default;
    Cpp_Compiler(const Cpp_Compiler &) = default;
    Cpp_Compiler &operator=(Cpp_Compiler &&) = default;
    Cpp_Compiler &operator=(const Cpp_Compiler &) = default;
    ~Cpp_Compiler();

  private:
};

#endif // CPP_1_H