#include "draw.h"

//load texture
SDL_Texture *SDL_LoadTexture(char *filename, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

    //Chargement surface
    surface = IMG_Load(filename);
    if(surface == NULL)
    {
        SDL_CleanRessources(window, renderer, NULL);
        SDL_ExitWithError("Chargement image echouee");
    }
    //Creation texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == NULL)
    {
        SDL_CleanRessources(window, renderer, NULL);
        SDL_ExitWithError("Creation texture echouee");
    }

    return texture;
}

//blit
void SDL_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y)
{
    SDL_Rect rectangle = {x, y};

    //Chargement texture
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
    {
        SDL_CleanRessources(window, renderer, texture);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    //Afficher texture
    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0)
    {
        SDL_CleanRessources(window, renderer, texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    return;
}