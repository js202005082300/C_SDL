#ifndef __STRUCTS__H__
#define __STRUCTS__H__

#include <SDL.h>
#include <SDL_image.h>

#include "draw.h"

typedef struct {
	int x, y;
	int dx, dy, health;
	SDL_Texture *texture;
} Entity;

Entity *initEntity(void);
Entity *initPlayer(SDL_Renderer *renderer, SDL_Window *window);
Entity *initBullet(SDL_Renderer *renderer, SDL_Window *window);
void freeEntity(Entity *entity);

#endif