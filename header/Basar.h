#ifndef BASAR_H
#define BASAR_H

#include <iostream>
#include <vector>
#include "Journal.h"
#include "Page.h"

class Basar {
    private:
        Journal journal;
    public:
        void outputBasarScreen(); // Outputs main Basar/pause screen.
        void outputJournalSelectScreen(); // Outputs the Journal screen via which you can access each individual page.
        void outputJournalScreen(unsigned); // Outputs the Journal selection.
        void addPage(Page); // Adds a new page to the journal.
};

#endif //BASAR_H
