#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <string>
#include <vector>


class Argument {
public:
    Argument(std::vector<std::string> options);
    Argument(std::vector<std::string> options, std::string description);
    Argument(std::vector<std::string> options, std::string description, std::vector<std::string> param);
    Argument(std::vector<std::string> options, std::vector<std::string> param);
    ~Argument();
    
    std::string getDescription();
    std::vector<std::string> getOptions();
    bool has(std::string option);
    Argument& addParam(std::string param);

private:
    std::vector<std::string> options;
    std::vector<std::string> params;
    std::string description;
};

#endif