#ifndef __EVENT__H__
#define __EVENT__H__

#include <SDL.h>
#include <stdio.h>

#include "player.h"

//	Prototypes des fonctions
void SDL_DoInput(SDL_bool *program_launched, int *x, int *y, const int MapLimitX, const int MapLimitY);
void moveUp(int *y);
void moveDown(int *y, const int MapLimitY);
void moveLeft(int *x);
void moveRight(int *x, const int MapLimitX);

#endif