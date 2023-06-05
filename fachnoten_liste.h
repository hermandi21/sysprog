//
// Created by hermann.andreas on 25.05.23.
//

#ifndef SYSPROG_FACHNOTEN_LISTE_H
#define SYSPROG_FACHNOTEN_LISTE_H

#include "fachnote.h"


class fachnoten_liste final
{
private:
    class element;
    element *head;


public:
    //statt eines Standardkonstruktors soll es einen expliziten Konstruktor mit einem Parameter geben
    explicit fachnoten_liste(void(fachnote*));
    //Destruktor
    ~fachnoten_liste();

    //Die Entitätsklassen sollen nicht kopierbar oder verschiebbar sein, deshalb "=delete"
    fachnoten_liste(const fachnoten_liste&) = delete;
    fachnoten_liste& operator=(const fachnoten_liste&) = delete;

    fachnoten_liste(const fachnoten_liste&&) = delete;
    fachnoten_liste& operator=(fachnoten_liste&&) = delete;

    //wichtig
    fachnoten_liste& insert(fachnote*);

    //Iterator
    class iterator final
    {
    private:
        element *current;
        explicit iterator(element*);
    public:
        bool operator!=(const iterator&) const;
        fachnote*& operator*() const;
        iterator& operator++();

        friend class fachnoten_liste;
    };

    //Fabrikfunktionen für Iteratoren (müssen so heißen)
    iterator begin();
    iterator end();
};


#endif //SYSPROG_FACHNOTEN_LISTE_H
