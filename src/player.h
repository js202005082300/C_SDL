#ifndef __PLAYER__H__
#define __PLAYER__H__

// Fichiers d'en-tête
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type booléen
typedef enum
{
	false, //0
	true //1
}Bool;

typedef struct Position {
    int X;
    int Y;
}Position;

// Définition d'un Joueur
typedef struct Player
{
	char *name;
	int score;
	Position *position;
}Player;

// Définition d'une Pile
typedef struct StackPlayer
{
	Player pp;
	struct StackPlayer *next;
}StackPlayer;

// Prototypes des fonctions
Player *new_player(const char *name);
void print_player(Player *p);
void free_player(Player *p);

#endif