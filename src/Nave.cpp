#include "Nave.h"



Nave::Nave()
{
    vidas = 5;
    nave = SDL_LoadBMP("nave1.bmp");
    SDL_SetColorKey(nave, SDL_SRCCOLORKEY,SDL_MapRGB(nave->format, 255, 255, 255));
    ancho = 120;
    alto = 120;

    x=500;
    y=500;

    caja2.w=90;
    caja2.h=90;

    xVel = 0;
    yVel = 0;

}


int Nave::get_x()
{
    return x;
}

int Nave::get_y()
{
    return y;
}

SDL_Surface* Nave::get_nave()
{
    return nave;
}







void Nave::movernave()
{
    Juego j;
    //Move the dot left or right
    x += xVel;

    if( x < 0 )
    {
       x = j.get_width()-ancho;
    }
    else if ( x + ancho > j.get_width() )
    {
        x = 0;
    }

    y += yVel;

    if( y < 0 )
    {
        y = j.get_high()-alto-yVel;

    }

    else if ( y + alto > j.get_high() )
    {
        //move back
        y = 0;
    }

    caja2.x=x;
    caja2.y=y;

}


void Nave::mostrar()
{
    Juego jk;
    jk.aplicar(x,y,nave,jk.get_screen());
}


Nave::~Nave()
{
    //dtor
}
