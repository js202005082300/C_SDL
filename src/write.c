#include <write.h>

void SDL_textInit(void)
{   	
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    return;
}

//load texture
SDL_Texture *SDL_loadText(TTF_Font *font, char *message, SDL_Color color, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = NULL;

    //Chargement surface
    surface = TTF_RenderText_Solid(font, message, color);
        if(surface == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_ExitWithError("Chargement texte echouee"); }

    //Creation texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); 
        if(texture == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_ExitWithError("Creation texture echouee"); }

    return texture;
}

//blit
void SDL_renderText(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window, int x, int y)
{
    SDL_Rect rectangle = {x, y, 0, 0};

    //Chargement texture
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) { SDL_DestroyTexture(texture); SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_ExitWithError("Impossible de charger la texture"); }

    //Afficher texture
    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) { SDL_DestroyTexture(texture); SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_ExitWithError("Impossible d'afficher la texture");}

    return;
}

void SDL_CleanTextRessources(SDL_Texture *texture, TTF_Font *font)
{
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

    TTF_Quit();
    return;
}