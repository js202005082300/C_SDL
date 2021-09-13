#ifndef __DRAW__H__
#define __DRAW__H__

#include "init.h"
#include "structs.h"

#define SHIP "src/gfx/ship-100.png"
#define BULLET "src/gfx/bullet-10.png"

#define TEXTURES_NUMBER 2

void prepareScene(App *app);
void presentScene(SDL_Renderer *renderer);

SDL_Texture *loadTexture(SDL_Renderer *renderer, SDL_Window *window, char *filename);
void blit(SDL_Renderer *renderer, SDL_Texture *texture, int *x, int *y);

SDL_Texture **initTextures(SDL_Renderer *renderer, SDL_Window *window);
void freeTextures(SDL_Texture **texID);

void drawBullet(Entity *bullet, SDL_Renderer *renderer, SDL_Texture **textures);


#endif