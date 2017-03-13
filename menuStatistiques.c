#include "header/menuStatistiques.h"

void MenuStatistiques(SDL_Renderer* rendererWindow){

    MettreFondUni(rendererWindow);
    printf("Menu en devellopement");

    char NomImage[21]="DAT/Image/pawn_nb.bmp";
    EventCLickStatistiques(rendererWindow);
}

void EventCLickStatistiques(SDL_Renderer* rendererWindow){
    SDL_Event event;
    int Continuer=1;

    while(Continuer){
        if ( SDL_PollEvent(&event) )
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT:
                    if ( event.window.event == SDL_WINDOWEVENT_CLOSE ){
                        Continuer=0;
                    }
                    break;
                case SDL_KEYUP:
                    if ( event.key.keysym.sym == SDLK_ESCAPE ){
                        Continuer=0;
                    }
                    break;
            }
        }
    }

}
