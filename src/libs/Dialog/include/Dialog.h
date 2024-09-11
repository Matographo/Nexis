#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <map>
#include <iostream>


class Dialog {
    private:
        std::map<std::string, std::string> questions;
        std::map<std::string, std::string> answers;
        
    public:
        Dialog();
        ~Dialog();
        void addQuestionStr(std::string question, std::string key);
        void addQuestionInt(std::string question, std::string key);
        void addQuestionFloat(std::string question, std::string key);   
        void addQuestionBool(std::string question, std::string key);
        void addQuestionChar(std::string question, std::string key);
        
        void ask();
        
        std::string getAnswerStr(std::string key);
        int getAnswerInt(std::string key);
        float getAnswerFloat(std::string key);
        bool getAnswerBool(std::string key);
        char getAnswerChar(std::string key);
};

#endif