#ifndef NEXIS_PLUGIN_H
#define NEXIS_PLUGIN_H

#include <string>
#include "Interfaces/Utilities/NexisLogger.h"
#include "Interfaces/NexisInterfaceRegistry.h"
#include "DataObject.h"

class NexisPlugin : public virtual NexisInterfaceRegistry {
public:
    NexisPlugin(nexis::NexisLogger * logger, DataObject * config, DataObject * properties) : logger(logger), config(config), properties(properties) {
        addInterface("NexisPlugin");
    }
    NexisPlugin(const NexisPlugin&) = default;
    
    virtual ~NexisPlugin() = default;

protected:
    nexis::NexisLogger * logger;
    DataObject * config;
    DataObject * properties;
};

#endif