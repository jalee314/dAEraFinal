#include "../header/Basar.h"
#include <iostream>
#include <string>
#include <cctype>

bool isInteger(const std::string& inputString){
    for(char characters: inputString) {
        if(std::isdigit(characters) == 0) return false;
    }
    return true;
}

void Basar::outputBasarScreen() {
    std::string input; 
    unsigned selection = 0;

    while (true) {
        std::cout << "                                                                      BASAR" << std::endl;
        std::cout << "\n\n\n\n\n\n\n" << "1. ACCESS JOURNAL" << "\n\n" << "2. EXIT BASAR" << "\n\n" << "3. EXIT GAME\n\n\n";
        std::cin >> input;

        if(isInteger(input)) {
            selection = std::stoi(input);
        }
        else{
            std::cout << "\n\nBASAR ONLY TAKES NUMBERS. INPUT A NUMBER\n\n";
            continue;
        }

        if (selection == 1) this->outputJournalSelectScreen();
        else if (selection == 2) {
            std::cout << "\n\n";
            return;
        }
        else if (selection == 3) {
            std::cout << "Are you sure you want to quit the game?\n1: Yes\nAnything else: No" << std::endl;
            std::cin >> selection;
            if (selection == 1) exit(0);
            else selection = 0;
        }
        else std::cout << "\n\nSELECTION UNRECOGNIZED. PLEASE TRY AGAIN.\n";
    }
}

void Basar::outputJournalSelectScreen() {
    std::string input;
    unsigned selection = 0;
    unsigned numEntries = this->journal.getNumPages();
    while (selection > numEntries || selection < 1) {
        std::cout << "                                                                      BASAR" << std::endl;
        std::cout << "\n\n\n\nSELECT ENTRY" << "\n\n";
        for (unsigned i = 1; i < numEntries + 1; i++) std::cout << i << ". Entry " << i << "\n\n";
        std::cout << "9. Exit" << "\n\n";
        std::cin >> input;
        if(!isInteger(input)) {
            std::cout << "\n\nBASAR ONLY TAKES NUMBERS. INPUT A NUMBER\n\n";
            continue;
        }
        selection = std::stoi(input);
        if (selection > 0 && selection <= numEntries) {
            this->outputJournalScreen(selection-1);
        } 
        else if(selection == 9) {
            return;
        }
        else std::cout << "\n\nSELECTION UNRECOGNIZED. PLEASE TRY AGAIN.";
    }
}

void Basar::outputJournalScreen(unsigned p) {
    this->journal.outputPage(p);
    std::cin.get();
}

void Basar::addPage(Page p) { this->journal.addPage(p); }
