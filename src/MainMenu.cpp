#include "../header/MainMenu.h"
#include <stdlib.h>

void MainMenu::output() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "                                        dÆRA" << std::endl;
    std::cout << " 1.   Start Game" << std::endl;
    std::cout << " 2.   Exit" << std::endl;
}

void MainMenu::quit() {
    exit(0);
}