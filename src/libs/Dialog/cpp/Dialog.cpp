#include "Dialog.h"

Dialog::Dialog() {
    questions = std::map<std::string, std::string>();
    answers   = std::map<std::string, std::string>();
}

Dialog::~Dialog() {
    questions.clear();
    answers.clear();
}

void Dialog::addQuestionStr(std::string question, std::string key) {
    questions[key] = question;
}

void Dialog::addQuestionInt(std::string question, std::string key) {
    questions[key] = question;
}

void Dialog::addQuestionFloat(std::string question, std::string key) {
    questions[key] = question;
}

void Dialog::addQuestionBool(std::string question, std::string key) {
    questions[key] = question;
}

void Dialog::addQuestionChar(std::string question, std::string key) {
    questions[key] = question;
}

void Dialog::ask() {
    for(auto it = questions.begin(); it != questions.end(); it++) {
        std::string answer;
        std::cout << it->second << std::endl;
        std::cin >> answer;
        answers[it->first] = answer;
    }
}