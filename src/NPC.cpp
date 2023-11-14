#include "../header/NPC.h"
#include <iostream>

void NPC::addResponse(const std::string& response) {
    responses.push_back(response);
}

void NPC::addQuestion(const std::string& question) {
    askableQuestions.push_back(question);
}

void NPC::printName() {
    std::cout << this->name << "\n";
}

void NPC::printResponse(int index) {xw
    if(index >= 0 && index < responses.size()) {
        std::cout << responses[questionIndex] << "\n";
    }
    else std:: cout << "I am unable to answer your question." << "\n";
}

/* this is a temporary implementation from my understanding of what the NPC character is to do 
basically printResponse is totally up for change if its dependent on an algorithm that 
finds the most appropriate response to a question */
