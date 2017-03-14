#include "header/echiquier.h"

void Echiquier(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]){
    AffichageEchequier(rendererWindow);
    SDL_Delay(5000);
}

void AffichageEchequier(SDL_Renderer* rendererWindow){
    int i=0,j=0,wW,wH;
    SDL_Rect CaractCase;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    MettreFondUni(rendererWindow);
    SDL_SetRenderDrawColor(rendererWindow,0,0,0,255);

    CaractCase.x=(wW-wH*7/8)/2;
    CaractCase.y=(wH-wH*7/8)/2;
    CaractCase.h=wH*7/8;
    CaractCase.w=wH*7/8;

    SDL_RenderFillRect(rendererWindow,&CaractCase);
    SDL_RenderPresent(rendererWindow);

    SDL_SetRenderDrawColor(rendererWindow,255,255,255,255);

    CaractCase.h=wH*7/8/8;
    CaractCase.w=wH*7/8/8;

    for(i=0;i<8;i=i+2){

        /*;*/
        for(j=0;j<8;j++){

            if(j%2==0){
                CaractCase.x=((wW-wH*7/8)/2)+CaractCase.h*i;
                CaractCase.y=((wH-wH*7/8)/2)+CaractCase.w*j;
                SDL_RenderFillRect(rendererWindow,&CaractCase);
                SDL_RenderPresent(rendererWindow);
            }
            else{
                CaractCase.x=((wW-wH*7/8)/2)+CaractCase.h*(i+1);
                CaractCase.y=((wH-wH*7/8)/2)+CaractCase.w*j;
                SDL_RenderFillRect(rendererWindow,&CaractCase);
                SDL_RenderPresent(rendererWindow);
            }
        }
    }
    printf("Echiquier fait.\n");
}
