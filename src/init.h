#ifndef __INIT__H__
#define __INIT__H__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "map.h" // les macros de taille d'écran
#include "write.h" // initialisation de SDL TTF

//	Definitions
typedef struct App
{
    SDL_Window *window;
    SDL_Renderer *renderer;
}App;

//	Prototypes des fonctions
App *SDL_InitGame(void);
void SDL_ExitWithError(const char *message);
void SDL_CleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
void SDL_FreeGame(App *app);

#endif