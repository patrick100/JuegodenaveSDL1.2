#include "bala.h"

bala::bala()
{
    Nave nav;
    ndisparos = 5;
    bala1 = SDL_LoadBMP("bala1.bmp");
    SDL_SetColorKey(bala1, SDL_SRCCOLORKEY,SDL_MapRGB(bala1->format, 255, 255, 255));
    disparar = true;
    balax = 0;
    balay = 0;
    caja3.w=20;
    caja3.h=20;

}

void bala::set_enlace(bala* n)
{
    enlace = n;
}

bala* bala::get_enlace()
{
    return enlace;
}




SDL_Surface* bala::get_bala()
{
    return bala1;
}



void bala::moverbala()
{
    balay -= 35;
    if(balay<0)
        disparar = false;
        //delete bala1;
        //balay = 680;
    caja3.x=balax;
    caja3.y=balay;
}


bala::~bala()
{
    //dtor
}
