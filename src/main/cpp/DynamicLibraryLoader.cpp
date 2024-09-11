#include "DynamicLibraryLoader.h"

NexisPlugin * loadDynamicLibrary(std::string path, nexis::NexisLogger * logger, DataObject * dataObject) {
    void * handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        logger->err("Failed to load dynamic library: " + std::string(dlerror()));
        return nullptr;
    }

    NexisPlugin * (*createPlugin)(nexis::NexisLogger *, DataObject *);
    createPlugin = (NexisPlugin * (*)(nexis::NexisLogger *, DataObject *))dlsym(handle, "createPlugin");
    if (!createPlugin) {
        logger->err("Failed to load symbol createPlugin: " + std::string(dlerror()));
        return nullptr;
    }

    NexisPlugin * plugin = createPlugin(logger, dataObject);
    if (!plugin) {
        logger->err("Failed to create plugin instance");
        return nullptr;
    }

    return plugin;
}