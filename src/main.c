#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char **argv)
{
	versionSDL();
	arg(argc, argv);

    SDL_Window *window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        SDL_Log("ERREUR : Initialisation SDL > %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Jeu C/SDL",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 600,
                                0);

    if(window == NULL)
    {
        SDL_Log("ERREUR : Creation fenetre echouee > %s\n",SDL_GetError()); 
        exit(EXIT_FAILURE);
    }

    SDL_Delay(5000);

    SDL_Quit();

    return EXIT_SUCCESS;
}