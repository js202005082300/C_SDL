#ifndef __DRAW__H__
#define __DRAW__H__

#include "init.h"

void prepareScene(App *app);
void presentScene(SDL_Renderer *renderer);

SDL_Texture *loadTexture(SDL_Renderer *renderer, SDL_Window *window, char *filename);
void blit(SDL_Renderer *renderer, SDL_Texture *texture, int *x, int *y);

#endif