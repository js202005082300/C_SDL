#ifndef __INPUT__H__
#define __INPUT__H__

#include "init.h"
#include "structs.h"

#define PLAYER_SPEED            20
#define PLAYER_BULLET_SPEED     16

#define MAX_KEYBOARD_KEYS 		350

void doInput(SDL_bool *ptr, SDL_bool *b_pressed, int *player_x, int *player_y);
void moveUp(int *player_y);
void moveDown(int *player_y);
void moveLeft(int *player_x);
void moveRight(int *player_x);

#endif