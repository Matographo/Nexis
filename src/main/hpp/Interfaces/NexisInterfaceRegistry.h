#ifndef NEXIS_INTERFACE_REGISTRY_H
#define NEXIS_INTERFACE_REGISTRY_H

#include <set>
#include <string>


class NexisInterfaceRegistry {
protected:
    mutable std::set<std::string> interfaces;
    
    void addInterface(std::string interface) {
        this->interfaces.insert(interface);
    }

public:
    ~NexisInterfaceRegistry() = default;
    
    std::set<std::string> getInterfaces() {
        return this->interfaces;
    }

};

#endif