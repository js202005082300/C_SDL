#ifndef __STRUCTS__H__
#define __STRUCTS__H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "util.h"

#define SIZE_PLAYER_SQUARE 50
#define SIZE_ENEMY_SQUARE 50
#define SIZE_BULLET_SQUARE 5

typedef struct str_entity Entity;

struct str_entity {
	int x, y, w, h, dx, dy;
	int health;
	int side;
	int texID;
	Entity *next;
};

Entity *initEntity(void);

Entity *initPlayer(void);
Entity *initEnemy(Entity *entityList);
Entity *initBullet(Entity *entityList, int *entity_x, int *entity_y);

void drawListBullet(void);
void freeEntity(Entity *entityList);
Entity *freeDeadEntity(Entity *list, int x);

#endif