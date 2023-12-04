#include "../header/Basar.h"

void Basar::outputBasarScreen() {
    std::cout << "\n\n\n\n";
    std::cout << "                                                                    BASAR" << std::endl;
    std::cout << "\n\n\n\n" << "1. access journal" << "\n\n\n\n" << "2. speak to BASAR" << "\n\n\n\n" << "3. return to game" << "\n\n\n\n" << "4. exit to main menu" << "\n\n\n\n" << "5. exit game";
}

void Basar::outputJournalScreen() {
    std::cout << "";
}

void Basar::outputResponse(int) {
    std::cout << "t";
}

unsigned Basar::getAffinity() { return this->playerAffinity; }

void Basar::decreaseAffinity() { if (this->playerAffinity > 1) this->playerAffinity--; }

void Basar::increaseAffinity() { if (this->playerAffinity < 3) this->playerAffinity++; }
