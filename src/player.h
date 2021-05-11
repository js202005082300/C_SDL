#ifndef __PLAYER__H__
#define __PLAYER__H__

/* Fichiers d'en-tête */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Type booléen */
typedef enum
{
	false, //0
	true //1
}Bool;

/* Définition d'un Joueur */
typedef struct Player
{
	char *name;
	int level;
}Player;

/* Définition d'une Pile */
typedef struct StackPlayer
{
	Player pp;
	struct StackPlayer *next;
}StackPlayer;

/* Prototypes des fonctions */
Player *new_player(char *name);
void print_player(Player *p);
void kill_player(Player *p);


#endif