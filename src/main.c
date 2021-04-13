#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *background = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dstrect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        SDL_ExitWithError("Initialisation SDL echouee");
    
    window = SDL_CreateWindow("Jeu C/SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(window == NULL)
        SDL_ExitWithError("Creation fenetre echouee");
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL)
    {
        SDL_CleanRessources(window, NULL, NULL);
        SDL_ExitWithError("Creation rendu echouee");
    }

    background = IMG_Load("src/background.png");
    if(background == NULL)
    {
        SDL_CleanRessources(window, renderer, NULL);
        SDL_ExitWithError("Chargement background echouee");
    }

    texture = SDL_CreateTextureFromSurface(renderer, background);
    SDL_FreeSurface(background);
    if(texture == NULL)
    {
        SDL_CleanRessources(window, renderer, NULL);
        SDL_ExitWithError("Creation texture echouee");
    }

    if(SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h) != 0)
    {
        SDL_CleanRessources(window, renderer, texture);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    // dstrect.x = (WINDOW_WIDTH - dstrect.w) / 2;
    // dstrect.y = (WINDOW_HEIGHT - dstrect.h) / 2;

    if(SDL_RenderCopy(renderer, texture, NULL, &dstrect) != 0)
    {
        SDL_CleanRessources(window, renderer, texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    SDL_CleanRessources(window, renderer, texture);
    return EXIT_SUCCESS;
}