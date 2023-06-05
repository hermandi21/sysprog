//
// Created by hermann.andreas on 25.05.23.
//

#ifndef SYSPROG_FACHNOTE_H
#define SYSPROG_FACHNOTE_H


#include <string>
#include <stdexcept>
#include "benotung.h"

class fachnote {
    // zwei öffentliche konstante Membervariablen fach vom Typ std::string und note vom Typ benotung zum Speichern eines Fachnamens mit Note
public:
    const std::string fach;
    const benotung note;

    // einen öffentlichen Konstruktor fachnote(const std::string&, const benotung&) zum Initialisieren der Membervariablen
    fachnote(const std::string&, const benotung&);


// impliziten Memberfunktionen die man mit = delete unterdrücken müssen
//weil
//der Compiler soll unter keinen Umständen einen Copy-Konstruktor automatisch erzeugen : Entitäten sollen nicht verschiebbar und kopierbar sein
    fachnote &operator=(const fachnote&) = delete;
    fachnote(fachnote&&) = delete;
    fachnote &operator=(fachnote&&) = delete;
private:

};


#endif //SYSPROG_FACHNOTE_H
