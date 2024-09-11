#ifndef YAML_TO_DATA_OBJECT_PARSER_H
#define YAML_TO_DATA_OBJECT_PARSER_H

#include <string>
#include <iostream>
#include <filesystem>
#include "DataObject.h"
#include "yaml-cpp/yaml.h"
#include "FileReader.h"

DataObject parseYaml(const std::string& base_pathe);



#endif