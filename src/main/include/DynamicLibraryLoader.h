#ifndef DYANMIC_LIBRARY_LOADER_H
#define DYANMIC_LIBRARY_LOADER_H

#include <string>
#include <dlfcn.h>
#include "Interfaces/Utilities/NexisPlugin.h"

NexisPlugin * loadDynamicLibrary(std::string path, nexis::NexisLogger * logger, DataObject * dataObject);

#endif