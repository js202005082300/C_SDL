
#ifndef __WRITE__H__
#define __WRITE__H__

#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL.h>

//	Definitions
void SDL_textInit(void);
SDL_Texture *SDL_loadTexture(TTF_Font *font, char *message, SDL_Color color, SDL_Window *window, SDL_Renderer *renderer);
void SDL_CleanTextRessources(SDL_Texture *texture, TTF_Font *font);

#endif