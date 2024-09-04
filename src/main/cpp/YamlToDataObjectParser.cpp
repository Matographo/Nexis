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
}

DataObject parseYaml(const std::string& yamlContent) {
    YAML::Node root = YAML::Load(yamlContent);
    return parseYAMLNode(root);
}