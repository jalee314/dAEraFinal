#include "../header/NPC.h"
#include <iostream>

void NPCQuestionManager::addResponse(const std::string& response) {
    responses.push_back(response);
}

void NPCQuestionManager::addQuestion(const std::string& question) {
    askableQuestions.push_back(question);
}

std::string NPCQuestionManager::getResponse(int index) {
    if(index >= 0 && index < responses.size()) {
        return responses[index];
    }
    else return "";
}

void NPCPrinter::printName() {
    std::cout << name << "\n";
}

void NPCPrinter::printResponse(int index) {
    if(index >= 0 && index < questionManager.getResponsesSize()) {
        std::cout << questionManager.getResponse(index) << "\n";

    }
    else std:: cout << "I am unable to answer your question." << "\n";
}

/* this is a temporary implementation from my understanding of what the NPC character is to do 
basically printResponse is totally up for change if its dependent on an algorithm that 
finds the most appropriate response to a question */
