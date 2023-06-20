//
// Created by hermann.andreas on 25.05.23.
//

#ifndef SYSPROG_FACHNOTE_H
#define SYSPROG_FACHNOTE_H

#include <string>
#include <stdexcept>
#include "benotung.h"

class fachnote {
public:
    const std::string fach;
    const benotung note;

    fachnote(const std::string&, const benotung&);

    fachnote(const fachnote&) = delete; //Copy-Konstruktor
    fachnote &operator=(const fachnote&) = delete;
    fachnote(fachnote&&) = delete;
    fachnote &operator=(fachnote&&) = delete;
};

#endif //SYSPROG_FACHNOTE_H

