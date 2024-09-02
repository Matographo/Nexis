#ifndef NEXIS_BUILDER_H
#define NEXIS_BUILDER_H

#include <string>
#include <vector>
#include "NexisLogger.h"

namespace nexis
{
    
} // namespace nexis

class NexisBuilder {
private:
    nexis::NexisLogger& log;
public:
    NexisBuilder(nexis::NexisLogger& nlog);
    ~NexisBuilder();
};

#endif // NEXIS_BUILDER_H