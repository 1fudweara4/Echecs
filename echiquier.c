#include "header/echiquier.h"

void Echiquier(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]){
    int emplacementPions[8][8],i,j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            emplacementPions[i][j]=3;
        }
    }
    AffichageEchequier(rendererWindow);
    initPions(rendererWindow,emplacementPions);
    affichagePseudos(rendererWindow,Nom);
    affichageNombrePions(rendererWindow,emplacementPions);
    deroulementPartie(rendererWindow,emplacementPions,Nom);

}


void AffichageEchequier(SDL_Renderer* rendererWindow){
    int i=0,j=0,wW,wH;
    SDL_Rect CaractCase;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    MettreFondUni(rendererWindow);

    CaractCase.h=wH*7/8/8;
    CaractCase.w=wH*7/8/8;

    for(i=0;i<8;i++){
        CaractCase.x=((wW-wH*7/8)/2)+CaractCase.h*i;

        for(j=0;j<8;j++){
            CaractCase.y=((wH-wH*7/8)/2)+CaractCase.w*j;

            if(j%2==0){
                if(i%2==0){
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
                }
                else{
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
                }
            }
            else{
                if(i%2==0){
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
                }
                else{
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
                }
            }

        }
    }
    printf("Echiquier fait.\n");
}

void initPions(SDL_Renderer* rendererWindow, int emplacementPions[8][8]){
    int i,j,wW,wH;
    SDL_Rect CaractCase;

    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    CaractCase.h=wH*7/8/8;
    CaractCase.w=wH*7/8/8;

    for(i=0;i<8;i++){

            CaractCase.y=((wH-wH*7/8)/2)+CaractCase.h*i;

            for(j=0;j<8;j++){
                CaractCase.x=((wW-wH*7/8)/2)+CaractCase.w*j;

                if(i<2){
                    AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nb.bmp");
                    emplacementPions[i][j]=1;
                }
                if(i>5){
                    AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nw.bmp");
                    emplacementPions[i][j]=0;
                }
            }
    }
}


void AffichagePions(SDL_Renderer* rendererWindow,SDL_Rect CaractSurface, char* NomImage){

    SDL_Surface* Surface=NULL;

    if(NomImage!=NULL){
        Surface=SDL_LoadBMP(NomImage);

        Uint32 colorkey = SDL_MapRGB( Surface->format, 0xFF, 0, 0xFF );
        SDL_SetColorKey( Surface, SDL_TRUE, colorkey );

        BlitRefreshSurface(rendererWindow,Surface, CaractSurface);
        printf("Affichage %s : ok\n", NomImage);
    }
    else{
        printf("Erreur nom d'image non défini\n");
    }

}

void affichagePseudos(SDL_Renderer* rendererWindow,struct Pseudo Nom[2]){
    SDL_Rect caractTextePseudo[2];
    int i,wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    caractTextePseudo[1].h=NULL;
    caractTextePseudo[1].w=NULL;
    caractTextePseudo[1].x=((wW-wH*7/8)/2)/2;
    caractTextePseudo[1].y=wH/3;

    caractTextePseudo[0].h=NULL;
    caractTextePseudo[0].w=NULL;
    caractTextePseudo[0].x=wW-((wW-wH*7/8)/2)/2;
    caractTextePseudo[0].y=wH-wH/3;

    for(i=0;i<2;i++){
        if(Nom[i].Nom[0]==NULL){
            affichageTexte(rendererWindow,"Ordinateur",30,caractTextePseudo[i]);
        }
        else{
            affichageTexte(rendererWindow,Nom[i].Nom,30,caractTextePseudo[i]);
        }
    }

}

int CompterNbPions(int emplacementPions[8][8],int Couleur){
    int NombreDePions=0,i,j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(emplacementPions[i][j]==Couleur){
                NombreDePions++;
            }
        }
    }
    return NombreDePions;
}

void affichageNombrePions(SDL_Renderer*rendererWindow,int emplacementPions[8][8]){
    int i,wW,wH;
    SDL_Rect CaractTexte[2];
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    char Nb[8];

    CaractTexte[1].h=NULL;
    CaractTexte[1].w=NULL;
    CaractTexte[1].x=((wW-wH*7/8)/2)/2;
    CaractTexte[1].y=wH/3+wH/10;

    CaractTexte[0].h=NULL;
    CaractTexte[0].w=NULL;
    CaractTexte[0].x=wW-((wW-wH*7/8)/2)/2;
    CaractTexte[0].y=wH-wH/3+wH/10;

    for(i=0;i<2;i++){
        sprintf (Nb, "%d", CompterNbPions(emplacementPions,i));

        if(CompterNbPions(emplacementPions,i)==1){
            strcat(&Nb, " pion ");
        }
        else{
            strcat(&Nb, " pions");
        }
        affichageTexte(rendererWindow,Nb,30,CaractTexte[i]);
        printf("%d pions restants\n",CompterNbPions(emplacementPions,i));
    }
}

void deroulementPartie(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct Pseudo Nom[2]){
    int Continuer=1,i;

    while(Continuer){
            /** Coder fonction perdre/gagner ici! ( si sauvegarde peut être mettre condition si les deux nb pions ==0 et réflechir égalité **/
                                                   /** un if/else ? donc un if avec Continuer=0 mais vide **/
        for(i=0;i<2;i++){
            if(CompterNbPions(emplacementPions,0)!=0 && CompterNbPions(emplacementPions,1)!=0){
                Continuer=ActionPions(rendererWindow,emplacementPions,Nom,i);
            }
        }
    }
}

int ActionPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct Pseudo Nom[2],int NumeroJoueur){
    int Continuer=0;

    if(Nom[NumeroJoueur].Nom[0]==NULL){
        printf("Ordinateur qui joue\n");
    }
    else{
        printf("Joueur 'réel' qui joue\n");
        ChoixEvenement(rendererWindow,emplacementPions,NumeroJoueur);

    }

    return Continuer;
}

int ChoixEvenement(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur){
    SDL_Event event;
    int Continuer=0, Condition=1;

    while(Condition){
        if(SDL_PollEvent(&event)){
             switch(event.type){

                case SDL_WINDOWEVENT:
                    if ( event.window.event == SDL_WINDOWEVENT_CLOSE ){
                        Condition=0;
                        Continuer=0;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    Condition=DeplacementPions(rendererWindow,emplacementPions,NumeroJoueur);
                    break;
                case SDL_KEYUP:
                    if ( event.key.keysym.sym == SDLK_ESCAPE ){
                        Condition=0;
                        Continuer=0;
                    }
                    break;
                default:
                    break;

             }
        }
    }
    return Continuer;
}

int DeplacementPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur){
    int wW,wH,i,j,pX,pY,Condition=1;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_GetMouseState(&pX,&pY);

    for(i=0;i<8;i++){

        if(pX>((wH-wH*7/8)/2)+wH*7/8/8*i && pX<((wH-wH*7/8)/2)+wH*7/8/8*(i+1)){
            for(j=0;j<8;j++){
                if(pY>((wW-wH*7/8)/2)+wH*7/8/8*j && pY<((wW-wH*7/8)/2)+wH*7/8/8*(j+1)){
                    if(emplacementPions[j][i]==NumeroJoueur){
                        printf("OH YES\n");
                    }
                }
            }
        }
    }
    return Condition;
}
