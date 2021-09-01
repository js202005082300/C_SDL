#ifndef __MAP__H__
#define __MAP__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE_SIZE 10
/*--------------------------------------------------------*/
//	Macros pour la taille de l'espace de jeu (modifiables)
#define MAX_SQUARES_ROWS 64
#define MAX_SQUARES_COLS 48
/*--------------------------------------------------------*/
#define WINDOW_WIDTH SQUARE_SIZE*MAX_SQUARES_ROWS
#define WINDOW_HEIGHT SQUARE_SIZE*MAX_SQUARES_COLS
/*--------------------------------------------------------*/
#define MAP01 "src/matrix/niveau1.lvl"
#define MAP02 "src/matrix/niveau2.lvl"
#define MAP06 "src/matrix/niveau6.lvl"
#define BIN "src/matrix/data1.bin"


// Definition de MapPosition
typedef struct MapPos
{
	int xscroll, yscroll;
	int minX, minY, maxX, maxY;
}MapPos;

// Definition de MapSize
typedef struct MapSize
{
	unsigned int rows;
	unsigned int columns;
	unsigned int nb_block;
}MapSize;

// Definition d'une carte
typedef struct Map
{
	int **matrix;
	MapSize *size;
	MapPos *position;
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
void drawMap(Map *m);

#endif