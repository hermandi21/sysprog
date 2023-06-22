//
// Created by hermann.andreas on 25.05.23.
//

#include "fachnote.h"
#include "stdexcept"
#include "string"

//Der Fachname darf nicht die Länge 0 haben. Werfen Sie eine Ausnahme vom Typ std::invalid_argument, wenn diese Konsistenzregel verletzt ist.
fachnote::fachnote(const std::string& fach, const benotung& note): fach(fach), note(note)
{
    if (fach.length()== 0)
    {
        throw std::invalid_argument("Fachname muss mindestens 1 Zeichen lang sein");
    }
}