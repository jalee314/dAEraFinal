#include "../header/Page.h"

void Page::output() {
    std::cout << this->words;
    std::cout << "\n\n\n\n\n" << this->getPageNum() << '\n';
    std::cout << "                                                To read more, press ENTER" << std::endl;
    std::cin.get();
}

int Page::getPageNum() { return this->pageNum; }
