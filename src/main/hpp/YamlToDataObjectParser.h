#ifndef YAML_TO_DATA_OBJECT_PARSER_H
#define YAML_TO_DATA_OBJECT_PARSER_H

#include <string>
#include "DataObject.h"
#include "yaml-cpp/yaml.h"

DataObject parseYaml(const std::string& yamlContent);

#endif