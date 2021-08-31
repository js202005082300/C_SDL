#ifndef __GAME__H__
#define __GAME__H__

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "player.h"
#include "game.h"
#include "map.h"
#include "save.h"
#include "write.h"

#define SQUARE_SIZE 10
/*--------------------------------------------------------*/
//	Macros pour la taille de l'espace de jeu (modifiables)
#define MAX_SQUARES_ROWS 64
#define MAX_SQUARES_COLS 48
/*--------------------------------------------------------*/
#define WINDOW_WIDTH SQUARE_SIZE*MAX_SQUARES_ROWS
#define WINDOW_HEIGHT SQUARE_SIZE*MAX_SQUARES_COLS
/*--------------------------------------------------------*/

//	Definitions
typedef struct App
{
    SDL_Window *window;
    SDL_Renderer *renderer;
}App;

//	Prototypes des fonctions
void SDL_VersionUsed(void);
void SDL_GameManager(void);
App *SDL_InitGame(void);
SDL_Texture *SDL_LoadTexture(char *filename, App *app);
void SDL_RenderTexture(SDL_Texture *texture, App *app, int x, int y);
void SDL_DoInput(SDL_bool *program_launched, int *x, int *y);
void SDL_ExitWithError(const char *message);
void SDL_FreeGame(App *app);
void SDL_CleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
/*--------------------------------------------------------*/
#endif