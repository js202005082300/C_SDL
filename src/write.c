#include "write.h"

void TTF_InitText(void)
{   	
    if(TTF_Init()==-1)
        TTF_ExitWithError("TTF_InitText");
}

TTF_Font * TTF_LoadFont()
{
    TTF_Font *font = NULL;
    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
    if(!font)
        TTF_ExitWithError("TTF_InitFont");

    return font;
}

SDL_Color TTF_textColor()
{
    SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF };
    return textColor;
}

//load text
SDL_Texture *TTF_LoadTexture(char *buffer, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

    //Chargement surface & Creation texture
    surface = TTF_RenderText_Solid(font, buffer, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); 
    if(texture == NULL || surface == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("Chargement surface & Creation texture"); }

    return texture;
}

//blit text
void TTF_RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y)
{
    SDL_Rect rectangle = {x, y, 0, 0};

    //Chargement & affichage de la texture (blit)
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0 || SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) 
    { SDL_DestroyTexture(texture); SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); TTF_ExitWithError("Chargement & affichage de la texture (blit)"); }
}

void TTF_ExitWithError(const char *message)
{
    fprintf(stderr, "Erreur %s : %s\n", message, TTF_GetError());
    exit(EXIT_FAILURE);
}

void TTF_CleanTextRessources(SDL_Texture *texture, TTF_Font *font)
{
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    texture = NULL;
    font = NULL;
    TTF_Quit();
}