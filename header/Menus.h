#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include<string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void MenuPrincipal(SDL_Renderer* rendererWindow);
void MenuJouer(SDL_Renderer* rendererWindow);
void MenuNombreJoueur(SDL_Renderer* rendererWindow);
void MenuPartieEnregistree(SDL_Renderer* rendererWindow);
void EntreeNom(SDL_Renderer* rendererWindow, int NbJoueur);

void EventCLickMenuPrincipal(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
void EventCLickMenuJouer(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
void EventCLickMenuNombreJoueur(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
void EventCLickMenuPartieEnregistree(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
void EventCLickEntreeNom(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton,int NbJoueur);

int IssueMenuPrincipal(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
int IssueMenuJouer(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
int IssueMenuNombreJoueur(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
int IssueMenuPartieEnregistree(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton);
int IssueEntreeNom(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton, int NbJoueur);

