//
// Created by hermann.andreas on 25.05.23.
//

//Übersetzungseinheit "benotung" mit gleichnamiger Wertklasse


#include "benotung.h"
#include "stdexcept"


//zwei öffentliche konstante statische Membervariablen
const benotung benotung::beste = benotung(10);
const benotung benotung::schlechteste = benotung(50);

//Konsturktor Implmentation
benotung::benotung(int note) 
    :note(note)
    {
        switch(note)
        {
            case 10:
            case 13:
            case 17:
            case 20:
            case 23:
            case 27:
            case 30:
            case 33:
            case 37:
            case 40:
            case 50:
                break;

            //bei unzulässiger Note eine Ausnahme vom Typ std::invalid_argument
            default:
                throw std::invalid_argument("unzulässige Note");
                break;
        }
    }


/*//Destruktor Implementation
benotung::~benotung() {}*/

//Implementierung: eine öffentliche Memberfunktion int int_value(), die die im Objekt gekapselte Note liefert
int benotung::int_value() const
{
    return this->note;
}

//Implementierung: eine öffentliche Memberfunktion bool ist_bestanden(), die true liefert, wenn der Wert der gekapselten Note kleiner oder gleich 40 ist, sonst false
bool benotung::ist_bestanden() const
{
    return this->note < schlechteste.int_value();
}

//Implementierung: befreundete Funktion bool operator==(benotung, benotung), die true liefert, wenn beide Objekte die gleiche Noten kapseln, sonst false
// friend Funktionen werden ohne Klassenname definiert und aufgerufen:
bool operator==(const benotung& b1, const benotung& b2)
{
    //Frage: Kann ich die Funktion "int_value()" nur auf die Speicheradresse der Variablen note anwenden??
    return b1.int_value() == b2.int_value();
}

bool operator<(const benotung& b1, const benotung& b2)
{
    return b1.int_value() < b2.int_value();
}

