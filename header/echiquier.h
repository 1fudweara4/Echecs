#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

struct Pseudo{
    char Nom[15];
};

void Echiquier(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]);
void AffichageEchequier(SDL_Renderer* rendererWindow);
