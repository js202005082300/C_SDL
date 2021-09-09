#ifndef __INPUT__H__
#define __INPUT__H__

#include "init.h"
#include "structs.h"

#define PLAYER_SPEED 20

void doInput(int *player_x, int *player_y, Entity *bullet);
void moveUp(int *player_y);
void moveDown(int *player_y);
void moveLeft(int *player_x);
void moveRight(int *player_x);

void loadBullet(int *player_x, int *player_y, Entity *bullet);
void moveBullet(Entity *bullet);

#endif