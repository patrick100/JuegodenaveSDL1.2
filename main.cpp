#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "Juego.h"
#include "Nave.h"
#include "bala.h"
#include "Meteoro.h"
#include "ListaEnlazada.h"

int main( int argc, char* args[] )
{
    bool perder=false;
    bool reiniciar = false;

    bool quit = false;
    Juego obj;
    obj.iniciarjuego();

    Mix_Music *sonido;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    sonido = Mix_LoadMUS("disparo.wav");


    Mix_Music *sonido2;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    sonido2 = Mix_LoadMUS("choque.wav");

    Mix_Music *sonido3;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    sonido3 = Mix_LoadMUS("llorar.wav");


    Nave *nav;
    nav = new Nave();
    Meteoro ast;
    Meteoro ast1;

    ListaEnlazada *cadena= new ListaEnlazada();
    bala *aux;

    aux = new bala;

    while(quit == false)
    {


        SDL_Delay(50);
        while( SDL_PollEvent(&nav->event))
        {


            if( nav->event.type == SDL_KEYDOWN )
            {


                switch( nav->event.key.keysym.sym )
                {
                    case SDLK_UP: nav->yVel -= nav->alto / 3; break;
                    case SDLK_DOWN: nav->yVel += nav->alto / 3; break;
                    case SDLK_LEFT: nav->xVel -= nav->ancho / 3; break;
                    case SDLK_RIGHT: nav->xVel += nav->ancho / 3; break;
                    case SDLK_z:aux->disparar = true;
                    default: break;
                }

            }

            else if( nav->event.type == SDL_KEYUP )
            {
                switch( nav->event.key.keysym.sym )
                {
                    case SDLK_UP: nav->yVel += nav->alto / 3; break;
                    case SDLK_DOWN: nav->yVel -= nav->alto / 3; break;
                    case SDLK_LEFT: nav->xVel += nav->ancho / 3; break;
                    case SDLK_RIGHT: nav->xVel -= nav->ancho / 3; break;
                    case SDLK_z: //aux->disparar = true;
                    default: break;

                }

            }

            if(nav->event.type == SDL_QUIT)
            {
                quit = true;
            }

        }




            //SDL_FillRect( obj.get_screen(), &obj.get_screen()->clip_rect, SDL_MapRGB( obj.get_screen()->format, 0, 0, 0 ) );
            obj.aplicar(0,0,obj.get_fondo(),obj.get_screen());

            //La nave tapa al fondo

            //Nave
            obj.aplicar(nav->get_x(),nav->get_y(),nav->get_nave(),obj.get_screen());
            nav->movernave();

            if(aux->disparar == false)
            {
                    aux->balax = nav->get_x()+35; aux->balay=nav->get_y()-20;
            }

            else
            {
                Mix_PlayMusic(sonido, 1);
                obj.aplicar(aux->balax,aux->balay,aux->get_bala(), obj.get_screen());
                aux->moverbala();
            }


                if( obj.colision(&ast.caja1,&nav->caja2)==true )
                {
                    Mix_PlayMusic(sonido2, 1);
                    ast.dibujar = false;
                    nav->vidas--;
                }

                if( obj.colision(&ast1.caja1,&nav->caja2)==true )
                {
                    Mix_PlayMusic(sonido2, 1);
                    ast1.dibujar = false;
                    nav->vidas--;
                }



                if (obj.colision1(&ast.caja1,&aux->caja3,aux->disparar)==true)
                {
                    ast.dibujar = false;
                    aux->disparar=false;
                }

                if (obj.colision1(&ast1.caja1,&aux->caja3,aux->disparar)==true)
                {
                    ast1.dibujar = false;
                    aux->disparar=false;
                }


                //asteroide 1
                obj.aplicar(ast.ejex,ast.ejey,ast.get_ast(),obj.get_screen());
                ast.movermeteoro();

                //asteroide 2
                obj.aplicar(ast1.ejex,ast1.ejey,ast1.get_ast(),obj.get_screen());
                ast1.movermeteoro();



                if(nav->vidas==0)
                    {
                        quit= true;
                        //perder = true;
                    }


    SDL_Flip(obj.get_screen());
}


    obj.clean_up();
    return 0;
}


