#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include "../header/Page.h"

class Journal {
    private:
        std::vector<Page> pages;
        unsigned numPages; // One page is immediately given at the start. Maximum number is three.
    public:
        Journal() : numPages(1) {
            pages.push_back(Page("   The Free finally did it. They hit the lab—blew it to smithereens. Now that goddamned thing's on the loose.\n\n   I know the government's a shitty mess and that they're a bunch of corrupt, espionage-obsessed freaks. But what the hell do we have to do with that?\n\n   Maybe it's because we're all complicit, serving the system. Still... I don't want to die. I don't deserve to die.\n\n   They're lucky that the explosion didn't damage the hull. Or maybe that makes us all unlucky sons of bitches.\n\n   I don't know what's become of my comrades. I don't even know if anybody's going to be able to read this.\n\n   God, just please let me get out of this.", 1));
        }
        unsigned getNumPages();
        void outputPage(unsigned);
        void addPage(Page p);
};

#endif //JOURNAL_H
