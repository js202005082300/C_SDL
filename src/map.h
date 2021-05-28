#ifndef __MAP__H__
#define __MAP__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h" // tmp : juste pour les defines

// Définition d'une carte
typedef struct Map
{
	int **matrix;
	int rows, columns, nb_block;
	int xscroll, yscroll;
}Map;

// Prototypes des fonctions
void map_init(const char *fileLvl, const char *fileBin);
//void map_texture_loading(void);
void printMapToTheConsole(Map *m);
//map_filling();
//map_displaying();
//void freeMap(Map *m);
void test(const char *filename);

#endif