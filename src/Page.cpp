#include "../header/Page.h"

void Page::output() {
    std::cout << this->words;
    std::cout << "\n\n\n\n\n" << this->getPageNum();

    std::cout << "                                         To read more, press ENTER" << std::endl;
}

int Page::getPageNum() { return this->pageNum; }
