#include"header/Menus.h"

void MenuPrincipal(SDL_Renderer* rendererWindow){

    int i=0,wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Rect CaractBoutton[3];

    MettreFondUni(rendererWindow);

    for(i=0;i<3;i++){
        CaractBoutton[i].x=(wW/2)-(wW/10)*2;;
        CaractBoutton[i].y=((wH/13)*3+(wH/13)*3*i);
        CaractBoutton[i].w=(wW/5)*2;
        CaractBoutton[i].h=(wH/13)*2;
    }

    Boutton(rendererWindow,CaractBoutton[0],"Jouer");
    Boutton(rendererWindow,CaractBoutton[1],"Statistiques");
    Boutton(rendererWindow,CaractBoutton[2],"Quitter");


EventCLickMenuPrincipal(rendererWindow,CaractBoutton);
}

void MenuJouer(SDL_Renderer* rendererWindow){
    int i=0,wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Rect CaractBoutton[3];

    MettreFondUni(rendererWindow);

    for(i=0;i<3;i++){
        CaractBoutton[i].x=(wW/2)-(wW/10)*2;;
        CaractBoutton[i].y=((wH/13)*3+(wH/13)*3*i);
        CaractBoutton[i].w=(wW/5)*2;
        CaractBoutton[i].h=(wH/13)*2;

    }

    Boutton(rendererWindow,CaractBoutton[0],"Nouveau jeu");
    Boutton(rendererWindow,CaractBoutton[1],"Reprendre partie");
    Boutton(rendererWindow,CaractBoutton[2],"Retour");

    EventCLickMenuJouer(rendererWindow,CaractBoutton);
}

void MenuNombreJoueur(SDL_Renderer* rendererWindow){
    int i=0,wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Rect CaractBoutton[3];

    MettreFondUni(rendererWindow);

    for(i=0;i<3;i++){
        CaractBoutton[i].x=(wW/2)-(wW/10)*2;;
        CaractBoutton[i].y=((wH/13)*3+(wH/13)*3*i);
        CaractBoutton[i].w=(wW/5)*2;
        CaractBoutton[i].h=(wH/13)*2;

    }

    Boutton(rendererWindow,CaractBoutton[0],"1 joueur");
    Boutton(rendererWindow,CaractBoutton[1],"2 joueurs");
    Boutton(rendererWindow,CaractBoutton[2],"Retour");

    EventCLickMenuNombreJoueur(rendererWindow,CaractBoutton);
}

void MenuPartieEnregistree(SDL_Renderer* rendererWindow){
    printf("Menu en cours de develeloppement");
}

void EntreeNom(SDL_Renderer* rendererWindow, int NbJoueur){

    int wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Rect CaractBoutton[3];

    CaractBoutton[0].x=wW-150;
    CaractBoutton[0].y=wH-100;
    CaractBoutton[0].w=100;
    CaractBoutton[0].h=50;

    CaractBoutton[1].x=wW/3;
    CaractBoutton[1].y=wH/4;
    CaractBoutton[1].w=wW/3;
    CaractBoutton[1].h=wH/5;

    CaractBoutton[2].x=wW*3.5/9;
    CaractBoutton[2].y=wH/2;
    CaractBoutton[2].w=wW*2/9;
    CaractBoutton[2].h=wH/6;


    MettreFondUni(rendererWindow);

    Boutton(rendererWindow,CaractBoutton[1],"  ");
    Boutton(rendererWindow,CaractBoutton[0],"Retour");
    Boutton(rendererWindow,CaractBoutton[2],"Valider");

    EventCLickEntreeNom(rendererWindow,CaractBoutton,NbJoueur);
}



