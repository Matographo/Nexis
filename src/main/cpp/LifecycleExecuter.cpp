#include "LifecycleExecuter.h"

LifecycleExecuter::LifecycleExecuter(std::map<std::string, std::vector<std::shared_ptr<void>>> plugins, nexis::NexisLogger * logger) {
    this->plugins = plugins;
    this->logger = logger;
}

LifecycleExecuter::~LifecycleExecuter() {
    delete this->logger;
}

int LifecycleExecuter::clean() {
    return 0;
}

int LifecycleExecuter::start() {
    return 0;
}

int LifecycleExecuter::validate() {
    return 0;
}

int LifecycleExecuter::compile() {
    return 0;
}

int LifecycleExecuter::test() {
    return 0;
}

int LifecycleExecuter::package() {
    return 0;
}

int LifecycleExecuter::deploy() {
    return 0;
}


int LifecycleExecuter::startLifecycle(int cycleTasks) {
    LifecycleTasks tasks = this->getLifecycleTasks(cycleTasks);

    std::vector<std::pair<bool, std::function<int()>>> taskList = {
        {tasks.clean,    [this]() { return this->clean(); }},
        {tasks.start,    [this]() { return this->start(); }},
        {tasks.validate, [this]() { return this->validate(); }},
        {tasks.compile,  [this]() { return this->compile(); }},
        {tasks.test,     [this]() { return this->test(); }},
        {tasks.package,  [this]() { return this->package(); }},
        {tasks.deploy,   [this]() { return this->deploy(); }}
    };

    for (const auto& task : taskList) {
        if (task.first && task.second() != 0) {
            return 1;
        }
    }

    return 0;
}

LifecycleExecuter::LifecycleTasks LifecycleExecuter::getLifecycleTasks(int cycleTasks) {
    LifecycleTasks tasks;
    tasks.clean    = cycleTasks & 1;
    tasks.start    = cycleTasks & 2;
    tasks.validate = cycleTasks & 4;
    tasks.compile  = cycleTasks & 8;
    tasks.test     = cycleTasks & 16;
    tasks.package  = cycleTasks & 32;
    tasks.deploy   = cycleTasks & 64;
    return tasks;
}

int LifecycleExecuter::executeTask(std::string &taskName, std::function<int(void*)> functionName) {
    auto it = plugins.find(taskName);

    if (it == plugins.end()) {
        return 1;
    }

    for (const auto& obj : it->second) {
        if (functionName(obj.get()) != 0) {
            return 1;
        } 
    }

    return 0;
}