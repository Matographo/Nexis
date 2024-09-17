#ifndef CLEAN_IMPL_H
#define CLEAN_IMPL_H

#include "Interfaces/Lifecycles/CleanTask.h"
#include "Interfaces/Utilities/NexisLogger.h"
#include "DataObject.h"
#include <string>
#include <filesystem>

class CleanImpl : public CleanTask {
    public:
        
        CleanImpl(nexis::NexisLogger* logger, DataObject* dataObject);
        ~CleanImpl() override;

        
        int clean() override;

    private:
        nexis::NexisLogger* logger;
        DataObject* dataObject;
};


#endif