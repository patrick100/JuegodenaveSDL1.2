#ifndef NAVE_H
#define NAVE_H
#include "Juego.h"
#include <SDL/SDL.h>



class Nave:public Juego
{
    private:

    public:
        Nave();
        float x, y;
        int vidas;
        int ancho , alto;
        SDL_Rect caja2;

        int xVel , yVel;
        int get_x();
        int get_y();
        SDL_Event event;
        SDL_Surface* get_nave();

        //toma las pulsaciones de las teclas y ajusta la vel de la nave
        void press_vel1();
        void press_vel2();
        void movernave();
        void mostrar();

        virtual ~Nave();
};

#endif // NAVE_H
