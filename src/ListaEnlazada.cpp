#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
    cabeza = NULL;
}

void ListaEnlazada::set_cabeza(bala* n)
{
    cabeza = n;
}

bala* ListaEnlazada::get_cabeza()
{
    return cabeza;
}

bala* ListaEnlazada::get_ultimo()
{
    bala* ultimo=get_cabeza();

    while(ultimo->get_enlace()!=NULL)
    {
        ultimo=ultimo->get_enlace();
    }
    return ultimo;

}


void ListaEnlazada::agregarbala(bala** n)
{
    if(cabeza->get_enlace()==NULL)
    {
        cabeza->set_enlace(*n);
    }
    else
    {
        get_ultimo()->set_enlace(*n);
    }
}





ListaEnlazada::~ListaEnlazada()
{
    //dtor
}
