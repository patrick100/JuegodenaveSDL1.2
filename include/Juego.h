#ifndef JUEGO_H
#define JUEGO_H
#include "SDL/SDL.h"


class Juego
{
    private:
        SDL_Surface* screen = NULL;
        SDL_Surface* fondo = NULL;
        SDL_Surface* perdiste = NULL;
        int width;
        int high;

    public:
        Juego();

        int get_width();
        int get_high();


        SDL_Surface* get_screen();
        SDL_Surface* get_fondo();
        SDL_Surface* get_perdiste();

        bool colision(SDL_Rect* ,SDL_Rect*);

        bool colision1(SDL_Rect* ,SDL_Rect*,bool);

        void aplicar(int,int,SDL_Surface*,SDL_Surface*);

        void iniciarjuego();
        void clean_up();
        virtual ~Juego();
    protected:
        SDL_Surface* nave = NULL;




};

#endif // JUEGO_H
