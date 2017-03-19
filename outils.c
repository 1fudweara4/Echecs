#include "header/outils.h"

void MettreFondUni(SDL_Renderer* rendererWindow){

    SDL_SetRenderDrawColor(rendererWindow,51,51,51,255);

    if(SDL_RenderClear(rendererWindow)<0){
        printf("Erreur:%s\n",SDL_GetError());
    }
    SDL_RenderPresent(rendererWindow);
}

void BlitRefreshSurface(SDL_Renderer* rendererWindow,SDL_Surface* Surface,SDL_Rect CaractSurface){

    SDL_Texture *TextureImage = SDL_CreateTextureFromSurface(rendererWindow, Surface);
    SDL_RenderCopy(rendererWindow,TextureImage,NULL,&CaractSurface);
    SDL_RenderPresent(rendererWindow);

    SDL_DestroyTexture(TextureImage);
    SDL_FreeSurface(Surface);
    Surface = NULL;
}

void AffichageImage(SDL_Renderer* rendererWindow,SDL_Rect CaractSurface, char* NomImage){

    SDL_Surface* Surface=NULL;

    if(NomImage!=NULL){
        Surface=SDL_LoadBMP(NomImage);
        BlitRefreshSurface(rendererWindow,Surface, CaractSurface);
        printf("Affichage %s : ok\n", NomImage);
    }
    else{
        printf("Erreur nom d'image non défini\n");
    }

}

void Boutton(SDL_Renderer* rendererWindow, SDL_Rect CaractSurface,char* Texte){

    int wW,wH;
    SDL_GetRendererOutputSize(rendererWindow,&wW,&wH);
    SDL_Texture* texture;

    if(strcmp(Texte,"")!=0){

        SDL_Surface* SurfaceText=NULL;
        SDL_Color Couleur={1,1,1};
        TTF_Font *Font = NULL;

        Font = TTF_OpenFont("DAT/chesterfield.ttf",50);
        SurfaceText = TTF_RenderText_Solid(Font, Texte, Couleur);

        SDL_SetRenderDrawColor(rendererWindow,250,250,250,255);

         if(SDL_RenderFillRect(rendererWindow,&CaractSurface)<0)
        {
        printf("Erreur lors du remplissage du rectangle: %s",SDL_GetError());
        }
        SDL_RenderPresent(rendererWindow);

        texture = SDL_CreateTextureFromSurface(rendererWindow, SurfaceText);

        		if( texture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}

        CaractSurface.x=(CaractSurface.x+((CaractSurface.w)-(SurfaceText->w))/2);
        CaractSurface.y=(CaractSurface.y+((CaractSurface.h)-(SurfaceText->h))/2);
        CaractSurface.w=SurfaceText->w;
        CaractSurface.h=SurfaceText->h;


        SDL_RenderCopy(rendererWindow,texture,NULL ,&CaractSurface);

        SDL_RenderPresent(rendererWindow);

        SDL_FreeSurface(SurfaceText);
        TTF_CloseFont(Font);
        Font = NULL;
        SDL_DestroyTexture(texture);
        printf("Boutton %s : ok\n",Texte);
    }
    else{
        printf("Erreur Texte non défini\n");
    }
}

void affichageTexte(SDL_Renderer* rendererWindow,char* Texte,int taille, SDL_Rect Position){

    SDL_Surface* SurfaceText=NULL;
    SDL_Texture* texture;
    SDL_Color Couleur={1,1,1},Fond={51,51,51};
    TTF_Font *Font = NULL;

    if(Texte==""){
        printf("Erreur texte non défini\n");
    }
    else{
        Font = TTF_OpenFont("DAT/chesterfield.ttf",taille);
        SurfaceText = TTF_RenderText_Shaded(Font, Texte, Couleur,Fond);
        texture = SDL_CreateTextureFromSurface(rendererWindow, SurfaceText);

        Position.w=SurfaceText->w;
        Position.h=SurfaceText->h;
        Position.x=Position.x-(Position.w/2);
        Position.y=Position.y-(Position.h/2);

        SDL_RenderCopy(rendererWindow,texture,NULL ,&Position);
        SDL_RenderPresent(rendererWindow);

        printf("Texte '%s' affiché\n",Texte);

        SDL_FreeSurface(SurfaceText);
        TTF_CloseFont(Font);
        Font = NULL;
        SDL_DestroyTexture(texture);
    }
}
