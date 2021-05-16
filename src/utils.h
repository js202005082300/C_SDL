#ifndef __UTILS__H__
#define __UTILS__H__

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#define SQUARE_SIZE 10
/*--------------------------------------------------------*/
//	Macros pour la taille de l'espace de jeu (modifiables)
#define MAX_SQUARES_ROWS 64
#define MAX_SQUARES_COLS 48
/*--------------------------------------------------------*/
#define WINDOW_WIDTH SQUARE_SIZE*MAX_SQUARES_ROWS
#define WINDOW_HEIGHT SQUARE_SIZE*MAX_SQUARES_COLS
/*--------------------------------------------------------*/

//	Définitions
typedef struct App
{
    SDL_Window *window;
    SDL_Renderer *renderer;
}App;

//	Prototypes des fonctions
void SDL_V(void);
void SDL_ExitWithError(const char *message);
App *SDL_initGame(void);
void SDL_CleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
void SDL_freeGame(App *app);
/*--------------------------------------------------------*/
#endif