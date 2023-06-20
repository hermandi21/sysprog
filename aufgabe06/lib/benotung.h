//
// Created by hermann.andreas on 25.05.23.
//

//Übersetzungseinheit "benotung" mit gleichnamiger Wertklasse
#ifndef SYSPROG_BENOTUNG_H
#define SYSPROG_BENOTUNG_H


class benotung {
    private:
    int note;

    public:
    // einen öffentlichen expliziten Konstruktor benotung(int) zum Initialisieren der Membervariablen
    static const benotung beste;
    static const benotung schlechteste;
    explicit benotung(int note);  //Standard-Konstruktor
    //benotung(const benotung&);   //Copy-Konstruktor
    //benotung(const benotung&&);  //Move-Konsturktor
    //~benotung(); //Destruktor
    //benotung& operator=(const benotung&);   //Copy-Zuweisung
    //benotung& operator=(benotung&&);        //Move-Zuweisung

    //eine öffentliche Memberfunktion int int_value(), die die im Objekt gekapselte Note liefert
    int int_value() const;

    //eine öffentliche Memberfunktion bool ist_bestanden(), die true liefert, wenn der Wert der gekapselten Note kleiner oder gleich 40 ist, sonst false
    //Frage: Warum const??
    bool ist_bestanden() const;

    //befreundete Funktion bool operator==(benotung, benotung), die true liefert, wenn beide Objekte die gleiche Noten kapseln, sonst false
    friend bool operator==(const benotung& b1, const benotung& b2);

    //für Zusatzpunkt Nr.2
    friend bool operator<(const benotung& b1, const benotung& b2);

};


#endif //SYSPROG_BENOTUNG_H
