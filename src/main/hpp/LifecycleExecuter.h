#ifndef LIFECYCLE_EXECUTER_H
#define LIFECYCLE_EXECUTER_H

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include "NexisLogger.h"
#include "PluginStructs.h"

#include "Interfaces/Events/Before/BeforeCleanTask.h"

class LifecycleExecuter {
private:
    nexis::NexisLogger * logger;
    PluginStruct plugins;
    
    int clean();
    int run();
    int validate();
    int compile();
    int test();
    int package();
    int deploy();
    
    struct LifecycleTasks {
        bool clean    = false;
        bool run      = false;
        bool validate = false;
        bool compile  = false;
        bool test     = false;
        bool package  = false;
        bool deploy   = false;
    };

    LifecycleTasks getLifecycleTasks(int cycleTasks);

    
public:
    LifecycleExecuter(PluginStruct * plugins, nexis::NexisLogger * logger);
    ~LifecycleExecuter();
    
    int startLifecycle(int cycleTasks);
};


#endif