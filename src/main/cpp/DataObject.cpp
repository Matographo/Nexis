#include "DataObject.h"

DataObject::DataObject() : value(0) {}

DataObject::~DataObject() {
}

DataObject::DataObject(const DataObject& other) : value(other.value) {}

DataObject DataObject::createInt(int v) {
    return DataObject(v);
}

DataObject DataObject::createFloat(float v) {
    return DataObject(v);
}

DataObject DataObject::createBool(bool v) {
    return DataObject(v);
}

DataObject DataObject::createString(const std::string& v) {
    return DataObject(v);
}

DataObject DataObject::createDictionary() {
    return DataObject(Dictionary());
}

DataObject DataObject::createList() {
    return DataObject(List());
}

int DataObject::asInt() const {
    return std::get<int>(value);
}

float DataObject::asFloat() const {
    return std::get<float>(value);
}

bool DataObject::asBool() const {
    return std::get<bool>(value);
}

std::string DataObject::asString() const {
    return std::get<std::string>(value);
}

DataObject::Dictionary& DataObject::asDictionary() {
    return std::get<Dictionary>(value);
}

DataObject::List& DataObject::asList() {
    return std::get<List>(value);
}

void DataObject::addToList(const DataObject& obj) {
    asList().push_back(obj);
}

void DataObject::addToDictionary(const std::string& key, const DataObject& obj) {
    asDictionary().insert({key, obj});
}

bool DataObject::isInt() const {
    return std::holds_alternative<int>(value);
}

bool DataObject::isFloat() const {
    return std::holds_alternative<float>(value);
}

bool DataObject::isBool() const {
    return std::holds_alternative<bool>(value);
}

bool DataObject::isString() const {
    return std::holds_alternative<std::string>(value);
}

bool DataObject::isDictionary() const {
    return std::holds_alternative<Dictionary>(value);
}

bool DataObject::isList() const {
    return std::holds_alternative<List>(value);
}

bool DataObject::hasKey(const std::string& key) {
    return isDictionary() && this->asDictionary().find(key) != asDictionary().end();
}