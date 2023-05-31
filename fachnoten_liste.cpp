#include "fachnoten_liste.h"

//----------------------------------------------------- Klasse fachnoten_liste::element
class fachnoten_liste::element final
{
    element *next;
    fachnote* f;

    element(element *e, fachnote* fn)
            : next(e), f(fn)
    { }

    friend class fachnoten_liste;
    friend class fachnoten_liste::iterator;
};

//----------------------------------------- Member-Funktionen fachnoten_liste::iterator
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

//--------------------------------------------------- Member-Funktionen fachnoten_liste
fachnoten_liste::fachnoten_liste(void (*vFunctionCall)(fachnote*))
        : head(nullptr), vFunctionCall(vFunctionCall)
{ }

fachnoten_liste::~fachnoten_liste()
{
    element *e = this->head;
    while (e != nullptr)
    {
        element *x = e;
        e = e->next;
        delete x;
    }
}

fachnoten_liste& fachnoten_liste::insert(fachnote* f)
{
    this->head = new element(this->head, f);
    return *this;
}

fachnoten_liste::iterator fachnoten_liste::begin()
{
    return fachnoten_liste::iterator(this->head);
}

fachnoten_liste::iterator fachnoten_liste::end()
{
    return fachnoten_liste::iterator(nullptr);
}
