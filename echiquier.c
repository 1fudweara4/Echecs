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

    do{
        for(i=0;i<2;i++){
            if(CompterNbPions(emplacementPions,0)!=0 && CompterNbPions(emplacementPions,1)!=0 && Continuer!=0){
                Continuer=ActionPions(rendererWindow,emplacementPions,Nom,i);
                affichageNombrePions(rendererWindow,emplacementPions);
            }
        }
    }while(Continuer);
}

int ActionPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct Pseudo Nom[2],int NumeroJoueur){
    int Continuer,i;

    if(Nom[NumeroJoueur].Nom[0]==NULL){
        printf("Ordinateur qui joue\n");
    }
    else{
        printf("Joueur 'réel' qui joue\n");
        Continuer=ChoixEvenement(rendererWindow,emplacementPions,NumeroJoueur);

    }

    for(i=0;i<8;i++){
        if(emplacementPions[0][i]==0){
            printf("Victoire Blanche\n");
            Continuer=0;
        }
        if(emplacementPions[7][i]==1){
            printf("Victoire Noir\n");
            Continuer=0;
        }
    }
     /** Coder fonction perdre/gagner ici! ( si sauvegarde peut être mettre condition si les deux nb pions ==0 et réflechir égalité **/
                                                   /** un if/else ? donc un if avec Continuer=0 mais vide **/

    return Continuer;
}

int ChoixEvenement(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur){
    SDL_Event event;
    int Continuer=1, Condition=1;

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
                    Condition=ClickSurPion(rendererWindow,emplacementPions,NumeroJoueur);
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

int ClickSurPion(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur){
    int wW,wH,i,j,pX,pY,Condition=1,positionCaseX,positionCaseY,TailleCase;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_GetMouseState(&pX,&pY);
    struct pos Position={12,12,12};
    struct pos possibilites[3]={16,16,16,16,16,16,16,16,16,16};
    TailleCase=wH*7/8/8;

    for(i=0;i<8;i++){

        positionCaseX=((wW-wH*7/8)/2)+i*TailleCase;

        if(pX>positionCaseX && pX<positionCaseX+TailleCase){

            for(j=0;j<8;j++){

                positionCaseY=((wH-wH*7/8)/2)+TailleCase*j;

                if(pY>positionCaseY && pY<positionCaseY+TailleCase){
                    if(emplacementPions[j][i]==NumeroJoueur){
                        Position.x=i;
                        Position.y=j;
                        printf("TEST\n");
                        propositionDelacement(rendererWindow,emplacementPions,NumeroJoueur,Position,possibilites);
                        Condition=DeplacementPions(rendererWindow,emplacementPions,NumeroJoueur,possibilites,Position);
                        ActualisationEchequier(rendererWindow,emplacementPions,possibilites,Position);
                        printf("Attente de 5s\n");
                    }
                }
            }
        }

    }
    return Condition;
}

int puissance(int nombre, int p){
	if(p==0){
        return 1;
	}
	else{
		return nombre*puissance(nombre,p-1);
	}
	//return nombre;

}

void propositionDelacement(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur,struct pos Case,struct pos possibilites[3]){
    remplirTableauCondition(emplacementPions,Case,possibilites,NumeroJoueur);
    affichagePossilite(rendererWindow,possibilites);
}

void remplirTableauCondition(int emplacementPions[8][8],struct pos Case,struct pos possibilites[3],int NumeroJoueur){

    if(Case.x-1>=0 && Case.x-1<8 && Case.y-puissance(-1,NumeroJoueur)>=0 && Case.y-puissance(-1,NumeroJoueur)<8){
            if(emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x-1]!=NumeroJoueur && emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x-1]!=3){
                possibilites[0].x=Case.x-1;
                possibilites[0].y=Case.y-puissance(-1,NumeroJoueur);
            }
    }

    if(Case.x>=0 && Case.x<8 && Case.y-puissance(-1,NumeroJoueur)>=0 && Case.y-puissance(-1,NumeroJoueur)<8){
            if(emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x]!=NumeroJoueur && emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x]==3){
                possibilites[1].x=Case.x;
                possibilites[1].y=Case.y-puissance(-1,NumeroJoueur);
            }
    }
    if(Case.x+1>=0 && Case.x+1<8 && Case.y-puissance(-1,NumeroJoueur)>=0 && Case.y-puissance(-1,NumeroJoueur)<8){
        if(emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x+1]!=NumeroJoueur && emplacementPions[Case.y-puissance(-1,NumeroJoueur)][Case.x+1]!=3){
                possibilites[2].x=Case.x+1;
                possibilites[2].y=Case.y-puissance(-1,NumeroJoueur);
        }
    }
}

