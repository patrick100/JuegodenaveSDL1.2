#ifndef METEORO_H
#define METEORO_H
#include <Juego.h>
#include <stdlib.h>
#include <time.h>


class Meteoro
{
    private:
    public:
        Meteoro();
        int aste;
        bool dibujar;

        SDL_Rect caja1;

        int velAste;
        int ejex;
        int ejey;
        void generar();
        SDL_Surface *meteoro;
        SDL_Surface * get_ast();
        void movermeteoro();
        virtual ~Meteoro();

};

#endif // METEORO_H
