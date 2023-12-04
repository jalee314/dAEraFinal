#include "../header/Journal.h"

void Journal::outputPage(unsigned p) { this->pages.at(p).output(); }

void Journal::addPage(Page p) { this->pages.push_back(p); }
