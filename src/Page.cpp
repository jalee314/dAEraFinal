#include "../header/Page.h"

void Page::output() {
    std::cout << this->words;
    std::cout << "\n\n\n\n\n" << this->getPageNum() << '\n';
    std::cout << "                                                press ENTER to finish reading" << std::endl;
    std::cin.get();
}

int Page::getPageNum() { return this->pageNum; }
