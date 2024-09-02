#include "Argument.h"


Argument::Argument(std::vector<std::string> options, std::string description, std::vector<std::string> param) {
    this->options     = options;
    this->description = description;
    this->params      = param;
}

Argument::Argument(std::vector<std::string> options) : Argument(options, "") {
}

Argument::Argument(std::vector<std::string> options, std::string description) : Argument(options, description, {}) {
}

Argument::Argument(std::vector<std::string> options, std::vector<std::string> param) : Argument(options, "", param) {
}

Argument::~Argument() {
}

std::string Argument::getDescription() {
    return description;
}

std::vector<std::string> Argument::getOptions() {
    return options;
}

bool Argument::has(std::string option) {
    for(auto it = options.begin(); it != options.end(); it++) {
        if(*it == option) {
            return true;
        }
    }
    return false;
}