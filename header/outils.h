#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include<string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void MettreFondUni(SDL_Renderer* rendererWindow);
void BlitRefreshSurface(SDL_Renderer* rendererWindow,SDL_Surface* Surface,SDL_Rect CaractSurface);
void AffichageImage(SDL_Renderer* rendererWindow,SDL_Rect CaractSurface, char* NomImage);
void Boutton(SDL_Renderer* rendererWindow, SDL_Rect CaractSurface,char* Texte);

void affichageTexte(SDL_Renderer* rendererWindow,char* Texte, SDL_Rect Position);
