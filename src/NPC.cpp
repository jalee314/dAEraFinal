#include "../header/NPC.h"
#include <iostream>

void NPC::addResponse(const std::string& response) {
    responses.push_back(response);
}

void NPC::addQuestion(const std::string& question) {
    askableQuestions.push_back(question);
}

void NPC::printName() {
    cout << this->name << "\n";
}

void NPC::printResponse(int index) {
    if(index >= 0 && index < responses.size()) {
        std::cout << responses[questionIndex] << "\n"
    }
    else std:: cout << "I am unable to answer your question." << "\n"
}

