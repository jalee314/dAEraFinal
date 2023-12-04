#ifndef BASAR_H
#define BASAR_H

#include <iostream>
#include <vector>
#include "Journal.h"
#include "Page.h"

class Basar {
    private:
        unsigned playerAffinity; // Can only be 1 - 3, affects responses
        Journal journal;
        std::vector<std::string> responses;
    public:
        Basar() : playerAffinity(2) {}
        void outputBasarScreen(); // Outputs main Basar screen.
        void outputJournalScreen(); // Outputs the Journal screen via which you can access each individual page.
        void outputResponse(int); // Outputs a response from std::vector<std::string> responses.
        unsigned getAffinity(); // Retrieves the player affinity level.
        void decreaseAffinity(); // Decrements playerAffinity by 1.
        void increaseAffinity(); // Increments playerAffinity by 1.
        void addPage(Page); // Adds a new page to the journal.
};

#endif //BASAR_H
