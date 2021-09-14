#ifndef __STRUCTS__H__
#define __STRUCTS__H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "util.h"

typedef struct str_entity Entity;

struct str_entity {
	int x, y, dx, dy;
	int health;
	int side;
	int texID;
	Entity *next;
};

Entity *initEntity(void);

Entity *initPlayer(void);
Entity *initEnemy(Entity *entityList);
Entity *initBullet(Entity *entityList, int *entity_x, int *entity_y);

Entity *popFrontList(Entity *entityList);

void drawListBullet(void);
void freeEntity(Entity *entityList);

#endif