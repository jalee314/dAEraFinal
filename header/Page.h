#ifndef PAGE_H
#define PAGE_H

#include <iostream>

class Page {
    private:
        std::string words;
        unsigned pageNum;
    public:
        Page() : pageNum(0) {}
        Page(unsigned n) : pageNum(n) {}
        Page(std::string w, unsigned n) : words(w), pageNum(n) {}
        void output(); // outputs words and pageNum at the end
        int getPageNum();
};

#endif //PAGE_H
