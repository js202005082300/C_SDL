#include "event.h"

void SDL_DoInput(SDL_bool *program_launched, int *x, int *y)
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
                        moveDown(y);
                        continue;
                    case SDLK_LEFT:
                        moveLeft(x);
                        continue;
                    case SDLK_RIGHT:
                        moveRight(x);
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
    *y -= SPEED_PLAYER;
    //printf("(%d,%d)\n", *x, *y);
}

/*------------------------------------------------------------------------------------------------*/

void moveDown(int *y)
{
    *y += SPEED_PLAYER;
    //printf("(%d,%d)\n", *x, *y);
}

/*------------------------------------------------------------------------------------------------*/

void moveLeft(int *x)
{
    *x -= SPEED_PLAYER;
    //printf("(%d,%d)\n", *x, *y);
}

/*------------------------------------------------------------------------------------------------*/

void moveRight(int *x)
{
    *x += SPEED_PLAYER;
    //printf("(%d,%d)\n", *x, *y);
}