#include "test.h"

Test::Test(nexis::NexisLogger *logger, DataObject *dataObject) : NexisPlugin(logger, dataObject) {
}

Test::~Test() {
}

int Test::validate() {
    this->logger->warn("Test Plugin Validate Task");
    return 0;
}

extern "C" NexisPlugin * createPlugin(nexis::NexisLogger *logger, DataObject *dataObject) {
    return new Test(logger, dataObject);
}

extern "C" void destroyPlugin(NexisPlugin *plugin) {
    delete plugin;
}