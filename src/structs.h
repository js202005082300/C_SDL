#ifndef __STRUCTS__H__
#define __STRUCTS__H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct str_entity Entity;

struct str_entity {
	int x, y;
	int dx, dy, health;
	int reload;
	int texID;
	Entity *next;
};

Entity *initEntity(void);

Entity *initPlayer(void);
Entity *initBullet(Entity *entity, int *entity_x, int *entity_y);

Entity *popFrontList(Entity *entity);

void drawListBullet(void);
void freeEntity(Entity *entity);

#endif