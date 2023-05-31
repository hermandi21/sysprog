//
// Created by hermandi on 25.05.23.
//

#include "fachnote.h"
#include "stdexcept"
#include "string"

fachnote::fachnote(const std::string& fach, const benotung& note): fach(fach), note(note)
{
    if (fach.length() == 0)
    {
        throw
                std::invalid_argument("Der Fachname muss mindestens 1 Zeichen lang sein");
    }
}