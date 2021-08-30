#include <SDL_ttf.h>

void SDL_writeInit(void)
{
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,"Welcome to Programmer's Ranch", color);
    retrurn;
}

void SDL_writeQuit(void)
{
    TTF_CloseFont(font); //!
    TTF_Quit();
    retrurn;
}

void SDL_writeManager(void)
{
    //https://www.programmersranch.com/2014/03/sdl2-displaying-text-with-sdlttf.html
    return;
}