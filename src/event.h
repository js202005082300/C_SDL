#ifndef __EVENT__H__
#define __EVENT__H__

#include <SDL.h>
#include <stdio.h>

#define SPEED_PLAYER 30

//	Prototypes des fonctions
void SDL_DoInput(SDL_bool *program_launched, int *x, int *y);
void moveUp(int *y);
void moveDown(int *y);
void moveLeft(int *x);
void moveRight(int *x);

#endif