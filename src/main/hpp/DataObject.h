#ifndef DATA_OBJECT_H
#define DATA_OBJECT_H

#include <string>
#include <vector>
#include <variant>
#include <unordered_map>
#include <stdexcept>

class DataObject {
public:
    using Dictionary = std::unordered_map<std::string, DataObject>;
    using List = std::vector<DataObject>;
    using Value = std::variant<int, float, bool, std::string, Dictionary, List>;
    
    DataObject() : value("") {}

    // Privater Konstruktor, damit Instanzen nur über die statische Methode erstellt werden können
    explicit DataObject(Value v) : value(v) {}

    // Statische Methode zur Erstellung von DataObject-Instanzen
    static DataObject createInt(int v);
    static DataObject createFloat(float v); 
    static DataObject createBool(bool v); 
    static DataObject createString(const std::string& v);
    static DataObject createDictionary();
    static DataObject createList();

    bool isInt() const;
    bool isFloat() const;
    bool isBool() const;
    bool isString() const;
    bool isDictionary() const;
    bool isList() const;

    // Methoden zur Interaktion
    int asInt() const;
    float asFloat() const;
    bool asBool() const;
    std::string asString() const;
    Dictionary& asDictionary();
    List& asList();

    void addToList(const DataObject& obj);
    void addToDictionary(const std::string& key, const DataObject& obj);
    
    bool hasKey(const std::string& key);

private:
    Value value;
};

#endif