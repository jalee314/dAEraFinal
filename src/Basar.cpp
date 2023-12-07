#include "../header/Basar.h"
#include <iostream>

void Basar::outputBasarScreen() {
    unsigned selection = 0;

    while (selection < 1 || selection > 3) {
        std::cout << "                                                                      BASAR" << std::endl;
        std::cout << "\n\n\n\n\n\n\n" << "1. ACCESS JOURNAL" << "\n\n" << "2. EXIT BASAR" << "\n\n" << "3. EXIT GAME";
        std::cin >> selection;
        if (selection == 1) this->outputJournalSelectScreen();
        else if (selection == 2) return;
        else if (selection == 3) {
            std::cout << "Are you sure you want to quit the game?\n1: Yes\nAnything else: No" << std::endl;
            std::cin >> selection;
            if (selection == 1) exit(0);
            else selection = 0;
        }
        else std::cout << "SELECTION UNRECOGNIZED. PLEASE TRY AGAIN.";
    }
}

void Basar::outputJournalSelectScreen() {
    unsigned selection = 0;
    unsigned numEntries = this->journal.getNumPages();
    while (selection > numEntries || selection < 1) {
        std::cout << "                                                                      BASAR" << std::endl;
        std::cout << "\n\n\n\nSELECT ENTRY" << '\n';
        for (unsigned i = 1; i < numEntries + 1; i++) std::cout << i << ". Entry " << i << "\n\n";
        std::cout << "9. Exit" << "\n\n";
        std::cin >> selection;
        if (selection == 1) this->outputJournalScreen(1);
        else if (selection == 2 && numEntries > 1) this->outputJournalScreen(2);
        else if (selection == 3 && numEntries == 3) this->outputJournalScreen(3);
        else if (selection == 9) return;
        else std::cout << "SELECTION UNRECOGNIZED. PLEASE TRY AGAIN.";
    }
}

void Basar::outputJournalScreen(unsigned p) {
    this->journal.outputPage(p);
    std::cin.get();
}

void Basar::addPage(Page p) { this->journal.addPage(p); }
