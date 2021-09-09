#ifndef __INIT__H__
#define __INIT__H__

#define SCREEN_WIDTH   640
#define SCREEN_HEIGHT  480

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

App *initSDL();
void freeSDL(App *app);
void SDL_ExitWithError(const char *message);

#endif