#include "write.h"

void TTF_InitText(void)
{   	
    if(TTF_Init()==-1)
        TTF_ExitWithError("TTF_InitText");
}

//load texture
SDL_Texture *TTF_LoadTexture(TTF_Font *font, char *message, SDL_Color color, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = NULL;

    //Chargement surface
    surface = TTF_RenderText_Solid(font, message, color);
        if(surface == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("TTF_LoadText"); }

    //Creation texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); 
        if(texture == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("TTF_LoadText"); }

    return texture;
}

//blit
void TTF_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y)
{
    SDL_Rect rectangle = {x, y, 0, 0};

    //Chargement texture
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) { SDL_DestroyTexture(texture); SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("TTF_RenderText"); }

    //Afficher texture
    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) { SDL_DestroyTexture(texture); SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("TTF_RenderText"); }

    return;
}

void TTF_ExitWithError(const char *message)
{
    const char * error = TTF_GetError();
    printf("%s: %s\n", message, error);
    exit(EXIT_FAILURE);
}

void TTF_CleanTextRessources(SDL_Texture *texture, TTF_Font *font)
{
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

    TTF_Quit();
}