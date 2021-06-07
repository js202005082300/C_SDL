#ifndef __MAP__H__
#define __MAP__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h" // tmp : juste pour les defines

#define MAP01 "src/matrix/niveau1.lvl"
#define BIN "src/matrix/data1.bin"


// Définition de MapPosition
typedef struct MapPos
{
	int xscroll;
	int yscroll;
}MapPos;

// Définition de MapSize
typedef struct MapSize
{
	int rows;
	int columns;
	int nb_block;
}MapSize;

// Définition d'une carte
typedef struct Map
{
	int **matrix;
	MapSize *MapSize;
	MapPos *MapPos;
}Map;

// Prototypes des fonctions
void MapManager(void);

Map *new_map(const char *fileLevel);
Map *InitMap(void);
MapPos *InitMapPos(void);
MapSize *GetSizeMatrix(FILE *fic);
int **GetMatrix(FILE *fic, int rows, int columns);
void free_map(Map *map);

void test_ecriture(MapSize *mSize, const char *filename);
MapSize *test_lecture(const char *filename);

void printMapToTheConsole(Map *m);
void PrintSize(MapSize *mSize);

#endif