void EventCLickMenuPrincipal(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){;
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

                case SDL_MOUSEBUTTONUP:
                        Continuer=IssueMenuPrincipal(rendererWindow,CaractBoutton);
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

void EventCLickMenuJouer(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
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

                case SDL_MOUSEBUTTONUP:
                        Continuer=IssueMenuJouer(rendererWindow,CaractBoutton);
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

void EventCLickMenuNombreJoueur(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
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

                case SDL_MOUSEBUTTONUP:
                        Continuer=IssueMenuNombreJoueur(rendererWindow,CaractBoutton);
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

void EventCLickMenuPartieEnregistree(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
printf("Menu en cours de develeloppement\n");
}

void EventCLickEntreeNom(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton,int NbJoueur){

    SDL_Event event;
    int Continuer=1, AvancementTexte=0, wH,wW,NombreNomEntree=0;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Rect Position={wW/3,wH/4,wW/3,wH/5};

    struct Pseudo Nom[2];

    Nom[0].Nom[0]=NULL;
    Nom[1].Nom[0]=NULL;


    SDL_StartTextInput();

        while(Continuer){
        if(SDL_PollEvent(&event)){
            switch(event.type)
            {
                case SDL_WINDOWEVENT:
                    if ( event.window.event == SDL_WINDOWEVENT_CLOSE ){
                        Continuer=0;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    printf("Le pseudo %s est entré \n",Nom[NombreNomEntree].Nom);
                    Continuer=IssueEntreeNom(rendererWindow,CaractBoutton,NbJoueur,&NombreNomEntree,&AvancementTexte,Position,Nom);
                    break;

                case SDL_TEXTINPUT:
                        if(AvancementTexte<10){
                            strcat(&Nom[NombreNomEntree].Nom, event.text.text);
                            Boutton(rendererWindow,Position,&Nom[NombreNomEntree].Nom[0]);
                            printf("%s, sur %d\n",&Nom[NombreNomEntree].Nom[0]);
                            AvancementTexte++;
                        }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_BACKSPACE){
                        if(AvancementTexte>0){
                            Nom[NombreNomEntree].Nom[AvancementTexte-1]='\0';
                            Boutton(rendererWindow,Position,"  ");
                            Boutton(rendererWindow,Position,&Nom[NombreNomEntree].Nom[0]);
                            AvancementTexte--;
                        }
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
    SDL_StopTextInput();
}



int IssueMenuPrincipal(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
    int Continuer=1,pX,pY;
    SDL_GetMouseState(&pX,&pY);

    printf("Appuie en %d %d\n",pX,pY);

    if(pX>CaractBoutton[0].x && pX<CaractBoutton[0].x+CaractBoutton[0].w && pY>CaractBoutton[0].y && pY<CaractBoutton[0].y+CaractBoutton[0].h){
        printf("Appuie sur boutton Jouer\n");
        MenuJouer(rendererWindow);
        Continuer=0;
    }
    if(pX>CaractBoutton[1].x && pX<CaractBoutton[1].x+CaractBoutton[1].w && pY>CaractBoutton[1].y && pY<CaractBoutton[1].y+CaractBoutton[1].h){
        printf("Appuie sur boutton Statistiques\n");
        MenuStatistiques(rendererWindow);
        Continuer=0;
    }
    if(pX>CaractBoutton[2].x && pX<CaractBoutton[2].x+CaractBoutton[2].w && pY>CaractBoutton[2].y && pY<CaractBoutton[2].y+CaractBoutton[2].h){
        Continuer=0;
    }

    return Continuer;
}

int IssueMenuJouer(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
    int Continuer=1,pX,pY;
    SDL_GetMouseState(&pX,&pY);

    printf("Appuie en %d %d\n",pX,pY);

    if(pX>CaractBoutton[0].x && pX<CaractBoutton[0].x+CaractBoutton[0].w && pY>CaractBoutton[0].y && pY<CaractBoutton[0].y+CaractBoutton[0].h){
        printf("Appuie sur boutton Nouveau jeu\n");
        MenuNombreJoueur(rendererWindow);
        Continuer=0;
    }
    if(pX>CaractBoutton[1].x && pX<CaractBoutton[1].x+CaractBoutton[1].w && pY>CaractBoutton[1].y && pY<CaractBoutton[1].y+CaractBoutton[1].h){
        printf("Appuie sur boutton Reprendre partie\n");
        SDL_Delay(1000);
        Continuer=0;
    }
    if(pX>CaractBoutton[2].x && pX<CaractBoutton[2].x+CaractBoutton[2].w && pY>CaractBoutton[2].y && pY<CaractBoutton[2].y+CaractBoutton[2].h){
        printf("Appuie sur boutton Retour\n");
        MenuPrincipal(rendererWindow);
        Continuer=0;
    }
    return Continuer;
}

int IssueMenuNombreJoueur(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){

    int Continuer=1,pX,pY;
    SDL_GetMouseState(&pX,&pY);

    printf("Appuie en %d %d\n",pX,pY);

    if(pX>CaractBoutton[0].x && pX<CaractBoutton[0].x+CaractBoutton[0].w && pY>CaractBoutton[0].y && pY<CaractBoutton[0].y+CaractBoutton[0].h){
        printf("Appuie sur boutton 1 joueur\n");
        EntreeNom(rendererWindow, 1);
        Continuer=0;
    }
    if(pX>CaractBoutton[1].x && pX<CaractBoutton[1].x+CaractBoutton[1].w && pY>CaractBoutton[1].y && pY<CaractBoutton[1].y+CaractBoutton[1].h){
        printf("Appuie sur boutton 2 joueur\n");
        EntreeNom(rendererWindow, 2);
        Continuer=0;
    }
    if(pX>CaractBoutton[2].x && pX<CaractBoutton[2].x+CaractBoutton[2].w && pY>CaractBoutton[2].y && pY<CaractBoutton[2].y+CaractBoutton[2].h){
        printf("Appuie sur boutton Retour\n");
        MenuJouer(rendererWindow);

        Continuer=0;
    }
    return Continuer;
}

int IssueMenuPartieEnregistree(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton){
    printf("Menu en cours de develeloppement");
}

int IssueEntreeNom(SDL_Renderer* rendererWindow, SDL_Rect* CaractBoutton, int NbJoueur,int* NombreNomEntree,int*AvancementTexte,SDL_Rect Position,struct Pseudo Nom[2]){
    int Continuer=1,pX,pY;
    SDL_GetMouseState(&pX,&pY);

    if(pX>CaractBoutton[0].x && pX<CaractBoutton[0].x+CaractBoutton[0].w && pY>CaractBoutton[0].y && pY<CaractBoutton[0].y+CaractBoutton[0].h){
        MenuNombreJoueur(rendererWindow);
        Continuer=0;
    }
    if(pX>CaractBoutton[2].x && pX<CaractBoutton[2].x+CaractBoutton[2].w && pY>CaractBoutton[2].y && pY<CaractBoutton[2].y+CaractBoutton[2].h){

        if(NbJoueur-1==*NombreNomEntree){
            Continuer=0;
            printf("Passage à l'échec !\n");
            Echiquier(rendererWindow,Nom);
        }
        else{
            *NombreNomEntree=1;
            *AvancementTexte=0;
            Boutton(rendererWindow,Position,"  ");
            printf("Ok,%d\n",*NombreNomEntree);
        }
    }
    return Continuer;
}
