#ifndef __GAME__H__
#define __GAME__H__

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "player.h"
#include "game.h"
#include "map.h"
#include "save.h"

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
void SDL_versionUsed(void);
void SDL_gameManager(void);
App *SDL_initGame(void);
SDL_Texture *SDL_loadTexture(char *filename, App *app);
void SDL_renderTexture(SDL_Texture *texture, App *app, int x, int y, int w, int h);
void SDL_doInput(SDL_bool *program_launched, unsigned int *x, unsigned int *y);
void SDL_ExitWithError(const char *message);
void SDL_freeGame(App *app);
void SDL_CleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
/*--------------------------------------------------------*/
#endif