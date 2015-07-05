#include "Juego.h"
#include "SDL/SDL.h"

Juego::Juego()
{
    width = 800;
    high = 680;
    fondo = SDL_LoadBMP( "fondo.bmp" );
    perdiste = SDL_LoadBMP("perdiste.bmp");

}


SDL_Surface* Juego::get_perdiste()
{

    return perdiste;
}



bool Juego::colision(SDL_Rect* A, SDL_Rect* B)
{
    //EL A es es meteoro
    //El B es el usuario
    int supA, supB;
    int infA, infB;
    int izqA, izqB;
    int derA, derB;

    izqA = A->x;
    derA = A->x+A->w;
    supA = A->y;
    infA = A->y + A->h;

    supB = B->y;
    infB = B->y + B->h;
    izqB = B->x;
    derB = B->x + B->w;

    if( infA >= supB and  derA >= B->x)
    {
        return true;
    }


    else
        return false;
}


bool Juego::colision1(SDL_Rect* A, SDL_Rect* B,bool disp)
{
    //EL A es es meteoro
    //El B es el usuario
    int supA, supB;
    int infA, infB;
    int izqA, izqB;
    int derA, derB;

    izqA = A->x;
    derA = A->x+A->w;
    supA = A->y;
    infA = A->y + A->h;

    supB = B->y;
    infB = B->y + B->h;
    izqB = B->x;
    derB = B->x + B->w;

    if( infA >= supB and  izqB <= derA and disp == true)//derA >= B->x  and disp == true )
    {
        return true;
    }


    else
        return false;
}




int Juego::get_width()
{
    return width;
}

int Juego::get_high()
{
    return high;
}



SDL_Surface* Juego::get_screen()
{
    return screen;
}

SDL_Surface* Juego::get_fondo()
{
    return fondo;
}



void Juego::aplicar(int x, int y, SDL_Surface* fuente, SDL_Surface* destino)
{
    SDL_Rect temp;

    temp.x = x;
    temp.y = y;

    SDL_BlitSurface(fuente,NULL,destino,&temp);
}



void Juego::clean_up()
{
    //Libera la memoria
    SDL_FreeSurface(nave);
    SDL_FreeSurface(fondo);
    //TTF_CloseFont( font );

    //Quit SDL_ttf
    //TTF_Quit();
}



void Juego::iniciarjuego()
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_WM_SetCaption( "SPACE GAME", NULL );

    screen = SDL_SetVideoMode(width, high, 32, SDL_SWSURFACE );

    SDL_Flip(screen);


}


Juego::~Juego()
{
    //dtor
}
