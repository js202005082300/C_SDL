#ifndef __DRAW__H__
#define __DRAW__H__

#include "structs.h"

#define BLUE_SHIP "src/gfx/blue_ship-50.png"
#define RED_BULLET "src/gfx/bullet-red-5.png"
#define BLUE_BULLET "src/gfx/bullet-blue-5.png"
#define RED_SHIP "src/gfx/red_ship-50.png"
#define TEXTURES_NUMBER 4

void prepareScene(App *app);
void presentScene(SDL_Renderer *renderer);

SDL_Texture *loadTexture(SDL_Renderer *renderer, SDL_Window *window, char *filename);
void blit(SDL_Renderer *renderer, SDL_Texture *texture, int *x, int *y);

SDL_Texture **initTextures(SDL_Renderer *renderer, SDL_Window *window);
void freeTextures(SDL_Texture **texID);

void drawPlayer(Entity *player, SDL_Renderer *renderer, SDL_Texture **textures);
void drawBullet(Entity *bullet, SDL_Renderer *renderer, SDL_Texture **textures);
void drawEnemy(Entity *enemy, SDL_Renderer *renderer, SDL_Texture **textures);
void drawAlienBullet(Entity *bullet, SDL_Renderer *renderer, SDL_Texture **textures);

#endif