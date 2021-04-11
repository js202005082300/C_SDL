#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *background = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dest_rect = {0, 0, 640, 480};

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        SDL_ExitWithError("Initialisation SDL echouee");

    window = SDL_CreateWindow("Jeu C/SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
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

    if(SDL_QueryTexture(texture, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_CleanRessources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer, texture, NULL, &dest_rect) != 0)
    {
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_CleanRessources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    SDL_CleanRessources(window, renderer, texture);
    return EXIT_SUCCESS;
}