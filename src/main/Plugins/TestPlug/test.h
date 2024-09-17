#ifndef TEST_H
#define TEST_H

#include <string>
#include <Interfaces/Lifecycles/ValidateTask.h>
#include <Interfaces/Utilities/NexisLogger.h>
#include <Interfaces/Utilities/NexisPlugin.h>
#include <DataObject.h>

class Test : public ValidateTask, public NexisPlugin {
  public:
    Test(nexis::NexisLogger *logger, DataObject *dataObject);
    Test(Test &&) = default;
    Test(const Test &) = default;
    Test &operator=(Test &&) = default;
    Test &operator=(const Test &) = default;
    ~Test();
    
    int validate() override;

  private:

};

#endif // TEST_H