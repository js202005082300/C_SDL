#include "event.h"

void SDL_DoInput(SDL_bool *program_launched, int *x, int *y, const int MapLimitX, const int MapLimitY)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {               
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        moveUp(y);
                        continue;
                    case SDLK_DOWN:
                        moveDown(y, MapLimitY);
                        continue;
                    case SDLK_LEFT:
                        moveLeft(x);
                        continue;
                    case SDLK_RIGHT:
                        moveRight(x, MapLimitX);
                        continue;
                    case SDLK_b:
                        continue;
                    
                    default:
                        continue;
                }
    
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_b:
                        printf("Vous avez relache la touche B\n");
                        continue;
                    
                    default:
                        continue;
                }
    
            case SDL_QUIT:
                *program_launched = SDL_FALSE;
                break;
            
            default:
                break;
        }
    }
}

/*------------------------------------------------------------------------------------------------*/

void moveUp(int *y)
{
    if(*y > SPEED_PLAYER)
        *y -= SPEED_PLAYER;
    else
        *y = 0;
}

/*------------------------------------------------------------------------------------------------*/

void moveDown(int *y, const int MapLimitY)
{
    if(*y < MapLimitY - SPEED_PLAYER)
        *y += SPEED_PLAYER;
    else
        *y = MapLimitY;
}

/*------------------------------------------------------------------------------------------------*/

void moveLeft(int *x)
{
    if(*x > SPEED_PLAYER)
        *x -= SPEED_PLAYER;
    else
        *x = 0;
}

/*------------------------------------------------------------------------------------------------*/

void moveRight(int *x, const int MapLimitX)
{
    if(*x < MapLimitX - SPEED_PLAYER)
        *x += SPEED_PLAYER;
    else
        *x = MapLimitX;
}