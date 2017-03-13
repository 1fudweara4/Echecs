#include "header/main.h"

int main(int argc, char* args[])
{

    SDL_Window* window = NULL; //Déclaration fenetre

    if(!InitSDL()){
        CreationFenetre(window);
    }
    else{
        printf("Le programme n'a pas pu se lancer au moment de l'initialisation de la SDL."); //AH
    }

    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}


int InitSDL(){

	int Erreur=0;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf("SDL n'a pas reussi à se lancer. SDL_Error: %s\n", SDL_GetError());
		Erreur=1;
	}
	else{
        printf("Init SDL : ok.\n");

        //Initialize SDL_ttf
        if( TTF_Init() == -1 ){
            printf( "Erreur lors de l'initialisation de SDL_ttf SDL_ttf Error: %s\n", TTF_GetError() );
            Erreur=1;
        }
        else{
            printf("Initialisation TTF_Init : OK\n.");
        }
        }
    return Erreur;
}


void CreationFenetre(SDL_Window* window){

    SDL_Renderer* rendererWindow=NULL;
    window = SDL_CreateWindow("Echecs", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if( window == NULL ){
        printf("La fenetre n'a pas pu être créee. SDL_Error: %s\n",SDL_GetError());
    }
    else{
        rendererWindow = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

        if(rendererWindow == NULL){
            printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        }
        else{
            printf("Initialisation renderer : OK\n");
        }

        SDL_Delay(100); //Delai pour ne pas avoir de prob. d'affichage car librairie pas encore totalement chargée
        MettreFondUni(rendererWindow);

        MenuPrincipal(rendererWindow); //Passage Menus.c
        SDL_DestroyRenderer(rendererWindow);
    }
}
