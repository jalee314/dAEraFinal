#ifndef PAGE_H
#define PAGE_H

class Page {
    private:
        std::string words;
        unsigned pageNum;
        unsigned numRows;
    public:
        Page() : pageNum(0), numRows(0) {}
        Page(unsigned n) : pageNum(n), numRows(0) {}
        Page(std::string w, unsigned n) : 
        words(w),
        pageNum(n),
        numRows(w.length() / 110) {}
        void output(); // outputs words and pageNum at the end, wraps words at a value around the num of columns in terminal (110)
        int getPageNum();
        int getNumRows();
};

#endif //PAGE_H
