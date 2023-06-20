//
// Created by hermann.andreas on 25.05.23.
//


//Folie 5-35
#include "fachnoten_liste.h"

//---------------------------------------Member-Funktion fachnote_liste::element
class fachnoten_liste::element final
{
    element *next;
    fachnote* f;

    element(element *e, fachnote* m) : next(e), f(m)
    { }
    friend class fachnoten_liste;
    friend class fachnoten_liste::iterator;
};
//------------------------------------------------------- Member-Funktionen fachnoten_liste::iterator
fachnoten_liste::iterator::iterator(element *e)
        : current(e)
{ }

bool fachnoten_liste::iterator::operator!=(const iterator& i) const
{
    return this->current != i.current;
}

fachnote*& fachnoten_liste::iterator::operator*() const
{
    return this->current->f;
}

fachnoten_liste::iterator& fachnoten_liste::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

//-------------------------------------------------------- Member-Funktion fachnote_liste

//Ab c11 schreibt man nullptr statt NULL
fachnoten_liste::fachnoten_liste(void (*functionPointer)(fachnote*))
        : head(nullptr), functionPointer(functionPointer)
{ }

//Destruktor
//fachnoten_liste::insert wird Heapspeicher für die Listenelemente allokiert,
// dieser wird hier im Destruktor wieder freigegeben
fachnoten_liste::~fachnoten_liste()
{
    element *e = this->head;
    while (e != nullptr)
    {
        element *x = e;
        e = e->next;

        //Um das Speicherleck zu schließen
        functionPointer(x->f);

        delete x;
    }
}

//alte insert-Methode
fachnoten_liste& fachnoten_liste::insert(fachnote* f)
{
    this->head = new element(this->head, f);
    return *this;
}

/*//insert-Methode welche aufsteigend im Wert einfügt
fachnoten_liste& fachnoten_liste::insert(fachnote* f)
{
    element* current = head;
    if(head == nullptr || *f < *(head->f))
    {
        head = new element(head, f);
    }
    else
    {
        element* current = head;
        while (current->next != nullptr && !((f* < current->next->f)))
        {

        }
    }
}*/

fachnoten_liste::iterator fachnoten_liste::begin()
{
    return fachnoten_liste::iterator(this->head);
}

fachnoten_liste::iterator fachnoten_liste::end()
{
    return fachnoten_liste::iterator(nullptr);
}


