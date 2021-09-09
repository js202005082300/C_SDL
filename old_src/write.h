
#ifndef __WRITE__H__
#define __WRITE__H__

#include <stdio.h>
#include <string.h>

#include <SDL_ttf.h>
#include <SDL.h>

#define FONT_PATH "src/fonts/PIXEARG_.TTF"
#define FONT_SIZE 8

//	Definitions
void TTF_InitText(void);
TTF_Font *TTF_LoadFont();
SDL_Color TTF_textColor();
SDL_Texture *TTF_LoadTexture(char *buffer, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer, SDL_Window *window);
void TTF_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y);
void TTF_ExitWithError(const char *message);
void TTF_CleanTextRessources(SDL_Texture *texture, TTF_Font *font);

#endif