#include "event.h"

void SDL_DoInput(SDL_bool *program_launched, int *PosPlayerX, int *PosPlayerY, const int MapLimitX, const int MapLimitY, int **matrix)
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
                        moveUp(PosPlayerX, PosPlayerY, matrix);
                        continue;
                    case SDLK_DOWN:
                        moveDown(PosPlayerX, PosPlayerY, matrix, MapLimitY);
                        continue;
                    case SDLK_LEFT:
                        moveLeft(PosPlayerX, PosPlayerY, matrix);
                        continue;
                    case SDLK_RIGHT:
                        moveRight(PosPlayerX, PosPlayerY, matrix, MapLimitX);
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

void moveUp(int *PosPlayerX, int *PosPlayerY, int **matrix)
{    
    for(int i = 0 ; i < SPEED_PLAYER ; i++)
        if(matrix[*PosPlayerY/SQUARE_SIZE - i/SQUARE_SIZE][*PosPlayerX/SQUARE_SIZE] == '1')
        {
            return;
        }

    if(*PosPlayerY > SPEED_PLAYER)
        *PosPlayerY -= SPEED_PLAYER;
    else
        *PosPlayerY = 0;
}

/*------------------------------------------------------------------------------------------------*/

void moveDown(int *PosPlayerX, int *PosPlayerY, int **matrix, const int MapLimitY)
{
    if(*PosPlayerY < MapLimitY - SPEED_PLAYER)
        *PosPlayerY += SPEED_PLAYER;
    else
        *PosPlayerY = MapLimitY;
}

/*------------------------------------------------------------------------------------------------*/

void moveLeft(int *PosPlayerX, int *PosPlayerY, int **matrix)
{
    if(*PosPlayerX > SPEED_PLAYER)
        *PosPlayerX -= SPEED_PLAYER;
    else
        *PosPlayerX = 0;
}

/*------------------------------------------------------------------------------------------------*/

void moveRight(int *PosPlayerX, int *PosPlayerY, int **matrix, const int MapLimitX)
{
    if(*PosPlayerX < MapLimitX - SPEED_PLAYER)
        *PosPlayerX += SPEED_PLAYER;
    else
        *PosPlayerX = MapLimitX;
}