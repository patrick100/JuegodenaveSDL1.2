#ifndef BALA_H
#define BALA_H
//#include <Juego.h>
#include <SDL/SDL.h>
#include <Nave.h>

class bala:public Nave
{
    private:
        SDL_Surface* bala1 = NULL;
    public:
        bala();
        bala* enlace;
        bool disparar;
        int balax;
        int balay;
        SDL_Surface* get_bala();

        void set_enlace(bala*);
        bala* get_enlace();

        SDL_Rect caja3;
        void moverbala();

        virtual ~bala();

};

#endif // BALA_H
