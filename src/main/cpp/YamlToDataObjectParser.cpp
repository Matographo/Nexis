#include "YamlToDataObjectParser.h"

namespace {
    
    // Diese Funktion ist nur in dieser Datei sichtbar
    DataObject parseYAMLNode(const YAML::Node& node) {
        if (node.IsScalar()) {
            try {
                return DataObject::createInt(node.as<int>());
            } catch (...) {
                try {
                    return DataObject::createFloat(node.as<float>());
                } catch (...) {
                    try {
                        return DataObject::createBool(node.as<bool>());
                    } catch (...) {
                        return DataObject::createString(node.as<std::string>());
                    }
                }
            }
        } else if (node.IsSequence()) {
            DataObject list = DataObject::createList();
            for (std::size_t i = 0; i < node.size(); i++) {
                list.addToList(parseYAMLNode(node[i]));
            }
            return list;
        } else if (node.IsMap()) {
            DataObject dict = DataObject::createDictionary();
            for (YAML::const_iterator it = node.begin(); it != node.end(); ++it) {
                dict.addToDictionary(it->first.as<std::string>(), parseYAMLNode(it->second));
            }
            return dict;
        }

        // Fallback für den Fall, dass der Knoten einen unbekannten Typ hat
        return DataObject::createString("");
    }

    std::string getIncludePath(const std::string& path) {
        return std::filesystem::path(path).parent_path().string();
    }

    YAML::Node process_includes(YAML::Node baseNode, const std::string& base_path) {
        if (baseNode.IsMap()) {
            std::map<std::string, YAML::Node> nodesToInclude;
            for (YAML::const_iterator baseNodeIt = baseNode.begin(); baseNodeIt != baseNode.end(); ++baseNodeIt) {
                const std::string baseNodeKey = baseNodeIt->first.as<std::string>();
                YAML::Node baseNodeValue      = baseNodeIt->second;

                if (baseNodeKey == "include") {
                    if(baseNodeValue.IsScalar()) {
                        std::string include_file = base_path + "/" + baseNodeIt->second.as<std::string>();

                        YAML::Node included_yaml = YAML::LoadFile(include_file);
                        if(included_yaml && included_yaml["includes"]) {
                            if(included_yaml["includes"].IsScalar() && included_yaml["includes"].as<bool>() == true) {
                                included_yaml.remove("includes");
                                included_yaml = process_includes(included_yaml, getIncludePath(include_file));
                            }
                        }

                        for(YAML::const_iterator all_include_it = included_yaml.begin(); all_include_it != included_yaml.end(); ++all_include_it) {
                            nodesToInclude[all_include_it->first.as<std::string>()] = all_include_it->second;
                        }

                    } else if(baseNodeIt->second.IsSequence()) {
                        for (YAML::Node include : baseNodeIt->second) {
                            std::string include_file = base_path + "/" + include.as<std::string>();

                            YAML::Node included_yaml = YAML::LoadFile(include_file);
                            if(included_yaml && included_yaml["includes"]) {
                                if(included_yaml["includes"].IsScalar() && included_yaml["includes"].as<bool>() == true) {
                                    included_yaml.remove("includes");
                                    included_yaml = process_includes(included_yaml, getIncludePath(include_file));
                                }
                            }
                            
                            for(YAML::const_iterator all_include_it = included_yaml.begin(); all_include_it != included_yaml.end(); ++all_include_it) {
                                nodesToInclude[all_include_it->first.as<std::string>()] = all_include_it->second;
                            }

                        }
                    } else if (baseNodeIt->second.IsMap()) {
                        for (YAML::const_iterator include_it = baseNodeIt->second.begin(); include_it != baseNodeIt->second.end(); ++include_it) {

                            const std::string include_key = include_it->first.as<std::string>();
                            std::string include_file = base_path + "/" + include_it->second.as<std::string>();

                            YAML::Node included_yaml = YAML::LoadFile(include_file);
                            if(included_yaml && included_yaml["includes"]) {
                                if(included_yaml["includes"].IsScalar() && included_yaml["includes"].as<bool>() == true) {
                                    included_yaml.remove("includes");
                                    included_yaml = process_includes(included_yaml, getIncludePath(include_file));
                                }
                            }
                            
                            nodesToInclude[include_key] = included_yaml;

                            //for(YAML::const_iterator all_include_it = included_yaml.begin(); all_include_it != included_yaml.end(); ++all_include_it) {
                            //    nodesToInclude[all_include_it->first.as<std::string>()] = all_include_it->second;
                            //}

                        }
                    }

                } else {
                    // Rekursiv alle inneren Elemente durchgehen
                    baseNode[baseNodeKey] = process_includes(baseNode[baseNodeKey], base_path);
                }
            }
            for(auto& [key, value] : nodesToInclude) {
                baseNode[key] = value;
            }
        } else if (baseNode.IsSequence()) {
            for (std::size_t i = 0; i < baseNode.size(); ++i) {
                baseNode[i] = process_includes(baseNode[i], base_path);
            }
        }

        return baseNode;
    }
    
}

DataObject parseYaml(const std::string& base_path) {
    YAML::Node root = YAML::LoadFile(base_path);
    if(root && root["includes"]) {
        if(root["includes"].IsScalar() && root["includes"].as<bool>() == true) {
            root.remove("includes");
            root = process_includes(root, getIncludePath(base_path));
        }
    }
    return parseYAMLNode(root);
}