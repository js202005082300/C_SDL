#include "draw.h"

void prepareScene(App *app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(SDL_Renderer *renderer)
{
	SDL_RenderPresent(renderer);
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, SDL_Window *window, char *filename)
{
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    //Chargement surface
    surface = IMG_Load(filename);
    if(surface == NULL)
    {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
        SDL_ExitWithError("Chargement image echouee");
    }

    //Creation texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == NULL)
    {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
        SDL_ExitWithError("Creation texture echouee");
    }

	return texture;
}

void blit(SDL_Renderer *renderer, SDL_Texture *texture, int *x, int *y)
{
	SDL_Rect dest;

	dest.x = *x;
	dest.y = *y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, NULL, &dest);
}