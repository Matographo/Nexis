#include "Arguments.h"

Arguments::Arguments() : prefixSize(2) {
}

Arguments::~Arguments() {
}

void Arguments::parse(int argc, char** argv[]) {
}

std::string Arguments::getHelp() {
    std::string result;
    if(usageDescription != "") {
        result += "usage: " + usageDescription + "\n";
    }
    int maxOptionSize = findMaxOptionSize();
    result += "Options:\n";
    for(auto it = options.begin(); it != options.end(); it++) {
        result += getSpaces(prefixSize);
        std::vector<std::string> optionsList = it->getOptions();
        for(auto it2 = optionsList.begin(); it2 != optionsList.end(); it2++) {
            result += *it2;
            if(it2 != optionsList.end() - 1) {
                result += ",";
            }
        }
    }
}

bool Arguments::isHelp() {
    return help;
}

bool Arguments::has(std::string option) {
    for(auto it = options.begin(); it != options.end(); it++) {
        if(it->has(option)) {
            return true;
        }
    }
}

void Arguments::add(std::string option) {
    options.emplace_back(option);
}

void Arguments::add(std::string option, std::string description) {
    options.emplace_back(option, description);
}

void Arguments::setUsageDescription(std::string usageDescription) {
    this->usageDescription = usageDescription;
}

int Arguments::findMaxOptionSize() {
    int max = 0;
    for(auto it = this->options.begin(); it != this->options.end(); it++) {
        std::vector<std::string> optionsList = it->getOptions();
        int argumentsSize = 0;
        for(auto it2 = optionsList.begin(); it2 != optionsList.end(); it2++) {
            argumentsSize += it2->size();
        }
        
        argumentsSize += optionsList.size() - 1;
        
        argumentsSize += prefixSize;
        

        if(argumentsSize > max) {
            max = argumentsSize;
        }
    }
}

std::string Arguments::getSpaces(int size) {
    std::string result;
    for(int i = 0; i < size; i++) {
        result += " ";
    }
    return result;
}