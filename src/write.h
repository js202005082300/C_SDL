
#ifndef __WRITE__H__
#define __WRITE__H__

#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL.h>

//	Definitions
void TTF_InitText(void);
SDL_Texture *TTF_LoadTexture(TTF_Font *font, char *message, SDL_Color color, SDL_Renderer *renderer, SDL_Window *window);
void TTF_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y);
void TTF_ExitWithError(const char *message);
void TTF_CleanTextRessources(SDL_Texture *texture, TTF_Font *font);

#endif