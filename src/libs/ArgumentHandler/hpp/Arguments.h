#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <map>
#include "Argument.h"

class Arguments {
public:
    Arguments();
    ~Arguments();
    void parse(int argc, char** argv[]);
    std::string getHelp();
    bool isHelp();
    bool has(std::string option);
    void add(std::string option);
    void add(std::string option, std::string desctiption);
    void add(std::string option, int priority);
    void add(std::string option, std::string description, int priority);
    void setUsageDescription(std::string usageDescription);

private:
    bool help;
    const int prefixSize;
    std::string usageDescription;
    std::vector<Argument> options;
    
    int findMaxOptionSize();
    std::string getSpaces(int size);
};

#endif