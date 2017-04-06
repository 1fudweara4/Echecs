#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

struct Pseudo{
    char Nom[10];
};
struct CaractEchiquier{
    int emplacementPions[8][8];
    int DebutCase[8][8]; // En x : le 'début de la case en partant de la gauche, en y le début de la case en commencant par le haut
    int TailleCase;
};
struct pos{
    int x;
    int y;
};

void Echiquier(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]);
void AffichageEchequier(SDL_Renderer* rendererWindow);
void initPions(SDL_Renderer* rendererWindow, int emplacementPions[8][8]);
void AffichagePions(SDL_Renderer* rendererWindow,SDL_Rect CaractSurface, char* NomImage);
void affichagePseudo(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]);

int CompterNbPions(int emplacementPions[8][8],int Couleur);
void affichageNombrePions(SDL_Renderer*rendererWindow,int emplacementPions[8][8]);

void deroulementPartie(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct Pseudo Nom[2]);
int ActionPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct Pseudo Nom[2],int NumeroJoueur);

int ChoixEvenement(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur);

int puissance(int nombre, int p);

void propositionDelacement(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur,struct pos Case,struct pos possibilites[3]);
void affichagePossilite(SDL_Renderer* rendererWindow,struct pos possibilites[3]);

int DeplacementPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur,struct pos possibilites[3], struct pos Position);
void ActualisationEchequier(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct pos possibilites[3],struct pos Case);
