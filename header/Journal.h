#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include "../header/Page.h"

class Journal {
    private:
        std::vector<Page> pages;
    public:
        void outputPage(unsigned);
};

#endif //JOURNAL_H
