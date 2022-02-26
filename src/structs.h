#ifndef __STRUCTS__H__
#define __STRUCTS__H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "util.h"

#define SIZE_SQUARE 	50
#define SIZE_BULLET 	5
#define BULLET_SPEED 10

typedef struct str_entity Entity;

struct str_entity {
	int x, y, w, h, dx, dy;
	int health;
	int score;
	int side;
	int texID;
	Entity *next;
};

Entity *initEntity(void);

Entity *initPlayer(void);
Entity *initEnemy(Entity *entityList);
Entity *initBullet(Entity *entityList, int *entity_x, int *entity_y);
Entity *initAlienBullet(Entity *entityList, int *entity_x, int *entity_y);

void freeEntity(Entity *entityList);
Entity *freeDeadEntity(Entity *list, int x);
int bulletHitEnnemy(Entity *bullet, Entity *enemy, int score);
int bulletHitPlayer(Entity *bullet, Entity *enemy);

#endif