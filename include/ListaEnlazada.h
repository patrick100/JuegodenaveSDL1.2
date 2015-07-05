#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "bala.h"
#include "Meteoro.h"


class ListaEnlazada: public bala , public Meteoro
{
    public:
        bala* cabeza;

        void agregarbala(bala**);
        bala* get_ultimo();

        void set_cabeza(bala*);
        bala* get_cabeza();
        ListaEnlazada();
        virtual ~ListaEnlazada();
    protected:
    private:
};

#endif // LISTAENLAZADA_H
