#ifndef PAGE_H
#define PAGE_H

class Page {
    private:
        std::string words;
        unsigned pageNum;
    public:
        Page() : pageNum(0) {}
        Page(unsigned n) : pageNum(n) {}
        Page(std::string w, unsigned n) : words(w), pageNum(n) {}
        void output(); // outputs all words and the page number at the end,
                       // wraps the words around the size of the default
                       // terminal (120)
};

#endif //PAGE_H
