#include "Meteoro.h"


Meteoro::Meteoro()
{
    meteoro = SDL_LoadBMP("meteoro.bmp");
    SDL_SetColorKey(meteoro, SDL_SRCCOLORKEY,SDL_MapRGB(meteoro->format, 255, 255, 255));
    dibujar = true;
    aste = 0;
    velAste = 0;

    ejex = 0;
    ejey = 0;

    caja1.w =67;
    caja1.h =67;
    caja1.x =0;
    caja1.y =0;

}

void  Meteoro::generar()
{
    aste = rand()%6+1;
    //ejex = rand()%700;
    ejex=0;
}

SDL_Surface* Meteoro::get_ast()
{
    return meteoro;
}


void Meteoro::movermeteoro()
{

    if(ejey > 680 or dibujar == false)
    {
        ejey = -120;
        if(ejex <=350)
            ejex = rand()%350+350;
        else
            ejex = rand()%350;
        dibujar =true;
    }

       //srand(time(0)); //genera semilla basada en el reloj del sistema
    //velAste = rand()%15+10;
    velAste = 20;
    ejey +=velAste;
    caja1.x =ejex;
    caja1.y =ejey;
    //if (ast.dibujar==true)

}



Meteoro::~Meteoro()
{
    //dtor
}