void affichagePossilite(SDL_Renderer* rendererWindow,struct pos possibilites[3]){
    int i,wW,wH;
    SDL_Rect PositionImage;

    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    for(i=0;i<3;i++){
        if(possibilites[i].x!=16){
            printf("%d %d %d\n",possibilites[i].x,possibilites[i].y,i);
            PositionImage.x=((wW-wH*7/8)/2)+wH*7/8/8*possibilites[i].x;
            PositionImage.y=((wH-wH*7/8)/2)+wH*7/8/8*possibilites[i].y;
            PositionImage.h=wH*7/8/8;
            PositionImage.w=wH*7/8/8;
            AffichageImage(rendererWindow,PositionImage,"DAT/Image/proposition.bmp");
        }
    }
}

int DeplacementPions(SDL_Renderer* rendererWindow,int emplacementPions[8][8],int NumeroJoueur,struct pos possibilites[3],struct pos Position){
    SDL_Event event;
    int i, RefaireBoucle=1,Quitter=0;
    struct pos PositionCurseur,TailleEcran;
    SDL_GetRendererOutputSize(rendererWindow,&TailleEcran.x,&TailleEcran.y);

    while(!Quitter){
        if(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_MOUSEBUTTONUP:
                    Quitter=1;
                    SDL_GetMouseState(&PositionCurseur.x,&PositionCurseur.y);
                    for(i=0;i<3;i++){
                        if(PositionCurseur.x>((TailleEcran.x-TailleEcran.y*7/8)/2)+TailleEcran.y*7/8/8*possibilites[i].x && PositionCurseur.x<((TailleEcran.x-TailleEcran.y*7/8)/2)+TailleEcran.y*7/8/8*(possibilites[i].x+1)){
                            if(PositionCurseur.y>((TailleEcran.y-TailleEcran.y*7/8)/2)+TailleEcran.y*7/8/8*possibilites[i].y && PositionCurseur.y<((TailleEcran.y-TailleEcran.y*7/8)/2)+TailleEcran.y*7/8/8*(possibilites[i].y+1)){
                                RefaireBoucle=0;
                                emplacementPions[possibilites[i].y][possibilites[i].x]=NumeroJoueur;
                                emplacementPions[Position.y][Position.x]=3;
                                printf("%d %d est l'emplacement cliqué.\n",possibilites[i].x,possibilites[i].y);
                            }
                        }
                    }
                    break;
            }
        }
    }

    return RefaireBoucle;
}

void ActualisationEchequier(SDL_Renderer* rendererWindow,int emplacementPions[8][8],struct pos possibilites[3],struct pos Case){
    int i,wW,wH;
    SDL_Rect CaractCase;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);

    for(i=0;i<3;i++){
            CaractCase.h=CaractCase.w=wH*7/8/8;
            CaractCase.x=((wW-wH*7/8)/2)+CaractCase.h*possibilites[i].x;
            CaractCase.y=((wH-wH*7/8)/2)+CaractCase.w*possibilites[i].y;

        if(possibilites[i].y%2==0){
                if(possibilites[i].x%2==0){
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
                }
                else{
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
                }
            }
            else{
                if(possibilites[i].x%2==0){
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
                }
                else{
                    AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
                }
    }
    if(emplacementPions[possibilites[i].y][possibilites[i].x]==0){
            printf("%d valeur /%d %d case blanche affichée.\n",emplacementPions[possibilites[i].x][possibilites[i].y],possibilites[i].x,possibilites[i].y);
        AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nw.bmp");
    }
    if(emplacementPions[possibilites[i].y][possibilites[i].x]==1){
        printf(" %d valeur / %d %d case noire affichée.\n",emplacementPions[possibilites[i].x][possibilites[i].y],possibilites[i].x,possibilites[i].y);
        AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nb.bmp");
    }

    CaractCase.x=((wW-wH*7/8)/2)+CaractCase.h*Case.x;
    CaractCase.y=((wH-wH*7/8)/2)+CaractCase.w*Case.y;

    if(Case.y%2==0){
        if(Case.x%2==0){
            AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
        }
        else{
            AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
        }
    }
    else{
        if(Case.x%2==0){
            AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseNoir.bmp");
        }
        else{
            AffichageImage(rendererWindow,CaractCase,"DAT/Image/caseBlanche.bmp");
        }
    }

    if(emplacementPions[Case.y][Case.x]==0){
        AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nw.bmp");
    }
    if(emplacementPions[Case.y][Case.x]==1){
        AffichagePions(rendererWindow,CaractCase,"DAT/Image/pawn_nb.bmp");
    }

    }
}
