#ifndef LIFECYCLE_EXECUTER_H
#define LIFECYCLE_EXECUTER_H

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include "NexisLogger.h"

class LifecycleExecuter {
private:
    nexis::NexisLogger * logger;
    std::map<std::string, std::vector<std::shared_ptr<void>>> plugins;
    
    int clean();
    int start();
    int validate();
    int compile();
    int test();
    int package();
    int deploy();
    
    struct LifecycleTasks {
        bool clean    = false;
        bool start    = false;
        bool validate = false;
        bool compile  = false;
        bool test     = false;
        bool package  = false;
        bool deploy   = false;
    };

    LifecycleTasks getLifecycleTasks(int cycleTasks);

    int executeTask(std::string &taskName, std::function<int(void*)> functionName);

    
public:
    LifecycleExecuter(std::map<std::string, std::vector<std::shared_ptr<void>>> plugins, nexis::NexisLogger * logger);
    ~LifecycleExecuter();
    
    int startLifecycle(int cycleTasks);
};


#endif