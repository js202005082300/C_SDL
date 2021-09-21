#ifndef __GAME__H__
#define __GAME__H__

#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "player.h"
#include "map.h"
#include "init.h"
#include "draw.h"
#include "write.h"
#include "event.h"
#include "save.h"

//	Prototypes des fonctions
void SDL_VersionUsed(void);
void SDL_GameManager(void);

//  Infos pour le développeur
void printDatasToTheConsole(Map *map, Player *joueur);
/*--------------------------------------------------------*/
#endif