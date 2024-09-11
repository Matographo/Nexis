#ifndef NEXIS_PLUGIN_H
#define NEXIS_PLUGIN_H

#include <string>
#include "Interfaces/Utilities/NexisLogger.h"
#include "Interfaces/NexisInterfaceRegistry.h"
#include "DataObject.h"

class NexisPlugin : public virtual NexisInterfaceRegistry {
public:
    NexisPlugin(nexis::NexisLogger * logger, DataObject * dataObject) : logger(logger), dataObject(dataObject) {
        addInterface("NexisPlugin");
    }
    
    virtual ~NexisPlugin() = default;

protected:
    nexis::NexisLogger * logger;
    DataObject * dataObject;
};

#endif