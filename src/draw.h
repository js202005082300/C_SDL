#ifndef __DRAW__H__
#define __DRAW__H__

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "init.h" // gestion des erreurs

//	Prototypes des fonctions
SDL_Texture *SDL_LoadTexture(char *filename, SDL_Renderer *renderer, SDL_Window *window);
void SDL_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y);

#endif