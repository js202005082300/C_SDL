#ifndef __EVENT__H__
#define __EVENT__H__

#include <SDL.h>
#include <stdio.h>

#include "player.h"
#include "map.h"

//	Prototypes des fonctions
void SDL_DoInput(SDL_bool *program_launched, int *PosPlayerX, int *PosPlayerY, const int MapLimitX, const int MapLimitY, int **matrix);
void moveUp(int *PosPlayerX, int *PosPlayerY, int **matrix);
void moveDown(int *PosPlayerX, int *PosPlayerY, int **matrix, const int MapLimitY);
void moveLeft(int *PosPlayerX, int *PosPlayerY, int **matrix);
void moveRight(int *PosPlayerX, int *PosPlayerY, int **matrix, const int MapLimitX);

#endif